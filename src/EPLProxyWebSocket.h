#pragma once

#include "stdafx.h"
#include "lib2.h"


#define DECL_DATA_TYPE_ProxyWebSocket \
	{ /*33*/ \
		/*m_szName*/		 _WT("水星网页套接字"), \
		/*m_szEgName*/		 _WT("ProxyWebSocket"), \
		/*m_szExplain*/		 _WT("表示一个Websocket连接的类。"), \
		/*m_nCmdCount*/		 12, \
		/*m_pnCmdsIndex*/		 s_nProxyWebSocketElementCmdIndex, \
		/*m_dwState*/		 NULL, \
		/*m_dwUnitBmpID*/		 NULL, \
		/*m_nEventCount*/		 0, \
		/*m_pEventBegin*/		 NULL, \
		/*m_nPropertyCount*/		 0, \
		/*m_pPropertyBegin*/		 NULL, \
		/*m_pfnGetInterface*/		 NULL, \
		/*m_nElementCount*/		 1, \
		/*m_pElementBegin*/		 s_dtDataElemnet \
	}, \


//==========================================

#define DECL_DATA_TYPE_ProxyWebSocket_ARGINFO \
	{ /****** ProxyWebSocket::SetProxy ** 0 **/ \
		/*name*/	 _WT("服务器信息"), \
		/*explain*/	 _WT("服务器URI, 输入格式: http://username:passweord@proxy-server:proxy-port"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyWebSocket::SetUserAgent ** 1 **/ \
		/*name*/	 _WT("用户代理标识"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyWebSocket::SetHeaderByName ** 2 **/ \
		/*name*/	 _WT("名称"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyWebSocket::SetHeaderByName ** 3 **/ \
		/*name*/	 _WT("值"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyWebSocket::AddSubProtocol ** 4 **/ \
		/*name*/	 _WT("协议名"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyWebSocket::Connect ** 5 **/ \
		/*name*/	 _WT("地址"), \
		/*explain*/	 _WT("服务器地址"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyWebSocket::Send ** 6 **/ \
		/*name*/	 _WT("流类型"), \
		/*explain*/	 _WT("发送的数据流类型。定义值为枚举常量: #超文本流类型.* 。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyWebSocket::Send ** 7 **/ \
		/*name*/	 _WT("流数据"), \
		/*explain*/	 _WT("待发送的字节流数据"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_BIN, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyWebSocket::Send ** 8 **/ \
		/*name*/	 _WT("流长度"), \
		/*explain*/	 _WT("流数据的字节长度"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyWebSocket_CMDINFO(BeginIndex) \
	{ /*0*/ \
		/*ccname*/	_WT("Constructor"),\
		/*egname*/	_WT(""), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	CT_IS_HIDED|CT_IS_OBJ_CONSTURCT_CMD, \
		/*ret*/	NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	NULL, \
	},\
	{ /*1*/ \
		/*ccname*/	_WT("Destructor"),\
		/*egname*/	_WT(""), \
		/*explain*/	_WT("{0}"), \
		/*category*/	-1, \
		/*state*/	CT_IS_HIDED|CT_IS_OBJ_FREE_CMD, \
		/*ret*/	NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	NULL, \
	},\
	{ /*2*/ \
		/*ccname*/	_WT("CopyConstructor"),\
		/*egname*/	_WT(""), \
		/*explain*/	_WT("{0}"), \
		/*category*/	-1, \
		/*state*/	CT_IS_HIDED|CT_IS_OBJ_COPY_CMD, \
		/*ret*/	 NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	NULL, \
	},\
	{ /*3*/ \
		/*ccname*/	_WT("置代理"),\
		/*egname*/	_WT("SetProxy"), \
		/*explain*/	_WT("设置代理服务器。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*4*/ \
		/*ccname*/	_WT("置用户代理标识"),\
		/*egname*/	_WT("SetUserAgent"), \
		/*explain*/	_WT("设置用户代理标识(user-agent)字符串。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+1] \
	},\
	{ /*5*/ \
		/*ccname*/	_WT("置标头"),\
		/*egname*/	_WT("SetHeaderByName"), \
		/*explain*/	_WT("设置HTTP标头信息。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	2, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+2] \
	},\
	{ /*6*/ \
		/*ccname*/	_WT("置子协议"),\
		/*egname*/	_WT("AddSubProtocol"), \
		/*explain*/	_WT("设置websocket子协议(sub-protocol)。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+4] \
	},\
	{ /*7*/ \
		/*ccname*/	_WT("连接"),\
		/*egname*/	_WT("Connect"), \
		/*explain*/	_WT("连接到websocket-server。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+5] \
	},\
	{ /*8*/ \
		/*ccname*/	_WT("发送"),\
		/*egname*/	_WT("Send"), \
		/*explain*/	_WT("发送数据流到服务器。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	3, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+6] \
	},\
	{ /*9*/ \
		/*ccname*/	_WT("关闭"),\
		/*egname*/	_WT("Close"), \
		/*explain*/	_WT("关闭与websocket-server的连接。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+9] \
	},\
	{ /*10*/ \
		/*ccname*/	_WT("连接是否有效"),\
		/*egname*/	_WT("IsConnected"), \
		/*explain*/	_WT("如果连接没有被断开返回真。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+9] \
	},\
	{ /*11*/ \
		/*ccname*/	_WT("是否有效"),\
		/*egname*/	_WT("IsValid"), \
		/*explain*/	_WT("此函数检查本类中的对象实例是否有效。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+9] \
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyWebSocket_FUN_NAMES \
	EDITIONS("ProxyWebSocket_Constructor"),\
	EDITIONS("ProxyWebSocket_Destructor"),\
	EDITIONS("ProxyWebSocket_CopyConstructor"),\
	EDITIONS("ProxyWebSocket_SetProxy"),\
	EDITIONS("ProxyWebSocket_SetUserAgent"),\
	EDITIONS("ProxyWebSocket_SetHeaderByName"),\
	EDITIONS("ProxyWebSocket_AddSubProtocol"),\
	EDITIONS("ProxyWebSocket_Connect"),\
	EDITIONS("ProxyWebSocket_Send"),\
	EDITIONS("ProxyWebSocket_Close"),\
	EDITIONS("ProxyWebSocket_IsConnected"),\
	EDITIONS("ProxyWebSocket_IsValid"),\


//==========================================

#define DECL_DATA_TYPE_ProxyWebSocket_FUN_CALLS \
	EDITIONF(ProxyWebSocket_Constructor),\
	EDITIONF(ProxyWebSocket_Destructor),\
	EDITIONF(ProxyWebSocket_CopyConstructor),\
	EDITIONF(ProxyWebSocket_SetProxy),\
	EDITIONF(ProxyWebSocket_SetUserAgent),\
	EDITIONF(ProxyWebSocket_SetHeaderByName),\
	EDITIONF(ProxyWebSocket_AddSubProtocol),\
	EDITIONF(ProxyWebSocket_Connect),\
	EDITIONF(ProxyWebSocket_Send),\
	EDITIONF(ProxyWebSocket_Close),\
	EDITIONF(ProxyWebSocket_IsConnected),\
	EDITIONF(ProxyWebSocket_IsValid),\


//==========================================

extern "C"
void EDITIONF(ProxyWebSocket_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyWebSocket_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyWebSocket_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyWebSocket_SetProxy) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyWebSocket_SetUserAgent) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyWebSocket_SetHeaderByName) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyWebSocket_AddSubProtocol) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyWebSocket_Connect) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyWebSocket_Send) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyWebSocket_Close) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyWebSocket_IsConnected) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyWebSocket_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);


//==========================================

