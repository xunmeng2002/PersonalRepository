#include "MdbEnumDict.h"


OrderStatus ConvertToOrderStatus(const std::string& value)
{
	return (OrderStatus)value[0];
}
Direction ConvertToDirection(const std::string& value)
{
	return (Direction)value[0];
}
LoginStatus ConvertToLoginStatus(const std::string& value)
{
	return (LoginStatus)value[0];
}
HedgeFlag ConvertToHedgeFlag(const std::string& value)
{
	return (HedgeFlag)value[0];
}
OrderPriceType ConvertToOrderPriceType(const std::string& value)
{
	return (OrderPriceType)value[0];
}
OffsetFlag ConvertToOffsetFlag(const std::string& value)
{
	return (OffsetFlag)value[0];
}
ContingentCondition ConvertToContingentCondition(const std::string& value)
{
	return (ContingentCondition)value[0];
}
TimeCondition ConvertToTimeCondition(const std::string& value)
{
	return (TimeCondition)value[0];
}
VolumeCondition ConvertToVolumeCondition(const std::string& value)
{
	return (VolumeCondition)value[0];
}
ForceCloseReason ConvertToForceCloseReason(const std::string& value)
{
	return (ForceCloseReason)value[0];
}
TradeType ConvertToTradeType(const std::string& value)
{
	return (TradeType)value[0];
}
MarginPriceType ConvertToMarginPriceType(const std::string& value)
{
	return (MarginPriceType)value[0];
}
IsLocalOrder ConvertToIsLocalOrder(const std::string& value)
{
	return (IsLocalOrder)value[0];
}

