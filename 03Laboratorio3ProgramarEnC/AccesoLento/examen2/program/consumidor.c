/*Librerias*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/*Encabezados*/
#include "framework/archivos.h"
#include "program/defines.h"

#include "consumidor.h"

void leerLineas()
{
  char* linea;
  char caracter;
  int valorNumerico;

  linea = (char*)malloc((LARGO_LINEA)*sizeof(char));
  memset(linea,0x00,sizeof(linea));
  while(leerLineaArchivo(linea) != 0)
  {
    sscanf(linea, FORMATO_OUTPUT_ARCHIVO, &caracter, &valorNumerico);
    printf(FORMATO_OUTPUT_PANTALLA, caracter, valorNumerico);
  
    memset(linea,0x00,sizeof(linea));
  }
  free(linea);
}
