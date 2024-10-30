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
    opcionElegida = 0;
    while(opcionElegida < 1 || opcionElegida > 2)
    {
      printf("Ingrese una opción:\n");
      printf("1.Leer Panel\n");
      printf("2.Escribir Panel\n");
      scanf("%d",&opcionElegida);
    }

    panelElegido = 0;
    while(panelElegido < 1 || panelElegido > 3)
    {
      printf("Ingrese una panel (1, 2 o 3):\n");
      scanf("%d",&panelElegido);
    }
    
    /*printf("CCI: Esperando Acceso...\n");*/
    strcpy(rutaArchivo, obtenerRutaArchivoPanel(panelElegido));
    esperaSemaforo(idSemaforoPanel);

    while (!abrirLectura(rutaArchivo))
    {
      printf("CCI: Hubo un error al querer abrir el archivo\n");
      levantaSemaforo(idSemaforoPanel);
      usleep(INTERVALO_CCI_MS*10000);
      esperaSemaforo(idSemaforoPanel);
    }
    /*printf("CCI: Acceso Obtenido...\n");*/
    leerPanel();
    cerrarArchivo();
    
    if (opcionElegida == 2)
    {
      while (!abrirEscritura(rutaArchivo))
      {
        printf("CCI: Hubo un error al querer abrir el archivo\n");
        levantaSemaforo(idSemaforoPanel);
        usleep(INTERVALO_CCI_MS*10000);
        esperaSemaforo(idSemaforoPanel);
      }
      escribirPanel();
      cerrarArchivo();
      
      /*Leo nuevamente el archivo para verificar*/
      /*que los cambios hayan impactado correctamente*/
      while (!abrirLectura(rutaArchivo))
      {
        printf("CCI: Hubo un error al querer abrir el archivo\n");
        levantaSemaforo(idSemaforoPanel);
        usleep(INTERVALO_CCI_MS*10000);
        esperaSemaforo(idSemaforoPanel);
      }
      leerPanel();
      cerrarArchivo();
    }

    levantaSemaforo(idSemaforoPanel);
    memset(rutaArchivo,0x00,sizeof(rutaArchivo));
    usleep(INTERVALO_CCI_MS * 30000);
  }
  free(rutaArchivo);
  return 0;
}
