/*
 CH-230-A
 a5_p9.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <stdio.h>
#include <stdlib.h>
int  ***inputmatrix(int r,int c,int d)
{
    int ***matrix=NULL;
    matrix = (int ***)malloc(r * sizeof(int **)); 
    if (matrix== NULL)
    {
        exit(1);
    }
    for (int i=0; i<r; i++) 
    {
        matrix[i] = (int **)malloc(c * sizeof(int*));
        if (matrix[i] == NULL)
        {
        exit(1);
        }
        for (int j = 0; j < c; j++)
        {
            matrix[i][j]= (int*)malloc(d*sizeof(int));
            if (matrix[i][j] == NULL)
            {
                exit(1);
            }
        }
        
    }

    for (int i = 0; i <  r; i++) 
    {
      for (int j = 0; j < c; j++) 
      {
          for (int k = 0; k < d; k++)
          {
              scanf("%d",&(matrix[i][j][k]));
          }  
      }
    }   
    return matrix;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            free(matrix[i][j]);
        }
        free (matrix[i]);
    }
    free (matrix);
}
void printmatrix(int*** matrix,int r,int c,int d)
{
    for (int k=0; k <d;k++)
    {
        printf("Section %d:\n",k+1);
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                  printf("%d ",matrix[i][j][k]);
            }
            printf("\n");
        }
    }
}
int main()
{
    int r,c,d;
    int ***matrix;
    scanf("%d",&r);
    scanf("%d",&c);
    scanf("%d",&d);
    matrix=inputmatrix(r,c,d);
    printmatrix(matrix,r,c,d);
}