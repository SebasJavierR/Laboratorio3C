#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define CANTIDAD 10
#define DESDE 0
#define HASTA 10

int main(int argc, char *argv[]){
	/*se cargan valores por defecto en caso de no pasar por parametros*/
	int desde = DESDE;
	int hasta = HASTA;
	int n,num;
	/* se valida, si se reciben los 2 argumentos, cargarlos. Tener en cuenta que el primer argumento, el “0”, es el nombre del programa.*/
	if(argc==3){
		/* atoi() transforma un texto al valor numérico*/
		desde = atoi(argv[1]);
		hasta = atoi(argv[2]);
	}
	printf("cantidad = %d desde = %d hasta = %d \n",CANTIDAD, desde, hasta);
	srand(time(0));
	/*En C, para obtener números aleatorios, existe la función rand().*/
	/*Esta función, cada vez que se la llama,*/
	/*devuelve un número entero aleatorio entre 0 y el RAND_MAX (un númeroenorme, como de 2 mil millones).*/
	/*La operación módulo (%) da el resto de dividir rand() entre 11. Esteresto puede ir de 0 a 10.*/
	/*De la misma forma, el módulo de rand(), entre N+1, va de 0 a N.*/
	/*Si se desea un rango que no empiece en 0, por ejemplo, entre 20 y 30*/
	/*(de forma más general, entre M y N con N mayor que M).*/
	/*Para esto se obtiene un número entre 0 y 10 y se le suma 20 (un número entre 0 y N-M, y se le suma M)*/
	/*numero = (rand () % 11) + 20;*/
	/* Éste está entre 20 y 30// (rand () & (30-20+1)) + 20;*/
	/*numero = (rand () % (N-M+1)) + M;*/
	/* Éste está entre M y N*/
	for (n=0; n<CANTIDAD;n++)
	{
		num = (rand()%(hasta-desde+1))+desde;
		printf("el numero es %d \n", num);
	}
	return 0;
}
