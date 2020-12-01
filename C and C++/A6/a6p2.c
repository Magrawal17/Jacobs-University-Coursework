/*
 CH-230-A
 a6_p2.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <stdio.h>
#define lbit(n) (n&1)==0?0:1
int main(){
    char c;
    scanf("%c",&c);
   // unsigned char bit=c;
    printf("The decimal representation is: %d\n",c);
    printf("The least significant bit is: %d\n",lbit(c)) ;
}