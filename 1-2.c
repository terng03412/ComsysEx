#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main()
{
    printf("Start\n");
    if (fork() != 0)
    {
        printf("One\n");
        if (fork() != 0)
        {
            printf("Two\n");
        }
    }
    sleep(1);
    printf("End\n");
}
