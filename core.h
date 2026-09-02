#pragma once
#include "types.h"

/* -------------------------------------------------------------------------- */

boolean_t ResolveSymbols();

/* -------------------------------------------------------------------------- */

boolean_t AdjustProcessTokenPrivileges();

void PrintDllExports(uint8_t *dllBaseAddress);