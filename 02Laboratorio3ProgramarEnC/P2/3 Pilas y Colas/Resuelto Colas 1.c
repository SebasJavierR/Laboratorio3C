/*
Dada una cola de numeros enteros calcular:
    La sumatoria de los números múltiplos de 4.
    El máximo elemento de la cola
    La cantidad de veces que se repite el primer número ingresado a la cola.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CANT 5


typedef struct tiponodo
{
	int dato;

    struct tiponodo *siguiente;
}nodo;

void mostrar (nodo aux, int *c, int *max, int *cant, int primero)

{
    if (aux.dato%4==0)
        *c=*c+aux.dato;
    if (aux.dato >*max)
        *max=aux.dato;
    if (aux.dato==primero)
        *cant=*cant+1;


  	printf("%d \n", aux.dato);
}

nodo* crear_nodo(int dato)
{
   nodo* u;
   u = (nodo *)malloc(sizeof(nodo));

   u->dato = dato;

   u->siguiente = NULL;

   return u;
}

void acolar(nodo** p,nodo** u, nodo *q)
{
   printf("acolar_nodo\n");
	if(*p==NULL)
    *p = *u = q; /*porque hay uno solo*/
   else
   {
    	(*u)->siguiente = q;
    	(*u) = q;
   }
  	printf("%02d p=%X u=%X\n", q->dato, *p, *u);
}

nodo desacolar(nodo** inicio)
{
	nodo* aux;
   nodo datos;

	datos=**inicio;

	aux=*inicio;

	*inicio=(*inicio)->siguiente;
	free(aux);

    return datos;
}

int main()
{

   int i,num,c=0,max, cant=0,primero;
   nodo* p=NULL;
   nodo* u=NULL;

   for(i=0; i<CANT; i++)
   {
       printf("Ingrese un numero");
       scanf("%d",&num);
       if (i==0)
          {
          max=num;
          primero=num;
          }

        acolar(&p, &u, crear_nodo(num));

   }


   printf("\nVamos a desacolar todo\n");
	while(p!=NULL)
   {
    	mostrar(desacolar(&p),&c,&max,&cant,primero);
   }
   printf("\n la sumatoria de los multiplos de 4 es %d",c);
      printf("\n El valor maximo de la cola %d",max);
      printf("\n la cantidad de veces que se repite el primer numero es %d",cant-1);
   return 0;
}
