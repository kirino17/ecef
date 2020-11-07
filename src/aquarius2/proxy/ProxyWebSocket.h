#pragma once
#include "../def/def.h"

class AQUADLL ProxyWebSocket : public refcounted {
public:
	ProxyWebSocket(void* ptr);
	~ProxyWebSocket();

public:
	void SetProxy(const char* uri);

	void SetUserAgent(const char* user_agent);

	void SetHeaderByName(const char* name, const char* value);

	void AddSubProtocol(const char* name);

	void Connect(const char* uri);

	void Send(int type, const unsigned char* data, size_t data_size);

	void Close();

	bool IsConnected();

	bool IsValid();
public:
	AQUA_DECL_PUBLIC_ORIGIN;
	PRIME_IMPLEMENT_REFCOUNTING(ProxyWebSocket);

private:
	void* _rawptr;
};