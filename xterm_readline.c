#include "ntdll.h"
#include "console.h"
#include "utility.h"
#include "intrinsics.h"
#include "process_information.h"

// https://invisible-island.net/xterm/ctlseqs/ctlseqs.html
// https://ecma-international.org/publications-and-standards/standards/ecma-48/
// https://ecma-international.org/wp-content/uploads/ECMA-48_5th_edition_june_1991.pdf

typedef struct READ_LINE_CONTEXT
{
	uint8_t *Buffer;
	uint16_t Length;
	uint16_t Position;
	uint16_t WrittenBytes;
	boolean_t HideOutput;
	boolean_t OverwriteMode;
	IO_STATUS_BLOCK IoStatusBlock;
} READ_LINE_CONTEXT;

static __forceinline boolean_t ConsumeUnhandled(READ_LINE_CONTEXT *const context)
{
	uint8_t controlCharacter;
READ_NEXT:
	if (NtReadFile(ProcessInformation.StandardInput, null, null, null, &context->IoStatusBlock, &controlCharacter, 1, null, null)) return false;
	if (controlCharacter >= 0x40 && 0x7E >= controlCharacter) return true;
	else goto READ_NEXT;
}

static boolean_t HandleCSI(READ_LINE_CONTEXT *const context)
{
	uint16_t escapeIndex = 0;
	uint8_t *escapeBuffer = _alloca(32);
	__stosb(escapeBuffer, 0, 32);

READ_NEXT:
	if (escapeIndex == 31 || NtReadFile(ProcessInformation.StandardInput, null, null, null, &context->IoStatusBlock, escapeBuffer + escapeIndex, 1, null, null)) return false;
	if (escapeBuffer[escapeIndex] < 0x40 || 0x7E < escapeBuffer[escapeIndex])
	{
		++escapeIndex;
		goto READ_NEXT;
	}

	switch (escapeBuffer[0])
	{
	case 'D': // arrow left
		if (context->Position < 1) return true;
		--context->Position;
		return !NtWriteFile(ProcessInformation.StandardOutput, null, null, null, &context->IoStatusBlock, "\x1b[D", 3, null, null);

	case 'C': // arrow right
		if (context->Position + 1 > context->WrittenBytes) return true;
		++context->Position;
		return !NtWriteFile(ProcessInformation.StandardOutput, null, null, null, &context->IoStatusBlock, "\x1b[C", 3, null, null);

	case '2': // insert
		if (escapeIndex == 1)
		{
			 if (context->OverwriteMode)
			 {
				 context->OverwriteMode = false;
				 return !NtWriteFile(ProcessInformation.StandardOutput, null, null, null, &context->IoStatusBlock, "\x1b[0 q", 5, null, null);
			 }
			 else
			 {
				 context->OverwriteMode = true;
				 return !NtWriteFile(ProcessInformation.StandardOutput, null, null, null, &context->IoStatusBlock, "\x1b[3 q", 5, null, null);
			 }
		}
		else return true; // modifier was present

	case '3': // del key
		if (escapeIndex == 1)
		{
			if (context->Position == context->WrittenBytes) return true; // end of line - nothing to do
			--context->WrittenBytes;
			__movsb(context->Buffer + context->Position, context->Buffer + context->Position + 1, (uint64_t)context->WrittenBytes - context->Position);
			return !NtWriteFile(ProcessInformation.StandardOutput, null, null, null, &context->IoStatusBlock, "\x1b[P", 3, null, null);
		}
		else return true; // modifier was present

	case 'H': // home
		if (escapeIndex == 0)
		{
			context->Position = 0;
			return !NtWriteFile(ProcessInformation.StandardOutput, null, null, null, &context->IoStatusBlock, "\r", 1, null, null);
		}		
		else return true; // modifier was present

	case 'F': // end
		if (escapeIndex == 0)
		{
			context->Position = context->WrittenBytes;
			// input is at most 5 chars long
			// expects length of 20 - writes back to front
			uint16_t length = UInt64ToChar(context->WrittenBytes + 1, (char_t *)escapeBuffer);
			escapeBuffer[20 - length - 2] = '\x1b';
			escapeBuffer[20 - length - 1] = '[';
			escapeBuffer[20] = 'G';
			return !NtWriteFile(ProcessInformation.StandardOutput, null, null, null, &context->IoStatusBlock, escapeBuffer + 20 - length - 2, length + 3, null, null);
		}
		else return true; // modifier was present

	default:
		return true;
	}
}

static boolean_t HandleEscapeSequence(READ_LINE_CONTEXT *const context)
{
	uint8_t controlCharacter;
	if (NtReadFile(ProcessInformation.StandardInput, null, null, null, &context->IoStatusBlock, &controlCharacter, 1, null, null)) return false;

	switch (controlCharacter)
	{
	case '[':
		return HandleCSI(context);

	case 'O':
		return ConsumeUnhandled(context);

	default:
		if (controlCharacter < 0x40 || 0x7E < controlCharacter) return ConsumeUnhandled(context);
		else return true;
	}
}

// ---------------------------------------------------------------------------------

boolean_t ReadLine(uint8_t *const restrict buffer, uint16_t const length, uint16_t *const restrict writtenBytes)
{
	READ_LINE_CONTEXT context;
	context.Buffer = buffer;
	context.Length = length;
	context.Position = 0;
	context.OverwriteMode = false;
	context.WrittenBytes = 0;

	uint8_t character;

READ_NEXT:
	if (NtReadFile(ProcessInformation.StandardInput, null, null, null, &context.IoStatusBlock, &character, 1, null, null)) return false;

	// ------------------------------------------------------------------------------------------

	if (character == '\r')
	{
		*writtenBytes = context.WrittenBytes;
		if (context.OverwriteMode && NtWriteFile(ProcessInformation.StandardOutput, null, null, null, &context.IoStatusBlock, "\x1b[0 q", 5, null, null)) return false;
		return !NtWriteFile(ProcessInformation.StandardOutput, null, null, null, &context.IoStatusBlock, "\n", 1, null, null);
	}

	// ----------------------------------

	if (character == 127) // backspace
	{
		if (context.Position == 0) goto READ_NEXT;

		if (NtWriteFile(ProcessInformation.StandardOutput, null, null, null, &context.IoStatusBlock, "\x1b[D\x1b[P", 6, null, null)) return false;

		--context.Position;
		--context.WrittenBytes;
		
		// shift buffer left when not at end
		if (context.Position != context.WrittenBytes) __movsb(context.Buffer + context.Position, context.Buffer + context.Position + 1, context.WrittenBytes - context.Position);

		goto READ_NEXT;
	}

	// ----------------------------------

	if (character == '\x1b')
	{
		if (!HandleEscapeSequence(&context)) return false;
		goto READ_NEXT;
	}

	// ----------------------------------

	if (character == '\f')
	{
		context.Position = 0;
		context.WrittenBytes = 0;
		if (NtWriteFile(ProcessInformation.StandardOutput, null, null, null, &context.IoStatusBlock, "\x1b[2K\r", 5, null, null)) return false;
		goto READ_NEXT;
	}

	// ----------------------------------

	if (character < ' ') goto READ_NEXT;

	// ----------------------------------

	// jump words
	// C U
	// C K

	// ----------------------------------

	// buffer full
	if (context.WrittenBytes == length) goto READ_NEXT;

	if (!context.OverwriteMode && context.WrittenBytes != context.Position) // move line one right from curser when in middle
	{
		MemoryInverseCopyX86(context.WrittenBytes - context.Position, context.Buffer + context.Position, context.Buffer + context.Position + 1);
		if (NtWriteFile(ProcessInformation.StandardOutput, null, null, null, &context.IoStatusBlock, "\x1b[@", 3, null, null)) return false;
	}

	// don't inc when in insert mode and not at end of line
	if (!context.OverwriteMode || context.Position == context.WrittenBytes) ++context.WrittenBytes;
	context.Buffer[context.Position] = character;
	++context.Position;

	if (NtWriteFile(ProcessInformation.StandardOutput, null, null, null, &context.IoStatusBlock, &character, 1, null, null)) return false;

	goto READ_NEXT;
}