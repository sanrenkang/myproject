#ifndef _SRK_LOG_
#define _SRK_LOG_
#include <string>
#include <deque>
#include "mutex.h"
#include <iostream>
#include <fstream>
#include "threadbase.h"
#include "semaphore.h"
using namespace std;


namespace SRK
{

	class CLog : public CThreadBase
	{
	public:
		virtual VOID Run();
		void Init(string strFilePath, string strFileName, UINT8 nCount );
		void PushBack(string strMsg);

		void PopFront( );
		void WriteLog(string strMsg);
	protected:
		void CheckUpgrade();
	private:
		deque<string> m_strMsg;
		CMutex m_oMutex;
		ofstream m_oFstream;
		string m_strFileName;
		string m_strFilePath;
		UINT8 m_nCount;
		time_t m_logTime;
		UINT8 m_byLogType;
		CSemaphore m_oSema;
	};
}

#endif