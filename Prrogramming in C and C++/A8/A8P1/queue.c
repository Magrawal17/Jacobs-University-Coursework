/*
 CH-230-A
 a8_p1.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void initialize_queue(Queue *pq)
{
	pq->front = pq->rear = NULL;
	pq->items = 0;
}

int queue_is_full(const Queue *pq)
{
	return pq->items == MAXQUEUE;
}

int queue_is_empty(const Queue *pq)
{
	return pq->items == 0;
}

int queue_item_count(const Queue *pq)
{
	return pq->items;
}

int enqueue(Item item, Queue *pq)
{
		Node *Newelem;
		Newelem=(Node*)malloc(sizeof(Node));
		if (Newelem==NULL)
		{
			printf("Error allocating memory");
			exit(1);
		}
		Newelem->item=item;
		Newelem->next=NULL;
		if (queue_is_empty(pq))
		{
			pq ->front = Newelem;
			pq ->rear  = Newelem;
		}
		else
		{
			pq ->rear->next = Newelem;
			pq ->rear = Newelem;
		}
		pq ->items=pq->items +1;
        return 0;
}

int dequeue(Item *pitem, Queue *pq)
{
	// add missing stuff
        return 0;
}

void empty_queue(Queue *pq)
{
	Item dummy;
	while (!queue_is_empty(pq)) {
		dequeue(&dummy, pq);
	}
}