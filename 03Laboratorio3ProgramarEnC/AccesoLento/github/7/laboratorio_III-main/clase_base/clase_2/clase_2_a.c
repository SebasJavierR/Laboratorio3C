#include <stdio.h>

struct carta {
	int valor;
};

int main (int argc, char *argv[]) {
	puts("Hola Mundo\n");
	printf("cant argumentos %d \n", argc);
	int i;
	for (i=0; i<argc; i++) {
	printf("argumento %d %s \n", i, argv[i]);
	}
	struct carta miCarta;
	miCarta.valor=8;
	printf("el valor de la carta es %d \n", miCarta.valor);
	return 0;
}
