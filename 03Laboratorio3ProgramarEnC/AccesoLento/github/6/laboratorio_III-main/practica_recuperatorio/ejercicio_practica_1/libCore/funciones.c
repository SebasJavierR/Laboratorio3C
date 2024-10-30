/*Standard Library*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/*Headers Library*/
#include "defines.h"
/*File Header*/
#include "funciones.h"

char* obtenerRutaArchivoMenu(int valor)
{
  switch(valor)
  {
    case 1:
      return RUTA_ARCHIVO_MENU_A;
    case 2:
      return RUTA_ARCHIVO_MENU_B;
    case 3:
      return RUTA_ARCHIVO_MENU_C;
    default:
      return "";
  }
}

char* obtenerMenuLetra(int valor)
{
  switch(valor)
  {
    case 1:
      return MENU_A;
    case 2:
      return MENU_B;
    case 3:
      return MENU_C;
  }
  return 0;
}

int obtenerMenuNum(char* valor)
{
  if (strcmp("A", valor) == 0)
  {
    return 1;
  }
  else if (strcmp("B", valor) == 0)
  {
    return 2;
  }
  else if (strcmp("C", valor) == 0)
  {
    return 3;
  }
  return -1;
}

int obtenerPrecioMenu(int valor)
{
  switch(valor)
  {
    case 1:
      return IMPORTE_MENU_A;
    case 2:
      return IMPORTE_MENU_B;
    case 3:
      return IMPORTE_MENU_C;
  }
  return 0;
}
