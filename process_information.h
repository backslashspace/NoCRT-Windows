#pragma once
#include "types.h"

// ░░░ structs ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

typedef struct COMMAND_LINE_STRING
{
	wchar_t *Buffer;
	uint64_t Length;
} COMMAND_LINE_STRING;

typedef struct
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

__declspec(noreturn) void Exit(int32_t exitCode);

void ReadOwnProcessInformation(BasicProcessInformation *processInfo);

uint64_t ParseCommandLine(wchar_t const *restrict const commandLine, uint64_t const commandLineLength, COMMAND_LINE_STRING *restrict const *restrict const arguments, uint64_t const argumentBufferLength);