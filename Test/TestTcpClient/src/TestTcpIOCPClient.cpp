#include "TestTcpIOCPClient.h"
#include "TcpIOCPClient.h"
#include "TcpClientSubscriberImpl.h"
#include "Logger.h"


void TestTcpIOCPClient(const char* ip, const char* port)
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
    //tcpIOCPClient.Connect(ip, port);
    //tcpIOCPClient.Connect(IP1, port);
    tcpIOCPClient.Connect(IP2, port);
    //tcpIOCPClient.Connect(IP3, port);
    //tcpIOCPClient.Connect(IP4, port);
    //tcpIOCPClient.Connect(IP5, port);
    tcpIOCPClient.Connect(IP6, port);
    tcpIOCPClient.Connect(IP7, port);


    tcpIOCPClient.Join();
}
