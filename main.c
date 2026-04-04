#include "ntdll.h"
#include "testing.h"
#include "console.h"
#include "utility.h"
#include "kernelbase.h"
#include "initialization.h"
#include "resolve_symbols.h"
#include "process_information.h"

static void Test()
{

}

int32_t Main()
{
	if (!ResolveSymbols()) return -1;
	ReadOwnProcessInformation(&ProcessInformation);
	Test();

	THREAD_NAME_INFORMATION nameInformation;
	nameInformation.ThreadName.Buffer = u"Main Thread";
	nameInformation.ThreadName.Length = 22;
	nameInformation.ThreadName.MaximumLength = 24;
	if (NtSetInformationThread((Handle)-2, ThreadNameInformation, &nameInformation, sizeof(THREAD_NAME_INFORMATION))) return -2;

	ConsoleWrite("----------------------------------------------------------------\n\n");

	if (!EnableXTerm(ProcessInformation.StandardOutput, ProcessInformation.StandardInput)) return -3;
	ConsoleLog("Enabled XTerm!", Info, "Main");
	ConsoleLogW(u"UTF-16 WriteConsoleW test message: 𐍈 öüäß", 42, Alert, u"Main", 4, ProcessInformation.StandardOutput);
	ConsoleLogA(u8"UTF-8 WriteConsoleA test message: 𐍈 öüäß", 47, Alert, "Main", 4, ProcessInformation.StandardOutput);

	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	ConsoleLogA("Set console in- and output to UTF-8 (CP65001)", 45, Verbose, "Main", 4, ProcessInformation.StandardOutput);

	ConsoleLogW(u"UTF-16 WriteConsoleW test message: 𐍈 öüäß", 42, Alert, u"Main", 4, ProcessInformation.StandardOutput);
	ConsoleLogA(u8"UTF-8 WriteConsoleA test message: 𐍈 öüäß", 47, Alert, "Main", 4, ProcessInformation.StandardOutput);

	ConsoleWrite("\n----------------------------------------------------------------\n\n");

	if (!AdjustProcessTokenPrivileges(ProcessInformation.StandardOutput)) return -4;

	ConsoleWrite("\n----------------------------------------------------------------\n\n");

	PrintArguments(ProcessInformation.CommandLineBuffer, ProcessInformation.StandardOutput);

	ConsoleWrite("----------------------------------------------------------------\n\n");

	ASLR(ProcessInformation.StandardOutput);

	ConsoleWrite("----------------------------------------------------------------\n\n");

	PrintCPUIDInformation();

	ConsoleWrite("----------------------------------------------------------------\n\n");

	MWaitX();

	ConsoleWrite("----------------------------------------------------------------\n\n");

	if (!Multithreading()) return -5;

	ConsoleWrite("----------------------------------------------------------------\n\n");

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

	ConsoleWrite("DONE - exiting\n");

	return 0;
}