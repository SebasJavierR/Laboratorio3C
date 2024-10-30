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
#include "libCore/menus.h"
#include "libCore/productor.h"
#include "libCore/consumidor.h"

int main(int argc, char *argv[])
{
  /*General*/
  int idSemaforo;

  /*Custom*/
  char rutaArchivo[LARGO_LINEA+1];
  int accionElegida;
  int panelElegido;

  if (argc != 1)
  {
    printf("Uso: ./cci\n");
    return -1;
  }

  idSemaforo = 0;
  accionElegida = 0;
  panelElegido = 0;

  srand(time(0));

  idSemaforo = crearSemaforo();
  iniciarSemaforo(idSemaforo, VERDE);

  memset(rutaArchivo,0x00,sizeof(char)*(LARGO_LINEA+1));

  inicializarPanel(PANEL_1, idSemaforo);
  inicializarPanel(PANEL_2, idSemaforo);
  inicializarPanel(PANEL_3, idSemaforo);

  limpiarPantalla();

  while(1)
  {
    accionElegida = mostrarMenuAccion();
    panelElegido = mostrarMenuPanel();
    printf("accion: %s\n", obtenerNombreAccion(accionElegida));
    printf("panel: %s\n", obtenerNombrePanel(panelElegido));
    strcpy(rutaArchivo, obtenerRutaArchivoPanel(panelElegido));

    switch(accionElegida)
    {
      case M_AC_LEER:
        esperarSemaforo(idSemaforo);
        if (abrirLectura(rutaArchivo))
        {
          leerPanel();
          cerrarArchivo();
        }
        levantarSemaforo(idSemaforo);
        break;
      case M_AC_ESCRIBIR:
        esperarSemaforo(idSemaforo);
        if (abrirEscritura(rutaArchivo))
        {
          escribirPanel();
          cerrarArchivo();
        }
        levantarSemaforo(idSemaforo);
      break;
      default:
      break;
    }

    memset(rutaArchivo,0x00,sizeof(rutaArchivo));
    usleep(INTERVALO_CCI_MS * 1000);
  }

  eliminarSemaforo(idSemaforo);
  return 0;
}
