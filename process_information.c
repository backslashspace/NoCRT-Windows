#include "ntdll.h"
#include "intrinsics.h"
#include "process_information.h"

BasicProcessInformation ProcessInformation = { 0 };

void ReadOwnProcessInformation(BasicProcessInformation *processInformation)
{
	uint8_t *processEnvironmentBlock = (uint8_t *)__readgsqword(0x60);
	uint8_t *processParameters = *(uint8_t **)(processEnvironmentBlock + 0x20);

	processInformation->Environment = *(void **)(processParameters + 0x80);
	processInformation->ImageBaseAddress = *(void **)(processEnvironmentBlock + 0x10);

	processInformation->StandardInput = *(Handle *)(processParameters + 0x20);
	processInformation->StandardOutput = *(Handle *)(processParameters + 0x28);
	processInformation->StandardError = *(Handle *)(processParameters + 0x30);

	processInformation->ConsoleHandle = *(Handle *)(processParameters + 0x10);

	processInformation->WorkingDirectoryHandle = *(Handle *)(processParameters + 0x50);
	processInformation->WorkingDirectoryBuffer = *(wchar_t **)(processParameters + 0x40);
	processInformation->WorkingDirectoryLength = *(uint16_t *)(processParameters + 0x38);

	processInformation->ImagePathNameBuffer = *(wchar_t **)(processParameters + 0x68);
	processInformation->ImagePathNameLength = *(uint16_t *)(processParameters + 0x60);

	processInformation->CommandLineBuffer = *(wchar_t **)(processParameters + 0x78);
	processInformation->CommandLineLength = *(uint16_t *)(processParameters + 0x70);
}