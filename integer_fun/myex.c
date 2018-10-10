#include <stdio.h>
#include <string.h>
int main(void){
    char max[] = "10asdf..."; // Have something like this, and keep appending to the string. After a while, it will grow super large! This could then have a length function, that could be overflown.
    short size = 32768;

    attack(max,size);
    return 0;
}

char* attack(char* buffer, int len){
    char copy_buf[10];

    printf("%i\n",len);
    if(len > (short) sizeof(copy_buf)){
        printf("Here?%i\n", len);
        return;
    }

    printf("%s\n","Attack!");
    return memcpy(copy_buf,buffer,len);
}

char* add_to_string(char* buffer, int len){

}
