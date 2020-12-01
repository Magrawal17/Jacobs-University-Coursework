/*
 CH-230-A
 a4_p5.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */
#include <stdio.h>
#include <stdlib.h>

void greatest(int *list,int n){
    int grt1,grt2,pos;
    grt1= *list;
    for (int i=0;i < n; i++){
        if ( (*(list+i)) >= grt1){
          grt1=*(list+i);
          pos = i;
        }
    }
    *(list + pos) = '\0'; 
    grt2=*list;
    for (int i=0;i < n; i++){
        if ((*(list+i)) >= grt2){
          grt2 = *(list+i);
        }
    }
    printf("The greatest two numbers are %d and %d\n",grt1,grt2);
}

int main(){
    int n;
    printf("Enter the number of elements you want\n");
    scanf("%d",&n);
    int *list;
    list= (int*) malloc(sizeof(int)* n);
    if (list == NULL){
    exit(1);}
    for (int i=0;i < n; i++){
        printf("Enter a number ");
        scanf("%d",&(*(list + i)));
    }
    greatest(list,n);
    free(list);
    return 0;
}