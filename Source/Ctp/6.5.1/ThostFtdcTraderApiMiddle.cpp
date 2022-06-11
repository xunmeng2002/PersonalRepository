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

void CThostFtdcTraderApiMiddle::RegisterFensUserInfo(CThostFtdcFensUserInfoField *FensUserInfo)
{
	WRITE_LOG(LogLevel::Info, "RegisterFensUserInfo:");
	WriteFensUserInfo(FensUserInfo);

	return m_TraderApi->RegisterFensUserInfo(FensUserInfo);
}

void CThostFtdcTraderApiMiddle::RegisterSpi(CThostFtdcTraderSpi *TraderSp)
{
	WRITE_LOG(LogLevel::Info, "RegisterSpi:");

	return m_TraderApi->RegisterSpi(TraderSp);
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

int CThostFtdcTraderApiMiddle::ReqAuthenticate(CThostFtdcReqAuthenticateField *ReqAuthenticate, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqAuthenticate: nRequestID[%d]", nRequestID);
	WriteReqAuthenticate(ReqAuthenticate);

	return m_TraderApi->ReqAuthenticate(ReqAuthenticate, nRequestID);
}

int CThostFtdcTraderApiMiddle::RegisterUserSystemInfo(CThostFtdcUserSystemInfoField *UserSystemInfo)
{
	WRITE_LOG(LogLevel::Info, "RegisterUserSystemInfo:");
	WriteUserSystemInfo(UserSystemInfo);

	return m_TraderApi->RegisterUserSystemInfo(UserSystemInfo);
}

int CThostFtdcTraderApiMiddle::SubmitUserSystemInfo(CThostFtdcUserSystemInfoField *UserSystemInfo)
{
	WRITE_LOG(LogLevel::Info, "SubmitUserSystemInfo:");
	WriteUserSystemInfo(UserSystemInfo);

	return m_TraderApi->SubmitUserSystemInfo(UserSystemInfo);
}

int CThostFtdcTraderApiMiddle::ReqUserLogin(CThostFtdcReqUserLoginField *ReqUserLogin, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqUserLogin: nRequestID[%d]", nRequestID);
	WriteReqUserLogin(ReqUserLogin);

	return m_TraderApi->ReqUserLogin(ReqUserLogin, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqUserLogout(CThostFtdcUserLogoutField *UserLogout, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqUserLogout: nRequestID[%d]", nRequestID);
	WriteUserLogout(UserLogout);

	return m_TraderApi->ReqUserLogout(UserLogout, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqUserPasswordUpdate(CThostFtdcUserPasswordUpdateField *UserPasswordUpdate, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqUserPasswordUpdate: nRequestID[%d]", nRequestID);
	WriteUserPasswordUpdate(UserPasswordUpdate);

	return m_TraderApi->ReqUserPasswordUpdate(UserPasswordUpdate, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField *TradingAccountPasswordUpdate, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqTradingAccountPasswordUpdate: nRequestID[%d]", nRequestID);
	WriteTradingAccountPasswordUpdate(TradingAccountPasswordUpdate);

	return m_TraderApi->ReqTradingAccountPasswordUpdate(TradingAccountPasswordUpdate, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqUserAuthMethod(CThostFtdcReqUserAuthMethodField *ReqUserAuthMethod, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqUserAuthMethod: nRequestID[%d]", nRequestID);
	WriteReqUserAuthMethod(ReqUserAuthMethod);

	return m_TraderApi->ReqUserAuthMethod(ReqUserAuthMethod, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqGenUserCaptcha(CThostFtdcReqGenUserCaptchaField *ReqGenUserCaptcha, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqGenUserCaptcha: nRequestID[%d]", nRequestID);
	WriteReqGenUserCaptcha(ReqGenUserCaptcha);

	return m_TraderApi->ReqGenUserCaptcha(ReqGenUserCaptcha, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqGenUserText(CThostFtdcReqGenUserTextField *ReqGenUserText, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqGenUserText: nRequestID[%d]", nRequestID);
	WriteReqGenUserText(ReqGenUserText);

	return m_TraderApi->ReqGenUserText(ReqGenUserText, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqUserLoginWithCaptcha(CThostFtdcReqUserLoginWithCaptchaField *ReqUserLoginWithCaptcha, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqUserLoginWithCaptcha: nRequestID[%d]", nRequestID);
	WriteReqUserLoginWithCaptcha(ReqUserLoginWithCaptcha);

	return m_TraderApi->ReqUserLoginWithCaptcha(ReqUserLoginWithCaptcha, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqUserLoginWithText(CThostFtdcReqUserLoginWithTextField *ReqUserLoginWithText, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqUserLoginWithText: nRequestID[%d]", nRequestID);
	WriteReqUserLoginWithText(ReqUserLoginWithText);

	return m_TraderApi->ReqUserLoginWithText(ReqUserLoginWithText, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqUserLoginWithOTP(CThostFtdcReqUserLoginWithOTPField *ReqUserLoginWithOTP, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqUserLoginWithOTP: nRequestID[%d]", nRequestID);
	WriteReqUserLoginWithOTP(ReqUserLoginWithOTP);

	return m_TraderApi->ReqUserLoginWithOTP(ReqUserLoginWithOTP, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqOrderInsert(CThostFtdcInputOrderField *InputOrder, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqOrderInsert: nRequestID[%d]", nRequestID);
	WriteInputOrder(InputOrder);

	return m_TraderApi->ReqOrderInsert(InputOrder, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqParkedOrderInsert(CThostFtdcParkedOrderField *ParkedOrder, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqParkedOrderInsert: nRequestID[%d]", nRequestID);
	WriteParkedOrder(ParkedOrder);

	return m_TraderApi->ReqParkedOrderInsert(ParkedOrder, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqParkedOrderAction(CThostFtdcParkedOrderActionField *ParkedOrderAction, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqParkedOrderAction: nRequestID[%d]", nRequestID);
	WriteParkedOrderAction(ParkedOrderAction);

	return m_TraderApi->ReqParkedOrderAction(ParkedOrderAction, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqOrderAction(CThostFtdcInputOrderActionField *InputOrderAction, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqOrderAction: nRequestID[%d]", nRequestID);
	WriteInputOrderAction(InputOrderAction);

	return m_TraderApi->ReqOrderAction(InputOrderAction, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryMaxOrderVolume(CThostFtdcQryMaxOrderVolumeField *QryMaxOrderVolume, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryMaxOrderVolume: nRequestID[%d]", nRequestID);
	WriteQryMaxOrderVolume(QryMaxOrderVolume);

	return m_TraderApi->ReqQryMaxOrderVolume(QryMaxOrderVolume, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *SettlementInfoConfirm, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqSettlementInfoConfirm: nRequestID[%d]", nRequestID);
	WriteSettlementInfoConfirm(SettlementInfoConfirm);

	return m_TraderApi->ReqSettlementInfoConfirm(SettlementInfoConfirm, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqRemoveParkedOrder(CThostFtdcRemoveParkedOrderField *RemoveParkedOrder, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqRemoveParkedOrder: nRequestID[%d]", nRequestID);
	WriteRemoveParkedOrder(RemoveParkedOrder);

	return m_TraderApi->ReqRemoveParkedOrder(RemoveParkedOrder, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField *RemoveParkedOrderAction, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqRemoveParkedOrderAction: nRequestID[%d]", nRequestID);
	WriteRemoveParkedOrderAction(RemoveParkedOrderAction);

	return m_TraderApi->ReqRemoveParkedOrderAction(RemoveParkedOrderAction, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqExecOrderInsert(CThostFtdcInputExecOrderField *InputExecOrder, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqExecOrderInsert: nRequestID[%d]", nRequestID);
	WriteInputExecOrder(InputExecOrder);

	return m_TraderApi->ReqExecOrderInsert(InputExecOrder, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqExecOrderAction(CThostFtdcInputExecOrderActionField *InputExecOrderAction, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqExecOrderAction: nRequestID[%d]", nRequestID);
	WriteInputExecOrderAction(InputExecOrderAction);

	return m_TraderApi->ReqExecOrderAction(InputExecOrderAction, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqForQuoteInsert(CThostFtdcInputForQuoteField *InputForQuote, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqForQuoteInsert: nRequestID[%d]", nRequestID);
	WriteInputForQuote(InputForQuote);

	return m_TraderApi->ReqForQuoteInsert(InputForQuote, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQuoteInsert(CThostFtdcInputQuoteField *InputQuote, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQuoteInsert: nRequestID[%d]", nRequestID);
	WriteInputQuote(InputQuote);

	return m_TraderApi->ReqQuoteInsert(InputQuote, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQuoteAction(CThostFtdcInputQuoteActionField *InputQuoteAction, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQuoteAction: nRequestID[%d]", nRequestID);
	WriteInputQuoteAction(InputQuoteAction);

	return m_TraderApi->ReqQuoteAction(InputQuoteAction, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqBatchOrderAction(CThostFtdcInputBatchOrderActionField *InputBatchOrderAction, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqBatchOrderAction: nRequestID[%d]", nRequestID);
	WriteInputBatchOrderAction(InputBatchOrderAction);

	return m_TraderApi->ReqBatchOrderAction(InputBatchOrderAction, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField *InputOptionSelfClose, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqOptionSelfCloseInsert: nRequestID[%d]", nRequestID);
	WriteInputOptionSelfClose(InputOptionSelfClose);

	return m_TraderApi->ReqOptionSelfCloseInsert(InputOptionSelfClose, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqOptionSelfCloseAction(CThostFtdcInputOptionSelfCloseActionField *InputOptionSelfCloseAction, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqOptionSelfCloseAction: nRequestID[%d]", nRequestID);
	WriteInputOptionSelfCloseAction(InputOptionSelfCloseAction);

	return m_TraderApi->ReqOptionSelfCloseAction(InputOptionSelfCloseAction, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqCombActionInsert(CThostFtdcInputCombActionField *InputCombAction, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqCombActionInsert: nRequestID[%d]", nRequestID);
	WriteInputCombAction(InputCombAction);

	return m_TraderApi->ReqCombActionInsert(InputCombAction, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryOrder(CThostFtdcQryOrderField *QryOrder, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryOrder: nRequestID[%d]", nRequestID);
	WriteQryOrder(QryOrder);

	return m_TraderApi->ReqQryOrder(QryOrder, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryTrade(CThostFtdcQryTradeField *QryTrade, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryTrade: nRequestID[%d]", nRequestID);
	WriteQryTrade(QryTrade);

	return m_TraderApi->ReqQryTrade(QryTrade, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryInvestorPosition(CThostFtdcQryInvestorPositionField *QryInvestorPosition, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryInvestorPosition: nRequestID[%d]", nRequestID);
	WriteQryInvestorPosition(QryInvestorPosition);

	return m_TraderApi->ReqQryInvestorPosition(QryInvestorPosition, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryTradingAccount(CThostFtdcQryTradingAccountField *QryTradingAccount, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryTradingAccount: nRequestID[%d]", nRequestID);
	WriteQryTradingAccount(QryTradingAccount);

	return m_TraderApi->ReqQryTradingAccount(QryTradingAccount, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryInvestor(CThostFtdcQryInvestorField *QryInvestor, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryInvestor: nRequestID[%d]", nRequestID);
	WriteQryInvestor(QryInvestor);

	return m_TraderApi->ReqQryInvestor(QryInvestor, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryTradingCode(CThostFtdcQryTradingCodeField *QryTradingCode, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryTradingCode: nRequestID[%d]", nRequestID);
	WriteQryTradingCode(QryTradingCode);

	return m_TraderApi->ReqQryTradingCode(QryTradingCode, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryInstrumentMarginRate(CThostFtdcQryInstrumentMarginRateField *QryInstrumentMarginRate, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryInstrumentMarginRate: nRequestID[%d]", nRequestID);
	WriteQryInstrumentMarginRate(QryInstrumentMarginRate);

	return m_TraderApi->ReqQryInstrumentMarginRate(QryInstrumentMarginRate, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryInstrumentCommissionRate(CThostFtdcQryInstrumentCommissionRateField *QryInstrumentCommissionRate, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryInstrumentCommissionRate: nRequestID[%d]", nRequestID);
	WriteQryInstrumentCommissionRate(QryInstrumentCommissionRate);

	return m_TraderApi->ReqQryInstrumentCommissionRate(QryInstrumentCommissionRate, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryExchange(CThostFtdcQryExchangeField *QryExchange, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryExchange: nRequestID[%d]", nRequestID);
	WriteQryExchange(QryExchange);

	return m_TraderApi->ReqQryExchange(QryExchange, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryProduct(CThostFtdcQryProductField *QryProduct, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryProduct: nRequestID[%d]", nRequestID);
	WriteQryProduct(QryProduct);

	return m_TraderApi->ReqQryProduct(QryProduct, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryInstrument(CThostFtdcQryInstrumentField *QryInstrument, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryInstrument: nRequestID[%d]", nRequestID);
	WriteQryInstrument(QryInstrument);

	return m_TraderApi->ReqQryInstrument(QryInstrument, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryDepthMarketData(CThostFtdcQryDepthMarketDataField *QryDepthMarketData, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryDepthMarketData: nRequestID[%d]", nRequestID);
	WriteQryDepthMarketData(QryDepthMarketData);

	return m_TraderApi->ReqQryDepthMarketData(QryDepthMarketData, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQrySettlementInfo(CThostFtdcQrySettlementInfoField *QrySettlementInfo, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQrySettlementInfo: nRequestID[%d]", nRequestID);
	WriteQrySettlementInfo(QrySettlementInfo);

	return m_TraderApi->ReqQrySettlementInfo(QrySettlementInfo, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryTransferBank(CThostFtdcQryTransferBankField *QryTransferBank, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryTransferBank: nRequestID[%d]", nRequestID);
	WriteQryTransferBank(QryTransferBank);

	return m_TraderApi->ReqQryTransferBank(QryTransferBank, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryInvestorPositionDetail(CThostFtdcQryInvestorPositionDetailField *QryInvestorPositionDetail, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryInvestorPositionDetail: nRequestID[%d]", nRequestID);
	WriteQryInvestorPositionDetail(QryInvestorPositionDetail);

	return m_TraderApi->ReqQryInvestorPositionDetail(QryInvestorPositionDetail, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryNotice(CThostFtdcQryNoticeField *QryNotice, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryNotice: nRequestID[%d]", nRequestID);
	WriteQryNotice(QryNotice);

	return m_TraderApi->ReqQryNotice(QryNotice, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQrySettlementInfoConfirm(CThostFtdcQrySettlementInfoConfirmField *QrySettlementInfoConfirm, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQrySettlementInfoConfirm: nRequestID[%d]", nRequestID);
	WriteQrySettlementInfoConfirm(QrySettlementInfoConfirm);

	return m_TraderApi->ReqQrySettlementInfoConfirm(QrySettlementInfoConfirm, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryInvestorPositionCombineDetail(CThostFtdcQryInvestorPositionCombineDetailField *QryInvestorPositionCombineDetail, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryInvestorPositionCombineDetail: nRequestID[%d]", nRequestID);
	WriteQryInvestorPositionCombineDetail(QryInvestorPositionCombineDetail);

	return m_TraderApi->ReqQryInvestorPositionCombineDetail(QryInvestorPositionCombineDetail, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryCFMMCTradingAccountKey(CThostFtdcQryCFMMCTradingAccountKeyField *QryCFMMCTradingAccountKey, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryCFMMCTradingAccountKey: nRequestID[%d]", nRequestID);
	WriteQryCFMMCTradingAccountKey(QryCFMMCTradingAccountKey);

	return m_TraderApi->ReqQryCFMMCTradingAccountKey(QryCFMMCTradingAccountKey, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryEWarrantOffset(CThostFtdcQryEWarrantOffsetField *QryEWarrantOffset, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryEWarrantOffset: nRequestID[%d]", nRequestID);
	WriteQryEWarrantOffset(QryEWarrantOffset);

	return m_TraderApi->ReqQryEWarrantOffset(QryEWarrantOffset, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryInvestorProductGroupMargin(CThostFtdcQryInvestorProductGroupMarginField *QryInvestorProductGroupMargin, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryInvestorProductGroupMargin: nRequestID[%d]", nRequestID);
	WriteQryInvestorProductGroupMargin(QryInvestorProductGroupMargin);

	return m_TraderApi->ReqQryInvestorProductGroupMargin(QryInvestorProductGroupMargin, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryExchangeMarginRate(CThostFtdcQryExchangeMarginRateField *QryExchangeMarginRate, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryExchangeMarginRate: nRequestID[%d]", nRequestID);
	WriteQryExchangeMarginRate(QryExchangeMarginRate);

	return m_TraderApi->ReqQryExchangeMarginRate(QryExchangeMarginRate, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryExchangeMarginRateAdjust(CThostFtdcQryExchangeMarginRateAdjustField *QryExchangeMarginRateAdjust, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryExchangeMarginRateAdjust: nRequestID[%d]", nRequestID);
	WriteQryExchangeMarginRateAdjust(QryExchangeMarginRateAdjust);

	return m_TraderApi->ReqQryExchangeMarginRateAdjust(QryExchangeMarginRateAdjust, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryExchangeRate(CThostFtdcQryExchangeRateField *QryExchangeRate, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryExchangeRate: nRequestID[%d]", nRequestID);
	WriteQryExchangeRate(QryExchangeRate);

	return m_TraderApi->ReqQryExchangeRate(QryExchangeRate, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQrySecAgentACIDMap(CThostFtdcQrySecAgentACIDMapField *QrySecAgentACIDMap, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQrySecAgentACIDMap: nRequestID[%d]", nRequestID);
	WriteQrySecAgentACIDMap(QrySecAgentACIDMap);

	return m_TraderApi->ReqQrySecAgentACIDMap(QrySecAgentACIDMap, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryProductExchRate(CThostFtdcQryProductExchRateField *QryProductExchRate, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryProductExchRate: nRequestID[%d]", nRequestID);
	WriteQryProductExchRate(QryProductExchRate);

	return m_TraderApi->ReqQryProductExchRate(QryProductExchRate, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryProductGroup(CThostFtdcQryProductGroupField *QryProductGroup, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryProductGroup: nRequestID[%d]", nRequestID);
	WriteQryProductGroup(QryProductGroup);

	return m_TraderApi->ReqQryProductGroup(QryProductGroup, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryMMInstrumentCommissionRate(CThostFtdcQryMMInstrumentCommissionRateField *QryMMInstrumentCommissionRate, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryMMInstrumentCommissionRate: nRequestID[%d]", nRequestID);
	WriteQryMMInstrumentCommissionRate(QryMMInstrumentCommissionRate);

	return m_TraderApi->ReqQryMMInstrumentCommissionRate(QryMMInstrumentCommissionRate, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryMMOptionInstrCommRate(CThostFtdcQryMMOptionInstrCommRateField *QryMMOptionInstrCommRate, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryMMOptionInstrCommRate: nRequestID[%d]", nRequestID);
	WriteQryMMOptionInstrCommRate(QryMMOptionInstrCommRate);

	return m_TraderApi->ReqQryMMOptionInstrCommRate(QryMMOptionInstrCommRate, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryInstrumentOrderCommRate(CThostFtdcQryInstrumentOrderCommRateField *QryInstrumentOrderCommRate, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryInstrumentOrderCommRate: nRequestID[%d]", nRequestID);
	WriteQryInstrumentOrderCommRate(QryInstrumentOrderCommRate);

	return m_TraderApi->ReqQryInstrumentOrderCommRate(QryInstrumentOrderCommRate, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQrySecAgentTradingAccount(CThostFtdcQryTradingAccountField *QryTradingAccount, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQrySecAgentTradingAccount: nRequestID[%d]", nRequestID);
	WriteQryTradingAccount(QryTradingAccount);

	return m_TraderApi->ReqQrySecAgentTradingAccount(QryTradingAccount, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQrySecAgentCheckMode(CThostFtdcQrySecAgentCheckModeField *QrySecAgentCheckMode, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQrySecAgentCheckMode: nRequestID[%d]", nRequestID);
	WriteQrySecAgentCheckMode(QrySecAgentCheckMode);

	return m_TraderApi->ReqQrySecAgentCheckMode(QrySecAgentCheckMode, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQrySecAgentTradeInfo(CThostFtdcQrySecAgentTradeInfoField *QrySecAgentTradeInfo, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQrySecAgentTradeInfo: nRequestID[%d]", nRequestID);
	WriteQrySecAgentTradeInfo(QrySecAgentTradeInfo);

	return m_TraderApi->ReqQrySecAgentTradeInfo(QrySecAgentTradeInfo, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryOptionInstrTradeCost(CThostFtdcQryOptionInstrTradeCostField *QryOptionInstrTradeCost, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryOptionInstrTradeCost: nRequestID[%d]", nRequestID);
	WriteQryOptionInstrTradeCost(QryOptionInstrTradeCost);

	return m_TraderApi->ReqQryOptionInstrTradeCost(QryOptionInstrTradeCost, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryOptionInstrCommRate(CThostFtdcQryOptionInstrCommRateField *QryOptionInstrCommRate, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryOptionInstrCommRate: nRequestID[%d]", nRequestID);
	WriteQryOptionInstrCommRate(QryOptionInstrCommRate);

	return m_TraderApi->ReqQryOptionInstrCommRate(QryOptionInstrCommRate, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryExecOrder(CThostFtdcQryExecOrderField *QryExecOrder, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryExecOrder: nRequestID[%d]", nRequestID);
	WriteQryExecOrder(QryExecOrder);

	return m_TraderApi->ReqQryExecOrder(QryExecOrder, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryForQuote(CThostFtdcQryForQuoteField *QryForQuote, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryForQuote: nRequestID[%d]", nRequestID);
	WriteQryForQuote(QryForQuote);

	return m_TraderApi->ReqQryForQuote(QryForQuote, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryQuote(CThostFtdcQryQuoteField *QryQuote, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryQuote: nRequestID[%d]", nRequestID);
	WriteQryQuote(QryQuote);

	return m_TraderApi->ReqQryQuote(QryQuote, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryOptionSelfClose(CThostFtdcQryOptionSelfCloseField *QryOptionSelfClose, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryOptionSelfClose: nRequestID[%d]", nRequestID);
	WriteQryOptionSelfClose(QryOptionSelfClose);

	return m_TraderApi->ReqQryOptionSelfClose(QryOptionSelfClose, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryInvestUnit(CThostFtdcQryInvestUnitField *QryInvestUnit, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryInvestUnit: nRequestID[%d]", nRequestID);
	WriteQryInvestUnit(QryInvestUnit);

	return m_TraderApi->ReqQryInvestUnit(QryInvestUnit, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryCombInstrumentGuard(CThostFtdcQryCombInstrumentGuardField *QryCombInstrumentGuard, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryCombInstrumentGuard: nRequestID[%d]", nRequestID);
	WriteQryCombInstrumentGuard(QryCombInstrumentGuard);

	return m_TraderApi->ReqQryCombInstrumentGuard(QryCombInstrumentGuard, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryCombAction(CThostFtdcQryCombActionField *QryCombAction, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryCombAction: nRequestID[%d]", nRequestID);
	WriteQryCombAction(QryCombAction);

	return m_TraderApi->ReqQryCombAction(QryCombAction, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryTransferSerial(CThostFtdcQryTransferSerialField *QryTransferSerial, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryTransferSerial: nRequestID[%d]", nRequestID);
	WriteQryTransferSerial(QryTransferSerial);

	return m_TraderApi->ReqQryTransferSerial(QryTransferSerial, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryAccountregister(CThostFtdcQryAccountregisterField *QryAccountregister, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryAccountregister: nRequestID[%d]", nRequestID);
	WriteQryAccountregister(QryAccountregister);

	return m_TraderApi->ReqQryAccountregister(QryAccountregister, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryContractBank(CThostFtdcQryContractBankField *QryContractBank, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryContractBank: nRequestID[%d]", nRequestID);
	WriteQryContractBank(QryContractBank);

	return m_TraderApi->ReqQryContractBank(QryContractBank, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryParkedOrder(CThostFtdcQryParkedOrderField *QryParkedOrder, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryParkedOrder: nRequestID[%d]", nRequestID);
	WriteQryParkedOrder(QryParkedOrder);

	return m_TraderApi->ReqQryParkedOrder(QryParkedOrder, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryParkedOrderAction(CThostFtdcQryParkedOrderActionField *QryParkedOrderAction, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryParkedOrderAction: nRequestID[%d]", nRequestID);
	WriteQryParkedOrderAction(QryParkedOrderAction);

	return m_TraderApi->ReqQryParkedOrderAction(QryParkedOrderAction, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryTradingNotice(CThostFtdcQryTradingNoticeField *QryTradingNotice, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryTradingNotice: nRequestID[%d]", nRequestID);
	WriteQryTradingNotice(QryTradingNotice);

	return m_TraderApi->ReqQryTradingNotice(QryTradingNotice, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryBrokerTradingParams(CThostFtdcQryBrokerTradingParamsField *QryBrokerTradingParams, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryBrokerTradingParams: nRequestID[%d]", nRequestID);
	WriteQryBrokerTradingParams(QryBrokerTradingParams);

	return m_TraderApi->ReqQryBrokerTradingParams(QryBrokerTradingParams, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryBrokerTradingAlgos(CThostFtdcQryBrokerTradingAlgosField *QryBrokerTradingAlgos, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryBrokerTradingAlgos: nRequestID[%d]", nRequestID);
	WriteQryBrokerTradingAlgos(QryBrokerTradingAlgos);

	return m_TraderApi->ReqQryBrokerTradingAlgos(QryBrokerTradingAlgos, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQueryCFMMCTradingAccountToken(CThostFtdcQueryCFMMCTradingAccountTokenField *QueryCFMMCTradingAccountToken, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQueryCFMMCTradingAccountToken: nRequestID[%d]", nRequestID);
	WriteQueryCFMMCTradingAccountToken(QueryCFMMCTradingAccountToken);

	return m_TraderApi->ReqQueryCFMMCTradingAccountToken(QueryCFMMCTradingAccountToken, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqFromBankToFutureByFuture(CThostFtdcReqTransferField *ReqTransfer, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqFromBankToFutureByFuture: nRequestID[%d]", nRequestID);
	WriteReqTransfer(ReqTransfer);

	return m_TraderApi->ReqFromBankToFutureByFuture(ReqTransfer, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqFromFutureToBankByFuture(CThostFtdcReqTransferField *ReqTransfer, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqFromFutureToBankByFuture: nRequestID[%d]", nRequestID);
	WriteReqTransfer(ReqTransfer);

	return m_TraderApi->ReqFromFutureToBankByFuture(ReqTransfer, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField *ReqQueryAccount, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQueryBankAccountMoneyByFuture: nRequestID[%d]", nRequestID);
	WriteReqQueryAccount(ReqQueryAccount);

	return m_TraderApi->ReqQueryBankAccountMoneyByFuture(ReqQueryAccount, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryClassifiedInstrument(CThostFtdcQryClassifiedInstrumentField *QryClassifiedInstrument, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryClassifiedInstrument: nRequestID[%d]", nRequestID);
	WriteQryClassifiedInstrument(QryClassifiedInstrument);

	return m_TraderApi->ReqQryClassifiedInstrument(QryClassifiedInstrument, nRequestID);
}

int CThostFtdcTraderApiMiddle::ReqQryCombPromotionParam(CThostFtdcQryCombPromotionParamField *QryCombPromotionParam, int nRequestID)
{
	WRITE_LOG(LogLevel::Info, "ReqQryCombPromotionParam: nRequestID[%d]", nRequestID);
	WriteQryCombPromotionParam(QryCombPromotionParam);

	return m_TraderApi->ReqQryCombPromotionParam(QryCombPromotionParam, nRequestID);
}

