#include "InternalServerClient.h"
#include "InternalClient.h"
#include <atlconv.h>

InternalServerClient::InternalServerClient() {

}

InternalServerClient::~InternalServerClient() {

}

void InternalServerClient::OnServerCreated(CefRefPtr<CefServer> server){
	shrewd_ptr<ProxyClient> client = InternalClient::GetShareInatance()->GetClient();
	if (client) {
		client->OnServerCreated(new ProxyServer(server));
	}
}

void InternalServerClient::OnServerDestroyed(CefRefPtr<CefServer> server){
	shrewd_ptr<ProxyClient> client = InternalClient::GetShareInatance()->GetClient();
	if (client) {
		client->OnServerDestroyed(new ProxyServer(server));
	}
}

void InternalServerClient::OnClientConnected(CefRefPtr<CefServer> server,
	int connection_id){
	shrewd_ptr<ProxyClient> client = InternalClient::GetShareInatance()->GetClient();
	if (client) {
		client->OnClientConnected(new ProxyServer(server), connection_id);
	}
}

void InternalServerClient::OnClientDisconnected(CefRefPtr<CefServer> server,
	int connection_id){
	shrewd_ptr<ProxyClient> client = InternalClient::GetShareInatance()->GetClient();
	if (client) {
		client->OnClientDisconnected(new ProxyServer(server), connection_id);
	}
}

void InternalServerClient::OnHttpRequest(CefRefPtr<CefServer> server,
	int connection_id,
	const CefString& client_address,
	CefRefPtr<CefRequest> request){
	shrewd_ptr<ProxyClient> client = InternalClient::GetShareInatance()->GetClient();
	if (client) {
		USES_CONVERSION;
		client->OnHttpRequest(new ProxyServer(server), connection_id, W2A(client_address.c_str()),new ProxyRequest(request) );
	}
}

void InternalServerClient::OnWebSocketRequest(CefRefPtr<CefServer> server,
	int connection_id,
	const CefString& client_address,
	CefRefPtr<CefRequest> request,
	CefRefPtr<CefCallback> callback){
	shrewd_ptr<ProxyClient> client = InternalClient::GetShareInatance()->GetClient();
	bool result = false;
	if (client) {
		USES_CONVERSION;
		result = client->OnWebSocketRequest(new ProxyServer(server), connection_id, W2A(client_address.c_str()), new ProxyRequest(request));
	}
	if (result) {
		callback->Continue();
	}
	else {
		callback->Cancel();
	}
}

void InternalServerClient::OnWebSocketConnected(CefRefPtr<CefServer> server,
	int connection_id){
	shrewd_ptr<ProxyClient> client = InternalClient::GetShareInatance()->GetClient();
	if (client) {
		client->OnWebSocketConnected(new ProxyServer(server), connection_id);
	}
}

void InternalServerClient::OnWebSocketMessage(CefRefPtr<CefServer> server,
	int connection_id,
	const void* data,
	size_t data_size){
	shrewd_ptr<ProxyClient> client = InternalClient::GetShareInatance()->GetClient();
	if (client) {
		unsigned char* buffer = (unsigned char*)NewBuffer(data_size + 8);
		*((int*)&buffer[0]) = 1;
		*((int*)&buffer[4]) = data_size;
		memcpy(&buffer[8], data, data_size);
		client->OnWebSocketMessage(new ProxyServer(server), connection_id, buffer, data_size);
		DeleteBuffer(buffer);
	}
}