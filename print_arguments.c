#include "console.h"
#include "process_information.h"

void PrintArguments()
{
	ConsoleWrite("# Start arguments:\n\n");

	if (ProcessInformation.CommandLineBuffer == null || ProcessInformation.CommandLineBuffer[0] == null)
	{
		ConsoleWrite("CommandLine was null or empty\n");
		return;
	}

	COMMAND_LINE_STRING *arguments = _alloca(sizeof(COMMAND_LINE_STRING) * 8);

	uint64_t argumentCount = ParseCommandLine(ProcessInformation.CommandLineBuffer, ProcessInformation.CommandLineLength >> 1, &arguments, 10);

	for (uint16_t i = 0; i < argumentCount; ++i)
	{
		WriteConsoleW(ProcessInformation.StandardOutput, u" → ", 3, null, null);
		WriteConsoleW(ProcessInformation.StandardOutput, arguments[i].Buffer, (uint32_t)arguments[i].Length, null, null);
		WriteConsoleW(ProcessInformation.StandardOutput, u"\n", 1, null, null);
	}

	ConsoleWrite("\n");
}