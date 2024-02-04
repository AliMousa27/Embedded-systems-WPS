#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//define max elemtns in a given array
#define MAX_ELEMENTS 5
//define max word lenght for each word
#define MAX_WORD_LENGTH 100
// function defination that takes a 2d pointer to a char array and returns a 2d pointer to a char array
char** remove_shortest_element(char **words);
// main fucntion
int main(int argc, char *argv[]){
    // allovate max elemnts times size of a char in memeory
    char **words = malloc(MAX_ELEMENTS * (sizeof(char*)));
    // loop for max elemnts
    for(int i=0; i< MAX_ELEMENTS; i++){
        // allocate max word length * char in memory to each cell
        words[i] = malloc(MAX_WORD_LENGTH * sizeof(char*));
        printf("Enter the %d word\n",i+1);
        // scan the word in the array
        scanf("%s",words[i]);
    }
    
    printf("Array before removal:\n");
    //loop over array and print each word
    for(int i=0; i < MAX_ELEMENTS; i++){
        printf("%s\n",words[i]);
    }

    // call the function and pass the array
    words = remove_shortest_element(words);
    
    printf("Array after removal:\n");
    //loop over array and print each word
    for(int i=0; i < MAX_ELEMENTS; i++){
        printf("%s\n",words[i]);
    }
}

char** remove_shortest_element(char **words){
    // define a shortes index and set it to first elemtn initalluy
    int index_of_shortest = 0;
    // define a current shortest and set it to the length of the first word
    int current_shortest = strlen(words[0]);
    // loop over the array and find the shortest word
    for(int i=0; i < MAX_ELEMENTS; i++){
        //get lenght of current word
        int length = strlen(words[i]);
        // if length is shorter than the currnet shortest
        if(length < current_shortest){
            // assign the current length to the current shortest
            current_shortest = length;
            // assign the index of the current shortest to the index of the shortest
            index_of_shortest = i; 
        }

    }
    printf("Shortest string removed: %s\n", words[index_of_shortest]);

    // loop over the array and shift the elements to the left. We -1 freom max lements because the last element will be gone as we remove one lement from array
    // so the new max is max -1
    for(int i=index_of_shortest; i < MAX_ELEMENTS-1; i++ ){
        // copy the next element to the current element therofore efficctivly making the last element empty
        strcpy(words[i],words[i+1]);
    }

    // clear the last element. this works by giivng the addrtess of the last element to memset and setting 0 for max word length of bytes
    memset(words[MAX_ELEMENTS-1],0,MAX_WORD_LENGTH);
    // return pointer to the array
    return words;
}
