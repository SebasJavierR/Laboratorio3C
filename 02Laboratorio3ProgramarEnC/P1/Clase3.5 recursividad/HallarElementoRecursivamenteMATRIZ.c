//Ingresar los nxn elementos de una matriz y mostrarlos. Hallar el valor máximo de cada fila enforma recursiva

#include <stdio.h>
#include <stdlib.h>
void cargar (int mat[4][4],int dim)
{
int i,j;
for (i=0; i<dim; i++)
   {
   for (j=0;j<dim; j++)
     {
      printf ("\nIngrese un numero[%d][%d]: ",i,j);
      scanf ("%d", &mat[i][j]);
     }
  }
}

void mostrar (int mat[4][4],int dim)
{
    int i,j;
    for (i=0; i<dim; i++)
    {
        for (j=0;j<dim; j++)
        {
            printf (" %d", mat[i][j]);
        }
        printf("\n");
    }
}
 
int  Maximofila(int mat[4][4],int max,int i,int j,int dim)
{
    if (j>dim)
        return max;
    if  (mat[i][j]>max)
          max=mat[i][j];
    return Maximofila(mat,max,i,j+1,dim);
} 


int main()
{
    int mat[4][4],dim,max,m,j,i;
    printf("Ingrese dimension: ");
    scanf("%d",&dim);
    cargar (mat,dim);
 
    printf("Estos son los datos que se cargaron: \n");
    printf("------------------------------------ \n");
    mostrar(mat,dim);
    j=0;
    for (i=0;i<dim; i++)
    {
        j=0;
        max=mat[i][j];
        m=Maximofila(mat,max,i, j,dim-1);
        printf("Maximo fila: %d\n",m);
    }
}