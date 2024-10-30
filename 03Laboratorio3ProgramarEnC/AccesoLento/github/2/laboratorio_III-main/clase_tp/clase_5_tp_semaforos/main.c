#include "stdio.h"
#include "string.h"
#include "unistd.h"
#include "defines.h"
#include "gestionararchivos.h"
#include "semaforos.h"
int main(int argc, char *argv[])
{
  int idSemaforo;
  if (argc != 1)
  {
    printf("Uso: ./semaforos \n");
    return 0;
  }
  
  idSemaforo = creoSemaforo();
  
  iniciaSemaforo(idSemaforo, VERDE);
  
  while(1)
  {
    esperaSemaforo(idSemaforo);
    printf("Seccion critica\n");
    sleep(1);
    levantaSemaforo(idSemaforo);
    sleep(10);
  }
  return 0;
}
