#ifndef _MENUS_H
#define _MENUS_H
#define TECLA_ENTER '\n'
/*File Header*/
#include "globals.h"
enum acciones_menu
{
  AC_NINGUNA, /*0*/
  AC_COMIDA_1,
  AC_COMIDA_2,
  AC_COMIDA_3,
  AC_MAX
};
typedef enum acciones_menu AccionesMenu;
int mostrarMenu(comida*);
#endif
