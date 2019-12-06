/*
 CH-230-A
 a2_p4.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <stdio.h>
int main(){
    float a,b,h; 
    scanf("%f",&a);
    scanf("%f",&b);
    scanf("%f",&h);
    float result1,result2,result3,result4;
    result1=a*a;
    result2=a*b;
    result3=0.5 * a* h;
    result4=0.5 * (a+b) * h;
    printf("square area=%f\n",result1);
    printf("rectangle area=%f\n",result2);
    printf("triangle area=%f\n",result3);
    printf("trapezoid area=%f\n",result4);
    return 0;
}