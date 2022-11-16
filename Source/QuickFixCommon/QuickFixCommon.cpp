#ifdef _MSC_VER
#pragma warning( disable : 4503 4355 4786 5040 4267 26451 26495 26812)
#endif

#include "QuickFixCommon.h"
#include "Logger.h"
#include "Config.h"


QuickFixCommon::QuickFixCommon(const FIX::SessionSettings& settings)
	:OfferBase(), m_SessionSettings(&settings), m_FixDictionary(settings.get(*(m_SessionSettings->getSessions().begin()))), m_Initiator(nullptr)
{
	m_SessionID = *(m_SessionSettings->getSessions().begin());
	m_BeginString = m_SessionID.getBeginString().getString();
}
void QuickFixCommon::SetInitiator(FIX::Initiator* Initiator)
{
	m_Initiator = Initiator;
}
void QuickFixCommon::onLogon(const FIX::SessionID& sessionID)
{
	WRITE_LOG(LogLevel::Info, "Logon - %s", sessionID.toString().c_str());
	UpdateLoginStatus(true);
}
void QuickFixCommon::onLogout(const FIX::SessionID& sessionID)
{
	WRITE_LOG(LogLevel::Info, "Logout - %s", sessionID.toString().c_str());
	UpdateLoginStatus(false);
}
void QuickFixCommon::toAdmin(FIX::Message& message, const FIX::SessionID& sessionID)
{
    WRITE_LOG(LogLevel::Info, "toAdmin FIX:Message:%s", message.toString().c_str());
}
void QuickFixCommon::toApp(FIX::Message& message, const FIX::SessionID& sessionID) throw(FIX::DoNotSend)
{
	//WRITE_LOG(LogLevel::Info, "toApp FIX:Message:%s", message.toXML().c_str());
	WRITE_LOG(LogLevel::Info, "toApp FIX:Message:%s", message.toString().c_str());
}
void QuickFixCommon::fromAdmin(const FIX::Message& message, const FIX::SessionID& sessionID) throw(FIX::FieldNotFound, FIX::IncorrectDataFormat, FIX::IncorrectTagValue, FIX::RejectLogon)
{
	crack(message, sessionID);
	WRITE_LOG(LogLevel::Info, "fromAdmin FIX:Message:%s", message.toString().c_str());
}
void QuickFixCommon::fromApp(const FIX::Message& message, const FIX::SessionID& sessionID) throw(FIX::FieldNotFound, FIX::IncorrectDataFormat, FIX::IncorrectTagValue, FIX::UnsupportedMessageType)
{
	crack(message, sessionID);
	WRITE_LOG(LogLevel::Info, "fromApp FIX:Message:%s", message.toString().c_str());
}

void QuickFixCommon::ReqInsertOrder(Order* order)
{
	if(!HandleInsertOrder(order))
	{
		m_MdbPublisher->OnRtnOrder(order);
	}
}
void QuickFixCommon::ReqInsertOrderCancel(OrderCancel* orderCancel)
{
	if (!HandleInsertOrderCancel(orderCancel))
	{
		m_MdbPublisher->OnErrRtnOrderCancel(orderCancel);
	}
}


bool QuickFixCommon::HandleInsertOrder(Order* order)
{
	if (m_BeginString == FIX::BeginString_FIX40)
	{
		return HandleInsertOrder40(order);
	}
	else if (m_BeginString == FIX::BeginString_FIX41)
	{
		return HandleInsertOrder41(order);
	}
	else if (m_BeginString == FIX::BeginString_FIX42)
	{
		return HandleInsertOrder42(order);
	}
	else if (m_BeginString == FIX::BeginString_FIX43)
	{
		return HandleInsertOrder43(order);
	}
	else if (m_BeginString == FIX::BeginString_FIX44)
	{
		return HandleInsertOrder44(order);
	}
	else if (m_BeginString == FIX::BeginString_FIX50)
	{
		return HandleInsertOrder50(order);
	}
	WRITE_LOG(LogLevel::Error, "UnSupported Fix Version:[%s]", m_BeginString.c_str());
	order->ErrorID = -1;
	order->ErrorMsg = "UnSupported Fix Version:" + m_BeginString;
	WRITE_LOG(LogLevel::Error, order->ErrorMsg.c_str());
	return false;
}
bool QuickFixCommon::HandleInsertOrderCancel(OrderCancel* orderCancel)
{
	if (m_BeginString == FIX::BeginString_FIX40)
	{
		return HandleInsertOrderCancel40(orderCancel);
	}
	else if (m_BeginString == FIX::BeginString_FIX41)
	{
		return HandleInsertOrderCancel41(orderCancel);
	}
	else if (m_BeginString == FIX::BeginString_FIX42)
	{
		return HandleInsertOrderCancel42(orderCancel);
	}
	else if (m_BeginString == FIX::BeginString_FIX43)
	{
		return HandleInsertOrderCancel43(orderCancel);
	}
	else if (m_BeginString == FIX::BeginString_FIX44)
	{
		return HandleInsertOrderCancel44(orderCancel);
	}
	else if (m_BeginString == FIX::BeginString_FIX50)
	{
		return HandleInsertOrderCancel50(orderCancel);
	}
	WRITE_LOG(LogLevel::Error, "UnSupported Fix Version:[%s]", m_BeginString.c_str());
	orderCancel->ErrorID = -1;
	orderCancel->ErrorMsg = "UnSupported Fix Version:" + m_BeginString;
	WRITE_LOG(LogLevel::Error, orderCancel->ErrorMsg.c_str());
	return false;
}

void QuickFixCommon::onMessage(const FIX40::Logon& message, const FIX::SessionID& sessionID)
{
	WRITE_LOG(LogLevel::Info, "onMessage FIX40::Logon: [%s], SessionID:[%d]", message.toString().c_str(), sessionID.toString().c_str());
}
void QuickFixCommon::onMessage(const FIX41::Logon& message, const FIX::SessionID& sessionID)
{
	WRITE_LOG(LogLevel::Info, "onMessage FIX41::Logon: [%s], SessionID:[%d]", message.toString().c_str(), sessionID.toString().c_str());
}
void QuickFixCommon::onMessage(const FIX42::Logon& message, const FIX::SessionID& sessionID)
{
	WRITE_LOG(LogLevel::Info, "onMessage FIX42::Logon: [%s], SessionID:[%d]", message.toString().c_str(), sessionID.toString().c_str());
}
void QuickFixCommon::onMessage(const FIX43::Logon& message, const FIX::SessionID& sessionID)
{
	WRITE_LOG(LogLevel::Info, "onMessage FIX43::Logon: [%s], SessionID:[%d]", message.toString().c_str(), sessionID.toString().c_str());
}
void QuickFixCommon::onMessage(const FIX44::Logon& message, const FIX::SessionID& sessionID)
{
	WRITE_LOG(LogLevel::Info, "onMessage FIX44::Logon: [%s], SessionID:[%d]", message.toString().c_str(), sessionID.toString().c_str());
}

void QuickFixCommon::onMessage(const FIX40::Logout& message, const FIX::SessionID& sessionID)
{
	WRITE_LOG(LogLevel::Info, "onMessage FIX40::Logout: [%s], SessionID:[%d]", message.toString().c_str(), sessionID.toString().c_str());
}
void QuickFixCommon::onMessage(const FIX41::Logout& message, const FIX::SessionID& sessionID)
{
	WRITE_LOG(LogLevel::Info, "onMessage FIX41::Logout: [%s], SessionID:[%d]", message.toString().c_str(), sessionID.toString().c_str());
}
void QuickFixCommon::onMessage(const FIX42::Logout& message, const FIX::SessionID& sessionID)
{
	WRITE_LOG(LogLevel::Info, "onMessage FIX42::Logout: [%s], SessionID:[%d]", message.toString().c_str(), sessionID.toString().c_str());
}
void QuickFixCommon::onMessage(const FIX43::Logout& message, const FIX::SessionID& sessionID)
{
	WRITE_LOG(LogLevel::Info, "onMessage FIX43::Logout: [%s], SessionID:[%d]", message.toString().c_str(), sessionID.toString().c_str());
}
void QuickFixCommon::onMessage(const FIX44::Logout& message, const FIX::SessionID& sessionID)
{
	WRITE_LOG(LogLevel::Info, "onMessage FIX44::Logout: [%s], SessionID:[%d]", message.toString().c_str(), sessionID.toString().c_str());
}


void QuickFixCommon::onMessage(const FIX40::News& message, const FIX::SessionID& sessionID)
{
	WRITE_LOG(LogLevel::Info, "onMessage FIX40::News: [%s], SessionID:[%d]", message.toString().c_str(), sessionID.toString().c_str());
}
void QuickFixCommon::onMessage(const FIX41::News& message, const FIX::SessionID& sessionID)
{
	WRITE_LOG(LogLevel::Info, "onMessage FIX41::News: [%s], SessionID:[%d]", message.toString().c_str(), sessionID.toString().c_str());
}
void QuickFixCommon::onMessage(const FIX42::News& message, const FIX::SessionID& sessionID)
{
	WRITE_LOG(LogLevel::Info, "onMessage FIX42::News: [%s], SessionID:[%d]", message.toString().c_str(), sessionID.toString().c_str());
}
void QuickFixCommon::onMessage(const FIX43::News& message, const FIX::SessionID& sessionID)
{
	WRITE_LOG(LogLevel::Info, "onMessage FIX43::News: [%s], SessionID:[%d]", message.toString().c_str(), sessionID.toString().c_str());
}
void QuickFixCommon::onMessage(const FIX44::News& message, const FIX::SessionID& sessionID)
{
	WRITE_LOG(LogLevel::Info, "onMessage FIX44::News: [%s], SessionID:[%d]", message.toString().c_str(), sessionID.toString().c_str());
}
void QuickFixCommon::onMessage(const FIX50::News& message, const FIX::SessionID& sessionID)
{
	WRITE_LOG(LogLevel::Info, "onMessage FIX50::News: [%s], SessionID:[%d]", message.toString().c_str(), sessionID.toString().c_str());
}

void QuickFixCommon::onMessage(const FIX40::ExecutionReport& message, const FIX::SessionID& sessionID)
{
	WRITE_LOG(LogLevel::Info, "onMessage FIX40::ExecutionReport: [%s], SessionID:[%d]", message.toString().c_str(), sessionID.toString().c_str());
}
void QuickFixCommon::onMessage(const FIX41::ExecutionReport& message, const FIX::SessionID& sessionID)
{
	WRITE_LOG(LogLevel::Info, "onMessage FIX41::ExecutionReport: [%s], SessionID:[%d]", message.toString().c_str(), sessionID.toString().c_str());
}
void QuickFixCommon::onMessage(const FIX42::ExecutionReport& message, const FIX::SessionID& sessionID)
{
	WRITE_LOG(LogLevel::Info, "onMessage FIX42::ExecutionReport: [%s], SessionID:[%d]", message.toString().c_str(), sessionID.toString().c_str());
}
void QuickFixCommon::onMessage(const FIX43::ExecutionReport& message, const FIX::SessionID& sessionID)
{
	WRITE_LOG(LogLevel::Info, "onMessage FIX43::ExecutionReport: [%s], SessionID:[%d]", message.toString().c_str(), sessionID.toString().c_str());
}
void QuickFixCommon::onMessage(const FIX44::ExecutionReport& message, const FIX::SessionID& sessionID)
{
	WRITE_LOG(LogLevel::Info, "onMessage FIX44::ExecutionReport: [%s], SessionID:[%d]", message.toString().c_str(), sessionID.toString().c_str());
}
void QuickFixCommon::onMessage(const FIX50::ExecutionReport& message, const FIX::SessionID& sessionID)
{
	WRITE_LOG(LogLevel::Info, "onMessage FIX50::ExecutionReport: [%s], SessionID:[%d]", message.toString().c_str(), sessionID.toString().c_str());
}

void QuickFixCommon::onMessage(const FIX40::OrderCancelReject& message, const FIX::SessionID& sessionID)
{
	WRITE_LOG(LogLevel::Info, "onMessage FIX40::OrderCancelReject: [%s], SessionID:[%d]", message.toString().c_str(), sessionID.toString().c_str());
}
void QuickFixCommon::onMessage(const FIX41::OrderCancelReject& message, const FIX::SessionID& sessionID)
{
	WRITE_LOG(LogLevel::Info, "onMessage FIX41::OrderCancelReject: [%s], SessionID:[%d]", message.toString().c_str(), sessionID.toString().c_str());
}
void QuickFixCommon::onMessage(const FIX42::OrderCancelReject& message, const FIX::SessionID& sessionID)
{
	WRITE_LOG(LogLevel::Info, "onMessage FIX42::OrderCancelReject: [%s], SessionID:[%d]", message.toString().c_str(), sessionID.toString().c_str());
}
void QuickFixCommon::onMessage(const FIX43::OrderCancelReject& message, const FIX::SessionID& sessionID)
{
	WRITE_LOG(LogLevel::Info, "onMessage FIX43::OrderCancelReject: [%s], SessionID:[%d]", message.toString().c_str(), sessionID.toString().c_str());
}
void QuickFixCommon::onMessage(const FIX44::OrderCancelReject& message, const FIX::SessionID& sessionID)
{
	WRITE_LOG(LogLevel::Info, "onMessage FIX44::OrderCancelReject: [%s], SessionID:[%d]", message.toString().c_str(), sessionID.toString().c_str());
}
void QuickFixCommon::onMessage(const FIX50::OrderCancelReject& message, const FIX::SessionID& sessionID)
{
	WRITE_LOG(LogLevel::Info, "onMessage FIX50::OrderCancelReject: [%s], SessionID:[%d]", message.toString().c_str(), sessionID.toString().c_str());
}

void QuickFixCommon::PrepareHeader(FIX::Header& header)
{
	FIX::BeginString beginString(m_SessionID.getBeginString());
	FIX::SenderCompID senderCompID(m_SessionID.getSenderCompID());
	FIX::TargetCompID targetCompID(m_SessionID.getTargetCompID());
	header.setField(beginString);
	header.setField(senderCompID);
	header.setField(targetCompID);

	FIX::SenderLocationID senderLocationID(m_FixDictionary.getString("SenderLocationID"));
	header.setField(senderLocationID);
}
