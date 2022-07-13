#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char c1, c2, temp;
	int d, code;
	
	printf("Enter the 1st character: ");
	scanf("%c", &c1);
	fflush(stdin); 
	
	printf("Enter the 2nd character: ");
	scanf("%c", &c2);
	
	if (c1 > c2) {
		temp = c1;
		c1 = c2;
		c2 = temp;
	}
	
	d = c2 - c1;
	
	printf("d = %d\n", d);
	
	for (code = c1 + 1; code < c2; code++) {
		printf("%c \t %d \t %o \t %X\n", code, code, code, code);
	}
	return 0;
}
