#include "ProxyPostData.h"
#include "include/cef_request.h"

ProxyPostData::ProxyPostData(void* ptr) :
	_rawptr(ptr), _elementArrays(new CefPostData::ElementVector) {

}

ProxyPostData::~ProxyPostData() {
	if (_rawptr) {
		reinterpret_cast<CefPostData*>(_rawptr)->Release();
	}
	if (_elementArrays) {
		auto arrays = reinterpret_cast<CefPostData::ElementVector*>(_elementArrays);
		arrays->clear();
		delete arrays;
	}
}

///
// Create a new CefPostData object.
///
/*--cef()--*/
shrewd_ptr<ProxyPostData> ProxyPostData::Create() {
	return new ProxyPostData(CefPostData::Create());
}

bool ProxyPostData::IsValid() {
	return _rawptr != nullptr;
}

///
// Returns true if this object is read-only.
///
/*--cef()--*/
bool ProxyPostData::IsReadOnly() {
	ASSERTQ(false);
	return FORWARD(CefPostData)->IsReadOnly();
}

///
// Returns true if the underlying POST data includes elements that are not
// represented by this CefPostData object (for example, multi-part file upload
// data). Modifying CefPostData objects with excluded elements may result in
// the request failing.
///
/*--cef()--*/
bool ProxyPostData::HasExcludedElements() {
	ASSERTQ(false);
	return FORWARD(CefPostData)->HasExcludedElements();
}

///
// Returns the number of existing post data elements.
///
/*--cef()--*/
size_t ProxyPostData::GetElementCount() {
	ASSERTQ(0);
	return FORWARD(CefPostData)->GetElementCount();
}

///
// Retrieve the post data elements.
///
/*--cef(count_func=elements:GetElementCount)--*/
shrewd_ptr<ProxyPostDataElement> ProxyPostData::GetElement(size_t index) {
	ASSERTQ(NULL);
	auto arrays = reinterpret_cast<CefPostData::ElementVector*>(_elementArrays);
	if (index == 0) {
		arrays->clear();
		FORWARD(CefPostData)->GetElements((*arrays));
		if (!arrays->empty()) {
			return new ProxyPostDataElement(arrays->at(0));
		}
	}
	else if(index < arrays->size()) {
		return new ProxyPostDataElement(arrays->at(index));
	}
	return NULL;
}

///
// Remove the specified post data element.  Returns true if the removal
// succeeds.
///
/*--cef()--*/
bool ProxyPostData::RemoveElement(shrewd_ptr<ProxyPostDataElement> element) {
	ASSERTQ(false);
	if (!element || !ORIGIN(CefPostDataElement, element)) {
		return false;
	}
	return FORWARD(CefPostData)->RemoveElement(ORIGIN(CefPostDataElement, element));
}

///
// Add the specified post data element.  Returns true if the add succeeds.
///
/*--cef()--*/
bool ProxyPostData::AddElement(shrewd_ptr<ProxyPostDataElement> element) {
	ASSERTQ(false);
	if (!element || !ORIGIN(CefPostDataElement, element)) {
		return false;
	}
	return FORWARD(CefPostData)->AddElement(ORIGIN(CefPostDataElement, element));
}

///
// Remove all existing post data elements.
///
/*--cef()--*/
void ProxyPostData::RemoveElements() {
	ASSERTN();
	FORWARD(CefPostData)->RemoveElements();
	reinterpret_cast<CefPostData::ElementVector*>(_elementArrays)->clear();
}
