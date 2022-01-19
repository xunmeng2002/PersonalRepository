#include "TestUdpClient.h"
#include "Udp.h"


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

	Udp::GetInstance().SetBindAddressInfo(IP1, ClientPort);
	Udp::GetInstance().SetRemoteAddressInfo(IP6, ServerPort);
    Udp::GetInstance().Init(true, AF_INET);

    for (auto i = 0; i < 5; i++)
    {
        TcpEvent* tcpEvent = TcpEvent::Allocate();
        tcpEvent->Length = sprintf(tcpEvent->Buff, "Udp Message[%d]", i);
        Udp::GetInstance().SendTo(tcpEvent);
        tcpEvent->Free();
        Sleep(1000);
    }
}