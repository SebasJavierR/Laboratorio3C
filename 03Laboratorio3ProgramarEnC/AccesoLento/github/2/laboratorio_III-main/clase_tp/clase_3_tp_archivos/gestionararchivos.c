#include "gestionararchivos.h"
#include "stdio.h"

int abrirArchivo(char* ruta, char* modo, FILE** fp)
{
  return (*fp=fopen(ruta,modo))!=0;
}

void cerrarArchivo(FILE* fp)
{
  fclose(fp);
}

int esFinArchivo(FILE* fp)
{
  return feof(fp);
}
