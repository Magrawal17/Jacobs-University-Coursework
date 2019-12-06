/*
 CH-230-A
 a7_p4.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


void ucase(char str[100])
{
    for (int i=0; i < strlen(str); i++)
    {
        if (str[i]<=122 && str[i]>=97)
        {
            printf("%c",toupper(str[i]));
        }
        else
        {
            printf("%c",str[i]);
        }
        
    }
    
}

void lcase(char str[100])
{
    for (int i=0; i < strlen(str); i++)
    {
        if (str[i]<=90 && str[i]>=65)
        {
            printf("%c",tolower(str[i]));
        }
        else
        {
            printf("%c",str[i]);
        }
        
    }
    
}

void ulcase(char str[100])
{
    for (int i=0; i < strlen(str); i++)
    {
        if (str[i]<=122 && str[i]>=97)
        {
            printf("%c",toupper(str[i]));
        }
        else if (str[i]<=90 && str[i]>=65)
        {
            printf("%c",tolower(str[i]));
        }
        else
        {
            printf("%c",str[i]);
        }
    }  
}

void quit(char * str)
{
    exit(1);
}

int main()
{   
    char str[100];
    int n=0;
    void (*ptrfunc[4])(char*);
    fgets(str,sizeof(str),stdin);
    ptrfunc[0]=ucase;
    ptrfunc[1]=lcase;
    ptrfunc[2]=ulcase;
    ptrfunc[3]=quit;
    while (1)
    {
        scanf("%d",&n);
        (ptrfunc[n-1])(str);
    } 
    return 0;
}
