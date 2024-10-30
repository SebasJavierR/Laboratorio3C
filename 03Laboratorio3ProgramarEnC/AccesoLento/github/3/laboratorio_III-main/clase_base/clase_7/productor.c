#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "defines.h"
#include "globals.h"
#include "funciones.h"
#include "semaforos.h"

void iniciarMemoria(dato* memoria)
{
  int i;
  for (i = 0; i < CANTIDAD; i++)
  {
    memoria[i].numero = 0;
    memoria[i].letra = 0x00;
    memoria[i].inicializado = 1;
  }
}

void escribirMemoria(dato* memoria)
{
  int i;
  int aleatorio;
  aleatorio = 0;
  for (i = 0; i < CANTIDAD; i++)
  {
    aleatorio = obtenerNumeroAleatorio(DESDE, HASTA);
    memoria[i].numero = aleatorio;
    memoria[i].letra = 0x41 + aleatorio;
    /* 0x41: 'A' en ASCII */
    printf("Escrito %d %c\n", memoria[i].numero, memoria[i].letra);
    sleep(1);
  }
  printf("Dejamos de escribir en la memoria\n");
}
