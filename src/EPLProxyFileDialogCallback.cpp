#include "stdafx.h"
#include "EPLProxyFileDialogCallback.h"
#include <proxy/ProxyBrowser.h>
#include <proxy/ProxyBrowserHost.h>
#include <proxy/ProxyFrame.h>
#include <proxy/ProxyRequest.h>
#include <proxy/ProxyResponse.h>
#include <proxy/proxyValue.h>
#include <proxy/proxyListValue.h>
#include <proxy/ProxyDictionaryValue.h>
#include <proxy/ProxyFileDialogCallback.h>



//==========================================

extern "C"
void EDITIONF(ProxyFileDialogCallback_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void EDITIONF(ProxyFileDialogCallback_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData) { return; }
	shrewd_ptr<ProxyFileDialogCallback> ptr = (ProxyFileDialogCallback*)*pArgInf->m_ppCompoundData;
	if(ptr){ ptr->release(); *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyFileDialogCallback_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf[1].m_pCompoundData || NULL == *pArgInf[1].m_ppCompoundData) { return; }
	shrewd_ptr<ProxyFileDialogCallback> ptr = (ProxyFileDialogCallback*)*pArgInf[1].m_ppCompoundData;
	if(ptr){ ptr->retain(); *pArgInf->m_ppCompoundData = ptr.get(); }
	else { *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyFileDialogCallback_Continue) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyFileDialogCallback> self = (ProxyFileDialogCallback*)*pArgInf->m_ppCompoundData;
	int argSelected_Accept_Filter = pArgInf[1].m_int;
	const char* argFile_Paths = (NULL==pArgInf[2].m_pText || strlen(pArgInf[2].m_pText) <= 0) ? NULL : pArgInf[2].m_pText;
	self->Continue(argSelected_Accept_Filter,argFile_Paths);
}

extern "C"
void EDITIONF(ProxyFileDialogCallback_Cancel) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyFileDialogCallback> self = (ProxyFileDialogCallback*)*pArgInf->m_ppCompoundData;
	self->Cancel();
}



//==========================================

