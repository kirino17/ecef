#pragma once
#include "include/cef_resource_request_handler.h"
#include <vector>
#include <Windows.h>

struct MEMORY_DATA_BUFFER {
	unsigned char*	pointer;
	size_t	size;
	size_t	offset;

	MEMORY_DATA_BUFFER(size_t length):
		pointer(nullptr),
		size(0),
		offset(0){
		if (length > 0) {
			Initialized(length);
		}
	}

	~MEMORY_DATA_BUFFER() {
		if (pointer) {
			VirtualFree(pointer, 0, MEM_RELEASE);
		}
	}

	//MEMORY_DATA_BUFFER(const MEMORY_DATA_BUFFER&) = delete;
	//MEMORY_DATA_BUFFER(MEMORY_DATA_BUFFER&& t) noexcept {
	//	this->Clear();
	//	this->pointer = t.pointer;
	//	this->offset = t.offset;
	//	this->size = t.size;
	//	
	//	t.pointer = nullptr;
	//	t.size = t.offset = 0;
	//}


	void Initialized(size_t length) {
		this->Clear();
		pointer = (unsigned char*)VirtualAlloc(nullptr, length, MEM_COMMIT, PAGE_READWRITE);
		this->size = length;
		this->offset = 0;
	}

	void Clear() {
		if (pointer) {
			VirtualFree(pointer, 0, MEM_RELEASE);
			this->size = 0;
			this->offset = 0;
		}
	}
};

class InternalResponseFilter : public CefResponseFilter {
public:
	InternalResponseFilter(CefRefPtr<CefBrowser> browser, const CefString& url, const CefString& mime_type);
	~InternalResponseFilter();

public:
	CefString GetURL();

	CefString GetMimeType();

	size_t GetTotalBytes();

	void GetBuffer(void* outputBuffer, size_t length);



protected:
	virtual bool InitFilter() override;
	virtual FilterStatus Filter(void* data_in,
		size_t data_in_size,
		size_t& data_in_read,
		void* data_out,
		size_t data_out_size,
		size_t& data_out_written) override;

public:
	IMPLEMENT_REFCOUNTING(InternalResponseFilter);

private:
	CefString _responseURL;
	CefString _responseMimeType;
	CefRefPtr<CefBrowser> _browser;
	std::vector<MEMORY_DATA_BUFFER> _memoryBuffer;
	bool _readEnded;
};