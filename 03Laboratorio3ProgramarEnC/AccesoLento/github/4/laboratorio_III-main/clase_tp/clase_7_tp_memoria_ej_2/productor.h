#ifndef _PRODUCTOR_H
#define _PRODUCTOR_H
#include "globals.h"
void iniciarMemoria(dato*, int);
void iniciarMemoriaInicial(inicial*);
void liberarAsignacionesMemoria(dato*);
void aumentarVehiculosEnCola(dato*, int);
void decrementarVehiculosEnCola(dato*, int);
void escribirVehiculosEnCola(dato*, int, int);
#endif
