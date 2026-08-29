#include "intrinsics.h"
#include "process_information.h"

OWN_PROCESS_INFORMATION OwnProcessInformation = { 0 };

void ReadOwnProcessInformation()
{
	uint8_t *processEnvironmentBlock = (uint8_t *)__readgsqword(0x60);
	uint8_t *processParameters = *(uint8_t **)(processEnvironmentBlock + 0x20);

	OwnProcessInformation.Environment = *(void **)(processParameters + 0x80);
	OwnProcessInformation.ImageBaseAddress = *(void **)(processEnvironmentBlock + 0x10);

	OwnProcessInformation.StandardInput = *(Handle *)(processParameters + 0x20);
	OwnProcessInformation.StandardOutput = *(Handle *)(processParameters + 0x28);
	OwnProcessInformation.StandardError = *(Handle *)(processParameters + 0x30);

	OwnProcessInformation.ConsoleHandle = *(Handle *)(processParameters + 0x10);

	OwnProcessInformation.WorkingDirectoryHandle = *(Handle *)(processParameters + 0x50);
	OwnProcessInformation.WorkingDirectoryBuffer = *(wchar_t **)(processParameters + 0x40);
	OwnProcessInformation.WorkingDirectoryByteCount = *(uint16_t *)(processParameters + 0x38);

	OwnProcessInformation.ImagePathNameBuffer = *(wchar_t **)(processParameters + 0x68);
	OwnProcessInformation.ImagePathNameByteCount = *(uint16_t *)(processParameters + 0x60);

	OwnProcessInformation.CommandLineBuffer = *(wchar_t **)(processParameters + 0x78);
	OwnProcessInformation.CommandLineByteCount = *(uint16_t *)(processParameters + 0x70);
}