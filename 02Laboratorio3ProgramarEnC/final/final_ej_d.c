//FUNCIONA ALREVEZ
// Dada una lista con numeros enteros, solicitar al usuario 2 numeros y luego eliminar aquillos nodos que se encutran entre las posiciones que corresponden a dichos numeros (hay pos 0)

#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
int num;
struct lista *sig;
}nodo;

void crear (nodo *pt,int);
void mostrar(nodo *pt);
void eliminar2(nodo* , int *,int *,int *); 

int main(){
    
    int i;
    int A = 2; 
    int B = 4;
    int cont = 1;
    nodo *prin=NULL;
    prin=(nodo*)malloc(sizeof(nodo));
    crear(prin,i);
    printf("Lista\n");
    mostrar (prin);
    printf("Borrando del %d al %d\n", A, B);
    eliminar2(prin,&A,&B,&cont); 
    printf("Lista\n");
    mostrar (prin);
    
    return 0;
}

void crear (nodo *registro,int cont){
    scanf("%d",&registro->num);
    if (registro->num==0)
    registro->sig=NULL;
    else{
        registro->sig=(nodo*)malloc(sizeof(nodo));
        crear (registro->sig,cont);
    }
    return;
}


void mostrar (nodo *registro){
    if (registro->sig !=NULL){
        printf ("%d\n",registro->num);
        mostrar (registro->sig);
    }
    return;
}


void eliminar2(nodo* p,int *A, int *B, int *cont){ 
    nodo *aux;
    while(p->sig!=NULL&& p->sig->sig!=NULL)
    {
        printf("********************\n"); //DEBUG
        printf("A, B y cont: %d, %d y %d \n",*A , *B, *cont); //DEBUG
        if(*B >= *A && *cont >= *A ) //condicion de eliminacion
        {
            printf("Borrando Dato\n"); //DEBUG
            aux=p->sig->sig;
            free(p->sig);
            *A = *A+1;
            *cont = *cont +1;
            p->sig=aux;
        }
        else{
            *cont = *cont +1;
            printf("salto y contador +1 = %d \n", *cont); //DEBUG
            p=p->sig;
        }
    }
}
