#ifndef _THREAD_JUGADORES_H
#define _THREAD_JUGADORES_H
/*Encabezados*/
#include "program/memoria_core.h"
struct tipo_jugador
{
  int idColaMensajes;
  int idSemaforo;
  dato_memoria* memoria;
  /*custom*/
  int nroJugador;
};
typedef struct tipo_jugador jugador;
void* jugadoresThread(void*);
#endif
