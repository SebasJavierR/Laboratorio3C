/*Standard Library*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
/*Headers Library*/
#include "libCommon/semaforos.h"
#include "libCommon/aleatorio.h"
#include "libCommon/pantalla.h"
#include "libCommon/archivos.h"
#include "libCommon/cadenas.h"
#include "libCommon/memoria.h"
#include "libCommon/memoria_ini.h"
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
  int meseroElegido;
  char* rutaArchivo;

  if (argc != 2)
  {
    puts("Uso: ./mesero [1-3]");
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

