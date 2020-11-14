#pragma once
#include "../def/def.h"
#include "ProxyDictionaryValue.h"

class AQUADLL ProxyServer : public refcounted {
public:
	ProxyServer(void* ptr);
	~ProxyServer();

public:

	void Shutdown();

	bool IsRunning();

	char* GetAddress();

	bool HasConnection();

	bool IsValidConnection(int connection_id);

	void SendHttp200Response(int connection_id,
		const char* content_type,
		const unsigned char* data,
		size_t data_size);
	void SendHttp404Response(int connection_id);

	void SendHttp500Response(int connection_id,
		const char* error_message);

	void SendHttpResponse(int connection_id,
		int response_code,
		const char* content_type,
		__int64 content_length,
		const char* extra_headers);

	void SendRawData(int connection_id,
		const unsigned char* data,
		size_t data_size);

	void CloseConnection(int connection_id);

	void SendWebSocketMessage(int connection_id,
		const unsigned char* data,
		size_t data_size);

public:
	AQUA_DECL_PUBLIC_ORIGIN;
	PRIME_IMPLEMENT_REFCOUNTING(ProxyServer);

private:
	void* _rawptr;
};