#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#ifdef __APPLE__
#include <dispatch/dispatch.h>
#else
#include <semaphore.h>
#endif

#include "common_threads.h"

#define SIZE 10000
#define MAX_THREAD 4

int min = 0x7fffffff;
int buf[SIZE];

// there may be more declarations here
//--------------------------------------------------
#ifdef __APPLE__
dispatch_semaphore_t mutex; /* Semaphore that protects counter */
#else
sem_t mutex;
#endif
/* $end goodcntsemdef */
//--------------------------------------------------

void *worker(void *arg)
{
    int mypart = (int)arg;
    int i, part_min = 0x7fffffff;
    int MAX = SIZE;
    for (i = mypart * (MAX / 4); i < (mypart + 1) * (MAX / 4); i++)
        if (buf[i] < part_min)
        {
            part_min = buf[i];
            // sleep(0.001);
        }

    // there may be more code here
    /* $begin  */
    for (i = 1; i < MAX_THREAD; i++)
    {
#ifdef __APPLE__
        dispatch_semaphore_wait(mutex, DISPATCH_TIME_FOREVER);
#else
        P(&mutex);
#endif
        if (min > part_min)
            min = part_min;
#ifdef __APPLE__
        dispatch_semaphore_signal(mutex);
#else
        V(&mutex);
#endif
    }
    /* $end  */

    // printf("Min value is = %d\n", part_min);
    // if (part_min < min)
    //     min = part_min;
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

    //--------------------------------------------------
/* Create threads and wait for them to finish */
/* $begin goodcntseminit */
#ifdef __APPLE__
    mutex = dispatch_semaphore_create(1); // init with value of 1
#else
    Sem_init(&mutex, 0, 1); /* mutex = 1 */
                            /* $end goodcntseminit */
#endif
    //--------------------------------------------------

    // Creating 3 worker threads
    for (i = 1; i < MAX_THREAD; i++)
        pthread_create(&tid[i], NULL, worker, (void *)i);
    // there may be more code here
    for (int j = 1; j < MAX_THREAD; j++)
        Pthread_join(tid[j], NULL);

    printf("min =  %d\n", min);

    return 0;
}
