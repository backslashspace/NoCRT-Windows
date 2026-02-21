#include "ntdll.h"

boolean_t EnableVT100(Handle consoleHandle)
{
	// rest in piss to everyone that does not use the "Windows Terminal"
	// https://learn.microsoft.com/en-us/windows/console/setconsolecursorposition
	// TL;DR: use "Virtual Terminal" - old is deprecated - "support will continue for indefinite future"

#define ENABLE_PROCESSED_OUTPUT 0x0001
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004

	IO_STATUS_BLOCK ioStatusBlock = { 0 };
	FILE_MODE_INFORMATION modeInfo = { 0 };

	if (NtQueryInformationFile(consoleHandle, &ioStatusBlock, &modeInfo, sizeof(modeInfo), FileModeInformation)) return false;
	modeInfo.Mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	if (NtSetInformationFile(consoleHandle, &ioStatusBlock, &modeInfo, sizeof(modeInfo), FileModeInformation)) return false;

	return true;
}