#pragma once
#include "types.h"

// ░░░ structs ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

typedef struct BasicProcessInformation
{
    void *Environment;
    void *ImageBaseAddress;

    Handle StandardInput;
    Handle StandardOutput;
    Handle StandardError;
    Handle ConsoleHandle;

    Handle WorkingDirectoryHandle;
    wchar_t *WorkingDirectoryBuffer;
    uint16_t WorkingDirectoryLength;

    wchar_t *ImagePathNameBuffer;
    uint16_t ImagePathNameLength;

    wchar_t *CommandLineBuffer;
    uint16_t CommandLineLength;
} BasicProcessInformation;

// ░░░ Global Data ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

extern BasicProcessInformation ProcessInformation;

// ░░░ Function Definitions ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

void ReadOwnProcessInformation(BasicProcessInformation *const processInformation);