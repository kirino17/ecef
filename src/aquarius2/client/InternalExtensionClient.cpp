#include "InternalExtensionClient.h"
#include "InternalClient.h"
#include <atlconv.h>

InternalExtensionClient::InternalExtensionClient() {

}

InternalExtensionClient::~InternalExtensionClient() {

}

///
// Called if the CefRequestContext::LoadExtension request fails. |result| will
// be the error code.
///
/*--cef()--*/
void InternalExtensionClient::OnExtensionLoadFailed(cef_errorcode_t result) {
    shrewd_ptr<ProxyClient> client = InternalClient::GetShareInatance()->GetClient();
    if (client) {
        client->OnExtensionLoadFailed(result);
    }
}

///
// Called if the CefRequestContext::LoadExtension request succeeds.
// |extension| is the loaded extension.
///
/*--cef()--*/
void InternalExtensionClient::OnExtensionLoaded(CefRefPtr<CefExtension> extension) {
    shrewd_ptr<ProxyClient> client = InternalClient::GetShareInatance()->GetClient();
    if (client) {
        client->OnExtensionLoaded(new ProxyExtension(extension));
    }
}

///
// Called after the CefExtension::Unload request has completed.
///
/*--cef()--*/
void InternalExtensionClient::OnExtensionUnloaded(CefRefPtr<CefExtension> extension) {
    shrewd_ptr<ProxyClient> client = InternalClient::GetShareInatance()->GetClient();
    if (client) {
        client->OnExtensionUnloaded(new ProxyExtension(extension));
    }
}

///
// Called when an extension needs a browser to host a background script
// specified via the "background" manifest key. The browser will have no
// visible window and cannot be displayed. |extension| is the extension that
// is loading the background script. |url| is an internally generated
// reference to an HTML page that will be used to load the background script
// via a <script> src attribute. To allow creation of the browser optionally
// modify |client| and |settings| and return false. To cancel creation of the
// browser (and consequently cancel load of the background script) return
// true. Successful creation will be indicated by a call to
// CefLifeSpanHandler::OnAfterCreated, and CefBrowserHost::IsBackgroundHost
// will return true for the resulting browser. See
// https://developer.chrome.com/extensions/event_pages for more information
// about extension background script usage.
///
/*--cef()--*/
bool InternalExtensionClient::OnBeforeBackgroundBrowser(CefRefPtr<CefExtension> extension,
    const CefString& url,
    CefRefPtr<CefClient>& client,
    CefBrowserSettings& settings) {
    shrewd_ptr<ProxyClient> evt = InternalClient::GetShareInatance()->GetClient();
    bool result = false;
    if (evt) {
        const char* szURL = NULL;
        USES_CONVERSION;
        if (!url.empty()) {
            szURL = W2A(url.c_str());
        }
        result = evt->OnBeforeBackgroundBrowser(new ProxyExtension(extension), szURL);
    }
    if (result == false) {
        client = InternalClient::GetShareInatance();
    }
    return result;
}

///
// Called when an extension API (e.g. chrome.tabs.create) requests creation of
// a new browser. |extension| and |browser| are the source of the API call.
// |active_browser| may optionally be specified via the windowId property or
// returned via the GetActiveBrowser() callback and provides the default
// |client| and |settings| values for the new browser. |index| is the position
// value optionally specified via the index property. |url| is the URL that
// will be loaded in the browser. |active| is true if the new browser should
// be active when opened.  To allow creation of the browser optionally modify
// |windowInfo|, |client| and |settings| and return false. To cancel creation
// of the browser return true. Successful creation will be indicated by a call
// to CefLifeSpanHandler::OnAfterCreated. Any modifications to |windowInfo|
// will be ignored if |active_browser| is wrapped in a CefBrowserView.
///
/*--cef()--*/
bool InternalExtensionClient::OnBeforeBrowser(CefRefPtr<CefExtension> extension,
    CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefBrowser> active_browser,
    int index,
    const CefString& url,
    bool active,
    CefWindowInfo& windowInfo,
    CefRefPtr<CefClient>& client,
    CefBrowserSettings& settings) {
    shrewd_ptr<ProxyClient> evt = InternalClient::GetShareInatance()->GetClient();
    bool result = false;
    if (evt) {
        const char* szURL = NULL;
        USES_CONVERSION;
        if (!url.empty()) {
            szURL = W2A(url.c_str());
        }

        shrewd_ptr<ProxyWindowInfo> info = new ProxyWindowInfo(new CefWindowInfo());

        result = evt->OnBeforeBrowser(new ProxyExtension(extension),
            new ProxyBrowser(browser),
            new ProxyBrowser(active_browser),
            index,szURL,active, info);

        if (result == false) {
            windowInfo = (*(ORIGIN(CefWindowInfo,info)));
        }
    }
    if (result == false) {
        client = InternalClient::GetShareInatance();
    }
    return result;
}

///
// Called when no tabId is specified to an extension API call that accepts a
// tabId parameter (e.g. chrome.tabs.*). |extension| and |browser| are the
// source of the API call. Return the browser that will be acted on by the API
// call or return NULL to act on |browser|. The returned browser must share
// the same CefRequestContext as |browser|. Incognito browsers should not be
// considered unless the source extension has incognito access enabled, in
// which case |include_incognito| will be true.
///
/*--cef()--*/
CefRefPtr<CefBrowser> InternalExtensionClient::GetActiveBrowser(
    CefRefPtr<CefExtension> extension,
    CefRefPtr<CefBrowser> browser,
    bool include_incognito) {
    shrewd_ptr<ProxyClient> evt = InternalClient::GetShareInatance()->GetClient();
    CefRefPtr<CefBrowser> activeBrowser = nullptr;
    if (evt) {
         evt->GetActiveBrowser(
            new ProxyExtension(extension),
            new ProxyBrowser(browser),
            include_incognito,
            new ProxyActiveBrowserCallback(&activeBrowser)
        );
    }
    return activeBrowser;
}

///
// Called when the tabId associated with |target_browser| is specified to an
// extension API call that accepts a tabId parameter (e.g. chrome.tabs.*).
// |extension| and |browser| are the source of the API call. Return true
// to allow access of false to deny access. Access to incognito browsers
// should not be allowed unless the source extension has incognito access
// enabled, in which case |include_incognito| will be true.
///
/*--cef()--*/
bool InternalExtensionClient::CanAccessBrowser(CefRefPtr<CefExtension> extension,
    CefRefPtr<CefBrowser> browser,
    bool include_incognito,
    CefRefPtr<CefBrowser> target_browser) {
    shrewd_ptr<ProxyClient> evt = InternalClient::GetShareInatance()->GetClient();
    bool result = false;
    if (evt) {
        evt->CanAccessBrowser(new ProxyExtension(extension), new ProxyBrowser(browser), include_incognito, new ProxyBrowser(target_browser));
    }
    return result;
}

///
// Called to retrieve an extension resource that would normally be loaded from
// disk (e.g. if a file parameter is specified to chrome.tabs.executeScript).
// |extension| and |browser| are the source of the resource request. |file| is
// the requested relative file path. To handle the resource request return
// true and execute |callback| either synchronously or asynchronously. For the
// default behavior which reads the resource from the extension directory on
// disk return false. Localization substitutions will not be applied to
// resources handled via this method.
///
/*--cef()--*/
bool InternalExtensionClient::GetExtensionResource(
    CefRefPtr<CefExtension> extension,
    CefRefPtr<CefBrowser> browser,
    const CefString& file,
    CefRefPtr<CefGetExtensionResourceCallback> callback){
    shrewd_ptr<ProxyClient> evt = InternalClient::GetShareInatance()->GetClient();
    bool result = false;
    if (evt) {
        const char* szFile = NULL;
        USES_CONVERSION;
        if (!file.empty()) {
            szFile = W2A(file.c_str());
        }
        result = evt->GetExtensionResource(
            new ProxyExtension(extension), 
            new ProxyBrowser(browser), 
            szFile,
            new ProxyGetExtensionResourceCallback(callback));
    }
    return result;
}