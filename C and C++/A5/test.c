/*
CH-230-A
a5_p7.c
Shashwat Guragain
s.guragain@jacobs-university.de
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char onec[100];
    char twoc[100];
    char *cat;
    fgets(onec, sizeof(onec), stdin);
    onec[strlen(onec) - 1] = '\0';
    fgets(twoc, sizeof(twoc), stdin);
    twoc[strlen(twoc) - 1] = '\0';
    strcat(onec, twoc);
    cat =(char *) malloc(sizeof(char) * strlen(onec));
    strcpy(cat,onec);
    printf("Result of concatenation: %s\n", cat);
    free (cat);

    return 0;
    
}