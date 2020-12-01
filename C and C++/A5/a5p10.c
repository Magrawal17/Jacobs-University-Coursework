/*
 CH-230-A
 a5_p10.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <stdio.h>
void recursion(int n)
{
    if (n != 0)
    {
        printf("%d\n",n);
        recursion(n-1);
    }
}


int main()
{
    int n;
    scanf("%d",&n);
    recursion(n);
}
