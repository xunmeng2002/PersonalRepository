#include "SocketApi.h"
#include "Logger.h"

SocketApi SocketApi::m_Instance;

SocketApi::SocketApi()
{
	AcceptExV4 = nullptr;
	GetAcceptExSockAddrsV4 = nullptr;
	ConnectExV4 = nullptr;
	DisconnectExV4 = nullptr;

	AcceptExV6 = nullptr;
	GetAcceptExSockAddrsV6 = nullptr;
	ConnectExV6 = nullptr;
	DisconnectExV6 = nullptr;
}
SocketApi::~SocketApi()
{

}

SocketApi& SocketApi::GetInstance()
{
	return m_Instance;
}

bool SocketApi::InitV4(SOCKET sockV4)
{
	GUID guidAcceptEx = WSAID_ACCEPTEX;
	GUID guidGetAcceptExSockAddrs = WSAID_GETACCEPTEXSOCKADDRS;
	GUID guidConnectEx = WSAID_CONNECTEX;
	GUID guidDisconnectEx = WSAID_DISCONNECTEX;


	DWORD dwBytes = 0;
	if (SOCKET_ERROR == WSAIoctl(sockV4, SIO_GET_EXTENSION_FUNCTION_POINTER, &guidAcceptEx, sizeof(guidAcceptEx),
		&AcceptExV4, sizeof(AcceptExV4), &dwBytes, NULL, NULL))
	{
		WRITE_ERROR_LOG(WSAGetLastError(), "Get AcceptExV4 Func Failed.");
		return false;
	}
	if (SOCKET_ERROR == WSAIoctl(sockV4, SIO_GET_EXTENSION_FUNCTION_POINTER, &guidGetAcceptExSockAddrs, sizeof(guidGetAcceptExSockAddrs),
		&GetAcceptExSockAddrsV4, sizeof(GetAcceptExSockAddrsV4), &dwBytes, NULL, NULL))
	{
		WRITE_ERROR_LOG(WSAGetLastError(), "Get GetAcceptExSockAddrsV4 Func Failed.");
		return false;
	}
	if (SOCKET_ERROR == WSAIoctl(sockV4, SIO_GET_EXTENSION_FUNCTION_POINTER, &guidConnectEx, sizeof(guidConnectEx),
		&ConnectExV4, sizeof(ConnectExV4), &dwBytes, NULL, NULL))
	{
		WRITE_ERROR_LOG(WSAGetLastError(), "Get ConnectExV4 Func Failed.");
		return false;
	}
	if (SOCKET_ERROR == WSAIoctl(sockV4, SIO_GET_EXTENSION_FUNCTION_POINTER, &guidDisconnectEx, sizeof(guidDisconnectEx),
		&DisconnectExV4, sizeof(DisconnectExV4), &dwBytes, NULL, NULL))
	{
		WRITE_ERROR_LOG(WSAGetLastError(), "Get DisconnectExV4 Func Failed.");
		return false;
	}
	return true;
}
bool SocketApi::InitV6(SOCKET sockV6)
{
	GUID guidAcceptEx = WSAID_ACCEPTEX;
	GUID guidGetAcceptExSockAddrs = WSAID_GETACCEPTEXSOCKADDRS;
	GUID guidConnectEx = WSAID_CONNECTEX;
	GUID guidDisconnectEx = WSAID_DISCONNECTEX;


	DWORD dwBytes = 0;
	if (SOCKET_ERROR == WSAIoctl(sockV6, SIO_GET_EXTENSION_FUNCTION_POINTER, &guidAcceptEx, sizeof(guidAcceptEx),
		&AcceptExV6, sizeof(AcceptExV6), &dwBytes, NULL, NULL))
	{
		WRITE_ERROR_LOG(WSAGetLastError(), "Get AcceptExV6 Func Failed.");
		return false;
	}
	if (SOCKET_ERROR == WSAIoctl(sockV6, SIO_GET_EXTENSION_FUNCTION_POINTER, &guidGetAcceptExSockAddrs, sizeof(guidGetAcceptExSockAddrs),
		&GetAcceptExSockAddrsV6, sizeof(GetAcceptExSockAddrsV6), &dwBytes, NULL, NULL))
	{
		WRITE_ERROR_LOG(WSAGetLastError(), "Get GetAcceptExSockAddrsV6 Func Failed.");
		return false;
	}
	if (SOCKET_ERROR == WSAIoctl(sockV6, SIO_GET_EXTENSION_FUNCTION_POINTER, &guidConnectEx, sizeof(guidConnectEx),
		&ConnectExV6, sizeof(ConnectExV6), &dwBytes, NULL, NULL))
	{
		WRITE_ERROR_LOG(WSAGetLastError(), "Get ConnectExV6 Func Failed.");
		return false;
	}
	if (SOCKET_ERROR == WSAIoctl(sockV6, SIO_GET_EXTENSION_FUNCTION_POINTER, &guidDisconnectEx, sizeof(guidDisconnectEx),
		&DisconnectExV6, sizeof(DisconnectExV6), &dwBytes, NULL, NULL))
	{
		WRITE_ERROR_LOG(WSAGetLastError(), "Get DisconnectExV6 Func Failed.");
		return false;
	}
	return true;
}

bool SocketApi::AcceptEx(int family,
	_In_ SOCKET sListenSocket,
	_In_ SOCKET sAcceptSocket,
	_Out_writes_bytes_(dwReceiveDataLength + dwLocalAddressLength + dwRemoteAddressLength) PVOID lpOutputBuffer,
	_In_ DWORD dwReceiveDataLength,
	_In_ DWORD dwLocalAddressLength,
	_In_ DWORD dwRemoteAddressLength,
	_Out_ LPDWORD lpdwBytesReceived,
	_Inout_ LPOVERLAPPED lpOverlapped)
{
	if (family == AF_INET)
	{
		return AcceptExV4(sListenSocket, sAcceptSocket, lpOutputBuffer, dwReceiveDataLength, dwLocalAddressLength, dwRemoteAddressLength, lpdwBytesReceived, lpOverlapped);
	}
	else if (family == AF_INET6)
	{
		return AcceptExV6(sListenSocket, sAcceptSocket, lpOutputBuffer, dwReceiveDataLength, dwLocalAddressLength, dwRemoteAddressLength, lpdwBytesReceived, lpOverlapped);
	}
	return false;
}

void SocketApi::GetAcceptExSockAddrs(int family,
	_In_reads_bytes_(dwReceiveDataLength + dwLocalAddressLength + dwRemoteAddressLength) PVOID lpOutputBuffer,
	_In_ DWORD dwReceiveDataLength,
	_In_ DWORD dwLocalAddressLength,
	_In_ DWORD dwRemoteAddressLength,
	_Outptr_result_bytebuffer_(*LocalSockaddrLength) struct sockaddr** LocalSockaddr,
	_Out_ LPINT LocalSockaddrLength,
	_Outptr_result_bytebuffer_(*RemoteSockaddrLength) struct sockaddr** RemoteSockaddr,
	_Out_ LPINT RemoteSockaddrLength)
{
	if (family == AF_INET)
	{
		GetAcceptExSockAddrsV4(lpOutputBuffer, dwReceiveDataLength, dwLocalAddressLength, dwRemoteAddressLength, LocalSockaddr, LocalSockaddrLength, RemoteSockaddr, RemoteSockaddrLength);
	}
	else if (family == AF_INET6)
	{
		GetAcceptExSockAddrsV6(lpOutputBuffer, dwReceiveDataLength, dwLocalAddressLength, dwRemoteAddressLength, LocalSockaddr, LocalSockaddrLength, RemoteSockaddr, RemoteSockaddrLength);
	}
}

bool SocketApi::ConnectEx(int family,
	_In_ SOCKET s,
	_In_reads_bytes_(namelen) const struct sockaddr FAR* name,
	_In_ int namelen,
	_In_reads_bytes_opt_(dwSendDataLength) PVOID lpSendBuffer,
	_In_ DWORD dwSendDataLength,
	_Out_ LPDWORD lpdwBytesSent,
	_Inout_ LPOVERLAPPED lpOverlapped)
{
	if (family == AF_INET)
	{
		return ConnectExV4(s, name, namelen, lpSendBuffer, dwSendDataLength, lpdwBytesSent, lpOverlapped);
	}
	else if (family == AF_INET6)
	{
		return ConnectExV6(s, name, namelen, lpSendBuffer, dwSendDataLength, lpdwBytesSent, lpOverlapped);
	}
	return false;
}


bool SocketApi::DisconnectEx(int family,
	_In_ SOCKET s,
	_Inout_opt_ LPOVERLAPPED lpOverlapped,
	_In_ DWORD  dwFlags,
	_In_ DWORD  dwReserved)
{
	if (family == AF_INET)
	{
		return DisconnectExV4(s, lpOverlapped, dwFlags, dwReserved);
	}
	else if (family == AF_INET6)
	{
		return DisconnectExV6(s, lpOverlapped, dwFlags, dwReserved);
	}
	return false;
}