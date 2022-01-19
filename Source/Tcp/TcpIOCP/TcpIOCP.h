#include <map>
#include <mutex>
#include "OverlappedData.h"
#include "ConnectData.h"
#include "TcpBase.h"


class TcpIOCP : public TcpBase
{
public:
	TcpIOCP(const char* name);
	~TcpIOCP();

	virtual void SetSocketTimeOut(int milliSeconds) override;
	virtual bool Init();
	virtual void Stop() override;

	void OnEventPostAccept();

protected:
	virtual void Run() override;
	virtual void HandleEvent() override;
	virtual void HandleCompletePortEvent();

	
	virtual bool PostConnect(const char* ip, const char* port) { return false; }
	virtual bool PostDisConnect(int sessionID);
	virtual bool PostAccept() { return false; }
	virtual bool PostSend(TcpEvent* tcpEvent);
	virtual bool PostRecv(OverlappedData* overlappedData);
	
	virtual void ConnectComplete(OverlappedData* overlappedData, int len);
	virtual void DisConnectComplete(OverlappedData* overlappedData, int len);
	virtual void AcceptComplete(OverlappedData* overlappedData, int len) {}
	virtual void SendComplete(OverlappedData* overlappedData, int len);
	virtual void RecvComplete(OverlappedData* overlappedData, int len);
	
	SOCKET PrepareSocket(int family);
	bool AssociateDevice(SOCKET socket);

protected:
	unsigned long m_IOWaitTime;
};

