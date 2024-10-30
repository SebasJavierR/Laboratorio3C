#ifndef _SEMAFOROS_H
#define _SEMAFOROS_H
#define ROJO 0
#define VERDE 1
int crearSemaforoConClave(int);
int crearSemaforo();
void iniciarSemaforo(int,int);
void eliminarSemaforo(int);
void levantarSemaforo(int);
void esperarSemaforo(int);
#endif
