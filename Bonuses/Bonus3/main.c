#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
//define global variables that need to be passed into functions in order to not deal with double pointers
int rows, columns;
//funnction to clear the buffer
void clear_buffer();
//function to read the input and store it in the input array
void append_to_input_array(char input[], char c);
// function to read the input and store it in the input array. Returns the position of the pointer for the second list to be populated
int *populate_input_list();
// function to populate the matrx
void *populate_matrices(int matrix[rows][columns],int rows, int columns, int *elements_ptr);
//function to add 2 matrices and sum them
void add_matrices(int matrix_one[rows][columns], int matrix_two[rows][columns],int result_matrix[rows][columns]);
//function to print the matrix
void print_matrix(int matrix[rows][columns]);
//function to check if the sizes are valid regarding the input and rows and columns
void check_size(int *input_list);
//main function
int main(int argc, char *argv[]){

    printf("Enter the sizes: ");
    //read into input rows and columns golbals
    scanf("%d %d", &rows, &columns);
    //clear the buffer
    clear_buffer();
    //declare pointer that will point to the list of numbers that will be populated
    int *list_of_numbers = populate_input_list();
    //check if the rows and columns are valid
    if(rows <= 1 || columns <= 1){
        printf("invalid");
        //return 0 to exit the program
        return 0;
    }
    //check if the size of the input is valid regarding the rows and columns
    check_size(list_of_numbers);
    printf("\n");
    //declare matrix 1
    int matrix_one[rows][columns];
    //declare matrix 2
    int matrix_two[rows][columns];
    //populate the matrix 1 and move the pointer of the lsit of numbers to where the second matrix should start
    list_of_numbers = populate_matrices(matrix_one, rows, columns, list_of_numbers);
    //populate the matrix 2
    list_of_numbers = populate_matrices(matrix_two, rows, columns, list_of_numbers);
    //declare the result matrix
    int result[rows][columns];
    //add the matrices
    add_matrices(matrix_one, matrix_two, result);
    printf("The sum is:\n");
    //print the result
    print_matrix(result);
    //return 0 to exit the program
    return 0;

}

// function to check if the sizes are valid regarding the input and rows and columns
void check_size(int *input_list){
    // counter to count the number of elements in the list
    int counter = 0;
    //iterate through the list and count the number of elements. 
    //loop stops at the memory cell thats equal to INT_MAX thats defined later on in the program
    while(*input_list != INT_MAX){
        // increment the pointer to the next memory cell
        input_list++;
        //increment the counter
        counter++;
    }
    //if the number of elements is not equal to rows * columns * 2 then the input is invalid
    if(counter != (rows * columns * 2)){
        printf("invalid");
        //exit the program
        exit(0);
    }
}

//function to add 2 matrices and sum them
void add_matrices(int matrix_one[rows][columns], int matrix_two[rows][columns],int result_matrix[rows][columns]){
    //iterate through rows
    for(int i=0; i< rows; i++){
        //iterate through columns
        for(int j=0; j<columns;j++){
            //add the elements of the 2 matrices and store them in the result matrix
            result_matrix[i][j] = matrix_one[i][j] + matrix_two[i][j];
        }
    }
}

void print_matrix(int matrix[rows][columns]){
    //iterate through rows
    for(int i=0; i< rows; i++){
        //iterate through columns
        for(int j=0; j<columns;j++){
            //print the element
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

//returns the position of the pointer for the second list to be populated
void *populate_matrices(int matrix[rows][columns],int rows, int columns, int *elements_ptr){
    //iterate through rows
    for(int i=0; i< rows; i++){
        //iterate through columns
        for(int j=0; j<columns;j++){
            //populate the matrix with the elements of the list
            matrix[i][j] = *elements_ptr;
            //increment the pointer to the next memory cell of the input list
            elements_ptr++;
        }
    }
    //return the pointer to the next memory cell of the input list so that the second matrix can be populated starting from there
    return elements_ptr;
}

// function to read the input and store it in the input array
void read_input(char input[]){
    //declare the char that will be read
    int c;
    //read the input until the end of the line or the end of the file
    while((c = getchar()) != '\n'&& c != EOF){
        //append the char to the input array
        append_to_input_array(input, (char)c);
    }
}


int *populate_input_list(){
    //initalize the array 
    char input[100] = "";
    printf("Enter the first matrix: ");
    //read the input
    read_input(input);
    //append a space to the input array so that the second list can be populated without issues
    append_to_input_array(input, ' ');
    printf("Enter the second matrix: ");
    //again read the input of the second matrix
    read_input(input);
    //check if the input is valid by looping over each char
    for(int i=0; i<strlen(input); i++){
        //if the char is not a digit or a space or a minus sign then the input is invalid
        if(!isdigit(input[i]) && input[i] != ' ' && input[i] != '-'){
            printf("invalid");
            //exit the program
            exit(0);
        }
    }

    //allocate memory for the list of numbers thats equal to size of 1 intger * the length of the input divided by 2 because there are spaces between each number
    int *integer_array = malloc((strlen(input)/2) * sizeof(int));
    //declare pointer that will point to the input array
    char * ptr;
    //declare pointer that will point to the current position of the integer array so that we save the integer array pointer
    //to return later on
    int *current_position = integer_array;
    //split by space and declare pointer to the first token
    ptr = strtok (input," ");
    //loop over the tokens
    while (ptr != NULL){
        //convert the token to integer and store it in the current position of the integer array
        *current_position = atoi(ptr);
        //increment the pointer to the next memory cell
        current_position++;
        //giving null tells it to continue tokenizing the string
        ptr = strtok (NULL, " \n");
    }
    //set the last element of the integer array to INT_MAX so that we know where the list ends
    *current_position = INT_MAX;
    //return the pointer pointing to the first element of the integer array
    return integer_array;
}

void append_to_input_array(char input[], char c){
    //get the length of the input array
    int len = strlen(input);
    //append the char to the end of the input array
    input[len] = c;
    //terminate the string
    input[len+1] = '\0';
}


//function to clear the buffer
void clear_buffer() {
    //declare the char that will be read
    int c;
    //read the input until the end of the line or the end of the file and discard them
    while ((c = getchar()) != '\n' && c != EOF);
}
