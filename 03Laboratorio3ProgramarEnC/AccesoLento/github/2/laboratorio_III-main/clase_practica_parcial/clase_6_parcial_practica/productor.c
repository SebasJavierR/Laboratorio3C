#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "defines.h"
#include "gestionararchivos.h"
#include "funciones.h"
#include "productor.h"

void escribirPanel()
{
  char* mensaje;
  char* mensajeConFormato;

  mensaje = (char*)malloc(100*sizeof(char));
  mensajeConFormato = (char*)malloc(100*sizeof(char));
  printf("Ingrese un nuevo mensaje:");
  scanf("%s",mensaje);
  sprintf(mensajeConFormato,"%s\n",mensaje);
  escribirArchivo(mensajeConFormato);
  free(mensaje);
  free(mensajeConFormato);
}

void escribirDefaultPanel()
{
  escribirArchivo(MENSAJE_DEFAULT);
}



