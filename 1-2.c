#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main()
{
    printf("Start\n");
    if (fork() != 0)
    {
        sleep(1);
        printf("One\n");
        if (fork() != 0)
        {
            sleep(1);
            printf("Two\n");
        }
    }
    printf("End\n");
}
