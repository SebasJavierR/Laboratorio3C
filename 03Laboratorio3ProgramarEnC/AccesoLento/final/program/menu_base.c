/*Librerias*/
#include "stdio.h"
/*Header*/
#include "menu_base.h"

int menuBase(int hormiga_actual)
{
    int opcion;
    opcion = -1;

    while((opcion <= OP_NINGUNA) || (opcion >= OP_MAX))    
    {
      printf("------------------------------------------\n");
      printf("          Menu - Hormiga [%d]\n\n", hormiga_actual + 1);
      printf("Comida[1] // Agua[2] // Palo[4] // Hoja[4]\n");
      printf("Ingresar Opcion:\n");
      if ((scanf("%d", &opcion) != 1) || (opcion <= OP_NINGUNA) || (opcion >= OP_MAX))
      {
        printf("Opcion Invalida!\n");
      }
    }
    printf("*fin de uso del menu\n");
    printf("------------------------------------------\n");
    return opcion;
}
