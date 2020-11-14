#pragma once
#include "../def/def.h"

class AQUADLL ProxyResponse : public refcounted {
public:
	ProxyResponse(void* ptr = NULL);
	~ProxyResponse();

public:
    // is valid
    bool IsValid();

    ///
    // Returns true if this object is read-only.
    ///
    /*--cef()--*/
     bool IsReadOnly();

    ///
    // Get the response error code. Returns ERR_NONE if there was no error.
    ///
    /*--cef(default_retval=ERR_NONE)--*/
     int GetError();

    ///
    // Set the response error code. This can be used by custom scheme handlers
    // to return errors during initial request processing.
    ///
    /*--cef()--*/
     void SetError(int error);

    ///
    // Get the response status code.
    ///
    /*--cef()--*/
     int GetStatus();

    ///
    // Set the response status code.
    ///
    /*--cef()--*/
     void SetStatus(int status);

    ///
    // Get the response status text.
    ///
    /*--cef()--*/
     char* GetStatusText();

    ///
    // Set the response status text.
    ///
    /*--cef(optional_param=statusText)--*/
     void SetStatusText(const char* statusText);

    ///
    // Get the response mime type.
    ///
    /*--cef()--*/
     char* GetMimeType();

    ///
    // Set the response mime type.
    ///
    /*--cef(optional_param=mimeType)--*/
     void SetMimeType(const char* mimeType);

    ///
    // Get the response charset.
    ///
    /*--cef()--*/
     char* GetCharset();

    ///
    // Set the response charset.
    ///
    /*--cef(optional_param=charset)--*/
     void SetCharset(const char* charset);

    ///
    // Get the value for the specified response header field.
    ///
    /*--cef()--*/
     char* GetHeaderByName(const char* name);

    ///
    // Set the header |name| to |value|. If |overwrite| is true any existing
    // values will be replaced with the new value. If |overwrite| is false any
    // existing values will not be overwritten.
    ///
    /*--cef(optional_param=value)--*/
     void SetHeaderByName(const char* name,
        const char* value,
        bool overwrite);

    ///
    // Get all response header fields.
    ///
    /*--cef()--*/
     char** GetHeaderMap();

    ///
    // Set all response header fields.
    ///
    /*--cef()--*/
     void SetHeaderMap(const char* headerMap);

    ///
    // Get the resolved URL after redirects or changed as a result of HSTS.
    ///
    /*--cef()--*/
     char* GetURL();

    ///
    // Set the resolved URL after redirects or changed as a result of HSTS.
    ///
    /*--cef(optional_param=url)--*/
     void SetURL(const char* url);


public:
    PRIME_IMPLEMENT_REFCOUNTING(ProxyResponse);
    AQUA_DECL_PUBLIC_ORIGIN;

private:
	void* _rawptr;
};