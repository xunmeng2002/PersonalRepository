#include "OfferBase.h"
#include "Logger.h"
#include "Error.h"


OfferBase::OfferBase()
	:m_MdbPublisher(nullptr), m_LoginStatus(false)
{
}
OfferBase::~OfferBase()
{
}
void OfferBase::RegisterMdbPublisher(MdbPublisher* mdbPublisher)
{
	m_MdbPublisher = mdbPublisher;
}

void OfferBase::OnRtnOrder(Order* order)
{
	m_MdbPublisher->OnRtnOrder(order);
}
void OfferBase::OnRtnTrade(Trade* trade)
{
	m_MdbPublisher->OnRtnTrade(trade);
}
void OfferBase::OnErrRtnOrderCancel(OrderCancel* orderCancel)
{
	m_MdbPublisher->OnErrRtnOrderCancel(orderCancel);
}

void OfferBase::UpdateLoginStatus(bool loginStatus)
{
	m_LoginStatus = loginStatus;
	m_MdbPublisher->UpdateLoginStatus(loginStatus);
}
