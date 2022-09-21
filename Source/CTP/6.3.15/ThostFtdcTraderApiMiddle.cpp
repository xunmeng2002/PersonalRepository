#include "ThostFtdcTraderApiMiddle.h"
#include "Logger.h"
#include "StructWriteLogFunc.h"



CThostFtdcTraderApi *CThostFtdcTraderApiMiddle::CreateFtdcTraderApi(const char *pszFlowPath)
{
	WRITE_LOG(LogLevel::Info, "CreateFtdcTraderApi: pszFlowPath[%s]", pszFlowPath);
	
	auto traderApi = CThostFtdcTraderApi::CreateFtdcTraderApi(pszFlowPath);
	auto apiMiddle = new CThostFtdcTraderApiMiddle();
	apiMiddle->m_TraderApi = traderApi;
	
	return apiMiddle;
}

const char *CThostFtdcTraderApiMiddle::GetApiVersion()
{
	WRITE_LOG(LogLevel::Info, "GetApiVersion:");
	
	return CThostFtdcTraderApi::GetApiVersion();
}

void CThostFtdcTraderApiMiddle::Release()
{
	WRITE_LOG(LogLevel::Info, "Release:");

	return m_TraderApi->Release();
}

void CThostFtdcTraderApiMiddle::Init()
{
	WRITE_LOG(LogLevel::Info, "Init:");

	return m_TraderApi->Init();
}

int CThostFtdcTraderApiMiddle::Join()
{
	WRITE_LOG(LogLevel::Info, "Join:");

	return m_TraderApi->Join();
}

const char * CThostFtdcTraderApiMiddle::GetTradingDay()
{
	WRITE_LOG(LogLevel::Info, "GetTradingDay:");

	return m_TraderApi->GetTradingDay();
}

void CThostFtdcTraderApiMiddle::RegisterFront(char * pszFrontAddress)
{
	WRITE_LOG(LogLevel::Info, "RegisterFront: pszFrontAddress[%s]", pszFrontAddress);

	return m_TraderApi->RegisterFront(pszFrontAddress);
}

void CThostFtdcTraderApiMiddle::RegisterNameServer(char * pszNsAddress)
{
	WRITE_LOG(LogLevel::Info, "RegisterNameServer: pszNsAddress[%s]", pszNsAddress);

	return m_TraderApi->RegisterNameServer(pszNsAddress);
}

void CThostFtdcTraderApiMiddle::RegisterFensUserInfo(CThostFtdcFensUserInfoField *pFensUserInfo)
{
	WRITE_LOG(LogLevel::Info, "RegisterFensUserInfo:");
	WriteFensUserInfo(pFensUserInfo);

	return m_TraderApi->RegisterFensUserInfo(pFensUserInfo);
}

void CThostFtdcTraderApiMiddle::RegisterSpi(CThostFtdcTraderSpi *pTraderSp)
{
	WRITE_LOG(LogLevel::Info, "RegisterSpi:");

	return m_TraderApi->RegisterSpi(pTraderSp);
}

void CThostFtdcTraderApiMiddle::SubscribePrivateTopic(THOST_TE_RESUME_TYPE nResumeType)
{
	WRITE_LOG(LogLevel::Info, "SubscribePrivateTopic: nResumeType[%d]", nResumeType);

	return m_TraderApi->SubscribePrivateTopic(nResumeType);
}

void CThostFtdcTraderApiMiddle::SubscribePublicTopic(THOST_TE_RESUME_TYPE nResumeType)
{
	WRITE_LOG(LogLevel::Info, "SubscribePublicTopic: nResumeType[%d]", nResumeType);

	return m_TraderApi->SubscribePublicTopic(nResumeType);
}

int CThostFtdcTraderApiMiddle::ReqAuthenticate(CThostFtdcReqAuthenticateField *pReqAuthenticate, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqAuthenticate: nRequestID[%d]", nRequestID);
	WriteReqAuthenticate(pReqAuthenticate);

	return m_TraderApi->ReqAuthenticate(pReqAuthenticate, nRequestID);
}

int CThostFtdcTraderApiMiddle::RegisterUserSystemInfo(CThostFtdcUserSystemInfoField *pUserSystemInfo)
{
	WRITE_LOG(LogLevel::Info, "RegisterUserSystemInfo:");
	WriteUserSystemInfo(pUserSystemInfo);

	return m_TraderApi->RegisterUserSystemInfo(pUserSystemInfo);
}

int CThostFtdcTraderApiMiddle::SubmitUserSystemInfo(CThostFtdcUserSystemInfoField *pUserSystemInfo)
{
	WRITE_LOG(LogLevel::Info, "SubmitUserSystemInfo:");
	WriteUserSystemInfo(pUserSystemInfo);

	return m_TraderApi->SubmitUserSystemInfo(pUserSystemInfo);
}

int CThostFtdcTraderApiMiddle::ReqUserLogin(CThostFtdcReqUserLoginField *pReqUserLogin, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqUserLogin: nRequestID[%d]", nRequestID);
	WriteReqUserLogin(pReqUserLogin);

	return m_TraderApi->ReqUserLogin(pReqUserLogin, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqUserLogout(CThostFtdcUserLogoutField *pUserLogout, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqUserLogout: nRequestID[%d]", nRequestID);
	WriteUserLogout(pUserLogout);

	return m_TraderApi->ReqUserLogout(pUserLogout, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqUserPasswordUpdate(CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqUserPasswordUpdate: nRequestID[%d]", nRequestID);
	WriteUserPasswordUpdate(pUserPasswordUpdate);

	return m_TraderApi->ReqUserPasswordUpdate(pUserPasswordUpdate, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqTradingAccountPasswordUpdate: nRequestID[%d]", nRequestID);
	WriteTradingAccountPasswordUpdate(pTradingAccountPasswordUpdate);

	return m_TraderApi->ReqTradingAccountPasswordUpdate(pTradingAccountPasswordUpdate, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqUserAuthMethod(CThostFtdcReqUserAuthMethodField *pReqUserAuthMethod, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqUserAuthMethod: nRequestID[%d]", nRequestID);
	WriteReqUserAuthMethod(pReqUserAuthMethod);

	return m_TraderApi->ReqUserAuthMethod(pReqUserAuthMethod, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqGenUserCaptcha(CThostFtdcReqGenUserCaptchaField *pReqGenUserCaptcha, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqGenUserCaptcha: nRequestID[%d]", nRequestID);
	WriteReqGenUserCaptcha(pReqGenUserCaptcha);

	return m_TraderApi->ReqGenUserCaptcha(pReqGenUserCaptcha, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqGenUserText(CThostFtdcReqGenUserTextField *pReqGenUserText, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqGenUserText: nRequestID[%d]", nRequestID);
	WriteReqGenUserText(pReqGenUserText);

	return m_TraderApi->ReqGenUserText(pReqGenUserText, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqUserLoginWithCaptcha(CThostFtdcReqUserLoginWithCaptchaField *pReqUserLoginWithCaptcha, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqUserLoginWithCaptcha: nRequestID[%d]", nRequestID);
	WriteReqUserLoginWithCaptcha(pReqUserLoginWithCaptcha);

	return m_TraderApi->ReqUserLoginWithCaptcha(pReqUserLoginWithCaptcha, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqUserLoginWithText(CThostFtdcReqUserLoginWithTextField *pReqUserLoginWithText, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqUserLoginWithText: nRequestID[%d]", nRequestID);
	WriteReqUserLoginWithText(pReqUserLoginWithText);

	return m_TraderApi->ReqUserLoginWithText(pReqUserLoginWithText, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqUserLoginWithOTP(CThostFtdcReqUserLoginWithOTPField *pReqUserLoginWithOTP, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqUserLoginWithOTP: nRequestID[%d]", nRequestID);
	WriteReqUserLoginWithOTP(pReqUserLoginWithOTP);

	return m_TraderApi->ReqUserLoginWithOTP(pReqUserLoginWithOTP, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqOrderInsert(CThostFtdcInputOrderField *pInputOrder, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqOrderInsert: nRequestID[%d]", nRequestID);
	WriteInputOrder(pInputOrder);

	return m_TraderApi->ReqOrderInsert(pInputOrder, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqParkedOrderInsert(CThostFtdcParkedOrderField *pParkedOrder, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqParkedOrderInsert: nRequestID[%d]", nRequestID);
	WriteParkedOrder(pParkedOrder);

	return m_TraderApi->ReqParkedOrderInsert(pParkedOrder, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqParkedOrderAction: nRequestID[%d]", nRequestID);
	WriteParkedOrderAction(pParkedOrderAction);

	return m_TraderApi->ReqParkedOrderAction(pParkedOrderAction, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqOrderAction: nRequestID[%d]", nRequestID);
	WriteInputOrderAction(pInputOrderAction);

	return m_TraderApi->ReqOrderAction(pInputOrderAction, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQueryMaxOrderVolume(CThostFtdcQueryMaxOrderVolumeField *pQueryMaxOrderVolume, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQueryMaxOrderVolume: nRequestID[%d]", nRequestID);
	WriteQueryMaxOrderVolume(pQueryMaxOrderVolume);

	return m_TraderApi->ReqQueryMaxOrderVolume(pQueryMaxOrderVolume, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqSettlementInfoConfirm: nRequestID[%d]", nRequestID);
	WriteSettlementInfoConfirm(pSettlementInfoConfirm);

	return m_TraderApi->ReqSettlementInfoConfirm(pSettlementInfoConfirm, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqRemoveParkedOrder(CThostFtdcRemoveParkedOrderField *pRemoveParkedOrder, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqRemoveParkedOrder: nRequestID[%d]", nRequestID);
	WriteRemoveParkedOrder(pRemoveParkedOrder);

	return m_TraderApi->ReqRemoveParkedOrder(pRemoveParkedOrder, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField *pRemoveParkedOrderAction, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqRemoveParkedOrderAction: nRequestID[%d]", nRequestID);
	WriteRemoveParkedOrderAction(pRemoveParkedOrderAction);

	return m_TraderApi->ReqRemoveParkedOrderAction(pRemoveParkedOrderAction, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqExecOrderInsert(CThostFtdcInputExecOrderField *pInputExecOrder, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqExecOrderInsert: nRequestID[%d]", nRequestID);
	WriteInputExecOrder(pInputExecOrder);

	return m_TraderApi->ReqExecOrderInsert(pInputExecOrder, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqExecOrderAction(CThostFtdcInputExecOrderActionField *pInputExecOrderAction, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqExecOrderAction: nRequestID[%d]", nRequestID);
	WriteInputExecOrderAction(pInputExecOrderAction);

	return m_TraderApi->ReqExecOrderAction(pInputExecOrderAction, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqForQuoteInsert: nRequestID[%d]", nRequestID);
	WriteInputForQuote(pInputForQuote);

	return m_TraderApi->ReqForQuoteInsert(pInputForQuote, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQuoteInsert(CThostFtdcInputQuoteField *pInputQuote, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQuoteInsert: nRequestID[%d]", nRequestID);
	WriteInputQuote(pInputQuote);

	return m_TraderApi->ReqQuoteInsert(pInputQuote, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQuoteAction(CThostFtdcInputQuoteActionField *pInputQuoteAction, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQuoteAction: nRequestID[%d]", nRequestID);
	WriteInputQuoteAction(pInputQuoteAction);

	return m_TraderApi->ReqQuoteAction(pInputQuoteAction, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqBatchOrderAction(CThostFtdcInputBatchOrderActionField *pInputBatchOrderAction, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqBatchOrderAction: nRequestID[%d]", nRequestID);
	WriteInputBatchOrderAction(pInputBatchOrderAction);

	return m_TraderApi->ReqBatchOrderAction(pInputBatchOrderAction, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField *pInputOptionSelfClose, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqOptionSelfCloseInsert: nRequestID[%d]", nRequestID);
	WriteInputOptionSelfClose(pInputOptionSelfClose);

	return m_TraderApi->ReqOptionSelfCloseInsert(pInputOptionSelfClose, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqOptionSelfCloseAction(CThostFtdcInputOptionSelfCloseActionField *pInputOptionSelfCloseAction, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqOptionSelfCloseAction: nRequestID[%d]", nRequestID);
	WriteInputOptionSelfCloseAction(pInputOptionSelfCloseAction);

	return m_TraderApi->ReqOptionSelfCloseAction(pInputOptionSelfCloseAction, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqCombActionInsert(CThostFtdcInputCombActionField *pInputCombAction, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqCombActionInsert: nRequestID[%d]", nRequestID);
	WriteInputCombAction(pInputCombAction);

	return m_TraderApi->ReqCombActionInsert(pInputCombAction, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryOrder(CThostFtdcQryOrderField *pQryOrder, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryOrder: nRequestID[%d]", nRequestID);
	WriteQryOrder(pQryOrder);

	return m_TraderApi->ReqQryOrder(pQryOrder, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryTrade(CThostFtdcQryTradeField *pQryTrade, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryTrade: nRequestID[%d]", nRequestID);
	WriteQryTrade(pQryTrade);

	return m_TraderApi->ReqQryTrade(pQryTrade, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryInvestorPosition(CThostFtdcQryInvestorPositionField *pQryInvestorPosition, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryInvestorPosition: nRequestID[%d]", nRequestID);
	WriteQryInvestorPosition(pQryInvestorPosition);

	return m_TraderApi->ReqQryInvestorPosition(pQryInvestorPosition, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryTradingAccount(CThostFtdcQryTradingAccountField *pQryTradingAccount, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryTradingAccount: nRequestID[%d]", nRequestID);
	WriteQryTradingAccount(pQryTradingAccount);

	return m_TraderApi->ReqQryTradingAccount(pQryTradingAccount, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryInvestor(CThostFtdcQryInvestorField *pQryInvestor, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryInvestor: nRequestID[%d]", nRequestID);
	WriteQryInvestor(pQryInvestor);

	return m_TraderApi->ReqQryInvestor(pQryInvestor, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryTradingCode(CThostFtdcQryTradingCodeField *pQryTradingCode, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryTradingCode: nRequestID[%d]", nRequestID);
	WriteQryTradingCode(pQryTradingCode);

	return m_TraderApi->ReqQryTradingCode(pQryTradingCode, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryInstrumentMarginRate(CThostFtdcQryInstrumentMarginRateField *pQryInstrumentMarginRate, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryInstrumentMarginRate: nRequestID[%d]", nRequestID);
	WriteQryInstrumentMarginRate(pQryInstrumentMarginRate);

	return m_TraderApi->ReqQryInstrumentMarginRate(pQryInstrumentMarginRate, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryInstrumentCommissionRate(CThostFtdcQryInstrumentCommissionRateField *pQryInstrumentCommissionRate, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryInstrumentCommissionRate: nRequestID[%d]", nRequestID);
	WriteQryInstrumentCommissionRate(pQryInstrumentCommissionRate);

	return m_TraderApi->ReqQryInstrumentCommissionRate(pQryInstrumentCommissionRate, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryExchange(CThostFtdcQryExchangeField *pQryExchange, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryExchange: nRequestID[%d]", nRequestID);
	WriteQryExchange(pQryExchange);

	return m_TraderApi->ReqQryExchange(pQryExchange, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryProduct(CThostFtdcQryProductField *pQryProduct, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryProduct: nRequestID[%d]", nRequestID);
	WriteQryProduct(pQryProduct);

	return m_TraderApi->ReqQryProduct(pQryProduct, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryInstrument(CThostFtdcQryInstrumentField *pQryInstrument, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryInstrument: nRequestID[%d]", nRequestID);
	WriteQryInstrument(pQryInstrument);

	return m_TraderApi->ReqQryInstrument(pQryInstrument, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryDepthMarketData(CThostFtdcQryDepthMarketDataField *pQryDepthMarketData, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryDepthMarketData: nRequestID[%d]", nRequestID);
	WriteQryDepthMarketData(pQryDepthMarketData);

	return m_TraderApi->ReqQryDepthMarketData(pQryDepthMarketData, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQrySettlementInfo(CThostFtdcQrySettlementInfoField *pQrySettlementInfo, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQrySettlementInfo: nRequestID[%d]", nRequestID);
	WriteQrySettlementInfo(pQrySettlementInfo);

	return m_TraderApi->ReqQrySettlementInfo(pQrySettlementInfo, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryTransferBank(CThostFtdcQryTransferBankField *pQryTransferBank, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryTransferBank: nRequestID[%d]", nRequestID);
	WriteQryTransferBank(pQryTransferBank);

	return m_TraderApi->ReqQryTransferBank(pQryTransferBank, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryInvestorPositionDetail(CThostFtdcQryInvestorPositionDetailField *pQryInvestorPositionDetail, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryInvestorPositionDetail: nRequestID[%d]", nRequestID);
	WriteQryInvestorPositionDetail(pQryInvestorPositionDetail);

	return m_TraderApi->ReqQryInvestorPositionDetail(pQryInvestorPositionDetail, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryNotice(CThostFtdcQryNoticeField *pQryNotice, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryNotice: nRequestID[%d]", nRequestID);
	WriteQryNotice(pQryNotice);

	return m_TraderApi->ReqQryNotice(pQryNotice, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQrySettlementInfoConfirm(CThostFtdcQrySettlementInfoConfirmField *pQrySettlementInfoConfirm, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQrySettlementInfoConfirm: nRequestID[%d]", nRequestID);
	WriteQrySettlementInfoConfirm(pQrySettlementInfoConfirm);

	return m_TraderApi->ReqQrySettlementInfoConfirm(pQrySettlementInfoConfirm, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryInvestorPositionCombineDetail(CThostFtdcQryInvestorPositionCombineDetailField *pQryInvestorPositionCombineDetail, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryInvestorPositionCombineDetail: nRequestID[%d]", nRequestID);
	WriteQryInvestorPositionCombineDetail(pQryInvestorPositionCombineDetail);

	return m_TraderApi->ReqQryInvestorPositionCombineDetail(pQryInvestorPositionCombineDetail, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryCFMMCTradingAccountKey(CThostFtdcQryCFMMCTradingAccountKeyField *pQryCFMMCTradingAccountKey, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryCFMMCTradingAccountKey: nRequestID[%d]", nRequestID);
	WriteQryCFMMCTradingAccountKey(pQryCFMMCTradingAccountKey);

	return m_TraderApi->ReqQryCFMMCTradingAccountKey(pQryCFMMCTradingAccountKey, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryEWarrantOffset(CThostFtdcQryEWarrantOffsetField *pQryEWarrantOffset, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryEWarrantOffset: nRequestID[%d]", nRequestID);
	WriteQryEWarrantOffset(pQryEWarrantOffset);

	return m_TraderApi->ReqQryEWarrantOffset(pQryEWarrantOffset, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryInvestorProductGroupMargin(CThostFtdcQryInvestorProductGroupMarginField *pQryInvestorProductGroupMargin, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryInvestorProductGroupMargin: nRequestID[%d]", nRequestID);
	WriteQryInvestorProductGroupMargin(pQryInvestorProductGroupMargin);

	return m_TraderApi->ReqQryInvestorProductGroupMargin(pQryInvestorProductGroupMargin, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryExchangeMarginRate(CThostFtdcQryExchangeMarginRateField *pQryExchangeMarginRate, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryExchangeMarginRate: nRequestID[%d]", nRequestID);
	WriteQryExchangeMarginRate(pQryExchangeMarginRate);

	return m_TraderApi->ReqQryExchangeMarginRate(pQryExchangeMarginRate, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryExchangeMarginRateAdjust(CThostFtdcQryExchangeMarginRateAdjustField *pQryExchangeMarginRateAdjust, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryExchangeMarginRateAdjust: nRequestID[%d]", nRequestID);
	WriteQryExchangeMarginRateAdjust(pQryExchangeMarginRateAdjust);

	return m_TraderApi->ReqQryExchangeMarginRateAdjust(pQryExchangeMarginRateAdjust, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryExchangeRate(CThostFtdcQryExchangeRateField *pQryExchangeRate, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryExchangeRate: nRequestID[%d]", nRequestID);
	WriteQryExchangeRate(pQryExchangeRate);

	return m_TraderApi->ReqQryExchangeRate(pQryExchangeRate, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQrySecAgentACIDMap(CThostFtdcQrySecAgentACIDMapField *pQrySecAgentACIDMap, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQrySecAgentACIDMap: nRequestID[%d]", nRequestID);
	WriteQrySecAgentACIDMap(pQrySecAgentACIDMap);

	return m_TraderApi->ReqQrySecAgentACIDMap(pQrySecAgentACIDMap, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryProductExchRate(CThostFtdcQryProductExchRateField *pQryProductExchRate, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryProductExchRate: nRequestID[%d]", nRequestID);
	WriteQryProductExchRate(pQryProductExchRate);

	return m_TraderApi->ReqQryProductExchRate(pQryProductExchRate, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryProductGroup(CThostFtdcQryProductGroupField *pQryProductGroup, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryProductGroup: nRequestID[%d]", nRequestID);
	WriteQryProductGroup(pQryProductGroup);

	return m_TraderApi->ReqQryProductGroup(pQryProductGroup, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryMMInstrumentCommissionRate(CThostFtdcQryMMInstrumentCommissionRateField *pQryMMInstrumentCommissionRate, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryMMInstrumentCommissionRate: nRequestID[%d]", nRequestID);
	WriteQryMMInstrumentCommissionRate(pQryMMInstrumentCommissionRate);

	return m_TraderApi->ReqQryMMInstrumentCommissionRate(pQryMMInstrumentCommissionRate, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryMMOptionInstrCommRate(CThostFtdcQryMMOptionInstrCommRateField *pQryMMOptionInstrCommRate, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryMMOptionInstrCommRate: nRequestID[%d]", nRequestID);
	WriteQryMMOptionInstrCommRate(pQryMMOptionInstrCommRate);

	return m_TraderApi->ReqQryMMOptionInstrCommRate(pQryMMOptionInstrCommRate, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryInstrumentOrderCommRate(CThostFtdcQryInstrumentOrderCommRateField *pQryInstrumentOrderCommRate, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryInstrumentOrderCommRate: nRequestID[%d]", nRequestID);
	WriteQryInstrumentOrderCommRate(pQryInstrumentOrderCommRate);

	return m_TraderApi->ReqQryInstrumentOrderCommRate(pQryInstrumentOrderCommRate, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQrySecAgentTradingAccount(CThostFtdcQryTradingAccountField *pQryTradingAccount, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQrySecAgentTradingAccount: nRequestID[%d]", nRequestID);
	WriteQryTradingAccount(pQryTradingAccount);

	return m_TraderApi->ReqQrySecAgentTradingAccount(pQryTradingAccount, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQrySecAgentCheckMode(CThostFtdcQrySecAgentCheckModeField *pQrySecAgentCheckMode, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQrySecAgentCheckMode: nRequestID[%d]", nRequestID);
	WriteQrySecAgentCheckMode(pQrySecAgentCheckMode);

	return m_TraderApi->ReqQrySecAgentCheckMode(pQrySecAgentCheckMode, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQrySecAgentTradeInfo(CThostFtdcQrySecAgentTradeInfoField *pQrySecAgentTradeInfo, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQrySecAgentTradeInfo: nRequestID[%d]", nRequestID);
	WriteQrySecAgentTradeInfo(pQrySecAgentTradeInfo);

	return m_TraderApi->ReqQrySecAgentTradeInfo(pQrySecAgentTradeInfo, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryOptionInstrTradeCost(CThostFtdcQryOptionInstrTradeCostField *pQryOptionInstrTradeCost, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryOptionInstrTradeCost: nRequestID[%d]", nRequestID);
	WriteQryOptionInstrTradeCost(pQryOptionInstrTradeCost);

	return m_TraderApi->ReqQryOptionInstrTradeCost(pQryOptionInstrTradeCost, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryOptionInstrCommRate(CThostFtdcQryOptionInstrCommRateField *pQryOptionInstrCommRate, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryOptionInstrCommRate: nRequestID[%d]", nRequestID);
	WriteQryOptionInstrCommRate(pQryOptionInstrCommRate);

	return m_TraderApi->ReqQryOptionInstrCommRate(pQryOptionInstrCommRate, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryExecOrder(CThostFtdcQryExecOrderField *pQryExecOrder, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryExecOrder: nRequestID[%d]", nRequestID);
	WriteQryExecOrder(pQryExecOrder);

	return m_TraderApi->ReqQryExecOrder(pQryExecOrder, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryForQuote(CThostFtdcQryForQuoteField *pQryForQuote, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryForQuote: nRequestID[%d]", nRequestID);
	WriteQryForQuote(pQryForQuote);

	return m_TraderApi->ReqQryForQuote(pQryForQuote, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryQuote(CThostFtdcQryQuoteField *pQryQuote, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryQuote: nRequestID[%d]", nRequestID);
	WriteQryQuote(pQryQuote);

	return m_TraderApi->ReqQryQuote(pQryQuote, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryOptionSelfClose(CThostFtdcQryOptionSelfCloseField *pQryOptionSelfClose, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryOptionSelfClose: nRequestID[%d]", nRequestID);
	WriteQryOptionSelfClose(pQryOptionSelfClose);

	return m_TraderApi->ReqQryOptionSelfClose(pQryOptionSelfClose, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryInvestUnit(CThostFtdcQryInvestUnitField *pQryInvestUnit, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryInvestUnit: nRequestID[%d]", nRequestID);
	WriteQryInvestUnit(pQryInvestUnit);

	return m_TraderApi->ReqQryInvestUnit(pQryInvestUnit, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryCombInstrumentGuard(CThostFtdcQryCombInstrumentGuardField *pQryCombInstrumentGuard, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryCombInstrumentGuard: nRequestID[%d]", nRequestID);
	WriteQryCombInstrumentGuard(pQryCombInstrumentGuard);

	return m_TraderApi->ReqQryCombInstrumentGuard(pQryCombInstrumentGuard, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryCombAction(CThostFtdcQryCombActionField *pQryCombAction, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryCombAction: nRequestID[%d]", nRequestID);
	WriteQryCombAction(pQryCombAction);

	return m_TraderApi->ReqQryCombAction(pQryCombAction, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryTransferSerial(CThostFtdcQryTransferSerialField *pQryTransferSerial, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryTransferSerial: nRequestID[%d]", nRequestID);
	WriteQryTransferSerial(pQryTransferSerial);

	return m_TraderApi->ReqQryTransferSerial(pQryTransferSerial, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryAccountregister(CThostFtdcQryAccountregisterField *pQryAccountregister, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryAccountregister: nRequestID[%d]", nRequestID);
	WriteQryAccountregister(pQryAccountregister);

	return m_TraderApi->ReqQryAccountregister(pQryAccountregister, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryContractBank(CThostFtdcQryContractBankField *pQryContractBank, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryContractBank: nRequestID[%d]", nRequestID);
	WriteQryContractBank(pQryContractBank);

	return m_TraderApi->ReqQryContractBank(pQryContractBank, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryParkedOrder(CThostFtdcQryParkedOrderField *pQryParkedOrder, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryParkedOrder: nRequestID[%d]", nRequestID);
	WriteQryParkedOrder(pQryParkedOrder);

	return m_TraderApi->ReqQryParkedOrder(pQryParkedOrder, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryParkedOrderAction(CThostFtdcQryParkedOrderActionField *pQryParkedOrderAction, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryParkedOrderAction: nRequestID[%d]", nRequestID);
	WriteQryParkedOrderAction(pQryParkedOrderAction);

	return m_TraderApi->ReqQryParkedOrderAction(pQryParkedOrderAction, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryTradingNotice(CThostFtdcQryTradingNoticeField *pQryTradingNotice, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryTradingNotice: nRequestID[%d]", nRequestID);
	WriteQryTradingNotice(pQryTradingNotice);

	return m_TraderApi->ReqQryTradingNotice(pQryTradingNotice, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryBrokerTradingParams(CThostFtdcQryBrokerTradingParamsField *pQryBrokerTradingParams, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryBrokerTradingParams: nRequestID[%d]", nRequestID);
	WriteQryBrokerTradingParams(pQryBrokerTradingParams);

	return m_TraderApi->ReqQryBrokerTradingParams(pQryBrokerTradingParams, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryBrokerTradingAlgos(CThostFtdcQryBrokerTradingAlgosField *pQryBrokerTradingAlgos, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryBrokerTradingAlgos: nRequestID[%d]", nRequestID);
	WriteQryBrokerTradingAlgos(pQryBrokerTradingAlgos);

	return m_TraderApi->ReqQryBrokerTradingAlgos(pQryBrokerTradingAlgos, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQueryCFMMCTradingAccountToken(CThostFtdcQueryCFMMCTradingAccountTokenField *pQueryCFMMCTradingAccountToken, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQueryCFMMCTradingAccountToken: nRequestID[%d]", nRequestID);
	WriteQueryCFMMCTradingAccountToken(pQueryCFMMCTradingAccountToken);

	return m_TraderApi->ReqQueryCFMMCTradingAccountToken(pQueryCFMMCTradingAccountToken, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqFromBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqFromBankToFutureByFuture: nRequestID[%d]", nRequestID);
	WriteReqTransfer(pReqTransfer);

	return m_TraderApi->ReqFromBankToFutureByFuture(pReqTransfer, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqFromFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqFromFutureToBankByFuture: nRequestID[%d]", nRequestID);
	WriteReqTransfer(pReqTransfer);

	return m_TraderApi->ReqFromFutureToBankByFuture(pReqTransfer, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQueryBankAccountMoneyByFuture: nRequestID[%d]", nRequestID);
	WriteReqQueryAccount(pReqQueryAccount);

	return m_TraderApi->ReqQueryBankAccountMoneyByFuture(pReqQueryAccount, nRequestID);
}

