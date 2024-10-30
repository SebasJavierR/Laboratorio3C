#ifndef _MENU_BASE_H
#define _MENU_BASE_H
int mostrarMenu(void);
enum opcionesMenu
{
  AC_NINGUNA, /*0*/
  OP_A,
  OP_B,
  OP_C,
  AC_MAX
};
typedef enum opcionesMenu OpcionesMenu;
#endif
