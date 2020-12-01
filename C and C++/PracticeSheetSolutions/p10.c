#include <stdio.h>
#include <stdlib.h>
//print matrix
void print_matrix(int **A, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int k = 0; k < col; k++)
        {
            printf("%d ", A[i][k]);
        }
        printf("\n");
    }
}

int main()
{
    //file open
    FILE *fp;
    fp = fopen("matrix.dat", "r");
    //file check
    if (fp == NULL)
    {
        perror("Error ");
        exit(EXIT_FAILURE);
    }

    int row, col;
    fscanf(fp, "%d", &row);
    fscanf(fp, "%d", &col);
    //dynamically allocate A
    int **A;
    A = (int **)malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++)
    {
        A[i] = (int *)malloc(col * sizeof(int));
    }

    //set initial values
    for (int i = 0; i < row; i++)
    {
        for (int k = 0; k < col; k++)
        {
            A[i][k] = 0;
        }
    }

    //read and store values
    int r, c;
    while (!feof(fp))
    {
        fscanf(fp, "%d", &r);
        fscanf(fp, "%d", &c);
        fscanf(fp, "%d", &A[r - 1][c - 1]);
    }

    //print matrix
    print_matrix(A, row, col);

    //deallocate matrix
    for (int i = 0; i < row; i++)
    {
        free(A[i]);
    }
    free(A);

    //close file
    fclose(fp);
    return 0;
}
