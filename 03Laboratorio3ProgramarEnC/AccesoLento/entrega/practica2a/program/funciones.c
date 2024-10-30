/*Librerias*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/*Encabezados*/
#include "defines.h"

#include "funciones.h"

char* obtenerCaracterPorNumero(int valor)
{
  switch(valor)
  {
    case 1:
      return "A";
  }
  return 0;
}

int obtenerNumeroPorCaracter(char* valor)
{
  if (strcmp("A", valor) == 0)
  {
    return 1;
  }
  return -1;
}


char* obtenerRutaArchivo(int valor)
{
  switch(valor)
  {
    case 1:
      return RUTA_ARCHIVO;
  }
  return "";
}

char* obtenerNombreJugador(int nroJugador)
{
  switch(nroJugador)
  {
    case 0:
      return "HOJA";
    case 1:
      return "PIEDRA";
    case 2:
      return "PAPEL";
    case 3:
      return "TIERRA";
    case 4:
      return "PALITO";
  }
  return "";
}

int obtenerIntervaloJugador(int nroJugador)
{
  switch(nroJugador)
  {
    case 0:
      return INTERVALO_PASO_CONEJO_MS;
    case 1:
      return INTERVALO_PASO_TORTUGA_MS;
  }
  return 0;
}
