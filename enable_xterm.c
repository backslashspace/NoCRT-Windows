#include "kernelbase.h"

boolean_t EnableXTerm(Handle const standardOutput, Handle const standardInput)
{
	// https://learn.microsoft.com/en-us/windows/console/console-virtual-terminal-sequences
	// TL;DR: use "Virtual Terminal" - old is deprecated - "support will continue for indefinite future"

	uint32_t modeInfo = 0;
	if (!GetConsoleMode(standardOutput, &modeInfo)) return false;
	modeInfo |= ENABLE_PROCESSED_OUTPUT | ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	if (!SetConsoleMode(standardOutput, modeInfo)) return false;

	modeInfo = 0;
	if (!GetConsoleMode(standardInput, &modeInfo)) return false;
	modeInfo |= ENABLE_VIRTUAL_TERMINAL_INPUT;
	modeInfo &= ~(ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT);
	if (!SetConsoleMode(standardInput, modeInfo)) return false;

	return true;
}