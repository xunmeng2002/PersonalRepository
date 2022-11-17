#pragma once
#include <string>

extern std::string ProgramName;
extern std::string ConfigName;

class Sqlite;
class ItsEngine;
class MdbSubscriber;
class COfferDlg;
struct AccountInfo;
class OfferInit
{
public:
	static OfferInit* CreateInstance();
	virtual bool Init(COfferDlg* offerDlg);
	virtual void SetAccountInfo() = 0;
	virtual void InitConfig();
	virtual void InitLogger();
	virtual void InitOfferDlg(COfferDlg* offerDlg);
	virtual bool InitItsEngine(MdbSubscriber* mdbSubscriber, COfferDlg* offerDlg);
	virtual bool Start();
	virtual void Stop();

protected:
	ItsEngine* m_ItsEngine;
	Sqlite* m_Sqlite;
	AccountInfo* m_AccountInfo;
};
