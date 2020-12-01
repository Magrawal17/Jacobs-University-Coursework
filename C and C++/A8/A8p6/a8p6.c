/*
 CH-230-A
 a8_p6.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char x,y;
    int sum;
    FILE *Readp;
    FILE *Writep;
    Readp=fopen("chars.txt","r");
    Writep=fopen("codesum.txt","w");
    if ( Readp == NULL || Writep == NULL ) 
    {
        printf("Cannot open file !\n");
    }
    x = getc(Readp);
    y = getc(Readp) ;
    sum=x+y;
    fprintf(Writep,"%d",sum);
    fclose(Writep);
    fclose(Readp);
    return 0;
}