#include "ntdll.h"
#include "utility.h"
#include "process_information.h"

void ConsoleWrite(char_t const *const message)
{
	uint32_t length = (uint32_t)MemoryGetFirstByteMatchIndexX86(256, null, message);

	IO_STATUS_BLOCK ioStatusBlock = { 0 };
	NtWriteFile(ProcessInformation.StandardOutput, null, null, null, &ioStatusBlock, message, length, null, null);
}

void ConsoleWriteA(char_t const *const message, uint32_t const length)
{
	IO_STATUS_BLOCK ioStatusBlock = { 0 };
	NtWriteFile(ProcessInformation.StandardOutput, null, null, null, &ioStatusBlock, message, length, null, null);
}

void ConsoleWriteW(wchar_t const *const message, uint32_t const length)
{
	IO_STATUS_BLOCK ioStatusBlock = { 0 };
	NtWriteFile(ProcessInformation.StandardOutput, null, null, null, &ioStatusBlock, message, length, null, null);
}