#include <iostream>
#include <set>
#include <string.h>
#include "Logger.h"
#include "TestTcpSelectClient.h"
#include "TestTcpIOCPClient.h"


using namespace std;


auto IP1 = "0.0.0.0";
auto IP2 = "127.0.0.1";
auto IP3 = "192.168.2.29";
auto IP4 = "::";
auto IP5 = "::0";
auto IP6 = "::1";
auto IP7 = "fe80::59d8:5d6d:25cc:42cf%14";

auto Port = "10000";

int main(int argc, const char* argv[])
{
    Logger::GetInstance().Init(argv[0]);
    Logger::GetInstance().Start();

    //TestTcpSelectClient(IP7, Port);
    TestTcpIOCPClient(IP7, Port);


    Logger::GetInstance().Stop();
    Logger::GetInstance().Join();

	return 0;
}
