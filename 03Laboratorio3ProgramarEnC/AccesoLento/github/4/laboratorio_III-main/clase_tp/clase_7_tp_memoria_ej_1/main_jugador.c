#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "time.h"
#include "defines.h"
#include "globals.h"
#include "semaforos.h"
#include "memoria.h"
#include "funciones.h"
#include "productor.h"
#include "consumidor.h"

int main(int argc, char *argv[])
{
  int idMemoria;
  int idMemoriaInicial;
  int idSemaforo;
  int numeroAleatorio;
  int intentos;
  char* nombreJugador;
  dato* memoria;
  inicial* memoriaInicial;

  if (argc != 1)
  {
    printf("Uso: ./jugador \n");
    return 0;
  }

  memoria = 0; /*NULL*/
  memoriaInicial = 0; /*NULL*/
  idMemoria = 0;
  idMemoriaInicial = 0;
  idSemaforo = 0;
  numeroAleatorio = 0;
  intentos = 0;

  nombreJugador = (char*)malloc((LARGO_NOMBRE)*sizeof(char));
  memset(nombreJugador,0x00,sizeof(nombreJugador));

  srand(time(0));

  idSemaforo = creoSemaforo();
  
  memoriaInicial = (inicial*)creoMemoria(sizeof(inicial)*CANTIDAD, &idMemoriaInicial, CLAVE_BASE_INI);
  verificarMemoriaInicial(memoriaInicial);
  memoria = (dato*)creoMemoria(sizeof(dato)*CANTIDAD, &idMemoria, CLAVE_BASE);

  do
  {
    printf("Ingrese nombre jugador:\n");
    scanf("%s", nombreJugador);
  } while(strlen(nombreJugador) < 1);
  limpiarPantalla();

  printf("Hola %s\n", nombreJugador);

  escribirNombreJugador(memoria, nombreJugador);

  while(1)
  {
    esperaSemaforo(idSemaforo);
    if (leerNumeroPensado(memoria) == 0 && leerEstadoAcierto(memoria) == 0)
    {
      printf("Pensando numero...\n");
      numeroAleatorio = obtenerNumeroAleatorio(NUM_MIN, NUM_MAX);
      printf("Numero pensado %d\n", numeroAleatorio);
      escribirNumeroPensado(memoria, numeroAleatorio);
      intentos++;
    }
    else if (leerNumeroPensado(memoria) > 0 && leerEstadoAcierto(memoria) == 1)
    {
      limpiarPantalla();
      printf("Jugador:\t%s\tHas ganado el juego\n", nombreJugador);
      printf("El número pensado era el %d\n", numeroAleatorio);
      printf("Cantidad de intentos:\t%d\n", intentos);
      levantaSemaforo(idSemaforo);
      break;
    }
    levantaSemaforo(idSemaforo);
    usleep(INTERVALO_JUGADOR_MS * 1000);
  }
  liberoMemoria(idMemoriaInicial, (char*)memoriaInicial);
  liberoMemoria(idMemoria, (char*)memoria);
  free(nombreJugador);
  return 0;
}
