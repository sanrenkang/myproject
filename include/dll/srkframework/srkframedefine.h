#ifndef _SRK_FRAME_DEFINE_H_
#define _SRK_FRAME_DEFINE_H_

enum EServerType
{
	GameServer = 1,//游戏服务器
	GateServer = 2,//网关服务器
	GmServer = 3,//GM服务器
	BranchCrossServer = 4,//跨服服务器（分）
	TrunkCrossServer = 5,//跨服服务器（总）
};

enum EDBType
{
	EDT_CFG = 1,//配置库
	EDT_LOG = 2,//日志库
	EDT_PAY = 3,//消费库
	EDT_USR = 4,//玩家数据库
};

enum ELogType
{
	ELT_DBG = 1,//调试日志
	ELT_USR = 2,//用户日志
	ELT_WARN = 3,//警告
	ELT_ERR = 4,//错误
};
#endif