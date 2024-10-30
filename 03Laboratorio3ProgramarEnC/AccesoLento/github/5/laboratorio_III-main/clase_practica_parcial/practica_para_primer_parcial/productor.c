#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "defines.h"
#include "gestionararchivos.h"
#include "funciones.h"
#include "semaforos.h"

void escribirOrden(int menuActual)
{
  char* lineaOrden;
  char* letraMenu;
  int conPostre;
  int precio;
  lineaOrden = (char*)malloc((LARGO_LINEA+1)*sizeof(char));
  memset(lineaOrden,0x00,sizeof(lineaOrden));
  letraMenu = (char*)malloc((1+1)*sizeof(char));
  memset(letraMenu,0x00,sizeof(letraMenu));
  precio = obtenerPrecioMenu(menuActual);
  strcpy(letraMenu, obtenerMenuLetra(menuActual));
  conPostre=-1;
  while (conPostre != 0 && conPostre != 1)
  {
    printf("¿Quiere postre? (1=si;0=no)");
    scanf("%d", &conPostre);
  }
  if (conPostre == 1)
  {
    precio += IMPORTE_POSTRE;
  }
  sprintf(lineaOrden , FORMATO_OUTPUT, precio, conPostre, letraMenu);
  escribirArchivo(lineaOrden);
  printf(lineaOrden);
  free(lineaOrden);
  free(letraMenu);
}


