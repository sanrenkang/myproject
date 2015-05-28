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

#endif