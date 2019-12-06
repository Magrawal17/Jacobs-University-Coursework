/*
 CH-230-A
 a4_p1.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */
#include <stdio.h>
#include <math.h>
int main(){
    float a,b,c,i;
    scanf("%f",&a);
    scanf("%f",&b);
    scanf("%f",&c);
    for (i = a; i <= b ; i=i+c)
    {
        printf("%f %f %f\n", i, i * i * M_PI, 2 * M_PI * i);
    }
    return 0;
}
