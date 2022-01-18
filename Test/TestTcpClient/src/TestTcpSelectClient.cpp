#include "TestTcpSelectClient.h"
#include "TcpClientSubscriberImpl.h"
#include "Logger.h"


void TestTcpSelectClient(const char* ip, const char* port)
{
    TcpSelectClient tcpSelectClient;
    tcpSelectClient.SetTimeOut(1000);
    tcpSelectClient.SetSocketTimeOut(5000);
    TcpClientSubscriberImpl tcpClientSubscriberImpl(&tcpSelectClient);
    tcpSelectClient.Subscriber(&tcpClientSubscriberImpl);

    if (!tcpSelectClient.Init(AF_INET6))
    {
        return;
    }
    tcpSelectClient.Start();

    tcpSelectClient.Connect(ip, port);

    tcpSelectClient.Join();
}
