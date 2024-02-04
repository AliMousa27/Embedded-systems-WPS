#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BITS 32
//https://stackoverflow.com/questions/49829864/decimal-to-binary-using-bitwise-operator
char* toBinary(int num);
void printFormat(char binary[], int number);
int main(int argc, char *argv[]) {
    //if less than 2 args are provided means nothing was provided
    if(argc<2){
        printf("Error: No number provided. Please provide a number as a command line argument.");
        //program failed
        return 0;
    }
    //loop over the arguemnts length to check if its a string or not
    for (int i = 0; i < strlen(argv[1]); i++) {
        //if its not a digit then its an invalid arg
        if (!isdigit(argv[1][i])) {
            printf("Error: Invalid number.");
            //program failed
            return 0;
        }
    }
    int num = atoi(argv[1]);

    printf("The number is %d",num);
    char* res = toBinary(num);
    printFormat(res,num);
  return 0;
}

void printFormat(char binary[], int number){
    int numberOfZeros=0;
    int numberOfOnes=0;
    //pointer variable
    char *e;
    //index variable
    int index;
    //point it to the first instance of that letter. this will return the first instance of 1 and ignores all preceedings 0s
    e = strchr(binary, '1');
    for(int i=0; i<strlen(e);i++){
        if(e[i]=='1') {
            numberOfOnes++;
        } else{
            numberOfZeros++;
        }
    }
    printf("Number: %d\n",number);
    printf("Binary: 0b%s\n",e);
    printf("Number of 0s: %d\n",numberOfZeros);
    printf("Number of 1s: %d\n",numberOfOnes);
}


char * toBinary(int num) {
  //c keeps track of the cth bit to check for and result is the resulting shift to comapre with the 1 in binary
  int c, result;
  //declare the array of chars with bits +1 for terminating symbol
  char *binary = malloc((BITS+1) * sizeof(char));  
  //loop starts at numbher of bits -1 so 31, because if we shift all of the bits by 32 then we will always get a 0 no matter what for the first iteration
  for (c = BITS-1; c >= 0; c--){
      //when shifting, the bits at the left are replaced by 0 and therfreo we will always compare 0.......1|0 to 0 which always 0.....1 which will return 0 or 1
       result = num >> c;
       if(1 & result){
         //add the result to the start of the string as thats the bit we are checking
         binary[BITS-1-c]='1';
       }
       else{
        //otherwise the current bit is a 0
         binary[BITS-1-c]='0';
       }
  }
  
  //null terminating symbol
  binary[BITS]='\0';
  //return the string
  return binary;
}