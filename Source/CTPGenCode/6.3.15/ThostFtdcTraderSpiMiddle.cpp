#include "ThostFtdcTraderSpiMiddle.h"
#include "Logger.h"
#include "StructWriteLogFunc.h"



void CThostFtdcTraderSpiMiddle::OnFrontConnected()
{
	WRITE_LOG(LogLevel::Info, "OnFrontConnected:");
}

void CThostFtdcTraderSpiMiddle::OnFrontDisconnected(int nReason)
{
	WRITE_LOG(LogLevel::Info, "OnFrontDisconnected: nReason[%d]", nReason);
}

void CThostFtdcTraderSpiMiddle::OnHeartBeatWarning(int nTimeLapse)
{
	WRITE_LOG(LogLevel::Info, "OnHeartBeatWarning: nTimeLapse[%d]", nTimeLapse);
}

void CThostFtdcTraderSpiMiddle::OnRspAuthenticate(CThostFtdcRspAuthenticateField *pRspAuthenticate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspAuthenticate: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteRspAuthenticate(pRspAuthenticate);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspUserLogin: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteRspUserLogin(pRspUserLogin);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspUserLogout: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteUserLogout(pUserLogout);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspUserPasswordUpdate: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteUserPasswordUpdate(pUserPasswordUpdate);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspTradingAccountPasswordUpdate: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteTradingAccountPasswordUpdate(pTradingAccountPasswordUpdate);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspUserAuthMethod(CThostFtdcRspUserAuthMethodField *pRspUserAuthMethod, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspUserAuthMethod: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteRspUserAuthMethod(pRspUserAuthMethod);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspGenUserCaptcha(CThostFtdcRspGenUserCaptchaField *pRspGenUserCaptcha, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspGenUserCaptcha: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteRspGenUserCaptcha(pRspGenUserCaptcha);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspGenUserText(CThostFtdcRspGenUserTextField *pRspGenUserText, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspGenUserText: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteRspGenUserText(pRspGenUserText);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspOrderInsert: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteInputOrder(pInputOrder);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspParkedOrderInsert(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspParkedOrderInsert: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteParkedOrder(pParkedOrder);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspParkedOrderAction: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteParkedOrderAction(pParkedOrderAction);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspOrderAction: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteInputOrderAction(pInputOrderAction);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQueryMaxOrderVolume(CThostFtdcQueryMaxOrderVolumeField *pQueryMaxOrderVolume, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQueryMaxOrderVolume: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteQueryMaxOrderVolume(pQueryMaxOrderVolume);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspSettlementInfoConfirm: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteSettlementInfoConfirm(pSettlementInfoConfirm);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspRemoveParkedOrder(CThostFtdcRemoveParkedOrderField *pRemoveParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspRemoveParkedOrder: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteRemoveParkedOrder(pRemoveParkedOrder);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField *pRemoveParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspRemoveParkedOrderAction: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteRemoveParkedOrderAction(pRemoveParkedOrderAction);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspExecOrderInsert(CThostFtdcInputExecOrderField *pInputExecOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspExecOrderInsert: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteInputExecOrder(pInputExecOrder);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspExecOrderAction(CThostFtdcInputExecOrderActionField *pInputExecOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspExecOrderAction: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteInputExecOrderAction(pInputExecOrderAction);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspForQuoteInsert: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteInputForQuote(pInputForQuote);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQuoteInsert(CThostFtdcInputQuoteField *pInputQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQuoteInsert: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteInputQuote(pInputQuote);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQuoteAction(CThostFtdcInputQuoteActionField *pInputQuoteAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQuoteAction: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteInputQuoteAction(pInputQuoteAction);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspBatchOrderAction(CThostFtdcInputBatchOrderActionField *pInputBatchOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspBatchOrderAction: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteInputBatchOrderAction(pInputBatchOrderAction);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField *pInputOptionSelfClose, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspOptionSelfCloseInsert: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteInputOptionSelfClose(pInputOptionSelfClose);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspOptionSelfCloseAction(CThostFtdcInputOptionSelfCloseActionField *pInputOptionSelfCloseAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspOptionSelfCloseAction: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteInputOptionSelfCloseAction(pInputOptionSelfCloseAction);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspCombActionInsert(CThostFtdcInputCombActionField *pInputCombAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspCombActionInsert: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteInputCombAction(pInputCombAction);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryOrder(CThostFtdcOrderField *pOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryOrder: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteOrder(pOrder);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryTrade(CThostFtdcTradeField *pTrade, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryTrade: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteTrade(pTrade);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryInvestorPosition: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteInvestorPosition(pInvestorPosition);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryTradingAccount: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteTradingAccount(pTradingAccount);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryInvestor(CThostFtdcInvestorField *pInvestor, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryInvestor: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteInvestor(pInvestor);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryTradingCode(CThostFtdcTradingCodeField *pTradingCode, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryTradingCode: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteTradingCode(pTradingCode);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField *pInstrumentMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryInstrumentMarginRate: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteInstrumentMarginRate(pInstrumentMarginRate);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField *pInstrumentCommissionRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryInstrumentCommissionRate: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteInstrumentCommissionRate(pInstrumentCommissionRate);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryExchange(CThostFtdcExchangeField *pExchange, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryExchange: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteExchange(pExchange);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryProduct(CThostFtdcProductField *pProduct, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryProduct: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteProduct(pProduct);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryInstrument: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteInstrument(pInstrument);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryDepthMarketData: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteDepthMarketData(pDepthMarketData);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQrySettlementInfo(CThostFtdcSettlementInfoField *pSettlementInfo, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQrySettlementInfo: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteSettlementInfo(pSettlementInfo);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryTransferBank(CThostFtdcTransferBankField *pTransferBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryTransferBank: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteTransferBank(pTransferBank);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField *pInvestorPositionDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryInvestorPositionDetail: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteInvestorPositionDetail(pInvestorPositionDetail);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryNotice(CThostFtdcNoticeField *pNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryNotice: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteNotice(pNotice);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQrySettlementInfoConfirm: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteSettlementInfoConfirm(pSettlementInfoConfirm);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField *pInvestorPositionCombineDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryInvestorPositionCombineDetail: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteInvestorPositionCombineDetail(pInvestorPositionCombineDetail);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryCFMMCTradingAccountKey(CThostFtdcCFMMCTradingAccountKeyField *pCFMMCTradingAccountKey, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryCFMMCTradingAccountKey: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteCFMMCTradingAccountKey(pCFMMCTradingAccountKey);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryEWarrantOffset(CThostFtdcEWarrantOffsetField *pEWarrantOffset, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryEWarrantOffset: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteEWarrantOffset(pEWarrantOffset);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryInvestorProductGroupMargin(CThostFtdcInvestorProductGroupMarginField *pInvestorProductGroupMargin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryInvestorProductGroupMargin: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteInvestorProductGroupMargin(pInvestorProductGroupMargin);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryExchangeMarginRate(CThostFtdcExchangeMarginRateField *pExchangeMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryExchangeMarginRate: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteExchangeMarginRate(pExchangeMarginRate);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryExchangeMarginRateAdjust(CThostFtdcExchangeMarginRateAdjustField *pExchangeMarginRateAdjust, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryExchangeMarginRateAdjust: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteExchangeMarginRateAdjust(pExchangeMarginRateAdjust);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryExchangeRate(CThostFtdcExchangeRateField *pExchangeRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryExchangeRate: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteExchangeRate(pExchangeRate);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQrySecAgentACIDMap(CThostFtdcSecAgentACIDMapField *pSecAgentACIDMap, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQrySecAgentACIDMap: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteSecAgentACIDMap(pSecAgentACIDMap);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryProductExchRate(CThostFtdcProductExchRateField *pProductExchRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryProductExchRate: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteProductExchRate(pProductExchRate);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryProductGroup(CThostFtdcProductGroupField *pProductGroup, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryProductGroup: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteProductGroup(pProductGroup);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryMMInstrumentCommissionRate(CThostFtdcMMInstrumentCommissionRateField *pMMInstrumentCommissionRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryMMInstrumentCommissionRate: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteMMInstrumentCommissionRate(pMMInstrumentCommissionRate);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryMMOptionInstrCommRate(CThostFtdcMMOptionInstrCommRateField *pMMOptionInstrCommRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryMMOptionInstrCommRate: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteMMOptionInstrCommRate(pMMOptionInstrCommRate);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryInstrumentOrderCommRate(CThostFtdcInstrumentOrderCommRateField *pInstrumentOrderCommRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryInstrumentOrderCommRate: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteInstrumentOrderCommRate(pInstrumentOrderCommRate);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQrySecAgentTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQrySecAgentTradingAccount: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteTradingAccount(pTradingAccount);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQrySecAgentCheckMode(CThostFtdcSecAgentCheckModeField *pSecAgentCheckMode, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQrySecAgentCheckMode: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteSecAgentCheckMode(pSecAgentCheckMode);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQrySecAgentTradeInfo(CThostFtdcSecAgentTradeInfoField *pSecAgentTradeInfo, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQrySecAgentTradeInfo: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteSecAgentTradeInfo(pSecAgentTradeInfo);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryOptionInstrTradeCost(CThostFtdcOptionInstrTradeCostField *pOptionInstrTradeCost, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryOptionInstrTradeCost: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteOptionInstrTradeCost(pOptionInstrTradeCost);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryOptionInstrCommRate(CThostFtdcOptionInstrCommRateField *pOptionInstrCommRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryOptionInstrCommRate: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteOptionInstrCommRate(pOptionInstrCommRate);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryExecOrder(CThostFtdcExecOrderField *pExecOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryExecOrder: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteExecOrder(pExecOrder);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryForQuote(CThostFtdcForQuoteField *pForQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryForQuote: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteForQuote(pForQuote);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryQuote(CThostFtdcQuoteField *pQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryQuote: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteQuote(pQuote);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryOptionSelfClose(CThostFtdcOptionSelfCloseField *pOptionSelfClose, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryOptionSelfClose: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteOptionSelfClose(pOptionSelfClose);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryInvestUnit(CThostFtdcInvestUnitField *pInvestUnit, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryInvestUnit: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteInvestUnit(pInvestUnit);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryCombInstrumentGuard(CThostFtdcCombInstrumentGuardField *pCombInstrumentGuard, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryCombInstrumentGuard: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteCombInstrumentGuard(pCombInstrumentGuard);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryCombAction(CThostFtdcCombActionField *pCombAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryCombAction: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteCombAction(pCombAction);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryTransferSerial(CThostFtdcTransferSerialField *pTransferSerial, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryTransferSerial: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteTransferSerial(pTransferSerial);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryAccountregister(CThostFtdcAccountregisterField *pAccountregister, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryAccountregister: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteAccountregister(pAccountregister);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspError: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRtnOrder(CThostFtdcOrderField *pOrder)
{
	WRITE_LOG(LogLevel::Info, "OnRtnOrder:");
	WriteOrder(pOrder);
}

void CThostFtdcTraderSpiMiddle::OnRtnTrade(CThostFtdcTradeField *pTrade)
{
	WRITE_LOG(LogLevel::Info, "OnRtnTrade:");
	WriteTrade(pTrade);
}

void CThostFtdcTraderSpiMiddle::OnErrRtnOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo)
{
	WRITE_LOG(LogLevel::Info, "OnErrRtnOrderInsert:");
	WriteInputOrder(pInputOrder);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnErrRtnOrderAction(CThostFtdcOrderActionField *pOrderAction, CThostFtdcRspInfoField *pRspInfo)
{
	WRITE_LOG(LogLevel::Info, "OnErrRtnOrderAction:");
	WriteOrderAction(pOrderAction);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRtnInstrumentStatus(CThostFtdcInstrumentStatusField *pInstrumentStatus)
{
	WRITE_LOG(LogLevel::Info, "OnRtnInstrumentStatus:");
	WriteInstrumentStatus(pInstrumentStatus);
}

void CThostFtdcTraderSpiMiddle::OnRtnBulletin(CThostFtdcBulletinField *pBulletin)
{
	WRITE_LOG(LogLevel::Info, "OnRtnBulletin:");
	WriteBulletin(pBulletin);
}

void CThostFtdcTraderSpiMiddle::OnRtnTradingNotice(CThostFtdcTradingNoticeInfoField *pTradingNoticeInfo)
{
	WRITE_LOG(LogLevel::Info, "OnRtnTradingNotice:");
	WriteTradingNoticeInfo(pTradingNoticeInfo);
}

void CThostFtdcTraderSpiMiddle::OnRtnErrorConditionalOrder(CThostFtdcErrorConditionalOrderField *pErrorConditionalOrder)
{
	WRITE_LOG(LogLevel::Info, "OnRtnErrorConditionalOrder:");
	WriteErrorConditionalOrder(pErrorConditionalOrder);
}

void CThostFtdcTraderSpiMiddle::OnRtnExecOrder(CThostFtdcExecOrderField *pExecOrder)
{
	WRITE_LOG(LogLevel::Info, "OnRtnExecOrder:");
	WriteExecOrder(pExecOrder);
}

void CThostFtdcTraderSpiMiddle::OnErrRtnExecOrderInsert(CThostFtdcInputExecOrderField *pInputExecOrder, CThostFtdcRspInfoField *pRspInfo)
{
	WRITE_LOG(LogLevel::Info, "OnErrRtnExecOrderInsert:");
	WriteInputExecOrder(pInputExecOrder);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnErrRtnExecOrderAction(CThostFtdcExecOrderActionField *pExecOrderAction, CThostFtdcRspInfoField *pRspInfo)
{
	WRITE_LOG(LogLevel::Info, "OnErrRtnExecOrderAction:");
	WriteExecOrderAction(pExecOrderAction);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnErrRtnForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote, CThostFtdcRspInfoField *pRspInfo)
{
	WRITE_LOG(LogLevel::Info, "OnErrRtnForQuoteInsert:");
	WriteInputForQuote(pInputForQuote);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRtnQuote(CThostFtdcQuoteField *pQuote)
{
	WRITE_LOG(LogLevel::Info, "OnRtnQuote:");
	WriteQuote(pQuote);
}

void CThostFtdcTraderSpiMiddle::OnErrRtnQuoteInsert(CThostFtdcInputQuoteField *pInputQuote, CThostFtdcRspInfoField *pRspInfo)
{
	WRITE_LOG(LogLevel::Info, "OnErrRtnQuoteInsert:");
	WriteInputQuote(pInputQuote);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnErrRtnQuoteAction(CThostFtdcQuoteActionField *pQuoteAction, CThostFtdcRspInfoField *pRspInfo)
{
	WRITE_LOG(LogLevel::Info, "OnErrRtnQuoteAction:");
	WriteQuoteAction(pQuoteAction);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp)
{
	WRITE_LOG(LogLevel::Info, "OnRtnForQuoteRsp:");
	WriteForQuoteRsp(pForQuoteRsp);
}

void CThostFtdcTraderSpiMiddle::OnRtnCFMMCTradingAccountToken(CThostFtdcCFMMCTradingAccountTokenField *pCFMMCTradingAccountToken)
{
	WRITE_LOG(LogLevel::Info, "OnRtnCFMMCTradingAccountToken:");
	WriteCFMMCTradingAccountToken(pCFMMCTradingAccountToken);
}

void CThostFtdcTraderSpiMiddle::OnErrRtnBatchOrderAction(CThostFtdcBatchOrderActionField *pBatchOrderAction, CThostFtdcRspInfoField *pRspInfo)
{
	WRITE_LOG(LogLevel::Info, "OnErrRtnBatchOrderAction:");
	WriteBatchOrderAction(pBatchOrderAction);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRtnOptionSelfClose(CThostFtdcOptionSelfCloseField *pOptionSelfClose)
{
	WRITE_LOG(LogLevel::Info, "OnRtnOptionSelfClose:");
	WriteOptionSelfClose(pOptionSelfClose);
}

void CThostFtdcTraderSpiMiddle::OnErrRtnOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField *pInputOptionSelfClose, CThostFtdcRspInfoField *pRspInfo)
{
	WRITE_LOG(LogLevel::Info, "OnErrRtnOptionSelfCloseInsert:");
	WriteInputOptionSelfClose(pInputOptionSelfClose);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnErrRtnOptionSelfCloseAction(CThostFtdcOptionSelfCloseActionField *pOptionSelfCloseAction, CThostFtdcRspInfoField *pRspInfo)
{
	WRITE_LOG(LogLevel::Info, "OnErrRtnOptionSelfCloseAction:");
	WriteOptionSelfCloseAction(pOptionSelfCloseAction);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRtnCombAction(CThostFtdcCombActionField *pCombAction)
{
	WRITE_LOG(LogLevel::Info, "OnRtnCombAction:");
	WriteCombAction(pCombAction);
}

void CThostFtdcTraderSpiMiddle::OnErrRtnCombActionInsert(CThostFtdcInputCombActionField *pInputCombAction, CThostFtdcRspInfoField *pRspInfo)
{
	WRITE_LOG(LogLevel::Info, "OnErrRtnCombActionInsert:");
	WriteInputCombAction(pInputCombAction);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryContractBank(CThostFtdcContractBankField *pContractBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryContractBank: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteContractBank(pContractBank);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryParkedOrder(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryParkedOrder: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteParkedOrder(pParkedOrder);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryParkedOrderAction: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteParkedOrderAction(pParkedOrderAction);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryTradingNotice(CThostFtdcTradingNoticeField *pTradingNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryTradingNotice: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteTradingNotice(pTradingNotice);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryBrokerTradingParams(CThostFtdcBrokerTradingParamsField *pBrokerTradingParams, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryBrokerTradingParams: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteBrokerTradingParams(pBrokerTradingParams);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryBrokerTradingAlgos(CThostFtdcBrokerTradingAlgosField *pBrokerTradingAlgos, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryBrokerTradingAlgos: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteBrokerTradingAlgos(pBrokerTradingAlgos);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQueryCFMMCTradingAccountToken(CThostFtdcQueryCFMMCTradingAccountTokenField *pQueryCFMMCTradingAccountToken, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQueryCFMMCTradingAccountToken: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteQueryCFMMCTradingAccountToken(pQueryCFMMCTradingAccountToken);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRtnFromBankToFutureByBank(CThostFtdcRspTransferField *pRspTransfer)
{
	WRITE_LOG(LogLevel::Info, "OnRtnFromBankToFutureByBank:");
	WriteRspTransfer(pRspTransfer);
}

void CThostFtdcTraderSpiMiddle::OnRtnFromFutureToBankByBank(CThostFtdcRspTransferField *pRspTransfer)
{
	WRITE_LOG(LogLevel::Info, "OnRtnFromFutureToBankByBank:");
	WriteRspTransfer(pRspTransfer);
}

void CThostFtdcTraderSpiMiddle::OnRtnRepealFromBankToFutureByBank(CThostFtdcRspRepealField *pRspRepeal)
{
	WRITE_LOG(LogLevel::Info, "OnRtnRepealFromBankToFutureByBank:");
	WriteRspRepeal(pRspRepeal);
}

void CThostFtdcTraderSpiMiddle::OnRtnRepealFromFutureToBankByBank(CThostFtdcRspRepealField *pRspRepeal)
{
	WRITE_LOG(LogLevel::Info, "OnRtnRepealFromFutureToBankByBank:");
	WriteRspRepeal(pRspRepeal);
}

void CThostFtdcTraderSpiMiddle::OnRtnFromBankToFutureByFuture(CThostFtdcRspTransferField *pRspTransfer)
{
	WRITE_LOG(LogLevel::Info, "OnRtnFromBankToFutureByFuture:");
	WriteRspTransfer(pRspTransfer);
}

void CThostFtdcTraderSpiMiddle::OnRtnFromFutureToBankByFuture(CThostFtdcRspTransferField *pRspTransfer)
{
	WRITE_LOG(LogLevel::Info, "OnRtnFromFutureToBankByFuture:");
	WriteRspTransfer(pRspTransfer);
}

void CThostFtdcTraderSpiMiddle::OnRtnRepealFromBankToFutureByFutureManual(CThostFtdcRspRepealField *pRspRepeal)
{
	WRITE_LOG(LogLevel::Info, "OnRtnRepealFromBankToFutureByFutureManual:");
	WriteRspRepeal(pRspRepeal);
}

void CThostFtdcTraderSpiMiddle::OnRtnRepealFromFutureToBankByFutureManual(CThostFtdcRspRepealField *pRspRepeal)
{
	WRITE_LOG(LogLevel::Info, "OnRtnRepealFromFutureToBankByFutureManual:");
	WriteRspRepeal(pRspRepeal);
}

void CThostFtdcTraderSpiMiddle::OnRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField *pNotifyQueryAccount)
{
	WRITE_LOG(LogLevel::Info, "OnRtnQueryBankBalanceByFuture:");
	WriteNotifyQueryAccount(pNotifyQueryAccount);
}

void CThostFtdcTraderSpiMiddle::OnErrRtnBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo)
{
	WRITE_LOG(LogLevel::Info, "OnErrRtnBankToFutureByFuture:");
	WriteReqTransfer(pReqTransfer);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnErrRtnFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo)
{
	WRITE_LOG(LogLevel::Info, "OnErrRtnFutureToBankByFuture:");
	WriteReqTransfer(pReqTransfer);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnErrRtnRepealBankToFutureByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo)
{
	WRITE_LOG(LogLevel::Info, "OnErrRtnRepealBankToFutureByFutureManual:");
	WriteReqRepeal(pReqRepeal);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnErrRtnRepealFutureToBankByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo)
{
	WRITE_LOG(LogLevel::Info, "OnErrRtnRepealFutureToBankByFutureManual:");
	WriteReqRepeal(pReqRepeal);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnErrRtnQueryBankBalanceByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo)
{
	WRITE_LOG(LogLevel::Info, "OnErrRtnQueryBankBalanceByFuture:");
	WriteReqQueryAccount(pReqQueryAccount);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRtnRepealFromBankToFutureByFuture(CThostFtdcRspRepealField *pRspRepeal)
{
	WRITE_LOG(LogLevel::Info, "OnRtnRepealFromBankToFutureByFuture:");
	WriteRspRepeal(pRspRepeal);
}

void CThostFtdcTraderSpiMiddle::OnRtnRepealFromFutureToBankByFuture(CThostFtdcRspRepealField *pRspRepeal)
{
	WRITE_LOG(LogLevel::Info, "OnRtnRepealFromFutureToBankByFuture:");
	WriteRspRepeal(pRspRepeal);
}

void CThostFtdcTraderSpiMiddle::OnRspFromBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspFromBankToFutureByFuture: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteReqTransfer(pReqTransfer);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspFromFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspFromFutureToBankByFuture: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteReqTransfer(pReqTransfer);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQueryBankAccountMoneyByFuture: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteReqQueryAccount(pReqQueryAccount);
	WriteRspInfo(pRspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRtnOpenAccountByBank(CThostFtdcOpenAccountField *pOpenAccount)
{
	WRITE_LOG(LogLevel::Info, "OnRtnOpenAccountByBank:");
	WriteOpenAccount(pOpenAccount);
}

void CThostFtdcTraderSpiMiddle::OnRtnCancelAccountByBank(CThostFtdcCancelAccountField *pCancelAccount)
{
	WRITE_LOG(LogLevel::Info, "OnRtnCancelAccountByBank:");
	WriteCancelAccount(pCancelAccount);
}

void CThostFtdcTraderSpiMiddle::OnRtnChangeAccountByBank(CThostFtdcChangeAccountField *pChangeAccount)
{
	WRITE_LOG(LogLevel::Info, "OnRtnChangeAccountByBank:");
	WriteChangeAccount(pChangeAccount);
}

