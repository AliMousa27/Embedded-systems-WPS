#include <stdio.h>
#include <stdlib.h>
int search_number(int number, int tab[], int size);
void sort(int number, int tab[]);
void swap(int* x, int* y);

int main(int argc, char* argv[]) {
    int test[] = { 1, 2, 34, 5, 67, 3, 23, 12, 13, 10 };
    int test_num = search_number(34232, test, 10);
    printf("index of number is %d\n", test_num);
    sort(10, test);
    for (int i = 0; i < 10; i++) {
        printf("%d ", test[i]);
    }

    return 0;
}
// assume number is size
void sort(int number, int tab[]) {
    for (int i = 0; i < number; i++) {
        int smallest_index = i;
        for (int j = i; j < number; j++) {
            if (tab[j] < tab[smallest_index]) {
                smallest_index = j;
            }
        }
        swap(&tab[i], &tab[smallest_index]);
    }
}

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int search_number(int number, int tab[], int size) {

    for (int i = 0; i < size; i++) {
        int num = tab[i];
        if (num == number) {
            return i;
        }
    }
    return -1;
}
