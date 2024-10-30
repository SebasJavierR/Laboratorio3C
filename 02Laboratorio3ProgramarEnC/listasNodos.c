#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista{
	int Legajo;
	char Nombre[20];
	char Apellido[20];
	int CantidadMateriasAprobadas;
	struct lista *sig;
 }nodo;

void crear (nodo *pt);
void mostrar(nodo *pt);
void MasDeDiez(nodo *pt);
void generar(nodo *pt, nodo *s);

int main()
{
    int i=0;
    nodo *prin=NULL;
    nodo *seg=NULL;
    prin=(nodo*)malloc(sizeof(nodo));
    seg=(nodo*)malloc(sizeof(nodo));
    crear(prin);
    printf("---\n");
    printf("La lista ingresada es: \n");
    mostrar (prin);
    printf("---\n");
    printf("Cantidad alumnos con mas de 10 materias aprobadas: ");
    MasDeDiez(prin);
    generar(prin,seg);
    printf("---\n");
    printf("La lista alumnos con menos de 3 materias aprobadas es: \n");
    mostrar (seg);

    return 0;
}

void crear (nodo *registro)
{
    printf("Ingrese legajo: ");
    scanf("%d",&registro->Legajo);

    if (registro->Legajo==0)
        registro->sig=NULL;
    else
	{
        printf("Ingrese nombre: ");
        scanf("%s",registro->Nombre);
        printf("Ingrese apellido: ");
        scanf("%s",registro->Apellido);
        printf("Ingrese cantidad materias aprobadas: ");
        scanf("%d",&registro->CantidadMateriasAprobadas);

        registro->sig=(nodo*)malloc(sizeof(nodo));
        crear (registro->sig);

	}
	return;
}

void mostrar (nodo *registro)
{
    if (registro->sig !=NULL)
	{
        printf ("Legajo: %d\n",registro->Legajo);
        printf ("Nombre: %s\n",registro->Nombre);
        printf ("Apellido: %s\n",registro->Apellido);
        printf ("Materias Aprobadas: %d\n",registro->CantidadMateriasAprobadas);

        mostrar (registro->sig);
	}
	return;
}
void generar(nodo *r, nodo *n)
{
    while(r->sig!=NULL)
    {
        if (r->CantidadMateriasAprobadas<3)
        {
            n->Legajo = r->Legajo;
            strcpy(n->Nombre,r->Nombre);
            strcpy(n->Apellido,r->Apellido);
            n->CantidadMateriasAprobadas=r->CantidadMateriasAprobadas;
            n->sig=(nodo*)malloc(sizeof(nodo));
            n=n->sig;
        }
        r=r->sig;
    }
    n->sig=NULL;
}

void MasDeDiez(nodo *r)
{
    int cont = 0;
    while(r->sig!=NULL)
	{
        if (r->CantidadMateriasAprobadas>10)
            cont++;
            
        r=r->sig;
	}   
    printf (" %d \n", cont);
	return ;
}