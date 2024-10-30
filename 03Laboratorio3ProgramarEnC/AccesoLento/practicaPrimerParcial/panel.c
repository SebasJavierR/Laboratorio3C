#include <stdio.h>
#include "utilidades.h"
#include "semaforos.h"
#include "gestionArchivos.h"




typedef struct paneles{
			
	int nro_panel;
	char mensaje[LARGO_MENSAJE];	

};


/*Proceso PANEL*/ /*MOVER A OTRO ARCHIVO APARTE*/
panel(int argc, char *argv[]){

	/*Comprobar que el numero sea del 1 a 3*/
	//if(argc==1){

		/*Cargar mensaje "default"*/
		esperarSemaforo()
		abrirArchivo(w)
		nro_panel = leerLineaArchivo( 1 )
		replazarLineaArchivo( mensajeDefault, nro_panel+1 )
		cerrarArchvo()
		levantarSemaforo()

		panel.nro_panel = atoi(argv[1]);
		//memset(&panel.mensaje[0],0x00,sizeof(panel.mensaje));
		snprintf(&panel.mensaje[0],sizeof(panel.mensaje),mensajeDefault);

		while(true){
			
			esperarSemaforo()
			abrirArchivo(r)

			for ( leerLineaArchivo(1)+1 ){
				if(strcmp(&panel.mensaje[0],leerLineaArchivo(i) == 1){
					printf( leerLineaArchivo(i))
					memset(&panel.mensaje[0],0x00,sizeof(panel.mensaje));
					snprintf(&panel.mensaje[0],sizeof(panel.mensaje),leerLineaArchivo(i));
				}
				i++
			}
			/*Esperar 100ms*/
			usleep(INTERVALO_CHEQUEO);
		}

}
