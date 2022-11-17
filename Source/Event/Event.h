#pragma once
#include <string>
#include <vector>


constexpr int BuffSize = 64 * 1024;

struct Event
{
	int EventID;

	static Event* Allocate();
	virtual void Free();
};

struct TcpEvent : public Event
{
	TcpEvent(int buffSize = BuffSize);
	~TcpEvent();
	int SessionID;
	std::string IP;
	std::string Port;
	char* ReadPos;
	char* Buff;
	int Length;


	static TcpEvent* Allocate();
	virtual void Free() override;
	virtual void Shift(int len);
};

struct MyEvent : public Event
{
	void* Field;
	std::vector<int> NumParams;
	std::vector<std::string> StringParams;

	static MyEvent* Allocate();
	virtual void Free() override;
};

constexpr int EventConnect = 0;		//请求连接
constexpr int EventDisConnect = 1;		//请求断开连接
constexpr int EventAccept = 2;		//请求接受连接
constexpr int EventOnConnected = 3;		//已连接
constexpr int EventOnDisConnected = 4;		//已断开连接
constexpr int EventOnAccept = 5;		//已接受连接
constexpr int EventSend = 6;		//请求发送
constexpr int EventRecv = 7;		//请求接收

constexpr int EventItsInsertOrder = 100;		//请求报单
constexpr int EventItsInsertOrderCancel = 101;		//请求撤单
constexpr int EventItsRspOrder = 102;		//报单回报
constexpr int EventItsRtnOrder = 103;		//报单推送
constexpr int EventItsRtnTrade = 104;		//成交推送
constexpr int EventItsRtnOrderCancel = 105;		//撤单推送
constexpr int EventOrderSequence = 106;		//委托序号
constexpr int EventOnRtnOrder = 107;		//报单推送
constexpr int EventOnRtnTrade = 108;		//成交推送
constexpr int EventOnRtnOrderCancel = 109;		//撤单推送

