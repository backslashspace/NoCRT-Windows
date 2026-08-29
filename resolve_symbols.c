#include "ntdll.h"
#include "shell32.h"
#include "advapi32.h"
#include "kernelbase.h"

// ░░░ Modules ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

static boolean_t ResolveNtSymbols()
{
	if (!LoadNtClose()) return false;
	if (!LoadLdrLoadDll()) return false;
	if (!LoadNtReadFile()) return false;
	if (!LoadNtWriteFile()) return false;
	if (!LoadNtCreateFile()) return false;
	if (!LoadLdrUnloadDll()) return false;
	if (!LoadNtResumeThread()) return false;
	if (!LoadNtSuspendThread()) return false;
	if (!LoadNtCreateThreadEx()) return false;
	if (!LoadNtDelayExecution()) return false;
	if (!LoadNtYieldExecution()) return false;
	if (!LoadLdrGetDllHandleEx()) return false;
	if (!LoadNtTerminateThread()) return false;
	if (!LoadRtlUnicodeToUTF8N()) return false;
	if (!LoadNtOpenProcessToken()) return false;
	if (!LoadNtGetContextThread()) return false;
	if (!LoadNtSetContextThread()) return false;
	if (!LoadNtFreeVirtualMemory()) return false;
	if (!LoadRtlTimeToTimeFields()) return false;
	if (!Load__C_specific_handler()) return false;
	if (!LoadNtSetInformationFile()) return false;
	if (!LoadNtWaitForSingleObject()) return false;
	if (!LoadNtQueryInformationFile()) return false;
	if (!LoadNtSetInformationThread()) return false;
	if (!LoadNtAllocateVirtualMemory()) return false;
	if (!LoadNtAdjustPrivilegesToken()) return false;
	if (!LoadNtQueryInformationToken()) return false;
	if (!LoadRtlAddVectoredContinueHandler()) return false;
	if (!LoadRtlAddVectoredExceptionHandler()) return false;
	if (!LoadRtlSetUnhandledExceptionFilter()) return false;
	if (!LoadRtlRemoveVectoredContinueHandler()) return false;
	if (!LoadRtlRemoveVectoredExceptionHandler()) return false;

	return true;
}

static boolean_t LoadAndResolveAdvapi32Symbols()
{
	if (!InitializeAdvapi32()) return false;

	if (!LoadLookupPrivilegeNameW()) return false;
	if (!LoadLookupPrivilegeValueW()) return false;

	return true;
}

static boolean_t LoadAndResolveKernelbaseSymbols()
{
	if (!InitializeKernelbase()) return false;

	if (!LoadGetConsoleCP()) return false;
	if (!LoadSetConsoleCP()) return false;
	if (!LoadWriteConsoleA()) return false;
	if (!LoadWriteConsoleW()) return false;
	if (!LoadGetConsoleMode()) return false;
	if (!LoadSetConsoleMode()) return false;
	if (!LoadGetConsoleOutputCP()) return false;
	if (!LoadSetConsoleOutputCP()) return false;
	if (!LoadSetConsoleCtrlHandler()) return false;

	return true;
}

// ░░░ Loader ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

boolean_t ResolveSymbols()
{
	if (!ResolveNtSymbols()) return false;
	if (!LoadAndResolveKernelbaseSymbols()) return false;

	return true;
}