#include "ProxyServer.h"
#include "include/cef_server.h"
#include <atlconv.h>
#include "include/cef_values.h"
#include "../client/InternalServerTask.h"
#include "../def/internalDef.h"

AQUA_PROXY_AUTO_CONSTRUCTOR(ProxyServer, CefServer);

void ProxyServer::Shutdown(){
	ASSERTN();
	FORWARD(CefServer)->Shutdown();
}

bool ProxyServer::IsRunning(){
	ASSERTQ(false);
	bool result = false;
	CefRefPtr<CefTaskRunner> runner = CefTaskRunner::GetForCurrentThread();
	CefRefPtr<CefTaskRunner> serverRunnter = FORWARD(CefServer)->GetTaskRunner();
	if (runner && runner->IsSame(serverRunnter)) {
		result = FORWARD(CefServer)->IsRunning();
	}
	else {
		CefRefPtr<InternalServerTask> task = new InternalServerTask();
		CefRefPtr<CefWaitableEvent> wait = task->Run(serverRunnter, [this,&result]() {
			result = FORWARD(CefServer)->IsRunning();
		});
		WaitAwaking(wait);
	}
	return result;
}

char* ProxyServer::GetAddress(){
	ASSERTQ(NULL);
	char* result = NULL;
	CefString string = FORWARD(CefServer)->GetAddress();
	result = ToAnsi(string.c_str(), string.length());
	return result;
}

bool ProxyServer::HasConnection(){
	ASSERTQ(false);
	bool result = false;
	CefRefPtr<CefTaskRunner> runner = CefTaskRunner::GetForCurrentThread();
	CefRefPtr<CefTaskRunner> serverRunnter = FORWARD(CefServer)->GetTaskRunner();
	if (runner && runner->IsSame(serverRunnter)) {
		result = FORWARD(CefServer)->HasConnection();
	}
	else {
		CefRefPtr<InternalServerTask> task = new InternalServerTask();
		CefRefPtr<CefWaitableEvent> wait = task->Run(serverRunnter, [this, &result]() {
			result = FORWARD(CefServer)->HasConnection();
			});
		WaitAwaking(wait);
	}
	return result;
}

bool ProxyServer::IsValidConnection(int connection_id){
	bool result = false;
	CefRefPtr<CefTaskRunner> runner = CefTaskRunner::GetForCurrentThread();
	CefRefPtr<CefTaskRunner> serverRunnter = FORWARD(CefServer)->GetTaskRunner();
	if (runner && runner->IsSame(serverRunnter)) {
		result = FORWARD(CefServer)->IsValidConnection(connection_id);
	}
	else {
		CefRefPtr<InternalServerTask> task = new InternalServerTask();
		CefRefPtr<CefWaitableEvent> wait = task->Run(serverRunnter, [this, &result, connection_id]() {
			result = FORWARD(CefServer)->IsValidConnection(connection_id);
		});
		WaitAwaking(wait);
	}
	return result;
}

void ProxyServer::SendHttp200Response(int connection_id,
	const char* content_type,
	const unsigned char* data,
	size_t data_size){
	ASSERTN();
	if (data && data_size > 0) {
		FORWARD(CefServer)->SendHttp200Response(connection_id, content_type, &data[8], data_size);
	}
	else {
		FORWARD(CefServer)->SendHttp200Response(connection_id, content_type, nullptr, 0);
	}
}

void ProxyServer::SendHttp404Response(int connection_id){
	ASSERTN();
	return FORWARD(CefServer)->SendHttp404Response(connection_id);
}

void ProxyServer::SendHttp500Response(int connection_id,
	const char* error_message){
	ASSERTN();
	USES_CONVERSION;
	if (error_message) {
		FORWARD(CefServer)->SendHttp500Response(connection_id, A2W(error_message));
	}
}

void ProxyServer::SendHttpResponse(int connection_id,
	int response_code,
	const char* content_type,
	__int64 content_length,
	const char* extra_headers){
	ASSERTN();
	USES_CONVERSION;
	CefRefPtr<CefDictionaryValue> values = nullptr;
	CefServer::HeaderMap headers;

	if (extra_headers) {
		std::vector<std::wstring> stringArrays;
		int count = SplitString(extra_headers, "\r\n", stringArrays);
		std::wstring key, value;
		for (size_t i = 0; i < count; i++)
		{
			const wchar_t* buffer = stringArrays[i].c_str();
			std::size_t end = stringArrays[i].find(':');
			if (end != std::wstring::npos) {
				key.assign(buffer, end);
				value.assign(&buffer[end + 1], stringArrays[i].length() - end - 1);
				headers.insert(std::make_pair(key, value));
			}
		}
	}
	FORWARD(CefServer)->SendHttpResponse(connection_id, response_code,content_type, content_length, headers);
}

void ProxyServer::SendRawData(int connection_id,
	const unsigned char* data,
	size_t data_size){
	ASSERTN();
	if (data && data_size > 0) {
		FORWARD(CefServer)->SendRawData(connection_id, &data[8], data_size);
	}
	else {
		FORWARD(CefServer)->SendRawData(connection_id, nullptr, 0);
	}
}

void ProxyServer::CloseConnection(int connection_id){
	ASSERTN();
	FORWARD(CefServer)->CloseConnection(connection_id);
}

void ProxyServer::SendWebSocketMessage(int connection_id,
	const unsigned char* data,
	size_t data_size){
	ASSERTN();
	if (data && data_size > 0) {
		FORWARD(CefServer)->SendWebSocketMessage(connection_id, &data[8], data_size);
	}
	else {
		FORWARD(CefServer)->SendWebSocketMessage(connection_id, nullptr, 0);
	}
}