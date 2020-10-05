#include "InternalCookieVisitor.h"
#include "InternalClient.h"

InternalCookieVisitor::InternalCookieVisitor(bool is_delete):
	_isDelete(is_delete)
{

}
InternalCookieVisitor::~InternalCookieVisitor() {
	if (_isDelete == false) {
		shrewd_ptr<ProxyClient> client = InternalClient::GetShareInatance()->GetClient();
		if (client) {
			client->OnCookieVisitor(nullptr, -1, -1);
		}
	}
}

bool InternalCookieVisitor::Visit(const CefCookie& cookie,
	int count,
	int total,
	bool& deleteCookie) {
	bool result = false;
	if (_isDelete == false) {
		shrewd_ptr<ProxyCookie> temp_cookie = new ProxyCookie(new CefCookie(cookie));
		shrewd_ptr<ProxyClient> client = InternalClient::GetShareInatance()->GetClient();
		if (client) {
			result = client->OnCookieVisitor(temp_cookie, count, total);
		}
	}
	else {
		deleteCookie = true;
		MessageBox(NULL, cookie.name.str, NULL, NULL);
		return true;
	}
	return result;
}