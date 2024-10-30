#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "defines.h"
#include "gestionararchivos.h"

FILE* cfptr;

int abrirArchivo(char* ruta, char* modo)
{
  return (cfptr=fopen(ruta,modo))!=0;
}

void escribirArchivo(char* linea)
{
  fprintf(cfptr,linea);
}

int leerStringArchivo(char* linea)
{
  return fscanf(cfptr,"%s\n",linea);
}

int leerNumeroArchivo(int* numero)
{
  return fscanf(cfptr,"%d",numero);
}

char* leerLineaArchivo(char* linea)
{
  return fgets(linea, LARGO_LINEA, cfptr);
}

void cerrarArchivo()
{
  if (cfptr != 0)
  {
    fclose(cfptr);
  }
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

int esFinArchivo()
{
  return feof(cfptr);
}

int limpiarArchivo(char* ruta)
{
  if (!abrirEscritura(ruta))
  {
    printf("Hubo un error al querer abrir el archivo\n");
    return -1;
  }
  cerrarArchivo();
  return 0;
}

int renombrarArchivo(char* ruta, char* rutaNuevoNombre)
{
  return rename(ruta, rutaNuevoNombre);
} 

int backupArchivo(char* ruta, char* rutaNuevoNombre)
{
  int cantLineasCopiadas;
  char* mensaje;
  FILE* cfptrBak;

  cantLineasCopiadas = 0;
  mensaje = (char*)malloc((LARGO_LINEA)*sizeof(char));
  memset(mensaje,0x00,sizeof(mensaje));

  if (!abrirLectura(ruta))
  {
   printf("Hubo un error al querer abrir el archivo\n");
   return -1;
  }

  if ((cfptrBak=fopen(rutaNuevoNombre,"a"))==0)
  {
     printf("Hubo un error al querer abrir el archivo de backup\n");
     return -1;
  }

  while(leerLineaArchivo(mensaje) != 0)
  {
    fprintf(cfptrBak,mensaje);
    cantLineasCopiadas++;
    memset(mensaje,0x00,sizeof(mensaje));
  }

  cerrarArchivo();
  fclose(cfptrBak);
  if (cantLineasCopiadas > 0)
  {
    printf("Ruta Backup: %s\n", rutaNuevoNombre);
  }
  free(mensaje);
  return 0;
}  
