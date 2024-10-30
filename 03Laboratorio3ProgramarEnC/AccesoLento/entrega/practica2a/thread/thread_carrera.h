#ifndef _THREAD_CARRERA_H
#define _THREAD_CARRERA_H
/*Encabezados*/
#include "program/memoria_core.h"
struct tipo_tablero
{
  int idColaMensajes;
  int idSemaforo;
  dato_memoria* memoria;
};
typedef struct tipo_tablero tablero;
void* carreraThread(void*);
#endif
