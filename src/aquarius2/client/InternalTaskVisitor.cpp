#include "InternalTaskVisitor.h"
#include "InternalClient.h"
#include <Windows.h>

InternalTaskVisitor::InternalTaskVisitor(int taskid,int threadId, CefRefPtr<CefValue> params):
	_taskId(taskid),
	_threadId(threadId),
	_params(params)
{

}

InternalTaskVisitor::~InternalTaskVisitor() {

}

void InternalTaskVisitor::Execute() {
	CefRefPtr<InternalClient> internalClient = InternalClient::GetShareInatance();
	shrewd_ptr<ProxyClient> client = internalClient->GetClient();
	if (client) {
		if (_params) {
			client->OnTaskVisitor(_taskId, _threadId, new ProxyValue(_params));
		}
		else {
			client->OnTaskVisitor(_taskId, _threadId, nullptr);
		}
	}
}