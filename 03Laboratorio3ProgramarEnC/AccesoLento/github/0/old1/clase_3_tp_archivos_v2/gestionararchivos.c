#include "gestionararchivos.h"
#include "stdio.h"

FILE* cfptr;

int abrirArchivo(char* ruta, char* modo)
{
  return (cfptr=fopen(ruta,modo))!=0;
}

void escribirArchivo(char* linea)
{
  fprintf(cfptr,linea);
}

void leerArchivo(char* linea)
{
  fscanf(cfptr,"%s\n",linea);
}

void cerrarArchivo()
{
  fclose(cfptr);
}

int esFinArchivo()
{
  return feof(cfptr);
}
