#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int code;
	
	for (code = 0; code < 256; code++) {	
		printf("%c \t %d \t %o \t %X \n", code, code, code, code);
	}
	
	system("pause");
	return 0;
}
