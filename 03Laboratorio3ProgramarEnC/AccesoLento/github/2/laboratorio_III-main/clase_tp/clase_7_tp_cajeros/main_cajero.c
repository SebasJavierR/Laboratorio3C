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
#include "consumidor.h"
int main(int argc, char *argv[])
{
  int idMemoria;
  int idSemaforo;
  int cajero;
  int intervalo;
  dato* memoria;

  if (argc != 2)
  {
    printf("Uso: ./cajero [1-3] \n");
    return 0;
  }

  cajero = atoi(argv[1]);

  if (cajero < 1 || cajero >3)
  {
    printf("Uso: ./cajero [1-3] \n");
    return 0;
  }

  limpiarPantalla();
  printf("Cajero\t%d\n", cajero);

  memoria = 0; /*NULL*/
  idMemoria = 0;
  idSemaforo = 0;

  srand(time(0));

  idSemaforo = creoSemaforo();
  memoria = (dato*)creoMemoria(sizeof(dato)*CANTIDAD, &idMemoria, CLAVE_BASE);

  verificarMemoriaIni(memoria);

  while(1)
  {
    esperaSemaforo(idSemaforo);
    limpiarPantalla();
    cargarCajero(memoria, cajero);
    levantaSemaforo(idSemaforo);
    intervalo = obtenerNumeroAleatorio(INTERVALO_CAJERO_MIN_MS, INTERVALO_CAJERO_MAX_MS);
    usleep(intervalo * 1000);
  }
  liberoMemoria(idMemoria, (char*)memoria);
  return 0;
}
