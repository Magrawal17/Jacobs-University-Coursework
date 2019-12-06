/*
 CH-230-A
 a2_p8.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <stdio.h>
#include <math.h>

int main(){
    int a;
    scanf("%d",&a);
    if ((a%7== 0) && (a%2==0))
    {
        printf("The number is divisible by 2 and 7\n");
    }
    else
    {
        printf("The number is NOT divisible by 2 and 7\n");

    }    
    return 0;
}