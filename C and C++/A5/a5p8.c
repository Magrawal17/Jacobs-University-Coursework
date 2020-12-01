/*
 CH-230-A
 a5_p8.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <stdio.h>
#include <stdlib.h>
int  **inputmatrix(int x,int y)
{
    int **matrix=NULL;
    matrix = (int **)malloc(x * sizeof(int *)); 
    if (matrix== NULL)
    {
        exit(1);
    }
    for (int i=0; i<x; i++) 
    {
        matrix[i] = (int *)malloc(y * sizeof(int));
        if (matrix[i] == NULL)
        {
        exit(1);
        } 
    }

    for (int i = 0; i <  x; i++) 
    {
      for (int j = 0; j < y; j++) 
      {
         scanf("%d",&(matrix[i][j]));  // OR *(*(arr+i)+j)  
      }
    }   
    return matrix;
    for ( int i = 0; i < x ; i ++)
    {
        free (matrix [i]) ;
    }
    free (matrix);
}

void printmatrix(int** matrix1,int x,int y)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("%d ",matrix1[i][j]);
        }
        printf("\n");
    }
}
int **matrixmulti(int **matrix1,int **matrix2,int n,int m,int p)
{
    int **matrix=NULL;
    matrix = (int **)malloc(n * sizeof(int *)); 
    if (matrix== NULL)
    {
        exit(1);
    }
    for (int i=0; i<n; i++) 
    {
        matrix[i] = (int *)malloc(p * sizeof(int));
        if (matrix[i] == NULL)
        {
        exit(1);
        } 
    }

    for (int j = 0; j < m; j++)
    {
        for ( int i = 0; i < n; i++)
        {
            for (int k = 0; k < p; k++)
            {
                matrix[i][k]=matrix[i][k]+(matrix1[i][j]*matrix2[j][k]);
            }
        }
    }
    return matrix;
    for ( int i = 0; i < n ; i ++)
    {
        free (matrix [i]) ;
    }
    free (matrix);
}


int main()
{
    int n,m,p;
    int **matrix1;
    int **matrix2;
    int **multi;
    scanf("%d",&n);
    scanf("%d",&m);
    scanf("%d",&p);
    matrix1=inputmatrix(n,m);
    matrix2=inputmatrix(m,p);
    printf("Matrix A:\n");
    printmatrix(matrix1,n,m);
    printf("Matrix B:\n");
    printmatrix(matrix2,m,p);
    multi=matrixmulti(matrix1,matrix2,n,m,p);
    printf("Result of multiplication\n");
    printmatrix(multi,n,p);
    return 0;
}

   
