#include "testing.h"
#include "shell32.h"
#include "console.h"
#include "intrinsics.h"
#include "resolve_symbols.h"
#include "process_information.h"

void StartThread();
boolean_t AdjustProcessTokenPrivileges();

int32_t Main()
{
	if (!ResolveNtSymbols()) return -1;
	if (!ResolveShell32Symbols()) return -1;
	if (!LoadAndResolveAdvapi32Symbols()) return -1;

	BasicProcessInformation processInformation;
	ReadOwnProcessInformation(&processInformation);
	ConsoleWriteHandle = processInformation.StandardOutput;

	if (!AdjustProcessTokenPrivileges()) return -1;

	ConsoleWrite("--------------------------------------\n\n");

	if (!TestConsole(processInformation.ConsoleHandle, processInformation.StandardOutput)) return -2;
	ConsoleLog("VT100 Test Message\n", Info, "Main");

	ConsoleWrite("--------------------------------------\n\n");

	ASLR();

	StartThread();

	return 0;
}