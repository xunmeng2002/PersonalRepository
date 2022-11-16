#pragma warning(disable: 5040)
#include "QuickFixCanoncial.h"
#include "Logger.h"


std::string GetCanonicalReq(const FIX::Message& message)
{
    std::string canonicalRequest = "";
    FIX::MsgSeqNum msgSeqNum;
    if (message.getHeader().getFieldIfSet(msgSeqNum))
    {
        canonicalRequest += msgSeqNum.getString();
    }

    FIX::SenderCompID senderCompID;
    if (message.getHeader().getFieldIfSet(senderCompID))
    {
        canonicalRequest += "\n" + senderCompID.getString();
    }
    FIX::SenderSubID senderSubID;
    if (message.getHeader().getFieldIfSet(senderSubID))
    {
        canonicalRequest += "\n" + senderSubID.getString();
    }
    FIX::SendingTime sendingTime;
    if (message.getHeader().getFieldIfSet(sendingTime))
    {
        canonicalRequest += "\n" + sendingTime.getString();
    }
    FIX::TargetSubID targetSubID;
    if (message.getHeader().getFieldIfSet(targetSubID))
    {
        canonicalRequest += "\n" + targetSubID.getString();
    }
    FIX::HeartBtInt heartBtInt;
    if (message.getFieldIfSet(heartBtInt))
    {
        canonicalRequest += "\n" + heartBtInt.getString();
    }
    FIX::SenderLocationID senderLocationID;
    if (message.getHeader().getFieldIfSet(senderLocationID))
    {
        canonicalRequest += "\n" + senderLocationID.getString();
    }
    FIX::LastMsgSeqNumProcessed lastMsgSeqNumProcessed;
    if (message.getHeader().getFieldIfSet(lastMsgSeqNumProcessed))
    {
        canonicalRequest += "\n" + lastMsgSeqNumProcessed.getString();
    }

    if (message.isSetField(1603))   //ApplicationSystemName
    {
        canonicalRequest += "\n" + message.getField(1603);;
    }
    if (message.isSetField(1604))   //ApplicationSystemVersion
    {
        canonicalRequest += "\n" + message.getField(1604);;
    }
    if (message.isSetField(1605))   //ApplicationSystemVendor
    {
        canonicalRequest += "\n" + message.getField(1605);;
    }

    WRITE_LOG(LogLevel::Info, "CanonicalRequest: [%s]", canonicalRequest.c_str());
    return canonicalRequest;
}
