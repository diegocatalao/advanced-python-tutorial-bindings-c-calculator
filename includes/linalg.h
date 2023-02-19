#ifndef _H_PYCTUTORIAL_PYCALC_BASIC_
#define _H_PYCTUTORIAL_PYCALC_BASIC_
#define PY_SSIZE_T_CLEAN

#include <Python.h>
#include <math.h>

/* Funções do módulo */

/**
 * @brief Calcula o produto interno de um vetor e retorna o resultado.
 *
 * @param self {PyObject} - Objeto de referência
 * @param args {PyObject} - Objeto com os argumentos obrigatórios da função
 * @return PyObject* - Retorna a referência do objeto calculado.
 */
static PyObject *dot(PyObject *self, PyObject *args);

/**
 * @brief Calcula a norma de um vetor e retorna o resultado.
 *
 * @param self {PyObject} - Objeto de referência
 * @param args {PyObject} - Objeto com os argumentos obrigatórios da função
 * @return PyObject* - Retorna a referência do objeto calculado.
 */
static PyObject *norm(PyObject *self, PyObject *args);

/* Definições do módulo */

static PyMethodDef pycalc_linalg_ModuleMethods[] = {
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

static struct PyModuleDef pycalc_Module = {
    .m_base = PyModuleDef_HEAD_INIT,
    .m_name = "pyccalc.linalg",
    .m_doc = "Funções elementares para algebra linear",
    .m_size = -1,
    .m_methods = pycalc_linalg_ModuleMethods,
    .m_slots = NULL,
    .m_traverse = NULL,
    .m_clear = NULL,
    .m_free = NULL,
};

/* Variáveis globais estáticas do módulo */

static PyObject *LinalgError;

#endif