#pragma once
#include "../def/def.h"
#include "ProxyTaskBind.h"

class AQUADLL ProxyTaskRunner : public refcounted {
public:
	ProxyTaskRunner(void* ptr);
	~ProxyTaskRunner();

public:
	bool IsValid();

	bool IsSame(shrewd_ptr<ProxyTaskRunner> runner);

	bool BelongsToCurrentThread();

	bool PostTask(int cb, shrewd_ptr<ProxyTaskBind> binding);

	bool PostDelayedTask(int cb, shrewd_ptr<ProxyTaskBind> binding,int delay_ms);

public:
	PRIME_IMPLEMENT_REFCOUNTING(ProxyTaskRunner);
	AQUA_DECL_PUBLIC_ORIGIN;

private:
	void* _rawptr;
};