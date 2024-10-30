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
#include "framework/memoria.h"
#include "framework/memoria_ini.h"
#include "program/defines.h"
#include "program/globals.h"
#include "program/funciones.h"
#include "program/menus.h"
#include "program/productor.h"
#include "program/consumidor.h"

int main(int argc, char *argv[])
{
  /*General*/
  int idSemaforo;
  int idMemoriaIni;
  dato_memoria_ini* memoriaIni;

  /*Custom*/
  comida* comidas;
  char* rutaArchivo;
  int comidaElegida;
  int totalComida;
  int meseroAleatorio;
  int i;

  if (argc != 1)
  {
    puts("Uso: ./resto");
    return -1;
  }

  idSemaforo = 0;
  memoriaIni = 0; /*NULL*/
  idMemoriaIni = 0;
  comidaElegida = 0;
  totalComida = 0;
  meseroAleatorio = 0;
  i = 0;

  srand(time(0));

  idSemaforo = crearSemaforo();
  iniciarSemaforo(idSemaforo, VERDE);
  memoriaIni = crearMemoriaIni(&idMemoriaIni);
  configurarMemoriaIni(memoriaIni);

  comidas = (comida*)malloc(3*sizeof(comida));
  memset(comidas,0x00,3*sizeof(comida));
  rutaArchivo = (char*)malloc(sizeof(char)*LARGO_RUTA);
  memset(rutaArchivo,0x00,sizeof(char)*LARGO_RUTA);

  limpiarPantalla();

  for (i = 0; i < CANT_COMIDAS; i++)
  {
    while(strcmp(comidas[i].descripcion, "") == 0)
    {
      printf("Comida %d\n", i + 1);
      solicitarCadena(comidas[i].descripcion, "Ingrese descripción:");
    }
    puts("");
    while(comidas[i].precio == 0)
    {
      printf("Comida %d\n", i + 1);
      solicitarEntero(&comidas[i].precio, "Ingrese precio:");
    }
    puts("");
    comidas[i].total = 0;
  }

  while(1)
  {
    if (totalComida <= (MAX_PEDIDOS - 1))
    {
      totalComida++;
    }
    else
    {
      puts("Se alcanzó máximo de órdenes");
      puts("Cerrando Resto");
      break;
    }
    comidaElegida = mostrarMenu(comidas);
    meseroAleatorio = obtenerNumeroAleatorio(MESERO_MIN, MESERO_MAX);
    strcpy(rutaArchivo, obtenerRutaArchivoMesero(meseroAleatorio));
    comidas[comidaElegida-1].total++;
    printf("Total Ordenes: %d\n", totalComida);
    printf("Total Ordenes Comida 1 (%s): %d\n", comidas[0].descripcion, comidas[0].total);
    printf("Total Ordenes Comida 2 (%s): %d\n", comidas[1].descripcion, comidas[1].total);
    printf("Total Ordenes Comida 3 (%s): %d\n", comidas[2].descripcion, comidas[2].total);
    printf("Total Obtenido Comida 1 (%s): $%d\n", comidas[0].descripcion, comidas[0].precio * comidas[0].total);
    printf("Total Obtenido Comida 2 (%s): $%d\n", comidas[1].descripcion, comidas[1].precio * comidas[1].total);
    printf("Total Obtenido Comida 3 (%s): $%d\n", comidas[2].descripcion, comidas[2].precio * comidas[2].total);
    printf("Mesero Elegido: %d\n", meseroAleatorio);
    esperarSemaforo(idSemaforo);
    if (abrirAdicion(rutaArchivo))
    {
      escribirOrden(&comidas[comidaElegida-1], comidaElegida);
      cerrarArchivo();
    }
    levantarSemaforo(idSemaforo);

    memset(rutaArchivo,0x00,sizeof(char)*LARGO_RUTA);
    usleep(INTERVALO_RESTO_MS * 1000);
  }

  liberarMemoria(idMemoriaIni, (char*)memoriaIni);
  eliminarSemaforo(idSemaforo);
  free(comidas);
  free(rutaArchivo);
  return 0;
}
