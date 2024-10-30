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
  int intervaloEspera;

  if (argc != 2)
  {
    printf("Uso: ./autos [vias] \n");
    return 0;
  }

  memoria = 0; /*NULL*/
  memoriaInicial = 0; /*NULL*/
  idMemoria = 0;
  idMemoriaInicial = 0;
  idSemaforo = 0;
  intervaloEspera = 0;
  vias = atoi(argv[1]);

  if (vias <= 0)
  {
    printf("Error: vias debe ser un valor mayor a 0\n");
    return 0;
  }

  srand(time(0));

  idSemaforo = creoSemaforo();
  
  memoriaInicial = (inicial*)creoMemoria(sizeof(inicial)*CANTIDAD, &idMemoriaInicial, CLAVE_BASE_INI);
  verificarMemoriaInicial(memoriaInicial);

  memoria = (dato*)creoMemoria(sizeof(dato)*CANTIDAD, &idMemoria, CLAVE_BASE);

  limpiarPantalla();

  while(1)
  {
    esperaSemaforo(idSemaforo);

    levantaSemaforo(idSemaforo);
    intervaloEspera = obtenerNumeroAleatorio(INTERVALO_AUTOS_MS_MIN, INTERVALO_AUTOS_MS_MAX);
    usleep(intervaloEspera * MICRO_A_MILLI);
  }
  liberoMemoria(idMemoriaInicial, (char*)memoriaInicial);
  liberoMemoria(idMemoria, (char*)memoria);
  return 0;
}
