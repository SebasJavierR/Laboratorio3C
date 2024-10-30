#ifndef _THREAD_PARTIDO_H
#define _THREAD_PARTIDO_H
/*Headers Library*/
#include "libCore/memoria_core.h"
struct tipo_partido
{
  int idColaMensajes;
  dato_memoria* memoria;
};
typedef struct tipo_partido partido;
void* partidoThread(void*);
#endif
