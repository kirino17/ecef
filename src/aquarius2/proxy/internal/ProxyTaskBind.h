#pragma once
#include "../def/def.h"

class AQUADLL ProxyTaskBind : public refcounted {
public:
	ProxyTaskBind(void* ptr);
	~ProxyTaskBind();

public:
	int GetData(int index);

public:
	PRIME_IMPLEMENT_REFCOUNTING(ProxyTaskBind);
	AQUA_DECL_PUBLIC_ORIGIN;

private:
	void* _rawptr;
};