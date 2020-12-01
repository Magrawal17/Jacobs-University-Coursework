/*
 CH-230-A
 a6_p7.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <stdio.h>
#include <math.h>
unsigned char set3bit(unsigned char c,int bit1,int bit2,int bit3)
{
    c = c | (int)pow(2,bit1);
    c = c | (int)pow(2,bit2);
    c = c | (int)pow(2,bit3);
    return c;
}
void binary(unsigned char c)
{
    for (int i = 7; i >= 0; i--) 
        {        
            if ( (c >> i) & 1) 
                printf("1") ;
            else
                printf("0") ;
        } 
        printf("\n");
}
int main()
    {
    unsigned char c;
    scanf("%c",&c);
    printf("The decimal representation is: %d\n",c);
    printf("The binary representation is: ");
    binary(c);
    int bit1,bit2,bit3;
    scanf("%d",&bit1);
    scanf("%d",&bit2);
    scanf("%d",&bit3);
    printf("After setting the bits: ");
    printf("%d\n",set3bit(c,bit1,bit2,bit3));
    binary(set3bit(c,bit1,bit2,bit3));
    return 0;
}