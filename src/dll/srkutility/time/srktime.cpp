#include "time/srktime.h"
#include "thread/lock.h"
namespace SRK
{
	CTime::CTime()
	{
		m_timeValue = 0;
	}
	CTime::CTime(time_t dateValue)
	{
		m_timeValue = dateValue;
	}

	UINT32 CTime::GetYear()
	{
		 
		struct tm curTime;
		localtime_s(&curTime, &m_timeValue);
		return curTime.tm_year + 1990;
	}

	UINT32 CTime::GetMonth()
	{
		 
		struct tm curTime;
		localtime_s(&curTime, &m_timeValue);
		return curTime.tm_mon + 1;
	}
	UINT32 CTime::GetDay()
	{
		 
		struct tm curTime;
		localtime_s(&curTime, &m_timeValue);
		return curTime.tm_mday;
	}
	UINT32 CTime::GetHour()
	{
		 
		struct tm curTime;
		localtime_s(&curTime, &m_timeValue);
		return curTime.tm_hour;
	}
	UINT32 CTime::GetMinute()
	{
		 
		struct tm curTime;
		localtime_s(&curTime, &m_timeValue);
		return curTime.tm_min;
	}
	UINT32 CTime::GetSecond()
	{
		 
		struct tm curTime;
		localtime_s(&curTime, &m_timeValue);
		return curTime.tm_sec;
	}

	UINT64 CTime::GetTimeValue()
	{
		 
		return m_timeValue;
	}

	string CTime::ToString()
	{
		 
		struct tm curTime;
		localtime_s(&curTime, &m_timeValue);
		curTime.tm_year += 1900;
		curTime.tm_mon += 1;
		TCHAR aszTimeBuf[64] = {0};
		sprintf_s(aszTimeBuf,"%04u-%02u-%02u %02d:%02d:%02d",curTime.tm_year, curTime.tm_mon,curTime.tm_mday,
			curTime.tm_hour, curTime.tm_min, curTime.tm_sec);
		return aszTimeBuf;
	}

	string CTime::ToString(const char* format)
	{
		 
		struct tm curTime;;
		localtime_s(&curTime, &m_timeValue);
		curTime.tm_year += 1900;
		curTime.tm_mon += 1;
		TCHAR aszTimeBuf[64] = {0};
		if ( 0 == strcmp("YYYY-MM-DD hh:mm:ss", format) )
		{
			sprintf_s(aszTimeBuf,"%04u-%02u-%02u %02d:%02d:%02d",curTime.tm_year, curTime.tm_mon,curTime.tm_mday,
				curTime.tm_hour, curTime.tm_min, curTime.tm_sec);
			return aszTimeBuf;
		}
		else if ( 0 == strcmp("YYYY-MM-DD", format))
		{
			sprintf_s(aszTimeBuf,"%04u-%02u-%02u",curTime.tm_year, curTime.tm_mon,curTime.tm_mday);
			return aszTimeBuf;
		}
		else if ( 0 == strcmp("hh:mm:ss" , format))
		{
			sprintf_s(aszTimeBuf,"%02d:%02d:%02d", curTime.tm_hour, curTime.tm_min, curTime.tm_sec);
			return aszTimeBuf;
		}
		else if ( 0 == strcmp("YYYYMMDDhhmmss", format))
		{
			sprintf_s(aszTimeBuf,"%04u%02u%02u%02d%02d%02d",curTime.tm_year, curTime.tm_mon,curTime.tm_mday,
				curTime.tm_hour, curTime.tm_min, curTime.tm_sec);
			return aszTimeBuf;
		}
		return "";
	}

	void CTime::SetYear(UINT32 dwYear)
	{
		 
		if ( dwYear >= 1900 && dwYear < 10000)
		{
			struct tm curTime;
			localtime_s(&curTime, &m_timeValue);
			curTime.tm_year = dwYear - 1900;
			m_timeValue = mktime(&curTime);
		}
	}
	void CTime::SetMonth(UINT32 dwMonth)
	{
		 
		if(dwMonth > 0 && dwMonth < 13)
		{
			struct tm curTime;
			localtime_s(&curTime, &m_timeValue);
			curTime.tm_mon = dwMonth - 1;
			m_timeValue = mktime(&curTime);
		}
	}
	void CTime::SetDay(UINT32 dwDay)
	{
		 
		if ( dwDay > 0 && dwDay < 32)
		{
			struct tm curTime;
			localtime_s(&curTime, &m_timeValue);
			curTime.tm_mday = dwDay;
			m_timeValue = mktime(&curTime);
		}
	}
	void CTime::SetHour(UINT32 dwHour)
	{
		 
		if ( dwHour >= 0 && dwHour < 24)
		{
			struct tm curTime;
			localtime_s(&curTime, &m_timeValue);
			curTime.tm_hour = dwHour;
			m_timeValue = mktime(&curTime);
		}
	}
	void CTime::SetMinute(UINT32 dwMin)
	{
		 
		if (dwMin >= 0 && dwMin < 60)
		{
			struct tm curTime;
			localtime_s(&curTime, &m_timeValue);
			curTime.tm_min = dwMin;
			m_timeValue = mktime(&curTime);
		}
	}
	void CTime::SetSecond(UINT32 dwSec)
	{
		 
		if (dwSec >= 0 && dwSec < 60)
		{
			struct tm curTime;
			localtime_s(&curTime, &m_timeValue);
			curTime.tm_sec = dwSec;
			m_timeValue = mktime(&curTime);
		}
	}

	INT64 CTime::DiffSecond(UINT64 qwTimeValue)
	{
		 
		return GetTimeValue() - qwTimeValue;
	}

	UINT64 GetCurTimeValue()
	{
		time_t curTime = 0;
		time(&curTime);
		return curTime;
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