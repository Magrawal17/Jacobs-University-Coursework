/*
 CH-230-A
 a5_p1.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */
#include <stdio.h>

void triangle(char ch,int n){
    int temp=n;
    for (int i =0; i < n; i++)
    {
       for (int j=0; j < temp; j++)
        {
           printf("%c",ch);
        }       
        temp=temp-1;
    printf("\n");
    }
}
int main(){
    char ch;
    int n;
    scanf("%d",&n);
    getchar();
    scanf("%c",&ch);
    triangle(ch,n);
    return 0;
}