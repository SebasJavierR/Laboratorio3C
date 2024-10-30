#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "defines.h"
#include "gestionararchivos.h"
#include "funciones.h"
#include "semaforos.h"

void escribirDeposito(int monto, int esEfectivo)
{
  char* deposito;

  deposito = (char*)malloc((LARGO_LINEA+1)*sizeof(char));
  memset(deposito,0x00,sizeof(deposito));
  sprintf(deposito,"%d %d\n", monto, esEfectivo);
  escribirArchivo(deposito);
  printf(deposito);
  free(deposito);
}

void inicializarCajero(int numeroCajero, int idSemaforoCajero)
{
  char* rutaArchivo;
  rutaArchivo = (char*)malloc(100*sizeof(char));
  memset(rutaArchivo,0x00,sizeof(rutaArchivo));
  strcpy(rutaArchivo, obtenerRutaArchivoCajero(numeroCajero));
  esperaSemaforo(idSemaforoCajero);
  limpiarArchivo(rutaArchivo);
  levantaSemaforo(idSemaforoPanel);
  free(rutaArchivo);
}



