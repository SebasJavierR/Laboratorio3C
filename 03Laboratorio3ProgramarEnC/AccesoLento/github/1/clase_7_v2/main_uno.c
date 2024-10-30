#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "time.h"
#include "defines.h"
#include "globals.h"
#include "semaforos.h"
#include "memoria.h"
#include "funciones.h"
#include "productor.h"
int main(int argc, char *argv[])
{
  int idMemoria;
  int aleatorio;
  dato* memoria;

  if (argc != 1)
  {
    printf("Uso: ./uno \n");
    return 0;
  }

  memoria = 0; /*NULL*/
  idMemoria = 0;
  aleatorio = 0;

  srand(time(0));
  memoria = (dato*)creoMemoria(sizeof(dato)*CANTIDAD, &idMemoria, CLAVE_BASE);

  iniciarMemoria(memoria);

  while(1)
  {
    printf("Escribimos en la memoria\n");
    escribirMemoria(memoria);
    sleep(INTERVALO_UNO_S);
  }
  liberoMemoria(idMemoria, (char*)memoria);
  return 0;
}
