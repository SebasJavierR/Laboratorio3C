/*Standard Library*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/*Headers Library*/
#include "libCommon/archivos.h"
#include "libCommon/pantalla.h"
#include "defines.h"
#include "globals.h"
#include "funciones.h"
/*File Header*/
#include "consumidor.h"

void leerPanel()
{
 char mensaje[LARGO_LINEA+1];
 memset(mensaje,0x00,sizeof(char)*(LARGO_LINEA+1));
 while(leerLineaArchivo(mensaje) != 0)
 {
   printf("valor actual: %s\n", mensaje);
   memset(mensaje,0x00,sizeof(mensaje));
 }
}

void renderPanel(char* mensajeActual)
{
 char mensaje[LARGO_LINEA+1];
 memset(mensaje,0x00,sizeof(char)*(LARGO_LINEA+1));
 while(leerLineaArchivo(mensaje) != 0)
 {
   if (strstr(mensajeActual, mensaje)==0)
   {
    strcpy(mensajeActual, mensaje);
    limpiarPantalla();
    printf("%s\n", mensaje);
   }
   memset(mensaje,0x00,sizeof(mensaje));
 }
}
