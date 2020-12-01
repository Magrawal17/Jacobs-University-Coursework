/*
 CH-230-A
 a4_p13.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void uppcase(char *str){
    for (int i = 0; i < strlen(str); i++)
    {
        *(str +i)=toupper(*(str +i));
    }
printf("uppcase=%s",str);
}
void lowcase(char *str){
    for (int i = 0; i < strlen(str); i++)
    {
        *(str +i)=tolower(*(str +i));
    }
printf("lowcase=%s",str);
}
int main()
 {
    char str[90];
    while(1)
        {
        fgets(str,sizeof(str),stdin);
        if (strcmp(str,"exit\n") == 0)
            {
            break;
            }
        uppcase(str);
        lowcase(str);
        }   
   
    return 0;
}
