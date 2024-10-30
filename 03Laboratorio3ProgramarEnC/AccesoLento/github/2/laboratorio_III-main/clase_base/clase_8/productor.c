#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "defines.h"
#include "globals.h"
#include "funciones.h"
#include "semaforos.h"

void iniciarMemoria(dato* memoria)
{
  memset(memoria[POS_INI_MEM].nombreJugador,0x00,sizeof(memoria[POS_INI_MEM].nombreJugador));
  memoria[POS_INI_MEM].numeroPensado = 0;
  memoria[POS_INI_MEM].estadoAcierto = 0;
}

void iniciarMemoriaInicial(inicial* memoria)
{
  memoria[POS_INI_MEM].inicializado = 1;
}
