#ifndef _MEMORIA_CORE_H
#define _MEMORIA_CORE_H
/*Encabezados*/
#include "program/defines.h"
struct tipo_dato_memoria
{
  int pasosJugador;
  char nombreJugador[MAX_LARGO_CADENA];
};
typedef struct tipo_dato_memoria dato_memoria;
void configurarMemoria(dato_memoria*, int);
int leerPasosJugador(dato_memoria*, int);
void escribirPasosJugador(dato_memoria*, int, int);
char* leerNombreJugador(dato_memoria*, int);
void escribirNombreJugador(dato_memoria*, int, char*);
#endif
