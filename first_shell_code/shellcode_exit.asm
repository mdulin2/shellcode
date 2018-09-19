; nasm  -f elf(or os format) shellcode_exit.asm
; ld -o shellcode  shellcode_exit.o
; objdump -d shellcode_exit
; op codes will be there!

Section 	.text
	global _start
_start:
	mov ebx, 0
	mov eax, 1
	int 0x80; 
