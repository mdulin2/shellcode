main()
	{
		exit(0);
	}


/*
gcc -static -o exit exit.c
View the code for exit in gdb with disas _exit
   0x0806c941 <+0>:	mov    0x4(%esp),%ebx
=> 0x0806c945 <+4>:	mov    $0xfc,%eax
   0x0806c94a <+9>:	call   *0x80ea9f0
   0x0806c950 <+15>:	mov    $0x1,%eax
   0x0806c955 <+20>:	int    $0x80
   0x0806c957 <+22>:	hlt


What is actually happening here?
- 0x0806c941 is getting ready for an interrupt; it is moving the value on the stack into ebx(happens to be 0).
- 0x0806c945 is getting the interrupt code ready. Put this into eax.
- 0x0806c94a calls the interrupt.
- 0x0806c950 gets ready for next interrupt. Putting 1 into eax.
- 0x0806c955 runs interrupt.
- Halts the execution.


The exit call looks like for a minimal exit:
	xor ebx,ebx
	mov $0x1, %eax
	int $0x80
Which adds the interrupt type, then executes the interrupt.

Then run shellcode_exit.asm to figure out the opcodes.
31 db
b0 01
cd 80
*/
