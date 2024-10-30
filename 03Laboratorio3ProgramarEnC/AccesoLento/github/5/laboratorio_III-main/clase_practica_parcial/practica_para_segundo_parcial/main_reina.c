/*Standard Library*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "time.h"
#include "pthread.h"
/*Headers Library*/
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
#include "libThread/thread_reina.h"

int main(int argc, char *argv[])
{
  int idColaMensajes;
  int idMemoria;
  dato_memoria* memoria;
  int idMemoriaIni;
  dato_memoria_ini* memoriaIni;
  pthread_t idHilo;
  pthread_attr_t atributos;
  reina datosThread;

  if (argc != 2)
  {
    printf("Uso: ./reina [cantidad_hormigas]\n");
    return -1;
  }

  memoriaIni = 0;
  idMemoriaIni = 0;
  memoria = 0;
  idMemoria = 0;
  idColaMensajes = 0;
  idHilo = 0;
  cantidadHormigas = atoi(argv[1]);

  srand(time(0));

  iniciarMutex(&mutex);
  iniciarAttr(&atributos);

  idColaMensajes = crearColaMensajes();
  borrarMensajes(idColaMensajes);
  memoria = (dato_memoria*)crearMemoria(sizeof(dato_memoria), &idMemoria);
  configurarMemoria(memoria);
  memoriaIni = crearMemoriaIni(&idMemoriaIni);
  configurarMemoriaIni(memoriaIni);

  limpiarPantalla();

  printf("Cantidad Hormigas %d\n", cantidadHormigas);

  datosThread.idColaMensajes = idColaMensajes;
  datosThread.memoria = memoria;

  if (!crearThread(&idHilo, &atributos, reinaThread, (void*)&datosThread))
  {
    printf("Error: No se pude crear el thread\n");
    return -1;
  }

  joinThread(&idHilo);

  verificarFinalizarMemoriaIni(memoriaIni, "hormigas");

  liberarMemoria(idMemoriaIni, (char*)memoriaIni);
  liberarMemoria(idMemoria, (char*)memoria);
  liberarColaMensajes(idColaMensajes);
  destruirMutex(&mutex);
  return 0;
}
