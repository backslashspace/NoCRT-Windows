#pragma message("[ole32] v1.0.0.0")

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

boolean_t LoadCoTaskMemFree()
{
	if (Ole32DllBaseAddress == null) return false;
	if (Ole32.CoTaskMemFree != null) return true;

	STRING functionName;
	functionName.Buffer = "CoTaskMemFree";
	functionName.Length = 13;
	functionName.MaximumLength = 14;

	return !LdrGetProcedureAddressEx(Ole32DllBaseAddress, &functionName, null, (void **)&Ole32.CoTaskMemFree, null);
}

boolean_t LoadCoUninitialize()
{
	if (Ole32DllBaseAddress == null) return false;
	if (Ole32.CoUninitialize != null) return true;

	STRING functionName;
	functionName.Buffer = "CoUninitialize";
	functionName.Length = 15;
	functionName.MaximumLength = 15;

	return !LdrGetProcedureAddressEx(Ole32DllBaseAddress, &functionName, null, (void **)&Ole32.CoUninitialize, null);
}

boolean_t LoadCoInitializeEx()
{
	if (Ole32DllBaseAddress == null) return false;
	if (Ole32.CoInitializeEx != null) return true;

	STRING functionName;
	functionName.Buffer = "CoInitializeEx";
	functionName.Length = 14;
	functionName.MaximumLength = 15;

	return !LdrGetProcedureAddressEx(Ole32DllBaseAddress, &functionName, null, (void **)&Ole32.CoInitializeEx, null);
}

boolean_t LoadCoCreateInstance()
{
	if (Ole32DllBaseAddress == null) return false;
	if (Ole32.CoCreateInstance != null) return true;

	STRING functionName;
	functionName.Buffer = "CoCreateInstance";
	functionName.Length = 16;
	functionName.MaximumLength = 17;

	return !LdrGetProcedureAddressEx(Ole32DllBaseAddress, &functionName, null, (void **)&Ole32.CoCreateInstance, null);
}