#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "time.h"
#include "defines.h"
#include "globals.h"
#include "semaforos.h"
#include "memoria.h"
#include "cola.h"
#include "funciones.h"
#include "productor.h"
#include "consumidor.h"

int procesarEvento(int idColaMensajes, mensaje msg)
{
  switch(msg.intEvento)
  {
    case EVT_NINGUNO:
      return 0;
    case EVT_MENSAJE:
      printf(msg.charMensaje);
      printf("\n");
      enviarMensaje(idColaMensajes,MSG_UNO,MSG_DOS,EVT_FIN, "Chau Uno");
      return 0;
    case EVT_FIN:
      printf(msg.charMensaje);
      printf("\n");
      return -1;
    default:
      return 0;
  }
}

int main(int argc, char *argv[])
{
  int idMemoriaInicial;
  int idSemaforo;
  int idColaMensajes;
  inicial* memoriaInicial;
  mensaje msg;

  msg.longDest = MSG_NADIE;
  msg.intRte = MSG_NADIE;
  msg.intEvento = EVT_NINGUNO;
  memset(msg.charMensaje,0x00,LARGO_MENSAJE);

  if (argc != 1)
  {
    printf("Uso: ./dos \n");
    return 0;
  }

  memoriaInicial = 0; /*NULL*/
  idMemoriaInicial = 0;
  idSemaforo = 0;

  srand(time(0));
  idSemaforo = creoSemaforo();
  iniciaSemaforo(idSemaforo, VERDE);
  idColaMensajes = creoIdColaMensajes(CLAVE_BASE);
  memoriaInicial = (inicial*)creoMemoria(sizeof(inicial)*CANTIDAD, &idMemoriaInicial, CLAVE_BASE_INI);
  verificarMemoriaInicial(memoriaInicial);

  limpiarPantalla();

  esperaSemaforo(idSemaforo);
  enviarMensaje(idColaMensajes,MSG_UNO,MSG_DOS,EVT_MENSAJE, "Hola Uno");
  levantaSemaforo(idSemaforo);

  while(1)
  {
    esperaSemaforo(idSemaforo);
    recibirMensaje(idColaMensajes, MSG_DOS, &msg);
    if (procesarEvento(idColaMensajes, msg) == -1)
    {
      levantaSemaforo(idSemaforo);
      break;
    }
    levantaSemaforo(idSemaforo);
    usleep(INTERVALO_UNO_MS * 1000);
  }
  liberoMemoria(idMemoriaInicial, (char*)memoriaInicial);
  liberarColaMensajes(idColaMensajes);
  return 0;
}
