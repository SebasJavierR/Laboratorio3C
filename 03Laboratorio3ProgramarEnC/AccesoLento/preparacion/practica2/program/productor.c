/*Librerias*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/*Encabezados*/
#include "framework/archivos.h"
#include "program/defines.h"
#include "program/funciones.h"

#include "productor.h"

void escribirLinea(int valorNumerico)
{
  char* linea;
  char caracter;
  linea = (char*)malloc((LARGO_LINEA+1)*sizeof(char));
  memset(linea,0x00,sizeof(linea));
  strcpy(&caracter, obtenerCaracterPorNumero(valorNumerico));
  sprintf(linea , FORMATO_OUTPUT_ARCHIVO, caracter, valorNumerico);
  escribirArchivo(linea);
  printf(linea);
  free(linea);
}
