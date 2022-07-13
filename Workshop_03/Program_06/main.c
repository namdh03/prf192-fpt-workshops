#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int isFibonacci(int n) {
	int firstNumb = 1, secondNumb = 1;
	int fib = 1;
	
	if (n == 1) {
		return 1;
	}
	
	while (fib < n) {
		fib = firstNumb + secondNumb;
		firstNumb = secondNumb;
		secondNumb = fib;
		
		if (n == fib) {
			return 1;
		}
	}
}

int main(int argc, char *argv[]) {
	int n;
	char c;
	
	do {
		system("cls");
		printf("Enter a positive integer: ");
		fflush(stdin);
	} while ((scanf("%d%c", &n, &c) != 2 || c != '\n') || n <= 0);
	
	if (isFibonacci(n) == 1) {
		printf("It is a Fibonacci element\n");
	}
	else {
		printf("It is not a Fibonacci element\n");
	}
	
	return 0;
}
