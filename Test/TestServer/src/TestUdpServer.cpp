#include "TestUdpServer.h"
#include "UdpServer.h"
#include "Logger.h"


void TestUdpServer()
{
    auto IP1 = "0.0.0.0";
    auto IP2 = "::";

    auto Port = "10000";

    UdpServer udpServer;
    udpServer.SetBindAddressInfo(IP2, Port);
    udpServer.Init(false);

    while (true)
    {
        TcpEvent* tcpEvent = TcpEvent::Allocate();
        //udpServer.RecvFrom(tcpEvent);
        udpServer.ZipRecvFrom(tcpEvent);
        tcpEvent->Free();
    }
}