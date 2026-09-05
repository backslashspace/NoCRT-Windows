#include "ntdll.h"
#include "console.h"

typedef __declspec(align(64)) union CACHE_LINE
{
	boolean_t volatile Flag;
	uint8_t volatile Byte[64];
	uint16_t volatile UInt16[32];
	uint32_t volatile UInt32[16];
	uint64_t volatile UInt64[8];
} CACHE_LINE;
_Static_assert(_Alignof(CACHE_LINE) == 64, "CACHE_LINE struct was NOT 64 byte aligned.");

void MWaitXSpinWait(boolean_t volatile *address);

NtStatus WaitingWorker(boolean_t *argument)
{
	CACHE_LINE *cacheLine = (CACHE_LINE *)argument;

	__try
	{
		ConsoleWrite(u"[Worker] waiting for flag to be set with MONITORX & MWAITX\n");
		MWaitXSpinWait(&cacheLine->Flag);
		ConsoleWrite(u"[Worker] flag was set\n");
	}
#pragma warning(push)
#pragma warning(disable:6320)
	__except (EXCEPTION_EXECUTE_HANDLER)
#pragma warning(pop)
	{
		ConsoleWrite(u"MWaitXSpinWait error - not supported?\n");
	}

	return 0;
}


void TestMWaitXSpinWait()
{
	ConsoleWrite(u"# MWAITX SpinWait Test\n\n");

	CACHE_LINE cacheLine = { 0 };

	Handle threadHandle;
	if (STATUS_SUCCESS != NtCreateThreadEx(&threadHandle, THREAD_ALL_ACCESS, null, (Handle)-1i64, &WaitingWorker, &cacheLine, THREAD_CREATE_FLAGS_SKIP_THREAD_ATTACH | THREAD_CREATE_FLAGS_CREATE_SUSPENDED, 0, 4096, 4096, null))
	{
		ConsoleWrite(u"[Main] Failed to create thread\n");
		return;
	}
	ConsoleWrite(u"[Main] Starting worker thread\n");

	if (STATUS_SUCCESS != NtResumeThread(threadHandle, null))
	{
		ConsoleWrite(u"[Main] Failed to start thread\n");
		return;
	}

	int64_t delay = 4'000 * -10'000;
	NtDelayExecution(false, &delay);

	cacheLine.Flag = true;

	if (STATUS_SUCCESS != NtWaitForSingleObject(threadHandle, false, null))
	{
		ConsoleWrite(u"[Main] Failed to wait for thread to end\n");
		return;
	}
	NtClose(threadHandle);

	ConsoleWrite(u"[Main] Thread exited\n");

	ConsoleWrite(u"\n----------------------------------------------------------------\n\n");
}