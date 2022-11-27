#include "skeleton.h"

PyMODINIT_FUNC PyInit_skeleton(void) {
  printf("Módulo criado com sucesso!\n");
  /* Cria um PyObject a partir do módulo definido no header */
  return PyModule_Create(&skeleton_Module);
}