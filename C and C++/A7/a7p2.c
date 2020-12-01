/*
 CH-230-A
 a7_p2.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <stdio.h>
#include <stdlib.h>

struct list
{
    char data;
    struct list *fptr;
    struct list *bptr;
    
};

struct list* removeelem(struct list* linklist,char c)
{
    struct list* cursor = NULL;
    struct list* back =NULL;
    struct list* ahead = NULL;
    cursor = linklist;
    int bool=0;
    while (cursor != NULL)
    {
        if (cursor ->data == c)
        {
            bool=1;
            if (cursor ->bptr == NULL)
            {
                cursor=cursor->fptr;
                cursor->bptr = NULL;
                linklist=cursor;
            }
            else if (cursor ->fptr == NULL)
            {
                cursor=cursor->bptr;
                cursor->fptr= NULL;
            }
            else
            {
                back =cursor -> bptr ;
                ahead = cursor ->fptr ;
                cursor = ahead;
                cursor ->bptr = back;
                cursor = back;
                cursor ->fptr = ahead;
                
            }
        }
        cursor =cursor ->fptr;
    }
    if (bool==0)
    {
        printf("The element is not in the list!\n");
    }
    return linklist;   
}



struct list* startoflist(struct list* linklist, char c)
{
    struct list* newelem;
    newelem = (struct list *) malloc (sizeof(struct list));
    if (newelem == NULL)
    {
        printf(" Error allocating memory \n");
        return linklist;
    }
    newelem ->bptr = NULL;
    newelem ->data = c;
    newelem ->fptr = linklist;
    if (linklist == NULL)
    {
        return newelem;
    }
    else
    {
        linklist ->bptr = newelem;
        return newelem;
    }
}

void printlist(struct list* linklist)
{
    struct list *p;
    for (p = linklist; p!= NULL; p = p->fptr)
    {
        printf("%c ", p->data);
    }
    printf("\n");  
}

void reverse(struct list *linklist)
{
        struct list* cursor;
        cursor = linklist;
        while (cursor ->fptr != NULL)
        {
            cursor = cursor->fptr;
        }
        struct list* back;
        for (back = cursor; back != NULL; back = back->bptr)
        {
            printf("%c ", back->data);
        }
        printf("\n"); 
        
}

void freelist(struct list* linklist)
{
    struct list *nextelem;
    while (linklist != NULL)
    {
        nextelem = linklist->fptr;
        free(linklist);
        linklist = nextelem;
    }
}


int main()
{
    int a;
    struct list *linklist = NULL;
    char c;
    do
    {
        scanf("%d",&a);
        getchar();
        switch (a)
        {
        case 1:
            scanf("%c",&c);
            getchar();
            linklist=startoflist(linklist,c);
            break;
        case 2:
            scanf("%c",&c);
            getchar();
            linklist=removeelem(linklist,c);
            break;
        case 3:
            printlist(linklist);
            break;
        case 4:
            reverse(linklist);
            break;
        case 5:
            freelist(linklist);
            break;
        default:
            a=5;
            break;
        }
    } while (a != 5);
    return 0;
}

