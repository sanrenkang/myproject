#ifndef _SRK_LOG_MGR_H
#define _SRK_LOG_MGR_H
#include <string>
#include "threadbase.h"
#include "srktype.h"
#include "log.h"
#include <map>
using namespace std;
namespace SRK
{

#define DBG_MSG 0
#define INFO_MSG 1
#define WARN_MSG 2
#define ERR_MSG 3
#define DBG_LOG \
	CLogMgr::GetInstance()->LOG_TEXT

	class CLogMgr
	{
		typedef map<UINT8, CLog*> CMapLog;
		typedef CMapLog::iterator CMapLogItr;
		DECLARE_SINGLE_OBJECT(CLogMgr)
	public:
		CLogMgr(){}
		~CLogMgr(){}
	public: 
		void Run();
		void PushBack(UINT8 byLogType, string strMsg);
		void LOG_TEXT(const char* format, ...);
		BOOL Init();
	private:
		CMapLog m_mapLog;
	};


}


#endif