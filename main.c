#include "testing.h"
#include "shell32.h"
#include "console.h"
#include "intrinsics.h"
#include "resolve_symbols.h"
#include "process_information.h"

int32_t Main()
{
	if (!ResolveNtSymbols()) return -1;
	if (!ResolveShell32Symbols()) return -1;

	BasicProcessInformation processInformation;
	ReadOwnProcessInformation(&processInformation);

	if (!TestConsole(processInformation.ConsoleHandle, processInformation.StandardOutput)) return -2;
	ConsoleWriteHandle = processInformation.StandardOutput;

	ASLR();


	



	_mm_pause();

	return 0;
}