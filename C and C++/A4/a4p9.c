/*
 CH-230-A
 a4_p9.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */
 
#include <stdio.h>
#include <stdlib.h>

int prodminmax(int arr[],int n){
    int max;
    max= arr[0];
    for (int i = 0; i < n; i++)
   {
       if (max < arr[i]){
           max=arr[i];
       }
    }
    int min;
    min = arr[0];
    for (int i = 0; i < n; i++)
    {
       if (min > arr[i]){
           min=arr[i];
       }
    }
    return (min*max);
}
int main(){
    int n;
    printf("Enter the number of elements you want\n");
    scanf("%d",&n);
    int *arr;
    arr= (int*) malloc(sizeof(int)* n);
    if (arr == NULL){
        exit(1);
    }
    for (int i=0;i < n; i++){
        printf("Enter a number ");
        scanf("%d",&(*(arr + i)));
    }
    printf("The result of the max * min is %d\n",prodminmax(arr,n));
    free(arr);
    return 0;
}