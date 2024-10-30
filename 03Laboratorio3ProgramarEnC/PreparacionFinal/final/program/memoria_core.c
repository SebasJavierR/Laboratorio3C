/*Librerias*/
#include "stdio.h"
#include "string.h"
/*Librerias de Headers*/
#include "framework/pantalla.h"
/*Header*/
#include "memoria_core.h"

void configurarMemoria(dato_memoria* memoria)
{
  memoria[0].recursoComida = 0;
  memoria[0].recursoHoja = 0;
  memoria[0].recursoPalo = 0;
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

int leerrecursoPalo(dato_memoria* memoria, int posicion)
{
  return memoria[posicion].recursoPalo;
}

void escribirrecursoPalo(dato_memoria* memoria, int posicion, int valor)
{
  memoria[posicion].recursoPalo = valor;
}

int leerRecursoAgua(dato_memoria* memoria, int posicion)
{
  return memoria[posicion].recursoAgua;
}

void escribirRecursoAgua(dato_memoria* memoria, int posicion, int valor)
{
  memoria[posicion].recursoAgua = valor;
}



