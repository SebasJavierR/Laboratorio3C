/*Standard Library*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
/*Headers Library*/
#include "libCommon/semaforos.h"
#include "libCommon/archivos.h"
#include "defines.h"
#include "globals.h"
#include "funciones.h"
#include "menus.h"
/*File Header*/
#include "productor.h"

void escribirPanel()
{
  char mensaje[LARGO_LINEA];
  char mensajeConFormato[LARGO_LINEA];
  memset(mensaje,0x00,sizeof(char)*LARGO_LINEA);
  memset(mensaje,0x00,sizeof(char)*LARGO_LINEA);

  printf("Ingrese un nuevo mensaje: \n");
  scanf("%s", mensaje);
  sprintf(mensajeConFormato, "%s", mensaje);
  escribirArchivo(mensajeConFormato);
}

void escribirMensajeDefaultPanel()
{
  escribirArchivo(MENSAJE_DEFAULT);
}

void inicializarPanel(int numeroPanel, int idSemaforoPanel)
{
  char rutaArchivo[LARGO_LINEA];
  memset(rutaArchivo,0x00,sizeof(char)*LARGO_LINEA);
  strcpy(rutaArchivo, obtenerRutaArchivoPanel(numeroPanel));
  esperarSemaforo(idSemaforoPanel);
  while (!abrirEscritura(rutaArchivo))
  {
    levantarSemaforo(idSemaforoPanel);
    usleep(INTERVALO_CCI_MS*10000);
    esperarSemaforo(idSemaforoPanel);
  }
  escribirMensajeDefaultPanel();
  cerrarArchivo();
  levantarSemaforo(idSemaforoPanel);
}

