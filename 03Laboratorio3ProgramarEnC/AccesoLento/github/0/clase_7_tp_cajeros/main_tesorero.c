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
  dato* memoria;

  if (argc != 1)
  {
    printf("Uso: ./tesorero \n");
    return 0;
  }

  memoria = 0; /*NULL*/
  idMemoria = 0;
  idSemaforo = 0;

  srand(time(0));

  idSemaforo = creoSemaforo();
  iniciaSemaforo(idSemaforo, VERDE);
  memoria = (dato*)creoMemoria(sizeof(dato)*CANTIDAD, &idMemoria, CLAVE_BASE);

  iniciarMemoria(memoria);
  inicializarResumenes();

  while(1)
  {
    esperaSemaforo(idSemaforo);
    limpiarPantalla();
    leerDepositosCajeros(memoria);
    imprimirResumen();
    levantaSemaforo(idSemaforo);
    usleep(INTERVALO_TESORERO_MS * 10000);
  }
  liberoMemoria(idMemoria, (char*)memoria);
  return 0;
}
