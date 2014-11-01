#ifndef _SRK_MUTEX_H
#define _SRK_MUTEX_H
#include "srktype.h"
#ifdef WIN32
#include <Windows.h>
#else
#include <unistd.h>
#include <pthread.h>
#endif
namespace SRK
{
	class CMutex
	{
#ifdef WIN32 
		typedef CRITICAL_SECTION MUTEX_T;
#else
		typedef pthread_mutex_t MUTEX_T;
#endif
	public:
		CMutex();
		~CMutex();
		VOID Lock();
		VOID UnLock();
	private:
		MUTEX_T m_mt;
	};
}
#endif