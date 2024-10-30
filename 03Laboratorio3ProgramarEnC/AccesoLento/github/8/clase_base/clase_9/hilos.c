#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "string.h"
#include "pthread.h"
#include "defines.h"
#include "globals.h"

void iniciarMutex(pthread_mutex_t* mutex)
{
  pthread_mutex_init(mutex, 0);
}

void iniciarAttr(pthread_attr_t* atributos)
{
  pthread_attr_init(atributos);
  pthread_attr_setdetachstate(atributos, PTHREAD_CREATE_JOINABLE);
}

void joinThread(pthread_t* hilo)
{
  pthread_join(*hilo, 0);
}

/*Ejemplo uso: joinThreadValorSalida(&idHilo, (void*)&valorDevuelto)*/
/*char* valorDevuelto; valorDevuelto = 0;*/
/*No responde bien al free(valorDevuelto) luego del pthread_exit()*/
void joinThreadValorSalida(pthread_t* hilo, char* valorDevuelto)
{
    pthread_join(*hilo, (void**)valorDevuelto);
}

void lockMutex(pthread_mutex_t* mutex)
{
  pthread_mutex_lock(mutex);
}

void unlockMutex(pthread_mutex_t* mutex)
{
  pthread_mutex_unlock(mutex);
}

void* funcionThread(void* parametro)
{
  int i;
  printf("Hijo\n");
  for (i = 0; i < CANTIDAD; i++)
  {
    lockMutex(&mutex);
    printf("Soy el hijo y tengo el mutex\n");
    sleep(1);
    unlockMutex(&mutex);
    sleep(1);
  }
  printf("Soy el hijo y espero 2 segundos\n");
  sleep(2);
  printf("Hijo: Termino\n");
  return 0;
  
  /*Alternativa:*/
  /*Permite retornar un valor*/
  /*pthread_exit((void*)0);*/
}

int crearThread(pthread_t* hilo, pthread_attr_t* atributos, void* arg)
{
  return pthread_create(hilo, atributos, funcionThread, arg) == 0;
}
