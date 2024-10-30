/*Librerias*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <signal.h>
/*Librerias Propias*/
#include "framework/memoria.h"
#include "framework/memoria_ini.h"
#include "framework/cola.h"
#include "framework/hilos.h"
#include "framework/aleatorio.h"
#include "framework/pantalla.h"
#include "framework/signals.h"
#include "program/defines.h"
#include "program/globals.h"
#include "program/funciones.h"
#include "program/productor.h"
#include "program/consumidor.h"
#include "program/memoria_core.h"
#include "hilos/thread_jugador.h"

pthread_t* idHilo;
pthread_attr_t atributos;
jugador* datosThread;

void liberarRecursos(void)
{
  free(idHilo);
  free(datosThread);
  destruirMutex(&mutex);
  destruirAttr(&atributos);
}

void manejadorSignals(int signum)
{
    if (signum == SIGINT || signum == SIGALRM)
    {
      puts("Liberando Recursos...");
      liberarRecursos();
      puts("Proceso Finalizado");
      exit(0);
    }
}

int main(int argc, char *argv[])
{
  int idColaMensajes;
  int idMemoria;
  dato_memoria* memoria;
  dato_memoria_ini* memoriaIni;
  int idMemoriaIni;
  int i;

  if (argc != 1)
  {
    puts("Uso: ./jugador");
    return -1;
  }

  memoriaIni = 0; /*NULL*/
  idMemoriaIni = 0;
  memoria = 0;
  idMemoria = 0;
  idHilo = 0;
  cantidadJugadores = 2;

  srand(time(0));

  iniciarMutex(&mutex);
  iniciarAttr(&atributos);
  asignarEstadoJoinableAttr(&atributos);

  crearSignal(SIGINT, manejadorSignals);
  crearSignal(SIGALRM, manejadorSignals);

  idColaMensajes = crearColaMensajes();
  memoria = (dato_memoria*)crearMemoria(sizeof(dato_memoria)*cantidadJugadores, &idMemoria);
  memoriaIni = crearMemoriaIni(&idMemoriaIni);
  crearAlarma(TIEMPO_ALARMA_DEFAULT);
  verificarMemoriaIni(memoriaIni, "partido");
  cancelarAlarma();

  limpiarPantalla();
  printf("Cantidad Jugadores %d\n", cantidadJugadores);

  idHilo = (pthread_t*)malloc(sizeof(pthread_t)*cantidadJugadores);
  datosThread = (jugador*)malloc(sizeof(jugador)*cantidadJugadores);

  for (i = 0; i < cantidadJugadores; i++)
  {
    datosThread[i].idColaMensajes = idColaMensajes;
    datosThread[i].memoria = memoria;
    datosThread[i].nroJugador = i;
    memset(datosThread[i].nombreJugador, 0x00, sizeof(char)*LARGO_NOMBRE);
    strcpy(datosThread[i].nombreJugador, obtenerNombreJugadorPorNumero(i));

    if (!crearThread(&idHilo[i], &atributos, jugadorThread, (void*)&datosThread[i]))
    {
      puts("Error: No se pude crear el thread");
      return -1;
    }
  }

  for (i = 0; i < cantidadJugadores; i++)
  {
   joinThread(&idHilo[i]);
  }

  liberarRecursos();

  configurarFinalizarMemoriaIni(memoriaIni);

  return 0;
}
