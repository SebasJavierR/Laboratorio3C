/*Standard Library*/
#include "stdio.h"
/*Headers Library*/
#include "libCommon/pantalla.h"
#include "defines.h"
#include "globals.h"
/*File Header*/
#include "memoria_core.h"

void configurarMemoriaInicial(inicial* memoria)
{
  memoria[POS_INI_MEM].inicializado = 1;
}

void verificarMemoriaInicial(inicial* memoria)
{
  while (memoria[POS_INI_MEM].inicializado != 1)
  {
    printf("Atención: Recuerde levantar el programa inicial \"uno\". Presione \"enter\" para continuar...\n");
    getchar();
  }

  limpiarPantalla();
}
