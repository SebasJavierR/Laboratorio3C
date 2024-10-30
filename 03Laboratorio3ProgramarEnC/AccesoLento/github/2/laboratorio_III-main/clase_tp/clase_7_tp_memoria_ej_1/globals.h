#ifndef _GLOBALS_H
#define _GLOBALS_H
#include "defines.h"
struct tipo_dato
{
  char nombreJugador[LARGO_NOMBRE]; /*nombreJugador[LARGO_NOMBRE]*/
  int numeroPensado; /*0:sin número; 1-99:número a verificar*/
  int estadoAcierto; /*0:no acierto;1: acierto*/
  int inicializado;
};
typedef struct tipo_dato dato;
#endif
