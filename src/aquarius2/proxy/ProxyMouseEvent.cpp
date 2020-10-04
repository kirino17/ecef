#include "ProxyMouseEvent.h"
#include "include/cef_browser.h"
#include <atlconv.h>

ProxyMouseEvent::ProxyMouseEvent(void* ptr): _rawptr(ptr) {

}

ProxyMouseEvent::~ProxyMouseEvent() {
	if (_rawptr) {
		delete (CefMouseEvent*)_rawptr;
		_rawptr = nullptr;
	}
}

shrewd_ptr<ProxyMouseEvent> ProxyMouseEvent::Create() {
	return new ProxyMouseEvent( new CefMouseEvent );
}

bool ProxyMouseEvent::IsValid() {
	return _rawptr != nullptr;
}

void ProxyMouseEvent::SetX(int x) {
	if(!_rawptr) return; ((CefMouseEvent*)_rawptr)->x = x;
}

void ProxyMouseEvent::SetY(int y) {
	if(!_rawptr) return; ((CefMouseEvent*)_rawptr)->y = y;
}

void ProxyMouseEvent::SetModifiers(int modifiers) {
	if(!_rawptr) return; ((CefMouseEvent*)_rawptr)->modifiers = modifiers;
}
