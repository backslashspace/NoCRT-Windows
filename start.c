#pragma message("==================================================================================================\n__chkstk has no functionality\nMust commit stack stack pages MANUALLY by touching guard pages OR use stack reserve = stack commit\nhttps://learn.microsoft.com/en-us/windows/win32/devnotes/-win32-__chkstk\n==================================================================================================")

#include "ntdll.h"
#include "intrinsics.h"

// ░░░ Forward Declarations ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

int32_t Main();

// ░░░ Entry ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

__declspec(noreturn) void Start()
{
	if (!InitializeNtDll()) __fastfail(FAST_FAIL_FATAL_APP_EXIT);
	if (!LoadNtTerminateProcess()) __fastfail(FAST_FAIL_FATAL_APP_EXIT);

	int32_t exitCode = Main();

	NtTerminateProcess((Handle)-1i64, exitCode);
}