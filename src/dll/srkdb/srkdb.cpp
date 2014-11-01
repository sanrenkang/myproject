#include "srkdb.h"
#include "logmgr.h"
namespace SRK
{
	CDBSession::CDBSession()
	{
		
	}
	CDBSession::~CDBSession()
	{
		
	}
	BOOL CDBSession::Init(const char* ip, UINT32 port, const char* username, const char* userpwd, const char* dbname)
	{
		if( mysql_init(&m_mysql) == NULL )
		{
			DBG_LOG( "inital mysql handle error");
			return FALSE;
		}    

		if (mysql_real_connect(&m_mysql, ip, username, userpwd, dbname, 0, NULL, 0) == NULL)
		{
			DBG_LOG( "Failed to connect to database: Error" );
			return FALSE;
		}    

		if(mysql_set_character_set(&m_mysql, "UTF-8") != 0)
		{
			DBG_LOG( "mysql_set_character_set Error" );
			return FALSE;
		}
		
		return TRUE;
	}

}