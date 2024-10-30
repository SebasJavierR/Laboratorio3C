#ifndef _GLOBALS_H
#define _GLOBALS_H
/*Standard Library*/
#include "pthread.h"
/*Message Queue*/
enum destinos
{
  MSG_NADIE, /*0*/
  MSG_TABLERO,
  MSG_JUGADOR
};
enum eventos
{
  EVT_NINGUNO, /*0*/
  EVT_COMIDA,
  EVT_PALITOS,
  EVT_HOJAS,
  EVT_TIERRA,
  EVT_CAMINAR,
  EVT_FIN
};
typedef enum destinos Destinos;
typedef enum eventos Eventos;
/*Shared Global Variables*/
extern pthread_mutex_t mutex;
extern int cantidadJugadores;
#endif
