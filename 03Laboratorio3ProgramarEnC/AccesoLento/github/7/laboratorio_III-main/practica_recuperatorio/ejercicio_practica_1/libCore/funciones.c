/*Standard Library*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/*Headers Library*/
#include "defines.h"
#include "globals.h"
#include "menus.h"
/*File Header*/
#include "funciones.h"

char* obtenerRutaArchivoMenu(int valor)
{
  switch(valor)
  {
    case M_A:
      return RUTA_ARCHIVO_MENU_A;
    case M_B:
      return RUTA_ARCHIVO_MENU_B;
    case M_C:
      return RUTA_ARCHIVO_MENU_C;
    default:
      return "";
  }
}

char* obtenerMenuLetra(int valor)
{
  switch(valor)
  {
    case M_A:
      return MENU_A;
    case M_B:
      return MENU_B;
    case M_C:
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
    case M_A:
      return IMPORTE_MENU_A;
    case M_B:
      return IMPORTE_MENU_B;
    case M_C:
      return IMPORTE_MENU_C;
  }
  return 0;
}

char* obtenerCadenaPostre(int valor)
{
  switch(valor)
  {
    case AC_SI:
      return "SI";
    case AC_NO:
      return "NO";
  }
  return "";
}
