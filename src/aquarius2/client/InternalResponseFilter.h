#pragma once
#include "include/cef_resource_request_handler.h"
#include <vector>
#include <Windows.h>
#include "../def/internalDef.h"
#include <sstream>

class InternalResponseFilter : public CefResponseFilter {
public:
	InternalResponseFilter(CefRefPtr<CefBrowser> browser, const CefString& url, const CefString& mime_type);
	~InternalResponseFilter();

public:
	CefString GetURL();

	CefString GetMimeType();

	size_t GetTotalBytes();

	void GetBuffer(void* outputBuffer, size_t length);

	void SetBuffer(void* inputBuffer, size_t length);

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
	bool _readEnded;
	std::stringstream _rdbuf;
	std::size_t _totalReadBytes;
};