#include "stdio.h"
#include "string.h"
#include "unistd.h"
#include "defines.h"
#include "gestionararchivos.h"
#include "semaforos.h"
#include "funciones.h"
#include "consumidor.h"
int main(int argc, char *argv[])
{
  int numLote;
  int idSemaforo;
  if (argc != 1)
  {
    printf("Uso: ./reserva \n");
    return 0;
  }
  
  numLote = 0;
  idSemaforo = creoSemaforo();
  iniciaSemaforo(idSemaforo, VERDE);
  
  while(1)
  {
    printf("Reserva: Esperando Acceso...\n");
    esperaSemaforo(idSemaforo);
    while (!abrirLectura(RUTA_ARCHIVO_LOTE))
    {
      printf("Reserva: Hubo un error al querer abrir el archivo\n");
      levantaSemaforo(idSemaforo);
      usleep(INTERVALO_RESERVA_MS*10000);
      esperaSemaforo(idSemaforo);
    }
    printf("Reserva: Acceso Obtenido...\n");
    if (leerReservas() > 0)
    {
      cerrarArchivo();
      if (numLote <= 999)
      {
        backupLote(numLote);
        numLote++;
      }
    }
    else
    {
      cerrarArchivo();
    }
 
    levantaSemaforo(idSemaforo);
    usleep(INTERVALO_RESERVA_MS*10000);
  }
  return 0;
}
