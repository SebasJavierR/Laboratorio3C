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
    printf("Atención: Recuerde levantar el programa inicial \"peaje\". Presione \"enter\" para continuar...\n");
    getchar();
  }

  limpiarPantalla();
}
