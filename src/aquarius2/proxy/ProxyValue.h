#pragma once
#include "../def/def.h"

class ProxyListValue;
class ProxyDictionaryValue;

class AQUADLL ProxyValue : refcounted {
public:
	ProxyValue(void* ptr);
	~ProxyValue();

public:

	///
	// Creates a new object.
	///
	/*--cef()--*/
	static shrewd_ptr<ProxyValue> Create();

public:
    ///
    // Returns true if the underlying data is valid. This will always be true for
    // simple types. For complex types (binary, dictionary and list) the
    // underlying data may become invalid if owned by another object (e.g. list or
    // dictionary) and that other object is then modified or destroyed. This value
    // object can be re-used by calling Set*() even if the underlying data is
    // invalid.
    ///
    /*--cef()--*/
    bool IsValid();

    ///
    // Returns true if the underlying data is owned by another object.
    ///
    /*--cef()--*/
    bool IsOwned();

    ///
    // Returns true if the underlying data is read-only. Some APIs may expose
    // read-only objects.
    ///
    /*--cef()--*/
    bool IsReadOnly();

    ///
    // Returns true if this object and |that| object have the same underlying
    // data. If true modifications to this object will also affect |that| object
    // and vice-versa.
    ///
    /*--cef()--*/
    bool IsSame(shrewd_ptr<ProxyValue> that);

    ///
    // Returns true if this object and |that| object have an equivalent underlying
    // value but are not necessarily the same object.
    ///
    /*--cef()--*/
    bool IsEqual(shrewd_ptr<ProxyValue> that);

    ///
    // Returns a copy of this object. The underlying data will also be copied.
    ///
    /*--cef()--*/
    shrewd_ptr<ProxyValue> Copy();

    ///
    // Returns the underlying value type.
    ///
    /*--cef(default_retval=VTYPE_INVALID)--*/
    int GetType();

    ///
    // Returns the underlying value as type bool.
    ///
    /*--cef()--*/
    bool GetBool();

    ///
    // Returns the underlying value as type int.
    ///
    /*--cef()--*/
    int GetInt();

    ///
    // Returns the underlying value as type double.
    ///
    /*--cef()--*/
    double GetDouble();

    ///
    // Returns the underlying value as type string.
    ///
    /*--cef()--*/
    char* GetString();

    ///
    // Returns the underlying value as type binary. The returned reference may
    // become invalid if the value is owned by another object or if ownership is
    // transferred to another object in the future. To maintain a reference to
    // the value after assigning ownership to a dictionary or list pass this
    // object to the SetValue() method instead of passing the returned reference
    // to SetBinary().
    ///
    /*--cef()--*/
    unsigned char* GetBinary();

    ///
    // Returns the underlying value as type dictionary. The returned reference may
    // become invalid if the value is owned by another object or if ownership is
    // transferred to another object in the future. To maintain a reference to
    // the value after assigning ownership to a dictionary or list pass this
    // object to the SetValue() method instead of passing the returned reference
    // to SetDictionary().
    ///
    /*--cef()--*/
    shrewd_ptr<ProxyDictionaryValue> GetDictionary();

    ///
    // Returns the underlying value as type list. The returned reference may
    // become invalid if the value is owned by another object or if ownership is
    // transferred to another object in the future. To maintain a reference to
    // the value after assigning ownership to a dictionary or list pass this
    // object to the SetValue() method instead of passing the returned reference
    // to SetList().
    ///
    /*--cef()--*/
    shrewd_ptr<ProxyListValue> GetList();

    ///
    // Sets the underlying value as type null. Returns true if the value was set
    // successfully.
    ///
    /*--cef()--*/
    bool SetNull();

    ///
    // Sets the underlying value as type bool. Returns true if the value was set
    // successfully.
    ///
    /*--cef()--*/
    bool SetBool(bool value);

    ///
    // Sets the underlying value as type int. Returns true if the value was set
    // successfully.
    ///
    /*--cef()--*/
    bool SetInt(int value);

    ///
    // Sets the underlying value as type double. Returns true if the value was set
    // successfully.
    ///
    /*--cef()--*/
    bool SetDouble(double value);

    ///
    // Sets the underlying value as type string. Returns true if the value was set
    // successfully.
    ///
    /*--cef(optional_param=value)--*/
    bool SetString(const char* value);

    ///
    // Sets the underlying value as type binary. Returns true if the value was set
    // successfully. This object keeps a reference to |value| and ownership of the
    // underlying data remains unchanged.
    ///
    /*--cef()--*/
    bool SetBinary(unsigned char* value, size_t length);

    ///
    // Sets the underlying value as type dict. Returns true if the value was set
    // successfully. This object keeps a reference to |value| and ownership of the
    // underlying data remains unchanged.
    ///
    /*--cef()--*/
    bool SetDictionary(shrewd_ptr<ProxyDictionaryValue> value);

    ///
    // Sets the underlying value as type list. Returns true if the value was set
    // successfully. This object keeps a reference to |value| and ownership of the
    // underlying data remains unchanged.
    ///
    /*--cef()--*/
    bool SetList(shrewd_ptr<ProxyListValue> value);
public:
	PRIME_IMPLEMENT_REFCOUNTING(ProxyValue);
	AQUA_DECL_PUBLIC_ORIGIN;

private:
	void* _rawptr;
};