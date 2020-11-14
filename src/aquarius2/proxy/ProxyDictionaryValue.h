#pragma once
#include "../def/def.h"

class ProxyValue;
class ProxyListValue;

class AQUADLL ProxyDictionaryValue : public refcounted {
public:
	ProxyDictionaryValue(void* ptr);
	~ProxyDictionaryValue();

public:
    ///
    // Returns true if this object is valid. This object may become invalid if
    // the underlying data is owned by another object (e.g. list or dictionary)
    // and that other object is then modified or destroyed. Do not call any other
    // methods if this method returns false.
    ///
    /*--cef()--*/
    bool IsValid();

    ///
    // Returns true if this object is currently owned by another object.
    ///
    /*--cef()--*/
    bool IsOwned();

    ///
    // Returns true if the values of this object are read-only. Some APIs may
    // expose read-only objects.
    ///
    /*--cef()--*/
    bool IsReadOnly();

    ///
    // Returns true if this object and |that| object have the same underlying
    // data. If true modifications to this object will also affect |that| object
    // and vice-versa.
    ///
    /*--cef()--*/
    bool IsSame(shrewd_ptr<ProxyDictionaryValue> that);

    ///
    // Returns true if this object and |that| object have an equivalent underlying
    // value but are not necessarily the same object.
    ///
    /*--cef()--*/
    bool IsEqual(shrewd_ptr<ProxyDictionaryValue> that);

    ///
    // Returns a writable copy of this object. If |exclude_empty_children| is true
    // any empty dictionaries or lists will be excluded from the copy.
    ///
    /*--cef()--*/
    shrewd_ptr<ProxyDictionaryValue> Copy(bool exclude_empty_children);

    ///
    // Returns the number of values.
    ///
    /*--cef()--*/
    size_t GetSize();

    ///
    // Removes all values. Returns true on success.
    ///
    /*--cef()--*/
    bool Clear();

    ///
    // Returns true if the current dictionary has a value for the given key.
    ///
    /*--cef()--*/
    bool HasKey(const char* key);

    ///
    // Reads all keys for this dictionary into the specified vector.
    ///
    /*--cef()--*/
    char** GetKeys();

    ///
    // Removes the value at the specified key. Returns true is the value was
    // removed successfully.
    ///
    /*--cef()--*/
    bool Remove(const char* key);

    ///
    // Returns the value type for the specified key.
    ///
    /*--cef(default_retval=VTYPE_INVALID)--*/
    int GetType(const char* key);

    ///
    // Returns the value at the specified key. For simple types the returned
    // value will copy existing data and modifications to the value will not
    // modify this object. For complex types (binary, dictionary and list) the
    // returned value will reference existing data and modifications to the value
    // will modify this object.
    ///
    /*--cef()--*/
    shrewd_ptr<ProxyValue> GetValue(const char* key);

    ///
    // Returns the value at the specified key as type bool.
    ///
    /*--cef()--*/
    bool GetBool(const char* key);

    ///
    // Returns the value at the specified key as type int.
    ///
    /*--cef()--*/
    int GetInt(const char* key);

    ///
    // Returns the value at the specified key as type double.
    ///
    /*--cef()--*/
    double GetDouble(const char* key);

    ///
    // Returns the value at the specified key as type string.
    ///
    /*--cef()--*/
    char* GetString(const char* key);

    ///
    // Returns the value at the specified key as type binary. The returned
    // value will reference existing data.
    ///
    /*--cef()--*/
    unsigned char* GetBinary(const char* key);

    ///
    // Returns the value at the specified key as type dictionary. The returned
    // value will reference existing data and modifications to the value will
    // modify this object.
    ///
    /*--cef()--*/
    shrewd_ptr<ProxyDictionaryValue> GetDictionary(const char* key);

    ///
    // Returns the value at the specified key as type list. The returned value
    // will reference existing data and modifications to the value will modify
    // this object.
    ///
    /*--cef()--*/
    shrewd_ptr<ProxyListValue> GetList(const char* key);

    ///
    // Sets the value at the specified key. Returns true if the value was set
    // successfully. If |value| represents simple data then the underlying data
    // will be copied and modifications to |value| will not modify this object. If
    // |value| represents complex data (binary, dictionary or list) then the
    // underlying data will be referenced and modifications to |value| will modify
    // this object.
    ///
    /*--cef()--*/
    bool SetValue(const char* key, shrewd_ptr<ProxyValue> value);

    ///
    // Sets the value at the specified key as type null. Returns true if the
    // value was set successfully.
    ///
    /*--cef()--*/
    bool SetNull(const char* key);

    ///
    // Sets the value at the specified key as type bool. Returns true if the
    // value was set successfully.
    ///
    /*--cef()--*/
    bool SetBool(const char* key, bool value);

    ///
    // Sets the value at the specified key as type int. Returns true if the
    // value was set successfully.
    ///
    /*--cef()--*/
    bool SetInt(const char* key, int value);

    ///
    // Sets the value at the specified key as type double. Returns true if the
    // value was set successfully.
    ///
    /*--cef()--*/
    bool SetDouble(const char* key, double value);

    ///
    // Sets the value at the specified key as type string. Returns true if the
    // value was set successfully.
    ///
    /*--cef(optional_param=value)--*/
    bool SetString(const char* key, const char* value);

    ///
    // Sets the value at the specified key as type binary. Returns true if the
    // value was set successfully. If |value| is currently owned by another object
    // then the value will be copied and the |value| reference will not change.
    // Otherwise, ownership will be transferred to this object and the |value|
    // reference will be invalidated.
    ///
    /*--cef()--*/
    bool SetBinary(const char* key, unsigned char* value, size_t length);

    ///
    // Sets the value at the specified key as type dict. Returns true if the
    // value was set successfully. If |value| is currently owned by another object
    // then the value will be copied and the |value| reference will not change.
    // Otherwise, ownership will be transferred to this object and the |value|
    // reference will be invalidated.
    ///
    /*--cef()--*/
    bool SetDictionary(const char* key,
        shrewd_ptr<ProxyDictionaryValue> value);

    ///
    // Sets the value at the specified key as type list. Returns true if the
    // value was set successfully. If |value| is currently owned by another object
    // then the value will be copied and the |value| reference will not change.
    // Otherwise, ownership will be transferred to this object and the |value|
    // reference will be invalidated.
    ///
    /*--cef()--*/
    bool SetList(const char* key, shrewd_ptr<ProxyListValue> value);

public:
    PRIME_IMPLEMENT_REFCOUNTING(ProxyDictionaryValue);
    AQUA_DECL_PUBLIC_ORIGIN;

private:
	void* _rawptr;
};