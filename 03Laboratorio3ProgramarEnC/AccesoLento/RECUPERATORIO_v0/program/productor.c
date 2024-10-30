/*Standard Library*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/*Headers Library*/
#include "framework/archivos.h"
#include "program/defines.h"
#include "program/funciones.h"
#include "program/menu_base.h"
#include "program/globals.h"
/*File Header*/
#include "productor.h"

void configurarMemoria(dato_memoria* memoria)
{
  memoria[0].mesero = 0;
  memoria[0].pedido = 0;
}

int leerMesero(dato_memoria* memoria, int posicion)
{
  return memoria[posicion].mesero;
}
int leerPedido(dato_memoria* memoria, int posicion)
{
  return memoria[posicion].pedido;
}
void escribirMesero(dato_memoria* memoria, int posicion, int valor)
{
  memoria[posicion].mesero = valor;
}
void escribirPedido(dato_memoria* memoria, int posicion, int valor)
{
  memoria[posicion].pedido = valor;
}