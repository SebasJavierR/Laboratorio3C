#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "time.h"
#include "defines.h"
#include "globals.h"
#include "semaforos.h"
#include "memoria.h"
#include "funciones.h"
int main(int argc, char *argv[])
{
  int idMemoria;
  int i;
  int aleatorio;
  dato* memoria;
 
  memoria = 0; /*NULL*/
  idMemoria = 0;
  i = 0;
  aleatorio = 0;
  memoria = (dato*)creoMemoria(sizeof(dato)*CANTIDAD, &idMemoria, CLAVE_BASE);

  if (argc != 1)
  {
    printf("Uso: ./uno \n");
    return 0;
  }
  
  srand(time(0));

  while(1)
  {
    printf("Escribimos en la memoria\n");
    for (i=0; i<CANTIDAD; i++)
    {
      aleatorio = obtenerNumeroAleatorio(DESDE, HASTA);
      memoria[i].numero = aleatorio;
      memoria[i].letra = 0x41 + aleatorio;
      /* 0x41: 'A' en ASCII */
      printf("Escrito %d %c\n", memoria[i].numero, memoria[i].letra);
      sleep(1);
    }
    printf("Dejamos de escribir en la memoria\n");
    sleep(10);
  }
  liberoMemoria(idMemoria, (char*)memoria);
  return 0;
}
