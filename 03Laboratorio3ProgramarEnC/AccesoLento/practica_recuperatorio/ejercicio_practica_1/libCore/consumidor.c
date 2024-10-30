/*Standard Library*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/*Headers Library*/
#include "libCommon/archivos.h"
#include "defines.h"
#include "globals.h"
#include "funciones.h"
/*File Header*/
#include "consumidor.h"

void leerOrdenes()
{
  orden nuevaOrden;
  char* menuLetra;
  char* lineaOrden;

  menuLetra = (char*)malloc((1)*sizeof(char));
  memset(menuLetra,0x00,sizeof(menuLetra));

  lineaOrden = (char*)malloc((LARGO_LINEA)*sizeof(char));
  memset(lineaOrden,0x00,sizeof(lineaOrden));
  nuevaOrden.precio = 0;
  nuevaOrden.conPostre = 0;
  while(leerLineaArchivo(lineaOrden) != 0)
  {
    sscanf(lineaOrden, FORMATO_OUTPUT, &nuevaOrden.precio, &nuevaOrden.conPostre, menuLetra);
    printf(FORMATO_MENU, menuLetra, nuevaOrden.precio, obtenerCadenaPostre(nuevaOrden.conPostre));
    nuevaOrden.precio = 0;
    nuevaOrden.conPostre = 0;
    memset(lineaOrden,0x00,sizeof(lineaOrden));
    memset(menuLetra,0x00,sizeof(menuLetra));
  }
  free(lineaOrden);
  free(menuLetra);
}
