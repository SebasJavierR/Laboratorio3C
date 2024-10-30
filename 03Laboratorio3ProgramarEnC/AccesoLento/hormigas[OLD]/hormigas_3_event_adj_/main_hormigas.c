/*Standard Library*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "time.h"
#include "pthread.h"
/*Headers Library*/
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
#include "thread/thread_hormigas.h"

int main(int argc, char *argv[])
{
  int idColaMensajes;
  int idMemoria;
  dato_memoria* memoria;
  int idMemoriaIni;
  dato_memoria_ini* memoriaIni;
  pthread_t* idHilo;
  pthread_attr_t atributos;
  hormiga* datosThread;
  int i;

  if (argc != 2)
  {
    printf("Uso: ./hormiga [cantidad_hormigas]\n");
    return -1;
  }

  memoriaIni = 0; /*NULL*/
  idMemoriaIni = 0;
  memoria = 0;
  idMemoria = 0;
  idHilo = 0;
  cantidadHormigas = atoi(argv[1]);

  srand(time(0));

  iniciarMutex(&mutex);
  iniciarAttr(&atributos);

  srand(time(0));

  idColaMensajes = crearColaMensajes();
  memoria = (dato_memoria*)crearMemoria(sizeof(dato_memoria), &idMemoria);
  memoriaIni = crearMemoriaIni(&idMemoriaIni);
  verificarMemoriaIni(memoriaIni, "reina");

  limpiarPantalla();
  printf("Cantidad Hormigas %d\n", cantidadHormigas);

  idHilo = (pthread_t*)malloc(sizeof(pthread_t)*cantidadHormigas);
  datosThread = (hormiga*)malloc(sizeof(hormiga)*cantidadHormigas);

  for (i = 0; i < cantidadHormigas; i++)
  {
    datosThread[i].idColaMensajes = idColaMensajes;
    datosThread[i].memoria = memoria;
    datosThread[i].nroHormiga = i;
    datosThread[i].recursoComida = 0;
    datosThread[i].recursoHoja = 0;
    datosThread[i].recursoRama = 0;
    datosThread[i].recursoAgua = 0;

    if (!crearThread(&idHilo[i], &atributos, hormigasThread, (void*)&datosThread[i]))
    {
      printf("Error: No se pude crear el thread\n");
      return -1;
    }
  }

  for (i = 0; i < cantidadHormigas; i++)
  {
   joinThread(&idHilo[i]);
  }

  free(idHilo);
  free(datosThread);
  destruirMutex(&mutex);

  configurarFinalizarMemoriaIni(memoriaIni);
  return 0;
}
