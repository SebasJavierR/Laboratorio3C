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
  int idSemaforo;
  int menuActual;
  char* rutaArchivo;

  if (argc != 1)
  {
    printf("Uso: ./resto \n");
    return 0;
  }
  
  srand(time(0));
  idSemaforo = creoSemaforo();
  iniciaSemaforo(idSemaforo, VERDE);

  rutaArchivo = (char*)malloc(LARGO_LINEA*sizeof(char));
  memset(rutaArchivo,0x00,sizeof(rutaArchivo));
  menuActual = 1;

  while(1)
  {
    menuActual = obtenerNumeroAleatorio(TIPOS_MENU_MIN, TIPOS_MENU_MAX);
    strcpy(rutaArchivo, obtenerRutaArchivoMenu(menuActual));
    esperaSemaforo(idSemaforo);

    if (abrirAdicion(rutaArchivo))
    {
      escribirOrden(menuActual);
    }
    cerrarArchivo();
    levantaSemaforo(idSemaforo);
    memset(rutaArchivo,0x00,sizeof(rutaArchivo));
    usleep(INTERVALO_RESTO_MS * 10000);
  }
  free(rutaArchivo);
  return 0;
}
