#include "elementary.h"

/* Funções do módulo */

/**
 * @brief Implementação da função de soma.
 *
 * @param self {PyObject} - Objeto de referência
 * @param args {PyObject} - Objeto com os argumentos obrigatórios da função
 * @return PyObject* - Retorna a referência do objeto calculado.
 */
static PyObject *sum(PyObject *self, PyObject *args) {
  PyObject *pyobject_result;

  float first_value;
  float second_value;
  float result;

  /* faz o parse da entrada pelo objeto args */
  /* é recomendável seguir as instruções da tabela de tipos: */
  /* https://docs.python.org/3/c-api/arg.html#strings-and-buffers */
  if (!PyArg_ParseTuple(args, "ff", &first_value, &second_value)) {
    return NULL;
  }

  result = first_value + second_value;
  /* cria um pyobject para o valor calculado */
  pyobject_result = Py_BuildValue("f", result);

  /* incrementa o contador de referências para o novo objeto */
  Py_INCREF(pyobject_result);

  return pyobject_result;
}

/**
 * @brief Implementação da função de subtração.
 *
 * @param self {PyObject} - Objeto de referência
 * @param args {PyObject} - Objeto com os argumentos obrigatórios da função
 * @return PyObject* - Retorna a referência do objeto calculado.
 */
static PyObject *sub(PyObject *self, PyObject *args) {
  PyObject *pyobject_result;

  float first_value;
  float second_value;
  float result;

  /* faz o parse da entrada pelo objeto args */
  /* é recomendável seguir as instruções da tabela de tipos: */
  /* https://docs.python.org/3/c-api/arg.html#strings-and-buffers */
  if (!PyArg_ParseTuple(args, "ff", &first_value, &second_value)) {
    return NULL;
  }

  result = first_value - second_value;
  /* cria um pyobject para o valor calculado */
  pyobject_result = Py_BuildValue("f", result);

  /* incrementa o contador de referências para o novo objeto */
  Py_INCREF(pyobject_result);

  return pyobject_result;
}

/**
 * @brief Implementação da função de multiplicação.
 *
 * @param self {PyObject} - Objeto de referência
 * @param args {PyObject} - Objeto com os argumentos obrigatórios da função
 * @return PyObject* - Retorna a referência do objeto calculado.
 */
static PyObject *mul(PyObject *self, PyObject *args) {
  PyObject *pyobject_result;

  float first_value;
  float second_value;
  float result;

  /* faz o parse da entrada pelo objeto args */
  /* é recomendável seguir as instruções da tabela de tipos: */
  /* https://docs.python.org/3/c-api/arg.html#strings-and-buffers */
  if (!PyArg_ParseTuple(args, "ff", &first_value, &second_value)) {
    return NULL;
  }

  result = first_value * second_value;
  /* cria um pyobject para o valor calculado */
  pyobject_result = Py_BuildValue("f", result);

  /* incrementa o contador de referências para o novo objeto */
  Py_INCREF(pyobject_result);

  return pyobject_result;
}

/**
 * @brief Implementação da função de divisão.
 *
 * @param self {PyObject} - Objeto de referência
 * @param args {PyObject} - Objeto com os argumentos obrigatórios da função
 * @return PyObject* - Retorna a referência do objeto calculado.
 */
static PyObject *divs(PyObject *self, PyObject *args) {
  PyObject *pyobject_result;

  float first_value;
  float second_value;
  float result;

  /* faz o parse da entrada pelo objeto args */
  /* é recomendável seguir as instruções da tabela de tipos: */
  /* https://docs.python.org/3/c-api/arg.html#strings-and-buffers */
  if (!PyArg_ParseTuple(args, "ff", &first_value, &second_value)) {
    return NULL;
  }

  /* para evitar o retorno de 'inf', se o segundo parâmetro for zero, retorna o
   * erro de divisão por zero */
  if (second_value == 0) {
    PyErr_SetString(ElementaryError, "Zero division.");
    return NULL;
  }

  result = first_value / second_value;
  /* cria um pyobject para o valor calculado */
  pyobject_result = Py_BuildValue("f", result);

  /* incrementa o contador de referências para o novo objeto */
  Py_INCREF(pyobject_result);

  return pyobject_result;
}

/* Inicialização do módulo */

PyMODINIT_FUNC PyInit_elementary(void) {
  /* Cria um novo PyObject para o módulo com base na lista de funções do módulo
   * dividindo o estágio de inicialização. */
  PyObject *module;
  module = PyModule_Create(&calculator_elementary_Module);

  /* Caso haja algum erro, retorna a exceção */
  if (module == NULL)
    return NULL;

  /* Cria uma nova excessão genérica para o módulo */
  ElementaryError =
      PyErr_NewException("elementary.ElementaryError", NULL, NULL);
  /* Incrementa o contador de referências para o objeto */
  Py_XINCREF(ElementaryError);
  /* Tenta adicionar o objeto de exceção ao módulo */
  if (PyModule_AddObject(module, "error", ElementaryError) < 0) {
    /* Quando PyModule_AddObject for menor que zero, ocorreu um erro */

    /* Decrementa o contador de referências para o objeto de exceção */
    Py_XDECREF(ElementaryError);
    /* Limpa o objeto da memória */
    Py_CLEAR(ElementaryError);
    /* Decrementa o contador de referências para o módulo */
    Py_DECREF(module);
    /* Retorna a exceção */
    return NULL;
  }

  /* Retorna o módulo alocado */
  return module;
}