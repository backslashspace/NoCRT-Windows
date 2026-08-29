#pragma once
#include "types.h"

// ░░░ Structures ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

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
	uint16_t WorkingDirectoryByteCount;

	wchar_t *ImagePathNameBuffer;
	uint16_t ImagePathNameByteCount;

	wchar_t *CommandLineBuffer;
	uint16_t CommandLineByteCount;
} OWN_PROCESS_INFORMATION;

// ░░░ Global Data ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

extern OWN_PROCESS_INFORMATION OwnProcessInformation;

// ░░░ Functions ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

void ReadOwnProcessInformation();