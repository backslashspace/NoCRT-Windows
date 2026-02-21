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

boolean_t EnableVT100(Handle consoleHandle);

NtStatus ConsoleLogA(char_t* message, uint16_t messageLength, LogLevel logLevel, char_t* source, uint16_t sourceLength, Handle outputHandle);
NtStatus ConsoleLogW(wchar_t* message, uint16_t messageLength, LogLevel logLevel, wchar_t* source, uint16_t sourceLength, Handle outputHandle);