#include "TestUdpServer.h"
#include "Udp.h"
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

    Udp::GetInstance().SetBindAddressInfo(IP1, ServerPort);
    Udp::GetInstance().SetRemoteAddressInfo(IP1, ClientPort);
    Udp::GetInstance().Init(true);

    while (true)
    {
        TcpEvent* tcpEvent = TcpEvent::Allocate();
        Udp::GetInstance().RecvFrom(tcpEvent);
        WRITE_LOG(LogLevel::Info, "RecvFrom:<%s|%s> Message:%s", IP1, ClientPort, tcpEvent->ReadPos);
        tcpEvent->Free();
    }
}