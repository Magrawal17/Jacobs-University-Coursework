/*
 CH-230-A
 a8_p8.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *readp1;
    FILE *readp2;
    FILE *merge;
    char c;
    readp1=fopen("text1.txt","r");
    if (readp1==NULL) 
    {
        printf("Cannot open file !\n");
    }   
    readp2=fopen("text2.txt","r");
    if (readp2==NULL) 
    {
        printf("Cannot open file !\n");
    }
    merge= fopen("merge12.txt", "w");   
    if (merge==NULL) 
    {
        printf("Cannot open file !\n");
    }
    while ((c = fgetc(readp1)) != EOF)
    {
        fputc(c, merge);
    }
    while ((c = fgetc(readp2)) != EOF)
    {
        fputc(c, merge);
    }
    //question does not tell whether or not have space,newline after the two files.
    //what exaclty is the meaning of merge therefore i just concatented them.
    fclose(readp1);
    fclose(readp2);
    fclose(merge);
    return 0;
}