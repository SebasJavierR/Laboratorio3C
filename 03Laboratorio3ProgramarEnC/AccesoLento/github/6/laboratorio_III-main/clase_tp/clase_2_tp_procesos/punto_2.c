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
	int nums[CANTIDAD];
	desde = DESDE;
	hasta = HASTA;
	n = 0;
	if(argc==3){
		desde = atoi(argv[1]);
		hasta = atoi(argv[2]);
	}
	/*Lo ejecutamos una única vez en el main*/
	srand(time(0));
	printf("Array números aleatorios\n");
	obtenerNumerosAleatorios(desde, hasta, CANTIDAD, nums);
	while (n < CANTIDAD) {
		printf("numero aleatorio %d \n", nums[n]);
		n++;
	}
	return 0;
}
