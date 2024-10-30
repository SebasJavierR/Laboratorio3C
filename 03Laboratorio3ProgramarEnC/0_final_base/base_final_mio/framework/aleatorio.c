/*Librerias*/
#include <stdlib.h>
/*Archivo .h*/
#include "aleatorio.h"

int obtenerNumeroAleatorio(int desde, int hasta)
{
	int num = 0;
	num = (rand()%(hasta-desde+1))+desde;
	return num;
}

void obtenerNumerosAleatorios(int desde, int hasta, int tamanio, int* nums)
{
	int i;
	for (i = 0; i < tamanio; i++)
	{
		int valor = (rand()%(hasta-desde+1))+desde;
		nums[i] = valor;
	}
}
