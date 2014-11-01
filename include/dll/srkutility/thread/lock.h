#ifndef _SRK_LOCK_H
#define _SRK_LOCK_H
#include "mutex.h"
namespace SRK
{
	class CLock
	{
	public:
		CLock(CMutex& mutex);
		~CLock();
	private:
		CMutex& m_mutex;
	};
}
#endif