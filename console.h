#pragma once
#include "types.h"
#include "utility.h"
#include "kernelbase.h"
#include "process_information.h"

typedef enum LogLevel
{
    Debug = 0,      // green
    Verbose = 1,    // magenta
    Info = 2,       // cyan
    Warning = 3,    // yellow
    Alert = 4,      // yellow
    Error = 5,      // red
    Critical = 6,   // red
} LogLevel;

boolean_t EnableXTerm(Handle const standardOutput, Handle const standardInput);

boolean_t ReadLine(uint8_t *const restrict buffer, uint16_t const length, uint16_t *const restrict writtenBytes);

bool_t ConsoleLog(char_t const *const message, LogLevel logLevel, char_t const *const source);

bool_t ConsoleLogA(char_t const *const message, uint16_t const messageLength, LogLevel const logLevel, char_t const *const source, uint16_t const sourceLength, Handle const outputHandle);
bool_t ConsoleLogW(wchar_t const *const message, uint16_t const messageLength, LogLevel const logLevel, wchar_t const *const source, uint16_t const sourceLength, Handle const outputHandle);

static __forceinline bool_t ConsoleWrite(char_t const *const message)
{
	uint32_t length = (uint32_t)MemoryGetFirstByteMatchIndexX86(256, null, message);
	return WriteConsoleA(ProcessInformation.StandardOutput, message, length, null, null);
}