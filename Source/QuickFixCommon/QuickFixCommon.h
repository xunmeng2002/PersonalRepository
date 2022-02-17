#pragma once
#ifdef _MSC_VER
#pragma warning( disable : 4503 4355 4786 5040 4267)
#endif

#include "quickfix/Application.h"
#include "quickfix/MessageCracker.h"
#include "quickfix/Values.h"
#include "quickfix/Mutex.h"
#include "quickfix/SessionSettings.h"

#include "quickfix/fix40/News.h"
#include "quickfix/fix40/NewOrderSingle.h"
#include "quickfix/fix40/ExecutionReport.h"
#include "quickfix/fix40/OrderCancelRequest.h"
#include "quickfix/fix40/OrderCancelReject.h"
#include "quickfix/fix40/OrderCancelReplaceRequest.h"

#include "quickfix/fix41/News.h"
#include "quickfix/fix41/NewOrderSingle.h"
#include "quickfix/fix41/ExecutionReport.h"
#include "quickfix/fix41/OrderCancelRequest.h"
#include "quickfix/fix41/OrderCancelReject.h"
#include "quickfix/fix41/OrderCancelReplaceRequest.h"

#include "quickfix/fix42/News.h"
#include "quickfix/fix42/NewOrderSingle.h"
#include "quickfix/fix42/ExecutionReport.h"
#include "quickfix/fix42/OrderCancelRequest.h"
#include "quickfix/fix42/OrderCancelReject.h"
#include "quickfix/fix42/OrderCancelReplaceRequest.h"

#include "quickfix/fix43/News.h"
#include "quickfix/fix43/NewOrderSingle.h"
#include "quickfix/fix43/ExecutionReport.h"
#include "quickfix/fix43/OrderCancelRequest.h"
#include "quickfix/fix43/OrderCancelReject.h"
#include "quickfix/fix43/OrderCancelReplaceRequest.h"
#include "quickfix/fix43/MarketDataRequest.h"

#include "quickfix/fix44/News.h"
#include "quickfix/fix44/NewOrderSingle.h"
#include "quickfix/fix44/ExecutionReport.h"
#include "quickfix/fix44/OrderCancelRequest.h"
#include "quickfix/fix44/OrderCancelReject.h"
#include "quickfix/fix44/OrderCancelReplaceRequest.h"
#include "quickfix/fix44/MarketDataRequest.h"

#include "quickfix/fix50/News.h"
#include "quickfix/fix50/NewOrderSingle.h"
#include "quickfix/fix50/ExecutionReport.h"
#include "quickfix/fix50/OrderCancelRequest.h"
#include "quickfix/fix50/OrderCancelReject.h"
#include "quickfix/fix50/OrderCancelReplaceRequest.h"
#include "quickfix/fix50/MarketDataRequest.h"


template<typename T1, typename T2>
T2 GetItem(const T1& message)
{
    T2 item;
    message.getIfSet(item);
    return item;
}
template<typename T1, typename T2>
bool GetBoolItem(const T1& message, bool defaultValue = false)
{
    T2 item(defaultValue);
    message.getIfSet(item);
    return item.getValue();
}
template<typename T1, typename T2>
char GetCharItem(const T1& message, char defaultValue = '0')
{
    T2 item(defaultValue);
    message.getIfSet(item);
    return item.getValue();
}
template<typename T1, typename T2>
int GetIntItem(const T1& message, int defaultValue = 0)
{
    T2 item(defaultValue);
    message.getIfSet(item);
    return item.getValue();
}
template<typename T1, typename T2>
double GetDoubleItem(const T1& message, double defaultValue = 0)
{
    T2 item(defaultValue);
    message.getIfSet(item);
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