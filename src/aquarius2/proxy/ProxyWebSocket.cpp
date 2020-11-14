#include "ProxyWebSocket.h"
#include <cpprest/ws_client.h>
#include <atlconv.h>
#include "include/cef_base.h"
#include "ProxyClient.h"
#include "../client/InternalClient.h"
#include <cpprest/producerconsumerstream.h>

using namespace web;
using namespace web::websockets;
using namespace web::websockets::client;
using namespace utility;
using namespace web::http;
using namespace concurrency;

#pragma comment(lib,"user32.lib")
#pragma comment(lib,"gdi32.lib")
#pragma comment(lib,"Advapi32.lib")

#if _MSC_VER>=1900
#include <stdio.h>
_ACRTIMP_ALT FILE* __cdecl __acrt_iob_func(unsigned);
#ifdef __cplusplus 
extern "C"
#endif 
FILE * __cdecl __iob_func(unsigned i) {
	return __acrt_iob_func(i);
}
#endif /* _MSC_VER>=1900 */

struct WEB_SOCKET_RUNNING_DATA : public CefBaseRefCounted {
	websocket_client_config config;
	websocket_callback_client* internalClient;
	bool isConnected;

	WEB_SOCKET_RUNNING_DATA():
		config(),
		internalClient(nullptr),
		isConnected(false){

	}

	~WEB_SOCKET_RUNNING_DATA() {
		if (internalClient) {
			internalClient->set_close_handler(nullptr);
			internalClient->set_message_handler(nullptr);
			delete internalClient; 
			internalClient = nullptr;
		}
	}

public:
	IMPLEMENT_REFCOUNTING(WEB_SOCKET_RUNNING_DATA);
};


ProxyWebSocket::ProxyWebSocket(void* ptr):
	_rawptr(ptr){
	if (_rawptr) {
		((CefBaseRefCounted*)_rawptr)->AddRef();
	}
	else {
		CefRefPtr<WEB_SOCKET_RUNNING_DATA> data = new WEB_SOCKET_RUNNING_DATA();
		data->AddRef();
		_rawptr = (void*)data.get();

	}
}

ProxyWebSocket::~ProxyWebSocket() {
	if (_rawptr) {
		((CefBaseRefCounted*)_rawptr)->Release();
		_rawptr = nullptr;
	}
}

void ProxyWebSocket::SetProxy(const char* url) {
	ASSERTN();
	USES_CONVERSION;
	if (!url) return;
	std::wstring proxyUri = A2W(url);
	std::size_t end = std::wstring::npos;
	std::size_t begin = 0;
	if ((end=proxyUri.find(L"@"))!= std::wstring::npos) {
		std::wstring auth;
		for (int i = end; i >= 0; i--){
			if (proxyUri[i] == '/') {
				begin = i + 1;
				break;
			}
		}
		auth = proxyUri.substr(begin, end - begin);
		std::size_t auth_end = std::wstring::npos;
		if ((auth_end=auth.find(':')) != std::wstring::npos) {
			FORWARD(WEB_SOCKET_RUNNING_DATA)->config.set_credentials(web::credentials(
				auth.substr(0,auth_end), &auth[auth_end+1]
			));
		}

		if (begin > 0) {
			proxyUri = proxyUri.substr(0, begin) + &proxyUri[end + 1];
		}
		else {
			proxyUri = &proxyUri[end + 1];
		}
	}
	FORWARD(WEB_SOCKET_RUNNING_DATA)->config.set_proxy(web::web_proxy(proxyUri));
}

void ProxyWebSocket::SetUserAgent(const char* user_agent) {
	ASSERTN();
	if (!user_agent) return;
	FORWARD(WEB_SOCKET_RUNNING_DATA)->config.set_user_agent(user_agent);
}

void ProxyWebSocket::SetHeaderByName(const char* name, const char* value) {
	ASSERTN();
	if (!name) {
		return;
	}
	USES_CONVERSION;
	http_headers& headers = FORWARD(WEB_SOCKET_RUNNING_DATA)->config.headers();
	headers.add(A2W(name), value);
}

void ProxyWebSocket::AddSubProtocol(const char* name) {
	ASSERTN();
	if (!name) {
		return;
	}
	USES_CONVERSION;
	FORWARD(WEB_SOCKET_RUNNING_DATA)->config.add_subprotocol(A2W(name));
}

void ProxyWebSocket::Connect(const char* uri) {
	ASSERTN();
	if (!uri) return;
	USES_CONVERSION;
	void* pointer = _rawptr;

	websocket_callback_client* client = FORWARD(WEB_SOCKET_RUNNING_DATA)->internalClient;
	if (client && FORWARD(WEB_SOCKET_RUNNING_DATA)->isConnected) {
		client->close().get();
		FORWARD(WEB_SOCKET_RUNNING_DATA)->Release();
	}
	client = new websocket_callback_client(FORWARD(WEB_SOCKET_RUNNING_DATA)->config);
	FORWARD(WEB_SOCKET_RUNNING_DATA)->internalClient = client;

	client->set_close_handler([pointer](websocket_close_status close_status,
		const utility::string_t& reason,
		const std::error_code& error) {
			shrewd_ptr<ProxyWebSocket> websocket = new ProxyWebSocket(pointer);
			((WEB_SOCKET_RUNNING_DATA*)pointer)->isConnected = false;
			shrewd_ptr<ProxyClient> client = InternalClient::GetShareInatance()->GetClient();

			if (close_status != websocket_close_status::normal) {
				if (client) {
					USES_CONVERSION;
					client->OnWebSocketClientError(websocket, W2A(reason.c_str()));
				}
			}

			if (client) {
				client->OnWebSocketClientClosed(websocket);
			}
			((WEB_SOCKET_RUNNING_DATA*)pointer)->Release();
	});

	client->set_message_handler([pointer](const websocket_incoming_message& msg) {
		shrewd_ptr<ProxyWebSocket> websocket = new ProxyWebSocket(pointer);
		shrewd_ptr<ProxyClient> client = InternalClient::GetShareInatance()->GetClient();
		if (client) {
			auto type = msg.message_type();
			if (type == websocket_message_type::text_message) {
				std::string string = msg.extract_string().get();
				unsigned char* buffer = (unsigned char*)NewBuffer(8 + string.length());
				*(int*)&buffer[0] = 1;
				*(int*)&buffer[4] = string.length();
				memcpy(&buffer[8], string.c_str(),string.length());
				client->OnWebSocketClientMessage(websocket,(int)type, buffer);
				DeleteBuffer(buffer);
			}
			else {
				streams::istream input = msg.body();
				streams::streambuf<uint8_t> stream = input.streambuf();
				size_t length = stream.size();
				unsigned char* buffer = (unsigned char*)NewBuffer(8 + length);
				*(int*)&buffer[0] = 1;
				*(int*)&buffer[4] = length;
				stream.getn((uint8_t*)&buffer[8], length);
				client->OnWebSocketClientMessage(websocket, (int)type, buffer);
				DeleteBuffer(buffer);
			}
		}
	});


	FORWARD(WEB_SOCKET_RUNNING_DATA)->AddRef();
	client->connect(A2W(uri)).then([pointer]() {
		shrewd_ptr<ProxyWebSocket> websocket = new ProxyWebSocket(pointer);
		((WEB_SOCKET_RUNNING_DATA*)pointer)->isConnected = true;
		shrewd_ptr<ProxyClient> client = InternalClient::GetShareInatance()->GetClient();
		if (client) {
			client->OnWebSocketClientConnected(websocket);
		}

	}).then([pointer](pplx::task<void> t) {
		try
		{
			t.get();
		}
		catch (const std::exception &ex)
		{

		}
	});
}
#pragma warning(disable : 4996)

void ProxyWebSocket::Send(int type, const unsigned char* data, size_t data_size) {
	ASSERTN();
	if (FORWARD(WEB_SOCKET_RUNNING_DATA)->internalClient) {
		try
		{
			websocket_outgoing_message msg;
			if (type == (int)websocket_message_type::text_message) {
				msg.set_utf8_message(std::string((char*)&data[8], data_size));
			}
			else {
				msg.set_binary_message(
					concurrency::streams::container_buffer<std::string>(std::move(std::string((char*)&data[8], data_size)))
				);
			}
			FORWARD(WEB_SOCKET_RUNNING_DATA)->internalClient->send(msg).get();
		}
		catch (const std::exception &ex)
		{

		}
	}
}

void ProxyWebSocket::Close() {
	ASSERTN();
	if (FORWARD(WEB_SOCKET_RUNNING_DATA)->internalClient) {
		FORWARD(WEB_SOCKET_RUNNING_DATA)->internalClient->close();
		FORWARD(WEB_SOCKET_RUNNING_DATA)->Release();
		_rawptr = nullptr;
	};
}

bool ProxyWebSocket::IsConnected() {
	ASSERTQ(false);
	return FORWARD(WEB_SOCKET_RUNNING_DATA)->isConnected;
}

bool ProxyWebSocket::IsValid() {
	return _rawptr != nullptr;
}