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
#include "program/funciones.h"
#include "program/productor.h"
#include "program/consumidor.h"

int main(int argc, char *argv[])
{
  /*General*/
  int idSemaforo;
  int idMemoriaIni;
  dato_memoria_ini* memoriaIni;
  dato_memoria* memoria;
  int asignarMesero;
  int accionElegida;

  if (argc != 1)
  {
    printf("Uso: ./mesero\n");
    return -1;
  }

  memoriaIni = 0; /*NULL*/
  idMemoriaIni = 0;
  idSemaforo = 0;
  memoria = 0;
  idMemoria = 0;

  asignarMesero = 0;
  accionElegida = 0;

  srand(time(0));

  idSemaforo = crearSemaforo();
  memoriaIni = crearMemoriaIni(&idMemoriaIni);
  memoria = (dato_memoria*)crearMemoria(sizeof(dato_memoria)*3, &idMemoria);
  verificarMemoriaIni(memoriaIni, "carrera");

  limpiarPantalla();

  while(1)
  {
    esperarSemaforo(idSemaforo);
    accionElegida = leerMesero(memoria, 0);
    asignarMesero = leerPedido(memoria, 0);
    levantarSemaforo(idSemaforo);

    switch(accionElegida)
    {
      case 1:
        printf("El mesero %d, tiene como pedio OPCION A", asignarMesero);
        printf("El costo de este plato es de X");
        
      case 2:
        printf("El mesero %d, tiene como pedio OPCION B", asignarMesero);
        printf("El costo de este plato es de Y");
      case 3:
        printf("El mesero %d, tiene como pedio OPCION C", asignarMesero);
        printf("El costo de este plato es de Z");
      default:
        usleep(1000*200);
    }
    meseroElegido = 0;
    accionElegida = 0
    esperarSemaforo(idSemaforo);
    escribirMesero(memoria, 0, meseroElegido);
    escribirPedido(memoria, 0, accionElegida);
    levantarSemaforo(idSemaforo);



    /*break;*/
    usleep(1000*200);
  }

  esperarSemaforo(idSemaforo);
  configurarFinalizarMemoriaIni(memoriaIni);
  levantarSemaforo(idSemaforo);
  return 0;
}