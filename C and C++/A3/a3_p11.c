/*
 CH-230-A
 a3_p11.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */
#include <stdio.h>
#include <string.h>
int main(){
    char one[100],two[100],three[100],temp[100],c;
    int bool;
    fgets(one,sizeof(one),stdin); 
    fgets(two,sizeof(two),stdin);
    scanf("%c",&c);
    getchar();
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
    printf("length1=%lu\n",strlen(one));     
    printf("length2=%lu\n",strlen(two));
    strcpy(temp,one);                     //storing in temp value so that you dont have error later on concatenation
    printf("concatenation=%s\n",strcat(temp,two));
    strcpy(three,two);
    printf("copy=%s\n",three);
    if (strcmp(one,two)==0){            //comapring the values of a and b
        printf("one is equal to two\n");
    }
    else if (strcmp(one,two) > 0){
        printf("one is larger than two\n");
    }
    else 
    {
     printf("one is smaller than two\n");
        
    }
    bool=0;                                      // decalration of boolean variable
    for (int  i = 0; i <= strlen(two); i++)     // condition to search the charatcer
    {
        if (two[i] ==c)
        {
            printf("position=%d\n",i);
            bool=1;
            break;
        }
    }    
    if (bool== 0)                                  //checking when you dont find the character
        {
        printf("The character is not in the string\n");
        }
    return 0;
}
