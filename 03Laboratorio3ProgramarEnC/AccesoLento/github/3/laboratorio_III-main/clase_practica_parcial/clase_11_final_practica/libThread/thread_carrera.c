/*Standard Library*/
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "string.h"
#include "pthread.h"
/*Headers Library*/
#include "libCommon/aleatorio.h"
#include "libCommon/hilos.h"
#include "libCommon/cola.h"
#include "libCommon/semaforos.h"
#include "libCore/defines.h"
#include "libCore/globals.h"
#include "libCore/funciones.h"
/*File Header*/
#include "thread_carrera.h"

void* carreraThread(void* parametro)
{
  mensaje msg;
  tablero* datosThread;
  int pasosJugador;
  char nombreJugador[LARGO_NOMBRE];
  int finJuego;
  int i;

  msg.longDest = MSG_NADIE;
  msg.intRte = MSG_NADIE;
  msg.intEvento = EVT_NINGUNO;
  memset(msg.charMensaje,0x00,LARGO_MENSAJE);

  memset(nombreJugador, 0x00, sizeof(LARGO_NOMBRE));

  datosThread = (tablero*)parametro;
  pasosJugador = 0;
  finJuego = 0;

  for (i = 0; i < cantidadJugadores; i++)
  {
    enviarMensaje(datosThread->idColaMensajes, MSG_JUGADOR + i, MSG_TABLERO, EVT_CAMINAR, "");
  }

  while(1)
  {
    recibirMensaje(datosThread->idColaMensajes, MSG_TABLERO, &msg);
    switch(msg.intEvento)
    {
      case EVT_NINGUNO:
        break;
      case EVT_CAMINAR_FIN:
        esperarSemaforo(datosThread->idSemaforo);
        pasosJugador = leerPasosJugador(datosThread->memoria, msg.intRte - MSG_JUGADOR);
        strcpy(nombreJugador, leerNombreJugador(datosThread->memoria, msg.intRte - MSG_JUGADOR));
        levantarSemaforo(datosThread->idSemaforo);
        if (pasosJugador < TOTAL_PASOS)
        {
          enviarMensaje(datosThread->idColaMensajes, msg.intRte, MSG_TABLERO, EVT_CAMINAR, "");
        }
        else
        {
          finJuego = 1;
          printf("Ganó jugador %s\n", nombreJugador);
          for (i = 0; i < cantidadJugadores; i++)
          {
            enviarMensaje(datosThread->idColaMensajes, MSG_JUGADOR + i, MSG_TABLERO, EVT_FIN, "");
          }
          break;
        }
        break;
      default:
        break;
    }
    unlockMutex(&mutex);
    if (finJuego == 1)
    {
      break;
    }
    usleep(INTERVALO_CARRERA_MS * 1000);
  }
  return 0;
}
