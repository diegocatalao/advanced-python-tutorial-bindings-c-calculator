#ifndef _H_PYCTUTORIAL_CALCULATOR_BASIC_
#define _H_PYCTUTORIAL_CALCULATOR_BASIC_
#define PY_SSIZE_T_CLEAN

#include <math.h>
#include <python3.8/Python.h>

/* Funções do módulo */

static PyObject *dot(PyObject *self, PyObject *args);

static PyObject *norm(PyObject *self, PyObject *args);

/* Definições do módulo */

static PyMethodDef calculator_linalg_ModuleMethods[] = {
    {
        .ml_name = "dot",
        .ml_meth = (PyCFunction)dot,
        .ml_flags = METH_VARARGS,
        .ml_doc = "Simple vector dot function",
    },
    {
        .ml_name = "norm",
        .ml_meth = (PyCFunction)norm,
        .ml_flags = METH_VARARGS,
        .ml_doc = "Simple vector norm function",
    },
    {NULL, NULL, 0, NULL},
};

/* Inicialização do módulo */

static struct PyModuleDef calculator_Module = {
    .m_base = PyModuleDef_HEAD_INIT,
    .m_name = "calculator.linalg",
    .m_doc = "Funções elementares para algebra linear",
    .m_size = -1,
    .m_methods = calculator_linalg_ModuleMethods,
    .m_slots = NULL,
    .m_traverse = NULL,
    .m_clear = NULL,
    .m_free = NULL,
};

/* Variáveis globais estáticas do módulo */

static PyObject *LinalgError;

#endif