#include "TestTcpSelectServer.h"
#include "TcpSelectServer.h"
#include "TcpServerSubscriberImpl.h"
#include "Logger.h"



void TestTcpSelectServer(const char* ip, const char* port)
{
    TcpSelectServer tcpSelectServer;
    tcpSelectServer.SetTimeOut(1000);
    tcpSelectServer.SetSocketTimeOut(2000);
    tcpSelectServer.SetBindAddressInfo(port);
    TcpServerSubscriberImpl tcpServerSubscriberImpl(&tcpSelectServer);
    tcpSelectServer.Subscriber(&tcpServerSubscriberImpl);

    if (!tcpSelectServer.Init())
    {
        return;
    }
    tcpSelectServer.Start();

    tcpSelectServer.Join();
}
