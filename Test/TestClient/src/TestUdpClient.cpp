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
    std::string msg = "���գ��������ϵģ�΢��ٷ��ṩ�� System.IO.Compression �еķ������ٶ����������Ե����ƣ���Ȼ�����ṩDeflate��ͷβ��Ϣ����������취�Լ����ɣ�������һȱ��������ǿ�����ȫ���Եġ� Zlib.net ��Ȼ���ٶ��ϱ���Ҳ����ͬʱҲ������Deflateѹ����ͷβ��Ϣ������Ϊ���װ�Ƚ��ʲݣ�ʹ��������Բ����㡣�� SharpZipLib �ܿ�ϧ����Ȼ���������涼�ܷ��㣬���ٶ��ϵ�ȱ���൱������ֻ����һ����Ҫ Deflate ���� RawDeflate ����ʹ�õ�.Net Framework����4.5��ʱ����������ʱ�����Ĳ���Ҫ��͵������һ���ˡ�";
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
