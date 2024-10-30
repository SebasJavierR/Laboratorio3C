#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "time.h"
#include "defines.h"
#include "gestionararchivos.h"
#include "semaforos.h"
#include "funciones.h"
#include "productor.h"
int main(int argc, char *argv[])
{
  int idSemaforo;
  int espera;

  if (argc != 1)
  {
    printf("Uso: ./carga \n");
    return 0;
  }
  
  srand(time(0));
  
  idSemaforo = creoSemaforo();
  
  iniciaSemaforo(idSemaforo, VERDE);
  
  while(1)
  {
    printf("Carga: Esperando Acceso...\n");
    esperaSemaforo(idSemaforo);
    while (!abrirAdicion(RUTA_ARCHIVO_LOTE))
    {
      printf("Carga: Hubo un error al querer abrir el archivo\n");
      levantaSemaforo(idSemaforo);
      usleep(INTERVALO_RESERVA_MS*10000);
      esperaSemaforo(idSemaforo);
    }
    printf("Carga: Acceso Obtenido...\n");
    escribirReservas();
    cerrarArchivo();
    levantaSemaforo(idSemaforo);
    espera = obtenerNumeroAleatorio(DESDE, HASTA);
    sleep(espera);
  }
  return 0;
}
