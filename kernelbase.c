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
	moduleName.Buffer = L"kernelbase";
	moduleName.Length = 20;
	moduleName.MaximumLength = 22;

	return !LdrLoadDll(null, null, &moduleName, &KernelbaseBaseAddress);
}

// ░░░ Runtime Loaders ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

boolean_t LoadGetConsoleMode()
{
	if (KernelbaseBaseAddress == null) return false;
	if (Kernelbase.GetConsoleMode != null) return true;

	STRING functionName;
	functionName.Buffer = "GetConsoleMode";
	functionName.Length = 14;
	functionName.MaximumLength = 15;

	return !NtDll.LdrGetProcedureAddressEx(KernelbaseBaseAddress, &functionName, null, &Kernelbase.GetConsoleMode, null);
}

boolean_t LoadSetConsoleMode()
{
	if (KernelbaseBaseAddress == null) return false;
	if (Kernelbase.SetConsoleMode != null) return true;

	STRING functionName;
	functionName.Buffer = "SetConsoleMode";
	functionName.Length = 14;
	functionName.MaximumLength = 15;

	return !NtDll.LdrGetProcedureAddressEx(KernelbaseBaseAddress, &functionName, null, &Kernelbase.SetConsoleMode, null);
}