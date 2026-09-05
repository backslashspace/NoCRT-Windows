#include "ntdll.h"
#include "dnsapi.h"
#include "console.h"
#include "intrinsics.h"

void TestDNS()
{
	ConsoleWrite(u"# DNS\n\n");

	DNS_RECORD_W *record;

	DNS_STATUS test = DnsQuery_UTF8(u8"google.com", DNS_TYPE_A, DNS_QUERY_STANDARD, null, &record, null);

	uint8_t test2[4];
	*(uint32_t *)test2 = record->Data.A;

	if (test != STATUS_SUCCESS) ConsoleWrite(u"DnsQuery_UTF8() failed");
	else DnsFree(record, DnsFreeRecordList);

	test = DnsValidateName_UTF8(u8"fih", DnsNameDomain);
	test = DnsValidateName_UTF8(u8"musty.com", DnsNameDomain);

	_mm_pause();

	ConsoleWrite(u"\n----------------------------------------------------------------\n\n");
}