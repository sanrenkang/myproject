#include "thread/lock.h"

namespace SRK
{
	CLock::CLock(CMutex& mutex):m_mutex(mutex)
	{
		m_mutex.Lock();
	}

	CLock::~CLock()
	{
		m_mutex.UnLock();
	}
}
