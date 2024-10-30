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
 
int  Diagonal(int mat[4][4],int i,int j,int dim)
{
    if (dim == j && dim == i){
        if(mat[i][j] == 1){
            printf("ultimo == 1\n"); //Debug
            return 1;
        }
        if(mat[i][j] != 1){
            printf("ultimo != 1\n"); //Debug
            return 0;
        }
    }
    if (dim == i){
        printf("Fin de Fila\n"); //Debug
        return Diagonal( mat, i-dim, j+1, dim) + 0;
        }
        
    if(j == i && mat[i][j] == 1){
        printf("Se cumple contador +1\n"); //Debug
        return Diagonal( mat, i+1, j, dim) + 1;
    }
    printf("No se cumple, paso columna\n"); //Debug
    return Diagonal( mat, i+1, j, dim) + 0;
    
} 


int main()
{
    int mat[4][4],dim,contador,j,i;
    printf("Ingrese dimension: ");
    scanf("%d",&dim);
    cargar (mat,dim);
 
    printf("Estos son los datos que se cargaron: \n");
    printf("------------------------------------ \n");
    mostrar(mat,dim);
    j=0;
    i=0;
    contador = Diagonal(mat,i, j,dim-1);
    printf("Contador: %d, Dim: %d\n", contador,dim);
    if(contador==dim)
        printf("La diagonal esta compuesta por 1\n");
    else
        printf("La diagonal NO esta compuesta por 1\n");
}