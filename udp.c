#include "ntdll.h"
#include "dnsapi.h"
#include "ws2_32.h"
#include "console.h"
#include "intrinsics.h"

void TestUDP()
{
	ConsoleWrite(u"# UDP\n\n");

	Socket socket = INVALID_SOCKET;
	WSADATA wsData;

	if (WSAStartup((2 << 8) | 2, &wsData))
	{
		ConsoleWrite(u"WSAStartup() failed\n");
		return;
	}

	if (wsData.wHighVersion != 0x0202)
	{
		ConsoleWrite(u"There is a newer version than 2.2 of Winsock available?!\n");
		goto ERROR_EXIT;
	}

	if (wsData.wVersion != 0x0202)
	{
		ConsoleWrite(u"Winsock 2.2 not supported\n");
		goto ERROR_EXIT;
	}

	/* - - - - - - - - - - - - - - - - - - - */

	socket = WSASocketW(AF_INET, SOCK_DGRAM, IPPROTO_UDP, null, 0, WSA_FLAG_OVERLAPPED | WSA_FLAG_NO_HANDLE_INHERIT);
	if (socket == INVALID_SOCKET)
	{
		ConsoleWrite(u"WSASocketW() failed\n");
		goto ERROR_EXIT;
	}

	SOCKADDR_IN socketAddress;
	socketAddress.sin_family = AF_INET;
	socketAddress.sin_port = _byteswap_ushort(420);
	socketAddress.sin_addr.S_addr = _byteswap_ulong(0x7F'00'00'01);
	*(uint64_t *)socketAddress.sin_zero = 0;

	uint32_t pmtud = IP_PMTUDISC_DO; // DF
	setsockopt(socket, IPPROTO_IP, IP_MTU_DISCOVER, (const uint8_t *)&pmtud, sizeof(pmtud));

	int32_t size = 1 << 16;   // 64KiB = default
	setsockopt(socket, SOL_SOCKET, SO_RCVBUF, (const uint8_t *)&size, sizeof(size));
	setsockopt(socket, SOL_SOCKET, SO_SNDBUF, (const uint8_t *)&size, sizeof(size));

	uint32_t bytesReturned = 0;
	bool_t udpConnectionReset = false; 
	if (SOCKET_ERROR == WSAIoctl(socket, SIO_UDP_CONNRESET, &udpConnectionReset, sizeof(udpConnectionReset), null, 0, &bytesReturned, null, null))
	{
		ConsoleWrite(u"WSAIoctl() failed\n");
		goto ERROR_EXIT;
	}

	uint32_t timeout = 2048;
	setsockopt(socket, SOL_SOCKET, SO_RCVTIMEO, (const uint8_t *)&timeout, sizeof(timeout));
	setsockopt(socket, SOL_SOCKET, SO_SNDTIMEO, (const uint8_t *)&timeout, sizeof(timeout));

	/* - - - - - - - - - - - - - - - - - - - */

	if (SOCKET_ERROR == WSAConnect(socket, (SOCKADDR *)&socketAddress, sizeof(SOCKADDR_IN), null, null, null, null))
	{
		ConsoleWrite(u"WSAConnect() failed\n");
		goto ERROR_EXIT;
	}

	uint8_t data[] = "BUSTING IN PROGRESS";

	WSABUF wsBuffer = { 0 };
	wsBuffer.buf = data;
	wsBuffer.len = sizeof(data);

	uint32_t send = 0;
	if (SOCKET_ERROR == WSASend(socket, &wsBuffer, 1, &send, 0, null, null))
	{
		ConsoleWrite(u"WSASend() failed\n");
		goto ERROR_EXIT;
	}

	uint32_t flags = 0;
	if (SOCKET_ERROR == WSARecv(socket, &wsBuffer, 1, &send, &flags, null, null))
	{
		// WSAECONNRESET when SIO_UDP_CONNRESET is set to true - no timeout
		// otherwise WSAETIMEDOUT after timeout
		if (WSAECONNRESET == GET_LAST_ERROR) ConsoleWrite(u"WSARecv() failed: WSAECONNRESET\n");
		else if (WSAETIMEDOUT == GET_LAST_ERROR) ConsoleWrite(u"WSARecv() failed: WSAETIMEDOUT\n");
		else ConsoleWrite(u"WSARecv() failed\n");
		goto ERROR_EXIT;
	}

	/* - - - - - - - - - - - - - - - - - - - */

	if (socket != INVALID_SOCKET) closesocket(socket);
	WSACleanup();

	ConsoleWrite(u"\n----------------------------------------------------------------\n\n");
	return;

ERROR_EXIT:
	if (socket != INVALID_SOCKET) closesocket(socket);
	WSACleanup();

	ConsoleWrite(u"\n----------------------------------------------------------------\n\n");
}