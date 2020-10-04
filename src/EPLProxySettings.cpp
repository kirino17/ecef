#include "stdafx.h"
#include "EPLProxySettings.h"
#include <proxy/ProxyBrowser.h>
#include <proxy/ProxyBrowserHost.h>
#include <proxy/ProxyFrame.h>
#include <proxy/ProxyRequest.h>
#include <proxy/ProxyResponse.h>
#include <proxy/proxyValue.h>
#include <proxy/proxyListValue.h>
#include <proxy/ProxyDictionaryValue.h>
#include <proxy/ProxySettings.h>



//==========================================

extern "C"
void EDITIONF(ProxySettings_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void EDITIONF(ProxySettings_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData) { return; }
	shrewd_ptr<ProxySettings> ptr = (ProxySettings*)*pArgInf->m_ppCompoundData;
	if(ptr){ ptr->release(); *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxySettings_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf[1].m_pCompoundData || NULL == *pArgInf[1].m_ppCompoundData) { return; }
	shrewd_ptr<ProxySettings> ptr = (ProxySettings*)*pArgInf[1].m_ppCompoundData;
	if(ptr){ ptr->retain(); *pArgInf->m_ppCompoundData = ptr.get(); }
	else { *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxySettings_Create) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	shrewd_ptr<ProxySettings> result = ProxySettings::Create();
	if(*pArgInf->m_ppCompoundData){
		((refcounted*)*pArgInf->m_ppCompoundData)->release();
	 }
	if(result){
		result->retain();
		*pArgInf->m_ppCompoundData = result.get();
	}
}

extern "C"
void EDITIONF(ProxySettings_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxySettings> self = (ProxySettings*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsValid();
}

extern "C"
void EDITIONF(ProxySettings_SetBrowserSubProcessPath) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxySettings> self = (ProxySettings*)*pArgInf->m_ppCompoundData;
	const char* argPath = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	self->SetBrowserSubProcessPath(argPath);
}

extern "C"
void EDITIONF(ProxySettings_SetMultiThreadedMessageLoop) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxySettings> self = (ProxySettings*)*pArgInf->m_ppCompoundData;
	int argValue = pArgInf[1].m_int;
	self->SetMultiThreadedMessageLoop(argValue);
}

extern "C"
void EDITIONF(ProxySettings_SetExternalMessagePump) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxySettings> self = (ProxySettings*)*pArgInf->m_ppCompoundData;
	int argValue = pArgInf[1].m_int;
	self->SetExternalMessagePump(argValue);
}

extern "C"
void EDITIONF(ProxySettings_SetWindowlessRenderingEnabled) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxySettings> self = (ProxySettings*)*pArgInf->m_ppCompoundData;
	int argValue = pArgInf[1].m_int;
	self->SetWindowlessRenderingEnabled(argValue);
}

extern "C"
void EDITIONF(ProxySettings_SetCommandLineArgsDisabled) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxySettings> self = (ProxySettings*)*pArgInf->m_ppCompoundData;
	int argValue = pArgInf[1].m_int;
	self->SetCommandLineArgsDisabled(argValue);
}

extern "C"
void EDITIONF(ProxySettings_SetCachePath) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxySettings> self = (ProxySettings*)*pArgInf->m_ppCompoundData;
	const char* argPath = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	self->SetCachePath(argPath);
}

extern "C"
void EDITIONF(ProxySettings_SetRootCachePath) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxySettings> self = (ProxySettings*)*pArgInf->m_ppCompoundData;
	const char* argPath = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	self->SetRootCachePath(argPath);
}

extern "C"
void EDITIONF(ProxySettings_SetUserDataPath) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxySettings> self = (ProxySettings*)*pArgInf->m_ppCompoundData;
	const char* argPath = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	self->SetUserDataPath(argPath);
}

extern "C"
void EDITIONF(ProxySettings_SetPersistSessionCookies) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxySettings> self = (ProxySettings*)*pArgInf->m_ppCompoundData;
	int argValue = pArgInf[1].m_int;
	self->SetPersistSessionCookies(argValue);
}

extern "C"
void EDITIONF(ProxySettings_SetPersistUserPreferences) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxySettings> self = (ProxySettings*)*pArgInf->m_ppCompoundData;
	int argValue = pArgInf[1].m_int;
	self->SetPersistUserPreferences(argValue);
}

extern "C"
void EDITIONF(ProxySettings_SetUserAgent) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxySettings> self = (ProxySettings*)*pArgInf->m_ppCompoundData;
	const char* argUser_Agent = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	self->SetUserAgent(argUser_Agent);
}

extern "C"
void EDITIONF(ProxySettings_SetProductVersion) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxySettings> self = (ProxySettings*)*pArgInf->m_ppCompoundData;
	const char* argProduct_Version = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	self->SetProductVersion(argProduct_Version);
}

extern "C"
void EDITIONF(ProxySettings_SetLocale) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxySettings> self = (ProxySettings*)*pArgInf->m_ppCompoundData;
	const char* argLocale = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	self->SetLocale(argLocale);
}

extern "C"
void EDITIONF(ProxySettings_SetJavascriptFlags) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxySettings> self = (ProxySettings*)*pArgInf->m_ppCompoundData;
	const char* argJavascript_Flags = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	self->SetJavascriptFlags(argJavascript_Flags);
}

extern "C"
void EDITIONF(ProxySettings_SetPackLoadingDisabled) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxySettings> self = (ProxySettings*)*pArgInf->m_ppCompoundData;
	int argValue = pArgInf[1].m_int;
	self->SetPackLoadingDisabled(argValue);
}

extern "C"
void EDITIONF(ProxySettings_SetRemoteDebuggingPort) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxySettings> self = (ProxySettings*)*pArgInf->m_ppCompoundData;
	int argValue = pArgInf[1].m_int;
	self->SetRemoteDebuggingPort(argValue);
}

extern "C"
void EDITIONF(ProxySettings_SetUncaughtExceptionStackSize) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxySettings> self = (ProxySettings*)*pArgInf->m_ppCompoundData;
	int argValue = pArgInf[1].m_int;
	self->SetUncaughtExceptionStackSize(argValue);
}

extern "C"
void EDITIONF(ProxySettings_SetIgnoreCertificateErrors) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxySettings> self = (ProxySettings*)*pArgInf->m_ppCompoundData;
	int argValue = pArgInf[1].m_int;
	self->SetIgnoreCertificateErrors(argValue);
}

extern "C"
void EDITIONF(ProxySettings_SetBackgroundColor) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxySettings> self = (ProxySettings*)*pArgInf->m_ppCompoundData;
	unsigned int argColor = pArgInf[1].m_uint;
	self->SetBackgroundColor(argColor);
}

extern "C"
void EDITIONF(ProxySettings_SetAcceptLanguageList) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxySettings> self = (ProxySettings*)*pArgInf->m_ppCompoundData;
	const char* argAccept_Language_List = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	self->SetAcceptLanguageList(argAccept_Language_List);
}

extern "C"
void EDITIONF(ProxySettings_SetApplicationClientIdForFileScanning) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxySettings> self = (ProxySettings*)*pArgInf->m_ppCompoundData;
	const char* argValue = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	self->SetApplicationClientIdForFileScanning(argValue);
}



//==========================================

