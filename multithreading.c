#include "ntdll.h"
#include "console.h"
#include "testing.h"
#include "intrinsics.h"

/* -------------------------------------------------------------------------- */

#define STACK_SIZE (2 * 1'024 * 1'024)

typedef struct LARGE_STACK_THREAD_START_PARAMETER
{
	uint64_t StackSize;
	uint8_t *StackMemory;
	uint64_t Argument;
	NtStatus (*Procedure)(void *argument);
	uint64_t volatile Flag;	// set to non zero when done reading this structure
	NtTerminateThread_t NtTerminateThread;
} LARGE_STACK_THREAD_START_PARAMETER;

__declspec(noreturn) NtStatus LargeStackThreadEntry(LARGE_STACK_THREAD_START_PARAMETER *threadStartParameter);

/* -------------------------------------------------------------------------- */

boolean_t Multithreading()
{
	ConsoleWrite(u"# Multithreading\n\n");

	uint8_t *threadStack = null;
	uint64_t size = STACK_SIZE;
	if (STATUS_SUCCESS != NtAllocateVirtualMemory((Handle)-1i64, &threadStack, null, &size, MEM_RESERVE | MEM_COMMIT | MEM_LARGE_PAGES, PAGE_READWRITE))
	{
		ConsoleWrite(u"NtAllocateVirtualMemory failed to allocate large pages\n");
		return false;
	}

	/* ---------------------------------------------------------------------------------- */

	Handle threadHandle;
	LARGE_STACK_THREAD_START_PARAMETER threadStartParameter;
	threadStartParameter.Flag = 0;
	threadStartParameter.Procedure = &LargePageStackTestThreadMain;
	threadStartParameter.Argument = 42067;	
	threadStartParameter.StackSize = STACK_SIZE;
	threadStartParameter.StackMemory = threadStack;
	threadStartParameter.NtTerminateThread = NtDll.NtTerminateThread;
	if (STATUS_SUCCESS != NtCreateThreadEx(&threadHandle, THREAD_ALL_ACCESS, null, (Handle)-1i64, &LargeStackThreadEntry, &threadStartParameter, THREAD_CREATE_FLAGS_SKIP_THREAD_ATTACH | THREAD_CREATE_FLAGS_CREATE_SUSPENDED, 0, 4096, 4096, null))
	{
		ConsoleWrite(u"[MAIN] Failed to create thread\n");
		return false;
	}
	ConsoleWrite(u"[MAIN] Starting worker thread\n");

	_mm_lfence();
	uint64_t now = __rdtsc();
	_mm_lfence();

	if (STATUS_SUCCESS != NtResumeThread(threadHandle, null))
	{
		ConsoleWrite(u"[MAIN] Failed to start thread\n");
		return false;
	}

	// wait for thread to consume THREAD_START_PARAMETER
	while (!threadStartParameter.Flag) _mm_pause();
	// returning is safe now - since THREAD_START_PARAMETER was already read

	if (STATUS_SUCCESS != NtWaitForSingleObject(threadHandle, false, null))
	{
		ConsoleWrite(u"[MAIN] Failed to wait for thread to end\n");
		return false;
	}
	NtClose(threadHandle);

	ConsoleWrite(u"[MAIN] Thread exited\n");

	size = 0;

	ConsoleWrite(u"\n----------------------------------------------------------------\n\n");

	return !NtFreeVirtualMemory((Handle)-1, &threadStack, &size, MEM_RELEASE);
}