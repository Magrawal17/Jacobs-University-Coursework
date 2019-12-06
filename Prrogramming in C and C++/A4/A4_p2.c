/*
 CH-230-A
 a4_p24.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <stdio.h>
#include <string.h>
int main(){
    char var[50];
    fgets(var,sizeof(var),stdin);
     for (int i = 0; i < (strlen(var)-1) ; i++)
    {
        if (i%2==0){
        printf("%c\n",var[i]);
        }
        else
        {
            printf(" %c\n",var[i]);
        } 
    }
    return 0;
}