#pragma once
#include "types.h"

// ░░░ Structs uses by shell32 Functions ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

// ░░░ Loader API ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

boolean_t InitializeShell32();
extern uint8_t* Shell32DllBaseAddress;

boolean_t LoadCommandLineToArgvW();

// ░░░ shell32 Function Typedefs ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

// https://learn.microsoft.com/en-us/windows/win32/api/shellapi/nf-shellapi-commandlinetoargvw
typedef wchar_t**(*CommandLineToArgvW_t)(const wchar_t* lpCmdLine, uint32_t* pNumArgs);

// ░░░ Callable Grouped shell32 Functions ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

struct Shell32Functions
{
    CommandLineToArgvW_t CommandLineToArgvW;
};

extern struct Shell32Functions Shell32;

// ░░░ Wrap to normal Function ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

static __forceinline wchar_t** CommandLineToArgvW(const wchar_t* lpCmdLine, uint32_t* pNumArgs) { return Shell32.CommandLineToArgvW(lpCmdLine, pNumArgs); }