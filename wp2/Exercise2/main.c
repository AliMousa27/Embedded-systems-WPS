#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
// #### Constants #####
#define MAX 5
// ##### typedefs ####
// struct defination
typedef struct q {
    // has number
    int number;
    // has a pointer to the next element
    struct q* next;
    // and a pointer to the previous element
    struct q* prev;
} REGTYPE;
// ##### Function declarations #####
REGTYPE* random_list(void);
REGTYPE* add_first(REGTYPE* temp, int data);
// ###### Main program #######
int main(int argc, char* argv[]) {
    int nr = 1;
    REGTYPE* act_post = NULL;
    REGTYPE* head = NULL;
    srand(time(0)); // Random seed
    head = random_list();
    act_post = head;
    while (act_post != NULL) {
        printf("\n Post nr %d : %d", nr++, act_post->number);
        if (act_post->prev != NULL) {
            printf(" THE NUMBER BEFORE WAS %d\n", act_post->prev->number);
        }
        act_post = act_post->next;
    }
    printf("\n");

    // Test the list again after inserting one node at the front.
    printf("Insert one node at start: \n");
    nr = 1;
    act_post = head;
    act_post = add_first(act_post, 999);

    while (act_post != NULL) {
        printf("\n Post nr %d : %d", nr++, act_post->number);
        if (act_post->prev != NULL) {
            printf(" THE NUMBER BEFORE WAS %d\n", act_post->prev->number);
        }
        act_post = act_post->next;
    }

    // --- Free the allocated memory ---
    while ((act_post = head) != NULL) { // Assign head to actual position, then check if its not null.
        head = act_post->next;
        free(act_post);
    }
    return 0;
}

// ==== End of main ======================================
REGTYPE* random_list(void) {
    // define the top, old and item pointers to REGTYPE
    REGTYPE* head = NULL;
    REGTYPE* current = NULL;
    REGTYPE* new = NULL;
    // loop through the list and add random numbers to the list for max times
    for (int i = 0; i < MAX; i++) {
        // generate a random number between 0 and 100
        int nr = rand() % 101;
        // assign memory
        new = malloc(sizeof(REGTYPE));
        // assing the news number to be the number we just made
        new->number = nr;
        // mark the next to be null for list traversal
        new->next = NULL;
        // if its first iter
        if (i == 0) {
            // make head the first elem
            head = new;
            // mark prev null
            head->prev = NULL;
        } else if (current != NULL) {
            // make the currents next to be new. Current isnt null in secodn iter and on cuz in first iter i set it to be new
            current->next = new;
            // so the nexts elemnt is the current to make it doubly linked
            new->prev = current;
        }
        // move the pointer to the next element basicaly
        current = new;
    }
    return head;
}
REGTYPE* add_first(REGTYPE* temp, int data) {
    // allocate memory for the new element
    REGTYPE* new_element = malloc(sizeof(REGTYPE));
    // assign the data to the number of the new element
    new_element->number = data;
    // assign the next pointer of the new element to the temp pointer
    new_element->next = temp;
    // assign the prev pointer of the new element to null
    new_element->prev = NULL;
    // assign the prev pointer of the temp pointer to the new element
    temp->prev = new_element;
    // return the new element
    return new_element;
}
