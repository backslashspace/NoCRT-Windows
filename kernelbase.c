#pragma message("[kernelbase] v1.3.1")

#include "ntdll.h"
#include "kernelbase.h"      
#include "intrinsics.h"

// ░░░ Initialization + State ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

Handle KernelbaseBaseAddress = null;
struct KernelbaseFunctions Kernelbase = { 0 };

boolean_t InitializeKernelbase()
{
	if (NtDll.LdrLoadDll == null || NtDll.LdrGetProcedureAddressEx == null) return false;

	UNICODE_STRING moduleName;
	moduleName.Buffer = u"kernelbase";
	moduleName.Length = 20;
	moduleName.MaximumLength = 22;

	return !LdrGetDllHandleEx(0, null, null, &moduleName, &KernelbaseBaseAddress);
}

// ░░░ Runtime Loaders ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

#define LOAD(functionName) \
boolean_t Load##functionName() \
{ \
	if (KernelbaseBaseAddress == null) return false; \
	if (Kernelbase.functionName != null) return true; \
	 \
	STRING procedureName; \
	procedureName.Buffer = #functionName; \
	procedureName.Length = sizeof(#functionName) - 1; \
	procedureName.MaximumLength = sizeof(#functionName); \
	 \
	return !LdrGetProcedureAddressEx(KernelbaseBaseAddress, &procedureName, 0, (void **)&Kernelbase.functionName, 0); \
}

LOAD(GetConsoleCP)
LOAD(SetConsoleCP)
LOAD(WriteConsoleA)
LOAD(WriteConsoleW)
LOAD(GetConsoleMode)
LOAD(SetConsoleMode)
LOAD(GetConsoleOutputCP)
LOAD(SetConsoleOutputCP)
LOAD(SetConsoleCtrlHandler)