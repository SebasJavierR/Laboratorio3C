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
#include "libCommon/cola.h"
#include "libCommon/hilos.h"
#include "libCommon/aleatorio.h"
#include "libCommon/pantalla.h"
#include "libCore/defines.h"
#include "libCore/globals.h"
#include "libCore/funciones.h"
#include "libCore/productor.h"
#include "libCore/consumidor.h"
#include "libThread/thread_pienso.h"

int main(int argc, char *argv[])
{
 /* int idMemoriaInicial;
  inicial* memoriaInicial;*/
  pthread_t* idHilo;
  pthread_attr_t atributos;
  int i;
  int cantidadJugadores;
  int localPiensoUnNumero;
  jugador* datosThread;
  int alguienAcerto;

  if (argc != 2)
  {
    printf("Uso: ./uno [cantidad_jugadores]\n");
    return -1;
  }

 /* memoriaInicial = 0;
  idMemoriaInicial = 0;*/
  idHilo = 0;
  i = 0;
  localPiensoUnNumero = 0;
  alguienAcerto = 0;
  cantidadJugadores = atoi(argv[1]);

  if (cantidadJugadores <= 0)
  {
    printf("cantidad_jugadores debe ser mayor o igual a 1\n");
    return -1;
  }

  srand(time(0));

  iniciarMutex(&mutex);
  iniciarAttr(&atributos);

  /*memoriaInicial = (inicial*)crearMemoria(sizeof(inicial)*CANTIDAD, &idMemoriaInicial, CLAVE_BASE_INI);
  iniciarMemoriaInicial(memoriaInicial);*/

  limpiarPantalla();
  printf("Pensando número...\n");
  localPiensoUnNumero = obtenerNumeroAleatorio(NUM_MIN, NUM_MAX);
  printf("Número pensado %d\n", localPiensoUnNumero);

  idHilo = (pthread_t*)malloc(sizeof(pthread_t)*cantidadJugadores);
  datosThread = (jugador*)malloc(sizeof(jugador)*cantidadJugadores);

  for (i = 0; i < cantidadJugadores; i++)
  {
    datosThread[i].nroJugador = i+1;
    datosThread[i].cantidadIntentos = 0;
    datosThread[i].alguienAcerto = 0;
    datosThread[i].numeroPensado = localPiensoUnNumero;
    if (!crearThread(&idHilo[i], &atributos, piensoThread, (void*)&datosThread[i]))
    {
      printf("Error: No se pude crear el thread\n");
      return -1;
    }
  }

  for (i = 0; i < cantidadJugadores; i++)
  {
    joinThread(&idHilo[i]);
    printf("Jugador %d intentos %d\n", i + 1, datosThread[i].cantidadIntentos);
  }
  free(idHilo);
  free(datosThread);
  /*liberarMemoria(idMemoriaInicial, (char*)memoriaInicial);*/
  return 0;
}
