/*Standard Library*/
#include "stdio.h"
/*File Header*/
#include "menu_base.h"

int mostrarMenu()
{
    int opcion;
    opcion = -1;

    while((opcion <= AC_NINGUNA) || (opcion >= AC_MAX))    
    {
      printf("Jugador \n");
      printf("Menu - Opcion Comida\n");
      printf("[1] // [2] // [3]\n");
      printf("Ingresar Opcion:\n");
      if ((scanf("%d", &opcion) != 1) || (opcion <= AC_NINGUNA) || (opcion >= AC_MAX))
      {
        printf("Opcion Invalida!\n");
      }
    }
    return opcion;
}
