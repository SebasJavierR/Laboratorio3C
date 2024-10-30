#include "funciones.h"
#include "stdlib.h"
#include "stdio.h"

int obtenerNumeroAleatorio(int desde, int hasta) {
	int num = 0;
	num = (rand()%(hasta-desde+1))+desde;
	return num;
}
