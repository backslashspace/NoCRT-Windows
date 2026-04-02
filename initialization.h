#pragma once
#include "types.h"

void PrintArguments(wchar_t const *const commandLine, Handle const outputHandle);
boolean_t ResolveSymbols();
boolean_t AdjustProcessTokenPrivileges(Handle const outputHandle);