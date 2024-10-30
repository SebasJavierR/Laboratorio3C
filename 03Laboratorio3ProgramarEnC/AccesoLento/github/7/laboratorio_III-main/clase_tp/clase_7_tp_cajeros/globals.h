#ifndef _GLOBALS_H
#define _GLOBALS_H
struct tipo_dato
{
  int cajero;
  int importe;
  int cheque; /*0: efectivo; 1: cheque*/
  int listo; /*0: libre; 1: a procesar*/
  int inicializado;
};
typedef struct tipo_dato dato;
#endif
