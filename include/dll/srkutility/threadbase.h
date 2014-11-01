#ifndef _MY_THREAD_BASE_H_
#define _MY_THREAD_BASE_H_
#ifdef WIN32
#include <Windows.h>
#include <process.h>
#endif
namespace SRK
{
	class CThreadBase
	{
#ifdef WIN32
		typedef uintptr_t ThreadID;
#else
		typedef pthread_t ThreadID;
#endif
	public:
		CThreadBase();
		virtual ~CThreadBase();
	public:
		void Start();
		virtual void Run();
		virtual void OnTerminate();
		void  Wait();
		void  Terminate();
	private:
		static void ThreadProc(void* pParam);
		ThreadID m_ThreadId;
		BOOL m_bStart;
	};
}
#endif