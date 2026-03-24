#include "ntdll.h"
#include "testing.h"
#include "shell32.h"
#include "console.h"
#include "utility.h";
#include "intrinsics.h"
#include "resolve_symbols.h"
#include "process_information.h"

boolean_t AdjustProcessTokenPrivileges();

boolean_t Init()
{
	if (!ResolveNtSymbols()) return false;
	if (!ResolveShell32Symbols()) return false;
	if (!LoadAndResolveAdvapi32Symbols()) return false;
	if (!LoadAndResolveKernelbaseSymbols()) return false;

	ReadOwnProcessInformation(&ProcessInformation);

	if (!AdjustProcessTokenPrivileges()) return false;
}

void PrintArguments()
{
	ConsoleWrite("# Start arguments:\n\n");

	uint32_t argc;
	wchar_t **argv = CommandLineToArgvW(ProcessInformation.CommandLineBuffer, &argc);

	for (uint16_t i = 0; i < argc; ++i)
	{
		ConsoleWriteW(argv[i], (uint32_t)MemoryGetFirstWordMatchIndexX86(512, null, argv[i]) << 1);
		ConsoleWrite("\n");
	}
}

int32_t Main()
{
	if (!Init()) return false;

	ConsoleWrite("--------------------------------------\n\n");

	PrintArguments();

	ConsoleWrite("\n--------------------------------------\n\n");

	if (!EnableVT100(ProcessInformation.StandardOutput, ProcessInformation.StandardInput)) return -1;
	ConsoleWrite("# Enabled VT100!\n\n");
	ConsoleLog("VT100 Test Message\n", Info, "Main");

	ConsoleWrite("--------------------------------------\n\n");

	ASLR();

	ConsoleWrite("--------------------------------------\n\n");

	if (!MoveConsoleCurser()) return -1;

	ConsoleWrite("--------------------------------------\n\n");

	if (!Multithreading()) return -1;

	ConsoleWrite("--------------------------------------\n\n");

	return 0;
}