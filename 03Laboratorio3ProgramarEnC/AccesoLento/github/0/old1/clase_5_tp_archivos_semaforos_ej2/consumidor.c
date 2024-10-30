#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "defines.h"
#include "funciones.h"
#include "gestionararchivos.h"

void leerDepositoCajero(int* monto, int* esEfectivo)
{
 char deposito[LARGO_LINEA+1];
 memset(mensaje,0x00,sizeof(mensaje));
 while(!esFinArchivo())
 {
   leerArchivo(mensaje);
   sprintf("valor actual: %s\n", mensaje);
   memset(mensaje,0x00,sizeof(mensaje));
 }
}

void renderCajero()
{
 char* mensaje;
 mensaje = (char*)malloc((LARGO_LINEA+1)*sizeof(char));
 memset(mensaje,0x00,sizeof(mensaje));

 limpiarPantalla();
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

void backupLote(int numLote, int numCajero)
{
  char nuevoLote[32+1];
  sprintf(nuevoLote, RUTA_ARCHIVO_LOTE_BAK, numCajero, numLote);
  renombrarArchivo(RUTA_ARCHIVO_LOTE, nuevoLote);
  limpiarArchivo(RUTA_ARCHIVO_LOTE);
  printf("Generado Backup: %s\n", nuevoLote);
}
