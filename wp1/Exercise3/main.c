//Guess the number game, program generates a random number between 1-100, and tells you if your guess is too low or too high, after game over it will ask you if you want to keep playing.
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUMBER 5 //Define constant for max number of tries the player gets/

bool isValidGuess(int* pguess); //Define the function for checking and validating input
void clearInput(); //Define the function to clear input buffer.
void confirm(bool* pkeepPlaying); //Define the function for asking the player if they want to keep playing.

int main(int argc, char* argv[]) { //Define main function
    int guessCount = 0; //Initialize variable for storing guess count
    int guess = 0; //Initialize variable for storing the player guess
    bool keepPlaying = true; //Initialize variable for controlling the main loop.
    srand(time(NULL)); //Seed the random number with time in seconds since January 1, 1970.
    int randomNum = rand() % 100 + 1; // get random number from 1 to 100.
    printf("%d\n", randomNum);

    while (keepPlaying) { //Main loop
        if(guessCount >= MAX_NUMBER){ //If all tries have been used up
            printf("You lost!\n");
            confirm(&keepPlaying); //
            randomNum = rand() % 100 + 1;
            guessCount = 0;
        }
        printf("%d tries left.\n", MAX_NUMBER-guessCount);
        guessCount++; //Increment the guessCount after each try
        if (isValidGuess(&guess)) { //Check if guess is a valid input.
            printf("%d\n", guess);
            if(guess == randomNum){ //If guess was correct.
                printf("You have guessed %d times and your guess is correct\n", guessCount);
                confirm(&keepPlaying); //Ask if player wants to play another round, sets the boolean variable.
                randomNum = rand() % 100 + 1;
                guessCount = 0;
            }else if(guess > randomNum){ //If guess was too high
                printf("Too high\n");
            }else if(guess < randomNum){ //If guess was too low
                printf("Too low\n");
            }

        } else { //If input was invalid
            printf("Invalid guess\n");

        }

    }

    return 0; //Return 0 means program executed successfully
}

bool isValidGuess(int* pguess) { // Function that takes in a pointer to the input address and check if input is valid.
    printf("Guess the number between 1-100: ");
    if (scanf("%d", pguess) == 0) { // If scanf fails to read an integer
        printf("Must be a number\n");
        clearInput(); //Clear the input buffer
        return false; //Invalid
    } else { //Input is a number
        if (*pguess < 1 || *pguess > 100) { //If input is outside the range
            printf("Number must be between 1-100\n");
            clearInput(); //Clear the input buffer
            return false; //Invalid guess
        }
    }
    clearInput(); //Clear the input buffer
    return true; //Valid
}

void clearInput() { // Clear any charcters left in the input buffer
    char temp; //Define temp variable
    while ((temp = getchar()) != '\n' && temp != EOF) { //Take chars out of the input buffer until it reaches new line or
    }
}

void confirm(bool* keepPlaying) { // Function that takes in a pointer to the boolean address determines if player wants to continue.
    char yesNo; // Declare a char for storing player input
    while (1) { //Loop while input is not Y or N, case insensitive.
        printf("Keep playing? (Y/N): ");
        scanf("%c", &yesNo); //Scan the input.
        yesNo = toupper(yesNo); //Convert input to upper case
        if (yesNo == 'Y') { //If user types Y or y
            *keepPlaying = true; //Set the boolean to true
            break; //Break out of the loop and continue with the main game
        } else if (yesNo == 'N') { //If user types N or n
            *keepPlaying = false; //Set the boolean to false
            exit(0); //Exit the program
        }
    }
}