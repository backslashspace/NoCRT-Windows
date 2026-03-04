#pragma once
#include "types.h"

// ░░░ Structs uses by advapi32 Functions ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

// https://learn.microsoft.com/en-us/windows/win32/api/winsvc/nf-winsvc-startservicectrldispatcherw
typedef struct SERVICE_TABLE_ENTRYW
{
    wchar_t lpServiceName;
    const void (*lpServiceProc)(uint32_t dwNumServicesArgs, wchar_t** lpServiceArgVectors);
} SERVICE_TABLE_ENTRYW;

// https://learn.microsoft.com/en-us/windows/win32/api/winsvc/ns-winsvc-service_status
typedef struct SERVICE_STATUS
{
    uint32_t dwServiceType;
    uint32_t dwCurrentState;
    uint32_t dwControlsAccepted;
    uint32_t dwWin32ExitCode;
    uint32_t dwServiceSpecificExitCode;
    uint32_t dwCheckPoint;
    uint32_t dwWaitHint;
} SERVICE_STATUS;

// ░░░ Loader API ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

boolean_t InitializeAdvapi32();
extern uint8_t *Advapi32DllBaseAddress;

boolean_t LoadLookupPrivilegeNameW();
boolean_t LoadLookupPrivilegeValueW();

boolean_t LoadStartServiceCtrlDispatcherW();
boolean_t LoadRegisterServiceCtrlHandlerExW();

// ░░░ advapi32 Function Typedefs ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

// https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-lookupprivilegevaluew
typedef bool_t(*LookupPrivilegeNameW_t)(wchar_t const *lpSystemName, LUID *lpLuid, wchar_t *lpName, uint32_t *cchName);

// https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-lookupprivilegevaluew
typedef bool_t(*LookupPrivilegeValueW_t)(wchar_t const *lpSystemName, wchar_t const *lpName, LUID *lpLuid);

// https://learn.microsoft.com/en-us/windows/win32/api/winsvc/nf-winsvc-startservicectrldispatcherw
typedef bool_t(*StartServiceCtrlDispatcherW_t)(SERVICE_TABLE_ENTRYW const *lpServiceStartTable);

// https://learn.microsoft.com/en-us/windows/win32/api/winsvc/nf-winsvc-registerservicectrlhandlerexw
typedef Handle(*RegisterServiceCtrlHandlerExW_t)(wchar_t const *lpServiceName, uint32_t(*lpHandlerProc)(uint32_t dwControl, uint32_t dwEventType, void *lpEventData, void *lpContext), void *lpContext);

// ░░░ Callable Grouped advapi32 Functions ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

struct Advapi32Functions
{
    LookupPrivilegeNameW_t LookupPrivilegeNameW;
    LookupPrivilegeValueW_t LookupPrivilegeValueW;
    StartServiceCtrlDispatcherW_t StartServiceCtrlDispatcherW;
    RegisterServiceCtrlHandlerExW_t RegisterServiceCtrlHandlerExW;
};

extern struct Advapi32Functions Advapi32;

// ░░░ Wrap to normal Function ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

static __forceinline bool_t LookupPrivilegeNameW(wchar_t const *lpSystemName, LUID *lpLuid, wchar_t *lpName, uint32_t *cchName) { return Advapi32.LookupPrivilegeNameW(lpSystemName, lpLuid, lpName, cchName); }
static __forceinline bool_t LookupPrivilegeValueW(wchar_t const *lpSystemName, wchar_t const *lpName, LUID *lpLuid) { return Advapi32.LookupPrivilegeValueW(lpSystemName, lpName, lpLuid); }

static __forceinline bool_t StartServiceCtrlDispatcherW(SERVICE_TABLE_ENTRYW const *lpServiceStartTable) { return Advapi32.StartServiceCtrlDispatcherW(lpServiceStartTable); }
static __forceinline Handle RegisterServiceCtrlHandlerExW(wchar_t const *lpServiceName, uint32_t(*lpHandlerProc)(uint32_t dwControl, uint32_t dwEventType, void *lpEventData, void *lpContext), void *lpContext) { return Advapi32.RegisterServiceCtrlHandlerExW(lpServiceName, lpHandlerProc, lpContext); }