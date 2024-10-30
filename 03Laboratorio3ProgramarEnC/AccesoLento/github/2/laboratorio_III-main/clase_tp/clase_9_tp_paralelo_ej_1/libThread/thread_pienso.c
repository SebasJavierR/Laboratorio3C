/*Standard Library*/
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "string.h"
#include "pthread.h"
/*Headers Library*/
#include "libCore/defines.h"
#include "libCore/globals.h"
#include "libCommon/aleatorio.h"
#include "libCommon/hilos.h"
/*File Header*/
#include "thread_pienso.h"

void* piensoThread(void* parametro)
{
  int numeroPensadoJugador;
  int intervalo;
  jugador* datosThread;
  numeroPensadoJugador = 0;
  intervalo = 0;
  datosThread = (jugador*)parametro;
  while(1)
  {
    lockMutex(&mutex);
    printf("Jugador %d: Pensando número...\n", datosThread->nroJugador);
    numeroPensadoJugador = obtenerNumeroAleatorio(NUM_MIN, NUM_MAX);
    printf("Jugador %d: Número pensado %d\n",  datosThread->nroJugador, numeroPensadoJugador);
    datosThread->cantidadIntentos++;
    if (numeroPensadoJugador == numeroPensadoJugador)
    {
       datosThread->alguienAcerto = datosThread->nroJugador;
       break;
    }
    intervalo = obtenerNumeroAleatorio(INTERVALO_JUGADOR_MS_MIN, INTERVALO_JUGADOR_MS_MAX);
    unlockMutex(&mutex);
    usleep(intervalo * 1000);
  }
  return 0;
}
