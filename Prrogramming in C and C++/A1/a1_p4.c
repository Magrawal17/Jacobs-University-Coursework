
/*
 CH-230-A
 a1_p4.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */
 
#include <stdio.h>
int main() {
    int x=17;
    printf("x=%d\n",x);
    int y=4;
    printf("y=%d\n",y);
    int result= x+y;
    printf("sum=%d\n",result);
    int result2=x*y;
    printf("product=%d\n",result2 );
    int result3= x-y;
    printf("difference=%d\n",result3);
    float result4 = (float)x/(float)y;
    printf("division=%f\n",result4);
    int result5=x%y;
    printf("remainder of division=%d\n",result5);
}
