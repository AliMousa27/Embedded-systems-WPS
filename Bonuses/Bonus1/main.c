#include <stdio.h>
#include <string.h>
// Main function in the program, no program arguments supported
int main (int argc, char *argv[]) {
    //storing length of the arg
    //if only 1 arg is provided then its just the path to the program and no further args are provided
    if(argc == 1){
        printf("No command line argument provided, please provide a name.");
        return 0;
    }
    int len = strlen(argv[1]);
    //checking if its bigger than max
    if(len > 50){
        printf("Name too long, max 50 characters");
    }//checking if its less than min
    else if(len < 3){
        printf("Name too short, min 3 characters");
    }
    //otherwise its ok to be printed
    else{
    printf("Hello %s, how is your day today?", argv[1]);
    }
    //program executed succesfully
    return 0;
}


