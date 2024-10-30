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

  for (i = 0; i < CANT_COMIDAS; i++)                /*cant_comidas = cant_kartings*/
  {
    while(strcmp(comidas[i].descripcion, "") == 0)   /*Descripcion = nombre*/
    {
      printf("Karting %d\n", i + 1);
      solicitarCadena(comidas[i].descripcion, "Ingrese descripción:");
    }
    puts("");
    comidas[i].precio = 1;          /*precio = irrelebante en este ejercicio la dejo para no arriesgarme a romper nada*/
    puts("");
    comidas[i].total = 0;           /*total = metros*/
  }

  while(1)
  {
    for (i = 0; i < CANT_COMIDAS; i++)                                       /*cant_comidas = cant_kartings*/
    {
      comidaElegida = mostrarMenu(comidas);                                 /*pausa*/
      meseroAleatorio = obtenerNumeroAleatorio(MESERO_MIN, MESERO_MAX);     /*MeseroAleatoria = numero Metros avanzados 5-12*/
      strcpy(rutaArchivo, obtenerRutaArchivoMesero(i));
      comidas[i].total = comidas[i].total + meseroAleatorio;
      /*comidas[comidaElegida-1].total++;*/

      /*printf("Total Ordenes: %d\n", totalComida);*/
      printf("Karting actual (%s), avanza: %d para un total de: %d \n", comidas[0].descripcion, meseroAleatorio , comidas[0].total);

      printf("Nombre del Karting 1 (%s), metros recorridos: %d\n", comidas[0].descripcion, comidas[0].total);
      printf("Nombre del Karting 2 (%s), metros recorridos: %d\n", comidas[1].descripcion, comidas[1].total);
      printf("Nombre del Karting 3 (%s), metros recorridos: %d\n", comidas[2].descripcion, comidas[2].total);
      /*
      printf("Total Obtenido Comida 1 (%s): $%d\n", comidas[0].descripcion, comidas[0].precio * comidas[0].total);
      printf("Total Obtenido Comida 2 (%s): $%d\n", comidas[1].descripcion, comidas[1].precio * comidas[1].total);
      printf("Total Obtenido Comida 3 (%s): $%d\n", comidas[2].descripcion, comidas[2].precio * comidas[2].total);
      */
      /*printf("Mesero Elegido: %d\n", meseroAleatorio);*/

      esperarSemaforo(idSemaforo);
      if (abrirAdicion(rutaArchivo))
      {
        escribirOrden(&comidas[i], i);
        cerrarArchivo();
      }
      levantarSemaforo(idSemaforo);

      memset(rutaArchivo,0x00,sizeof(char)*LARGO_RUTA);
      usleep(INTERVALO_RESTO_MS * 1000);
    }
    if ( (comidas[0].total <= (MAX_PEDIDOS)) || (comidas[1].total <= (MAX_PEDIDOS)) || (comidas[2].total <= (MAX_PEDIDOS)))
    {
      puts("Se alcanzó máximo de metros");
      puts("Terminando Carrera");
      break;
    }
  }

  liberarMemoria(idMemoriaIni, (char*)memoriaIni);
  eliminarSemaforo(idSemaforo);
  free(comidas);
  free(rutaArchivo);
  return 0;
}
