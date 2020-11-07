#include "stdafx.h"
#include "EPLProxyBase.h"
#include <proxy/ProxyBrowser.h>
#include <proxy/ProxyFrame.h>
#include <proxy/ProxyRequest.h>
#include <proxy/ProxyResponse.h>
#include <proxy/proxyValue.h>
#include <proxy/proxyListValue.h>
#include <proxy/ProxyDictionaryValue.h>
#include <proxy/ProxyDOMNode.h>
#include <proxy/ProxyBase.h>



//==========================================

#ifdef NOT_USED
extern "C"
void EDITIONF(ProxyBase_Initialize) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	shrewd_ptr<ProxySettings> argSettings = (ProxySettings*)*pArgInf[0].m_ppCompoundData;
	unsigned int argClient = pArgInf[1].m_uint;
	pRetData->m_bool = ProxyBase::Initialize(argSettings,argClient);
}
#endif

extern "C"
void EDITIONF(ProxyBase_Base64Encode) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	unsigned char* argData = pArgInf[0].m_pBin;
	int argSize = pArgInf[1].m_int;
	pRetData->m_pText = ProxyBase::Base64Encode(argData,argSize);
}

extern "C"
void EDITIONF(ProxyBase_Base64Decode) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	char* argData = (NULL==pArgInf[0].m_pText || strlen(pArgInf[0].m_pText) <= 0) ? NULL : pArgInf[0].m_pText;
	pRetData->m_pBin = ProxyBase::Base64Decode(argData);
}

extern "C"
void EDITIONF(ProxyBase_UriEncode) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	char* argData = (NULL==pArgInf[0].m_pText || strlen(pArgInf[0].m_pText) <= 0) ? NULL : pArgInf[0].m_pText;
	bool argUse_Plus = pArgInf[1].m_bool;
	pRetData->m_pText = ProxyBase::UriEncode(argData,argUse_Plus);
}

extern "C"
void EDITIONF(ProxyBase_UriDecode) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	char* argData = (NULL==pArgInf[0].m_pText || strlen(pArgInf[0].m_pText) <= 0) ? NULL : pArgInf[0].m_pText;
	bool argConvert_To_Utf8 = pArgInf[1].m_bool;
	int argUnescape_Rule = pArgInf[2].m_int;
	pRetData->m_pText = ProxyBase::UriDecode(argData,argConvert_To_Utf8,argUnescape_Rule);
}

extern "C"
void EDITIONF(ProxyBase_Utf8ToBytes) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	unsigned char* argData = pArgInf[0].m_pBin;
	int argLength = pArgInf[1].m_int;
	pRetData->m_pText = ProxyBase::Utf8ToBytes(argData,argLength);
}

extern "C"
void EDITIONF(ProxyBase_BytesToUtf8) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	char* argData = (NULL==pArgInf[0].m_pText || strlen(pArgInf[0].m_pText) <= 0) ? NULL : pArgInf[0].m_pText;
	pRetData->m_pBin = ProxyBase::BytesToUtf8(argData);
}

extern "C"
void EDITIONF(ProxyBase_CreateBrowserSettings) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	shrewd_ptr<ProxyBrowserSettings> result = ProxyBase::CreateBrowserSettings();
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
void EDITIONF(ProxyBase_CreateCommandLine) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	shrewd_ptr<ProxyCommandLine> result = ProxyBase::CreateCommandLine();
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
void EDITIONF(ProxyBase_GetGlobalCommandLine) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	shrewd_ptr<ProxyCommandLine> result = ProxyBase::GetGlobalCommandLine();
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
void EDITIONF(ProxyBase_GetGlobalCookieManager) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	shrewd_ptr<ProxyCookieManager> result = ProxyBase::GetGlobalCookieManager();
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
void EDITIONF(ProxyBase_CreateDictionartyValue) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	shrewd_ptr<ProxyDictionaryValue> result = ProxyBase::CreateDictionartyValue();
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

#ifdef NOT_USED
extern "C"
void EDITIONF(ProxyBase_CreateListValue) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	void* argValue = NULL;
	shrewd_ptr<ProxyListValue> result = ProxyBase::CreateListValue(argValue);
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
#endif

extern "C"
void EDITIONF(ProxyBase_CreatePostDataElement) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	shrewd_ptr<ProxyPostDataElement> result = ProxyBase::CreatePostDataElement();
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
void EDITIONF(ProxyBase_CreatePostDataElementWithFile) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	const char* argFilename = (NULL==pArgInf[0].m_pText || strlen(pArgInf[0].m_pText) <= 0) ? NULL : pArgInf[0].m_pText;
	shrewd_ptr<ProxyPostDataElement> result = ProxyBase::CreatePostDataElementWithFile(argFilename);
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
void EDITIONF(ProxyBase_CreatePostDataElementWithData) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	const unsigned char* argBuffer = NULL;
	const unsigned char* argBufferTempBuf = pArgInf[0].m_pBin;
	if(NULL != argBufferTempBuf) { argBuffer = argBufferTempBuf; }
	shrewd_ptr<ProxyPostDataElement> result = ProxyBase::CreatePostDataElementWithData(argBuffer);
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

#ifdef NOT_USED
extern "C"
void EDITIONF(ProxyBase_CreateRequest) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	const char* argMethod = (NULL==pArgInf[0].m_pText || strlen(pArgInf[0].m_pText) <= 0) ? NULL : pArgInf[0].m_pText;
	const char* argUrl = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	const char* argReferrer = (NULL==pArgInf[2].m_pText || strlen(pArgInf[2].m_pText) <= 0) ? NULL : pArgInf[2].m_pText;
	const char* argHeadermaps = (NULL==pArgInf[3].m_pText || strlen(pArgInf[3].m_pText) <= 0) ? NULL : pArgInf[3].m_pText;
	shrewd_ptr<ProxyPostDataElement> argPostdata = (ProxyPostDataElement*)*pArgInf[4].m_ppCompoundData;
	shrewd_ptr<ProxyRequest> result = ProxyBase::CreateRequest(argMethod,argUrl,argReferrer,argHeadermaps,argPostdata);
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
#endif

extern "C"
void EDITIONF(ProxyBase_CreateResponse) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	shrewd_ptr<ProxyResponse> result = ProxyBase::CreateResponse();
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
void EDITIONF(ProxyBase_CreateSetting) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	shrewd_ptr<ProxySettings> result = ProxyBase::CreateSetting();
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

#ifdef NOT_USED
extern "C"
void EDITIONF(ProxyBase_CreateValue) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	void* argValue = NULL;
	shrewd_ptr<ProxyValue> result = ProxyBase::CreateValue(argValue);
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
#endif

extern "C"
void EDITIONF(ProxyBase_CreateWindowInfo) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	shrewd_ptr<ProxyWindowInfo> result = ProxyBase::CreateWindowInfo();
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
void EDITIONF(ProxyBase_CreateAsChildWindow) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	int argParent = pArgInf[0].m_int;
	int argX = pArgInf[1].m_int;
	int argY = pArgInf[2].m_int;
	int argWidth = pArgInf[3].m_int;
	int argHeight = pArgInf[4].m_int;
	shrewd_ptr<ProxyWindowInfo> result = ProxyBase::CreateAsChildWindow(argParent,argX,argY,argWidth,argHeight);
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
void EDITIONF(ProxyBase_CreateAsPopupWindow) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	int argParent = pArgInf[0].m_int;
	const char* argTitle = (NULL==pArgInf[1].m_pText || strlen(pArgInf[1].m_pText) <= 0) ? NULL : pArgInf[1].m_pText;
	shrewd_ptr<ProxyWindowInfo> result = ProxyBase::CreateAsPopupWindow(argParent,argTitle);
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
void EDITIONF(ProxyBase_SendURLRequest) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	shrewd_ptr<ProxyRequest> argRequest = (ProxyRequest*)*pArgInf[0].m_ppCompoundData;
	bool argIncognito_Mode = pArgInf[1].m_bool;
	const char* argProxy_Username = (NULL==pArgInf[2].m_pText || strlen(pArgInf[2].m_pText) <= 0) ? NULL : pArgInf[2].m_pText;
	const char* argProxy_Password = (NULL==pArgInf[3].m_pText || strlen(pArgInf[3].m_pText) <= 0) ? NULL : pArgInf[3].m_pText;
	shrewd_ptr<ProxyURLRequest> result = ProxyBase::SendURLRequest(argRequest,argIncognito_Mode,argProxy_Username,argProxy_Password);
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
void EDITIONF(ProxyBase_CreateServer) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	const char* argAddress = (NULL==pArgInf[0].m_pText || strlen(pArgInf[0].m_pText) <= 0) ? NULL : pArgInf[0].m_pText;
	int argPort = pArgInf[1].m_int;
	int argBacklog = pArgInf[2].m_int;
	ProxyBase::CreateServer(argAddress,argPort,argBacklog);
}

extern "C"
void EDITIONF(ProxyBase_CreateWebSocket) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	shrewd_ptr<ProxyWebSocket> result = ProxyBase::CreateWebSocket();
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
void EDITIONF(ProxyBase_CreateWaitableEvent) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	shrewd_ptr<ProxyWaitableEvent> result = ProxyBase::CreateWaitableEvent();
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
void EDITIONF(ProxyBase_Awaking) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	shrewd_ptr<ProxyWaitableEvent> argWaitable = (ProxyWaitableEvent*)*pArgInf[0].m_ppCompoundData;
	ProxyBase::Awaking(argWaitable);
}

extern "C"
void EDITIONF(ProxyBase_TimedAwaking) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	shrewd_ptr<ProxyWaitableEvent> argWaitable = (ProxyWaitableEvent*)*pArgInf[0].m_ppCompoundData;
	float argMax_Ms = pArgInf[1].m_float;
	pRetData->m_bool = ProxyBase::TimedAwaking(argWaitable,argMax_Ms);
}

extern "C"
void EDITIONF(ProxyBase_CreateMenu) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	shrewd_ptr<ProxyMenuModel> result = ProxyBase::CreateMenu();
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
void EDITIONF(ProxyBase_CreateCollection) (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	bool argShared_Cache = pArgInf[0].m_bool;
	shrewd_ptr<ProxyCollection> result = ProxyBase::CreateCollection(argShared_Cache);
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



//==========================================

