#include "ntdll.h"
#include "shell32.h"
#include "advapi32.h"
#include "kernelbase.h"

boolean_t ResolveNtSymbols()
{
	if (!LoadNtClose()) return false;
	if (!LoadLdrLoadDll()) return false;
	if (!LoadNtReadFile()) return false;
	if (!LoadNtWriteFile()) return false;
	if (!LoadNtResumeThread()) return false;
	if (!LoadNtSuspendThread()) return false;
	if (!LoadNtCreateThreadEx()) return false;
	if (!LoadNtDelayExecution()) return false;
	if (!LoadNtYieldExecution()) return false;
	if (!LoadNtTerminateThread()) return false;
	if (!LoadNtOpenProcessToken()) return false;
	if (!LoadNtGetContextThread()) return false;
	if (!LoadNtSetContextThread()) return false;
	if (!LoadRtlTimeToTimeFields()) return false;
	if (!LoadNtSetInformationFile()) return false;
	if (!LoadNtWaitForSingleObject()) return false;
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

boolean_t LoadAndResolveKernelbaseSymbols()
{
	if (!InitializeKernelbase()) return false;

	if (!LoadGetConsoleMode()) return false;
	if (!LoadSetConsoleMode()) return false;

	return true;
}