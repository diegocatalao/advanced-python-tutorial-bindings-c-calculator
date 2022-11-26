#ifndef _H_PYCTUTORIAL_CALCULATOR_BASIC_
#define _H_PYCTUTORIAL_CALCULATOR_BASIC_

#include <python3.8/Python.h>

/* Funções do módulo */

/**
 * @brief Calcula a soma de dois números e retorna o resultado.
 *
 * @param self {PyObject} - Objeto de referência
 * @param args {PyObject} - Objeto com os argumentos obrigatórios da função
 * @return PyObject* - Retorna a referência do objeto calculado.
 */
static PyObject *sum(PyObject *self, PyObject *args);

/**
 * @brief Calcula a subtração de dois números e retorna o resultado.
 *
 * @param self {PyObject} - Objeto de referência
 * @param args {PyObject} - Objeto com os argumentos obrigatórios da função
 * @return PyObject* - Retorna a referência do objeto calculado.
 */
static PyObject *sub(PyObject *self, PyObject *args);

/**
 * @brief Calcula a multiplicação de dois números e retorna o resultado.
 *
 * @param self {PyObject} - Objeto de referência
 * @param args {PyObject} - Objeto com os argumentos obrigatórios da função
 * @return PyObject* - Retorna a referência do objeto calculado.
 */
static PyObject *mul(PyObject *self, PyObject *args);

/**
 * @brief Calcula a divisão de dois números e retorna o resultado.
 *
 * @param self {PyObject} - Objeto de referência
 * @param args {PyObject} - Objeto com os argumentos obrigatórios da função
 * @return PyObject* - Retorna a referência do objeto calculado.
 */
static PyObject *divs(PyObject *self, PyObject *args);

/* Definições do módulo */

/* uma lista com as funções que serão registradas no módulo */
static PyMethodDef calculator_elementary_ModuleMethods[] = {
    {
        /* nome do método */
        .ml_name = "sum",
        /* ponteiro para a implementação da função */
        .ml_meth = (PyCFunction)sum,
        /* flag para indicar como a chamada deve ser construída */
        .ml_flags = METH_VARARGS,
        /* ponteiro para um conteúdo da docstring */
        .ml_doc = "Simple sum function",
    },
    {
        /* nome do método */
        .ml_name = "sub",
        /* ponteiro para a implementação da função */
        .ml_meth = (PyCFunction)sub,
        /* flag para indicar como a chamada deve ser construída */
        .ml_flags = METH_VARARGS,
        /* ponteiro para um conteúdo da docstring */
        .ml_doc = "Simple sub function",
    },
    {
        /* nome do método */
        .ml_name = "mul",
        /* ponteiro para a implementação da função */
        .ml_meth = (PyCFunction)mul,
        /* flag para indicar como a chamada deve ser construída */
        .ml_flags = METH_VARARGS,
        /* ponteiro para um conteúdo da docstring */
        .ml_doc = "Simple mul function",
    },
    {
        /* nome do método */
        .ml_name = "divs",
        /* ponteiro para a implementação da função */
        .ml_meth = (PyCFunction)divs,
        /* flag para indicar como a chamada deve ser construída */
        .ml_flags = METH_VARARGS,
        /* ponteiro para um conteúdo da docstring */
        .ml_doc = "Simple div function",
    },
    /* Sentinela. Segurança para avisar que a lista acaba aqui */
    {NULL, NULL, 0, NULL},
};

/* Inicialização do módulo */

static struct PyModuleDef calculator_elementary_Module = {
    /* Sempre inicializado com PyModuleDef_HEAD_INIT */
    .m_base = PyModuleDef_HEAD_INIT,
    /* Nome do módulo com namespace "calculator" (não obrigatório)*/
    .m_name = "calculator.elementary",
    /* Ponteiro para a docstring do módulo, ou nulo */
    .m_doc = "Funções elementares de uma calculadora",
    /* Indica o estado da memória do módulo tornando o módulo mais seguro
       quando usado por subinterpretadores. quando m_size for -1, significa que
       o módulo não oferece suporte a subinterpretadores */
    .m_size = -1,
    /* Ponteiro para uma lista de funções no nível do módulo */
    .m_methods = calculator_elementary_ModuleMethods,
    /* Matriz de definição de slots para inicialização multifásica finalizada
       por uma entrada {0, NULL}. Quando usado por um módulo monofásico a
       entrada deve ser NULL */
    .m_slots = NULL,
    /* Função chamada durante a passagem do Garbage Collector ou NULL se não for
       necessária */
    .m_traverse = NULL,
    /* Função chamada durante a limpeza do Garbage Collector ou NULL se não for
       necessária */
    .m_clear = NULL,
    /* Função chamda durante a desalocação do objeto pelo Garbage Collector ou
       NULL se não for necessária */
    .m_free = NULL,
};

/* Variáveis globais estáticas do módulo */

/* Erro genérico para o módulo inicializado no PyInit_seu_modulo */
static PyObject *ElementaryError;

#endif