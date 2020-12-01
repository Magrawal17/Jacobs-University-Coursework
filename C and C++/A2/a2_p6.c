/*
 CH-230-A
 a2_p6.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <stdio.h>
int main(){
    double x,y;
    scanf("%lf",&x);
    scanf("%lf",&y);
    double *ptr_one,*ptr_two,*ptr_three;
    ptr_one=&x;
    ptr_two=&x;
    ptr_three=&y;
    printf("Memory adress of pointer one is %p\n",ptr_one);
    printf("Memory adress of pointer two is also %p\n",ptr_two);
    printf("Memory adress of pointer three however is %p\n",ptr_three);
    return 0;
}