#include <stdio.h>
#include <stdlib.h>
// function defination to search a number in an array (linear search)
int search_number(int number, int tab[], int size);
// sort function defination that uses sleection sort algoirthm
void sort(int number, int tab[]);
// swaps 2 integers
void swap(int* x, int* y);

int main(int argc, char* argv[]) {
    // defining an array of integers
    int test[] = { 1, 2, 34, 5, 67, 3, 23, 12, 13, 10 };
    // calling the search function and printing the index of the number will return  -1 if not in array
    int test_num = search_number(34232, test, 10);
    printf("index of number is %d\n", test_num);
    // sorts the array and prints the sorted array. Gives 10 as the size of the array
    sort(10, test);
    // printing the sorted array
    for (int i = 0; i < 10; i++) {
        printf("%d ", test[i]);
    }
    // return 0 to indicate success
    return 0;
}
// assume number is size
void sort(int number, int tab[]) {
    // loop over the array
    for (int i = 0; i < number; i++) {
        // define them smallest index as the index of the ith elemnt to not have to swap in correct elemnts
        int smallest_index = i;
        // loop over the array and find the smallest element
        for (int j = i; j < number; j++) {
            // if the current element is smaller than the smallest element
            if (tab[j] < tab[smallest_index]) {
                // assign the current index to the smallest index
                smallest_index = j;
            }
        }
        // give the addreses to the numbers to swap
        swap(&tab[i], &tab[smallest_index]);
    }
}

void swap(int* x, int* y) {
    // make temp to store the value of x
    int temp = *x;
    // assing x to y
    *x = *y;
    // assing y to temp which is x
    *y = temp;
}

int search_number(int number, int tab[], int size) {
    // loop over the array
    for (int i = 0; i < size; i++) {
        // get the current number
        int num = tab[i];
        // if the number is found return the index
        if (num == number) {
            // return the index
            return i;
        }
    }
    // if not found return -1
    return -1;
}

/* we werent sure which one you wanted but heres also bubble sort
void bubble_sort (int number, int tab []){
    for(int i =0; i < number-1; i++){
        for(int j =i+1; j <number; j++){
            if(tab[i]>tab[j]){
                int temp= tab[i];
                tab[i] = tab[j];
                tab[j]= temp;
            }
        }
    }
    printf("Sorted Array: ");
    for(int i =0 ; i < number; i++){
        printf("%d ", tab[i]);
    }
    printf("\n");
}*/