#include "stdafx.h"
#include "EPLProxyRequestContext.h"
#include <proxy/ProxyBrowser.h>
#include <proxy/ProxyBrowserHost.h>
#include <proxy/ProxyFrame.h>
#include <proxy/ProxyRequest.h>
#include <proxy/ProxyResponse.h>
#include <proxy/proxyValue.h>
#include <proxy/proxyListValue.h>
#include <proxy/ProxyDictionaryValue.h>
#include <proxy/ProxyRequestContext.h>



//==========================================

extern "C"
void EDITIONF(ProxyRequestContext_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void EDITIONF(ProxyRequestContext_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData) { return; }
	shrewd_ptr<ProxyRequestContext> ptr = (ProxyRequestContext*)*pArgInf->m_ppCompoundData;
	if(ptr){ ptr->release(); *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyRequestContext_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf[1].m_pCompoundData || NULL == *pArgInf[1].m_ppCompoundData) { return; }
	shrewd_ptr<ProxyRequestContext> ptr = (ProxyRequestContext*)*pArgInf[1].m_ppCompoundData;
	if(ptr){ ptr->retain(); *pArgInf->m_ppCompoundData = ptr.get(); }
	else { *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyRequestContext_GetGlobalContext) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	shrewd_ptr<ProxyRequestContext> result = ProxyRequestContext::GetGlobalContext();
	if(*pArgInf->m_ppCompoundData){
		((refcounted*)*pArgInf->m_ppCompoundData)->release();
	 }
	if(result){
		result->retain();
		*pArgInf->m_ppCompoundData = result.get();
	}
}

extern "C"
void EDITIONF(ProxyRequestContext_CreateContext) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	shrewd_ptr<ProxyRequestContextSettings> argSettings = (ProxyRequestContextSettings*)*pArgInf[1].m_ppCompoundData;
	shrewd_ptr<ProxyRequestContext> result = ProxyRequestContext::CreateContext(argSettings);
	if(*pArgInf->m_ppCompoundData){
		((refcounted*)*pArgInf->m_ppCompoundData)->release();
	 }
	if(result){
		result->retain();
		*pArgInf->m_ppCompoundData = result.get();
	}
}

extern "C"
void EDITIONF(ProxyRequestContext_CreateContextWith) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	shrewd_ptr<ProxyRequestContext> argOther = (ProxyRequestContext*)*pArgInf[1].m_ppCompoundData;
	shrewd_ptr<ProxyRequestContext> result = ProxyRequestContext::CreateContextWith(argOther);
	if(*pArgInf->m_ppCompoundData){
		((refcounted*)*pArgInf->m_ppCompoundData)->release();
	 }
	if(result){
		result->retain();
		*pArgInf->m_ppCompoundData = result.get();
	}
}

extern "C"
void EDITIONF(ProxyRequestContext_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyRequestContext> self = (ProxyRequestContext*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsValid();
}

extern "C"
void EDITIONF(ProxyRequestContext_IsSame) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyRequestContext> self = (ProxyRequestContext*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyRequestContext> argOther = (ProxyRequestContext*)*pArgInf[1].m_ppCompoundData;
	pRetData->m_bool = self->IsSame(argOther);
}

extern "C"
void EDITIONF(ProxyRequestContext_IsSharingWith) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyRequestContext> self = (ProxyRequestContext*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyRequestContext> argOther = (ProxyRequestContext*)*pArgInf[1].m_ppCompoundData;
	pRetData->m_bool = self->IsSharingWith(argOther);
}

extern "C"
void EDITIONF(ProxyRequestContext_IsGlobal) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyRequestContext> self = (ProxyRequestContext*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsGlobal();
}

extern "C"
void EDITIONF(ProxyRequestContext_GetCachePath) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_pText = NULL;
		return ;
	}
	shrewd_ptr<ProxyRequestContext> self = (ProxyRequestContext*)*pArgInf->m_ppCompoundData;
	pRetData->m_pText = self->GetCachePath();
}

extern "C"
void EDITIONF(ProxyRequestContext_GetCookieManager) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		*((DWORD*)pRetData->m_pCompoundData) = NULL;
		return ;
	}
	shrewd_ptr<ProxyRequestContext> self = (ProxyRequestContext*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyCookieManager> result = self->GetCookieManager();
	if(result){
	result->retain();
	DWORD* InternalPointer = (DWORD*)NotifySys(NRS_MALLOC,4,0);
	*InternalPointer = (DWORD)result.get();
	pRetData->m_pCompoundData = InternalPointer;
}
	else{
	pRetData->m_pCompoundData=NULL;
}
}

extern "C"
void EDITIONF(ProxyRequestContext_PurgePluginListCache) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyRequestContext> self = (ProxyRequestContext*)*pArgInf->m_ppCompoundData;
	bool argReload_Pages = pArgInf[1].m_bool;
	self->PurgePluginListCache(argReload_Pages);
}

extern "C"
void EDITIONF(ProxyRequestContext_ClearCertificateExceptions) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyRequestContext> self = (ProxyRequestContext*)*pArgInf->m_ppCompoundData;
	self->ClearCertificateExceptions();
}

extern "C"
void EDITIONF(ProxyRequestContext_ClearHttpAuthCredentials) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyRequestContext> self = (ProxyRequestContext*)*pArgInf->m_ppCompoundData;
	self->ClearHttpAuthCredentials();
}

extern "C"
void EDITIONF(ProxyRequestContext_CloseAllConnections) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyRequestContext> self = (ProxyRequestContext*)*pArgInf->m_ppCompoundData;
	self->CloseAllConnections();
}



//==========================================

