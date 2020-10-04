#include "InternalResponseFilter.h"
#include "InternalClient.h"

InternalResponseFilter::InternalResponseFilter(CefRefPtr<CefBrowser> browser, const CefString& url, const CefString& mime_type):
	_browser(browser),_responseURL(url),_responseMimeType(mime_type)
{

}

InternalResponseFilter::~InternalResponseFilter() {
	_browser = nullptr;
	_memoryBuffer.clear();
}

bool InternalResponseFilter::InitFilter() {
	_readEnded = false;
	return true;
}

InternalResponseFilter::FilterStatus InternalResponseFilter::Filter(void* data_in,
	size_t data_in_size,
	size_t& data_in_read,
	void* data_out,
	size_t data_out_size,
	size_t& data_out_written) {

	if (data_in && data_in_size > 0) {

		if (_memoryBuffer.empty()) {
			_memoryBuffer.emplace_back(0x8000);
		}
		MEMORY_DATA_BUFFER& buffer = _memoryBuffer.back();
		size_t length = buffer.size - buffer.offset;
		if (length >= data_in_size) {
			memcpy(&buffer.pointer[buffer.offset], data_in, data_in_size);
			buffer.offset += data_in_size;
			data_in_read = data_in_size;
		}
		else {
			memcpy(&buffer.pointer[buffer.offset], data_in, length);
			buffer.offset += length;
			data_in_read = length;
			_memoryBuffer.emplace_back(0x8000);
		}
	}
	else {
		if ( _memoryBuffer.empty() ) {
			return FilterStatus::RESPONSE_FILTER_DONE;
		}

		if (_readEnded == false) {
			for (size_t i = 0; i < _memoryBuffer.size(); i++){
				_memoryBuffer[i].size = _memoryBuffer[i].offset;
				_memoryBuffer[i].offset = 0;
			}
			{
				CefRefPtr<InternalClient> inclient = InternalClient::GetShareInatance();
				shrewd_ptr<ProxyClient> client = inclient->GetClient();
				if (client) {
					client->OnResourceFilter(new ProxyBrowser(_browser),new ProxyResponseFilter(this));
				}
			}
			_readEnded = true;
		}
		
		MEMORY_DATA_BUFFER& buffer = _memoryBuffer.front();
		size_t length = buffer.size - buffer.offset;
		if (data_out_size >= length) {
			memcpy(data_out, &buffer.pointer[buffer.offset], length);
			data_out_written = length;
			_memoryBuffer.erase(_memoryBuffer.begin());
		}
		else {
			memcpy(data_out, &buffer.pointer[buffer.offset], data_out_size);
			data_out_written = data_out_size;
			buffer.offset += data_out_size;
		}
	}
	
	//TCHAR text[260];
	//wsprintf(text, L"in-size = %d, in-read=%d, out-size=%d,out-written=%d",
	//	data_in_size, data_in_read, data_out_size, data_out_written);
	////OutputDebugString(text);
	//MessageBox(NULL, text, NULL, NULL);

	return FilterStatus::RESPONSE_FILTER_NEED_MORE_DATA;
}

CefString InternalResponseFilter::GetURL() {
	return _responseURL;
}

CefString InternalResponseFilter::GetMimeType() {
	return _responseMimeType;
}

size_t InternalResponseFilter::GetTotalBytes() {
	size_t length = 0;
	for (size_t i = 0; i < _memoryBuffer.size(); i++)
	{
		length += _memoryBuffer[i].size;
	}
	return length;
}

void InternalResponseFilter::GetBuffer(void* outputBuffer, size_t length) {
	if (!outputBuffer || length <= 0) {
		return;
	}
	int offset = 0;
	unsigned char* out = (unsigned char*)outputBuffer;
	for (size_t i = 0; i < _memoryBuffer.size(); i++)
	{
		if (offset >=length) {
			return;
		}

		MEMORY_DATA_BUFFER& buffer = _memoryBuffer[i];

		size_t num = (length - offset);
		if (num >= buffer.size ) {
			memcpy(&out[offset], buffer.pointer, buffer.size);
			offset += buffer.size;
		}
		else {
			memcpy(&out[offset], buffer.pointer, num);
			offset += num;
		}
	}
}



