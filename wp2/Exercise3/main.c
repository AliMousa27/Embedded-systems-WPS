#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MENU_OPTIONS_LENGTH 5
// -----typedefs -------
typedef struct {
    char firstname[20];
    char famname[20];
    char pers_number[13]; // yyyymmddnnnc
} PERSON;
// Function declaration (to be extend)
PERSON input_record(void); // Reads a person’s record.
void write_new_file(PERSON* inrecord); // Creates a file and
// writes the first record
void printfile(void); // Prints out all persons in the file
// added parameter to know which one to search by
void search_by_first_or_last(char* name, bool search_by_firstname); // Prints out the person if
void append_file(PERSON* inrecord); // appends a new person to the file
int main(int argc, char* argv[]) {
    // int c to store choice
    int c;
    // char arrays to store the name
    char fname[20];
    // store fam name
    char famname[20];
    // store personnummer
    char personnummer[13];
    // menu options lsit to iterate over
    const char* MENU_OPTIONS[5] = {
        "Create a new and delete the old file.",
        "Add a new person to the file.",
        "Search for a person in the file.",
        "Print out all in the file.",
        "Exit the program."
    };
    // do while loop. to choose options
    do {
        printf("Choose your option\n");
        // iterate over the menu options and print them
        for (int i = 0; i < MENU_OPTIONS_LENGTH; i++) {
            printf("%d. %s\n", (i + 1), MENU_OPTIONS[i]);
        }
        // get the choice
        scanf("%d", &c);
        // switch case to see the input
        switch (c) {
        // if the choice is 1
        case 1:;
            // create a dummy person
            PERSON dummy_data = { "Ali\0", "Mousa\0", "Notgivingit" };
            // write dummy data to file
            write_new_file(&dummy_data);
            // break out of the switch case
            break;
        case 2:;
            printf("Write your first name, family name, and personummer\n");
            // allocate memory to a new person
            PERSON* data = malloc(sizeof(PERSON));
            // get the input
            scanf("%s %s %s", data->firstname, data->famname, data->pers_number);
            // forward data to append file function
            append_file(data);
            // break out of the switch case
            break;
        case 3:;
            // ask the user if they wanna search by first or last name
            int choice;
            printf("Search by first name or last name? type 0 for first name or 1 for last name\n");
            // get the choice
            int result = scanf("%d", &choice);
            printf("result %d\n", result);

            while (getchar() != '\n')
                ; // clear the buffer
            // if the choice is not 0 or 1 or the result is not 1 then its invalid
            if ((choice != 0 && choice != 1) || result != 1) {
                printf("Invalid input\n");
            } else {
                // allocate memory for the name
                char* name = malloc(sizeof(char) * 20);
                printf("Provide a name to search with\n");
                // get the name
                scanf("%s", name);

                printf("Searching for %s\n", name);
                // forward the name and choice to the search function
                search_by_first_or_last(name, choice == 0);
            }
            // break out of the switch case
            break;
        case 4:
            // print the file
            printfile();
            // break out of the switch case
            break;
        case 5:
            printf("Exit the program.\n");

            // break out of the switch case
            break;
        // default case for unrecognized input
        default:
            printf("Invalid option\n");
        }
        // while c isnt case 5 which is exit
    } while (c != 5);
    // return 0 to exit the program
    return 0;
}

// create a new file and write the first record
void write_new_file(PERSON* inrecord) {
    // creat a file ptr
    FILE* fileptr;
    // open the file in write mode and assign it to the file ptr and also check if it was successful
    if ((fileptr = fopen("people.dat", "w")) == NULL) {
        printf("\n Can not create the file");
        // exit with error code 1
        exit(1);
    }
    // write the record to the file
    fwrite(inrecord, sizeof(PERSON), 1, fileptr);
    // close the file
    fclose(fileptr);
}
// appends a new person to the file
void append_file(PERSON* inrecord) {
    // create a file ptr
    FILE* fileptr;
    // open the file in append mode and assign it to the file ptr and also check if it was successful
    if ((fileptr = fopen("people.dat", "a")) == NULL) {
        printf("\n Can not create the file");
        // exit with error code 1
        exit(1);
    }
    // write the record to the file
    fwrite(inrecord, sizeof(PERSON), 1, fileptr);
    // close the file
    fclose(fileptr);
}

// search for a person in the file. It takes in the name and a bool to know if its first or last name
void search_by_first_or_last(char* name, bool search_by_firstname) {
    // create a file ptr
    FILE* fileptr;
    // open the file in read mode and assign it to the file ptr and also check if it was successful
    if ((fileptr = fopen("people.dat", "r")) == NULL) {
        printf("\n Can not create the file");
        // exit with error code 1
        exit(1);
    }
    // create a person to store the data
    PERSON person;
    // while we can read from the file. The fread function continues to read each record until it reaches the end of the file
    while (fread(&person, sizeof(PERSON), 1, fileptr)) {
        // if the search by first name is true and the name matches the first name then print it
        if (search_by_firstname && strcmp(name, person.firstname) == 0) {
            printf("first name: %s last name: %s personnumer: %s\n", person.firstname, person.famname, person.pers_number);
            // if the search by first name is false and the name matches the last name then print it
        } else if (!search_by_firstname && strcmp(name, person.famname) == 0) {
            printf("first name: %s last name: %s personnumer: %s\n", person.firstname, person.famname, person.pers_number);
        }
    }
    // close the file
    fclose(fileptr);
}
// prints out all persons in the file
void printfile(void) {
    // create a file ptr
    FILE* fileptr;
    // open the file in read mode and assign it to the file ptr and also check if it was successful
    if ((fileptr = fopen("people.dat", "r")) == NULL) {
        printf("\n Can not create the file");
        // exit with error code 1
        exit(1);
    }
    // create a person to store the data
    PERSON person;
    // while we can read from the file. The fread function continues to read each record until it reaches the end of the file
    while (fread(&person, sizeof(PERSON), 1, fileptr)) {
        printf("first name: %s last name: %s personnumer: %s\n", person.firstname, person.famname, person.pers_number);
    }
    // close the file
    fclose(fileptr);
}