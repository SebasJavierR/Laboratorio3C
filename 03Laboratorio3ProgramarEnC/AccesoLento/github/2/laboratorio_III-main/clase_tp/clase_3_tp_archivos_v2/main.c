#include "stdio.h"
#include "string.h"
#include "defines.h"
#include "gestionararchivos.h"
#include "productor.h"
#include "consumidor.h"
int main(int argc, char *argv[]) {

  if (argc != 1)
  {
    printf("Uso: ./archivos \n");
    return 0;
  }
  if (!abrirArchivo(RUTA_ARCHIVO_PRODUCTO,"w"))
  {
    printf("Hubo un error al querer abrir el archivo\n");
    return 0;
  }
  escribirProductos();
  cerrarArchivo();

  if (!abrirArchivo(RUTA_ARCHIVO_PRODUCTO,"r"))
  {
    printf("Hubo un error al querer abrir el archivo\n");
    return 0;
  }
  leerProductos();
  cerrarArchivo();
  return 0;
}
