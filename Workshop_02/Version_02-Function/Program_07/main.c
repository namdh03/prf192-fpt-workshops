#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void output(char c1, char c2, int d, int code) {
	printf("d = %d\n", d);
	
	for (code = c1 + 1; code < c2; code++) {
		printf("%c \t %d \t %o \t %X\n", code, code, code, code);
	}
}

void swap(char c1, char c2) {
	char temp;
	int d, code;
	
	if (c1 > c2) {
		temp = c1;
		c1 = c2;
		c2 = temp;
	}
	
	d = c2 - c1;
	
	output(c1, c2, d, code);
}

int main(int argc, char *argv[]) {
	char c1, c2;
	
	printf("Enter the 1st character: ");
	scanf("%c", &c1);
	fflush(stdin); 
	
	printf("Enter the 2nd character: ");
	scanf("%c", &c2);
	
	swap(c1, c2);
	return 0;
}
