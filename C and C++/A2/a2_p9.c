/*
 CH-230-A
 a2_p9.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <stdio.h>
int main(){
    char a;
    scanf("%c",&a);
    int a1;
    a1=(int) a;
 if ((a1 >= 65 && a1 <=90) || (a1 >=97 && a1<=122) )
    {
     printf("%c is a letter\n",a);
    }
    else if (a1 >= 48 && a1 <=57 ){
     printf("%c is a digit\n",a);
    }
    else
    {
     printf("%c is some other symbol\n",a);
    }
 
    return 0;
}