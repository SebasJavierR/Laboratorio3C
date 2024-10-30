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
#include "hilos/thread_partido.h"

int idColaMensajes;
int idMemoria;
dato_memoria* memoria;
int idMemoriaIni;
dato_memoria_ini* memoriaIni;
pthread_attr_t atributos;

void liberarRecursos(void)
{
  liberarMemoria(idMemoriaIni, (char*)memoriaIni);
  liberarMemoria(idMemoria, (char*)memoria);
  liberarColaMensajes(idColaMensajes);
  destruirAttr(&atributos);
}

void manejadorSignals(int signum)
{
    if (signum == SIGINT)
    {
      puts("Liberando Recursos...");
      liberarRecursos();
      puts("Proceso Finalizado");
      exit(0);
    }
}

int main(int argc, char *argv[])
{
  pthread_t idHilo;
  partido datosThread;

  if (argc != 1)
  {
    puts("Uso: ./partido");
    return -1;
  }

  memoriaIni = 0;
  idMemoriaIni = 0;
  memoria = 0;
  idMemoria = 0;
  idColaMensajes = 0;
  idHilo = 0;
  cantidadJugadores = 2;

  srand(time(0));

  iniciarAttr(&atributos);
  asignarEstadoJoinableAttr(&atributos);

  crearSignal(SIGINT, manejadorSignals);

  idColaMensajes = crearColaMensajes();
  borrarMensajes(idColaMensajes);
  memoria = (dato_memoria*)crearMemoria(sizeof(dato_memoria)*cantidadJugadores, &idMemoria);
  configurarMemoria(memoria, cantidadJugadores);
  memoriaIni = crearMemoriaIni(&idMemoriaIni);
  configurarMemoriaIni(memoriaIni);

  limpiarPantalla();

  printf("Cantidad Jugadores %d\n", cantidadJugadores);

  datosThread.idColaMensajes = idColaMensajes;
  datosThread.memoria = memoria;

  if (!crearThread(&idHilo, &atributos, partidoThread, (void*)&datosThread))
  {
    puts("Error: No se pude crear el thread");
    return -1;
  }

  joinThread(&idHilo);

  verificarFinalizarMemoriaIni(memoriaIni, "jugador");

  liberarRecursos();
  return 0;
}
