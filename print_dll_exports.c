#include "utility.h"
#include "kernelbase.h"
#include "process_information.h"

void PrintDllExports(uint8_t *dllBaseAddress)
{
	// IMAGE_FILE_HEADER
	// IMAGE_NT_HEADERS64
	// IMAGE_DATA_DIRECTORY
	// IMAGE_EXPORT_DIRECTORY
	// IMAGE_OPTIONAL_HEADER64

	uint8_t *ntHeaders = dllBaseAddress + *(uint32_t *)(dllBaseAddress + 0x3C);

	uint8_t *exportDirectory = (dllBaseAddress + *(uint32_t *)(ntHeaders + 0x18 + 0x70)); // ntHeaders->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress | IMAGE_DIRECTORY_ENTRY_EXPORT = 0

	uint32_t numberOfNames = *(uint32_t *)(exportDirectory + 0x18);
	uint32_t *names = (uint32_t *)(dllBaseAddress + *(uint32_t *)(exportDirectory + 0x20));

	if (numberOfNames == 0) return;

	/* - - - - - - - - - - - - - - - - - - - */

	uint32_t index = 0;

NEXT_FUNCTION:;
	uint8_t *functionName = dllBaseAddress + names[index];

	int64_t length = MemoryGetFirstByteMatchIndexX86(128, null, functionName);
	char_t *buffer = _alloca(length + 2);
	__movsb(buffer, functionName, length);
	*(uint16_t *)(&buffer[length]) = '\r\n';

	WriteConsoleA(OwnProcessInformation.StandardOutput, buffer, (uint32_t)length + 2, null, null);

	if (++index < numberOfNames) goto NEXT_FUNCTION;
}