//Names: Ali Mousa Baqer Al-Muslim, Mehmet Asim Altinisik, Zepei Zhao
//Group number: 27
//Submssion code: 760MUG

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

//defining the max long value as a string
#define MAX_LONG_STRING "2147483647"
//fucntion to print dec2bin
void dec2bin(long number);
//function to check for argument validity
bool checkArgValidity(char *arg);

int main(int argc, char *argv[]){
    // Check if no arguments were provided
    if (argc < 2){
        printf("Please provide an arg\n");
        return 2;
    }
    //if the arguembnt is -h
    else if(strcmp(argv[1],"-h")==0){
        printf("provide exactly 1 argument (a non negative numberthats below 2147483647) after compiling the file for example ./a.exe 3498439\n");
        return 2;
    }
    // Check if the argument is valid
    else if (!checkArgValidity(argv[1])) {
        printf("Invalid argument. add -h for help");
        return 2;
    }
    
    // Initialize a pointer variable that points to a char. Needed by string to long function
    char *endptr;
    // Convert the string to a long integer. The base is 10 because the decimal number system is based on base 10
    //then pass the long to the function
    long num = strtol(argv[1], &endptr, 10);
    dec2bin(num);
}

// Function to check if the argument is a valid positive integer not larger than MAX_LONG
bool checkArgValidity(char *arg) {
    // Check if the argument is negative
    if(arg[0]=='-'){
        printf("Please provide a positive num\n");
        //retrun false if it is
        return false;
    }

    // Loop over each character in the argument
    for (int i = 0; i < strlen(arg); i++){
        char c = arg[i];
        // Check if the character is not a digit
        if(!isdigit(c)){
            printf("Your arg is either not a digit or is above max long val\n");
            //return false if its not a digit
            return false;
        }
    }
    //pointer needed for the strtol
    char *endptr;
    // Convert the string to a long integer. The base is 10 because the decimal number system is based on base 10
    long val = strtol(arg, &endptr, 10);

    // Check if the value is MAX_LONG and the argument is not equal to the string representation of MAX_LONG
    if(val==LONG_MAX && strcmp(MAX_LONG_STRING,arg)!=0){
        printf("Your arg is above max long val\n");
        //return false as they have provided somethung above the max
        return false;
    }

    // If all checks passed, return true
    return true;
}

void dec2bin(long number){
    //https://www.geeksforgeeks.org/count-total-bits-number/
    //taking base 2 of the number will return how many bits it has
    //if number is amx number then we cant increment it
    int addOne = (number == 2147483647) ? 0 : 1;
    // +1 is necessary because log2(1) = 0
    int unfilteredBits = (int)log2(number+addOne); 
    //nested ternanry operator to first check if its less than 8 otherwise it should be either 16 or 32
    int bits = unfilteredBits < 8 ? 8 : (unfilteredBits < 16 ? 16 : 32);
    //iteratre over the number of bits -1 to not go out of the rang eof bits
    for (int c=bits-1; c>=0; c--){
        //shift the current bit by c cahratcers to compare it to 1 and see if it is 1 ,or 0
        printf("%d", (number >> c) & 1);
    }
}