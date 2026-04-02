#include "ntdll.h"
#include "testing.h"
#include "console.h"
#include "utility.h"
#include "kernelbase.h"
#include "initialization.h"
#include "resolve_symbols.h"
#include "process_information.h"

struct test
{
	uint64_t gurt[8];
} gurtinger;


void TestASM(void *cacheLine);

static void Test()
{
	//_mm_monitorx(&gurtinger, 0, 0);
	//TestASM(&gurtinger);
}

int32_t Main()
{
	if (!ResolveSymbols()) return false;
	ReadOwnProcessInformation(&ProcessInformation);
	Test();

	ConsoleWrite("----------------------------------------------------------------\n\n");

	if (!EnableXTerm(ProcessInformation.StandardOutput, ProcessInformation.StandardInput)) return -1;
	ConsoleLog("Enabled XTerm!", Info, "Main");
	ConsoleLogW(u"UTF-16 WriteConsoleW test message: 𐍈 öüäß", 42, Alert, u"Main", 4, ProcessInformation.StandardOutput);
	ConsoleLogA(u8"UTF-8 WriteConsoleA test message: 𐍈 öüäß", 47, Alert, "Main", 4, ProcessInformation.StandardOutput);

	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	ConsoleLogA("Set console in- and output to UTF-8 (CP65001)", 45, Verbose, "Main", 4, ProcessInformation.StandardOutput);

	ConsoleLogW(u"UTF-16 WriteConsoleW test message: 𐍈 öüäß", 42, Alert, u"Main", 4, ProcessInformation.StandardOutput);
	ConsoleLogA(u8"UTF-8 WriteConsoleA test message: 𐍈 öüäß", 47, Alert, "Main", 4, ProcessInformation.StandardOutput);

	ConsoleWrite("\n----------------------------------------------------------------\n\n");

	if (!AdjustProcessTokenPrivileges(ProcessInformation.StandardOutput)) return false;

	ConsoleWrite("\n----------------------------------------------------------------\n\n");

	PrintArguments(ProcessInformation.CommandLineBuffer, ProcessInformation.StandardOutput);

	ConsoleWrite("----------------------------------------------------------------\n\n");

	ASLR(ProcessInformation.StandardOutput);

	ConsoleWrite("----------------------------------------------------------------\n\n");

	PrintCPUIDInformation();

	ConsoleWrite("----------------------------------------------------------------\n\n");

//	uint8_t *buffer = _alloca(258);
//AHH:
//	uint16_t writtenBytes;
//	__stosb(buffer, 0, 257);
//	ReadLine(buffer, 256, &writtenBytes);
//
//	buffer[writtenBytes] = '\n';
//	buffer[writtenBytes + 1] = 0;
//	ConsoleWrite((char_t *)buffer);
//	goto AHH;

	ConsoleWrite("----------------------------------------------------------------\n\n");

	if (!Multithreading()) return -1;

	ConsoleWrite("----------------------------------------------------------------\n\n");

	return 0;
}