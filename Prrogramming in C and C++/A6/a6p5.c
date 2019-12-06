
/*
 CH-230-A
 a6_p5.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <stdio.h>
int main()
    {
    unsigned char c;
    scanf("%c",&c);
    printf("The decimal representation is: %d\n",c);
    printf("The backwards binary representation is: ");
    int i=0;
    while ( (1 << i) <= c)
    {
        
        if ((c >> i) & 1) //c=c>>1 and c&1
            printf("1") ;
        else
            printf("0") ;
        i=i+1;
    }
    printf("\n");
    return 0;
}