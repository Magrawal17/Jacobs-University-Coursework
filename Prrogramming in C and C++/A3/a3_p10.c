/*
 CH-230-A
 a3_p10.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <stdio.h>
float product(float a,float b)
{
    return (a*b);
}
void productbyref(float a, float b, float *p){
    *p=a*b;                //using by reference by only changing value inside pointer
}
void modifybyref(float *a, float *b){
    *a= *a + 3;              // adding 3 to the value contained inside pointer
    *b= *b + 11;              // adding 11 to the value contained inside pointer  
} 

int main(){
    float a,b,function1,function2;
    float *p,*ptra,*ptrb;
    function2 = 0.0;
    printf("Enter first value ");
    scanf("%f",&a);
    printf("Enter second value ");
    scanf("%f",&b);
    function1 = product(a,b);
    p=&function2;              //assigning value to pointer p
    productbyref(a,b,p);
    ptra=&a;                  //assigning value of variable a
    ptrb=&b;                  //assigning value of variable b
    modifybyref(ptra,ptrb);
    printf("Result of function1 %f\n",function1);
    printf("Result of function2 %f\n",&p);
    printf("Changed value of a is %f and value of b is %f\n",*ptra,*ptrb);
    return 0;
}

