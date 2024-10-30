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

int validarGanador(partido* datosThread)
{
  int i;
  int j;
  int goles;
  int intentos;
  int goles2;
  int intentos2;
  for (i = 0; i < cantidadJugadores; i++)
  {
    goles = leerGoles(datosThread->memoria, i);
    if (goles >= MAX_GOLES)
    {
      for (j = 0; j < cantidadJugadores; j++)
      {
        if (i != j)
        {
          intentos = leerIntentos(datosThread->memoria, i);
          intentos2 = leerIntentos(datosThread->memoria, j);
          goles2 = leerGoles(datosThread->memoria, j);
          if (intentos == intentos2 && goles > goles2)
          {
            return i;
          }
        }
      }
    }
  }
  return -1;
}

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
  int intentosJugador;
  int ganador;
  int i;
  int jugadorMensaje;
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
  intentosJugador = 0;
  ganador = -1;
  jugadorMensaje = 0;
  memset(nomJugador, 0x00, sizeof(LARGO_NOMBRE));

  for (i = 0; i < cantidadJugadores; i++)
  {
    intentosJugador = leerIntentos(datosThread->memoria, i);
    strcpy(nomJugador, obtenerNombreJugadorPorNumero(i));
    intentosJugador++;
    printf("Intento Nº %d\n", intentosJugador);
    opcion = mostrarMenuPartido(nomJugador);
    partidoAcciones(opcion, datosThread->idColaMensajes, i);
  }

  while(1)
  {
    lockMutex(&mutex);
    recibirMensaje(datosThread->idColaMensajes, MSG_PARTIDO, &msg);
    unlockMutex(&mutex);
    usleep(100 * 1000);

    numJugador = msg.intRte - MSG_JUGADOR;
    strcpy(nomJugador, obtenerNombreJugadorPorNumero(numJugador));

    switch(msg.intEvento)
    {
      case EVT_NINGUNO:
        break;
      case EVT_GOL:
        printf("Gol de %s\n", nomJugador);
        for (i = 0; i < cantidadJugadores; i++)
        {
          printf("Jugador %s: %d goles\n", obtenerNombreJugadorPorNumero(i), leerGoles(datosThread->memoria, i));
        }
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

    ganador = validarGanador(datosThread);
    if (ganador >= 0)
    {
      strcpy(nomJugador, obtenerNombreJugadorPorNumero(ganador));
      printf("Jugador %s: ganó el partido con %d goles\n", nomJugador, leerGoles(datosThread->memoria, ganador));
      for (i = 0; i < cantidadJugadores; i++)
      {
        lockMutex(&mutex);
        escribirFinPartido(datosThread->memoria, i, 1);
        enviarMensaje(datosThread->idColaMensajes, MSG_JUGADOR + i, MSG_PARTIDO, EVT_NINGUNO, "");
        unlockMutex(&mutex);
        usleep(100 * 1000);
      }
      break;
    }

    intentosJugador = leerIntentos(datosThread->memoria, jugadorMensaje);
    strcpy(nomJugador, obtenerNombreJugadorPorNumero(jugadorMensaje));
    intentosJugador++;
    printf("Intento Nº %d\n", intentosJugador);
    opcion = mostrarMenuPartido(nomJugador);
    partidoAcciones(opcion, datosThread->idColaMensajes, jugadorMensaje);

    if (jugadorMensaje < (cantidadJugadores - 1))
    {
      jugadorMensaje++;
    }
    else
    {
      jugadorMensaje = 0;
    }

    usleep(INTERVALO_PARTIDO_MS * 1000);
  }
  return 0;
}
