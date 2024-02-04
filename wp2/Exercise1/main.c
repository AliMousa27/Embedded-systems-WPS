#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// defining the number of directions
#define NUMBER_OF_DIRECTIONS 4
// defining the maximum number of instructions
#define MAX_INSTRUCTIONS 100

// making a direction enum
enum DIRECTION {
    N,
    E,
    S,
    W
};
// function prototypes. Clear buffer is used to clear the buffer of the input
void clear_buffer();
// move is used to move the robot in the direction it is facing
void move(int* x_ptr, int* y_ptr, enum DIRECTION direction);
// turn is used to turn the robot in the direction it is facing
void turn(enum DIRECTION* direction_ptr);

// structure definition. has x and y coords and a direction
typedef struct {
    int xpos;
    int ypos;
    enum DIRECTION dir;
} ROBOT;
// main function
int main(int argc, char* argv[]) {
    // array to hold the instructions
    char instructions[MAX_INSTRUCTIONS];
    // char to hold the current instruction
    char c;
    do {
        // creating a robot
        ROBOT robot;
        // setting the default direction to north
        robot.dir = N;
        printf("Enter the starting x coordinate: \n");
        // getting the x coordinate and checking if it is valid
        int result = scanf("%d", &robot.xpos);
        // if the result is not 1 or the x coordinate is not between 0 and 99 then its invalid
        if (result != 1 || robot.xpos < 0 || robot.xpos > 99) {
            printf("Invalid input\n");
            // clearing the buffer
            clear_buffer();
            // skip the iteration to get new input
            continue;
        }
        printf("Enter the starting y coordinate: \n");
        // getting the y coordinate and checking if it is valid
        result = scanf("%d", &robot.ypos);
        // same thing as the previous if statmement
        if (result != 1 || robot.ypos < 0 || robot.ypos > 99) {
            printf("Invalid input\n");
            // clearing the buffer
            clear_buffer();
            // skip the iteration to get new input
            continue;
        }
        // clearing the buffer
        clear_buffer();
        printf("Enter instructions:\n");
        // getting the instructions
        scanf("%s", instructions);
        // looping through the instructions
        for (int i; i < strlen(instructions); i++) {
            // getting the current instruction
            c = instructions[i];
            // if its move
            if (c == 'm') {
                // move the robot in the direction it is facing
                move(&robot.xpos, &robot.ypos, robot.dir);
                // if its turn
            } else if (c == 't') {
                // turn the robot and give the current direction
                turn(&robot.dir);
                // if its quit
            } else if (c == 'q') {
                // break out of the loop and enter the while loop again to cvheck if is q which it is
                break;
            } else {
                printf("invalid char %c\n", c);
            }
        }
        printf("x: %d, y: %d\n", robot.xpos, robot.ypos);
        printf("c is %c\n", c);
        // while c is not q whihc is the exit char
    } while (c != 'q');
}
// moves the robot in the direction it is facing. Takes in the x and y coordinates and the direction
void move(int* x_ptr, int* y_ptr, enum DIRECTION direction) {

    // depedning on direction robot changes its x and y
    switch (direction) {
    // if north
    case N:
        // increment y and mod it by 100 to stay within the allowed bounds
        *y_ptr = (++*y_ptr) % 100;
        // break out of the switch
        break;
    // if east
    case E:
        // increment x and mod it by 100 to stay within the allowed bounds
        *x_ptr = (++*x_ptr) % 100;
        // break out of the switch
        break;
    case S:
        // decrement y and check if it is greater than 0 to stay within the allowed bounds
        if (*y_ptr > 0)
            --*y_ptr;
        // break out of the switch
        break;
    case W:
        // decrement x and check if it is greater than 0 to stay within the allowed bounds
        if (*x_ptr > 0)
            --*x_ptr;
        // break out of the switch
        break;
    }
}
// turns the robot in the direction it is facing. Takes in the direction
void turn(enum DIRECTION* direction_ptr) {
    // increment the direction and mod it by the number such that it loops back to the start
    *direction_ptr = (++*direction_ptr) % NUMBER_OF_DIRECTIONS;
}
// clears the buffer
void clear_buffer() {
    // declare int to hold the character
    int c;
    // while the character is not a new line or end of file, bascailly eats all the input until it reaches a new line or end of file
    while ((c = getchar()) != '\n' && c != EOF) { }
}