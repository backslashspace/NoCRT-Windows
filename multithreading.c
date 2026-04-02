#include "ntdll.h"
#include "console.h"
#include "intrinsics.h"

typedef struct THREAD_START_PARAMETER
{
	NtTerminateThread_t NtTerminateThread;
	void *StackBase; // base is bottom of buffer - stack grows down - StackBase = buffer + bufferSize - must be 16 byte aligned
	uint64_t Argument;
	uint64_t volatile Flag;	// will turn non 0 when entry stub is reached
	NtStatus (*ThreadMain)(void *argument);
} THREAD_START_PARAMETER;

// thread entry via asm - to set RSP
__declspec(noreturn) NtStatus ThreadEntry(THREAD_START_PARAMETER *threadStartParameter);

// called by 
NtStatus TestThreadMain(void *argument)
{
	THREAD_NAME_INFORMATION nameInformation;
	nameInformation.ThreadName.Buffer = u"Test Worker Thread";
	nameInformation.ThreadName.Length = 36;
	nameInformation.ThreadName.MaximumLength = 38;
	NtStatus status = NtSetInformationThread((Handle)-2, ThreadNameInformation, &nameInformation, sizeof(THREAD_NAME_INFORMATION));

	char_t *string = _alloca(21);
	string[20] = '\n';
	uint16_t length = UInt64ToChar((uint64_t)argument, string);
	ConsoleWrite("Message from worker thread: argument was ");
	ConsoleWrite(string + 20 - length);

	return status;
}

#define STACK_SIZE (2 * 1'024 * 1'024)

boolean_t Multithreading()
{
	ConsoleWrite("# Multithreading\n\n");

	uint8_t *threadStack = null;
	uint64_t size = STACK_SIZE;
	if (STATUS_SUCCESS != NtAllocateVirtualMemory((Handle)-1i64, &threadStack, null, &size, MEM_RESERVE | MEM_COMMIT | MEM_LARGE_PAGES, PAGE_READWRITE))
	{
		ConsoleWrite("NtAllocateVirtualMemory failed to allocate large pages\n");
		return false;
	}

	/* ---------------------------------------------------------------------------------- */

	Handle threadHandle;
	THREAD_START_PARAMETER threadStartParameter;
	threadStartParameter.Flag = 0;
	threadStartParameter.Argument = 42067;	
	threadStartParameter.StackBase = threadStack + STACK_SIZE;
	threadStartParameter.NtTerminateThread = NtDll.NtTerminateThread;
	if (STATUS_SUCCESS != NtCreateThreadEx(&threadHandle, THREAD_ALL_ACCESS, null, (Handle)-1i64, &ThreadEntry, &threadStartParameter, THREAD_CREATE_FLAGS_SKIP_THREAD_ATTACH | THREAD_CREATE_FLAGS_CREATE_SUSPENDED, 0, 4096, 4096, null))
	{
		ConsoleWrite("Failed to create thread\n");
		return false;
	}
	ConsoleWrite("Starting worker thread\n");

	_mm_lfence();
	uint64_t now = __rdtsc();
	_mm_lfence();

	if (STATUS_SUCCESS != NtResumeThread(threadHandle, null))
	{
		ConsoleWrite("Failed to start thread\n");
		return false;
	}

	// wait for thread to consume THREAD_START_PARAMETER
	while (!threadStartParameter.Flag) _mm_pause();
	// returning is safe now - since THREAD_START_PARAMETER was on the stack

	if (STATUS_SUCCESS != NtWaitForSingleObject(threadHandle, false, null))
	{
		ConsoleWrite("Failed to wait for thread to end\n");
		return false;
	}
	NtClose(threadHandle);

	ConsoleWrite("Thread exited\n\n");

	size = 0;
	return !NtFreeVirtualMemory((Handle)-1, &threadStack, &size, MEM_RELEASE);
}