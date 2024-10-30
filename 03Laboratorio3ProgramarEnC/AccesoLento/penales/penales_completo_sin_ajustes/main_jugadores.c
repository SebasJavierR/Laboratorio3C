/*Standard Library*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "time.h"
#include "pthread.h"
/*Headers Library*/
#include "libCommon/semaforos.h"
#include "libCommon/memoria.h"
#include "libCommon/memoria_ini.h"
#include "libCommon/cola.h"
#include "libCommon/hilos.h"
#include "libCommon/aleatorio.h"
#include "libCommon/pantalla.h"
#include "libCore/defines.h"
#include "libCore/globals.h"
#include "libCore/funciones.h"
#include "libCore/productor.h"
#include "libCore/consumidor.h"
#include "libCore/memoria_core.h"
#include "libThread/thread_jugadores.h"

int main(int argc, char *argv[])
{
  int idColaMensajes;
  int idMemoria;
  dato_memoria* memoria;
  int idSemaforo;
  int idMemoriaIni;
  dato_memoria_ini* memoriaIni;
  pthread_t* idHilo;
  pthread_attr_t atributos;
  jugador* datosThread;
  int i;

  if (argc != 1)
  {
    printf("Uso: ./jugadores\n");
    return -1;
  }

  memoriaIni = 0; /*NULL*/
  idMemoriaIni = 0;
  memoria = 0;
  idMemoria = 0;
  idSemaforo = 0;
  idHilo = 0;
  cantidadJugadores = CANTIDAD_JUGADORES;

  srand(time(0));

  iniciarMutex(&mutex);
  iniciarAttr(&atributos);

  srand(time(0));

  idSemaforo = crearSemaforo();
  idColaMensajes = crearColaMensajes();
  memoria = (dato_memoria*)crearMemoria(sizeof(dato_memoria)*cantidadJugadores, &idMemoria);
  memoriaIni = crearMemoriaIni(&idMemoriaIni);
  verificarMemoriaIni(memoriaIni, "carrera");

  limpiarPantalla();

  idHilo = (pthread_t*)malloc(sizeof(pthread_t)*cantidadJugadores);
  datosThread = (jugador*)malloc(sizeof(jugador)*cantidadJugadores);

  for (i = 0; i < cantidadJugadores; i++)
  {
    datosThread[i].idColaMensajes = idColaMensajes;
    datosThread[i].idSemaforo = idSemaforo;
    datosThread[i].memoria = memoria;
    datosThread[i].nroJugador = i;

    if (!crearThread(&idHilo[i], &atributos, jugadoresThread, (void*)&datosThread[i]))
    {
      printf("Error: No se pude crear el thread\n");
      return -1;
    }
  }

  for (i = 0; i < cantidadJugadores; i++)
  {
   joinThread(&idHilo[i]);
  }

  free(idHilo);
  free(datosThread);
  destruirMutex(&mutex);

  esperarSemaforo(idSemaforo);
  configurarFinalizarMemoriaIni(memoriaIni);
  levantarSemaforo(idSemaforo);
  return 0;
}
