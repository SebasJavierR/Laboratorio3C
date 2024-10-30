#ifndef _GLOBALS_H
#define _GLOBALS_H
/*Librerias*/
#include "pthread.h"
/*Message Queue*/
enum destinos
{
  MSG_NADIE, /*0*/
  MSG_REINA,
  MSG_HORMIGA
};
enum eventos
{
  EVT_NINGUNO, /*0*/

  EVT_START_COMIDA,
  EVT_START_AGUA,
  EVT_START_PALO,
  EVT_START_HOJA,

  EVT_END_COMIDA,
  EVT_END_AGUA,
  EVT_END_PALO,
  EVT_END_HOJA,

  EVT_PATEAR,

  EVT_FIN_HORMIGA
};
typedef enum destinos Destinos;
typedef enum eventos Eventos;
/*Shared Global Variables*/
extern pthread_mutex_t mutex;
extern int hormigas_totales;
#endif
