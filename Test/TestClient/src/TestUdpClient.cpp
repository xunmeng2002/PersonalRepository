#include "TestUdpClient.h"
#include "UdpClient.h"


void TestUdpClient()
{
    auto IP1 = "127.0.0.1";
    auto IP2 = "192.168.2.29";
    auto IP3 = "::1";
    auto IP4 = "fe80::59d8:5d6d:25cc:42cf%14";

    auto ServerPort = "10000";
    auto ClientPort = "10001";

    UdpClient udpClient;
    udpClient.Init(false);

    for (auto i = 0; i < 3; i++)
    {
        TcpEvent* tcpEvent = TcpEvent::Allocate();
        tcpEvent->IP = IP1;
        tcpEvent->Port = ServerPort;
        tcpEvent->Length = sprintf(tcpEvent->Buff, "Udp Message[%d]", i);
        //udpClient.SendTo(tcpEvent);
        udpClient.ZipSendTo(tcpEvent);
        tcpEvent->Free();
        Sleep(1000);
    }
}