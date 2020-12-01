/*
 CH-230-A
 a6_p8.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

struct list
{
    int data;
    struct list *ptr;
};

struct list *remov(struct list *my_list);
struct list * push_front (struct list * my_list,int value ) ;
struct list *push_back(struct list *my_list, int value);
void print_list (struct list * my_list) ;
void freelist(struct list *my_list);;