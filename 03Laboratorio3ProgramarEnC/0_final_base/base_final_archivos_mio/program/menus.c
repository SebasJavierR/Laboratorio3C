/*Standard Library*/
#include <stdio.h>
/*File Header*/
#include "globals.h"
/*File Header*/
#include "menus.h"

int mostrarMenu(comida* comidas)
{
    int opcion;
    opcion = -1;

    while((opcion <= AC_NINGUNA) || (opcion >= AC_MAX))    
    {
      puts("Menu - Elegir comida:");
      printf("1.Comida 1 (%s) $%d\n", comidas[0].descripcion, comidas[0].precio);
      printf("2.Comida 2 (%s) $%d\n", comidas[1].descripcion, comidas[1].precio);
      printf("3.Comida 3 (%s) $%d\n", comidas[2].descripcion, comidas[2].precio);
      if ((scanf("%d", &opcion) != 1)
        || (opcion <= AC_NINGUNA)
        || (opcion >= AC_MAX))
      {
        puts("Opcion Invalida!");
      }
    }
    return opcion;
}
