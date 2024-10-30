#include "sys/ipc.h"
#include "sys/sem.h"
#include "stdio.h"
#include "defines.h"
#include "claves.h"
#include "semaforos.h"

int creoSemaforo()
{
  key_t clave;
  int idSemaforo;
  clave = creoClave(CLAVE_BASE);
  idSemaforo = semget(clave, 1, 0600|IPC_CREAT);
  /*
   0600: permiso de lectura y escritura para el owner
   El 0 adlente es para que lo tome como octal
   El segundo parámetro es la cantidad de semáforos
  */
  if (idSemaforo == -1)
  {
    printf("Error: no se ha podido crear el semáforo\n");
    return 0;
  }
  return idSemaforo;
}

void iniciaSemaforo(int idSemaforo, int valor)
{
  semctl(idSemaforo, 0, SETVAL, valor);
}

void levantaSemaforo(int idSemaforo)
{
  struct sembuf operacion;
  printf("Levanto Semáforo: %d\n", idSemaforo);
  operacion.sem_num = 0;
  /* Para levantar el semáforo, lo incremento en 1 */
  operacion.sem_op = 1;
  operacion.sem_flg = 0;
  semop(idSemaforo, &operacion, 1);
}

void esperaSemaforo(int idSemaforo)
{
  struct sembuf operacion;
  printf("Espera Semáforo: %d\n", idSemaforo);
  operacion.sem_num = 0;
  /* Para esperar el semáforo, lo decremento en 1 */
  operacion.sem_op = -1;
  operacion.sem_flg = 0;
  semop(idSemaforo, &operacion, 1);
}
