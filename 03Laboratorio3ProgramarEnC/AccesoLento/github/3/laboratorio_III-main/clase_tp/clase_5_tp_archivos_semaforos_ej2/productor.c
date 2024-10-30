#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "defines.h"
#include "gestionararchivos.h"
#include "funciones.h"
#include "semaforos.h"

void escribirDeposito(int monto, int esCheque)
{
  char* deposito;
  deposito = (char*)malloc((LARGO_LINEA+1)*sizeof(char));
  memset(deposito,0x00,sizeof(deposito));
  sprintf(deposito,"%d %d\n", monto, esCheque);
  escribirArchivo(deposito);
  printf(deposito);
  free(deposito);
}


