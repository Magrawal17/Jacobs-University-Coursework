/*
 CH-230-A
 a4_p4.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */
#include <stdio.h>
#include <math.h>
#include <string.h>

int count_consonants(char c[]){
 int consonants;
 consonants=0;
 for (int i = 0; i < strlen(c); i++){
        if (c[i]=='a' || c[i]=='e' || c[i]=='i' ||
           c[i]=='o' || c[i]=='u' || c[i]=='A' ||
           c[i]=='E' || c[i]=='I' || c[i]=='O' ||
           c[i]=='U'){

           }
        else if((c[i]>='a'&& c[i]<='z') || (c[i]>='A'&& c[i]<='Z'))
        {
            consonants=consonants+1;
        }   
    }
 return (consonants);   
}

int main(){
    int temp[100];
    char c[100];
    for (int i = 0; i < 100; i++)
    {
        fgets(c,sizeof(c),stdin);
        if (strlen(c) == 1){
            break;
        }        
        temp[i] =count_consonants(c);
        printf("Number of consonants=%d\n",temp[i]);
    } 
    return 0;
}
