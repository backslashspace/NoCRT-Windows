#include "intrinsics.h"
#include "process_information.h"

BasicProcessInformation ProcessInformation = { 0 };

void ReadOwnProcessInformation(BasicProcessInformation *processInformation)
{
	uint8_t *processEnvironmentBlock = (uint8_t *)__readgsqword(0x60);
	uint8_t *processParameters = *(uint8_t **)(processEnvironmentBlock + 0x20);

	processInformation->Environment = *(void **)(processParameters + 0x80);
	processInformation->ImageBaseAddress = *(void **)(processEnvironmentBlock + 0x10);

	processInformation->StandardInput = *(Handle *)(processParameters + 0x20);
	processInformation->StandardOutput = *(Handle *)(processParameters + 0x28);
	processInformation->StandardError = *(Handle *)(processParameters + 0x30);

	processInformation->ConsoleHandle = *(Handle *)(processParameters + 0x10);

	processInformation->WorkingDirectoryHandle = *(Handle *)(processParameters + 0x50);
	processInformation->WorkingDirectoryBuffer = *(wchar_t **)(processParameters + 0x40);
	processInformation->WorkingDirectoryLength = *(uint16_t *)(processParameters + 0x38);

	processInformation->ImagePathNameBuffer = *(wchar_t **)(processParameters + 0x68);
	processInformation->ImagePathNameLength = *(uint16_t *)(processParameters + 0x60);

	processInformation->CommandLineBuffer = *(wchar_t **)(processParameters + 0x78);
	processInformation->CommandLineLength = *(uint16_t *)(processParameters + 0x70);
}

// return 0 if arguments are invalid or cli is only US
// skips initial US, after the first non US, any double US produce empty entries
uint64_t ParseCommandLine(wchar_t const *restrict const commandLine, uint64_t const commandLineLength, COMMAND_LINE_STRING *restrict const *restrict const arguments, uint64_t const argumentBufferLength)
{
	if (commandLine == null || commandLine[0] == null || argumentBufferLength == 0 || arguments == null) return 0;
	if (commandLineLength == 1 && *commandLine == 0x1F) return 0;

	uint64_t argumentIndex = 0;
	uint64_t argumentCount = 0;
	uint64_t unitStartIndex = 0;
	uint64_t commandLineIndex = 0;

FIND_START:
	if (commandLine[commandLineIndex] == 0x1F)
	{
		++unitStartIndex;
		++commandLineIndex;

		if (commandLineLength == commandLineIndex) return 0;
		goto FIND_START;
	}

NEXT_WCHAR:
	if (commandLineLength == commandLineIndex)
	{
		(*arguments)[argumentIndex].Buffer = (wchar_t *)&commandLine[unitStartIndex];
		(*arguments)[argumentIndex].Length = commandLineIndex - unitStartIndex;

		++argumentCount;

		return argumentCount;
	}

	if (commandLine[commandLineIndex] == 0x1F)
	{
		(*arguments)[argumentIndex].Buffer = (wchar_t *)&commandLine[unitStartIndex];
		(*arguments)[argumentIndex].Length = commandLineIndex - unitStartIndex;

		++argumentIndex;
		++argumentCount;
		unitStartIndex = ++commandLineIndex;

		if (argumentIndex == argumentBufferLength || commandLineIndex == commandLineLength) return argumentCount;

		goto NEXT_WCHAR;
	}

	++commandLineIndex;
	goto NEXT_WCHAR;
}