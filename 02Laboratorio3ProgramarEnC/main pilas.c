#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define CANT 4



typedef struct tiponodo
{
	int dato;

    struct tiponodo *siguiente;
}nodo;

void mostrar (nodo aux,int *cont,int *acum,int *cont1,int *cont2,int ultimo)

{
     	printf("%d \n", aux.dato);
     	if(aux.dato %2 !=0)
            *cont=*cont+1;
        if(aux.dato %4==0)
        {
            *acum=*acum+aux.dato;
            *cont1=*cont1+1;
        }
        if(aux.dato > ultimo && aux.dato!=ultimo)
            *cont2=*cont2+1;

}

nodo* crear_nodo(int dato )
{
   nodo* u;
   u = (nodo *)malloc(sizeof(nodo));
   u->dato = dato;

   u->siguiente = NULL;

   return u;
}

void apilar(nodo** p, nodo* u)
{
    printf("apilar_nodo\n");


  	u->siguiente = *p;
  	printf("%02d p=%p u=%p\n", u->dato, *p, u);
	*p = u;
}

nodo desapilar(nodo** p)
{
	nodo* aux;
    nodo datos;

	datos=**p;

	aux=*p;

	*p=(*p)->siguiente;
	free(aux);

    return datos;
}

int main()
{


   int i,num, cont=0,acum=0,cont1=0,cont2=0,ultimo;
   nodo* p=NULL;


   for(i=0; i<CANT; i++)
   {
   	printf("Ingrese un numero \n");
   	scanf("%d",&num);
   	ultimo=num;
   	apilar(&p, crear_nodo(num));
   }


   printf("\nVamos a desapilar todo\n");
	while(p!=NULL)
   {
    	mostrar(desapilar(&p),&cont,&acum,&cont1,&cont2,ultimo);
   }

   printf("la cantidad de numeros impares %d\n",cont);
   if (cont1!=0)
       printf("El promedio de los numeros multiplos de 4 es %d\n",acum/cont1);

   printf("la cantidad de numeros mayores al ultimo elemento de la pila es %d\n",cont2);
   return 0;
}
