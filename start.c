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

	NtTerminateProcess((Handle)-1, exitCode);
}

/* ░░░ Error Handling ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

 FastFail, Security Cookie, CFG, Heap Corruption
	- bypasses all
	- exit

 debugger first chance

 VEH - (Process):
	- handler must be registered (RtlAdd/RemoveVectoredExceptionHandler)
	- run in list order: RtlAddVectoredExceptionHandler(First != 0) inserts at head
	- handler can exit outright (NtTerminateProcess)
	- handler can return 0 (none -1) = pass on: next VEH, then SEH
	- handler can return -1 = fix context and retry -> goto RETRY (skip other) | retry not possible EXCEPTION_NONCONTINUABLE is set

 SEH (Thread):
	- when any call in __try faults, the filter is executed
	- filter returns 0, no unwinding, search continues to the next enclosing filter, if none return 1 the UEF handles it
	- filter returns 1, each __finally block runs, then the __except block runs
	- filter returns -1, the filter could have fixed the context -> goto RETRY

	- needs: __C_specific_handler
	- nice to haves: EXCEPTION_POINTERS *_exception_info();

 UEF = last SEH frame:
	- ntdll filter is called
		- slot default = kernelbase!UnhandledExceptionFilter, set by kernelbase init
		- kernelbase!UnhandledExceptionFilter calls the kernelbase SetUnhandledExceptionFilter callback (user set-able) (nested inside, not instead of), then WER if it returns 0
		- slot replaceable via RtlSetUnhandledExceptionFilter -> bypasses kernelbase
	- user registered ntdll should call RtlUnhandledExceptionFilter(2) to restore WER behaviour after custom code
	- filter returns 1, it unwinds to RtlUserThreadStart -> its __except block terminates the process
	- filter returns 0, debugger second chance -> kernel terminates, no unwind
	- filter returns -1, the filter could have fixed the context -> goto RETRY

 RETRY:
	- all registered VectoredContinueHandler run (RtlAdd/RemoveVectoredContinueHandler)
	- a registered handler can return -1 to skip the ones after it
	- continues and re-execute faulting instruction with (maybe) modified context

*/