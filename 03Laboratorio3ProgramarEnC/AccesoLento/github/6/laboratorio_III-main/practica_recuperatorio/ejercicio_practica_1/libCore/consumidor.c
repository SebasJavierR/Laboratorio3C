/*Standard Library*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/*Headers Library*/
#include "libCommon/archivos.h"
#include "libCore/defines.h"
/*File Header*/
#include "consumidor.h"

void leerOrdenes()
{
  int conPostre;
  int precio;
  char* menuLetra;
  char* lineaOrden;

  menuLetra = (char*)malloc((1)*sizeof(char));
  memset(menuLetra,0x00,sizeof(menuLetra));

  lineaOrden = (char*)malloc((LARGO_LINEA)*sizeof(char));
  memset(lineaOrden,0x00,sizeof(lineaOrden));
  precio = 0;
  conPostre = 0;
  while(leerLineaArchivo(lineaOrden) != 0)
  {
    sscanf(lineaOrden, FORMATO_OUTPUT, &precio, &conPostre, menuLetra);
    printf(FORMATO_MENU, menuLetra, precio, conPostre);            precio = 0;
    conPostre = 0;
    memset(lineaOrden,0x00,sizeof(lineaOrden));
    memset(menuLetra,0x00,sizeof(menuLetra));
  }
  free(lineaOrden);
  free(menuLetra);
}
