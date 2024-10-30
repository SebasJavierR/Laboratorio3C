#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "time.h"
#include "defines.h"
#include "gestionararchivos.h"
#include "semaforos.h"
#include "funciones.h"
#include "productor.h"

int main(int argc, char *argv[])
{
  int idSemaforoCajero;
  int cajeroElegido;
  char* rutaArchivo;
  int cantidad;  
  int monto;
  int esCheque;
  int intervalo;
  int i;

  if (argc != 2)
  {
    printf("Uso: ./cajero [1-3]\n");
    return 0;
  }

	cajeroElegido = atoi(argv[1]);
  
  srand(time(0));
  rutaArchivo = (char*)malloc((LARGO_RUTA+1)*sizeof(char));
  memset(rutaArchivo,0x00,sizeof(rutaArchivo));

  strcpy(rutaArchivo, obtenerRutaArchivoCajero(cajeroElegido));

  idSemaforoCajero = creoSemaforo();
  
  i = 1;
  cantidad = 0;
  monto = 0;
  esCheque = 0;
  intervalo = 0;

  while(1)
  {
    esperaSemaforo(idSemaforoCajero);
    if (abrirAdicion(rutaArchivo))
    {
      cantidad = obtenerNumeroAleatorio(CANT_DEPOSITOS_MIN, CANT_DEPOSITOS_MAX);
      limpiarPantalla();
      i = 1;
      while (i <= cantidad)
      {
        monto = obtenerNumeroAleatorio(IMPORTE_MIN, IMPORTE_MAX);
        esCheque = obtenerNumeroAleatorio(VAL_CHEQUE, VAL_EFECTIVO);
        escribirDeposito(monto, esCheque);
        i++;
      } 
    }

    cerrarArchivo();
    levantaSemaforo(idSemaforoCajero);
    intervalo = obtenerNumeroAleatorio(INTERVALO_CAJERO_MIN_MS, INTERVALO_CAJERO_MAX_MS);
    usleep(intervalo * 10000);
  }
  free(rutaArchivo);
  return 0;
}
