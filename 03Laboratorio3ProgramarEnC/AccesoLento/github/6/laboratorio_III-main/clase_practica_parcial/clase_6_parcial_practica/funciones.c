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

char* obtenerRutaArchivoPanel(int valor)
{
  switch(valor)
  {
    case 1:
      return RUTA_ARCHIVO_PANEL_1;
    case 2:
      return RUTA_ARCHIVO_PANEL_2;
    case 3:
      return RUTA_ARCHIVO_PANEL_3;
    default:
      return "";
  }
}
