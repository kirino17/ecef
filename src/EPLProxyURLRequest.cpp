#include "stdafx.h"
#include "EPLProxyURLRequest.h"
#include <proxy/ProxyBrowser.h>
#include <proxy/ProxyFrame.h>
#include <proxy/ProxyRequest.h>
#include <proxy/ProxyResponse.h>
#include <proxy/proxyValue.h>
#include <proxy/proxyListValue.h>
#include <proxy/ProxyDictionaryValue.h>
#include <proxy/ProxyDOMNode.h>
#include <proxy/ProxyURLRequest.h>



//==========================================

extern "C"
void EDITIONF(ProxyURLRequest_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void EDITIONF(ProxyURLRequest_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData) { return; }
	shrewd_ptr<ProxyURLRequest> ptr = (ProxyURLRequest*)*pArgInf->m_ppCompoundData;
	if(ptr){ ptr->release(); *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyURLRequest_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf[1].m_pCompoundData || NULL == *pArgInf[1].m_ppCompoundData) { return; }
	shrewd_ptr<ProxyURLRequest> ptr = (ProxyURLRequest*)*pArgInf[1].m_ppCompoundData;
	if(ptr){ ptr->retain(); *pArgInf->m_ppCompoundData = ptr.get(); }
	else { *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyURLRequest_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyURLRequest> self = (ProxyURLRequest*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsValid();
}

extern "C"
void EDITIONF(ProxyURLRequest_GetRequest) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		
		return ;
	}
	shrewd_ptr<ProxyURLRequest> self = (ProxyURLRequest*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyRequest> result = self->GetRequest();
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
void EDITIONF(ProxyURLRequest_GetResponse) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		
		return ;
	}
	shrewd_ptr<ProxyURLRequest> self = (ProxyURLRequest*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyResponse> result = self->GetResponse();
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
void EDITIONF(ProxyURLRequest_GetRequestStatus) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyURLRequest> self = (ProxyURLRequest*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetRequestStatus();
}

extern "C"
void EDITIONF(ProxyURLRequest_GetRequestError) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyURLRequest> self = (ProxyURLRequest*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetRequestError();
}

extern "C"
void EDITIONF(ProxyURLRequest_ResponseWasCached) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyURLRequest> self = (ProxyURLRequest*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->ResponseWasCached();
}

extern "C"
void EDITIONF(ProxyURLRequest_GetResponseDataBytes) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		
		return ;
	}
	shrewd_ptr<ProxyURLRequest> self = (ProxyURLRequest*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetResponseDataBytes();
}

extern "C"
void EDITIONF(ProxyURLRequest_GetResponseData) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		
		return ;
	}
	shrewd_ptr<ProxyURLRequest> self = (ProxyURLRequest*)*pArgInf->m_ppCompoundData;
	pRetData->m_pBin = self->GetResponseData();
}

extern "C"
void EDITIONF(ProxyURLRequest_GetCookieManager) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		
		return ;
	}
	shrewd_ptr<ProxyURLRequest> self = (ProxyURLRequest*)*pArgInf->m_ppCompoundData;
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



//==========================================

