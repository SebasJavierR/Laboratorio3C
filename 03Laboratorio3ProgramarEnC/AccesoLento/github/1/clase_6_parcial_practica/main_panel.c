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
void renderPanel(char* mensajeActual)
{
 char mensaje[100+1];
 memset(mensaje,0x00,sizeof(mensaje));
 while(!esFinArchivo())
 {
   leerArchivo(mensaje);
   if (strstr(mensajeActual, mensaje)==0)
   {
    strcpy(mensajeActual, mensaje);
    system("clear");
    printf("%s\n", mensaje);
   }
   memset(mensaje,0x00,sizeof(mensaje));
 }
}

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
  rutaArchivo = (char*)malloc(30*sizeof(char));
  mensajeActual = (char*)malloc(100*sizeof(char));
  idSemaforoPanel=0;
  switch(panelElegido)
  {
    case 1:
      strcpy(rutaArchivo, RUTA_ARCHIVO_PANEL_1);
      idSemaforoPanel = creoSemaforoConClave(CLAVE_BASE_PANEL_1);
      break;
    case 2:
      strcpy(rutaArchivo, RUTA_ARCHIVO_PANEL_2);
      idSemaforoPanel = creoSemaforoConClave(CLAVE_BASE_PANEL_2);
      break;
    case 3:
      strcpy(rutaArchivo, RUTA_ARCHIVO_PANEL_3);
      idSemaforoPanel = creoSemaforoConClave(CLAVE_BASE_PANEL_3);
      break;
  }
  
  iniciaSemaforo(idSemaforoPanel, VERDE);
  
  while(1)
  {
    /*printf("PANEL: Esperando Acceso...\n");*/
    esperaSemaforo(idSemaforoPanel);
    while (!abrirLectura(rutaArchivo))
    {
      printf("PANEL: Hubo un error al querer abrir el archivo\n");
      levantaSemaforo(idSemaforoPanel);
      usleep(INTERVALO_CCI_MS*10000);
      esperaSemaforo(idSemaforoPanel);
    }
    /*printf("PANEL: Acceso Obtenido...\n");*/
    renderPanel(mensajeActual);
    cerrarArchivo(rutaArchivo);
    levantaSemaforo(idSemaforoPanel);
    usleep(INTERVALO_PANEL_MS * 1000);
  }
  free(rutaArchivo);
  free(mensajeActual);
  return 0;
}
