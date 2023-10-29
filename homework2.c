
// Online C Compiler - Build, Compile and Run your C programs online in your favorite browser
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to add a new node to the list
struct Node* addNode(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf("->");
        }
        current = current->next;
    }
    printf("\n");
}

// Function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform a partition for QuickSort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] >= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Function to implement QuickSort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    struct Node* list = NULL;
    int numbers[100];

    // Seed the random number generator
    srand(time(NULL));

    // Generate 100 random numbers and add them to the list and array
    for (int i = 0; i < 100; i++) {
        int randomNumber = rand() % 1000;  // Adjust the range as needed
        list = addNode(list, randomNumber);
        numbers[i] = randomNumber;
    }

    // Sort the array in descending order
    quickSort(numbers, 0, 99);

    // Create the linked list from the sorted array
    list = NULL;
    for (int i = 0; i < 100; i++) {
        list = addNode(list, numbers[i]);
    }

    // Print the sorted list
    printf("Sorted numbers on the screen:\n");
    printList(list);

    // Free memory by deallocating the linked list
    struct Node* current = list;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
