#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <stdio.h>

static unsigned long long timestamp() {
    unsigned long long ts;
    asm volatile (  // volatile to prevent compiler from optimizing out
        "rdtsc;"
        "shl $32, %%rdx;"
        "or %%rdx, %%rax;"
        : "=a" (ts)
    ); 
    return ts;
}

static PyObject* timestamp_wrapper(PyObject* self, PyObject* args) {
    unsigned long long start = timestamp();
    unsigned long long overhead = timestamp() - start;
    
    return Py_BuildValue("K", timestamp());
}

static PyMethodDef methods[] = {
    {"timestamp", timestamp_wrapper, METH_NOARGS, "Get the hardware timestamp"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "timestamp",
    NULL,
    -1,
    methods
};

PyMODINIT_FUNC PyInit_timestamp(void) {
    return PyModule_Create(&module);
}