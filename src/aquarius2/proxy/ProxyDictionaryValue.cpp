#include "ProxyDictionaryValue.h"
#include "ProxyValue.h"
#include "ProxyListValue.h"
#include "include/cef_values.h"
#include <atlconv.h>
#include "../def/internalDef.h"

AQUA_PROXY_AUTO_CONSTRUCTOR(ProxyDictionaryValue,CefDictionaryValue);

///
// Returns true if this object is valid. This object may become invalid if
// the underlying data is owned by another object (e.g. list or dictionary)
// and that other object is then modified or destroyed. Do not call any other
// methods if this method returns false.
///
/*--cef()--*/
bool ProxyDictionaryValue::IsValid(){
	ASSERTQ(false);
	return FORWARD(CefDictionaryValue)->IsValid();
}

///
// Returns true if this object is currently owned by another object.
///
/*--cef()--*/
bool ProxyDictionaryValue::IsOwned(){
	ASSERTQ(false);
	return FORWARD(CefDictionaryValue)->IsOwned();
}

///
// Returns true if the values of this object are read-only. Some APIs may
// expose read-only objects.
///
/*--cef()--*/
bool ProxyDictionaryValue::IsReadOnly(){
	ASSERTQ(false);
	return FORWARD(CefDictionaryValue)->IsReadOnly();
}

///
// Returns true if this object and |that| object have the same underlying
// data. If true modifications to this object will also affect |that| object
// and vice-versa.
///
/*--cef()--*/
bool ProxyDictionaryValue::IsSame(shrewd_ptr<ProxyDictionaryValue> that){
	ASSERTQ(false);
	if (!that || !ORIGIN(CefDictionaryValue, that)) {
		return false;
	}
	return FORWARD(CefDictionaryValue)->IsSame( ORIGIN(CefDictionaryValue, that) );
}

///
// Returns true if this object and |that| object have an equivalent underlying
// value but are not necessarily the same object.
///
/*--cef()--*/
bool ProxyDictionaryValue::IsEqual(shrewd_ptr<ProxyDictionaryValue> that){
	ASSERTQ(false);
	if (!that || !ORIGIN(CefDictionaryValue, that)) {
		return false;
	}
	return FORWARD(CefDictionaryValue)->IsSame(ORIGIN(CefDictionaryValue, that));
}

///
// Returns a writable copy of this object. If |exclude_empty_children| is true
// any empty dictionaries or lists will be excluded from the copy.
///
/*--cef()--*/
shrewd_ptr<ProxyDictionaryValue> ProxyDictionaryValue::Copy(bool exclude_empty_children){
	ASSERTQ(NULL);
	CefRefPtr<CefDictionaryValue> dictionary = FORWARD(CefDictionaryValue)->Copy(exclude_empty_children);
	if (!dictionary) {
		return NULL;
	}
	return new ProxyDictionaryValue(dictionary);
}

///
// Returns the number of values.
///
/*--cef()--*/
size_t ProxyDictionaryValue::GetSize(){
	ASSERTQ(0);
	return FORWARD(CefDictionaryValue)->GetSize();
}

///
// Removes all values. Returns true on success.
///
/*--cef()--*/
bool ProxyDictionaryValue::Clear(){
	ASSERTQ(false);
	return FORWARD(CefDictionaryValue)->Clear();
}

///
// Returns true if the current dictionary has a value for the given key.
///
/*--cef()--*/
bool ProxyDictionaryValue::HasKey(const char* key){
	ASSERTQ(false);
	CefString originKey;
	if (key) {
		USES_CONVERSION;
		originKey = A2W(key);
	}
	return FORWARD(CefDictionaryValue)->HasKey(originKey);
}

///
// Reads all keys for this dictionary into the specified vector.
///
/*--cef()--*/
char** ProxyDictionaryValue::GetKeys(){
	ASSERTARRAY(char);
	std::vector<CefString> keyList;
	bool result = FORWARD(CefDictionaryValue)->GetKeys(keyList);
	return CreateEPLStringArray(keyList);
}

///
// Removes the value at the specified key. Returns true is the value was
// removed successfully.
///
/*--cef()--*/
bool ProxyDictionaryValue::Remove(const char* key){
	ASSERTQ(false);
	CefString originKey;
	if (key) {
		USES_CONVERSION;
		originKey = A2W(key);
	}
	return FORWARD(CefDictionaryValue)->Remove(originKey);
}

///
// Returns the value type for the specified key.
///
/*--cef(default_retval=VTYPE_INVALID)--*/
int ProxyDictionaryValue::GetType(const char* key){
	ASSERTQ(0);
	CefString originKey;
	if (key) {
		USES_CONVERSION;
		originKey = A2W(key);
	}
	return FORWARD(CefDictionaryValue)->GetType(originKey);
}

///
// Returns the value at the specified key. For simple types the returned
// value will copy existing data and modifications to the value will not
// modify this object. For complex types (binary, dictionary and list) the
// returned value will reference existing data and modifications to the value
// will modify this object.
///
/*--cef()--*/
shrewd_ptr<ProxyValue> ProxyDictionaryValue::GetValue(const char* key){
	ASSERTQ(NULL);
	CefString originKey;
	if (key) {
		USES_CONVERSION;
		originKey = A2W(key);
	}
	CefRefPtr<CefValue> value = FORWARD(CefDictionaryValue)->GetValue(originKey);
	if (!value) {
		return NULL;
	}
	return new ProxyValue( value );
}

///
// Returns the value at the specified key as type bool.
///
/*--cef()--*/
bool ProxyDictionaryValue::GetBool(const char* key){
	ASSERTQ(false);
	CefString originKey;
	if (key) {
		USES_CONVERSION;
		originKey = A2W(key);
	}
	return FORWARD(CefDictionaryValue)->GetBool(originKey);
}

///
// Returns the value at the specified key as type int.
///
/*--cef()--*/
int ProxyDictionaryValue::GetInt(const char* key){
	ASSERTQ(0);
	CefString originKey;
	if (key) {
		USES_CONVERSION;
		originKey = A2W(key);
	}
	return FORWARD(CefDictionaryValue)->GetInt(originKey);
}

///
// Returns the value at the specified key as type double.
///
/*--cef()--*/
double ProxyDictionaryValue::GetDouble(const char* key){
	ASSERTQ(0.0f);
	CefString originKey;
	if (key) {
		USES_CONVERSION;
		originKey = A2W(key);
	}
	return FORWARD(CefDictionaryValue)->GetDouble(originKey);
}

///
// Returns the value at the specified key as type string.
///
/*--cef()--*/
char* ProxyDictionaryValue::GetString(const char* key){
	ASSERTQ(NULL);
	assert(NewBuffer);
	CefString originKey;
	if (key) {
		USES_CONVERSION;
		originKey = A2W(key);
	}
	CefString string = FORWARD(CefDictionaryValue)->GetString(originKey);
	if (string.empty()) {
		return NULL;
	}
	


	return ToAnsi(string.c_str(),string.length());
}

///
// Returns the value at the specified key as type binary. The returned
// value will reference existing data.
///
/*--cef()--*/
unsigned char* ProxyDictionaryValue::GetBinary(const char* key){
	ASSERTQ(0);
	assert(NewBuffer);
	CefString originKey;
	if (key) {
		USES_CONVERSION;
		originKey = A2W(key);
	}
	CefRefPtr<CefBinaryValue> binary = FORWARD(CefDictionaryValue)->GetBinary(originKey);
	if (!binary) {
		return NULL;
	}
	size_t length = binary->GetSize();
	unsigned char* buffer = (unsigned char*)NewBuffer(length + 8);
	*(int*)&buffer[0] = 1;
	*(int*)&buffer[4] = length;
	binary->GetData(&buffer[8], length, 0);
	return buffer;
}

///
// Returns the value at the specified key as type dictionary. The returned
// value will reference existing data and modifications to the value will
// modify this object.
///
/*--cef()--*/
shrewd_ptr<ProxyDictionaryValue> ProxyDictionaryValue::GetDictionary(const char* key){
	ASSERTQ(NULL);
	CefString originKey;
	if (key) {
		USES_CONVERSION;
		originKey = A2W(key);
	}
	CefRefPtr<CefDictionaryValue> dictionary = FORWARD(CefDictionaryValue)->GetDictionary(originKey);
	if (!dictionary) {
		return NULL;
	}
	return new ProxyDictionaryValue(dictionary);
}

///
// Returns the value at the specified key as type list. The returned value
// will reference existing data and modifications to the value will modify
// this object.
///
/*--cef()--*/
shrewd_ptr<ProxyListValue> ProxyDictionaryValue::GetList(const char* key){
	ASSERTQ(NULL);
	CefString originKey;
	if (key) {
		USES_CONVERSION;
		originKey = A2W(key);
	}
	CefRefPtr<CefListValue> listValue = FORWARD(CefDictionaryValue)->GetList(originKey);
	if (!listValue) {
		return NULL;
	}
	return new ProxyListValue(listValue);
}

///
// Sets the value at the specified key. Returns true if the value was set
// successfully. If |value| represents simple data then the underlying data
// will be copied and modifications to |value| will not modify this object. If
// |value| represents complex data (binary, dictionary or list) then the
// underlying data will be referenced and modifications to |value| will modify
// this object.
///
/*--cef()--*/
bool ProxyDictionaryValue::SetValue(const char* key, shrewd_ptr<ProxyValue> value){
	ASSERTQ(false);
	CefString originKey;
	if (key) {
		USES_CONVERSION;
		originKey = A2W(key);
	}
	if (!value || !ORIGIN(CefValue, value)) {
		return false;
	}
	return FORWARD(CefDictionaryValue)->SetValue(originKey,ORIGIN(CefValue, value));
}

///
// Sets the value at the specified key as type null. Returns true if the
// value was set successfully.
///
/*--cef()--*/
bool ProxyDictionaryValue::SetNull(const char* key){
	ASSERTQ(false);
	CefString originKey;
	if (key) {
		USES_CONVERSION;
		originKey = A2W(key);
	}
	return FORWARD(CefDictionaryValue)->SetNull(originKey);
}

///
// Sets the value at the specified key as type bool. Returns true if the
// value was set successfully.
///
/*--cef()--*/
bool ProxyDictionaryValue::SetBool(const char* key, bool value){
	ASSERTQ(false);
	CefString originKey;
	if (key) {
		USES_CONVERSION;
		originKey = A2W(key);
	}
	return FORWARD(CefDictionaryValue)->SetBool(originKey, value);
}

///
// Sets the value at the specified key as type int. Returns true if the
// value was set successfully.
///
/*--cef()--*/
bool ProxyDictionaryValue::SetInt(const char* key, int value){
	ASSERTQ(false);
	CefString originKey;
	if (key) {
		USES_CONVERSION;
		originKey = A2W(key);
	}
	if (!value) {
		return false;
	}
	return FORWARD(CefDictionaryValue)->SetInt(originKey, value);
}

///
// Sets the value at the specified key as type double. Returns true if the
// value was set successfully.
///
/*--cef()--*/
bool ProxyDictionaryValue::SetDouble(const char* key, double value){
	ASSERTQ(false);
	CefString originKey;
	if (key) {
		USES_CONVERSION;
		originKey = A2W(key);
	}
	return FORWARD(CefDictionaryValue)->SetDouble(originKey, value);
}

///
// Sets the value at the specified key as type string. Returns true if the
// value was set successfully.
///
/*--cef(optional_param=value)--*/
bool ProxyDictionaryValue::SetString(const char* key, const char* value){
	ASSERTQ(false);
	CefString originKey;
	CefString originValue;
	USES_CONVERSION;
	if (key) {
		originKey = A2W(key);
	}
	if (value) {
		wchar_t* buffer = ToUnicode(value, strlen(value));
		originValue = buffer;
		DeleteBuffer(buffer);
	}
	return FORWARD(CefDictionaryValue)->SetString(originKey, originValue);
}

///
// Sets the value at the specified key as type binary. Returns true if the
// value was set successfully. If |value| is currently owned by another object
// then the value will be copied and the |value| reference will not change.
// Otherwise, ownership will be transferred to this object and the |value|
// reference will be invalidated.
///
/*--cef()--*/
bool ProxyDictionaryValue::SetBinary(const char* key, unsigned char* value, size_t length){
	ASSERTQ(false);
	CefString originKey;
	CefRefPtr<CefBinaryValue> binary = NULL;
	if (key) {
		USES_CONVERSION;
		originKey = A2W(key);
	}
	if (value) {
		binary = CefBinaryValue::Create(&value[8], length);
	}
	return FORWARD(CefDictionaryValue)->SetBinary(originKey, binary);
}

///
// Sets the value at the specified key as type dict. Returns true if the
// value was set successfully. If |value| is currently owned by another object
// then the value will be copied and the |value| reference will not change.
// Otherwise, ownership will be transferred to this object and the |value|
// reference will be invalidated.
///
/*--cef()--*/
bool ProxyDictionaryValue::SetDictionary(const char* key,
	shrewd_ptr<ProxyDictionaryValue> value){
	ASSERTQ(false);
	CefString originKey;
	CefRefPtr<CefDictionaryValue> dictionary = NULL;
	if (key) {
		USES_CONVERSION;
		originKey = A2W(key);
	}
	if (value && ORIGIN(CefDictionaryValue, value)) {
		dictionary = ORIGIN(CefDictionaryValue,value);
	}
	return FORWARD(CefDictionaryValue)->SetDictionary(originKey, dictionary);
}

///
// Sets the value at the specified key as type list. Returns true if the
// value was set successfully. If |value| is currently owned by another object
// then the value will be copied and the |value| reference will not change.
// Otherwise, ownership will be transferred to this object and the |value|
// reference will be invalidated.
///
/*--cef()--*/
bool ProxyDictionaryValue::SetList(const char* key, shrewd_ptr<ProxyListValue> value){
	ASSERTQ(false);
	CefString originKey;
	CefRefPtr<CefListValue> listValue = NULL;
	if (key) {
		USES_CONVERSION;
		originKey = A2W(key);
	}
	if (value && ORIGIN(CefListValue, value)) {
		listValue = ORIGIN(CefListValue, value);
	}
	return FORWARD(CefDictionaryValue)->SetList(originKey, listValue);
}
