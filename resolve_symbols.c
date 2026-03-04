#include "ntdll.h"
#include "shell32.h"
#include "advapi32.h"

boolean_t ResolveNtSymbols()
{
	if (!LoadLdrLoadDll()) return false;
	if (!LoadNtWriteFile()) return false;
	if (!LoadNtOpenProcessToken()) return false;
	if (!LoadRtlTimeToTimeFields()) return false;
	if (!LoadNtSetInformationFile()) return false;
	if (!LoadNtQueryInformationFile()) return false;
	if (!LoadNtAllocateVirtualMemory()) return false;
	if (!LoadNtAdjustPrivilegesToken()) return false;
	if (!LoadNtQueryInformationToken()) return false;

	return true;
}

boolean_t ResolveShell32Symbols()
{
	if (!InitializeShell32()) return false;

	if (!LoadCommandLineToArgvW()) return false;

	return true;
}

boolean_t LoadAndResolveAdvapi32Symbols()
{
	if (!InitializeAdvapi32()) return false;

	if (!LoadLookupPrivilegeNameW()) return false;
	if (!LoadLookupPrivilegeValueW()) return false;

	return true;
}