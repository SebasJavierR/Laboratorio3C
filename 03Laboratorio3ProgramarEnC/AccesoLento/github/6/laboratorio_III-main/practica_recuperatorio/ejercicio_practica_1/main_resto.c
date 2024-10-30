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
#include "libCore/defines.h"
#include "libCore/globals.h"
#include "libCore/funciones.h"
#include "libCore/productor.h"
#include "libCore/consumidor.h"

int main(int argc, char *argv[])
{
  /*General*/
  int idSemaforo;

  /*Custom*/
  int menuActual;
  char* rutaArchivo;

  if (argc != 1)
  {
    printf("Uso: ./resto\n");
    return -1;
  }

  idSemaforo = 0;
  menuActual = 1;

  srand(time(0));

  idSemaforo = crearSemaforo();
  iniciarSemaforo(idSemaforo, VERDE);

  rutaArchivo = (char*)malloc(LARGO_LINEA*sizeof(char));
  memset(rutaArchivo,0x00,sizeof(rutaArchivo));

  limpiarPantalla();

  while(1)
  {
    menuActual = obtenerNumeroAleatorio(MENU_MIN, MENU_MAX);
    strcpy(rutaArchivo, obtenerRutaArchivoMenu(menuActual));
    esperarSemaforo(idSemaforo);
    if (abrirAdicion(rutaArchivo))
    {
      escribirOrden(menuActual);
      cerrarArchivo();
    }
    levantarSemaforo(idSemaforo);
    memset(rutaArchivo,0x00,sizeof(rutaArchivo));
    usleep(INTERVALO_RESTO_MS * 1000);
  }
  free(rutaArchivo);
  return 0;
}
