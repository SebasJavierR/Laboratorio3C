#ifndef _GLOBALS_H
#define _GLOBALS_H
/*Headers Library*/
#include "libCommon/archivos.h"
#include "defines.h"
enum postre
{
  P_NINGUNO, /*0*/
  P_SI,
  P_NO
};
enum menu
{
  M_NINGUNO, /*0*/
  M_A,
  M_B,
  M_C
};
typedef enum postre Postre;
typedef enum menu Menu;
struct tipo_orden
{
  int tipoMenu;
  int precio;
  int conPostre;
  char descripcion[LARGO_LINEA];
};
typedef struct tipo_orden orden;
/*Shared Global Variables*/
extern int cantidadJugadores;
#endif
