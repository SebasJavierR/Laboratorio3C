#ifndef _PRODUCTOR_H
#define _PRODUCTOR_H
/*Headers Library*/
#include "globals.h"
struct tipo_dato_memoria
{
  int mesero;
  int pedido;
};
typedef struct tipo_dato_memoria dato_memoria;
void configurarMemoria(dato_memoria*);
int leerMesero(dato_memoria*, int);
int leerPedido(dato_memoria*, int);
void escribirMesero(dato_memoria*, int, int);
void escribirPedido(dato_memoria*, int, int);
#endif