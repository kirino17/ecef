#pragma once
#include "../def/def.h"

class AQUADLL ProxyPostDataElement : public refcounted {
public:
	ProxyPostDataElement(void* ptr = NULL);
	~ProxyPostDataElement();

public:
    // is valid
    bool IsValid();

    ///
 // Returns true if this object is read-only.
 ///
 /*--cef()--*/
     bool IsReadOnly();

    ///
    // Remove all contents from the post data element.
    ///
    /*--cef()--*/
     void SetToEmpty();

    ///
    // The post data element will represent a file.
    ///
    /*--cef()--*/
     void SetToFile(const char* fileName);

    ///
    // The post data element will represent bytes.  The bytes passed
    // in will be copied.
    ///
    /*--cef()--*/
     void SetToBytes(size_t size, const unsigned char* bytes);

    ///
    // Return the type of this post data element.
    ///
    /*--cef(default_retval=PDE_TYPE_EMPTY)--*/
     int GetType();

    ///
    // Return the file name.
    ///
    /*--cef()--*/
     char* GetFile();

    ///
    // Return the number of bytes.
    ///
    /*--cef()--*/
     size_t GetBytesCount();

    ///
    // Read up to |size| bytes into |bytes| and return the number of bytes
    // actually read.
    ///
    /*--cef()--*/
     unsigned char* GetBytes();

public:
	PRIME_IMPLEMENT_REFCOUNTING(ProxyPostDataElement);
	AQUA_DECL_PUBLIC_ORIGIN;

private:
	void* _rawptr;
};