#include "stdafx.h"
#include "EPLProxyGetExtensionResourceCallback.h"
#include <proxy/ProxyBrowser.h>
#include <proxy/ProxyFrame.h>
#include <proxy/ProxyRequest.h>
#include <proxy/ProxyResponse.h>
#include <proxy/proxyValue.h>
#include <proxy/proxyListValue.h>
#include <proxy/ProxyDictionaryValue.h>
#include <proxy/ProxyDOMNode.h>
#include <proxy/ProxyGetExtensionResourceCallback.h>



//==========================================

extern "C"
void EDITIONF(ProxyGetExtensionResourceCallback_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void EDITIONF(ProxyGetExtensionResourceCallback_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData) { return; }
	shrewd_ptr<ProxyGetExtensionResourceCallback> ptr = (ProxyGetExtensionResourceCallback*)*pArgInf->m_ppCompoundData;
	if(ptr){ ptr->release(); *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyGetExtensionResourceCallback_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf[1].m_pCompoundData || NULL == *pArgInf[1].m_ppCompoundData) { return; }
	shrewd_ptr<ProxyGetExtensionResourceCallback> ptr = (ProxyGetExtensionResourceCallback*)*pArgInf[1].m_ppCompoundData;
	if(ptr){ ptr->retain(); *pArgInf->m_ppCompoundData = ptr.get(); }
	else { *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyGetExtensionResourceCallback_ContinueWithData) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyGetExtensionResourceCallback> self = (ProxyGetExtensionResourceCallback*)*pArgInf->m_ppCompoundData;
	unsigned char* argData = pArgInf[1].m_pBin;
	int argSize = pArgInf[2].m_int;
	self->ContinueWithData(argData,argSize);
}

extern "C"
void EDITIONF(ProxyGetExtensionResourceCallback_ContinueWithFile) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyGetExtensionResourceCallback> self = (ProxyGetExtensionResourceCallback*)*pArgInf->m_ppCompoundData;
	const char* argFile = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	self->ContinueWithFile(argFile);
}

extern "C"
void EDITIONF(ProxyGetExtensionResourceCallback_Cancel) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyGetExtensionResourceCallback> self = (ProxyGetExtensionResourceCallback*)*pArgInf->m_ppCompoundData;
	self->Cancel();
}



//==========================================

