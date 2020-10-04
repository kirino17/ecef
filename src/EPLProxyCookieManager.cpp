#include "stdafx.h"
#include "EPLProxyCookieManager.h"
#include <proxy/ProxyBrowser.h>
#include <proxy/ProxyBrowserHost.h>
#include <proxy/ProxyFrame.h>
#include <proxy/ProxyRequest.h>
#include <proxy/ProxyResponse.h>
#include <proxy/proxyValue.h>
#include <proxy/proxyListValue.h>
#include <proxy/ProxyDictionaryValue.h>
#include <proxy/ProxyCookieManager.h>



//==========================================

extern "C"
void EDITIONF(ProxyCookieManager_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void EDITIONF(ProxyCookieManager_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData) { return; }
	shrewd_ptr<ProxyCookieManager> ptr = (ProxyCookieManager*)*pArgInf->m_ppCompoundData;
	if(ptr){ ptr->release(); *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyCookieManager_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf[1].m_pCompoundData || NULL == *pArgInf[1].m_ppCompoundData) { return; }
	shrewd_ptr<ProxyCookieManager> ptr = (ProxyCookieManager*)*pArgInf[1].m_ppCompoundData;
	if(ptr){ ptr->retain(); *pArgInf->m_ppCompoundData = ptr.get(); }
	else { *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyCookieManager_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyCookieManager> self = (ProxyCookieManager*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsValid();
}

extern "C"
void EDITIONF(ProxyCookieManager_GetGlobalManager) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	shrewd_ptr<ProxyCookieManager> result = ProxyCookieManager::GetGlobalManager();
	if(*pArgInf->m_ppCompoundData){
		((refcounted*)*pArgInf->m_ppCompoundData)->release();
	 }
	if(result){
		result->retain();
		*pArgInf->m_ppCompoundData = result.get();
	}
}

extern "C"
void EDITIONF(ProxyCookieManager_SetSupportedSchemes) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyCookieManager> self = (ProxyCookieManager*)*pArgInf->m_ppCompoundData;
	const char* argSchemes = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	bool argInclude_Defaults = pArgInf[2].m_bool;
	self->SetSupportedSchemes(argSchemes,argInclude_Defaults);
}

extern "C"
void EDITIONF(ProxyCookieManager_VisitAllCookies) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyCookieManager> self = (ProxyCookieManager*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->VisitAllCookies();
}

extern "C"
void EDITIONF(ProxyCookieManager_VisitUrlCookies) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyCookieManager> self = (ProxyCookieManager*)*pArgInf->m_ppCompoundData;
	const char* argUrl = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	bool argIncludehttponly = pArgInf[2].m_bool;
	pRetData->m_bool = self->VisitUrlCookies(argUrl,argIncludehttponly);
}

extern "C"
void EDITIONF(ProxyCookieManager_SetCookie) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyCookieManager> self = (ProxyCookieManager*)*pArgInf->m_ppCompoundData;
	const char* argUrl = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	shrewd_ptr<ProxyCookie> argCookie = (ProxyCookie*)*pArgInf[2].m_ppCompoundData;
	pRetData->m_bool = self->SetCookie(argUrl,argCookie);
}

extern "C"
void EDITIONF(ProxyCookieManager_DeleteCookies) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyCookieManager> self = (ProxyCookieManager*)*pArgInf->m_ppCompoundData;
	const char* argUrl = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	const char* argCookie_Name = (NULL==pArgInf[2].m_pText || strlen(pArgInf[2].m_pText) <= 0) ? NULL : pArgInf[2].m_pText;
	pRetData->m_bool = self->DeleteCookies(argUrl,argCookie_Name);
}

extern "C"
void EDITIONF(ProxyCookieManager_FlushStore) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyCookieManager> self = (ProxyCookieManager*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->FlushStore();
}



//==========================================

