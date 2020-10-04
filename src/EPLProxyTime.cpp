#include "stdafx.h"
#include "EPLProxyTime.h"
#include <proxy/ProxyBrowser.h>
#include <proxy/ProxyBrowserHost.h>
#include <proxy/ProxyFrame.h>
#include <proxy/ProxyRequest.h>
#include <proxy/ProxyResponse.h>
#include <proxy/proxyValue.h>
#include <proxy/proxyListValue.h>
#include <proxy/ProxyDictionaryValue.h>
#include <proxy/ProxyTime.h>



//==========================================

extern "C"
void EDITIONF(ProxyTime_Constructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void EDITIONF(ProxyTime_Destructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData) { return; }
	shrewd_ptr<ProxyTime> ptr = (ProxyTime*)*pArgInf->m_ppCompoundData;
	if(ptr){ ptr->release(); *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyTime_CopyConstructor)(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf[1].m_pCompoundData || NULL == *pArgInf[1].m_ppCompoundData) { return; }
	shrewd_ptr<ProxyTime> ptr = (ProxyTime*)*pArgInf[1].m_ppCompoundData;
	if(ptr){ ptr->retain(); *pArgInf->m_ppCompoundData = ptr.get(); }
	else { *pArgInf->m_ppCompoundData = NULL; }
}

extern "C"
void EDITIONF(ProxyTime_Create) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	shrewd_ptr<ProxyTime> result = ProxyTime::Create();
	if(*pArgInf->m_ppCompoundData){
		((refcounted*)*pArgInf->m_ppCompoundData)->release();
	 }
	if(result){
		result->retain();
		*pArgInf->m_ppCompoundData = result.get();
	}
}

extern "C"
void EDITIONF(ProxyTime_IsValid) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_bool = FALSE;
		return ;
	}
	shrewd_ptr<ProxyTime> self = (ProxyTime*)*pArgInf->m_ppCompoundData;
	pRetData->m_bool = self->IsValid();
}

extern "C"
void EDITIONF(ProxyTime_SetYear) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyTime> self = (ProxyTime*)*pArgInf->m_ppCompoundData;
	int argYear = pArgInf[1].m_int;
	self->SetYear(argYear);
}

extern "C"
void EDITIONF(ProxyTime_GetYear) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyTime> self = (ProxyTime*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetYear();
}

extern "C"
void EDITIONF(ProxyTime_SetMonth) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyTime> self = (ProxyTime*)*pArgInf->m_ppCompoundData;
	int argMonth = pArgInf[1].m_int;
	self->SetMonth(argMonth);
}

extern "C"
void EDITIONF(ProxyTime_GetMonth) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyTime> self = (ProxyTime*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetMonth();
}

extern "C"
void EDITIONF(ProxyTime_SetDayOfWeek) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyTime> self = (ProxyTime*)*pArgInf->m_ppCompoundData;
	int argDay_Of_Week = pArgInf[1].m_int;
	self->SetDayOfWeek(argDay_Of_Week);
}

extern "C"
void EDITIONF(ProxyTime_GetDayOfWeek) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyTime> self = (ProxyTime*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetDayOfWeek();
}

extern "C"
void EDITIONF(ProxyTime_SetDayOfMonth) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyTime> self = (ProxyTime*)*pArgInf->m_ppCompoundData;
	int argDay_Of_Month = pArgInf[1].m_int;
	self->SetDayOfMonth(argDay_Of_Month);
}

extern "C"
void EDITIONF(ProxyTime_GetDayOfMonth) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyTime> self = (ProxyTime*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetDayOfMonth();
}

extern "C"
void EDITIONF(ProxyTime_SetHour) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyTime> self = (ProxyTime*)*pArgInf->m_ppCompoundData;
	int argHour = pArgInf[1].m_int;
	self->SetHour(argHour);
}

extern "C"
void EDITIONF(ProxyTime_GetHour) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyTime> self = (ProxyTime*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetHour();
}

extern "C"
void EDITIONF(ProxyTime_SetMinute) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyTime> self = (ProxyTime*)*pArgInf->m_ppCompoundData;
	int argMinute = pArgInf[1].m_int;
	self->SetMinute(argMinute);
}

extern "C"
void EDITIONF(ProxyTime_GetMinute) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyTime> self = (ProxyTime*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetMinute();
}

extern "C"
void EDITIONF(ProxyTime_SetSecond) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyTime> self = (ProxyTime*)*pArgInf->m_ppCompoundData;
	int argSecond = pArgInf[1].m_int;
	self->SetSecond(argSecond);
}

extern "C"
void EDITIONF(ProxyTime_GetSecond) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyTime> self = (ProxyTime*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetSecond();
}

extern "C"
void EDITIONF(ProxyTime_SetMillisecond) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyTime> self = (ProxyTime*)*pArgInf->m_ppCompoundData;
	int argMillisecond = pArgInf[1].m_int;
	self->SetMillisecond(argMillisecond);
}

extern "C"
void EDITIONF(ProxyTime_GetMillisecond) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int = 0;
		return ;
	}
	shrewd_ptr<ProxyTime> self = (ProxyTime*)*pArgInf->m_ppCompoundData;
	pRetData->m_int = self->GetMillisecond();
}

extern "C"
void EDITIONF(ProxyTime_SetTime) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyTime> self = (ProxyTime*)*pArgInf->m_ppCompoundData;
	__int64 argTime = pArgInf[1].m_int64;
	self->SetTime(argTime);
}

extern "C"
void EDITIONF(ProxyTime_GetTime) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int64 = 0;
		return ;
	}
	shrewd_ptr<ProxyTime> self = (ProxyTime*)*pArgInf->m_ppCompoundData;
	pRetData->m_int64 = self->GetTime();
}

extern "C"
void EDITIONF(ProxyTime_SetTimeDouble) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyTime> self = (ProxyTime*)*pArgInf->m_ppCompoundData;
	double argTime = pArgInf[1].m_double;
	self->SetTimeDouble(argTime);
}

extern "C"
void EDITIONF(ProxyTime_GetTimeDouble) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_double = 0.0f;
		return ;
	}
	shrewd_ptr<ProxyTime> self = (ProxyTime*)*pArgInf->m_ppCompoundData;
	pRetData->m_double = self->GetTimeDouble();
}

extern "C"
void EDITIONF(ProxyTime_SetNow) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		return ;
	}
	shrewd_ptr<ProxyTime> self = (ProxyTime*)*pArgInf->m_ppCompoundData;
	self->SetNow();
}

extern "C"
void EDITIONF(ProxyTime_Delta) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	if(NULL == pArgInf->m_pCompoundData || NULL == *pArgInf->m_ppCompoundData){
		pRetData->m_int64 = 0;
		return ;
	}
	shrewd_ptr<ProxyTime> self = (ProxyTime*)*pArgInf->m_ppCompoundData;
	shrewd_ptr<ProxyTime> argOther = (ProxyTime*)*pArgInf[1].m_ppCompoundData;
	pRetData->m_int64 = self->Delta(argOther);
}



//==========================================

