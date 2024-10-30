/*Standard Library*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Headers Library*/
#include "defines.h"
/*File Header*/
#include "funciones.h"

char* obtenerRutaArchivoMesero(int valor)
{
  switch(valor)
  {
    case MESERO_1:
      return RUTA_ARCHIVO_MESERO_1;
    case MESERO_2:
      return RUTA_ARCHIVO_MESERO_2;
    case MESERO_3:
      return RUTA_ARCHIVO_MESERO_3;
    default:
      return "";
  }
}
