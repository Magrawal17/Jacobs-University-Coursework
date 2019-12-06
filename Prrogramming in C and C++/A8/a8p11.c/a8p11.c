/*
 CH-230-A
 a8_p11.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    char fname[n][30];
    FILE *write;
    FILE *temp;
    char temp1[64];
    write=fopen("output.txt","w");
    if (write==NULL) 
    {
        printf("Cannot open file !\n");
    }
    for (int i=0;i<n;i++)
    {  
        scanf("%s",fname[i]);         
    }
    printf("Concating the content of %d files ...\n",n);
    printf("The result is:\n");
     char newline[] ="\n";
    for (int i=0;i<n;i++)
    {
        temp=fopen(fname[i],"r");
        fseek(temp,0,SEEK_END);
        int size=ftell(temp);
        fseek(temp,0,SEEK_SET);
        fread(temp1,sizeof(char),size,temp);
        temp1[size]='\0';
        printf("%s\n",temp1);
        fwrite(temp1,sizeof(char),size,write);
        fclose(temp);
        fwrite(newline,sizeof(char),1,write);
    }
    printf("The result was written into output.txt\n");
    fclose(write);
    return 0;
}

