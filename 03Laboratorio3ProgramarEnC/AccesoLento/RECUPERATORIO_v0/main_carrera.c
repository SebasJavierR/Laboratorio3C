/*Library*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "time.h"
/*Headers*/
#include "framework/semaforos.h"
#include "framework/memoria.h"
#include "framework/memoria_ini.h"
#include "framework/cola.h"
#include "framework/aleatorio.h"
#include "framework/pantalla.h"
#include "program/defines.h"
#include "program/globals.h"
#include "program/menu_base.h"
#include "program/funciones.h"
#include "program/productor.h"
#include "program/consumidor.h"

int main(int argc, char *argv[])
{
  /*General*/
  int idSemaforo;
  int idMemoriaIni;
  int idMemoria;
  dato_memoria_ini* memoriaIni;
  dato_memoria* memoria;
  int accionElegida = 0;
  int meseroElegido = 0;

  /*Custom*/

  if (argc != 1)
  {
    printf("Uso: ./derivador\n");
    return -1;
  }

  memoriaIni = 0; /*NULL*/
  idMemoriaIni = 0;
  idSemaforo = 0;
  memoria = 0;
  idMemoria = 0;


  srand(time(0));

  idSemaforo = crearSemaforo();
  iniciarSemaforo(idSemaforo, VERDE);

  memoriaIni = crearMemoriaIni(&idMemoriaIni);
  memoria = (dato_memoria*)crearMemoria(sizeof(dato_memoria)*3, &idMemoria);
  configurarMemoriaIni(memoriaIni);


  limpiarPantalla();

  while(1)
  {
    accionElegida = mostrarMenu();
    meseroElegido = obtenerNumeroAleatorio(1,3);

    esperarSemaforo(idSemaforo);
    escribirMesero(memoria, 0, meseroElegido);
    escribirPedido(memoria, 0, accionElegida);
    levantarSemaforo(idSemaforo);


    /*break;*/
    usleep(1000*200);
  }

  verificarFinalizarMemoriaIni(memoriaIni, "jugadores");

  liberarMemoria(idMemoriaIni, (char*)memoriaIni);
  eliminarSemaforo(idSemaforo);
  return 0;
}

