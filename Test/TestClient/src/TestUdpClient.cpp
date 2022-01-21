#include "TestUdpClient.h"
#include "UdpClient.h"


void TestUdpClient()
{
    auto IP1 = "127.0.0.1";
    auto IP2 = "192.168.2.29";
    auto IP3 = "::1";
    auto IP4 = "fe80::59d8:5d6d:25cc:42cf%14";

    auto Port = "10000";

    UdpClient udpClient;
    udpClient.SetRemoteAddress(IP1, Port);
    udpClient.Init(false);

    TcpEvent* tcpEvent = TcpEvent::Allocate();
    tcpEvent->Length = sprintf(tcpEvent->Buff, "Udp Message[1]");
    //udpClient.SendTo(tcpEvent);
    udpClient.ZipSendTo(tcpEvent);
    Sleep(1000);

    tcpEvent->IP = IP2;
    tcpEvent->Port = Port;
    tcpEvent->Length = sprintf(tcpEvent->Buff, "Udp Message[2]");
    //udpClient.SendTo(tcpEvent);
    udpClient.ZipSendTo(tcpEvent);
    Sleep(1000);

    tcpEvent->IP = IP3;
    tcpEvent->Port = Port;
    tcpEvent->Length = sprintf(tcpEvent->Buff, "Udp Message[3]");
    //udpClient.SendTo(tcpEvent);
    udpClient.ZipSendTo(tcpEvent);
    Sleep(1000);

    tcpEvent->IP = IP4;
    tcpEvent->Port = Port;
    tcpEvent->Length = sprintf(tcpEvent->Buff, "Udp Message[4]");
    //udpClient.SendTo(tcpEvent);
    udpClient.ZipSendTo(tcpEvent);
    tcpEvent->Free();
    Sleep(5000);
}