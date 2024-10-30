/*Standard Library*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/*Headers Library*/
#include "libCommon/archivos.h"
#include "defines.h"
#include "globals.h"
#include "funciones.h"
#include "menus.h"
/*File Header*/
#include "productor.h"

void escribirOrden(orden* nuevaOrden)
{
  char* lineaOrden;
  char* letraMenu;
  lineaOrden = (char*)malloc((LARGO_LINEA+1)*sizeof(char));
  memset(lineaOrden,0x00,sizeof(lineaOrden));
  letraMenu = (char*)malloc((1+1)*sizeof(char));
  memset(letraMenu,0x00,sizeof(letraMenu));
  nuevaOrden->precio = obtenerPrecioMenu(nuevaOrden->tipoMenu);
  strcpy(letraMenu, obtenerMenuLetra(nuevaOrden->tipoMenu));
  nuevaOrden->conPostre = mostrarMenuPostre(letraMenu);
  if (nuevaOrden->conPostre == 1)
  {
    nuevaOrden->precio += IMPORTE_POSTRE;
  }
  sprintf(lineaOrden , FORMATO_OUTPUT, nuevaOrden->precio, nuevaOrden->conPostre, letraMenu);
  escribirArchivo(lineaOrden);
  printf(FORMATO_MENU, letraMenu, nuevaOrden->precio, obtenerCadenaPostre(nuevaOrden->conPostre));
  free(lineaOrden);
  free(letraMenu);
}
