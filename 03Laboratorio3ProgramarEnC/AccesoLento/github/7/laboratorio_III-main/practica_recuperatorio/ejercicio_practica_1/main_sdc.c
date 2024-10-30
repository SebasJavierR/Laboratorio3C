/*Standard Library*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "time.h"
/*Headers Library*/
#include "libCommon/semaforos.h"
#include "libCommon/aleatorio.h"
#include "libCommon/pantalla.h"
#include "libCommon/archivos.h"
#include "libCommon/cadenas.h"
#include "libCore/defines.h"
#include "libCore/globals.h"
#include "libCore/funciones.h"
#include "libCore/productor.h"
#include "libCore/consumidor.h"

int main(int argc, char *argv[])
{
  /*General*/
  int idSemaforo;
  int sdcElegido;
  char* rutaArchivo;

  /*Custom*/

  if (argc != 2)
  {
    printf("Uso: ./sdc [A-C]\n");
    return -1;
  }

  idSemaforo = 0;
  sdcElegido = 0;

  srand(time(0));

  printf("Atención: Recuerde levantar el programa inicial \"resto\". Presione \"enter\" para continuar...");
  getchar();
  limpiarPantalla();

  cadenaMayuscula(argv[1], argv[1]);
  sdcElegido = obtenerMenuNum(argv[1]);

  if (sdcElegido == -1)
  {
    printf("Ingrese A, B o C\n");
    return 0;
  }

  rutaArchivo = (char*)malloc((LARGO_RUTA+1)*sizeof(char));
  memset(rutaArchivo,0x00,sizeof(rutaArchivo));
  strcpy(rutaArchivo, obtenerRutaArchivoMenu(sdcElegido));

  idSemaforo = crearSemaforo();

  limpiarPantalla();

  while(1)
  {
    esperarSemaforo(idSemaforo);
    if (abrirLectura(rutaArchivo))
    {
      leerOrdenes(sdcElegido);
      cerrarArchivo();
      /*backupArchivo(rutaArchivo, RUTA_ARCHIVO_BACKUP);*/
      limpiarArchivo(rutaArchivo);
    }
    levantarSemaforo(idSemaforo);
    usleep(INTERVALO_SDC_MS * 1000);
  }

  free(rutaArchivo);
  return 0;
}

