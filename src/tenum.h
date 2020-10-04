#pragma once
#include "stdafx.h"
#include "lib2.h"


#define DATA_TYPE_ENUM_DEFINITION(Name, EgName, Explain, Elem) \
	{ \
		/*m_szName*/			_WT(Name), \
		/*m_szEgName*/			_WT(EgName), \
		/*m_szExplain*/			_WT(Explain), \
		/*m_nCmdCount*/			0, \
		/*m_pnCmdsIndex*/ 		NULL, \
		/*m_dwState*/			_DT_OS (__OS_WIN) | LDT_ENUM, \
		/*m_dwUnitBmpID*/		NULL, \
		/*m_nEventCount*/		0, \
		/*m_pEventBegin*/		NULL, \
		/*m_nPropertyCount*/	0, \
		/*m_pPropertyBegin*/	NULL, \
		/*m_pfnGetInterface*/	NULL, \
		/*m_nElementCount*/		sizeof(Elem)/sizeof(Elem[0]), \
		/*m_pElementBegin*/		Elem \
	}, \



LIB_DATA_TYPE_ELEMENT s_ChromiumMouseEventEnumList[] = {
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("鼠标左键"), 
		/*szEgName*/	_WT("MBT_LEFT"), 
		/*szExplain*/	_WT(""), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	0 
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("鼠标中键"), 
		/*szEgName*/	_WT("MBT_LEFT"), 
		/*szExplain*/	_WT(""), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1 
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("鼠标右键"), 
		/*szEgName*/	_WT("MBT_LEFT"), 
		/*szExplain*/	_WT(""), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	2 
	},
};
#define ENUM_MOUSE_EVENT_EXPLAIN	"鼠标点击事件类型枚举常量。"


LIB_DATA_TYPE_ELEMENT s_RequestReferrerPolicyEnumList[] = {
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("默认"), 
		/*szEgName*/	_WT("default"), 
		/*szExplain*/	_WT("在没有指定任何策略的情况下用户代理的默认行为。在同等安全级别的情况下，来源页面的地址会被发送(HTTPS->HTTPS)，但是在降级的情况下不会被发送 (HTTPS->HTTP)。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	0 
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("同源发送一"), 
		/*szEgName*/	_WT("reduct_referrer_granularity_on_transition_cross_origin"), 
		/*szExplain*/	_WT("对于同源的请求，会发送完整的URL作为来源地址，但是对于非同源请求如果目标是HTTP,则将清除HTTPS来源地址。如果目标地址与来源地址是跨源的(但不降级),则仅发送简化后的来源地址。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1 
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("同源发送二"), 
		/*szEgName*/	_WT("origin_only_on_transition_cross_origin"), 
		/*szExplain*/	_WT("对于同源的请求，会发送完整的URL作为来源地址，但是对于非同源请求仅发送文件的源。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	2
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("从不更改"), 
		/*szEgName*/	_WT("never_clear_referrer"), 
		/*szExplain*/	_WT("从不更改来源地址。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	3
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("简化地址"), 
		/*szEgName*/	_WT("origin"), 
		/*szExplain*/	_WT("不管重定向位置如何, 都将来源地址化简为原始地址。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	4
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("交叉清除"), 
		/*szEgName*/	_WT("clear_referrer_on_transition_cross_rogin"), 
		/*szExplain*/	_WT("当请求的来源地址与请求目标来源相互交叉时, 清除来源地址。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	5
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("简化发送"), 
		/*szEgName*/	_WT("clear_on_transition_from_secure_to_insecure"), 
		/*szExplain*/	_WT("将来源地址简化为原始地址, 但是如果来源地址的值为HTTPS并且目标地址为HTTP, 则将其完全清除。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	6
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("从不发送"), 
		/*szEgName*/	_WT("no_referrer"), 
		/*szExplain*/	_WT("无论目标地址如何，始终清除来源地址。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	7
	},
};
#define ENUM_REFERRER_POLICY_EXPLAIN	"同源策略枚举常量"


LIB_DATA_TYPE_ELEMENT s_ResourceTypeEnumList[] = {
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("MAIN_FRAME"), 
		/*szEgName*/	_WT("MAIN_FRAME"), 
		/*szExplain*/	_WT("Top level page."), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	0 
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("SUB_FRAME"), 
		/*szEgName*/	_WT("SUB_FRAME"), 
		/*szExplain*/	_WT("Frame or iframe."), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1 
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("STYLESHEET"), 
		/*szEgName*/	_WT("STYLESHEET"), 
		/*szExplain*/	_WT("CSS stylesheet."), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	2 
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("SCRIPT"), 
		/*szEgName*/	_WT("SCRIPT"), 
		/*szExplain*/	_WT("External script."), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	3 
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("IMAGE"), 
		/*szEgName*/	_WT("IMAGE"), 
		/*szExplain*/	_WT("Image (jpg/gif/png/etc)."), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	4
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("FONT_RESOURCE"), 
		/*szEgName*/	_WT("FONT_RESOURCE"), 
		/*szExplain*/	_WT("font"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	5
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("SUB_RESOURCE"), 
		/*szEgName*/	_WT("SUB_RESOURCE"), 
		/*szExplain*/	_WT("Some other subresource."), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	6
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("OBJECT"), 
		/*szEgName*/	_WT("OBJECT"), 
		/*szExplain*/	_WT("Object (or embed) tag for a plugin, or a resource that a plugin requested."), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	7 
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("MEDIA"), 
		/*szEgName*/	_WT("MEDIA"), 
		/*szExplain*/	_WT("Media resource."), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	8
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("WORKER"), 
		/*szEgName*/	_WT("WORKER"), 
		/*szExplain*/	_WT("Main resource of a dedicated worker."), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	9 
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("SHARED_WORKER"), 
		/*szEgName*/	_WT("SHARED_WORKER"), 
		/*szExplain*/	_WT("Main resource of a shared worker."), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	10 
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("PREFETCH"), 
		/*szEgName*/	_WT("PREFETCH"), 
		/*szExplain*/	_WT("Explicitly requested prefetch."), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	11 
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("FAVICON"), 
		/*szEgName*/	_WT("FAVICON"), 
		/*szExplain*/	_WT("Favicon."), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	12 
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("XHR"), 
		/*szEgName*/	_WT("XHR"), 
		/*szExplain*/	_WT("XMLHttpRequest."), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	13 
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("PING"), 
		/*szEgName*/	_WT("PING"), 
		/*szExplain*/	_WT("A request for a <ping>"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	14 
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("SERVICE_WORKER"), 
		/*szEgName*/	_WT("SERVICE_WORKER"), 
		/*szExplain*/	_WT("Main resource of a service worker."), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	15 
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("CSP_REPORT"), 
		/*szEgName*/	_WT("CSP_REPORT"), 
		/*szExplain*/	_WT("A report of Content Security Policy violations."), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	16
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("PLUGIN_RESOURCE"), 
		/*szEgName*/	_WT("PLUGIN_RESOURCE"), 
		/*szExplain*/	_WT("A resource that a plugin requested."), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	17
	},
};
#define ENUM_RESOURCE_TYPE_EXPLAIN	"资源类型枚举常量。"


LIB_DATA_TYPE_ELEMENT s_JavaScriptDialogTypeEnumList[] = {
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("ALERT"), 
		/*szEgName*/	_WT("ALERT"), 
		/*szExplain*/	_WT("Alert"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	0 
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("CONFIRM"), 
		/*szEgName*/	_WT("CONFIRM"), 
		/*szExplain*/	_WT("CONFIRM"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("PROMPT"), 
		/*szEgName*/	_WT("PROMPT"), 
		/*szExplain*/	_WT("PROMPT"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	2
	}
};

#define ENUM_JAVASCRIPTDIALOG_TYPE_EXPLAIN	"脚本对话框类型枚举常量"


LIB_DATA_TYPE_ELEMENT s_ResourceRetValueEnumList[] = {
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("立即取消"), 
		/*szEgName*/	_WT("Cancel"), 
		/*szExplain*/	_WT("立即取消本次资源请求。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	0 
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("立即通过"), 
		/*szEgName*/	_WT("Continue"), 
		/*szExplain*/	_WT("立即通过本次资源请求。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1 
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("待决定"), 
		/*szEgName*/	_WT("Continue_async"), 
		/*szExplain*/	_WT("异步继续执行本次资源请求, 通过待决回调接口可以在后续再次设置请求状态。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	2 
	},
};
#define ENUM_RESOURCE_RETVALUE_TYPE_EXPLAIN	"资源请求枚举常量"


LIB_DATA_TYPE_ELEMENT s_ThreadIdEnumList[] = {
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("THREAD_UI"), 
		/*szEgName*/	_WT("THREAD_UI"), 
		/*szExplain*/	_WT("浏览器UI线程"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	0 
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("THREAD_PROCESS_LAUNCHER"), 
		/*szEgName*/	_WT("THREAD_PROCESS_LAUNCHER"), 
		/*szExplain*/	_WT("浏览器进程守护线程"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	4 
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("THREAD_IO"), 
		/*szEgName*/	_WT("THREAD_IO"), 
		/*szExplain*/	_WT("浏览器IO线程"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	5 
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("THREAD_RENDERER"), 
		/*szEgName*/	_WT("THREAD_RENDERER"), 
		/*szExplain*/	_WT("浏览器渲染线程"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	6
	},
};
#define ENUM_THREAD_TYPE_EXPLAIN	"浏览器线程枚举常量"


LIB_DATA_TYPE_ELEMENT s_FileModeEnumList[] = {
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("打开文件"), 
		/*szEgName*/	_WT("FILE_DIALOG_OPEN"), 
		/*szExplain*/	_WT("Requires that the file exists before allowing the user to pick it."), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	0 
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("打开文件_多项选择"), 
		/*szEgName*/	_WT("FILE_DIALOG_OPEN_MULTIPLE"), 
		/*szExplain*/	_WT("Like Open, but allows picking multiple files to open."), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1 
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("打开文件夹"), 
		/*szEgName*/	_WT("FILE_DIALOG_OPEN_FOLDER"), 
		/*szExplain*/	_WT("Like Open, but selects a folder to open."), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	2 
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("保存文件"), 
		/*szEgName*/	_WT("FILE_DIALOG_SAVE"), 
		/*szExplain*/	_WT("Allows picking a nonexistent file, and prompts to overwrite if the file already exists."), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	3
	}
};
#define ENUM_FILEMODE_TYPE_EXPLAIN	"浏览器文件对话框枚举常量"

LIB_DATA_TYPE_ELEMENT s_EventFlagsEnumList[] = {
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("NONE"), 
		/*szEgName*/	_WT("NONE"), 
		/*szExplain*/	_WT(""), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	0 
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("CAPS_LOCK_ON"), 
		/*szEgName*/	_WT("CAPS_LOCK_ON"), 
		/*szExplain*/	_WT(""), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1 << 0
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("SHIFT_DOWN"), 
		/*szEgName*/	_WT("SHIFT_DOWN"), 
		/*szExplain*/	_WT(""), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1 << 1
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("CONTROL_DOWN"), 
		/*szEgName*/	_WT("CONTROL_DOWN"), 
		/*szExplain*/	_WT(""), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1 << 2
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("ALT_DOWN"), 
		/*szEgName*/	_WT("ALT_DOWN"), 
		/*szExplain*/	_WT(""), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1 << 3
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("LEFT_MOUSE_BUTTON"), 
		/*szEgName*/	_WT("LEFT_MOUSE_BUTTON"), 
		/*szExplain*/	_WT(""), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1 << 4
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("MIDDLE_MOUSE_BUTTON"), 
		/*szEgName*/	_WT("MIDDLE_MOUSE_BUTTON"), 
		/*szExplain*/	_WT(""), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1 << 5
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("RIGHT_MOUSE_BUTTON"), 
		/*szEgName*/	_WT("RIGHT_MOUSE_BUTTON"), 
		/*szExplain*/	_WT(""), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1 << 6
	},
};
#define ENUM_EVENTFLAGS_EXPLAIN	"菜单事件标志枚举常量"

LIB_DATA_TYPE_ELEMENT s_CommandSwitchEnumList[] = {
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("默认"), 
		/*szEgName*/	_WT("STATE_DEFAULT"), 
		/*szExplain*/	_WT("Use the default state for the setting."), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	0 
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("启用"), 
		/*szEgName*/	_WT("STATE_ENABLED"), 
		/*szExplain*/	_WT("Enable or allow the setting."), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1 
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("禁止"), 
		/*szEgName*/	_WT("STATE_DISABLED"), 
		/*szExplain*/	_WT("Disable or disallow the setting."), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	2 
	},
};
#define ENUM_COMMANDSWITCH_EXPLAIN	"浏览器状态开关枚举常量"

LIB_DATA_TYPE_ELEMENT s_TransitionTypeEnumList[] = {
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("LINK"), 
		/*szEgName*/	_WT("LINK"), 
		/*szExplain*/	_WT("Source is a link click or the JavaScript window.open function. This is also the default value for requests like sub-resource loads that are not navigations."), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	0 
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("EXPLICIT"), 
		/*szEgName*/	_WT("EXPLICIT"), 
		/*szExplain*/	_WT("Source is some other \\\"explicit\\\" navigation. This is the default value for.navigations where the actual type is unknown. See also TT_DIRECT_LOAD_FLAG."), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("AUTO_SUBFRAME"), 
		/*szEgName*/	_WT("AUTO_SUBFRAME"), 
		/*szExplain*/	_WT("Source is a subframe navigation. This is any content that is automatically loaded in a non-toplevel frame. For example, if a page consists of several frames containing ads, those ad URLs will have this transition type.The user may not even realize the content in these pages is a separate frame, so may not care about the URL."), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	3
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("MANUAL_SUBFRAME"), 
		/*szEgName*/	_WT("MANUAL_SUBFRAME"), 
		/*szExplain*/	_WT("Source is a subframe navigation explicitly requested by the user that will generate new navigation entries in the back/forward list. These are probably more important than frames that were automatically loaded in the background because the user probably cares about the fact that this link was loaded."), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	4
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("FORM_SUBMIT"), 
		/*szEgName*/	_WT("FORM_SUBMIT"), 
		/*szExplain*/	_WT("Source is a form submission by the user. NOTE: In some situations submitting a form does not result in this transition type. This can happen if the form uses a script to submit the contents."), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	7
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("RELOAD"), 
		/*szEgName*/	_WT("RELOAD"), 
		/*szExplain*/	_WT("Source is a \"reload\" of the page via the Reload function or by re-visiting the same URL. NOTE: This is distinct from the concept of whether a particular load uses \"reload semantics\" (i.e. bypasses cached data)."), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	8
	},
};
#define ENUM_TRANSITION_TYPE_EXPLAIN	"指示浏览器导航来源的枚举常量"


LIB_DATA_TYPE_ELEMENT s_ValueTypeEnumList[] = {
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("INVALID"), 
		/*szEgName*/	_WT("INVALID"), 
		/*szExplain*/	_WT(""), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	0 
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("NULL"), 
		/*szEgName*/	_WT("NULL"), 
		/*szExplain*/	_WT(""), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1 
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("BOOL"), 
		/*szEgName*/	_WT("BOOL"), 
		/*szExplain*/	_WT(""), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	2
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("INT"), 
		/*szEgName*/	_WT("INT"), 
		/*szExplain*/	_WT(""), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	3
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("DOUBLE"), 
		/*szEgName*/	_WT("DOUBLE"), 
		/*szExplain*/	_WT(""), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	4
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("STRING"), 
		/*szEgName*/	_WT("STRING"), 
		/*szExplain*/	_WT(""), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	5 
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("BINARY"), 
		/*szEgName*/	_WT("BINARY"), 
		/*szExplain*/	_WT(""), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	6 
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("DICTIONARY"), 
		/*szEgName*/	_WT("DICTIONARY"), 
		/*szExplain*/	_WT(""), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	7 
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("LIST"), 
		/*szEgName*/	_WT("LIST"), 
		/*szExplain*/	_WT(""), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	8 
	},
};
#define ENUM_VALUE_TYPE_EXPLAIN	"浏览器值类型枚举常量"


LIB_DATA_TYPE_ELEMENT s_WindowOpenDispositionEnumList[] = {
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("UNKNOWN"), 
		/*szEgName*/	_WT("UNKNOWN"), 
		/*szExplain*/	_WT(""), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	0 
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("CURRENT_TAB"), 
		/*szEgName*/	_WT("CURRENT_TAB"), 
		/*szExplain*/	_WT(""), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1 
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("SINGLETON_TAB"), 
		/*szEgName*/	_WT("SINGLETON_TAB"), 
		/*szExplain*/	_WT(""), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	2 
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("NEW_FOREGROUND_TAB"), 
		/*szEgName*/	_WT("NEW_FOREGROUND_TAB"), 
		/*szExplain*/	_WT(""), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	3 
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("NEW_BACKGROUND_TAB"), 
		/*szEgName*/	_WT("NEW_BACKGROUND_TAB"), 
		/*szExplain*/	_WT(""), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	4 
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("NEW_POPUP"), 
		/*szEgName*/	_WT("NEW_POPUP"), 
		/*szExplain*/	_WT(""), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	5 
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("NEW_WINDOW"), 
		/*szEgName*/	_WT("NEW_WINDOW"), 
		/*szExplain*/	_WT(""), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	6
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("SAVE_TO_DISK"), 
		/*szEgName*/	_WT("SAVE_TO_DISK"), 
		/*szExplain*/	_WT(""), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	7 
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("OFF_THE_RECORD"), 
		/*szEgName*/	_WT("OFF_THE_RECORD"), 
		/*szExplain*/	_WT(""), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	8 
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("IGNORE_ACTION"), 
		/*szEgName*/	_WT("IGNORE_ACTION"), 
		/*szExplain*/	_WT(""), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	9 
	},
};
#define ENUM_WINDOW_OPEN_DISPOSITION_EXPLAIN 	"浏览器链接点击的打开方式。"

LIB_DATA_TYPE_ELEMENT s_MessageLevelEnumList[] = {
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("DEFAULT"), 
		/*szEgName*/	_WT("DEFAULT"), 
		/*szExplain*/	_WT("默认日志记录（当前为INFO日志记录）。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	0 
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("VERBOSE"), 
		/*szEgName*/	_WT("VERBOSE"), 
		/*szExplain*/	_WT("详细记录。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("DEBUG"), 
		/*szEgName*/	_WT("DEBUG"), 
		/*szExplain*/	_WT("Debug记录。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1 
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("INFO"), 
		/*szEgName*/	_WT("INFO"), 
		/*szExplain*/	_WT("信息记录。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	2 
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("WARNING"), 
		/*szEgName*/	_WT("WARNING"), 
		/*szExplain*/	_WT("警告记录。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	3 
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("ERROR"), 
		/*szEgName*/	_WT("ERROR"), 
		/*szExplain*/	_WT("错误记录。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	4
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("FATAL"), 
		/*szEgName*/	_WT("FATAL"), 
		/*szExplain*/	_WT("致命错误记录。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	5 
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("DISABLE"), 
		/*szEgName*/	_WT("DISABLE"), 
		/*szExplain*/	_WT("对所有消息禁用日志记录到文件，对于严重性小于FATAL的消息禁用stderr。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	99
	},
};

#define ENUM_MESSAGE_LEVEL_EXPLAIN 	"记录控制台消息严重性等级的枚举常量。"

LIB_DATA_TYPE_ELEMENT s_SystemMenuIdEnumList[] = {
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("BACK"), 
		/*szEgName*/	_WT("BACK"), 
		/*szExplain*/	_WT("导航相关。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	100
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("FORWARD"), 
		/*szEgName*/	_WT("FORWARD"), 
		/*szExplain*/	_WT("导航相关。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	101
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("RELOAD"), 
		/*szEgName*/	_WT("RELOAD"), 
		/*szExplain*/	_WT("导航相关。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	102
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("RELOAD_NOCACHE"), 
		/*szEgName*/	_WT("RELOAD_NOCACHE"), 
		/*szExplain*/	_WT("导航相关。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	103
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("STOPLOAD"), 
		/*szEgName*/	_WT("STOPLOAD"), 
		/*szExplain*/	_WT("导航相关。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	104
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("UNDO"), 
		/*szEgName*/	_WT("UNDO"), 
		/*szExplain*/	_WT("编辑相关。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	110
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("REDO"), 
		/*szEgName*/	_WT("REDO"), 
		/*szExplain*/	_WT("编辑相关。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	111
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("CUT"), 
		/*szEgName*/	_WT("CUT"), 
		/*szExplain*/	_WT("编辑相关。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	112
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("COPY"), 
		/*szEgName*/	_WT("COPY"), 
		/*szExplain*/	_WT("编辑相关。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	113
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("PASTE"), 
		/*szEgName*/	_WT("PASTE"), 
		/*szExplain*/	_WT("编辑相关。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	114
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("DELETE"), 
		/*szEgName*/	_WT("DELETE"), 
		/*szExplain*/	_WT("编辑相关。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	115
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("SELECT_ALL"), 
		/*szEgName*/	_WT("SELECT_ALL"), 
		/*szExplain*/	_WT("编辑相关。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	116
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("FIND"), 
		/*szEgName*/	_WT("FIND"), 
		/*szExplain*/	_WT("杂项。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	130
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("PRINT"), 
		/*szEgName*/	_WT("PRINT"), 
		/*szExplain*/	_WT("杂项。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	131
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("VIEW_SOURCE"), 
		/*szEgName*/	_WT("PRINT"), 
		/*szExplain*/	_WT("杂项。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	132
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("SPELLCHECK_SUGGESTION_0"), 
		/*szEgName*/	_WT("SPELLCHECK_SUGGESTION_0"), 
		/*szExplain*/	_WT("拼写检查单词更正建议。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	200
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("SPELLCHECK_SUGGESTION_1"), 
		/*szEgName*/	_WT("SPELLCHECK_SUGGESTION_1"), 
		/*szExplain*/	_WT("拼写检查单词更正建议。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	201
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("SPELLCHECK_SUGGESTION_2"), 
		/*szEgName*/	_WT("SPELLCHECK_SUGGESTION_2"), 
		/*szExplain*/	_WT("拼写检查单词更正建议。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	202
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("SPELLCHECK_SUGGESTION_3"), 
		/*szEgName*/	_WT("SPELLCHECK_SUGGESTION_3"), 
		/*szExplain*/	_WT("拼写检查单词更正建议。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	203
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("SPELLCHECK_SUGGESTION_4"), 
		/*szEgName*/	_WT("SPELLCHECK_SUGGESTION_4"), 
		/*szExplain*/	_WT("拼写检查单词更正建议。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	204
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("SPELLCHECK_SUGGESTION_LAST"), 
		/*szEgName*/	_WT("SPELLCHECK_SUGGESTION_LAST"), 
		/*szExplain*/	_WT("拼写检查单词更正建议。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	204
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("SPELLCHECK_SUGGESTION_SUGGESTIONS"), 
		/*szEgName*/	_WT("SPELLCHECK_SUGGESTION_SUGGESTIONS"), 
		/*szExplain*/	_WT("拼写检查单词更正建议。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	205
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("ADD_TO_DICTIONARY"), 
		/*szEgName*/	_WT("ADD_TO_DICTIONARY"), 
		/*szExplain*/	_WT("拼写检查单词更正建议。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	206
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("CUSTOM_FIRST"), 
		/*szEgName*/	_WT("CUSTOM_FIRST"), 
		/*szExplain*/	_WT("来自渲染器过程的自定义菜单项。 例如，插件占位符菜单项或Flash菜单项。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	220
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("CUSTOM_LAST"), 
		/*szEgName*/	_WT("CUSTOM_LAST"), 
		/*szExplain*/	_WT("来自渲染器过程的自定义菜单项。 例如，插件占位符菜单项或Flash菜单项。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	250
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("USER_FIRST"), 
		/*szEgName*/	_WT("USER_FIRST"), 
		/*szExplain*/	_WT("所有用户定义的菜单ID都应介于USER_FIRST和USER_LAST之间, 以避免与系统保留菜单ID产生冲突。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	26500
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("USER_FIRST"), 
		/*szEgName*/	_WT("USER_FIRST"), 
		/*szExplain*/	_WT("所有用户定义的菜单ID都应介于USER_FIRST和USER_LAST之间, 以避免与系统保留菜单ID产生冲突。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	28500
	},
};
#define ENUM_SYSTEM_MENU_ID_EXPLAIN		"浏览器内置菜单ID枚举常量。"

LIB_DATA_TYPE_ELEMENT s_V8PropertyAttriEnumList[] = {
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("NONE"), 
		/*szEgName*/	_WT("NONE"), 
		/*szExplain*/	_WT("目标属性可写可写、可枚举、可配置的。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	0
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("READONLY"), 
		/*szEgName*/	_WT("READONLY"), 
		/*szExplain*/	_WT("目标属性仅提供只读副本, 不可写入。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1<<0
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("DOTTENUM"), 
		/*szEgName*/	_WT("DOTTENUM"), 
		/*szExplain*/	_WT("目标属性可读可写, 但不能枚举。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1<<1
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("DONTDELETE"), 
		/*szEgName*/	_WT("DONTDELETE"), 
		/*szExplain*/	_WT("目标属性可读可写, 可枚举, 但不接受配置。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1<<2
	},
};

#define ENUM_V8_PROPERTY_ATTRI_EXPLAIN		"属性拦截器枚举常量。"

LIB_DATA_TYPE_ELEMENT s_KeyEventEnumList[] = {
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("RAWKEYDOWN"), 
		/*szEgName*/	_WT("RAWKEYDOWN"), 
		/*szExplain*/	_WT("按下按键。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	0
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("KEYDOWN"), 
		/*szEgName*/	_WT("KEYDOWN"), 
		/*szExplain*/	_WT("通知已按下键。根据键定义和语言环境, 该值不一定会与输入字符一一对应。字符应该使用 CHAR 类型进行输入。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("KEYUP"), 
		/*szEgName*/	_WT("KEYUP"), 
		/*szExplain*/	_WT("通知键已弹起。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	2
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("CHAR"), 
		/*szEgName*/	_WT("CHAR"), 
		/*szExplain*/	_WT("关于输入字符的通知。可以使用此类型进行字符文本输入。按键事件可能会产生0个到1个或者更多的字符事件, 具体取决于按键, 语言环境和操作系统。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	3
	},
};
#define ENUM_KEY_EVENT_EXPLAIN		"键盘事件类型枚举常量。"

LIB_DATA_TYPE_ELEMENT s_TouchEventTypeEnumList[] = {
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("TET_RELEASED"), 
		/*szEgName*/	_WT("TET_RELEASED"), 
		/*szExplain*/	_WT(""), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	0
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("TET_PRESSED"), 
		/*szEgName*/	_WT("TET_PRESSED"), 
		/*szExplain*/	_WT(""), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("TET_MOVED"), 
		/*szEgName*/	_WT("TET_MOVED"), 
		/*szExplain*/	_WT(""), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	2
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("TET_CANCELLED"), 
		/*szEgName*/	_WT("TET_CANCELLED"), 
		/*szExplain*/	_WT(""), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	3
	},
};
#define ENUM_TOUCH_EVENT_TYPE_EXPLAIN		"触点状态类型枚举常量"

LIB_DATA_TYPE_ELEMENT s_TouchPointerTypeEnumList[] = {
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("TYPE_TOUCH"), 
		/*szEgName*/	_WT("TYPE_TOUCH"), 
		/*szExplain*/	_WT("触摸板"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	0
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("TYPE_MOUSE"), 
		/*szEgName*/	_WT("TYPE_MOUSE"), 
		/*szExplain*/	_WT("鼠标"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("TYPE_PEN"), 
		/*szEgName*/	_WT("TYPE_PEN"), 
		/*szExplain*/	_WT("触笔"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	2
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("TYPE_ERASER"), 
		/*szEgName*/	_WT("TYPE_ERASER"), 
		/*szExplain*/	_WT(""), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	3
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("TYPE_UNKNOWN"), 
		/*szEgName*/	_WT("TYPE_UNKNOWN"), 
		/*szExplain*/	_WT(""), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	4
	},
};
#define ENUM_TOUCH_POINTER_TYPE_EXPLAIN		"触摸设备指针类型枚举常量"

LIB_DATA_TYPE_ELEMENT s_PostDataElementTypeEnumList[] = {
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("EMPTY"), 
		/*szEgName*/	_WT("EMPTY"), 
		/*szExplain*/	_WT("空"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	0
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("BYTES"), 
		/*szEgName*/	_WT("BYTES"), 
		/*szExplain*/	_WT("字节流"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("FILE"), 
		/*szEgName*/	_WT("FILE"), 
		/*szExplain*/	_WT("文件"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	2
	},
};
#define ENUM_POST_DATA_ELEMENT_TYPE_EXPLAIN		"提交数据元素类型"