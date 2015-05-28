#ifndef SRK_CONFIG_H_
#define SRK_CONFIG_H_

#include "srkframedefine.h"
#include "srktype.h"
#include <string>

using namespace std;
struct SDBConfig
{
	EDBType eDBType;	//数据库类型
	string strDBIP;//数据库IP
	UINT16 wDBPort;//数据库端口
	string strDBName;//数据库名称
	string strDBUser;//数据库登录名
	string strDBPwd;//数据库密码
};

struct SLogConfig
{
	ELogType eLogType;
	string strLogName;
	UINT8 byLogFlag;
};

class CSRKConfig
#endif