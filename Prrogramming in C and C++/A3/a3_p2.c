/*
 CH-230-A
 a3_p2.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <stdio.h>
int main(){
    char ch;
    printf("Enter a lowercase character ");
    scanf("%c", &ch);
    int n,i;
    printf("Enter an integer ");
    scanf("%d",&n);
    for (i=0 ;i < n; i++){             // Runs the program till n 
        printf("%c,",ch);                 
        ch= ch -1;                    // Deducts the value of ch each time
        }
    return 0;
}

