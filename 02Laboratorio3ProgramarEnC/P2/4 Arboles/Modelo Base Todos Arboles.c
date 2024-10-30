#include <stdio.h>
#include <stdlib.h>

typedef struct arbol
{
    int dato;
    struct arbol *izq;
    struct arbol *der;
}treenode;

void crear (treenode **hoja);
void insertar(treenode **hoja, int elem);
void mostrarOrden (treenode *hoja);
void mostrarPreOrden (treenode *hoja);
void mostrarPosOrden (treenode *hoja);

int main (){
    printf ("arboles\n");
    treenode* arbol=NULL;

    crear (&arbol);
    printf ("**************\n");
    printf ("mostrar arbol\n");
    printf ("***************\n");

    printf ("\nMostrar en PreOrden:\n");
    mostrarPreOrden (arbol);
    printf ("\nMostrar en Orden:\n");
    mostrarOrden (arbol);
    printf ("\nMostrar en PosOrden:\n");
    mostrarPosOrden (arbol);

    return 0;
}
void crear (treenode **hoja)
{
    int numero;

    printf ("ingrese numero\n");
    scanf ("%d",&numero);
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



void mostrarOrden (treenode *hoja)
{
    if (hoja!=NULL){
        mostrarOrden(hoja->izq);
        printf("%d ",hoja->dato);
        mostrarOrden(hoja->der);
    }
    return;
}

void mostrarPreOrden (treenode *hoja)
{
    if (hoja!=NULL){
        printf("%d ",hoja->dato);
        mostrarPreOrden(hoja->izq);
        mostrarPreOrden(hoja->der);
    }
    return;
}

void mostrarPosOrden (treenode *hoja)
{
    if (hoja!=NULL){
        mostrarPosOrden(hoja->izq);
        mostrarPosOrden(hoja->der);
        printf("%d ",hoja->dato);
    }
    return;
}