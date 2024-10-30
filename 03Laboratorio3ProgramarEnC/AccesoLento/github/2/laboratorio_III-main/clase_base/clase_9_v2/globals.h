#ifndef _GLOBALS_H
#define _GLOBALS_H
#include "defines.h"
struct tipo_inicial
{
  int inicializado;
};
typedef struct tipo_inicial inicial;
enum destinos
{
  MSG_NADIE, /*0*/
  MSG_UNO,
  MSG_DOS
};
enum eventos
{
  EVT_NINGUNO, /*0*/
  EVT_MENSAJE,
  EVT_FIN
};
typedef enum destinos Destinos;
typedef enum eventos Eventos;
extern pthread_mutex_t mutex;
#endif
