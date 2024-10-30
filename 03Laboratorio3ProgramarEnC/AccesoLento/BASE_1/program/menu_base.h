#ifndef _MENUS_H
#define _MENUS_H
enum opcionesMenu
{
  AC_NINGUNA, /*0*/
  AC_PATEAR,
  AC_MAX
};
typedef enum opcionesMenu OpcionesMenu;
int mostrarMenuPartido(char*);
#endif
