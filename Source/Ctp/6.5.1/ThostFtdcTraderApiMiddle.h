#pragma once
#include "ThostFtdcTraderApi.h"


class CThostFtdcTraderApiMiddle : public CThostFtdcTraderApi
{
public:
	static CThostFtdcTraderApi *CreateFtdcTraderApi(const char *pszFlowPath = "");
	
	static const char *GetApiVersion();
	
	virtual void Release();

	virtual void Init();

	virtual int Join();

	virtual const char * GetTradingDay();

	virtual void RegisterFront(char * pszFrontAddress);

	virtual void RegisterNameServer(char * pszNsAddress);

	virtual void RegisterFensUserInfo(CThostFtdcFensUserInfoField *FensUserInfo);

	virtual void RegisterSpi(CThostFtdcTraderSpi *TraderSp);

	virtual void SubscribePrivateTopic(THOST_TE_RESUME_TYPE nResumeType);

	virtual void SubscribePublicTopic(THOST_TE_RESUME_TYPE nResumeType);

	virtual int ReqAuthenticate(CThostFtdcReqAuthenticateField *ReqAuthenticate, int nRequestID);

	virtual int RegisterUserSystemInfo(CThostFtdcUserSystemInfoField *UserSystemInfo);

	virtual int SubmitUserSystemInfo(CThostFtdcUserSystemInfoField *UserSystemInfo);

	virtual int ReqUserLogin(CThostFtdcReqUserLoginField *ReqUserLogin, int nRequestID);

	virtual int ReqUserLogout(CThostFtdcUserLogoutField *UserLogout, int nRequestID);

	virtual int ReqUserPasswordUpdate(CThostFtdcUserPasswordUpdateField *UserPasswordUpdate, int nRequestID);

	virtual int ReqTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField *TradingAccountPasswordUpdate, int nRequestID);

	virtual int ReqUserAuthMethod(CThostFtdcReqUserAuthMethodField *ReqUserAuthMethod, int nRequestID);

	virtual int ReqGenUserCaptcha(CThostFtdcReqGenUserCaptchaField *ReqGenUserCaptcha, int nRequestID);

	virtual int ReqGenUserText(CThostFtdcReqGenUserTextField *ReqGenUserText, int nRequestID);

	virtual int ReqUserLoginWithCaptcha(CThostFtdcReqUserLoginWithCaptchaField *ReqUserLoginWithCaptcha, int nRequestID);

	virtual int ReqUserLoginWithText(CThostFtdcReqUserLoginWithTextField *ReqUserLoginWithText, int nRequestID);

	virtual int ReqUserLoginWithOTP(CThostFtdcReqUserLoginWithOTPField *ReqUserLoginWithOTP, int nRequestID);

	virtual int ReqOrderInsert(CThostFtdcInputOrderField *InputOrder, int nRequestID);

	virtual int ReqParkedOrderInsert(CThostFtdcParkedOrderField *ParkedOrder, int nRequestID);

	virtual int ReqParkedOrderAction(CThostFtdcParkedOrderActionField *ParkedOrderAction, int nRequestID);

	virtual int ReqOrderAction(CThostFtdcInputOrderActionField *InputOrderAction, int nRequestID);

	virtual int ReqQryMaxOrderVolume(CThostFtdcQryMaxOrderVolumeField *QryMaxOrderVolume, int nRequestID);

	virtual int ReqSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *SettlementInfoConfirm, int nRequestID);

	virtual int ReqRemoveParkedOrder(CThostFtdcRemoveParkedOrderField *RemoveParkedOrder, int nRequestID);

	virtual int ReqRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField *RemoveParkedOrderAction, int nRequestID);

	virtual int ReqExecOrderInsert(CThostFtdcInputExecOrderField *InputExecOrder, int nRequestID);

	virtual int ReqExecOrderAction(CThostFtdcInputExecOrderActionField *InputExecOrderAction, int nRequestID);

	virtual int ReqForQuoteInsert(CThostFtdcInputForQuoteField *InputForQuote, int nRequestID);

	virtual int ReqQuoteInsert(CThostFtdcInputQuoteField *InputQuote, int nRequestID);

	virtual int ReqQuoteAction(CThostFtdcInputQuoteActionField *InputQuoteAction, int nRequestID);

	virtual int ReqBatchOrderAction(CThostFtdcInputBatchOrderActionField *InputBatchOrderAction, int nRequestID);

	virtual int ReqOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField *InputOptionSelfClose, int nRequestID);

	virtual int ReqOptionSelfCloseAction(CThostFtdcInputOptionSelfCloseActionField *InputOptionSelfCloseAction, int nRequestID);

	virtual int ReqCombActionInsert(CThostFtdcInputCombActionField *InputCombAction, int nRequestID);

	virtual int ReqQryOrder(CThostFtdcQryOrderField *QryOrder, int nRequestID);

	virtual int ReqQryTrade(CThostFtdcQryTradeField *QryTrade, int nRequestID);

	virtual int ReqQryInvestorPosition(CThostFtdcQryInvestorPositionField *QryInvestorPosition, int nRequestID);

	virtual int ReqQryTradingAccount(CThostFtdcQryTradingAccountField *QryTradingAccount, int nRequestID);

	virtual int ReqQryInvestor(CThostFtdcQryInvestorField *QryInvestor, int nRequestID);

	virtual int ReqQryTradingCode(CThostFtdcQryTradingCodeField *QryTradingCode, int nRequestID);

	virtual int ReqQryInstrumentMarginRate(CThostFtdcQryInstrumentMarginRateField *QryInstrumentMarginRate, int nRequestID);

	virtual int ReqQryInstrumentCommissionRate(CThostFtdcQryInstrumentCommissionRateField *QryInstrumentCommissionRate, int nRequestID);

	virtual int ReqQryExchange(CThostFtdcQryExchangeField *QryExchange, int nRequestID);

	virtual int ReqQryProduct(CThostFtdcQryProductField *QryProduct, int nRequestID);

	virtual int ReqQryInstrument(CThostFtdcQryInstrumentField *QryInstrument, int nRequestID);

	virtual int ReqQryDepthMarketData(CThostFtdcQryDepthMarketDataField *QryDepthMarketData, int nRequestID);

	virtual int ReqQrySettlementInfo(CThostFtdcQrySettlementInfoField *QrySettlementInfo, int nRequestID);

	virtual int ReqQryTransferBank(CThostFtdcQryTransferBankField *QryTransferBank, int nRequestID);

	virtual int ReqQryInvestorPositionDetail(CThostFtdcQryInvestorPositionDetailField *QryInvestorPositionDetail, int nRequestID);

	virtual int ReqQryNotice(CThostFtdcQryNoticeField *QryNotice, int nRequestID);

	virtual int ReqQrySettlementInfoConfirm(CThostFtdcQrySettlementInfoConfirmField *QrySettlementInfoConfirm, int nRequestID);

	virtual int ReqQryInvestorPositionCombineDetail(CThostFtdcQryInvestorPositionCombineDetailField *QryInvestorPositionCombineDetail, int nRequestID);

	virtual int ReqQryCFMMCTradingAccountKey(CThostFtdcQryCFMMCTradingAccountKeyField *QryCFMMCTradingAccountKey, int nRequestID);

	virtual int ReqQryEWarrantOffset(CThostFtdcQryEWarrantOffsetField *QryEWarrantOffset, int nRequestID);

	virtual int ReqQryInvestorProductGroupMargin(CThostFtdcQryInvestorProductGroupMarginField *QryInvestorProductGroupMargin, int nRequestID);

	virtual int ReqQryExchangeMarginRate(CThostFtdcQryExchangeMarginRateField *QryExchangeMarginRate, int nRequestID);

	virtual int ReqQryExchangeMarginRateAdjust(CThostFtdcQryExchangeMarginRateAdjustField *QryExchangeMarginRateAdjust, int nRequestID);

	virtual int ReqQryExchangeRate(CThostFtdcQryExchangeRateField *QryExchangeRate, int nRequestID);

	virtual int ReqQrySecAgentACIDMap(CThostFtdcQrySecAgentACIDMapField *QrySecAgentACIDMap, int nRequestID);

	virtual int ReqQryProductExchRate(CThostFtdcQryProductExchRateField *QryProductExchRate, int nRequestID);

	virtual int ReqQryProductGroup(CThostFtdcQryProductGroupField *QryProductGroup, int nRequestID);

	virtual int ReqQryMMInstrumentCommissionRate(CThostFtdcQryMMInstrumentCommissionRateField *QryMMInstrumentCommissionRate, int nRequestID);

	virtual int ReqQryMMOptionInstrCommRate(CThostFtdcQryMMOptionInstrCommRateField *QryMMOptionInstrCommRate, int nRequestID);

	virtual int ReqQryInstrumentOrderCommRate(CThostFtdcQryInstrumentOrderCommRateField *QryInstrumentOrderCommRate, int nRequestID);

	virtual int ReqQrySecAgentTradingAccount(CThostFtdcQryTradingAccountField *QryTradingAccount, int nRequestID);

	virtual int ReqQrySecAgentCheckMode(CThostFtdcQrySecAgentCheckModeField *QrySecAgentCheckMode, int nRequestID);

	virtual int ReqQrySecAgentTradeInfo(CThostFtdcQrySecAgentTradeInfoField *QrySecAgentTradeInfo, int nRequestID);

	virtual int ReqQryOptionInstrTradeCost(CThostFtdcQryOptionInstrTradeCostField *QryOptionInstrTradeCost, int nRequestID);

	virtual int ReqQryOptionInstrCommRate(CThostFtdcQryOptionInstrCommRateField *QryOptionInstrCommRate, int nRequestID);

	virtual int ReqQryExecOrder(CThostFtdcQryExecOrderField *QryExecOrder, int nRequestID);

	virtual int ReqQryForQuote(CThostFtdcQryForQuoteField *QryForQuote, int nRequestID);

	virtual int ReqQryQuote(CThostFtdcQryQuoteField *QryQuote, int nRequestID);

	virtual int ReqQryOptionSelfClose(CThostFtdcQryOptionSelfCloseField *QryOptionSelfClose, int nRequestID);

	virtual int ReqQryInvestUnit(CThostFtdcQryInvestUnitField *QryInvestUnit, int nRequestID);

	virtual int ReqQryCombInstrumentGuard(CThostFtdcQryCombInstrumentGuardField *QryCombInstrumentGuard, int nRequestID);

	virtual int ReqQryCombAction(CThostFtdcQryCombActionField *QryCombAction, int nRequestID);

	virtual int ReqQryTransferSerial(CThostFtdcQryTransferSerialField *QryTransferSerial, int nRequestID);

	virtual int ReqQryAccountregister(CThostFtdcQryAccountregisterField *QryAccountregister, int nRequestID);

	virtual int ReqQryContractBank(CThostFtdcQryContractBankField *QryContractBank, int nRequestID);

	virtual int ReqQryParkedOrder(CThostFtdcQryParkedOrderField *QryParkedOrder, int nRequestID);

	virtual int ReqQryParkedOrderAction(CThostFtdcQryParkedOrderActionField *QryParkedOrderAction, int nRequestID);

	virtual int ReqQryTradingNotice(CThostFtdcQryTradingNoticeField *QryTradingNotice, int nRequestID);

	virtual int ReqQryBrokerTradingParams(CThostFtdcQryBrokerTradingParamsField *QryBrokerTradingParams, int nRequestID);

	virtual int ReqQryBrokerTradingAlgos(CThostFtdcQryBrokerTradingAlgosField *QryBrokerTradingAlgos, int nRequestID);

	virtual int ReqQueryCFMMCTradingAccountToken(CThostFtdcQueryCFMMCTradingAccountTokenField *QueryCFMMCTradingAccountToken, int nRequestID);

	virtual int ReqFromBankToFutureByFuture(CThostFtdcReqTransferField *ReqTransfer, int nRequestID);

	virtual int ReqFromFutureToBankByFuture(CThostFtdcReqTransferField *ReqTransfer, int nRequestID);

	virtual int ReqQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField *ReqQueryAccount, int nRequestID);

	virtual int ReqQryClassifiedInstrument(CThostFtdcQryClassifiedInstrumentField *QryClassifiedInstrument, int nRequestID);

	virtual int ReqQryCombPromotionParam(CThostFtdcQryCombPromotionParamField *QryCombPromotionParam, int nRequestID);


private:
	CThostFtdcTraderApi* m_TraderApi;
};