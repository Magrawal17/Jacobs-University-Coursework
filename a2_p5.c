/*
 CH-230-A
 a2_p5.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <stdio.h>
int main(){
    int a;
    scanf("%d",&a);
    printf("The integer is %d\n",a);
    int *ptr_a;
    ptr_a=&a;
    printf("The memory address of the integer is %p\n",ptr_a);
    *ptr_a= *ptr_a + 5;
    printf("The value of the modified integer is %d\n",*ptr_a);
    printf("The address of the modified integer is %p\n",ptr_a);
    return 0;
}