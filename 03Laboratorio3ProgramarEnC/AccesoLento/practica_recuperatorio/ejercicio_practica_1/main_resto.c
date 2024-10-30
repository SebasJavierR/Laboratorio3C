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
  orden* ordenes;
  int numOrden;

  if (argc != 1)
  {
    printf("Uso: ./resto\n");
    return -1;
  }

  idSemaforo = 0;
  menuActual = 1;
  numOrden = 0;

  srand(time(0));

  idSemaforo = crearSemaforo();
  iniciarSemaforo(idSemaforo, VERDE);

  ordenes = (orden*)malloc(MAX_ORDENES*sizeof(orden));
  memset(ordenes,0x00,MAX_ORDENES*sizeof(orden));

  rutaArchivo = (char*)malloc(LARGO_LINEA*sizeof(char));
  memset(rutaArchivo,0x00,LARGO_LINEA*sizeof(char));

  limpiarPantalla();

  while(1)
  {
    ordenes[numOrden].tipoMenu = obtenerNumeroAleatorio(MENU_MIN, MENU_MAX);
    strcpy(rutaArchivo, obtenerRutaArchivoMenu(ordenes[numOrden].tipoMenu));
    esperarSemaforo(idSemaforo);
    if (abrirAdicion(rutaArchivo))
    {
      escribirOrden(&ordenes[numOrden]);
      cerrarArchivo();
    }
    levantarSemaforo(idSemaforo);
    if (numOrden < (MAX_ORDENES - 1))
    {
      numOrden++;
    }
    else
    {
      printf("Se alcanzó máximo de órdenes\n");
      printf("Cerrando Resto\n");
      break;
    }
    memset(rutaArchivo,0x00,sizeof(rutaArchivo));
    usleep(INTERVALO_RESTO_MS * 1000);
  }

  eliminarSemaforo(idSemaforo);
  free(rutaArchivo);
  free(ordenes);
  return 0;
}
