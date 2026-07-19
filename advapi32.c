#pragma message("[advapi32] v1.1.2")

#include "ntdll.h"
#include "advapi32.h"      
#include "intrinsics.h"

// ░░░ Initialization + State ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

Handle Advapi32DllBaseAddress = null;
struct Advapi32Functions Advapi32 = { 0 };

boolean_t InitializeAdvapi32()
{
	if (NtDll.LdrLoadDll == null || NtDll.LdrGetProcedureAddressEx == null) return false;

	UNICODE_STRING moduleName;
	moduleName.Buffer = u"advapi32";
	moduleName.Length = 16;
	moduleName.MaximumLength = 18;

	return !LdrLoadDll(null, null, &moduleName, &Advapi32DllBaseAddress);
}

// ░░░ Runtime Loaders ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

#define LOAD(functionName) \
boolean_t Load##functionName() \
{ \
	if (Advapi32DllBaseAddress == null) return false; \
	if (Advapi32.functionName != null) return true; \
	 \
	STRING procedureName; \
	procedureName.Buffer = #functionName; \
	procedureName.Length = sizeof(#functionName) - 1; \
	procedureName.MaximumLength = sizeof(#functionName); \
	 \
	return !LdrGetProcedureAddressEx(Advapi32DllBaseAddress, &procedureName, 0, (void **)&Advapi32.functionName, 0); \
}

LOAD(LookupPrivilegeNameA)
LOAD(LookupPrivilegeNameW)
LOAD(LookupPrivilegeValueA)
LOAD(LookupPrivilegeValueW)
LOAD(StartServiceCtrlDispatcherW)
LOAD(RegisterServiceCtrlHandlerExW)