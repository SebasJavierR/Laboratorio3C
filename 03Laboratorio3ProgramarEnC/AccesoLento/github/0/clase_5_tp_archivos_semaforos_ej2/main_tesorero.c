#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "defines.h"
#include "gestionararchivos.h"
#include "semaforos.h"
#include "funciones.h"
#include "consumidor.h"
int main(int argc, char *argv[])
{
  int idSemaforoCajero;
  int cajeroActual;
  char* rutaArchivo;

  if (argc != 1)
  {
    printf("Uso: ./tesorero \n");
    return 0;
  }

  idSemaforoCajero = creoSemaforo();
  iniciaSemaforo(idSemaforoCajero, VERDE);

  rutaArchivo = (char*)malloc(LARGO_LINEA*sizeof(char));
  memset(rutaArchivo,0x00,sizeof(rutaArchivo));
  cajeroActual = 1;

  inicializarResumenes();

  while(1)
  {
    strcpy(rutaArchivo, obtenerRutaArchivoCajero(cajeroActual));
    esperaSemaforo(idSemaforoCajero);

    if (abrirLectura(rutaArchivo))
    {
      leerDepositosCajero(cajeroActual);
    }

    imprimirResumen();

    if (cajeroActual < 3)
    {
      cajeroActual++;
    }
    else
    {
      cajeroActual = 1;
    }
    levantaSemaforo(idSemaforoCajero);
    memset(rutaArchivo,0x00,sizeof(rutaArchivo));
    usleep(INTERVALO_TESORERO_MS * 10000);
  }
  free(rutaArchivo);
  return 0;
}
