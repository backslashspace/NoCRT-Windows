#include "testing.h"
#include "shell32.h"
#include "intrinsics.h"
#include "resolve_symbols.h"
#include "console_logging.h"
#include "process_information.h"

int64_t MemoryGetFirstByteMatchIndexX86(const void* buffer, uint8_t value, uint64_t count);
int64_t MemoryGetFirstWordMatchIndexX86(const void* buffer, uint16_t value, uint64_t count);

int32_t Main()
{
	if (!ResolveNtSymbols()) return -1;
	if (!ResolveShell32Symbols()) return -1;

	BasicProcessInformation processInformation;
	ReadOwnProcessInformation(&processInformation);

	if (!TestConsole(processInformation.ConsoleHandle, processInformation.StandardOutput)) return -2;

	uint32_t argc;
	wchar_t** argv = Shell32.CommandLineToArgvW(processInformation.CommandLineBuffer, &argc);

	char_t* testss = "gurt yo my nuts";

	int64_t inde = MemoryGetFirstByteMatchIndexX86(testss, 'n', 15);

	for (uint16_t i = 0; i < argc; ++i)
	{
		int64_t length = MemoryGetFirstWordMatchIndexX86(argv[i], 0, processInformation.CommandLineLength);
		ConsoleLogW(argv[i], (uint16_t)length, Info, L"Args", 4, processInformation.StandardOutput);
	}






	_mm_pause();

	return 0;
}