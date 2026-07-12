#include "kernelbase.h"
#include "process_information.h"

static uint32_t _standardInputMode;
static uint32_t _standardOutputMode;

static uint32_t _standardCodePage;
static uint32_t _standardOutputCodePage;

boolean_t EnableXTerm()
{
	_standardCodePage = GetConsoleCP();
	_standardOutputCodePage = GetConsoleOutputCP();

	//if (!SetConsoleCP(65001)) return false;
	//if (!SetConsoleOutputCP(65001)) return false;

	// https://learn.microsoft.com/en-us/windows/console/console-virtual-terminal-sequences
	// TL;DR: use "Virtual Terminal" - old is deprecated - "support will continue for indefinite future"

	uint32_t modeInfo = 0;
	if (!GetConsoleMode(ProcessInformation.StandardInput, &modeInfo)) return false;
	_standardInputMode = modeInfo;
	modeInfo |= ENABLE_VIRTUAL_TERMINAL_INPUT;
	modeInfo &= ~(ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT);
	if (!SetConsoleMode(ProcessInformation.StandardInput, modeInfo)) return false;

	modeInfo = 0;
	if (!GetConsoleMode(ProcessInformation.StandardOutput, &modeInfo)) return false;
	_standardOutputMode = modeInfo;
	modeInfo |= ENABLE_PROCESSED_OUTPUT | ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	if (!SetConsoleMode(ProcessInformation.StandardOutput, modeInfo)) return false;

	return true;
}

void RestoreConsoleMode()
{
	SetConsoleCP(_standardCodePage);
	SetConsoleOutputCP(_standardOutputCodePage);

	SetConsoleMode(ProcessInformation.StandardInput, _standardInputMode);
	SetConsoleMode(ProcessInformation.StandardOutput, _standardOutputMode);
}