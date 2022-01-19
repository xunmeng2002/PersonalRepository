#include "TestTcpIOCPClient.h"
#include "TcpIOCPClient.h"
#include "TcpClientSubscriberImpl.h"
#include "Logger.h"


void TestTcpIOCPClient()
{
    auto IP1 = "127.0.0.1";
    auto IP2 = "192.168.2.29";
    auto IP3 = "::1";
    auto IP4 = "fe80::59d8:5d6d:25cc:42cf%14";

    auto Port = "10000";

    TcpIOCPClient tcpIOCPClient;
    tcpIOCPClient.SetTimeOut(1000);
    tcpIOCPClient.SetSocketTimeOut(5000);
    TcpClientSubscriberImpl tcpClientSubscriberImpl(&tcpIOCPClient);
    tcpIOCPClient.Subscriber(&tcpClientSubscriberImpl);

    if (!tcpIOCPClient.Init())
    {
        return;
    }
    tcpIOCPClient.Start();

    tcpIOCPClient.Connect(IP1, Port);
    tcpIOCPClient.Connect(IP2, Port);
    tcpIOCPClient.Connect(IP3, Port);
    tcpIOCPClient.Connect(IP4, Port);

    tcpIOCPClient.Join();
}
