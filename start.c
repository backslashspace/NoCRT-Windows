#include "ntdll.h"
#include "intrinsics.h"
#include "process_information.h"

// ░░░ Forward Declarations ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

int32_t Main();

// ░░░ Entry ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

__declspec(noreturn) void Start()
{
	if (!InitializeNtDll()) __fastfail(FAST_FAIL_FATAL_APP_EXIT);
	if (!LoadNtTerminateProcess()) __fastfail(FAST_FAIL_FATAL_APP_EXIT);

	ReadOwnProcessInformation();

	int32_t exitCode = Main();

	NtTerminateProcess((Handle)-1, exitCode);
	__assume(0);
}