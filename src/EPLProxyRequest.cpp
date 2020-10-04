#include "stdafx.h"
#include "EPLProxyRequest.h"
#include <proxy/ProxyBrowser.h>
#include <proxy/ProxyBrowserHost.h>
#include <proxy/ProxyFrame.h>
#include <proxy/ProxyRequest.h>
#include <proxy/ProxyResponse.h>
#include <proxy/proxyValue.h>
#include <proxy/proxyListValue.h>
#include <proxy/ProxyDictionaryValue.h>
#include <proxy/ProxyRequest.h>



//==========================================

extern "C"
void EDITIONF(ProxyRequest_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void EDITIONF(ProxyRequest_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData) { return; }
	shrewd_ptr<ProxyRequest> ptr = (ProxyRequest*)*pArgInf->m_ppCompoundData;
	if(ptr){ ptr->release(); *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyRequest_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf[1].m_pCompoundData || NULL == *pArgInf[1].m_ppCompoundData) { return; }
	shrewd_ptr<ProxyRequest> ptr = (ProxyRequest*)*pArgInf[1].m_ppCompoundData;
	if(ptr){ ptr->retain(); *pArgInf->m_ppCompoundData = ptr.get(); }
	else { *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyRequest_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyRequest> self = (ProxyRequest*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsValid();
}

extern "C"
void EDITIONF(ProxyRequest_Create) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	shrewd_ptr<ProxyRequest> result = ProxyRequest::Create();
	if(*pArgInf->m_ppCompoundData){
		((refcounted*)*pArgInf->m_ppCompoundData)->release();
	 }
	if(result){
		result->retain();
		*pArgInf->m_ppCompoundData = result.get();
	}
}

extern "C"
void EDITIONF(ProxyRequest_IsReadOnly) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyRequest> self = (ProxyRequest*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsReadOnly();
}

extern "C"
void EDITIONF(ProxyRequest_GetURL) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_pText = NULL;
		return ;
	}
	shrewd_ptr<ProxyRequest> self = (ProxyRequest*)*pArgInf->m_ppCompoundData;
	pRetData->m_pText = self->GetURL();
}

extern "C"
void EDITIONF(ProxyRequest_SetURL) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyRequest> self = (ProxyRequest*)*pArgInf->m_ppCompoundData;
	const char* argUrl = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	self->SetURL(argUrl);
}

extern "C"
void EDITIONF(ProxyRequest_GetMethod) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_pText = NULL;
		return ;
	}
	shrewd_ptr<ProxyRequest> self = (ProxyRequest*)*pArgInf->m_ppCompoundData;
	pRetData->m_pText = self->GetMethod();
}

extern "C"
void EDITIONF(ProxyRequest_SetMethod) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyRequest> self = (ProxyRequest*)*pArgInf->m_ppCompoundData;
	const char* argMethod = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	self->SetMethod(argMethod);
}

extern "C"
void EDITIONF(ProxyRequest_SetReferrer) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyRequest> self = (ProxyRequest*)*pArgInf->m_ppCompoundData;
	const char* argReferrer_Url = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	int argPolicy = pArgInf[2].m_int;
	self->SetReferrer(argReferrer_Url,argPolicy);
}

extern "C"
void EDITIONF(ProxyRequest_GetReferrerURL) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_pText = NULL;
		return ;
	}
	shrewd_ptr<ProxyRequest> self = (ProxyRequest*)*pArgInf->m_ppCompoundData;
	pRetData->m_pText = self->GetReferrerURL();
}

extern "C"
void EDITIONF(ProxyRequest_GetReferrerPolicy) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyRequest> self = (ProxyRequest*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetReferrerPolicy();
}

extern "C"
void EDITIONF(ProxyRequest_GetPostData) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		*((DWORD*)pRetData->m_pCompoundData) = NULL;
		return ;
	}
	shrewd_ptr<ProxyRequest> self = (ProxyRequest*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyPostData> result = self->GetPostData();
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
void EDITIONF(ProxyRequest_SetPostData) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyRequest> self = (ProxyRequest*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyPostData> argPostdata = (ProxyPostData*)*pArgInf[1].m_ppCompoundData;
	self->SetPostData(argPostdata);
}

extern "C"
void EDITIONF(ProxyRequest_GetHeaderMap) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		*((DWORD*)pRetData->m_pCompoundData) = NULL;
		return ;
	}
	shrewd_ptr<ProxyRequest> self = (ProxyRequest*)*pArgInf->m_ppCompoundData;
	pRetData->m_pCompoundData = (void*)self->GetHeaderMap();
}

extern "C"
void EDITIONF(ProxyRequest_SetHeaderMap) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyRequest> self = (ProxyRequest*)*pArgInf->m_ppCompoundData;
	const char* argHeadermap = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	self->SetHeaderMap(argHeadermap);
}

extern "C"
void EDITIONF(ProxyRequest_GetHeaderByName) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_pText = NULL;
		return ;
	}
	shrewd_ptr<ProxyRequest> self = (ProxyRequest*)*pArgInf->m_ppCompoundData;
	const char* argName = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	pRetData->m_pText = self->GetHeaderByName(argName);
}

extern "C"
void EDITIONF(ProxyRequest_SetHeaderByName) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyRequest> self = (ProxyRequest*)*pArgInf->m_ppCompoundData;
	const char* argName = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	const char* argValue = (NULL==pArgInf[2].m_pText || strlen(pArgInf[2].m_pText) <= 0) ? NULL : pArgInf[2].m_pText;
	bool argOverwrite = pArgInf[3].m_bool;
	self->SetHeaderByName(argName,argValue,argOverwrite);
}

extern "C"
void EDITIONF(ProxyRequest_Set) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyRequest> self = (ProxyRequest*)*pArgInf->m_ppCompoundData;
	const char* argUrl = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	const char* argMethod = (NULL==pArgInf[2].m_pText || strlen(pArgInf[2].m_pText) <= 0) ? NULL : pArgInf[2].m_pText;
	shrewd_ptr<ProxyPostData> argPostdata = (ProxyPostData*)*pArgInf[3].m_ppCompoundData;
	const char* argHeadermap = (NULL==pArgInf[4].m_pText || strlen(pArgInf[4].m_pText) <= 0) ? NULL : pArgInf[4].m_pText;
	self->Set(argUrl,argMethod,argPostdata,argHeadermap);
}

extern "C"
void EDITIONF(ProxyRequest_GetFlags) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyRequest> self = (ProxyRequest*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetFlags();
}

extern "C"
void EDITIONF(ProxyRequest_SetFlags) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyRequest> self = (ProxyRequest*)*pArgInf->m_ppCompoundData;
	int argFlags = pArgInf[1].m_int;
	self->SetFlags(argFlags);
}

extern "C"
void EDITIONF(ProxyRequest_GetFirstPartyForCookies) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_pText = NULL;
		return ;
	}
	shrewd_ptr<ProxyRequest> self = (ProxyRequest*)*pArgInf->m_ppCompoundData;
	pRetData->m_pText = self->GetFirstPartyForCookies();
}

extern "C"
void EDITIONF(ProxyRequest_SetFirstPartyForCookies) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyRequest> self = (ProxyRequest*)*pArgInf->m_ppCompoundData;
	const char* argUrl = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	self->SetFirstPartyForCookies(argUrl);
}

extern "C"
void EDITIONF(ProxyRequest_GetResourceType) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyRequest> self = (ProxyRequest*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetResourceType();
}

extern "C"
void EDITIONF(ProxyRequest_GetTransitionType) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyRequest> self = (ProxyRequest*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetTransitionType();
}

extern "C"
void EDITIONF(ProxyRequest_GetIdentifier) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int64 = 0;
		return ;
	}
	shrewd_ptr<ProxyRequest> self = (ProxyRequest*)*pArgInf->m_ppCompoundData;
	pRetData->m_int64 = self->GetIdentifier();
}



//==========================================

