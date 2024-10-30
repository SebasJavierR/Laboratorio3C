/*Standard Library*/
#include "stdio.h"
#include "sys/ipc.h"
/*Headers Library*/
#include "libCore/defines.h"
/*File Header*/
#include "claves.h"

key_t crearClave(int idClave)
{
  /* Igual que en cualquier recurso compartido (memoria compartida,
   semáforos o colas) se obtiene una clave a partir de un fichero
   existente cualquiera y de un entero cualquiera.
   Todos los procesos que quieran compartir este recurso,
   deben usar el mismo fichero y el mismo entero.
  */
  key_t clave;
  clave = ftok(RUTA_ARCHIVO_FTOK, idClave);
  if (clave == (key_t)-1)
  {
    printf("No se pudo conseguir clave\n");
    return 0;
  }
  return clave;
}
