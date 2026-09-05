#pragma once
#include "generic_windows.h"

// ░░░ Definitions ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

/*
 * This is used instead of -1, since the
 * SOCKET type is unsigned.
 */
#define INVALID_SOCKET  (Handle)(~0)
#define SOCKET_ERROR            (-1)

#define WSAPROTOCOL_LEN			255
#define WSADESCRIPTION_LEN      256
#define WSASYS_STATUS_LEN       128

#define MAX_PROTOCOL_CHAIN 7

#define BASE_PROTOCOL      1
#define LAYERED_PROTOCOL   0

/* Event flag definitions for WSAPoll(). */

#define POLLRDNORM  0x0100
#define POLLRDBAND  0x0200
#define POLLIN      (POLLRDNORM | POLLRDBAND)
#define POLLPRI     0x0400

#define POLLWRNORM  0x0010
#define POLLOUT     (POLLWRNORM)
#define POLLWRBAND  0x0020

#define POLLERR     0x0001
#define POLLHUP     0x0002
#define POLLNVAL    0x0004

//
// Although AF_UNSPEC is defined for backwards compatibility, using
// AF_UNSPEC for the "af" parameter when creating a socket is STRONGLY
// DISCOURAGED.  The interpretation of the "protocol" parameter
// depends on the actual address family chosen.  As environments grow
// to include more and more address families that use overlapping
// protocol values there is more and more chance of choosing an
// undesired address family when AF_UNSPEC is used.
//
#define AF_UNSPEC       0               // unspecified
#define AF_UNIX         1               // local to host (pipes, portals)
#define AF_INET         2               // internetwork: UDP, TCP, etc.
#define AF_IMPLINK      3               // arpanet imp addresses
#define AF_PUP          4               // pup protocols: e.g. BSP
#define AF_CHAOS        5               // mit CHAOS protocols
#define AF_NS           6               // XEROX NS protocols
#define AF_IPX          AF_NS           // IPX protocols: IPX, SPX, etc.
#define AF_ISO          7               // ISO protocols
#define AF_OSI          AF_ISO          // OSI is ISO
#define AF_ECMA         8               // european computer manufacturers
#define AF_DATAKIT      9               // datakit protocols
#define AF_CCITT        10              // CCITT protocols, X.25 etc
#define AF_SNA          11              // IBM SNA
#define AF_DECnet       12              // DECnet
#define AF_DLI          13              // Direct data link interface
#define AF_LAT          14              // LAT
#define AF_HYLINK       15              // NSC Hyperchannel
#define AF_APPLETALK    16              // AppleTalk
#define AF_NETBIOS      17              // NetBios-style addresses
#define AF_VOICEVIEW    18              // VoiceView
#define AF_FIREFOX      19              // Protocols from Firefox
#define AF_UNKNOWN1     20              // Somebody is using this!
#define AF_BAN          21              // Banyan
#define AF_ATM          22              // Native ATM Services
#define AF_INET6        23              // Internetwork Version 6
#define AF_CLUSTER      24              // Microsoft Wolfpack
#define AF_12844        25              // IEEE 1284.4 WG AF
#define AF_IRDA         26              // IrDA
#define AF_NETDES       28              // Network Designers OSI & gateway

#define AF_TCNPROCESS   29
#define AF_TCNMESSAGE   30
#define AF_ICLFXBM      31
#define AF_BTH          32    
#define AF_LINK         33
#define AF_HYPERV       34
#define AF_MAX          35

/*
 * WinSock 2 extension -- manifest constants for return values of the condition function
 */
#define CF_ACCEPT       0x0000
#define CF_REJECT       0x0001
#define CF_DEFER        0x0002

 /*
  * WinSock 2 extension -- manifest constants for shutdown()
  */
#define SD_RECEIVE      0x00
#define SD_SEND         0x01
#define SD_BOTH         0x02

  /*
   * WinSock 2 extension -- data type and manifest constants for socket groups
   */
#define SG_UNCONSTRAINED_GROUP   0x01

/*
 * Constants and structures defined by the internet system,
 * Per RFC 790, September 1981, taken from the BSD file netinet/in.h.
 */

 /*
  * Protocols
  */
#define IPPROTO_IP              0               /* dummy for IP */
#define IPPROTO_ICMP            1               /* control message protocol */
#define IPPROTO_IGMP            2               /* group management protocol */
#define IPPROTO_GGP             3               /* gateway^2 (deprecated) */
#define IPPROTO_TCP             6               /* tcp */
#define IPPROTO_PUP             12              /* pup */
#define IPPROTO_UDP             17              /* user datagram protocol */
#define IPPROTO_IDP             22              /* xns idp */
#define IPPROTO_ND              77              /* UNOFFICIAL net disk proto */

#define IPPROTO_RAW             255             /* raw IP packet */
#define IPPROTO_MAX             256

  /*
   * Port/socket numbers: network standard functions
   */
#define IPPORT_ECHO             7
#define IPPORT_DISCARD          9
#define IPPORT_SYSTAT           11
#define IPPORT_DAYTIME          13
#define IPPORT_NETSTAT          15
#define IPPORT_FTP              21
#define IPPORT_TELNET           23
#define IPPORT_SMTP             25
#define IPPORT_TIMESERVER       37
#define IPPORT_NAMESERVER       42
#define IPPORT_WHOIS            43
#define IPPORT_MTP              57

   /*
	* Port/socket numbers: host specific functions
	*/
#define IPPORT_TFTP             69
#define IPPORT_RJE              77
#define IPPORT_FINGER           79
#define IPPORT_TTYLINK          87
#define IPPORT_SUPDUP           95

	/*
	 * UNIX TCP sockets
	 */
#define IPPORT_EXECSERVER       512
#define IPPORT_LOGINSERVER      513
#define IPPORT_CMDSERVER        514
#define IPPORT_EFSSERVER        520

	 /*
	  * UNIX UDP sockets
	  */
#define IPPORT_BIFFUDP          512
#define IPPORT_WHOSERVER        513
#define IPPORT_ROUTESERVER      520
	  /* 520+1 also used */

/*
 * Ports < IPPORT_RESERVED are reserved for
 * privileged processes (e.g. root).
 */
#define IPPORT_RESERVED         1024

 /*
  * Link numbers
  */
#define IMPLINK_IP              155
#define IMPLINK_LOWEXPER        156
#define IMPLINK_HIGHEXPER       158

  /*
   * Definitions of bits in internet address integers.
   * On subnets, the decomposition of addresses to host and net parts
   * is done according to subnet mask, not the masks here.
   */
#define IN_CLASSA(i)            (((long)(i) & 0x80000000) == 0)
#define IN_CLASSA_NET           0xff000000
#define IN_CLASSA_NSHIFT        24
#define IN_CLASSA_HOST          0x00ffffff
#define IN_CLASSA_MAX           128

#define IN_CLASSB(i)            (((long)(i) & 0xc0000000) == 0x80000000)
#define IN_CLASSB_NET           0xffff0000
#define IN_CLASSB_NSHIFT        16
#define IN_CLASSB_HOST          0x0000ffff
#define IN_CLASSB_MAX           65536

#define IN_CLASSC(i)            (((long)(i) & 0xe0000000) == 0xc0000000)
#define IN_CLASSC_NET           0xffffff00
#define IN_CLASSC_NSHIFT        8
#define IN_CLASSC_HOST          0x000000ff

#define INADDR_ANY              (unsigned long)0x00000000
#define INADDR_LOOPBACK         0x7f000001
#define INADDR_BROADCAST        (unsigned long)0xffffffff
#define INADDR_NONE             0xffffffff

//
// Socket types.
//

#define SOCK_STREAM     1
#define SOCK_DGRAM      2
#define SOCK_RAW        3
#define SOCK_RDM        4
#define SOCK_SEQPACKET  5

//
// Define a level for socket I/O controls in the same numbering space as
// IPPROTO_TCP, IPPROTO_IP, etc.
//

#define SOL_SOCKET 0xffff
#define SOL_IP     (SOL_SOCKET-4)
#define SOL_IPV6   (SOL_SOCKET-5)

//
// Define socket-level options.
//

#define SO_DEBUG        0x0001      // turn on debugging info recording
#define SO_ACCEPTCONN   0x0002      // socket has had listen()
#define SO_REUSEADDR    0x0004      // allow local address reuse
#define SO_KEEPALIVE    0x0008      // keep connections alive
#define SO_DONTROUTE    0x0010      // just use interface addresses
#define SO_BROADCAST    0x0020      // permit sending of broadcast msgs
#define SO_USELOOPBACK  0x0040      // bypass hardware when possible
#define SO_LINGER       0x0080      // linger on close if data present
#define SO_OOBINLINE    0x0100      // leave received OOB data in line

#define SO_DONTLINGER   (int)(~SO_LINGER)
#define SO_EXCLUSIVEADDRUSE \
    ((int)(~SO_REUSEADDR))          // disallow local address reuse

#define SO_SNDBUF       0x1001      // send buffer size
#define SO_RCVBUF       0x1002      // receive buffer size
#define SO_SNDLOWAT     0x1003      // send low-water mark
#define SO_RCVLOWAT     0x1004      // receive low-water mark
#define SO_SNDTIMEO     0x1005      // send timeout
#define SO_RCVTIMEO     0x1006      // receive timeout
#define SO_ERROR        0x1007      // get error status and clear
#define SO_TYPE         0x1008      // get socket type
#define SO_BSP_STATE    0x1009      // get socket 5-tuple state

#define SO_GROUP_ID     0x2001      // ID of a socket group
#define SO_GROUP_PRIORITY 0x2002    // the relative priority within a group
#define SO_MAX_MSG_SIZE 0x2003      // maximum message size

#define SO_CONDITIONAL_ACCEPT 0x3002 // enable true conditional accept:
									// connection is not ack-ed to the
									// other side until conditional
									// function returns CF_ACCEPT
#define SO_PAUSE_ACCEPT 0x3003      // pause accepting new connections
#define SO_COMPARTMENT_ID 0x3004    // get/set the compartment for a socket

#define SO_RANDOMIZE_PORT 0x3005    // randomize assignment of wildcard ports
#define SO_PORT_SCALABILITY 0x3006  // enable port scalability
#define SO_REUSE_UNICASTPORT 0x3007 // defer ephemeral port allocation for
									// outbound connections
#define SO_REUSE_MULTICASTPORT 0x3008 // enable port reuse and disable unicast
									  //reception.
#define SO_ORIGINAL_DST 0x300F      // Query the original destination address
									// of a redirected connection.
#define IP6T_SO_ORIGINAL_DST SO_ORIGINAL_DST

#define SO_RECEIVED_HOPLIMIT 0x3010
#define SO_RECEIVED_PROCESSOR 0x3011 // Receive the processor number packets - have been processed by

//
// Base constant used for defining WSK-specific options.
//

#define WSK_SO_BASE  0x4000

//
// Options to use with [gs]etsockopt at the IPPROTO_TCP level.
//

#define TCP_NODELAY         0x0001

//
// Possible flags for the  iiFlags - bitmask.
//

#define IFF_UP              0x00000001 // Interface is up.
#define IFF_BROADCAST       0x00000002 // Broadcast is  supported.
#define IFF_LOOPBACK        0x00000004 // This is loopback interface.
#define IFF_POINTTOPOINT    0x00000008 // This is point-to-point interface.
#define IFF_MULTICAST       0x00000010 // Multicast is supported.

//
// Options to use with [gs]etsockopt at the IPPROTO_IP level.
// The values should be consistent with the IPv6 equivalents.
//
#define IP_OPTIONS                 1 // Set/get IP options.
#define IP_HDRINCL                 2 // Header is included with data.
#define IP_TOS                     3 // IP type of service.
#define IP_TTL                     4 // IP TTL (hop limit).
#define IP_MULTICAST_IF            9 // IP multicast interface.
#define IP_MULTICAST_TTL          10 // IP multicast TTL (hop limit).
#define IP_MULTICAST_LOOP         11 // IP multicast loopback.
#define IP_ADD_MEMBERSHIP         12 // Add an IP group membership.
#define IP_DROP_MEMBERSHIP        13 // Drop an IP group membership.
#define IP_DONTFRAGMENT           14 // Don't fragment IP datagrams.
#define IP_ADD_SOURCE_MEMBERSHIP  15 // Join IP group/source.
#define IP_DROP_SOURCE_MEMBERSHIP 16 // Leave IP group/source.
#define IP_BLOCK_SOURCE           17 // Block IP group/source.
#define IP_UNBLOCK_SOURCE         18 // Unblock IP group/source.
#define IP_PKTINFO                19 // Receive packet information.
#define IP_HOPLIMIT               21 // Receive packet hop limit.
#define IP_RECVTTL                21 // Receive packet Time To Live (TTL).
#define IP_RECEIVE_BROADCAST      22 // Allow/block broadcast reception.
#define IP_RECVIF                 24 // Receive arrival interface.
#define IP_RECVDSTADDR            25 // Receive destination address.
#define IP_IFLIST                 28 // Enable/Disable an interface list.
#define IP_ADD_IFLIST             29 // Add an interface list entry.
#define IP_DEL_IFLIST             30 // Delete an interface list entry.
#define IP_UNICAST_IF             31 // IP unicast interface.
#define IP_RTHDR                  32 // Set/get IPv6 routing header.
#define IP_GET_IFLIST             33 // Get an interface list.
#define IP_RECVRTHDR              38 // Receive the routing header.
#define IP_TCLASS                 39 // Packet traffic class.
#define IP_RECVTCLASS             40 // Receive packet traffic class.
#define IP_RECVTOS                40 // Receive packet Type Of Service (TOS).
#define IP_ORIGINAL_ARRIVAL_IF    47 // Original Arrival Interface Index.
#define IP_ECN                    50 // IP ECN codepoint.
#define IP_RECVECN                50 // Receive ECN codepoints in the IP header.
#define IP_PKTINFO_EX             51 // Receive extended packet information.
#define IP_WFP_REDIRECT_RECORDS   60 // WFP's Connection Redirect Records.
#define IP_WFP_REDIRECT_CONTEXT   70 // WFP's Connection Redirect Context.
#define IP_MTU_DISCOVER           71 // Set/get path MTU discover state.
#define IP_MTU                    73 // Get path MTU.
#define IP_NRT_INTERFACE          74 // Set NRT interface constraint (outbound).
#define IP_RECVERR                75 // Receive ICMP errors.
#define IP_USER_MTU               76 // Set/get app defined upper bound IP layer MTU.

#define IP_UNSPECIFIED_TYPE_OF_SERVICE -1

/* Option to use with [gs]etsockopt at the IPPROTO_UDP level */

#define UDP_NOCHECKSUM  1
#define UDP_CHECKSUM_COVERAGE   20  /* Set/get UDP-Lite checksum coverage */

//
// Options to use with [gs]etsockopt at the IPPROTO_IPV6 level.
// These are specified in RFCs 3493 and 3542.
// The values should be consistent with the IPv6 equivalents.
//
#define IPV6_HOPOPTS           1 // Set/get IPv6 hop-by-hop options.
#define IPV6_HDRINCL           2 // Header is included with data.
#define IPV6_UNICAST_HOPS      4 // IP unicast hop limit.
#define IPV6_MULTICAST_IF      9 // IP multicast interface.
#define IPV6_MULTICAST_HOPS   10 // IP multicast hop limit.
#define IPV6_MULTICAST_LOOP   11 // IP multicast loopback.
#define IPV6_ADD_MEMBERSHIP   12 // Add an IP group membership.
#define IPV6_JOIN_GROUP       IPV6_ADD_MEMBERSHIP
#define IPV6_DROP_MEMBERSHIP  13 // Drop an IP group membership.
#define IPV6_LEAVE_GROUP      IPV6_DROP_MEMBERSHIP
#define IPV6_DONTFRAG         14 // Don't fragment IP datagrams.
#define IPV6_PKTINFO          19 // Receive packet information.
#define IPV6_HOPLIMIT         21 // Receive packet hop limit.
#define IPV6_PROTECTION_LEVEL 23 // Set/get IPv6 protection level.
#define IPV6_RECVIF           24 // Receive arrival interface.
#define IPV6_RECVDSTADDR      25 // Receive destination address.
#define IPV6_CHECKSUM         26 // Offset to checksum for raw IP socket send.
#define IPV6_V6ONLY           27 // Treat wildcard bind as AF_INET6-only.
#define IPV6_IFLIST           28 // Enable/Disable an interface list.
#define IPV6_ADD_IFLIST       29 // Add an interface list entry.
#define IPV6_DEL_IFLIST       30 // Delete an interface list entry.
#define IPV6_UNICAST_IF       31 // IP unicast interface.
#define IPV6_RTHDR            32 // Set/get IPv6 routing header.
#define IPV6_GET_IFLIST       33 // Get an interface list.
#define IPV6_RECVRTHDR        38 // Receive the routing header.
#define IPV6_TCLASS           39 // Packet traffic class.
#define IPV6_RECVTCLASS       40 // Receive packet traffic class.
#define IPV6_ECN              50 // IPv6 ECN codepoint.
#define IPV6_RECVECN          50 // Receive ECN codepoints in the IPv6 header.
#define IPV6_PKTINFO_EX       51 // Receive extended packet information.
#define IPV6_WFP_REDIRECT_RECORDS   60 // WFP's Connection Redirect Records
#define IPV6_WFP_REDIRECT_CONTEXT   70 // WFP's Connection Redirect Context
#define IPV6_MTU_DISCOVER           71 // Set/get path MTU discover state.
#define IPV6_MTU                    72 // Get path MTU.
#define IPV6_NRT_INTERFACE          74 // Set NRT interface constraint (outbound).
#define IPV6_RECVERR                75 // Receive ICMPv6 errors.
#define IPV6_USER_MTU               76 // Set/get app defined upper bound IP layer MTU.

#define IP_UNSPECIFIED_HOP_LIMIT -1

#define IP_PROTECTION_LEVEL   IPV6_PROTECTION_LEVEL

//
// Values of IPV6_PROTECTION_LEVEL.
//
#define PROTECTION_LEVEL_UNRESTRICTED   10 // For peer-to-peer apps.
#define PROTECTION_LEVEL_EDGERESTRICTED 20 // Same as unrestricted. Except for
										   // Teredo.
#define PROTECTION_LEVEL_RESTRICTED     30 // For Intranet apps.

/* Flag bit definitions for dwProviderFlags */
#define PFL_MULTIPLE_PROTO_ENTRIES          0x00000001
#define PFL_RECOMMENDED_PROTO_ENTRY         0x00000002
#define PFL_HIDDEN                          0x00000004
#define PFL_MATCHES_PROTOCOL_ZERO           0x00000008
#define PFL_NETWORKDIRECT_PROVIDER          0x00000010

/* Flag bit definitions for dwServiceFlags1 */
#define XP1_CONNECTIONLESS                  0x00000001
#define XP1_GUARANTEED_DELIVERY             0x00000002
#define XP1_GUARANTEED_ORDER                0x00000004
#define XP1_MESSAGE_ORIENTED                0x00000008
#define XP1_PSEUDO_STREAM                   0x00000010
#define XP1_GRACEFUL_CLOSE                  0x00000020
#define XP1_EXPEDITED_DATA                  0x00000040
#define XP1_CONNECT_DATA                    0x00000080
#define XP1_DISCONNECT_DATA                 0x00000100
#define XP1_SUPPORT_BROADCAST               0x00000200
#define XP1_SUPPORT_MULTIPOINT              0x00000400
#define XP1_MULTIPOINT_CONTROL_PLANE        0x00000800
#define XP1_MULTIPOINT_DATA_PLANE           0x00001000
#define XP1_QOS_SUPPORTED                   0x00002000
#define XP1_INTERRUPT                       0x00004000
#define XP1_UNI_SEND                        0x00008000
#define XP1_UNI_RECV                        0x00010000
#define XP1_IFS_HANDLES                     0x00020000
#define XP1_PARTIAL_MESSAGE                 0x00040000
#define XP1_SAN_SUPPORT_SDP                 0x00080000

#define BIGENDIAN                           0x0000
#define LITTLEENDIAN                        0x0001

#define SECURITY_PROTOCOL_NONE              0x0000

/*
 * WinSock 2 extension -- manifest constants for WSAIoctl()
 */
#define IOC_UNIX                      0x00000000
#define IOC_WS2                       0x08000000
#define IOC_PROTOCOL                  0x10000000
#define IOC_VENDOR                    0x18000000

/*
 * Commands for ioctlsocket(),  taken from the BSD file fcntl.h.
 *
 *
 * Ioctl's have the command encoded in the lower word,
 * and the size of any in or out parameters in the upper
 * word.  The high 2 bits of the upper word are used
 * to encode the in/out status of the parameter; for now
 * we restrict parameters to at most 128 bytes.
 */
#define IOCPARM_MASK    0x7f            /* parameters must be < 128 bytes */
#define IOC_VOID        0x20000000      /* no parameters */
#define IOC_OUT         0x40000000      /* copy out parameters */
#define IOC_IN          0x80000000      /* copy in parameters */
#define IOC_INOUT       (IOC_IN|IOC_OUT)
 /* 0x20000000 distinguishes new &
	old ioctl's */

#define _WSAIO(x,y)                   (IOC_VOID|(x)|(y))
#define _WSAIOR(x,y)                  (IOC_OUT|(x)|(y))
#define _WSAIOW(x,y)                  (IOC_IN|(x)|(y))
#define _WSAIORW(x,y)                 (IOC_INOUT|(x)|(y))

#define SIO_ASSOCIATE_HANDLE          _WSAIOW(IOC_WS2,1)
#define SIO_ENABLE_CIRCULAR_QUEUEING  _WSAIO(IOC_WS2,2)
#define SIO_FIND_ROUTE                _WSAIOR(IOC_WS2,3)
#define SIO_FLUSH                     _WSAIO(IOC_WS2,4)
#define SIO_GET_BROADCAST_ADDRESS     _WSAIOR(IOC_WS2,5)
#define SIO_GET_EXTENSION_FUNCTION_POINTER  _WSAIORW(IOC_WS2,6)
#define SIO_GET_QOS                   _WSAIORW(IOC_WS2,7)
#define SIO_GET_GROUP_QOS             _WSAIORW(IOC_WS2,8)
#define SIO_MULTIPOINT_LOOPBACK       _WSAIOW(IOC_WS2,9)
#define SIO_MULTICAST_SCOPE           _WSAIOW(IOC_WS2,10)
#define SIO_SET_QOS                   _WSAIOW(IOC_WS2,11)
#define SIO_SET_GROUP_QOS             _WSAIOW(IOC_WS2,12)
#define SIO_TRANSLATE_HANDLE          _WSAIORW(IOC_WS2,13)
#define SIO_ROUTING_INTERFACE_QUERY   _WSAIORW(IOC_WS2,20)
#define SIO_ROUTING_INTERFACE_CHANGE  _WSAIOW(IOC_WS2,21)
#define SIO_ADDRESS_LIST_QUERY        _WSAIOR(IOC_WS2,22)
#define SIO_ADDRESS_LIST_CHANGE       _WSAIO(IOC_WS2,23)
#define SIO_QUERY_TARGET_PNP_HANDLE   _WSAIOR(IOC_WS2,24)
#define SIO_QUERY_RSS_PROCESSOR_INFO  _WSAIOR(IOC_WS2,37)

//
// WSAIoctl Options
//
#define SIO_RCVALL                          _WSAIOW(IOC_VENDOR,1)
#define SIO_RCVALL_MCAST                    _WSAIOW(IOC_VENDOR,2)
#define SIO_RCVALL_IGMPMCAST                _WSAIOW(IOC_VENDOR,3)
#define SIO_KEEPALIVE_VALS                  _WSAIOW(IOC_VENDOR,4)
#define SIO_ABSORB_RTRALERT                 _WSAIOW(IOC_VENDOR,5)
#define SIO_UCAST_IF                        _WSAIOW(IOC_VENDOR,6)
#define SIO_LIMIT_BROADCASTS                _WSAIOW(IOC_VENDOR,7)
#define SIO_INDEX_BIND                      _WSAIOW(IOC_VENDOR,8)
#define SIO_INDEX_MCASTIF                   _WSAIOW(IOC_VENDOR,9)
#define SIO_INDEX_ADD_MCAST                 _WSAIOW(IOC_VENDOR,10)
#define SIO_INDEX_DEL_MCAST                 _WSAIOW(IOC_VENDOR,11)
#define SIO_RCVALL_MCAST_IF                 _WSAIOW(IOC_VENDOR,13)
#define SIO_RCVALL_IF                       _WSAIOW(IOC_VENDOR,14)
#define SIO_LOOPBACK_FAST_PATH              _WSAIOW(IOC_VENDOR,16)
#define SIO_TCP_INITIAL_RTO                 _WSAIOW(IOC_VENDOR,17)
#define SIO_APPLY_TRANSPORT_SETTING         _WSAIOW(IOC_VENDOR,19)
#define SIO_QUERY_TRANSPORT_SETTING         _WSAIOW(IOC_VENDOR,20)
#define SIO_TCP_SET_ICW                     _WSAIOW(IOC_VENDOR,22)
#define SIO_TCP_SET_ACK_FREQUENCY           _WSAIOW(IOC_VENDOR,23)

#define SIO_SET_PRIORITY_HINT               _WSAIOW(IOC_VENDOR,24)
#define SIO_PRIORITY_HINT SIO_SET_PRIORITY_HINT
#define SIO_TCP_INFO                        _WSAIORW(IOC_VENDOR,39)
#define SIO_CPU_AFFINITY                    _WSAIOW(IOC_VENDOR,21)

#define SIO_UDP_CONNRESET  _WSAIOW(IOC_VENDOR, 12)   /* 0x9800000C */
#define SIO_UDP_NETRESET   _WSAIOW(IOC_VENDOR, 15)   /* 0x9800000F */

//
// Flags for the TIMESTAMPING_CONFIG struct. Specify a flag to enable, or omit
// to disable timestamp reception for that direction.
//
#define TIMESTAMPING_FLAG_RX 0x1
#define TIMESTAMPING_FLAG_TX 0x2

//
// Control message type for returning a rx timestamp through WSARecvMsg.
// The control message data is returned as a UINT64.
//
#define SO_TIMESTAMP 0x300A

//
// Control message type for specifying a tx timestamp ID through WSASendMsg.
// The control message data is supplied as a UINT32.
//
#define SO_TIMESTAMP_ID 0x300B

//
// Socket IOCTL to get timestamps for transmitted packets. Enable timestamp
// reception first by using the SIO_TIMESTAMPING socket IOCTL, then retrieve tx
// timestamps by ID using this IOCTL. Only valid for datagram sockets.
//
// Input is a UINT32 timestamp ID.
// Output is a UINT64 timestamp value.
// On success, the tx timestamp is available and is returned.
// On failure, the tx timestamp is unavailable. WSAGetLastError will return
//    WSAEWOULDBLOCK.
//
#define SIO_GET_TX_TIMESTAMP _WSAIOW(IOC_VENDOR, 234)

/*
 * WinSock 2 extension -- manifest constants for WSAJoinLeaf()
 */
#define JL_SENDER_ONLY    0x01
#define JL_RECEIVER_ONLY  0x02
#define JL_BOTH           0x04

 /*
  * WinSock 2 extension -- manifest constants for WSASocket()
  */
#define WSA_FLAG_OVERLAPPED           0x01
#define WSA_FLAG_MULTIPOINT_C_ROOT    0x02
#define WSA_FLAG_MULTIPOINT_C_LEAF    0x04
#define WSA_FLAG_MULTIPOINT_D_ROOT    0x08
#define WSA_FLAG_MULTIPOINT_D_LEAF    0x10
#define WSA_FLAG_ACCESS_SYSTEM_SECURITY 0x40
#define WSA_FLAG_NO_HANDLE_INHERIT    0x80
#define WSA_FLAG_REGISTERED_IO       0x100

  /*
   * Commands for ioctlsocket(),  taken from the BSD file fcntl.h.
   *
   *
   * Ioctl's have the command encoded in the lower word,
   * and the size of any in or out parameters in the upper
   * word.  The high 2 bits of the upper word are used
   * to encode the in/out status of the parameter; for now
   * we restrict parameters to at most 128 bytes.
   */
#define IOCPARM_MASK    0x7f            /* parameters must be < 128 bytes */
#define IOC_VOID        0x20000000      /* no parameters */
#define IOC_OUT         0x40000000      /* copy out parameters */
#define IOC_IN          0x80000000      /* copy in parameters */
#define IOC_INOUT       (IOC_IN|IOC_OUT)
   /* 0x20000000 distinguishes new &
	  old ioctl's */
#define _IO(x,y)        (IOC_VOID|((x)<<8)|(y))

#define _IOR(x,y,t)     (IOC_OUT|(((long)sizeof(t)&IOCPARM_MASK)<<16)|((x)<<8)|(y))

#define _IOW(x,y,t)     (IOC_IN|(((long)sizeof(t)&IOCPARM_MASK)<<16)|((x)<<8)|(y))

#define FIONREAD    _IOR('f', 127, u_long) /* get # bytes to read */
#define FIONBIO     _IOW('f', 126, u_long) /* set/clear non-blocking i/o */
#define FIOASYNC    _IOW('f', 125, u_long) /* set/clear async i/o */

	  /* Socket I/O Controls */
#define SIOCSHIWAT  _IOW('s',  0, u_long)  /* set high watermark */
#define SIOCGHIWAT  _IOR('s',  1, u_long)  /* get high watermark */
#define SIOCSLOWAT  _IOW('s',  2, u_long)  /* set low watermark */
#define SIOCGLOWAT  _IOR('s',  3, u_long)  /* get low watermark */
#define SIOCATMARK  _IOR('s',  7, u_long)  /* at oob mark? */

//
// Options to use with [gs]etsockopt at the IPPROTO_TCP level.
// TCP_NODELAY is defined in ws2def.h for historical reasons.
//

//
// Offload preferences supported.
//
#define TCP_OFFLOAD_NO_PREFERENCE	0
#define	TCP_OFFLOAD_NOT_PREFERRED	1
#define TCP_OFFLOAD_PREFERRED		2

//      TCP_NODELAY         	 0x0001
#define TCP_EXPEDITED_1122  	 0x0002
#define TCP_KEEPALIVE       	 3
#define TCP_MAXSEG          	 4
#define TCP_MAXRT           	 5
#define TCP_STDURG          	 6
#define TCP_NOURG           	 7
#define TCP_ATMARK          	 8
#define TCP_NOSYNRETRIES    	 9
#define TCP_TIMESTAMPS      	 10
#define TCP_OFFLOAD_PREFERENCE	 11
#define TCP_CONGESTION_ALGORITHM 12
#define TCP_DELAY_FIN_ACK        13
#define TCP_MAXRTMS              14
#define TCP_FASTOPEN             15
#define TCP_KEEPCNT              16
#define TCP_KEEPIDLE             TCP_KEEPALIVE
#define TCP_KEEPINTVL            17
#define TCP_FAIL_CONNECT_ON_ICMP_ERROR 18
#define TCP_ICMP_ERROR_INFO      19

///////////////////////////////////////////////////
//                                               //
//               WinSock Error Codes             //
//                                               //
//                 10000 to 11999                //
///////////////////////////////////////////////////

//
// WinSock error codes are also defined in WinSock.h
// and WinSock2.h, hence the IFDEF

// MessageId: WSAEINTR
//
// MessageText:
//
// A blocking operation was interrupted by a call to WSACancelBlockingCall.
//
#define WSAEINTR                         10004L

//
// MessageId: WSAEBADF
//
// MessageText:
//
// The file handle supplied is not valid.
//
#define WSAEBADF                         10009L

//
// MessageId: WSAEACCES
//
// MessageText:
//
// An attempt was made to access a socket in a way forbidden by its access permissions.
//
#define WSAEACCES                        10013L

//
// MessageId: WSAEFAULT
//
// MessageText:
//
// The system detected an invalid pointer address in attempting to use a pointer argument in a call.
//
#define WSAEFAULT                        10014L

//
// MessageId: WSAEINVAL
//
// MessageText:
//
// An invalid argument was supplied.
//
#define WSAEINVAL                        10022L

//
// MessageId: WSAEMFILE
//
// MessageText:
//
// Too many open sockets.
//
#define WSAEMFILE                        10024L

//
// MessageId: WSAEWOULDBLOCK
//
// MessageText:
//
// A non-blocking socket operation could not be completed immediately.
//
#define WSAEWOULDBLOCK                   10035L

//
// MessageId: WSAEINPROGRESS
//
// MessageText:
//
// A blocking operation is currently executing.
//
#define WSAEINPROGRESS                   10036L

//
// MessageId: WSAEALREADY
//
// MessageText:
//
// An operation was attempted on a non-blocking socket that already had an operation in progress.
//
#define WSAEALREADY                      10037L

//
// MessageId: WSAENOTSOCK
//
// MessageText:
//
// An operation was attempted on something that is not a socket.
//
#define WSAENOTSOCK                      10038L

//
// MessageId: WSAEDESTADDRREQ
//
// MessageText:
//
// A required address was omitted from an operation on a socket.
//
#define WSAEDESTADDRREQ                  10039L

//
// MessageId: WSAEMSGSIZE
//
// MessageText:
//
// A message sent on a datagram socket was larger than the internal message buffer or some other network limit, or the buffer used to receive a datagram into was smaller than the datagram itself.
//
#define WSAEMSGSIZE                      10040L

//
// MessageId: WSAEPROTOTYPE
//
// MessageText:
//
// A protocol was specified in the socket function call that does not support the semantics of the socket type requested.
//
#define WSAEPROTOTYPE                    10041L

//
// MessageId: WSAENOPROTOOPT
//
// MessageText:
//
// An unknown, invalid, or unsupported option or level was specified in a getsockopt or setsockopt call.
//
#define WSAENOPROTOOPT                   10042L

//
// MessageId: WSAEPROTONOSUPPORT
//
// MessageText:
//
// The requested protocol has not been configured into the system, or no implementation for it exists.
//
#define WSAEPROTONOSUPPORT               10043L

//
// MessageId: WSAESOCKTNOSUPPORT
//
// MessageText:
//
// The support for the specified socket type does not exist in this address family.
//
#define WSAESOCKTNOSUPPORT               10044L

//
// MessageId: WSAEOPNOTSUPP
//
// MessageText:
//
// The attempted operation is not supported for the type of object referenced.
//
#define WSAEOPNOTSUPP                    10045L

//
// MessageId: WSAEPFNOSUPPORT
//
// MessageText:
//
// The protocol family has not been configured into the system or no implementation for it exists.
//
#define WSAEPFNOSUPPORT                  10046L

//
// MessageId: WSAEAFNOSUPPORT
//
// MessageText:
//
// An address incompatible with the requested protocol was used.
//
#define WSAEAFNOSUPPORT                  10047L

//
// MessageId: WSAEADDRINUSE
//
// MessageText:
//
// Only one usage of each socket address (protocol/network address/port) is normally permitted.
//
#define WSAEADDRINUSE                    10048L

//
// MessageId: WSAEADDRNOTAVAIL
//
// MessageText:
//
// The requested address is not valid in its context.
//
#define WSAEADDRNOTAVAIL                 10049L

//
// MessageId: WSAENETDOWN
//
// MessageText:
//
// A socket operation encountered a dead network.
//
#define WSAENETDOWN                      10050L

//
// MessageId: WSAENETUNREACH
//
// MessageText:
//
// A socket operation was attempted to an unreachable network.
//
#define WSAENETUNREACH                   10051L

//
// MessageId: WSAENETRESET
//
// MessageText:
//
// The connection has been broken due to keep-alive activity detecting a failure while the operation was in progress.
//
#define WSAENETRESET                     10052L

//
// MessageId: WSAECONNABORTED
//
// MessageText:
//
// An established connection was aborted by the software in your host machine.
//
#define WSAECONNABORTED                  10053L

//
// MessageId: WSAECONNRESET
//
// MessageText:
//
// An existing connection was forcibly closed by the remote host.
//
#define WSAECONNRESET                    10054L

//
// MessageId: WSAENOBUFS
//
// MessageText:
//
// An operation on a socket could not be performed because the system lacked sufficient buffer space or because a queue was full.
//
#define WSAENOBUFS                       10055L

//
// MessageId: WSAEISCONN
//
// MessageText:
//
// A connect request was made on an already connected socket.
//
#define WSAEISCONN                       10056L

//
// MessageId: WSAENOTCONN
//
// MessageText:
//
// A request to send or receive data was disallowed because the socket is not connected and (when sending on a datagram socket using a sendto call) no address was supplied.
//
#define WSAENOTCONN                      10057L

//
// MessageId: WSAESHUTDOWN
//
// MessageText:
//
// A request to send or receive data was disallowed because the socket had already been shut down in that direction with a previous shutdown call.
//
#define WSAESHUTDOWN                     10058L

//
// MessageId: WSAETOOMANYREFS
//
// MessageText:
//
// Too many references to some kernel object.
//
#define WSAETOOMANYREFS                  10059L

//
// MessageId: WSAETIMEDOUT
//
// MessageText:
//
// A connection attempt failed because the connected party did not properly respond after a period of time, or established connection failed because connected host has failed to respond.
//
#define WSAETIMEDOUT                     10060L

//
// MessageId: WSAECONNREFUSED
//
// MessageText:
//
// No connection could be made because the target machine actively refused it.
//
#define WSAECONNREFUSED                  10061L

//
// MessageId: WSAELOOP
//
// MessageText:
//
// Cannot translate name.
//
#define WSAELOOP                         10062L

//
// MessageId: WSAENAMETOOLONG
//
// MessageText:
//
// Name component or name was too long.
//
#define WSAENAMETOOLONG                  10063L

//
// MessageId: WSAEHOSTDOWN
//
// MessageText:
//
// A socket operation failed because the destination host was down.
//
#define WSAEHOSTDOWN                     10064L

//
// MessageId: WSAEHOSTUNREACH
//
// MessageText:
//
// A socket operation was attempted to an unreachable host.
//
#define WSAEHOSTUNREACH                  10065L

//
// MessageId: WSAENOTEMPTY
//
// MessageText:
//
// Cannot remove a directory that is not empty.
//
#define WSAENOTEMPTY                     10066L

//
// MessageId: WSAEPROCLIM
//
// MessageText:
//
// A Windows Sockets implementation may have a limit on the number of applications that may use it simultaneously.
//
#define WSAEPROCLIM                      10067L

//
// MessageId: WSAEUSERS
//
// MessageText:
//
// Ran out of quota.
//
#define WSAEUSERS                        10068L

//
// MessageId: WSAEDQUOT
//
// MessageText:
//
// Ran out of disk quota.
//
#define WSAEDQUOT                        10069L

//
// MessageId: WSAESTALE
//
// MessageText:
//
// File handle reference is no longer available.
//
#define WSAESTALE                        10070L

//
// MessageId: WSAEREMOTE
//
// MessageText:
//
// Item is not available locally.
//
#define WSAEREMOTE                       10071L

//
// MessageId: WSASYSNOTREADY
//
// MessageText:
//
// WSAStartup cannot function at this time because the underlying system it uses to provide network services is currently unavailable.
//
#define WSASYSNOTREADY                   10091L

//
// MessageId: WSAVERNOTSUPPORTED
//
// MessageText:
//
// The Windows Sockets version requested is not supported.
//
#define WSAVERNOTSUPPORTED               10092L

//
// MessageId: WSANOTINITIALISED
//
// MessageText:
//
// Either the application has not called WSAStartup, or WSAStartup failed.
//
#define WSANOTINITIALISED                10093L

//
// MessageId: WSAEDISCON
//
// MessageText:
//
// Returned by WSARecv or WSARecvFrom to indicate the remote party has initiated a graceful shutdown sequence.
//
#define WSAEDISCON                       10101L

//
// MessageId: WSAENOMORE
//
// MessageText:
//
// No more results can be returned by WSALookupServiceNext.
//
#define WSAENOMORE                       10102L

//
// MessageId: WSAECANCELLED
//
// MessageText:
//
// A call to WSALookupServiceEnd was made while this call was still processing. The call has been canceled.
//
#define WSAECANCELLED                    10103L

//
// MessageId: WSAEINVALIDPROCTABLE
//
// MessageText:
//
// The procedure call table is invalid.
//
#define WSAEINVALIDPROCTABLE             10104L

//
// MessageId: WSAEINVALIDPROVIDER
//
// MessageText:
//
// The requested service provider is invalid.
//
#define WSAEINVALIDPROVIDER              10105L

//
// MessageId: WSAEPROVIDERFAILEDINIT
//
// MessageText:
//
// The requested service provider could not be loaded or initialized.
//
#define WSAEPROVIDERFAILEDINIT           10106L

//
// MessageId: WSASYSCALLFAILURE
//
// MessageText:
//
// A system call has failed.
//
#define WSASYSCALLFAILURE                10107L

//
// MessageId: WSASERVICE_NOT_FOUND
//
// MessageText:
//
// No such service is known. The service cannot be found in the specified name space.
//
#define WSASERVICE_NOT_FOUND             10108L

//
// MessageId: WSATYPE_NOT_FOUND
//
// MessageText:
//
// The specified class was not found.
//
#define WSATYPE_NOT_FOUND                10109L

//
// MessageId: WSA_E_NO_MORE
//
// MessageText:
//
// No more results can be returned by WSALookupServiceNext.
//
#define WSA_E_NO_MORE                    10110L

//
// MessageId: WSA_E_CANCELLED
//
// MessageText:
//
// A call to WSALookupServiceEnd was made while this call was still processing. The call has been canceled.
//
#define WSA_E_CANCELLED                  10111L

//
// MessageId: WSAEREFUSED
//
// MessageText:
//
// A database query failed because it was actively refused.
//
#define WSAEREFUSED                      10112L

//
// MessageId: WSAHOST_NOT_FOUND
//
// MessageText:
//
// No such host is known.
//
#define WSAHOST_NOT_FOUND                11001L

//
// MessageId: WSATRY_AGAIN
//
// MessageText:
//
// This is usually a temporary error during hostname resolution and means that the local server did not receive a response from an authoritative server.
//
#define WSATRY_AGAIN                     11002L

//
// MessageId: WSANO_RECOVERY
//
// MessageText:
//
// A non-recoverable error occurred during a database lookup.
//
#define WSANO_RECOVERY                   11003L

//
// MessageId: WSANO_DATA
//
// MessageText:
//
// The requested name is valid, but no data of the requested type was found.
//
#define WSANO_DATA                       11004L

//
// MessageId: WSA_QOS_RECEIVERS
//
// MessageText:
//
// At least one reserve has arrived.
//
#define WSA_QOS_RECEIVERS                11005L

//
// MessageId: WSA_QOS_SENDERS
//
// MessageText:
//
// At least one path has arrived.
//
#define WSA_QOS_SENDERS                  11006L

//
// MessageId: WSA_QOS_NO_SENDERS
//
// MessageText:
//
// There are no senders.
//
#define WSA_QOS_NO_SENDERS               11007L

//
// MessageId: WSA_QOS_NO_RECEIVERS
//
// MessageText:
//
// There are no receivers.
//
#define WSA_QOS_NO_RECEIVERS             11008L

//
// MessageId: WSA_QOS_REQUEST_CONFIRMED
//
// MessageText:
//
// Reserve has been confirmed.
//
#define WSA_QOS_REQUEST_CONFIRMED        11009L

//
// MessageId: WSA_QOS_ADMISSION_FAILURE
//
// MessageText:
//
// Error due to lack of resources.
//
#define WSA_QOS_ADMISSION_FAILURE        11010L

//
// MessageId: WSA_QOS_POLICY_FAILURE
//
// MessageText:
//
// Rejected for administrative reasons - bad credentials.
//
#define WSA_QOS_POLICY_FAILURE           11011L

//
// MessageId: WSA_QOS_BAD_STYLE
//
// MessageText:
//
// Unknown or conflicting style.
//
#define WSA_QOS_BAD_STYLE                11012L

//
// MessageId: WSA_QOS_BAD_OBJECT
//
// MessageText:
//
// Problem with some part of the filterspec or providerspecific buffer in general.
//
#define WSA_QOS_BAD_OBJECT               11013L

//
// MessageId: WSA_QOS_TRAFFIC_CTRL_ERROR
//
// MessageText:
//
// Problem with some part of the flowspec.
//
#define WSA_QOS_TRAFFIC_CTRL_ERROR       11014L

//
// MessageId: WSA_QOS_GENERIC_ERROR
//
// MessageText:
//
// General QOS error.
//
#define WSA_QOS_GENERIC_ERROR            11015L

//
// MessageId: WSA_QOS_ESERVICETYPE
//
// MessageText:
//
// An invalid or unrecognized service type was found in the flowspec.
//
#define WSA_QOS_ESERVICETYPE             11016L

//
// MessageId: WSA_QOS_EFLOWSPEC
//
// MessageText:
//
// An invalid or inconsistent flowspec was found in the QOS structure.
//
#define WSA_QOS_EFLOWSPEC                11017L

//
// MessageId: WSA_QOS_EPROVSPECBUF
//
// MessageText:
//
// Invalid QOS provider-specific buffer.
//
#define WSA_QOS_EPROVSPECBUF             11018L

//
// MessageId: WSA_QOS_EFILTERSTYLE
//
// MessageText:
//
// An invalid QOS filter style was used.
//
#define WSA_QOS_EFILTERSTYLE             11019L

//
// MessageId: WSA_QOS_EFILTERTYPE
//
// MessageText:
//
// An invalid QOS filter type was used.
//
#define WSA_QOS_EFILTERTYPE              11020L

//
// MessageId: WSA_QOS_EFILTERCOUNT
//
// MessageText:
//
// An incorrect number of QOS FILTERSPECs were specified in the FLOWDESCRIPTOR.
//
#define WSA_QOS_EFILTERCOUNT             11021L

//
// MessageId: WSA_QOS_EOBJLENGTH
//
// MessageText:
//
// An object with an invalid ObjectLength field was specified in the QOS provider-specific buffer.
//
#define WSA_QOS_EOBJLENGTH               11022L

//
// MessageId: WSA_QOS_EFLOWCOUNT
//
// MessageText:
//
// An incorrect number of flow descriptors was specified in the QOS structure.
//
#define WSA_QOS_EFLOWCOUNT               11023L

//
// MessageId: WSA_QOS_EUNKOWNPSOBJ
//
// MessageText:
//
// An unrecognized object was found in the QOS provider-specific buffer.
//
#define WSA_QOS_EUNKOWNPSOBJ             11024L

//
// MessageId: WSA_QOS_EPOLICYOBJ
//
// MessageText:
//
// An invalid policy object was found in the QOS provider-specific buffer.
//
#define WSA_QOS_EPOLICYOBJ               11025L

//
// MessageId: WSA_QOS_EFLOWDESC
//
// MessageText:
//
// An invalid QOS flow descriptor was found in the flow descriptor list.
//
#define WSA_QOS_EFLOWDESC                11026L

//
// MessageId: WSA_QOS_EPSFLOWSPEC
//
// MessageText:
//
// An invalid or inconsistent flowspec was found in the QOS provider specific buffer.
//
#define WSA_QOS_EPSFLOWSPEC              11027L

//
// MessageId: WSA_QOS_EPSFILTERSPEC
//
// MessageText:
//
// An invalid FILTERSPEC was found in the QOS provider-specific buffer.
//
#define WSA_QOS_EPSFILTERSPEC            11028L

//
// MessageId: WSA_QOS_ESDMODEOBJ
//
// MessageText:
//
// An invalid shape discard mode object was found in the QOS provider specific buffer.
//
#define WSA_QOS_ESDMODEOBJ               11029L

//
// MessageId: WSA_QOS_ESHAPERATEOBJ
//
// MessageText:
//
// An invalid shaping rate object was found in the QOS provider-specific buffer.
//
#define WSA_QOS_ESHAPERATEOBJ            11030L

//
// MessageId: WSA_QOS_RESERVED_PETYPE
//
// MessageText:
//
// A reserved policy element was found in the QOS provider-specific buffer.
//
#define WSA_QOS_RESERVED_PETYPE          11031L

//
// MessageId: WSA_SECURE_HOST_NOT_FOUND
//
// MessageText:
//
// No such host is known securely.
//
#define WSA_SECURE_HOST_NOT_FOUND        11032L

//
// MessageId: WSA_IPSEC_NAME_POLICY_ERROR
//
// MessageText:
//
// Name based IPSEC policy could not be added.
//
#define WSA_IPSEC_NAME_POLICY_ERROR      11033L

///////////////////////////////////////////////////
//                                               //
//           End of WinSock Error Codes          //
//                                               //
//                 10000 to 11999                //
///////////////////////////////////////////////////

// ░░░ Enums ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

//
// Path MTU discovery states.
//

typedef enum PMTUD_STATE
{
	IP_PMTUDISC_NOT_SET,
	IP_PMTUDISC_DO,
	IP_PMTUDISC_DONT,
	IP_PMTUDISC_PROBE,
	IP_PMTUDISC_MAX
} PMTUD_STATE;

// ░░░ Structs ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

typedef Handle Socket;
typedef uint16_t ADDRESS_FAMILY;

typedef struct WSADATA
{
	uint16_t wVersion;
	uint16_t wHighVersion;
	uint16_t iMaxSockets;
	uint16_t iMaxUdpDg;
	uint8_t *lpVendorInfo;
	uint8_t szDescription[WSADESCRIPTION_LEN + 1];
	uint8_t szSystemStatus[WSASYS_STATUS_LEN + 1];
} WSADATA;

typedef struct WSABUF
{
	uint32_t len;	/* the length of the buffer */
	uint8_t *buf;	/* the pointer to the buffer */
} WSABUF;

//
// Structure used to store most addresses.
//
typedef struct SOCKADDR
{
	ADDRESS_FAMILY sa_family;           // Address family.
	uint8_t sa_data[14];                   // Up to 14 bytes of direct address.
} SOCKADDR;

//
// IPv4 Internet address
// This is an 'on-wire' format structure.
//
typedef union IN_ADDR
{
	struct
	{
		uint8_t s_b1, s_b2, s_b3, s_b4;
	} S_un_b;
	struct
	{
		uint16_t s_w1, s_w2;
	} S_un_w;
	uint32_t S_addr;
} IN_ADDR;

typedef struct SOCKADDR_IN
{
	ADDRESS_FAMILY sin_family;

	uint16_t sin_port;
	IN_ADDR sin_addr;
	uint8_t sin_zero[8];
} SOCKADDR_IN;

//
// IPv6 Internet address (RFC 2553)
// This is an 'on-wire' format structure.
//
typedef union IN6_ADDR
{
	uint8_t Byte[16];
	uint16_t Word[8];
} IN6_ADDR;

typedef struct SCOPE_ID
{
	union
	{
		struct
		{
			uint32_t Zone : 28;
			uint32_t Level : 4;
		} DUMMYSTRUCTNAME;
		uint32_t Value;
	} DUMMYUNIONNAME;
} SCOPE_ID;

typedef struct SOCKADDR_IN6
{
	ADDRESS_FAMILY sin6_family; // AF_INET6.
	uint16_t sin6_port;           // Transport level port number.
	uint32_t  sin6_flowinfo;       // IPv6 flow information.
	IN6_ADDR sin6_addr;         // IPv6 address.
	union
	{
		uint32_t sin6_scope_id;     // Set of interfaces for a scope.
		SCOPE_ID sin6_scope_struct;
	};
} SOCKADDR_IN6;

typedef struct OVERLAPPED
{
	uint64_t Internal;
	uint64_t InternalHigh;
	union
	{
		struct
		{
			uint32_t Offset;
			uint32_t OffsetHigh;
		} DUMMYSTRUCTNAME;
		void *Pointer;
	} DUMMYUNIONNAME;

	Handle hEvent;
} OVERLAPPED;

typedef struct WSAPROTOCOLCHAIN
{
	int32_t ChainLen;                                 /* the length of the chain,     */
	/* length = 0 means layered protocol, */
	/* length = 1 means base protocol, */
	/* length > 1 means protocol chain */
	uint32_t ChainEntries[MAX_PROTOCOL_CHAIN];       /* a list of dwCatalogEntryIds */
} WSAPROTOCOLCHAIN;

typedef struct WSAPROTOCOL_INFOW
{
	uint32_t dwServiceFlags1;
	uint32_t dwServiceFlags2;
	uint32_t dwServiceFlags3;
	uint32_t dwServiceFlags4;
	uint32_t dwProviderFlags;
	GUID ProviderId;
	uint32_t dwCatalogEntryId;
	WSAPROTOCOLCHAIN ProtocolChain;
	int iVersion;
	int iAddressFamily;
	int iMaxSockAddr;
	int iMinSockAddr;
	int iSocketType;
	int iProtocol;
	int iProtocolMaxOffset;
	int iNetworkByteOrder;
	int iSecurityScheme;
	uint32_t dwMessageSize;
	uint32_t dwProviderReserved;
	wchar_t  szProtocol[WSAPROTOCOL_LEN + 1];
} WSAPROTOCOL_INFOW;

typedef struct FLOWSPEC
{
	uint32_t TokenRate;              /* In Bytes/sec */
	uint32_t TokenBucketSize;        /* In Bytes */
	uint32_t PeakBandwidth;          /* In Bytes/sec */
	uint32_t Latency;                /* In microseconds */
	uint32_t DelayVariation;         /* In microseconds */
	uint32_t ServiceType;
	uint32_t MaxSduSize;             /* In Bytes */
	uint32_t MinimumPolicedSize;     /* In Bytes */
} FLOWSPEC;

typedef struct QOS
{
	FLOWSPEC      SendingFlowspec;       /* the flow spec for data sending */
	FLOWSPEC      ReceivingFlowspec;     /* the flow spec for data receiving */
	WSABUF        ProviderSpecific;      /* additional provider specific stuff */
} QOS;

typedef struct WSAPOLLFD
{
	Socket fd;
	uint16_t events;
	uint16_t revents;

} WSAPOLLFD;

//
// Argument structure for SIO_KEEPALIVE_VALS.
//
typedef struct TCP_KEEPALIVE_STRUCT
{
	uint32_t onoff;
	uint32_t keepalivetime;
	uint32_t keepaliveinterval;
} TCP_KEEPALIVE_STRUCT;

/*
 * Structure used for manipulating linger option.
 * https://learn.microsoft.com/en-us/windows/win32/api/winsock/ns-winsock-linger
 */
typedef struct LINGER
{
	uint16_t l_onoff;                /* option on/off */
	uint16_t l_linger;               /* linger time in seconds */
} LINGER;

// ░░░ Loader API ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

boolean_t InitializeWS2_32(boolean_t skipLoad);
extern Handle WS2_32DllBaseAddress;

boolean_t Loadbind();
boolean_t Loadlisten();
boolean_t LoadWSASend();
boolean_t LoadWSARecv();
boolean_t LoadWSAPoll();
boolean_t Loadshutdown();
boolean_t LoadWSAIoctl();
boolean_t LoadInetPtonW();
boolean_t LoadInetNtopW();
boolean_t LoadWSASendTo();
boolean_t LoadWSAAccept();
boolean_t LoadWSAConnect();
boolean_t Loadgetsockopt();
boolean_t Loadsetsockopt();
boolean_t LoadWSACleanup();
boolean_t LoadWSAStartup();
boolean_t LoadWSASocketW();
boolean_t Loadclosesocket();
boolean_t Loadgetsockname();
boolean_t Loadgetpeername();
boolean_t LoadWSARecvFrom();

// ░░░ Callbacks / Parameter Functions ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

// https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nc-winsock2-lpwsaoverlapped_completion_routine
typedef void (*WSAOverlappedCompletionRoutine_t)(uint32_t dwError, uint32_t cbTransferred, OVERLAPPED *lpOverlapped, uint32_t dwFlags);

// https://microsoft.github.io/windows-docs-rs/doc/windows/Win32/Networking/WinSock/type.LPCONDITIONPROC.html
typedef int32_t(*ConditionProc_t)(WSABUF *lpCallerId, WSABUF *lpCallerData, QOS *lpSQOS, QOS *lpGQOS, WSABUF *lpCalleeId, WSABUF *lpCalleeData, uint32_t *group, uint64_t dwCallbackData);

// ░░░ WS2_32 Function Typedefs ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

// https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-wsapoll
typedef int32_t(*WSAPoll_t)(WSAPOLLFD *fdArray, uint32_t fds, int32_t timeout);

// https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-wsastartup
typedef int32_t(*WSAStartup_t)(uint16_t wVersionRequired, WSADATA *lpWSAData);

// https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-bind
typedef int32_t(*bind_t)(Socket s, SOCKADDR const *addr, int32_t namelen);

// https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-wsaaccept
typedef Socket(*WSAAccept_t)(Socket s, SOCKADDR *addr, int32_t *addrlen, ConditionProc_t lpfnCondition, uint64_t dwCallbackData);

// https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-wsaconnect
typedef int32_t(*WSAConnect_t)(Socket s, SOCKADDR const *name, int32_t namelen, WSABUF *lpCallerData, WSABUF *lpCalleeData, QOS *lpSQOS, QOS *lpGQOS);

// https://learn.microsoft.com/en-us/windows/win32/winsock/winsock-ioctls
// https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-wsaioctl
typedef int32_t(*WSAIoctl_t)(Socket s, uint32_t dwIoControlCode, void *lpvInBuffer, uint32_t cbInBuffer, void *lpvOutBuffer, uint32_t cbOutBuffer, uint32_t lpcbBytesReturned, OVERLAPPED *lpOverlapped, WSAOverlappedCompletionRoutine_t lpCompletionRoutine);

// https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-setsockopt
typedef int32_t(*setsockopt_t)(Socket s, int32_t level, int32_t optname, uint8_t const *optval, int32_t optlen);

// https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-getsockopt
typedef int32_t(*getsockopt_t)(Socket s, int32_t level, int32_t optname, uint8_t const *optval, int32_t *optlen);

// https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-closesocket
typedef int32_t(*closesocket_t)(Socket s);

// https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-listen
typedef int32_t(*listen_t)(Socket s, int32_t backlog);

// https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-shutdown
typedef int32_t(*shutdown_t)(Socket s, int32_t how);

// https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-getsockname
typedef int32_t(*getsockname_t)(Socket s, SOCKADDR *name, int32_t *namelen);

// https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-getpeername
typedef int32_t(*getpeername_t)(Socket s, SOCKADDR *name, int32_t *namelen);

// https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-wsasend
typedef int32_t(*WSASend_t)(Socket s, WSABUF *lpBuffers, uint32_t dwBufferCount, uint32_t *lpNumberOfBytesSent, uint32_t dwFlags, OVERLAPPED *lpOverlapped, WSAOverlappedCompletionRoutine_t lpCompletionRoutine);

// https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-wsarecv
typedef int32_t(*WSARecv_t)(Socket s, WSABUF *lpBuffers, uint32_t dwBufferCount, uint32_t *lpNumberOfBytesRecvd, uint32_t *dwFlags, OVERLAPPED *lpOverlapped, WSAOverlappedCompletionRoutine_t lpCompletionRoutine);

// https://learn.microsoft.com/en-us/windows/win32/api/ws2tcpip/nf-ws2tcpip-inetptonw
typedef int32_t(*InetPtonW_t)(int32_t Family, wchar_t const *pszAddrString, void *pAddrBuf);

// https://learn.microsoft.com/en-us/windows/win32/api/ws2tcpip/nf-ws2tcpip-inetntopw
typedef wchar_t const *(*InetNtopW_t)(int32_t Family, void const *pAddr, wchar_t *pStringBuf, uint64_t StringBufSize);

// https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-wsacleanup
typedef int32_t(*WSACleanup_t)();

// https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-wsasocketw
typedef Socket(*WSASocketW_t)(int32_t af, int32_t type, int32_t protocol, WSAPROTOCOL_INFOW *lpProtocolInfo, uint32_t group, uint32_t dwFlags);

// https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-wsarecvfrom
typedef int32_t(*WSARecvFrom_t)(Socket s, WSABUF *lpBuffers, uint32_t dwBufferCount, uint32_t *lpNumberOfBytesRecvd, uint32_t *lpFlags, SOCKADDR *lpFrom, int32_t *lpFromlen, OVERLAPPED *lpOverlapped, WSAOverlappedCompletionRoutine_t lpCompletionRoutine);

// https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-wsasendto
typedef int32_t(*WSASendTo_t)(Socket s, WSABUF *lpBuffers, uint32_t dwBufferCount, uint32_t *lpNumberOfBytesSent, uint32_t dwFlags, SOCKADDR const *lpTo, int32_t iTolen, OVERLAPPED *lpOverlapped, WSAOverlappedCompletionRoutine_t lpCompletionRoutine);

// ░░░ Callable Grouped WS2_32 Functions ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

struct WS2_32Functions
{
	bind_t bind;
	listen_t listen;
	WSASend_t WSASend;
	WSARecv_t WSARecv;
	WSAPoll_t WSAPoll;
	shutdown_t shutdown;
	WSAIoctl_t WSAIoctl;
	WSASendTo_t WSASendTo;
	WSAAccept_t WSAAccept;
	InetPtonW_t InetPtonW;
	InetNtopW_t InetNtopW;
	WSAConnect_t WSAConnect;
	WSAStartup_t WSAStartup;
	WSACleanup_t WSACleanup;
	WSASocketW_t WSASocketW;
	getsockopt_t getsockopt;
	setsockopt_t setsockopt;
	closesocket_t closesocket;
	getsockname_t getsockname;
	getpeername_t getpeername;
	WSARecvFrom_t WSARecvFrom;
};

extern struct WS2_32Functions WS2_32;

// ░░░ Wrap to normal Function ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

static __forceinline int32_t bind(Socket s, SOCKADDR const *addr, int32_t namelen) { return WS2_32.bind(s, addr, namelen); }
static __forceinline int32_t listen(Socket s, int32_t backlog) { return WS2_32.listen(s, backlog); }
static __forceinline int32_t WSASend(Socket s, WSABUF *lpBuffers, uint32_t dwBufferCount, uint32_t *lpNumberOfBytesSent, uint32_t dwFlags, OVERLAPPED *lpOverlapped, WSAOverlappedCompletionRoutine_t lpCompletionRoutine) { return WS2_32.WSASend(s, lpBuffers, dwBufferCount, lpNumberOfBytesSent, dwFlags, lpOverlapped, lpCompletionRoutine); }
static __forceinline int32_t WSARecv(Socket s, WSABUF *lpBuffers, uint32_t dwBufferCount, uint32_t *lpNumberOfBytesRecvd, uint32_t *dwFlags, OVERLAPPED *lpOverlapped, WSAOverlappedCompletionRoutine_t lpCompletionRoutine) { return WS2_32.WSARecv(s, lpBuffers, dwBufferCount, lpNumberOfBytesRecvd, dwFlags, lpOverlapped, lpCompletionRoutine); }
static __forceinline int32_t WSAPoll(WSAPOLLFD *fdArray, uint32_t fds, int32_t timeout) { return WS2_32.WSAPoll(fdArray, fds, timeout); }
static __forceinline int32_t shutdown(Socket s, int32_t how) { return WS2_32.shutdown(s, how); }
static __forceinline int32_t WSAIoctl(Socket s, uint32_t dwIoControlCode, void *lpvInBuffer, uint32_t cbInBuffer, void *lpvOutBuffer, uint32_t cbOutBuffer, uint32_t lpcbBytesReturned, OVERLAPPED *lpOverlapped, WSAOverlappedCompletionRoutine_t lpCompletionRoutine) { return WS2_32.WSAIoctl(s, dwIoControlCode, lpvInBuffer, cbInBuffer, lpvOutBuffer, cbOutBuffer, lpcbBytesReturned, lpOverlapped, lpCompletionRoutine); }
static __forceinline Socket WSAAccept(Socket s, SOCKADDR *addr, int32_t *addrlen, ConditionProc_t lpfnCondition, uint64_t dwCallbackData) { return WS2_32.WSAAccept(s, addr, addrlen, lpfnCondition, dwCallbackData); }
static __forceinline Socket WSASocketW(int32_t af, int32_t type, int32_t protocol, WSAPROTOCOL_INFOW *lpProtocolInfo, uint32_t group, uint32_t dwFlags) { return WS2_32.WSASocketW(af, type, protocol, lpProtocolInfo, group, dwFlags); }
static __forceinline int32_t InetPtonW(int32_t Family, wchar_t const *pszAddrString, void *pAddrBuf) { return WS2_32.InetPtonW(Family, pszAddrString, pAddrBuf); }
static __forceinline int32_t WSASendTo(Socket s, WSABUF *lpBuffers, uint32_t dwBufferCount, uint32_t *lpNumberOfBytesSent, uint32_t dwFlags, SOCKADDR const *lpTo, int32_t iTolen, OVERLAPPED *lpOverlapped, WSAOverlappedCompletionRoutine_t lpCompletionRoutine) { return WS2_32.WSASendTo(s, lpBuffers, dwBufferCount, lpNumberOfBytesSent, dwFlags, lpTo, iTolen, lpOverlapped, lpCompletionRoutine); }
static __forceinline int32_t setsockopt(Socket s, int32_t level, int32_t optname, uint8_t const *optval, int32_t optlen) { return WS2_32.setsockopt(s, level, optname, optval, optlen); }
static __forceinline int32_t getsockopt(Socket s, int32_t level, int32_t optname, uint8_t const *optval, int32_t *optlen) { return WS2_32.getsockopt(s, level, optname, optval, optlen); }
static __forceinline int32_t WSAConnect(Socket s, SOCKADDR const *name, int32_t namelen, WSABUF *lpCallerData, WSABUF *lpCalleeData, QOS *lpSQOS, QOS *lpGQOS) { return WS2_32.WSAConnect(s, name, namelen, lpCallerData, lpCalleeData, lpSQOS, lpGQOS); }
static __forceinline int32_t WSACleanup() { return WS2_32.WSACleanup(); }
static __forceinline int32_t WSAStartup(uint16_t wVersionRequired, WSADATA *lpWSAData) { return WS2_32.WSAStartup(wVersionRequired, lpWSAData); }
static __forceinline int32_t closesocket(Socket s) { return WS2_32.closesocket(s); }
static __forceinline int32_t WSARecvFrom(Socket s, WSABUF *lpBuffers, uint32_t dwBufferCount, uint32_t *lpNumberOfBytesRecvd, uint32_t *lpFlags, SOCKADDR *lpFrom, int32_t *lpFromlen, OVERLAPPED *lpOverlapped, WSAOverlappedCompletionRoutine_t lpCompletionRoutine) { return WS2_32.WSARecvFrom(s, lpBuffers, dwBufferCount, lpNumberOfBytesRecvd, lpFlags, lpFrom, lpFromlen, lpOverlapped, lpCompletionRoutine); }
static __forceinline int32_t getsockname(Socket s, SOCKADDR *name, int32_t *namelen) { return WS2_32.getsockname(s, name, namelen); }
static __forceinline int32_t getpeername(Socket s, SOCKADDR *name, int32_t *namelen) { return WS2_32.getpeername(s, name, namelen); }
static __forceinline wchar_t const *InetNtopW(int32_t Family, void const *pAddr, wchar_t *pStringBuf, uint64_t StringBufSize) { return WS2_32.InetNtopW(Family, pAddr, pStringBuf, StringBufSize); }