#include<stdio.h>

#include<stdlib.h>

typedef struct tiponodo

{ int dato;

struct tiponodo *siguiente;

}nodo;



void mostrar (nodo aux)



{

printf("%d \n", aux.dato);

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

void sumImp(nodo*p, int *cont,int *cont2, int *acum,int *prom)
{
    nodo *temp = p;
    while(temp!=NULL){
        *cont = *cont + 1;
        if(*cont%2!=2 && temp->dato%5==0){
            *acum = *acum + temp->dato;
            printf("%d", *acum);
        }
        else if(*cont%2==0 && (*acum)<=0){
                *cont2 = *cont2 + 1;
                *acum = *acum + temp->dato;
            }
        }
        temp = temp->siguiente;
    }
    prom = (*acum) / (*cont2);
    if(cont2>0){
        printf("%d",prom);
    }
    else{
        printf("%d", acum);
    }

}



int main()

{

int num;

nodo* p=NULL;

int contador2 = 0;
int contador =0;
int promedio=0;
int acumulador=0;

printf("Ingrese un numero \n");

scanf("%d",&num);

while(num != -1){
    apilar(&p, crear_nodo(num));
    printf("Ingrese un numero \n");
    scanf("%d",&num);
    }

sumImp(p, &contador,&contador2 ,&acumulador, &promedio);



printf("\nVamos a desapilar todo\n");

while(p!=NULL)

{

mostrar(desapilar(&p));

}

return 0;

}


    *prom = *acum/(*cont2);

}



int main()

{

int num;

nodo* p=NULL;

int contador2 = 0;
int contador =0;
int promedio=0;
int acumulador=0;

printf("Ingrese un numero \n");

scanf("%d",&num);

while(num != -1){
    apilar(&p, crear_nodo(num));
    printf("Ingrese un numero \n");
    scanf("%d",&num);
    }

sumImp(p, &contador,&contador2 ,&acumulador, &promedio);
printf("%d",acumulador);


printf("\nVamos a desapilar todo\n");

while(p!=NULL)

{

mostrar(desapilar(&p));

}

return 0;

}

