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
#include "consumidor.h"

int main(int argc, char *argv[])
{
  int idSemaforoPanel;
  int opcionElegida;
  int panelElegido;
  char* rutaArchivo;

  if (argc != 1)
  {
    printf("Uso: ./cci \n");
    return 0;
  }
  
  srand(time(0));
  
  idSemaforoPanel = creoSemaforo();
  iniciaSemaforo(idSemaforoPanel, VERDE);

  rutaArchivo = (char*)malloc(100*sizeof(char));
  memset(rutaArchivo,0x00,sizeof(rutaArchivo));

  /* Inicializo Archivos */

  inicializarPanel(1, idSemaforoPanel);
  inicializarPanel(2, idSemaforoPanel);
  inicializarPanel(3, idSemaforoPanel);
  
  while(1)
  {
    

    levantaSemaforo(idSemaforoPanel);
    memset(rutaArchivo,0x00,sizeof(rutaArchivo));
    usleep(INTERVALO_CCI_MS * 30000);
  }
  free(rutaArchivo);
  return 0;
}
