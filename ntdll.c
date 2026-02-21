#include "ntdll.h"
#include "intrinsics.h"

// ░░░ Initialization + State ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

struct NtDllFunctions NtDll = { 0 };
uint8_t* NtDllBaseAddress = null;

boolean_t InitializeNtDll()
{
	// https://www.vergiliusproject.com/kernels/x64/windows-11/24h2/_PEB
	// https://www.vergiliusproject.com/kernels/x64/windows-11/24h2/_PEB_LDR_DATA
	// https://www.vergiliusproject.com/kernels/x64/windows-11/24h2/_LDR_DATA_TABLE_ENTRY

	uint8_t* processEnvironmentBlock = (uint8_t*)__readgsqword(0x60);
	uint8_t* loaderData = *(uint8_t**)(processEnvironmentBlock + 0x18);
	uint8_t* inMemoryOrderModuleList = loaderData + 0x20;

	uint8_t* headNode = (*(uint8_t**)inMemoryOrderModuleList) - 0x10;
	uint8_t* node = headNode;

NEXT_MODULE:
	uint8_t* dllBaseAddress = *(void**)(node + 0x30);
	uint16_t* nameLengthBytes = (uint16_t*)(node + 0x58);
	wchar_t* baseDllName = *(wchar_t**)(node + 0x60);

	if (*nameLengthBytes != 18)
	{
		node = (*(uint8_t**)(node));

		if (node == headNode) return false;
		else goto NEXT_MODULE;
	}

	// if string is ntdll.dll | little endian | they said msvc has no alias rule when optimizing
	if (*((__unaligned uint64_t*)baseDllName) != 30399726989082734 || *((__unaligned uint64_t*)(baseDllName + 4)) != 30399726984495212 || baseDllName[8] != L'l')
	{
		node = (*(uint8_t**)(node));
		goto NEXT_MODULE;
	}

	/* - - - - - - - - - - - - - - - - - - - */

	// IMAGE_FILE_HEADER
	// IMAGE_NT_HEADERS64
	// IMAGE_DATA_DIRECTORY
	// IMAGE_EXPORT_DIRECTORY
	// IMAGE_OPTIONAL_HEADER64

	uint8_t* ntHeaders = dllBaseAddress + *(uint32_t*)(dllBaseAddress + 0x3C);

	uint8_t* exportDirectory = (dllBaseAddress + *(uint32_t*)(ntHeaders + 0x18 + 0x70)); // ntHeaders->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress | IMAGE_DIRECTORY_ENTRY_EXPORT = 0

	uint32_t numberOfNames = *(uint32_t*)(exportDirectory + 0x18);
	uint32_t* names = (uint32_t*)(dllBaseAddress + *(uint32_t*)(exportDirectory + 0x20));
	uint16_t* ordinals = (uint16_t*)(dllBaseAddress + *(uint32_t*)(exportDirectory + 0x24));
	uint32_t* functions = (uint32_t*)(dllBaseAddress + *(uint32_t*)(exportDirectory + 0x1c));

	/* - - - - - - - - - - - - - - - - - - - */

	uint32_t index = 0;

NEXT_FUNCTION:
	uint8_t* moduleName = dllBaseAddress + names[index];

	// if string is LdrGetProcedureAddressEx | little endian | they said msvc has no alias rule when optimizing
	if (*(__unaligned uint64_t*)moduleName == 8237211696799835212 && *(__unaligned uint64_t*)(moduleName + 8) == 4712298433634198383 && *(__unaligned uint64_t*)(moduleName + 16) == 8666459997404816484 && moduleName[24] == '\0')
	{
		uint16_t ordinal = ordinals[index];
		uint8_t* functionAddress = dllBaseAddress + functions[ordinal];

		__stosb(&NtDll, 0, sizeof(struct NtDllFunctions));

		NtDllBaseAddress = dllBaseAddress;
		NtDll.LdrGetProcedureAddressEx = (LdrGetProcedureAddressEx_t)functionAddress;

		return true;
	}

	++index;

	if (index < numberOfNames) goto NEXT_FUNCTION;
	else return false;
}

// ░░░ Runtime Loaders ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

boolean_t LoadNtClose()
{
	if (NtDllBaseAddress == null) return false;
	if (NtDll.NtClose != null) return true;

	STRING functionName;
	functionName.Buffer = "NtClose";
	functionName.Length = 7;
	functionName.MaximumLength = 8;

	return !NtDll.LdrGetProcedureAddressEx(NtDllBaseAddress, &functionName, null, &NtDll.NtClose, null);
}

boolean_t LoadNtOpenFile()
{
	if (NtDllBaseAddress == null) return false;
	if (NtDll.NtOpenFile != null) return true;

	STRING functionName;
	functionName.Buffer = "NtOpenFile";
	functionName.Length = 10;
	functionName.MaximumLength = 11;

	return !NtDll.LdrGetProcedureAddressEx(NtDllBaseAddress, &functionName, null, &NtDll.NtOpenFile, null);
}

boolean_t LoadLdrLoadDll()
{
	if (NtDllBaseAddress == null) return false;
	if (NtDll.LdrLoadDll != null) return true;

	STRING functionName;
	functionName.Buffer = "LdrLoadDll";
	functionName.Length = 10;
	functionName.MaximumLength = 11;

	return !NtDll.LdrGetProcedureAddressEx(NtDllBaseAddress, &functionName, null, &NtDll.LdrLoadDll, null);
}

boolean_t LoadLdrUnloadDll()
{
	if (NtDllBaseAddress == null) return false;
	if (NtDll.LdrUnloadDll != null) return true;

	STRING functionName;
	functionName.Buffer = "LdrUnloadDll";
	functionName.Length = 12;
	functionName.MaximumLength = 13;

	return !NtDll.LdrGetProcedureAddressEx(NtDllBaseAddress, &functionName, null, &NtDll.LdrUnloadDll, null);
}

boolean_t LoadNtDelayExecution()
{
	if (NtDllBaseAddress == null) return false;
	if (NtDll.NtDelayExecution != null) return true;

	STRING functionName;
	functionName.Buffer = "NtDelayExecution";
	functionName.Length = 16;
	functionName.MaximumLength = 17;

	return !NtDll.LdrGetProcedureAddressEx(NtDllBaseAddress, &functionName, null, &NtDll.NtDelayExecution, null);
}

boolean_t LoadNtWriteFile()
{
	if (NtDllBaseAddress == null) return false;
	if (NtDll.NtWriteFile != null) return true;

	STRING functionName;
	functionName.Buffer = "NtWriteFile";
	functionName.Length = 11;
	functionName.MaximumLength = 12;

	return !NtDll.LdrGetProcedureAddressEx(NtDllBaseAddress, &functionName, null, &NtDll.NtWriteFile, null);
}

boolean_t LoadNtReadFile()
{
	if (NtDllBaseAddress == null) return false;
	if (NtDll.NtReadFile != null) return true;

	STRING functionName;
	functionName.Buffer = "NtReadFile";
	functionName.Length = 10;
	functionName.MaximumLength = 11;

	return !NtDll.LdrGetProcedureAddressEx(NtDllBaseAddress, &functionName, null, &NtDll.NtReadFile, null);
}

boolean_t LoadNtTerminateProcess()
{
	if (NtDllBaseAddress == null) return false;
	if (NtDll.NtTerminateProcess != null) return true;

	STRING functionName;
	functionName.Buffer = "NtTerminateProcess";
	functionName.Length = 18;
	functionName.MaximumLength = 19;

	return !NtDll.LdrGetProcedureAddressEx(NtDllBaseAddress, &functionName, null, &NtDll.NtTerminateProcess, null);
}

boolean_t LoadNtAllocateVirtualMemory()
{
	if (NtDllBaseAddress == null) return false;
	if (NtDll.NtAllocateVirtualMemory != null) return true;

	STRING functionName;
	functionName.Buffer = "NtAllocateVirtualMemory";
	functionName.Length = 23;
	functionName.MaximumLength = 24;

	return !NtDll.LdrGetProcedureAddressEx(NtDllBaseAddress, &functionName, null, &NtDll.NtAllocateVirtualMemory, null);
}

boolean_t LoadNtFreeVirtualMemory()
{
	if (NtDllBaseAddress == null) return false;
	if (NtDll.NtFreeVirtualMemory != null) return true;

	STRING functionName;
	functionName.Buffer = "NtFreeVirtualMemory";
	functionName.Length = 19;
	functionName.MaximumLength = 20;

	return !NtDll.LdrGetProcedureAddressEx(NtDllBaseAddress, &functionName, null, &NtDll.NtFreeVirtualMemory, null);
}

boolean_t LoadRtlTimeToTimeFields()
{
	if (NtDllBaseAddress == null) return false;
	if (NtDll.RtlTimeToTimeFields != null) return true;

	STRING functionName;
	functionName.Buffer = "RtlTimeToTimeFields";
	functionName.Length = 19;
	functionName.MaximumLength = 20;

	return !NtDll.LdrGetProcedureAddressEx(NtDllBaseAddress, &functionName, null, &NtDll.RtlTimeToTimeFields, null);
}

boolean_t LoadNtQueryObject()
{
	if (NtDllBaseAddress == null) return false;
	if (NtDll.NtQueryObject != null) return true;

	STRING functionName;
	functionName.Buffer = "NtQueryObject";
	functionName.Length = 13;
	functionName.MaximumLength = 14;

	return !NtDll.LdrGetProcedureAddressEx(NtDllBaseAddress, &functionName, null, &NtDll.NtQueryObject, null);
}

boolean_t LoadNtDeviceIoControlFile()
{
	if (NtDllBaseAddress == null) return false;
	if (NtDll.NtDeviceIoControlFile != null) return true;

	STRING functionName;
	functionName.Buffer = "NtDeviceIoControlFile";
	functionName.Length = 21;
	functionName.MaximumLength = 22;

	return !NtDll.LdrGetProcedureAddressEx(NtDllBaseAddress, &functionName, null, &NtDll.NtDeviceIoControlFile, null);
}

boolean_t LoadNtQueryInformationFile()
{
	if (NtDllBaseAddress == null) return false;
	if (NtDll.NtQueryInformationFile != null) return true;

	STRING functionName;
	functionName.Buffer = "NtQueryInformationFile";
	functionName.Length = 22;
	functionName.MaximumLength = 23;

	return !NtDll.LdrGetProcedureAddressEx(NtDllBaseAddress, &functionName, null, &NtDll.NtQueryInformationFile, null);
}

boolean_t LoadNtSetInformationFile()
{
	if (NtDllBaseAddress == null) return false;
	if (NtDll.NtSetInformationFile != null) return true;

	STRING functionName;
	functionName.Buffer = "NtSetInformationFile";
	functionName.Length = 20;
	functionName.MaximumLength = 21;

	return !NtDll.LdrGetProcedureAddressEx(NtDllBaseAddress, &functionName, null, &NtDll.NtSetInformationFile, null);
}