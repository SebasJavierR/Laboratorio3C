/*Librerias*/
#include "stdio.h"
#include "string.h"
#include "sys/ipc.h"
#include "sys/msg.h"
/*Librerias de Headers*/
#include "claves.h"
/*Header*/
#include "cola.h"

int crearColaMensajesConClave(int clave)
{
  int idColaMensajes = msgget(crearClave(clave), 0600 | IPC_CREAT);
  if (idColaMensajes == -1)
  {
    printf("Error: no se ha podido obtener identificador para cola de mensajes\n");
  }
  return idColaMensajes;
}

int crearColaMensajes()
{
  return crearColaMensajesConClave(CLAVE_BASE);
}

int borrarMensajes(int idColaMensajes)
{
  mensaje msg;
  int res;
  do
  {
     /*(struct msgbuf*)&msg*/
    res = msgrcv(idColaMensajes, &msg, sizeof(msg.intRte)+sizeof(msg.intEvento)+sizeof(msg.charMensaje), 0, IPC_NOWAIT);
  }
  while (res>0); 
  return res;
}

int recibirMensaje(int idColaMensajes, long rLongDest, mensaje* rMsg)
{
  mensaje msg;
  int res;
  /*(struct msgbuf*)&msg*/
  res = msgrcv(idColaMensajes, &msg, sizeof(msg.intRte)+sizeof(msg.intEvento)+sizeof(msg.charMensaje), rLongDest, 0);
  rMsg->longDest = msg.longDest;
  rMsg->intRte = msg.intRte;
  rMsg->intEvento = msg.intEvento;
  strcpy(rMsg->charMensaje, msg.charMensaje);
  return res;
}

int enviarMensaje(int idColaMensajes, long rLongDest, int rIntRte, int rIntEvento, char* rpCharMsg)
{
  mensaje msg;
  msg.longDest = rLongDest;
  msg.intRte = rIntRte;
  msg.intEvento = rIntEvento;
  strcpy(msg.charMensaje, rpCharMsg);
  /*(struct msgbuf*)&msg*/
  return msgsnd(idColaMensajes, &msg, sizeof(msg.intRte)+sizeof(msg.intEvento)+sizeof(msg.charMensaje), IPC_NOWAIT);
}

void liberarColaMensajes(int idColaMensajes)
{
  msgctl(idColaMensajes, IPC_RMID, (struct msqid_ds*) 0);
}
