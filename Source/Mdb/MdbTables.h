#pragma once
#pragma warning(disable : 26495)
#include <string>
#include "MdbEnumDict.h"

using std::string;

class OrderSequence
{
public:
	int ToStream(char* buff, int size) const;
	int ToString(char* buff, int size) const;
	static std::string CreateSql();
	std::string InsertSql();
	static int OnSelectCallback(void* callback, int colCount, char** colValues, char** colNames);

public:
	string TradingDay;
	int MaxOrderLocalID;
	
	static constexpr const char* TableName = "t_MdbOrderSequence";
};

class Order
{
public:
	int ToStream(char* buff, int size) const;
	int ToString(char* buff, int size) const;
	static std::string CreateSql();
	std::string InsertSql();
	static int OnSelectCallback(void* callback, int colCount, char** colValues, char** colNames);

public:
	string TradingDay;
	string AccountID;
	string CurrencyID;
	string ExchangeID;
	string InstrumentID;
	string OrderLocalID;
	string OrderSysID;
	Direction Direction = Direction::Buy;
	OffsetFlag OffsetFlag = OffsetFlag::Open;
	HedgeFlag HedgeFlag = HedgeFlag::Speculation;
	OrderPriceType OrderPriceType = OrderPriceType::LimitPrice;
	double Price;
	int Volume;
	int VolumeTraded;
	OrderStatus OrderStatus = OrderStatus::Unknown;
	int ErrorID;
	string ErrorMsg;
	string RequestID;
	string FrontID;
	int SessionID;
	string InsertDate;
	string InsertTime;
	string ExchangeInsertDate;
	string ExchangeInsertTime;
	string CancelDate;
	string CancelTime;
	ForceCloseReason ForceCloseReason = ForceCloseReason::NotForceClose;
	IsLocalOrder IsLocalOrder = IsLocalOrder::Others;
	string UserProductInfo;
	TimeCondition TimeCondition = TimeCondition::GFD;
	string GTDDate;
	VolumeCondition VolumeCondition = VolumeCondition::AV;
	int MinVolume;
	ContingentCondition ContingentCondition = ContingentCondition::Immediately;
	double StopPrice;
	int IsSwapOrder;
	int T1Valid;
	
	static constexpr const char* TableName = "t_MdbOrder";
};

class OrderCancel
{
public:
	int ToStream(char* buff, int size) const;
	int ToString(char* buff, int size) const;
	static std::string CreateSql();
	std::string InsertSql();
	static int OnSelectCallback(void* callback, int colCount, char** colValues, char** colNames);

public:
	string TradingDay;
	string AccountID;
	string ExchangeID;
	string InstrumentID;
	string OrderLocalID;
	string OrigOrderLocalID;
	string OrderSysID;
	Direction Direction = Direction::Buy;
	string OrderRef;
	string FrontID;
	int SessionID;
	int ErrorID;
	string ErrorMsg;
	string InsertDate;
	string CancelDate;
	
	static constexpr const char* TableName = "t_MdbOrderCancel";
};

class Trade
{
public:
	int ToStream(char* buff, int size) const;
	int ToString(char* buff, int size) const;
	static std::string CreateSql();
	std::string InsertSql();
	static int OnSelectCallback(void* callback, int colCount, char** colValues, char** colNames);

public:
	string TradingDay;
	string AccountID;
	string ExchangeID;
	string InstrumentID;
	string TradeID;
	Direction Direction = Direction::Buy;
	OffsetFlag OffsetFlag = OffsetFlag::Open;
	HedgeFlag HedgeFlag = HedgeFlag::Speculation;
	double Price;
	int Volume;
	string OrderLocalID;
	string OrderSysID;
	string TradeTime;
	string TradeDate;
	
	static constexpr const char* TableName = "t_MdbTrade";
};


class MdbCallback
{
public:
	virtual void SelectMdbOrderSequenceCallback(OrderSequence* field) { delete field; }
	virtual void SelectMdbOrderCallback(Order* field) { delete field; }
	virtual void SelectMdbOrderCancelCallback(OrderCancel* field) { delete field; }
	virtual void SelectMdbTradeCallback(Trade* field) { delete field; }
};

