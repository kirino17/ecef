#pragma once
#include "include/cef_client.h"

class InternalDevToolsClient : public CefClient {
public:
	InternalDevToolsClient();
	~InternalDevToolsClient();

public:
	IMPLEMENT_REFCOUNTING(InternalDevToolsClient);
};