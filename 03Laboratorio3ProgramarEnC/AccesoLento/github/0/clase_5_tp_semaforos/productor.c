#include "stdio.h"
#include "string.h"
#include "defines.h"
#include "gestionararchivos.h"

void escribirProductos()
{
  int cantProd;
  int i;
  char nom[32+1];
  char producto[100+1];
  printf("Ingrese cantidad de productos:");
  scanf("%d",&cantProd);
  memset(nom,0x00,sizeof(nom));
  i = 1;
  while(i <= cantProd)
  {
    printf("Ingrese Nombre del Producto %d:\n", i);
    scanf("%s",nom);
    sprintf(producto,"PRODUCTO-%02d %s %d\n",i,nom,UNIDADES_LOTE);    
    escribirArchivo(producto);
    memset(nom,0x00,sizeof(nom));
    i++;
  }
}



