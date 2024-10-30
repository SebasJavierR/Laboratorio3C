#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "time.h"
#include "defines.h"
#include "gestionararchivos.h"
#include "semaforos.h"
#include "funciones.h"
#include "consumidor.h"

int main(int argc, char *argv[])
{
  int idSemaforoPanel;
  int panelElegido;
  char* rutaArchivo;
  char* mensajeActual;

  if (argc != 2)
  {
    printf("Uso: ./panel [1-3]\n");
    return 0;
  }

	panelElegido = atoi(argv[1]);
  
  srand(time(0));
  rutaArchivo = (char*)malloc((LARGO_RUTA+1)*sizeof(char));
  mensajeActual = (char*)malloc((LARGO_LINEA+1)*sizeof(char));
  memset(rutaArchivo,0x00,sizeof(rutaArchivo));
  memset(mensajeActual,0x00,sizeof(mensajeActual));

  strcpy(rutaArchivo, obtenerRutaArchivoPanel(panelElegido));

  idSemaforoPanel = creoSemaforo();

  while(1)
  {
  

  
    renderPanel(mensajeActual);
    cerrarArchivo();
    levantaSemaforo(idSemaforoPanel);
    memset(mensajeActual,0x00,sizeof(mensajeActual));
    usleep(INTERVALO_PANEL_MS * 1000);
  }
  free(rutaArchivo);
  free(mensajeActual);
  return 0;
}
