#ifndef _THREAD_REINA_H
#define _THREAD_REINA_H
/*Headers Library*/
#include "libCore/memoria_core.h"
struct tipo_reina
{
  int idColaMensajes;
  dato_memoria* memoria;
};
typedef struct tipo_reina reina;
void* reinaThread(void*);
void reinaAcciones(int, int, int);
#endif
