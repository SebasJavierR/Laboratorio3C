#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "defines.h"
#include "globals.h"
#include "funciones.h"

void verificarMemoriaInicial(inicial* memoria)
{
  while (memoria[POS_INI_MEM].inicializado != 1)
  {
    printf("Atención: Recuerde levantar el programa inicial \"pienso\". Presione \"enter\" para continuar...\n");
    getchar();
  }

  limpiarPantalla();
}

int leerNumeroPensado(dato* memoria)
{
  return memoria[POS_INI_MEM].numeroPensado;
}

int leerEstadoAcierto(dato* memoria)
{
  return memoria[POS_INI_MEM].estadoAcierto;
}

char* leerNombreJugador(dato* memoria)
{
  return memoria[POS_INI_MEM].nombreJugador;
}
