#include "ProxyPostDataElement.h"
#include "include/cef_request.h"
#include <atlconv.h>

AQUA_PROXY_AUTO_CONSTRUCTOR(ProxyPostDataElement,CefPostDataElement);


bool ProxyPostDataElement::IsValid() {
	return _rawptr != nullptr;
}

///
// Returns true if this object is read-only.
///
/*--cef()--*/
bool ProxyPostDataElement::IsReadOnly() {
	ASSERTQ(false);
	return FORWARD(CefPostDataElement)->IsReadOnly();
}

///
// Remove all contents from the post data element.
///
/*--cef()--*/
void ProxyPostDataElement::SetToEmpty() {
	ASSERTN();
	FORWARD(CefPostDataElement)->SetToEmpty();
}

///
// The post data element will represent a file.
///
/*--cef()--*/
void ProxyPostDataElement::SetToFile(const char* fileName) {
	ASSERTN();
	if (!fileName) {
		return ;
	}
	USES_CONVERSION;
	FORWARD(CefPostDataElement)->SetToFile(A2W(fileName));
}

///
// The post data element will represent bytes.  The bytes passed
// in will be copied.
///
/*--cef()--*/
void ProxyPostDataElement::SetToBytes(size_t size, const unsigned char* bytes) {
	ASSERTN();
	if (size <= 0 || bytes == NULL) {
		SetToEmpty();
		return;
	}
	FORWARD(CefPostDataElement)->SetToBytes(size, &bytes[8]);
}

///
// Return the type of this post data element.
///
/*--cef(default_retval=PDE_TYPE_EMPTY)--*/
int ProxyPostDataElement::GetType() {
	ASSERTQ(0);
	return FORWARD(CefPostDataElement)->GetType();
}

///
// Return the file name.
///
/*--cef()--*/
char* ProxyPostDataElement::GetFile() {
	ASSERTQ(NULL);
	assert(NewBuffer);
	CefString string = FORWARD(CefPostDataElement)->GetFile();
	return ToAnsi(string.c_str(), string.length());
}

///
// Return the number of bytes.
///
/*--cef()--*/
size_t ProxyPostDataElement::GetBytesCount() {
	ASSERTQ(0);
	return FORWARD(CefPostDataElement)->GetBytesCount();
}

///
// Read up to |size| bytes into |bytes| and return the number of bytes
// actually read.
///
/*--cef()--*/
unsigned char* ProxyPostDataElement::GetBytes() {
	ASSERTQ(NULL);
	size_t count = FORWARD(CefPostDataElement)->GetBytesCount();
	unsigned char* buffer = (unsigned char*)NewBuffer(count + 8);
	*((int*)&buffer[0]) = 1;
	*((int*)&buffer[4]) = count;
	FORWARD(CefPostDataElement)->GetBytes(count, &buffer[8]);
	return buffer;
}
