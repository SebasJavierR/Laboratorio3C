#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "defines.h"
#include "funciones.h"
#include "gestionararchivos.h"

void leerPanel()
{
 char mensaje[LARGO_LINEA+1];
 memset(mensaje,0x00,sizeof(mensaje));
 while(!esFinArchivo())
 {
   leerArchivo(mensaje);
   printf("valor actual: %s\n", mensaje);
   memset(mensaje,0x00,sizeof(mensaje));
 }
}

void renderPanel(char* mensajeActual)
{
 char* mensaje;
 mensaje = (char*)malloc((LARGO_LINEA+1)*sizeof(char));
 memset(mensaje,0x00,sizeof(mensaje));

 while(!esFinArchivo())
 {
   leerArchivo(mensaje);
   if (strstr(mensajeActual, mensaje)==0)
   {
    strcpy(mensajeActual, mensaje);
    limpiarPantalla();
    printf("%s\n", mensaje);
   }
   memset(mensaje,0x00,sizeof(mensaje));
 }
 free(mensaje);
}
