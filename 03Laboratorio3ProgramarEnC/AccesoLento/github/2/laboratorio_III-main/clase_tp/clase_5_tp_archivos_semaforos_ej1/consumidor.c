#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "defines.h"
#include "funciones.h"
#include "gestionararchivos.h"

int leerReservas()
{
  char reserva[100+1];
  int pasajeros[11];
  int numero;
  int i;
  char* destino;
  char* texto;
  
  destino = (char*)malloc(20+1 * sizeof(char));
  texto = (char*)malloc(20+1 * sizeof(char));
 
  memset(reserva,0x00,sizeof(reserva));
  
  for (i=0; i <= 10; i++)
  {
    pasajeros[i] = 0;
  } 
  while(!esFinArchivo())
  {
    if (leerArchivo(reserva) == 0)
    {
      return -1;
    }

    if (strstr(reserva, "VUELO")!=0)
    {
      numero = 0;
      leerArchivo(reserva);
      sscanf(reserva,"%d\n",&numero);
      if (numero >= 1000 && numero <= 1010)
      {
        pasajeros[numero-NUM_VUELO_MIN]++;
      }
    }
    memset(reserva,0x00,sizeof(reserva));
  }
  printf("VUELO DESTINO PASAJEROS\n");
  for (i = 0; i<=10; i++)
  {
    strcpy(destino, obtenerDestino(i+NUM_VUELO_MIN));
    printf("%d %s %d\n",i+NUM_VUELO_MIN,destino,pasajeros[i]);
  }
  free(texto);
  free(destino);
  return 0;
}

void backupLote(int numLote)
{
  char nuevoLote[32+1];
  sprintf(nuevoLote, RUTA_ARCHIVO_LOTE_BAK, numLote);
  renombrarArchivo(RUTA_ARCHIVO_LOTE, nuevoLote);
  limpiarArchivo(RUTA_ARCHIVO_LOTE);
}
