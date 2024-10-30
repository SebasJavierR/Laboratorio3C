#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "defines.h"
#include "globals.h"
#include "semaforos.h"
#include "memoria.h"
#include "funciones.h"
#include "consumidor.h"

int main(int argc, char *argv[])
{
  int idMemoria;
  int aleatorio;
  dato* memoria;

  if (argc != 1)
  {
    printf("Uso: ./dos \n");
    return 0;
  }

  memoria = 0; /*NULL*/
  idMemoria = 0;
  aleatorio = 0;
  memoria = (dato*)creoMemoria(sizeof(dato)*CANTIDAD, &idMemoria, CLAVE_BASE);

  verificarMemoriaIni(memoria);

  while(1)
  {
    leerMemoria(memoria);
    sleep(INTERVALO_DOS_S);
  }
  liberoMemoria(idMemoria, (char*)memoria);
  return 0;
}
