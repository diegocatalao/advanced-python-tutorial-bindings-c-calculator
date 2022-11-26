#include "linalg.h"

static PyObject *dot(PyObject *self, PyObject *args) {
  PyObject *pyobject_first_list;
  PyObject *pyobject_second_list;

  PyObject *pyobject_first_list_it;
  PyObject *pyobject_second_list_it;

  Py_ssize_t lists_size_st;

  float dot_product = 0;
  PyObject *pyobject_dot_product;

  if (!PyArg_ParseTuple(args, "OO", &pyobject_first_list,
                        &pyobject_second_list)) {
    PyErr_SetString(PyExc_TypeError, "parameter must be a list.");
    return NULL;
  }

  if (PyList_Size(pyobject_first_list) != PyList_Size(pyobject_second_list)) {
    PyErr_SetString(LinalgError, "the lists must be equal in size");
    return NULL;
  }

  if ((PyList_Size(pyobject_first_list) == 0) ||
      (PyList_Size(pyobject_second_list) == 0)) {
    PyErr_SetString(LinalgError, "list must be greater than zero");
    return NULL;
  }

  lists_size_st = PyList_Size(pyobject_first_list);

  for (int i = 0; i < lists_size_st; i++) {
    pyobject_first_list_it = PyList_GetItem(pyobject_first_list, i);
    pyobject_second_list_it = PyList_GetItem(pyobject_second_list, i);

    if ((!PyNumber_Check(pyobject_first_list_it)) ||
        (!PyNumber_Check(pyobject_second_list_it))) {
      PyErr_SetString(LinalgError, "impossible to operate between non-numbers");
      Py_DECREF(pyobject_first_list_it);
      Py_DECREF(pyobject_second_list_it);
      return NULL;
    }

    dot_product += PyFloat_AsDouble(pyobject_first_list_it) *
                   PyFloat_AsDouble(pyobject_second_list_it);
  }

  pyobject_dot_product = Py_BuildValue("f", dot_product);

  /* */
  Py_DECREF(pyobject_first_list);
  Py_DECREF(pyobject_second_list);
  Py_DECREF(pyobject_first_list_it);
  Py_DECREF(pyobject_second_list_it);

  return pyobject_dot_product;
}

static PyObject *norm(PyObject *self, PyObject *args) {
  PyObject *pyobject_vector;
  PyObject *pyobject_vector_item;
  Py_ssize_t vector_st;

  float norm = 0;
  PyObject *pyobject_norm;

  if (!PyArg_ParseTuple(args, "O", &pyobject_vector)) {
    PyErr_SetString(PyExc_TypeError, "parameter must be a list.");
    return NULL;
  }

  vector_st = PyList_Size(pyobject_vector);

  if (vector_st == 0) {
    PyErr_SetString(LinalgError, "list must be greater than zero");
    return NULL;
  }

  for (int i = 0; i < vector_st; i++) {
    pyobject_vector_item = PyList_GetItem(pyobject_vector, i);
    norm += pow(PyFloat_AsDouble(pyobject_vector_item), 2);
  }

  norm = sqrt(norm);

  /* */
  Py_DECREF(pyobject_vector);
  Py_DECREF(pyobject_vector_item);

  pyobject_norm = Py_BuildValue("f", norm);

  return pyobject_norm;
}

PyMODINIT_FUNC PyInit_linalg(void) {
  PyObject *module;

  module = PyModule_Create(&calculator_Module);

  if (module == NULL)
    return NULL;

  LinalgError = PyErr_NewException("linalg.LinalgError", NULL, NULL);
  Py_XINCREF(LinalgError);
  if (PyModule_AddObject(module, "error", LinalgError) < 0) {
    Py_XDECREF(LinalgError);
    Py_CLEAR(LinalgError);
    Py_DECREF(module);
    return NULL;
  }

  return module;
}