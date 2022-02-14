#pragma once
#include "SocketInit.h"
#ifdef WINDOWS
#include <mswsock.h>
#endif

class SocketApi
{
private:
	SocketApi();
	~SocketApi();
	SocketApi(const SocketApi&) = delete;
	SocketApi& operator=(const SocketApi&) = delete;

public:
	static SocketApi& GetInstance();
	bool Init();
	bool InitV4(SOCKET sockV4);
	bool InitV6(SOCKET sockV6);

	bool AcceptEx(int family,
		_In_ SOCKET sListenSocket,
		_In_ SOCKET sAcceptSocket,
		PVOID lpOutputBuffer,
		_In_ DWORD dwReceiveDataLength,
		_In_ DWORD dwLocalAddressLength,
		_In_ DWORD dwRemoteAddressLength,
		LPDWORD lpdwBytesReceived,
		_Inout_ LPOVERLAPPED lpOverlapped);

	void GetAcceptExSockAddrs(int family,
		_In_reads_bytes_(dwReceiveDataLength + dwLocalAddressLength + dwRemoteAddressLength) PVOID lpOutputBuffer,
		_In_ DWORD dwReceiveDataLength,
		_In_ DWORD dwLocalAddressLength,
		_In_ DWORD dwRemoteAddressLength,
		struct sockaddr** LocalSockaddr,
		LPINT LocalSockaddrLength,
		struct sockaddr** RemoteSockaddr,
		LPINT RemoteSockaddrLength);

	bool ConnectEx(int family,
		_In_ SOCKET s,
		_In_reads_bytes_(namelen) const struct sockaddr FAR* name,
		_In_ int namelen,
		_In_reads_bytes_opt_(dwSendDataLength) PVOID lpSendBuffer,
		_In_ DWORD dwSendDataLength,
		_Out_ LPDWORD lpdwBytesSent,
		_Inout_ LPOVERLAPPED lpOverlapped);


	bool DisconnectEx(int family,
		_In_ SOCKET s,
		_Inout_opt_ LPOVERLAPPED lpOverlapped,
		_In_ DWORD  dwFlags,
		_In_ DWORD  dwReserved);





private:
	static SocketApi m_Instance;
	
	LPFN_ACCEPTEX AcceptExV4;
	LPFN_GETACCEPTEXSOCKADDRS GetAcceptExSockAddrsV4;
	LPFN_CONNECTEX ConnectExV4;
	LPFN_DISCONNECTEX DisconnectExV4;
	
	LPFN_ACCEPTEX AcceptExV6;
	LPFN_GETACCEPTEXSOCKADDRS GetAcceptExSockAddrsV6;
	LPFN_CONNECTEX ConnectExV6;
	LPFN_DISCONNECTEX DisconnectExV6;
};