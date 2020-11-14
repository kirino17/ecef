#include "stdafx.h"
#include "EPLProxyServer.h"
#include <proxy/ProxyBrowser.h>
#include <proxy/ProxyFrame.h>
#include <proxy/ProxyRequest.h>
#include <proxy/ProxyResponse.h>
#include <proxy/proxyValue.h>
#include <proxy/proxyListValue.h>
#include <proxy/ProxyDictionaryValue.h>
#include <proxy/ProxyDOMNode.h>
#include <proxy/ProxyServer.h>



//==========================================

extern "C"
void EDITIONF(ProxyServer_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void EDITIONF(ProxyServer_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData) { return; }
	shrewd_ptr<ProxyServer> ptr = (ProxyServer*)*pArgInf->m_ppCompoundData;
	if(ptr){ ptr->release(); *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyServer_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf[1].m_pCompoundData || NULL == *pArgInf[1].m_ppCompoundData) { return; }
	shrewd_ptr<ProxyServer> ptr = (ProxyServer*)*pArgInf[1].m_ppCompoundData;
	if(ptr){ ptr->retain(); *pArgInf->m_ppCompoundData = ptr.get(); }
	else { *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyServer_Shutdown) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyServer> self = (ProxyServer*)*pArgInf->m_ppCompoundData;
	self->Shutdown();
}

extern "C"
void EDITIONF(ProxyServer_IsRunning) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyServer> self = (ProxyServer*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsRunning();
}

extern "C"
void EDITIONF(ProxyServer_GetAddress) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_pText = NULL;
		return ;
	}
	shrewd_ptr<ProxyServer> self = (ProxyServer*)*pArgInf->m_ppCompoundData;
	pRetData->m_pText = self->GetAddress();
}

extern "C"
void EDITIONF(ProxyServer_HasConnection) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyServer> self = (ProxyServer*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->HasConnection();
}

extern "C"
void EDITIONF(ProxyServer_IsValidConnection) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyServer> self = (ProxyServer*)*pArgInf->m_ppCompoundData;
	int argConnection_Id = pArgInf[1].m_int;
	pRetData->m_bool = self->IsValidConnection(argConnection_Id);
}

extern "C"
void EDITIONF(ProxyServer_SendHttp200Response) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyServer> self = (ProxyServer*)*pArgInf->m_ppCompoundData;
	int argConnection_Id = pArgInf[1].m_int;
	const char* argContent_Type = (NULL==pArgInf[2].m_pText || strlen(pArgInf[2].m_pText) <= 0) ? NULL : pArgInf[2].m_pText;
	const unsigned char* argData = NULL;
	const unsigned char* argDataTempBuf = pArgInf[3].m_pBin;
	if(NULL != argDataTempBuf) { argData = argDataTempBuf; }
	int argData_Size = pArgInf[4].m_int;
	self->SendHttp200Response(argConnection_Id,argContent_Type,argData,argData_Size);
}

extern "C"
void EDITIONF(ProxyServer_SendHttp404Response) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyServer> self = (ProxyServer*)*pArgInf->m_ppCompoundData;
	int argConnection_Id = pArgInf[1].m_int;
	self->SendHttp404Response(argConnection_Id);
}

extern "C"
void EDITIONF(ProxyServer_SendHttp500Response) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyServer> self = (ProxyServer*)*pArgInf->m_ppCompoundData;
	int argConnection_Id = pArgInf[1].m_int;
	const char* argError_Message = (NULL==pArgInf[2].m_pText || strlen(pArgInf[2].m_pText) <= 0) ? NULL : pArgInf[2].m_pText;
	self->SendHttp500Response(argConnection_Id,argError_Message);
}

extern "C"
void EDITIONF(ProxyServer_SendHttpResponse) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyServer> self = (ProxyServer*)*pArgInf->m_ppCompoundData;
	int argConnection_Id = pArgInf[1].m_int;
	int argResponse_Code = pArgInf[2].m_int;
	const char* argContent_Type = (NULL==pArgInf[3].m_pText || strlen(pArgInf[3].m_pText) <= 0) ? NULL : pArgInf[3].m_pText;
	__int64 argContent_Length = pArgInf[4].m_int64;
	const char* argExtra_Headers = (NULL==pArgInf[5].m_pText || strlen(pArgInf[5].m_pText) <= 0) ? NULL : pArgInf[5].m_pText;
	self->SendHttpResponse(argConnection_Id,argResponse_Code,argContent_Type,argContent_Length,argExtra_Headers);
}

extern "C"
void EDITIONF(ProxyServer_SendRawData) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyServer> self = (ProxyServer*)*pArgInf->m_ppCompoundData;
	int argConnection_Id = pArgInf[1].m_int;
	const unsigned char* argData = NULL;
	const unsigned char* argDataTempBuf = pArgInf[2].m_pBin;
	if(NULL != argDataTempBuf) { argData = argDataTempBuf; }
	int argData_Size = pArgInf[3].m_int;
	self->SendRawData(argConnection_Id,argData,argData_Size);
}

extern "C"
void EDITIONF(ProxyServer_CloseConnection) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyServer> self = (ProxyServer*)*pArgInf->m_ppCompoundData;
	int argConnection_Id = pArgInf[1].m_int;
	self->CloseConnection(argConnection_Id);
}

extern "C"
void EDITIONF(ProxyServer_SendWebSocketMessage) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyServer> self = (ProxyServer*)*pArgInf->m_ppCompoundData;
	int argConnection_Id = pArgInf[1].m_int;
	const unsigned char* argData = NULL;
	const unsigned char* argDataTempBuf = pArgInf[2].m_pBin;
	if(NULL != argDataTempBuf) { argData = argDataTempBuf; }
	int argData_Size = pArgInf[3].m_int;
	self->SendWebSocketMessage(argConnection_Id,argData,argData_Size);
}



//==========================================

