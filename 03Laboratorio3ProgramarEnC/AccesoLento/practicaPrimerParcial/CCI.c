#include <stdio.h>
#include "utilidades.h"
#include "semaforos.h"
#include "gestionArchivos.h"



/*Proceso CCI*/
CCI(int argc, char *argv[]){
//declarar variables
int valorUsuario;
int valorPanel;
int x = 0;
int modificar;



/*pedir input*/
printf("Panel: ");
scanf("%d", &numeroPanel); //crash si no es un numero?
/*si n input mostar mensaje igual*/
semaforoCerrado()
if ( 1 == numeroPanel || 2 == numeroPanel || 3 == numeroPanel ) { //si
	/*Abrir archivo, funcion distinta*/
	abrirArchivo(baseDatos);
	valorPanel = devolverLinea(baseDatos/*definir archivo en utilidades*/,numeroPanel);
	cerrarArchivo(baseDatos);

	/*Pregunta si modificar o no*/
	/*pedir input*/
	x = 1;
	while (x == 1) {
	printf("Modificar si/no: ");
	scanf("%d", &numeroPanel); //crash si no es un numero?
	if ( modificar == "si") {
		/*Comprobar que el numero sea del 1 a 3*/
		/*abrir archivo*/
		abrirArchivo(baseDatos);
		/*remplazar linea n*/
		replazarLineaArchivo(baseDatos, linea, contenidoNuevo);
		/*cerrar archivo*/
		cerrarArchivo(baseDatos);
		/*set semaforo n en 1*/
		semaforoAbierto()
		}
	if (modificar == "no"){
		x = 0
		}
	}
}
else { //no
/*nada?*/
}
/*end?*/
}




















