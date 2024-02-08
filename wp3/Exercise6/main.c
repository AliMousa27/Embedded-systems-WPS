#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20
void copy_string(char* ptr); // function to copy a string
void copy_string_using_lib(char input[]); // same function byt uses libs instead
void read_txt_file(); // function to read txt file
int main(int argc, char* argv[]) {
    // allocate memory of max +1 chars
    char input[MAX + 1]; //+1 to terminate
    // pass input to be copied into
    copy_string(input);
    printf("Your string is:  %s", input);
    // call the read text function
    read_txt_file();
}

void copy_string(char* ptr) {
    printf("Enter string\n");
    // define a char
    char c;
    // index to track length
    int i = 0;
    // loop to get chars or if I hits 20
    while ((c = getchar()) != '\n' && i < 20) {
        // assign value of pointer to value of c
        *ptr++ = c;
        // and increment i
        i++;
    }

    // terminate string
    *ptr = '\0';
}

void copy_string_using_lib(char ptr[]) {
    printf("Enter string\n");
    // define a temp variable
    char temp[MAX];
    // store terminal input in temp
    fgets(temp, MAX, stdin);

    // check if last char is new line
    if (temp[strlen(temp) - 1] == '\n') {
        // and replace it with null termianting
        temp[strlen(temp) - 1] = '\0';
    }

    // use the function to copy it to the pointer that we got
    strcpy(ptr, temp);
}

// on windows use Get-Content sample.txt | ./a.exe to get the contents of a file for a powershell terminal
// so get content makes the content of stdin the file name passed in
void read_txt_file() {
    // define a string of 1000s characters
    char str[1000];
    // copy the content of stdin into it
    fgets(str, sizeof(str), stdin);
    // print it
    printf("%s", str);
}