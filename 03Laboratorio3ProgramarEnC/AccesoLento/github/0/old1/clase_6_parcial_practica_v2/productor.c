#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "defines.h"
#include "gestionararchivos.h"
#include "funciones.h"
#include "semaforos.h"

void escribirPanel()
{
  char* mensaje;
  char* mensajeConFormato;

  mensaje = (char*)malloc(100*sizeof(char));
  mensajeConFormato = (char*)malloc(100*sizeof(char));
  printf("Ingrese un nuevo mensaje: ");
  scanf("%s",mensaje);
  sprintf(mensajeConFormato,"%s\n",mensaje);
  escribirArchivo(mensajeConFormato);
  free(mensaje);
  free(mensajeConFormato);
}

void escribirMensajeDefaultPanel()
{
  escribirArchivo(MENSAJE_DEFAULT);
}

void inicializarPanel(int numeroPanel, int idSemaforoPanel)
{
  char* rutaArchivo;
  rutaArchivo = (char*)malloc(100*sizeof(char));
  memset(rutaArchivo,0x00,sizeof(rutaArchivo));
  strcpy(rutaArchivo, obtenerRutaArchivoPanel(numeroPanel));
  esperaSemaforo(idSemaforoPanel);
  while (!abrirEscritura(rutaArchivo))
  {
    printf("CCI: Hubo un error al querer abrir el archivo\n");
    levantaSemaforo(idSemaforoPanel);
    usleep(INTERVALO_CCI_MS*10000);
    esperaSemaforo(idSemaforoPanel);
  }
  escribirMensajeDefaultPanel();
  cerrarArchivo();
  levantaSemaforo(idSemaforoPanel);
  free(rutaArchivo);
}



