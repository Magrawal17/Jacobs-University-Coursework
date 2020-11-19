/*
Apparently, the cost of obtaining locks frequently is much higher 
than the performance gain obtained by using multiple threads.

This arguement is also supported by the resuls of my program
*/

#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <errno.h>

int persons = 100;
int n_flips = 10000;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
char coins[20] = "OOOOOOOOOOXXXXXXXXXX";

char flip(char side);
static double timeit(int n, void *(*proc)(void *));
static void run_threads(int n, void *(*proc)(void *));
static void *strategy_one();
static void *strategy_three();
static void *strategy_two();

int main(int argc, char **argv)
{
    int flag;
    while ((flag = getopt(argc, argv, "p:n:")) != -1)
    {
        switch (flag)
        {
        case 'p':
            persons = atoi(optarg);
            if (persons < 1)
            {
                perror("Error: Invalid Entry (Number of People)  \n");
                exit(EXIT_FAILURE);
            }
            break;
        case 'n':
            n_flips = atoi(optarg);
            if (n_flips < 1)
            {
                perror("Error: Invalid Entry (Number of Flips)  \n");
                exit(EXIT_FAILURE);
            }
        }
    }

    printf("Persons (P): %d \nFlips (N) : %d \n", persons, n_flips);
    printf("----------------------------------------------------- \n\n");

    printf("coins: %s (start - global lock)\n", coins);
    double time1 = timeit(persons, strategy_one);
    printf("coins: %s (end - global lock)\n", coins);
    printf("%d threads x %d flips: %.3lf ms\n\n", persons, n_flips, time1);

    printf("coins: %s (start - iteration lock)\n", coins);
    double time2 = timeit(persons, strategy_two);
    printf("coins: %s (end - table lock)\n", coins);
    printf("%d threads x %d flips: %.3lf ms\n\n", persons, n_flips, time2);

    printf("coins: %s (start - coin lock)\n", coins);
    double time3 = timeit(persons, strategy_three);
    printf("coins: %s (end - coin lock)\n", coins);
    printf("%d threads x %d flips: %.3lf ms\n\n", persons, n_flips, time3);

    return EXIT_SUCCESS;
}

char flip(char side)
{
    if (side == 'O')
    {
        return 'X';
    }
    else
    {
        return 'O';
    }
}

static double timeit(int n, void *(*proc)(void *))
{
    clock_t t1, t2;
    t1 = clock();
    run_threads(n, proc);
    t2 = clock();
    return ((double)t2 - (double)t1) / CLOCKS_PER_SEC * 1000;
}

static void run_threads(int n, void *(*proc)(void *))
{
    pthread_t threads[n];
    int r;
    for (int i = 0; i < n; i++)
    {
        r = pthread_create(&threads[i], NULL, proc, NULL);
        if (r)
        {
            fprintf(stderr, "Failed to create thread: %s\n", strerror(r));
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (threads[i])
        {
            pthread_join(threads[i], NULL);
        }
    }
}

static void *strategy_one()
{
    pthread_mutex_lock(&mutex);
    for (int j = 0; j < n_flips; j++)
    {
        for (int i = 0; i < 20; i++)
        {
            coins[i] = flip(coins[i]);
        }
    }
    pthread_mutex_unlock(&mutex);
    return NULL;
}

static void *strategy_two()
{
    for (int j = 0; j < n_flips; j++)
    {
        pthread_mutex_lock(&mutex);
        for (int i = 0; i < 20; i++)
        {
            coins[i] = flip(coins[i]);
        }
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

static void *strategy_three()
{
    for (int j = 0; j < n_flips; j++)
    {
        for (int i = 0; i < 20; i++)
        {
            pthread_mutex_lock(&mutex);
            coins[i] = flip(coins[i]);
            pthread_mutex_unlock(&mutex);
        }
    }
    return NULL;
}