#ifndef _GLOBALS_H
#define _GLOBALS_H
#include "defines.h"
struct tipo_inicial
{
  int inicializado;
};
struct tipo_dato
{
  int* vehiculosEnColas; /*vehiculosEnColas[CANTIDAD_DE_VIAS]*/
};
typedef struct tipo_dato dato;
typedef struct tipo_inicial inicial;
#endif
