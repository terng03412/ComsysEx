#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "common_threads.h"

#define SIZE 10000
#define MAX_THREAD 4

int min;
int buf[SIZE];

// there may be more declarations here

void *worker(void *arg)
{
    int mypart = (int)arg;
    int i, part_min = 0x7fffffff;
    int MAX = SIZE;
    for (i = mypart * (MAX / 4); i < (mypart + 1) * (MAX / 4); i++)
        if (buf[i] < part_min)
            part_min = buf[i];

    printf("Min value is = %d\n", part_min);
    // there may be more code here
}

int main()
{
    FILE *ptr;
    int i = 0, count = 0;
    pthread_t tid[MAX_THREAD];

    ptr = fopen("int_in.txt", "r");
    while (fscanf(ptr, "%d ", &buf[count]) != EOF)
    {
        count++;
    }
    printf("Total numbers read = %d\n", count);

    // Creating 3 worker threads
    for (i = 1; i < MAX_THREAD; i++)
        pthread_create(&tid[i], NULL, worker, (void *)i);

    for (int j = 1; j < MAX_THREAD; j++)
        Pthread_join(tid[j], NULL);

    // there may be more code here

    return 0;
}
