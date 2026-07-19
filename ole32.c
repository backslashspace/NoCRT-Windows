#pragma message("[ole32] v1.0.1")

#include "ntdll.h"
#include "ole32.h"      
#include "intrinsics.h"

// ░░░ Initialization + State ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

Handle Ole32DllBaseAddress = null;
struct Ole32Functions Ole32 = { 0 };

boolean_t InitializeOle32(boolean_t skipLoad)
{
	if (NtDll.LdrLoadDll == null || NtDll.LdrGetProcedureAddressEx == null) return false;

	UNICODE_STRING moduleName;
	moduleName.Buffer = u"ole32";
	moduleName.Length = 10;
	moduleName.MaximumLength = 12;

	return skipLoad ? !LdrGetDllHandleEx(0, null, null, &moduleName, &Ole32DllBaseAddress) : !LdrLoadDll(null, null, &moduleName, &Ole32DllBaseAddress);
}

// ░░░ Runtime Loaders ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

#define LOAD(functionName) \
boolean_t Load##functionName() \
{ \
	if (Ole32DllBaseAddress == null) return false; \
	if (Ole32.functionName != null) return true; \
	 \
	STRING procedureName; \
	procedureName.Buffer = #functionName; \
	procedureName.Length = sizeof(#functionName) - 1; \
	procedureName.MaximumLength = sizeof(#functionName); \
	 \
	return !LdrGetProcedureAddressEx(Ole32DllBaseAddress, &procedureName, 0, (void **)&Ole32.functionName, 0); \
}

LOAD(CoTaskMemFree)
LOAD(CoInitializeEx)
LOAD(CoUninitialize)
LOAD(CoCreateInstance)