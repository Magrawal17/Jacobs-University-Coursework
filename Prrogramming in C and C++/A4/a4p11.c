/*
 CH-230-A
 a4_p11.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int count_insensitive(char *str, char c){ 
int count=0;
   for (int i = 0; i < strlen(str); i++)
    {
        if (tolower(c) == tolower(*(str+i)))
        {
        count=count+1;
        }
    }
return count;
}


int main(){
    char *str;
    int n;
    char *temp= malloc(50 *sizeof(char));
    if (temp== NULL ){
        exit(1);
    }
    fgets(temp,50,stdin);
    n=strlen(temp);
    str= (char*) malloc (sizeof(char) * n);
    if (str == NULL){
        exit(1);
    }
    strcpy(str,temp);
    free(temp);
    printf("The character 'b' occurs %d times\n",count_insensitive(str,'b')); 
    printf("The character 'H' occurs %d times\n",count_insensitive(str,'H'));
    printf("The character '8' occurs %d times\n",count_insensitive(str,'8'));
    printf("The character 'u' occurs %d times\n",count_insensitive(str,'u'));
    printf("The character '$' occurs %d times\n",count_insensitive(str,'$'));
    printf("%s",str);
    free(str);
    return 0;
}