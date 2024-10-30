#ifndef _GLOBALS_H
#define _GLOBALS_H
/*Headers Library*/
#include "defines.h"
enum menu
{
  M_NINGUNO, /*0*/
  M_UNO,
  M_DOS,
  M_TRES
};
typedef enum menu Menu;
struct tipo_comida
{
  int precio;
  char descripcion[LARGO_DESCRIPCION];
  int total;
};
typedef struct tipo_comida comida;
/*Shared Global Variables*/
extern int cantidadJugadores;
#endif
