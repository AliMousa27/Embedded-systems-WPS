#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// define a max for hex
#define MAX 100
// type defination of byte from 0 to 255
typedef unsigned char byte;
// function protoypes. get hex takes in a char, a binary string, and a pointer to an index to be updated
int get_gear(int num);
int main(int argc, char* argv[]) {
    // if no arg is provided
    if (argc != 2) {
        printf("No arg provided");
        // exit the program
        return 0;
    }
    // declare a hex to store the arg in
    char hex[MAX];
    // copy argv into the hex string
    strcpy(hex, argv[1]);
    // https://stackoverflow.com/questions/29547115/how-to-convert-string-to-hex-value-in-c
    // give base 16 to the function so if provided AB its (A=10*16 + 11) = 171
    int num = (int)strtol(hex, NULL, 16);
    int engine_on = num >> 7;
    // shift the first 4 bits all the way to thre gith then & with 0b111 so that only the bits with 1 get turned on
    int gear = (num >> 4) & 0b111;
    // shift the first 2 bits all the way to thre gith then & with 0b11 so that only the bits with 1 get turned on
    int key = (num >> 2) & 0b11;
    // shift the first bit all the way to thre gith then & with 0b1 so that only the bits with 1 get turned on
    int b1 = (num >> 1) & 0b1;
    // & with 0b1 so that only the bits with 1 get turned on
    int b2 = num & 0b1;
    printf("Name         Value\n-------------------\n");
    printf("engine_on      %d\n", engine_on);
    printf("gear_pos       %d\n", gear);
    printf("key_pos        %d\n", key);
    printf("brake1         %d\n", b1);
    printf("brake2         %d\n", b2);
}