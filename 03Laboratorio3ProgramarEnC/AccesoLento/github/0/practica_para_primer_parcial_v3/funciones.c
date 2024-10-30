#include "stdio.h"
#include "stdlib.h"
#include "string.h"
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

char* obtenerRutaArchivoMenu(int valor)
{
  switch(valor)
  {
    case 1:
      return RUTA_ARCHIVO_MENU_A;
    case 2:
      return RUTA_ARCHIVO_MENU_B;
    case 3:
      return RUTA_ARCHIVO_MENU_C;
    default:
      return "";
  }
}

char* obtenerMenuLetra(int valor)
{
  switch(valor)
  {
    case 1:
      return MENU_A;
    case 2:
      return MENU_B;
    case 3:
      return MENU_C;
  }
  return 0;
}

int obtenerMenuNum(char* valor)
{
  if (strcmp("A", valor) == 0)
  {
    return 1;
  }
  else if (strcmp("B", valor) == 0)
  {
    return 2;
  }
  else if (strcmp("C", valor) == 0)
  {
    return 3;
  }
  return -1;
}

int obtenerPrecioMenu(int valor)
{
  switch(valor)
  {
    case 1:
      return IMPORTE_MENU_A;
    case 2:
      return IMPORTE_MENU_B;
    case 3:
      return IMPORTE_MENU_C;
  }
  return 0;
}
