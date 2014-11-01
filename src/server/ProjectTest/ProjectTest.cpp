// ProjectTest.cpp : 定义控制台应用程序的入口点。
//
#include "srkdb.h"
#include <iostream>
#include "logmgr.h"
#include "time/srktime.h"
#include "thread/threadbase.h"
#include "thread/semaphore.h"

using namespace SRK;

class CTestLog : public CThreadBase
{
public:
	virtual void Run()
	{
		while (1)
		{
			char buf[250] = {0};
			sprintf_s(buf, "%d", i++);
			sprintf_s(buf, "[ %s : %d ] : %s", __FUNCTION__, __LINE__, "操蛋");
			DBG_LOG("[ %s : %d ] : %s", __FUNCTION__, __LINE__, "操蛋");
			Sleep(1);
		}
	}
	CTestLog()
	{
		i = 0;
	}
private:
	int i ;
};

class CSema : public CThreadBase
{
public:
	virtual void Run()
	{
		int i = 1;
		while ( 1 )
		{
			cout << i++ << endl;
			m_oSema.Wait();
		}
	}

	CSema()
	{
		m_oSema.Init();
	}

private:
	CSemaphore m_oSema;
};

int main(int argc, char* argv[])
{
	CDBSession test;
	test.Init("127.0.0.1", 3306, "root", "123456", "test");
	/*CLogMgr::GetInstance()->Init();
	CLogMgr::GetInstance()->Run();
	CTestLog log1;
	CTestLog log2;
	CTestLog log3;
	CTestLog log4;
	log1.Start();
	log2.Start();
	log3.Start();
	log4.Start();*/
	while(1);
	return 0;
}

