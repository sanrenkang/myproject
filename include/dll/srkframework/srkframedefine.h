#ifndef _SRK_FRAME_DEFINE_H_
#define _SRK_FRAME_DEFINE_H_

enum EServerType
{
	GameServer = 1,//��Ϸ������
	GateServer = 2,//���ط�����
	GmServer = 3,//GM������
	BranchCrossServer = 4,//������������֣�
	TrunkCrossServer = 5,//������������ܣ�
};

enum EDBType
{
	EDT_CFG = 1,//���ÿ�
	EDT_LOG = 2,//��־��
	EDT_PAY = 3,//���ѿ�
	EDT_USR = 4,//������ݿ�
};

enum ELogType
{
	ELT_DBG = 1,//������־
	ELT_USR = 2,//�û���־
	ELT_WARN = 3,//����
	ELT_ERR = 4,//����
};
#endif