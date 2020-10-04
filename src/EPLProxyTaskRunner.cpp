#include "stdafx.h"
#include "EPLProxyTaskRunner.h"
#include <proxy/ProxyBrowser.h>
#include <proxy/ProxyBrowserHost.h>
#include <proxy/ProxyFrame.h>
#include <proxy/ProxyRequest.h>
#include <proxy/ProxyResponse.h>
#include <proxy/proxyValue.h>
#include <proxy/proxyListValue.h>
#include <proxy/ProxyDictionaryValue.h>
#include <proxy/ProxyTaskRunner.h>



//==========================================

extern "C"
void EDITIONF(ProxyTaskRunner_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void EDITIONF(ProxyTaskRunner_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData) { return; }
	shrewd_ptr<ProxyTaskRunner> ptr = (ProxyTaskRunner*)*pArgInf->m_ppCompoundData;
	if(ptr){ ptr->release(); *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyTaskRunner_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf[1].m_pCompoundData || NULL == *pArgInf[1].m_ppCompoundData) { return; }
	shrewd_ptr<ProxyTaskRunner> ptr = (ProxyTaskRunner*)*pArgInf[1].m_ppCompoundData;
	if(ptr){ ptr->retain(); *pArgInf->m_ppCompoundData = ptr.get(); }
	else { *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyTaskRunner_GetForThread) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	int argThreadid = pArgInf[1].m_int;
	shrewd_ptr<ProxyTaskRunner> result = ProxyTaskRunner::GetForThread(argThreadid);
	if(*pArgInf->m_ppCompoundData){
		((refcounted*)*pArgInf->m_ppCompoundData)->release();
	 }
	if(result){
		result->retain();
		*pArgInf->m_ppCompoundData = result.get();
	}
}

extern "C"
void EDITIONF(ProxyTaskRunner_PostTask) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyTaskRunner> self = (ProxyTaskRunner*)*pArgInf->m_ppCompoundData;
	int argTaskid = pArgInf[1].m_int;
	shrewd_ptr<ProxyValue> argParams = (ProxyValue*)*pArgInf[2].m_ppCompoundData;
	pRetData->m_bool = self->PostTask(argTaskid,argParams);
}

extern "C"
void EDITIONF(ProxyTaskRunner_PostDelayedTask) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyTaskRunner> self = (ProxyTaskRunner*)*pArgInf->m_ppCompoundData;
	int argTaskid = pArgInf[1].m_int;
	shrewd_ptr<ProxyValue> argParams = (ProxyValue*)*pArgInf[2].m_ppCompoundData;
	__int64 argDelay_Ms = pArgInf[3].m_int64;
	pRetData->m_bool = self->PostDelayedTask(argTaskid,argParams,argDelay_Ms);
}



//==========================================

