#pragma once
#pragma warning(disable : 26945)
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
private:
	char m_Buff[4096];
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
	string AccountID;
	string ExchangeID;
	string InstrumentID;
	string OrderLocalID;
	string OrderSysID;
	Direction Direction;
	OffsetFlag OffsetFlag;
	HedgeFlag HedgeFlag;
	OrderPriceType OrderPriceType;
	double Price;
	int Volume;
	int VolumeTraded;
	OrderStatus OrderStatus;
	string StatusMsg;
	string RequestID;
	string FrontID;
	int SessionID;
	string InsertDate;
	string InsertTime;
	string ExchangeInsertDate;
	string ExchangeInsertTime;
	string CancelDate;
	string CancelTime;
	ForceCloseReason ForceCloseReason;
	IsLocalOrder IsLocalOrder;
	string UserProductInfo;
	TimeCondition TimeCondition;
	string GTDDate;
	VolumeCondition VolumeCondition;
	int MinVolume;
	ContingentCondition ContingentCondition;
	double StopPrice;
	int IsSwapOrder;
	
	static constexpr const char* TableName = "t_MdbOrder";
private:
	char m_Buff[4096];
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
	string AccountID;
	string ExchangeID;
	string InstrumentID;
	string OrderLocalID;
	string OrigOrderLocalID;
	string OrderSysID;
	Direction Direction;
	string OrderRef;
	string FrontID;
	int SessionID;
	int ErrorID;
	string ErrorMsg;
	string InsertDate;
	string CancelDate;
	
	static constexpr const char* TableName = "t_MdbOrderCancel";
private:
	char m_Buff[4096];
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
	string AccountID;
	string ExchangeID;
	string InstrumentID;
	string TradeID;
	Direction Direction;
	OffsetFlag OffsetFlag;
	HedgeFlag HedgeFlag;
	double Price;
	int Volume;
	string OrderLocalID;
	string OrderSysID;
	string TradeTime;
	string TradeDate;
	
	static constexpr const char* TableName = "t_MdbTrade";
private:
	char m_Buff[4096];
};


class MdbCallback
{
public:
	virtual void SelectMdbOrderSequenceCallback(OrderSequence* field) { delete field; }
	virtual void SelectMdbOrderCallback(Order* field) { delete field; }
	virtual void SelectMdbOrderCancelCallback(OrderCancel* field) { delete field; }
	virtual void SelectMdbTradeCallback(Trade* field) { delete field; }
};

