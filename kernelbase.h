#pragma once
#include "types.h"

// ░░░ Definitions uses by kernelbase Functions ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

//
// Input Mode flags:
//

#define ENABLE_PROCESSED_INPUT              0x0001
#define ENABLE_LINE_INPUT                   0x0002
#define ENABLE_ECHO_INPUT                   0x0004
#define ENABLE_WINDOW_INPUT                 0x0008
#define ENABLE_MOUSE_INPUT                  0x0010
#define ENABLE_INSERT_MODE                  0x0020
#define ENABLE_QUICK_EDIT_MODE              0x0040
#define ENABLE_EXTENDED_FLAGS               0x0080
#define ENABLE_AUTO_POSITION                0x0100
#define ENABLE_VIRTUAL_TERMINAL_INPUT       0x0200

//
// Output Mode flags:
//

#define ENABLE_PROCESSED_OUTPUT             0x0001
#define ENABLE_WRAP_AT_EOL_OUTPUT           0x0002
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING  0x0004
#define DISABLE_NEWLINE_AUTO_RETURN         0x0008
#define ENABLE_LVB_GRID_WORLDWIDE           0x0010

// ░░░ Structs uses by kernelbase Functions ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░



// ░░░ Loader API ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

boolean_t InitializeKernelbase();
extern Handle KernelbaseDllBaseAddress;

boolean_t LoadSetConsoleCP();
boolean_t LoadWriteConsoleA();
boolean_t LoadWriteConsoleW();
boolean_t LoadGetConsoleMode();
boolean_t LoadSetConsoleMode();
boolean_t LoadSetConsoleOutputCP();

// ░░░ kernelbase Function Typedefs ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

// https://learn.microsoft.com/en-us/windows/console/getconsolemode
typedef bool_t(*GetConsoleMode_t)(Handle hConsoleHandle, uint32_t *lpMode);

// https://learn.microsoft.com/en-us/windows/console/setconsolemode
typedef bool_t(*SetConsoleMode_t)(Handle hConsoleHandle, uint32_t dwMode);

// https://learn.microsoft.com/en-us/windows/console/setconsoleoutputcp
// https://learn.microsoft.com/en-us/windows/win32/intl/code-page-identifiers
typedef bool_t(*SetConsoleOutputCP_t)(uint32_t wCodePageID);

// https://learn.microsoft.com/en-us/windows/console/setconsolecp
// https://learn.microsoft.com/en-us/windows/win32/intl/code-page-identifiers
typedef bool_t(*SetConsoleCP_t)(uint32_t wCodePageID);

// https://learn.microsoft.com/en-us/windows/console/writeconsole
typedef bool_t(*WriteConsoleA_t)(Handle hConsoleOutput, char_t const *lpBuffer, uint32_t nNumberOfCharsToWrite, uint32_t *lpNumberOfCharsWritten, void *lpReserved);

// https://learn.microsoft.com/en-us/windows/console/writeconsole
typedef bool_t(*WriteConsoleW_t)(Handle hConsoleOutput, wchar_t const *lpBuffer, uint32_t nNumberOfCharsToWrite, uint32_t *lpNumberOfCharsWritten, void *lpReserved);

// ░░░ Callable Grouped kernelbase Functions ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

struct KernelbaseFunctions
{
	SetConsoleCP_t SetConsoleCP;
	WriteConsoleA_t WriteConsoleA;
	WriteConsoleW_t WriteConsoleW;
	GetConsoleMode_t GetConsoleMode;
	SetConsoleMode_t SetConsoleMode;
	SetConsoleOutputCP_t SetConsoleOutputCP;
};

extern struct KernelbaseFunctions Kernelbase;

// ░░░ Wrap to normal Function ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

static __forceinline bool_t SetConsoleCP(uint32_t wCodePageID) { return Kernelbase.SetConsoleCP(wCodePageID); }
static __forceinline bool_t WriteConsoleA(Handle hConsoleOutput, char_t const *lpBuffer, uint32_t nNumberOfCharsToWrite, uint32_t *lpNumberOfCharsWritten, void *lpReserved) { return Kernelbase.WriteConsoleA(hConsoleOutput, lpBuffer, nNumberOfCharsToWrite, lpNumberOfCharsWritten, lpReserved); }
static __forceinline bool_t WriteConsoleW(Handle hConsoleOutput, wchar_t const *lpBuffer, uint32_t nNumberOfCharsToWrite, uint32_t *lpNumberOfCharsWritten, void *lpReserved) { return Kernelbase.WriteConsoleW(hConsoleOutput, lpBuffer, nNumberOfCharsToWrite, lpNumberOfCharsWritten, lpReserved); }
static __forceinline bool_t GetConsoleMode(Handle hConsoleHandle, uint32_t *lpMode) { return Kernelbase.GetConsoleMode(hConsoleHandle, lpMode); }
static __forceinline bool_t SetConsoleMode(Handle hConsoleHandle, uint32_t dwMode) { return Kernelbase.SetConsoleMode(hConsoleHandle, dwMode); }
static __forceinline bool_t SetConsoleOutputCP(uint32_t wCodePageID) { return Kernelbase.SetConsoleOutputCP(wCodePageID); }