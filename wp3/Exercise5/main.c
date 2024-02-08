#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10
#define MAX_NUM 100

void random_array(int* array_ptr);

int main(int argc, char* argv[]) {
    int* array = malloc(sizeof(int) * MAX);
    random_array(array);
    printf("The value of the address of the array (pointer) is: %p\n", array);
    printf("First integer in the array is (array[0]): %d\n", *array);
    printf("The last integer in the array is: %d\n", array[MAX - 1]);
    printf("The size of an integer (number of bytes) is: %d\n", sizeof(*array));
    printf("The size of the whole array in bytes is: %d\n", sizeof(*array) * MAX);
    for (int i = 0; i < MAX; i++) {
        printf("Integer: %d,  2 * Integer: %d\n", *array, *array * 2);
        array++;
    }
    free(array);
}

void random_array(int* array_ptr) {
    srand(time(NULL));
    for (int i = 0; i < MAX; i++) {
        int nr = rand() % MAX_NUM;
        *array_ptr = nr;
        array_ptr++;
    }
}