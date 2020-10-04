// TestRenderer.cpp : 定义应用程序的入口点。
//
#include <windows.h>
#include "include/cef_app.h"
#include <sstream>
#include <list>

#define RENDERER_PROCESS_EXTRA_INFO_V8_INTERCEPTOR		(0x8001)
#define RENDERER_PROCESS_EXTRA_INFO_V8_OBJECT			(0x8002)

class InternalProgram : public CefApp,
    public CefRenderProcessHandler
{
public:
    InternalProgram() {}
    ~InternalProgram() {}

public:
	///
	// Return the handler for functionality specific to the render process. This
	// method is called on the render process main thread.
	///
	/*--cef()--*/
	virtual CefRefPtr<CefRenderProcessHandler> GetRenderProcessHandler() override {
		return this;
	}

public:
	virtual void OnRenderThreadCreated(CefRefPtr<CefListValue> extra_info) {



	}


    ///
    // Called when a new message is received from a different process. Return true
    // if the message was handled or false otherwise. Do not keep a reference to
    // or attempt to access the message outside of this callback.
    ///
    /*--cef()--*/
    virtual bool OnProcessMessageReceived(CefRefPtr<CefBrowser> browser,
        CefRefPtr<CefFrame> frame,
        CefProcessId source_process,
        CefRefPtr<CefProcessMessage> message) {
        CefString name = message->GetName();
        if (name == L"IPC_V8_CALCULATE") {
            CefRefPtr<CefListValue> arguments = message->GetArgumentList();
            CalcuateExpression(browser, frame, arguments);
            return true;
        }
        return false;
    }

	virtual void OnContextCreated(CefRefPtr<CefBrowser> browser,
		CefRefPtr<CefFrame> frame,
		CefRefPtr<CefV8Context> context) OVERRIDE {

	}

	virtual void OnContextReleased(CefRefPtr<CefBrowser> browser,
		CefRefPtr<CefFrame> frame,
		CefRefPtr<CefV8Context> context) OVERRIDE {
	}

	virtual void OnBrowserCreated(CefRefPtr<CefBrowser> browser,
		CefRefPtr<CefDictionaryValue> extra_info) {
	}

	virtual void OnBrowserDestroyed(CefRefPtr<CefBrowser> browser) {
	}

public:

	void CalcuateExpression(
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



private:

public:
    IMPLEMENT_REFCOUNTING(InternalProgram);
};


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    CefMainArgs mainArgs(hInstance);
	CefRefPtr<InternalProgram> program = new InternalProgram();
    return CefExecuteProcess(mainArgs, program, nullptr);
}