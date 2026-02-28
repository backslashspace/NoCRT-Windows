#include "ntdll.h"
#include "shell32.h"

boolean_t ResolveNtSymbols()
{
	if (!LoadLdrLoadDll()) return false;
	if (!LoadNtWriteFile()) return false;
	if (!LoadRtlTimeToTimeFields()) return false;
	if (!LoadNtSetInformationFile()) return false;
	if (!LoadNtQueryInformationFile()) return false;
	if (!LoadNtAllocateVirtualMemory()) return false;

	return true;
}

boolean_t ResolveShell32Symbols()
{
	if (!InitializeShell32()) return false;

	if (!LoadCommandLineToArgvW()) return false;

	return true;
}