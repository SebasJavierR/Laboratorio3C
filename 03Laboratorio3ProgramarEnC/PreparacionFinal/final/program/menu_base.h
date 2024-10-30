#ifndef _MENU_BASE_H
#define _MENU_BASE_H
enum opciones_menu
{
  OP_NINGUNA, /*0*/

  OP_COMIDA,
  OP_AGUA,
  OP_PALO,
  OP_HOJA,
  
  OP_MAX
};
typedef enum opciones_menu OpcionesMenu;
int menuBase(int);
#endif
