#include "TestUdpClient.h"
#include "UdpClient.h"
#include "Config.h"
#include <thread>
#include <string.h>

void TestUdpClient()
{
    auto IP1 = "127.0.0.1";
    auto IP2 = "192.168.2.29";
    auto IP3 = "::1";
    auto IP4 = "fe80::59d8:5d6d:25cc:42cf%14";
    auto IP = "114.80.171.123";
    auto Port = "10000";

    UdpClient udpClient;
    udpClient.SetRemoteAddress(Config::GetInstance().ConnectIP.c_str(), Config::GetInstance().ConnectPort.c_str());
    udpClient.Init(true);
    
    //std::string msg = "Hello World, From UdpClient!";
    std::string msg = "最终，不出所料的，微软官方提供的 System.IO.Compression 中的方法在速度上有着明显的优势；虽然不会提供Deflate的头尾信息，但可以想办法自己生成，而且这一缺点基本上是可以完全忽略的。 Zlib.net 虽然在速度上表现也不错，同时也会生成Deflate压缩的头尾信息，但因为其包装比较潦草，使用起来相对不方便。而 SharpZipLib 很可惜，虽然其他各方面都很方便，但速度上的缺陷相当致命，只能在一定需要 Deflate 而非 RawDeflate 或者使用的.Net Framework早于4.5的时候（且运行中时间消耗不重要）偷懒的用一用了。";
    for (auto i = 0; i < 5; i++)
    {
        TcpEvent* tcpEvent = TcpEvent::Allocate();
        tcpEvent->IP = Config::GetInstance().ConnectIP.c_str();
        tcpEvent->Port = Config::GetInstance().ConnectPort.c_str();
        ::memcpy(tcpEvent->Buff, msg.c_str(), msg.length());
        tcpEvent->Length = msg.length();
        tcpEvent->Buff[tcpEvent->Length] = '\0';
        udpClient.ZipSendTo(tcpEvent);

        std::this_thread::sleep_for(std::chrono::seconds(10));
    }
}
