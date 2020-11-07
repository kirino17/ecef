#include "stdafx.h"
#include "EPLProxyMenuModel.h"
#include <proxy/ProxyBrowser.h>
#include <proxy/ProxyFrame.h>
#include <proxy/ProxyRequest.h>
#include <proxy/ProxyResponse.h>
#include <proxy/proxyValue.h>
#include <proxy/proxyListValue.h>
#include <proxy/ProxyDictionaryValue.h>
#include <proxy/ProxyDOMNode.h>
#include <proxy/ProxyMenuModel.h>



//==========================================

extern "C"
void EDITIONF(ProxyMenuModel_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void EDITIONF(ProxyMenuModel_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData) { return; }
	shrewd_ptr<ProxyMenuModel> ptr = (ProxyMenuModel*)*pArgInf->m_ppCompoundData;
	if(ptr){ ptr->release(); *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyMenuModel_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf[1].m_pCompoundData || NULL == *pArgInf[1].m_ppCompoundData) { return; }
	shrewd_ptr<ProxyMenuModel> ptr = (ProxyMenuModel*)*pArgInf[1].m_ppCompoundData;
	if(ptr){ ptr->retain(); *pArgInf->m_ppCompoundData = ptr.get(); }
	else { *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyMenuModel_IsSubMenu) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyMenuModel> self = (ProxyMenuModel*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsSubMenu();
}

extern "C"
void EDITIONF(ProxyMenuModel_Clear) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyMenuModel> self = (ProxyMenuModel*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->Clear();
}

extern "C"
void EDITIONF(ProxyMenuModel_GetCount) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyMenuModel> self = (ProxyMenuModel*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetCount();
}

extern "C"
void EDITIONF(ProxyMenuModel_AddSeparator) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyMenuModel> self = (ProxyMenuModel*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->AddSeparator();
}

extern "C"
void EDITIONF(ProxyMenuModel_AddItem) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyMenuModel> self = (ProxyMenuModel*)*pArgInf->m_ppCompoundData;
	int argCommand_Id = pArgInf[1].m_int;
	const char* argLabel = (NULL==pArgInf[2].m_pText || strlen(pArgInf[2].m_pText) <= 0) ? NULL : pArgInf[2].m_pText;
	pRetData->m_bool = self->AddItem(argCommand_Id,argLabel);
}

extern "C"
void EDITIONF(ProxyMenuModel_AddCheckItem) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyMenuModel> self = (ProxyMenuModel*)*pArgInf->m_ppCompoundData;
	int argCommand_Id = pArgInf[1].m_int;
	const char* argLabel = (NULL==pArgInf[2].m_pText || strlen(pArgInf[2].m_pText) <= 0) ? NULL : pArgInf[2].m_pText;
	pRetData->m_bool = self->AddCheckItem(argCommand_Id,argLabel);
}

extern "C"
void EDITIONF(ProxyMenuModel_AddRadioItem) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyMenuModel> self = (ProxyMenuModel*)*pArgInf->m_ppCompoundData;
	int argCommand_Id = pArgInf[1].m_int;
	const char* argLabel = (NULL==pArgInf[2].m_pText || strlen(pArgInf[2].m_pText) <= 0) ? NULL : pArgInf[2].m_pText;
	int argGroup_Id = pArgInf[3].m_int;
	pRetData->m_bool = self->AddRadioItem(argCommand_Id,argLabel,argGroup_Id);
}

extern "C"
void EDITIONF(ProxyMenuModel_AddSubMenu) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		
		return ;
	}
	shrewd_ptr<ProxyMenuModel> self = (ProxyMenuModel*)*pArgInf->m_ppCompoundData;
	int argCommand_Id = pArgInf[1].m_int;
	const char* argLabel = (NULL==pArgInf[2].m_pText || strlen(pArgInf[2].m_pText) <= 0) ? NULL : pArgInf[2].m_pText;
	shrewd_ptr<ProxyMenuModel> result = self->AddSubMenu(argCommand_Id,argLabel);
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
void EDITIONF(ProxyMenuModel_InsertSeparatorAt) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyMenuModel> self = (ProxyMenuModel*)*pArgInf->m_ppCompoundData;
	int argIndex = pArgInf[1].m_int;
	pRetData->m_bool = self->InsertSeparatorAt(argIndex);
}

extern "C"
void EDITIONF(ProxyMenuModel_InsertItemAt) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyMenuModel> self = (ProxyMenuModel*)*pArgInf->m_ppCompoundData;
	int argIndex = pArgInf[1].m_int;
	int argCommand_Id = pArgInf[2].m_int;
	const char* argLabel = (NULL==pArgInf[3].m_pText || strlen(pArgInf[3].m_pText) <= 0) ? NULL : pArgInf[3].m_pText;
	pRetData->m_bool = self->InsertItemAt(argIndex,argCommand_Id,argLabel);
}

extern "C"
void EDITIONF(ProxyMenuModel_InsertCheckItemAt) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyMenuModel> self = (ProxyMenuModel*)*pArgInf->m_ppCompoundData;
	int argIndex = pArgInf[1].m_int;
	int argCommand_Id = pArgInf[2].m_int;
	const char* argLabel = (NULL==pArgInf[3].m_pText || strlen(pArgInf[3].m_pText) <= 0) ? NULL : pArgInf[3].m_pText;
	pRetData->m_bool = self->InsertCheckItemAt(argIndex,argCommand_Id,argLabel);
}

extern "C"
void EDITIONF(ProxyMenuModel_InsertRadioItemAt) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyMenuModel> self = (ProxyMenuModel*)*pArgInf->m_ppCompoundData;
	int argIndex = pArgInf[1].m_int;
	int argCommand_Id = pArgInf[2].m_int;
	const char* argLabel = (NULL==pArgInf[3].m_pText || strlen(pArgInf[3].m_pText) <= 0) ? NULL : pArgInf[3].m_pText;
	int argGroup_Id = pArgInf[4].m_int;
	pRetData->m_bool = self->InsertRadioItemAt(argIndex,argCommand_Id,argLabel,argGroup_Id);
}

extern "C"
void EDITIONF(ProxyMenuModel_InsertSubMenuAt) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		
		return ;
	}
	shrewd_ptr<ProxyMenuModel> self = (ProxyMenuModel*)*pArgInf->m_ppCompoundData;
	int argIndex = pArgInf[1].m_int;
	int argCommand_Id = pArgInf[2].m_int;
	const char* argLabel = (NULL==pArgInf[3].m_pText || strlen(pArgInf[3].m_pText) <= 0) ? NULL : pArgInf[3].m_pText;
	shrewd_ptr<ProxyMenuModel> result = self->InsertSubMenuAt(argIndex,argCommand_Id,argLabel);
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
void EDITIONF(ProxyMenuModel_Remove) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyMenuModel> self = (ProxyMenuModel*)*pArgInf->m_ppCompoundData;
	int argCommand_Id = pArgInf[1].m_int;
	pRetData->m_bool = self->Remove(argCommand_Id);
}

extern "C"
void EDITIONF(ProxyMenuModel_RemoveAt) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyMenuModel> self = (ProxyMenuModel*)*pArgInf->m_ppCompoundData;
	int argIndex = pArgInf[1].m_int;
	pRetData->m_bool = self->RemoveAt(argIndex);
}

extern "C"
void EDITIONF(ProxyMenuModel_GetIndexOf) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyMenuModel> self = (ProxyMenuModel*)*pArgInf->m_ppCompoundData;
	int argCommand_Id = pArgInf[1].m_int;
	pRetData->m_int = self->GetIndexOf(argCommand_Id);
}

extern "C"
void EDITIONF(ProxyMenuModel_GetCommandIdAt) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyMenuModel> self = (ProxyMenuModel*)*pArgInf->m_ppCompoundData;
	int argIndex = pArgInf[1].m_int;
	pRetData->m_int = self->GetCommandIdAt(argIndex);
}

extern "C"
void EDITIONF(ProxyMenuModel_SetCommandIdAt) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyMenuModel> self = (ProxyMenuModel*)*pArgInf->m_ppCompoundData;
	int argIndex = pArgInf[1].m_int;
	int argCommand_Id = pArgInf[2].m_int;
	pRetData->m_bool = self->SetCommandIdAt(argIndex,argCommand_Id);
}

extern "C"
void EDITIONF(ProxyMenuModel_GetLabel) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_pText = NULL;
		return ;
	}
	shrewd_ptr<ProxyMenuModel> self = (ProxyMenuModel*)*pArgInf->m_ppCompoundData;
	int argCommand_Id = pArgInf[1].m_int;
	pRetData->m_pText = self->GetLabel(argCommand_Id);
}

extern "C"
void EDITIONF(ProxyMenuModel_GetLabelAt) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_pText = NULL;
		return ;
	}
	shrewd_ptr<ProxyMenuModel> self = (ProxyMenuModel*)*pArgInf->m_ppCompoundData;
	int argIndex = pArgInf[1].m_int;
	pRetData->m_pText = self->GetLabelAt(argIndex);
}

extern "C"
void EDITIONF(ProxyMenuModel_SetLabel) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyMenuModel> self = (ProxyMenuModel*)*pArgInf->m_ppCompoundData;
	int argCommand_Id = pArgInf[1].m_int;
	const char* argLabel = (NULL==pArgInf[2].m_pText || strlen(pArgInf[2].m_pText) <= 0) ? NULL : pArgInf[2].m_pText;
	pRetData->m_bool = self->SetLabel(argCommand_Id,argLabel);
}

extern "C"
void EDITIONF(ProxyMenuModel_SetLabelAt) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyMenuModel> self = (ProxyMenuModel*)*pArgInf->m_ppCompoundData;
	int argIndex = pArgInf[1].m_int;
	const char* argLabel = (NULL==pArgInf[2].m_pText || strlen(pArgInf[2].m_pText) <= 0) ? NULL : pArgInf[2].m_pText;
	pRetData->m_bool = self->SetLabelAt(argIndex,argLabel);
}

extern "C"
void EDITIONF(ProxyMenuModel_GetType) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyMenuModel> self = (ProxyMenuModel*)*pArgInf->m_ppCompoundData;
	int argCommand_Id = pArgInf[1].m_int;
	pRetData->m_int = self->GetType(argCommand_Id);
}

extern "C"
void EDITIONF(ProxyMenuModel_GetTypeAt) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyMenuModel> self = (ProxyMenuModel*)*pArgInf->m_ppCompoundData;
	int argIndex = pArgInf[1].m_int;
	pRetData->m_int = self->GetTypeAt(argIndex);
}

extern "C"
void EDITIONF(ProxyMenuModel_GetGroupId) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyMenuModel> self = (ProxyMenuModel*)*pArgInf->m_ppCompoundData;
	int argCommand_Id = pArgInf[1].m_int;
	pRetData->m_int = self->GetGroupId(argCommand_Id);
}

extern "C"
void EDITIONF(ProxyMenuModel_GetGroupIdAt) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyMenuModel> self = (ProxyMenuModel*)*pArgInf->m_ppCompoundData;
	int argIndex = pArgInf[1].m_int;
	pRetData->m_int = self->GetGroupIdAt(argIndex);
}

extern "C"
void EDITIONF(ProxyMenuModel_SetGroupId) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyMenuModel> self = (ProxyMenuModel*)*pArgInf->m_ppCompoundData;
	int argCommand_Id = pArgInf[1].m_int;
	int argGroup_Id = pArgInf[2].m_int;
	pRetData->m_bool = self->SetGroupId(argCommand_Id,argGroup_Id);
}

extern "C"
void EDITIONF(ProxyMenuModel_SetGroupIdAt) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyMenuModel> self = (ProxyMenuModel*)*pArgInf->m_ppCompoundData;
	int argIndex = pArgInf[1].m_int;
	int argGroup_Id = pArgInf[2].m_int;
	pRetData->m_bool = self->SetGroupIdAt(argIndex,argGroup_Id);
}

extern "C"
void EDITIONF(ProxyMenuModel_GetSubMenu) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		
		return ;
	}
	shrewd_ptr<ProxyMenuModel> self = (ProxyMenuModel*)*pArgInf->m_ppCompoundData;
	int argCommand_Id = pArgInf[1].m_int;
	shrewd_ptr<ProxyMenuModel> result = self->GetSubMenu(argCommand_Id);
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
void EDITIONF(ProxyMenuModel_GetSubMenuAt) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		
		return ;
	}
	shrewd_ptr<ProxyMenuModel> self = (ProxyMenuModel*)*pArgInf->m_ppCompoundData;
	int argIndex = pArgInf[1].m_int;
	shrewd_ptr<ProxyMenuModel> result = self->GetSubMenuAt(argIndex);
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
void EDITIONF(ProxyMenuModel_IsVisible) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyMenuModel> self = (ProxyMenuModel*)*pArgInf->m_ppCompoundData;
	int argCommand_Id = pArgInf[1].m_int;
	pRetData->m_bool = self->IsVisible(argCommand_Id);
}

extern "C"
void EDITIONF(ProxyMenuModel_IsVisibleAt) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyMenuModel> self = (ProxyMenuModel*)*pArgInf->m_ppCompoundData;
	int argIndex = pArgInf[1].m_int;
	pRetData->m_bool = self->IsVisibleAt(argIndex);
}

extern "C"
void EDITIONF(ProxyMenuModel_SetVisible) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyMenuModel> self = (ProxyMenuModel*)*pArgInf->m_ppCompoundData;
	int argCommand_Id = pArgInf[1].m_int;
	bool argVisible = pArgInf[2].m_bool;
	pRetData->m_bool = self->SetVisible(argCommand_Id,argVisible);
}

extern "C"
void EDITIONF(ProxyMenuModel_SetVisibleAt) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyMenuModel> self = (ProxyMenuModel*)*pArgInf->m_ppCompoundData;
	int argIndex = pArgInf[1].m_int;
	bool argVisible = pArgInf[2].m_bool;
	pRetData->m_bool = self->SetVisibleAt(argIndex,argVisible);
}

extern "C"
void EDITIONF(ProxyMenuModel_IsEnabled) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyMenuModel> self = (ProxyMenuModel*)*pArgInf->m_ppCompoundData;
	int argCommand_Id = pArgInf[1].m_int;
	pRetData->m_bool = self->IsEnabled(argCommand_Id);
}

extern "C"
void EDITIONF(ProxyMenuModel_IsEnabledAt) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyMenuModel> self = (ProxyMenuModel*)*pArgInf->m_ppCompoundData;
	int argIndex = pArgInf[1].m_int;
	pRetData->m_bool = self->IsEnabledAt(argIndex);
}

extern "C"
void EDITIONF(ProxyMenuModel_SetEnabled) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyMenuModel> self = (ProxyMenuModel*)*pArgInf->m_ppCompoundData;
	int argCommand_Id = pArgInf[1].m_int;
	bool argEnabled = pArgInf[2].m_bool;
	pRetData->m_bool = self->SetEnabled(argCommand_Id,argEnabled);
}

extern "C"
void EDITIONF(ProxyMenuModel_SetEnabledAt) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyMenuModel> self = (ProxyMenuModel*)*pArgInf->m_ppCompoundData;
	int argIndex = pArgInf[1].m_int;
	bool argEnabled = pArgInf[2].m_bool;
	pRetData->m_bool = self->SetEnabledAt(argIndex,argEnabled);
}

extern "C"
void EDITIONF(ProxyMenuModel_IsChecked) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyMenuModel> self = (ProxyMenuModel*)*pArgInf->m_ppCompoundData;
	int argCommand_Id = pArgInf[1].m_int;
	pRetData->m_bool = self->IsChecked(argCommand_Id);
}

extern "C"
void EDITIONF(ProxyMenuModel_IsCheckedAt) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyMenuModel> self = (ProxyMenuModel*)*pArgInf->m_ppCompoundData;
	int argIndex = pArgInf[1].m_int;
	pRetData->m_bool = self->IsCheckedAt(argIndex);
}

extern "C"
void EDITIONF(ProxyMenuModel_SetChecked) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyMenuModel> self = (ProxyMenuModel*)*pArgInf->m_ppCompoundData;
	int argCommand_Id = pArgInf[1].m_int;
	bool argChecked = pArgInf[2].m_bool;
	pRetData->m_bool = self->SetChecked(argCommand_Id,argChecked);
}

extern "C"
void EDITIONF(ProxyMenuModel_SetCheckedAt) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyMenuModel> self = (ProxyMenuModel*)*pArgInf->m_ppCompoundData;
	int argIndex = pArgInf[1].m_int;
	bool argChecked = pArgInf[2].m_bool;
	pRetData->m_bool = self->SetCheckedAt(argIndex,argChecked);
}

extern "C"
void EDITIONF(ProxyMenuModel_HasAccelerator) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyMenuModel> self = (ProxyMenuModel*)*pArgInf->m_ppCompoundData;
	int argCommand_Id = pArgInf[1].m_int;
	pRetData->m_bool = self->HasAccelerator(argCommand_Id);
}

extern "C"
void EDITIONF(ProxyMenuModel_HasAcceleratorAt) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyMenuModel> self = (ProxyMenuModel*)*pArgInf->m_ppCompoundData;
	int argIndex = pArgInf[1].m_int;
	pRetData->m_bool = self->HasAcceleratorAt(argIndex);
}

extern "C"
void EDITIONF(ProxyMenuModel_SetAccelerator) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyMenuModel> self = (ProxyMenuModel*)*pArgInf->m_ppCompoundData;
	int argCommand_Id = pArgInf[1].m_int;
	int argKey_Code = pArgInf[2].m_int;
	bool argShift_Pressed = pArgInf[3].m_bool;
	bool argCtrl_Pressed = pArgInf[4].m_bool;
	bool argAlt_Pressed = pArgInf[5].m_bool;
	pRetData->m_bool = self->SetAccelerator(argCommand_Id,argKey_Code,argShift_Pressed,argCtrl_Pressed,argAlt_Pressed);
}

extern "C"
void EDITIONF(ProxyMenuModel_SetAcceleratorAt) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyMenuModel> self = (ProxyMenuModel*)*pArgInf->m_ppCompoundData;
	int argIndex = pArgInf[1].m_int;
	int argKey_Code = pArgInf[2].m_int;
	bool argShift_Pressed = pArgInf[3].m_bool;
	bool argCtrl_Pressed = pArgInf[4].m_bool;
	bool argAlt_Pressed = pArgInf[5].m_bool;
	pRetData->m_bool = self->SetAcceleratorAt(argIndex,argKey_Code,argShift_Pressed,argCtrl_Pressed,argAlt_Pressed);
}

extern "C"
void EDITIONF(ProxyMenuModel_RemoveAccelerator) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyMenuModel> self = (ProxyMenuModel*)*pArgInf->m_ppCompoundData;
	int argCommand_Id = pArgInf[1].m_int;
	pRetData->m_bool = self->RemoveAccelerator(argCommand_Id);
}

extern "C"
void EDITIONF(ProxyMenuModel_RemoveAcceleratorAt) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyMenuModel> self = (ProxyMenuModel*)*pArgInf->m_ppCompoundData;
	int argIndex = pArgInf[1].m_int;
	pRetData->m_bool = self->RemoveAcceleratorAt(argIndex);
}

extern "C"
void EDITIONF(ProxyMenuModel_SetColor) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyMenuModel> self = (ProxyMenuModel*)*pArgInf->m_ppCompoundData;
	int argCommand_Id = pArgInf[1].m_int;
	int argColor_Type = pArgInf[2].m_int;
	unsigned int argColor = pArgInf[3].m_uint;
	pRetData->m_bool = self->SetColor(argCommand_Id,argColor_Type,argColor);
}

extern "C"
void EDITIONF(ProxyMenuModel_SetColorAt) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyMenuModel> self = (ProxyMenuModel*)*pArgInf->m_ppCompoundData;
	int argIndex = pArgInf[1].m_int;
	int argColor_Type = pArgInf[2].m_int;
	unsigned int argColor = pArgInf[3].m_uint;
	pRetData->m_bool = self->SetColorAt(argIndex,argColor_Type,argColor);
}

extern "C"
void EDITIONF(ProxyMenuModel_SetFontList) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyMenuModel> self = (ProxyMenuModel*)*pArgInf->m_ppCompoundData;
	int argCommand_Id = pArgInf[1].m_int;
	const char* argFont_List = (NULL==pArgInf[2].m_pText || strlen(pArgInf[2].m_pText) <= 0) ? NULL : pArgInf[2].m_pText;
	pRetData->m_bool = self->SetFontList(argCommand_Id,argFont_List);
}

extern "C"
void EDITIONF(ProxyMenuModel_SetFontListAt) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyMenuModel> self = (ProxyMenuModel*)*pArgInf->m_ppCompoundData;
	int argIndex = pArgInf[1].m_int;
	const char* argFont_List = (NULL==pArgInf[2].m_pText || strlen(pArgInf[2].m_pText) <= 0) ? NULL : pArgInf[2].m_pText;
	pRetData->m_bool = self->SetFontListAt(argIndex,argFont_List);
}



//==========================================

