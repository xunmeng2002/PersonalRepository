#include "TestTcpSelectClient.h"
#include "TcpClientSubscriberImpl.h"
#include "Logger.h"
#include "Config.h"


void TestTcpSelectClient()
{
    auto IP1 = "127.0.0.1";
    auto IP2 = "192.168.2.29";
    auto IP3 = "::1";
    auto IP4 = "fe80::59d8:5d6d:25cc:42cf%14";

    auto IP = "114.80.171.123";

    auto Port = "10000";

    TcpSelectClient tcpSelectClient;
    tcpSelectClient.SetSocketTimeOut(5000);
    
    TcpClientSubscriberImpl tcpClientSubscriberImpl(&tcpSelectClient);
    if (!tcpClientSubscriberImpl.Init())
    {
        return;
    }
    tcpClientSubscriberImpl.Start();

    //tcpSelectClient.Connect(IP, Port);
    //tcpSelectClient.Connect(IP1, Port);
    tcpSelectClient.Connect(Config::GetInstance().ConnectIP.c_str(), Config::GetInstance().ConnectPort.c_str());
    tcpSelectClient.Connect(Config::GetInstance().ConnectIP.c_str(), Config::GetInstance().ConnectPort.c_str());
    tcpSelectClient.Connect(Config::GetInstance().ConnectIP.c_str(), Config::GetInstance().ConnectPort.c_str());
    //tcpSelectClient.Connect(IP3, Port);
    //tcpSelectClient.Connect(IP4, Port);

    std::this_thread::sleep_for(std::chrono::seconds(5));
    tcpClientSubscriberImpl.Stop();
    tcpClientSubscriberImpl.Join();
}
