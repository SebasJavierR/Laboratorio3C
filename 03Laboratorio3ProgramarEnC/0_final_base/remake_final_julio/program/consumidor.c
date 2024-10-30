/*Librerias*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Librerias Propias*/
#include "framework/archivos.h"
#include "defines.h"
/*Archivo .h*/
#include "consumidor.h"

void leerLineas(void)
{
  char* linea;
  char caracter;
  int valorNumerico;

  linea = (char*)malloc(sizeof(char)*LARGO_LINEA);
  memset(linea,0x00,sizeof(char)*LARGO_LINEA);
  while(leerLineaArchivo(linea) != 0)
  {
    sscanf(linea, FORMATO_OUTPUT_ARCHIVO, &caracter, &valorNumerico);
    printf(FORMATO_OUTPUT_PANTALLA, caracter, valorNumerico);
  
    memset(linea,0x00,sizeof(char)*LARGO_LINEA);
  }
  free(linea);
}
