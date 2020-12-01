/*
 CH-230-A
 a8_p9.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */


#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *readp1;
    char temp[20];
    scanf("%s",temp);
    char c;
    int bool=0,count=0;
    readp1=fopen(temp,"r");
    if (readp1==NULL) 
    {
    printf("Cannot open file !\n");
    }
    c=fgetc(readp1);
    while (c != EOF)
    {
            if (c == ' '||c == '\n'||c=='\t'||c=='.'||c=='?'||c=='\r'||c=='!'||c==',')
            {
                bool = 0;
            }
            else if (bool == 0)
            {
                bool = 1;
                count= count+1;
            }
            c= fgetc(readp1);
    }
    printf("The file contains %d words.\n",count);
    fclose(readp1);
    return 0;
}
