#pragma message("[kernelbase] v1.1.0.0")

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

	return !LdrGetProcedureAddressEx(KernelbaseBaseAddress, &functionName, null, (void **)&Kernelbase.GetConsoleMode, null);
}

boolean_t LoadSetConsoleMode()
{
	if (KernelbaseBaseAddress == null) return false;
	if (Kernelbase.SetConsoleMode != null) return true;

	STRING functionName;
	functionName.Buffer = "SetConsoleMode";
	functionName.Length = 14;
	functionName.MaximumLength = 15;

	return !LdrGetProcedureAddressEx(KernelbaseBaseAddress, &functionName, null, (void **)&Kernelbase.SetConsoleMode, null);
}

boolean_t LoadSetConsoleOutputCP()
{
	if (KernelbaseBaseAddress == null) return false;
	if (Kernelbase.SetConsoleOutputCP != null) return true;

	STRING functionName;
	functionName.Buffer = "SetConsoleOutputCP";
	functionName.Length = 18;
	functionName.MaximumLength = 19;

	return !LdrGetProcedureAddressEx(KernelbaseBaseAddress, &functionName, null, (void **)&Kernelbase.SetConsoleOutputCP, null);
}

boolean_t LoadSetConsoleCP()
{
	if (KernelbaseBaseAddress == null) return false;
	if (Kernelbase.SetConsoleOutputCP != null) return true;

	STRING functionName;
	functionName.Buffer = "SetConsoleCP";
	functionName.Length = 12;
	functionName.MaximumLength = 13;

	return !LdrGetProcedureAddressEx(KernelbaseBaseAddress, &functionName, null, (void **)&Kernelbase.SetConsoleCP, null);
}

boolean_t LoadWriteConsoleA()
{
	if (KernelbaseBaseAddress == null) return false;
	if (Kernelbase.WriteConsoleA != null) return true;

	STRING functionName;
	functionName.Buffer = "WriteConsoleA";
	functionName.Length = 13;
	functionName.MaximumLength = 14;

	return !LdrGetProcedureAddressEx(KernelbaseBaseAddress, &functionName, null, (void **)&Kernelbase.WriteConsoleA, null);
}

boolean_t LoadWriteConsoleW()
{
	if (KernelbaseBaseAddress == null) return false;
	if (Kernelbase.WriteConsoleW != null) return true;

	STRING functionName;
	functionName.Buffer = "WriteConsoleW";
	functionName.Length = 13;
	functionName.MaximumLength = 14;

	return !LdrGetProcedureAddressEx(KernelbaseBaseAddress, &functionName, null, (void **)&Kernelbase.WriteConsoleW, null);
}