#pragma once

/*
 *       desc:		Implement atomic level automatic reference counting tools.
 *		 by:		primewww/heimao
 *		 version:	1.00
 *		 update:	...
*/

#if (defined(WIN32) || defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(__WINDOWS__))
#define OS_WIN96
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef _WINSOCKAPI_
#define _WINSOCKAPI_
#endif
#include <windows.h>
#elif (defined(__linux__) || defined(linux) || defined(__linux) || defined(__gnu_linux__))
#define OS_LINUX
#include <unistd.h>
#elif (define(macintosh) || defined(Macintosh) || (defined(__APPLE__) && defined(__MACH__)))
#define OS_MACOS
#endif

//This macro is used to add a reference counting tool to a subclass.
#ifndef PRIME_IMPLEMENT_REFCOUNTING
#define PRIME_IMPLEMENT_REFCOUNTING(ClassName) \
private: \
    prime::internal::autocounted _ref; \
public: \
    virtual void retain() const { this->_ref.retain(); } \
    virtual bool release() const { if(this->_ref.release()) {delete static_cast<const ClassName*>(this);return true;} else return false;} \
    virtual bool last() const {return this->_ref.last(); } \
	virtual int counted() const {return this->_ref.counted(); }
#endif

namespace prime {
    //Atomic count type
    typedef long Atomic32;

    /*  The base class used to build the reference count,
        all classes that need to use this tool should inherit from it
    */
    class PRIME_DLL refcounted {
    public:
        /*Increase the reference count*/
        virtual void retain() const = 0;

        /*Release a reference count*/
        virtual bool release() const = 0;

        /*Returns true if the current instance object has only one reference*/
        virtual bool last() const = 0;

        /*Get the number of times the current instance is referenced*/
        virtual int counted() const = 0;
    public:
        virtual ~refcounted() {
        }
    };

    namespace internal {

        /*Automatic reference counting tool*/
        class PRIME_DLL autocounted : public prime::refcounted {
        public:
            autocounted() :_refcount(0) {}
            ~autocounted() {}

        public:
            void retain() const {
#if defined(OS_WIN96)
                InterlockedIncrement(&this->_refcount);
#elif defined(OS_LINUX)
                __sync_fetch_and_add(&this->_refcount, 1);
#endif
            }

            bool release() const {
#if defined(OS_WIN96)
                auto count = InterlockedDecrement(&this->_refcount); if (count == 0) return true; else return false;
#elif defined(OS_LINUX)
                auto count = __sync_fetch_and_add(&this->_refcount, -1); if (count == 0) return true; else return false;
#endif
                return false;
            }

            bool last() const {
#if defined(OS_WIN96)
                if (InterlockedExchange(&this->_refcount, this->_refcount) == 1) return true; else return false;
#elif defined(OS_LINUX)
                auto count = __sync_or_and_fetch(&this->_refcount, 0); return count == 1 ? true : false;
#endif
                return false;
            }

            int counted() const {
                return this->_refcount;
            }

        private:
            mutable Atomic32 _refcount;
        };
    }

    /*Automatic reference counting template*/
    template<class T>
    class shrewd_ptr {
    public:
        shrewd_ptr() :_ptr(0) {

        }

        shrewd_ptr(T* p) :_ptr(p) {
            if (_ptr) _ptr->retain();
        }

        shrewd_ptr(const shrewd_ptr<T>& r) :_ptr(r._ptr) {
            if (_ptr) _ptr->retain();
        }

        //template<typename U>
        //shrewd_ptr(const shrewd_ptr<U>& r) : _ptr(r.get()) {
        //    if (_ptr) _ptr->retain();
        //}

        ~shrewd_ptr() {
            if (_ptr) {
                _ptr->release();
                _ptr = NULL;
            }
        }

    public:
        T* get() const { return _ptr; }

        void swap(T** obj) {
            T* p = _ptr;
            _ptr = *obj;
            *obj = p;
        }

        void swap(shrewd_ptr<T>& r) { swap(&r.ptr_); }

    public:
        operator T* () const { return _ptr; }

        T* operator->() const {
            if (!_ptr) {
                throw (const char*)"_ptr == NULL";
            }
            return _ptr;
        }

        shrewd_ptr<T>& operator=(T* p) {
            if (_ptr) {
                _ptr->release();
            }
            _ptr = NULL;
            if (p) {
                _ptr = p;
                _ptr->retain();
            }
            return (*this);
        }

        shrewd_ptr<T>& operator=(const shrewd_ptr<T>& r) {
            if (_ptr) {
                _ptr->release();
            }
            _ptr = NULL;
            if (r.get()) {
                _ptr = r.get();
                _ptr->retain();
            }
            return (*this);

        }

        //template<typename U>
        //shrewd_ptr<T>& operator=(const shrewd_ptr<U>& r) {
        //    return *this = r.get();
        //}
    private:
        T* _ptr;
    };
}
