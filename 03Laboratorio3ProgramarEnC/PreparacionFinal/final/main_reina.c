/*Librerias*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "time.h"
#include "pthread.h"
/*Librerias de Headers*/
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
#include "thread/thread_reina.h"

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
  int i;

  if (argc != 2)
  {
    printf("Uso: ./reina 5\n");
    return -1;
  }

  memoriaIni = 0;
  idMemoriaIni = 0;
  memoria = 0;
  idMemoria = 0;
  idColaMensajes = 0;
  idHilo = 0;
  hormigas_totales = atoi(argv[1]);
  if( hormigas_totales != 5)
  {
    printf("Uso: ./reina 5\n");
    return -1;
  }

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

  printf("Cantidad Hormigas %d\n", hormigas_totales);

  datosThread.idColaMensajes = idColaMensajes;
  datosThread.memoria = memoria;

  for (i = 0; i < hormigas_totales; i++)
  {
    datosThread[i].idColaMensajes = idColaMensajes;
    datosThread[i].memoria = memoria;
    datosThread[i].nroHormiga = i;

    if (!crearThread(&idHilo[i], &atributos, reinaThread, (void*)&datosThread[i]))
    {
      printf("Error: No se pude crear el thread\n");
      return -1;
    }
  }

  joinThread(&idHilo);

  verificarFinalizarMemoriaIni(memoriaIni, "hormigas");

  liberarMemoria(idMemoriaIni, (char*)memoriaIni);
  liberarMemoria(idMemoria, (char*)memoria);
  liberarColaMensajes(idColaMensajes);
  destruirMutex(&mutex);
  return 0;
}
