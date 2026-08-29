#include "console.h"
#include "process_information.h"

void PrintArguments()
{
	ConsoleWrite("# Start arguments\n\n");

	if (OwnProcessInformation.CommandLineBuffer == null || OwnProcessInformation.CommandLineBuffer[0] == null)
	{
		ConsoleWrite("CommandLine was null or empty\n");
		return;
	}

	COMMAND_LINE_STRING arguments[8];

	uint64_t argumentCount = ParseCommandLine(OwnProcessInformation.CommandLineBuffer, OwnProcessInformation.CommandLineByteCount >> 1, arguments, 8);

	for (uint64_t i = 0; i < argumentCount; ++i)
	{
		WriteConsoleW(OwnProcessInformation.StandardOutput, u"\t→ ", 3, null, null);
		WriteConsoleW(OwnProcessInformation.StandardOutput, arguments[i].Buffer, (uint32_t)arguments[i].Length, null, null);
		WriteConsoleW(OwnProcessInformation.StandardOutput, u"\n", 1, null, null);
	}

	ConsoleWrite("\n----------------------------------------------------------------\n\n");
}