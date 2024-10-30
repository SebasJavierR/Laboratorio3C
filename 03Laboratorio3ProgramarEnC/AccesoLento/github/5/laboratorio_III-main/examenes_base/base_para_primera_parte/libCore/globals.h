#ifndef _GLOBALS_H
#define _GLOBALS_H
/*Standard Library*/
#include "stdio.h"
#include "string.h"
/*Headers Library*/
#include "libCommon/pantalla.h"
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
struct tipo_carrera
{
  /*custom*/
  int nroCarrera;
};
typedef struct tipo_carrera carrera;
struct tipo_jugador
{
  /*custom*/
  int nroJugador;
};
typedef struct tipo_jugador jugador;
/*Shared Global Variables*/
extern int cantidadJugadores;
#endif
