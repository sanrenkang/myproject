#include "thread/semaphore.h"

namespace SRK
{
	void CSemaphore::Init(UINT8 byNum)
	{
		m_hSema = CreateSemaphore( NULL, byNum, byNum, NULL );
	}
	CSemaphore::CSemaphore()
	{
		
	}

	void CSemaphore::Wait()
	{
		WaitForSingleObject( m_hSema, INFINITE);
	}

	void CSemaphore::Relase()
	{
		ReleaseSemaphore(m_hSema, 1, NULL);
	}
	
}
