#ifndef _THREAD_HORMIGAS_H
#define _THREAD_HORMIGAS_H
/*Librerias de Headers*/
#include "program/memoria_core.h"
struct tipo_hormiga
{
  int idColaMensajes;
  dato_memoria* memoria;
  int nroHormiga;
  
  int recursoComida;
  int recursoHoja;
  int recursoPalo;
  int recursoAgua;

};
typedef struct tipo_hormiga hormiga;
void* hormigasThread(void*);
#endif
