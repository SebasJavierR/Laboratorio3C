#ifndef _SEMAFOROS_H
#define _SEMAFOROS_H
int crearSemaforo();
void iniciarSemaforo(int,int);
void eliminarSemaforo(int);
void levantarSemaforo(int);
void esperarSemaforo(int);
int crearSemaforoConClave(int);
#endif
