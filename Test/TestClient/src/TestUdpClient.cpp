#include "TestUdpClient.h"
#include "UdpClient.h"


void TestUdpClient()
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

    UdpClient udpClient;
    udpClient.Init(false);

    for (auto i = 0; i < 3; i++)
    {
        TcpEvent* tcpEvent = TcpEvent::Allocate();
        tcpEvent->IP = IP3;
        tcpEvent->Port = ServerPort;
        tcpEvent->Length = sprintf(tcpEvent->Buff, "Udp Message[%d]", i);
        //udpClient.SendTo(tcpEvent);
        udpClient.ZipSendTo(tcpEvent);
        tcpEvent->Free();
        Sleep(1000);
    }
}