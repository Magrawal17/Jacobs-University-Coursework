/*
 CH-230-A
 a5_p11.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <stdio.h>
int prime(int first,int n)
{    
    if(n ==1)
    {
        return 1;
    }
    else
    {
       if(first%n ==0)
       {
         return 0;
       }
       else
       {
        return prime(first,n-1);
       }
    }
}

int main()
{
    int n;
    int result;
    scanf("%d",&n);
    if(n ==1)
    {
        result = 0;
    }
    else
    {
        result=prime(n,n/2);
    }
    if (result ==1)
    {
        printf("%d is prime\n",n);
    }
    else
    {
        printf("%d is not prime\n",n);
    }
}