
// Online C Compiler - Build, Compile and Run your C programs online in your favorite browser
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a student record
struct Student {
    char name[50];
    int rollNumber;
    struct Student* next;
};

// Function to search for a student by name and return their record
struct Student* searchStudentByName(struct Student* head, const char* nameToFind) {
    struct Student* current = head;
    
    while (current != NULL) {
        if (strcmp(current->name, nameToFind) == 0) {
            return current; // Found the student by name
        }
        current = current->next;
    }
    
    return NULL; // Student not found
}

// Function to delete the next node after a given node
void deleteNextNode(struct Student* previousNode) {
    if (previousNode == NULL || previousNode->next == NULL) {
        return; // Nothing to delete
    }
    
    struct Student* nodeToDelete = previousNode->next;
    previousNode->next = nodeToDelete->next;
    free(nodeToDelete);
}

// Function to add a new student to the list
struct Student* addStudentToList(struct Student* head, const char* name, int rollNumber) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    if (newStudent == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    
    strcpy(newStudent->name, name);
    newStudent->rollNumber = rollNumber;
    newStudent->next = head;
    
    return newStudent;
}

int main() {
    struct Student* list = NULL;
    
    // Add some sample student records to the list with different names
    list = addStudentToList(list, "John", 101);
    list = addStudentToList(list, "Emily", 102);
    list = addStudentToList(list, "Daniel", 103);
    list = addStudentToList(list, "Sophia", 104);

    printf("Enter a student name to search: ");
    char nameToSearch[50];
    scanf("%s", nameToSearch);

    struct Student* foundStudent = searchStudentByName(list, nameToSearch);

    if (foundStudent != NULL) {
        printf("Student found:\n");
        printf("Name: %s\n", foundStudent->name);
        printf("Roll Number: %d\n", foundStudent->rollNumber);
        
        deleteNextNode(foundStudent); // Delete the next node

        printf("Next student node after %s has been deleted.\n", nameToSearch);
    } else {
        printf("Student not found.\n");
    }

    // Free memory by deallocating the linked list
    struct Student* current = list;
    while (current != NULL) {
        struct Student* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
