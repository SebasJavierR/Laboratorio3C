#ifndef _GESTIONAR_ARCHIVOS_H
#define _GESTIONAR_ARCHIVOS_H
int abrirArchivo(char*, char*);
void escribirArchivo(char*);
int leerStringArchivo(char*);
int leerNumeroArchivo(int*);
char* leerLineaArchivo(char*);
void cerrarArchivo();
int abrirLectura(char*);
int abrirEscritura(char*);
int abrirAdicion(char*);
int esFinArchivo();
int limpiarArchivo(char*);
int renombrarArchivo(char*, char*);
int backupArchivo(char*, char*);
#endif
