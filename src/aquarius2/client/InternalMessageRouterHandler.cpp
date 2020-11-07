#include "InternalMessageRouterHandler.h"
#include "InternalClient.h"
#include <atlconv.h>
#include "../def/internalDef.h"


InternalMessageRouterHandler::InternalMessageRouterHandler() {

}

InternalMessageRouterHandler::~InternalMessageRouterHandler() {

}

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
bool InternalMessageRouterHandler::OnQuery(CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefFrame> frame,
    int64 query_id,
    const CefString& request,
    bool persistent,
    CefRefPtr<Callback> callback) {
    bool result = false;
    shrewd_ptr<ProxyClient> client = InternalClient::GetShareInatance()->GetClient();
    if (client) {

        size_t length = request.length();
        USES_CONVERSION;
        const char* buffer = NULL;
        if (length <= 200) {
            buffer = W2A(request.c_str());
        }
        else {
            buffer = ToAnsi(request.c_str(),request.length());
        }

        result = client->OnQuery(
            new ProxyBrowser(browser),
            new ProxyFrame(frame),
            query_id,
            buffer,
            persistent,
            new ProxyQueryCallback(callback)
        );

        if (length > 200) {
            DeleteBuffer((void*)buffer);
        }
    }

    return result;
}

///
// Executed when a query has been canceled either explicitly using the
// JavaScript cancel function or implicitly due to browser destruction,
// navigation or renderer process termination. It will only be called for
// the single handler that returned true from OnQuery for the same
// |query_id|. No references to the associated Callback object should be
// kept after this method is called, nor should any Callback methods be
// executed.
///
void InternalMessageRouterHandler::OnQueryCanceled(CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefFrame> frame,
    int64 query_id) {
    shrewd_ptr<ProxyClient> client = InternalClient::GetShareInatance()->GetClient();
    if (client) {

        client->OnQueryCanceled(
            new ProxyBrowser(browser),
            new ProxyFrame(frame),
            query_id);
    }

    return ;
}