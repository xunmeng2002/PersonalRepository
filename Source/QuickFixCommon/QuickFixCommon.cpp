#ifdef _MSC_VER
#pragma warning( disable : 4503 4355 4786 5040 4267 26451 26495 26812)
#endif

#include "QuickFixCommon.h"
#include "Logger.h"

QuickFixCommon::QuickFixCommon(const std::string& beginString)
	:m_BeginString(beginString), m_LogonStatus(false)
{

}
void QuickFixCommon::onLogon(const FIX::SessionID& sessionID)
{
	WRITE_LOG(LogLevel::Info, "Logon - %s", sessionID.toString().c_str());
	m_LogonStatus = true;
}
void QuickFixCommon::onLogout(const FIX::SessionID& sessionID)
{
	WRITE_LOG(LogLevel::Info, "Logout - %s", sessionID.toString().c_str());

	m_LogonStatus = false;
}
void QuickFixCommon::toAdmin(FIX::Message& message, const FIX::SessionID& sessionID)
{
    WRITE_LOG(LogLevel::Info, "toAdmin FIX:Message:%s", message.toString().c_str());
}
void QuickFixCommon::toApp(FIX::Message& message, const FIX::SessionID& sessionID) throw(FIX::DoNotSend)
{
	WRITE_LOG(LogLevel::Info, "toApp FIX:Message:%s", message.toXML().c_str());
}
void QuickFixCommon::fromAdmin(const FIX::Message& message, const FIX::SessionID& sessionID) throw(FIX::FieldNotFound, FIX::IncorrectDataFormat, FIX::IncorrectTagValue, FIX::RejectLogon)
{
	WRITE_LOG(LogLevel::Info, "fromAdmin FIX:Message:%s", message.toString().c_str());
}
void QuickFixCommon::fromApp(const FIX::Message& message, const FIX::SessionID& sessionID) throw(FIX::FieldNotFound, FIX::IncorrectDataFormat, FIX::IncorrectTagValue, FIX::UnsupportedMessageType)
{
	crack(message, sessionID);
	WRITE_LOG(LogLevel::Info, "fromApp FIX:Message:%s", message.toXML().c_str());
}

void QuickFixCommon::onMessage(const FIX40::News& message, const FIX::SessionID& sessionID)
{
	WRITE_LOG(LogLevel::Info, "onMessage FIX40::News: %s", message.toString().c_str());
}
void QuickFixCommon::onMessage(const FIX41::News& message, const FIX::SessionID& sessionID)
{
	WRITE_LOG(LogLevel::Info, "onMessage FIX41::News: %s", message.toString().c_str());
}
void QuickFixCommon::onMessage(const FIX42::News& message, const FIX::SessionID& sessionID)
{
	WRITE_LOG(LogLevel::Info, "onMessage FIX42::News: %s", message.toString().c_str());
}
void QuickFixCommon::onMessage(const FIX43::News& message, const FIX::SessionID& sessionID)
{
	WRITE_LOG(LogLevel::Info, "onMessage FIX43::News: %s", message.toString().c_str());
}
void QuickFixCommon::onMessage(const FIX44::News& message, const FIX::SessionID& sessionID)
{
	WRITE_LOG(LogLevel::Info, "onMessage FIX44::News: %s", message.toString().c_str());
}
void QuickFixCommon::onMessage(const FIX50::News& message, const FIX::SessionID& sessionID)
{
	WRITE_LOG(LogLevel::Info, "onMessage FIX50::News: %s", message.toString().c_str());
}

void QuickFixCommon::onMessage(const FIX40::ExecutionReport& message, const FIX::SessionID& sessionID)
{
	WRITE_LOG(LogLevel::Info, "onMessage FIX40::ExecutionReport: %s", message.toString().c_str());
}
void QuickFixCommon::onMessage(const FIX41::ExecutionReport& message, const FIX::SessionID& sessionID)
{
	WRITE_LOG(LogLevel::Info, "onMessage FIX41::ExecutionReport: %s", message.toString().c_str());
}
void QuickFixCommon::onMessage(const FIX42::ExecutionReport& message, const FIX::SessionID& sessionID)
{
	WRITE_LOG(LogLevel::Info, "onMessage FIX42::ExecutionReport: %s", message.toString().c_str());
}
void QuickFixCommon::onMessage(const FIX43::ExecutionReport& message, const FIX::SessionID& sessionID)
{
	WRITE_LOG(LogLevel::Info, "onMessage FIX43::ExecutionReport: %s", message.toString().c_str());
}
void QuickFixCommon::onMessage(const FIX44::ExecutionReport& message, const FIX::SessionID& sessionID)
{
	WRITE_LOG(LogLevel::Info, "onMessage FIX44::ExecutionReport: %s", message.toString().c_str());
}
void QuickFixCommon::onMessage(const FIX50::ExecutionReport& message, const FIX::SessionID& sessionID)
{
	WRITE_LOG(LogLevel::Info, "onMessage FIX50::ExecutionReport: %s", message.toString().c_str());
}

void QuickFixCommon::onMessage(const FIX40::OrderCancelReject& message, const FIX::SessionID& sessionID)
{
	WRITE_LOG(LogLevel::Info, "onMessage FIX40::OrderCancelReject: %s", message.toString().c_str());
}
void QuickFixCommon::onMessage(const FIX41::OrderCancelReject& message, const FIX::SessionID& sessionID)
{
	WRITE_LOG(LogLevel::Info, "onMessage FIX41::OrderCancelReject: %s", message.toString().c_str());
}
void QuickFixCommon::onMessage(const FIX42::OrderCancelReject& message, const FIX::SessionID& sessionID)
{
	WRITE_LOG(LogLevel::Info, "onMessage FIX42::OrderCancelReject: %s", message.toString().c_str());
}
void QuickFixCommon::onMessage(const FIX43::OrderCancelReject& message, const FIX::SessionID& sessionID)
{
	WRITE_LOG(LogLevel::Info, "onMessage FIX43::OrderCancelReject: %s", message.toString().c_str());
}
void QuickFixCommon::onMessage(const FIX44::OrderCancelReject& message, const FIX::SessionID& sessionID)
{
	WRITE_LOG(LogLevel::Info, "onMessage FIX44::OrderCancelReject: %s", message.toString().c_str());
}
void QuickFixCommon::onMessage(const FIX50::OrderCancelReject& message, const FIX::SessionID& sessionID)
{
	WRITE_LOG(LogLevel::Info, "onMessage FIX50::OrderCancelReject: %s", message.toString().c_str());
}

