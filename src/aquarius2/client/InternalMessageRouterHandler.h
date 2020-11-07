#pragma once
#include "include/wrapper/cef_message_router.h"

class InternalMessageRouterHandler : public CefMessageRouterBrowserSide::Handler {
public:
	InternalMessageRouterHandler();
	~InternalMessageRouterHandler();

public:
    ///
    // Executed when a new query is received. |query_id| uniquely identifies the
    // query for the life span of the router. Return true to handle the query
    // or false to propagate the query to other registered handlers, if any. If
    // no handlers return true from this method then the query will be
    // automatically canceled with an error code of -1 delivered to the
    // JavaScript onFailure callback. If this method returns true then a
    // Callback method must be executed either in this method or asynchronously
    // to complete the query.
    ///
    virtual bool OnQuery(CefRefPtr<CefBrowser> browser,
        CefRefPtr<CefFrame> frame,
        int64 query_id,
        const CefString& request,
        bool persistent,
        CefRefPtr<Callback> callback) OVERRIDE;

    ///
    // Executed when a query has been canceled either explicitly using the
    // JavaScript cancel function or implicitly due to browser destruction,
    // navigation or renderer process termination. It will only be called for
    // the single handler that returned true from OnQuery for the same
    // |query_id|. No references to the associated Callback object should be
    // kept after this method is called, nor should any Callback methods be
    // executed.
    ///
    virtual void OnQueryCanceled(CefRefPtr<CefBrowser> browser,
        CefRefPtr<CefFrame> frame,
        int64 query_id) OVERRIDE;

};
