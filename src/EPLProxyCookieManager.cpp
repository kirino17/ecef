#include "stdafx.h"
#include "EPLProxyCookieManager.h"
#include <proxy/ProxyBrowser.h>
#include <proxy/ProxyFrame.h>
#include <proxy/ProxyRequest.h>
#include <proxy/ProxyResponse.h>
#include <proxy/proxyValue.h>
#include <proxy/proxyListValue.h>
#include <proxy/ProxyDictionaryValue.h>
#include <proxy/ProxyDOMNode.h>
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
void EDITIONF(ProxyCookieManager_VisitAllCookies) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		DWORD* InternalPointer = (DWORD*)NotifySys(NRS_MALLOC, 8, 0);
		InternalPointer[0] = 1;
		InternalPointer[1] = 0;
		pRetData->m_pCompoundData = InternalPointer;
		return ;
	}
	shrewd_ptr<ProxyCookieManager> self = (ProxyCookieManager*)*pArgInf->m_ppCompoundData;
	pRetData->m_pCompoundData = (void*)self->VisitAllCookies();
}

extern "C"
void EDITIONF(ProxyCookieManager_VisitUrlCookies) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		DWORD* InternalPointer = (DWORD*)NotifySys(NRS_MALLOC, 8, 0);
		InternalPointer[0] = 1;
		InternalPointer[1] = 0;
		pRetData->m_pCompoundData = InternalPointer;
		return ;
	}
	shrewd_ptr<ProxyCookieManager> self = (ProxyCookieManager*)*pArgInf->m_ppCompoundData;
	const char* argUrl = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	bool argIncludehttponly = pArgInf[2].m_bool;
	pRetData->m_pCompoundData = (void*)self->VisitUrlCookies(argUrl,argIncludehttponly);
}

extern "C"
void EDITIONF(ProxyCookieManager_SetCookie) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyCookieManager> self = (ProxyCookieManager*)*pArgInf->m_ppCompoundData;
	const char* argUrl = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	const char* argDomain = (NULL==pArgInf[2].m_pText || strlen(pArgInf[2].m_pText) <= 0) ? NULL : pArgInf[2].m_pText;
	const char* argName = (NULL==pArgInf[3].m_pText || strlen(pArgInf[3].m_pText) <= 0) ? NULL : pArgInf[3].m_pText;
	const char* argValue = (NULL==pArgInf[4].m_pText || strlen(pArgInf[4].m_pText) <= 0) ? NULL : pArgInf[4].m_pText;
	pRetData->m_bool = self->SetCookie(argUrl,argDomain,argName,argValue);
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

extern "C"
void EDITIONF(ProxyCookieManager_ExtractToString) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_pText = NULL;
		return ;
	}
	shrewd_ptr<ProxyCookieManager> self = (ProxyCookieManager*)*pArgInf->m_ppCompoundData;
	pRetData->m_pText = self->ExtractToString();
}

extern "C"
void EDITIONF(ProxyCookieManager_ReduceFromString) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyCookieManager> self = (ProxyCookieManager*)*pArgInf->m_ppCompoundData;
	const char* argString = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	self->ReduceFromString(argString);
}

extern "C"
void EDITIONF(ProxyCookieManager_ExtractToHTTP) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_pText = NULL;
		return ;
	}
	shrewd_ptr<ProxyCookieManager> self = (ProxyCookieManager*)*pArgInf->m_ppCompoundData;
	const char* argUrl = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	pRetData->m_pText = self->ExtractToHTTP(argUrl);
}



//==========================================

