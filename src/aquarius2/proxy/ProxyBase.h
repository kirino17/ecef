#pragma once
#include "../def/def.h"
#include "ProxySettings.h"
#include "ProxyListValue.h"
#include "ProxyValue.h"
#include "ProxyBrowserSettings.h"
#include "ProxyCookie.h"
#include "ProxyCommandLine.h"
#include "ProxyCookieManager.h"
#include "ProxyRequest.h"
#include "ProxyResponse.h"
#include "ProxyURLRequest.h"
#include "ProxyBrowser.h"
#include "ProxyWindowInfo.h"
#include "ProxyServer.h"
#include "ProxyWebSocket.h"
#include "ProxyWaitableEvent.h"
#include "ProxyMenuModel.h"
#include "ProxyCollection.h"

typedef void*  EPL_STATEMENT;

#define INTERNAL_TOOL_CALL	\
	static void \
		ExportResourceToDir(const char* inDir);

class AQUADLL ProxyBase : public refcounted {
public:
	ProxyBase();
	~ProxyBase();

public:

	///
	// This function should be called on the main application thread to initialize
	// the CEF browser process. The |application| parameter may be empty. A return
	// value of true indicates that it succeeded and false indicates that it failed.
	// The |windows_sandbox_info| parameter is only used on Windows and may be NULL
	// (see cef_sandbox_win.h for details).
	///
	/*--cef(api_hash_check,optional_param=application,
			optional_param=windows_sandbox_info)--*/
	static bool Initialize(
		shrewd_ptr<ProxySettings> settings,
		unsigned int client
	);

	///
	//	Base64Encode
	///
	static char* Base64Encode(unsigned char* data, size_t size);

	///
	//	Base64Decode
	///
	static unsigned char* Base64Decode(char* data);

	///
	//	UrlEncode
	///
	static char* UriEncode(char* data, bool use_plus);

	///
	//	UrlEncode
	///
	static char* UriDecode(char* data, bool convert_to_utf8, int unescape_rule);

	///
	//	Utf8ToAnsi
	///
	static char* Utf8ToBytes(unsigned char* data, size_t length);

	///
	//	AnsiToUtf8
	///
	static unsigned char* BytesToUtf8(char* data);


	////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////

	///
	//	CreateBrowserSettings
	///
	static shrewd_ptr<ProxyBrowserSettings> CreateBrowserSettings();

	///
	//	CreateCommandLine
	///
	static shrewd_ptr<ProxyCommandLine> CreateCommandLine();

	///
	//	CreateCommandLine
	///
	static shrewd_ptr<ProxyCommandLine> GetGlobalCommandLine();

	///
	//	GetGlobalCookieManager
	///
	static shrewd_ptr<ProxyCookieManager> GetGlobalCookieManager();

	///
	//	CreateDictionartyValue
	///
	static shrewd_ptr<ProxyDictionaryValue> CreateDictionartyValue();

	///
	//	CreateListValue
	///
	static shrewd_ptr<ProxyListValue> CreateListValue(EPL_ALL value);

	///
	//	CreatePostDataElement
	///
	static shrewd_ptr<ProxyPostDataElement> CreatePostDataElement();

	static shrewd_ptr<ProxyPostDataElement> CreatePostDataElementWithFile(const char* filename);

	static shrewd_ptr<ProxyPostDataElement> CreatePostDataElementWithData(const unsigned char* buffer);

	///
	//	CreateRequest
	///
	static shrewd_ptr<ProxyRequest> CreateRequest(const char* method, const char* url, const char* referrer, const char* headerMaps, shrewd_ptr<ProxyPostDataElement> postData);

	///
	//	CreateResponse
	///
	static shrewd_ptr<ProxyResponse> CreateResponse();

	///
	//	CreateSetting
	///
	static shrewd_ptr<ProxySettings> CreateSetting();

	///
	//	CreateValue
	///
	static shrewd_ptr<ProxyValue> CreateValue(EPL_ALL value);

	///
	//	CreateWindowInfo
	///
	static shrewd_ptr<ProxyWindowInfo> CreateWindowInfo();

	static shrewd_ptr<ProxyWindowInfo> CreateAsChildWindow(int parent, int x, int y, int width, int height);

	static shrewd_ptr<ProxyWindowInfo> CreateAsPopupWindow(int parent, const char* title);

	///
	//	SendURLRequest
	///
	static shrewd_ptr<ProxyURLRequest> SendURLRequest( shrewd_ptr<ProxyRequest> request, bool incognito_mode, const char* proxy_username, const char* proxy_password);

	///
	//	CreateServer
	///
	static void CreateServer(const char* address, int port, int backlog);

	///
	//	CreateWebSocket
	///
	static shrewd_ptr<ProxyWebSocket> CreateWebSocket();

	///
	//	CreateWaitableEvent
	///
	static shrewd_ptr<ProxyWaitableEvent> CreateWaitableEvent();

	///
	//	Awaking
	///
	static void Awaking( shrewd_ptr<ProxyWaitableEvent> waitable);

	///
	//	TimedAwaking
	///
	static bool TimedAwaking(shrewd_ptr<ProxyWaitableEvent> waitable, float max_ms);

	///
	//	´´½¨²Ëµ¥
	///
	static shrewd_ptr<ProxyMenuModel> CreateMenu();

	///
	//	create collection
	///
	static shrewd_ptr<ProxyCollection> CreateCollection(bool shared_cache);

public:
	INTERNAL_TOOL_CALL;

public:
	PRIME_IMPLEMENT_REFCOUNTING(ProxyBase);
};