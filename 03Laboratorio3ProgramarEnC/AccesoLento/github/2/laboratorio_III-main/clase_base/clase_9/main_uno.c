#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "time.h"
#include "pthread.h"
#include "defines.h"
#include "globals.h"
#include "semaforos.h"
#include "memoria.h"
#include "cola.h"
#include "hilos.h"
#include "funciones.h"
#include "productor.h"
#include "consumidor.h"

int main(int argc, char *argv[])
{
  int idMemoriaInicial;
  inicial* memoriaInicial;
  pthread_t idHilo;
  pthread_attr_t atributos;
  int i;

  if (argc != 1)
  {
    printf("Uso: ./uno \n");
    return 0;
  }

  memoriaInicial = 0; /*NULL*/
  idMemoriaInicial = 0;
  idHilo = 0;
  i = 0;

  srand(time(0));

  iniciarMutex(&mutex);
  iniciarAttr(&atributos);

  memoriaInicial = (inicial*)creoMemoria(sizeof(inicial)*CANTIDAD, &idMemoriaInicial, CLAVE_BASE_INI);
  iniciarMemoriaInicial(memoriaInicial);

  limpiarPantalla();

  if (!crearThread(&idHilo, &atributos, 0))
  {
    printf("Error: No se pude crear el thread\n");
    return -1;
  }

  while(1)
  {
    lockMutex(&mutex);
    printf("Soy el padre y tengo el mutex\n");
    sleep(1);
    unlockMutex(&mutex);
    if (i < CANTIDAD)
    {
      i++;
    }
    else
    {
      break;
    }
    usleep(INTERVALO_UNO_MS * 1000);
  }

  printf("Padre: Espero al thread\n");
  joinThread(&idHilo);
  printf("Padre: Ya ha terminado el thread\n");
  liberoMemoria(idMemoriaInicial, (char*)memoriaInicial);
  return 0;
}
