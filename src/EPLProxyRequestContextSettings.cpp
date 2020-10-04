#include "stdafx.h"
#include "EPLProxyRequestContextSettings.h"
#include <proxy/ProxyBrowser.h>
#include <proxy/ProxyBrowserHost.h>
#include <proxy/ProxyFrame.h>
#include <proxy/ProxyRequest.h>
#include <proxy/ProxyResponse.h>
#include <proxy/proxyValue.h>
#include <proxy/proxyListValue.h>
#include <proxy/ProxyDictionaryValue.h>
#include <proxy/ProxyRequestContextSettings.h>



//==========================================

extern "C"
void EDITIONF(ProxyRequestContextSettings_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void EDITIONF(ProxyRequestContextSettings_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData) { return; }
	shrewd_ptr<ProxyRequestContextSettings> ptr = (ProxyRequestContextSettings*)*pArgInf->m_ppCompoundData;
	if(ptr){ ptr->release(); *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyRequestContextSettings_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf[1].m_pCompoundData || NULL == *pArgInf[1].m_ppCompoundData) { return; }
	shrewd_ptr<ProxyRequestContextSettings> ptr = (ProxyRequestContextSettings*)*pArgInf[1].m_ppCompoundData;
	if(ptr){ ptr->retain(); *pArgInf->m_ppCompoundData = ptr.get(); }
	else { *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyRequestContextSettings_Create) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	shrewd_ptr<ProxyRequestContextSettings> result = ProxyRequestContextSettings::Create();
	if(*pArgInf->m_ppCompoundData){
		((refcounted*)*pArgInf->m_ppCompoundData)->release();
	 }
	if(result){
		result->retain();
		*pArgInf->m_ppCompoundData = result.get();
	}
}

extern "C"
void EDITIONF(ProxyRequestContextSettings_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyRequestContextSettings> self = (ProxyRequestContextSettings*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsValid();
}

extern "C"
void EDITIONF(ProxyRequestContextSettings_SetCachePath) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyRequestContextSettings> self = (ProxyRequestContextSettings*)*pArgInf->m_ppCompoundData;
	const char* argCache_Path = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	self->SetCachePath(argCache_Path);
}

extern "C"
void EDITIONF(ProxyRequestContextSettings_SetPersistSessionCookies) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyRequestContextSettings> self = (ProxyRequestContextSettings*)*pArgInf->m_ppCompoundData;
	int argPersist_Session_Cookies = pArgInf[1].m_int;
	self->SetPersistSessionCookies(argPersist_Session_Cookies);
}

extern "C"
void EDITIONF(ProxyRequestContextSettings_SetPersistUserPreferences) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyRequestContextSettings> self = (ProxyRequestContextSettings*)*pArgInf->m_ppCompoundData;
	int argPersist_User_Preferences = pArgInf[1].m_int;
	self->SetPersistUserPreferences(argPersist_User_Preferences);
}

extern "C"
void EDITIONF(ProxyRequestContextSettings_SetIgnoreCertificateErrors) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyRequestContextSettings> self = (ProxyRequestContextSettings*)*pArgInf->m_ppCompoundData;
	int argIgnore_Certificate_Errors = pArgInf[1].m_int;
	self->SetIgnoreCertificateErrors(argIgnore_Certificate_Errors);
}

extern "C"
void EDITIONF(ProxyRequestContextSettings_SetAcceptLanguageList) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyRequestContextSettings> self = (ProxyRequestContextSettings*)*pArgInf->m_ppCompoundData;
	const char* argAccept_Language_List = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	self->SetAcceptLanguageList(argAccept_Language_List);
}



//==========================================

