/*
 CH-230-A
 a7_p4.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h" 


int main()
{
    char c;
    int n;
    struct stack *list;
    list = (struct stack *)malloc(sizeof(struct stack));
    
    do
    {
        scanf("%c",&c);
        switch (c)
        {
        case 's':
            scanf("%d",&n);
            getchar();
            push(list,n);
            break;
        case 'p':
            pop(list);
            break;
        case 'e':
            empty(list);
            break;
        case 'q':
            printf("Quit\n");
            break;
        }
    } while (c !='q');
    return 0;
}