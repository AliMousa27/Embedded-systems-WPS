#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
#include <string.h>
//function delcartions
void swap(char* x, char* y);
void print_all_permutations(char* string, int start, int end, int *counter, char (*storage)[1000][strlen(string)]);

int main(int argc, char *argv[]){ 
    // no arg provided
    if(argc < 2 ){
        printf("invalid");
        return 0;
    }
    //get the word
    char *string = argv[1]; 
    //get the length
    int length = strlen(string); 
    //to not get huge amount of input
    if (strlen(string) > 6) {
        printf("invalid");
        return 0;
    }
    //https://stackoverflow.com/questions/36890624/malloc-a-2d-array-in-c
    //allocate 6 memory cells where each memory cell is an array of chars of lenght string 
    char (*storage)[1000][strlen(string)] = storage = malloc(sizeof(char[1000][length]));
    //intiate counter for how many words we have to iterate over and store in storage
    int counter =0;
    //ptr to counter
    int *counter_ptr = &counter;
    //finding everything and passing the string, 0 the length, counter and storage
    print_all_permutations(string, 0, length,counter_ptr,storage); 
    printf("all permutations of the string %s are:  ",string);
    //iterate over how many words we counted
    //start at 1 to skip the first word that we know
    for(int i=1; i<*counter_ptr; i++){
        //iterate over each words chars
        for(int j=0; j<length; j++){
            printf("%c",(*storage)[i][j]);
        }
        printf("  ");
    }
    // free the memory allocated for the 2d array
    free(storage);
    //return 0 for sucess
    return 0; 
}



//takes 2 pointers to 2 chars and swaps them
void swap(char* c1, char* c2) { 
    //declare a temp to store 1
    char temp; 
    //value of temp becomes that of c1
    temp = *c1; 
    //value of c1 pointer becomes vlaue of c2 pointer
    *c1 = *c2; 
    //c2 value becomes temp 
    *c2 = temp; 
} 
  
//string to create all permutations of, start index and end index
void print_all_permutations(char* string, int start, int end, int *counter,char (*storage)[1000][strlen(string)]) { 
    //base case. if they are equal means that theres nothing else to swap to permutate so we just print it
    if(start == end){
        //copy the value of the pointer of string into storage at element counter
        strcpy((*storage)[*counter], string);
        //increment the value of pointer
        (*counter)++;
        
    }
    else{
        //iterate over the start until the end of the current string
        for(int i=start; i < end; i++){
            //swap the characters by moving the pointer by + start and + i
            //this is done because we recursivly increase start AND iterativly increase i. Therefore we get the majority
            //of the permuatations that way. For example ABC, start is at A, swap A with A, then move start and add another call where start points to B
            //same thing with B swaps with B so nothing happens and same with C. Afterwards the base case is triggered, it prints the string and pops the call.
            //After that we restore original string and then move to the next call where i start is still 0 and points to A and i is 1 points to B so swap A and B
            //so on and so forth for each character 
            swap((string + start) ,(string + i));
            //recursivly call it and move the start for the next call in the stack
            print_all_permutations(string,start+1,end,counter,storage);
            //undoes the original swap to restore original string
            swap((string + start ),(string + i));
        }
    }
} 
