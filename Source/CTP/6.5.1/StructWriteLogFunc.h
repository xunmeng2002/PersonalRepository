﻿#pragma once
#include "ThostFtdcUserApiStruct.h"

void WriteDissemination(CThostFtdcDisseminationField* Dissemination);

void WriteReqUserLogin(CThostFtdcReqUserLoginField* ReqUserLogin);

void WriteRspUserLogin(CThostFtdcRspUserLoginField* RspUserLogin);

void WriteUserLogout(CThostFtdcUserLogoutField* UserLogout);

void WriteForceUserLogout(CThostFtdcForceUserLogoutField* ForceUserLogout);

void WriteReqAuthenticate(CThostFtdcReqAuthenticateField* ReqAuthenticate);

void WriteRspAuthenticate(CThostFtdcRspAuthenticateField* RspAuthenticate);

void WriteAuthenticationInfo(CThostFtdcAuthenticationInfoField* AuthenticationInfo);

void WriteRspUserLogin2(CThostFtdcRspUserLogin2Field* RspUserLogin2);

void WriteTransferHeader(CThostFtdcTransferHeaderField* TransferHeader);

void WriteTransferBankToFutureReq(CThostFtdcTransferBankToFutureReqField* TransferBankToFutureReq);

void WriteTransferBankToFutureRsp(CThostFtdcTransferBankToFutureRspField* TransferBankToFutureRsp);

void WriteTransferFutureToBankReq(CThostFtdcTransferFutureToBankReqField* TransferFutureToBankReq);

void WriteTransferFutureToBankRsp(CThostFtdcTransferFutureToBankRspField* TransferFutureToBankRsp);

void WriteTransferQryBankReq(CThostFtdcTransferQryBankReqField* TransferQryBankReq);

void WriteTransferQryBankRsp(CThostFtdcTransferQryBankRspField* TransferQryBankRsp);

void WriteTransferQryDetailReq(CThostFtdcTransferQryDetailReqField* TransferQryDetailReq);

void WriteTransferQryDetailRsp(CThostFtdcTransferQryDetailRspField* TransferQryDetailRsp);

void WriteRspInfo(CThostFtdcRspInfoField* RspInfo);

void WriteExchange(CThostFtdcExchangeField* Exchange);

void WriteProduct(CThostFtdcProductField* Product);

void WriteInstrument(CThostFtdcInstrumentField* Instrument);

void WriteBroker(CThostFtdcBrokerField* Broker);

void WriteTrader(CThostFtdcTraderField* Trader);

void WriteInvestor(CThostFtdcInvestorField* Investor);

void WriteTradingCode(CThostFtdcTradingCodeField* TradingCode);

void WritePartBroker(CThostFtdcPartBrokerField* PartBroker);

void WriteSuperUser(CThostFtdcSuperUserField* SuperUser);

void WriteSuperUserFunction(CThostFtdcSuperUserFunctionField* SuperUserFunction);

void WriteInvestorGroup(CThostFtdcInvestorGroupField* InvestorGroup);

void WriteTradingAccount(CThostFtdcTradingAccountField* TradingAccount);

void WriteInvestorPosition(CThostFtdcInvestorPositionField* InvestorPosition);

void WriteInstrumentMarginRate(CThostFtdcInstrumentMarginRateField* InstrumentMarginRate);

void WriteInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField* InstrumentCommissionRate);

void WriteDepthMarketData(CThostFtdcDepthMarketDataField* DepthMarketData);

void WriteInstrumentTradingRight(CThostFtdcInstrumentTradingRightField* InstrumentTradingRight);

void WriteBrokerUser(CThostFtdcBrokerUserField* BrokerUser);

void WriteBrokerUserPassword(CThostFtdcBrokerUserPasswordField* BrokerUserPassword);

void WriteBrokerUserFunction(CThostFtdcBrokerUserFunctionField* BrokerUserFunction);

void WriteTraderOffer(CThostFtdcTraderOfferField* TraderOffer);

void WriteSettlementInfo(CThostFtdcSettlementInfoField* SettlementInfo);

void WriteInstrumentMarginRateAdjust(CThostFtdcInstrumentMarginRateAdjustField* InstrumentMarginRateAdjust);

void WriteExchangeMarginRate(CThostFtdcExchangeMarginRateField* ExchangeMarginRate);

void WriteExchangeMarginRateAdjust(CThostFtdcExchangeMarginRateAdjustField* ExchangeMarginRateAdjust);

void WriteExchangeRate(CThostFtdcExchangeRateField* ExchangeRate);

void WriteSettlementRef(CThostFtdcSettlementRefField* SettlementRef);

void WriteCurrentTime(CThostFtdcCurrentTimeField* CurrentTime);

void WriteCommPhase(CThostFtdcCommPhaseField* CommPhase);

void WriteLoginInfo(CThostFtdcLoginInfoField* LoginInfo);

void WriteLogoutAll(CThostFtdcLogoutAllField* LogoutAll);

void WriteFrontStatus(CThostFtdcFrontStatusField* FrontStatus);

void WriteUserPasswordUpdate(CThostFtdcUserPasswordUpdateField* UserPasswordUpdate);

void WriteInputOrder(CThostFtdcInputOrderField* InputOrder);

void WriteOrder(CThostFtdcOrderField* Order);

void WriteExchangeOrder(CThostFtdcExchangeOrderField* ExchangeOrder);

void WriteExchangeOrderInsertError(CThostFtdcExchangeOrderInsertErrorField* ExchangeOrderInsertError);

void WriteInputOrderAction(CThostFtdcInputOrderActionField* InputOrderAction);

void WriteOrderAction(CThostFtdcOrderActionField* OrderAction);

void WriteExchangeOrderAction(CThostFtdcExchangeOrderActionField* ExchangeOrderAction);

void WriteExchangeOrderActionError(CThostFtdcExchangeOrderActionErrorField* ExchangeOrderActionError);

void WriteExchangeTrade(CThostFtdcExchangeTradeField* ExchangeTrade);

void WriteTrade(CThostFtdcTradeField* Trade);

void WriteUserSession(CThostFtdcUserSessionField* UserSession);

void WriteQryMaxOrderVolume(CThostFtdcQryMaxOrderVolumeField* QryMaxOrderVolume);

void WriteSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField* SettlementInfoConfirm);

void WriteSyncDeposit(CThostFtdcSyncDepositField* SyncDeposit);

void WriteSyncFundMortgage(CThostFtdcSyncFundMortgageField* SyncFundMortgage);

void WriteBrokerSync(CThostFtdcBrokerSyncField* BrokerSync);

void WriteSyncingInvestor(CThostFtdcSyncingInvestorField* SyncingInvestor);

void WriteSyncingTradingCode(CThostFtdcSyncingTradingCodeField* SyncingTradingCode);

void WriteSyncingInvestorGroup(CThostFtdcSyncingInvestorGroupField* SyncingInvestorGroup);

void WriteSyncingTradingAccount(CThostFtdcSyncingTradingAccountField* SyncingTradingAccount);

void WriteSyncingInvestorPosition(CThostFtdcSyncingInvestorPositionField* SyncingInvestorPosition);

void WriteSyncingInstrumentMarginRate(CThostFtdcSyncingInstrumentMarginRateField* SyncingInstrumentMarginRate);

void WriteSyncingInstrumentCommissionRate(CThostFtdcSyncingInstrumentCommissionRateField* SyncingInstrumentCommissionRate);

void WriteSyncingInstrumentTradingRight(CThostFtdcSyncingInstrumentTradingRightField* SyncingInstrumentTradingRight);

void WriteQryOrder(CThostFtdcQryOrderField* QryOrder);

void WriteQryTrade(CThostFtdcQryTradeField* QryTrade);

void WriteQryInvestorPosition(CThostFtdcQryInvestorPositionField* QryInvestorPosition);

void WriteQryTradingAccount(CThostFtdcQryTradingAccountField* QryTradingAccount);

void WriteQryInvestor(CThostFtdcQryInvestorField* QryInvestor);

void WriteQryTradingCode(CThostFtdcQryTradingCodeField* QryTradingCode);

void WriteQryInvestorGroup(CThostFtdcQryInvestorGroupField* QryInvestorGroup);

void WriteQryInstrumentMarginRate(CThostFtdcQryInstrumentMarginRateField* QryInstrumentMarginRate);

void WriteQryInstrumentCommissionRate(CThostFtdcQryInstrumentCommissionRateField* QryInstrumentCommissionRate);

void WriteQryInstrumentTradingRight(CThostFtdcQryInstrumentTradingRightField* QryInstrumentTradingRight);

void WriteQryBroker(CThostFtdcQryBrokerField* QryBroker);

void WriteQryTrader(CThostFtdcQryTraderField* QryTrader);

void WriteQrySuperUserFunction(CThostFtdcQrySuperUserFunctionField* QrySuperUserFunction);

void WriteQryUserSession(CThostFtdcQryUserSessionField* QryUserSession);

void WriteQryPartBroker(CThostFtdcQryPartBrokerField* QryPartBroker);

void WriteQryFrontStatus(CThostFtdcQryFrontStatusField* QryFrontStatus);

void WriteQryExchangeOrder(CThostFtdcQryExchangeOrderField* QryExchangeOrder);

void WriteQryOrderAction(CThostFtdcQryOrderActionField* QryOrderAction);

void WriteQryExchangeOrderAction(CThostFtdcQryExchangeOrderActionField* QryExchangeOrderAction);

void WriteQrySuperUser(CThostFtdcQrySuperUserField* QrySuperUser);

void WriteQryExchange(CThostFtdcQryExchangeField* QryExchange);

void WriteQryProduct(CThostFtdcQryProductField* QryProduct);

void WriteQryInstrument(CThostFtdcQryInstrumentField* QryInstrument);

void WriteQryDepthMarketData(CThostFtdcQryDepthMarketDataField* QryDepthMarketData);

void WriteQryBrokerUser(CThostFtdcQryBrokerUserField* QryBrokerUser);

void WriteQryBrokerUserFunction(CThostFtdcQryBrokerUserFunctionField* QryBrokerUserFunction);

void WriteQryTraderOffer(CThostFtdcQryTraderOfferField* QryTraderOffer);

void WriteQrySyncDeposit(CThostFtdcQrySyncDepositField* QrySyncDeposit);

void WriteQrySettlementInfo(CThostFtdcQrySettlementInfoField* QrySettlementInfo);

void WriteQryExchangeMarginRate(CThostFtdcQryExchangeMarginRateField* QryExchangeMarginRate);

void WriteQryExchangeMarginRateAdjust(CThostFtdcQryExchangeMarginRateAdjustField* QryExchangeMarginRateAdjust);

void WriteQryExchangeRate(CThostFtdcQryExchangeRateField* QryExchangeRate);

void WriteQrySyncFundMortgage(CThostFtdcQrySyncFundMortgageField* QrySyncFundMortgage);

void WriteQryHisOrder(CThostFtdcQryHisOrderField* QryHisOrder);

void WriteOptionInstrMiniMargin(CThostFtdcOptionInstrMiniMarginField* OptionInstrMiniMargin);

void WriteOptionInstrMarginAdjust(CThostFtdcOptionInstrMarginAdjustField* OptionInstrMarginAdjust);

void WriteOptionInstrCommRate(CThostFtdcOptionInstrCommRateField* OptionInstrCommRate);

void WriteOptionInstrTradeCost(CThostFtdcOptionInstrTradeCostField* OptionInstrTradeCost);

void WriteQryOptionInstrTradeCost(CThostFtdcQryOptionInstrTradeCostField* QryOptionInstrTradeCost);

void WriteQryOptionInstrCommRate(CThostFtdcQryOptionInstrCommRateField* QryOptionInstrCommRate);

void WriteIndexPrice(CThostFtdcIndexPriceField* IndexPrice);

void WriteInputExecOrder(CThostFtdcInputExecOrderField* InputExecOrder);

void WriteInputExecOrderAction(CThostFtdcInputExecOrderActionField* InputExecOrderAction);

void WriteExecOrder(CThostFtdcExecOrderField* ExecOrder);

void WriteExecOrderAction(CThostFtdcExecOrderActionField* ExecOrderAction);

void WriteQryExecOrder(CThostFtdcQryExecOrderField* QryExecOrder);

void WriteExchangeExecOrder(CThostFtdcExchangeExecOrderField* ExchangeExecOrder);

void WriteQryExchangeExecOrder(CThostFtdcQryExchangeExecOrderField* QryExchangeExecOrder);

void WriteQryExecOrderAction(CThostFtdcQryExecOrderActionField* QryExecOrderAction);

void WriteExchangeExecOrderAction(CThostFtdcExchangeExecOrderActionField* ExchangeExecOrderAction);

void WriteQryExchangeExecOrderAction(CThostFtdcQryExchangeExecOrderActionField* QryExchangeExecOrderAction);

void WriteErrExecOrder(CThostFtdcErrExecOrderField* ErrExecOrder);

void WriteQryErrExecOrder(CThostFtdcQryErrExecOrderField* QryErrExecOrder);

void WriteErrExecOrderAction(CThostFtdcErrExecOrderActionField* ErrExecOrderAction);

void WriteQryErrExecOrderAction(CThostFtdcQryErrExecOrderActionField* QryErrExecOrderAction);

void WriteOptionInstrTradingRight(CThostFtdcOptionInstrTradingRightField* OptionInstrTradingRight);

void WriteQryOptionInstrTradingRight(CThostFtdcQryOptionInstrTradingRightField* QryOptionInstrTradingRight);

void WriteInputForQuote(CThostFtdcInputForQuoteField* InputForQuote);

void WriteForQuote(CThostFtdcForQuoteField* ForQuote);

void WriteQryForQuote(CThostFtdcQryForQuoteField* QryForQuote);

void WriteExchangeForQuote(CThostFtdcExchangeForQuoteField* ExchangeForQuote);

void WriteQryExchangeForQuote(CThostFtdcQryExchangeForQuoteField* QryExchangeForQuote);

void WriteInputQuote(CThostFtdcInputQuoteField* InputQuote);

void WriteInputQuoteAction(CThostFtdcInputQuoteActionField* InputQuoteAction);

void WriteQuote(CThostFtdcQuoteField* Quote);

void WriteQuoteAction(CThostFtdcQuoteActionField* QuoteAction);

void WriteQryQuote(CThostFtdcQryQuoteField* QryQuote);

void WriteExchangeQuote(CThostFtdcExchangeQuoteField* ExchangeQuote);

void WriteQryExchangeQuote(CThostFtdcQryExchangeQuoteField* QryExchangeQuote);

void WriteQryQuoteAction(CThostFtdcQryQuoteActionField* QryQuoteAction);

void WriteExchangeQuoteAction(CThostFtdcExchangeQuoteActionField* ExchangeQuoteAction);

void WriteQryExchangeQuoteAction(CThostFtdcQryExchangeQuoteActionField* QryExchangeQuoteAction);

void WriteOptionInstrDelta(CThostFtdcOptionInstrDeltaField* OptionInstrDelta);

void WriteForQuoteRsp(CThostFtdcForQuoteRspField* ForQuoteRsp);

void WriteStrikeOffset(CThostFtdcStrikeOffsetField* StrikeOffset);

void WriteQryStrikeOffset(CThostFtdcQryStrikeOffsetField* QryStrikeOffset);

void WriteInputBatchOrderAction(CThostFtdcInputBatchOrderActionField* InputBatchOrderAction);

void WriteBatchOrderAction(CThostFtdcBatchOrderActionField* BatchOrderAction);

void WriteExchangeBatchOrderAction(CThostFtdcExchangeBatchOrderActionField* ExchangeBatchOrderAction);

void WriteQryBatchOrderAction(CThostFtdcQryBatchOrderActionField* QryBatchOrderAction);

void WriteCombInstrumentGuard(CThostFtdcCombInstrumentGuardField* CombInstrumentGuard);

void WriteQryCombInstrumentGuard(CThostFtdcQryCombInstrumentGuardField* QryCombInstrumentGuard);

void WriteInputCombAction(CThostFtdcInputCombActionField* InputCombAction);

void WriteCombAction(CThostFtdcCombActionField* CombAction);

void WriteQryCombAction(CThostFtdcQryCombActionField* QryCombAction);

void WriteExchangeCombAction(CThostFtdcExchangeCombActionField* ExchangeCombAction);

void WriteQryExchangeCombAction(CThostFtdcQryExchangeCombActionField* QryExchangeCombAction);

void WriteProductExchRate(CThostFtdcProductExchRateField* ProductExchRate);

void WriteQryProductExchRate(CThostFtdcQryProductExchRateField* QryProductExchRate);

void WriteQryForQuoteParam(CThostFtdcQryForQuoteParamField* QryForQuoteParam);

void WriteForQuoteParam(CThostFtdcForQuoteParamField* ForQuoteParam);

void WriteMMOptionInstrCommRate(CThostFtdcMMOptionInstrCommRateField* MMOptionInstrCommRate);

void WriteQryMMOptionInstrCommRate(CThostFtdcQryMMOptionInstrCommRateField* QryMMOptionInstrCommRate);

void WriteMMInstrumentCommissionRate(CThostFtdcMMInstrumentCommissionRateField* MMInstrumentCommissionRate);

void WriteQryMMInstrumentCommissionRate(CThostFtdcQryMMInstrumentCommissionRateField* QryMMInstrumentCommissionRate);

void WriteInstrumentOrderCommRate(CThostFtdcInstrumentOrderCommRateField* InstrumentOrderCommRate);

void WriteQryInstrumentOrderCommRate(CThostFtdcQryInstrumentOrderCommRateField* QryInstrumentOrderCommRate);

void WriteTradeParam(CThostFtdcTradeParamField* TradeParam);

void WriteInstrumentMarginRateUL(CThostFtdcInstrumentMarginRateULField* InstrumentMarginRateUL);

void WriteFutureLimitPosiParam(CThostFtdcFutureLimitPosiParamField* FutureLimitPosiParam);

void WriteLoginForbiddenIP(CThostFtdcLoginForbiddenIPField* LoginForbiddenIP);

void WriteIPList(CThostFtdcIPListField* IPList);

void WriteInputOptionSelfClose(CThostFtdcInputOptionSelfCloseField* InputOptionSelfClose);

void WriteInputOptionSelfCloseAction(CThostFtdcInputOptionSelfCloseActionField* InputOptionSelfCloseAction);

void WriteOptionSelfClose(CThostFtdcOptionSelfCloseField* OptionSelfClose);

void WriteOptionSelfCloseAction(CThostFtdcOptionSelfCloseActionField* OptionSelfCloseAction);

void WriteQryOptionSelfClose(CThostFtdcQryOptionSelfCloseField* QryOptionSelfClose);

void WriteExchangeOptionSelfClose(CThostFtdcExchangeOptionSelfCloseField* ExchangeOptionSelfClose);

void WriteQryOptionSelfCloseAction(CThostFtdcQryOptionSelfCloseActionField* QryOptionSelfCloseAction);

void WriteExchangeOptionSelfCloseAction(CThostFtdcExchangeOptionSelfCloseActionField* ExchangeOptionSelfCloseAction);

void WriteSyncDelaySwap(CThostFtdcSyncDelaySwapField* SyncDelaySwap);

void WriteQrySyncDelaySwap(CThostFtdcQrySyncDelaySwapField* QrySyncDelaySwap);

void WriteInvestUnit(CThostFtdcInvestUnitField* InvestUnit);

void WriteQryInvestUnit(CThostFtdcQryInvestUnitField* QryInvestUnit);

void WriteSecAgentCheckMode(CThostFtdcSecAgentCheckModeField* SecAgentCheckMode);

void WriteSecAgentTradeInfo(CThostFtdcSecAgentTradeInfoField* SecAgentTradeInfo);

void WriteMarketData(CThostFtdcMarketDataField* MarketData);

void WriteMarketDataBase(CThostFtdcMarketDataBaseField* MarketDataBase);

void WriteMarketDataStatic(CThostFtdcMarketDataStaticField* MarketDataStatic);

void WriteMarketDataLastMatch(CThostFtdcMarketDataLastMatchField* MarketDataLastMatch);

void WriteMarketDataBestPrice(CThostFtdcMarketDataBestPriceField* MarketDataBestPrice);

void WriteMarketDataBid23(CThostFtdcMarketDataBid23Field* MarketDataBid23);

void WriteMarketDataAsk23(CThostFtdcMarketDataAsk23Field* MarketDataAsk23);

void WriteMarketDataBid45(CThostFtdcMarketDataBid45Field* MarketDataBid45);

void WriteMarketDataAsk45(CThostFtdcMarketDataAsk45Field* MarketDataAsk45);

void WriteMarketDataUpdateTime(CThostFtdcMarketDataUpdateTimeField* MarketDataUpdateTime);

void WriteMarketDataExchange(CThostFtdcMarketDataExchangeField* MarketDataExchange);

void WriteSpecificInstrument(CThostFtdcSpecificInstrumentField* SpecificInstrument);

void WriteInstrumentStatus(CThostFtdcInstrumentStatusField* InstrumentStatus);

void WriteQryInstrumentStatus(CThostFtdcQryInstrumentStatusField* QryInstrumentStatus);

void WriteInvestorAccount(CThostFtdcInvestorAccountField* InvestorAccount);

void WritePositionProfitAlgorithm(CThostFtdcPositionProfitAlgorithmField* PositionProfitAlgorithm);

void WriteDiscount(CThostFtdcDiscountField* Discount);

void WriteQryTransferBank(CThostFtdcQryTransferBankField* QryTransferBank);

void WriteTransferBank(CThostFtdcTransferBankField* TransferBank);

void WriteQryInvestorPositionDetail(CThostFtdcQryInvestorPositionDetailField* QryInvestorPositionDetail);

void WriteInvestorPositionDetail(CThostFtdcInvestorPositionDetailField* InvestorPositionDetail);

void WriteTradingAccountPassword(CThostFtdcTradingAccountPasswordField* TradingAccountPassword);

void WriteMDTraderOffer(CThostFtdcMDTraderOfferField* MDTraderOffer);

void WriteQryMDTraderOffer(CThostFtdcQryMDTraderOfferField* QryMDTraderOffer);

void WriteQryNotice(CThostFtdcQryNoticeField* QryNotice);

void WriteNotice(CThostFtdcNoticeField* Notice);

void WriteUserRight(CThostFtdcUserRightField* UserRight);

void WriteQrySettlementInfoConfirm(CThostFtdcQrySettlementInfoConfirmField* QrySettlementInfoConfirm);

void WriteLoadSettlementInfo(CThostFtdcLoadSettlementInfoField* LoadSettlementInfo);

void WriteBrokerWithdrawAlgorithm(CThostFtdcBrokerWithdrawAlgorithmField* BrokerWithdrawAlgorithm);

void WriteTradingAccountPasswordUpdateV1(CThostFtdcTradingAccountPasswordUpdateV1Field* TradingAccountPasswordUpdateV1);

void WriteTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField* TradingAccountPasswordUpdate);

void WriteQryCombinationLeg(CThostFtdcQryCombinationLegField* QryCombinationLeg);

void WriteQrySyncStatus(CThostFtdcQrySyncStatusField* QrySyncStatus);

void WriteCombinationLeg(CThostFtdcCombinationLegField* CombinationLeg);

void WriteSyncStatus(CThostFtdcSyncStatusField* SyncStatus);

void WriteQryLinkMan(CThostFtdcQryLinkManField* QryLinkMan);

void WriteLinkMan(CThostFtdcLinkManField* LinkMan);

void WriteQryBrokerUserEvent(CThostFtdcQryBrokerUserEventField* QryBrokerUserEvent);

void WriteBrokerUserEvent(CThostFtdcBrokerUserEventField* BrokerUserEvent);

void WriteQryContractBank(CThostFtdcQryContractBankField* QryContractBank);

void WriteContractBank(CThostFtdcContractBankField* ContractBank);

void WriteInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField* InvestorPositionCombineDetail);

void WriteParkedOrder(CThostFtdcParkedOrderField* ParkedOrder);

void WriteParkedOrderAction(CThostFtdcParkedOrderActionField* ParkedOrderAction);

void WriteQryParkedOrder(CThostFtdcQryParkedOrderField* QryParkedOrder);

void WriteQryParkedOrderAction(CThostFtdcQryParkedOrderActionField* QryParkedOrderAction);

void WriteRemoveParkedOrder(CThostFtdcRemoveParkedOrderField* RemoveParkedOrder);

void WriteRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField* RemoveParkedOrderAction);

void WriteInvestorWithdrawAlgorithm(CThostFtdcInvestorWithdrawAlgorithmField* InvestorWithdrawAlgorithm);

void WriteQryInvestorPositionCombineDetail(CThostFtdcQryInvestorPositionCombineDetailField* QryInvestorPositionCombineDetail);

void WriteMarketDataAveragePrice(CThostFtdcMarketDataAveragePriceField* MarketDataAveragePrice);

void WriteVerifyInvestorPassword(CThostFtdcVerifyInvestorPasswordField* VerifyInvestorPassword);

void WriteUserIP(CThostFtdcUserIPField* UserIP);

void WriteTradingNoticeInfo(CThostFtdcTradingNoticeInfoField* TradingNoticeInfo);

void WriteTradingNotice(CThostFtdcTradingNoticeField* TradingNotice);

void WriteQryTradingNotice(CThostFtdcQryTradingNoticeField* QryTradingNotice);

void WriteQryErrOrder(CThostFtdcQryErrOrderField* QryErrOrder);

void WriteErrOrder(CThostFtdcErrOrderField* ErrOrder);

void WriteErrorConditionalOrder(CThostFtdcErrorConditionalOrderField* ErrorConditionalOrder);

void WriteQryErrOrderAction(CThostFtdcQryErrOrderActionField* QryErrOrderAction);

void WriteErrOrderAction(CThostFtdcErrOrderActionField* ErrOrderAction);

void WriteQryExchangeSequence(CThostFtdcQryExchangeSequenceField* QryExchangeSequence);

void WriteExchangeSequence(CThostFtdcExchangeSequenceField* ExchangeSequence);

void WriteQryMaxOrderVolumeWithPrice(CThostFtdcQryMaxOrderVolumeWithPriceField* QryMaxOrderVolumeWithPrice);

void WriteQryBrokerTradingParams(CThostFtdcQryBrokerTradingParamsField* QryBrokerTradingParams);

void WriteBrokerTradingParams(CThostFtdcBrokerTradingParamsField* BrokerTradingParams);

void WriteQryBrokerTradingAlgos(CThostFtdcQryBrokerTradingAlgosField* QryBrokerTradingAlgos);

void WriteBrokerTradingAlgos(CThostFtdcBrokerTradingAlgosField* BrokerTradingAlgos);

void WriteQueryBrokerDeposit(CThostFtdcQueryBrokerDepositField* QueryBrokerDeposit);

void WriteBrokerDeposit(CThostFtdcBrokerDepositField* BrokerDeposit);

void WriteQryCFMMCBrokerKey(CThostFtdcQryCFMMCBrokerKeyField* QryCFMMCBrokerKey);

void WriteCFMMCBrokerKey(CThostFtdcCFMMCBrokerKeyField* CFMMCBrokerKey);

void WriteCFMMCTradingAccountKey(CThostFtdcCFMMCTradingAccountKeyField* CFMMCTradingAccountKey);

void WriteQryCFMMCTradingAccountKey(CThostFtdcQryCFMMCTradingAccountKeyField* QryCFMMCTradingAccountKey);

void WriteBrokerUserOTPParam(CThostFtdcBrokerUserOTPParamField* BrokerUserOTPParam);

void WriteManualSyncBrokerUserOTP(CThostFtdcManualSyncBrokerUserOTPField* ManualSyncBrokerUserOTP);

void WriteCommRateModel(CThostFtdcCommRateModelField* CommRateModel);

void WriteQryCommRateModel(CThostFtdcQryCommRateModelField* QryCommRateModel);

void WriteMarginModel(CThostFtdcMarginModelField* MarginModel);

void WriteQryMarginModel(CThostFtdcQryMarginModelField* QryMarginModel);

void WriteEWarrantOffset(CThostFtdcEWarrantOffsetField* EWarrantOffset);

void WriteQryEWarrantOffset(CThostFtdcQryEWarrantOffsetField* QryEWarrantOffset);

void WriteQryInvestorProductGroupMargin(CThostFtdcQryInvestorProductGroupMarginField* QryInvestorProductGroupMargin);

void WriteInvestorProductGroupMargin(CThostFtdcInvestorProductGroupMarginField* InvestorProductGroupMargin);

void WriteQueryCFMMCTradingAccountToken(CThostFtdcQueryCFMMCTradingAccountTokenField* QueryCFMMCTradingAccountToken);

void WriteCFMMCTradingAccountToken(CThostFtdcCFMMCTradingAccountTokenField* CFMMCTradingAccountToken);

void WriteQryProductGroup(CThostFtdcQryProductGroupField* QryProductGroup);

void WriteProductGroup(CThostFtdcProductGroupField* ProductGroup);

void WriteBulletin(CThostFtdcBulletinField* Bulletin);

void WriteQryBulletin(CThostFtdcQryBulletinField* QryBulletin);

void WriteMulticastInstrument(CThostFtdcMulticastInstrumentField* MulticastInstrument);

void WriteQryMulticastInstrument(CThostFtdcQryMulticastInstrumentField* QryMulticastInstrument);

void WriteAppIDAuthAssign(CThostFtdcAppIDAuthAssignField* AppIDAuthAssign);

void WriteReqOpenAccount(CThostFtdcReqOpenAccountField* ReqOpenAccount);

void WriteReqCancelAccount(CThostFtdcReqCancelAccountField* ReqCancelAccount);

void WriteReqChangeAccount(CThostFtdcReqChangeAccountField* ReqChangeAccount);

void WriteReqTransfer(CThostFtdcReqTransferField* ReqTransfer);

void WriteRspTransfer(CThostFtdcRspTransferField* RspTransfer);

void WriteReqRepeal(CThostFtdcReqRepealField* ReqRepeal);

void WriteRspRepeal(CThostFtdcRspRepealField* RspRepeal);

void WriteReqQueryAccount(CThostFtdcReqQueryAccountField* ReqQueryAccount);

void WriteRspQueryAccount(CThostFtdcRspQueryAccountField* RspQueryAccount);

void WriteFutureSignIO(CThostFtdcFutureSignIOField* FutureSignIO);

void WriteRspFutureSignIn(CThostFtdcRspFutureSignInField* RspFutureSignIn);

void WriteReqFutureSignOut(CThostFtdcReqFutureSignOutField* ReqFutureSignOut);

void WriteRspFutureSignOut(CThostFtdcRspFutureSignOutField* RspFutureSignOut);

void WriteReqQueryTradeResultBySerial(CThostFtdcReqQueryTradeResultBySerialField* ReqQueryTradeResultBySerial);

void WriteRspQueryTradeResultBySerial(CThostFtdcRspQueryTradeResultBySerialField* RspQueryTradeResultBySerial);

void WriteReqDayEndFileReady(CThostFtdcReqDayEndFileReadyField* ReqDayEndFileReady);

void WriteReturnResult(CThostFtdcReturnResultField* ReturnResult);

void WriteVerifyFuturePassword(CThostFtdcVerifyFuturePasswordField* VerifyFuturePassword);

void WriteVerifyCustInfo(CThostFtdcVerifyCustInfoField* VerifyCustInfo);

void WriteVerifyFuturePasswordAndCustInfo(CThostFtdcVerifyFuturePasswordAndCustInfoField* VerifyFuturePasswordAndCustInfo);

void WriteDepositResultInform(CThostFtdcDepositResultInformField* DepositResultInform);

void WriteReqSyncKey(CThostFtdcReqSyncKeyField* ReqSyncKey);

void WriteRspSyncKey(CThostFtdcRspSyncKeyField* RspSyncKey);

void WriteNotifyQueryAccount(CThostFtdcNotifyQueryAccountField* NotifyQueryAccount);

void WriteTransferSerial(CThostFtdcTransferSerialField* TransferSerial);

void WriteQryTransferSerial(CThostFtdcQryTransferSerialField* QryTransferSerial);

void WriteNotifyFutureSignIn(CThostFtdcNotifyFutureSignInField* NotifyFutureSignIn);

void WriteNotifyFutureSignOut(CThostFtdcNotifyFutureSignOutField* NotifyFutureSignOut);

void WriteNotifySyncKey(CThostFtdcNotifySyncKeyField* NotifySyncKey);

void WriteQryAccountregister(CThostFtdcQryAccountregisterField* QryAccountregister);

void WriteAccountregister(CThostFtdcAccountregisterField* Accountregister);

void WriteOpenAccount(CThostFtdcOpenAccountField* OpenAccount);

void WriteCancelAccount(CThostFtdcCancelAccountField* CancelAccount);

void WriteChangeAccount(CThostFtdcChangeAccountField* ChangeAccount);

void WriteSecAgentACIDMap(CThostFtdcSecAgentACIDMapField* SecAgentACIDMap);

void WriteQrySecAgentACIDMap(CThostFtdcQrySecAgentACIDMapField* QrySecAgentACIDMap);

void WriteUserRightsAssign(CThostFtdcUserRightsAssignField* UserRightsAssign);

void WriteBrokerUserRightAssign(CThostFtdcBrokerUserRightAssignField* BrokerUserRightAssign);

void WriteDRTransfer(CThostFtdcDRTransferField* DRTransfer);

void WriteFensUserInfo(CThostFtdcFensUserInfoField* FensUserInfo);

void WriteCurrTransferIdentity(CThostFtdcCurrTransferIdentityField* CurrTransferIdentity);

void WriteLoginForbiddenUser(CThostFtdcLoginForbiddenUserField* LoginForbiddenUser);

void WriteQryLoginForbiddenUser(CThostFtdcQryLoginForbiddenUserField* QryLoginForbiddenUser);

void WriteTradingAccountReserve(CThostFtdcTradingAccountReserveField* TradingAccountReserve);

void WriteQryLoginForbiddenIP(CThostFtdcQryLoginForbiddenIPField* QryLoginForbiddenIP);

void WriteQryIPList(CThostFtdcQryIPListField* QryIPList);

void WriteQryUserRightsAssign(CThostFtdcQryUserRightsAssignField* QryUserRightsAssign);

void WriteReserveOpenAccountConfirm(CThostFtdcReserveOpenAccountConfirmField* ReserveOpenAccountConfirm);

void WriteReserveOpenAccount(CThostFtdcReserveOpenAccountField* ReserveOpenAccount);

void WriteAccountProperty(CThostFtdcAccountPropertyField* AccountProperty);

void WriteQryCurrDRIdentity(CThostFtdcQryCurrDRIdentityField* QryCurrDRIdentity);

void WriteCurrDRIdentity(CThostFtdcCurrDRIdentityField* CurrDRIdentity);

void WriteQrySecAgentCheckMode(CThostFtdcQrySecAgentCheckModeField* QrySecAgentCheckMode);

void WriteQrySecAgentTradeInfo(CThostFtdcQrySecAgentTradeInfoField* QrySecAgentTradeInfo);

void WriteReqUserAuthMethod(CThostFtdcReqUserAuthMethodField* ReqUserAuthMethod);

void WriteRspUserAuthMethod(CThostFtdcRspUserAuthMethodField* RspUserAuthMethod);

void WriteReqGenUserCaptcha(CThostFtdcReqGenUserCaptchaField* ReqGenUserCaptcha);

void WriteRspGenUserCaptcha(CThostFtdcRspGenUserCaptchaField* RspGenUserCaptcha);

void WriteReqGenUserText(CThostFtdcReqGenUserTextField* ReqGenUserText);

void WriteRspGenUserText(CThostFtdcRspGenUserTextField* RspGenUserText);

void WriteReqUserLoginWithCaptcha(CThostFtdcReqUserLoginWithCaptchaField* ReqUserLoginWithCaptcha);

void WriteReqUserLoginWithText(CThostFtdcReqUserLoginWithTextField* ReqUserLoginWithText);

void WriteReqUserLoginWithOTP(CThostFtdcReqUserLoginWithOTPField* ReqUserLoginWithOTP);

void WriteReqApiHandshake(CThostFtdcReqApiHandshakeField* ReqApiHandshake);

void WriteRspApiHandshake(CThostFtdcRspApiHandshakeField* RspApiHandshake);

void WriteReqVerifyApiKey(CThostFtdcReqVerifyApiKeyField* ReqVerifyApiKey);

void WriteDepartmentUser(CThostFtdcDepartmentUserField* DepartmentUser);

void WriteQueryFreq(CThostFtdcQueryFreqField* QueryFreq);

void WriteAuthForbiddenIP(CThostFtdcAuthForbiddenIPField* AuthForbiddenIP);

void WriteQryAuthForbiddenIP(CThostFtdcQryAuthForbiddenIPField* QryAuthForbiddenIP);

void WriteSyncDelaySwapFrozen(CThostFtdcSyncDelaySwapFrozenField* SyncDelaySwapFrozen);

void WriteUserSystemInfo(CThostFtdcUserSystemInfoField* UserSystemInfo);

void WriteAuthUserID(CThostFtdcAuthUserIDField* AuthUserID);

void WriteAuthIP(CThostFtdcAuthIPField* AuthIP);

void WriteQryClassifiedInstrument(CThostFtdcQryClassifiedInstrumentField* QryClassifiedInstrument);

void WriteQryCombPromotionParam(CThostFtdcQryCombPromotionParamField* QryCombPromotionParam);

void WriteCombPromotionParam(CThostFtdcCombPromotionParamField* CombPromotionParam);

