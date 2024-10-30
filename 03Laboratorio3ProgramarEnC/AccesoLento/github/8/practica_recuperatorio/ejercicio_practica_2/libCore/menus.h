#ifndef _MENUS_H
#define _MENUS_H
enum acciones_menu_accion
{
  M_AC_NINGUNA, /*0*/
  M_AC_LEER,
  M_AC_ESCRIBIR,
  M_AC_MAX
};
enum acciones_menu_panel
{
  M_PANEL_NINGUNA, /*0*/
  M_PANEL_1,
  M_PANEL_2,
  M_PANEL_3,
  M_PANEL_MAX
};
typedef enum acciones_menu_accion AccionesMenuAccion;
typedef enum acciones_menu_panel AccionesMenuPanel;
int mostrarMenuAccion();
int mostrarMenuPanel();
#endif
