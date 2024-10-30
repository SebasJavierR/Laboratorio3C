/*Librerias*/
#include "stdio.h"
/*Header*/
#include "pantalla.h"

void limpiarPantalla()
{
  int i;
  i = 0;
  while (i<LINEAS_PANTALLA)
  {
    printf("\n");
    i++;
  }
}
