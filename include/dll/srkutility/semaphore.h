#ifndef _SEMAPHORE_H_
#define _SEMAPHORE_H_
#include "srktype.h"
#include <Windows.h>
namespace SRK
{
	class CSemaphore
	{
	public:
		CSemaphore();
		void Wait();
		void Relase();
		void Init(UINT8 byNum = 10);
	private:
		HANDLE m_hSema;
	};
}

#endif