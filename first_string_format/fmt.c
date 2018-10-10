#include <stdio.h>
#include <stdlib.h>
/*
Good string formats to know:
- %x: Shows the values on the stack in hexadecimal form
-


*/
int main( int argc, char *argv[]){
	char str[] = "Password";	
	printf(argv[1]);
	printf("\n");
	return 0;
}

/*
String formating in C has major, major issues...
If you give it a format string, then it will just give you the piece of information that you ask for! 

A likely payload to view the information on the stack 
./fmt "AAAAAAAAAAAAAAAA %x %x %x %x %x %x %x %x %x %x%x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %d"

To grab a particular value from the stack, use ./fmt "%4\$x"
*/
