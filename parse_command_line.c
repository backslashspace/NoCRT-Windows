#include "utility.h"

// return 0 if arguments are invalid or cli is only US
// skips initial US, after the first non US, any double US produce empty entries
uint64_t ParseCommandLine(wchar_t const *restrict const commandLine, uint64_t const commandLineLength, COMMAND_LINE_STRING *restrict const arguments, uint64_t const argumentBufferLength)
{
	if (commandLine == null || commandLineLength == 0 || commandLine[0] == null || arguments == null || argumentBufferLength == 0) return 0;

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
		arguments[argumentIndex].Buffer = &commandLine[unitStartIndex];
		arguments[argumentIndex].Length = commandLineIndex - unitStartIndex;

		++argumentCount;

		return argumentCount;
	}

	if (commandLine[commandLineIndex] == 0x1F)
	{
		arguments[argumentIndex].Buffer = &commandLine[unitStartIndex];
		arguments[argumentIndex].Length = commandLineIndex - unitStartIndex;

		++argumentIndex;
		++argumentCount;
		unitStartIndex = ++commandLineIndex;

		if (argumentIndex == argumentBufferLength || commandLineIndex == commandLineLength) return argumentCount;

		goto NEXT_WCHAR;
	}

	++commandLineIndex;
	goto NEXT_WCHAR;
}