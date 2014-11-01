#include "log.h"
#include "thread/lock.h"
#include "time/srktime.h"
#include <iostream>
using namespace std;
namespace SRK
{
	void CLog::PushBack(string strMsg)
	{
		m_oSema.Wait();
		CLock lock(m_oMutex);
		CTime oTime = GetCurTimeObject();
		string strTimeMsg = oTime.ToString();
		strTimeMsg.append(strMsg);
		m_strMsg.push_back(strTimeMsg);
	}

	void CLog::PopFront()
	{
		CLock lock(m_oMutex);
		if ( m_strMsg.size())
		{
			string strMsg = m_strMsg.front();
			m_strMsg.pop_front();
			strMsg.append("\n");
			WriteLog(strMsg);
			CheckUpgrade();
			m_oSema.Relase();
		}
		
		return ;
	}

	void CLog::WriteLog(string strMsg)
	{
		cout << strMsg;
		m_oFstream.write(strMsg.c_str() , strMsg.size());
		m_oFstream.flush();
	}

	VOID CLog::Run()
	{
		while (TRUE)
		{
			PopFront();
		}
	}
	void CLog::Init(string strFilePath, string strFileName, UINT8 nCount)
	{
		if ( !m_oFstream.is_open() )
		{
			m_logTime = GetCurTimeValue();
			char aszFile[256] = {0};
			string curTime = GetCurTimeObject().ToString("YYYY-MM-DD");
			sprintf_s(aszFile, "%s%s%s_%d.log", strFilePath.c_str(), strFileName.c_str(), curTime.c_str(), nCount );
			m_oFstream.open(aszFile, ios::app);
			m_strFileName = strFileName;
			m_strFilePath = strFilePath;
			m_nCount = nCount;
			m_oSema.Init();
		}
		else
		{
			cout << "Init Log field! File Name = " << strFileName << "_" << nCount << endl;
		}
		
	}

	void CLog::CheckUpgrade()
	{
		if ( IsToday( m_logTime))
		{
			ios::pos_type dwSize = m_oFstream.tellp();
			if ( dwSize >= 1 * 1024 * 1024 * 1024)
			{
				m_oFstream.close();
				Init(m_strFilePath, m_strFileName, ++m_nCount);
			}
		}
		else
		{
			m_oFstream.close();
			CTime curTime(GetCurTimeValue());
			m_strFileName = curTime.ToString("YYYYMMDDhhmmss");
			m_nCount = 1;
			Init(m_strFilePath, m_strFileName, m_nCount);
		}
	}
}
