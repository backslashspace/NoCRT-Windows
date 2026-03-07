#include "ntdll.h"
#include "console.h"
#include "intrinsics.h"

typedef struct THREAD_START_PARAMETER
{
	void *StackBase; // base is bottom of buffer - stack grows down - StackBase = buffer + bufferSize - must be 16 byte aligned
	uint64_t Argument;
} THREAD_START_PARAMETER;

NtStatus ThreadEntry(THREAD_START_PARAMETER *threadStartParameter);

NtStatus TestThreadMain(uint64_t value)
{
	ConsoleWrite("Test Thread: entry\n");
	ConsoleWrite("Test Thread: message from thread with large page stack (hell yeah)\n");

	_mm_pause();

	ConsoleWrite("Test Thread: enter sleep\n");
	int64_t delay = -10'000 * 3'000;
	if (STATUS_SUCCESS != NtDelayExecution(false, &delay))
	{
		ConsoleWrite("Failed to sleep\n");
		return;
	}
	ConsoleWrite("Test Thread: exited sleep\n");

	_mm_pause();

	ConsoleWrite("Test Thread: exiting\n");

	value += 420;

	return (NtStatus)value;
}

#define STACK_SIZE (2 * 1'024 * 1'024)

boolean_t Multithreading()
{
	ConsoleWrite("# Multithreading\n");

	uint8_t *memory = null;
	uint64_t size = STACK_SIZE;
	if (STATUS_SUCCESS != NtAllocateVirtualMemory((Handle)-1i64, &memory, null, &size, MEM_RESERVE | MEM_COMMIT | MEM_LARGE_PAGES, PAGE_READWRITE))
	{
		ConsoleWrite("NtAllocateVirtualMemory failed to allocate large pages\n");
		return false;
	}

	/* ---------------------------------------------------------------------------------- */

	Handle threadHandle;
	THREAD_START_PARAMETER threadStartParameter;
	threadStartParameter.Argument = 0xdeadbeef;	
	threadStartParameter.StackBase = memory + STACK_SIZE;
	if (STATUS_SUCCESS != NtCreateThreadEx(&threadHandle, THREAD_ALL_ACCESS, null, (Handle)-1i64, &ThreadEntry, &threadStartParameter, THREAD_CREATE_FLAGS_SKIP_THREAD_ATTACH | THREAD_CREATE_FLAGS_CREATE_SUSPENDED, 0, 4096, 4096, null))
	{
		ConsoleWrite("Failed to create thread\n");
		return false;
	}

	ConsoleWrite("Starting thread");
	if (STATUS_SUCCESS != NtResumeThread(threadHandle, null))
	{
		ConsoleWrite("Failed to start thread\n");
		return false;
	}
	ConsoleWrite("Started thread\n");

	//CONTEXT context;
	//context.ContextFlags = CONTEXT_ALL;
	//if (STATUS_SUCCESS != NtGetContextThread(threadHandle, &context))
	//{
	//	ConsoleWrite("Failed to get thread context");
	//	return;
	//}
	//context.R15 = 0xdeadbeef;
	//if (STATUS_SUCCESS != NtSetContextThread(threadHandle, &context))
	//{
	//	ConsoleWrite("Failed to set thread context");
	//	return;
	//}

	//if (STATUS_SUCCESS != NtResumeThread(threadHandle, null))
	//{
	//	ConsoleWrite("Failed to start thread");
	//	return;
	//}

	ConsoleWrite("Waiting for thread to end\n");
	if (STATUS_SUCCESS != NtWaitForSingleObject(threadHandle, false, null))
	{
		ConsoleWrite("Failed to wait for thread to end\n");
		return false;
	}
	NtClose(threadHandle);

	ConsoleWrite("Thread exited\n\n");
	return true;
}