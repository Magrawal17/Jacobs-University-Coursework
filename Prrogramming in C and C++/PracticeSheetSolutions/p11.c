#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct list {
	char str[20];
	struct list* next;
};

struct list*insertBegin(struct list* my_list, char *arr)
{
	struct list *new = (struct list*)malloc(sizeof(struct list));
	if (new == NULL)
		return my_list;
	strcpy(new->str,arr);
	new -> next = my_list;
	return new;
}

void printList(struct list *my_list)
{
	while(my_list != NULL)
	{
		printf("%s ", my_list->str);
		my_list = my_list -> next;
	}
}

int main()
{
	int count;
	scanf("%d", &count);
	getchar();
	struct list *my_list = NULL;
	char arr[100];
	for(int i=0; i<count; i++)
	{
		fgets(arr,sizeof(arr),stdin);
		arr[strlen(arr) - 1] = '\0';
		my_list = insertBegin(my_list, arr);
		printList(my_list);
		printf("\n");
	}
	free(my_list);
	return 0;
}
