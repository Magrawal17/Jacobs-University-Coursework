/*
 CH-230-A
 a6_p3.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <stdio.h>
#define min(a,b,c)(( (a<b) & (a<c) ) ? (a) : ( (b<c) ? (b):(c) ))
#define max(a,b,c)(( (a>b) & (a>c) ) ? (a) : ( (b>c) ? (b):(c) ))
#define mid_range(a,b,c) (min(a,b,c) + max(a,b,c)) /2.0
int main()
{
    int a,b,c;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    printf("The mid-range is: %.6lf\n",mid_range(a,b,c));
    return 0;
}
