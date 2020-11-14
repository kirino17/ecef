#include "ProxyResponseFilter.h"
#include "../client/InternalResponseFilter.h"

AQUA_PROXY_AUTO_CONSTRUCTOR(ProxyResponseFilter, InternalResponseFilter);

// is valid
bool ProxyResponseFilter::IsValid() {
	return _rawptr != nullptr;
}

// get url
char* ProxyResponseFilter::GetURL() {
	ASSERTQ(NULL);
	assert(NewBuffer);
	CefString string = FORWARD(InternalResponseFilter)->GetURL();
	return ToAnsi(string.c_str(), string.length());
}

// get mime type
char* ProxyResponseFilter::GetMimeType() {
	ASSERTQ(NULL);
	assert(NewBuffer);
	CefString string = FORWARD(InternalResponseFilter)->GetMimeType();
	return ToAnsi(string.c_str(), string.length());
}

// get total bytes
int ProxyResponseFilter::GetTotalBytes() {
	ASSERTQ(0);
	return FORWARD(InternalResponseFilter)->GetTotalBytes();
}

// get buffer
unsigned char* ProxyResponseFilter::GetResource() {
	ASSERTQ(NULL);
	assert(NewBuffer);
	size_t length = FORWARD(InternalResponseFilter)->GetTotalBytes();
	if (length <= 0) {
		return NULL;
	}
	unsigned char* buffer = (unsigned char*)NewBuffer(length + 8);
	*(int*)&buffer[0] = 1;
	*(int*)&buffer[4] = length;
	FORWARD(InternalResponseFilter)->GetBuffer(&buffer[8], length);
	return buffer;
}



// set buffer
void ProxyResponseFilter::SetResource(unsigned char* buffer, int length) {
	ASSERTN();
	if (!buffer || ((size_t)length) <= 0) {
		return ;
	}
	
	FORWARD(InternalResponseFilter)->SetBuffer(&buffer[8],(size_t)length);
}

