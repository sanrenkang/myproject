#include "thread/threadbase.h"
#ifdef WIN32

#endif
namespace SRK
{
	CThreadBase::CThreadBase()
	{
		m_ThreadId = 0;
		m_bStart = 0;
	}
	CThreadBase::~CThreadBase()
	{
		if ( m_bStart )
		{
			Terminate();
		}
	}
	void CThreadBase::Start()
	{
#ifdef WIN32
		m_ThreadId = _beginthread( ThreadProc, 0, this);
		m_bStart = TRUE;
#endif
	}

	void CThreadBase::Run()
	{

	}
	void CThreadBase::OnTerminate()
	{

	}
	void  CThreadBase::Wait()
	{
		if ( m_bStart)
		{
#ifdef WIN32
			WaitForSingleObject( (HANDLE) m_ThreadId, INFINITE);
#else
			void* pStatu;
			pthread_join(m_ThreadId, &pStatu);
#endif
		}

	}

	void  CThreadBase::Terminate()
	{
#ifdef WIN32
		TerminateThread( (HANDLE)m_ThreadId, 0);
		CloseHandle((HANDLE)m_ThreadId);
#else
		pthread_cancel(m_ThreadId);
#endif
		OnTerminate();
	}

	void CThreadBase::ThreadProc(void* pParam)
	{
		CThreadBase* pThread = static_cast<CThreadBase*>(pParam);
		pThread->Run();
#ifdef WIN32
		_endthread();
#endif
		pThread->OnTerminate();
	}
}



