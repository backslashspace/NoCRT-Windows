#include "console.h"

static bool_t ConsoleControlHandler(uint32_t dwCtrlType)
{
	RestoreConsoleMode();

	// show curser
	ConsoleWrite(u"\x1B[?25h");

	ConsoleWrite(u"Received a Console Signal - Terminating\n");

	NtTerminateProcess((Handle)-1i64, dwCtrlType);
	__assume(0);
}

// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

boolean_t EnableAndTestXTermOutput()
{
	if (!EnableXTerm()) return false;
	ConsoleLog("Enabled XTerm!", Info, "Main");

	if (!SetConsoleCtrlHandler(&ConsoleControlHandler, true))
	{
		//uint32_t errorValue = GetLastError;
		ConsoleWrite(u"SetConsoleCtrlHandler failed\n");
		return false;
	}
	ConsoleLog("Registered ConsoleCtrlHandler", Info, "Main");

	/* -------------------------------------------------------------------------- */

	// output testing
	// default is CP1252 (depends)

	IO_STATUS_BLOCK ioStatusBlock = { 0 };

	// WriteConsoleW: Unicode-native - no conversion - UTF-16LE → conhost renders directly
	ConsoleLogW(u"UTF-16 WriteConsoleW test message: 𐍈 öüäß", 42, Alert, u"Main", 4, OwnProcessInformation.StandardOutput);

	// WriteConsoleA: internally calls MultiByteToWideChar(GetConsoleOutputCP(), ...) 
	// was send UTF-8 string - was read as Windows1252 → yeye ahh output
	ConsoleLogA(u8"UTF-8 WriteConsoleA test message: 𐍈 öüäß", 47, Alert, "Main", 4, OwnProcessInformation.StandardOutput);

	// NtWriteFile: raw byte write, no conversion — conhost interprets per OutputCP
	// display UTF-16LE as Windows1252: null chars get skipped on new Windows Terminal
	NtWriteFile(OwnProcessInformation.StandardOutput, null, null, null, &ioStatusBlock, u"UTF-16 NtWriteFile test message: 𐍈 öüäß\n", 82, 0, null);

	// NtWriteFile: raw byte write — conhost interprets per OutputCP
	// display UTF-8 as Windows1252 → yeye ahh output
	NtWriteFile(OwnProcessInformation.StandardOutput, null, null, null, &ioStatusBlock, u8"UTF-8 NtWriteFile test message: 𐍈 öüäß\n", 46, 0, null);

	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	ConsoleLogA("Set console in- and output to UTF-8 (CP65001)", 45, Verbose, "Main", 4, OwnProcessInformation.StandardOutput);

	// WriteConsoleW: unchanged - Unicode-native
	ConsoleLogW(u"UTF-16 WriteConsoleW test message: 𐍈 öüäß", 42, Alert, u"Main", 4, OwnProcessInformation.StandardOutput);

	// converter expects UTF-8, we send UTF-8 → OK
	ConsoleLogA(u8"UTF-8 WriteConsoleA test message: 𐍈 öüäß", 47, Alert, "Main", 4, OwnProcessInformation.StandardOutput);

	// NtWriteFile: raw byte write, no conversion — conhost interprets per OutputCP
	// UTF-16LE bytes are invalid UTF-8
	NtWriteFile(OwnProcessInformation.StandardOutput, null, null, null, &ioStatusBlock, u"UTF-16 NtWriteFile test message: 𐍈 öüäß\n", 82, 0, null);

	// NtWriteFile: raw byte write, no conversion — conhost interprets per OutputCP
	// converter expects UTF-8, we send UTF-8 → OK
	NtWriteFile(OwnProcessInformation.StandardOutput, null, null, null, &ioStatusBlock, u8"UTF-8 NtWriteFile test message: 𐍈 öüäß\n", 46, 0, null);

	ConsoleWrite(u"\n----------------------------------------------------------------\n\n");

	return true;
}