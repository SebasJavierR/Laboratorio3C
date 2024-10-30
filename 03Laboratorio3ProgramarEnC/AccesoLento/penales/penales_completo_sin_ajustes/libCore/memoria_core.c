/*Standard Library*/
#include "stdio.h"
#include "string.h"
/*Headers Library*/
#include "libCommon/pantalla.h"
/*File Header*/
#include "memoria_core.h"

void configurarMemoria(dato_memoria* memoria, int cantidadPosiciones)
{
  int i;
  for (i = 0; i < cantidadPosiciones; i++)
  {
    memoria[i].pasosJugador = 0;
    memset(memoria[i].nombreJugador,0x00,sizeof(memoria[i].nombreJugador));
  }
}

int leerPasosJugador(dato_memoria* memoria, int posicion)
{
  return memoria[posicion].pasosJugador;
}

void escribirPasosJugador(dato_memoria* memoria, int posicion, int valor)
{
  memoria[posicion].pasosJugador = valor;
}

char* leerNombreJugador(dato_memoria* memoria, int posicion)
{
  return memoria[posicion].nombreJugador;
}

void escribirNombreJugador(dato_memoria* memoria, int posicion, char* ptrCadena)
{
  strcpy(memoria[posicion].nombreJugador, ptrCadena);
}





