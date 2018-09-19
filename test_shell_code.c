/*
How to test shell code that is being written. 
gcc -o badass badass.c -fno-stack-protector -z execstack -no-pie -m32
./badass to see the results
*/

char shellcode[] = "\xbb\x00\x00\x00\x00"
                    "\xb8\x01\x00\x00\x00"
                    "\xcd\x80";

typedef int(*shellcode_t)();

int main()
{
    shellcode_t ret = (shellcode_t)shellcode;
    ret();
}
