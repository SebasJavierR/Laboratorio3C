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
  int idSemaforo;
  int sdcElegido;
  char* rutaArchivo;

  if (argc != 2)
  {
    printf("Uso: ./sdc [A-C]\n");
    return 0;
  }
  sdcElegido = 0;
  sdcElegido = obtenerMenuNum(argv[1]);

  if (sdcElegido == -1)
  {
    printf("Ingrese A, B o C\n");
    return 0;
  }

  rutaArchivo = (char*)malloc((LARGO_RUTA+1)*sizeof(char));
  memset(rutaArchivo,0x00,sizeof(rutaArchivo));

  strcpy(rutaArchivo, obtenerRutaArchivoMenu(sdcElegido));

  idSemaforo = creoSemaforo();

  while(1)
  {
    esperaSemaforo(idSemaforo);
    if (abrirLectura(rutaArchivo))
    {
      leerOrdenes(sdcElegido);
    }
    cerrarArchivo();
    limpiarArchivo(obtenerRutaArchivoMenu(sdcElegido));
    levantaSemaforo(idSemaforo);
    usleep(INTERVALO_SDC_MS * 10000);
  }
  free(rutaArchivo);
  return 0;
}
