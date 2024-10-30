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
  int idMemoriaInicial;
  int idSemaforo;
  dato* memoria;
  inicial* memoriaInicial;
  int vias;

  if (argc != 2)
  {
    printf("Uso: ./peaje [vias]\n");
    return 0;
  }

  memoria = 0; /*NULL*/
  memoriaInicial = 0; /*NULL*/
  idMemoria = 0;
  idMemoriaInicial = 0;
  idSemaforo = 0;
  vias = atoi(argv[1]);

  srand(time(0));
  idSemaforo = creoSemaforo();
  iniciaSemaforo(idSemaforo, VERDE);
  memoriaInicial = (inicial*)creoMemoria(sizeof(inicial)*CANTIDAD, &idMemoriaInicial, CLAVE_BASE_INI);
  iniciarMemoriaInicial(memoriaInicial);

  memoria = (dato*)creoMemoria(sizeof(dato)*CANTIDAD, &idMemoria, CLAVE_BASE);
  iniciarMemoria(memoria, 4);

  limpiarPantalla();

  while(1)
  {
    esperaSemaforo(idSemaforo);

    levantaSemaforo(idSemaforo);
    usleep(INTERVALO_PIENSO_MS * 1000);
  }
  liberoMemoria(idMemoriaInicial, (char*)memoriaInicial);
  liberoMemoria(idMemoria, (char*)memoria);
  return 0;
}
