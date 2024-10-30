/*Librerias*/
#include "pthread.h"

#include "hilos.h"

void iniciarMutex(pthread_mutex_t* mutex)
{
  pthread_mutex_init(mutex, 0);
}

void destruirMutex(pthread_mutex_t* mutex)
{
  pthread_mutex_destroy(mutex);
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

/*Alternativa valor de retorno:*/
/*Permite retornar un valor*/
/*En vez de return utilizamos la siguiente función:*/
/*pthread_exit((void*)0);*/
/*Donde esta el 0 podemos indicar cualquier valor de salida*/
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

int crearThread(pthread_t* hilo, pthread_attr_t* atributos, void* (*funcionThread)(void*), void* arg)
{
  return pthread_create(hilo, atributos, funcionThread, arg) == 0;
}
