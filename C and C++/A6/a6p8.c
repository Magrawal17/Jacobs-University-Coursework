/*
 CH-230-A
 a6_p8.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <stdio.h>
#include <stdlib.h>
struct list
{
    int data;
    struct list *ptr;
};


struct list *remov(struct list *my_list)
{
    if (my_list==NULL)
    {
        return my_list;
    }
    my_list->data=0;
    return my_list->ptr;  
}


struct list * push_front (struct list * my_list,int value ) 
{
    struct list *newel;
    newel = (struct list *)malloc(sizeof(struct list));
    if (newel == NULL)
    {
        printf(" Error allocating memory \n");
        return my_list;
    }
    newel->data = value;
    newel->ptr = my_list;
    return newel;
}

struct list *push_back(struct list *my_list, int value)
{
    struct list *cursor, *newel;
    cursor = my_list;
    newel = (struct list *)malloc(sizeof(struct list));
    if (newel == NULL)
    {
        printf(" Error allocating memory \n");
        return my_list;
    }
    newel->data = value;
    newel->ptr = NULL;
    if (my_list == NULL)
        return newel;
    while (cursor->ptr != NULL)
    {
        cursor = cursor->ptr;
    }
    cursor->ptr = newel;
    return my_list;
}

void print_list (struct list * my_list) 
{
    struct list *p;
    for (p = my_list; p!=NULL; p = p->ptr)
    {
        printf("%d ", p->data);
    }
    printf("\n");
 }

void freelist(struct list *my_list)
{
    struct list *nextelem;
    while (my_list != NULL)
    {
        nextelem = my_list->ptr;
        free(my_list);
        my_list = nextelem;
    }
}

int main()
{
char c;
int a,b;
struct list *linkedlist=NULL;
do
{
    scanf("%c",&c);
    switch (c)
    {
    case 'a':
        scanf("%d",&a);
        linkedlist=push_back(linkedlist,a);
        break;
    case 'b':
        scanf("%d",&b);
        linkedlist=push_front(linkedlist,b);
        break;
    case 'r':
        linkedlist=remov(linkedlist);
        break;
    case 'p':
        print_list(linkedlist);
        break;
    case 'q':
        freelist(linkedlist);
    default:
        break;
    }
    
} while (c !='q');
return 0;
}


