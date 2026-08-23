#include "ntdll.h"
#include "testing.h"
#include "console.h"
#include "utility.h"
#include "advapi32.h"      
#include "kernelbase.h"
#include "initialization.h"
#include "resolve_symbols.h"
#include "process_information.h"

/* ------------------------------------------------------------------------------------- */

int32_t Filter(EXCEPTION_POINTERS *ep)
{
	//ep->ExceptionRecord->ExceptionFlags

	_mm_pause();
	//*(uint32_t *)(ep->ContextRecord->Rbp) = 4;
	return 1;
}

static void Test()
{

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
	__except (Filter(_exception_info()))
	{
		_mm_pause();
	}





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

static bool_t ConsoleControlHandler(uint32_t dwCtrlType)
{
	RestoreConsoleMode();

	// show curser
	ConsoleWrite("\x1B[?25h");

	ConsoleWrite("Received Console Signal - Terminating\n");

	NtTerminateProcess((Handle)-1i64, dwCtrlType);
	__assume(0);
}

/* ------------------------------------------------------------------------------------- */

int32_t Main()
{
	if (!ResolveSymbols()) return -1;
	ReadOwnProcessInformation(&ProcessInformation);

	Test();

	/* ------------------------------------------------------------------------------------- */

	if (!EnableXTerm()) return -3;

	if (!SetConsoleCtrlHandler(&ConsoleControlHandler, true))
	{
		//uint32_t errorValue = GetLastError;
		ConsoleWrite("SetConsoleCtrlHandler failed\n");
		return -3;
	}

	IO_STATUS_BLOCK ioStatusBlock = { 0 };

	ConsoleLog("Enabled XTerm!", Info, "Main");
	// WriteConsoleW: Unicode-native, no CP involved — UTF-16LE → conhost renders directly
	ConsoleLogW(u"UTF-16 WriteConsoleW test message: 𐍈 öüäß", 42, Alert, u"Main", 4, ProcessInformation.StandardOutput);
	// WriteConsoleA: internally calls MultiByteToWideChar(GetConsoleOutputCP(), ...) 
	// OutputCP is still system default (e.g. 1252) → UTF-8 bytes misread → yeye ahh ouput
	ConsoleLogA(u8"UTF-8 WriteConsoleA test message: 𐍈 öüäß", 47, Alert, "Main", 4, ProcessInformation.StandardOutput);
	// NtWriteFile: raw byte write, no conversion — conhost interprets per OutputCP
	// OutputCP is 1252 → UTF-16LE bytes treated as 1252 → garbage (coincidental render)
	NtWriteFile(ProcessInformation.StandardOutput, null, null, null, &ioStatusBlock, u"UTF-16 NtWriteFile test message: 𐍈 öüäß\n", 82, 0, null);
	// NtWriteFile: raw byte write — conhost interprets per OutputCP (1252)
	// UTF-8 multibyte sequences misread as 1252 → yeye ahh ouput
	NtWriteFile(ProcessInformation.StandardOutput, null, null, null, &ioStatusBlock, u8"UTF-8 NtWriteFile test message: 𐍈 öüäß\n", 46, 0, null);

	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	ConsoleLogA("Set console in- and output to UTF-8 (CP65001)", 45, Verbose, "Main", 4, ProcessInformation.StandardOutput);

	// WriteConsoleW: unchanged - still Unicode-native, CP irrelevant
	ConsoleLogW(u"UTF-16 WriteConsoleW test message: 𐍈 öüäß", 42, Alert, u"Main", 4, ProcessInformation.StandardOutput);
	// WriteConsoleA: MultiByteToWideChar(65001, ...) → UTF-8 input correctly decoded
	ConsoleLogA(u8"UTF-8 WriteConsoleA test message: 𐍈 öüäß", 47, Alert, "Main", 4, ProcessInformation.StandardOutput);
	// NtWriteFile: raw byte write — conhost now interprets per OutputCP (65001 = UTF-8)
	// UTF-16LE bytes are invalid UTF-8
	NtWriteFile(ProcessInformation.StandardOutput, null, null, null, &ioStatusBlock, u"UTF-16 NtWriteFile test message: 𐍈 öüäß\n", 82, 0, null);
	// NtWriteFile: raw byte write — conhost interprets per OutputCP (65001 = UTF-8)
	// UTF-8 input matches → correctly decoded and rendered
	NtWriteFile(ProcessInformation.StandardOutput, null, null, null, &ioStatusBlock, u8"UTF-8 NtWriteFile test message: 𐍈 öüäß\n", 46, 0, null);

	ConsoleWrite("\n----------------------------------------------------------------\n\n");

	if (!AdjustProcessTokenPrivileges()) return -4;

	/* ------------------------------------------------------------------------------------- */

	THREAD_NAME_INFORMATION nameInformation;
	nameInformation.ThreadName.Buffer = u"Main Thread";
	nameInformation.ThreadName.Length = 22;
	nameInformation.ThreadName.MaximumLength = 24;
	if (NtSetInformationThread((Handle)-2, ThreadNameInformation, &nameInformation, sizeof(THREAD_NAME_INFORMATION))) return -2;

	ConsoleWrite("\n----------------------------------------------------------------\n\n");

	//int64_t delay = 5000 * -10'000;
	//NtDelayExecution(false, &delay);

	PrintArguments(ProcessInformation.CommandLineBuffer, ProcessInformation.StandardOutput);

	ConsoleWrite("----------------------------------------------------------------\n\n");

	ASLR(ProcessInformation.StandardOutput);

	ConsoleWrite("----------------------------------------------------------------\n\n");

	PrintCPUIDInformation();

	ConsoleWrite("----------------------------------------------------------------\n\n");

	//MWaitX();

	//ConsoleWrite("----------------------------------------------------------------\n\n");

	if (!Multithreading())
	{
		RestoreConsoleMode();
		return -5;
	}

	ConsoleWrite("----------------------------------------------------------------\n\n");

	goto SKIP_READLINE;
	uint8_t *buffer = _alloca(258);
AGAIN:
	uint16_t writtenBytes;
	__stosb(buffer, 0, 257);
	ReadLine(buffer, 256, &writtenBytes);

	buffer[writtenBytes] = '\n';
	buffer[writtenBytes + 1] = 0;
	ConsoleWrite((char_t *)buffer);

	if (writtenBytes != 2 || buffer[0] != 'O' || buffer[1] != 'K')
	{
		ConsoleWrite("- - - - - -\n");
		goto AGAIN;
	}
	
	ConsoleWrite("\n----------------------------------------------------------------\n\n");

SKIP_READLINE:

	TestStatusBar(ProcessInformation.StandardOutput);

	ConsoleWrite("\n----------------------------------------------------------------\n\n");

	ConsoleWrite("DONE - exiting\n");
	
	RestoreConsoleMode();
	return 0;
}