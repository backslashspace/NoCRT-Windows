#pragma message("[shell32] v1.0.0.0")

#include "ntdll.h"
#include "shell32.h"      
#include "intrinsics.h"

// ░░░ Initialization + State ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

Handle Shell32BaseAddress = null;
struct Shell32Functions Shell32 = { 0 };

boolean_t InitializeShell32()
{
	if (NtDll.LdrLoadDll == null || NtDll.LdrGetProcedureAddressEx == null) return false;

	UNICODE_STRING moduleName;
	moduleName.Buffer = L"shell32";
	moduleName.Length = 14;
	moduleName.MaximumLength = 16;

	return !LdrLoadDll(null, null, &moduleName, &Shell32BaseAddress);
}

// ░░░ Runtime Loaders ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

boolean_t LoadCommandLineToArgvW()
{
	if (Shell32BaseAddress == null) return false;
	if (Shell32.CommandLineToArgvW != null) return true;

	STRING functionName;
	functionName.Buffer = "CommandLineToArgvW";
	functionName.Length = 18;
	functionName.MaximumLength = 19;

	return !LdrGetProcedureAddressEx(Shell32BaseAddress, &functionName, null, (void **)&Shell32.CommandLineToArgvW, null);
}