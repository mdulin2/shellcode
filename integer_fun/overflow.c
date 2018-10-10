#include <stdio.h>

int main(void){
    int a = 0xffffffff; //maximum size
    int b = 0x1;
    int r = a + b;
    printf("%i\n",r); // r is 0!

    return 0;
}
