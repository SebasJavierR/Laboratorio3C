/*HORMIGAS*/
/*Librerias*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "time.h"
#include "pthread.h"
/*Encabezados*/
#include "framework/semaforos.h"
#include "framework/memoria.h"
#include "framework/memoria_ini.h"
#include "framework/cola.h"
#include "framework/hilos.h"
#include "framework/aleatorio.h"
#include "framework/pantalla.h"
#include "program/defines.h"
#include "program/globals.h"
#include "program/funciones.h"
#include "program/productor.h"
#include "program/consumidor.h"
#include "program/memoria_core.h"
#include "thread/thread_jugadores.h"

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

  if (argc != 2)
  {
    printf("Uso: ./hormigas [hormigas_maximas]\n");
    return -1;
  }

  memoriaIni = 0; /*NULL*/
  idMemoriaIni = 0;
  memoria = 0;
  idMemoria = 0;
  idSemaforo = 0;
  idHilo = 0;
  cantidadJugadores = CANTIDAD_JUGADORES;
  hormigasMaximas = atoi(argv[1]);

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
