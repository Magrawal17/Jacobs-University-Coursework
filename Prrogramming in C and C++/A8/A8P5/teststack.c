/*
 CH-230-A
 a8_p5.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h" 


int main()
{
    struct stack *list;
    list = (struct stack *)malloc(sizeof(struct stack));
    char c[300];
    char temp[15][30];
    fgets(c,sizeof(c),stdin);
    c[(strlen(c))-1]='\0';
    char wordtemp[300];
    int charcount=0;
    int wordcount=0;
    
    for (int i = 0; i < strlen(c); i++)
	{
		if(c[i]==' ' || c[i]=='\0')
        {
            temp[wordcount][charcount]='\0';
            wordcount=wordcount+1;
            charcount=0;
		}
		else
        {
			temp[wordcount][charcount]=c[i];
            charcount=charcount+1;
		}
	}
    temp[wordcount][charcount]='\0';
    for (int i=0;i<=wordcount;i++)
    {
         push(temp[i],list);
    }
    while(list->count>0)
    {
       strcat(wordtemp, pop(list));
       strcat(wordtemp," ");
    }
    wordtemp[(strlen(c))]='\0';
    printf("%s\n",wordtemp);
    if(strcmp(wordtemp,c)==0)
    {
        printf("The sentence is palindromic by words!\n");
    }
    else
    {
        printf("The sentence is not palindromic by words!\n");
    }
    return 0;
}