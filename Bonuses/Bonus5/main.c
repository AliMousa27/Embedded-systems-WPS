#include <stdlib.h>
#include <stdio.h>

// type defination to make typing simpler. making byte between 0 and 256
typedef unsigned char byte;
// function definations. sets bits if engine is on
byte is_engine_on(byte current, int engine);
// sets bits for floor depending on number
byte get_floor(byte current, int floor);
// sets bits if door is open (1 or 0)
byte is_door_open(byte current, int door);
// sets bits if break1 is on (1 or 0)
byte break1(byte current, int break1);
// sets bits if break2 is on (1 or 0)
byte break2(byte current, int break2);
// main function
int main(int argc, char *argv[]) {
    // check if any arg is missing
    if (argc != 6) {
        printf("invalid");
        // exit program
        return 0;
    }
    // check validity of args and loop over themn. i starts at 1 to skip the program thats the first arg
    for(int i=1; i<argc; i++){
        // convert arg to int
        int num = atoi(argv[i]);
        // check if arg is not 0 or 1 and if its not the floor arg as all other args should be 0 or 1 but the floor
        if((num < 0 || num > 1) && i != 2){
            printf("invalid");
            // exit program
            return 0;
        }
        // check if floor arg is not between 0 and 7 and i is 2 as floor arg is the 3rd arg
        else if(i ==2 && (num < 0 && num > 7)){
            printf("invalid");
            // exit program
            return 0;
        }
    }
    // start with all 0 for this bit to be masked
    byte bits = 0b0000000;
    // convert args to int by position in argv (dont think i need to comment each one)
    int engine = atoi(argv[1]);
    int curr_floor = atoi(argv[2]);
    int door = atoi(argv[3]);
    int b1 = atoi(argv[4]);
    int b2 = atoi(argv[5]);
    // call functions to set bits
    bits = is_engine_on(bits,engine);
    bits = get_floor(bits,curr_floor);
    bits = is_door_open(bits,door);
    bits = break1(bits,b1);
    bits = break2(bits,b2);
    // print hex value of bits
    printf("0x%X", bits );
}
//all functions get teh current value of the byte and a value to change the byte 
byte is_engine_on(byte current, int engine){
    // if engfine is 1 then the right most gbitr of it is 1 so shift it all the way to the left and mask the current with it. if 0 then nothing happens
    return current | engine << 7;
}

byte get_floor(byte current, int floor){
    //create array of bytes with the bits in the right position for each floor
    byte bits_position[8] = { 0b00000000, 0b00010000, 0b00100000, 0b00110000, 0b01000000, 
    0b01010000, 0b01100000, 0b01110000 };
    //mask the current with the index of the floor
    return current | bits_position[floor];
}

byte is_door_open(byte current, int door){
    //shift the door bit to the left 2 times and mask the current with it
    return current | door << 2;
}

byte break1(byte current, int break1){
    //shift the break1 bit to the left 1 time and mask the current with it
    return current | break1 << 1;
}

byte break2(byte current, int break2){
    //mask the current with the break2 bit because break2 is the öast bit anyways so no shifitng needed
    return current | break2;
}

