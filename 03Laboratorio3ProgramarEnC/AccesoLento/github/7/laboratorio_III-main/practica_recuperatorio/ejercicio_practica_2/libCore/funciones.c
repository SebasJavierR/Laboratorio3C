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

char* obtenerRutaArchivoPanel(int valor)
{
  switch(valor)
  {
    case PANEL_1:
      return RUTA_ARCHIVO_PANEL_1;
    case PANEL_2:
      return RUTA_ARCHIVO_PANEL_2;
    case PANEL_3:
      return RUTA_ARCHIVO_PANEL_3;
    default:
      return "";
  }
}

char* obtenerNombrePanel(int valor)
{
  switch(valor)
  {
    case M_PANEL_1:
      return "PANEL_1";
    case M_PANEL_2:
       return "PANEL_2";
    case M_PANEL_3:
      return "PANEL_3";
    default:
      return "";
  }
}

char* obtenerNombreAccion(int valor)
{
  switch(valor)
  {
    case M_AC_LEER:
      return "LEER";
    case M_AC_ESCRIBIR:
       return "ESCRIBIR";
    default:
      return "";
  }
}
