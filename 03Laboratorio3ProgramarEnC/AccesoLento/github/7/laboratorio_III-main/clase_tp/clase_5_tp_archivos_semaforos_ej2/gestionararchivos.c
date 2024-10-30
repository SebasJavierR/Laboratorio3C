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

int leerArchivo(char* linea)
{
  return fscanf(cfptr,"%s\n",linea);
}

int leerNumeroArchivo(int* numero)
{
  return fscanf(cfptr,"%d",numero);
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
  char* mensaje;
  char* mensajeConFormato;
  mensaje = (char*)malloc((LARGO_LINEA+1)*sizeof(char));
  memset(mensaje,0x00,sizeof(mensaje));
  mensajeConFormato = (char*)malloc((LARGO_LINEA+1)*sizeof(char));
  memset(mensajeConFormato,0x00,sizeof(mensajeConFormato));

  if (!abrirLectura(ruta))
  {
   printf("Hubo un error al querer abrir el archivo\n");
   return -1;
  }

  while(!esFinArchivo())
  {
    leerArchivo(mensaje);
    cerrarArchivo();
    if (!abrirAdicion(rutaNuevoNombre))
    {
      printf("Hubo un error al querer abrir el archivo\n");
      return -1;
    }
    sprintf(mensajeConFormato,"%s\n",mensaje);
    escribirArchivo(mensajeConFormato);
    cerrarArchivo();
    memset(mensaje,0x00,sizeof(mensaje));
    memset(mensajeConFormato,0x00,sizeof(mensaje));
    if (!abrirLectura(ruta))
    {
     printf("Hubo un error al querer abrir el archivo\n");
     return -1;
    }
  }
  limpiarArchivo(ruta);
  printf("Ruta Backup: %s\n", rutaNuevoNombre);
  free(mensaje);
  free(mensajeConFormato);
  return 0;
} 
