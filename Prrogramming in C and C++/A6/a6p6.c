/*
 CH-230-A
 a6_p6.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <stdio.h>
int main()
    {
    
    unsigned char n;
    scanf("%c",&n);
    int k;
    printf("The decimal representation is: %d\n",n);
    printf("The binary representation is: ");
    for (int i = 7; i >= 0; i--) {   
     k=n>>i;
        if ( k & 1) 
            printf("1") ;
        else
            printf("0") ;
    } 
        

    printf("\n");
        
    return 0;
}