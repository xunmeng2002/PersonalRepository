#pragma once
#include "TestEngine.h"


class TestInit
{
public:
	static TestInit* CreateInstance();
	virtual bool Init();
	bool InitTestEngine(MdbSubscriber* mdbSubscriber);
	virtual void Stop();

	TestEngine* GetTestEngine();
private:
	void InitConfig();
	void InitLogger();
	
protected:
	TestEngine* m_TestEngine;
};
