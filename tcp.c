#include "ntdll.h"
#include "dnsapi.h"
#include "ws2_32.h"
#include "console.h"
#include "intrinsics.h"

void TestTCP()
{
	ConsoleWrite(u"# TCP\n\n");

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

	socket = WSASocketW(AF_INET, SOCK_STREAM, IPPROTO_TCP, null, 0, WSA_FLAG_OVERLAPPED | WSA_FLAG_NO_HANDLE_INHERIT);
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

	bool_t noDelay = 1;
	setsockopt(socket, IPPROTO_TCP, TCP_NODELAY, (const uint8_t *)&noDelay, sizeof(noDelay));

	bool_t keepAlive = 1;   // enable
	int32_t keepIdle = 25;   // seconds
	int32_t keepIntvl = 20;  // seconds
	int32_t keepCnt = 3;	 // count
	setsockopt(socket, SOL_SOCKET, SO_KEEPALIVE, (const uint8_t *)&keepAlive, sizeof(keepAlive));
	setsockopt(socket, IPPROTO_TCP, TCP_KEEPIDLE, (const uint8_t *)&keepIdle, sizeof(keepIdle));
	setsockopt(socket, IPPROTO_TCP, TCP_KEEPINTVL, (const uint8_t *)&keepIntvl, sizeof(keepIntvl));
	setsockopt(socket, IPPROTO_TCP, TCP_KEEPCNT, (const uint8_t *)&keepCnt, sizeof(keepCnt));

	uint32_t timeout = 20480;
	setsockopt(socket, SOL_SOCKET, SO_RCVTIMEO, (const uint8_t *)&timeout, sizeof(timeout));
	setsockopt(socket, SOL_SOCKET, SO_SNDTIMEO, (const uint8_t *)&timeout, sizeof(timeout));

	bool_t exclusive = 1;
	setsockopt(socket, SOL_SOCKET, SO_EXCLUSIVEADDRUSE, (const uint8_t *)&exclusive, sizeof(exclusive));

	//LINGER linger = { 1, 1 };
	//setsockopt(socket, SOL_SOCKET, SO_LINGER, (const uint8_t *)&linger, sizeof(linger));

	/* - - - - - - - - - - - - - - - - - - - */

	if (SOCKET_ERROR == WSAConnect(socket, (SOCKADDR *)&socketAddress, sizeof(SOCKADDR_IN), null, null, null, null))
	{
		ConsoleWrite(u"WSAConnect() failed\n");
		goto ERROR_EXIT;
	}

	uint8_t *buffér = _alloca(512);
	__stosb(buffér, 0, 512);
	__movsb(buffér, "BUSTING IN PROGRESS", 20);

	WSABUF wsBuffer = { 0 };
	wsBuffer.buf = buffér;
	wsBuffer.len = 512;

	uint32_t send = 0;
	if (SOCKET_ERROR == WSASend(socket, &wsBuffer, 1, &send, 0, null, null))
	{
		ConsoleWrite(u"WSASend() failed\n");
		goto ERROR_EXIT;
	}

	shutdown(socket, SD_SEND);

	uint32_t flags = 0;
	if (SOCKET_ERROR == WSARecv(socket, &wsBuffer, 1, &send, &flags, null, null))
	{
		if (WSAECONNRESET == GET_LAST_ERROR) ConsoleWrite(u"WSARecv() failed: WSAECONNRESET\n");
		else if (WSAETIMEDOUT == GET_LAST_ERROR) ConsoleWrite(u"WSARecv() failed: WSAETIMEDOUT\n");
		else ConsoleWrite(u"WSARecv() failed\n");
		goto ERROR_EXIT;
	}

AGAIN:
	flags = 0;
	if (SOCKET_ERROR == WSARecv(socket, &wsBuffer, 1, &send, &flags, null, null))
	{
		if (WSAECONNRESET == GET_LAST_ERROR) ConsoleWrite(u"WSARecv() failed: WSAECONNRESET\n");
		else if (WSAETIMEDOUT == GET_LAST_ERROR) ConsoleWrite(u"WSARecv() failed: WSAETIMEDOUT\n");
		else ConsoleWrite(u"WSARecv() failed\n");
		goto ERROR_EXIT;
	}

	if (send != 0) goto AGAIN;

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