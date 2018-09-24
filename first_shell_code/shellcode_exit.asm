; nasm  -f elf(or os format) shellcode_exit.asm
; ld -o shellcode_exit  shellcode_exit.o
; objdump -d shellcode_exit
; op codes will be there!
; Gives off:
; 8048060:	bb 00 00 00 00       	mov    $0x0,%ebx
; 8048065:	b8 01 00 00 00       	mov    $0x1,%eax
; 804806a:	cd 80                	int    $0x80

Section 	.text
	global _start
_start:
	mov ebx, 0
	mov eax, 1
	int 0x80;
