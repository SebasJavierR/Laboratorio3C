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

int leerArchivo(char* linea)
{
  return fscanf(cfptr,"%s\n",linea);
}

void cerrarArchivo()
{
  fclose(cfptr);
}

int abrirLectura(char* ruta)
{
  return abrirArchivo(ruta, "r");
}

int abrirEscritura(char* ruta)
{
  return abrirArchivo(ruta, "w");
}

int abrirAdicion(char* ruta)
{
  return abrirArchivo(ruta, "a");
}

void limpiarArchivo(char* ruta)
{
  abrirEscritura(ruta);
  cerrarArchivo();
}

int esFinArchivo()
{
  return feof(cfptr);
}

int renombrarArchivo(char* ruta, char* rutaNuevoNombre)
{
  return rename(ruta, rutaNuevoNombre);
} 
