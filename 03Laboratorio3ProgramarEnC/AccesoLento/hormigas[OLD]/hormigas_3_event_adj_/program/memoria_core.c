/*Standard Library*/
#include "stdio.h"
#include "string.h"
/*Headers Library*/
#include "framework/pantalla.h"
/*File Header*/
#include "memoria_core.h"

void configurarMemoria(dato_memoria* memoria)
{
  memoria[0].recursoComida = 0;
  memoria[0].recursoHoja = 0;
  memoria[0].recursoRama = 0;
  memoria[0].recursoAgua = 0;
}

int leerRecursoComida(dato_memoria* memoria, int posicion)
{
  return memoria[posicion].recursoComida;
}

void escribirRecursoComida(dato_memoria* memoria, int posicion, int valor)
{
  memoria[posicion].recursoComida = valor;
}

int leerRecursoHoja(dato_memoria* memoria, int posicion)
{
  return memoria[posicion].recursoHoja;
}

void escribirRecursoHoja(dato_memoria* memoria, int posicion, int valor)
{
  memoria[posicion].recursoHoja = valor;
}

int leerRecursoRama(dato_memoria* memoria, int posicion)
{
  return memoria[posicion].recursoRama;
}

void escribirRecursoRama(dato_memoria* memoria, int posicion, int valor)
{
  memoria[posicion].recursoRama = valor;
}

int leerRecursoAgua(dato_memoria* memoria, int posicion)
{
  return memoria[posicion].recursoAgua;
}

void escribirRecursoAgua(dato_memoria* memoria, int posicion, int valor)
{
  memoria[posicion].recursoAgua = valor;
}



