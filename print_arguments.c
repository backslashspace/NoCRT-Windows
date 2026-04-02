#include "shell32.h"
#include "console.h"
#include "utility.h"
#include "kernelbase.h"

void PrintArguments(wchar_t const *const commandLine, Handle const outputHandle)
{
	ConsoleWrite("# Start arguments:\n\n");

	uint32_t argc;
	wchar_t **argv = CommandLineToArgvW(commandLine, &argc);

	for (uint16_t i = 0; i < argc; ++i)
	{
		uint32_t length = (uint32_t)MemoryGetFirstWordMatchIndexX86(512, null, argv[i]);
		argv[i][length] = L'\n';
		WriteConsoleW(outputHandle, argv[i], length + 1, null, null);
		argv[i][length] = 0;
	}

	ConsoleWrite("\n");
}