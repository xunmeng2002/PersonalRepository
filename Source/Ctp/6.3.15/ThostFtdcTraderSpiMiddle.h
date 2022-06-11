#pragma once
#include "ThostFtdcTraderApi.h"


class CThostFtdcTraderSpiMiddle : public CThostFtdcTraderSpi
{
public:
	virtual void OnFrontConnected();

	virtual void OnFrontDisconnected(int nReason);

	virtual void OnHeartBeatWarning(int nTimeLapse);

	virtual void OnRspAuthenticate(CThostFtdcRspAuthenticateField *RspAuthenticate, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *RspUserLogin, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspUserLogout(CThostFtdcUserLogoutField *UserLogout, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField *UserPasswordUpdate, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField *TradingAccountPasswordUpdate, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspUserAuthMethod(CThostFtdcRspUserAuthMethodField *RspUserAuthMethod, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspGenUserCaptcha(CThostFtdcRspGenUserCaptchaField *RspGenUserCaptcha, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspGenUserText(CThostFtdcRspGenUserTextField *RspGenUserText, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspOrderInsert(CThostFtdcInputOrderField *InputOrder, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspParkedOrderInsert(CThostFtdcParkedOrderField *ParkedOrder, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspParkedOrderAction(CThostFtdcParkedOrderActionField *ParkedOrderAction, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspOrderAction(CThostFtdcInputOrderActionField *InputOrderAction, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQueryMaxOrderVolume(CThostFtdcQueryMaxOrderVolumeField *QueryMaxOrderVolume, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *SettlementInfoConfirm, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspRemoveParkedOrder(CThostFtdcRemoveParkedOrderField *RemoveParkedOrder, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField *RemoveParkedOrderAction, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspExecOrderInsert(CThostFtdcInputExecOrderField *InputExecOrder, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspExecOrderAction(CThostFtdcInputExecOrderActionField *InputExecOrderAction, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspForQuoteInsert(CThostFtdcInputForQuoteField *InputForQuote, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQuoteInsert(CThostFtdcInputQuoteField *InputQuote, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQuoteAction(CThostFtdcInputQuoteActionField *InputQuoteAction, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspBatchOrderAction(CThostFtdcInputBatchOrderActionField *InputBatchOrderAction, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField *InputOptionSelfClose, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspOptionSelfCloseAction(CThostFtdcInputOptionSelfCloseActionField *InputOptionSelfCloseAction, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspCombActionInsert(CThostFtdcInputCombActionField *InputCombAction, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQryOrder(CThostFtdcOrderField *Order, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQryTrade(CThostFtdcTradeField *Trade, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *InvestorPosition, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQryTradingAccount(CThostFtdcTradingAccountField *TradingAccount, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQryInvestor(CThostFtdcInvestorField *Investor, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQryTradingCode(CThostFtdcTradingCodeField *TradingCode, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField *InstrumentMarginRate, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField *InstrumentCommissionRate, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQryExchange(CThostFtdcExchangeField *Exchange, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQryProduct(CThostFtdcProductField *Product, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQryInstrument(CThostFtdcInstrumentField *Instrument, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField *DepthMarketData, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQrySettlementInfo(CThostFtdcSettlementInfoField *SettlementInfo, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQryTransferBank(CThostFtdcTransferBankField *TransferBank, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField *InvestorPositionDetail, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQryNotice(CThostFtdcNoticeField *Notice, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *SettlementInfoConfirm, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField *InvestorPositionCombineDetail, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQryCFMMCTradingAccountKey(CThostFtdcCFMMCTradingAccountKeyField *CFMMCTradingAccountKey, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQryEWarrantOffset(CThostFtdcEWarrantOffsetField *EWarrantOffset, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQryInvestorProductGroupMargin(CThostFtdcInvestorProductGroupMarginField *InvestorProductGroupMargin, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQryExchangeMarginRate(CThostFtdcExchangeMarginRateField *ExchangeMarginRate, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQryExchangeMarginRateAdjust(CThostFtdcExchangeMarginRateAdjustField *ExchangeMarginRateAdjust, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQryExchangeRate(CThostFtdcExchangeRateField *ExchangeRate, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQrySecAgentACIDMap(CThostFtdcSecAgentACIDMapField *SecAgentACIDMap, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQryProductExchRate(CThostFtdcProductExchRateField *ProductExchRate, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQryProductGroup(CThostFtdcProductGroupField *ProductGroup, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQryMMInstrumentCommissionRate(CThostFtdcMMInstrumentCommissionRateField *MMInstrumentCommissionRate, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQryMMOptionInstrCommRate(CThostFtdcMMOptionInstrCommRateField *MMOptionInstrCommRate, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQryInstrumentOrderCommRate(CThostFtdcInstrumentOrderCommRateField *InstrumentOrderCommRate, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQrySecAgentTradingAccount(CThostFtdcTradingAccountField *TradingAccount, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQrySecAgentCheckMode(CThostFtdcSecAgentCheckModeField *SecAgentCheckMode, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQrySecAgentTradeInfo(CThostFtdcSecAgentTradeInfoField *SecAgentTradeInfo, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQryOptionInstrTradeCost(CThostFtdcOptionInstrTradeCostField *OptionInstrTradeCost, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQryOptionInstrCommRate(CThostFtdcOptionInstrCommRateField *OptionInstrCommRate, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQryExecOrder(CThostFtdcExecOrderField *ExecOrder, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQryForQuote(CThostFtdcForQuoteField *ForQuote, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQryQuote(CThostFtdcQuoteField *Quote, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQryOptionSelfClose(CThostFtdcOptionSelfCloseField *OptionSelfClose, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQryInvestUnit(CThostFtdcInvestUnitField *InvestUnit, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQryCombInstrumentGuard(CThostFtdcCombInstrumentGuardField *CombInstrumentGuard, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQryCombAction(CThostFtdcCombActionField *CombAction, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQryTransferSerial(CThostFtdcTransferSerialField *TransferSerial, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQryAccountregister(CThostFtdcAccountregisterField *Accountregister, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspError(CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRtnOrder(CThostFtdcOrderField *Order);

	virtual void OnRtnTrade(CThostFtdcTradeField *Trade);

	virtual void OnErrRtnOrderInsert(CThostFtdcInputOrderField *InputOrder, CThostFtdcRspInfoField *RspInfo);

	virtual void OnErrRtnOrderAction(CThostFtdcOrderActionField *OrderAction, CThostFtdcRspInfoField *RspInfo);

	virtual void OnRtnInstrumentStatus(CThostFtdcInstrumentStatusField *InstrumentStatus);

	virtual void OnRtnBulletin(CThostFtdcBulletinField *Bulletin);

	virtual void OnRtnTradingNotice(CThostFtdcTradingNoticeInfoField *TradingNoticeInfo);

	virtual void OnRtnErrorConditionalOrder(CThostFtdcErrorConditionalOrderField *ErrorConditionalOrder);

	virtual void OnRtnExecOrder(CThostFtdcExecOrderField *ExecOrder);

	virtual void OnErrRtnExecOrderInsert(CThostFtdcInputExecOrderField *InputExecOrder, CThostFtdcRspInfoField *RspInfo);

	virtual void OnErrRtnExecOrderAction(CThostFtdcExecOrderActionField *ExecOrderAction, CThostFtdcRspInfoField *RspInfo);

	virtual void OnErrRtnForQuoteInsert(CThostFtdcInputForQuoteField *InputForQuote, CThostFtdcRspInfoField *RspInfo);

	virtual void OnRtnQuote(CThostFtdcQuoteField *Quote);

	virtual void OnErrRtnQuoteInsert(CThostFtdcInputQuoteField *InputQuote, CThostFtdcRspInfoField *RspInfo);

	virtual void OnErrRtnQuoteAction(CThostFtdcQuoteActionField *QuoteAction, CThostFtdcRspInfoField *RspInfo);

	virtual void OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *ForQuoteRsp);

	virtual void OnRtnCFMMCTradingAccountToken(CThostFtdcCFMMCTradingAccountTokenField *CFMMCTradingAccountToken);

	virtual void OnErrRtnBatchOrderAction(CThostFtdcBatchOrderActionField *BatchOrderAction, CThostFtdcRspInfoField *RspInfo);

	virtual void OnRtnOptionSelfClose(CThostFtdcOptionSelfCloseField *OptionSelfClose);

	virtual void OnErrRtnOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField *InputOptionSelfClose, CThostFtdcRspInfoField *RspInfo);

	virtual void OnErrRtnOptionSelfCloseAction(CThostFtdcOptionSelfCloseActionField *OptionSelfCloseAction, CThostFtdcRspInfoField *RspInfo);

	virtual void OnRtnCombAction(CThostFtdcCombActionField *CombAction);

	virtual void OnErrRtnCombActionInsert(CThostFtdcInputCombActionField *InputCombAction, CThostFtdcRspInfoField *RspInfo);

	virtual void OnRspQryContractBank(CThostFtdcContractBankField *ContractBank, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQryParkedOrder(CThostFtdcParkedOrderField *ParkedOrder, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQryParkedOrderAction(CThostFtdcParkedOrderActionField *ParkedOrderAction, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQryTradingNotice(CThostFtdcTradingNoticeField *TradingNotice, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQryBrokerTradingParams(CThostFtdcBrokerTradingParamsField *BrokerTradingParams, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQryBrokerTradingAlgos(CThostFtdcBrokerTradingAlgosField *BrokerTradingAlgos, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQueryCFMMCTradingAccountToken(CThostFtdcQueryCFMMCTradingAccountTokenField *QueryCFMMCTradingAccountToken, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRtnFromBankToFutureByBank(CThostFtdcRspTransferField *RspTransfer);

	virtual void OnRtnFromFutureToBankByBank(CThostFtdcRspTransferField *RspTransfer);

	virtual void OnRtnRepealFromBankToFutureByBank(CThostFtdcRspRepealField *RspRepeal);

	virtual void OnRtnRepealFromFutureToBankByBank(CThostFtdcRspRepealField *RspRepeal);

	virtual void OnRtnFromBankToFutureByFuture(CThostFtdcRspTransferField *RspTransfer);

	virtual void OnRtnFromFutureToBankByFuture(CThostFtdcRspTransferField *RspTransfer);

	virtual void OnRtnRepealFromBankToFutureByFutureManual(CThostFtdcRspRepealField *RspRepeal);

	virtual void OnRtnRepealFromFutureToBankByFutureManual(CThostFtdcRspRepealField *RspRepeal);

	virtual void OnRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField *NotifyQueryAccount);

	virtual void OnErrRtnBankToFutureByFuture(CThostFtdcReqTransferField *ReqTransfer, CThostFtdcRspInfoField *RspInfo);

	virtual void OnErrRtnFutureToBankByFuture(CThostFtdcReqTransferField *ReqTransfer, CThostFtdcRspInfoField *RspInfo);

	virtual void OnErrRtnRepealBankToFutureByFutureManual(CThostFtdcReqRepealField *ReqRepeal, CThostFtdcRspInfoField *RspInfo);

	virtual void OnErrRtnRepealFutureToBankByFutureManual(CThostFtdcReqRepealField *ReqRepeal, CThostFtdcRspInfoField *RspInfo);

	virtual void OnErrRtnQueryBankBalanceByFuture(CThostFtdcReqQueryAccountField *ReqQueryAccount, CThostFtdcRspInfoField *RspInfo);

	virtual void OnRtnRepealFromBankToFutureByFuture(CThostFtdcRspRepealField *RspRepeal);

	virtual void OnRtnRepealFromFutureToBankByFuture(CThostFtdcRspRepealField *RspRepeal);

	virtual void OnRspFromBankToFutureByFuture(CThostFtdcReqTransferField *ReqTransfer, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspFromFutureToBankByFuture(CThostFtdcReqTransferField *ReqTransfer, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRspQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField *ReqQueryAccount, CThostFtdcRspInfoField *RspInfo, int nRequestID, bool bIsLast);

	virtual void OnRtnOpenAccountByBank(CThostFtdcOpenAccountField *OpenAccount);

	virtual void OnRtnCancelAccountByBank(CThostFtdcCancelAccountField *CancelAccount);

	virtual void OnRtnChangeAccountByBank(CThostFtdcChangeAccountField *ChangeAccount);

};