// (C) Ali Mousa Baqer Al-Muslim, Mehmet Asim Altinisik, Zepei Zhao, group: 27 (2024)
// Work package 0
// Exercise 1
// Submission code: 691706413 (provided by your TA-s Sushant)
#include <stdio.h>
#include <string.h>
// Main function in the program, no program arguments supported
void main (int argc, char *argv[]) {
    //argc by default is 1 as it recives the name of the program as the first argument
    //therefore if its 1 then no arguments were provided
    if(argc == 1){
        printf("Error, no arguments were provided\n");
        printf("Use -h for help.\n");
    }
    //if argc is more than 2 means we have provided more than 1 arg
    else if(argc > 2) {
        printf("Error more than one argument provided\n");
        printf("Use -h for help.\n");
    }
    //if the string comparcent is exactly = 0 then the 2 strings are equal, meaning they provided -h as arg
    else if(strcmp(argv[1], "-h") == 0){
        printf("provide exactly 1 argument (a name) after compiling the file for example ./a.exe Miroslaw\n");
    }
    //else we provided exactly 1 arg
    else{
        printf("Hello World! - I'm %s!\n", argv[1]);
    }
}