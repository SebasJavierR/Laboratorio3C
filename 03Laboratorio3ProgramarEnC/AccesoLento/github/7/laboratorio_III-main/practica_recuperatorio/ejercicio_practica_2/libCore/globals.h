#ifndef _GLOBALS_H
#define _GLOBALS_H
/*Headers Library*/
#include "libCommon/archivos.h"
#include "defines.h"
enum panel
{
  M_NINGUNO, /*0*/
  PANEL_1,
  PANEL_2,
  PANEL_3
};
typedef enum panel panel;
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
