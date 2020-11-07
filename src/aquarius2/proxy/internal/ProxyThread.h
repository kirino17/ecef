#pragma once
#include "../def/def.h"
#include "ProxyTaskRunner.h"

class AQUADLL ProxyThread : public refcounted {
public:
	ProxyThread(void* ptr);
	~ProxyThread();

public:
	bool IsValid();

	shrewd_ptr<ProxyTaskRunner> GetTaskRunner();

	int GetPlatformThreadId();

	void Stop();

	bool IsRunning();

public:
	PRIME_IMPLEMENT_REFCOUNTING(ProxyThread);
	AQUA_DECL_PUBLIC_ORIGIN;

private:
	void* _rawptr;
};