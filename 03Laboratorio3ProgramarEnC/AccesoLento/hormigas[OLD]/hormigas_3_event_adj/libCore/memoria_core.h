#ifndef _MEMORIA_CORE_H
#define _MEMORIA_CORE_H
/*Headers Library*/
#include "libCore/defines.h"
struct tipo_dato_memoria
{
  int recursoComida;
  int recursoHoja;
  int recursoRama;
  int recursoAgua;
};
typedef struct tipo_dato_memoria dato_memoria;
void configurarMemoria(dato_memoria*);
int leerRecursoComida(dato_memoria*, int);
void escribirRecursoComida(dato_memoria*, int, int);
int leerRecursoHoja(dato_memoria*, int);
void escribirRecursoHoja(dato_memoria*, int, int);
int leerRecursoRama(dato_memoria*, int);
void escribirRecursoRama(dato_memoria*, int, int);
int leerRecursoAgua(dato_memoria*, int);
void escribirRecursoAgua(dato_memoria*, int, int);
#endif
