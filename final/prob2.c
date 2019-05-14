#include <stdio.h>

#define SIZE 10000

int min;
int buf[SIZE];

int main() {
    FILE *ptr;
    int i = 0, count = 0;
    ptr = fopen("int_in.txt", "r");
    while (fscanf(ptr, "%d ", &buf[count]) != EOF) {
        count++;
    }
    printf("Total numbers read = %d\n", count);

    min = 0x7fffffff;
    for (i=0; i<SIZE; i++) {
        if (buf[i] < min) min = buf[i];
    }
    printf("Min value is = %d\n", min);
    return 0;
}
