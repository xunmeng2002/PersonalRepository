#pragma once
#include <string>
#include <vector>

class ItsReqQryPrimaryAccountInfo
{
public:
	ItsReqQryPrimaryAccountInfo();
	ItsReqQryPrimaryAccountInfo(const std::vector<std::string>& items);
	int ToString(char* buff, int size);
	int ToStream(char* buff, int size);
	static string CreateSql();
	std::string InsertSql();
	static int OnSelectCallback(void* callback, int colCount, char** colValues, char** colNames);

public:
	std::string ProtocolType;
	std::string Command;
	std::string SequenceNo;
	std::string Reserve1;
	std::string Reserve2;
	std::string Reserve3;
	std::string Reserve4;
	std::string Reserve5;
	std::string Reserve6;
	std::string Unknown;
	std::string ChannelID;

	static constexpr char* TableName = "t_ItsReqQryPrimaryAccountInfo";
private:
	char m_Buff[4096];
};

class ItsRspQryPrimaryAccountInfo
{
public:
	ItsRspQryPrimaryAccountInfo();
	ItsRspQryPrimaryAccountInfo(const std::vector<std::string>& items);
	int ToString(char* buff, int size);
	int ToStream(char* buff, int size);
	static string CreateSql();
	std::string InsertSql();
	static int OnSelectCallback(void* callback, int colCount, char** colValues, char** colNames);

public:
	std::string ProtocolType;
	std::string SequenceNo;
	std::string IsLast;
	std::string Reserve1;
	std::string ErrorCode;
	std::string ErrorMessage;
	std::string ChannelID;
	std::string PrimaryAccountID;
	std::string Password;
	std::string Port;

	static constexpr char* TableName = "t_ItsRspQryPrimaryAccountInfo";
private:
	char m_Buff[4096];
};

class ItsInsertOrder
{
public:
	ItsInsertOrder();
	ItsInsertOrder(const std::vector<std::string>& items);
	int ToString(char* buff, int size);
	int ToStream(char* buff, int size);
	static string CreateSql();
	std::string InsertSql();
	static int OnSelectCallback(void* callback, int colCount, char** colValues, char** colNames);

public:
	std::string ProtocolType;
	std::string Command;
	std::string SequenceNo;
	std::string Reserve1;
	std::string Reserve2;
	std::string Reserve3;
	std::string Reserve4;
	std::string Reserve5;
	std::string Reserve6;
	std::string ExchangeID;
	std::string InstrumentID;
	std::string Price;
	std::string Direction;
	std::string Reserve7;
	std::string CombHedgeFlag;
	std::string Volume;
	std::string OrderPriceType;
	std::string RequestID;
	std::string Reserve8;
	std::string TimeCondition;
	std::string GTDDate;
	std::string VolumeCondition;
	std::string MinVolume;
	std::string IsSwapOrder;
	std::string ForceCloseReason;
	std::string AccountID;
	std::string TradingDay;

	static constexpr char* TableName = "t_ItsInsertOrder";
private:
	char m_Buff[4096];
};

class ItsInsertOrderCancel
{
public:
	ItsInsertOrderCancel();
	ItsInsertOrderCancel(const std::vector<std::string>& items);
	int ToString(char* buff, int size);
	int ToStream(char* buff, int size);
	static string CreateSql();
	std::string InsertSql();
	static int OnSelectCallback(void* callback, int colCount, char** colValues, char** colNames);

public:
	std::string ProtocolType;
	std::string Command;
	std::string SequenceNo;
	std::string Reserve1;
	std::string Reserve2;
	std::string Reserve3;
	std::string Reserve4;
	std::string Reserve5;
	std::string Reserve6;
	std::string OrderRef;
	std::string FrontID;
	std::string SessionID;
	std::string ExchangeID;
	std::string OrderSysID;
	std::string ChannelOrderID;
	std::string BrokerOrderID;
	std::string InstrumentID;
	std::string Direction;
	std::string TradingDay;

	static constexpr char* TableName = "t_ItsInsertOrderCancel";
private:
	char m_Buff[4096];
};

class ItsRspOrder
{
public:
	ItsRspOrder();
	ItsRspOrder(const std::vector<std::string>& items);
	int ToString(char* buff, int size);
	int ToStream(char* buff, int size);
	static string CreateSql();
	std::string InsertSql();
	static int OnSelectCallback(void* callback, int colCount, char** colValues, char** colNames);

public:
	std::string ProtocolType;
	std::string SequenceNo;
	std::string Reserve1;
	std::string Reserve2;
	std::string ErrorID;
	std::string ErrorMsg;
	std::string TradingDay;

	static constexpr char* TableName = "t_ItsRspOrder";
private:
	char m_Buff[4096];
};

class ItsOrder
{
public:
	ItsOrder();
	ItsOrder(const std::vector<std::string>& items);
	int ToString(char* buff, int size);
	int ToStream(char* buff, int size);
	static string CreateSql();
	std::string InsertSql();
	static int OnSelectCallback(void* callback, int colCount, char** colValues, char** colNames);

public:
	std::string ProtocolType;
	std::string Command;
	std::string Reserve1;
	std::string Reserve2;
	std::string Reserve3;
	std::string Reserve4;
	std::string ChannelID;
	std::string ExchangeID;
	std::string InstrumentID;
	std::string OrderRef;
	std::string InsertTime;
	std::string CancelTime;
	std::string OrderSysID;
	std::string StatusMsg;
	std::string Direction;
	std::string CombOffsetFlag;
	std::string CombHedgeFlag;
	std::string OrderPriceType;
	std::string OrderStatus;
	std::string ForceCloseReason;
	std::string RequestID;
	std::string FrontID;
	std::string SessionID;
	std::string BrokerOrderID;
	std::string VolumeTotalOriginal;
	std::string VolumeTraded;
	std::string InsertDate;
	std::string TradingDay;
	std::string LimitPrice;
	std::string IsLocalOrder;
	std::string UserProductInfo;
	std::string TimeCondition;
	std::string GTDDate;
	std::string VolumeCondition;
	std::string MinVolume;
	std::string ContingentCondition;
	std::string StopPrice;
	std::string IsSwapOrder;
	std::string Reserve5;

	static constexpr char* TableName = "t_ItsOrder";
private:
	char m_Buff[4096];
};

class ItsTrade
{
public:
	ItsTrade();
	ItsTrade(const std::vector<std::string>& items);
	int ToString(char* buff, int size);
	int ToStream(char* buff, int size);
	static string CreateSql();
	std::string InsertSql();
	static int OnSelectCallback(void* callback, int colCount, char** colValues, char** colNames);

public:
	std::string ProtocolType;
	std::string Command;
	std::string Reserve1;
	std::string Reserve2;
	std::string Reserve3;
	std::string Reserve4;
	std::string ChannelID;
	std::string ExchangeID;
	std::string InstrumentID;
	std::string OrderRef;
	std::string OrderSysID;
	std::string TradeTime;
	std::string TradeID;
	std::string Direction;
	std::string OffsetFlag;
	std::string HedgeFlag;
	std::string BrokerOrderID;
	std::string Volume;
	std::string TradeDate;
	std::string TradingDay;
	std::string Price;
	std::string Reserve5;
	std::string TradeType;
	std::string ExchangeTradeID;
	std::string Reserve7;
	std::string Reserve8;

	static constexpr char* TableName = "t_ItsTrade";
private:
	char m_Buff[4096];
};

class ItsErrRtnOrderCancel
{
public:
	ItsErrRtnOrderCancel();
	ItsErrRtnOrderCancel(const std::vector<std::string>& items);
	int ToString(char* buff, int size);
	int ToStream(char* buff, int size);
	static string CreateSql();
	std::string InsertSql();
	static int OnSelectCallback(void* callback, int colCount, char** colValues, char** colNames);

public:
	std::string ProtocolType;
	std::string Command;
	std::string Reserve1;
	std::string Reserve2;
	std::string Reserve3;
	std::string Reserve4;
	std::string ChannelID;
	std::string BrokerOrderID;
	std::string OrderRef;
	std::string FrontID;
	std::string SessionID;
	std::string ExchangeID;
	std::string OrderSysID;
	std::string Reserve5;
	std::string ErrorID;
	std::string ErrorMsg;
	std::string TradingDay;

	static constexpr char* TableName = "t_ItsErrRtnOrderCancel";
private:
	char m_Buff[4096];
};


class ItsMdbCallback
{
public:
	virtual void SelectItsReqQryPrimaryAccountInfoCallback(ItsReqQryPrimaryAccountInfo* field) { delete field; }
	virtual void SelectItsRspQryPrimaryAccountInfoCallback(ItsRspQryPrimaryAccountInfo* field) { delete field; }
	virtual void SelectItsInsertOrderCallback(ItsInsertOrder* field) { delete field; }
	virtual void SelectItsInsertOrderCancelCallback(ItsInsertOrderCancel* field) { delete field; }
	virtual void SelectItsRspOrderCallback(ItsRspOrder* field) { delete field; }
	virtual void SelectItsOrderCallback(ItsOrder* field) { delete field; }
	virtual void SelectItsTradeCallback(ItsTrade* field) { delete field; }
	virtual void SelectItsErrRtnOrderCancelCallback(ItsErrRtnOrderCancel* field) { delete field; }
};

