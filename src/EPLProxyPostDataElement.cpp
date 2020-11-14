#include "stdafx.h"
#include "EPLProxyPostDataElement.h"
#include <proxy/ProxyBrowser.h>
#include <proxy/ProxyFrame.h>
#include <proxy/ProxyRequest.h>
#include <proxy/ProxyResponse.h>
#include <proxy/proxyValue.h>
#include <proxy/proxyListValue.h>
#include <proxy/ProxyDictionaryValue.h>
#include <proxy/ProxyDOMNode.h>
#include <proxy/ProxyPostDataElement.h>



//==========================================

extern "C"
void EDITIONF(ProxyPostDataElement_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void EDITIONF(ProxyPostDataElement_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData) { return; }
	shrewd_ptr<ProxyPostDataElement> ptr = (ProxyPostDataElement*)*pArgInf->m_ppCompoundData;
	if(ptr){ ptr->release(); *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyPostDataElement_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf[1].m_pCompoundData || NULL == *pArgInf[1].m_ppCompoundData) { return; }
	shrewd_ptr<ProxyPostDataElement> ptr = (ProxyPostDataElement*)*pArgInf[1].m_ppCompoundData;
	if(ptr){ ptr->retain(); *pArgInf->m_ppCompoundData = ptr.get(); }
	else { *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyPostDataElement_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyPostDataElement> self = (ProxyPostDataElement*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsValid();
}

extern "C"
void EDITIONF(ProxyPostDataElement_IsReadOnly) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyPostDataElement> self = (ProxyPostDataElement*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsReadOnly();
}

extern "C"
void EDITIONF(ProxyPostDataElement_SetToEmpty) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyPostDataElement> self = (ProxyPostDataElement*)*pArgInf->m_ppCompoundData;
	self->SetToEmpty();
}

extern "C"
void EDITIONF(ProxyPostDataElement_SetToFile) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyPostDataElement> self = (ProxyPostDataElement*)*pArgInf->m_ppCompoundData;
	const char* argFilename = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	self->SetToFile(argFilename);
}

extern "C"
void EDITIONF(ProxyPostDataElement_SetToBytes) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyPostDataElement> self = (ProxyPostDataElement*)*pArgInf->m_ppCompoundData;
	int argSize = pArgInf[1].m_int;
	const unsigned char* argBytes = NULL;
	const unsigned char* argBytesTempBuf = pArgInf[2].m_pBin;
	if(NULL != argBytesTempBuf) { argBytes = argBytesTempBuf; }
	self->SetToBytes(argSize,argBytes);
}

extern "C"
void EDITIONF(ProxyPostDataElement_GetType) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyPostDataElement> self = (ProxyPostDataElement*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetType();
}

extern "C"
void EDITIONF(ProxyPostDataElement_GetFile) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_pText = NULL;
		return ;
	}
	shrewd_ptr<ProxyPostDataElement> self = (ProxyPostDataElement*)*pArgInf->m_ppCompoundData;
	pRetData->m_pText = self->GetFile();
}

extern "C"
void EDITIONF(ProxyPostDataElement_GetBytesCount) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		
		return ;
	}
	shrewd_ptr<ProxyPostDataElement> self = (ProxyPostDataElement*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetBytesCount();
}

extern "C"
void EDITIONF(ProxyPostDataElement_GetBytes) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		
		return ;
	}
	shrewd_ptr<ProxyPostDataElement> self = (ProxyPostDataElement*)*pArgInf->m_ppCompoundData;
	pRetData->m_pBin = self->GetBytes();
}



//==========================================

