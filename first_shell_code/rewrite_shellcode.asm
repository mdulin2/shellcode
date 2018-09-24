; nasm  -f elf(or os format) rewrite_shellcode.asm
; ld -o rewrite_shellcode  rewrite_shellcode.o
; objdump -d rewrite_shellcode
; op codes will be there!


;the rewrite step... How do get opcodes with nulls in it?

Section 	.text
	global _start
_start:
	xor ebx, ebx ; replaced mov ebx,0. Obviously, eax, 0 has a null byte
	mov al, 0x1 ; replaced mov eax, 1. This needs to have an al because eax has 4 bytes, but only places 1. So, other null bytes are brought in to compensate. al is the first 8 bites of the register.
	int 0x80;

;; gives the output in opcodes
; 31 db
; b0 01
; cd 80
