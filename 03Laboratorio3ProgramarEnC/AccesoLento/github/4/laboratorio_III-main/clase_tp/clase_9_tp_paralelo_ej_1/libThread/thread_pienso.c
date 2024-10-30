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
    printf("Jugador %d: Pensando número... (Intento Nro %d)\n", datosThread->nroJugador, datosThread->cantidadIntentos);
    /* Forzamos una espera para que se modifique el número aleatorio */
    sleep(1);
    numeroPensadoJugador = obtenerNumeroAleatorio(NUM_MIN, NUM_MAX);
    printf("Jugador %d: Número pensado %d\n",  datosThread->nroJugador, numeroPensadoJugador);
    datosThread->cantidadIntentos++;
    if (numeroPensadoJugador == datosThread->numeroPensado)
    {
       datosThread->alguienAcerto = datosThread->nroJugador;
       printf("Ganó el jugador %d\n", datosThread->alguienAcerto);
       unlockMutex(&mutex);
       return 0;
    }
    intervalo = obtenerNumeroAleatorio(INTERVALO_JUGADOR_MS_MIN, INTERVALO_JUGADOR_MS_MAX);
    unlockMutex(&mutex);
    usleep(intervalo * 1000);
  }
  return 0;
}
