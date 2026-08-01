#pragma message("[ntdll] v1.3.1")

#include "ntdll.h"
#include "intrinsics.h"

// ░░░ Initialization + State ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

Handle NtDllBaseAddress = null;
struct NtDllFunctions NtDll = { 0 };

boolean_t InitializeNtDll()
{
	// https://www.vergiliusproject.com/kernels/x64/windows-11/24h2/_PEB
	// https://www.vergiliusproject.com/kernels/x64/windows-11/24h2/_PEB_LDR_DATA
	// https://www.vergiliusproject.com/kernels/x64/windows-11/24h2/_LDR_DATA_TABLE_ENTRY

	uint8_t *processEnvironmentBlock = (uint8_t *)__readgsqword(0x60);
	uint8_t *loaderData = *(uint8_t **)(processEnvironmentBlock + 0x18);
	uint8_t *inMemoryOrderModuleList = loaderData + 0x20;

	uint8_t *headNode = (*(uint8_t **)inMemoryOrderModuleList) - 0x10;
	uint8_t *node = headNode;

NEXT_MODULE:
	uint8_t *dllBaseAddress = *(void **)(node + 0x30);
	uint16_t *nameLengthBytes = (uint16_t *)(node + 0x58);
	wchar_t *baseDllName = *(wchar_t **)(node + 0x60);

	if (*nameLengthBytes != 18)
	{
		node = (*(uint8_t **)(node));

		if (node == headNode) return false;
		else goto NEXT_MODULE;
	}

	// if string is ntdll.dll | little endian | they said msvc has no alias rule when optimizing
	if (*((uint64_t *)baseDllName) != 30399726989082734 || *((uint64_t *)(baseDllName + 4)) != 30399726984495212 || baseDllName[8] != L'l')
	{
		node = (*(uint8_t **)(node));
		goto NEXT_MODULE;
	}

	/* - - - - - - - - - - - - - - - - - - - */

	// IMAGE_FILE_HEADER
	// IMAGE_NT_HEADERS64
	// IMAGE_DATA_DIRECTORY
	// IMAGE_EXPORT_DIRECTORY
	// IMAGE_OPTIONAL_HEADER64

	uint8_t *ntHeaders = dllBaseAddress + *(uint32_t *)(dllBaseAddress + 0x3C);

	uint8_t *exportDirectory = (dllBaseAddress + *(uint32_t *)(ntHeaders + 0x18 + 0x70)); // ntHeaders->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress | IMAGE_DIRECTORY_ENTRY_EXPORT = 0

	uint32_t numberOfNames = *(uint32_t *)(exportDirectory + 0x18);
	uint32_t *names = (uint32_t *)(dllBaseAddress + *(uint32_t *)(exportDirectory + 0x20));
	uint16_t *ordinals = (uint16_t *)(dllBaseAddress + *(uint32_t *)(exportDirectory + 0x24));
	uint32_t *functions = (uint32_t *)(dllBaseAddress + *(uint32_t *)(exportDirectory + 0x1c));

	/* - - - - - - - - - - - - - - - - - - - */

	uint32_t index = 0;

NEXT_FUNCTION:
	uint8_t* moduleName = dllBaseAddress + names[index];

	// if string is LdrGetProcedureAddressEx | little endian | they said msvc has no alias rule when optimizing
	if (*(uint64_t *)moduleName == 8237211696799835212 && *(uint64_t *)(moduleName + 8) == 4712298433634198383 && *(uint64_t *)(moduleName + 16) == 8666459997404816484 && moduleName[24] == '\0')
	{
		uint16_t ordinal = ordinals[index];
		uint8_t *functionAddress = dllBaseAddress + functions[ordinal];

		__stosb(&NtDll, 0, sizeof(struct NtDllFunctions));

		NtDllBaseAddress = (Handle)dllBaseAddress;
		NtDll.LdrGetProcedureAddressEx = (LdrGetProcedureAddressEx_t)functionAddress;

		return true;
	}

	++index;

	if (index < numberOfNames) goto NEXT_FUNCTION;
	else return false;
}

// ░░░ Runtime Loaders ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

#define LOAD(functionName) \
boolean_t Load##functionName() \
{ \
	if (NtDllBaseAddress == null) return false; \
	if (NtDll.functionName != null) return true; \
	 \
	STRING procedureName; \
	procedureName.Buffer = #functionName; \
	procedureName.Length = sizeof(#functionName) - 1; \
	procedureName.MaximumLength = sizeof(#functionName); \
	 \
	return !LdrGetProcedureAddressEx(NtDllBaseAddress, &procedureName, 0, (void **)&NtDll.functionName, 0); \
}

LOAD(NtClose)
LOAD(NtReadFile)
LOAD(NtOpenFile)
LOAD(LdrLoadDll)
LOAD(NtWriteFile)
LOAD(LdrUnloadDll)
LOAD(NtCreateFile)
LOAD(NtAlertThread)
LOAD(NtOpenSection)
LOAD(NtQueryObject)
LOAD(NtResumeThread)
LOAD(NtCreateSection)
LOAD(NtSuspendThread)
LOAD(NtYieldExecution)
LOAD(NtDelayExecution)
LOAD(NtCreateThreadEx)
LOAD(RtlUnicodeToUTF8N)
LOAD(NtTerminateThread)
LOAD(LdrGetDllHandleEx)
LOAD(NtSetContextThread)
LOAD(NtGetContextThread)
LOAD(NtTerminateProcess)
LOAD(NtMapViewOfSection)
LOAD(NtOpenProcessToken)
LOAD(NtAlertResumeThread)
LOAD(NtFreeVirtualMemory)
LOAD(RtlTimeToTimeFields)
LOAD(NtUnmapViewOfSection)
LOAD(NtSetInformationFile)
LOAD(NtDeviceIoControlFile)
LOAD(NtWaitForSingleObject)
LOAD(NtSetInformationThread)
LOAD(NtQueryInformationFile)
LOAD(NtProtectVirtualMemory)
LOAD(NtAdjustPrivilegesToken)
LOAD(NtQueryInformationToken)
LOAD(NtAllocateVirtualMemory)
LOAD(NtSetInformationProcess)
LOAD(NtQuerySystemInformation)