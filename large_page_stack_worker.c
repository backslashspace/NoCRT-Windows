#include "ntdll.h"
#include "console.h"
#include "testing.h"

NtStatus LargePageStackTestThreadMain(void *argument)
{
	__try
	{
		THREAD_NAME_INFORMATION nameInformation;
		nameInformation.ThreadName.Buffer = u"Large Stack Test Worker Thread";
		nameInformation.ThreadName.Length = 60;
		nameInformation.ThreadName.MaximumLength = 62;
		if (NtSetInformationThread((Handle)-2, ThreadNameInformation, &nameInformation, sizeof(THREAD_NAME_INFORMATION)))
		{
			ConsoleWrite(u"[WORKER] NtSetInformationThread failed");
			return -2;
		}

		wchar_t string[21];
		uint16_t length = UInt64ToWChar((uint64_t)argument, string);
		string[20] = u'\n';
		ConsoleWrite(u"[WORKER] Message from worker thread: argument was ");
		ConsoleWrite(string + 20 - length);

		TestExceptions();

		return (NtStatus)argument;
	}
#pragma warning(push)
#pragma warning(disable:6320)
	__except (EXCEPTION_EXECUTE_HANDLER)
#pragma warning(pop)
	{
		ConsoleWrite(u"LargePageStackTestThreadMain failed somewhere, return -1");
		return -1;
	}
}