#pragma message("[ws2_32] v1.0.0")

#include "ntdll.h"
#include "ws2_32.h"      
#include "intrinsics.h"

// ░░░ Initialization + State ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

Handle WS2_32DllBaseAddress = null;
struct WS2_32Functions WS2_32 = { 0 };

boolean_t InitializeWS2_32(boolean_t skipLoad)
{
	if (NtDll.LdrLoadDll == null || NtDll.LdrGetProcedureAddressEx == null) return false;

	UNICODE_STRING moduleName;
	moduleName.Buffer = u"WS2_32";
	moduleName.Length = 12;
	moduleName.MaximumLength = 14;

	return skipLoad ? !LdrGetDllHandleEx(0, null, null, &moduleName, &WS2_32DllBaseAddress) : !LdrLoadDll(null, null, &moduleName, &WS2_32DllBaseAddress);
}

// ░░░ Runtime Loaders ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

#define LOAD(functionName) \
boolean_t Load##functionName() \
{ \
	if (WS2_32DllBaseAddress == null) return false; \
	if (WS2_32.functionName != null) return true; \
	 \
	STRING procedureName; \
	procedureName.Buffer = #functionName; \
	procedureName.Length = sizeof(#functionName) - 1; \
	procedureName.MaximumLength = sizeof(#functionName); \
	 \
	return !LdrGetProcedureAddressEx(WS2_32DllBaseAddress, &procedureName, 0, (void **)&WS2_32.functionName, 0); \
}

LOAD(bind)
LOAD(listen)
LOAD(WSASend)
LOAD(WSARecv)
LOAD(WSAPoll)
LOAD(shutdown)
LOAD(WSAIoctl)
LOAD(InetNtopW)
LOAD(InetPtonW)
LOAD(WSAAccept)
LOAD(WSASendTo)
LOAD(WSAConnect)
LOAD(WSAStartup)
LOAD(WSACleanup)
LOAD(WSASocketW)
LOAD(getsockopt)
LOAD(setsockopt)
LOAD(WSARecvFrom)
LOAD(getpeername)
LOAD(getsockname)
LOAD(closesocket)