#ifndef _COLA_H
#define _COLA_H
/*Headers Library*/
#include "libCore/defines.h"
struct tipo_mensaje
{
  long longDest; /*Destinatario*/
  int intRte; /*Remitente*/
  int intEvento; /*NroEvento*/
  char charMensaje[LARGO_MENSAJE]; /*Mensaje*/
};
typedef struct tipo_mensaje mensaje;
int crearColaMensajes(int);
int borrarMensajes(int);
int recibirMensaje(int, long, mensaje*);
int enviarMensaje(int, long, int, int, char*);
void liberarColaMensajes(int);
#endif
