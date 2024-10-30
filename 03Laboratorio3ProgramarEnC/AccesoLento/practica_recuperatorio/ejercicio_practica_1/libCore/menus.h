#ifndef _MENUS_H
#define _MENUS_H
enum acciones_menu_postre
{
  AC_NINGUNA, /*0*/
  AC_SI,
  AC_NO,
  AC_MAX
};
typedef enum acciones_menu_postre AccionesMenuPostre;
int mostrarMenuPostre(char*);
#endif
