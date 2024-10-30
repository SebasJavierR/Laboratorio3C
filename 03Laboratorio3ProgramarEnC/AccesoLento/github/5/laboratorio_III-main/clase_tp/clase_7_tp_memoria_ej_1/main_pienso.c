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
  int localPiensoUnNumero;
  dato* memoria;
  inicial* memoriaInicial;

  if (argc != 1)
  {
    printf("Uso: ./pienso \n");
    return 0;
  }

  memoria = 0; /*NULL*/
  memoriaInicial = 0; /*NULL*/
  idMemoria = 0;
  idMemoriaInicial = 0;
  idSemaforo = 0;
  localPiensoUnNumero = 0;

  srand(time(0));
  idSemaforo = creoSemaforo();
  iniciaSemaforo(idSemaforo, VERDE);
  memoriaInicial = (inicial*)creoMemoria(sizeof(inicial)*CANTIDAD, &idMemoriaInicial, CLAVE_BASE_INI);
  iniciarMemoriaInicial(memoriaInicial);

  memoria = (dato*)creoMemoria(sizeof(dato)*CANTIDAD, &idMemoria, CLAVE_BASE);
  iniciarMemoria(memoria);

  limpiarPantalla();
  printf("Pensando numero...\n");
  localPiensoUnNumero = obtenerNumeroAleatorio(NUM_MIN, NUM_MAX);
  printf("Numero pensado %d\n", localPiensoUnNumero);

  while(1)
  {
    esperaSemaforo(idSemaforo);
    if (leerNumeroPensado(memoria) > 0 && leerEstadoAcierto(memoria) == 0)
    {
      if (leerNumeroPensado(memoria) != localPiensoUnNumero)
      {
        escribirNumeroPensado(memoria, 0);
        escribirEstadoAcierto(memoria, 0);
      }
      else
      {
        escribirEstadoAcierto(memoria, 1);
        limpiarPantalla();
        printf("Jugador:\t%s\tHa ganado el juego\n", leerNombreJugador(memoria));
        printf("El número pensado era el %d\n", localPiensoUnNumero);
        levantaSemaforo(idSemaforo);
        break;
      }
    }
    levantaSemaforo(idSemaforo);
    usleep(INTERVALO_PIENSO_MS * 1000);
  }
  liberoMemoria(idMemoriaInicial, (char*)memoriaInicial);
  liberoMemoria(idMemoria, (char*)memoria);
  return 0;
}
