#pragma once

#include "quickfix/Application.h"
#include "quickfix/MessageCracker.h"
#include "quickfix/Values.h"
#include "quickfix/Mutex.h"
#include "quickfix/SessionSettings.h"

#include "quickfix/fix40/Logon.h"
#include "quickfix/fix41/Logon.h"
#include "quickfix/fix42/Logon.h"
#include "quickfix/fix43/Logon.h"
#include "quickfix/fix44/Logon.h"

#include "quickfix/fix40/Logout.h"
#include "quickfix/fix41/Logout.h"
#include "quickfix/fix42/Logout.h"
#include "quickfix/fix43/Logout.h"
#include "quickfix/fix44/Logout.h"


#include "quickfix/fix40/News.h"
#include "quickfix/fix41/News.h"
#include "quickfix/fix42/News.h"
#include "quickfix/fix43/News.h"
#include "quickfix/fix44/News.h"
#include "quickfix/fix50/News.h"

#include "quickfix/fix40/NewOrderSingle.h"
#include "quickfix/fix41/NewOrderSingle.h"
#include "quickfix/fix42/NewOrderSingle.h"
#include "quickfix/fix43/NewOrderSingle.h"
#include "quickfix/fix44/NewOrderSingle.h"
#include "quickfix/fix50/NewOrderSingle.h"

#include "quickfix/fix40/ExecutionReport.h"
#include "quickfix/fix41/ExecutionReport.h"
#include "quickfix/fix42/ExecutionReport.h"
#include "quickfix/fix43/ExecutionReport.h"
#include "quickfix/fix44/ExecutionReport.h"
#include "quickfix/fix50/ExecutionReport.h"

#include "quickfix/fix40/OrderCancelRequest.h"
#include "quickfix/fix41/OrderCancelRequest.h"
#include "quickfix/fix42/OrderCancelRequest.h"
#include "quickfix/fix43/OrderCancelRequest.h"
#include "quickfix/fix44/OrderCancelRequest.h"
#include "quickfix/fix50/OrderCancelRequest.h"

#include "quickfix/fix40/OrderCancelReject.h"
#include "quickfix/fix41/OrderCancelReject.h"
#include "quickfix/fix42/OrderCancelReject.h"
#include "quickfix/fix43/OrderCancelReject.h"
#include "quickfix/fix44/OrderCancelReject.h"
#include "quickfix/fix50/OrderCancelReject.h"

#include "quickfix/fix40/OrderCancelReplaceRequest.h"
#include "quickfix/fix41/OrderCancelReplaceRequest.h"
#include "quickfix/fix42/OrderCancelReplaceRequest.h"
#include "quickfix/fix43/OrderCancelReplaceRequest.h"
#include "quickfix/fix44/OrderCancelReplaceRequest.h"
#include "quickfix/fix50/OrderCancelReplaceRequest.h"

#include <quickfix/Initiator.h>
#include "OfferBase.h"


template<typename T1, typename T2>
T2 GetItem(const T1& message)
{
    T2 item = T2();
    message.getFieldIfSet(item);
    return item;
}
template<typename T1, typename T2>
bool GetBoolItem(const T1& message, bool defaultValue = false)
{
    T2 item(defaultValue);
    message.getFieldIfSet(item);
    return item.getValue();
}
template<typename T1, typename T2>
char GetCharItem(const T1& message, char defaultValue = '0')
{
    T2 item(defaultValue);
    message.getFieldIfSet(item);
    return item.getValue();
}
template<typename T1, typename T2>
int GetIntItem(const T1& message, int defaultValue = 0)
{
    T2 item(defaultValue);
    message.getFieldIfSet(item);
    return item.getValue();
}
template<typename T1, typename T2>
double GetDoubleItem(const T1& message, double defaultValue = 0)
{
    T2 item(defaultValue);
    message.getFieldIfSet(item);
    return item.getValue();
}

template<typename T1, typename T2>
T2 GetItemWithTag(const T1& message, int tag)
{
    T2 item(tag);
    message.getFieldIfSet(item);
    return item;
}
template<typename T1, typename T2>
bool GetBoolItemWithTag(const T1& message, int tag, bool defaultValue = false)
{
    T2 item(tag, defaultValue);
    message.getFieldIfSet(item);
    return item.getValue();
}
template<typename T1, typename T2>
char GetCharItemWithTag(const T1& message, int tag, char defaultValue = '0')
{
    T2 item(0);
    message.getFieldIfSet(tag, item);
    return item.getValue();
}
template<typename T1, typename T2>
int GetIntItemWithTag(const T1& message, int tag, int defaultValue = 0)
{
    T2 item(defaultValue);
    message.getFieldIfSet(tag, item);
    return item.getValue();
}
template<typename T1, typename T2>
double GetDoubleItemWithTag(const T1& message, int tag, double defaultValue = 0)
{
    T2 item(defaultValue);
    message.getFieldIfSet(tag, item);
    return item.getValue();
}


class Order;
class OrderCancel;
class COfferDlg;
class QuickFixCommon : public FIX::Application, public FIX::MessageCracker, public OfferBase
{
public:
    QuickFixCommon(const FIX::SessionSettings& settings);
    void SetInitiator(FIX::Initiator* Initiator);

    virtual void onCreate(const FIX::SessionID&) override {}
    virtual void onLogon(const FIX::SessionID& sessionID) override;
    virtual void onLogout(const FIX::SessionID& sessionID) override;
    virtual void toAdmin(FIX::Message& message, const FIX::SessionID& sessionID) override;
    virtual void toApp(FIX::Message& message, const FIX::SessionID& sessionID) throw(FIX::DoNotSend)override;
    virtual void fromAdmin(const FIX::Message& message, const FIX::SessionID& sessionID) throw(FIX::FieldNotFound, FIX::IncorrectDataFormat, FIX::IncorrectTagValue, FIX::RejectLogon) override;
    virtual void fromApp(const FIX::Message& message, const FIX::SessionID& sessionID) throw(FIX::FieldNotFound, FIX::IncorrectDataFormat, FIX::IncorrectTagValue, FIX::UnsupportedMessageType) override;

    virtual void ReqInsertOrder(Order* order) override;
    virtual void ReqInsertOrderCancel(OrderCancel* orderCancel) override;

    virtual bool HandleInsertOrder(Order* order);
    virtual bool HandleInsertOrderCancel(OrderCancel* orderCancel);

    virtual bool HandleInsertOrder40(Order* order) { return false; }
    virtual bool HandleInsertOrder41(Order* order) { return false; }
    virtual bool HandleInsertOrder42(Order* order) { return false; }
    virtual bool HandleInsertOrder43(Order* order) { return false; }
    virtual bool HandleInsertOrder44(Order* order) { return false; }
    virtual bool HandleInsertOrder50(Order* order) { return false; }
    virtual bool HandleInsertOrderCancel40(OrderCancel* orderCancel) { return false; }
    virtual bool HandleInsertOrderCancel41(OrderCancel* orderCancel) { return false; }
    virtual bool HandleInsertOrderCancel42(OrderCancel* orderCancel) { return false; }
    virtual bool HandleInsertOrderCancel43(OrderCancel* orderCancel) { return false; }
    virtual bool HandleInsertOrderCancel44(OrderCancel* orderCancel) { return false; }
    virtual bool HandleInsertOrderCancel50(OrderCancel* orderCancel) { return false; }

    virtual void onMessage(const FIX40::Logon& message, const FIX::SessionID& sessionID) override;
    virtual void onMessage(const FIX41::Logon& message, const FIX::SessionID& sessionID) override;
    virtual void onMessage(const FIX42::Logon& message, const FIX::SessionID& sessionID) override;
    virtual void onMessage(const FIX43::Logon& message, const FIX::SessionID& sessionID) override;
    virtual void onMessage(const FIX44::Logon& message, const FIX::SessionID& sessionID) override;

    virtual void onMessage(const FIX40::Logout& message, const FIX::SessionID& sessionID) override;
    virtual void onMessage(const FIX41::Logout& message, const FIX::SessionID& sessionID) override;
    virtual void onMessage(const FIX42::Logout& message, const FIX::SessionID& sessionID) override;
    virtual void onMessage(const FIX43::Logout& message, const FIX::SessionID& sessionID) override;
    virtual void onMessage(const FIX44::Logout& message, const FIX::SessionID& sessionID) override;

    virtual void onMessage(const FIX40::News& message, const FIX::SessionID& sessionID) override;
    virtual void onMessage(const FIX41::News& message, const FIX::SessionID& sessionID) override;
    virtual void onMessage(const FIX42::News& message, const FIX::SessionID& sessionID) override;
    virtual void onMessage(const FIX43::News& message, const FIX::SessionID& sessionID) override;
    virtual void onMessage(const FIX44::News& message, const FIX::SessionID& sessionID) override;
    virtual void onMessage(const FIX50::News& message, const FIX::SessionID& sessionID) override;

    virtual void onMessage(const FIX40::ExecutionReport& message, const FIX::SessionID& sessionID) override;
    virtual void onMessage(const FIX41::ExecutionReport& message, const FIX::SessionID& sessionID) override;
    virtual void onMessage(const FIX42::ExecutionReport& message, const FIX::SessionID& sessionID) override;
    virtual void onMessage(const FIX43::ExecutionReport& message, const FIX::SessionID& sessionID) override;
    virtual void onMessage(const FIX44::ExecutionReport& message, const FIX::SessionID& sessionID) override;
    virtual void onMessage(const FIX50::ExecutionReport& message, const FIX::SessionID& sessionID) override;

    virtual void onMessage(const FIX40::OrderCancelReject& message, const FIX::SessionID& sessionID) override;
    virtual void onMessage(const FIX41::OrderCancelReject& message, const FIX::SessionID& sessionID) override;
    virtual void onMessage(const FIX42::OrderCancelReject& message, const FIX::SessionID& sessionID) override;
    virtual void onMessage(const FIX43::OrderCancelReject& message, const FIX::SessionID& sessionID) override;
    virtual void onMessage(const FIX44::OrderCancelReject& message, const FIX::SessionID& sessionID) override;
    virtual void onMessage(const FIX50::OrderCancelReject& message, const FIX::SessionID& sessionID) override;

protected:
    void PrepareHeader(FIX::Header& header);

protected:
    const FIX::SessionSettings* m_SessionSettings;
    FIX::SessionID m_SessionID;
    const FIX::Dictionary& m_FixDictionary;

    std::string m_BeginString;
    FIX::Initiator* m_Initiator;
};
