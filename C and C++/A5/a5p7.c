/*
 CH-230-A
 a5_p7.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char one[100];
    char two[100];
    char *concat;
    fgets(one,sizeof(one),stdin);
    fgets(two,sizeof(two),stdin);
    for (int i=0; i <strlen(one);i++)      //takes out end of line from string one
    {
        if (one[i]== '\n')
        {
        one[i]='\0';
        }
    }
    for (int i=0; i <strlen(two);i++)     //takes out end of line from string two
    {
        if (two[i]== '\n')
        {
            two[i]='\0';
        }
    }
    strcat(one,two);
    concat=(char*) malloc(sizeof(char)* strlen(one));
    if (concat == NULL)
    {
    exit(1);
    }
    strcpy(concat,one);
    printf("Result of concatenation: %s\n",concat);
    return 0;
    free(concat);
}