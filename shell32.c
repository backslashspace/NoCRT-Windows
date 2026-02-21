#include "ntdll.h"
#include "shell32.h"      
#include "intrinsics.h"

// ░░░ Initialization + State ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

uint8_t* Shell32BaseAddress = null;
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
	functionName.Length = 56;
	functionName.MaximumLength = 58;

	return !NtDll.LdrGetProcedureAddressEx(Shell32BaseAddress, &functionName, null, &Shell32.CommandLineToArgvW, null);
}