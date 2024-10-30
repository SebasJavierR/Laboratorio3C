#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "defines.h"
#include "globals.h"
#include "funciones.h"
#include "semaforos.h"

void iniciarMemoria(dato* memoria, int vias)
{
  memoria[POS_INI_MEM].vehiculosEnColas = (int*)malloc((vias)*sizeof(int));
  /* Inicializo posiciones del array en 0 */
  memset(memoria[POS_INI_MEM].vehiculosEnColas,0x00,sizeof(memoria[POS_INI_MEM].vehiculosEnColas));
}

void liberarAsignacionesMemoria(dato* memoria)
{
  free(memoria[POS_INI_MEM].vehiculosEnColas);
}

void iniciarMemoriaInicial(inicial* memoria)
{
  memoria[POS_INI_MEM].inicializado = 1;
}

void aumentarVehiculosEnCola(dato* memoria, int via)
{
  memoria[POS_INI_MEM].vehiculosEnCola[via]++;
}

void decrementarVehiculosEnCola(dato* memoria, int via)
{
  memoria[POS_INI_MEM].vehiculosEnCola[via]--;
}

void escribirVehiculosEnCola(dato* memoria, int via, int valor)
{
  memoria[POS_INI_MEM].vehiculosEnCola[via] = valor;
}
