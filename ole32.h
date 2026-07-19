#pragma once
#include "types.h"

// ░░░ Definitions uses by ole32 Functions ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

#define S_OK 0L
#define S_FALSE 1L

typedef struct GUID
{
	uint32_t Data1;
	uint16_t Data2;
	uint16_t Data3;
	char_t Data4[8];
} GUID;

// extended waveform format structure used for all non-PCM formats. this
// structure is common to all non-PCM formats.
typedef struct WAVEFORMATEX
{
	uint16_t wFormatTag;         // format type
	uint16_t nChannels;          // number of channels (i.e. mono, stereo...)
	uint32_t nSamplesPerSec;     // sample rate
	uint32_t nAvgBytesPerSec;    // for buffer estimation
	uint16_t nBlockAlign;        // block size of data
	uint16_t wBitsPerSample;     // number of bits per sample of mono data
	uint16_t cbSize;             // the count in bytes of the size of
	// extra information (after cbSize)
} WAVEFORMATEX;

// ░░░ Loader API ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

boolean_t InitializeOle32(boolean_t skipLoad);
extern Handle Ole32DllBaseAddress;

boolean_t LoadCoTaskMemFree();
boolean_t LoadCoInitializeEx();
boolean_t LoadCoUninitialize();
boolean_t LoadCoCreateInstance();

// ░░░ ole32 Function Typedefs ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

// https://learn.microsoft.com/en-us/windows/win32/api/combaseapi/nf-combaseapi-coinitializeex
typedef HResult(*CoInitializeEx_t)(void *pvReserved, uint32_t dwCoInit);

// https://learn.microsoft.com/en-us/windows/win32/api/combaseapi/nf-combaseapi-couninitialize
typedef void(*CoUninitialize_t)();

// https://learn.microsoft.com/en-us/windows/win32/api/combaseapi/nf-combaseapi-cocreateinstance
typedef HResult(*CoCreateInstance_t)(const GUID *rclsid, void *pUnkOuter, uint32_t dwClsContext, const GUID *riid, void **ppv);

// https://learn.microsoft.com/en-us/windows/win32/api/combaseapi/nf-combaseapi-cotaskmemfree
typedef void(*CoTaskMemFree_t)(void *pv);

// ░░░ Callable Grouped ole32 Functions ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

struct Ole32Functions
{
	CoTaskMemFree_t CoTaskMemFree;
	CoInitializeEx_t CoInitializeEx;
	CoUninitialize_t CoUninitialize;
	CoCreateInstance_t CoCreateInstance;
};

extern struct Ole32Functions Ole32;

// ░░░ Wrap to normal Function ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

static __forceinline void CoTaskMemFree(void *pv) { Ole32.CoTaskMemFree(pv); }
static __forceinline void CoUninitialize() { Ole32.CoUninitialize(); }
static __forceinline HResult CoInitializeEx(void *pvReserved, uint32_t dwCoInit) { return Ole32.CoInitializeEx(pvReserved, dwCoInit); }
static __forceinline HResult CoCreateInstance(const GUID *rclsid, void *pUnkOuter, uint32_t dwClsContext, const GUID *riid, void **ppv) { return Ole32.CoCreateInstance(rclsid, pUnkOuter, dwClsContext, riid, ppv); }