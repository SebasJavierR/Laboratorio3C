/*Librerias*/
#include <stdio.h>
/*Librerias Propias*/
#include "framework/pantalla.h"
/*Archivo .h*/
#include "menus.h"


int mostrarMenuPartido(char* nombreJugador)
{
    int tecla;
    tecla = 0;
    while(tecla != TECLA_ENTER)    
    {
      printf("Jugador %s\n", nombreJugador);
      tecla = solicitarCaracter("Presione [Enter] para patear al arco");
    }
    return AC_PATEAR;
}
