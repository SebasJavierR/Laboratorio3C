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
#include "libCore/defines.h"
#include "libCore/globals.h"
#include "libCore/funciones.h"
#include "libCore/menus.h"
/*File Header*/
#include "thread_partido.h"

int partidoAcciones(int opcion, int idColaMensajes, int numJugador)
{
  int evento;
  evento = -1;
  switch (opcion) {
    case AC_PATEAR:
      evento = obtenerNumeroAleatorio(EVENTO_MIN, EVENTO_MAX);
      lockMutex(&mutex);
      enviarMensaje(idColaMensajes, MSG_JUGADOR + numJugador, MSG_PARTIDO, evento, "");
      unlockMutex(&mutex);
      break;
    default:
      break;
  }
  return evento;
}

void* partidoThread(void* parametro)
{
  mensaje msg;
  partido* datosThread;
  int opcion;
  int numJugador;
  int evento;
  int golesJugador;
  char nomJugador[LARGO_NOMBRE];

  msg.longDest = MSG_NADIE;
  msg.intRte = MSG_NADIE;
  msg.intEvento = EVT_NINGUNO;
  memset(msg.charMensaje,0x00,LARGO_MENSAJE);

  datosThread = (partido*)parametro;
  opcion = -1;
  numJugador = 0;
  evento = EVT_NINGUNO;
  golesJugador = 0;

  memset(nomJugador, 0x00, sizeof(LARGO_NOMBRE));

  while(1)
  {
    lockMutex(&mutex);
    golesJugador = leerGoles(datosThread->memoria, numJugador);
    unlockMutex(&mutex);
  
    strcpy(nomJugador, obtenerNombreJugadorPorNumero(numJugador));
    opcion = mostrarMenuPartido(nomJugador);
    evento = partidoAcciones(opcion, datosThread->idColaMensajes, numJugador);

    switch(evento)
    {
      case EVT_NINGUNO:
        break;
      case EVT_GOL:
        printf("Gol de %s\n", nomJugador);
        golesJugador++;
        break;
      case EVT_FUERA:
        printf("Jugador %s: fuera\n", nomJugador);
        break;
      case EVT_PALO:
        printf("Jugador %s: palo\n", nomJugador);
        break;
      case EVT_ATAJA:
        printf("Jugador %s: atajado\n", nomJugador);
        break;
      default:
        break;
    }
 
    if (golesJugador >= MAX_GOLES)
    {
      printf("Jugador %s: ganó el partido con %d goles\n", nomJugador, golesJugador);
      for (numJugador = 0; numJugador < cantidadJugadores; numJugador++)
      {
        lockMutex(&mutex);
        escribirFinPartido(datosThread->memoria, numJugador, 1);
        unlockMutex(&mutex);
      }
      break;
    }

    if (numJugador < cantidadJugadores - 1)
    {
      numJugador++;
    }
    else
    {
      numJugador = 0;
    }

    usleep(INTERVALO_PARTIDO_MS * 1000);
  }
  return 0;
}
