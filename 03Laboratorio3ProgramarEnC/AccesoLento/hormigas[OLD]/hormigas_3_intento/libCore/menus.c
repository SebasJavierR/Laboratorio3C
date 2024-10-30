/*Standard Library*/
#include "stdio.h"
/*File Header*/
#include "menus.h"

int mostrarMenuReina(int numeroHormiga)
{
    int opcion;
    opcion = -1;

    while((opcion <= AC_NINGUNA) || (opcion >= AC_MAX))    
    {
      printf("Hormiga %d\n", numeroHormiga);
      printf("Menu\n");
      printf("1.Juntar Comida\n");
      printf("2.Juntar Hoja\n");
      printf("3.Juntar Rama\n");
      printf("4.Juntar Agua\n");
      printf("Ingresar Opcion:\n");
      if ((scanf("%d", &opcion) != 1)
        || (opcion <= AC_NINGUNA)
        || (opcion >= AC_MAX))
      {
        printf("Opcion Invalida!\n");
      }
    }
    return opcion;
}
