#include "stdio.h"
#include "stdlib.h"
#include "defines.h"
#include "funciones.h"

int obtenerNumeroAleatorio(int desde, int hasta) {
	int num = 0;
	num = (rand()%(hasta-desde+1))+desde;
	return num;
}

void obtenerNumerosAleatorios(int desde, int hasta, int tamanio, int* nums) {
	int i;
	for (i = 0; i < tamanio; i++)
	{
		int valor = (rand()%(hasta-desde+1))+desde;
		nums[i] = valor;
	}
}

void limpiarPantalla()
{
  int i;
  i = 0;
  while (i<80)
  {
    printf("\n");
    i++;
  }
}

char* obtenerDestino(int numVuelo)
{
  switch(numVuelo)
  {
    case 1000:
      return "SEATTLE";
    case 1001:
      return "HELSINKI";
    case 1002:
      return "DENVER";
    case 1003:
      return "DUBLIN";
    case 1004:
      return "MONACO";
    case 1005:
      return "SAO PAULO";
    case 1006:
      return "HOUSTON";
    case 1007:
      return "TOKYO";
    case 1008:
      return "BUENOS AIRES";
    case 1009:
      return "MONTEVIDEO";
    case 1010:
      return "VANCOUVER";
    default:
      return "";
  }
}
