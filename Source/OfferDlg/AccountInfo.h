#pragma once
#include <string>
#include <map>

struct AccountInfo
{
	int SequenceNo = 0;
	std::wstring CompanyName = L"";
	std::wstring AccountID = L"";
	std::wstring AccountName = L"";
	int Status = 0;
	int ReqOrderNum = 0;
	int ReqCancelNum = 0;
	int TradeNum = 0;
	int TradeVolume = 0;
	int RtnOrderNum = 0;
	int RtnTradeNum = 0;
	std::wstring ExchangeNotify = L"";
	int LoginStatus = 0;

	std::wstring ToWstring();
	bool operator==(const AccountInfo& other);
};

class StatusText
{
public:
	static std::map<int, std::wstring> MapValues;
};
class LoginStatusText
{
public:
	static std::map<int, std::wstring> MapValues;
};