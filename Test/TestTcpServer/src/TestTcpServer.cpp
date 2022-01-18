#include <iostream>
#include <set>
#include <string.h>
#include "TestTcpSelectServer.h"
#include "TestTcpIOCPServer.h"
#include "Logger.h"


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

    //TestTcpSelectServer(IP4, Port);
    TestTcpIOCPServer(IP4, Port);

    Logger::GetInstance().Join();
    Logger::GetInstance().Join();
	return 0;
}
