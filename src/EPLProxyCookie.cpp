#include "stdafx.h"
#include "EPLProxyCookie.h"
#include <proxy/ProxyBrowser.h>
#include <proxy/ProxyBrowserHost.h>
#include <proxy/ProxyFrame.h>
#include <proxy/ProxyRequest.h>
#include <proxy/ProxyResponse.h>
#include <proxy/proxyValue.h>
#include <proxy/proxyListValue.h>
#include <proxy/ProxyDictionaryValue.h>
#include <proxy/ProxyCookie.h>



//==========================================

extern "C"
void EDITIONF(ProxyCookie_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void EDITIONF(ProxyCookie_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData) { return; }
	shrewd_ptr<ProxyCookie> ptr = (ProxyCookie*)*pArgInf->m_ppCompoundData;
	if(ptr){ ptr->release(); *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyCookie_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf[1].m_pCompoundData || NULL == *pArgInf[1].m_ppCompoundData) { return; }
	shrewd_ptr<ProxyCookie> ptr = (ProxyCookie*)*pArgInf[1].m_ppCompoundData;
	if(ptr){ ptr->retain(); *pArgInf->m_ppCompoundData = ptr.get(); }
	else { *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyCookie_Create) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	shrewd_ptr<ProxyCookie> result = ProxyCookie::Create();
	if(*pArgInf->m_ppCompoundData){
		((refcounted*)*pArgInf->m_ppCompoundData)->release();
	 }
	if(result){
		result->retain();
		*pArgInf->m_ppCompoundData = result.get();
	}
}

extern "C"
void EDITIONF(ProxyCookie_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyCookie> self = (ProxyCookie*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsValid();
}

extern "C"
void EDITIONF(ProxyCookie_SetName) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyCookie> self = (ProxyCookie*)*pArgInf->m_ppCompoundData;
	const char* argName = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	self->SetName(argName);
}

extern "C"
void EDITIONF(ProxyCookie_GetName) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_pText = NULL;
		return ;
	}
	shrewd_ptr<ProxyCookie> self = (ProxyCookie*)*pArgInf->m_ppCompoundData;
	pRetData->m_pText = self->GetName();
}

extern "C"
void EDITIONF(ProxyCookie_SetValue) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyCookie> self = (ProxyCookie*)*pArgInf->m_ppCompoundData;
	const char* argValue = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	self->SetValue(argValue);
}

extern "C"
void EDITIONF(ProxyCookie_GetValue) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_pText = NULL;
		return ;
	}
	shrewd_ptr<ProxyCookie> self = (ProxyCookie*)*pArgInf->m_ppCompoundData;
	pRetData->m_pText = self->GetValue();
}

extern "C"
void EDITIONF(ProxyCookie_SetDomain) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyCookie> self = (ProxyCookie*)*pArgInf->m_ppCompoundData;
	const char* argDomain = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	self->SetDomain(argDomain);
}

extern "C"
void EDITIONF(ProxyCookie_GetDomain) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_pText = NULL;
		return ;
	}
	shrewd_ptr<ProxyCookie> self = (ProxyCookie*)*pArgInf->m_ppCompoundData;
	pRetData->m_pText = self->GetDomain();
}

extern "C"
void EDITIONF(ProxyCookie_SetPath) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyCookie> self = (ProxyCookie*)*pArgInf->m_ppCompoundData;
	const char* argPath = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	self->SetPath(argPath);
}

extern "C"
void EDITIONF(ProxyCookie_GetPath) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_pText = NULL;
		return ;
	}
	shrewd_ptr<ProxyCookie> self = (ProxyCookie*)*pArgInf->m_ppCompoundData;
	pRetData->m_pText = self->GetPath();
}

extern "C"
void EDITIONF(ProxyCookie_SetSecure) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyCookie> self = (ProxyCookie*)*pArgInf->m_ppCompoundData;
	int argSecure = pArgInf[1].m_int;
	self->SetSecure(argSecure);
}

extern "C"
void EDITIONF(ProxyCookie_GetSecure) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyCookie> self = (ProxyCookie*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetSecure();
}

extern "C"
void EDITIONF(ProxyCookie_SetHttponly) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyCookie> self = (ProxyCookie*)*pArgInf->m_ppCompoundData;
	int argHttponly = pArgInf[1].m_int;
	self->SetHttponly(argHttponly);
}

extern "C"
void EDITIONF(ProxyCookie_GetHttponly) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyCookie> self = (ProxyCookie*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetHttponly();
}

extern "C"
void EDITIONF(ProxyCookie_SetCreation) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyCookie> self = (ProxyCookie*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyTime> argCreation = (ProxyTime*)*pArgInf[1].m_ppCompoundData;
	self->SetCreation(argCreation);
}

extern "C"
void EDITIONF(ProxyCookie_GetCreation) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		*((DWORD*)pRetData->m_pCompoundData) = NULL;
		return ;
	}
	shrewd_ptr<ProxyCookie> self = (ProxyCookie*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyTime> result = self->GetCreation();
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
void EDITIONF(ProxyCookie_SetLastAccess) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyCookie> self = (ProxyCookie*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyTime> argLast_Access = (ProxyTime*)*pArgInf[1].m_ppCompoundData;
	self->SetLastAccess(argLast_Access);
}

extern "C"
void EDITIONF(ProxyCookie_GetLastAccess) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		*((DWORD*)pRetData->m_pCompoundData) = NULL;
		return ;
	}
	shrewd_ptr<ProxyCookie> self = (ProxyCookie*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyTime> result = self->GetLastAccess();
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
void EDITIONF(ProxyCookie_SetHasExpires) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyCookie> self = (ProxyCookie*)*pArgInf->m_ppCompoundData;
	int argHas_Expires = pArgInf[1].m_int;
	self->SetHasExpires(argHas_Expires);
}

extern "C"
void EDITIONF(ProxyCookie_GetHasExpires) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyCookie> self = (ProxyCookie*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetHasExpires();
}

extern "C"
void EDITIONF(ProxyCookie_SetExpires) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyCookie> self = (ProxyCookie*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyTime> argExpires = (ProxyTime*)*pArgInf[1].m_ppCompoundData;
	self->SetExpires(argExpires);
}

extern "C"
void EDITIONF(ProxyCookie_GetExpires) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		*((DWORD*)pRetData->m_pCompoundData) = NULL;
		return ;
	}
	shrewd_ptr<ProxyCookie> self = (ProxyCookie*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyTime> result = self->GetExpires();
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



//==========================================

