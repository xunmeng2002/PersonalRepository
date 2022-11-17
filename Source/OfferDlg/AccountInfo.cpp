#pragma warning(disable: 4311 4302)
#include "pch.h"
#include "AccountInfo.h"


std::wstring AccountInfo::ToWstring()
{
	static wchar_t buff[1024];
	wsprintf(buff, L"%d-%s-%s-%s-%d-%d-%d-%d-%d-%d-%d-%s-%d ", SequenceNo, CompanyName.c_str(), AccountID.c_str(), AccountName.c_str(),
		Status, ReqOrderNum, ReqCancelNum, TradeNum, TradeVolume, RtnOrderNum, RtnTradeNum, ExchangeNotify.c_str(), LoginStatus);
	return std::wstring(buff);
}
bool AccountInfo::operator==(const AccountInfo& other)
{
	if (SequenceNo != other.SequenceNo || AccountID != other.AccountID || Status != other.Status || ReqOrderNum != other.ReqOrderNum || ReqCancelNum != other.ReqCancelNum || TradeNum != other.TradeNum
		|| TradeVolume != other.TradeVolume || RtnOrderNum != other.RtnOrderNum || RtnTradeNum != other.RtnTradeNum || ExchangeNotify != other.ExchangeNotify || LoginStatus != other.LoginStatus)
	{
		return false;
	}
	return true;
}

std::map<int, std::wstring> StatusText::MapValues = {
	{0, L"����"},
	{1, L"�쳣"},
};

std::map<int, std::wstring> LoginStatusText::MapValues = {
	{0, L"δ��¼"},
	{1, L"�ѵ�¼"},
	{2, L"��¼��"},
};
