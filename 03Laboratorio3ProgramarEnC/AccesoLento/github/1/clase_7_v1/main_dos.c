#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "defines.h"
#include "globals.h"
#include "semaforos.h"
#include "memoria.h"
#include "funciones.h"

int main(int argc, char *argv[])
{
  int idMemoria;
  int i;
  int aleatorio;
  dato* memoria;
 
  memoria = 0; /*NULL*/
  idMemoria = 0;
  i = 0;
  aleatorio = 0;
  memoria = (dato*)creoMemoria(sizeof(dato)*CANTIDAD, &idMemoria, CLAVE_BASE);

  if (argc != 1)
  {
    printf("Uso: ./dos \n");
    return 0;
  }

  printf("Atención: Recuerde levantar el programa incial \"uno\". Presione \"enter\" para continuar...");
  getchar();
  limpiarPantalla();

  while(1)
  {
    printf("Leemos en la memoria\n");
    for (i=0; i < CANTIDAD; i++)
    {
      printf("Leído %d %c\n", memoria[i].numero, memoria[i].letra);
      sleep(1);
    }
    printf("Dejamos de leer la memoria\n");
    sleep(10);
  }
  liberoMemoria(idMemoria, (char*)memoria);
  return 0;
}
