/*Standard Library*/
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "string.h"
#include "pthread.h"
/*Headers Library*/
#include "libCommon/semaforos.h"
#include "libCommon/aleatorio.h"
#include "libCommon/hilos.h"
#include "libCommon/cola.h"
#include "libCore/defines.h"
#include "libCore/globals.h"
#include "libCore/funciones.h"
/*File Header*/
#include "thread_jugadores.h"

void* jugadoresThread(void* parametro)
{
  mensaje msg;
  jugador* datosThread;
  int pasosAleatorio;
  int intervalo;
  int pasosJugador;
  char nombreJugador[LARGO_NOMBRE];
  int tiempoEspera;
  int mitadCamino;
  int finJuego;
  
  msg.longDest = MSG_NADIE;
  msg.intRte = MSG_NADIE;
  msg.intEvento = EVT_NINGUNO;
  memset(msg.charMensaje,0x00,LARGO_MENSAJE);

  datosThread = (jugador*)parametro;

  memset(nombreJugador, 0x00, sizeof(LARGO_NOMBRE));

  pasosAleatorio = 0;
  pasosJugador = 0;
  tiempoEspera = 0;
  mitadCamino = 0;
  finJuego = 0;

  strcpy(nombreJugador, obtenerNombreJugador(datosThread->nroJugador));
  esperarSemaforo(datosThread->idSemaforo);
  escribirNombreJugador(datosThread->memoria, datosThread->nroJugador, nombreJugador);
  levantarSemaforo(datosThread->idSemaforo);
  intervalo = obtenerIntervaloJugador(datosThread->nroJugador);

  while(msg.intEvento != EVT_FIN)
  {
    lockMutex(&mutex);
    recibirMensaje(datosThread->idColaMensajes, MSG_JUGADOR + datosThread->nroJugador, &msg);
    switch(msg.intEvento)
    {
      case EVT_NINGUNO:
        break;
      case EVT_CAMINAR:
        pasosAleatorio = obtenerNumeroAleatorio(PASOS_MIN, PASOS_MAX);
        pasosJugador += pasosAleatorio;
        esperarSemaforo(datosThread->idSemaforo);
        escribirPasosJugador(datosThread->memoria, datosThread->nroJugador, pasosJugador);
        levantarSemaforo(datosThread->idSemaforo);
        tiempoEspera = intervalo * pasosAleatorio;
        /*
        if (mitadCamino == 0 && pasosJugador >= 50)
        {
          if (datosThread->nroJugador == 0)
          {
            tiempoEspera = 5 * 1000;
          }
          mitadCamino = 1;
        }
        */
        printf("Jugador %s: metio %d gol\n", nombreJugador, pasosAleatorio);
        /*printf("Jugador %s: espera %d ms\n", nombreJugador, tiempoEspera);*/
        printf("Jugador %s: total %d pasos\n", nombreJugador, pasosJugador);
        enviarMensaje(datosThread->idColaMensajes, MSG_TABLERO, MSG_JUGADOR + datosThread->nroJugador, EVT_CAMINAR_FIN, "");
        break;
      case EVT_FIN:
        finJuego = 1;
        printf("Jugador %s: fin de juego\n", nombreJugador);
        break;
      default:
        break;
    }
    unlockMutex(&mutex);
    if (finJuego == 1)
    {
      break;
    }
    tiempoEspera = tiempoEspera != 0 ? tiempoEspera : intervalo;
    usleep(tiempoEspera * 1000);
  }
  return 0;
}
