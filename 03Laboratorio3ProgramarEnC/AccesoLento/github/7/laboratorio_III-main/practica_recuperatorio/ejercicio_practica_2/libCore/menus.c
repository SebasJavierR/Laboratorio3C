/*Standard Library*/
#include "stdio.h"
/*File Header*/
#include "menus.h"

int mostrarMenuAccion()
{
    int opcion;
    opcion = -1;

    while((opcion <= M_AC_NINGUNA) || (opcion >= M_AC_MAX))    
    {
      printf("Ingrese una opción:\n");
      printf("1.Leer Panel\n");
      printf("2.Escribir Panel\n");
      if ((scanf("%d", &opcion) != 1)
        || (opcion <= M_AC_NINGUNA)
        || (opcion >= M_AC_MAX))
      {
        printf("Opcion Invalida!\n");
      }
    }
    return opcion;
}

int mostrarMenuPanel()
{
    int opcion;
    opcion = -1;

    while((opcion <= M_PANEL_NINGUNA) || (opcion >= M_PANEL_MAX))    
    {
      printf("Ingrese una opción:\n");
      printf("1.Panel 1\n");
      printf("2.Panel 2\n");
      printf("2.Panel 3\n");
      if ((scanf("%d", &opcion) != 1)
        || (opcion <= M_PANEL_NINGUNA)
        || (opcion >= M_PANEL_MAX))
      {
        printf("Opcion Invalida!\n");
      }
    }
    return opcion;
}
