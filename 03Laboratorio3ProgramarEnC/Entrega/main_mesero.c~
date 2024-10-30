/*Standard Library*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
/*Headers Library*/
#include "framework/semaforos.h"
#include "framework/aleatorio.h"
#include "framework/pantalla.h"
#include "framework/archivos.h"
#include "framework/cadenas.h"
#include "framework/memoria.h"
#include "framework/memoria_ini.h"
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
  int meseroElegido;
  char* rutaArchivo;

  if (argc != 2)
  {
    puts("Uso: ./karging [1-3]");
    return -1;
  }

  idSemaforo = 0;
  memoriaIni = 0; /*NULL*/
  idMemoriaIni = 0;
  meseroElegido = 0;

  srand(time(0));

  limpiarPantalla();

  meseroElegido = atoi(argv[1]);

  if (meseroElegido < 1 || meseroElegido > 3)
  {
    puts("Ingrese 1, 2 o 3");
    return 0;
  }

  rutaArchivo = (char*)malloc(sizeof(char)*LARGO_RUTA);
  memset(rutaArchivo,0x00,sizeof(char)*LARGO_RUTA);
  strcpy(rutaArchivo, obtenerRutaArchivoMesero(meseroElegido));

  idSemaforo = crearSemaforo();
  memoriaIni = crearMemoriaIni(&idMemoriaIni);
  verificarMemoriaIni(memoriaIni, "resto");

  limpiarPantalla();

  while(1)
  {
    esperarSemaforo(idSemaforo);
    if (abrirLectura(rutaArchivo))
    {
      leerOrdenes();
      cerrarArchivo();
      limpiarArchivo(rutaArchivo);
    }
    levantarSemaforo(idSemaforo);
    usleep(INTERVALO_MESERO_MS * 1000);
  }

  free(rutaArchivo);
  return 0;
}

