/*
 CH-230-A
 a5_p4.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <stdio.h>
#include <stdlib.h>

void divby5(float arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        *(arr +i)= *(arr +i) /5.0;
    }
    
}

int main()
{
    int n;
    float *arr;
    printf("Number of elements you want\n");
    scanf("%d",&n);
    arr= (float*) malloc(sizeof(float)* n);
    if (arr == NULL)
    {
        exit(1);
    }
    for (int i=0;i < n; i++)
    {
        printf("Enter a number ");
        scanf("%f",&(*(arr + i)));
    }
    printf("Before:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%.3f ",*(arr +i));
    }
    printf("\n");
    divby5(arr,n);            // function dividing the elements by 5
    printf("After:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%.3f ",*(arr + i));
    }
    printf("\n");
    free(arr);
}