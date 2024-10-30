#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "defines.h"
#include "globals.h"
#include "funciones.h"

void verificarMemoriaIni(dato* memoria)
{
  int i;
  i = 0;
  while (memoria[i].inicializado != 1)
  {
    printf("Atención: Recuerde levantar el programa inicial \"uno\". Presione \"enter\" para continuar...\n");
    getchar();
  }

  limpiarPantalla();
}

void leerMemoria(dato* memoria)
{
  int i;
  printf("Leemos en la memoria\n");
  for (i=0; i < CANTIDAD; i++)
  {
    printf("Leído %d %c\n", memoria[i].numero, memoria[i].letra);
    sleep(1);
  }
  printf("Dejamos de leer la memoria\n");
}
