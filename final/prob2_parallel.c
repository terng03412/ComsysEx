#include <stdio.h>

#define SIZE 10000
#define MAX_THREAD 4

int min;
int buf[SIZE];

// there may be more declarations here

void *worker(void *arg) {
    int mypart = (int)arg;
    int i, part_min = 0x7fffffff;

    for (i = mypart * (MAX / 4); i < (mypart + 1) * (MAX / 4); i++)
        if (buf[i] < part_min) part_min = buf[i];
    
    // there may be more code here

}

int main() {
    FILE *ptr;
    int i = 0, count = 0;
    pthread_t tid[MAX_THREAD]; 

    ptr = fopen("int_in.txt", "r");
    while (fscanf(ptr, "%d ", &buf[count]) != EOF) {
        count++;
    }
    printf("Total numbers read = %d\n", count);
  
    // Creating 3 worker threads 
    for (int i = 1; i < MAX_THREAD; i++) 
        pthread_create(&tid[i], NULL, worker, (void*)i);

    // there may be more code here

    return 0;
}
