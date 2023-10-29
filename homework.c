
// Online C Compiler - Build, Compile and Run your C programs online in your favorite browser
#include <stdio.h>
#include <stdlib.h>

// Define a structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to add a node to the front of the linked list
struct Node* addNodeToFront(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

// Function to add a node to the end of the linked list
struct Node* addNodeToEnd(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (head == NULL) {
        return newNode;
    }
    
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    
    current->next = newNode;
    return head;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* list = NULL;
    int number;

    printf("Enter numbers (-1 to stop):\n");
    
    while (1) {
        scanf("%d", &number);

        if (number == -1) {
            break;
        } else if (number % 2 == 0) {
            // Even number, add to the end of the list
            list = addNodeToEnd(list, number);
        } else {
            // Odd number, add to the beginning of the list
            list = addNodeToFront(list, number);
        }
    }

    printf("Resulting list: ");
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


