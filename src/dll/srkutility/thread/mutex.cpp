#include "thread/mutex.h"
namespace SRK
{
	CMutex::CMutex()
	{
#ifdef WIN32
		InitializeCriticalSection(&m_mt);
#else
		m_mt = PTHREAD_MUTEX_INITIALIZER;
		pthread_mutex_init(&m_mt,NULL);
#endif
	}

	CMutex::~CMutex()
	{
#ifdef WIN32
		DeleteCriticalSection(&m_mt);
#else
		pthread_mutex_destroy(&m_mt);
#endif
	}

	VOID CMutex::Lock()
	{
#ifdef WIN32
		EnterCriticalSection(&m_mt);
#else
		pthread_mutex_lock(&m_mt);
#endif
	}

	VOID CMutex::UnLock()
	{
#ifdef WIN32
		LeaveCriticalSection(&m_mt);
#else
		pthread_mutex_unlock(&m_mt);
#endif
	}
}

