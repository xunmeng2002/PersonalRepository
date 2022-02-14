#include "IOCompletePort.h"

IOCompletePort IOCompletePort::m_Instance;

IOCompletePort::IOCompletePort()
{
	m_IOCompletionPortHandle = NULL;
}
IOCompletePort::~IOCompletePort()
{
	Close();
}

IOCompletePort& IOCompletePort::GetInstance()
{
	return m_Instance;
}

bool IOCompletePort::Create(int maxConcurrency)
{
	m_IOCompletionPortHandle = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, maxConcurrency);
	return (m_IOCompletionPortHandle != NULL);
}
bool IOCompletePort::Close()
{
	BOOL result = TRUE;
	if (m_IOCompletionPortHandle != NULL)
	{
		result = CloseHandle(m_IOCompletionPortHandle);
		m_IOCompletionPortHandle = NULL;
	}
	return result;
}
bool IOCompletePort::AssociateDevice(HANDLE device, ULONG_PTR completeKey)
{
	return (CreateIoCompletionPort(device, m_IOCompletionPortHandle, completeKey, 0) == m_IOCompletionPortHandle);
}
bool IOCompletePort::PostStatus(DWORD dwNumBytes, ULONG_PTR completeKey, OVERLAPPED* po)
{
	return PostQueuedCompletionStatus(m_IOCompletionPortHandle, dwNumBytes, completeKey, po);
}
bool IOCompletePort::GetStatus(PDWORD pdwNumBytes, ULONG_PTR* pCompKey, OVERLAPPED** ppo, DWORD dwMilliseconds)
{
	return GetQueuedCompletionStatus(m_IOCompletionPortHandle, pdwNumBytes, pCompKey, ppo, dwMilliseconds);
}