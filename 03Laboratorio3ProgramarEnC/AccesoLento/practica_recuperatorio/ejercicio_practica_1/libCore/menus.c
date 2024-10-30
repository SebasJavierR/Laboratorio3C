/*Standard Library*/
#include "stdio.h"
/*File Header*/
#include "menus.h"

int mostrarMenuPostre(char* letraMenu)
{
    int opcion;
    opcion = -1;

    while((opcion <= AC_NINGUNA) || (opcion >= AC_MAX))    
    {
      printf("Menu %s\n", letraMenu);
      printf("¿Quiere Postre?\n");
      printf("1.Si\n");
      printf("2.No\n");
      if ((scanf("%d", &opcion) != 1)
        || (opcion <= AC_NINGUNA)
        || (opcion >= AC_MAX))
      {
        printf("Opcion Invalida!\n");
      }
    }
    return opcion;
}
