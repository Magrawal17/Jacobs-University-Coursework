/*
 CH-230-A
 a6_p1.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <stdio.h>
#define swap(a,b,type) {type temp=a;a=b;b=temp;}

int main(){
int a,b;
double x,y;
scanf("%d",&a);
scanf("%d",&b);
swap(a,b, int);
scanf("%lf",&x);
scanf("%lf",&y);
swap(x,y, double);
printf("After swapping:\n");
printf("%d\n",a);
printf("%d\n",b);
printf("%.6lf\n",x);
printf("%.6lf\n",y);
return 0;
}