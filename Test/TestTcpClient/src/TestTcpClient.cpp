#include <iostream>
#include <set>
#include <string.h>
#include "Logger.h"
#include "TestTcpSelectClient.h"
#include "TestTcpIOCPClient.h"


using namespace std;


int main(int argc, const char* argv[])
{
    Logger::GetInstance().Init(argv[0]);
    Logger::GetInstance().Start();

    //TestTcpSelectClient();
    TestTcpIOCPClient();


    Logger::GetInstance().Stop();
    Logger::GetInstance().Join();

	return 0;
}
