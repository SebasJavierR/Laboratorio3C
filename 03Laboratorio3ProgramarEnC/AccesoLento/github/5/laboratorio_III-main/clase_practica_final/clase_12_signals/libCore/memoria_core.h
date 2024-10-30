#ifndef _MEMORIA_CORE_H
#define _MEMORIA_CORE_H
/*Headers Library*/
#include "libCore/defines.h"
struct tipo_dato_memoria
{
  int goles;
  int finPartido;
};
typedef struct tipo_dato_memoria dato_memoria;
void configurarMemoria(dato_memoria*, int);
int leerGoles(dato_memoria*, int);
void escribirGoles(dato_memoria*, int, int);
int leerFinPartido(dato_memoria*, int);
void escribirFinPartido(dato_memoria*, int, int);
#endif
