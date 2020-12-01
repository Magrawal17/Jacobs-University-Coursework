/*
 CH-230-A
 a2_p1.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <stdio.h>
int main(){
    
double d1,d2;
scanf("%lf",&d1);
scanf("%lf",&d2);
double result= d1+d2;
printf("sum of doubles=%lf\n",result);
double result2= d1-d2;
printf("difference of doubles=%lf\n",result2);
double result3= d1*d1;
printf("square=%lf\n",result3);

int i1,i2;
scanf("%d",&i1);
scanf("%d",&i2);
int result4= i1 + i2;
int result5= i1 * i2;
printf("sum of integers=%d\n",result4);
printf("product of integers=%d\n",result5);

getchar();
char c1,c2;
scanf("%c",&c1);
getchar();
scanf("%c",&c2);
int result6= (int) c1 + (int) c2;
int result7= (int) c1 * (int) c2;
printf("sum of chars=%d\n",result6);
printf("product of chars=%d\n",result7);
printf("sum of chars=%c\n",result6);
printf("product of chars=%c\n",result7);
return 0;

}

