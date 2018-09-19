There is a particular way to go about this...

- The exit.c file is meant to let us see actual commands for an exit call, in assembly. Allows us to get a foothold on what the exit looks like.
- shellcode_exit.asm is the assembly we decided to use, given from the exit.c files break down. From here, we can find the opcodes, which can be used in assembly land.
- - The badass.c file is meant to test the shellcode itself.
