/*Librerias*/
#include "stdio.h"

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
