#ifndef _GESTIONAR_ARCHIVOS_H
#define _GESTIONAR_ARCHIVOS_H
int abrirArchivo(char*, char*);
void escribirArchivo(char*);
int leerArchivo(char*);
void cerrarArchivo();
int abrirLectura(char* ruta);
int abrirEscritura(char* ruta);
int abrirAdicion(char* ruta);
void limpiarArchivo(char*);
int esFinArchivo();
int renombrarArchivo(char*, char*);
#endif
