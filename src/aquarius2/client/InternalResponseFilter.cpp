#include "InternalResponseFilter.h"
#include "InternalClient.h"

#define MEMORY_BLOCK_SIZE		(0x12000)

InternalResponseFilter::InternalResponseFilter(CefRefPtr<CefBrowser> browser, const CefString& url, const CefString& mime_type):
	_browser(browser),_responseURL(url),_responseMimeType(mime_type)
{
	_totalReadBytes = 0;
}

InternalResponseFilter::~InternalResponseFilter() {
	_browser = nullptr;
	_rdbuf.clear();
}

bool InternalResponseFilter::InitFilter() {
	_readEnded = false;
	_rdbuf.clear();

	return true;
}

InternalResponseFilter::FilterStatus InternalResponseFilter::Filter(void* data_in,
	size_t data_in_size,
	size_t& data_in_read,
	void* data_out,
	size_t data_out_size,
	size_t& data_out_written) {

	//TCHAR text[260];

	//OutputDebugString(_responseURL.c_str());
	//wsprintf(text, L"before /// in_size = %d, in_read = %d, out-size=%d, out-written=%d , total=%d",
	//	data_in_size, data_in_read, data_out_size, data_out_written, _totalReadBytes);
	//OutputDebugString(text); 

	if (data_in && data_in_size > 0) {

		_rdbuf.write((char*)data_in, data_in_size);
		_totalReadBytes += data_in_size;
		data_in_read = data_in_size;
	}
	else {
		if (_readEnded == false) {
			CefRefPtr<InternalClient> inclient = InternalClient::GetShareInatance();
			shrewd_ptr<ProxyClient> client = inclient->GetClient();
			if (client) {
				client->OnResourceFilter(new ProxyBrowser(_browser), new ProxyResponseFilter(this));
			}
			_readEnded = true;
		}

		if (_totalReadBytes > 0) {

			//_rdbuf.seekg(_readPointer, std::ios_base::beg);

			if (_totalReadBytes < data_out_size) {
				_rdbuf.read((char*)data_out, _totalReadBytes);
				data_out_written = _totalReadBytes;
				_totalReadBytes = 0;
				return FilterStatus::RESPONSE_FILTER_DONE;
			}
			else {
				_rdbuf.read((char*)data_out, data_out_size);
				data_out_written = data_out_size;
				_totalReadBytes -= data_out_size;
			}


			//MessageBox(NULL, text, NULL, NULL);
			
		}
	}

	//wsprintf(text, L"end /// in_size = %d, in_read = %d, out-size=%d, out-written=%d , total=%d",
	//	data_in_size,data_in_read,data_out_size, data_out_written, _totalReadBytes);
	//OutputDebugString(text);

	return FilterStatus::RESPONSE_FILTER_NEED_MORE_DATA;
}

CefString InternalResponseFilter::GetURL() {
	return _responseURL;
}

CefString InternalResponseFilter::GetMimeType() {
	return _responseMimeType;
}

size_t InternalResponseFilter::GetTotalBytes() {
	return _totalReadBytes;
}

void InternalResponseFilter::GetBuffer(void* outputBuffer, size_t length) {
	if (!outputBuffer || length <= 0 || _totalReadBytes <= 0 || length > _totalReadBytes) {
		return;
	}
	_rdbuf.seekg(0, std::ios_base::beg);
	_rdbuf.read((char*)outputBuffer, length);
	_rdbuf.seekg(0, std::ios_base::beg);
}

void InternalResponseFilter::SetBuffer(void* inputBuffer, size_t length) {
	_rdbuf.clear();
	_rdbuf.seekp(0, std::ios_base::beg);
	_rdbuf.write((char*)inputBuffer, length);
}

