#ifndef _SRK_DB_H
#define _SRK_DB_H
#include "mysql.h"
#include "srktype.h"


namespace SRK
{
	class CDBSession
	{
		DECLARE_SINGLE_OBJECT(CDBSession)
	public:
		CDBSession();
		~CDBSession();
		BOOL Init(const char* ip, UINT32 port, const char* username, const char* userpwd, const char* dbname);
	protected:

	private:
		MYSQL m_mysql;
	};
}

#endif