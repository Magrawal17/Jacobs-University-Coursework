/*
 CH-230-A
 a8_p3.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

/**
 * @file queue.h
 */

#ifndef _QUEUE_H_
#define _QUEUE_H_

typedef int Item;

#define MAXQUEUE 10

typedef struct node
{
	Item item;
	struct node *next;
} Node;

typedef struct queue
{
	Node *front;
	Node *rear;
	int items;
} Queue;


/**
 * @brief Initializes a queue
 *
 * Initializes a newly allocated queue. It does not cleanup an already
 * used queue. Use empty_queue() for cleaning up an already used queue.
 *
 * @param pq The pointer to the queue structure.
 */

void initialize_queue(Queue *pq);

/**
 * @brief Tests whether the queue is full.
 *
 * Tests whether the queue is full, i.e., the number of elements in
 * the queue has reached MAXQUEUE.
 *
 * @param pq The pointer to the queue structure.
 *
 * @return 1 if the queue is full, 0 otherwise
 */

int queue_is_full(const Queue *pq);

/**
 * @brief Tests whether the queue is empty.
 *
 * Tests whether the queue is full, i.e., the number of elements in
 * the queue has reached 0. A newly initialized queue is empty.
 *
 * @param pq The pointer to the queue structure.
 *
 * @return 1 if the queue is empty, 0 otherwise.
 */

int queue_is_empty(const Queue *pq);

/**
 * @brief Returns the number of items in the queue.
 *
 * Returns the number of items currently in the queue.
 *
 * @param pq The pointer to the queue structure.
 *
 * @return The returned value will be between 0 and MAXQUEUE.
 */

int queue_item_count(const Queue *pq);

/**
 * @brief Add a new item to the queue.
 *
 * Add a new item to the queue.
 *
 * @param item The item to add to the queue.
 * @param pq The pointer to the queue structure.
 *
 * @return Returns the value 0 if successful and the value -1 in case
 * an error occurred (e.g., the queue is full or memory allocation
 * failed).
 */

int enqueue(Item item, Queue *pq);

/**
 * @brief Remove an item from the queue.
 *
 * Remove an item from the queue.
 *
 * @param pitem The pointer to memory where the item can be returned.
 * @param pq The pointer to the queue structure.
 *
 * @return Returns the value 0 if successful and the value -1 in case
 * an error occurred (e.g., the queue is empty).
 */

int dequeue(Item *pitem, Queue *pq);

/**
 * @brief Empty the queue.
 *
 * Empty the queue by removing all stored items. This leaves the queue
 * in its initialized state so that the queue can be reused.
 *
 * @param pq The pointer to the queue structure.
 */

void empty_queue(Queue *pq);
void printq(Queue pq);

#endif