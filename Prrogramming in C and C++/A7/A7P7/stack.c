/*
 CH-230-A
 a7_p4.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h" 



void push(struct stack *list,int n)
{   
    if (list->count==12)
    {
        printf("Pushing Stack Overflow\n");
        
    }
    else
    {
        printf("Pushing %d\n",n);
        list->array[list->count]=n;
        list->count= list->count +1;
    }
    
}

void pop(struct stack *list)
{   
    if (list->count ==0)
    {
        printf("Popping Stack Underflow\n");
        
    }
    else
    {   
        list->count= list->count -1;  
        printf("Popping %d\n",list->array[list->count]);
        list->array[list->count]=0;
       

    }
   
}

void empty(struct stack *list)
{   
    printf("Emptying Stack ");
   while (list ->count > 0)
   {
       list ->count = list->count -1;
       printf("%d ",list ->array[list->count]);
   }
   printf("\n");
}

void isEmpty(struct stack *list){
   if(list->count==0)
   {
      printf("Stack is empty\n");
   }
}
