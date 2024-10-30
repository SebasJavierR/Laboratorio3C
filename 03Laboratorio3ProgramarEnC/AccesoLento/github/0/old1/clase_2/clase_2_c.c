#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "unistd.h"
#include "time.h"
#include "funciones.h"

int main(int argc, char *argv[]) {
	int desde = DESDE;
	int hasta = HASTA;
	int n = 0;
	if(argc==3){
		desde = atoi(argv[1]);
		hasta = atoi(argv[2]);
	}
	/*Lo ejecutamos una única vez en el main*/
	srand(time(0));
	while(n < CANTIDAD) {
		printf("numero aleatorio %d \n", obtenerNumeroAleatorio(desde, hasta));
		n++;
	}
	return 0;
}
