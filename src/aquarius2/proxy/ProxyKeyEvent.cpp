#include "ProxyKeyEvent.h"
#include "include/cef_browser.h"
#include <atlconv.h>

ProxyKeyEvent::ProxyKeyEvent(void* ptr):_rawptr(ptr) {

}

ProxyKeyEvent::~ProxyKeyEvent() {
	if (_rawptr) {
		delete (CefKeyEvent*)_rawptr;
		_rawptr = nullptr;
	}
}

shrewd_ptr<ProxyKeyEvent> ProxyKeyEvent::Create() {
	return new ProxyKeyEvent( new CefKeyEvent );
}

bool ProxyKeyEvent::IsValid() {
	return _rawptr != nullptr;
}

void ProxyKeyEvent::SetType(int type) {
	if(!_rawptr) return; ((CefKeyEvent*)_rawptr)->type = (cef_key_event_type_t)type;
}

void ProxyKeyEvent::SetModifiers(int modifiers) {
	if(!_rawptr) return; ((CefKeyEvent*)_rawptr)->modifiers = modifiers;
}

void ProxyKeyEvent::SetWindowsKeyCode(int windows_key_code) {
	if(!_rawptr) return; ((CefKeyEvent*)_rawptr)->windows_key_code = windows_key_code;
}

void ProxyKeyEvent::SetNativeKeyCode(int native_key_code) {
	if(!_rawptr) return; ((CefKeyEvent*)_rawptr)->native_key_code = native_key_code;
}

void ProxyKeyEvent::SetIsSystemKey(int is_system_key) {
	if(!_rawptr) return; ((CefKeyEvent*)_rawptr)->is_system_key = is_system_key;
}

void ProxyKeyEvent::SetCharacter(int character) {
	if(!_rawptr) return; ((CefKeyEvent*)_rawptr)->character = character;
}

void ProxyKeyEvent::SetUnmodifiedCharacter(int unmodified_character) {
	if(!_rawptr) return; ((CefKeyEvent*)_rawptr)->unmodified_character = unmodified_character;
}

void ProxyKeyEvent::SetFocusOnEditableField(int focus_on_editable_field) {
	if(!_rawptr) return; ((CefKeyEvent*)_rawptr)->focus_on_editable_field = focus_on_editable_field;
}
