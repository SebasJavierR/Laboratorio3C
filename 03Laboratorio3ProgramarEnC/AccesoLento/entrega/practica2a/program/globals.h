#ifndef _GLOBALS_H
#define _GLOBALS_H
/*Librerias*/
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
  EVT_CAMINAR,
  EVT_CAMINAR_FIN,
  EVT_FIN
};
typedef enum destinos Destinos;
typedef enum eventos Eventos;
/*Shared Global Variables*/
extern pthread_mutex_t mutex;
extern int cantidadJugadores;
extern int hormigasMaximas;
#endif
