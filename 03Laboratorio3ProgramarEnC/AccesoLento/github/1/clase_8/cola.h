#ifndef _MEMORIA_H
#define _MEMORIA_H
#include "defines.h"
struct tipo_mensaje
{
  long longDest; /*Destinatario*/
  int intRte; /*Remitente*/
  int intEvento; /*NroEvento*/
  char charMensaje[LARGO_MENSAJE]; /*Mensaje*/
};
typedef struct tipo_mensaje mensaje;
int creoIdColaMensajes(int);
int borrarMensajes(int);
int recibirMensaje(int, long, mensaje*);
int enviarMensaje(int, long, int, int, char*);
void liberarColaMensajes(int);
#endif
