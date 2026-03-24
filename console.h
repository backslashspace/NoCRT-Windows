#pragma once
#include "types.h"

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

boolean_t EnableVT100(Handle consoleHandle, Handle standardInput);

void ConsoleWrite(char_t const *const message);
void ConsoleWriteA(char_t const *const message, uint32_t length);
void ConsoleWriteW(wchar_t const *const message, uint32_t length);

void ConsoleLog(char_t const *const message, LogLevel logLevel, char_t const *const source);

NtStatus ConsoleLogA(char_t const *const message, uint16_t messageLength, LogLevel logLevel, char_t const *const source, uint16_t sourceLength, Handle outputHandle);
NtStatus ConsoleLogW(wchar_t const *const message, uint16_t messageLength, LogLevel logLevel, wchar_t const *const source, uint16_t sourceLength, Handle outputHandle);