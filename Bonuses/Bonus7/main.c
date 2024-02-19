#include <stdio.h> // Include the standard input/output library
#include <stdlib.h> // Include the standard library

// Define a struct for the nodes in the linked list
typedef struct Node {
    long long int number; // The number stored in this node
    struct Node* next; // Pointer to the next node
    struct Node* prev; // Pointer to the previous node
} Node;

Node* fib(int num); // Function prototype for the fib function

// The main function
int main(int argc, char* argv[]) {
    if (argc != 2) { // If the number of command-line arguments is not 2
        printf("invalid"); // Print an error message
        return 0; // And exit the program
    }

    else if (atoi(argv[1]) <= 0) { // If the first command-line argument is less than or equal to 0
        printf("%d", 0); // Print 0
        return 0; // And exit the program
    }
    int nr = atoi(argv[1]); // Convert the first command-line argument to an integer
    fib(nr); // Call the fib function with nr as the argument
}

// The fib function
Node* fib(int num) {
    Node* head = NULL; // The head of the linked list
    Node* curr = NULL; // The current node in the linked list
    for (int i = 0; i < num; i++) { // For each number from 0 to num-1
        Node* newNode = malloc(sizeof(Node)); // Allocate memory for a new node
        newNode->next = NULL; // Set the next pointer of the new node to NULL

        if (i == 0) { // If this is the first node
            newNode->number = 0; // Set the number to 0
            head = newNode; // Set the head to the new node
            curr = head; // Set the current node to the head
            head->prev = NULL; // Set the prev pointer of the head to NULL
        } else if (i == 1) { // If this is the second node
            newNode->number = 1; // Set the number to 1
            head->next = newNode; // Set the next pointer of the head to the new node
            newNode->prev = head; // Set the prev pointer of the new node to the head
            curr = newNode; // Set the current node to the new node
        } else { // For all subsequent nodes
            newNode->number = curr->prev->number + curr->number; // Set the number to the sum of the numbers in the previous two nodes
            curr->next = newNode; // Set the next pointer of the current node to the new node
            newNode->prev = curr; // Set the prev pointer of the new node to the current node
            curr = newNode; // Set the current node to the new node
        }
    }
    printf("%lld\n", curr->number); // Print the number in the current node
    while ((curr = head) != NULL) { // While the current node is not NULL
        head = curr->next; // Set the head to the next node
        free(curr); // Free the memory allocated for the current node
    }
}