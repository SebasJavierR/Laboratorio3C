/*Librerias*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/*Librerias de Headers*/
#include "defines.h"
/*Header*/
#include "funciones.h"

char* obtenerCaracterPorNumero(int valor)
{
  switch(valor)
  {
    case 1:
      return "A";
  }
  return 0;
}

int obtenerNumeroPorCaracter(char* valor)
{
  if (strcmp("A", valor) == 0)
  {
    return 1;
  }
  return -1;
}

/*
  Ejemplo:
  char * rutArchivo
  rutaArchivo = (char*)malloc((LARGO_RUTA+1)*sizeof(char));
  memset(rutaArchivo,0x00,sizeof(rutaArchivo));
  strcpy(rutaArchivo, obtenerRutaArchivo(1));
*/
char* obtenerRutaArchivo(int valor)
{
  switch(valor)
  {
    case 1:
      return RUTA_ARCHIVO;
  }
  return "";
}
