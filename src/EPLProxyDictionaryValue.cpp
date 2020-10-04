#include "stdafx.h"
#include "EPLProxyDictionaryValue.h"
#include <proxy/ProxyBrowser.h>
#include <proxy/ProxyBrowserHost.h>
#include <proxy/ProxyFrame.h>
#include <proxy/ProxyRequest.h>
#include <proxy/ProxyResponse.h>
#include <proxy/proxyValue.h>
#include <proxy/proxyListValue.h>
#include <proxy/ProxyDictionaryValue.h>
#include <proxy/ProxyDictionaryValue.h>



//==========================================

extern "C"
void EDITIONF(ProxyDictionaryValue_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void EDITIONF(ProxyDictionaryValue_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData) { return; }
	shrewd_ptr<ProxyDictionaryValue> ptr = (ProxyDictionaryValue*)*pArgInf->m_ppCompoundData;
	if(ptr){ ptr->release(); *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyDictionaryValue_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf[1].m_pCompoundData || NULL == *pArgInf[1].m_ppCompoundData) { return; }
	shrewd_ptr<ProxyDictionaryValue> ptr = (ProxyDictionaryValue*)*pArgInf[1].m_ppCompoundData;
	if(ptr){ ptr->retain(); *pArgInf->m_ppCompoundData = ptr.get(); }
	else { *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyDictionaryValue_Create) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	shrewd_ptr<ProxyDictionaryValue> result = ProxyDictionaryValue::Create();
	if(*pArgInf->m_ppCompoundData){
		((refcounted*)*pArgInf->m_ppCompoundData)->release();
	 }
	if(result){
		result->retain();
		*pArgInf->m_ppCompoundData = result.get();
	}
}

extern "C"
void EDITIONF(ProxyDictionaryValue_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyDictionaryValue> self = (ProxyDictionaryValue*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsValid();
}

extern "C"
void EDITIONF(ProxyDictionaryValue_IsOwned) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyDictionaryValue> self = (ProxyDictionaryValue*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsOwned();
}

extern "C"
void EDITIONF(ProxyDictionaryValue_IsReadOnly) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyDictionaryValue> self = (ProxyDictionaryValue*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsReadOnly();
}

extern "C"
void EDITIONF(ProxyDictionaryValue_IsSame) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyDictionaryValue> self = (ProxyDictionaryValue*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyDictionaryValue> argThat = (ProxyDictionaryValue*)*pArgInf[1].m_ppCompoundData;
	pRetData->m_bool = self->IsSame(argThat);
}

extern "C"
void EDITIONF(ProxyDictionaryValue_IsEqual) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyDictionaryValue> self = (ProxyDictionaryValue*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyDictionaryValue> argThat = (ProxyDictionaryValue*)*pArgInf[1].m_ppCompoundData;
	pRetData->m_bool = self->IsEqual(argThat);
}

extern "C"
void EDITIONF(ProxyDictionaryValue_Copy) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		*((DWORD*)pRetData->m_pCompoundData) = NULL;
		return ;
	}
	shrewd_ptr<ProxyDictionaryValue> self = (ProxyDictionaryValue*)*pArgInf->m_ppCompoundData;
	bool argExclude_Empty_Children = pArgInf[1].m_bool;
	shrewd_ptr<ProxyDictionaryValue> result = self->Copy(argExclude_Empty_Children);
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
void EDITIONF(ProxyDictionaryValue_GetSize) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		*((DWORD*)pRetData->m_pCompoundData) = NULL;
		return ;
	}
	shrewd_ptr<ProxyDictionaryValue> self = (ProxyDictionaryValue*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetSize();
}

extern "C"
void EDITIONF(ProxyDictionaryValue_Clear) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyDictionaryValue> self = (ProxyDictionaryValue*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->Clear();
}

extern "C"
void EDITIONF(ProxyDictionaryValue_HasKey) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyDictionaryValue> self = (ProxyDictionaryValue*)*pArgInf->m_ppCompoundData;
	const char* argKey = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	pRetData->m_bool = self->HasKey(argKey);
}

extern "C"
void EDITIONF(ProxyDictionaryValue_GetKeys) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		*((DWORD*)pRetData->m_pCompoundData) = NULL;
		return ;
	}
	shrewd_ptr<ProxyDictionaryValue> self = (ProxyDictionaryValue*)*pArgInf->m_ppCompoundData;
	pRetData->m_pCompoundData = (void*)self->GetKeys();
}

extern "C"
void EDITIONF(ProxyDictionaryValue_Remove) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyDictionaryValue> self = (ProxyDictionaryValue*)*pArgInf->m_ppCompoundData;
	const char* argKey = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	pRetData->m_bool = self->Remove(argKey);
}

extern "C"
void EDITIONF(ProxyDictionaryValue_GetType) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyDictionaryValue> self = (ProxyDictionaryValue*)*pArgInf->m_ppCompoundData;
	const char* argKey = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	pRetData->m_int = self->GetType(argKey);
}

extern "C"
void EDITIONF(ProxyDictionaryValue_GetValue) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		*((DWORD*)pRetData->m_pCompoundData) = NULL;
		return ;
	}
	shrewd_ptr<ProxyDictionaryValue> self = (ProxyDictionaryValue*)*pArgInf->m_ppCompoundData;
	const char* argKey = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	shrewd_ptr<ProxyValue> result = self->GetValue(argKey);
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
void EDITIONF(ProxyDictionaryValue_GetBool) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyDictionaryValue> self = (ProxyDictionaryValue*)*pArgInf->m_ppCompoundData;
	const char* argKey = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	pRetData->m_bool = self->GetBool(argKey);
}

extern "C"
void EDITIONF(ProxyDictionaryValue_GetInt) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyDictionaryValue> self = (ProxyDictionaryValue*)*pArgInf->m_ppCompoundData;
	const char* argKey = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	pRetData->m_int = self->GetInt(argKey);
}

extern "C"
void EDITIONF(ProxyDictionaryValue_GetDouble) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_double = 0.0f;
		return ;
	}
	shrewd_ptr<ProxyDictionaryValue> self = (ProxyDictionaryValue*)*pArgInf->m_ppCompoundData;
	const char* argKey = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	pRetData->m_double = self->GetDouble(argKey);
}

extern "C"
void EDITIONF(ProxyDictionaryValue_GetString) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_pText = NULL;
		return ;
	}
	shrewd_ptr<ProxyDictionaryValue> self = (ProxyDictionaryValue*)*pArgInf->m_ppCompoundData;
	const char* argKey = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	pRetData->m_pText = self->GetString(argKey);
}

extern "C"
void EDITIONF(ProxyDictionaryValue_GetBinary) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		*((DWORD*)pRetData->m_pCompoundData) = NULL;
		return ;
	}
	shrewd_ptr<ProxyDictionaryValue> self = (ProxyDictionaryValue*)*pArgInf->m_ppCompoundData;
	const char* argKey = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	pRetData->m_pBin = self->GetBinary(argKey);
}

extern "C"
void EDITIONF(ProxyDictionaryValue_GetDictionary) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		*((DWORD*)pRetData->m_pCompoundData) = NULL;
		return ;
	}
	shrewd_ptr<ProxyDictionaryValue> self = (ProxyDictionaryValue*)*pArgInf->m_ppCompoundData;
	const char* argKey = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	shrewd_ptr<ProxyDictionaryValue> result = self->GetDictionary(argKey);
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
void EDITIONF(ProxyDictionaryValue_GetList) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		*((DWORD*)pRetData->m_pCompoundData) = NULL;
		return ;
	}
	shrewd_ptr<ProxyDictionaryValue> self = (ProxyDictionaryValue*)*pArgInf->m_ppCompoundData;
	const char* argKey = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	shrewd_ptr<ProxyListValue> result = self->GetList(argKey);
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
void EDITIONF(ProxyDictionaryValue_SetValue) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyDictionaryValue> self = (ProxyDictionaryValue*)*pArgInf->m_ppCompoundData;
	const char* argKey = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	shrewd_ptr<ProxyValue> argValue = (ProxyValue*)*pArgInf[2].m_ppCompoundData;
	pRetData->m_bool = self->SetValue(argKey,argValue);
}

extern "C"
void EDITIONF(ProxyDictionaryValue_SetNull) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyDictionaryValue> self = (ProxyDictionaryValue*)*pArgInf->m_ppCompoundData;
	const char* argKey = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	pRetData->m_bool = self->SetNull(argKey);
}

extern "C"
void EDITIONF(ProxyDictionaryValue_SetBool) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyDictionaryValue> self = (ProxyDictionaryValue*)*pArgInf->m_ppCompoundData;
	const char* argKey = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	bool argValue = pArgInf[2].m_bool;
	pRetData->m_bool = self->SetBool(argKey,argValue);
}

extern "C"
void EDITIONF(ProxyDictionaryValue_SetInt) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyDictionaryValue> self = (ProxyDictionaryValue*)*pArgInf->m_ppCompoundData;
	const char* argKey = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	int argValue = pArgInf[2].m_int;
	pRetData->m_bool = self->SetInt(argKey,argValue);
}

extern "C"
void EDITIONF(ProxyDictionaryValue_SetDouble) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyDictionaryValue> self = (ProxyDictionaryValue*)*pArgInf->m_ppCompoundData;
	const char* argKey = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	double argValue = pArgInf[2].m_double;
	pRetData->m_bool = self->SetDouble(argKey,argValue);
}

extern "C"
void EDITIONF(ProxyDictionaryValue_SetString) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyDictionaryValue> self = (ProxyDictionaryValue*)*pArgInf->m_ppCompoundData;
	const char* argKey = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	const char* argValue = (NULL==pArgInf[2].m_pText || strlen(pArgInf[2].m_pText) <= 0) ? NULL : pArgInf[2].m_pText;
	pRetData->m_bool = self->SetString(argKey,argValue);
}

extern "C"
void EDITIONF(ProxyDictionaryValue_SetBinary) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyDictionaryValue> self = (ProxyDictionaryValue*)*pArgInf->m_ppCompoundData;
	const char* argKey = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	unsigned char* argValue = pArgInf[2].m_pBin;
	int argLength = pArgInf[3].m_int;
	pRetData->m_bool = self->SetBinary(argKey,argValue,argLength);
}

extern "C"
void EDITIONF(ProxyDictionaryValue_SetDictionary) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyDictionaryValue> self = (ProxyDictionaryValue*)*pArgInf->m_ppCompoundData;
	const char* argKey = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	shrewd_ptr<ProxyDictionaryValue> argValue = (ProxyDictionaryValue*)*pArgInf[2].m_ppCompoundData;
	pRetData->m_bool = self->SetDictionary(argKey,argValue);
}

extern "C"
void EDITIONF(ProxyDictionaryValue_SetList) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyDictionaryValue> self = (ProxyDictionaryValue*)*pArgInf->m_ppCompoundData;
	const char* argKey = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	shrewd_ptr<ProxyListValue> argValue = (ProxyListValue*)*pArgInf[2].m_ppCompoundData;
	pRetData->m_bool = self->SetList(argKey,argValue);
}



//==========================================

