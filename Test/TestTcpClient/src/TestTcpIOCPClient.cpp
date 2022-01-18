#include "TestTcpIOCPClient.h"
#include "TcpIOCPClient.h"
#include "TcpClientSubscriberImpl.h"
#include "Logger.h"


void TestTcpIOCPClient()
{
    TcpIOCPClient tcpIOCPClient;
    tcpIOCPClient.SetTimeOut(1000);
    tcpIOCPClient.SetSocketTimeOut(5000);
    tcpIOCPClient.SetBindAddressInfo("");
    TcpClientSubscriberImpl tcpClientSubscriberImpl(&tcpIOCPClient);
    tcpIOCPClient.Subscriber(&tcpClientSubscriberImpl);

    if (!tcpIOCPClient.Init(AF_INET6))
    {
        return;
    }
    tcpIOCPClient.Start();

    auto IP1 = "0.0.0.0";
    auto IP2 = "127.0.0.1";
    auto IP3 = "192.168.2.29";
    auto IP4 = "::";
    auto IP5 = "::0";
    auto IP6 = "::1";
    auto IP7 = "fe80::59d8:5d6d:25cc:42cf%14";
    
    auto Port = "10000";

    tcpIOCPClient.Connect(IP1, Port);
    tcpIOCPClient.Connect(IP2, Port);
    tcpIOCPClient.Connect(IP3, Port);
    tcpIOCPClient.Connect(IP4, Port);
    tcpIOCPClient.Connect(IP5, Port);
    tcpIOCPClient.Connect(IP6, Port);
    tcpIOCPClient.Connect(IP7, Port);


    tcpIOCPClient.Join();
}
