#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "unistd.h"
#include "time.h"
#include "funciones.h"

int main(int argc, char *argv[]) {
	int desde;
	int hasta;
	int n;
	desde = DESDE;
	hasta = HASTA;
	n = 0;
	if(argc==3){
		desde = atoi(argv[1]);
		hasta = atoi(argv[2]);
	}
	/*No usamos el srand para que no quede optimizado*/
	printf("Array números aleatorios\n");
	while(n < CANTIDAD) {
		printf("numero aleatorio %d \n", obtenerNumeroAleatorio(desde, hasta));
		n++;
	}
	return 0;
}
