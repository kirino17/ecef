#include "ProxyValue.h"
#include "include/cef_values.h"
#include "ProxyListValue.h"
#include "ProxyDictionaryValue.h"

AQUA_PROXY_AUTO_CONSTRUCTOR(ProxyValue,CefValue);

///
// Creates a new object.
///
/*--cef()--*/
shrewd_ptr<ProxyValue> ProxyValue::Create() {
	return new ProxyValue(CefValue::Create());
}

///
// Returns true if the underlying data is valid. This will always be true for
// simple types. For complex types (binary, dictionary and list) the
// underlying data may become invalid if owned by another object (e.g. list or
// dictionary) and that other object is then modified or destroyed. This value
// object can be re-used by calling Set*() even if the underlying data is
// invalid.
///
/*--cef()--*/
bool ProxyValue::IsValid() {
	ASSERTQ(false);
	return FORWARD(CefValue)->IsValid();
}

///
// Returns true if the underlying data is owned by another object.
///
/*--cef()--*/
bool ProxyValue::IsOwned() {
	ASSERTQ(false);
	return FORWARD(CefValue)->IsOwned();
}

///
// Returns true if the underlying data is read-only. Some APIs may expose
// read-only objects.
///
/*--cef()--*/
bool ProxyValue::IsReadOnly() {
	ASSERTQ(false);
	return FORWARD(CefValue)->IsReadOnly();
}

///
// Returns true if this object and |that| object have the same underlying
// data. If true modifications to this object will also affect |that| object
// and vice-versa.
///
/*--cef()--*/
bool ProxyValue::IsSame(shrewd_ptr<ProxyValue> that) {
	ASSERTQ(false);
	if (!that || !ORIGIN(CefValue, that)) {
		return false;
	}
	return FORWARD(CefValue)->IsSame( ORIGIN(CefValue, that) );
}

///
// Returns true if this object and |that| object have an equivalent underlying
// value but are not necessarily the same object.
///
/*--cef()--*/
bool ProxyValue::IsEqual(shrewd_ptr<ProxyValue> that) {
	ASSERTQ(false);
	if (!that || !ORIGIN(CefValue, that)) {
		return false;
	}
	return FORWARD(CefValue)->IsEqual(ORIGIN(CefValue, that));
}

///
// Returns a copy of this object. The underlying data will also be copied.
///
/*--cef()--*/
shrewd_ptr<ProxyValue> ProxyValue::Copy() {
	ASSERTQ(NULL);
	return new ProxyValue(FORWARD(CefValue)->Copy());
}

///
// Returns the underlying value type.
///
/*--cef(default_retval=VTYPE_INVALID)--*/
int ProxyValue::GetType() {
	ASSERTQ(0);
	return FORWARD(CefValue)->GetType();
}

///
// Returns the underlying value as type bool.
///
/*--cef()--*/
bool ProxyValue::GetBool() {
	ASSERTQ(false);
	return FORWARD(CefValue)->GetBool();
}

///
// Returns the underlying value as type int.
///
/*--cef()--*/
int ProxyValue::GetInt() {
	ASSERTQ(0);
	return FORWARD(CefValue)->GetInt();
}

///
// Returns the underlying value as type double.
///
/*--cef()--*/
double ProxyValue::GetDouble() {
	ASSERTQ(0.0f);
	return FORWARD(CefValue)->GetDouble();
}

///
// Returns the underlying value as type string.
///
/*--cef()--*/
char* ProxyValue::GetString() {
	ASSERTQ(NULL);
	assert(NewBuffer);
	CefString string = FORWARD(CefValue)->GetString();
	if (string.length() <= 0) {
		return NULL;
	}
	return ToAnsi(string.c_str(), string.length());
}

///
// Returns the underlying value as type binary. The returned reference may
// become invalid if the value is owned by another object or if ownership is
// transferred to another object in the future. To maintain a reference to
// the value after assigning ownership to a dictionary or list pass this
// object to the SetValue() method instead of passing the returned reference
// to SetBinary().
///
/*--cef()--*/
unsigned char* ProxyValue::GetBinary() {
	ASSERTQ(NULL);
	assert(NewBuffer);
	CefRefPtr<CefBinaryValue> binary = FORWARD(CefValue)->GetBinary();
	if (!binary) {
		return NULL;
	}
	size_t length = binary->GetSize();
	unsigned char* buffer =(unsigned char*)NewBuffer(length + 8);
	*(int*)&buffer[0] = 1;
	*(int*)&buffer[4] = length;
	binary->GetData(&buffer[8], length, 0);
	return buffer;
}

///
// Returns the underlying value as type dictionary. The returned reference may
// become invalid if the value is owned by another object or if ownership is
// transferred to another object in the future. To maintain a reference to
// the value after assigning ownership to a dictionary or list pass this
// object to the SetValue() method instead of passing the returned reference
// to SetDictionary().
///
/*--cef()--*/
shrewd_ptr<ProxyDictionaryValue> ProxyValue::GetDictionary() {
	ASSERTQ(NULL);
	CefRefPtr<CefDictionaryValue> dictionary = FORWARD(CefValue)->GetDictionary();
	if (!dictionary) {
		return NULL;
	}
	return new ProxyDictionaryValue(dictionary);
}

///
// Returns the underlying value as type list. The returned reference may
// become invalid if the value is owned by another object or if ownership is
// transferred to another object in the future. To maintain a reference to
// the value after assigning ownership to a dictionary or list pass this
// object to the SetValue() method instead of passing the returned reference
// to SetList().
///
/*--cef()--*/
shrewd_ptr<ProxyListValue> ProxyValue::GetList() {
	ASSERTQ(NULL);
	CefRefPtr<CefListValue> listValue = FORWARD(CefValue)->GetList();
	if (!listValue) {
		return NULL;
	}
	return new ProxyListValue(listValue);
}

///
// Sets the underlying value as type null. Returns true if the value was set
// successfully.
///
/*--cef()--*/
bool ProxyValue::SetNull() {
	ASSERTQ(false);
	return FORWARD(CefValue)->SetNull();
}

///
// Sets the underlying value as type bool. Returns true if the value was set
// successfully.
///
/*--cef()--*/
bool ProxyValue::SetBool(bool value) {
	ASSERTQ(false);
	return FORWARD(CefValue)->SetBool(value);
}

///
// Sets the underlying value as type int. Returns true if the value was set
// successfully.
///
/*--cef()--*/
bool ProxyValue::SetInt(int value) {
	ASSERTQ(false);
	return FORWARD(CefValue)->SetInt(value);
}

///
// Sets the underlying value as type double. Returns true if the value was set
// successfully.
///
/*--cef()--*/
bool ProxyValue::SetDouble(double value) {
	ASSERTQ(false);
	return FORWARD(CefValue)->SetDouble(value);
}

///
// Sets the underlying value as type string. Returns true if the value was set
// successfully.
///
/*--cef(optional_param=value)--*/
bool ProxyValue::SetString(const char* value) {
	ASSERTQ(false);
	CefString string;
	if (value) {
		wchar_t* buffer = ToUnicode(value, strlen(value));
		string = buffer;
		DeleteBuffer(buffer);
	}
	return FORWARD(CefValue)->SetString(string);
}

///
// Sets the underlying value as type binary. Returns true if the value was set
// successfully. This object keeps a reference to |value| and ownership of the
// underlying data remains unchanged.
///
/*--cef()--*/
bool ProxyValue::SetBinary(unsigned char* value, size_t length) {
	ASSERTQ(false);
	if (!value) {
		return false;
	}
	CefRefPtr<CefBinaryValue> binary = CefBinaryValue::Create(&value[8], length);
	return FORWARD(CefValue)->SetBinary(binary);
}

///
// Sets the underlying value as type dict. Returns true if the value was set
// successfully. This object keeps a reference to |value| and ownership of the
// underlying data remains unchanged.
///
/*--cef()--*/
bool ProxyValue::SetDictionary(shrewd_ptr<ProxyDictionaryValue> value) {
	ASSERTQ(false);
	if (!value || !ORIGIN(CefDictionaryValue, value)) {
		return false;
	}
	CefRefPtr<CefDictionaryValue> dictionary = ORIGIN(CefDictionaryValue, value);
	return FORWARD(CefValue)->SetDictionary(dictionary);
}

///
// Sets the underlying value as type list. Returns true if the value was set
// successfully. This object keeps a reference to |value| and ownership of the
// underlying data remains unchanged.
///
/*--cef()--*/
bool ProxyValue::SetList(shrewd_ptr<ProxyListValue> value) {
	ASSERTQ(false);
	if (!value || !ORIGIN(CefListValue, value)) {
		return false;
	}
	return FORWARD(CefValue)->SetList(ORIGIN( CefListValue, value ));
}
