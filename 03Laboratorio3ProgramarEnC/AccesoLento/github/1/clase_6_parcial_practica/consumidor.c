#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "defines.h"
#include "funciones.h"
#include "gestionararchivos.h"

void leerPanel()
{
 char mensaje[100+1];
 memset(mensaje,0x00,sizeof(mensaje));
 while(!esFinArchivo())
 {
   leerArchivo(mensaje);
   printf("%s\n", mensaje);
   memset(mensaje,0x00,sizeof(mensaje));
 }
}
