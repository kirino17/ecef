#pragma once
#include "../def/def.h"

class ProxyValue;
class ProxyDictionaryValue;


class AQUADLL ProxyListValue : public refcounted {
public:
	ProxyListValue(void* ptr);
	~ProxyListValue();

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
    bool IsSame(shrewd_ptr<ProxyListValue> that);

    ///
    // Returns true if this object and |that| object have an equivalent underlying
    // value but are not necessarily the same object.
    ///
    /*--cef()--*/
    bool IsEqual(shrewd_ptr<ProxyListValue> that);

    ///
    // Returns a writable copy of this object.
    ///
    /*--cef()--*/
    shrewd_ptr<ProxyListValue> Copy();

    ///
    // Sets the number of values. If the number of values is expanded all
    // new value slots will default to type null. Returns true on success.
    ///
    /*--cef()--*/
    bool SetSize(size_t size);

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
    // Removes the value at the specified index.
    ///
    /*--cef()--*/
    bool Remove(size_t index);

    ///
    // Returns the value type at the specified index.
    ///
    /*--cef(default_retval=VTYPE_INVALID)--*/
    int GetType(size_t index);

    ///
    // Returns the value at the specified index. For simple types the returned
    // value will copy existing data and modifications to the value will not
    // modify this object. For complex types (binary, dictionary and list) the
    // returned value will reference existing data and modifications to the value
    // will modify this object.
    ///
    /*--cef()--*/
    shrewd_ptr<ProxyValue> GetValue(size_t index);

    ///
    // Returns the value at the specified index as type bool.
    ///
    /*--cef()--*/
    bool GetBool(size_t index);

    ///
    // Returns the value at the specified index as type int.
    ///
    /*--cef()--*/
    int GetInt(size_t index);

    ///
    // Returns the value at the specified index as type double.
    ///
    /*--cef()--*/
    double GetDouble(size_t index);

    ///
    // Returns the value at the specified index as type string.
    ///
    /*--cef()--*/
    char* GetString(size_t index);

    ///
    // Returns the value at the specified index as type binary. The returned
    // value will reference existing data.
    ///
    /*--cef()--*/
    unsigned char* GetBinary(size_t index);

    ///
    // Returns the value at the specified index as type dictionary. The returned
    // value will reference existing data and modifications to the value will
    // modify this object.
    ///
    /*--cef()--*/
    shrewd_ptr<ProxyDictionaryValue> GetDictionary(size_t index);

    ///
    // Returns the value at the specified index as type list. The returned
    // value will reference existing data and modifications to the value will
    // modify this object.
    ///
    /*--cef()--*/
    shrewd_ptr<ProxyListValue> GetList(size_t index);

    ///
    // Sets the value at the specified index. Returns true if the value was set
    // successfully. If |value| represents simple data then the underlying data
    // will be copied and modifications to |value| will not modify this object. If
    // |value| represents complex data (binary, dictionary or list) then the
    // underlying data will be referenced and modifications to |value| will modify
    // this object.
    ///
    /*--cef()--*/
    bool SetValue(size_t index, shrewd_ptr<ProxyValue> value);

    ///
    // Sets the value at the specified index as type null. Returns true if the
    // value was set successfully.
    ///
    /*--cef()--*/
    bool SetNull(size_t index);

    ///
    // Sets the value at the specified index as type bool. Returns true if the
    // value was set successfully.
    ///
    /*--cef()--*/
    bool SetBool(size_t index, bool value);

    ///
    // Sets the value at the specified index as type int. Returns true if the
    // value was set successfully.
    ///
    /*--cef()--*/
    bool SetInt(size_t index, int value);

    ///
    // Sets the value at the specified index as type double. Returns true if the
    // value was set successfully.
    ///
    /*--cef()--*/
    bool SetDouble(size_t index, double value);

    ///
    // Sets the value at the specified index as type string. Returns true if the
    // value was set successfully.
    ///
    /*--cef(optional_param=value)--*/
    bool SetString(size_t index, const char* value);

    ///
    // Sets the value at the specified index as type binary. Returns true if the
    // value was set successfully. If |value| is currently owned by another object
    // then the value will be copied and the |value| reference will not change.
    // Otherwise, ownership will be transferred to this object and the |value|
    // reference will be invalidated.
    ///
    /*--cef()--*/
    bool SetBinary(size_t index, unsigned char* value, size_t length);

    ///
    // Sets the value at the specified index as type dict. Returns true if the
    // value was set successfully. If |value| is currently owned by another object
    // then the value will be copied and the |value| reference will not change.
    // Otherwise, ownership will be transferred to this object and the |value|
    // reference will be invalidated.
    ///
    /*--cef()--*/
    bool SetDictionary(size_t index, shrewd_ptr<ProxyDictionaryValue> value);

    ///
    // Sets the value at the specified index as type list. Returns true if the
    // value was set successfully. If |value| is currently owned by another object
    // then the value will be copied and the |value| reference will not change.
    // Otherwise, ownership will be transferred to this object and the |value|
    // reference will be invalidated.
    ///
    /*--cef()--*/
    bool SetList(size_t index, shrewd_ptr<ProxyListValue> value);

public:
	PRIME_IMPLEMENT_REFCOUNTING(ProxyListValue);
	AQUA_DECL_PUBLIC_ORIGIN;

private:
	void* _rawptr;
};