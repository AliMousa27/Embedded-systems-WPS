//Names: Ali Mousa Baqer Al-Muslim, Mehmet Asim Altinisik, Zepei Zhao
//Group number: 27
//Submssion code: 760MUG
//icnluding the printing lib
#include <stdio.h>
//include bool for fucntion
#include <stdbool.h>
// defining first sentence
#define sentence1 "This is sentence 1\n"
// defining second sentence
#define sentence2 "This is sentence 2\n"
// defining third sentence
#define sentence3 "This is sentence 3\n"
// defining fourth sentence
#define sentence4 "This is sentence 4\n"
// defining fifth sentence
#define sentence5 "This is sentence 5\n"
//defining a function that takes in a pointer
bool isValid(int* pointer);
//standard main function
int main(int argc, char *argv[]){
    //declaring input int
    int input;
    //while loop gives memory address to the function where the loop will only exit if the input is correct
    while(!isValid(&input)){}
    //switch takess the integer input
    switch (input){
        //if input is 1
        case 1:
        printf(sentence1);
        //mandatory break as a good practice learned frm the oop course
        break;
        //if input is 2
        case 2:
        printf(sentence2);
        //mandatory break as a good practice learned frm the oop course
        break;
        //if input is 3
        case 3:
        printf(sentence3);
        //mandatory break as a good practice learned frm the oop course
        break;
        //if input is 4
        case 4:
        printf(sentence4);
        //mandatory break as a good practice learned frm the oop course
        break;
        //if input is 5
        case 5:
        printf(sentence5);
        //mandatory break as a good practice learned frm the oop course
        break; 
    }
    return 0;
}
//function takes pointer and return a bool
bool isValid(int* pointer){
    printf("Enter a number between 1-5:\n");
    //scan the input and convert value to int. Note its not made to error handle
    scanf("%d", pointer);
    //notify the user provides incorrect input
    if(*pointer < 1 || *pointer > 5){
        printf("Invalid input. Please type a number between 1 and 5\n");
    }
    //return the valid conditon 
    return *pointer <= 5 && *pointer >= 1;
}
