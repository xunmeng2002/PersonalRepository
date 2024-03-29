#pragma warning(disable:4819)
#include "ThostFtdcTraderApiMiddle.h"
#include "ThostFtdcTraderSpiImpl.h"
#include "Logger.h"
#include "json/json.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <string.h>
#ifdef LINUX
#include <signal.h>
#endif // LINUX



using namespace std;

void PrintAccountInfo(AccountInfo* accountInfo)
{
	printf("AccountInfo: AccountType[%s], BrokerID[%s],  UserID[%s], Password[%s],  UserProductInfo[%s], AuthCode[%s],  AppID[%s]\nFrontAddrs",
		accountInfo->AccountType, accountInfo->BrokerID, accountInfo->UserID, accountInfo->Password, accountInfo->UserProductInfo, accountInfo->AuthCode, accountInfo->AppID);
	for (auto& FrontAddr : accountInfo->FrontAddrs)
	{
		printf("  [%s]", FrontAddr.c_str());
	}
	printf("\n\n");
}

void ReadAccountInfo(map<string, AccountInfo*>& accountInfos)
{
	Json::Reader reader;
	Json::FastWriter writer;
	Json::Value root;

	ifstream in_file("AccountInfo.json", ios::binary);
	cout << "parse: " << reader.parse(in_file, root) << endl;
	in_file.close();
	
	for (auto i = 0u; i < root.size(); i++)
	{
		AccountInfo* accountInfo = new AccountInfo();
		strcpy(accountInfo->AccountType, root[i]["AccountType"].asString().c_str());
		strcpy(accountInfo->BrokerID, root[i]["BrokerID"].asString().c_str());
		strcpy(accountInfo->UserID, root[i]["UserID"].asString().c_str());
		strcpy(accountInfo->Password, root[i]["Password"].asString().c_str());
		strcpy(accountInfo->UserProductInfo, root[i]["UserProductInfo"].asString().c_str());
		strcpy(accountInfo->AuthCode, root[i]["AuthCode"].asString().c_str());
		strcpy(accountInfo->AppID, root[i]["AppID"].asString().c_str());
		for (auto j = 0u; j < root[i]["FrontAddrs"].size(); j++)
		{
			accountInfo->FrontAddrs.insert(root[i]["FrontAddrs"][j].asString());
		}
		accountInfos.insert(make_pair(accountInfo->UserID, accountInfo));
	}
	for (auto& it : accountInfos)
	{
		PrintAccountInfo(it.second);
	}
}

#ifdef LINUX
void sigusr1_handler(int signo)
{
	printf("catch SIGUSR1\n");
	printf("back to main\n");
}
#endif // LINUX


int main()
{
	map<string, AccountInfo*> accountInfos;
	ReadAccountInfo(accountInfos);

	Logger::GetInstance().Init("CTPTraderApiTest");
	Logger::GetInstance().SetLogLevel(LogLevel::Info, LogLevel::Warning);
	Logger::GetInstance().Start();

	string userID = "132924";
	CThostFtdcTraderApi* traderApi = CThostFtdcTraderApiMiddle::CreateFtdcTraderApi();
	cout << "API Version:" << traderApi->GetApiVersion() << endl;
	CThostFtdcTraderSpiImpl* traderSpi = new CThostFtdcTraderSpiImpl(traderApi);
	traderSpi->SetAccountInfo(accountInfos[userID]);
	traderApi->RegisterSpi(traderSpi);
	for (auto& frontAddr : accountInfos[userID]->FrontAddrs)
	{
		traderApi->RegisterFront((char*)frontAddr.c_str());
	}
	traderApi->SubscribePrivateTopic(THOST_TE_RESUME_TYPE::THOST_TERT_RESTART);
	traderApi->SubscribePublicTopic(THOST_TE_RESUME_TYPE::THOST_TERT_RESTART);
	traderApi->Init();

#ifdef LINUX
	struct sigaction act;
	act.sa_handler = sigusr1_handler;
	act.sa_flags = SA_NODEFER;
	sigemptyset(&act.sa_mask);
	if (sigaction(SIGUSR1, &act, NULL) == -1)
	{
		perror("fail to set handler for SIGUSR1");
		exit(1);
	}
#endif // LINUX
	std::this_thread::sleep_for(std::chrono::seconds(30));

	traderApi->Release();
	//traderApi->Join();

	Logger::GetInstance().Stop();
	Logger::GetInstance().Join();
	return 0;
}


