#include "ntdll.h"
#include "intrinsics.h"

static int32_t VectorHandler(EXCEPTION_POINTERS *ExceptionInfo)
{
	//ep->ExceptionRecord->ExceptionFlags

	_mm_pause();
	//*(uint32_t *)(ep->ContextRecord->Rbp) = 4;
	return EXCEPTION_CONTINUE_SEARCH;
}

static int32_t SEHFilter(EXCEPTION_POINTERS *ep)
{
	//ep->ExceptionRecord->ExceptionFlags

	_mm_pause();
	//*(uint32_t *)(ep->ContextRecord->Rbp) = 4;
	return EXCEPTION_EXECUTE_HANDLER;
}

static int32_t VectorContinueHandler(EXCEPTION_POINTERS *ExceptionInfo)
{
	//ep->ExceptionRecord->ExceptionFlags

	_mm_pause();
	//*(uint32_t *)(ep->ContextRecord->Rbp) = 4;
	return EXCEPTION_CONTINUE_SEARCH;
}

static int32_t VectorContinueHandler2(EXCEPTION_POINTERS *ExceptionInfo)
{
	//ep->ExceptionRecord->ExceptionFlags

	_mm_pause();
	//*(uint32_t *)(ep->ContextRecord->Rbp) = 4;
	return EXCEPTION_CONTINUE_SEARCH;
}

static int32_t UnhandledSEHFilter(EXCEPTION_POINTERS *ExceptionInfo)
{
	//ep->ExceptionRecord->ExceptionFlags

	_mm_pause();
	//*(uint32_t *)(ep->ContextRecord->Rbp) = 4;
	return EXCEPTION_CONTINUE_EXECUTION;
}

/* ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░ */

void TestExceptions()
{
	RtlSetUnhandledExceptionFilter(&UnhandledSEHFilter);

	if (!RtlAddVectoredExceptionHandler(false, &VectorHandler))
	{
		__fastfail(1);
	}

	if (!RtlAddVectoredContinueHandler(false, &VectorContinueHandler))
	{
		__fastfail(1);
	}

	if (!RtlAddVectoredContinueHandler(false, &VectorContinueHandler2))
	{
		__fastfail(1);
	}

	// seh

	__try
	{
		__try
		{
			int ddd = 2 - 2;

			int a = 44 / ddd;

			int sd = a + 4;
		}
		__finally
		{
			unsigned int test = _abnormal_termination();
			test = +2;
		}
	}
	__except (SEHFilter(_exception_info()))
	{
		_mm_pause();
	}

	_mm_pause();
}