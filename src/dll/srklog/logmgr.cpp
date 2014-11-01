#include "logmgr.h"
#include "lock.h"
#include <cstdarg>
namespace SRK
{

	void CLogMgr::Run()
	{
		for (CMapLogItr itr = m_mapLog.begin(); itr != m_mapLog.end(); itr++)
		{
			itr->second->Start();
		}
	}

	void CLogMgr::PushBack(UINT8 byLogType, string strMsg)
	{
		CMapLogItr itr = m_mapLog.find(byLogType);
		if( itr != m_mapLog.end())
		{
			itr->second->PushBack(strMsg);
		}
	}

	void CLogMgr::LOG_TEXT(const char* format, ...)
	{
		char aszBuf[2048] = {0};
		va_list argLst;
		va_start(argLst, format);
		vsnprintf(aszBuf, 2048, format, argLst);
		PushBack(DBG_MSG, aszBuf);
		va_end(argLst);
	}

	BOOL CLogMgr::Init()
	{
		CLog* logDBG = new CLog();
		logDBG->Init("log/", "DBG_MSG", 1);
		m_mapLog[DBG_MSG] = logDBG;
		CLog* logINFO = new CLog();
		logDBG->Init("log/", "INFO_MSG", 1);
		m_mapLog[INFO_MSG] = logDBG;
		CLog* logWARN = new CLog();
		logDBG->Init("log/", "WARN_MSG", 1);
		m_mapLog[WARN_MSG] = logDBG;
		CLog* logERR = new CLog();
		logDBG->Init("log", "ERR_MSG", 1);
		m_mapLog[ERR_MSG] = logDBG;
		return TRUE;
	}

}