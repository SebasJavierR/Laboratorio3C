#ifndef _MENUS_H
#define _MENUS_H
enum acciones_menu_partido
{
  AC_NINGUNA, /*0*/
  AC_PATEAR,
  AC_MAX
};
typedef enum acciones_menu_partido AccionesMenuPartido;
int mostrarMenuPartido(char*);
#endif
