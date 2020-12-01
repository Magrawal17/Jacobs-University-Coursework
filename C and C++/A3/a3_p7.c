/*
 CH-230-A
 a3_p7.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <stdio.h>
void print_form(int n,int m, char c);
int main(){
    int n,m;
    scanf("%d",&n);
    scanf("%d",&m);
    char c;
    getchar();
    scanf("%c",&c);
    getchar();
    print_form(n,m,c);
    return 0;
    }

void print_form(int n,int m, char c){
    int test;
    test=m;                                   // used to store the initial position of m
    for ( int i = 1; i <= n ; i++){           // Height of the trapezuim
        for ( int j= 1; j <= test; j++){      // Number of times we want char c
            printf("%c",c);
        }
        printf("\n");                         // break into another line for printing
        if (test == (n+m-1)){                 // will run the loop only until (n+m-1)
         break;
        }   
        test=test+1;                          // increment of the value of test or m
                                
    }
}

