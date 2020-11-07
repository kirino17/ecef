#pragma once
#include "../def/def.h"
#include "ProxyValue.h"

class AQUADLL ProxyWaitableEvent : public refcounted {
public:
	ProxyWaitableEvent(void* ptr);
	~ProxyWaitableEvent();

public:
	bool IsValid();

	void Reset();

	void Signal();

	bool IsSignaled();

	void Wait();

	bool TimedWait(__int64 max_ms);

	void SetUserData( shrewd_ptr<ProxyValue> value );

	shrewd_ptr<ProxyValue> GetUserData();

public:
	AQUA_DECL_PUBLIC_ORIGIN;
	PRIME_IMPLEMENT_REFCOUNTING(ProxyWaitableEvent);

private:
	void* _rawptr;
	void* _userdata;
};