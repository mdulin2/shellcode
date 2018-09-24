
/*
How to compile this so that there is no seg fault on x86:
gcc -o badass badass.c -fno-stack-protector -z execstack -no-pie -m32
./badass to see the results
In order to actually see the exit codes, run strack ./badass

Found this at: https://gist.github.com/securitytube/5318838
*/

// Exit op codes! If the 0x01 is changes to fc, then it will exit group instead.
char shellcode[] = "\xbb\x00\x00\x00\x00"
                    "\xb8\x01\x00\x00\x00"
                    "\xcd\x80";

// This initially did not work... Not entirely sure why! But, it works now; life goes on! These two shellcodes do the same thing. The only difference is that one is usable in an injection, while the other will likely not because of the null bytes in there. 
char shellcode_shorten[] = "\x31\xdb"
                    "\xb0\x01"
                    "\xcd\x80";

typedef int(*shellcode_t)();

int main()
{
    shellcode_t ret = (shellcode_t)shellcode_shorten;
    ret();
}
