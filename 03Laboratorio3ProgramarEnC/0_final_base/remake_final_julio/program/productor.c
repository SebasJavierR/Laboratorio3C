/*Librerias*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Librerias Propias*/
#include "framework/archivos.h"
#include "defines.h"
#include "funciones.h"
/*Archivo .h*/
#include "productor.h"

void escribirLinea(int valorNumerico)
{
  char* linea;
  char caracter;
  linea = (char*)malloc(sizeof(char)*LARGO_LINEA);
  memset(linea,0x00,sizeof(char)*LARGO_LINEA);
  strcpy(&caracter, obtenerCaracterPorNumero(valorNumerico));
  sprintf(linea , FORMATO_OUTPUT_ARCHIVO, caracter, valorNumerico);
  escribirArchivo(linea);
  printf("%s\n", linea);
  free(linea);
}
