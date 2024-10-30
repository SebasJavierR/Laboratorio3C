#ifndef _GESTIONAR_ARCHIVOS_H
#define _GESTIONAR_ARCHIVOS_H
#include "stdio.h"
int abrirArchivo(char*, char*, FILE**);
void cerrarArchivo(FILE*);
int esFinArchivo(FILE* fp);
#endif
