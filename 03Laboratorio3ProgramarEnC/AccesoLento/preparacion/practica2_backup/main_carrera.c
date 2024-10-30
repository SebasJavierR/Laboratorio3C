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
#include "thread/thread_carrera.h"

int main(int argc, char *argv[])
{
  int idColaMensajes;
  int idMemoria;
  dato_memoria* memoria;
  int idSemaforo;
  int idMemoriaIni;
  dato_memoria_ini* memoriaIni;
  pthread_t idHilo;
  pthread_attr_t atributos;
  tablero datosThread;

  if (argc != 1)
  {
    printf("Uso: ./carrera\n");
    return -1;
  }

  memoriaIni = 0;
  idMemoriaIni = 0;
  memoria = 0;
  idMemoria = 0;
  idSemaforo = 0;
  idColaMensajes = 0;
  idHilo = 0;
  cantidadJugadores = CANTIDAD_JUGADORES;

  srand(time(0));

  iniciarMutex(&mutex);
  iniciarAttr(&atributos);

  idSemaforo = crearSemaforo();
  iniciarSemaforo(idSemaforo, VERDE);
  idColaMensajes = crearColaMensajes();
  borrarMensajes(idColaMensajes);
  memoria = (dato_memoria*)crearMemoria(sizeof(dato_memoria)*cantidadJugadores, &idMemoria);
  configurarMemoria(memoria, cantidadJugadores);
  memoriaIni = crearMemoriaIni(&idMemoriaIni);
  configurarMemoriaIni(memoriaIni);

  limpiarPantalla();

  datosThread.idColaMensajes = idColaMensajes;
  datosThread.idSemaforo = idSemaforo;
  datosThread.memoria = memoria;

  if (!crearThread(&idHilo, &atributos, carreraThread, (void*)&datosThread))
  {
    printf("Error: No se pude crear el thread\n");
    return -1;
  }

  joinThread(&idHilo);

  esperarSemaforo(idSemaforo);
  verificarFinalizarMemoriaIni(memoriaIni, "jugadores");
  levantarSemaforo(idSemaforo);

  liberarMemoria(idMemoriaIni, (char*)memoriaIni);
  liberarMemoria(idMemoria, (char*)memoria);
  liberarColaMensajes(idColaMensajes);
  eliminarSemaforo(idSemaforo);
  destruirMutex(&mutex);
  return 0;
}
