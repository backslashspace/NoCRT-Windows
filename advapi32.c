#include "ntdll.h"
#include "advapi32.h"      
#include "intrinsics.h"

// ░░░ Initialization + State ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

uint8_t* Advapi32BaseAddress = null;
struct Advapi32Functions Advapi32 = { 0 };

boolean_t InitializeAdvapi32()
{
	if (NtDll.LdrLoadDll == null || NtDll.LdrGetProcedureAddressEx == null) return false;

	UNICODE_STRING moduleName;
	moduleName.Buffer = L"advapi32";
	moduleName.Length = 16;
	moduleName.MaximumLength = 18;

	return !LdrLoadDll(null, null, &moduleName, &Advapi32BaseAddress);
}

// ░░░ Runtime Loaders ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

boolean_t LoadStartServiceCtrlDispatcherW()
{
	if (Advapi32BaseAddress == null) return false;
	if (Advapi32.StartServiceCtrlDispatcherW != null) return true;

	STRING functionName;
	functionName.Buffer = "StartServiceCtrlDispatcherW";
	functionName.Length = 27;
	functionName.MaximumLength = 28;

	return !NtDll.LdrGetProcedureAddressEx(Advapi32BaseAddress, &functionName, null, &Advapi32.StartServiceCtrlDispatcherW, null);
}

boolean_t LoadRegisterServiceCtrlHandlerExW()
{
	if (Advapi32BaseAddress == null) return false;
	if (Advapi32.RegisterServiceCtrlHandlerExW != null) return true;

	STRING functionName;
	functionName.Buffer = "RegisterServiceCtrlHandlerExW";
	functionName.Length = 29;
	functionName.MaximumLength = 30;

	return !NtDll.LdrGetProcedureAddressEx(Advapi32BaseAddress, &functionName, null, &Advapi32.RegisterServiceCtrlHandlerExW, null);
}