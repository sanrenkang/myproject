#ifndef _SRK_TIME_H_
#define _SRK_TIME_H_
#include <time.h>
#include "srktype.h"
#include <string>
#include "mutex.h"
using namespace std;
namespace SRK
{
	class CTime
	{
	public:
		CTime();
		CTime(time_t dateValue);

	public:
		UINT32 GetYear();
		UINT32 GetMonth();
		UINT32 GetDay();
		UINT32 GetHour();
		UINT32 GetMinute();
		UINT32 GetSecond();

		UINT64 GetTimeValue();

		string ToString();
		string ToString(const char* format);

		void SetYear(UINT32 dwYear);
		void SetMonth(UINT32 dwMon);
		void SetDay(UINT32 dwDay);
		void SetHour(UINT32 dwHour);
		void SetMinute(UINT32 dwMin);
		void SetSecond(UINT32 dwSec);

		INT64 DiffSecond(UINT64 qwTimeValue);


	private:
		time_t m_timeValue;
		//CMutex m_oMutex;
	};

	UINT64 GetCurTimeValue();
	BOOL IsToday(UINT64 qwTime);
	CTime GetCurTimeObject();
}
#endif