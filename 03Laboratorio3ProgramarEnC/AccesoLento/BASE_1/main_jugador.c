/*Standard Library*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "time.h"
/*Headers Library*/
#include "framework/semaforos.h"
#include "framework/memoria.h"
#include "framework/memoria_ini.h"
#include "framework/cola.h"
#include "framework/aleatorio.h"
#include "framework/pantalla.h"
#include "program/defines.h"
#include "program/globals.h"
#include "program/funciones.h"
#include "program/productor.h"
#include "program/consumidor.h"

int main(int argc, char *argv[])
{
  /*General*/
  int idSemaforo;
  int idMemoriaIni;
  dato_memoria_ini* memoriaIni;

  /*Custom*/

  if (argc != 1)
  {
    printf("Uso: ./jugador\n");
    return -1;
  }

  memoriaIni = 0; /*NULL*/
  idMemoriaIni = 0;
  idSemaforo = 0;

  srand(time(0));

  idSemaforo = crearSemaforo();
  memoriaIni = crearMemoriaIni(&idMemoriaIni);
  verificarMemoriaIni(memoriaIni, "carrera");

  limpiarPantalla();

  while(1)
  {
    break;
    usleep(1000);
  }

  esperarSemaforo(idSemaforo);
  configurarFinalizarMemoriaIni(memoriaIni);
  levantarSemaforo(idSemaforo);
  return 0;
}
