#include "stdio.h"
#include "string.h"
#include "defines.h"
#include "gestionararchivos.h"

void leerProductos()
{
  char producto[100+1];
  memset(producto,0x00,sizeof(producto));
  printf("Los productos ingresados son:\n");
  while(!esFinArchivo())
  {
    leerArchivo(producto);
    printf("%s\n",producto);
    memset(producto,0x00,sizeof(producto));
  }
}
