#include "TestUdpServer.h"
#include "UdpServer.h"
#include "Logger.h"


void TestUdpServer()
{
    auto IP1 = "0.0.0.0";
    auto IP2 = "::";

    auto ServerPort = "10000";
    auto ClientPort = "10001";

    UdpServer udpServer;
    udpServer.SetBindAddressInfo(ServerPort, IP2);
    udpServer.Init(false);

    while (true)
    {
        TcpEvent* tcpEvent = TcpEvent::Allocate();
        //udpServer.RecvFrom(tcpEvent);
        udpServer.ZipRecvFrom(tcpEvent);
        tcpEvent->Free();
    }
}