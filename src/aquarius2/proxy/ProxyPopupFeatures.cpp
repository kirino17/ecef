#include "ProxyPopupFeatures.h"
#include "include/cef_browser.h"
#include <atlconv.h>

ProxyPopupFeatures::ProxyPopupFeatures(void* ptr):_rawptr(ptr) {

}

ProxyPopupFeatures::~ProxyPopupFeatures() {
	if (_rawptr) {
		delete (CefPopupFeatures*)_rawptr;
		_rawptr = nullptr;
	}
}

shrewd_ptr<ProxyPopupFeatures> ProxyPopupFeatures::Create() {
	return new ProxyPopupFeatures( new CefPopupFeatures );
}

bool ProxyPopupFeatures::IsValid() {
	return _rawptr != nullptr;
}


int ProxyPopupFeatures::GetX() {
	if(!_rawptr) return 0; 
	return ((CefPopupFeatures*)_rawptr)->x;
}

int ProxyPopupFeatures::GetXSet() {
	if(!_rawptr) return 0; 
	return ((CefPopupFeatures*)_rawptr)->xSet;
}

int ProxyPopupFeatures::GetY() {
	if(!_rawptr) return 0; 
	return ((CefPopupFeatures*)_rawptr)->y;
}

int ProxyPopupFeatures::GetYSet() {
	if(!_rawptr) return 0; 
	return ((CefPopupFeatures*)_rawptr)->ySet;
}

int ProxyPopupFeatures::GetWidth() {
	if(!_rawptr) return 0; 
	return ((CefPopupFeatures*)_rawptr)->width;
}

int ProxyPopupFeatures::GetWidthSet() {
	if(!_rawptr) return 0;
	return ((CefPopupFeatures*)_rawptr)->widthSet;
}

int ProxyPopupFeatures::GetHeight() {
	if(!_rawptr) return 0; 
	return ((CefPopupFeatures*)_rawptr)->height;
}

int ProxyPopupFeatures::GetHeightSet() {
	if(!_rawptr) return 0; 
	return ((CefPopupFeatures*)_rawptr)->heightSet;
}

int ProxyPopupFeatures::GetMenuBarVisible() {
	if(!_rawptr) return 0; 
	return ((CefPopupFeatures*)_rawptr)->menuBarVisible;
}

int ProxyPopupFeatures::GetStatusBarVisible() {
	if(!_rawptr) return 0;
	return ((CefPopupFeatures*)_rawptr)->statusBarVisible;
}

int ProxyPopupFeatures::GetToolBarVisible() {
	if(!_rawptr) return 0;
	return ((CefPopupFeatures*)_rawptr)->toolBarVisible;
}

int ProxyPopupFeatures::GetScrollbarsVisible() {
	if(!_rawptr) return 0; 
	return ((CefPopupFeatures*)_rawptr)->scrollbarsVisible;
}
