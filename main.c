#include "core.h"
#include "ntdll.h"
#include "testing.h"
#include "console.h"
#include "utility.h"
#include "advapi32.h"      
#include "kernelbase.h"
#include "process_information.h"

static void Test()
{
	//UNICODE_STRING unicodeString;
	//unicodeString.Length = 53 << 1;
	//unicodeString.MaximumLength = 54 << 1;
	//unicodeString.Buffer = u"\\??\\C:\\Users\\dev0\\Desktop\\debug_nt_wavecap_buffer.raw";

	//IO_STATUS_BLOCK ioStatusBlock = { 0 };

	//OBJECT_ATTRIBUTES objectAttributes = { 0 };
	//objectAttributes.Length = sizeof(OBJECT_ATTRIBUTES);
	//objectAttributes.ObjectName = &unicodeString;
	//objectAttributes.Attributes = OBJ_CASE_INSENSITIVE;

	//Handle fileHandle = 0;
	//boolean_t success = STATUS_SUCCESS == NtCreateFile(&fileHandle, FILE_WRITE_DATA | SYNCHRONIZE, &objectAttributes, &ioStatusBlock, null, 0, FILE_SHARE_READ, FILE_OVERWRITE_IF, FILE_WRITE_THROUGH | FILE_SEQUENTIAL_ONLY | FILE_SYNCHRONOUS_IO_NONALERT, null, 0);


	//success = STATUS_SUCCESS == NtWriteFile(fileHandle, null, null, null, &ioStatusBlock, "test message", 12, null, null);

	//NtClose(fileHandle);
}

/* ------------------------------------------------------------------------------------- */

int32_t Main()
{
	if (!ResolveSymbols()) return -1;

	int32_t exitCode = 0;

	/* -------------------------------------------------------------------------- */

	if (!EnableAndTestXTermOutput()) return -2;

	if (!AdjustProcessTokenPrivileges())
	{
		exitCode = -4;
		goto ERROR_EXIT;
	}

	THREAD_NAME_INFORMATION nameInformation;
	nameInformation.ThreadName.Buffer = u"Main Thread";
	nameInformation.ThreadName.Length = 22;
	nameInformation.ThreadName.MaximumLength = 24;
	if (NtSetInformationThread((Handle)-2, ThreadNameInformation, &nameInformation, sizeof(THREAD_NAME_INFORMATION))) return -2;

	PrintArguments();

	if (!ASLR())
	{
		exitCode = -5;
		goto ERROR_EXIT;
	}

	PrintCPUIDInformation();

	//TestExceptions();

	if (!Multithreading())
	{
		exitCode = -4;
		goto ERROR_EXIT;
	}













//	goto SKIP_READLINE;
//	uint8_t *buffer = _alloca(258);
//AGAIN:
//	uint16_t writtenBytes;
//	__stosb(buffer, 0, 257);
//	ReadLine(buffer, 256, &writtenBytes);
//
//	buffer[writtenBytes] = '\n';
//	buffer[writtenBytes + 1] = 0;
//	//ConsoleWrite((char_t *)buffer);

	//if (writtenBytes != 2 || buffer[0] != 'O' || buffer[1] != 'K')
	//{
	//	ConsoleWrite(u"- - - - - -\n");
	//	goto AGAIN;
	//}

	ConsoleWrite(u"\n----------------------------------------------------------------\n\n");

//SKIP_READLINE:

	//MWaitX();

	TestStatusBar(OwnProcessInformation.StandardOutput);

	ConsoleWrite(u"\n----------------------------------------------------------------\n\n");

	ConsoleWrite(u"DONE - exiting\n");

ERROR_EXIT:
	RestoreConsoleMode();
	return exitCode;
}