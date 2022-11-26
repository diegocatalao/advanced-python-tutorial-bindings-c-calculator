#include "linalg.h"

#include <stdio.h>

/**
 * @brief Implementação da função que calcula o produto interno.
 *
 * @param self {PyObject} - Objeto de referência
 * @param args {PyObject} - Objeto com os argumentos obrigatórios da função
 * @return PyObject* - Retorna a referência do objeto calculado.
 */
static PyObject *dot(PyObject *self, PyObject *args) {
  /* referência das listas de entrada */
  PyObject *pyobject_first_list;
  PyObject *pyobject_second_list;

  /* referência dos objetos que percorrem a lista */
  PyObject *pyobject_first_list_it;
  PyObject *pyobject_second_list_it;

  /* tamanho das listas */
  Py_ssize_t lists_size_st;

  /* variável que irá receber o cálculo do produto interno */
  float dot_product = 0;
  /* seu objeto python de referência para ser retornado */
  PyObject *pyobject_dot_product;

  /* recebe dois objetos do tipo object como lista */
  if (!PyArg_ParseTuple(args, "OO", &pyobject_first_list,
                        &pyobject_second_list)) {
    PyErr_SetString(PyExc_TypeError, "parameter must be a list.");
    return NULL;
  }

  /* verifica se os objetos têm tamanhos iguais */
  if (PyList_Size(pyobject_first_list) != PyList_Size(pyobject_second_list)) {
    PyErr_SetString(LinalgError, "the lists must be equal in size");
    return NULL;
  }

  /* verifica se os objetos não estão vazios */
  if ((PyList_Size(pyobject_first_list) == 0) ||
      (PyList_Size(pyobject_second_list) == 0)) {
    PyErr_SetString(LinalgError, "list must be greater than zero");
    return NULL;
  }

  /* pega o tamanho da primeira lista */
  lists_size_st = PyList_Size(pyobject_first_list);

  for (int i = 0; i < lists_size_st; i++) {
    /* pega o item incrementado na variável (i) da primeira lista*/
    pyobject_first_list_it = PyList_GetItem(pyobject_first_list, i);
    /* pega o item incrementado na variável (i) da segunda lista*/
    pyobject_second_list_it = PyList_GetItem(pyobject_second_list, i);

    /* verifica se o item é um número antes de operar*/
    if ((!PyNumber_Check(pyobject_first_list_it)) ||
        (!PyNumber_Check(pyobject_second_list_it))) {
      /* se não,  retorna um erro e decrementa a referência do objeto */
      PyErr_SetString(LinalgError, "impossible to operate between non-numbers");
      Py_DECREF(pyobject_first_list);
      Py_DECREF(pyobject_second_list);
      Py_DECREF(pyobject_first_list_it);
      Py_DECREF(pyobject_second_list_it);
      return NULL;
    }

    /* converte o item da lista para o tipo primitivo double */
    dot_product += PyFloat_AsDouble(pyobject_first_list_it) *
                   PyFloat_AsDouble(pyobject_second_list_it);
  }

  /* converte o valor calculado em um tipo pyobject float */
  pyobject_dot_product = Py_BuildValue("f", dot_product);

  /* decrementa a referência dos objetos que não serão mais usados */
  Py_DECREF(pyobject_first_list);
  Py_DECREF(pyobject_second_list);

  return pyobject_dot_product;
}

/**
 * @brief Implementação da função que calcula a norma do vetor.
 *
 * @param self {PyObject} - Objeto de referência
 * @param args {PyObject} - Objeto com os argumentos obrigatórios da função
 * @return PyObject* - Retorna a referência do objeto calculado.
 */
static PyObject *norm(PyObject *self, PyObject *args) {
  /* cria a referência da lista de entrada */
  PyObject *pyobject_vector;
  /* cria a referência do objeto que percorre a lista */
  PyObject *pyobject_vector_item;
  /* tamanho da lista */
  Py_ssize_t vector_st;

  /* variável para o cálculo da norma e sua referência pyobject */
  float norm = 0;
  PyObject *pyobject_norm;

  /* recebe um vetor do tipo object */
  if (!PyArg_ParseTuple(args, "O", &pyobject_vector)) {
    PyErr_SetString(PyExc_TypeError, "parameter must be a list.");
    return NULL;
  }

  /* recupera o tamanho da lista */
  vector_st = PyList_Size(pyobject_vector);

  /* verifica se a lista não está vazia */
  if (vector_st == 0) {
    PyErr_SetString(LinalgError, "list must be greater than zero");
    return NULL;
  }

  for (int i = 0; i < vector_st; i++) {
    pyobject_vector_item = PyList_GetItem(pyobject_vector, i);
    /* verifica se o item é um número antes de operar */
    if (!PyNumber_Check(pyobject_vector_item)) {
      /* se não,  retorna um erro e decrementa a referência do objeto */
      PyErr_SetString(LinalgError, "impossible to operate between non-numbers");
      Py_DECREF(pyobject_vector);
      Py_DECREF(pyobject_vector_item);
      return NULL;
    }

    /* calcula a norma do vetor */
    norm += PyFloat_AsDouble(pyobject_vector_item) *
            PyFloat_AsDouble(pyobject_vector_item);
  }

  norm = sqrt(norm);

  /* converte o valor calculado em um tipo pyobject float */
  pyobject_norm = Py_BuildValue("f", norm);

  /* decrementa a referência dos objetos que não serão mais usados */
  Py_DECREF(pyobject_vector);

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