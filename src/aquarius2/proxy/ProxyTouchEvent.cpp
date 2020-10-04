#include "ProxyTouchEvent.h"
#include "include/cef_browser.h"
#include <atlconv.h>

ProxyTouchEvent::ProxyTouchEvent(void* ptr):_rawptr(ptr) {

}

ProxyTouchEvent::~ProxyTouchEvent() {
	if (_rawptr) {
		delete (CefTouchEvent*)_rawptr;
		_rawptr = nullptr;
	}
}

shrewd_ptr<ProxyTouchEvent> ProxyTouchEvent::Create() {
	return new ProxyTouchEvent( new CefTouchEvent );
}

bool ProxyTouchEvent::IsValid() {
	return _rawptr != nullptr;
}

void ProxyTouchEvent::SetId(int id) {
	if(!_rawptr) return; ((CefTouchEvent*)_rawptr)->id = id;
}

void ProxyTouchEvent::SetX(int x) {
	if(!_rawptr) return; ((CefTouchEvent*)_rawptr)->x = x;
}

void ProxyTouchEvent::SetY(int y) {
	if(!_rawptr) return; ((CefTouchEvent*)_rawptr)->y = y;
}

void ProxyTouchEvent::SetRadiusX(int radius_x) {
	if(!_rawptr) return; ((CefTouchEvent*)_rawptr)->radius_x = radius_x;
}

void ProxyTouchEvent::SetRadiusY(int radius_y) {
	if(!_rawptr) return; ((CefTouchEvent*)_rawptr)->radius_y = radius_y;
}

void ProxyTouchEvent::SetRotationAngle(int rotation_angle) {
	if(!_rawptr) return; ((CefTouchEvent*)_rawptr)->rotation_angle = rotation_angle;
}

void ProxyTouchEvent::SetPressure(int pressure) {
	if(!_rawptr) return; ((CefTouchEvent*)_rawptr)->pressure = pressure;
}

void ProxyTouchEvent::SetType(int type) {
	if(!_rawptr) return; ((CefTouchEvent*)_rawptr)->type = (cef_touch_event_type_t)type;
}

void ProxyTouchEvent::SetModifiers(int modifiers) {
	if(!_rawptr) return; ((CefTouchEvent*)_rawptr)->modifiers = modifiers;
}

void ProxyTouchEvent::SetPointerType(int pointer_type) {
	if(!_rawptr) return; ((CefTouchEvent*)_rawptr)->pointer_type = (cef_pointer_type_t)pointer_type;
}
