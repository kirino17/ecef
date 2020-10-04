#pragma once
#include "../def/def.h"
#include "ProxyPostDataElement.h"

class AQUADLL ProxyPostData : public refcounted {
public:
	ProxyPostData(void* ptr = NULL);
	~ProxyPostData();

public:
	///
	// Create a new CefPostData object.
	///
	/*--cef()--*/
	static shrewd_ptr<ProxyPostData> Create();

public:
    // is valid
    bool IsValid();

    ///
  // Returns true if this object is read-only.
  ///
  /*--cef()--*/
     bool IsReadOnly();

    ///
    // Returns true if the underlying POST data includes elements that are not
    // represented by this CefPostData object (for example, multi-part file upload
    // data). Modifying CefPostData objects with excluded elements may result in
    // the request failing.
    ///
    /*--cef()--*/
     bool HasExcludedElements();

    ///
    // Returns the number of existing post data elements.
    ///
    /*--cef()--*/
     size_t GetElementCount();

    ///
    // Retrieve the post data elements.
    ///
    /*--cef(count_func=elements:GetElementCount)--*/
     shrewd_ptr<ProxyPostDataElement> GetElement(size_t index);

    ///
    // Remove the specified post data element.  Returns true if the removal
    // succeeds.
    ///
    /*--cef()--*/
     bool RemoveElement(shrewd_ptr<ProxyPostDataElement> element);

    ///
    // Add the specified post data element.  Returns true if the add succeeds.
    ///
    /*--cef()--*/
     bool AddElement(shrewd_ptr<ProxyPostDataElement> element);

    ///
    // Remove all existing post data elements.
    ///
    /*--cef()--*/
     void RemoveElements();

public:
	PRIME_IMPLEMENT_REFCOUNTING(ProxyPostData);
	AQUA_DECL_PUBLIC_ORIGIN;

private:
	void* _rawptr;
    void* _elementArrays;
};