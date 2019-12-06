/*
 CH-230-A
 a2_p3.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <stdio.h>

int main(){
    int weeks,days,hours,total;
    printf("Enter weeks\n");
    scanf("%d",&weeks);
    printf("Enter days\n");
    scanf("%d",&days);
    printf("Enter hours\n");
    scanf("%d",&hours);
    total= ((weeks*168)+ (days*24)+(hours));
    printf("Total hours is %d\n",total);
    return 0;
}