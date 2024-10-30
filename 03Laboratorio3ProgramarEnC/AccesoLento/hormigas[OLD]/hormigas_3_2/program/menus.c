/*Librerias*/
#include "stdio.h"
/*Header*/
#include "menus.h"

int menuBase(int numeroHormiga)
{
    int opcion;
    opcion = -1;

    while((opcion <= AC_NINGUNA) || (opcion >= AC_MAX))    
    {
      printf("   -----\n");
      printf("Menu - Hormiga [%d]\n\n", numeroHormiga);
      printf("Comida[1] // Hoja[2] // Palo[4] // Agua[4]\n");
      printf("Ingresar Opcion:\n");
      if ((scanf("%d", &opcion) != 1) || (opcion <= AC_NINGUNA) || (opcion >= AC_MAX))
      {
        printf("Opcion Invalida!\n");
      }
    }
    return opcion;
}
