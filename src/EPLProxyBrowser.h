#pragma once

#include "stdafx.h"
#include "lib2.h"


#define DECL_DATA_TYPE_ProxyBrowser \
	{ /*4*/ \
		/*m_szName*/		 _WT("水星浏览器"), \
		/*m_szEgName*/		 _WT("ProxyBrowser"), \
		/*m_szExplain*/		 _WT("用于代表浏览器的类。在浏览器进程中可以在任何线程上调用此类方法, 除非注释中另有说明。"), \
		/*m_nCmdCount*/		 70, \
		/*m_pnCmdsIndex*/		 s_nProxyBrowserElementCmdIndex, \
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

#define DECL_DATA_TYPE_ProxyBrowser_ARGINFO \
	{ /****** ProxyBrowser::GetFrame ** 0 **/ \
		/*name*/	 _WT("框架名称"), \
		/*explain*/	 _WT("框架名称"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::GetFrameWithIdentity ** 1 **/ \
		/*name*/	 _WT("标识符"), \
		/*explain*/	 _WT("指定框架的标识符"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT64, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::CloseBrowser ** 2 **/ \
		/*name*/	 _WT("强制关闭"), \
		/*explain*/	 _WT("是否要求浏览器强制关闭。 设置为假时, 将会发送\"请求关闭\"事件, 在该事件中可进一步决定是否仍然关闭该浏览器, 详情请查看该事件说明。设置为真时, 浏览器将会被要求关闭并且不会发送\"请求关闭\"事件。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_BOOL, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SetFocus ** 3 **/ \
		/*name*/	 _WT("焦点"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_BOOL, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SetZoomLevel ** 4 **/ \
		/*name*/	 _WT("缩放比例"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_DOUBLE, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::StartDownload ** 5 **/ \
		/*name*/	 _WT("url"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SendKeyDownEvent ** 6 **/ \
		/*name*/	 _WT("键代码"), \
		/*explain*/	 _WT("windows 键盘虚拟键值码。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SendKeyDownEvent ** 7 **/ \
		/*name*/	 _WT("是否为系统键"), \
		/*explain*/	 _WT("指示是否将该事件视为\"system key\"事件(有关详细信息, 请参见: http://msdn.microsoft.com/en-us/library/ms646286(VS.85).aspx)。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_BOOL, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SendKeyDownEvent ** 8 **/ \
		/*name*/	 _WT("事件标志"), \
		/*explain*/	 _WT("事件标志, 用于描述功能键的按下状态, 定义值位枚举常量: #事件标志.* 。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SendKeyUpEvent ** 9 **/ \
		/*name*/	 _WT("键代码"), \
		/*explain*/	 _WT("windows 键盘虚拟键值码。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SendKeyUpEvent ** 10 **/ \
		/*name*/	 _WT("是否为系统键"), \
		/*explain*/	 _WT("指示是否将该事件视为\"system key\"事件(有关详细信息, 请参见: http://msdn.microsoft.com/en-us/library/ms646286(VS.85).aspx)。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_BOOL, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SendKeyUpEvent ** 11 **/ \
		/*name*/	 _WT("事件标志"), \
		/*explain*/	 _WT("事件标志, 用于描述功能键的按下状态, 定义值位枚举常量: #事件标志.* 。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SendKeyPressEvent ** 12 **/ \
		/*name*/	 _WT("键代码"), \
		/*explain*/	 _WT("windows 键盘虚拟键值码。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SendKeyPressEvent ** 13 **/ \
		/*name*/	 _WT("是否为系统键"), \
		/*explain*/	 _WT("指示是否将该事件视为\"system key\"事件(有关详细信息, 请参见: http://msdn.microsoft.com/en-us/library/ms646286(VS.85).aspx)。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_BOOL, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SendKeyPressEvent ** 14 **/ \
		/*name*/	 _WT("持续时间"), \
		/*explain*/	 _WT("从按下到弹起的毫秒持续时间。默认值: 0 , 表示按下后立即弹起。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SendKeyPressEvent ** 15 **/ \
		/*name*/	 _WT("事件标志"), \
		/*explain*/	 _WT("事件标志, 用于描述功能键的按下状态, 定义值位枚举常量: #事件标志.* 。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SendCharEvent ** 16 **/ \
		/*name*/	 _WT("字符"), \
		/*explain*/	 _WT("输入字符, 输入字符应为标准ascii码值。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_BYTE, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SendCharArrayEvent ** 17 **/ \
		/*name*/	 _WT("字符数组"), \
		/*explain*/	 _WT("输入字符数组, 输入字符应为标准acsii码值。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SendCharArrayEvent ** 18 **/ \
		/*name*/	 _WT("间隔时间"), \
		/*explain*/	 _WT("每输入一个字符所间隔的毫秒时间。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SendMouseClickEvent ** 19 **/ \
		/*name*/	 _WT("起始位置X"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SendMouseClickEvent ** 20 **/ \
		/*name*/	 _WT("起始位置Y"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SendMouseClickEvent ** 21 **/ \
		/*name*/	 _WT("点击类型"), \
		/*explain*/	 _WT("设置值为枚举常量: #点击事件.* "), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SendMouseClickEvent ** 22 **/ \
		/*name*/	 _WT("是否弹起"), \
		/*explain*/	 _WT("是否弹起按键"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_BOOL, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SendMouseClickEvent ** 23 **/ \
		/*name*/	 _WT("点击次数"), \
		/*explain*/	 _WT("点击次数"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SendMouseClickEvent ** 24 **/ \
		/*name*/	 _WT("事件标志"), \
		/*explain*/	 _WT("事件标志, 用于描述功能键的按下状态, 定义值位枚举常量: #事件标志.* 。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SendMouseMoveEvent ** 25 **/ \
		/*name*/	 _WT("起始位置X"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SendMouseMoveEvent ** 26 **/ \
		/*name*/	 _WT("起始位置Y"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SendMouseMoveEvent ** 27 **/ \
		/*name*/	 _WT("是否离开"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_BOOL, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SendMouseMoveEvent ** 28 **/ \
		/*name*/	 _WT("事件标志"), \
		/*explain*/	 _WT("事件标志, 用于描述功能键的按下状态, 定义值位枚举常量: #事件标志.* 。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SendMouseWheelEvent ** 29 **/ \
		/*name*/	 _WT("起始位置X"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SendMouseWheelEvent ** 30 **/ \
		/*name*/	 _WT("起始位置Y"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SendMouseWheelEvent ** 31 **/ \
		/*name*/	 _WT("增量X"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SendMouseWheelEvent ** 32 **/ \
		/*name*/	 _WT("增量Y"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SendMouseWheelEvent ** 33 **/ \
		/*name*/	 _WT("事件标志"), \
		/*explain*/	 _WT("事件标志, 用于描述功能键的按下状态, 定义值位枚举常量: #事件标志.* 。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SendTouchEvent ** 34 **/ \
		/*name*/	 _WT("标识符"), \
		/*explain*/	 _WT("用于标识接触点的标识符(ID), 此值在每一次触摸事件中必须唯一, 可以是-1以外的任何数组。请注意, 最多可以跟踪16个并发触摸事件。超出部分将被忽略。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SendTouchEvent ** 35 **/ \
		/*name*/	 _WT("触点位置X"), \
		/*explain*/	 _WT("相对于视图左边的X坐标"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_FLOAT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SendTouchEvent ** 36 **/ \
		/*name*/	 _WT("触点位置Y"), \
		/*explain*/	 _WT("相对于视图顶边的Y坐标"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_FLOAT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SendTouchEvent ** 37 **/ \
		/*name*/	 _WT("半径X"), \
		/*explain*/	 _WT("以触点为圆心的X半径值, 以像素为单位, 如果不适用, 则设置为0."), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_FLOAT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SendTouchEvent ** 38 **/ \
		/*name*/	 _WT("半径Y"), \
		/*explain*/	 _WT("以触点为圆心的Y半径值, 以像素为单位, 如果不适用, 则设置为0."), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_FLOAT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SendTouchEvent ** 39 **/ \
		/*name*/	 _WT("旋转角度"), \
		/*explain*/	 _WT("旋转角度, 以弧度为单位。如果不适用, 则设置为0."), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_FLOAT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SendTouchEvent ** 40 **/ \
		/*name*/	 _WT("输入压力"), \
		/*explain*/	 _WT("指针输入的标准化压力, 在[0, 1]的范围内。 如果不适用, 则设置为0."), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_FLOAT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SendTouchEvent ** 41 **/ \
		/*name*/	 _WT("触点状态"), \
		/*explain*/	 _WT("接触点状态。触摸从一个 #触点状态.PRESSED 事件开始, 然后是零个或多个 #触点状态.MOVED 事件, 最后一个是 #触点状态.CANCELLED 事件。 不遵守此顺序的事件将被忽略。 "), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SendTouchEvent ** 42 **/ \
		/*name*/	 _WT("事件标志"), \
		/*explain*/	 _WT("事件标志, 用于描述功能键的按下状态, 定义值位枚举常量: #事件标志.* 。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SendTouchEvent ** 43 **/ \
		/*name*/	 _WT("指针类型"), \
		/*explain*/	 _WT("产生触摸事件的设备类型。定义值为枚举常量: #设备指针类型.* 。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SendFocusEvent ** 44 **/ \
		/*name*/	 _WT("焦点"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_BOOL, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SetAudioMuted ** 45 **/ \
		/*name*/	 _WT("静音"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_BOOL, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::ShowDevTools ** 46 **/ \
		/*name*/	 _WT("审查坐标X"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::ShowDevTools ** 47 **/ \
		/*name*/	 _WT("审查坐标Y"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::AddFirstScriptOnNewDocument ** 48 **/ \
		/*name*/	 _WT("脚本代码"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SetUserAgentOverride ** 49 **/ \
		/*name*/	 _WT("用户代理标识"), \
		/*explain*/	 _WT("user-agent, 用户代理标识"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SetUserAgentOverride ** 50 **/ \
		/*name*/	 _WT("应用程序版本"), \
		/*explain*/	 _WT("app-version, 应用程序版本。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SetTouchEventEmulationEnabled ** 51 **/ \
		/*name*/	 _WT("启用"), \
		/*explain*/	 _WT("是否启用触摸事件的仿真模拟。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_BOOL, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SetTouchEventEmulationEnabled ** 52 **/ \
		/*name*/	 _WT("最大触点数"), \
		/*explain*/	 _WT("支持的最大接触点数, 默认值: 1"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SetGeolocationOverride ** 53 **/ \
		/*name*/	 _WT("纬度"), \
		/*explain*/	 _WT("latitude, 模拟纬度"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_FLOAT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SetGeolocationOverride ** 54 **/ \
		/*name*/	 _WT("经度"), \
		/*explain*/	 _WT("longitude, 模拟经度"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_FLOAT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SetGeolocationOverride ** 55 **/ \
		/*name*/	 _WT("精度"), \
		/*explain*/	 _WT("accuracy, 模拟精度"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_FLOAT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SetEmulatedMedia ** 56 **/ \
		/*name*/	 _WT("媒体类型"), \
		/*explain*/	 _WT("要模拟的媒体类型。设置为空时取消模拟。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SetEmulatedMedia ** 57 **/ \
		/*name*/	 _WT("功能"), \
		/*explain*/	 _WT("要模拟的多媒体功能。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(11,0),  /*shrewd_ptr<ProxyDictionaryValue>*/ \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::EnableDeviceEmulation ** 58 **/ \
		/*name*/	 _WT("仿真参数"), \
		/*explain*/	 _WT("设备仿真参数"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(11,0),  /*shrewd_ptr<ProxyDictionaryValue>*/ \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SetEmitTouchEventsForMouse ** 59 **/ \
		/*name*/	 _WT("启用"), \
		/*explain*/	 _WT("是否启用触摸模拟传感器"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_BOOL, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SetEmitTouchEventsForMouse ** 60 **/ \
		/*name*/	 _WT("配置参数"), \
		/*explain*/	 _WT("触摸传感器配置参数, 定义值为枚举常量: #触摸传感器配置.* 。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_INT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::LoadExtension ** 61 **/ \
		/*name*/	 _WT("加载目录"), \
		/*explain*/	 _WT("扩展程序的所在目录。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::LoadExtension ** 62 **/ \
		/*name*/	 _WT("清单内容"), \
		/*explain*/	 _WT("扩展程序清单内容(应从manifest.json文件中读取)。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(11,0),  /*shrewd_ptr<ProxyDictionaryValue>*/ \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::DidLoadExtension ** 63 **/ \
		/*name*/	 _WT("扩展程序标识符"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::HasExtension ** 64 **/ \
		/*name*/	 _WT("扩展程序标识符"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::GetExtension ** 65 **/ \
		/*name*/	 _WT("扩展程序标识符"), \
		/*explain*/	 _WT(""), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::HasPreference ** 66 **/ \
		/*name*/	 _WT("首选项"), \
		/*explain*/	 _WT("首选项名称"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::GetPreference ** 67 **/ \
		/*name*/	 _WT("首选项"), \
		/*explain*/	 _WT("首选项名称。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::GetAllPreferences ** 68 **/ \
		/*name*/	 _WT("包含默认首选项"), \
		/*explain*/	 _WT("是否包含当前处于默认值的首选项。"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_BOOL, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::CanSetPreference ** 69 **/ \
		/*name*/	 _WT("首选项"), \
		/*explain*/	 _WT("首选项名称"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SetPreference ** 70 **/ \
		/*name*/	 _WT("首选项"), \
		/*explain*/	 _WT("首选项名称"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 SDT_TEXT, \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\
	{ /****** ProxyBrowser::SetPreference ** 71 **/ \
		/*name*/	 _WT("值"), \
		/*explain*/	 _WT("首选项值"), \
		/*bmp inx*/	 0, \
		/*bmp num*/	 0, \
		/*type*/	 MAKELONG(31,0),  /*shrewd_ptr<ProxyValue>*/ \
		/*default*/	 0,\
		/*state*/	 NULL \
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyBrowser_CMDINFO(BeginIndex) \
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
		/*ccname*/	_WT("取窗口句柄"),\
		/*egname*/	_WT("GetWindowHandle"), \
		/*explain*/	_WT("取浏览器窗口句柄。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_INT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*5*/ \
		/*ccname*/	_WT("可否回退"),\
		/*egname*/	_WT("CanGoBack"), \
		/*explain*/	_WT("如果当前浏览器可回退至上一浏览页面返回真, 否则返回假。"), \
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
	{ /*6*/ \
		/*ccname*/	_WT("回退"),\
		/*egname*/	_WT("GoBack"), \
		/*explain*/	_WT("设置浏览器回退到上一浏览页面。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*7*/ \
		/*ccname*/	_WT("可否前进"),\
		/*egname*/	_WT("CanGoForward"), \
		/*explain*/	_WT("如果当前浏览器可前进至下一浏览页面返回真, 否则返回假"), \
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
	{ /*8*/ \
		/*ccname*/	_WT("前进"),\
		/*egname*/	_WT("GoForward"), \
		/*explain*/	_WT("设置浏览器前进至下一浏览页面。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*9*/ \
		/*ccname*/	_WT("是否正在加载"),\
		/*egname*/	_WT("IsLoading"), \
		/*explain*/	_WT("如果当前浏览器正在加载中返回真。"), \
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
	{ /*10*/ \
		/*ccname*/	_WT("重新加载"),\
		/*egname*/	_WT("Reload"), \
		/*explain*/	_WT("重新加载此页面。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*11*/ \
		/*ccname*/	_WT("重新加载忽略缓存"),\
		/*egname*/	_WT("ReloadIgnoreCache"), \
		/*explain*/	_WT("重新加载此页面, 不从缓冲中读取。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*12*/ \
		/*ccname*/	_WT("停止加载"),\
		/*egname*/	_WT("StopLoad"), \
		/*explain*/	_WT("停止加载页面。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*13*/ \
		/*ccname*/	_WT("取标识符"),\
		/*egname*/	_WT("GetIdentifier"), \
		/*explain*/	_WT("返回此浏览器的标识符"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_INT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*14*/ \
		/*ccname*/	_WT("是否为弹出式窗口"),\
		/*egname*/	_WT("IsPopup"), \
		/*explain*/	_WT("如果当前浏览器为弹出式窗口返回真。"), \
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
	{ /*15*/ \
		/*ccname*/	_WT("是否已加载文档"),\
		/*egname*/	_WT("HasDocument"), \
		/*explain*/	_WT("如果文档已加载到浏览器中返回真。"), \
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
	{ /*16*/ \
		/*ccname*/	_WT("取主框架"),\
		/*egname*/	_WT("GetMainFrame"), \
		/*explain*/	_WT("取第一个加载的(Top-Level)框架。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(17,0),  /*shrewd_ptr<ProxyFrame>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*17*/ \
		/*ccname*/	_WT("取焦点框架"),\
		/*egname*/	_WT("GetFocusedFrame"), \
		/*explain*/	_WT("取当前拥有焦点的框架。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(17,0),  /*shrewd_ptr<ProxyFrame>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*18*/ \
		/*ccname*/	_WT("从名称取框架"),\
		/*egname*/	_WT("GetFrame"), \
		/*explain*/	_WT("使用名称检索浏览器中的指定框架, 检索成功返回对象实例, 检索失败返回空对象, 可调用IsValid() 函数检查对象有效性。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(17,0),  /*shrewd_ptr<ProxyFrame>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+0] \
	},\
	{ /*19*/ \
		/*ccname*/	_WT("从标识符取框架"),\
		/*egname*/	_WT("GetFrameWithIdentity"), \
		/*explain*/	_WT("使用标识符检索浏览器中的指定框架, 检索成功返回对象实例, 检索失败返回空对象, 可调用IsValid() 函数检查对象有效性。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(17,0),  /*shrewd_ptr<ProxyFrame>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+1] \
	},\
	{ /*20*/ \
		/*ccname*/	_WT("取框架数量"),\
		/*egname*/	_WT("GetFrameCount"), \
		/*explain*/	_WT("取浏览器中已加载的框架数量。"), \
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
	{ /*21*/ \
		/*ccname*/	_WT("取所有框架名称"),\
		/*egname*/	_WT("GetFrameNames"), \
		/*explain*/	_WT("取浏览器中所有已加载框架的名称。"), \
		/*category*/	-1, \
		/*state*/	CT_RETRUN_ARY_TYPE_DATA, \
		/*ret*/	SDT_TEXT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+2] \
	},\
	{ /*22*/ \
		/*ccname*/	_WT("取所有框架标识符"),\
		/*egname*/	_WT("GetFrameIdentifiers"), \
		/*explain*/	_WT("取浏览器中所有已加载框架的标识符。"), \
		/*category*/	-1, \
		/*state*/	CT_RETRUN_ARY_TYPE_DATA, \
		/*ret*/	SDT_INT64, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+2] \
	},\
	{ /*23*/ \
		/*ccname*/	_WT("取所有框架"),\
		/*egname*/	_WT("GetFrames"), \
		/*explain*/	_WT("取浏览器中所有已加载的框架。"), \
		/*category*/	-1, \
		/*state*/	CT_RETRUN_ARY_TYPE_DATA, \
		/*ret*/	MAKELONG(17,0),  /*shrewd_ptr<ProxyFrame>***/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+2] \
	},\
	{ /*24*/ \
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
		/*arg lp*/	&s_ArgInfo[BeginIndex+2] \
	},\
	{ /*25*/ \
		/*ccname*/	_WT("置焦点"),\
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
		/*arg lp*/	&s_ArgInfo[BeginIndex+3] \
	},\
	{ /*26*/ \
		/*ccname*/	_WT("取所有者窗口句柄"),\
		/*egname*/	_WT("GetOpenerWindowHandle"), \
		/*explain*/	_WT("取创建此浏览器窗口的窗口句柄。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_INT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+4] \
	},\
	{ /*27*/ \
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
		/*arg lp*/	&s_ArgInfo[BeginIndex+4] \
	},\
	{ /*28*/ \
		/*ccname*/	_WT("置缩放比例"),\
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
		/*arg lp*/	&s_ArgInfo[BeginIndex+4] \
	},\
	{ /*29*/ \
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
		/*arg lp*/	&s_ArgInfo[BeginIndex+5] \
	},\
	{ /*30*/ \
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
		/*arg lp*/	&s_ArgInfo[BeginIndex+6] \
	},\
	{ /*31*/ \
		/*ccname*/	_WT("按下某键"),\
		/*egname*/	_WT("SendKeyDownEvent"), \
		/*explain*/	_WT("向浏览器发送一次键盘输入事件表示某个按键已被按下。"), \
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
	{ /*32*/ \
		/*ccname*/	_WT("弹起某键"),\
		/*egname*/	_WT("SendKeyUpEvent"), \
		/*explain*/	_WT("向浏览器发送一次键盘输入事件表示某个按键已弹起。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	3, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+9] \
	},\
	{ /*33*/ \
		/*ccname*/	_WT("某键输入"),\
		/*egname*/	_WT("SendKeyPressEvent"), \
		/*explain*/	_WT("向浏览器发送一次键盘输入事件包含某个按键的按下以及弹起过程。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	4, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+12] \
	},\
	{ /*34*/ \
		/*ccname*/	_WT("字符输入"),\
		/*egname*/	_WT("SendCharEvent"), \
		/*explain*/	_WT("向浏览器发送一次键盘输入事件表示某个字符已被输入。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+16] \
	},\
	{ /*35*/ \
		/*ccname*/	_WT("字符串输入"),\
		/*egname*/	_WT("SendCharArrayEvent"), \
		/*explain*/	_WT("向浏览器发送一次键盘输入事件包含一个字符数组的输入信息。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	2, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+17] \
	},\
	{ /*36*/ \
		/*ccname*/	_WT("鼠标点击"),\
		/*egname*/	_WT("SendMouseClickEvent"), \
		/*explain*/	_WT("向当前浏览器发送鼠标点击事件。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	6, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+19] \
	},\
	{ /*37*/ \
		/*ccname*/	_WT("鼠标移动"),\
		/*egname*/	_WT("SendMouseMoveEvent"), \
		/*explain*/	_WT("向当前浏览器发送鼠标移动事件。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	4, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+25] \
	},\
	{ /*38*/ \
		/*ccname*/	_WT("鼠标滚轮滑动"),\
		/*egname*/	_WT("SendMouseWheelEvent"), \
		/*explain*/	_WT("向当前浏览器发送鼠标滚轮事件。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	5, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+29] \
	},\
	{ /*39*/ \
		/*ccname*/	_WT("触摸"),\
		/*egname*/	_WT("SendTouchEvent"), \
		/*explain*/	_WT("向当前浏览器发送触摸事件。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	10, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+34] \
	},\
	{ /*40*/ \
		/*ccname*/	_WT("置焦点事件"),\
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
		/*arg lp*/	&s_ArgInfo[BeginIndex+44] \
	},\
	{ /*41*/ \
		/*ccname*/	_WT("置捕获丢失事件"),\
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
		/*arg lp*/	&s_ArgInfo[BeginIndex+45] \
	},\
	{ /*42*/ \
		/*ccname*/	_WT("通知位置尺寸已改变"),\
		/*egname*/	_WT("NotifyMoveOrResizeStarted"), \
		/*explain*/	_WT("通知浏览器窗口位置以及尺寸已变更。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+45] \
	},\
	{ /*43*/ \
		/*ccname*/	_WT("置静音模式"),\
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
		/*arg lp*/	&s_ArgInfo[BeginIndex+45] \
	},\
	{ /*44*/ \
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
		/*arg lp*/	&s_ArgInfo[BeginIndex+46] \
	},\
	{ /*45*/ \
		/*ccname*/	_WT("打开开发者工具"),\
		/*egname*/	_WT("ShowDevTools"), \
		/*explain*/	_WT("在此浏览器中运行开发者工具。成功返回开发者工具所在浏览器窗口句柄。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_INT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	2, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+46] \
	},\
	{ /*46*/ \
		/*ccname*/	_WT("关闭开发者工具"),\
		/*egname*/	_WT("CloseDevTools"), \
		/*explain*/	_WT("关闭运行的开发者工具。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+48] \
	},\
	{ /*47*/ \
		/*ccname*/	_WT("是否已打开开发者工具"),\
		/*egname*/	_WT("HasDevTools"), \
		/*explain*/	_WT("如果此浏览器已有开发者工具在运行返回真。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+48] \
	},\
	{ /*48*/ \
		/*ccname*/	_WT("取会话管理器"),\
		/*egname*/	_WT("GetCookieManager"), \
		/*explain*/	_WT("获取本浏览器使用的会话凭证(Cookie)管理器。 未设置隐身模式时浏览器共享使用全局的会话凭证管理器。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(10,0),  /*shrewd_ptr<ProxyCookieManager>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+48] \
	},\
	{ /*49*/ \
		/*ccname*/	_WT("置优先执行脚本"),\
		/*egname*/	_WT("AddFirstScriptOnNewDocument"), \
		/*explain*/	_WT("设置浏览器DOM结构加载后第一个执行的脚本。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+48] \
	},\
	{ /*50*/ \
		/*ccname*/	_WT("置用户代理标识"),\
		/*egname*/	_WT("SetUserAgentOverride"), \
		/*explain*/	_WT("使用新的用户代理标识以覆盖默认值。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	2, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+49] \
	},\
	{ /*51*/ \
		/*ccname*/	_WT("启用触摸事件模拟"),\
		/*egname*/	_WT("SetTouchEventEmulationEnabled"), \
		/*explain*/	_WT("在不支持的平台上启用触摸事件模拟。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	2, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+51] \
	},\
	{ /*52*/ \
		/*ccname*/	_WT("置地理位置"),\
		/*egname*/	_WT("SetGeolocationOverride"), \
		/*explain*/	_WT("设置地理位置信息。所有的参数都不可以省略。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	3, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+53] \
	},\
	{ /*53*/ \
		/*ccname*/	_WT("启用多媒体模拟"),\
		/*egname*/	_WT("SetEmulatedMedia"), \
		/*explain*/	_WT("模拟CSS媒体查询的给定媒体类型或媒体功能。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	2, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+56] \
	},\
	{ /*54*/ \
		/*ccname*/	_WT("清除多媒体模拟功能"),\
		/*egname*/	_WT("ClearMediaFeatureOverrides"), \
		/*explain*/	_WT("清除模拟的多媒体功能。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+58] \
	},\
	{ /*55*/ \
		/*ccname*/	_WT("启用设备仿真模拟"),\
		/*egname*/	_WT("EnableDeviceEmulation"), \
		/*explain*/	_WT("使用指定的参数进行设备仿真。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+58] \
	},\
	{ /*56*/ \
		/*ccname*/	_WT("关闭设备仿真模拟"),\
		/*egname*/	_WT("DisableDeviceEmulation"), \
		/*explain*/	_WT("关闭指定参数的设备仿真模拟"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+59] \
	},\
	{ /*57*/ \
		/*ccname*/	_WT("启用触摸模拟传感器"),\
		/*egname*/	_WT("SetEmitTouchEventsForMouse"), \
		/*explain*/	_WT("启用触摸模拟传感器, 开启后所有的鼠标事件将会转换为触摸事件。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	2, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+59] \
	},\
	{ /*58*/ \
		/*ccname*/	_WT("载入扩展程序"),\
		/*egname*/	_WT("LoadExtension"), \
		/*explain*/	_WT("加载 chrome extension 扩展程序。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	_SDT_NULL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	2, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+61] \
	},\
	{ /*59*/ \
		/*ccname*/	_WT("从标识符载入扩展程序"),\
		/*egname*/	_WT("DidLoadExtension"), \
		/*explain*/	_WT("加载 chrome extension 扩展程序。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+63] \
	},\
	{ /*60*/ \
		/*ccname*/	_WT("是否存在扩展程序"),\
		/*egname*/	_WT("HasExtension"), \
		/*explain*/	_WT("如果在此浏览器上下文中存在目标扩展程序返回真"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+64] \
	},\
	{ /*61*/ \
		/*ccname*/	_WT("取所有扩展程序标识符"),\
		/*egname*/	_WT("GetExtensions"), \
		/*explain*/	_WT("返回此浏览器上下文中所有存在的扩展程序标识符。"), \
		/*category*/	-1, \
		/*state*/	CT_RETRUN_ARY_TYPE_DATA, \
		/*ret*/	SDT_TEXT, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+65] \
	},\
	{ /*62*/ \
		/*ccname*/	_WT("取扩展程序"),\
		/*egname*/	_WT("GetExtension"), \
		/*explain*/	_WT("返回符合指定标识符的扩展程序对象。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(15,0),  /*shrewd_ptr<ProxyExtension>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+65] \
	},\
	{ /*63*/ \
		/*ccname*/	_WT("是否为扩展程序浏览器"),\
		/*egname*/	_WT("IsBackgroundHost"), \
		/*explain*/	_WT("如果此浏览器为装载扩展程序的宿主(host)浏览器返回真。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+66] \
	},\
	{ /*64*/ \
		/*ccname*/	_WT("取用户数据"),\
		/*egname*/	_WT("GetUserData"), \
		/*explain*/	_WT("返回用于设置与浏览器关联的用户自定义数据信息。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(20,0),  /*shrewd_ptr<ProxyListValue>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	0, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+66] \
	},\
	{ /*65*/ \
		/*ccname*/	_WT("是否存在首选项"),\
		/*egname*/	_WT("HasPreference"), \
		/*explain*/	_WT("如果具有符合指定名称的首选项存在则返回真。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+66] \
	},\
	{ /*66*/ \
		/*ccname*/	_WT("取首选项"),\
		/*egname*/	_WT("GetPreference"), \
		/*explain*/	_WT("返回具有符合指定名称的首选项的值。如果首选项不存在则返回空对象。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(31,0),  /*shrewd_ptr<ProxyValue>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+67] \
	},\
	{ /*67*/ \
		/*ccname*/	_WT("取所有首选项"),\
		/*egname*/	_WT("GetAllPreferences"), \
		/*explain*/	_WT("返回所有首选项信息。返回字典类型数据, 首选项名称为\"key\", 首选项值为\"value\"。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	MAKELONG(11,0),  /*shrewd_ptr<ProxyDictionaryValue>*/ \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+68] \
	},\
	{ /*68*/ \
		/*ccname*/	_WT("可否设置首选项"),\
		/*egname*/	_WT("CanSetPreference"), \
		/*explain*/	_WT("如果具有指定名称的首选项则返回真, 可以使用 置首选项值 方法进行修改。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	1, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+69] \
	},\
	{ /*69*/ \
		/*ccname*/	_WT("置首选项值"),\
		/*egname*/	_WT("SetPreference"), \
		/*explain*/	_WT("设置符合指定名称的首选项的值。如果设置成功返回真, 否则返回假。"), \
		/*category*/	-1, \
		/*state*/	NULL, \
		/*ret*/	SDT_BOOL, \
		/*reserved*/	0, \
		/*level*/	LVL_SIMPLE, \
		/*bmp inx*/	0, \
		/*bmp num*/	0, \
		/*argcount*/	2, \
		/*arg lp*/	&s_ArgInfo[BeginIndex+70] \
	},\


//==========================================

#define DECL_DATA_TYPE_ProxyBrowser_FUN_NAMES \
	EDITIONS("ProxyBrowser_Constructor"),\
	EDITIONS("ProxyBrowser_Destructor"),\
	EDITIONS("ProxyBrowser_CopyConstructor"),\
	EDITIONS("ProxyBrowser_IsValid"),\
	EDITIONS("ProxyBrowser_GetWindowHandle"),\
	EDITIONS("ProxyBrowser_CanGoBack"),\
	EDITIONS("ProxyBrowser_GoBack"),\
	EDITIONS("ProxyBrowser_CanGoForward"),\
	EDITIONS("ProxyBrowser_GoForward"),\
	EDITIONS("ProxyBrowser_IsLoading"),\
	EDITIONS("ProxyBrowser_Reload"),\
	EDITIONS("ProxyBrowser_ReloadIgnoreCache"),\
	EDITIONS("ProxyBrowser_StopLoad"),\
	EDITIONS("ProxyBrowser_GetIdentifier"),\
	EDITIONS("ProxyBrowser_IsPopup"),\
	EDITIONS("ProxyBrowser_HasDocument"),\
	EDITIONS("ProxyBrowser_GetMainFrame"),\
	EDITIONS("ProxyBrowser_GetFocusedFrame"),\
	EDITIONS("ProxyBrowser_GetFrame"),\
	EDITIONS("ProxyBrowser_GetFrameWithIdentity"),\
	EDITIONS("ProxyBrowser_GetFrameCount"),\
	EDITIONS("ProxyBrowser_GetFrameNames"),\
	EDITIONS("ProxyBrowser_GetFrameIdentifiers"),\
	EDITIONS("ProxyBrowser_GetFrames"),\
	EDITIONS("ProxyBrowser_CloseBrowser"),\
	EDITIONS("ProxyBrowser_SetFocus"),\
	EDITIONS("ProxyBrowser_GetOpenerWindowHandle"),\
	EDITIONS("ProxyBrowser_GetZoomLevel"),\
	EDITIONS("ProxyBrowser_SetZoomLevel"),\
	EDITIONS("ProxyBrowser_StartDownload"),\
	EDITIONS("ProxyBrowser_Print"),\
	EDITIONS("ProxyBrowser_SendKeyDownEvent"),\
	EDITIONS("ProxyBrowser_SendKeyUpEvent"),\
	EDITIONS("ProxyBrowser_SendKeyPressEvent"),\
	EDITIONS("ProxyBrowser_SendCharEvent"),\
	EDITIONS("ProxyBrowser_SendCharArrayEvent"),\
	EDITIONS("ProxyBrowser_SendMouseClickEvent"),\
	EDITIONS("ProxyBrowser_SendMouseMoveEvent"),\
	EDITIONS("ProxyBrowser_SendMouseWheelEvent"),\
	EDITIONS("ProxyBrowser_SendTouchEvent"),\
	EDITIONS("ProxyBrowser_SendFocusEvent"),\
	EDITIONS("ProxyBrowser_SendCaptureLostEvent"),\
	EDITIONS("ProxyBrowser_NotifyMoveOrResizeStarted"),\
	EDITIONS("ProxyBrowser_SetAudioMuted"),\
	EDITIONS("ProxyBrowser_IsAudioMuted"),\
	EDITIONS("ProxyBrowser_ShowDevTools"),\
	EDITIONS("ProxyBrowser_CloseDevTools"),\
	EDITIONS("ProxyBrowser_HasDevTools"),\
	EDITIONS("ProxyBrowser_GetCookieManager"),\
	EDITIONS("ProxyBrowser_AddFirstScriptOnNewDocument"),\
	EDITIONS("ProxyBrowser_SetUserAgentOverride"),\
	EDITIONS("ProxyBrowser_SetTouchEventEmulationEnabled"),\
	EDITIONS("ProxyBrowser_SetGeolocationOverride"),\
	EDITIONS("ProxyBrowser_SetEmulatedMedia"),\
	EDITIONS("ProxyBrowser_ClearMediaFeatureOverrides"),\
	EDITIONS("ProxyBrowser_EnableDeviceEmulation"),\
	EDITIONS("ProxyBrowser_DisableDeviceEmulation"),\
	EDITIONS("ProxyBrowser_SetEmitTouchEventsForMouse"),\
	EDITIONS("ProxyBrowser_LoadExtension"),\
	EDITIONS("ProxyBrowser_DidLoadExtension"),\
	EDITIONS("ProxyBrowser_HasExtension"),\
	EDITIONS("ProxyBrowser_GetExtensions"),\
	EDITIONS("ProxyBrowser_GetExtension"),\
	EDITIONS("ProxyBrowser_IsBackgroundHost"),\
	EDITIONS("ProxyBrowser_GetUserData"),\
	EDITIONS("ProxyBrowser_HasPreference"),\
	EDITIONS("ProxyBrowser_GetPreference"),\
	EDITIONS("ProxyBrowser_GetAllPreferences"),\
	EDITIONS("ProxyBrowser_CanSetPreference"),\
	EDITIONS("ProxyBrowser_SetPreference"),\


//==========================================

#define DECL_DATA_TYPE_ProxyBrowser_FUN_CALLS \
	EDITIONF(ProxyBrowser_Constructor),\
	EDITIONF(ProxyBrowser_Destructor),\
	EDITIONF(ProxyBrowser_CopyConstructor),\
	EDITIONF(ProxyBrowser_IsValid),\
	EDITIONF(ProxyBrowser_GetWindowHandle),\
	EDITIONF(ProxyBrowser_CanGoBack),\
	EDITIONF(ProxyBrowser_GoBack),\
	EDITIONF(ProxyBrowser_CanGoForward),\
	EDITIONF(ProxyBrowser_GoForward),\
	EDITIONF(ProxyBrowser_IsLoading),\
	EDITIONF(ProxyBrowser_Reload),\
	EDITIONF(ProxyBrowser_ReloadIgnoreCache),\
	EDITIONF(ProxyBrowser_StopLoad),\
	EDITIONF(ProxyBrowser_GetIdentifier),\
	EDITIONF(ProxyBrowser_IsPopup),\
	EDITIONF(ProxyBrowser_HasDocument),\
	EDITIONF(ProxyBrowser_GetMainFrame),\
	EDITIONF(ProxyBrowser_GetFocusedFrame),\
	EDITIONF(ProxyBrowser_GetFrame),\
	EDITIONF(ProxyBrowser_GetFrameWithIdentity),\
	EDITIONF(ProxyBrowser_GetFrameCount),\
	EDITIONF(ProxyBrowser_GetFrameNames),\
	EDITIONF(ProxyBrowser_GetFrameIdentifiers),\
	EDITIONF(ProxyBrowser_GetFrames),\
	EDITIONF(ProxyBrowser_CloseBrowser),\
	EDITIONF(ProxyBrowser_SetFocus),\
	EDITIONF(ProxyBrowser_GetOpenerWindowHandle),\
	EDITIONF(ProxyBrowser_GetZoomLevel),\
	EDITIONF(ProxyBrowser_SetZoomLevel),\
	EDITIONF(ProxyBrowser_StartDownload),\
	EDITIONF(ProxyBrowser_Print),\
	EDITIONF(ProxyBrowser_SendKeyDownEvent),\
	EDITIONF(ProxyBrowser_SendKeyUpEvent),\
	EDITIONF(ProxyBrowser_SendKeyPressEvent),\
	EDITIONF(ProxyBrowser_SendCharEvent),\
	EDITIONF(ProxyBrowser_SendCharArrayEvent),\
	EDITIONF(ProxyBrowser_SendMouseClickEvent),\
	EDITIONF(ProxyBrowser_SendMouseMoveEvent),\
	EDITIONF(ProxyBrowser_SendMouseWheelEvent),\
	EDITIONF(ProxyBrowser_SendTouchEvent),\
	EDITIONF(ProxyBrowser_SendFocusEvent),\
	EDITIONF(ProxyBrowser_SendCaptureLostEvent),\
	EDITIONF(ProxyBrowser_NotifyMoveOrResizeStarted),\
	EDITIONF(ProxyBrowser_SetAudioMuted),\
	EDITIONF(ProxyBrowser_IsAudioMuted),\
	EDITIONF(ProxyBrowser_ShowDevTools),\
	EDITIONF(ProxyBrowser_CloseDevTools),\
	EDITIONF(ProxyBrowser_HasDevTools),\
	EDITIONF(ProxyBrowser_GetCookieManager),\
	EDITIONF(ProxyBrowser_AddFirstScriptOnNewDocument),\
	EDITIONF(ProxyBrowser_SetUserAgentOverride),\
	EDITIONF(ProxyBrowser_SetTouchEventEmulationEnabled),\
	EDITIONF(ProxyBrowser_SetGeolocationOverride),\
	EDITIONF(ProxyBrowser_SetEmulatedMedia),\
	EDITIONF(ProxyBrowser_ClearMediaFeatureOverrides),\
	EDITIONF(ProxyBrowser_EnableDeviceEmulation),\
	EDITIONF(ProxyBrowser_DisableDeviceEmulation),\
	EDITIONF(ProxyBrowser_SetEmitTouchEventsForMouse),\
	EDITIONF(ProxyBrowser_LoadExtension),\
	EDITIONF(ProxyBrowser_DidLoadExtension),\
	EDITIONF(ProxyBrowser_HasExtension),\
	EDITIONF(ProxyBrowser_GetExtensions),\
	EDITIONF(ProxyBrowser_GetExtension),\
	EDITIONF(ProxyBrowser_IsBackgroundHost),\
	EDITIONF(ProxyBrowser_GetUserData),\
	EDITIONF(ProxyBrowser_HasPreference),\
	EDITIONF(ProxyBrowser_GetPreference),\
	EDITIONF(ProxyBrowser_GetAllPreferences),\
	EDITIONF(ProxyBrowser_CanSetPreference),\
	EDITIONF(ProxyBrowser_SetPreference),\


//==========================================

extern "C"
void EDITIONF(ProxyBrowser_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_GetWindowHandle) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_CanGoBack) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_GoBack) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_CanGoForward) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_GoForward) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_IsLoading) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_Reload) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_ReloadIgnoreCache) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_StopLoad) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_GetIdentifier) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_IsPopup) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_HasDocument) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_GetMainFrame) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_GetFocusedFrame) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_GetFrame) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_GetFrameWithIdentity) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_GetFrameCount) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_GetFrameNames) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_GetFrameIdentifiers) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_GetFrames) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_CloseBrowser) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_SetFocus) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_GetOpenerWindowHandle) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_GetZoomLevel) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_SetZoomLevel) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_StartDownload) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_Print) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_SendKeyDownEvent) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_SendKeyUpEvent) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_SendKeyPressEvent) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_SendCharEvent) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_SendCharArrayEvent) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_SendMouseClickEvent) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_SendMouseMoveEvent) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_SendMouseWheelEvent) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_SendTouchEvent) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_SendFocusEvent) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_SendCaptureLostEvent) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_NotifyMoveOrResizeStarted) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_SetAudioMuted) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_IsAudioMuted) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_ShowDevTools) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_CloseDevTools) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_HasDevTools) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_GetCookieManager) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_AddFirstScriptOnNewDocument) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_SetUserAgentOverride) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_SetTouchEventEmulationEnabled) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_SetGeolocationOverride) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_SetEmulatedMedia) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_ClearMediaFeatureOverrides) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_EnableDeviceEmulation) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_DisableDeviceEmulation) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_SetEmitTouchEventsForMouse) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_LoadExtension) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_DidLoadExtension) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_HasExtension) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_GetExtensions) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_GetExtension) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_IsBackgroundHost) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_GetUserData) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_HasPreference) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_GetPreference) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_GetAllPreferences) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_CanSetPreference) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
extern "C"
void EDITIONF(ProxyBrowser_SetPreference) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);


//==========================================

