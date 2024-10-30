#ifndef _THREAD_HORMIGAS_H
#define _THREAD_HORMIGAS_H
/*Librerias de Headers*/
#include "program/memoria_core.h"
struct tipo_hormiga
{
  int idColaMensajes;
  dato_memoria* memoria;
  int nroHormiga;     /*numero Lavarropas*/
  
  int recursoComida;  /*material = 0(Nylon)/1(Algodon)*/
  int recursoHoja;    /*Blanco*/
  int recursoPalo;    /*Color*/
  int recursoAgua;    /*Oscuro*/
};
typedef struct tipo_hormiga hormiga;
void* hormigasThread(void*);
#endif
