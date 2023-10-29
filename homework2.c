#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100

int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int numbers[ARRAY_SIZE];
    
    srand(time(NULL));
    
    for (int i = 0; i < ARRAY_SIZE; i++) {
        numbers[i] = rand() % 1000;
    }
    
    qsort(numbers, ARRAY_SIZE, sizeof(int), compare);
    
    printf("Sorted Numbers (Largest to Smallest):\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d\n", numbers[i]);
    }
    
    return 0;
}