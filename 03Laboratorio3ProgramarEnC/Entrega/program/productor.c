/*Standard Library*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Headers Library*/
#include "framework/archivos.h"
#include "defines.h"
#include "globals.h"
#include "funciones.h"
/*File Header*/
#include "productor.h"

void escribirOrden(comida* nuevaOrden, int numComida)
{
  char* lineaOrden;
  lineaOrden = (char*)malloc(sizeof(char)*LARGO_LINEA);
  memset(lineaOrden,0x00,sizeof(char)*LARGO_LINEA);
  sprintf(lineaOrden , FORMATO_OUTPUT, numComida, nuevaOrden->precio, nuevaOrden->descripcion);
  escribirArchivo(lineaOrden);
  printf(FORMATO_MENU, numComida, nuevaOrden->total, nuevaOrden->descripcion);
  free(lineaOrden);
}
