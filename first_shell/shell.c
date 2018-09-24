/*
gcc -static -o shell shell.c
./shell to get a shell spawned.
But, we need to get the opcodes from this!
How to do this:

gcc shell.c -c
objdump -D shell.o
*/

#include <stdio.h>
int main() {
	char *happy[2];
	happy[0] = "/bin/sh";
	happy[1] = NULL;
	execve(happy[0],happy, NULL);
}

/*
How to view a built in function in assembly?
- __execve shows the execute function.
What does the execve actually look like in C?

int execve(const char* filename, char *const argv[], char *const envp[]);

-filename can either be a binary executable or a string.
-argv is an array of arguement strings passed to the new program.
-Envp is an array of strings conventionallty of the form key=value. Must be terminated by a null pointer; this and argv.

Parameters are put into eax-edx. The interrupt number is 11, or 0xb.

There are many intriacies to this...
The function takes in pointers. So, we must have addresses already known...But how is this possible!

Well, people are really clever. So, there is a flow that has been created for this:

	jmp short GoToCall

shellcode:
	pop esi
	...
	shellcode...
	...

GoToCall:
	Call shelcode
	Db '/bin/sh'


The magic...
- esi now has the address of /bin/sh in it! The 'pop esi' pops the returned address. Because the next instructino is the '/bin/sh', we have the address of bin/sh.
- This defeats the relative addressing problem...
*/
