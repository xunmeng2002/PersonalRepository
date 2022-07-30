#include "TestUdpServer.h"
#include "UdpServer.h"
#include "Config.h"

void TestUdpServer()
{
    auto IP1 = "127.0.0.1";
    auto IP2 = "192.168.2.29";
    auto IP3 = "::1";
    auto IP4 = "fe80::59d8:5d6d:25cc:42cf%14";
    auto IP = "114.80.171.123";
    auto Port = "10000";

    UdpServer udpServer;
    udpServer.SetBindAddressInfo(Config::GetInstance().ListenIP.c_str(), Config::GetInstance().ListenPort.c_str());
    udpServer.Init(true);

    std::string msg = "Hello World, From UdpClient!";
    for (auto i = 0; i < 5; i++)
    {
        TcpEvent* tcpEvent = TcpEvent::Allocate();
        udpServer.ZipRecvFrom(tcpEvent);

        printf("udpServer RecvFrom IP[%s], Port[%s], Content:[%s]\n\n", tcpEvent->IP.c_str(), tcpEvent->Port.c_str(), tcpEvent->Buff);
    }
}
