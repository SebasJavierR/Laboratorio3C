/*Standard Library*/
#include <stdio.h>
/*File Header*/
#include "menus.h"

int mostrarMenuPartido(char* nombreJugador)
{
    int tecla;
    tecla = 0;
;
    while(tecla != TECLA_ENTER)    
    {
      printf("Jugador %s\n", nombreJugador);
      puts("Presione [Enter] para patear al arco");
      tecla = getchar();
    }
    return AC_PATEAR;
}
