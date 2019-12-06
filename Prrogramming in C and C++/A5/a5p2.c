/*
 CH-230-A
 a5_p2.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */


#include <stdio.h>
void divby5(float arr[], int size){
    
    for (int i = 0; i < size; i++)
    {
        *(arr +i)= *(arr +i) /5.0;
    }
    
}

int main(){
    float arr[]={5.5, 6.5, 7.75, 8.0, 9.60, 10.36};
    int size;
    size=sizeof(arr)/sizeof(float);
    printf("Before:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%.3f ",arr[i]);
    }
    printf("\n");
    divby5(arr,size);
    printf("After:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%.3f ",arr[i]);
    }
    printf("\n");
    return 0;
}