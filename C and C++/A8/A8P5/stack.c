#include<stdio.h>
#include<string.h>

#include "stack.h"

void push(char item[],struct stack *list){
   if (list->count<=19)
   {
      strcpy(list->array[list->count],item);
      list->count++;
   }
   else
   {
      printf("Pushing Stack Overflow\n");
   }
   
}

char *pop(struct stack *list){
   if (list->count>0)
   {
      list->count--;
      return list->array[list->count]; 
   }
   else
   {
     return "Poping Stack Underflow";
   }
}