/*
Crear una lista con dos números enteros hasta que dichos números sean cero. Mostrarla
    a) Insertar el doble de cada numero si la suma de ambos es mayor a 10.
    b) Eliminar aquellos nodos donde el primer numero es múltiplo del segundo.
    c) Con los nodos eliminados, generar una lista nueva.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int num1;
    int num2;
    struct lista *sig;

} nodo;

void crearlista (nodo*h)
{
    printf ("Ingrese dos numeros enteros:  ");
    scanf ("%d", &h -> num1);
    scanf ("%d", &h -> num2);
    if (h -> num1 == 0 && h -> num2 == 0)
        h -> sig = NULL;
    else
    {
        h -> sig = (nodo*)malloc(sizeof(nodo));
        crearlista (h -> sig);
    }
}

void mostrarlista (nodo*h)
{
    if ( h-> sig != NULL)
    {
        printf ("%d\t", h -> num1);
        printf ("%d", h -> num2);
        printf("\n");
        mostrarlista ( h -> sig);
    }
}

void insertar (nodo*h)
{
    nodo *aux = NULL;
    while (h -> sig != NULL)
    {
        if (h -> num1 + h -> num2 > 10)
        {
           aux = (nodo*)malloc(sizeof(nodo));
           aux -> num1 = h -> num1 * 2;
           aux -> num2 = h -> num2 * 2;
           aux -> sig = h -> sig;
           h -> sig = aux;
           h=h->sig->sig;
        }
        else
    h = h -> sig;
    }
}



nodo* eliminarporcabeza (nodo*h, nodo*n2)
{
    nodo *aux = NULL;
    nodo *a=NULL;
    nodo *aux1=NULL;
    while (h -> num1 % h -> num2 == 0)
    {
          n2->num1=h->num1;
        n2->num2=h->num2;
        n2->sig= (nodo*)malloc(sizeof(nodo));
        n2=n2->sig;
        aux = h->sig;
        free (h);
        h = aux;

    }
    a=h;

    while (a -> sig != NULL && a->sig->sig !=NULL)
    {
        if (a ->sig->num1 % a ->sig-> num2 == 0)
        {

            n2->num1=a->sig->num1;
            n2->num2=a->sig->num2;
            n2->sig= (nodo*)malloc(sizeof(nodo));
            n2=n2->sig;

            aux1 = a-> sig -> sig;
            free (a -> sig);
            a -> sig = aux1;
        }
        else
            a = a-> sig;
    }
    n2->sig=NULL;
    return h;
}



int main()
{
    nodo * p = NULL;
    nodo *n1=(nodo*)malloc(sizeof(nodo));
    p = (nodo*)malloc(sizeof(nodo));

    crearlista(p);
    mostrarlista(p);
    insertar (p);
    printf("La lista nueva es:\n ");
    mostrarlista (p);
    p = eliminarporcabeza (p,n1);
    //eliminar (p,n1);
    printf("La lista eliminada es: \n");
    mostrarlista(p);
     printf("La lista nueva creada es: \n");
    mostrarlista(n1);


}
