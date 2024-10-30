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

int opciones(void)
{
    int opcion;

    printf("Menu\n\n");
    printf("Elija: ");
    printf("COMIDA[1] // PALITOS[2] // HOJAS[3] // TIERRA[4]\n");
    while ((scanf(" %d", &opcion) != 1) || (opcion < 0) || (opcion > 4))
    {
        printf("No valido\n\n");
        printf("Elija: ");
        printf("COMIDA[1] // PALITOS[2] // HOJAS[3] // TIERRA[4]\n");
    }
    return opcion;
}

void* carreraThread(void* parametro)
{
  mensaje msg;
  tablero* datosThread;
  int pasosJugador;
  char nombreJugador[LARGO_NOMBRE];
  int finJuego;
  int i = 0;
  int opcion = 0;

  int comida = 0;
  int palitos = 0;
  int hojas = 0;
  int tierra = 0;

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
    lockMutex(&mutex);
    recibirMensaje(datosThread->idColaMensajes, MSG_TABLERO, &msg);

    printf("Trabaja la hormiga %d, opcion %d\n", i, opcion);
    esperarSemaforo(datosThread->idSemaforo);
    pasosJugador = leerPasosJugador(datosThread->memoria, msg.intRte - MSG_JUGADOR);
    if (pasosJugador <= TOTAL_PASOS)
    {
      enviarMensaje(datosThread->idColaMensajes, MSG_JUGADOR + i, MSG_TABLERO, EVT_FIN, "");
    }
    opcion = opciones();
    switch (opcion)
    {
    case EVT_NINGUNO:
        break;
    case EVT_COMIDA:
        comida = comida + 1;
        enviarMensaje(datosThread->idColaMensajes, MSG_JUGADOR + i, MSG_TABLERO, EVT_CAMINAR, "COMIDA");
        break;
    case EVT_PALITOS:
        palitos = palitos + 1;
        enviarMensaje(datosThread->idColaMensajes, MSG_JUGADOR + i, MSG_TABLERO, EVT_CAMINAR, "PALITOS");
        break;
    case EVT_HOJAS:
        hojas = hojas + 1;
        enviarMensaje(datosThread->idColaMensajes, MSG_JUGADOR + i, MSG_TABLERO, EVT_CAMINAR, "HOJAS");
        break;
    case EVT_TIERRA:
        tierra = tierra + 1;
        enviarMensaje(datosThread->idColaMensajes, MSG_JUGADOR + i, MSG_TABLERO, EVT_CAMINAR, "TIERRA");
        break;
    case EVT_FIN:
        printf("fin...\n");
        finJuego = 1;
        enviarMensaje(datosThread->idColaMensajes, MSG_JUGADOR + i, MSG_TABLERO, EVT_FIN, "");
        break;
    default:
        printf("INVALIDO\n");
    }
    levantarSemaforo(datosThread->idSemaforo);
    if (opcion != EVT_FIN)
    {
        opcion = opciones();
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
