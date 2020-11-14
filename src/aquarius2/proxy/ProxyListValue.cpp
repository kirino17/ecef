#include "ProxyListValue.h"
#include "include/cef_values.h"
#include "ProxyValue.h"
#include "ProxyDictionaryValue.h"

AQUA_PROXY_AUTO_CONSTRUCTOR(ProxyListValue, CefListValue);

///
// Returns true if this object is valid. This object may become invalid if
// the underlying data is owned by another object (e.g. list or dictionary)
// and that other object is then modified or destroyed. Do not call any other
// methods if this method returns false.
///
/*--cef()--*/
bool ProxyListValue::IsValid(){
	ASSERTQ(false);
	return FORWARD(CefListValue)->IsValid();
}

///
// Returns true if this object is currently owned by another object.
///
/*--cef()--*/
bool ProxyListValue::IsOwned(){
	ASSERTQ(false);
	return FORWARD(CefListValue)->IsOwned();
}

///
// Returns true if the values of this object are read-only. Some APIs may
// expose read-only objects.
///
/*--cef()--*/
bool ProxyListValue::IsReadOnly(){
	ASSERTQ(false);
	return FORWARD(CefListValue)->IsReadOnly();
}

///
// Returns true if this object and |that| object have the same underlying
// data. If true modifications to this object will also affect |that| object
// and vice-versa.
///
/*--cef()--*/
bool ProxyListValue::IsSame(shrewd_ptr<ProxyListValue> that){
	ASSERTQ(false);
	if (!that || !ORIGIN(CefListValue, that)) {
		return false;
	}
	return FORWARD(CefListValue)->IsSame( ORIGIN(CefListValue, that) );
}

///
// Returns true if this object and |that| object have an equivalent underlying
// value but are not necessarily the same object.
///
/*--cef()--*/
bool ProxyListValue::IsEqual(shrewd_ptr<ProxyListValue> that){
	ASSERTQ(false);
	if (!that || !ORIGIN(CefListValue, that)) {
		return false;
	}
	return FORWARD(CefListValue)->IsEqual(ORIGIN(CefListValue, that));
}

///
// Returns a writable copy of this object.
///
/*--cef()--*/
shrewd_ptr<ProxyListValue> ProxyListValue::Copy(){
	ASSERTQ(NULL);
	return new ProxyListValue(FORWARD(CefListValue)->Copy());
}

///
// Sets the number of values. If the number of values is expanded all
// new value slots will default to type null. Returns true on success.
///
/*--cef()--*/
bool ProxyListValue::SetSize(size_t size){
	ASSERTQ(false);
	return FORWARD(CefListValue)->SetSize(size);
}

///
// Returns the number of values.
///
/*--cef()--*/
size_t ProxyListValue::GetSize(){
	ASSERTQ(0);
	return FORWARD(CefListValue)->GetSize();
}

///
// Removes all values. Returns true on success.
///
/*--cef()--*/
bool ProxyListValue::Clear(){
	ASSERTQ(false);
	return FORWARD(CefListValue)->Clear();
}

///
// Removes the value at the specified index.
///
/*--cef()--*/
bool ProxyListValue::Remove(size_t index){
	ASSERTQ(false);
	return FORWARD(CefListValue)->Remove(index);
}

///
// Returns the value type at the specified index.
///
/*--cef(default_retval=VTYPE_INVALID)--*/
int ProxyListValue::GetType(size_t index){
	ASSERTQ(0);
	return FORWARD(CefListValue)->GetType(index);
}

///
// Returns the value at the specified index. For simple types the returned
// value will copy existing data and modifications to the value will not
// modify this object. For complex types (binary, dictionary and list) the
// returned value will reference existing data and modifications to the value
// will modify this object.
///
/*--cef()--*/
shrewd_ptr<ProxyValue> ProxyListValue::GetValue(size_t index){
	ASSERTQ(NULL);
	CefRefPtr<CefValue> value = FORWARD(CefListValue)->GetValue(index);
	if (!value) {
		return new ProxyValue(value);
	}
	return NULL;
}

///
// Returns the value at the specified index as type bool.
///
/*--cef()--*/
bool ProxyListValue::GetBool(size_t index){
	ASSERTQ(false);
	return FORWARD(CefListValue)->GetBool(index);
}

///
// Returns the value at the specified index as type int.
///
/*--cef()--*/
int ProxyListValue::GetInt(size_t index){
	ASSERTQ(0);
	return FORWARD(CefListValue)->GetInt(index);
}

///
// Returns the value at the specified index as type double.
///
/*--cef()--*/
double ProxyListValue::GetDouble(size_t index){
	ASSERTQ(0.0f);
	return FORWARD(CefListValue)->GetDouble(index);
}

///
// Returns the value at the specified index as type string.
///
/*--cef()--*/
char* ProxyListValue::GetString(size_t index){
	ASSERTQ(NULL);
	assert(NewBuffer);
	CefString string = FORWARD(CefListValue)->GetString(index);
	if (string.empty()) {
		return NULL;
	}
	return ToAnsi(string.c_str(), string.length());
}

///
// Returns the value at the specified index as type binary. The returned
// value will reference existing data.
///
/*--cef()--*/
unsigned char* ProxyListValue::GetBinary(size_t index){
	ASSERTQ(NULL);
	assert(NewBuffer);
	CefRefPtr<CefBinaryValue> binary = FORWARD(CefListValue)->GetBinary(index);
	if (!binary) {
		return NULL;
	}
	size_t length = binary->GetSize();
	unsigned char* buffer = (unsigned char*)NewBuffer(length + 8);
	*(int*)&buffer[0] = 1;
	*(int*)&buffer[4] = length;
	binary->GetData(buffer, length, 0);
	return buffer;
}

///
// Returns the value at the specified index as type dictionary. The returned
// value will reference existing data and modifications to the value will
// modify this object.
///
/*--cef()--*/
shrewd_ptr<ProxyDictionaryValue> ProxyListValue::GetDictionary(size_t index) {
	ASSERTQ(NULL);
	CefRefPtr<CefDictionaryValue> dictionary = FORWARD(CefListValue)->GetDictionary(index);
	if (!dictionary) {
		return NULL;
	}
	return new ProxyDictionaryValue(dictionary);
}

///
// Returns the value at the specified index as type list. The returned
// value will reference existing data and modifications to the value will
// modify this object.
///
/*--cef()--*/
shrewd_ptr<ProxyListValue> ProxyListValue::GetList(size_t index){
	ASSERTQ(NULL);
	CefRefPtr<CefListValue> listValue = FORWARD(CefListValue)->GetList(index);
	if (!listValue) {
		return NULL;
	}
	return new ProxyListValue(listValue);
}

///
// Sets the value at the specified index. Returns true if the value was set
// successfully. If |value| represents simple data then the underlying data
// will be copied and modifications to |value| will not modify this object. If
// |value| represents complex data (binary, dictionary or list) then the
// underlying data will be referenced and modifications to |value| will modify
// this object.
///
/*--cef()--*/
bool ProxyListValue::SetValue(size_t index, shrewd_ptr<ProxyValue> value){
	ASSERTQ(false);
	if (!value || !ORIGIN(CefValue, value)) {
		return false;
	}
	return FORWARD(CefListValue)->SetValue(index, ORIGIN(CefValue,value));
}

///
// Sets the value at the specified index as type null. Returns true if the
// value was set successfully.
///
/*--cef()--*/
bool ProxyListValue::SetNull(size_t index){
	ASSERTQ(false);
	return FORWARD(CefListValue)->SetNull(index);
}

///
// Sets the value at the specified index as type bool. Returns true if the
// value was set successfully.
///
/*--cef()--*/
bool ProxyListValue::SetBool(size_t index, bool value){
	ASSERTQ(false);
	return FORWARD(CefListValue)->SetBool(index,value);
}

///
// Sets the value at the specified index as type int. Returns true if the
// value was set successfully.
///
/*--cef()--*/
bool ProxyListValue::SetInt(size_t index, int value){
	ASSERTQ(false);
	return FORWARD(CefListValue)->SetInt(index, value);
}

///
// Sets the value at the specified index as type double. Returns true if the
// value was set successfully.
///
/*--cef()--*/
bool ProxyListValue::SetDouble(size_t index, double value){
	ASSERTQ(false);
	return FORWARD(CefListValue)->SetDouble(index, value);
}

///
// Sets the value at the specified index as type string. Returns true if the
// value was set successfully.
///
/*--cef(optional_param=value)--*/
bool ProxyListValue::SetString(size_t index, const char* value){
	ASSERTQ(false);
	if (!value) {
		return NULL;
	}
	wchar_t* buffer = ToUnicode(value, strlen(value));
	bool result = FORWARD(CefListValue)->SetString(index, buffer);
	DeleteBuffer(buffer);
	return result;
}

///
// Sets the value at the specified index as type binary. Returns true if the
// value was set successfully. If |value| is currently owned by another object
// then the value will be copied and the |value| reference will not change.
// Otherwise, ownership will be transferred to this object and the |value|
// reference will be invalidated.
///
/*--cef()--*/
bool ProxyListValue::SetBinary(size_t index, unsigned char* value, size_t length){
	ASSERTQ(false);
	if (!value) {
		return NULL;
	}
	return FORWARD(CefListValue)->SetBinary(index, CefBinaryValue::Create(&value[8], length));
}

///
// Sets the value at the specified index as type dict. Returns true if the
// value was set successfully. If |value| is currently owned by another object
// then the value will be copied and the |value| reference will not change.
// Otherwise, ownership will be transferred to this object and the |value|
// reference will be invalidated.
///
/*--cef()--*/
bool ProxyListValue::SetDictionary(size_t index, shrewd_ptr<ProxyDictionaryValue> value) {
	ASSERTQ(false);
	if (!value || !ORIGIN(CefDictionaryValue, value)) {
		return NULL;
	}
	return FORWARD(CefListValue)->SetDictionary(index, ORIGIN(CefDictionaryValue, value));
}

///
// Sets the value at the specified index as type list. Returns true if the
// value was set successfully. If |value| is currently owned by another object
// then the value will be copied and the |value| reference will not change.
// Otherwise, ownership will be transferred to this object and the |value|
// reference will be invalidated.
///
/*--cef()--*/
bool ProxyListValue::SetList(size_t index, shrewd_ptr<ProxyListValue> value){
	ASSERTQ(false);
	if (!value || !ORIGIN(CefListValue, value)) {
		return NULL;
	}
	return FORWARD(CefListValue)->SetList(index, ORIGIN(CefListValue, value));
}