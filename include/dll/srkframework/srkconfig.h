#ifndef SRK_CONFIG_H_
#define SRK_CONFIG_H_

#include "srkframedefine.h"
#include "srktype.h"
#include <string>

using namespace std;
struct SDBConfig
{
	EDBType eDBType;	//���ݿ�����
	string strDBIP;//���ݿ�IP
	UINT16 wDBPort;//���ݿ�˿�
	string strDBName;//���ݿ�����
	string strDBUser;//���ݿ��¼��
	string strDBPwd;//���ݿ�����
};

struct SLogConfig
{
	ELogType eLogType;
	string strLogName;
	UINT8 byLogFlag;
};

class CSRKConfig
#endif