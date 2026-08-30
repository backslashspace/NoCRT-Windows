#include "ntdll.h"
#include "console.h"
#include "kernelbase.h"

void TestStatusBar(Handle const outputHandle)
{
	IO_STATUS_BLOCK ioStatusBlock = { 0 };

	ConsoleWrite(u"10 seconds, update every 100ms\n");

	int64_t delay = 100 * -10'000;
	
	ConsoleWrite(u"╔═══════════════════════════════╗\n");
	ConsoleWrite(u"║ Data Point 1: 0               ║\n");
	ConsoleWrite(u"║ Progress: 000%                ║\n");
	ConsoleWrite(u"║ ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░ ║\n");
	ConsoleWrite(u"╚═══════════════════════════════╝\n");

	NtDelayExecution(false, &delay);

	uint64_t datapoint = 0;
	uint16_t pos = 0;
	uint16_t lastPos = 0;
	uint64_t progresss = 0;

	char_t *string = _alloca(20);
	uint16_t stringLength;

	// hide curser
	NtWriteFile(outputHandle, null, null, null, &ioStatusBlock, "\x1B[?25l", 6, null, null);

AGAIN:
	// set Data Point 1: x
	__stosb(string, ' ', 20);
	stringLength = UInt64ToChar(datapoint, string);
	NtWriteFile(outputHandle, null, null, null, &ioStatusBlock, "\x1B[4A\r\x1B[16C", 10, null, null);
	NtWriteFile(outputHandle, null, null, null, &ioStatusBlock, string + 20 - stringLength, stringLength, null, null);

	// set progress %
	string[16] = '0';
	string[17] = '0';
	string[18] = '0';
	string[19] = '%';
	stringLength = UInt64ToChar(progresss, string - 1);
	NtWriteFile(outputHandle, null, null, null, &ioStatusBlock, "\x1B[1B\r\x1B[12C", 10, null, null);
	NtWriteFile(outputHandle, null, null, null, &ioStatusBlock, string + 16, 4, null, null);

	// set visual bar
	pos = (uint16_t)((29 * progresss) / 100);
	if (pos != lastPos)
	{
		lastPos = pos;
		string[18] = '0';
		string[19] = '0';
		stringLength = UInt64ToChar(pos + 1, string);
		char_t barMod[] = "\x1B[1B\r\x1B[##C";
		barMod[7] = string[18];
		barMod[8] = string[19];
		NtWriteFile(outputHandle, null, null, null, &ioStatusBlock, barMod, 10, null, null);
		NtWriteFile(outputHandle, null, null, null, &ioStatusBlock, u8"█", 3, null, null);
	}
	else
	{
		NtWriteFile(outputHandle, null, null, null, &ioStatusBlock, "\x1B[1B\r", 5, null, null);
	}

	NtWriteFile(outputHandle, null, null, null, &ioStatusBlock, "\x1B[2B\r", 5, null, null);

	NtDelayExecution(false, &delay);
	if (progresss != 100)
	{
		++progresss;
		datapoint += 1345;
		goto AGAIN;
	}

	// show curser
	NtWriteFile(outputHandle, null, null, null, &ioStatusBlock, u8"\x1B[?25h", 6, null, null);
}