// a) la cantidad de nodos que poseen hijo izquierdo unicamente, y que a su vez son multiplos de la raiz de un arbol binario de busqueda
//Variables Raiz y Cont, Condiciones: Solo nodo izq y multiplo raiz

#include <stdio.h> 
#include <stdlib.h>

typedef struct arbol
{
    int dato;
    struct arbol *izq;
    struct arbol *der;
}treenode;

void crear (treenode **hoja, int *);
void insertar(treenode **hoja, int elem);
void mostrarOrden (treenode *hoja, int *, int);



int main (){

    int cont=0,raiz;
    printf ("arboles\n");
    treenode* arbol=NULL;

    crear (&arbol, &raiz);
    printf ("**************\n");
    printf ("mostrar arbol\n");
    printf ("***************\n");

    printf ("\nMostrar en Orden:\n");
    mostrarOrden (arbol, &cont, raiz);
    printf("Cantidad nodos en %d", cont);

    return 0;
}
void crear (treenode **hoja, int *raiz)
{
    int numero;

    printf ("ingrese numero\n");
    scanf ("%d",&numero);
    *raiz=numero;
    while (numero!=-1){
        insertar(&(*hoja),numero);
        printf ("ingrese numero\n");
        scanf ("%d",&numero);
    }
}

void insertar (treenode **hoja,int elem)
{
    int numero=elem;
    if (elem==-1)
        return;
    if (*hoja==NULL){
        //creo la hoja vacia
        (*hoja)=(treenode*)malloc(sizeof(treenode));
        (*hoja)->dato=elem;
        (*hoja)->der=NULL;
        (*hoja)->izq=NULL;
    }
    else{

        if (numero>(*hoja)->dato){
            insertar (&(*hoja)->der,elem);
        }
        else{
        insertar (&(*hoja)->izq,elem);
        }
    }
return;
}



void mostrarOrden (treenode *hoja, int *cont, int raiz)
{
    if (hoja!=NULL){
        mostrarOrden(hoja->izq,cont,raiz);
        printf("%d ",hoja->dato);
        mostrarOrden(hoja->der,cont,raiz);

        //if(hoja->dato == 10){ //DEBUG
        //    printf("Der %d \n", hoja->der);
        //    printf("IZQ %d \n", hoja->izq);
        //    printf("dato: %d \n", hoja->dato);
        //    printf("raiz: %d \n", raiz);
        //    if(hoja->dato % raiz==0)
        //        printf("true \n");
        //    if(hoja->dato % raiz!=0)
        //        printf("false \n");
        //    }
        
        if(hoja->dato % raiz==0 && hoja->der==NULL && hoja->izq!=NULL )
                *cont=*cont+1;

    }
    return;
}
