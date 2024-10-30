#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "defines.h"
#include "globals.h"
#include "funciones.h"
#include "semaforos.h"

void iniciarMemoria(dato* memoria)
{
  int i;
  for (i = 0; i < CANTIDAD; i++)
  {
    memoria[i].cajero = 0;
    memoria[i].importe = 0;
    memoria[i].cheque = 0;
    memoria[i].listo = 0;
    memoria[i].inicializado = 1;
  }
}

void cargarCajero(dato* memoria, int cajero)
{
  int i;
  int posicion;
  int importe;
  int cheque;
  
  printf("cajero\t%d\n", cajero);
  importe = obtenerNumeroAleatorio(IMPORTE_MIN, IMPORTE_MAX);
  cheque = obtenerNumeroAleatorio(CHEQUE_MIN, CHEQUE_MAX);
  posicion = -1;
  i = 0;
  while (posicion == -1 && i < CANTIDAD)
  {
    if (memoria[i].listo == 0)
    {
      posicion = i;
      memoria[posicion].cajero = cajero;
      memoria[posicion].importe = importe;
      memoria[posicion].cheque = cheque;
      memoria[posicion].listo = 1;

      printf("Posición\t%d\n", posicion);
      printf("Cajero\t%d\n", memoria[posicion].cajero);
      printf("Importe\t%d\n", memoria[posicion].importe);
      printf("Cheque\t%d\n", memoria[posicion].cheque);
      printf("Listo\t%d\n", memoria[posicion].listo);
    }
    i++;
  }
}
