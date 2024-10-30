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
  int idSemaforoPanel1;
  int idSemaforoPanel2;
  int idSemaforoPanel3;
  int opcionElegida;
  int panelElegido;

  if (argc != 1)
  {
    printf("Uso: ./cci \n");
    return 0;
  }
  
  srand(time(0));
  
  idSemaforoPanel1 = creoSemaforoConClave(CLAVE_BASE_PANEL_1);
  idSemaforoPanel2 = creoSemaforoConClave(CLAVE_BASE_PANEL_2);
  idSemaforoPanel3 = creoSemaforoConClave(CLAVE_BASE_PANEL_3);
  
  iniciaSemaforo(idSemaforoPanel1, VERDE);
  iniciaSemaforo(idSemaforoPanel2, VERDE);
  iniciaSemaforo(idSemaforoPanel3, VERDE);

  /* Inicializo Archivos */
  esperaSemaforo(idSemaforoPanel1);
  while (!abrirEscritura(RUTA_ARCHIVO_PANEL_1))
  {
    printf("CCI: Hubo un error al querer abrir el archivo\n");
    levantaSemaforo(idSemaforoPanel1);
    usleep(INTERVALO_CCI_MS*10000);
    esperaSemaforo(idSemaforoPanel1);
  }
  escribirDefaultPanel();
  cerrarArchivo(RUTA_ARCHIVO_PANEL_1);
  levantaSemaforo(idSemaforoPanel1);

  esperaSemaforo(idSemaforoPanel2);
  while (!abrirEscritura(RUTA_ARCHIVO_PANEL_2))
  {
    printf("CCI: Hubo un error al querer abrir el archivo\n");
    levantaSemaforo(idSemaforoPanel2);
    usleep(INTERVALO_CCI_MS*10000);
    esperaSemaforo(idSemaforoPanel2);
  }
  escribirDefaultPanel();
  cerrarArchivo(RUTA_ARCHIVO_PANEL_2);
  levantaSemaforo(idSemaforoPanel2);

  esperaSemaforo(idSemaforoPanel3);
  while (!abrirEscritura(RUTA_ARCHIVO_PANEL_3))
  {
    printf("CCI: Hubo un error al querer abrir el archivo\n");
    levantaSemaforo(idSemaforoPanel3);
    usleep(INTERVALO_CCI_MS*10000);
    esperaSemaforo(idSemaforoPanel3);
  }
  escribirDefaultPanel();
  cerrarArchivo(RUTA_ARCHIVO_PANEL_3);
  levantaSemaforo(idSemaforoPanel3);
  
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
    
    printf("CCI: Esperando Acceso...\n");
    switch(panelElegido)
    {
      case 1:
        esperaSemaforo(idSemaforoPanel1);
        break;
      case 2:
        esperaSemaforo(idSemaforoPanel2);
        break;
      case 3:
        esperaSemaforo(idSemaforoPanel3);
        break;
    }

    if (opcionElegida == 1)
    {
      switch(panelElegido)
      {
      case 1:
        while (!abrirLectura(RUTA_ARCHIVO_PANEL_1))
        {
          printf("CCI: Hubo un error al querer abrir el archivo\n");
          levantaSemaforo(idSemaforoPanel1);
          usleep(INTERVALO_CCI_MS*10000);
          esperaSemaforo(idSemaforoPanel1);
        }
        break;
      case 2:
        while (!abrirLectura(RUTA_ARCHIVO_PANEL_2))
        {
          printf("CCI: Hubo un error al querer abrir el archivo\n");
          levantaSemaforo(idSemaforoPanel2);
          usleep(INTERVALO_CCI_MS*10000);
          esperaSemaforo(idSemaforoPanel2);
        }
        break;
      case 3:
        while (!abrirLectura(RUTA_ARCHIVO_PANEL_3))
        {
          printf("CCI: Hubo un error al querer abrir el archivo\n");
          levantaSemaforo(idSemaforoPanel3);
          usleep(INTERVALO_CCI_MS*10000);
          esperaSemaforo(idSemaforoPanel3);
        }
        break;
      }
      printf("CCI: Acceso Obtenido...\n");
      leerPanel();
    }
    else
    {
      switch(panelElegido)
      {
      case 1:
        while (!abrirEscritura(RUTA_ARCHIVO_PANEL_1))
        {
          printf("CCI: Hubo un error al querer abrir el archivo\n");
          levantaSemaforo(idSemaforoPanel1);
          usleep(INTERVALO_CCI_MS*10000);
          esperaSemaforo(idSemaforoPanel1);
        }
        break;
      case 2:
        while (!abrirEscritura(RUTA_ARCHIVO_PANEL_2))
        {
          printf("CCI: Hubo un error al querer abrir el archivo\n");
          levantaSemaforo(idSemaforoPanel2);
          usleep(INTERVALO_CCI_MS*10000);
          esperaSemaforo(idSemaforoPanel2);
        }
        break;
      case 3:
        while (!abrirEscritura(RUTA_ARCHIVO_PANEL_3))
        {
          printf("CCI: Hubo un error al querer abrir el archivo\n");
          levantaSemaforo(idSemaforoPanel3);
          usleep(INTERVALO_CCI_MS*10000);
          esperaSemaforo(idSemaforoPanel3);
        }
        break;
      }
      escribirPanel();
    }

    switch(panelElegido)
    {
      case 1:
        cerrarArchivo(RUTA_ARCHIVO_PANEL_1);
        levantaSemaforo(idSemaforoPanel1);
        break;
      case 2:
        cerrarArchivo(RUTA_ARCHIVO_PANEL_2);
        levantaSemaforo(idSemaforoPanel2);
        break;
      case 3:
        cerrarArchivo(RUTA_ARCHIVO_PANEL_3);
        levantaSemaforo(idSemaforoPanel3);
        break;
    }
    usleep(INTERVALO_CCI_MS * 30000);
  }
  return 0;
}
