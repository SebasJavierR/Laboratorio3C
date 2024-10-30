#ifndef _MENUS_H
#define _MENUS_H
enum acciones_menu_reina
{
  AC_NINGUNA, /*0*/
  AC_JUNTAR_COMIDA,
  AC_JUNTAR_HOJA,
  AC_JUNTAR_RAMA,
  AC_JUNTAR_AGUA,
  AC_MAX
};
typedef enum acciones_menu_reina AccionesMenuReina;
int mostrarMenuReina(int);
#endif
