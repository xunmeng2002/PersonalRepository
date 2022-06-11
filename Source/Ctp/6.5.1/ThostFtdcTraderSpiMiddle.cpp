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

void CThostFtdcTraderSpiMiddle::OnRspAuthenticate(CThostFtdcRspAuthenticateField *RspAuthenticate, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspAuthenticate: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteRspAuthenticate(RspAuthenticate);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspUserLogin(CThostFtdcRspUserLoginField *RspUserLogin, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspUserLogin: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteRspUserLogin(RspUserLogin);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspUserLogout(CThostFtdcUserLogoutField *UserLogout, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspUserLogout: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteUserLogout(UserLogout);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField *UserPasswordUpdate, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspUserPasswordUpdate: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteUserPasswordUpdate(UserPasswordUpdate);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField *TradingAccountPasswordUpdate, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspTradingAccountPasswordUpdate: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteTradingAccountPasswordUpdate(TradingAccountPasswordUpdate);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspUserAuthMethod(CThostFtdcRspUserAuthMethodField *RspUserAuthMethod, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspUserAuthMethod: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteRspUserAuthMethod(RspUserAuthMethod);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspGenUserCaptcha(CThostFtdcRspGenUserCaptchaField *RspGenUserCaptcha, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspGenUserCaptcha: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteRspGenUserCaptcha(RspGenUserCaptcha);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspGenUserText(CThostFtdcRspGenUserTextField *RspGenUserText, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspGenUserText: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteRspGenUserText(RspGenUserText);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspOrderInsert(CThostFtdcInputOrderField *InputOrder, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspOrderInsert: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteInputOrder(InputOrder);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspParkedOrderInsert(CThostFtdcParkedOrderField *ParkedOrder, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspParkedOrderInsert: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteParkedOrder(ParkedOrder);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspParkedOrderAction(CThostFtdcParkedOrderActionField *ParkedOrderAction, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspParkedOrderAction: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteParkedOrderAction(ParkedOrderAction);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspOrderAction(CThostFtdcInputOrderActionField *InputOrderAction, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspOrderAction: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteInputOrderAction(InputOrderAction);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryMaxOrderVolume(CThostFtdcQryMaxOrderVolumeField *QryMaxOrderVolume, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryMaxOrderVolume: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteQryMaxOrderVolume(QryMaxOrderVolume);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *SettlementInfoConfirm, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspSettlementInfoConfirm: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteSettlementInfoConfirm(SettlementInfoConfirm);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspRemoveParkedOrder(CThostFtdcRemoveParkedOrderField *RemoveParkedOrder, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspRemoveParkedOrder: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteRemoveParkedOrder(RemoveParkedOrder);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField *RemoveParkedOrderAction, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspRemoveParkedOrderAction: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteRemoveParkedOrderAction(RemoveParkedOrderAction);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspExecOrderInsert(CThostFtdcInputExecOrderField *InputExecOrder, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspExecOrderInsert: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteInputExecOrder(InputExecOrder);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspExecOrderAction(CThostFtdcInputExecOrderActionField *InputExecOrderAction, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspExecOrderAction: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteInputExecOrderAction(InputExecOrderAction);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspForQuoteInsert(CThostFtdcInputForQuoteField *InputForQuote, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspForQuoteInsert: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteInputForQuote(InputForQuote);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQuoteInsert(CThostFtdcInputQuoteField *InputQuote, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQuoteInsert: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteInputQuote(InputQuote);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQuoteAction(CThostFtdcInputQuoteActionField *InputQuoteAction, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQuoteAction: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteInputQuoteAction(InputQuoteAction);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspBatchOrderAction(CThostFtdcInputBatchOrderActionField *InputBatchOrderAction, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspBatchOrderAction: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteInputBatchOrderAction(InputBatchOrderAction);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField *InputOptionSelfClose, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspOptionSelfCloseInsert: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteInputOptionSelfClose(InputOptionSelfClose);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspOptionSelfCloseAction(CThostFtdcInputOptionSelfCloseActionField *InputOptionSelfCloseAction, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspOptionSelfCloseAction: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteInputOptionSelfCloseAction(InputOptionSelfCloseAction);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspCombActionInsert(CThostFtdcInputCombActionField *InputCombAction, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspCombActionInsert: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteInputCombAction(InputCombAction);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryOrder(CThostFtdcOrderField *Order, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryOrder: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteOrder(Order);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryTrade(CThostFtdcTradeField *Trade, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryTrade: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteTrade(Trade);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *InvestorPosition, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryInvestorPosition: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteInvestorPosition(InvestorPosition);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryTradingAccount(CThostFtdcTradingAccountField *TradingAccount, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryTradingAccount: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteTradingAccount(TradingAccount);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryInvestor(CThostFtdcInvestorField *Investor, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryInvestor: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteInvestor(Investor);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryTradingCode(CThostFtdcTradingCodeField *TradingCode, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryTradingCode: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteTradingCode(TradingCode);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField *InstrumentMarginRate, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryInstrumentMarginRate: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteInstrumentMarginRate(InstrumentMarginRate);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField *InstrumentCommissionRate, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryInstrumentCommissionRate: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteInstrumentCommissionRate(InstrumentCommissionRate);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryExchange(CThostFtdcExchangeField *Exchange, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryExchange: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteExchange(Exchange);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryProduct(CThostFtdcProductField *Product, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryProduct: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteProduct(Product);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryInstrument(CThostFtdcInstrumentField *Instrument, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryInstrument: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteInstrument(Instrument);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField *DepthMarketData, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryDepthMarketData: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteDepthMarketData(DepthMarketData);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQrySettlementInfo(CThostFtdcSettlementInfoField *SettlementInfo, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQrySettlementInfo: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteSettlementInfo(SettlementInfo);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryTransferBank(CThostFtdcTransferBankField *TransferBank, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryTransferBank: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteTransferBank(TransferBank);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField *InvestorPositionDetail, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryInvestorPositionDetail: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteInvestorPositionDetail(InvestorPositionDetail);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryNotice(CThostFtdcNoticeField *Notice, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryNotice: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteNotice(Notice);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *SettlementInfoConfirm, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQrySettlementInfoConfirm: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteSettlementInfoConfirm(SettlementInfoConfirm);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField *InvestorPositionCombineDetail, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryInvestorPositionCombineDetail: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteInvestorPositionCombineDetail(InvestorPositionCombineDetail);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryCFMMCTradingAccountKey(CThostFtdcCFMMCTradingAccountKeyField *CFMMCTradingAccountKey, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryCFMMCTradingAccountKey: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteCFMMCTradingAccountKey(CFMMCTradingAccountKey);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryEWarrantOffset(CThostFtdcEWarrantOffsetField *EWarrantOffset, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryEWarrantOffset: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteEWarrantOffset(EWarrantOffset);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryInvestorProductGroupMargin(CThostFtdcInvestorProductGroupMarginField *InvestorProductGroupMargin, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryInvestorProductGroupMargin: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteInvestorProductGroupMargin(InvestorProductGroupMargin);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryExchangeMarginRate(CThostFtdcExchangeMarginRateField *ExchangeMarginRate, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryExchangeMarginRate: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteExchangeMarginRate(ExchangeMarginRate);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryExchangeMarginRateAdjust(CThostFtdcExchangeMarginRateAdjustField *ExchangeMarginRateAdjust, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryExchangeMarginRateAdjust: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteExchangeMarginRateAdjust(ExchangeMarginRateAdjust);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryExchangeRate(CThostFtdcExchangeRateField *ExchangeRate, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryExchangeRate: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteExchangeRate(ExchangeRate);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQrySecAgentACIDMap(CThostFtdcSecAgentACIDMapField *SecAgentACIDMap, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQrySecAgentACIDMap: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteSecAgentACIDMap(SecAgentACIDMap);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryProductExchRate(CThostFtdcProductExchRateField *ProductExchRate, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryProductExchRate: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteProductExchRate(ProductExchRate);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryProductGroup(CThostFtdcProductGroupField *ProductGroup, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryProductGroup: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteProductGroup(ProductGroup);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryMMInstrumentCommissionRate(CThostFtdcMMInstrumentCommissionRateField *MMInstrumentCommissionRate, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryMMInstrumentCommissionRate: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteMMInstrumentCommissionRate(MMInstrumentCommissionRate);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryMMOptionInstrCommRate(CThostFtdcMMOptionInstrCommRateField *MMOptionInstrCommRate, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryMMOptionInstrCommRate: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteMMOptionInstrCommRate(MMOptionInstrCommRate);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryInstrumentOrderCommRate(CThostFtdcInstrumentOrderCommRateField *InstrumentOrderCommRate, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryInstrumentOrderCommRate: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteInstrumentOrderCommRate(InstrumentOrderCommRate);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQrySecAgentTradingAccount(CThostFtdcTradingAccountField *TradingAccount, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQrySecAgentTradingAccount: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteTradingAccount(TradingAccount);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQrySecAgentCheckMode(CThostFtdcSecAgentCheckModeField *SecAgentCheckMode, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQrySecAgentCheckMode: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteSecAgentCheckMode(SecAgentCheckMode);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQrySecAgentTradeInfo(CThostFtdcSecAgentTradeInfoField *SecAgentTradeInfo, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQrySecAgentTradeInfo: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteSecAgentTradeInfo(SecAgentTradeInfo);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryOptionInstrTradeCost(CThostFtdcOptionInstrTradeCostField *OptionInstrTradeCost, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryOptionInstrTradeCost: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteOptionInstrTradeCost(OptionInstrTradeCost);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryOptionInstrCommRate(CThostFtdcOptionInstrCommRateField *OptionInstrCommRate, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryOptionInstrCommRate: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteOptionInstrCommRate(OptionInstrCommRate);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryExecOrder(CThostFtdcExecOrderField *ExecOrder, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryExecOrder: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteExecOrder(ExecOrder);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryForQuote(CThostFtdcForQuoteField *ForQuote, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryForQuote: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteForQuote(ForQuote);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryQuote(CThostFtdcQuoteField *Quote, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryQuote: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteQuote(Quote);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryOptionSelfClose(CThostFtdcOptionSelfCloseField *OptionSelfClose, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryOptionSelfClose: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteOptionSelfClose(OptionSelfClose);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryInvestUnit(CThostFtdcInvestUnitField *InvestUnit, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryInvestUnit: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteInvestUnit(InvestUnit);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryCombInstrumentGuard(CThostFtdcCombInstrumentGuardField *CombInstrumentGuard, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryCombInstrumentGuard: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteCombInstrumentGuard(CombInstrumentGuard);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryCombAction(CThostFtdcCombActionField *CombAction, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryCombAction: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteCombAction(CombAction);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryTransferSerial(CThostFtdcTransferSerialField *TransferSerial, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryTransferSerial: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteTransferSerial(TransferSerial);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryAccountregister(CThostFtdcAccountregisterField *Accountregister, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryAccountregister: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteAccountregister(Accountregister);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspError(CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspError: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRtnOrder(CThostFtdcOrderField *Order)
{
	WRITE_LOG(LogLevel::Info, "OnRtnOrder:");
	WriteOrder(Order);
}

void CThostFtdcTraderSpiMiddle::OnRtnTrade(CThostFtdcTradeField *Trade)
{
	WRITE_LOG(LogLevel::Info, "OnRtnTrade:");
	WriteTrade(Trade);
}

void CThostFtdcTraderSpiMiddle::OnErrRtnOrderInsert(CThostFtdcInputOrderField *InputOrder, CThostFtdcRspInfoField *RspInfo)
{
	WRITE_LOG(LogLevel::Info, "OnErrRtnOrderInsert:");
	WriteInputOrder(InputOrder);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnErrRtnOrderAction(CThostFtdcOrderActionField *OrderAction, CThostFtdcRspInfoField *RspInfo)
{
	WRITE_LOG(LogLevel::Info, "OnErrRtnOrderAction:");
	WriteOrderAction(OrderAction);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRtnInstrumentStatus(CThostFtdcInstrumentStatusField *InstrumentStatus)
{
	WRITE_LOG(LogLevel::Info, "OnRtnInstrumentStatus:");
	WriteInstrumentStatus(InstrumentStatus);
}

void CThostFtdcTraderSpiMiddle::OnRtnBulletin(CThostFtdcBulletinField *Bulletin)
{
	WRITE_LOG(LogLevel::Info, "OnRtnBulletin:");
	WriteBulletin(Bulletin);
}

void CThostFtdcTraderSpiMiddle::OnRtnTradingNotice(CThostFtdcTradingNoticeInfoField *TradingNoticeInfo)
{
	WRITE_LOG(LogLevel::Info, "OnRtnTradingNotice:");
	WriteTradingNoticeInfo(TradingNoticeInfo);
}

void CThostFtdcTraderSpiMiddle::OnRtnErrorConditionalOrder(CThostFtdcErrorConditionalOrderField *ErrorConditionalOrder)
{
	WRITE_LOG(LogLevel::Info, "OnRtnErrorConditionalOrder:");
	WriteErrorConditionalOrder(ErrorConditionalOrder);
}

void CThostFtdcTraderSpiMiddle::OnRtnExecOrder(CThostFtdcExecOrderField *ExecOrder)
{
	WRITE_LOG(LogLevel::Info, "OnRtnExecOrder:");
	WriteExecOrder(ExecOrder);
}

void CThostFtdcTraderSpiMiddle::OnErrRtnExecOrderInsert(CThostFtdcInputExecOrderField *InputExecOrder, CThostFtdcRspInfoField *RspInfo)
{
	WRITE_LOG(LogLevel::Info, "OnErrRtnExecOrderInsert:");
	WriteInputExecOrder(InputExecOrder);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnErrRtnExecOrderAction(CThostFtdcExecOrderActionField *ExecOrderAction, CThostFtdcRspInfoField *RspInfo)
{
	WRITE_LOG(LogLevel::Info, "OnErrRtnExecOrderAction:");
	WriteExecOrderAction(ExecOrderAction);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnErrRtnForQuoteInsert(CThostFtdcInputForQuoteField *InputForQuote, CThostFtdcRspInfoField *RspInfo)
{
	WRITE_LOG(LogLevel::Info, "OnErrRtnForQuoteInsert:");
	WriteInputForQuote(InputForQuote);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRtnQuote(CThostFtdcQuoteField *Quote)
{
	WRITE_LOG(LogLevel::Info, "OnRtnQuote:");
	WriteQuote(Quote);
}

void CThostFtdcTraderSpiMiddle::OnErrRtnQuoteInsert(CThostFtdcInputQuoteField *InputQuote, CThostFtdcRspInfoField *RspInfo)
{
	WRITE_LOG(LogLevel::Info, "OnErrRtnQuoteInsert:");
	WriteInputQuote(InputQuote);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnErrRtnQuoteAction(CThostFtdcQuoteActionField *QuoteAction, CThostFtdcRspInfoField *RspInfo)
{
	WRITE_LOG(LogLevel::Info, "OnErrRtnQuoteAction:");
	WriteQuoteAction(QuoteAction);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *ForQuoteRsp)
{
	WRITE_LOG(LogLevel::Info, "OnRtnForQuoteRsp:");
	WriteForQuoteRsp(ForQuoteRsp);
}

void CThostFtdcTraderSpiMiddle::OnRtnCFMMCTradingAccountToken(CThostFtdcCFMMCTradingAccountTokenField *CFMMCTradingAccountToken)
{
	WRITE_LOG(LogLevel::Info, "OnRtnCFMMCTradingAccountToken:");
	WriteCFMMCTradingAccountToken(CFMMCTradingAccountToken);
}

void CThostFtdcTraderSpiMiddle::OnErrRtnBatchOrderAction(CThostFtdcBatchOrderActionField *BatchOrderAction, CThostFtdcRspInfoField *RspInfo)
{
	WRITE_LOG(LogLevel::Info, "OnErrRtnBatchOrderAction:");
	WriteBatchOrderAction(BatchOrderAction);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRtnOptionSelfClose(CThostFtdcOptionSelfCloseField *OptionSelfClose)
{
	WRITE_LOG(LogLevel::Info, "OnRtnOptionSelfClose:");
	WriteOptionSelfClose(OptionSelfClose);
}

void CThostFtdcTraderSpiMiddle::OnErrRtnOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField *InputOptionSelfClose, CThostFtdcRspInfoField *RspInfo)
{
	WRITE_LOG(LogLevel::Info, "OnErrRtnOptionSelfCloseInsert:");
	WriteInputOptionSelfClose(InputOptionSelfClose);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnErrRtnOptionSelfCloseAction(CThostFtdcOptionSelfCloseActionField *OptionSelfCloseAction, CThostFtdcRspInfoField *RspInfo)
{
	WRITE_LOG(LogLevel::Info, "OnErrRtnOptionSelfCloseAction:");
	WriteOptionSelfCloseAction(OptionSelfCloseAction);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRtnCombAction(CThostFtdcCombActionField *CombAction)
{
	WRITE_LOG(LogLevel::Info, "OnRtnCombAction:");
	WriteCombAction(CombAction);
}

void CThostFtdcTraderSpiMiddle::OnErrRtnCombActionInsert(CThostFtdcInputCombActionField *InputCombAction, CThostFtdcRspInfoField *RspInfo)
{
	WRITE_LOG(LogLevel::Info, "OnErrRtnCombActionInsert:");
	WriteInputCombAction(InputCombAction);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryContractBank(CThostFtdcContractBankField *ContractBank, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryContractBank: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteContractBank(ContractBank);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryParkedOrder(CThostFtdcParkedOrderField *ParkedOrder, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryParkedOrder: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteParkedOrder(ParkedOrder);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryParkedOrderAction(CThostFtdcParkedOrderActionField *ParkedOrderAction, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryParkedOrderAction: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteParkedOrderAction(ParkedOrderAction);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryTradingNotice(CThostFtdcTradingNoticeField *TradingNotice, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryTradingNotice: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteTradingNotice(TradingNotice);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryBrokerTradingParams(CThostFtdcBrokerTradingParamsField *BrokerTradingParams, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryBrokerTradingParams: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteBrokerTradingParams(BrokerTradingParams);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryBrokerTradingAlgos(CThostFtdcBrokerTradingAlgosField *BrokerTradingAlgos, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryBrokerTradingAlgos: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteBrokerTradingAlgos(BrokerTradingAlgos);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQueryCFMMCTradingAccountToken(CThostFtdcQueryCFMMCTradingAccountTokenField *QueryCFMMCTradingAccountToken, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQueryCFMMCTradingAccountToken: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteQueryCFMMCTradingAccountToken(QueryCFMMCTradingAccountToken);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRtnFromBankToFutureByBank(CThostFtdcRspTransferField *RspTransfer)
{
	WRITE_LOG(LogLevel::Info, "OnRtnFromBankToFutureByBank:");
	WriteRspTransfer(RspTransfer);
}

void CThostFtdcTraderSpiMiddle::OnRtnFromFutureToBankByBank(CThostFtdcRspTransferField *RspTransfer)
{
	WRITE_LOG(LogLevel::Info, "OnRtnFromFutureToBankByBank:");
	WriteRspTransfer(RspTransfer);
}

void CThostFtdcTraderSpiMiddle::OnRtnRepealFromBankToFutureByBank(CThostFtdcRspRepealField *RspRepeal)
{
	WRITE_LOG(LogLevel::Info, "OnRtnRepealFromBankToFutureByBank:");
	WriteRspRepeal(RspRepeal);
}

void CThostFtdcTraderSpiMiddle::OnRtnRepealFromFutureToBankByBank(CThostFtdcRspRepealField *RspRepeal)
{
	WRITE_LOG(LogLevel::Info, "OnRtnRepealFromFutureToBankByBank:");
	WriteRspRepeal(RspRepeal);
}

void CThostFtdcTraderSpiMiddle::OnRtnFromBankToFutureByFuture(CThostFtdcRspTransferField *RspTransfer)
{
	WRITE_LOG(LogLevel::Info, "OnRtnFromBankToFutureByFuture:");
	WriteRspTransfer(RspTransfer);
}

void CThostFtdcTraderSpiMiddle::OnRtnFromFutureToBankByFuture(CThostFtdcRspTransferField *RspTransfer)
{
	WRITE_LOG(LogLevel::Info, "OnRtnFromFutureToBankByFuture:");
	WriteRspTransfer(RspTransfer);
}

void CThostFtdcTraderSpiMiddle::OnRtnRepealFromBankToFutureByFutureManual(CThostFtdcRspRepealField *RspRepeal)
{
	WRITE_LOG(LogLevel::Info, "OnRtnRepealFromBankToFutureByFutureManual:");
	WriteRspRepeal(RspRepeal);
}

void CThostFtdcTraderSpiMiddle::OnRtnRepealFromFutureToBankByFutureManual(CThostFtdcRspRepealField *RspRepeal)
{
	WRITE_LOG(LogLevel::Info, "OnRtnRepealFromFutureToBankByFutureManual:");
	WriteRspRepeal(RspRepeal);
}

void CThostFtdcTraderSpiMiddle::OnRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField *NotifyQueryAccount)
{
	WRITE_LOG(LogLevel::Info, "OnRtnQueryBankBalanceByFuture:");
	WriteNotifyQueryAccount(NotifyQueryAccount);
}

void CThostFtdcTraderSpiMiddle::OnErrRtnBankToFutureByFuture(CThostFtdcReqTransferField *ReqTransfer, CThostFtdcRspInfoField *RspInfo)
{
	WRITE_LOG(LogLevel::Info, "OnErrRtnBankToFutureByFuture:");
	WriteReqTransfer(ReqTransfer);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnErrRtnFutureToBankByFuture(CThostFtdcReqTransferField *ReqTransfer, CThostFtdcRspInfoField *RspInfo)
{
	WRITE_LOG(LogLevel::Info, "OnErrRtnFutureToBankByFuture:");
	WriteReqTransfer(ReqTransfer);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnErrRtnRepealBankToFutureByFutureManual(CThostFtdcReqRepealField *ReqRepeal, CThostFtdcRspInfoField *RspInfo)
{
	WRITE_LOG(LogLevel::Info, "OnErrRtnRepealBankToFutureByFutureManual:");
	WriteReqRepeal(ReqRepeal);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnErrRtnRepealFutureToBankByFutureManual(CThostFtdcReqRepealField *ReqRepeal, CThostFtdcRspInfoField *RspInfo)
{
	WRITE_LOG(LogLevel::Info, "OnErrRtnRepealFutureToBankByFutureManual:");
	WriteReqRepeal(ReqRepeal);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnErrRtnQueryBankBalanceByFuture(CThostFtdcReqQueryAccountField *ReqQueryAccount, CThostFtdcRspInfoField *RspInfo)
{
	WRITE_LOG(LogLevel::Info, "OnErrRtnQueryBankBalanceByFuture:");
	WriteReqQueryAccount(ReqQueryAccount);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRtnRepealFromBankToFutureByFuture(CThostFtdcRspRepealField *RspRepeal)
{
	WRITE_LOG(LogLevel::Info, "OnRtnRepealFromBankToFutureByFuture:");
	WriteRspRepeal(RspRepeal);
}

void CThostFtdcTraderSpiMiddle::OnRtnRepealFromFutureToBankByFuture(CThostFtdcRspRepealField *RspRepeal)
{
	WRITE_LOG(LogLevel::Info, "OnRtnRepealFromFutureToBankByFuture:");
	WriteRspRepeal(RspRepeal);
}

void CThostFtdcTraderSpiMiddle::OnRspFromBankToFutureByFuture(CThostFtdcReqTransferField *ReqTransfer, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspFromBankToFutureByFuture: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteReqTransfer(ReqTransfer);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspFromFutureToBankByFuture(CThostFtdcReqTransferField *ReqTransfer, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspFromFutureToBankByFuture: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteReqTransfer(ReqTransfer);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField *ReqQueryAccount, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQueryBankAccountMoneyByFuture: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteReqQueryAccount(ReqQueryAccount);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRtnOpenAccountByBank(CThostFtdcOpenAccountField *OpenAccount)
{
	WRITE_LOG(LogLevel::Info, "OnRtnOpenAccountByBank:");
	WriteOpenAccount(OpenAccount);
}

void CThostFtdcTraderSpiMiddle::OnRtnCancelAccountByBank(CThostFtdcCancelAccountField *CancelAccount)
{
	WRITE_LOG(LogLevel::Info, "OnRtnCancelAccountByBank:");
	WriteCancelAccount(CancelAccount);
}

void CThostFtdcTraderSpiMiddle::OnRtnChangeAccountByBank(CThostFtdcChangeAccountField *ChangeAccount)
{
	WRITE_LOG(LogLevel::Info, "OnRtnChangeAccountByBank:");
	WriteChangeAccount(ChangeAccount);
}

void CThostFtdcTraderSpiMiddle::OnRspQryClassifiedInstrument(CThostFtdcInstrumentField *Instrument, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryClassifiedInstrument: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteInstrument(Instrument);
	WriteRspInfo(RspInfo);
}

void CThostFtdcTraderSpiMiddle::OnRspQryCombPromotionParam(CThostFtdcCombPromotionParamField *CombPromotionParam, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast)
{
	WRITE_LOG(LogLevel::Info, "OnRspQryCombPromotionParam: nRequestID[%d] bIsLast[%d]", nRequestID, bIsLast);
	WriteCombPromotionParam(CombPromotionParam);
	WriteRspInfo(RspInfo);
}

