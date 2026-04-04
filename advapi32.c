#pragma message("[advapi32] v1.1.0.0")

#include "ntdll.h"
#include "advapi32.h"      
#include "intrinsics.h"

// ░░░ Initialization + State ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

Handle Advapi32BaseAddress = null;
struct Advapi32Functions Advapi32 = { 0 };

boolean_t InitializeAdvapi32()
{
	if (NtDll.LdrLoadDll == null || NtDll.LdrGetProcedureAddressEx == null) return false;

	UNICODE_STRING moduleName;
	moduleName.Buffer = u"advapi32";
	moduleName.Length = 16;
	moduleName.MaximumLength = 18;

	return !LdrLoadDll(null, null, &moduleName, &Advapi32BaseAddress);
}

// ░░░ Runtime Loaders ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

boolean_t LoadLookupPrivilegeValueW()
{
	if (Advapi32BaseAddress == null) return false;
	if (Advapi32.LookupPrivilegeValueW != null) return true;

	STRING functionName;
	functionName.Buffer = "LookupPrivilegeValueW";
	functionName.Length = 21;
	functionName.MaximumLength = 22;

	return !LdrGetProcedureAddressEx(Advapi32BaseAddress, &functionName, null, (void **)&Advapi32.LookupPrivilegeValueW, null);
}

boolean_t LoadLookupPrivilegeValueA()
{
	if (Advapi32BaseAddress == null) return false;
	if (Advapi32.LookupPrivilegeValueA != null) return true;

	STRING functionName;
	functionName.Buffer = "LookupPrivilegeValueA";
	functionName.Length = 21;
	functionName.MaximumLength = 22;

	return !LdrGetProcedureAddressEx(Advapi32BaseAddress, &functionName, null, (void **)&Advapi32.LookupPrivilegeValueA, null);
}

boolean_t LoadLookupPrivilegeNameA()
{
	if (Advapi32BaseAddress == null) return false;
	if (Advapi32.LookupPrivilegeNameA != null) return true;

	STRING functionName;
	functionName.Buffer = "LookupPrivilegeNameA";
	functionName.Length = 20;
	functionName.MaximumLength = 21;

	return !LdrGetProcedureAddressEx(Advapi32BaseAddress, &functionName, null, (void **)&Advapi32.LookupPrivilegeNameA, null);
}

boolean_t LoadLookupPrivilegeNameW()
{
	if (Advapi32BaseAddress == null) return false;
	if (Advapi32.LookupPrivilegeNameW != null) return true;

	STRING functionName;
	functionName.Buffer = "LookupPrivilegeNameW";
	functionName.Length = 20;
	functionName.MaximumLength = 21;

	return !LdrGetProcedureAddressEx(Advapi32BaseAddress, &functionName, null, (void **)&Advapi32.LookupPrivilegeNameW, null);
}

boolean_t LoadStartServiceCtrlDispatcherW()
{
	if (Advapi32BaseAddress == null) return false;
	if (Advapi32.StartServiceCtrlDispatcherW != null) return true;

	STRING functionName;
	functionName.Buffer = "StartServiceCtrlDispatcherW";
	functionName.Length = 27;
	functionName.MaximumLength = 28;

	return !LdrGetProcedureAddressEx(Advapi32BaseAddress, &functionName, null, (void **)&Advapi32.StartServiceCtrlDispatcherW, null);
}

boolean_t LoadRegisterServiceCtrlHandlerExW()
{
	if (Advapi32BaseAddress == null) return false;
	if (Advapi32.RegisterServiceCtrlHandlerExW != null) return true;

	STRING functionName;
	functionName.Buffer = "RegisterServiceCtrlHandlerExW";
	functionName.Length = 29;
	functionName.MaximumLength = 30;

	return !LdrGetProcedureAddressEx(Advapi32BaseAddress, &functionName, null, (void **)&Advapi32.RegisterServiceCtrlHandlerExW, null);
}