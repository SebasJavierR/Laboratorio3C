/*Standard Library*/
#include <stdio.h>
/*File Header*/
#include "pantalla.h"

void limpiarPantalla(void)
{
  int i;
  i = 0;
  while (i<LINEAS_PANTALLA)
  {
    puts("");
    i++;
  }
}
