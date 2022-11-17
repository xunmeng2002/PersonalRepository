#pragma once
#include "DboDataType.h"

struct DboAuthorizedSoftware
{
public:
	CSoftwareType Software;
	CAuthCodeType AuthCode;
	CAccountType Account;
	
	const char* GetString() const;
	const char* GetDebugString() const;
};
struct DboClose
{
public:
	CDateType OpenDate;
	COrderIDType OpenOrderID;
	CTradeIDType OpenTradeID;
	CDateType CloseDate;
	COrderIDType CloseOrderID;
	CTradeIDType CloseTradeID;
	CAccountType Account;
	CExchangeIDType ExchangeID;
	CContractIDType ContractID;
	CDirectionType BS;
	CHedgeFlagType Hedge;
	CPriceType OpenPrice;
	CPriceType LastSettle;
	CPriceType ClosePrice;
	CVolumeType Volume;
	CDateType RealOpenDate;
	CDateType RealCloseDate;
	CTimeType OpenTime;
	CTimeType CloseTime;
	CMoneyType CloseProfitFloat;
	CMoneyType CloseProfit;
	CCurrencyGroupType CurrencyGroup;
	CCurrencyIDType CurrencyID;
	
	const char* GetString() const;
	const char* GetDebugString() const;
};
struct DboCommission
{
public:
	CGroupIDType GroupID;
	CAccountType Account;
	CExchangeIDType ExchangeID;
	CProductIDType ProductID;
	CContractIDType ContractID;
	CRateType OpenByVolume;
	CRateType CloseByVolume;
	CRateType OpenByMoney;
	CRateType CloseByMoney;
	
	const char* GetString() const;
	const char* GetDebugString() const;
};
struct DboContract
{
public:
	CExchangeIDType ExchangeID;
	CProductIDType ProductID;
	CContractIDType ContractID;
	CContractNameType ContractName;
	CYearType DeliveryYear;
	CMonthType DeliveryMonth;
	CDateType OpenDate;
	CDateType ExpireDate;
	CDateType FirstNoticeDate;
	CDateType StartDelivDate;
	CDateType EndDelivDate;
	CTradeStatusType TradeStatus;
	CMoneyType Margin;
	CMoneyType MinMargin;
	
	const char* GetString() const;
	const char* GetDebugString() const;
};
struct DboCreditAmount
{
public:
	CIDType ID;
	CDateTimeType AuditTime;
	CDateTimeType OperationTime;
	CRemarkType Remark;
	CStatusType Status;
	CMoneyType Amount;
	CCurrencyGroupType CurrencyGroup;
	CDirectionType Direction;
	CDateType TradingDay;
	COperatorIDType OperatorID;
	CAccountType Account;
	CCurrencyIDType CurrencyID;
	CAuditorIDType AuditorID;
	CFlagType Flag;
	
	const char* GetString() const;
	const char* GetDebugString() const;
};
struct DboCurrencyRate
{
public:
	CCurrencyGroupType CurrencyGroup;
	CCurrencyIDType CurrencyID;
	CRateType TradeRate;
	CRateType SettlementRate;
	CBoolType IsBaseCurrency;
	
	const char* GetString() const;
	const char* GetDebugString() const;
};
struct DboDepositWithdrawal
{
public:
	CIDType ID;
	CTimeType AuditTime;
	CTimeType OperationTime;
	CRemarkType Remark;
	CStatusType Status;
	CMoneyType Amount;
	CRemarkType BankCardID;
	CCurrencyIDType CurrencyID;
	CCurrencyGroupType CurrencyGroup;
	CDirectionType Direction;
	CMethodType Method;
	CDateType TradingDay;
	COperatorIDType OperatorID;
	CAccountType Account;
	CAuditorIDType AuditorID;
	CFlagType Flag;
	
	const char* GetString() const;
	const char* GetDebugString() const;
};
struct DboExchange
{
public:
	CExchangeIDType ExchangeID;
	CExchangeNameType ExchangeName;
	CTradeStatusType TradeStatus;
	
	const char* GetString() const;
	const char* GetDebugString() const;
};
struct DboInvertor
{
public:
	CAccountType Account;
	CAccountStatusType AccountStatus;
	CAccountTypeType AccountType;
	CAgentTypeType AgentType;
	CDateType CloseDate;
	COrderTypeType OrderType;
	CInvestorTypeType InvestorType;
	CBoolType IsEmployee;
	CLoginStatusType LoginStatus;
	CNumType maxOnLine;
	CInvestorNameType Name;
	CDateType OpenDate;
	CPasswordType Password;
	CDateType PasswordDate;
	CBoolType PasswordExpired;
	CDateType PasswordValidDays;
	CNumType RiskLevel;
	CTradeStatusType TradeStatus;
	CTwoStepCodeType TwoStepCode;
	CTwoStepCodeTimeType TwoStepCodeTime;
	CBoolType TwoStepLogin;
	CGroupIDType CommissionGroupID;
	CGroupIDType MarginGroupID;
	
	const char* GetString() const;
	const char* GetDebugString() const;
};
struct DboInvestorMobile
{
public:
	CIDType ID;
	CMobileType Mobile;
	CMobileTypeType MobileType;
	CAccountType Account;
	CAreaCodeType AreaCode;
	
	const char* GetString() const;
	const char* GetDebugString() const;
};
struct DboInvestorParam
{
public:
	CAccountType Account;
	CExchangeIDType ExchangeID;
	CProductIDType ProductID;
	CContractIDType ContractID;
	CTradeStatusType TradeStatus;
	CVolumeType MaxPosition;
	CVolumeType MaxOrderVolume;
	CNumType CloseAdvanceDays;
	CChannelIDType ChannelID;
	
	const char* GetString() const;
	const char* GetDebugString() const;
};
struct DboLogin
{
public:
	CDateType TradeDate;
	CFrontIDType FrontID;
	CSessionIDType SessionID;
	CDateType RealDate;
	CAccountType Account;
	CAdminType Admin;
	CBoolType TwoStepLogin;
	CTimeType Time;
	CIPType IP;
	CMACType MAC;
	CUserProductType UserProduct;
	CHardwareType Hardware;
	COSType OS;
	CDateType LogoutDate;
	CTimeType LogoutTime;
	
	const char* GetString() const;
	const char* GetDebugString() const;
};
struct DboMargin
{
public:
	CGroupIDType GroupID;
	CAccountType Account;
	CExchangeIDType ExchangeID;
	CProductIDType ProductID;
	CContractIDType ContractID;
	CMarginTypeType MarginType;
	CMoneyType Margin;
	CMoneyType MinMargin;
	CMoneyType SettleMargin;
	
	const char* GetString() const;
	const char* GetDebugString() const;
};
struct DboMaxBalance
{
public:
	CAccountType Account;
	CMoneyType MaxBalance;
	CMoneyType EverMaxBalance;
	
	const char* GetString() const;
	const char* GetDebugString() const;
};
struct DboOrder
{
public:
	CDateTimeType TradeDate;
	COrderIDType OrderID;
	CAccountType Account;
	COperatorIDType InsertAccount;
	COperatorIDType CancelAccount;
	CRequestIDType RequestID;
	CExchangeIDType ExchangeID;
	CContractIDType ContractID;
	CDirectionType BS;
	COffsetFlagType OC;
	CHedgeFlagType Hedge;
	COrderPriceTypeType PriceType;
	CPriceType Price;
	CVolumeType Volume;
	CVolumeType TradeVolume;
	CStatusType Status;
	CDateType RealDate;
	CTimeType InsertTime;
	CTimeType CancelTime;
	CForceCloseReasonType ForceClose;
	CForceReasonType ForceReason;
	COrderSysIDType OrderSysID;
	COrderRemarkType Remark;
	CFrontIDType FrontID;
	CSessionIDType SessionID;
	COrderRefType OrderRef;
	CTimeConditionType TimeCondition;
	CDateType GTDDate;
	CVolumeConditionType VolumeCondition;
	CVolumeType MinVolume;
	CContingentConditionType ContingentCondition;
	CPriceType StopPrice;
	CSwapOrderType SwapOrder;
	CChannelIDType ChannelID;
	CTag50Type Tag50;
	CFrontIDType CancelFrontID;
	CSessionIDType CancelSessionID;
	CFrontIDType ChannelFrontID;
	CSessionIDType ChannelSessionID;
	COrderRefType ChannelOrderRef;
	CChannelOrderIDType ChannelOrderID;
	CT1ValidType T1Valid;
	CBoolType Deleted;
	COperatorIDType DeleteAccount;
	CTimeType DeleteTime;
	CDateType InsertDate;
	CInsertIDType InsertID;
	CPatchOrderType PatchOrder;
	CDateType CancelDate;
	CUserOrderIDType UserOrderID;
	
	const char* GetString() const;
	const char* GetDebugString() const;
};
struct DboOrderCheck
{
public:
	CIDType ID;
	CAccountType Account;
	CGroupIDType GroupID;
	CItemType Item;
	CParamType Param1;
	CProductIDType ProductID;
	CResultType Result;
	CExchangeIDType ExchangeID;
	
	const char* GetString() const;
	const char* GetDebugString() const;
};
struct DboPosition
{
public:
	CAccountType Account;
	CDateType TradeDate;
	CExchangeIDType ExchangeID;
	CContractIDType ContractID;
	CDirectionType BS;
	CHedgeFlagType Hedge;
	CDateType OpenDate;
	CTradeIDType TradeID;
	COrderIDType OrderID;
	CLocalTradeIDType LocalTradeID;
	CDateType RealOpenDate;
	CTimeType TradeTime;
	CVolumeType Volume;
	CPriceType OpenPrice;
	CPriceType SettlePrice;
	CPriceType LastSettle;
	CVolumeMultipleType VolumeMultiple;
	CMoneyType Margin;
	CMoneyType PositionProfitFloat;
	CMoneyType PositionProfit;
	CVolumeType CloseVolume;
	CMoneyType CloseProfitFloat;
	CMoneyType CloseProfit;
	CMoneyType CloseAmount;
	CTradeTypeType TradeType;
	CContractIDType CombineContractID;
	CTradeIDType CombineTradeID;
	CCurrencyGroupType CurrencyGroup;
	CCurrencyIDType CurrencyID;
	CMoneyType MinMargin;
	
	const char* GetString() const;
	const char* GetDebugString() const;
};
struct DboProduct
{
public:
	CExchangeIDType ExchangeID;
	CProductIDType ProductID;
	CProductClassType ProductClass;
	CProductNameType ProductName;
	CCurrencyGroupType CurrencyGroup;
	CCurrencyIDType CurrencyID;
	CVolumeMultipleType VolumeMultiple;
	CPriceTickType PriceTick;
	CDecimalDigitsType DecimalDigits;
	CT1SplitTimeType T1SplitTime;
	CVolumeType MaxPosition;
	CVolumeType MaxOrderVolume;
	CNumType CloseAdvanceDays;
	CDeliveryMethodType DeliveryMethod;
	CChannelIDType TradeChannel;
	CTradeStatusType TradeStatus;
	
	const char* GetString() const;
	const char* GetDebugString() const;
};
struct DboRiskControl
{
public:
	CRiskIDType RiskID;
	CAccountType Account;
	CGroupIDType GroupID;
	
	const char* GetString() const;
	const char* GetDebugString() const;
};
struct DboRiskControlTemplate
{
public:
	CIDType ID;
	CRiskClassType RiskClass;
	CRiskItemType RiskItem;
	CProductCombinationType Product;
	CBoolType OpenDenied;
	CBoolType CloseDenied;
	CNoticeType Notice;
	CVolumeType Position;
	CContentsType Contents;
	CTimeType TimeFrom;
	CTimeType TimeTo;
	CParamType Param1;
	CParamType Param2;
	CParamType Param3;
	CParamType Param4;
	CParamType Param5;
	CParamType Param6;
	CTimeType CreateTime;
	CTimeType UpdateTime;
	
	const char* GetString() const;
	const char* GetDebugString() const;
};
struct DboSession
{
public:
	CDateType TradeDate;
	CAccountType Account;
	CFrontIDType FrontID;
	CSessionIDType SessionID;
	
	const char* GetString() const;
	const char* GetDebugString() const;
};
struct DboSettlePrice
{
public:
	CExchangeIDType ExchangeID;
	CContractIDType ContractID;
	CDateType TradingDay;
	CPriceType SettlePrice;
	CPriceType PrevSettlePrice;
	CMoneyType Margin;
	CMoneyType MinMargin;
	
	const char* GetString() const;
	const char* GetDebugString() const;
};
struct DboSummary
{
public:
	CAccountType Account;
	CDateType TradeDate;
	CCurrencyGroupType CurrencyGroup;
	CCurrencyIDType CurrencyID;
	CRateType CurrencyRate;
	CMoneyType Balance;
	CMoneyType LastBalance;
	CMoneyType Available;
	CMoneyType Margin;
	CMoneyType Commission;
	CMoneyType PositionProfitFloat;
	CMoneyType PositionProfit;
	CMoneyType CloseProfitFloat;
	CMoneyType CloseProfit;
	CMoneyType Deposit;
	CMoneyType Withdraw;
	CRateType Risk;
	CMoneyType CloseBalance;
	CMoneyType CashInOutTotal;
	CMoneyType BalanceFloat;
	CMoneyType LastBalanceFloat;
	CMoneyType Credit;
	CMoneyType MinMargin;
	CStageType Stage;
	
	const char* GetString() const;
	const char* GetDebugString() const;
};
struct DboSysParam
{
public:
	CSysParamType Param;
	CSysParamValueType Value;
	
	const char* GetString() const;
	const char* GetDebugString() const;
};
struct DboTrade
{
public:
	CDateType TradeDate;
	COrderIDType OrderID;
	CTradeIDType TradeID;
	CAccountType Account;
	CRequestIDType RequestID;
	CExchangeIDType ExchangeID;
	CContractIDType ContractID;
	CDirectionType BS;
	CHedgeFlagType Hedge;
	CPriceType Price;
	CVolumeType Volume;
	CMoneyType Turnover;
	CDateType RealDate;
	CTimeType TradeTime;
	COrderSysIDType OrderSysID;
	CMoneyType Commission;
	CMoneyType CloseProfitFloat;
	CMoneyType CloseProfit;
	COrderRefType OrderRef;
	CTradeTypeType TradeType;
	CContractIDType CombineContractID;
	CLocalTradeIDType LocalTradeID;
	CCurrencyGroupType CurrencyGroup;
	CCurrencyIDType CurrencyID;
	CExchangeTradeIDType ExchangeTradeID;
	CVolumeType OpenVolume;
	CVolumeType CloseVolume;
	CBoolType Deleted;
	COperatorIDType DeleteAccount;
	CTimeType DeleteTime;
	CMoneyType ExchangeFee;
	CMoneyType Levy;
	COperatorIDType PatchAccount;
	
	const char* GetString() const;
	const char* GetDebugString() const;
};
struct DboTradeChannel
{
public:
	CIDType ID;
	CChannelNameType Name;
	CUserIDType UserID;
	CPasswordType Password;
	CIPType IP;
	CPortType Port;
	
	const char* GetString() const;
	const char* GetDebugString() const;
};
struct DboTrustedNetAddress
{
public:
	CAccountType Account;
	CIPType IP;
	CMACType MAC;
	
	const char* GetString() const;
	const char* GetDebugString() const;
};

