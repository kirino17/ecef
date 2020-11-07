#include "stdafx.h"
#include "EPLProxyDOMNode.h"
#include <proxy/ProxyBrowser.h>
#include <proxy/ProxyFrame.h>
#include <proxy/ProxyRequest.h>
#include <proxy/ProxyResponse.h>
#include <proxy/proxyValue.h>
#include <proxy/proxyListValue.h>
#include <proxy/ProxyDictionaryValue.h>
#include <proxy/ProxyDOMNode.h>
#include <proxy/ProxyDOMNode.h>



//==========================================

extern "C"
void EDITIONF(ProxyDOMNode_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void EDITIONF(ProxyDOMNode_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData) { return; }
	shrewd_ptr<ProxyDOMNode> ptr = (ProxyDOMNode*)*pArgInf->m_ppCompoundData;
	if(ptr){ ptr->release(); *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyDOMNode_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf[1].m_pCompoundData || NULL == *pArgInf[1].m_ppCompoundData) { return; }
	shrewd_ptr<ProxyDOMNode> ptr = (ProxyDOMNode*)*pArgInf[1].m_ppCompoundData;
	if(ptr){ ptr->retain(); *pArgInf->m_ppCompoundData = ptr.get(); }
	else { *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyDOMNode_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyDOMNode> self = (ProxyDOMNode*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsValid();
}

extern "C"
void EDITIONF(ProxyDOMNode_GetType) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyDOMNode> self = (ProxyDOMNode*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetType();
}

extern "C"
void EDITIONF(ProxyDOMNode_IsText) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyDOMNode> self = (ProxyDOMNode*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsText();
}

extern "C"
void EDITIONF(ProxyDOMNode_IsElement) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyDOMNode> self = (ProxyDOMNode*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsElement();
}

extern "C"
void EDITIONF(ProxyDOMNode_IsEditable) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyDOMNode> self = (ProxyDOMNode*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsEditable();
}

extern "C"
void EDITIONF(ProxyDOMNode_IsFormControlElement) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyDOMNode> self = (ProxyDOMNode*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsFormControlElement();
}

extern "C"
void EDITIONF(ProxyDOMNode_GetFormControlElementType) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_pText = NULL;
		return ;
	}
	shrewd_ptr<ProxyDOMNode> self = (ProxyDOMNode*)*pArgInf->m_ppCompoundData;
	pRetData->m_pText = self->GetFormControlElementType();
}

extern "C"
void EDITIONF(ProxyDOMNode_GetName) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_pText = NULL;
		return ;
	}
	shrewd_ptr<ProxyDOMNode> self = (ProxyDOMNode*)*pArgInf->m_ppCompoundData;
	pRetData->m_pText = self->GetName();
}

extern "C"
void EDITIONF(ProxyDOMNode_GetValue) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_pText = NULL;
		return ;
	}
	shrewd_ptr<ProxyDOMNode> self = (ProxyDOMNode*)*pArgInf->m_ppCompoundData;
	pRetData->m_pText = self->GetValue();
}

extern "C"
void EDITIONF(ProxyDOMNode_SetValue) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyDOMNode> self = (ProxyDOMNode*)*pArgInf->m_ppCompoundData;
	const char* argValue = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	pRetData->m_bool = self->SetValue(argValue);
}

extern "C"
void EDITIONF(ProxyDOMNode_GetAsMarkup) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_pText = NULL;
		return ;
	}
	shrewd_ptr<ProxyDOMNode> self = (ProxyDOMNode*)*pArgInf->m_ppCompoundData;
	pRetData->m_pText = self->GetAsMarkup();
}

extern "C"
void EDITIONF(ProxyDOMNode_GetDocument) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		
		return ;
	}
	shrewd_ptr<ProxyDOMNode> self = (ProxyDOMNode*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyDOMDocument> result = self->GetDocument();
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
void EDITIONF(ProxyDOMNode_GetParent) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		
		return ;
	}
	shrewd_ptr<ProxyDOMNode> self = (ProxyDOMNode*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyDOMNode> result = self->GetParent();
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
void EDITIONF(ProxyDOMNode_GetPreviousSibling) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		
		return ;
	}
	shrewd_ptr<ProxyDOMNode> self = (ProxyDOMNode*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyDOMNode> result = self->GetPreviousSibling();
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
void EDITIONF(ProxyDOMNode_GetNextSibling) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		
		return ;
	}
	shrewd_ptr<ProxyDOMNode> self = (ProxyDOMNode*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyDOMNode> result = self->GetNextSibling();
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
void EDITIONF(ProxyDOMNode_HasChildren) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyDOMNode> self = (ProxyDOMNode*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->HasChildren();
}

extern "C"
void EDITIONF(ProxyDOMNode_GetFirstChild) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		
		return ;
	}
	shrewd_ptr<ProxyDOMNode> self = (ProxyDOMNode*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyDOMNode> result = self->GetFirstChild();
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
void EDITIONF(ProxyDOMNode_GetLastChild) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		
		return ;
	}
	shrewd_ptr<ProxyDOMNode> self = (ProxyDOMNode*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyDOMNode> result = self->GetLastChild();
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
void EDITIONF(ProxyDOMNode_GetElementTagName) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_pText = NULL;
		return ;
	}
	shrewd_ptr<ProxyDOMNode> self = (ProxyDOMNode*)*pArgInf->m_ppCompoundData;
	pRetData->m_pText = self->GetElementTagName();
}

extern "C"
void EDITIONF(ProxyDOMNode_HasElementAttributes) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyDOMNode> self = (ProxyDOMNode*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->HasElementAttributes();
}

extern "C"
void EDITIONF(ProxyDOMNode_HasElementAttribute) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyDOMNode> self = (ProxyDOMNode*)*pArgInf->m_ppCompoundData;
	const char* argAttrname = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	pRetData->m_bool = self->HasElementAttribute(argAttrname);
}

extern "C"
void EDITIONF(ProxyDOMNode_GetElementAttribute) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_pText = NULL;
		return ;
	}
	shrewd_ptr<ProxyDOMNode> self = (ProxyDOMNode*)*pArgInf->m_ppCompoundData;
	const char* argAttrname = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	pRetData->m_pText = self->GetElementAttribute(argAttrname);
}

extern "C"
void EDITIONF(ProxyDOMNode_GetElementAttributes) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		
		return ;
	}
	shrewd_ptr<ProxyDOMNode> self = (ProxyDOMNode*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyDictionaryValue> result = self->GetElementAttributes();
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
void EDITIONF(ProxyDOMNode_SetElementAttribute) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyDOMNode> self = (ProxyDOMNode*)*pArgInf->m_ppCompoundData;
	const char* argAttrname = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	const char* argValue = (NULL==pArgInf[2].m_pText || strlen(pArgInf[2].m_pText) <= 0) ? NULL : pArgInf[2].m_pText;
	pRetData->m_bool = self->SetElementAttribute(argAttrname,argValue);
}

extern "C"
void EDITIONF(ProxyDOMNode_GetElementInnerText) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_pText = NULL;
		return ;
	}
	shrewd_ptr<ProxyDOMNode> self = (ProxyDOMNode*)*pArgInf->m_ppCompoundData;
	pRetData->m_pText = self->GetElementInnerText();
}

extern "C"
void EDITIONF(ProxyDOMNode_GetElementBounds) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		DWORD* InternalPointer = (DWORD*)NotifySys(NRS_MALLOC, 8, 0);
		InternalPointer[0] = 1;
		InternalPointer[1] = 0;
		pRetData->m_pCompoundData = InternalPointer;
		return ;
	}
	shrewd_ptr<ProxyDOMNode> self = (ProxyDOMNode*)*pArgInf->m_ppCompoundData;
	pRetData->m_pCompoundData = (void*)self->GetElementBounds();
}

#ifdef NOT_USED
extern "C"
void EDITIONF(ProxyDOMNode_SendEvent) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyDOMNode> self = (ProxyDOMNode*)*pArgInf->m_ppCompoundData;
	const char* argEvt_Name = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	void* argArguments = NULL;
	self->SendEvent(argEvt_Name,argArguments);
}
#endif

extern "C"
void EDITIONF(ProxyDOMNode_QuerySelector) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		
		return ;
	}
	shrewd_ptr<ProxyDOMNode> self = (ProxyDOMNode*)*pArgInf->m_ppCompoundData;
	const char* argSelectors = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	shrewd_ptr<ProxyDOMNode> result = self->QuerySelector(argSelectors);
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
void EDITIONF(ProxyDOMNode_QuerySelectorAll) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		DWORD* InternalPointer = (DWORD*)NotifySys(NRS_MALLOC, 8, 0);
		InternalPointer[0] = 1;
		InternalPointer[1] = 0;
		pRetData->m_pCompoundData = InternalPointer;
		return ;
	}
	shrewd_ptr<ProxyDOMNode> self = (ProxyDOMNode*)*pArgInf->m_ppCompoundData;
	const char* argSelectors = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	pRetData->m_pCompoundData = (void*)self->QuerySelectorAll(argSelectors);
}

extern "C"
void EDITIONF(ProxyDOMNode_GetChildCount) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyDOMNode> self = (ProxyDOMNode*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetChildCount();
}

extern "C"
void EDITIONF(ProxyDOMNode_GetSelector) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_pText = NULL;
		return ;
	}
	shrewd_ptr<ProxyDOMNode> self = (ProxyDOMNode*)*pArgInf->m_ppCompoundData;
	pRetData->m_pText = self->GetSelector();
}



//==========================================

