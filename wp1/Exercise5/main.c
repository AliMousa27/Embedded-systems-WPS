//Names: Ali Mousa Baqer Al-Muslim, Mehmet Asim Altinisik, Zepei Zhao
//Group number: 27
//Submssion code: 760MUG

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100 // Defines the maximum number of the values in the table
#define MAXNUMBER 20 // Defines the maximum value of random numbers
#define USABLE_MAXNUMBER MAXNUMBER+1 // +1 because c starts at index 0
// ------ Function declarations ----------
// This function generates a set of random numbers
// and fills the table *tab with these numbers
void create_random(int *tab );
// This function takes the *tab of random numbers
// and creates a table with the frequency counts for these numbers
void count_frequency(int *tab, int *freq );
// This function takes the frequency count table
// and draws a histogram of the values in that frequency table
void draw_histogram(int *freq );
// ------ Function definitions ----------
// ------ Main --------------------------
// The main entry point for the program
//
// If you choose to go for the optional part
// Please modify it accordingly
int main (void){
    // initalize the table with max elemtns in the array 
    int table[MAX];
    //initlaize frequency array with max number of elemnts
    int frequency[USABLE_MAXNUMBER];
    //pointer to first elemtn of table
    int* tablePTR = table;
    //pointer to first element of frequency
    int* freqPointer = frequency;
    //populate table with random, numbers and send in by value tableptr
    create_random(tablePTR);
    //count the populated table and send pointers by refrence
    count_frequency(tablePTR,freqPointer);
    //finally draw it from the freq pointer
    draw_histogram(freqPointer);

}

void create_random(int *table ){
    //initalize seed
    srand(time(NULL));
    //loop over required number of elemtns   
    for(int i=0; i < MAX; i++){
        //create random number and modulo max to get numbers within the desired range
        int r = rand()%USABLE_MAXNUMBER; 
        //dereference the pointer and assign it to the value of the number
        *table = r;
        //printing numebrs to verify the counting is correct
        printf("%d, ",*table);
        //increment pointer to go to next memory cell
        table++;
    }
    printf("\n");
}

void count_frequency(int *table, int *freq){   
    // create a temporary pointer that points to the same pointer
    int *temp_freq = freq; 
    //loop over maxnumber as thats the size of the freq array
    for (int i = 0; i < USABLE_MAXNUMBER; i++) {
        //assign it 0
        *temp_freq = 0;
        //move to next block
        temp_freq++;
}
    //save the starting frequency place in a variable to return to
    int* start_freq = freq;
    //loop over ax as thats the size of the table
    for(int i=0; i < MAX; i++){
        //get the number by dereferncing the table pointer
        int number = *table;
        //Heres the bulk of the algorithm. Freq  table has index where each index coresponds to how many there are. This works because the table
        //will ever have a max number in a given number in the array and the size of the freq table is max number so we can use indices as the key and the value is how many times
        //we encounter them
        freq = freq+number;// move pointer to the required index
        //increment the value the pointer points to
        ++*freq;
        //reset the pointer to the start of the freq table   
        freq = start_freq; 
        //increment the table pointer to go to the next memory cell
        table++;
    }
}



void draw_histogram(int *freq ){
    //loop over the max number as thats the size of the freq table
    for(int i=0; i < USABLE_MAXNUMBER; i++){
        //if the value is not 0 then print it
        if(*freq != 0){
            printf("%d ",i);
            //loop over the value of the pointer to print the number of stars
            for(int j = 0; j<*freq; j++){
                printf("X");
            }
                printf("\n");
            }
        //increment the pointer to go to the next memory cell
        freq++;
    }
}
