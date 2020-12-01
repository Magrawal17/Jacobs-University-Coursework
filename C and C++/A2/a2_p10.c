/*
 CH-230-A
 a2_p10.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <stdio.h>
int main(){
    int n,a;
    printf ("Enter a number ");
    scanf("%d",&n);
    while (n <= 0 ) {
    printf ("Enter the number again ");
    scanf("%d",&n);
    }
    a=1;
    while (a <= n) {
    printf ("%d day = %d hours\n",a,24*a) ;
    a ++;
    }
    return 0;
}