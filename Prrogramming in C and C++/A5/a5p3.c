/*
 CH-230-A
 a5_p3.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <stdio.h>
#include <string.h>

int count_lower(char *str){
    int count=0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (((int)(*(str +i)) >= 97) && ((int)(*(str +i)) <= 122))
        {
            count= count +1;
        }
        
    }
    return count;
}

int main(){
    char str[50];
    while(1)
    {
        printf("Enter a string\n");
        fgets(str,sizeof(str),stdin);
        
       
    } 
    return 0;
}