#ifndef _HILOS_H
#define _HILOS_H
/*Standard Library*/
#include "pthread.h"
void iniciarMutex(pthread_mutex_t*);
void destruirMutex(pthread_mutex_t*);
void iniciarAttr(pthread_attr_t*);
void joinThread(pthread_t*);
void joinThreadValorSalida(pthread_t*,char*);
void lockMutex(pthread_mutex_t*);
void unlockMutex(pthread_mutex_t*);
int crearThread(pthread_t*, pthread_attr_t*, void* (*f)(void*), void*);
#endif
