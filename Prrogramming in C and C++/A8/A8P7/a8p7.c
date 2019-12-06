/*
 CH-230-A
 a8_p7.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */


#include <stdio.h>
#include <stdlib.h>

int main()
{
FILE *readp1;
FILE *readp2;
FILE *writep;
char temp1[20];
char temp2[20];
double x=0.0,y=0.0;
scanf("%s",temp1);
scanf("%s",temp2);
readp1=fopen(temp1,"r");
if (readp1==NULL) 
{
    printf("Cannot open file !\n");
}
fscanf(readp1,"%lf",&x);
readp2=fopen(temp2,"r");
if (readp2==NULL) 
{
    printf("Cannot open file !\n");
}
fscanf(readp2,"%lf",&y);
writep=fopen("result.txt","w");
if (writep==NULL) 
{
    printf("Cannot open file !\n");
}
fprintf(writep,"sum is %lf\n",x+y);
fprintf(writep,"difference is %lf\n",x-y);
fprintf(writep,"division is %lf\n",x/y);
fprintf(writep,"product is %lf\n",x*y);
fclose(readp1);
fclose(readp2);
fclose(writep);
return 0;
}
