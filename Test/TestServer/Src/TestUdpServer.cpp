#include "TestUdpServer.h"
#include "UdpServer.h"
#include "Config.h"
#include "Logger.h"
#include "Encode.h"
#include <iostream>
#include <fstream>

void TestUdpServer()
{
    auto IP1 = "127.0.0.1";
    auto IP2 = "192.168.2.29";
    auto IP3 = "::1";
    auto IP4 = "fe80::59d8:5d6d:25cc:42cf%14";
    auto IP = "114.80.171.123";
    auto Port = "10000";

    UdpServer udpServer;
    udpServer.SetBindAddressInfo(Config::GetInstance().ListenIP.c_str(), Config::GetInstance().ListenPort.c_str());
    udpServer.Init(true);

    for (auto i = 0; i < 5; i++)
    {
        TcpEvent* tcpEvent = TcpEvent::Allocate();
        udpServer.ZipRecvFrom(tcpEvent);

        printf("udpServer RecvFrom IP[%s], Port[%s], Len:[%d] Content:[%s]\n\n", tcpEvent->IP.c_str(), tcpEvent->Port.c_str(), tcpEvent->Length, tcpEvent->Buff);

        std::ofstream of("utf8.txt");
        of.imbue(std::locale(std::locale(""), new std::codecvt_utf8<wchar_t>));
        of << tcpEvent->Buff;
        of.close();

        auto ws = Encode::utf8_to_wstring(tcpEvent->Buff);
        std::wofstream wfo("ws.txt");
        wfo.imbue(std::locale("zh_CN"));
        wfo << ws;
        wfo.close();

        auto s = Encode::to_string(ws);
        std::ofstream of2("gbk.txt");
        of2.imbue(std::locale("zh_CN"));
        of2 << s;
        of2.close();


        WRITE_LOG(LogLevel::Info, "TcpEvent Buff:[%s]", tcpEvent->Buff);
        WRITE_LOG(LogLevel::Info, "wstring:[%ws]", ws.c_str());
        WRITE_LOG(LogLevel::Info, "GBK:[%s]", s.c_str());
    }
}
