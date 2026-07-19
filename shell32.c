#pragma message("[shell32] v1.0.1")

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
	moduleName.Buffer = u"shell32";
	moduleName.Length = 14;
	moduleName.MaximumLength = 16;

	return !LdrLoadDll(null, null, &moduleName, &Shell32BaseAddress);
}

// ░░░ Runtime Loaders ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

#define LOAD(functionName) \
boolean_t Load##functionName() \
{ \
	if (Shell32BaseAddress == null) return false; \
	if (Shell32.functionName != null) return true; \
	 \
	STRING procedureName; \
	procedureName.Buffer = #functionName; \
	procedureName.Length = sizeof(#functionName) - 1; \
	procedureName.MaximumLength = sizeof(#functionName); \
	 \
	return !LdrGetProcedureAddressEx(Shell32BaseAddress, &procedureName, 0, (void **)&Shell32.functionName, 0); \
}

LOAD(CommandLineToArgvW)