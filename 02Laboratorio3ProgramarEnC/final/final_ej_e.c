#include<stdio.h> 
#include<stdlib.h>
#include<string.h>

#define CANT 6

typedef struct tiponodo{
	int dato;
    struct tiponodo *siguiente;
}nodo;

void mostrar (nodo aux,int ultimo, int primero, int *contador){
  	printf("%d \n", aux.dato);
  	if(aux.dato==ultimo+primero){
  	    printf("El numero coincidio: %d \n", aux.dato);
  	    *contador = *contador + 1;
  	    }
}

nodo* crear_nodo(int dato){
   nodo* u;
   u = (nodo *)malloc(sizeof(nodo));
   u->dato = dato;
   u->siguiente = NULL;
   return u;
}

void acolar(nodo** p,nodo** u, nodo *q){
   printf("Acolar nodo, dato: %d \n", q->dato);
	if(*p==NULL)
    *p = *u = q; /*porque hay uno solo*/
   else{
    	(*u)->siguiente = q;
    	(*u) = q;
   }
  	//printf("%02d p=%p u=%p\n", q->dato, *p, *u);
  	
}

nodo desacolar(nodo** inicio){
	nodo* aux;
	nodo datos;
	datos=**inicio;
	aux=*inicio;
	*inicio=(*inicio)->siguiente;
	free(aux);
    return datos;
}

int main(){
   int i,num,primero,ultimo,contador=0;
   nodo* p=NULL;
   nodo* u=NULL;

   for(i=0; i<CANT; i++)
   {
       printf("Ingrese un numero: ");
       scanf("%d",&num);
       acolar(&p, &u, crear_nodo(num));
       ultimo = num;
       if(i==0)
        primero= num;
   }


   printf("\nVamos a desacolar todo\n");
	while(p!=NULL){
    	mostrar(desacolar(&p),ultimo,primero,&contador);
   }
   printf("Ultimo %d, Primero %d, Contador: %d",ultimo, primero, contador);
   return 0;
}