#include "time/srktime.h"
#include "thread/lock.h"
#include "string/srkstring.h"

namespace SRK
{
	CTime::CTime()
	{
		m_timeValue = 0;
		memset(&m_curTime, 0, sizeof(m_curTime));
	}
	CTime::CTime(time_t dateValue)
	{
		m_timeValue = dateValue;
		localtime_s(&m_curTime, &m_timeValue);
	}

	UINT32 CTime::GetYear()
	{
		return m_curTime.tm_year + 1990;
	}

	UINT32 CTime::GetMonth()
	{
		return m_curTime.tm_mon + 1;
	}
	UINT32 CTime::GetDay()
	{
		return m_curTime.tm_mday;
	}
	UINT32 CTime::GetHour()
	{
		return m_curTime.tm_hour;
	}
	UINT32 CTime::GetMinute()
	{
		return m_curTime.tm_min;
	}
	UINT32 CTime::GetSecond()
	{
		return m_curTime.tm_sec;
	}

	UINT64 CTime::GetTimeValue()
	{
		return m_timeValue;
	}

	string CTime::ToString()
	{
		TCHAR aszTimeBuf[64] = {0};
		SRKSprintf(aszTimeBuf,"%04u-%02u-%02u %02d:%02d:%02d",m_curTime.tm_year + 1900 , m_curTime.tm_mon + 1,m_curTime.tm_mday,
			m_curTime.tm_hour, m_curTime.tm_min, m_curTime.tm_sec);
		return aszTimeBuf;
	}

	string CTime::ToString(const char* format)
	{
		TCHAR aszTimeBuf[64] = {0};
		if ( 0 == strcmp("YYYY-MM-DD hh:mm:ss", format) )
		{
			SRKSprintf(aszTimeBuf,"%04u-%02u-%02u %02d:%02d:%02d",m_curTime.tm_year + 1900, m_curTime.tm_mon + 1,m_curTime.tm_mday,
				m_curTime.tm_hour, m_curTime.tm_min, m_curTime.tm_sec);
			return aszTimeBuf;
		}
		else if ( 0 == strcmp("YYYY-MM-DD", format))
		{
			SRKSprintf(aszTimeBuf,"%04u-%02u-%02u",m_curTime.tm_year + 1900, m_curTime.tm_mon + 1, m_curTime.tm_mday);
			return aszTimeBuf;
		}
		else if ( 0 == strcmp("hh:mm:ss" , format))
		{
			SRKSprintf(aszTimeBuf,"%02d:%02d:%02d", m_curTime.tm_hour, m_curTime.tm_min, m_curTime.tm_sec);
			return aszTimeBuf;
		}
		else if ( 0 == strcmp("YYYYMMDDhhmmss", format))
		{
			SRKSprintf(aszTimeBuf,"%04u%02u%02u%02d%02d%02d", m_curTime.tm_year + 1900, m_curTime.tm_mon + 1, m_curTime.tm_mday,
				m_curTime.tm_hour, m_curTime.tm_min, m_curTime.tm_sec);
			return aszTimeBuf;
		}
		return "";
	}

	void CTime::SetYear(UINT32 dwYear)
	{
		 
		if ( dwYear >= 1900 && dwYear < 10000)
		{
			m_curTime.tm_year = dwYear - 1900;
			m_timeValue = mktime(&m_curTime);
		}
	}
	void CTime::SetMonth(UINT32 dwMonth)
	{
		 
		if(dwMonth > 0 && dwMonth < 13)
		{
			m_curTime.tm_mon = dwMonth - 1;
			m_timeValue = mktime(&m_curTime);
		}
	}
	void CTime::SetDay(UINT32 dwDay)
	{
		 
		if ( dwDay > 0 && dwDay < 32)
		{
			m_curTime.tm_mday = dwDay;
			m_timeValue = mktime(&m_curTime);
		}
	}
	void CTime::SetHour(UINT32 dwHour)
	{
		 
		if ( dwHour >= 0 && dwHour < 24)
		{
			m_curTime.tm_hour = dwHour;
			m_timeValue = mktime(&m_curTime);
		}
	}
	void CTime::SetMinute(UINT32 dwMin)
	{
		 
		if (dwMin >= 0 && dwMin < 60)
		{
			m_curTime.tm_min = dwMin;
			m_timeValue = mktime(&m_curTime);
		}
	}
	void CTime::SetSecond(UINT32 dwSec)
	{
		 
		if (dwSec >= 0 && dwSec < 60)
		{
			m_curTime.tm_sec = dwSec;
			m_timeValue = mktime(&m_curTime);
		}
	}

	INT64 CTime::DiffSecond(UINT64 qwTimeValue)
	{
		 
		return GetTimeValue() - qwTimeValue;
	}

	UINT64 GetCurTimeValue()
	{
		time_t curTime = 0;
		static CMutex timeMutex;
		timeMutex.Lock();
		time(&curTime);
		timeMutex.UnLock();
		return curTime;
	}
	#define EPOCH_1970_1601 116444736000000000ULL
	UINT64 GetCurMicroSeconds()
	{
#ifdef WIN32
		FILETIME ft;
		GetSystemTimeAsFileTime( &ft);
		ULARGE_INTEGER li;
		li.LowPart = ft.dwLowDateTime;
		li.HighPart = ft.dwHighDateTime;
		return (li.QuadPart - EPOCH_1970_1601) / 10;
#else
		struct timeval curTime;
		 gettimeofday(&curTime, NULL);
		 return curTime.tv_sec * 1000000 + curTime.tv_usec;
#endif
	}

	BOOL IsToday(UINT64 qwTime)
	{
		time_t nowTime = 0;
		time(&nowTime);
		struct tm pNowTime;
		localtime_s(&pNowTime, &nowTime);
		struct tm pTime;
		localtime_s(&pTime, (const time_t*)&qwTime);
		if ( pNowTime.tm_year == pTime.tm_year)
		{
			if (pNowTime.tm_mon == pTime.tm_mon)
			{
				if ( pNowTime.tm_mday == pTime.tm_mday)
				{
					return TRUE;
				}
			}
		}
		return FALSE;
	}

	CTime GetCurTimeObject()
	{
		CTime curTime(GetCurTimeValue());
		return curTime;
	}

}