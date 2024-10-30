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
#include "consumidor.h"

void leerOrdenes(void)
{
  char* lineaOrden;
  comida* nuevaOrden;
  int numComida;

  numComida = 0;
  lineaOrden = (char*)malloc(sizeof(char)*LARGO_LINEA);
  memset(lineaOrden,0x00,sizeof(char)*LARGO_LINEA);
  nuevaOrden = (comida*)malloc(sizeof(comida));
  memset(nuevaOrden, 0x00, sizeof(comida));
  while(leerLineaArchivo(lineaOrden) != 0)
  {
    sscanf(lineaOrden , FORMATO_OUTPUT, &numComida, &nuevaOrden->precio, nuevaOrden->descripcion);
    printf(FORMATO_MENU, numComida, nuevaOrden->precio, nuevaOrden->descripcion);
    memset(lineaOrden,0x00,sizeof(char)*LARGO_LINEA);
    memset(nuevaOrden, 0x00, sizeof(comida));
  }
  free(lineaOrden);
  free(nuevaOrden);
}
