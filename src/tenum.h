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
		/*nDefault*/	1 
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("立即通过"), 
		/*szEgName*/	_WT("Continue"), 
		/*szExplain*/	_WT("立即通过本次资源请求。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	0 
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
		/*szExplain*/	_WT("使用默认设置."), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	0 
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("启用"), 
		/*szEgName*/	_WT("STATE_ENABLED"), 
		/*szExplain*/	_WT("启用此选项."), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1 
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("禁止"), 
		/*szEgName*/	_WT("STATE_DISABLED"), 
		/*szExplain*/	_WT("禁用此选项"), 
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
		/*szName*/		_WT("RELEASED"), 
		/*szEgName*/	_WT("RELEASED"), 
		/*szExplain*/	_WT(""), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	0
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("PRESSED"), 
		/*szEgName*/	_WT("PRESSED"), 
		/*szExplain*/	_WT(""), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("MOVED"), 
		/*szEgName*/	_WT("MOVED"), 
		/*szExplain*/	_WT(""), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	2
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("CANCELLED"), 
		/*szEgName*/	_WT("CANCELLED"), 
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
		/*szName*/		_WT("TOUCH"), 
		/*szEgName*/	_WT("TOUCH"), 
		/*szExplain*/	_WT("触摸板"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	0
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("MOUSE"), 
		/*szEgName*/	_WT("MOUSE"), 
		/*szExplain*/	_WT("鼠标"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("PEN"), 
		/*szEgName*/	_WT("PEN"), 
		/*szExplain*/	_WT("触笔"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	2
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("ERASER"), 
		/*szEgName*/	_WT("ERASER"), 
		/*szExplain*/	_WT(""), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	3
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("UNKNOWN"), 
		/*szEgName*/	_WT("UNKNOWN"), 
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
		/*szExplain*/	_WT("字节集"), 
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

LIB_DATA_TYPE_ELEMENT s_UriUnescapeRuleEnumList[] = {
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("无"), 
		/*szEgName*/	_WT("NONE"), 
		/*szExplain*/	_WT("没有避免规则。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	0
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("普通转义"), 
		/*szEgName*/	_WT("NORMAL"), 
		/*szExplain*/	_WT("解码所有特殊字符的转义。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1 << 0
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("空格转义"), 
		/*szEgName*/	_WT("SPACES"), 
		/*szExplain*/	_WT("将%20转义为空格。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1 << 1
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("斜杠转义"), 
		/*szEgName*/	_WT("SPACES"), 
		/*szExplain*/	_WT("解码转义\"/\"和\"\\\\\"。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1 << 2
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("连接符转义"), 
		/*szEgName*/	_WT("REPLACE_PLUS_WITH_SPACE"), 
		/*szExplain*/	_WT("解码转义\"%\",\"+\",\"&\",\"#\"等连接字符。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1 << 3
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("加号转义"), 
		/*szEgName*/	_WT("REPLACE_PLUS_WITH_SPACE"), 
		/*szExplain*/	_WT("使用\"+\"表示空格。 "), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1 << 4
	},
};
#define ENUM_URI_UNESCAPE_RULE_EXPLAIN		"URI转义字符解码规则"

LIB_DATA_TYPE_ELEMENT s_UrlRequestStatusEnumList[] = {
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("UNKNOWN"), 
		/*szEgName*/	_WT("UNKNOWN"), 
		/*szExplain*/	_WT("状态未知。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	0
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("SUCCESS"), 
		/*szEgName*/	_WT("SUCCESS"), 
		/*szExplain*/	_WT("请求成功。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("IO_PENDING"), 
		/*szEgName*/	_WT("IO_PENDING"), 
		/*szExplain*/	_WT("IO处理仍在进行中。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	2
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("CANCELED"), 
		/*szEgName*/	_WT("CANCELED"), 
		/*szExplain*/	_WT("请求已被取消。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	3
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("FAILED"), 
		/*szEgName*/	_WT("FAILED"), 
		/*szExplain*/	_WT("请求失败。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	4
	},
};
#define ENUM_URL_REQUEST_STATUS_EXPLAIN		"URL请求会话状态"


LIB_DATA_TYPE_ELEMENT s_WebSocketDataTypeEnumList[] = {
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("字符串"), 
		/*szEgName*/	_WT("string"), 
		/*szExplain*/	_WT("字符串"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	0
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("字节集"), 
		/*szEgName*/	_WT("binary"), 
		/*szExplain*/	_WT("字节集"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1
	},
};
#define ENUM_WEB_SOCKET_DATA_TYPE_EXPLAIN		"超文本套接字数据流类型"

LIB_DATA_TYPE_ELEMENT s_MenuTypeEnumList[] = {
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("无"), 
		/*szEgName*/	_WT("None"), 
		/*szExplain*/	_WT("没有节点被选择"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	0
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("页"), 
		/*szEgName*/	_WT("Page"), 
		/*szExplain*/	_WT("选择了主页面。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1 << 0
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("子框架"), 
		/*szEgName*/	_WT("Frame"), 
		/*szExplain*/	_WT("选择了主框架"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1 << 1
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("链接"), 
		/*szEgName*/	_WT("Link"), 
		/*szExplain*/	_WT("选择了链接"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1 << 2
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("多媒体"), 
		/*szEgName*/	_WT("Media"), 
		/*szExplain*/	_WT("选择了多媒体"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1 << 3
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("选区"), 
		/*szEgName*/	_WT("Selection"), 
		/*szExplain*/	_WT("选择了一段选区"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1 << 4
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("可编辑组件"), 
		/*szEgName*/	_WT("Editable"), 
		/*szExplain*/	_WT("选择了可编辑组件"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1 << 5
	},
};
#define ENUM_MENU_TYPE_EXPLAIN		"超文本套接字数据流类型"


LIB_DATA_TYPE_ELEMENT s_MediaTypeEnumList[] = {
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("NONE"), 
		/*szEgName*/	_WT("NONE"), 
		/*szExplain*/	_WT("没有节点被选择"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	0
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("IMAGE"), 
		/*szEgName*/	_WT("IMAGE"), 
		/*szExplain*/	_WT("IMAGE节点被选择"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("VIDEO"), 
		/*szEgName*/	_WT("VIDEO"), 
		/*szExplain*/	_WT("VIDEO节点被选择"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	2
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("AUDIO"), 
		/*szEgName*/	_WT("AUDIO"), 
		/*szExplain*/	_WT("AUDIO节点被选择"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	3
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("FILE"), 
		/*szEgName*/	_WT("FILE"), 
		/*szExplain*/	_WT("FILE节点被选择"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	4
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("PLUGIN"), 
		/*szEgName*/	_WT("PLUGIN"), 
		/*szExplain*/	_WT("PLUGIN节点被选择"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	5
	},
};

#define ENUM_MEDIA_TYPE_EXPLAIN		"多媒体菜单类型"

LIB_DATA_TYPE_ELEMENT s_DocumentTypeEnumList[] = {
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("UNKNOWN"), 
		/*szEgName*/	_WT("UNKNOWN"), 
		/*szExplain*/	_WT("未知文档"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	0
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("HTML"), 
		/*szEgName*/	_WT("HTML"), 
		/*szExplain*/	_WT("HTML文档类型"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("XHTML"), 
		/*szEgName*/	_WT("XHTML"), 
		/*szExplain*/	_WT("XHTML文档类型"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	2
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("PLUGIN"), 
		/*szEgName*/	_WT("PLUGIN"), 
		/*szExplain*/	_WT("PLUGIN文档类型"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	3
	},
};

LIB_DATA_TYPE_ELEMENT s_DocumentElementTypeEnumList[] = {
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("UNSUPPORTED"), 
		/*szEgName*/	_WT("UNSUPPORTED"), 
		/*szExplain*/	_WT("未知元素"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	0
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("ELEMENT"), 
		/*szEgName*/	_WT("ELEMENT"), 
		/*szExplain*/	_WT("文档元素"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("ATTRIBUTE"), 
		/*szEgName*/	_WT("ATTRIBUTE"), 
		/*szExplain*/	_WT("属性元素"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	2
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("TEXT"), 
		/*szEgName*/	_WT("TEXT"), 
		/*szExplain*/	_WT("文本元素"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	3
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("CDATA_SECTION"), 
		/*szEgName*/	_WT("CDATA_SECTION"), 
		/*szExplain*/	_WT("CDATA_SECTION"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	4
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("PROCESSING_INSTRUCTIONS"), 
		/*szEgName*/	_WT("PROCESSING_INSTRUCTIONS"), 
		/*szExplain*/	_WT("PROCESSING_INSTRUCTIONS"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	5
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("COMMENT"), 
		/*szEgName*/	_WT("COMMENT"), 
		/*szExplain*/	_WT("COMMENT"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	6
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("DOCUMENT"), 
		/*szEgName*/	_WT("DOCUMENT"), 
		/*szExplain*/	_WT("DOCUMENT"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	7
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("DOCUMENT_TYPE"), 
		/*szEgName*/	_WT("DOCUMENT_TYPE"), 
		/*szExplain*/	_WT("DOCUMENT_TYPE"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	8
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("DOCUMENT_FRAGMENT"), 
		/*szEgName*/	_WT("DOCUMENT_FRAGMENT"), 
		/*szExplain*/	_WT("DOCUMENT_FRAGMENT"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	9
	},
};

LIB_DATA_TYPE_ELEMENT s_GestureSourceTypeEnumList[] = {
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("DEFAULT"), 
		/*szEgName*/	_WT("DEFAULT"), 
		/*szExplain*/	_WT("默认提供平台首选的输入类型。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	0
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("TOUCH"), 
		/*szEgName*/	_WT("TOUCH"), 
		/*szExplain*/	_WT("TOUCH。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("MOUSE"), 
		/*szEgName*/	_WT("MOUSE"), 
		/*szExplain*/	_WT("MOUSE"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	2
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("PEN"), 
		/*szEgName*/	_WT("PEN"), 
		/*szExplain*/	_WT("PEN"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	3
	},
};

LIB_DATA_TYPE_ELEMENT s_GestureProviderConfigTypeEnumList[] = {
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("当前平台"), 
		/*szEgName*/	_WT("CURRENT_PLATFORM"), 
		/*szExplain*/	_WT("为当前平台量身定制的参数。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	0
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("当前平台VR"), 
		/*szEgName*/	_WT("CURRENT_PLATFORM"), 
		/*szExplain*/	_WT("为VR中的当前平台量身定制的参数。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("桌面"), 
		/*szEgName*/	_WT("DESKTOP"), 
		/*szExplain*/	_WT("台式电脑的典型参数。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	2
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("移动设备"), 
		/*szEgName*/	_WT("MOBILE"), 
		/*szExplain*/	_WT("移动设备(电话/平板电脑)的典型参数。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	3
	},
};

LIB_DATA_TYPE_ELEMENT s_DeviceScreenTypeEnumList[] = {
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("桌面端"), 
		/*szEgName*/	_WT("DESKTOP"), 
		/*szExplain*/	_WT("桌面屏幕类型"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	0
	},
		{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("移动端"), 
		/*szEgName*/	_WT("MOBILE"), 
		/*szExplain*/	_WT("桌面屏幕类型"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1
	}
};

LIB_DATA_TYPE_ELEMENT s_ScreenOrientationTypeEnumList[] = {
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("原始方向"), 
		/*szEgName*/	_WT("Undefined"), 
		/*szExplain*/	_WT("保持屏幕原始方向"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	0
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("纵向主要"), 
		/*szEgName*/	_WT("PortraitPrimary"), 
		/*szExplain*/	_WT("纵向方向为主要方向"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("纵向次要"), 
		/*szEgName*/	_WT("PortraitSecondary"), 
		/*szExplain*/	_WT("纵向方向为次要方向"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	2
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("横向主要"), 
		/*szEgName*/	_WT("LandscapePrimary"), 
		/*szExplain*/	_WT("横向方向为主要方向"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	3
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("横向次要"), 
		/*szEgName*/	_WT("LandscapeSecondary"), 
		/*szExplain*/	_WT("横向方向为次要方向"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	4
	},
};

LIB_DATA_TYPE_ELEMENT s_URLRequestFlagsEnumList[] = {
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("没有标志"), 
		/*szEgName*/	_WT("NONE"), 
		/*szExplain*/	_WT("使用默认标志参数。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	0
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("跳过缓存"), 
		/*szEgName*/	_WT("SKIP_CACHE"), 
		/*szExplain*/	_WT("如果设置, 则在处理请求时将跳过缓存。设置此值等效于指定: \\\"Cache-Control: no-cache\\\"请求标头。 此标志值与 仅从缓存 标志冲突,组合使用会导致请求失败。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1 << 0
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("仅从缓存"), 
		/*szEgName*/	_WT("ONLY_FROM_CACHE"), 
		/*szExplain*/	_WT("如果设置, 若在无法从缓存(或某些等效的本地存储)中提供请求, 则该请求将失败。 设置此标志值等效于指定\\\"Cache-Control: only-if-cached\\\"请求标头。 此标志值与 跳过缓存 标志冲突, 组合使用会导致请求失败。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1 << 1
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("不使用缓存"), 
		/*szEgName*/	_WT("DISABLE_CACHE"), 
		/*szExplain*/	_WT("如果设置, 将根本不使用缓存。设置此标志值等效于指定\\\"Cache-Control: no-store\\\"请求标头。 此标志值与 仅从缓存 标志冲突, 组合使用会导致请求失败。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1 << 2
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("允许存储证书"), 
		/*szEgName*/	_WT("ALLOW_STORED_CREDENTIALS"), 
		/*szExplain*/	_WT("如果设置了用户名, 密码和cookie, 则可能会随请求一起发送, 并且cookie可能会从响应中保存。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1 << 3
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("报告上传进度"), 
		/*szEgName*/	_WT("REPORT_UPLOAD_PROGRESS"), 
		/*szExplain*/	_WT("如果设置了则在请求具有正文(Body)时将生成上传进度事件。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1 << 4
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("不下载数据"), 
		/*szEgName*/	_WT("NO_DOWNLOAD_DATA"), 
		/*szExplain*/	_WT("如果设置则不会调用下载事件接收数据。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1 << 5
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("回复5XX"), 
		/*szEgName*/	_WT("REPLY_5XX"), 
		/*szExplain*/	_WT("如果响应设置为5XX, 重定向错误将传播给观察者, 而不是自动重试。当前, 这仅适用于源自浏览器进程的请求。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1 << 6
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("不要重定向"), 
		/*szEgName*/	_WT("STOP_NO_REDIRECT"), 
		/*szExplain*/	_WT("如果响应设置为3XX, 则应立即停止抓取, 而不是继续进行重定向。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1 << 7
	},
};

LIB_DATA_TYPE_ELEMENT s_RequestTransitionTypeEnumList[] = {
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("链接"), 
		/*szEgName*/	_WT("LINK"), 
		/*szExplain*/	_WT("请求源是单击链接或 Javascript window.open 函数。这也是非导航之类的请求(如子资源加载)的默认值。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	0
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("显示导航"), 
		/*szEgName*/	_WT("EXPLICIT"), 
		/*szExplain*/	_WT("请求源是其它一些\\\"explicit\\\"导航。 这是实际类型位置的导航的默认值。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	1
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("自动子框架"), 
		/*szEgName*/	_WT("AUTO_SUBFRAME"), 
		/*szExplain*/	_WT("请求源是子框架, 这是在非顶级框架中自动加载的所有内容。例如, 如果页面由包含广告的多个框架组成, 则这些广告URL将具有此过渡类型。用户深圳可能没有意识到这些页面中的内容是单独的框架, 因此可能不在乎URL。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	3
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("手动子框架"), 
		/*szEgName*/	_WT("MANUAL_SUBFRAME"), 
		/*szExplain*/	_WT("请求源是用户明确请求的子框架导航, 它将在后退/前进列表中生成新的导航条目。这些可能比在后台自动加载的框架更为重要, 因为用户可能管线此链接已加载的事实。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	4
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("表单提交"), 
		/*szEgName*/	_WT("FORM_SUBMIT"), 
		/*szExplain*/	_WT("请求源是用户提交的表单, 注意: 在某些情况下, 提交表单不会导致此传输类型。如果表单使用脚本提交内容, 则会发生这种情况。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	7
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("掩码_请求源"), 
		/*szEgName*/	_WT("SOURCE_MASK"), 
		/*szExplain*/	_WT("通用掩码, 定义用于指示请求源的标志位。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	0xFF
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("掩码_请求被阻止"), 
		/*szEgName*/	_WT("BLOCKED_FLAG"), 
		/*szExplain*/	_WT("尝试访问URL, 但被阻止。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	0x00800000
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("掩码_请求或后退"), 
		/*szEgName*/	_WT("FORWARD_BACK_FLAG"), 
		/*szExplain*/	_WT("使用前进或后退功能在浏览历史记录直接导航。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	0x01000000
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("掩码_直接加载"), 
		/*szEgName*/	_WT("DIRECT_LOAD_FLAG"), 
		/*szExplain*/	_WT("直接通过创建浏览器、加载URL、加载请求等方法的请求。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	0x02000000
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("掩码_导航链开始"), 
		/*szEgName*/	_WT("CHAIN_START_FLAG"), 
		/*szExplain*/	_WT("导航链的开始。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	0x10000000
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("掩码_导航链结束"), 
		/*szEgName*/	_WT("CHAIN_END_FLAG"), 
		/*szExplain*/	_WT("结束导航链。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	0x20000000
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("掩码_客户端重定向"), 
		/*szEgName*/	_WT("CLIENT_REDIRECT_FLAG"), 
		/*szExplain*/	_WT("由 javascript 或页面上的meta refresh标签引擎的重定向"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	0x40000000
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("掩码_服务器重定向"), 
		/*szEgName*/	_WT("SERVER_REDIRECT_FLAG"), 
		/*szExplain*/	_WT("通过HTTP标头从服务器发送来的重定向"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	0x80000000
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("掩码_测试是否重定向"), 
		/*szEgName*/	_WT("IS_REDIRECT_MASK"), 
		/*szExplain*/	_WT("用于测试传输是否涉及重定向。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	0xC0000000
	},
	{ 
		/*dtType*/ 		SDT_INT, 
		/*pArySpec*/	NULL, 
		/*szName*/		_WT("掩码_标志位"), 
		/*szEgName*/	_WT("QUALIFIER_MASK"), 
		/*szExplain*/	_WT("用于限定标志位的掩码。"), 
		/*dwState*/		LES_HAS_DEFAULT_VALUE, 
		/*nDefault*/	0xFFFFFF00
	},
};
