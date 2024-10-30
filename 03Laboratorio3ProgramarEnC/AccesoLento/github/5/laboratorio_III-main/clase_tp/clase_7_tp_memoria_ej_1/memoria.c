#include "sys/shm.h"
#include "sys/ipc.h"
#include "stdio.h"
#include "defines.h"
#include "claves.h"
#include "memoria.h"

void* creoMemoria(int size, int* extIdMemoria, int claveBase)
{
  void* ptrMemoria;
  int idMemoria;
  
  idMemoria = shmget(creoClave(claveBase), size, 0777 | IPC_CREAT);
  /*0777: permisos de rwx para owner/group/other*/
  /*IPC_CREAT: crea la memoria si no existe*/
  if (idMemoria == -1)
  {
    printf("Error: no se ha podido conseguir id para la memoria compartida\n");
    return 0;
  }
  ptrMemoria = (void *)shmat(idMemoria, (char*)0, 0);

  if (ptrMemoria == 0)
  {
    printf("Error: no se ha podido conseguir memoria compartida\n");
    return 0;
  }
  *extIdMemoria = idMemoria;
  return ptrMemoria;
}

void liberoMemoria(int idMemoria, char* memoria)
{
  shmdt(memoria);
  shmctl(idMemoria, IPC_RMID, (struct shmid_ds*) 0);
}
