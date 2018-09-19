main()
	{
		exit(0);
	}


/*
gcc -static -o exit exit.c
View the code for exit in gdb with disas _exit
The exit call looks like:
	xor ebx,ebx
	mov $0x1, %eax
	int $0x80
Which adds the interrupt type, then executes the interrupt.

Then run shellcode_exit.asm to figure out the opcodes.
31 db
b0 01
cd 80
*/
