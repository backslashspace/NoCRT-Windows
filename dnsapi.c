#pragma message("[dnsapi] v1.0.0")

#include "ntdll.h"
#include "dnsapi.h"      
#include "intrinsics.h"

// ░░░ Initialization + State ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

Handle DnsApiDllBaseAddress = null;
struct DnsApiFunctions DnsApi = { 0 };

boolean_t InitializeDnsApi(boolean_t skipLoad)
{
	if (NtDll.LdrLoadDll == null || NtDll.LdrGetProcedureAddressEx == null) return false;

	UNICODE_STRING moduleName;
	moduleName.Buffer = u"dnsapi";
	moduleName.Length = 12;
	moduleName.MaximumLength = 14;

	return skipLoad ? !LdrGetDllHandleEx(0, null, null, &moduleName, &DnsApiDllBaseAddress) : !LdrLoadDll(null, null, &moduleName, &DnsApiDllBaseAddress);
}

// ░░░ Runtime Loaders ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

#define LOAD(functionName) \
boolean_t Load##functionName() \
{ \
	if (DnsApiDllBaseAddress == null) return false; \
	if (DnsApi.functionName != null) return true; \
	 \
	STRING procedureName; \
	procedureName.Buffer = #functionName; \
	procedureName.Length = sizeof(#functionName) - 1; \
	procedureName.MaximumLength = sizeof(#functionName); \
	 \
	return !LdrGetProcedureAddressEx(DnsApiDllBaseAddress, &procedureName, 0, (void **)&DnsApi.functionName, 0); \
}

LOAD(DnsFree);
LOAD(DnsQuery_W);
LOAD(DnsQuery_UTF8);
LOAD(DnsValidateName_W);
LOAD(DnsValidateName_UTF8);