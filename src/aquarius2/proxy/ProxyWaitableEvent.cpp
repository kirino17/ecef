#include "ProxyWaitableEvent.h"
#include "include/cef_waitable_event.h"

ProxyWaitableEvent::ProxyWaitableEvent(void* ptr):
	_rawptr(ptr),
	_userdata(nullptr)
{
	if (_rawptr) {
		((CefWaitableEvent*)_rawptr)->AddRef();
	}
}

ProxyWaitableEvent::~ProxyWaitableEvent() {
	if (_rawptr) {
		((CefWaitableEvent*)_rawptr)->Release();
		_rawptr = nullptr;
	}
	if (_userdata) {
		((ProxyValue*)_userdata)->release();
		_userdata = nullptr;
	}
}

bool ProxyWaitableEvent::IsValid() {
	return _rawptr != nullptr;
}

void ProxyWaitableEvent::Reset() {
	ASSERTN();
	FORWARD(CefWaitableEvent)->Reset();
}

void ProxyWaitableEvent::Signal() {
	ASSERTN();
	FORWARD(CefWaitableEvent)->Signal();
}

bool ProxyWaitableEvent::IsSignaled() {
	ASSERTQ(false);
	return FORWARD(CefWaitableEvent)->IsSignaled();
}

void ProxyWaitableEvent::Wait() {
	ASSERTN();
	FORWARD(CefWaitableEvent)->Wait();
}

bool ProxyWaitableEvent::TimedWait(__int64 max_ms) {
	ASSERTQ(false);
	return FORWARD(CefWaitableEvent)->TimedWait(max_ms);
}

void ProxyWaitableEvent::SetUserData(shrewd_ptr<ProxyValue> value) {
	if (value) {
		value->retain();
		_userdata = value.get();
	}
}

shrewd_ptr<ProxyValue> ProxyWaitableEvent::GetUserData() {
	return (ProxyValue*)_userdata;
}