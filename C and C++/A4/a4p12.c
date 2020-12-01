/*
 CH-230-A
 a4_p12.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void replaceAll(char *str,char c,char e){
    char temp[80];
    strcpy(temp,str);
    for (int i = 0; i < strlen(str); i++)
    {
        if ( *(str + i) == c)
        {
            *(str + i)= e;
        }
    }
    printf("The character to be replaced is %c\n",c);
    printf("The replacing character is %c\n",e);
    printf("The orignal word is %s",temp);
    printf("The replaced word is %s",str);
}

 int main()
 {
    char str[80],c,e;
    while(1)
        {
        fgets(str,sizeof(str),stdin);
        if (strcmp(str,"stop\n") == 0)
            {
            break;
            }
        printf("Enter the character to be replaced ");
        scanf("%c",&c);
        getchar();
        printf("Enter the replacing character ");
        scanf("%c",&e);
        getchar();
        replaceAll(str,c,e);
        }   
        return 0;
}