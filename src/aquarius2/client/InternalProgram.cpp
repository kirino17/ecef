#include "InternalProgram.h"
#include "../proxy/ProxyCommandLine.h"
#include <sstream>
#include "include/cef_v8.h"
#include "InternalV8Interceptor.h"
#include "../proxy/ProxyListValue.h"
#include <atlconv.h>

namespace Local {
	CefRefPtr<InternalProgram> shareInstance = nullptr;
}

InternalProgram::InternalProgram(shrewd_ptr<ProxyClient> client):
	_proxyClient(client)
{
	Local::shareInstance = this;
}

InternalProgram::~InternalProgram() {
	_proxyClient = nullptr;
	Local::shareInstance = nullptr;
}

CefRefPtr<InternalProgram> InternalProgram::GetShareInatance() {
	if (!Local::shareInstance) {
		Local::shareInstance = new InternalProgram(NULL);
	}
	return Local::shareInstance;
}

void InternalProgram::OnBeforeCommandLineProcessing(
	const CefString& process_type,
	CefRefPtr<CefCommandLine> command_line) {
	command_line->AppendSwitch(L"--disable-site-isolation-trials");
	const char* processType = NULL;
	USES_CONVERSION;

	if (!process_type.empty()) {
		processType = W2A(process_type.c_str());
	}

	if (_proxyClient) {
		_proxyClient->OnBeforeCommandLineProcessing(
			processType,
			new ProxyCommandLine(command_line)
		);
	}
}

void InternalProgram::OnContextInitialized() {
	if (_proxyClient) {
		_proxyClient->OnContextInitialized();
	}
}

void InternalProgram::OnBeforeChildProcessLaunch(
	CefRefPtr<CefCommandLine> command_line) {
	if (_proxyClient) {
		_proxyClient->OnBeforeChildProcessLaunch( new ProxyCommandLine(command_line) );
	}
}

void InternalProgram::OnRenderProcessThreadCreated(
	CefRefPtr<CefListValue> extra_info) {
	if (_proxyClient) {
		_proxyClient->OnRenderProcessThreadCreated(
			new ProxyListValue(extra_info)
		);
	}
	
}

void InternalProgram::SetClient(shrewd_ptr<ProxyClient> client) {
	_proxyClient = client;
}

shrewd_ptr<ProxyClient> InternalProgram::GetClient(void) {
	return _proxyClient;
}


void InternalProgram::CalcuateExpression(
	CefRefPtr<CefBrowser> browser,
	CefRefPtr<CefFrame> frame,
	CefRefPtr<CefListValue> arguments) {
	CefRefPtr<CefV8Context> context = frame->GetV8Context();
	CefRefPtr<CefV8Value> retval = nullptr;
	CefRefPtr<CefV8Exception> exception = nullptr;
	CefString scriptCode = arguments->GetString(2);
	CefString scriptUrl = arguments->GetString(3);
	int startLine = arguments->GetInt(4);
	context->Enter();
	bool result = context->Eval(scriptCode, scriptUrl, startLine, retval, exception);
	context->Exit();

	CefRefPtr<CefProcessMessage> sendMessage = CefProcessMessage::Create(L"IPC_V8_RESULT");
	CefRefPtr<CefListValue> info = sendMessage->GetArgumentList();
	info->SetSize(4);
	info->SetInt(0, arguments->GetInt(0));
	info->SetInt(1, arguments->GetInt(1));
	info->SetBool(2, result);

	if (result) {
		
		if (retval) {
			CefRefPtr<CefValue> value = CefValue::Create();
			if (retval->IsUndefined() || retval->IsNull()) {
				value->SetNull();
			}
			else if (retval->IsBool()) {
				value->SetBool(retval->GetBoolValue());
			}
			else if (retval->IsInt()) {
				value->SetInt(retval->GetIntValue());
			}
			else if (retval->IsUInt()) {
				value->SetInt(retval->GetUIntValue());
			}
			else if (retval->IsDouble()) {
				value->SetDouble(retval->GetDoubleValue());
			}
			else if (retval->IsString()) {
				value->SetString(retval->GetStringValue());
			}
			else {
				value->SetNull();
			}
			info->SetValue(3, value);
		}
	}
	else {
		std::wstringstream error;
		if (exception) {
			CefString messageText = exception->GetMessage();
			CefString scripeResourceText = exception->GetScriptResourceName();
			if (!messageText.empty()) {
				error << messageText.c_str();
			}
			else {
				error << L"Unknown Error";
			}
			if (!scripeResourceText.empty()) {
				error << L"\t at <" << scripeResourceText.c_str() << ">";
			}
			else {
				error << L"\t at <Unknown>";
			}
			error << L":" << exception->GetLineNumber();
			error << L"/" << exception->GetStartPosition();
			error << L"/" << exception->GetEndPosition();
		}
		std::wstring buffer = error.str();
		info->SetString(3, buffer);
	}

	frame->SendProcessMessage(PID_BROWSER, sendMessage);
}