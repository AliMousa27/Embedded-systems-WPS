#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20
void copy_string(char* ptr);
void copy_string_using_lib(char input[]);
void read_txt_file();
int main(int argc, char* argv[]) {
    // char input[MAX + 1]; //+1 to terminate
    // copy_string_using_lib(input);
    // printf("Your string is %s", input);
    read_txt_file();
}

void copy_string(char* ptr) {
    printf("Enter string\n");
    char c;
    int i = 0;
    while ((c = getchar()) != '\n' && i < 20) {
        *ptr++ = c;
        i++;
    }
    if (i == 20) {
        printf("Too long lil bro\n");
        exit(1);
    }
    *ptr = '\0';
}

void copy_string_using_lib(char ptr[]) {
    printf("Enter string");
    char temp[MAX];
    fgets(temp, MAX, stdin);

    // Remove newline character if present
    if (temp[strlen(temp) - 1] == '\n') {
        temp[strlen(temp) - 1] = '\0';
    }
    if (strlen(temp) > MAX) {
        printf("Too long lil bro\n");
        exit(1);
    }
    strcpy(ptr, temp);
}

// on windows use Get-Content sample.txt | ./a.exe to get the contents of a file
// so get content makes the content of stdin the file name passed in
void read_txt_file() {
    char str[1000];

    fgets(str, sizeof(str), stdin);

    printf("%s", str);
}