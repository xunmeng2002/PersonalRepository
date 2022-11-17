#include "TestEngine.h"
#include "Logger.h"


TestEngine::TestEngine()
	:m_MdbSubscriber(nullptr), m_LoginStatus(false)
{
	m_LogBuff = new char[BuffSize];
}
TestEngine::~TestEngine()
{
	delete[] m_LogBuff;
	m_LogBuff = nullptr;
}
void TestEngine::RegisterSubscriber(MdbSubscriber* mdbSubscriber)
{
	m_MdbSubscriber = mdbSubscriber;
}
bool TestEngine::Init()
{
	return true;
}
bool TestEngine::GetLoginStatus()
{
	return m_LoginStatus;
}


void TestEngine::UpdateLoginStatus(bool loginStatus)
{
	WRITE_LOG(LogLevel::Info, "UpdateLoginStatus [%d]", loginStatus);
	m_LoginStatus = loginStatus;
}
void TestEngine::OnRtnOrder(Order* field)
{
	field->ToString(m_LogBuff, BuffSize);
	WRITE_LOG(LogLevel::Info, "OnRtnOrder [%s]", m_LogBuff);
}
void TestEngine::OnRtnTrade(Trade* field)
{
	field->ToString(m_LogBuff, BuffSize);
	WRITE_LOG(LogLevel::Info, "OnRtnTrade [%s]", m_LogBuff);
}
void TestEngine::OnErrRtnOrderCancel(OrderCancel* field)
{
	field->ToString(m_LogBuff, BuffSize);
	WRITE_LOG(LogLevel::Info, "OnErrRtnOrderCancel [%s]", m_LogBuff);
}

void TestEngine::ReqLogin()
{
	m_MdbSubscriber->ReqLogin();
}
void TestEngine::ReqInsertOrder(Order* order)
{
	m_MdbSubscriber->ReqInsertOrder(order);
}
void TestEngine::ReqInsertOrderCancel(OrderCancel* orderCancel)
{
	m_MdbSubscriber->ReqInsertOrderCancel(orderCancel);
}
