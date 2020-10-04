#pragma once

#include "stdafx.h"
#include "lib2.h"


#define DECL_DATA_TYPE_ProxyBrowserHost \
	{ /*5*/ \
		/*m_szName*/		 _WT("Chromium浏览器宿主"), \
		/*m_szEgName*/		 _WT("ProxyBrowserHost"), \
		/*m_szExplain*/		 _WT("用于表示浏览器窗口过程方面的类。此类方法只能在浏览器进程中调用。"), \
		/*m_nCmdCount*/		 38, \
		/*m_pnCmdsIndex*/		 s_nProxyBrowserHostElementCmdIndex, \
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

#define DECL_DATA_TYPE_ProxyBrowserHost_ARGINFO \
	{ /****** ProxyBrowserHost::CloseBrowser ** 0 **/ \
		/*name*/	 _WT("强制关闭"), \
		/*explain*/	 _WT("是否要求浏览器强制关闭。 设置为假时, 将会发送\"请求关闭\"事件, 在该事件中可进一步决定是否仍然关闭该浏览器, 详情请查看该事件说明。设置为真时, 浏览器将会被要求关闭并且不会发送\"请求关闭\"事件。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_BOOL, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserHost::SetFocus ** 1 **/ \
		/*name*/	 _WT("索取焦点"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_BOOL, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserHost::SetZoomLevel ** 2 **/ \
		/*name*/	 _WT("缩放比例"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_DOUBLE, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserHost::StartDownload ** 3 **/ \
		/*name*/	 _WT("url"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserHost::SetMouseCursorChangeDisabled ** 4 **/ \
		/*name*/	 _WT("禁止"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_BOOL, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserHost::ReplaceMisspelling ** 5 **/ \
		/*name*/	 _WT("word"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserHost::AddWordToDictionary ** 6 **/ \
		/*name*/	 _WT("word"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserHost::WasHidden ** 7 **/ \
		/*name*/	 _WT("hidden"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_BOOL, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserHost::SendKeyEvent ** 8 **/ \
		/*name*/	 _WT("键盘事件"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(18,0),  /*shrewd_ptr<ProxyKeyEvent>*/ \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserHost::SendMouseClickEvent ** 9 **/ \
		/*name*/	 _WT("点击事件"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(21,0),  /*shrewd_ptr<ProxyMouseEvent>*/ \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserHost::SendMouseClickEvent ** 10 **/ \
		/*name*/	 _WT("点击类型"), \
		/*explain*/	 _WT("设置值为枚举常量: #点击事件.* "), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserHost::SendMouseClickEvent ** 11 **/ \
		/*name*/	 _WT("是否弹起"), \
		/*explain*/	 _WT("是否弹起按键"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_BOOL, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserHost::SendMouseClickEvent ** 12 **/ \
		/*name*/	 _WT("点击次数"), \
		/*explain*/	 _WT("点击次数"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserHost::SendMouseMoveEvent ** 13 **/ \
		/*name*/	 _WT("移动事件"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(21,0),  /*shrewd_ptr<ProxyMouseEvent>*/ \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserHost::SendMouseMoveEvent ** 14 **/ \
		/*name*/	 _WT("是否离开"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_BOOL, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserHost::SendMouseWheelEvent ** 15 **/ \
		/*name*/	 _WT("滚轮事件"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(21,0),  /*shrewd_ptr<ProxyMouseEvent>*/ \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserHost::SendMouseWheelEvent ** 16 **/ \
		/*name*/	 _WT("横向增量"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserHost::SendMouseWheelEvent ** 17 **/ \
		/*name*/	 _WT("纵向增量"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserHost::SendTouchEvent ** 18 **/ \
		/*name*/	 _WT("触摸事件"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(35,0),  /*shrewd_ptr<ProxyTouchEvent>*/ \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserHost::SendFocusEvent ** 19 **/ \
		/*name*/	 _WT("设置焦点"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_BOOL, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserHost::SetWindowlessFrameRate ** 20 **/ \
		/*name*/	 _WT("frame_rate"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserHost::SetAudioMuted ** 21 **/ \
		/*name*/	 _WT("静音"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_BOOL, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserHost::ShowDevTools ** 22 **/ \
		/*name*/	 _WT("windowInfo"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(37,0),  /*shrewd_ptr<ProxyWindowInfo>*/ \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserHost::ShowDevTools ** 23 **/ \
		/*name*/	 _WT("settings"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(7,0),  /*shrewd_ptr<ProxyBrowserSettings>*/ \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserHost::ShowDevTools ** 24 **/ \
		/*name*/	 _WT("inspect_element_at_x"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\
	{ /****** ProxyBrowserHost::ShowDevTools ** 25 **/ \
		/*name*/	 _WT("inspect_element_at_y"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL\
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyBrowserHost_CMDINFO(BeginIndex) \
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
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*4*/ \
		/*ccname*/	_WT("取浏览器"),\
		/*egname*/	_WT("GetBrowser"), \
		/*explain*/	_WT("返回本实例中的浏览器对象实例。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(5,0),  /*shrewd_ptr<ProxyBrowser>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*5*/ \
		/*ccname*/	_WT("关闭浏览器"),\
		/*egname*/	_WT("CloseBrowser"), \
		/*explain*/	_WT("向此实例中的浏览器发送关闭请求。发送此请求后JavaScript的\"onbeforeunload\"事件将被触发。"), \
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
	{ /*6*/ \
		/*ccname*/	_WT("TryCloseBrowser"),\
		/*egname*/	_WT("TryCloseBrowser"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+1] \
	},\
	{ /*7*/ \
		/*ccname*/	_WT("获取焦点"),\
		/*egname*/	_WT("SetFocus"), \
		/*explain*/	_WT("设置浏览器是否索取焦点。"), \
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
	{ /*8*/ \
		/*ccname*/	_WT("取窗口句柄"),\
		/*egname*/	_WT("GetWindowHandle"), \
		/*explain*/	_WT("获取浏览器窗口句柄。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_INT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+2] \
	},\
	{ /*9*/ \
		/*ccname*/	_WT("取所有者窗口句柄"),\
		/*egname*/	_WT("GetOpenerWindowHandle"), \
		/*explain*/	_WT("获取创建此浏览器窗口的窗口句柄。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_INT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+2] \
	},\
	{ /*10*/ \
		/*ccname*/	_WT("取会话环境"),\
		/*egname*/	_WT("GetRequestContext"), \
		/*explain*/	_WT("返回浏览器的会话环境会话环境对象实例。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(27,0),  /*shrewd_ptr<ProxyRequestContext>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+2] \
	},\
	{ /*11*/ \
		/*ccname*/	_WT("取缩放比例"),\
		/*egname*/	_WT("GetZoomLevel"), \
		/*explain*/	_WT("浏览器当前浏览器页面缩放比例。默认值为: 0.0f"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_DOUBLE, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+2] \
	},\
	{ /*12*/ \
		/*ccname*/	_WT("设置缩放比例"),\
		/*egname*/	_WT("SetZoomLevel"), \
		/*explain*/	_WT("设置当前浏览器页面缩放比例, 设置为0.0f时重置缩放比例。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+2] \
	},\
	{ /*13*/ \
		/*ccname*/	_WT("启动下载"),\
		/*egname*/	_WT("StartDownload"), \
		/*explain*/	_WT("下载指定URL资源。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+3] \
	},\
	{ /*14*/ \
		/*ccname*/	_WT("打印页面"),\
		/*egname*/	_WT("Print"), \
		/*explain*/	_WT("打印当前页面。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+4] \
	},\
	{ /*15*/ \
		/*ccname*/	_WT("设置禁止更改光标"),\
		/*egname*/	_WT("SetMouseCursorChangeDisabled"), \
		/*explain*/	_WT("设置当前浏览器是否禁止更改鼠标光标。"), \
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
	{ /*16*/ \
		/*ccname*/	_WT("可否更改光标"),\
		/*egname*/	_WT("IsMouseCursorChangeDisabled"), \
		/*explain*/	_WT("如果当前浏览器允许更改鼠标光标返回真。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+5] \
	},\
	{ /*17*/ \
		/*ccname*/	_WT("ReplaceMisspelling"),\
		/*egname*/	_WT("ReplaceMisspelling"), \
		/*explain*/	_WT(""), \
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
	{ /*18*/ \
		/*ccname*/	_WT("AddWordToDictionary"),\
		/*egname*/	_WT("AddWordToDictionary"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+6] \
	},\
	{ /*19*/ \
		/*ccname*/	_WT("IsWindowRenderingDisabled"),\
		/*egname*/	_WT("IsWindowRenderingDisabled"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+7] \
	},\
	{ /*20*/ \
		/*ccname*/	_WT("WasResized"),\
		/*egname*/	_WT("WasResized"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+7] \
	},\
	{ /*21*/ \
		/*ccname*/	_WT("WasHidden"),\
		/*egname*/	_WT("WasHidden"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+7] \
	},\
	{ /*22*/ \
		/*ccname*/	_WT("NotifyScreenInfoChanged"),\
		/*egname*/	_WT("NotifyScreenInfoChanged"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+8] \
	},\
	{ /*23*/ \
		/*ccname*/	_WT("发送键盘事件"),\
		/*egname*/	_WT("SendKeyEvent"), \
		/*explain*/	_WT("向当前浏览器发送指定的键盘事件。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+8] \
	},\
	{ /*24*/ \
		/*ccname*/	_WT("发送鼠标点击事件"),\
		/*egname*/	_WT("SendMouseClickEvent"), \
		/*explain*/	_WT("向当前浏览器发送鼠标点击事件。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	4, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+9] \
	},\
	{ /*25*/ \
		/*ccname*/	_WT("发送鼠标移动事件"),\
		/*egname*/	_WT("SendMouseMoveEvent"), \
		/*explain*/	_WT("向当前浏览器发送鼠标移动事件。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	2, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+13] \
	},\
	{ /*26*/ \
		/*ccname*/	_WT("发送鼠标滚轮事件"),\
		/*egname*/	_WT("SendMouseWheelEvent"), \
		/*explain*/	_WT("向当前浏览器发送鼠标滚轮事件。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	3, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+15] \
	},\
	{ /*27*/ \
		/*ccname*/	_WT("发送触摸事件"),\
		/*egname*/	_WT("SendTouchEvent"), \
		/*explain*/	_WT("向当前浏览器发送触摸事件。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+18] \
	},\
	{ /*28*/ \
		/*ccname*/	_WT("发送焦点事件"),\
		/*egname*/	_WT("SendFocusEvent"), \
		/*explain*/	_WT("向当前浏览器发送焦点事件"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+19] \
	},\
	{ /*29*/ \
		/*ccname*/	_WT("发送捕获丢失事件"),\
		/*egname*/	_WT("SendCaptureLostEvent"), \
		/*explain*/	_WT("向浏览器发送捕获丢失事件。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+20] \
	},\
	{ /*30*/ \
		/*ccname*/	_WT("NotifyMoveOrResizeStarted"),\
		/*egname*/	_WT("NotifyMoveOrResizeStarted"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+20] \
	},\
	{ /*31*/ \
		/*ccname*/	_WT("GetWindowlessFrameRate"),\
		/*egname*/	_WT("GetWindowlessFrameRate"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_INT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+20] \
	},\
	{ /*32*/ \
		/*ccname*/	_WT("SetWindowlessFrameRate"),\
		/*egname*/	_WT("SetWindowlessFrameRate"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+20] \
	},\
	{ /*33*/ \
		/*ccname*/	_WT("设置静音模式"),\
		/*egname*/	_WT("SetAudioMuted"), \
		/*explain*/	_WT("设置当前浏览器是否启用静音模式。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+21] \
	},\
	{ /*34*/ \
		/*ccname*/	_WT("是否为静音模式"),\
		/*egname*/	_WT("IsAudioMuted"), \
		/*explain*/	_WT("如果当前浏览器已设置为静音模式返回真。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+22] \
	},\
	{ /*35*/ \
		/*ccname*/	_WT("ShowDevTools"),\
		/*egname*/	_WT("ShowDevTools"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	4, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+22] \
	},\
	{ /*36*/ \
		/*ccname*/	_WT("CloseDevTools"),\
		/*egname*/	_WT("CloseDevTools"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+26] \
	},\
	{ /*37*/ \
		/*ccname*/	_WT("HasDevTools"),\
		/*egname*/	_WT("HasDevTools"), \
		/*explain*/	_WT(""), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+26] \
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyBrowserHost_FUN_NAMES \
	EDITIONS("ProxyBrowserHost_Constructor"),\
	EDITIONS("ProxyBrowserHost_Destructor"),\
	EDITIONS("ProxyBrowserHost_CopyConstructor"),\
	EDITIONS("ProxyBrowserHost_IsValid"),\
	EDITIONS("ProxyBrowserHost_GetBrowser"),\
	EDITIONS("ProxyBrowserHost_CloseBrowser"),\
	EDITIONS("ProxyBrowserHost_TryCloseBrowser"),\
	EDITIONS("ProxyBrowserHost_SetFocus"),\
	EDITIONS("ProxyBrowserHost_GetWindowHandle"),\
	EDITIONS("ProxyBrowserHost_GetOpenerWindowHandle"),\
	EDITIONS("ProxyBrowserHost_GetRequestContext"),\
	EDITIONS("ProxyBrowserHost_GetZoomLevel"),\
	EDITIONS("ProxyBrowserHost_SetZoomLevel"),\
	EDITIONS("ProxyBrowserHost_StartDownload"),\
	EDITIONS("ProxyBrowserHost_Print"),\
	EDITIONS("ProxyBrowserHost_SetMouseCursorChangeDisabled"),\
	EDITIONS("ProxyBrowserHost_IsMouseCursorChangeDisabled"),\
	EDITIONS("ProxyBrowserHost_ReplaceMisspelling"),\
	EDITIONS("ProxyBrowserHost_AddWordToDictionary"),\
	EDITIONS("ProxyBrowserHost_IsWindowRenderingDisabled"),\
	EDITIONS("ProxyBrowserHost_WasResized"),\
	EDITIONS("ProxyBrowserHost_WasHidden"),\
	EDITIONS("ProxyBrowserHost_NotifyScreenInfoChanged"),\
	EDITIONS("ProxyBrowserHost_SendKeyEvent"),\
	EDITIONS("ProxyBrowserHost_SendMouseClickEvent"),\
	EDITIONS("ProxyBrowserHost_SendMouseMoveEvent"),\
	EDITIONS("ProxyBrowserHost_SendMouseWheelEvent"),\
	EDITIONS("ProxyBrowserHost_SendTouchEvent"),\
	EDITIONS("ProxyBrowserHost_SendFocusEvent"),\
	EDITIONS("ProxyBrowserHost_SendCaptureLostEvent"),\
	EDITIONS("ProxyBrowserHost_NotifyMoveOrResizeStarted"),\
	EDITIONS("ProxyBrowserHost_GetWindowlessFrameRate"),\
	EDITIONS("ProxyBrowserHost_SetWindowlessFrameRate"),\
	EDITIONS("ProxyBrowserHost_SetAudioMuted"),\
	EDITIONS("ProxyBrowserHost_IsAudioMuted"),\
	EDITIONS("ProxyBrowserHost_ShowDevTools"),\
	EDITIONS("ProxyBrowserHost_CloseDevTools"),\
	EDITIONS("ProxyBrowserHost_HasDevTools"),\


//==========================================

#define DECL_DATA_TYPE_ProxyBrowserHost_FUN_CALLS \
	EDITIONF(ProxyBrowserHost_Constructor),\
	EDITIONF(ProxyBrowserHost_Destructor),\
	EDITIONF(ProxyBrowserHost_CopyConstructor),\
	EDITIONF(ProxyBrowserHost_IsValid),\
	EDITIONF(ProxyBrowserHost_GetBrowser),\
	EDITIONF(ProxyBrowserHost_CloseBrowser),\
	EDITIONF(ProxyBrowserHost_TryCloseBrowser),\
	EDITIONF(ProxyBrowserHost_SetFocus),\
	EDITIONF(ProxyBrowserHost_GetWindowHandle),\
	EDITIONF(ProxyBrowserHost_GetOpenerWindowHandle),\
	EDITIONF(ProxyBrowserHost_GetRequestContext),\
	EDITIONF(ProxyBrowserHost_GetZoomLevel),\
	EDITIONF(ProxyBrowserHost_SetZoomLevel),\
	EDITIONF(ProxyBrowserHost_StartDownload),\
	EDITIONF(ProxyBrowserHost_Print),\
	EDITIONF(ProxyBrowserHost_SetMouseCursorChangeDisabled),\
	EDITIONF(ProxyBrowserHost_IsMouseCursorChangeDisabled),\
	EDITIONF(ProxyBrowserHost_ReplaceMisspelling),\
	EDITIONF(ProxyBrowserHost_AddWordToDictionary),\
	EDITIONF(ProxyBrowserHost_IsWindowRenderingDisabled),\
	EDITIONF(ProxyBrowserHost_WasResized),\
	EDITIONF(ProxyBrowserHost_WasHidden),\
	EDITIONF(ProxyBrowserHost_NotifyScreenInfoChanged),\
	EDITIONF(ProxyBrowserHost_SendKeyEvent),\
	EDITIONF(ProxyBrowserHost_SendMouseClickEvent),\
	EDITIONF(ProxyBrowserHost_SendMouseMoveEvent),\
	EDITIONF(ProxyBrowserHost_SendMouseWheelEvent),\
	EDITIONF(ProxyBrowserHost_SendTouchEvent),\
	EDITIONF(ProxyBrowserHost_SendFocusEvent),\
	EDITIONF(ProxyBrowserHost_SendCaptureLostEvent),\
	EDITIONF(ProxyBrowserHost_NotifyMoveOrResizeStarted),\
	EDITIONF(ProxyBrowserHost_GetWindowlessFrameRate),\
	EDITIONF(ProxyBrowserHost_SetWindowlessFrameRate),\
	EDITIONF(ProxyBrowserHost_SetAudioMuted),\
	EDITIONF(ProxyBrowserHost_IsAudioMuted),\
	EDITIONF(ProxyBrowserHost_ShowDevTools),\
	EDITIONF(ProxyBrowserHost_CloseDevTools),\
	EDITIONF(ProxyBrowserHost_HasDevTools),\


//==========================================

extern "C"
void EDITIONF(ProxyBrowserHost_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserHost_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserHost_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserHost_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserHost_GetBrowser) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserHost_CloseBrowser) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserHost_TryCloseBrowser) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserHost_SetFocus) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserHost_GetWindowHandle) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserHost_GetOpenerWindowHandle) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserHost_GetRequestContext) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserHost_GetZoomLevel) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserHost_SetZoomLevel) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserHost_StartDownload) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserHost_Print) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserHost_SetMouseCursorChangeDisabled) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserHost_IsMouseCursorChangeDisabled) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserHost_ReplaceMisspelling) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserHost_AddWordToDictionary) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserHost_IsWindowRenderingDisabled) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserHost_WasResized) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserHost_WasHidden) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserHost_NotifyScreenInfoChanged) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserHost_SendKeyEvent) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserHost_SendMouseClickEvent) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserHost_SendMouseMoveEvent) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserHost_SendMouseWheelEvent) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserHost_SendTouchEvent) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserHost_SendFocusEvent) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserHost_SendCaptureLostEvent) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserHost_NotifyMoveOrResizeStarted) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserHost_GetWindowlessFrameRate) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserHost_SetWindowlessFrameRate) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserHost_SetAudioMuted) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserHost_IsAudioMuted) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserHost_ShowDevTools) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserHost_CloseDevTools) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowserHost_HasDevTools) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);


//==========================================

