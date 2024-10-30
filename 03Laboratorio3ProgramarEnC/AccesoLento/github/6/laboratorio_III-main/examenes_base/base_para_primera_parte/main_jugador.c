/*Standard Library*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "time.h"
/*Headers Library*/
#include "libCommon/semaforos.h"
#include "libCommon/memoria.h"
#include "libCommon/memoria_ini.h"
#include "libCommon/cola.h"
#include "libCommon/aleatorio.h"
#include "libCommon/pantalla.h"
#include "libCore/defines.h"
#include "libCore/globals.h"
#include "libCore/funciones.h"
#include "libCore/productor.h"
#include "libCore/consumidor.h"

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
