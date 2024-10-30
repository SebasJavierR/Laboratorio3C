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
  int panelElegido;
  char rutaArchivo[LARGO_RUTA+1];
  char mensajeActual[LARGO_RUTA+1];

  /*Custom*/

  if (argc != 2)
  {
    printf("Uso: ./panel [1-3]\n");
    return -1;
  }

  idSemaforo = 0;
  panelElegido = atoi(argv[1]);

  if (panelElegido < PANEL_1 || panelElegido > PANEL_3)
  {
    printf("Ingrese 1, 2 o 3\n");
    return 0;
  }

  srand(time(0));

  printf("Atención: Recuerde levantar el programa inicial \"cci\". Presione \"enter\" para continuar...");
  getchar();
  limpiarPantalla();

  memset(rutaArchivo,0x00,sizeof(char)*(LARGO_RUTA+1));
  memset(mensajeActual,0x00,sizeof(char)*(LARGO_RUTA+1));
  strcpy(rutaArchivo, obtenerRutaArchivoPanel(panelElegido));

  idSemaforo = crearSemaforo();

  limpiarPantalla();

  while(1)
  {
    esperarSemaforo(idSemaforo);
    if (abrirLectura(rutaArchivo))
    {
      renderPanel(mensajeActual);
      cerrarArchivo();
    }
    levantarSemaforo(idSemaforo);
    memset(mensajeActual,0x00,sizeof(char)*(LARGO_RUTA+1));
    usleep(INTERVALO_PANEL_MS * 1000);
  }
  return 0;
}

