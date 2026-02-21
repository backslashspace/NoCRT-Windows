#include "ntdll.h"
#include "console_logging.h"

boolean_t TestConsole(Handle consoleHandle, Handle standardOutput)
{
	if (!EnableVT100(consoleHandle)) return false;

	IO_STATUS_BLOCK ioStatusBlock = { 0 };
	NtStatus status = NtWriteFile(standardOutput, null, null, null, &ioStatusBlock, "Enabled VT100!\n\n", 16, null, null);

	return !status;
}