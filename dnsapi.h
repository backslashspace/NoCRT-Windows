#pragma once
#include "types.h"

// ░░░ Definitions uses by dnsapi Functions ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

//
//  DNS Query API
//

//
//  Options for DnsQuery
//

#define DNS_QUERY_STANDARD                  0x00000000
#define DNS_QUERY_ACCEPT_TRUNCATED_RESPONSE 0x00000001
#define DNS_QUERY_USE_TCP_ONLY              0x00000002
#define DNS_QUERY_NO_RECURSION              0x00000004
#define DNS_QUERY_BYPASS_CACHE              0x00000008
#define DNS_QUERY_NO_WIRE_QUERY             0x00000010
#define DNS_QUERY_NO_LOCAL_NAME             0x00000020
#define DNS_QUERY_NO_HOSTS_FILE             0x00000040
#define DNS_QUERY_NO_NETBT                  0x00000080
#define DNS_QUERY_WIRE_ONLY                 0x00000100
#define DNS_QUERY_RETURN_MESSAGE            0x00000200
#define DNS_QUERY_MULTICAST_ONLY            0x00000400
#define DNS_QUERY_NO_MULTICAST              0x00000800
#define DNS_QUERY_TREAT_AS_FQDN             0x00001000
#define DNS_QUERY_ADDRCONFIG                0x00002000
#define DNS_QUERY_DUAL_ADDR                 0x00004000
#define DNS_QUERY_DONT_RESET_TTL_VALUES     0x00100000
#define DNS_QUERY_DISABLE_IDN_ENCODING      0x00200000
#define DNS_QUERY_APPEND_MULTILABEL         0x00800000
#define DNS_QUERY_DNSSEC_OK                 0x01000000  // Sets DNSSEC OK (DO) bit in query
#define DNS_QUERY_DNSSEC_CHECKING_DISABLED  0x02000000  // Sets DNSSEC checking disabled (CD) bit in query
#define DNS_QUERY_DNSSEC_REQUIRED           0x04000000  // Sets DNSSEC OK (DO) bit in query AND requires that response contains authenticated data (AD) bit set
#define DNS_QUERY_RESERVED                  0xf0000000

//
//  DNS Record Types
//
//  _TYPE_ defines are in host byte order.
//  _RTYPE_ defines are in net byte order.
//
//  Generally always deal with types in host byte order as we index
//  resource record functions by type.
//

#define DNS_TYPE_ZERO       0x0000

//  RFC 1034/1035
#define DNS_TYPE_A          0x0001      //  1
#define DNS_TYPE_NS         0x0002      //  2
#define DNS_TYPE_MD         0x0003      //  3
#define DNS_TYPE_MF         0x0004      //  4
#define DNS_TYPE_CNAME      0x0005      //  5
#define DNS_TYPE_SOA        0x0006      //  6
#define DNS_TYPE_MB         0x0007      //  7
#define DNS_TYPE_MG         0x0008      //  8
#define DNS_TYPE_MR         0x0009      //  9
#define DNS_TYPE_NULL       0x000a      //  10
#define DNS_TYPE_WKS        0x000b      //  11
#define DNS_TYPE_PTR        0x000c      //  12
#define DNS_TYPE_HINFO      0x000d      //  13
#define DNS_TYPE_MINFO      0x000e      //  14
#define DNS_TYPE_MX         0x000f      //  15
#define DNS_TYPE_TEXT       0x0010      //  16

//  RFC 1183
#define DNS_TYPE_RP         0x0011      //  17
#define DNS_TYPE_AFSDB      0x0012      //  18
#define DNS_TYPE_X25        0x0013      //  19
#define DNS_TYPE_ISDN       0x0014      //  20
#define DNS_TYPE_RT         0x0015      //  21

//  RFC 1348
#define DNS_TYPE_NSAP       0x0016      //  22
#define DNS_TYPE_NSAPPTR    0x0017      //  23

//  RFC 2065    (DNS security)
#define DNS_TYPE_SIG        0x0018      //  24
#define DNS_TYPE_KEY        0x0019      //  25

//  RFC 1664    (X.400 mail)
#define DNS_TYPE_PX         0x001a      //  26

//  RFC 1712    (Geographic position)
#define DNS_TYPE_GPOS       0x001b      //  27

//  RFC 1886    (IPv6 Address)
#define DNS_TYPE_AAAA       0x001c      //  28

//  RFC 1876    (Geographic location)
#define DNS_TYPE_LOC        0x001d      //  29

//  RFC 2065    (Secure negative response)
#define DNS_TYPE_NXT        0x001e      //  30

//  Patton      (Endpoint Identifier)
#define DNS_TYPE_EID        0x001f      //  31

//  Patton      (Nimrod Locator)
#define DNS_TYPE_NIMLOC     0x0020      //  32

//  RFC 2052    (Service location)
#define DNS_TYPE_SRV        0x0021      //  33

//  ATM Standard something-or-another (ATM Address)
#define DNS_TYPE_ATMA       0x0022      //  34

//  RFC 2168    (Naming Authority Pointer)
#define DNS_TYPE_NAPTR      0x0023      //  35

//  RFC 2230    (Key Exchanger)
#define DNS_TYPE_KX         0x0024      //  36

//  RFC 2538    (CERT)
#define DNS_TYPE_CERT       0x0025      //  37

//  A6 Draft    (A6)
#define DNS_TYPE_A6         0x0026      //  38

//  DNAME Draft (DNAME)
#define DNS_TYPE_DNAME      0x0027      //  39

//  Eastlake    (Kitchen Sink)
#define DNS_TYPE_SINK       0x0028      //  40

//  RFC 2671    (EDNS OPT)
#define DNS_TYPE_OPT        0x0029      //  41

//  RFC 4034    (DNSSEC DS)
#define DNS_TYPE_DS         0x002b      //  43

//  RFC 4034    (DNSSEC RRSIG)
#define DNS_TYPE_RRSIG      0x002e      //  46

//  RFC 4034    (DNSSEC NSEC)
#define DNS_TYPE_NSEC       0x002f      //  47

//  RFC 4034    (DNSSEC DNSKEY)
#define DNS_TYPE_DNSKEY     0x0030      //  48

//  RFC 4701    (DHCID)
#define DNS_TYPE_DHCID      0x0031      //  49

//  RFC 5155    (DNSSEC NSEC3)
#define DNS_TYPE_NSEC3      0x0032      //  50

//  RFC 5155    (DNSSEC NSEC3PARAM)
#define DNS_TYPE_NSEC3PARAM 0x0033      //  51

//  RFC 6698    (TLSA)
#define DNS_TYPE_TLSA       0x0034      //  52

//  draft-ietf-dnsop-svcb-https
#define DNS_TYPE_SVCB       0x0040      //  64

//  draft-ietf-dnsop-svcb-https
#define DNS_TYPE_HTTPS      0x0041      //  65

//
//  IANA Reserved
//

#define DNS_TYPE_UINFO      0x0064      //  100
#define DNS_TYPE_UID        0x0065      //  101
#define DNS_TYPE_GID        0x0066      //  102
#define DNS_TYPE_UNSPEC     0x0067      //  103

//
//  Query only types (1035, 1995)
//      - Crawford      (ADDRS)
//      - TKEY draft    (TKEY)
//      - TSIG draft    (TSIG)
//      - RFC 1995      (IXFR)
//      - RFC 1035      (AXFR up)
//

#define DNS_TYPE_ADDRS      0x00f8      //  248
#define DNS_TYPE_TKEY       0x00f9      //  249
#define DNS_TYPE_TSIG       0x00fa      //  250
#define DNS_TYPE_IXFR       0x00fb      //  251
#define DNS_TYPE_AXFR       0x00fc      //  252
#define DNS_TYPE_MAILB      0x00fd      //  253
#define DNS_TYPE_MAILA      0x00fe      //  254
#define DNS_TYPE_ALL        0x00ff      //  255
#define DNS_TYPE_ANY        0x00ff      //  255

//
//  Private use Microsoft types --  See www.iana.org/assignments/dns-parameters
//

#define DNS_TYPE_WINS       0xff01      //  64K - 255
#define DNS_TYPE_WINSR      0xff02      //  64K - 254
#define DNS_TYPE_NBSTAT     (DNS_TYPE_WINSR)

//
//  DNS Record Types -- Net Byte Order
//

#define DNS_RTYPE_A              0x0100  //  1
#define DNS_RTYPE_NS             0x0200  //  2
#define DNS_RTYPE_MD             0x0300  //  3
#define DNS_RTYPE_MF             0x0400  //  4
#define DNS_RTYPE_CNAME          0x0500  //  5
#define DNS_RTYPE_SOA            0x0600  //  6
#define DNS_RTYPE_MB             0x0700  //  7
#define DNS_RTYPE_MG             0x0800  //  8
#define DNS_RTYPE_MR             0x0900  //  9
#define DNS_RTYPE_NULL           0x0a00  //  10
#define DNS_RTYPE_WKS            0x0b00  //  11
#define DNS_RTYPE_PTR            0x0c00  //  12
#define DNS_RTYPE_HINFO          0x0d00  //  13
#define DNS_RTYPE_MINFO          0x0e00  //  14
#define DNS_RTYPE_MX             0x0f00  //  15
#define DNS_RTYPE_TEXT           0x1000  //  16
#define DNS_RTYPE_RP             0x1100  //  17
#define DNS_RTYPE_AFSDB          0x1200  //  18
#define DNS_RTYPE_X25            0x1300  //  19
#define DNS_RTYPE_ISDN           0x1400  //  20
#define DNS_RTYPE_RT             0x1500  //  21
#define DNS_RTYPE_NSAP           0x1600  //  22
#define DNS_RTYPE_NSAPPTR        0x1700  //  23
#define DNS_RTYPE_SIG            0x1800  //  24
#define DNS_RTYPE_KEY            0x1900  //  25
#define DNS_RTYPE_PX             0x1a00  //  26
#define DNS_RTYPE_GPOS           0x1b00  //  27
#define DNS_RTYPE_AAAA           0x1c00  //  28
#define DNS_RTYPE_LOC            0x1d00  //  29
#define DNS_RTYPE_NXT            0x1e00  //  30
#define DNS_RTYPE_EID            0x1f00  //  31
#define DNS_RTYPE_NIMLOC         0x2000  //  32
#define DNS_RTYPE_SRV            0x2100  //  33
#define DNS_RTYPE_ATMA           0x2200  //  34
#define DNS_RTYPE_NAPTR          0x2300  //  35
#define DNS_RTYPE_KX             0x2400  //  36
#define DNS_RTYPE_CERT           0x2500  //  37
#define DNS_RTYPE_A6             0x2600  //  38
#define DNS_RTYPE_DNAME          0x2700  //  39
#define DNS_RTYPE_SINK           0x2800  //  40
#define DNS_RTYPE_OPT            0x2900  //  41

#define DNS_RTYPE_DS             0x2b00  //  43
#define DNS_RTYPE_RRSIG          0x2e00  //  46
#define DNS_RTYPE_NSEC           0x2f00  //  47
#define DNS_RTYPE_DNSKEY         0x3000  //  48
#define DNS_RTYPE_DHCID          0x3100  //  49
#define DNS_RTYPE_NSEC3          0x3200  //  50
#define DNS_RTYPE_NSEC3PARAM     0x3300  //  51
#define DNS_RTYPE_TLSA           0x3400  //  52

//
//  IANA Reserved
//

#define DNS_RTYPE_UINFO          0x6400  //  100
#define DNS_RTYPE_UID            0x6500  //  101
#define DNS_RTYPE_GID            0x6600  //  102
#define DNS_RTYPE_UNSPEC         0x6700  //  103

//
//  Query only types
//

#define DNS_RTYPE_TKEY           0xf900  //  249
#define DNS_RTYPE_TSIG           0xfa00  //  250
#define DNS_RTYPE_IXFR           0xfb00  //  251
#define DNS_RTYPE_AXFR           0xfc00  //  252
#define DNS_RTYPE_MAILB          0xfd00  //  253
#define DNS_RTYPE_MAILA          0xfe00  //  254
#define DNS_RTYPE_ALL            0xff00  //  255
#define DNS_RTYPE_ANY            0xff00  //  255

//
//  Private use Microsoft types --  See www.iana.org/assignments/dns-parameters
//

#define DNS_RTYPE_WINS           0x01ff  //  64K - 255
#define DNS_RTYPE_WINSR          0x02ff  //  64K - 254

//
//  Record type specific definitions
//

//
//  ATMA (ATM address type) formats
//
//  Define these directly for any environment (ex NT4)
//  without winsock2 ATM support (ws2atm.h)
//

#define DNS_ATMA_FORMAT_E164            1
#define DNS_ATMA_FORMAT_AESA            2
#define DNS_ATMA_MAX_ADDR_LENGTH        (20)

#define DNS_ATMA_AESA_ADDR_LENGTH       (20)
#define DNS_ATMA_MAX_RECORD_LENGTH      (DNS_ATMA_MAX_ADDR_LENGTH+1)

//
//  DNSSEC defs
//

//  DNSSEC algorithms

#define DNSSEC_ALGORITHM_RSAMD5                 1
#define DNSSEC_ALGORITHM_RSASHA1                5
#define DNSSEC_ALGORITHM_RSASHA1_NSEC3          7
#define DNSSEC_ALGORITHM_RSASHA256              8
#define DNSSEC_ALGORITHM_RSASHA512              10
#define DNSSEC_ALGORITHM_ECDSAP256_SHA256       13
#define DNSSEC_ALGORITHM_ECDSAP384_SHA384       14
#define DNSSEC_ALGORITHM_NULL                   253
#define DNSSEC_ALGORITHM_PRIVATE                254

//  DNSSEC DS record digest algorithms

#define DNSSEC_DIGEST_ALGORITHM_SHA1            1
#define DNSSEC_DIGEST_ALGORITHM_SHA256          2
#define DNSSEC_DIGEST_ALGORITHM_SHA384          4

//  DNSSEC KEY protocol table

#define DNSSEC_PROTOCOL_NONE        0
#define DNSSEC_PROTOCOL_TLS         1
#define DNSSEC_PROTOCOL_EMAIL       2
#define DNSSEC_PROTOCOL_DNSSEC      3
#define DNSSEC_PROTOCOL_IPSEC       4

//  DNSSEC KEY flag field

#define DNSSEC_KEY_FLAG_NOAUTH          0x0001
#define DNSSEC_KEY_FLAG_NOCONF          0x0002
#define DNSSEC_KEY_FLAG_FLAG2           0x0004
#define DNSSEC_KEY_FLAG_EXTEND          0x0008
#define DNSSEC_KEY_FLAG_
#define DNSSEC_KEY_FLAG_FLAG4           0x0010
#define DNSSEC_KEY_FLAG_FLAG5           0x0020

// bits 6,7 are name type

#define DNSSEC_KEY_FLAG_USER            0x0000
#define DNSSEC_KEY_FLAG_ZONE            0x0040
#define DNSSEC_KEY_FLAG_HOST            0x0080
#define DNSSEC_KEY_FLAG_NTPE3           0x00c0

// bits 8-11 are reserved for future use

#define DNSSEC_KEY_FLAG_FLAG8           0x0100
#define DNSSEC_KEY_FLAG_FLAG9           0x0200
#define DNSSEC_KEY_FLAG_FLAG10          0x0400
#define DNSSEC_KEY_FLAG_FLAG11          0x0800

// bits 12-15 are sig field

#define DNSSEC_KEY_FLAG_SIG0            0x0000
#define DNSSEC_KEY_FLAG_SIG1            0x1000
#define DNSSEC_KEY_FLAG_SIG2            0x2000
#define DNSSEC_KEY_FLAG_SIG3            0x3000
#define DNSSEC_KEY_FLAG_SIG4            0x4000
#define DNSSEC_KEY_FLAG_SIG5            0x5000
#define DNSSEC_KEY_FLAG_SIG6            0x6000
#define DNSSEC_KEY_FLAG_SIG7            0x7000
#define DNSSEC_KEY_FLAG_SIG8            0x8000
#define DNSSEC_KEY_FLAG_SIG9            0x9000
#define DNSSEC_KEY_FLAG_SIG10           0xa000
#define DNSSEC_KEY_FLAG_SIG11           0xb000
#define DNSSEC_KEY_FLAG_SIG12           0xc000
#define DNSSEC_KEY_FLAG_SIG13           0xd000
#define DNSSEC_KEY_FLAG_SIG14           0xe000
#define DNSSEC_KEY_FLAG_SIG15           0xf000

//
//  TKEY modes
//

#define DNS_TKEY_MODE_SERVER_ASSIGN         1
#define DNS_TKEY_MODE_DIFFIE_HELLMAN        2
#define DNS_TKEY_MODE_GSS                   3
#define DNS_TKEY_MODE_RESOLVER_ASSIGN       4

///////////////////////////////////////////////////
//                                               //
//               DNS Error codes                 //
//                                               //
//                 9000 to 9999                  //
///////////////////////////////////////////////////

// =============================
// Facility DNS Error Messages
// =============================

//
//  DNS response codes.
//

#define DNS_ERROR_RESPONSE_CODES_BASE 9000

#define DNS_ERROR_RCODE_NO_ERROR NO_ERROR

#define DNS_ERROR_MASK 0x00002328 // 9000 or DNS_ERROR_RESPONSE_CODES_BASE

// DNS_ERROR_RCODE_FORMAT_ERROR          0x00002329
//
// MessageId: DNS_ERROR_RCODE_FORMAT_ERROR
//
// MessageText:
//
// DNS server unable to interpret format.
//
#define DNS_ERROR_RCODE_FORMAT_ERROR     9001L

// DNS_ERROR_RCODE_SERVER_FAILURE        0x0000232a
//
// MessageId: DNS_ERROR_RCODE_SERVER_FAILURE
//
// MessageText:
//
// DNS server failure.
//
#define DNS_ERROR_RCODE_SERVER_FAILURE   9002L

// DNS_ERROR_RCODE_NAME_ERROR            0x0000232b
//
// MessageId: DNS_ERROR_RCODE_NAME_ERROR
//
// MessageText:
//
// DNS name does not exist.
//
#define DNS_ERROR_RCODE_NAME_ERROR       9003L

// DNS_ERROR_RCODE_NOT_IMPLEMENTED       0x0000232c
//
// MessageId: DNS_ERROR_RCODE_NOT_IMPLEMENTED
//
// MessageText:
//
// DNS request not supported by name server.
//
#define DNS_ERROR_RCODE_NOT_IMPLEMENTED  9004L

// DNS_ERROR_RCODE_REFUSED               0x0000232d
//
// MessageId: DNS_ERROR_RCODE_REFUSED
//
// MessageText:
//
// DNS operation refused.
//
#define DNS_ERROR_RCODE_REFUSED          9005L

// DNS_ERROR_RCODE_YXDOMAIN              0x0000232e
//
// MessageId: DNS_ERROR_RCODE_YXDOMAIN
//
// MessageText:
//
// DNS name that ought not exist, does exist.
//
#define DNS_ERROR_RCODE_YXDOMAIN         9006L

// DNS_ERROR_RCODE_YXRRSET               0x0000232f
//
// MessageId: DNS_ERROR_RCODE_YXRRSET
//
// MessageText:
//
// DNS RR set that ought not exist, does exist.
//
#define DNS_ERROR_RCODE_YXRRSET          9007L

// DNS_ERROR_RCODE_NXRRSET               0x00002330
//
// MessageId: DNS_ERROR_RCODE_NXRRSET
//
// MessageText:
//
// DNS RR set that ought to exist, does not exist.
//
#define DNS_ERROR_RCODE_NXRRSET          9008L

// DNS_ERROR_RCODE_NOTAUTH               0x00002331
//
// MessageId: DNS_ERROR_RCODE_NOTAUTH
//
// MessageText:
//
// DNS server not authoritative for zone.
//
#define DNS_ERROR_RCODE_NOTAUTH          9009L

// DNS_ERROR_RCODE_NOTZONE               0x00002332
//
// MessageId: DNS_ERROR_RCODE_NOTZONE
//
// MessageText:
//
// DNS name in update or prereq is not in zone.
//
#define DNS_ERROR_RCODE_NOTZONE          9010L

// DNS_ERROR_RCODE_BADSIG                0x00002338
//
// MessageId: DNS_ERROR_RCODE_BADSIG
//
// MessageText:
//
// DNS signature failed to verify.
//
#define DNS_ERROR_RCODE_BADSIG           9016L

// DNS_ERROR_RCODE_BADKEY                0x00002339
//
// MessageId: DNS_ERROR_RCODE_BADKEY
//
// MessageText:
//
// DNS bad key.
//
#define DNS_ERROR_RCODE_BADKEY           9017L

// DNS_ERROR_RCODE_BADTIME               0x0000233a
//
// MessageId: DNS_ERROR_RCODE_BADTIME
//
// MessageText:
//
// DNS signature validity expired.
//
#define DNS_ERROR_RCODE_BADTIME          9018L

#define DNS_ERROR_RCODE_LAST DNS_ERROR_RCODE_BADTIME

//
// DNSSEC errors
//

#define DNS_ERROR_DNSSEC_BASE 9100

//
// MessageId: DNS_ERROR_KEYMASTER_REQUIRED
//
// MessageText:
//
// Only the DNS server acting as the key master for the zone may perform this operation.
//
#define DNS_ERROR_KEYMASTER_REQUIRED     9101L

//
// MessageId: DNS_ERROR_NOT_ALLOWED_ON_SIGNED_ZONE
//
// MessageText:
//
// This operation is not allowed on a zone that is signed or has signing keys.
//
#define DNS_ERROR_NOT_ALLOWED_ON_SIGNED_ZONE 9102L

//
// MessageId: DNS_ERROR_NSEC3_INCOMPATIBLE_WITH_RSA_SHA1
//
// MessageText:
//
// NSEC3 is not compatible with the RSA-SHA-1 algorithm. Choose a different algorithm or use NSEC.
//
#define DNS_ERROR_NSEC3_INCOMPATIBLE_WITH_RSA_SHA1 9103L

//
// MessageId: DNS_ERROR_NOT_ENOUGH_SIGNING_KEY_DESCRIPTORS
//
// MessageText:
//
// The zone does not have enough signing keys. There must be at least one key signing key (KSK) and at least one zone signing key (ZSK).
//
#define DNS_ERROR_NOT_ENOUGH_SIGNING_KEY_DESCRIPTORS 9104L

//
// MessageId: DNS_ERROR_UNSUPPORTED_ALGORITHM
//
// MessageText:
//
// The specified algorithm is not supported.
//
#define DNS_ERROR_UNSUPPORTED_ALGORITHM  9105L

//
// MessageId: DNS_ERROR_INVALID_KEY_SIZE
//
// MessageText:
//
// The specified key size is not supported.
//
#define DNS_ERROR_INVALID_KEY_SIZE       9106L

//
// MessageId: DNS_ERROR_SIGNING_KEY_NOT_ACCESSIBLE
//
// MessageText:
//
// One or more of the signing keys for a zone are not accessible to the DNS server. Zone signing will not be operational until this error is resolved.
//
#define DNS_ERROR_SIGNING_KEY_NOT_ACCESSIBLE 9107L

//
// MessageId: DNS_ERROR_KSP_DOES_NOT_SUPPORT_PROTECTION
//
// MessageText:
//
// The specified key storage provider does not support DPAPI++ data protection. Zone signing will not be operational until this error is resolved.
//
#define DNS_ERROR_KSP_DOES_NOT_SUPPORT_PROTECTION 9108L

//
// MessageId: DNS_ERROR_UNEXPECTED_DATA_PROTECTION_ERROR
//
// MessageText:
//
// An unexpected DPAPI++ error was encountered. Zone signing will not be operational until this error is resolved.
//
#define DNS_ERROR_UNEXPECTED_DATA_PROTECTION_ERROR 9109L

//
// MessageId: DNS_ERROR_UNEXPECTED_CNG_ERROR
//
// MessageText:
//
// An unexpected crypto error was encountered. Zone signing may not be operational until this error is resolved.
//
#define DNS_ERROR_UNEXPECTED_CNG_ERROR   9110L

//
// MessageId: DNS_ERROR_UNKNOWN_SIGNING_PARAMETER_VERSION
//
// MessageText:
//
// The DNS server encountered a signing key with an unknown version. Zone signing will not be operational until this error is resolved.
//
#define DNS_ERROR_UNKNOWN_SIGNING_PARAMETER_VERSION 9111L

//
// MessageId: DNS_ERROR_KSP_NOT_ACCESSIBLE
//
// MessageText:
//
// The specified key service provider cannot be opened by the DNS server.
//
#define DNS_ERROR_KSP_NOT_ACCESSIBLE     9112L

//
// MessageId: DNS_ERROR_TOO_MANY_SKDS
//
// MessageText:
//
// The DNS server cannot accept any more signing keys with the specified algorithm and KSK flag value for this zone.
//
#define DNS_ERROR_TOO_MANY_SKDS          9113L

//
// MessageId: DNS_ERROR_INVALID_ROLLOVER_PERIOD
//
// MessageText:
//
// The specified rollover period is invalid.
//
#define DNS_ERROR_INVALID_ROLLOVER_PERIOD 9114L

//
// MessageId: DNS_ERROR_INVALID_INITIAL_ROLLOVER_OFFSET
//
// MessageText:
//
// The specified initial rollover offset is invalid.
//
#define DNS_ERROR_INVALID_INITIAL_ROLLOVER_OFFSET 9115L

//
// MessageId: DNS_ERROR_ROLLOVER_IN_PROGRESS
//
// MessageText:
//
// The specified signing key is already in process of rolling over keys.
//
#define DNS_ERROR_ROLLOVER_IN_PROGRESS   9116L

//
// MessageId: DNS_ERROR_STANDBY_KEY_NOT_PRESENT
//
// MessageText:
//
// The specified signing key does not have a standby key to revoke.
//
#define DNS_ERROR_STANDBY_KEY_NOT_PRESENT 9117L

//
// MessageId: DNS_ERROR_NOT_ALLOWED_ON_ZSK
//
// MessageText:
//
// This operation is not allowed on a zone signing key (ZSK).
//
#define DNS_ERROR_NOT_ALLOWED_ON_ZSK     9118L

//
// MessageId: DNS_ERROR_NOT_ALLOWED_ON_ACTIVE_SKD
//
// MessageText:
//
// This operation is not allowed on an active signing key.
//
#define DNS_ERROR_NOT_ALLOWED_ON_ACTIVE_SKD 9119L

//
// MessageId: DNS_ERROR_ROLLOVER_ALREADY_QUEUED
//
// MessageText:
//
// The specified signing key is already queued for rollover.
//
#define DNS_ERROR_ROLLOVER_ALREADY_QUEUED 9120L

//
// MessageId: DNS_ERROR_NOT_ALLOWED_ON_UNSIGNED_ZONE
//
// MessageText:
//
// This operation is not allowed on an unsigned zone.
//
#define DNS_ERROR_NOT_ALLOWED_ON_UNSIGNED_ZONE 9121L

//
// MessageId: DNS_ERROR_BAD_KEYMASTER
//
// MessageText:
//
// This operation could not be completed because the DNS server listed as the current key master for this zone is down or misconfigured. Resolve the problem on the current key master for this zone or use another DNS server to seize the key master role.
//
#define DNS_ERROR_BAD_KEYMASTER          9122L

//
// MessageId: DNS_ERROR_INVALID_SIGNATURE_VALIDITY_PERIOD
//
// MessageText:
//
// The specified signature validity period is invalid.
//
#define DNS_ERROR_INVALID_SIGNATURE_VALIDITY_PERIOD 9123L

//
// MessageId: DNS_ERROR_INVALID_NSEC3_ITERATION_COUNT
//
// MessageText:
//
// The specified NSEC3 iteration count is higher than allowed by the minimum key length used in the zone.
//
#define DNS_ERROR_INVALID_NSEC3_ITERATION_COUNT 9124L

//
// MessageId: DNS_ERROR_DNSSEC_IS_DISABLED
//
// MessageText:
//
// This operation could not be completed because the DNS server has been configured with DNSSEC features disabled. Enable DNSSEC on the DNS server.
//
#define DNS_ERROR_DNSSEC_IS_DISABLED     9125L

//
// MessageId: DNS_ERROR_INVALID_XML
//
// MessageText:
//
// This operation could not be completed because the XML stream received is empty or syntactically invalid.
//
#define DNS_ERROR_INVALID_XML            9126L

//
// MessageId: DNS_ERROR_NO_VALID_TRUST_ANCHORS
//
// MessageText:
//
// This operation completed, but no trust anchors were added because all of the trust anchors received were either invalid, unsupported, expired, or would not become valid in less than 30 days.
//
#define DNS_ERROR_NO_VALID_TRUST_ANCHORS 9127L

//
// MessageId: DNS_ERROR_ROLLOVER_NOT_POKEABLE
//
// MessageText:
//
// The specified signing key is not waiting for parental DS update.
//
#define DNS_ERROR_ROLLOVER_NOT_POKEABLE  9128L

//
// MessageId: DNS_ERROR_NSEC3_NAME_COLLISION
//
// MessageText:
//
// Hash collision detected during NSEC3 signing. Specify a different user-provided salt, or use a randomly generated salt, and attempt to sign the zone again.
//
#define DNS_ERROR_NSEC3_NAME_COLLISION   9129L

//
// MessageId: DNS_ERROR_NSEC_INCOMPATIBLE_WITH_NSEC3_RSA_SHA1
//
// MessageText:
//
// NSEC is not compatible with the NSEC3-RSA-SHA-1 algorithm. Choose a different algorithm or use NSEC3.
//
#define DNS_ERROR_NSEC_INCOMPATIBLE_WITH_NSEC3_RSA_SHA1 9130L


//
// Packet format
//

#define DNS_ERROR_PACKET_FMT_BASE 9500

// DNS_INFO_NO_RECORDS                   0x0000251d
//
// MessageId: DNS_INFO_NO_RECORDS
//
// MessageText:
//
// No records found for given DNS query.
//
#define DNS_INFO_NO_RECORDS              9501L

// DNS_ERROR_BAD_PACKET                  0x0000251e
//
// MessageId: DNS_ERROR_BAD_PACKET
//
// MessageText:
//
// Bad DNS packet.
//
#define DNS_ERROR_BAD_PACKET             9502L

// DNS_ERROR_NO_PACKET                   0x0000251f
//
// MessageId: DNS_ERROR_NO_PACKET
//
// MessageText:
//
// No DNS packet.
//
#define DNS_ERROR_NO_PACKET              9503L

// DNS_ERROR_RCODE                       0x00002520
//
// MessageId: DNS_ERROR_RCODE
//
// MessageText:
//
// DNS error, check rcode.
//
#define DNS_ERROR_RCODE                  9504L

// DNS_ERROR_UNSECURE_PACKET             0x00002521
//
// MessageId: DNS_ERROR_UNSECURE_PACKET
//
// MessageText:
//
// Unsecured DNS packet.
//
#define DNS_ERROR_UNSECURE_PACKET        9505L

#define DNS_STATUS_PACKET_UNSECURE DNS_ERROR_UNSECURE_PACKET

// DNS_REQUEST_PENDING                     0x00002522
//
// MessageId: DNS_REQUEST_PENDING
//
// MessageText:
//
// DNS query request is pending.
//
#define DNS_REQUEST_PENDING              9506L


//
// General API errors
//

#define DNS_ERROR_NO_MEMORY            ERROR_OUTOFMEMORY
#define DNS_ERROR_INVALID_NAME         ERROR_INVALID_NAME
#define DNS_ERROR_INVALID_DATA         ERROR_INVALID_DATA

#define DNS_ERROR_GENERAL_API_BASE 9550

// DNS_ERROR_INVALID_TYPE                0x0000254f
//
// MessageId: DNS_ERROR_INVALID_TYPE
//
// MessageText:
//
// Invalid DNS type.
//
#define DNS_ERROR_INVALID_TYPE           9551L

// DNS_ERROR_INVALID_IP_ADDRESS          0x00002550
//
// MessageId: DNS_ERROR_INVALID_IP_ADDRESS
//
// MessageText:
//
// Invalid IP address.
//
#define DNS_ERROR_INVALID_IP_ADDRESS     9552L

// DNS_ERROR_INVALID_PROPERTY            0x00002551
//
// MessageId: DNS_ERROR_INVALID_PROPERTY
//
// MessageText:
//
// Invalid property.
//
#define DNS_ERROR_INVALID_PROPERTY       9553L

// DNS_ERROR_TRY_AGAIN_LATER             0x00002552
//
// MessageId: DNS_ERROR_TRY_AGAIN_LATER
//
// MessageText:
//
// Try DNS operation again later.
//
#define DNS_ERROR_TRY_AGAIN_LATER        9554L

// DNS_ERROR_NOT_UNIQUE                  0x00002553
//
// MessageId: DNS_ERROR_NOT_UNIQUE
//
// MessageText:
//
// Record for given name and type is not unique.
//
#define DNS_ERROR_NOT_UNIQUE             9555L

// DNS_ERROR_NON_RFC_NAME                0x00002554
//
// MessageId: DNS_ERROR_NON_RFC_NAME
//
// MessageText:
//
// DNS name does not comply with RFC specifications.
//
#define DNS_ERROR_NON_RFC_NAME           9556L

// DNS_STATUS_FQDN                       0x00002555
//
// MessageId: DNS_STATUS_FQDN
//
// MessageText:
//
// DNS name is a fully-qualified DNS name.
//
#define DNS_STATUS_FQDN                  9557L

// DNS_STATUS_DOTTED_NAME                0x00002556
//
// MessageId: DNS_STATUS_DOTTED_NAME
//
// MessageText:
//
// DNS name is dotted (multi-label).
//
#define DNS_STATUS_DOTTED_NAME           9558L

// DNS_STATUS_SINGLE_PART_NAME           0x00002557
//
// MessageId: DNS_STATUS_SINGLE_PART_NAME
//
// MessageText:
//
// DNS name is a single-part name.
//
#define DNS_STATUS_SINGLE_PART_NAME      9559L

// DNS_ERROR_INVALID_NAME_CHAR           0x00002558
//
// MessageId: DNS_ERROR_INVALID_NAME_CHAR
//
// MessageText:
//
// DNS name contains an invalid character.
//
#define DNS_ERROR_INVALID_NAME_CHAR      9560L

// DNS_ERROR_NUMERIC_NAME                0x00002559
//
// MessageId: DNS_ERROR_NUMERIC_NAME
//
// MessageText:
//
// DNS name is entirely numeric.
//
#define DNS_ERROR_NUMERIC_NAME           9561L

// DNS_ERROR_NOT_ALLOWED_ON_ROOT_SERVER  0x0000255A
//
// MessageId: DNS_ERROR_NOT_ALLOWED_ON_ROOT_SERVER
//
// MessageText:
//
// The operation requested is not permitted on a DNS root server.
//
#define DNS_ERROR_NOT_ALLOWED_ON_ROOT_SERVER 9562L

// DNS_ERROR_NOT_ALLOWED_UNDER_DELEGATION  0x0000255B
//
// MessageId: DNS_ERROR_NOT_ALLOWED_UNDER_DELEGATION
//
// MessageText:
//
// The record could not be created because this part of the DNS namespace has been delegated to another server.
//
#define DNS_ERROR_NOT_ALLOWED_UNDER_DELEGATION 9563L

// DNS_ERROR_CANNOT_FIND_ROOT_HINTS  0x0000255C
//
// MessageId: DNS_ERROR_CANNOT_FIND_ROOT_HINTS
//
// MessageText:
//
// The DNS server could not find a set of root hints.
//
#define DNS_ERROR_CANNOT_FIND_ROOT_HINTS 9564L

// DNS_ERROR_INCONSISTENT_ROOT_HINTS  0x0000255D
//
// MessageId: DNS_ERROR_INCONSISTENT_ROOT_HINTS
//
// MessageText:
//
// The DNS server found root hints but they were not consistent across all adapters.
//
#define DNS_ERROR_INCONSISTENT_ROOT_HINTS 9565L

// DNS_ERROR_DWORD_VALUE_TOO_SMALL    0x0000255E
//
// MessageId: DNS_ERROR_DWORD_VALUE_TOO_SMALL
//
// MessageText:
//
// The specified value is too small for this parameter.
//
#define DNS_ERROR_DWORD_VALUE_TOO_SMALL  9566L

// DNS_ERROR_DWORD_VALUE_TOO_LARGE    0x0000255F
//
// MessageId: DNS_ERROR_DWORD_VALUE_TOO_LARGE
//
// MessageText:
//
// The specified value is too large for this parameter.
//
#define DNS_ERROR_DWORD_VALUE_TOO_LARGE  9567L

// DNS_ERROR_BACKGROUND_LOADING       0x00002560
//
// MessageId: DNS_ERROR_BACKGROUND_LOADING
//
// MessageText:
//
// This operation is not allowed while the DNS server is loading zones in the background. Please try again later.
//
#define DNS_ERROR_BACKGROUND_LOADING     9568L

// DNS_ERROR_NOT_ALLOWED_ON_RODC      0x00002561
//
// MessageId: DNS_ERROR_NOT_ALLOWED_ON_RODC
//
// MessageText:
//
// The operation requested is not permitted on against a DNS server running on a read-only DC.
//
#define DNS_ERROR_NOT_ALLOWED_ON_RODC    9569L

// DNS_ERROR_NOT_ALLOWED_UNDER_DNAME   0x00002562
//
// MessageId: DNS_ERROR_NOT_ALLOWED_UNDER_DNAME
//
// MessageText:
//
// No data is allowed to exist underneath a DNAME record.
//
#define DNS_ERROR_NOT_ALLOWED_UNDER_DNAME 9570L

// DNS_ERROR_DELEGATION_REQUIRED       0x00002563
//
// MessageId: DNS_ERROR_DELEGATION_REQUIRED
//
// MessageText:
//
// This operation requires credentials delegation.
//
#define DNS_ERROR_DELEGATION_REQUIRED    9571L

// DNS_ERROR_INVALID_POLICY_TABLE        0x00002564
//
// MessageId: DNS_ERROR_INVALID_POLICY_TABLE
//
// MessageText:
//
// Name resolution policy table has been corrupted. DNS resolution will fail until it is fixed. Contact your network administrator.
//
#define DNS_ERROR_INVALID_POLICY_TABLE   9572L

// DNS_ERROR_ADDRESS_REQUIRED        0x00002565
//
// MessageId: DNS_ERROR_ADDRESS_REQUIRED
//
// MessageText:
//
// Not allowed to remove all addresses.
//
#define DNS_ERROR_ADDRESS_REQUIRED       9573L


//
// Zone errors
//

#define DNS_ERROR_ZONE_BASE 9600

// DNS_ERROR_ZONE_DOES_NOT_EXIST         0x00002581
//
// MessageId: DNS_ERROR_ZONE_DOES_NOT_EXIST
//
// MessageText:
//
// DNS zone does not exist.
//
#define DNS_ERROR_ZONE_DOES_NOT_EXIST    9601L

// DNS_ERROR_NO_ZONE_INFO                0x00002582
//
// MessageId: DNS_ERROR_NO_ZONE_INFO
//
// MessageText:
//
// DNS zone information not available.
//
#define DNS_ERROR_NO_ZONE_INFO           9602L

// DNS_ERROR_INVALID_ZONE_OPERATION      0x00002583
//
// MessageId: DNS_ERROR_INVALID_ZONE_OPERATION
//
// MessageText:
//
// Invalid operation for DNS zone.
//
#define DNS_ERROR_INVALID_ZONE_OPERATION 9603L

// DNS_ERROR_ZONE_CONFIGURATION_ERROR    0x00002584
//
// MessageId: DNS_ERROR_ZONE_CONFIGURATION_ERROR
//
// MessageText:
//
// Invalid DNS zone configuration.
//
#define DNS_ERROR_ZONE_CONFIGURATION_ERROR 9604L

// DNS_ERROR_ZONE_HAS_NO_SOA_RECORD      0x00002585
//
// MessageId: DNS_ERROR_ZONE_HAS_NO_SOA_RECORD
//
// MessageText:
//
// DNS zone has no start of authority (SOA) record.
//
#define DNS_ERROR_ZONE_HAS_NO_SOA_RECORD 9605L

// DNS_ERROR_ZONE_HAS_NO_NS_RECORDS      0x00002586
//
// MessageId: DNS_ERROR_ZONE_HAS_NO_NS_RECORDS
//
// MessageText:
//
// DNS zone has no Name Server (NS) record.
//
#define DNS_ERROR_ZONE_HAS_NO_NS_RECORDS 9606L

// DNS_ERROR_ZONE_LOCKED                 0x00002587
//
// MessageId: DNS_ERROR_ZONE_LOCKED
//
// MessageText:
//
// DNS zone is locked.
//
#define DNS_ERROR_ZONE_LOCKED            9607L

// DNS_ERROR_ZONE_CREATION_FAILED        0x00002588
//
// MessageId: DNS_ERROR_ZONE_CREATION_FAILED
//
// MessageText:
//
// DNS zone creation failed.
//
#define DNS_ERROR_ZONE_CREATION_FAILED   9608L

// DNS_ERROR_ZONE_ALREADY_EXISTS         0x00002589
//
// MessageId: DNS_ERROR_ZONE_ALREADY_EXISTS
//
// MessageText:
//
// DNS zone already exists.
//
#define DNS_ERROR_ZONE_ALREADY_EXISTS    9609L

// DNS_ERROR_AUTOZONE_ALREADY_EXISTS     0x0000258a
//
// MessageId: DNS_ERROR_AUTOZONE_ALREADY_EXISTS
//
// MessageText:
//
// DNS automatic zone already exists.
//
#define DNS_ERROR_AUTOZONE_ALREADY_EXISTS 9610L

// DNS_ERROR_INVALID_ZONE_TYPE           0x0000258b
//
// MessageId: DNS_ERROR_INVALID_ZONE_TYPE
//
// MessageText:
//
// Invalid DNS zone type.
//
#define DNS_ERROR_INVALID_ZONE_TYPE      9611L

// DNS_ERROR_SECONDARY_REQUIRES_MASTER_IP 0x0000258c
//
// MessageId: DNS_ERROR_SECONDARY_REQUIRES_MASTER_IP
//
// MessageText:
//
// Secondary DNS zone requires master IP address.
//
#define DNS_ERROR_SECONDARY_REQUIRES_MASTER_IP 9612L

// DNS_ERROR_ZONE_NOT_SECONDARY          0x0000258d
//
// MessageId: DNS_ERROR_ZONE_NOT_SECONDARY
//
// MessageText:
//
// DNS zone not secondary.
//
#define DNS_ERROR_ZONE_NOT_SECONDARY     9613L

// DNS_ERROR_NEED_SECONDARY_ADDRESSES    0x0000258e
//
// MessageId: DNS_ERROR_NEED_SECONDARY_ADDRESSES
//
// MessageText:
//
// Need secondary IP address.
//
#define DNS_ERROR_NEED_SECONDARY_ADDRESSES 9614L

// DNS_ERROR_WINS_INIT_FAILED            0x0000258f
//
// MessageId: DNS_ERROR_WINS_INIT_FAILED
//
// MessageText:
//
// WINS initialization failed.
//
#define DNS_ERROR_WINS_INIT_FAILED       9615L

// DNS_ERROR_NEED_WINS_SERVERS           0x00002590
//
// MessageId: DNS_ERROR_NEED_WINS_SERVERS
//
// MessageText:
//
// Need WINS servers.
//
#define DNS_ERROR_NEED_WINS_SERVERS      9616L

// DNS_ERROR_NBSTAT_INIT_FAILED          0x00002591
//
// MessageId: DNS_ERROR_NBSTAT_INIT_FAILED
//
// MessageText:
//
// NBTSTAT initialization call failed.
//
#define DNS_ERROR_NBSTAT_INIT_FAILED     9617L

// DNS_ERROR_SOA_DELETE_INVALID          0x00002592
//
// MessageId: DNS_ERROR_SOA_DELETE_INVALID
//
// MessageText:
//
// Invalid delete of start of authority (SOA)
//
#define DNS_ERROR_SOA_DELETE_INVALID     9618L

// DNS_ERROR_FORWARDER_ALREADY_EXISTS    0x00002593
//
// MessageId: DNS_ERROR_FORWARDER_ALREADY_EXISTS
//
// MessageText:
//
// A conditional forwarding zone already exists for that name.
//
#define DNS_ERROR_FORWARDER_ALREADY_EXISTS 9619L

// DNS_ERROR_ZONE_REQUIRES_MASTER_IP     0x00002594
//
// MessageId: DNS_ERROR_ZONE_REQUIRES_MASTER_IP
//
// MessageText:
//
// This zone must be configured with one or more master DNS server IP addresses.
//
#define DNS_ERROR_ZONE_REQUIRES_MASTER_IP 9620L

// DNS_ERROR_ZONE_IS_SHUTDOWN            0x00002595
//
// MessageId: DNS_ERROR_ZONE_IS_SHUTDOWN
//
// MessageText:
//
// The operation cannot be performed because this zone is shut down.
//
#define DNS_ERROR_ZONE_IS_SHUTDOWN       9621L

// DNS_ERROR_ZONE_LOCKED_FOR_SIGNING     0x00002596
//
// MessageId: DNS_ERROR_ZONE_LOCKED_FOR_SIGNING
//
// MessageText:
//
// This operation cannot be performed because the zone is currently being signed. Please try again later.
//
#define DNS_ERROR_ZONE_LOCKED_FOR_SIGNING 9622L


//
// Datafile errors
//

#define DNS_ERROR_DATAFILE_BASE 9650

// DNS                                   0x000025b3
//
// MessageId: DNS_ERROR_PRIMARY_REQUIRES_DATAFILE
//
// MessageText:
//
// Primary DNS zone requires datafile.
//
#define DNS_ERROR_PRIMARY_REQUIRES_DATAFILE 9651L

// DNS                                   0x000025b4
//
// MessageId: DNS_ERROR_INVALID_DATAFILE_NAME
//
// MessageText:
//
// Invalid datafile name for DNS zone.
//
#define DNS_ERROR_INVALID_DATAFILE_NAME  9652L

// DNS                                   0x000025b5
//
// MessageId: DNS_ERROR_DATAFILE_OPEN_FAILURE
//
// MessageText:
//
// Failed to open datafile for DNS zone.
//
#define DNS_ERROR_DATAFILE_OPEN_FAILURE  9653L

// DNS                                   0x000025b6
//
// MessageId: DNS_ERROR_FILE_WRITEBACK_FAILED
//
// MessageText:
//
// Failed to write datafile for DNS zone.
//
#define DNS_ERROR_FILE_WRITEBACK_FAILED  9654L

// DNS                                   0x000025b7
//
// MessageId: DNS_ERROR_DATAFILE_PARSING
//
// MessageText:
//
// Failure while reading datafile for DNS zone.
//
#define DNS_ERROR_DATAFILE_PARSING       9655L


//
// Database errors
//

#define DNS_ERROR_DATABASE_BASE 9700

// DNS_ERROR_RECORD_DOES_NOT_EXIST       0x000025e5
//
// MessageId: DNS_ERROR_RECORD_DOES_NOT_EXIST
//
// MessageText:
//
// DNS record does not exist.
//
#define DNS_ERROR_RECORD_DOES_NOT_EXIST  9701L

// DNS_ERROR_RECORD_FORMAT               0x000025e6
//
// MessageId: DNS_ERROR_RECORD_FORMAT
//
// MessageText:
//
// DNS record format error.
//
#define DNS_ERROR_RECORD_FORMAT          9702L

// DNS_ERROR_NODE_CREATION_FAILED        0x000025e7
//
// MessageId: DNS_ERROR_NODE_CREATION_FAILED
//
// MessageText:
//
// Node creation failure in DNS.
//
#define DNS_ERROR_NODE_CREATION_FAILED   9703L

// DNS_ERROR_UNKNOWN_RECORD_TYPE         0x000025e8
//
// MessageId: DNS_ERROR_UNKNOWN_RECORD_TYPE
//
// MessageText:
//
// Unknown DNS record type.
//
#define DNS_ERROR_UNKNOWN_RECORD_TYPE    9704L

// DNS_ERROR_RECORD_TIMED_OUT            0x000025e9
//
// MessageId: DNS_ERROR_RECORD_TIMED_OUT
//
// MessageText:
//
// DNS record timed out.
//
#define DNS_ERROR_RECORD_TIMED_OUT       9705L

// DNS_ERROR_NAME_NOT_IN_ZONE            0x000025ea
//
// MessageId: DNS_ERROR_NAME_NOT_IN_ZONE
//
// MessageText:
//
// Name not in DNS zone.
//
#define DNS_ERROR_NAME_NOT_IN_ZONE       9706L

// DNS_ERROR_CNAME_LOOP                  0x000025eb
//
// MessageId: DNS_ERROR_CNAME_LOOP
//
// MessageText:
//
// CNAME loop detected.
//
#define DNS_ERROR_CNAME_LOOP             9707L

// DNS_ERROR_NODE_IS_CNAME               0x000025ec
//
// MessageId: DNS_ERROR_NODE_IS_CNAME
//
// MessageText:
//
// Node is a CNAME DNS record.
//
#define DNS_ERROR_NODE_IS_CNAME          9708L

// DNS_ERROR_CNAME_COLLISION             0x000025ed
//
// MessageId: DNS_ERROR_CNAME_COLLISION
//
// MessageText:
//
// A CNAME record already exists for given name.
//
#define DNS_ERROR_CNAME_COLLISION        9709L

// DNS_ERROR_RECORD_ONLY_AT_ZONE_ROOT    0x000025ee
//
// MessageId: DNS_ERROR_RECORD_ONLY_AT_ZONE_ROOT
//
// MessageText:
//
// Record only at DNS zone root.
//
#define DNS_ERROR_RECORD_ONLY_AT_ZONE_ROOT 9710L

// DNS_ERROR_RECORD_ALREADY_EXISTS       0x000025ef
//
// MessageId: DNS_ERROR_RECORD_ALREADY_EXISTS
//
// MessageText:
//
// DNS record already exists.
//
#define DNS_ERROR_RECORD_ALREADY_EXISTS  9711L

// DNS_ERROR_SECONDARY_DATA              0x000025f0
//
// MessageId: DNS_ERROR_SECONDARY_DATA
//
// MessageText:
//
// Secondary DNS zone data error.
//
#define DNS_ERROR_SECONDARY_DATA         9712L

// DNS_ERROR_NO_CREATE_CACHE_DATA        0x000025f1
//
// MessageId: DNS_ERROR_NO_CREATE_CACHE_DATA
//
// MessageText:
//
// Could not create DNS cache data.
//
#define DNS_ERROR_NO_CREATE_CACHE_DATA   9713L

// DNS_ERROR_NAME_DOES_NOT_EXIST         0x000025f2
//
// MessageId: DNS_ERROR_NAME_DOES_NOT_EXIST
//
// MessageText:
//
// DNS name does not exist.
//
#define DNS_ERROR_NAME_DOES_NOT_EXIST    9714L

// DNS_WARNING_PTR_CREATE_FAILED         0x000025f3
//
// MessageId: DNS_WARNING_PTR_CREATE_FAILED
//
// MessageText:
//
// Could not create pointer (PTR) record.
//
#define DNS_WARNING_PTR_CREATE_FAILED    9715L

// DNS_WARNING_DOMAIN_UNDELETED          0x000025f4
//
// MessageId: DNS_WARNING_DOMAIN_UNDELETED
//
// MessageText:
//
// DNS domain was undeleted.
//
#define DNS_WARNING_DOMAIN_UNDELETED     9716L

// DNS_ERROR_DS_UNAVAILABLE              0x000025f5
//
// MessageId: DNS_ERROR_DS_UNAVAILABLE
//
// MessageText:
//
// The directory service is unavailable.
//
#define DNS_ERROR_DS_UNAVAILABLE         9717L

// DNS_ERROR_DS_ZONE_ALREADY_EXISTS      0x000025f6
//
// MessageId: DNS_ERROR_DS_ZONE_ALREADY_EXISTS
//
// MessageText:
//
// DNS zone already exists in the directory service.
//
#define DNS_ERROR_DS_ZONE_ALREADY_EXISTS 9718L

// DNS_ERROR_NO_BOOTFILE_IF_DS_ZONE      0x000025f7
//
// MessageId: DNS_ERROR_NO_BOOTFILE_IF_DS_ZONE
//
// MessageText:
//
// DNS server not creating or reading the boot file for the directory service integrated DNS zone.
//
#define DNS_ERROR_NO_BOOTFILE_IF_DS_ZONE 9719L

// DNS_ERROR_NODE_IS_DNAME               0x000025f8
//
// MessageId: DNS_ERROR_NODE_IS_DNAME
//
// MessageText:
//
// Node is a DNAME DNS record.
//
#define DNS_ERROR_NODE_IS_DNAME          9720L

// DNS_ERROR_DNAME_COLLISION             0x000025f9
//
// MessageId: DNS_ERROR_DNAME_COLLISION
//
// MessageText:
//
// A DNAME record already exists for given name.
//
#define DNS_ERROR_DNAME_COLLISION        9721L

// DNS_ERROR_ALIAS_LOOP                  0x000025fa
//
// MessageId: DNS_ERROR_ALIAS_LOOP
//
// MessageText:
//
// An alias loop has been detected with either CNAME or DNAME records.
//
#define DNS_ERROR_ALIAS_LOOP             9722L


//
// Operation errors
//

#define DNS_ERROR_OPERATION_BASE 9750

// DNS_INFO_AXFR_COMPLETE                0x00002617
//
// MessageId: DNS_INFO_AXFR_COMPLETE
//
// MessageText:
//
// DNS AXFR (zone transfer) complete.
//
#define DNS_INFO_AXFR_COMPLETE           9751L

// DNS_ERROR_AXFR                        0x00002618
//
// MessageId: DNS_ERROR_AXFR
//
// MessageText:
//
// DNS zone transfer failed.
//
#define DNS_ERROR_AXFR                   9752L

// DNS_INFO_ADDED_LOCAL_WINS             0x00002619
//
// MessageId: DNS_INFO_ADDED_LOCAL_WINS
//
// MessageText:
//
// Added local WINS server.
//
#define DNS_INFO_ADDED_LOCAL_WINS        9753L


//
// Secure update
//

#define DNS_ERROR_SECURE_BASE 9800

// DNS_STATUS_CONTINUE_NEEDED            0x00002649
//
// MessageId: DNS_STATUS_CONTINUE_NEEDED
//
// MessageText:
//
// Secure update call needs to continue update request.
//
#define DNS_STATUS_CONTINUE_NEEDED       9801L


//
// Setup errors
//

#define DNS_ERROR_SETUP_BASE 9850

// DNS_ERROR_NO_TCPIP                    0x0000267b
//
// MessageId: DNS_ERROR_NO_TCPIP
//
// MessageText:
//
// TCP/IP network protocol not installed.
//
#define DNS_ERROR_NO_TCPIP               9851L

// DNS_ERROR_NO_DNS_SERVERS              0x0000267c
//
// MessageId: DNS_ERROR_NO_DNS_SERVERS
//
// MessageText:
//
// No DNS servers configured for local system.
//
#define DNS_ERROR_NO_DNS_SERVERS         9852L


//
// Directory partition (DP) errors
//

#define DNS_ERROR_DP_BASE 9900

// DNS_ERROR_DP_DOES_NOT_EXIST           0x000026ad
//
// MessageId: DNS_ERROR_DP_DOES_NOT_EXIST
//
// MessageText:
//
// The specified directory partition does not exist.
//
#define DNS_ERROR_DP_DOES_NOT_EXIST      9901L

// DNS_ERROR_DP_ALREADY_EXISTS           0x000026ae
//
// MessageId: DNS_ERROR_DP_ALREADY_EXISTS
//
// MessageText:
//
// The specified directory partition already exists.
//
#define DNS_ERROR_DP_ALREADY_EXISTS      9902L

// DNS_ERROR_DP_NOT_ENLISTED             0x000026af
//
// MessageId: DNS_ERROR_DP_NOT_ENLISTED
//
// MessageText:
//
// This DNS server is not enlisted in the specified directory partition.
//
#define DNS_ERROR_DP_NOT_ENLISTED        9903L

// DNS_ERROR_DP_ALREADY_ENLISTED         0x000026b0
//
// MessageId: DNS_ERROR_DP_ALREADY_ENLISTED
//
// MessageText:
//
// This DNS server is already enlisted in the specified directory partition.
//
#define DNS_ERROR_DP_ALREADY_ENLISTED    9904L

// DNS_ERROR_DP_NOT_AVAILABLE            0x000026b1
//
// MessageId: DNS_ERROR_DP_NOT_AVAILABLE
//
// MessageText:
//
// The directory partition is not available at this time. Please wait a few minutes and try again.
//
#define DNS_ERROR_DP_NOT_AVAILABLE       9905L

// DNS_ERROR_DP_FSMO_ERROR               0x000026b2
//
// MessageId: DNS_ERROR_DP_FSMO_ERROR
//
// MessageText:
//
// The operation failed because the domain naming master FSMO role could not be reached. The domain controller holding the domain naming master FSMO role is down or unable to service the request or is not running Windows Server 2003 or later.
//
#define DNS_ERROR_DP_FSMO_ERROR          9906L

//
// DNS RRL errors from 9911 to 9920
//
// DNS_ERROR_RRL_NOT_ENABLED 0x000026B7
//
// MessageId: DNS_ERROR_RRL_NOT_ENABLED
//
// MessageText:
//
// The RRL is not enabled.
//
#define DNS_ERROR_RRL_NOT_ENABLED        9911L

// DNS_ERROR_RRL_INVALID_WINDOW_SIZE 0x000026B8
//
// MessageId: DNS_ERROR_RRL_INVALID_WINDOW_SIZE
//
// MessageText:
//
// The window size parameter is invalid. It should be greater than or equal to 1.
//
#define DNS_ERROR_RRL_INVALID_WINDOW_SIZE 9912L

// DNS_ERROR_RRL_INVALID_IPV4_PREFIX 0x000026B9
//
// MessageId: DNS_ERROR_RRL_INVALID_IPV4_PREFIX
//
// MessageText:
//
// The IPv4 prefix length parameter is invalid. It should be less than or equal to 32.
//
#define DNS_ERROR_RRL_INVALID_IPV4_PREFIX 9913L

// DNS_ERROR_RRL_INVALID_IPV6_PREFIX 0x000026BA
//
// MessageId: DNS_ERROR_RRL_INVALID_IPV6_PREFIX
//
// MessageText:
//
// The IPv6 prefix length parameter is invalid. It should be less than or equal to 128.
//
#define DNS_ERROR_RRL_INVALID_IPV6_PREFIX 9914L

// DNS_ERROR_RRL_INVALID_TC_RATE 0x000026BB
//
// MessageId: DNS_ERROR_RRL_INVALID_TC_RATE
//
// MessageText:
//
// The TC Rate parameter is invalid. It should be less than 10.
//
#define DNS_ERROR_RRL_INVALID_TC_RATE    9915L

// DNS_ERROR_RRL_INVALID_LEAK_RATE 0x000026BC
//
// MessageId: DNS_ERROR_RRL_INVALID_LEAK_RATE
//
// MessageText:
//
// The Leak Rate parameter is invalid. It should be either 0, or between 2 and 10.
//
#define DNS_ERROR_RRL_INVALID_LEAK_RATE  9916L

// DNS_ERROR_RRL_LEAK_RATE_LESSTHAN_TC_RATE 0x000026BD
//
// MessageId: DNS_ERROR_RRL_LEAK_RATE_LESSTHAN_TC_RATE
//
// MessageText:
//
// The Leak Rate or TC Rate parameter is invalid. Leak Rate should be greater than TC Rate.
//
#define DNS_ERROR_RRL_LEAK_RATE_LESSTHAN_TC_RATE 9917L


//
// DNS Virtualization errors from 9921 to 9950
//
// DNS_ERROR_VIRTUALIZATION_INSTANCE_ALREADY_EXISTS    0x000026c1
//
// MessageId: DNS_ERROR_VIRTUALIZATION_INSTANCE_ALREADY_EXISTS
//
// MessageText:
//
// The virtualization instance already exists.
//
#define DNS_ERROR_VIRTUALIZATION_INSTANCE_ALREADY_EXISTS 9921L

// DNS_ERROR_VIRTUALIZATION_INSTANCE_DOES_NOT_EXIST    0x000026c2
//
// MessageId: DNS_ERROR_VIRTUALIZATION_INSTANCE_DOES_NOT_EXIST
//
// MessageText:
//
// The virtualization instance does not exist.
//
#define DNS_ERROR_VIRTUALIZATION_INSTANCE_DOES_NOT_EXIST 9922L

// DNS_ERROR_VIRTUALIZATION_TREE_LOCKED        0x000026c3
//
// MessageId: DNS_ERROR_VIRTUALIZATION_TREE_LOCKED
//
// MessageText:
//
// The virtualization tree is locked.
//
#define DNS_ERROR_VIRTUALIZATION_TREE_LOCKED 9923L

// DNS_ERROR_INVAILD_VIRTUALIZATION_INSTANCE_NAME      0x000026c4
//
// MessageId: DNS_ERROR_INVAILD_VIRTUALIZATION_INSTANCE_NAME
//
// MessageText:
//
// Invalid virtualization instance name.
//
#define DNS_ERROR_INVAILD_VIRTUALIZATION_INSTANCE_NAME 9924L

// DNS_ERROR_DEFAULT_VIRTUALIZATION_INSTANCE   0x000026c5
//
// MessageId: DNS_ERROR_DEFAULT_VIRTUALIZATION_INSTANCE
//
// MessageText:
//
// The default virtualization instance cannot be added, removed or modified.
//
#define DNS_ERROR_DEFAULT_VIRTUALIZATION_INSTANCE 9925L


//
// DNS ZoneScope errors from 9951 to 9970
//
// DNS_ERROR_ZONESCOPE_ALREADY_EXISTS               0x000026df
//
// MessageId: DNS_ERROR_ZONESCOPE_ALREADY_EXISTS
//
// MessageText:
//
// The scope already exists for the zone.
//
#define DNS_ERROR_ZONESCOPE_ALREADY_EXISTS 9951L

// DNS_ERROR_ZONESCOPE_DOES_NOT_EXIST       0x000026e0
//
// MessageId: DNS_ERROR_ZONESCOPE_DOES_NOT_EXIST
//
// MessageText:
//
// The scope does not exist for the zone.
//
#define DNS_ERROR_ZONESCOPE_DOES_NOT_EXIST 9952L

// DNS_ERROR_DEFAULT_ZONESCOPE 0x000026e1
//
// MessageId: DNS_ERROR_DEFAULT_ZONESCOPE
//
// MessageText:
//
// The scope is the same as the default zone scope.
//
#define DNS_ERROR_DEFAULT_ZONESCOPE      9953L

// DNS_ERROR_INVALID_ZONESCOPE_NAME 0x000026e2
//
// MessageId: DNS_ERROR_INVALID_ZONESCOPE_NAME
//
// MessageText:
//
// The scope name contains invalid characters.
//
#define DNS_ERROR_INVALID_ZONESCOPE_NAME 9954L

// DNS_ERROR_NOT_ALLOWED_WITH_ZONESCOPES 0x000026e3
//
// MessageId: DNS_ERROR_NOT_ALLOWED_WITH_ZONESCOPES
//
// MessageText:
//
// Operation not allowed when the zone has scopes.
//
#define DNS_ERROR_NOT_ALLOWED_WITH_ZONESCOPES 9955L

// DNS_ERROR_LOAD_ZONESCOPE_FAILED 0x000026e4
//
// MessageId: DNS_ERROR_LOAD_ZONESCOPE_FAILED
//
// MessageText:
//
// Failed to load zone scope.
//
#define DNS_ERROR_LOAD_ZONESCOPE_FAILED  9956L

// DNS_ERROR_ZONESCOPE_FILE_WRITEBACK_FAILED 0x000026e5
//
// MessageId: DNS_ERROR_ZONESCOPE_FILE_WRITEBACK_FAILED
//
// MessageText:
//
// Failed to write data file for DNS zone scope. Please verify the file exists and is writable.
//
#define DNS_ERROR_ZONESCOPE_FILE_WRITEBACK_FAILED 9957L

// DNS_ERROR_INVALID_SCOPE_NAME 0x000026e6
//
// MessageId: DNS_ERROR_INVALID_SCOPE_NAME
//
// MessageText:
//
// The scope name contains invalid characters.
//
#define DNS_ERROR_INVALID_SCOPE_NAME     9958L

// DNS_ERROR_SCOPE_DOES_NOT_EXIST       0x000026e7
//
// MessageId: DNS_ERROR_SCOPE_DOES_NOT_EXIST
//
// MessageText:
//
// The scope does not exist.
//
#define DNS_ERROR_SCOPE_DOES_NOT_EXIST   9959L

// DNS_ERROR_DEFAULT_SCOPE 0x000026e8
//
// MessageId: DNS_ERROR_DEFAULT_SCOPE
//
// MessageText:
//
// The scope is the same as the default scope.
//
#define DNS_ERROR_DEFAULT_SCOPE          9960L

// DNS_ERROR_INVALID_SCOPE_OPERATION 0x000026e9
//
// MessageId: DNS_ERROR_INVALID_SCOPE_OPERATION
//
// MessageText:
//
// The operation is invalid on the scope.
//
#define DNS_ERROR_INVALID_SCOPE_OPERATION 9961L

// DNS_ERROR_SCOPE_LOCKED 0x000026ea
//
// MessageId: DNS_ERROR_SCOPE_LOCKED
//
// MessageText:
//
// The scope is locked.
//
#define DNS_ERROR_SCOPE_LOCKED           9962L

// DNS_ERROR_SCOPE_ALREADY_EXISTS 0x000026eb
//
// MessageId: DNS_ERROR_SCOPE_ALREADY_EXISTS
//
// MessageText:
//
// The scope already exists.
//
#define DNS_ERROR_SCOPE_ALREADY_EXISTS   9963L


//
// DNS Policy errors from 9971 to 9999
//
// DNS_ERROR_POLICY_ALREADY_EXISTS 0x000026f3
//
// MessageId: DNS_ERROR_POLICY_ALREADY_EXISTS
//
// MessageText:
//
// A policy with the same name already exists on this level (server level or zone level) on the DNS server.
//
#define DNS_ERROR_POLICY_ALREADY_EXISTS  9971L

// DNS_ERROR_POLICY_DOES_NOT_EXIST 0x000026f4
//
// MessageId: DNS_ERROR_POLICY_DOES_NOT_EXIST
//
// MessageText:
//
// No policy with this name exists on this level (server level or zone level) on the DNS server.
//
#define DNS_ERROR_POLICY_DOES_NOT_EXIST  9972L

// DNS_ERROR_POLICY_INVALID_CRITERIA 0x000026f5
//
// MessageId: DNS_ERROR_POLICY_INVALID_CRITERIA
//
// MessageText:
//
// The criteria provided in the policy are invalid.
//
#define DNS_ERROR_POLICY_INVALID_CRITERIA 9973L

// DNS_ERROR_POLICY_INVALID_SETTINGS 0x000026f6
//
// MessageId: DNS_ERROR_POLICY_INVALID_SETTINGS
//
// MessageText:
//
// At least one of the settings of this policy is invalid.
//
#define DNS_ERROR_POLICY_INVALID_SETTINGS 9974L

// DNS_ERROR_CLIENT_SUBNET_IS_ACCESSED 0x000026f7
//
// MessageId: DNS_ERROR_CLIENT_SUBNET_IS_ACCESSED
//
// MessageText:
//
// The client subnet cannot be deleted while it is being accessed by a policy.
//
#define DNS_ERROR_CLIENT_SUBNET_IS_ACCESSED 9975L

// DNS_ERROR_CLIENT_SUBNET_DOES_NOT_EXIST 0x000026f8
//
// MessageId: DNS_ERROR_CLIENT_SUBNET_DOES_NOT_EXIST
//
// MessageText:
//
// The client subnet does not exist on the DNS server.
//
#define DNS_ERROR_CLIENT_SUBNET_DOES_NOT_EXIST 9976L

// DNS_ERROR_CLIENT_SUBNET_ALREADY_EXISTS 0x000026f9
//
// MessageId: DNS_ERROR_CLIENT_SUBNET_ALREADY_EXISTS
//
// MessageText:
//
// A client subnet with this name already exists on the DNS server.
//
#define DNS_ERROR_CLIENT_SUBNET_ALREADY_EXISTS 9977L

// DNS_ERROR_SUBNET_DOES_NOT_EXIST 0x000026fa
//
// MessageId: DNS_ERROR_SUBNET_DOES_NOT_EXIST
//
// MessageText:
//
// The IP subnet specified does not exist in the client subnet.
//
#define DNS_ERROR_SUBNET_DOES_NOT_EXIST  9978L

// DNS_ERROR_SUBNET_ALREADY_EXISTS 0x000026fb
//
// MessageId: DNS_ERROR_SUBNET_ALREADY_EXISTS
//
// MessageText:
//
// The IP subnet that is being added, already exists in the client subnet.
//
#define DNS_ERROR_SUBNET_ALREADY_EXISTS  9979L

// DNS_ERROR_POLICY_LOCKED 0x000026fc
//
// MessageId: DNS_ERROR_POLICY_LOCKED
//
// MessageText:
//
// The policy is locked.
//
#define DNS_ERROR_POLICY_LOCKED          9980L

// DNS_ERROR_POLICY_INVALID_WEIGHT 0x000026fd
//
// MessageId: DNS_ERROR_POLICY_INVALID_WEIGHT
//
// MessageText:
//
// The weight of the scope in the policy is invalid.
//
#define DNS_ERROR_POLICY_INVALID_WEIGHT  9981L

// DNS_ERROR_POLICY_INVALID_NAME 0x000026fe
//
// MessageId: DNS_ERROR_POLICY_INVALID_NAME
//
// MessageText:
//
// The DNS policy name is invalid.
//
#define DNS_ERROR_POLICY_INVALID_NAME    9982L

// DNS_ERROR_POLICY_MISSING_CRITERIA 0x000026ff
//
// MessageId: DNS_ERROR_POLICY_MISSING_CRITERIA
//
// MessageText:
//
// The policy is missing criteria.
//
#define DNS_ERROR_POLICY_MISSING_CRITERIA 9983L

// DNS_ERROR_INVALID_CLIENT_SUBNET_NAME 0x00002700
//
// MessageId: DNS_ERROR_INVALID_CLIENT_SUBNET_NAME
//
// MessageText:
//
// The name of the the client subnet record is invalid.
//
#define DNS_ERROR_INVALID_CLIENT_SUBNET_NAME 9984L

// DNS_ERROR_POLICY_PROCESSING_ORDER_INVALID 0x00002701
//
// MessageId: DNS_ERROR_POLICY_PROCESSING_ORDER_INVALID
//
// MessageText:
//
// Invalid policy processing order.
//
#define DNS_ERROR_POLICY_PROCESSING_ORDER_INVALID 9985L

// DNS_ERROR_POLICY_SCOPE_MISSING 0x00002702
//
// MessageId: DNS_ERROR_POLICY_SCOPE_MISSING
//
// MessageText:
//
// The scope information has not been provided for a policy that requires it.
//
#define DNS_ERROR_POLICY_SCOPE_MISSING   9986L

// DNS_ERROR_POLICY_SCOPE_NOT_ALLOWED 0x00002703
//
// MessageId: DNS_ERROR_POLICY_SCOPE_NOT_ALLOWED
//
// MessageText:
//
// The scope information has been provided for a policy that does not require it.
//
#define DNS_ERROR_POLICY_SCOPE_NOT_ALLOWED 9987L

// DNS_ERROR_SERVERSCOPE_IS_REFERENCED 0x00002704
//
// MessageId: DNS_ERROR_SERVERSCOPE_IS_REFERENCED
//
// MessageText:
//
// The server scope cannot be deleted because it is referenced by a DNS Policy.
//
#define DNS_ERROR_SERVERSCOPE_IS_REFERENCED 9988L

// DNS_ERROR_ZONESCOPE_IS_REFERENCED 0x00002705
//
// MessageId: DNS_ERROR_ZONESCOPE_IS_REFERENCED
//
// MessageText:
//
// The zone scope cannot be deleted because it is referenced by a DNS Policy.
//
#define DNS_ERROR_ZONESCOPE_IS_REFERENCED 9989L

// DNS_ERROR_POLICY_INVALID_CRITERIA_CLIENT_SUBNET 0x00002706
//
// MessageId: DNS_ERROR_POLICY_INVALID_CRITERIA_CLIENT_SUBNET
//
// MessageText:
//
// The criterion client subnet provided in the policy is invalid.
//
#define DNS_ERROR_POLICY_INVALID_CRITERIA_CLIENT_SUBNET 9990L

// DNS_ERROR_POLICY_INVALID_CRITERIA_TRANSPORT_PROTOCOL 0x00002707
//
// MessageId: DNS_ERROR_POLICY_INVALID_CRITERIA_TRANSPORT_PROTOCOL
//
// MessageText:
//
// The criterion transport protocol provided in the policy is invalid.
//
#define DNS_ERROR_POLICY_INVALID_CRITERIA_TRANSPORT_PROTOCOL 9991L

// DNS_ERROR_POLICY_INVALID_CRITERIA_NETWORK_PROTOCOL 0x00002708
//
// MessageId: DNS_ERROR_POLICY_INVALID_CRITERIA_NETWORK_PROTOCOL
//
// MessageText:
//
// The criterion network protocol provided in the policy is invalid.
//
#define DNS_ERROR_POLICY_INVALID_CRITERIA_NETWORK_PROTOCOL 9992L

// DNS_ERROR_POLICY_INVALID_CRITERIA_INTERFACE 0x00002709
//
// MessageId: DNS_ERROR_POLICY_INVALID_CRITERIA_INTERFACE
//
// MessageText:
//
// The criterion interface provided in the policy is invalid.
//
#define DNS_ERROR_POLICY_INVALID_CRITERIA_INTERFACE 9993L

// DNS_ERROR_POLICY_INVALID_CRITERIA_FQDN 0x0000270A
//
// MessageId: DNS_ERROR_POLICY_INVALID_CRITERIA_FQDN
//
// MessageText:
//
// The criterion FQDN provided in the policy is invalid.
//
#define DNS_ERROR_POLICY_INVALID_CRITERIA_FQDN 9994L

// DNS_ERROR_POLICY_INVALID_CRITERIA_QUERY_TYPE 0x0000270B
//
// MessageId: DNS_ERROR_POLICY_INVALID_CRITERIA_QUERY_TYPE
//
// MessageText:
//
// The criterion query type provided in the policy is invalid.
//
#define DNS_ERROR_POLICY_INVALID_CRITERIA_QUERY_TYPE 9995L

// DNS_ERROR_POLICY_INVALID_CRITERIA_TIME_OF_DAY 0x0000270C
//
// MessageId: DNS_ERROR_POLICY_INVALID_CRITERIA_TIME_OF_DAY
//
// MessageText:
//
// The criterion time of day provided in the policy is invalid.
//
#define DNS_ERROR_POLICY_INVALID_CRITERIA_TIME_OF_DAY 9996L

///////////////////////////////////////////////////
//                                               //
//             End of DNS Error Codes            //
//                                               //
//                  9000 to 9999                 //
///////////////////////////////////////////////////

// ░░░ Structs uses by dnsapi Functions ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

typedef int32_t DNS_STATUS;

typedef uint32_t IP4_ADDRESS;
typedef IP4_ADDRESS NS_A_DATA;

typedef struct DNS_RECORD_FLAGS
{
	uint32_t Section : 2;
	uint32_t Delete : 1;
	uint32_t CharSet : 2;
	uint32_t Unused : 3;
	uint32_t Reserved : 24;
} DNS_RECORD_FLAGS;

typedef struct
{
	wchar_t *pNamePrimaryServer;
	wchar_t *pNameAdministrator;
	uint32_t dwSerialNo;
	uint32_t dwRefresh;
	uint32_t dwRetry;
	uint32_t dwExpire;
	uint32_t dwDefaultTtl;
} DNS_SOA_DATAW;

typedef uint32_t DNS_A_DATA;
typedef wchar_t *DNS_PTR_DATAW;

typedef struct DNS_MINFO_DATAW
{
	wchar_t *pNameMailbox;
	wchar_t *pNameErrorsMailbox;
} DNS_MINFO_DATAW;

typedef struct DNS_MX_DATAW
{
	wchar_t *pNameExchange;
	uint16_t wPreference;
	uint16_t Pad;        // keep ptrs DWORD aligned
} DNS_MX_DATAW;

typedef struct DNS_TXT_DATAW
{
	uint32_t dwStringCount;
	wchar_t *pStringArray[1];
} DNS_TXT_DATAW;

typedef struct DNS_NULL_DATA
{
	uint32_t dwByteCount;
	uint8_t Data[1];
} DNS_NULL_DATA;

typedef struct DNS_WKS_DATA
{
	IP4_ADDRESS IpAddress;
	uint8_t chProtocol;
	uint8_t BitMask[1];
} DNS_WKS_DATA;

typedef union IP6_ADDRESS
{
	uint64_t IP6Qword[2];
	uint32_t IP6Dword[4];
	uint16_t IP6Word[8];
	uint8_t IP6Byte[16];
} IP6_ADDRESS;

typedef IP6_ADDRESS DNS_AAAA_DATA;

typedef struct DNS_KEY_DATA
{
	uint16_t wFlags;
	uint8_t chProtocol;
	uint8_t chAlgorithm;
	uint16_t wKeyLength;
	uint16_t wPad;            // keep byte field aligned
	uint8_t Key[1];
} DNS_KEY_DATA;

typedef struct DNS_SIG_DATAW
{
	uint16_t wTypeCovered;
	uint8_t chAlgorithm;
	uint8_t chLabelCount;
	uint32_t dwOriginalTtl;
	uint32_t dwExpiration;
	uint32_t dwTimeSigned;
	uint16_t wKeyTag;
	uint16_t wSignatureLength;
	wchar_t *pNameSigner;
	uint8_t Signature[1];
} DNS_SIG_DATAW;

typedef struct DNS_ATMA_DATA
{
	uint8_t            AddressType;
	uint8_t            Address[DNS_ATMA_MAX_ADDR_LENGTH];

	//  E164 -- Null terminated string of less than
	//      DNS_ATMA_MAX_ADDR_LENGTH
	//
	//  For NSAP (AESA) BCD encoding of exactly
	//      DNS_ATMA_AESA_ADDR_LENGTH
} DNS_ATMA_DATA;

typedef struct DNS_NXT_DATAW
{
	wchar_t *pNameNext;
	uint16_t wNumTypes;
	uint16_t wTypes[1];
} DNS_NXT_DATAW;

typedef struct DNS_SRV_DATAW
{
	wchar_t *pNameTarget;
	uint16_t wPriority;
	uint16_t wWeight;
	uint16_t wPort;
	uint16_t Pad;            // keep ptrs DWORD aligned
} DNS_SRV_DATAW;

typedef struct DNS_NAPTR_DATAW
{
	uint16_t wOrder;
	uint16_t wPreference;
	wchar_t *pFlags;
	wchar_t *pService;
	wchar_t *pRegularExpression;
	wchar_t *pReplacement;
} DNS_NAPTR_DATAW;

typedef struct DNS_OPT_DATA
{
	uint16_t wDataLength;
	uint16_t wPad;            // keep byte field aligned
	uint8_t Data[1];
} DNS_OPT_DATA;

typedef struct DNS_DS_DATA
{
	uint16_t wKeyTag;
	uint8_t chAlgorithm;
	uint8_t chDigestType;
	uint16_t wDigestLength;
	uint16_t wPad;            // keep byte field aligned
	uint8_t Digest[1];
} DNS_DS_DATA;

typedef struct DNS_RRSIG_DATAW
{
	uint16_t wTypeCovered;
	uint8_t chAlgorithm;
	uint8_t chLabelCount;
	uint32_t dwOriginalTtl;
	uint32_t dwExpiration;
	uint32_t dwTimeSigned;
	uint16_t wKeyTag;
	uint16_t wSignatureLength;
	wchar_t *pNameSigner;
	uint8_t Signature[1];
} DNS_RRSIG_DATAW;

typedef struct DNS_NSEC_DATAW
{
	wchar_t *pNextDomainName;
	uint16_t wTypeBitMapsLength;
	uint16_t wPad;            // keep byte field aligned
	uint8_t TypeBitMaps[1];
} DNS_NSEC_DATAW;

typedef struct DNS_TKEY_DATAW
{
	wchar_t *pNameAlgorithm;
	uint8_t *pAlgorithmPacket;
	uint8_t *pKey;
	uint8_t *pOtherData;
	uint32_t dwCreateTime;
	uint32_t dwExpireTime;
	uint16_t wMode;
	uint16_t wError;
	uint16_t wKeyLength;
	uint16_t wOtherLength;
	uint8_t cAlgNameLength;
	bool_t bPacketPointers;
} DNS_TKEY_DATAW;

typedef struct DNS_TSIG_DATAW
{
	wchar_t *pNameAlgorithm;
	uint8_t *pAlgorithmPacket;
	uint8_t *pSignature;
	uint8_t *pOtherData;
	int64_t i64CreateTime;
	uint16_t wFudgeTime;
	uint16_t wOriginalXid;
	uint16_t wError;
	uint16_t wSigLength;
	uint16_t wOtherLength;
	uint8_t cAlgNameLength;
	bool_t bPacketPointers;
} DNS_TSIG_DATAW;

typedef struct DNS_WINS_DATA
{
	uint32_t dwMappingFlag;
	uint32_t dwLookupTimeout;
	uint32_t dwCacheTimeout;
	uint32_t cWinsServerCount;
	IP4_ADDRESS WinsServers[1];
} DNS_WINS_DATA;

typedef struct DNS_WINSR_DATAW
{
	uint32_t dwMappingFlag;
	uint32_t dwLookupTimeout;
	uint32_t dwCacheTimeout;
	wchar_t *pNameResultDomain;
} DNS_WINSR_DATAW;

typedef struct DNS_DHCID_DATA
{
	uint32_t dwByteCount;
	uint8_t DHCID[1];
} DNS_DHCID_DATA;

typedef struct DNS_NSEC3_DATA
{
	uint8_t chAlgorithm;
	uint8_t bFlags;
	uint16_t wIterations;
	uint8_t bSaltLength;
	uint8_t bHashLength;
	uint16_t wTypeBitMapsLength;
	uint8_t chData[1];
} DNS_NSEC3_DATA;

typedef struct DNS_NSEC3PARAM_DATA
{
	uint8_t chAlgorithm;
	uint8_t bFlags;
	uint16_t wIterations;
	uint8_t bSaltLength;
	uint8_t bPad[3];        // keep salt field aligned
	uint8_t pbSalt[1];
} DNS_NSEC3PARAM_DATA;

typedef struct DNS_TLSA_DATA
{
	uint8_t bCertUsage;
	uint8_t bSelector;
	uint8_t bMatchingType;
	uint16_t bCertificateAssociationDataLength;
	uint8_t bPad[3];        // keep certificate association data field aligned
	uint8_t bCertificateAssociationData[1];
} DNS_TLSA_DATA;

typedef struct DNS_SVCB_PARAM_IPV4
{
	uint16_t cIps;
	IP4_ADDRESS rgIps[1];
} DNS_SVCB_PARAM_IPV4;

typedef struct DNS_SVCB_PARAM_IPV6
{
	uint16_t cIps;
	IP6_ADDRESS rgIps[1];
} DNS_SVCB_PARAM_IPV6;

typedef struct DNS_SVCB_PARAM_MANDATORY
{
	uint16_t cMandatoryKeys;
	uint16_t rgwMandatoryKeys[1];
} DNS_SVCB_PARAM_MANDATORY;

typedef struct DNS_SVCB_PARAM_ALPN_ID
{
	uint8_t cBytes;
	uint8_t *pbId;
} DNS_SVCB_PARAM_ALPN_ID;

typedef struct DNS_SVCB_PARAM_ALPN
{
	uint16_t cIds;
	DNS_SVCB_PARAM_ALPN_ID rgIds[1];
} DNS_SVCB_PARAM_ALPN;

typedef struct DNS_SVCB_PARAM_UNKNOWN
{
	uint16_t cBytes;
	uint8_t pbSvcParamValue[1];
} DNS_SVCB_PARAM_UNKNOWN;

#pragma warning(push)
#pragma warning(disable: 4201) // nameless struct/union (anonymous union for SVCB parameter variants)
typedef struct DNS_SVCB_PARAM
{
	uint16_t wSvcParamKey;
	union
	{
		DNS_SVCB_PARAM_IPV4 *pIpv4Hints;
		DNS_SVCB_PARAM_IPV6 *pIpv6Hints;
		DNS_SVCB_PARAM_MANDATORY *pMandatory;
		DNS_SVCB_PARAM_ALPN *pAlpn;
		uint16_t wPort;
		DNS_SVCB_PARAM_UNKNOWN *pUnknown;
		char_t *pszDohPath;
		void *pReserved;
	};
} DNS_SVCB_PARAM;
#pragma warning(pop)

typedef struct DNS_SVCB_DATA
{
	uint16_t wSvcPriority;
	char_t *pszTargetName;
	uint16_t cSvcParams;
	DNS_SVCB_PARAM *pSvcParams;
} DNS_SVCB_DATA;

typedef struct DNS_UNKNOWN_DATA
{
	uint32_t dwByteCount;
	uint8_t bData[1];
} DNS_UNKNOWN_DATA;

typedef struct DNS_RECORD_W
{
	struct DNS_RECORD_W *pNext;
	wchar_t *pName;
	uint16_t wType;
	uint16_t wDataLength;    // Not referenced for DNS record types
	// defined above.
	union
	{
		uint32_t DW;     // flags as DWORD
		DNS_RECORD_FLAGS S;      // flags as structure

	} Flags;

	uint32_t dwTtl;
	uint32_t dwReserved;

	//  Record Data

	union
	{
		uint32_t          A; // IPv4
		DNS_SOA_DATAW       SOA, Soa;
		wchar_t *PTR, Ptr,
			NS, Ns,
			CNAME, Cname,
			DNAME, Dname,
			MB, Mb,
			MD, Md,
			MF, Mf,
			MG, Mg,
			MR, Mr;
		DNS_MINFO_DATAW     MINFO, Minfo,
			RP, Rp;
		DNS_MX_DATAW        MX, Mx,
			AFSDB, Afsdb,
			RT, Rt;
		DNS_TXT_DATAW       HINFO, Hinfo,
			ISDN, Isdn,
			TXT, Txt,
			X25;
		DNS_NULL_DATA       Null;
		DNS_WKS_DATA        WKS, Wks;
		DNS_AAAA_DATA       AAAA;
		DNS_KEY_DATA        KEY, Key;
		DNS_SIG_DATAW       SIG, Sig;
		DNS_ATMA_DATA       ATMA, Atma;
		DNS_NXT_DATAW       NXT, Nxt;
		DNS_SRV_DATAW       SRV, Srv;
		DNS_NAPTR_DATAW     NAPTR, Naptr;
		DNS_OPT_DATA        OPT, Opt;
		DNS_DS_DATA         DS, Ds;
		DNS_RRSIG_DATAW     RRSIG, Rrsig;
		DNS_NSEC_DATAW      NSEC, Nsec;
		DNS_KEY_DATA        DNSKEY, Dnskey;
		DNS_TKEY_DATAW      TKEY, Tkey;
		DNS_TSIG_DATAW      TSIG, Tsig;
		DNS_WINS_DATA       WINS, Wins;
		DNS_WINSR_DATAW     WINSR, WinsR, NBSTAT, Nbstat;
		DNS_DHCID_DATA      DHCID;
		DNS_NSEC3_DATA      NSEC3, Nsec3;
		DNS_NSEC3PARAM_DATA NSEC3PARAM, Nsec3Param;
		DNS_TLSA_DATA       TLSA, Tlsa;
		DNS_SVCB_DATA       SVCB, Svcb;
		DNS_UNKNOWN_DATA    UNKNOWN, Unknown;
		uint8_t             *pDataPtr;

	} Data;
} DNS_RECORD_W;

// DNS_RECORD_W.Flags.S.CharSet
typedef enum DNS_CHARSET
{
	DnsCharSetUnknown,
	DnsCharSetUnicode,
	DnsCharSetUtf8,
	DnsCharSetAnsi,
} DNS_CHARSET;

//
//  Free structures returned from dnsapi.dll
//
//  Currently supported free structures:
//      Flat -- flat structure, including those allocated by DnsQueryConfig()
//      RecordList -- deep record list free, including sub-fields of DNS_RECORD;
//          includes those returned by DnsQuery() or DnsRecordSetCopy()
//
// https://learn.microsoft.com/en-us/windows/win32/api/windns/ne-windns-dns_free_type
typedef enum DNS_FREE_TYPE
{
	DnsFreeFlat = 0,
	DnsFreeRecordList,
	DnsFreeParsedMessageFields
} DNS_FREE_TYPE;

//  DNS name validation
// https://learn.microsoft.com/en-us/windows/win32/api/windns/ne-windns-dns_name_format
typedef enum DNS_NAME_FORMAT
{
	DnsNameDomain,
	DnsNameDomainLabel,
	DnsNameHostnameFull,	// strict RFC 952/1123 hostname (letters, digits, hyphen - no leading/trailing hyphen - not all-numeric)
	DnsNameHostnameLabel,
	DnsNameWildcard,
	DnsNameSrvRecord,
	DnsNameValidateTld		// rejects names that would need search-suffix
} DNS_NAME_FORMAT;

// ░░░ Loader API ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

boolean_t InitializeDnsApi(boolean_t skipLoad);
extern Handle DnsApiDllBaseAddress;

boolean_t LoadDnsFree();
boolean_t LoadDnsQuery_W();
boolean_t LoadDnsQuery_UTF8();
boolean_t LoadDnsValidateName_W();
boolean_t LoadDnsValidateName_UTF8();

// ░░░ dnsapi Function Typedefs ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

// https://learn.microsoft.com/en-us/windows/win32/api/windns/nf-windns-dnsfree
typedef void(*DnsFree_t)(void *pData, DNS_FREE_TYPE FreeType);

// https://learn.microsoft.com/en-us/windows/win32/api/windns/nf-windns-dnsquery_w
typedef DNS_STATUS(*DnsQuery_W_t)(wchar_t const *pszName, uint16_t wType, uint32_t Options, void *pExtra, DNS_RECORD_W **ppQueryResults, void *pReserved);

// https://learn.microsoft.com/en-us/windows/win32/api/windns/nf-windns-dnsquery_utf8
typedef DNS_STATUS(*DnsQuery_UTF8_t)(char_t const *pszName, uint16_t wType, uint32_t Options, void *pExtra, DNS_RECORD_W **ppQueryResults, void *pReserved);

// https://learn.microsoft.com/en-us/windows/win32/api/windns/nf-windns-dnsvalidatename_w
typedef DNS_STATUS(*DnsValidateName_W_t)(wchar_t const *pszName, DNS_NAME_FORMAT Format);

// https://learn.microsoft.com/en-us/windows/win32/api/windns/nf-windns-dnsvalidatename_utf8
typedef DNS_STATUS(*DnsValidateName_UTF8_t)(char_t const *pszName, DNS_NAME_FORMAT Format);

// ░░░ Callable Grouped dnsapi Functions ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

struct DnsApiFunctions
{
	DnsFree_t DnsFree;
	DnsQuery_W_t DnsQuery_W;
	DnsQuery_UTF8_t DnsQuery_UTF8;
	DnsValidateName_W_t DnsValidateName_W;
	DnsValidateName_UTF8_t DnsValidateName_UTF8;
};

extern struct DnsApiFunctions DnsApi;

// ░░░ Wrap to normal Function ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

static __forceinline void DnsFree(void *pData, DNS_FREE_TYPE FreeType) { DnsApi.DnsFree(pData, FreeType); }
static __forceinline DNS_STATUS DnsQuery_W(wchar_t const *pszName, uint16_t wType, uint32_t Options, void *pExtra, DNS_RECORD_W **ppQueryResults, void *pReserved) { return DnsApi.DnsQuery_W(pszName, wType, Options, pExtra, ppQueryResults, pReserved); }
static __forceinline DNS_STATUS DnsQuery_UTF8(char_t const *pszName, uint16_t wType, uint32_t Options, void *pExtra, DNS_RECORD_W **ppQueryResults, void *pReserved) { return DnsApi.DnsQuery_UTF8(pszName, wType, Options, pExtra, ppQueryResults, pReserved); }
static __forceinline DNS_STATUS DnsValidateName_W(wchar_t const *pszName, DNS_NAME_FORMAT Format) { return DnsApi.DnsValidateName_W(pszName, Format); }
static __forceinline DNS_STATUS DnsValidateName_UTF8(char_t const *pszName, DNS_NAME_FORMAT Format) { return DnsApi.DnsValidateName_UTF8(pszName, Format); }