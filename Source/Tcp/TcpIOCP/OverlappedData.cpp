#include "OverlappedData.h"
#include "MemCacheTemplateSingleton.h"
#include <Ws2tcpip.h>


OverlappedData::OverlappedData()
{
    RemoteAddressInfo = nullptr;
    Clear();
}
OverlappedData* OverlappedData::Allocate()
{
	return MemCacheTemplateSingleton<OverlappedData>::GetInstance().Allocate();
}
void OverlappedData::Free()
{
	Clear();
	MemCacheTemplateSingleton<OverlappedData>::GetInstance().Free(this);
}
void OverlappedData::Clear()
{
    EventID = -1;
    SessionID = 0;
    ConnectSocket = INVALID_SOCKET;
    Internal = InternalHigh = 0;
    Offset = OffsetHigh = 0;
    hEvent = NULL;
    WsaBuffer.len = 0;
    WsaBuffer.buf = Buffer;
    memset(Buffer, 0, sizeof(Buffer));
    if (RemoteAddressInfo)
    {
        freeaddrinfo(RemoteAddressInfo);
    }
    RemoteAddressInfo = nullptr;
    RemoteIP = "";
    RemotePort = "";
}