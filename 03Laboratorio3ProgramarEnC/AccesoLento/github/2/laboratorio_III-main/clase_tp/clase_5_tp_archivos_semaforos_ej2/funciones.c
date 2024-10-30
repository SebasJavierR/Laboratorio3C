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

char* obtenerRutaArchivoCajero(int valor)
{
  char* ruta;

  ruta = (char*)malloc((LARGO_LINEA+1)*sizeof(char));
  memset(ruta,0x00,sizeof(ruta));
  sprintf(ruta,RUTA_ARCHIVO_CAJERO,valor);
  return ruta;
}

char* obtenerRutaArchivoBakCajero(int cajero, int numLote)
{
  char* rutaBak;

  rutaBak = (char*)malloc((LARGO_LINEA+1)*sizeof(char));
  memset(rutaBak,0x00,sizeof(rutaBak));
  sprintf(rutaBak,RUTA_BACKUP,cajero,numLote);
  return rutaBak;
}
