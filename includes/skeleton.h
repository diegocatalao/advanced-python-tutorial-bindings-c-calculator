#ifndef _H_PY_SKELETON_
#define _H_PY_SKELETON_
/* Habilita o uso das variantes de # ("s#", "y#") e seu
 * tamanho paassa a ser do tipo Py_ssize_t e não int */
#define PY_SSIZE_T_CLEAN

#include <python3.8/Python.h>

/* uma lista com as funções que serão registradas no módulo */
static PyMethodDef skeleton_ModuleMethods[] = {
    {NULL, NULL, 0, NULL}, /* Sentinela */
};

/* Inicialização do módulo */

static struct PyModuleDef skeleton_Module = {
    /* Sempre inicializado com PyModuleDef_HEAD_INIT */
    .m_base = PyModuleDef_HEAD_INIT,
    /* Nome do módulo */
    .m_name = "skeleton",
    /* Ponteiro para a docstring do módulo, ou nulo */
    .m_doc = "Esqueleto de um módulo",
    /* Indica o estado da memória do módulo tornando o módulo mais seguro
       quando usado por subinterpretadores. quando m_size for -1, significa que
       o módulo não oferece suporte a subinterpretadores */
    .m_size = -1,
    /* Ponteiro para uma lista de funções no nível do módulo */
    .m_methods = skeleton_ModuleMethods,
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

#endif