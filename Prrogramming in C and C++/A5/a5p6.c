/*
 CH-230-A
 a5_p6.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int pos;
    float *temp;
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
    temp=arr;
    printf("Values before negative ones\n");
    while (*(arr) > 0)
    {
        printf("%f\n",*arr);
        arr++;
    }
    pos= (arr -temp);
    printf("Before the first negative value: %d elements\n",pos);
    free(arr);
}
