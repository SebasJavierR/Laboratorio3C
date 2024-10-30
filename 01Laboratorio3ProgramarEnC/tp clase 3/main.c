#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

/*
Producir
    “producto.txt”   
        “PRODUCTO-%02d\n”  -%02d es 1,2,3,4,5,6,7,8,9,10


*un puntero FILE para la produccion
*utilizar "w" en fopen
*/
int producir(int argc, char *argv[])
{
    FILE *producto;
    producto = fopen( “producto.txt”, "w" )
	if (fp==NULL) {fputs ("File error",stderr); exit (1);}

    while 1 al 10
    {
        /*
        escribir producto
        “PRODUCTO-%02d\n”  -%02d es 1,2,3,4,5,6,7,8,9,10
        */

    }

	fclose ( fp );

	return 0;
}


/*
Consumir
    Leer el archivo
    mostrar cada linea leida por pantalla
    "consumir el producto" de esa linea

*un puntero FILE para el consumo
*utilizar "r" en fopen
*/

int consumir(int argc, char *argv[])
{
    FILE *producto;
    producto = fopen( “producto.txt”, "r" )
	if (fp==NULL) {fputs ("File error",stderr); exit (1);}

    char *file_contents = malloc(sb.st_size);
    while (fscanf(producto,"%[^\n]", file_contents) != EOF )) /*EOF significa fin del archivo*/
    {
        /*
        printf(LINEA)
        Borrar linea
        */
        // Aquí, justo ahora, tenemos ya la línea. Le vamos a remover el salto
        strtok(bufer, "\n");
        // La imprimimos, pero realmente podríamos hacer cualquier otra cosa
        printf("La línea es: '%s'\n", bufer);
    }


	fclose ( fp );

	return 0;
}

int main(int incant, char *szarg[])
{

}