
/*
 CH-230-A
 a4_p7.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */
 
#include <stdio.h>
#include <stdlib.h>
 
void printmat(int mat[30][30],int n){
    printf("The entered matrix is:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}
void printdiag(int mat[30][30],int n){
    printf("Under the main diagonal:\n");
    for (int i = 0; i < n; i++)
    {
    for (int j=0;j <n;j++)
        {
        if (i==j)
            {
            for (int m = 0;  m < i ; m++)
                {
                printf("%d ",mat[i][m]);
                }
            }
        }
    }
    printf("\n");
}
 
int main(){
    int n;
    int mat[30][30];
    scanf("%d",&n);
    for (int i=0;i < n; i++){
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&mat[i][j]);
        }
        
    }
    printmat(mat,n);
    printdiag(mat,n);
    return 0;
}