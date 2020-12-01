/*
 CH-230-A
 a6_p8.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"


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
        push_front(linkedlist,b);
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