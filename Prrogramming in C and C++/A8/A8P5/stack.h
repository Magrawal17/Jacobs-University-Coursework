/*
 CH-230-A
 a8_p5.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */
struct stack {
   unsigned int count;
   char array[20][30]; // Container
};

void push(char temp[],struct stack *list);
char *pop(struct stack *list);