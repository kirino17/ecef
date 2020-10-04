#include "stdafx.h"
#include "EPLProxyBase.h"
#include <proxy/ProxyBrowser.h>
#include <proxy/ProxyBrowserHost.h>
#include <proxy/ProxyFrame.h>
#include <proxy/ProxyRequest.h>
#include <proxy/ProxyResponse.h>
#include <proxy/proxyValue.h>
#include <proxy/proxyListValue.h>
#include <proxy/ProxyDictionaryValue.h>
#include <proxy/ProxyBase.h>



//==========================================

extern "C"
void EDITIONF(ProxyBase_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void EDITIONF(ProxyBase_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData) { return; }
	shrewd_ptr<ProxyBase> ptr = (ProxyBase*)*pArgInf->m_ppCompoundData;
	if(ptr){ ptr->release(); *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyBase_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf[1].m_pCompoundData || NULL == *pArgInf[1].m_ppCompoundData) { return; }
	shrewd_ptr<ProxyBase> ptr = (ProxyBase*)*pArgInf[1].m_ppCompoundData;
	if(ptr){ ptr->retain(); *pArgInf->m_ppCompoundData = ptr.get(); }
	else { *pArgInf->m_ppCompoundData = NULL; }
}

#ifdef NOT_USED
extern "C"
void EDITIONF(ProxyBase_ExecuteProcess) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	unsigned int argClient = pArgInf[1].m_uint;
	pRetData->m_int = ProxyBase::ExecuteProcess(argClient);
}
#endif

#ifdef NOT_USED
extern "C"
void EDITIONF(ProxyBase_Initialize) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	shrewd_ptr<ProxySettings> argSettings = (ProxySettings*)*pArgInf[1].m_ppCompoundData;
	unsigned int argClient = pArgInf[2].m_uint;
	pRetData->m_bool = ProxyBase::Initialize(argSettings,argClient);
}
#endif

extern "C"
void EDITIONF(ProxyBase_Shutdown) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	ProxyBase::Shutdown();
}

extern "C"
void EDITIONF(ProxyBase_DoMessageLoopWork) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	ProxyBase::DoMessageLoopWork();
}

extern "C"
void EDITIONF(ProxyBase_RunMessageLoop) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	ProxyBase::RunMessageLoop();
}

extern "C"
void EDITIONF(ProxyBase_QuitMessageLoop) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	ProxyBase::QuitMessageLoop();
}

extern "C"
void EDITIONF(ProxyBase_SetOSModalLoop) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	bool argOsmodalloop = pArgInf[1].m_bool;
	ProxyBase::SetOSModalLoop(argOsmodalloop);
}

extern "C"
void EDITIONF(ProxyBase_EnableHighDPISupport) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	ProxyBase::EnableHighDPISupport();
}

extern "C"
void EDITIONF(ProxyBase_SetV8Interceptor) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	shrewd_ptr<ProxyListValue> argExtra_Info = (ProxyListValue*)*pArgInf[1].m_ppCompoundData;
	const char* argPath = (NULL==pArgInf[2].m_pText || strlen(pArgInf[2].m_pText) <= 0) ? NULL : pArgInf[2].m_pText;
	shrewd_ptr<ProxyValue> argRetval = (ProxyValue*)*pArgInf[3].m_ppCompoundData;
	int argAttribute = pArgInf[4].m_int;
	ProxyBase::SetV8Interceptor(argExtra_Info,argPath,argRetval,argAttribute);
}

extern "C"
void EDITIONF(ProxyBase_CreateV8Object) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	shrewd_ptr<ProxyListValue> argExtra_Info = (ProxyListValue*)*pArgInf[1].m_ppCompoundData;
	const char* argPath = (NULL==pArgInf[2].m_pText || strlen(pArgInf[2].m_pText) <= 0) ? NULL : pArgInf[2].m_pText;
	int argAttribute = pArgInf[3].m_int;
	ProxyBase::CreateV8Object(argExtra_Info,argPath,argAttribute);
}



//==========================================

