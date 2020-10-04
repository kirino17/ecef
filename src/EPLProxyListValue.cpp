#include "stdafx.h"
#include "EPLProxyListValue.h"
#include <proxy/ProxyBrowser.h>
#include <proxy/ProxyBrowserHost.h>
#include <proxy/ProxyFrame.h>
#include <proxy/ProxyRequest.h>
#include <proxy/ProxyResponse.h>
#include <proxy/proxyValue.h>
#include <proxy/proxyListValue.h>
#include <proxy/ProxyDictionaryValue.h>
#include <proxy/ProxyListValue.h>



//==========================================

extern "C"
void EDITIONF(ProxyListValue_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void EDITIONF(ProxyListValue_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData) { return; }
	shrewd_ptr<ProxyListValue> ptr = (ProxyListValue*)*pArgInf->m_ppCompoundData;
	if(ptr){ ptr->release(); *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyListValue_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf[1].m_pCompoundData || NULL == *pArgInf[1].m_ppCompoundData) { return; }
	shrewd_ptr<ProxyListValue> ptr = (ProxyListValue*)*pArgInf[1].m_ppCompoundData;
	if(ptr){ ptr->retain(); *pArgInf->m_ppCompoundData = ptr.get(); }
	else { *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyListValue_Create) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	shrewd_ptr<ProxyListValue> result = ProxyListValue::Create();
	if(*pArgInf->m_ppCompoundData){
		((refcounted*)*pArgInf->m_ppCompoundData)->release();
	 }
	if(result){
		result->retain();
		*pArgInf->m_ppCompoundData = result.get();
	}
}

extern "C"
void EDITIONF(ProxyListValue_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyListValue> self = (ProxyListValue*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsValid();
}

extern "C"
void EDITIONF(ProxyListValue_IsOwned) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyListValue> self = (ProxyListValue*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsOwned();
}

extern "C"
void EDITIONF(ProxyListValue_IsReadOnly) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyListValue> self = (ProxyListValue*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsReadOnly();
}

extern "C"
void EDITIONF(ProxyListValue_IsSame) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyListValue> self = (ProxyListValue*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyListValue> argThat = (ProxyListValue*)*pArgInf[1].m_ppCompoundData;
	pRetData->m_bool = self->IsSame(argThat);
}

extern "C"
void EDITIONF(ProxyListValue_IsEqual) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyListValue> self = (ProxyListValue*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyListValue> argThat = (ProxyListValue*)*pArgInf[1].m_ppCompoundData;
	pRetData->m_bool = self->IsEqual(argThat);
}

extern "C"
void EDITIONF(ProxyListValue_Copy) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		*((DWORD*)pRetData->m_pCompoundData) = NULL;
		return ;
	}
	shrewd_ptr<ProxyListValue> self = (ProxyListValue*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyListValue> result = self->Copy();
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
void EDITIONF(ProxyListValue_SetSize) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyListValue> self = (ProxyListValue*)*pArgInf->m_ppCompoundData;
	int argSize = pArgInf[1].m_int;
	pRetData->m_bool = self->SetSize(argSize);
}

extern "C"
void EDITIONF(ProxyListValue_GetSize) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		*((DWORD*)pRetData->m_pCompoundData) = NULL;
		return ;
	}
	shrewd_ptr<ProxyListValue> self = (ProxyListValue*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetSize();
}

extern "C"
void EDITIONF(ProxyListValue_Clear) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyListValue> self = (ProxyListValue*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->Clear();
}

extern "C"
void EDITIONF(ProxyListValue_Remove) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyListValue> self = (ProxyListValue*)*pArgInf->m_ppCompoundData;
	int argIndex = pArgInf[1].m_int;
	pRetData->m_bool = self->Remove(argIndex);
}

extern "C"
void EDITIONF(ProxyListValue_GetType) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyListValue> self = (ProxyListValue*)*pArgInf->m_ppCompoundData;
	int argIndex = pArgInf[1].m_int;
	pRetData->m_int = self->GetType(argIndex);
}

extern "C"
void EDITIONF(ProxyListValue_GetValue) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		*((DWORD*)pRetData->m_pCompoundData) = NULL;
		return ;
	}
	shrewd_ptr<ProxyListValue> self = (ProxyListValue*)*pArgInf->m_ppCompoundData;
	int argIndex = pArgInf[1].m_int;
	shrewd_ptr<ProxyValue> result = self->GetValue(argIndex);
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
void EDITIONF(ProxyListValue_GetBool) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyListValue> self = (ProxyListValue*)*pArgInf->m_ppCompoundData;
	int argIndex = pArgInf[1].m_int;
	pRetData->m_bool = self->GetBool(argIndex);
}

extern "C"
void EDITIONF(ProxyListValue_GetInt) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyListValue> self = (ProxyListValue*)*pArgInf->m_ppCompoundData;
	int argIndex = pArgInf[1].m_int;
	pRetData->m_int = self->GetInt(argIndex);
}

extern "C"
void EDITIONF(ProxyListValue_GetDouble) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_double = 0.0f;
		return ;
	}
	shrewd_ptr<ProxyListValue> self = (ProxyListValue*)*pArgInf->m_ppCompoundData;
	int argIndex = pArgInf[1].m_int;
	pRetData->m_double = self->GetDouble(argIndex);
}

extern "C"
void EDITIONF(ProxyListValue_GetString) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_pText = NULL;
		return ;
	}
	shrewd_ptr<ProxyListValue> self = (ProxyListValue*)*pArgInf->m_ppCompoundData;
	int argIndex = pArgInf[1].m_int;
	pRetData->m_pText = self->GetString(argIndex);
}

extern "C"
void EDITIONF(ProxyListValue_GetBinary) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		*((DWORD*)pRetData->m_pCompoundData) = NULL;
		return ;
	}
	shrewd_ptr<ProxyListValue> self = (ProxyListValue*)*pArgInf->m_ppCompoundData;
	int argIndex = pArgInf[1].m_int;
	pRetData->m_pBin = self->GetBinary(argIndex);
}

extern "C"
void EDITIONF(ProxyListValue_GetDictionary) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		*((DWORD*)pRetData->m_pCompoundData) = NULL;
		return ;
	}
	shrewd_ptr<ProxyListValue> self = (ProxyListValue*)*pArgInf->m_ppCompoundData;
	int argIndex = pArgInf[1].m_int;
	shrewd_ptr<ProxyDictionaryValue> result = self->GetDictionary(argIndex);
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
void EDITIONF(ProxyListValue_GetList) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		*((DWORD*)pRetData->m_pCompoundData) = NULL;
		return ;
	}
	shrewd_ptr<ProxyListValue> self = (ProxyListValue*)*pArgInf->m_ppCompoundData;
	int argIndex = pArgInf[1].m_int;
	shrewd_ptr<ProxyListValue> result = self->GetList(argIndex);
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
void EDITIONF(ProxyListValue_SetValue) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyListValue> self = (ProxyListValue*)*pArgInf->m_ppCompoundData;
	int argIndex = pArgInf[1].m_int;
	shrewd_ptr<ProxyValue> argValue = (ProxyValue*)*pArgInf[2].m_ppCompoundData;
	pRetData->m_bool = self->SetValue(argIndex,argValue);
}

extern "C"
void EDITIONF(ProxyListValue_SetNull) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyListValue> self = (ProxyListValue*)*pArgInf->m_ppCompoundData;
	int argIndex = pArgInf[1].m_int;
	pRetData->m_bool = self->SetNull(argIndex);
}

extern "C"
void EDITIONF(ProxyListValue_SetBool) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyListValue> self = (ProxyListValue*)*pArgInf->m_ppCompoundData;
	int argIndex = pArgInf[1].m_int;
	bool argValue = pArgInf[2].m_bool;
	pRetData->m_bool = self->SetBool(argIndex,argValue);
}

extern "C"
void EDITIONF(ProxyListValue_SetInt) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyListValue> self = (ProxyListValue*)*pArgInf->m_ppCompoundData;
	int argIndex = pArgInf[1].m_int;
	int argValue = pArgInf[2].m_int;
	pRetData->m_bool = self->SetInt(argIndex,argValue);
}

extern "C"
void EDITIONF(ProxyListValue_SetDouble) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyListValue> self = (ProxyListValue*)*pArgInf->m_ppCompoundData;
	int argIndex = pArgInf[1].m_int;
	double argValue = pArgInf[2].m_double;
	pRetData->m_bool = self->SetDouble(argIndex,argValue);
}

extern "C"
void EDITIONF(ProxyListValue_SetString) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyListValue> self = (ProxyListValue*)*pArgInf->m_ppCompoundData;
	int argIndex = pArgInf[1].m_int;
	const char* argValue = (NULL==pArgInf[2].m_pText || strlen(pArgInf[2].m_pText) <= 0) ? NULL : pArgInf[2].m_pText;
	pRetData->m_bool = self->SetString(argIndex,argValue);
}

extern "C"
void EDITIONF(ProxyListValue_SetBinary) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyListValue> self = (ProxyListValue*)*pArgInf->m_ppCompoundData;
	int argIndex = pArgInf[1].m_int;
	unsigned char* argValue = pArgInf[2].m_pBin;
	int argLength = pArgInf[3].m_int;
	pRetData->m_bool = self->SetBinary(argIndex,argValue,argLength);
}

extern "C"
void EDITIONF(ProxyListValue_SetDictionary) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyListValue> self = (ProxyListValue*)*pArgInf->m_ppCompoundData;
	int argIndex = pArgInf[1].m_int;
	shrewd_ptr<ProxyDictionaryValue> argValue = (ProxyDictionaryValue*)*pArgInf[2].m_ppCompoundData;
	pRetData->m_bool = self->SetDictionary(argIndex,argValue);
}

extern "C"
void EDITIONF(ProxyListValue_SetList) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyListValue> self = (ProxyListValue*)*pArgInf->m_ppCompoundData;
	int argIndex = pArgInf[1].m_int;
	shrewd_ptr<ProxyListValue> argValue = (ProxyListValue*)*pArgInf[2].m_ppCompoundData;
	pRetData->m_bool = self->SetList(argIndex,argValue);
}



//==========================================

