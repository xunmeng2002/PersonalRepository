#include "TestUdpServer.h"
#include "UdpServer.h"
#include "Logger.h"


void TestUdpServer()
{
    auto IP1 = "0.0.0.0";
    auto IP2 = "127.0.0.1";
    auto IP3 = "192.168.2.29";
    auto IP4 = "::";
    auto IP5 = "::0";
    auto IP6 = "::1";
    auto IP7 = "fe80::59d8:5d6d:25cc:42cf%14";

    auto ServerPort = "10000";
    auto ClientPort = "10001";

    UdpServer udpServer;
    udpServer.SetBindAddressInfo(ServerPort, IP4);
    udpServer.Init(false);

    while (true)
    {
        TcpEvent* tcpEvent = TcpEvent::Allocate();
        //udpServer.RecvFrom(tcpEvent);
        udpServer.ZipRecvFrom(tcpEvent);
        tcpEvent->Free();
    }
}