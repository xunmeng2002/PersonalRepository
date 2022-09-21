#include "ThostFtdcTraderSpiImpl.h"
#include "Logger.h"
#include <string.h>


CThostFtdcTraderSpiImpl::CThostFtdcTraderSpiImpl(CThostFtdcTraderApi* traderApi)
	:m_TraderApi(traderApi), m_RequestID(0), m_AccountInfo(nullptr)
{
}
void CThostFtdcTraderSpiImpl::OnFrontConnected()
{
	CThostFtdcTraderSpiMiddle::OnFrontConnected();
	ReqAuthenticate();
}
void CThostFtdcTraderSpiImpl::OnFrontDisconnected(int nReason)
{
	CThostFtdcTraderSpiMiddle::OnFrontDisconnected(nReason);
}
void CThostFtdcTraderSpiImpl::OnRspAuthenticate(CThostFtdcRspAuthenticateField* pRspAuthenticateField, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	CThostFtdcTraderSpiMiddle::OnRspAuthenticate(pRspAuthenticateField, pRspInfo, nRequestID, bIsLast);
	ReqUserLogin();
}
void CThostFtdcTraderSpiImpl::OnRspUserLogin(CThostFtdcRspUserLoginField* pRspUserLogin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	CThostFtdcTraderSpiMiddle::OnRspUserLogin(pRspUserLogin, pRspInfo, nRequestID, bIsLast);
	ReqQryInstrument();
}
void CThostFtdcTraderSpiImpl::OnRspQryInstrument(CThostFtdcInstrumentField* pInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	CThostFtdcTraderSpiMiddle::OnRspQryInstrument(pInstrument, pRspInfo, nRequestID, bIsLast);
	if (bIsLast)
	{
		ReqQryTradingAccount();
	}
}
void CThostFtdcTraderSpiImpl::OnRspQryTradingAccount(CThostFtdcTradingAccountField* pTradingAccount, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	CThostFtdcTraderSpiMiddle::OnRspQryTradingAccount(pTradingAccount, pRspInfo, nRequestID, bIsLast);
	ReqQryInvestorPosition();
}
void CThostFtdcTraderSpiImpl::OnRspQryInvestorPosition(CThostFtdcInvestorPositionField* pInvestorPosition, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	CThostFtdcTraderSpiMiddle::OnRspQryInvestorPosition(pInvestorPosition, pRspInfo, nRequestID, bIsLast);
	if (bIsLast)
	{
		ReqQryOrder();
	}
}
void CThostFtdcTraderSpiImpl::OnRspQryOrder(CThostFtdcOrderField* pOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	CThostFtdcTraderSpiMiddle::OnRspQryOrder(pOrder, pRspInfo, nRequestID, bIsLast);
	if (bIsLast)
	{
		ReqQryTrade();
	}
}
void CThostFtdcTraderSpiImpl::OnRspQryTrade(CThostFtdcTradeField* pTrade, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	CThostFtdcTraderSpiMiddle::OnRspQryTrade(pTrade, pRspInfo, nRequestID, bIsLast);
	if (bIsLast)
	{
		
	}
}

void CThostFtdcTraderSpiImpl::SetAccountInfo(AccountInfo* accountInfo)
{
	m_AccountInfo = accountInfo;
}

void CThostFtdcTraderSpiImpl::ReqAuthenticate()
{
	CThostFtdcReqAuthenticateField authenticate;
	::memset(&authenticate, 0, sizeof(authenticate));
	strcpy(authenticate.BrokerID, m_AccountInfo->BrokerID);
	strcpy(authenticate.UserID, m_AccountInfo->UserID);
	strcpy(authenticate.UserProductInfo, m_AccountInfo->UserProductInfo);
	strcpy(authenticate.AuthCode, m_AccountInfo->AuthCode);
	strcpy(authenticate.AppID, m_AccountInfo->AppID);

	int ret = m_TraderApi->ReqAuthenticate(&authenticate, m_RequestID++);
	WRITE_LOG(LogLevel::Info, "ReqAuthenticate: ret[%d]", ret);
}
void CThostFtdcTraderSpiImpl::ReqUserLogin()
{
	CThostFtdcReqUserLoginField userLogin;
	::memset(&userLogin, 0, sizeof(userLogin));
	strcpy(userLogin.TradingDay, "");
	strcpy(userLogin.BrokerID, m_AccountInfo->BrokerID);
	strcpy(userLogin.UserID, m_AccountInfo->UserID);
	strcpy(userLogin.Password, m_AccountInfo->Password);
	strcpy(userLogin.UserProductInfo, m_AccountInfo->UserProductInfo);

	int ret = m_TraderApi->ReqUserLogin(&userLogin, m_RequestID++);
	WRITE_LOG(LogLevel::Info, "ReqUserLogin: ret[%d]", ret);
}
void CThostFtdcTraderSpiImpl::ReqQryInstrument()
{
	CThostFtdcQryInstrumentField qryInstrument;
	::memset(&qryInstrument, 0, sizeof(qryInstrument));
	int ret = m_TraderApi->ReqQryInstrument(&qryInstrument, m_RequestID++);
	WRITE_LOG(LogLevel::Info, "ReqQryInstrument: ret[%d]", ret);
}
void CThostFtdcTraderSpiImpl::ReqQryTradingAccount()
{
	CThostFtdcQryTradingAccountField qryTradingAccount;
	::memset(&qryTradingAccount, 0, sizeof(qryTradingAccount));
	int ret = m_TraderApi->ReqQryTradingAccount(&qryTradingAccount, m_RequestID++);
	WRITE_LOG(LogLevel::Info, "ReqQryTradingAccount: ret[%d]", ret);
}
void CThostFtdcTraderSpiImpl::ReqQryInvestorPosition()
{
	CThostFtdcQryInvestorPositionField qryInvestorPosition;
	::memset(&qryInvestorPosition, 0, sizeof(qryInvestorPosition));
	int ret = m_TraderApi->ReqQryInvestorPosition(&qryInvestorPosition, m_RequestID++);
	WRITE_LOG(LogLevel::Info, "ReqQryInvestorPosition: ret[%d]", ret);
}
void CThostFtdcTraderSpiImpl::ReqQryOrder()
{
	CThostFtdcQryOrderField qryOrder;
	::memset(&qryOrder, 0, sizeof(qryOrder));
	int ret = m_TraderApi->ReqQryOrder(&qryOrder, m_RequestID++);
	WRITE_LOG(LogLevel::Info, "ReqQryOrder: ret[%d]", ret);
}
void CThostFtdcTraderSpiImpl::ReqQryTrade()
{
	CThostFtdcQryTradeField qryTrade;
	::memset(&qryTrade, 0, sizeof(qryTrade));
	int ret = m_TraderApi->ReqQryTrade(&qryTrade, m_RequestID++);
	WRITE_LOG(LogLevel::Info, "ReqQryTrade: ret[%d]", ret);
}
