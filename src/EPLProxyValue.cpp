#include "stdafx.h"
#include "EPLProxyValue.h"
#include <proxy/ProxyBrowser.h>
#include <proxy/ProxyFrame.h>
#include <proxy/ProxyRequest.h>
#include <proxy/ProxyResponse.h>
#include <proxy/proxyValue.h>
#include <proxy/proxyListValue.h>
#include <proxy/ProxyDictionaryValue.h>
#include <proxy/ProxyDOMNode.h>
#include <proxy/ProxyValue.h>



//==========================================

extern "C"
void EDITIONF(ProxyValue_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void EDITIONF(ProxyValue_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData) { return; }
	shrewd_ptr<ProxyValue> ptr = (ProxyValue*)*pArgInf->m_ppCompoundData;
	if(ptr){ ptr->release(); *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyValue_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf[1].m_pCompoundData || NULL == *pArgInf[1].m_ppCompoundData) { return; }
	shrewd_ptr<ProxyValue> ptr = (ProxyValue*)*pArgInf[1].m_ppCompoundData;
	if(ptr){ ptr->retain(); *pArgInf->m_ppCompoundData = ptr.get(); }
	else { *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyValue_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyValue> self = (ProxyValue*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsValid();
}

extern "C"
void EDITIONF(ProxyValue_IsOwned) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyValue> self = (ProxyValue*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsOwned();
}

extern "C"
void EDITIONF(ProxyValue_IsReadOnly) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyValue> self = (ProxyValue*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsReadOnly();
}

extern "C"
void EDITIONF(ProxyValue_IsSame) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyValue> self = (ProxyValue*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyValue> argThat = (ProxyValue*)*pArgInf[1].m_ppCompoundData;
	pRetData->m_bool = self->IsSame(argThat);
}

extern "C"
void EDITIONF(ProxyValue_IsEqual) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyValue> self = (ProxyValue*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyValue> argThat = (ProxyValue*)*pArgInf[1].m_ppCompoundData;
	pRetData->m_bool = self->IsEqual(argThat);
}

extern "C"
void EDITIONF(ProxyValue_Copy) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		
		return ;
	}
	shrewd_ptr<ProxyValue> self = (ProxyValue*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyValue> result = self->Copy();
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
void EDITIONF(ProxyValue_GetType) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyValue> self = (ProxyValue*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetType();
}

extern "C"
void EDITIONF(ProxyValue_GetBool) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyValue> self = (ProxyValue*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->GetBool();
}

extern "C"
void EDITIONF(ProxyValue_GetInt) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyValue> self = (ProxyValue*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetInt();
}

extern "C"
void EDITIONF(ProxyValue_GetDouble) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_double = 0.0f;
		return ;
	}
	shrewd_ptr<ProxyValue> self = (ProxyValue*)*pArgInf->m_ppCompoundData;
	pRetData->m_double = self->GetDouble();
}

extern "C"
void EDITIONF(ProxyValue_GetString) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_pText = NULL;
		return ;
	}
	shrewd_ptr<ProxyValue> self = (ProxyValue*)*pArgInf->m_ppCompoundData;
	pRetData->m_pText = self->GetString();
}

extern "C"
void EDITIONF(ProxyValue_GetBinary) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		
		return ;
	}
	shrewd_ptr<ProxyValue> self = (ProxyValue*)*pArgInf->m_ppCompoundData;
	pRetData->m_pBin = self->GetBinary();
}

extern "C"
void EDITIONF(ProxyValue_GetDictionary) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		
		return ;
	}
	shrewd_ptr<ProxyValue> self = (ProxyValue*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyDictionaryValue> result = self->GetDictionary();
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
void EDITIONF(ProxyValue_GetList) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		
		return ;
	}
	shrewd_ptr<ProxyValue> self = (ProxyValue*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyListValue> result = self->GetList();
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
void EDITIONF(ProxyValue_SetNull) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyValue> self = (ProxyValue*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->SetNull();
}

extern "C"
void EDITIONF(ProxyValue_SetBool) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyValue> self = (ProxyValue*)*pArgInf->m_ppCompoundData;
	bool argValue = pArgInf[1].m_bool;
	pRetData->m_bool = self->SetBool(argValue);
}

extern "C"
void EDITIONF(ProxyValue_SetInt) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyValue> self = (ProxyValue*)*pArgInf->m_ppCompoundData;
	int argValue = pArgInf[1].m_int;
	pRetData->m_bool = self->SetInt(argValue);
}

extern "C"
void EDITIONF(ProxyValue_SetDouble) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyValue> self = (ProxyValue*)*pArgInf->m_ppCompoundData;
	double argValue = pArgInf[1].m_double;
	pRetData->m_bool = self->SetDouble(argValue);
}

extern "C"
void EDITIONF(ProxyValue_SetString) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyValue> self = (ProxyValue*)*pArgInf->m_ppCompoundData;
	const char* argValue = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	pRetData->m_bool = self->SetString(argValue);
}

extern "C"
void EDITIONF(ProxyValue_SetBinary) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyValue> self = (ProxyValue*)*pArgInf->m_ppCompoundData;
	unsigned char* argValue = pArgInf[1].m_pBin;
	int argLength = pArgInf[2].m_int;
	pRetData->m_bool = self->SetBinary(argValue,argLength);
}

extern "C"
void EDITIONF(ProxyValue_SetDictionary) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyValue> self = (ProxyValue*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyDictionaryValue> argValue = (ProxyDictionaryValue*)*pArgInf[1].m_ppCompoundData;
	pRetData->m_bool = self->SetDictionary(argValue);
}

extern "C"
void EDITIONF(ProxyValue_SetList) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyValue> self = (ProxyValue*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyListValue> argValue = (ProxyListValue*)*pArgInf[1].m_ppCompoundData;
	pRetData->m_bool = self->SetList(argValue);
}



//==========================================

