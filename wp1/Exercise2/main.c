//Names: Ali Mousa Baqer Al-Muslim, Mehmet Asim Altinisik, Zepei Zhao
//Group number: 27
//Submssion code: 760MUG

#include <stdio.h> //included this libray for printing 
#include <string.h> // this library is used for strlen method ( it is for taking the length of string)
#include <stdlib.h> // for atoi, atoi is used for converting string to int
#include <ctype.h>  // included this for islower function so that we ccan check if the word is capital or not

void encrypt(int shift, char word[]); // this is needed so that program knows which methods exist after main

int main(int argc, char *argv[]) // argc counts the arguments and argv is the argument itself
{
    char word[100]; // defineng the characer length

    // atoi converts a string to integer, so provided number but as a string format gets converted into int
    int shift = atoi(argv[1]); 

    printf("Please enter a word to encrypt\n");
    while (scanf("%s", word) != EOF) // while scanned word is not EOF end the program
    {
        printf("Entered Word: %s\n", word);
        // shift is the argument that user enters while running the program
        //word is the word user has entered in the terminal
        // we are passing the values to the encrypt function
        encrypt(shift, word);

        printf("\n");

        printf("Please enter a word to encrypt\n");
    }
    return 0; // returning zero means that the program has executed successfully
}

// it recieves shift number that was given as argument and word that is given by the user
void encrypt(int shift, char word[])
{   // for loop for encrypting each and every letter of the word
    for (int i = 0; i < strlen(word); i++) 
    {
        char base = (islower(word[i])) ? 'a' : 'A'; // checking each letter if they are capital or not and assigning it to the base
        // https://stackoverflow.com/questions/1616706/how-to-get-characters-position-in-alphabet-in-c-language
        //  I was sarching for the ways to get letter indexes in alphabet and I found out that i could substract it by a to get index
        int index = word[i] - base; // substracting the each letter from the base to get the index in the alphabet  
        // adding shift to the index to create a new index and then turning it to char by adding the base then taking 
        // modulo so that the index can start from begining like a circular array
        word[i] = base + (shift + index) % 26; 
    }
    printf("Encrypted word: %s\n", word);
}